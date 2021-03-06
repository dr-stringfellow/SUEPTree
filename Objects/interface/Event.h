#ifndef SUEPTree_Objects_Event_h
#define SUEPTree_Objects_Event_h
#include "EventBase.h"
#include "Constants.h"
#include "GenReweight.h"
#include "PFCand.h"
#include "RecoVertex.h"
#include "SecondaryVertex.h"
#include "PackedTrack.h"
#include "SuperCluster.h"
#include "Electron.h"
#include "Muon.h"
#include "Tau.h"
#include "Photon.h"
#include "Jet.h"
#include "FatJet.h"
#include "MicroJet.h"
#include "GenJet.h"
#include "GenParticle.h"
#include "Proton.h"
#include "RecoMet.h"
#include "Met.h"
#include "MetFilters.h"
#include "Recoil.h"

namespace suep {

  class Event : public EventBase {
  public:
    Event();
    Event(Event const&);
    ~Event();
    Event& operator=(Event const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    GenParticleBaseCollection const* genParticleCollection() const override { return &genParticles; }
    GenParticleBaseCollection* genParticleCollection() override { return &genParticles; }

    GenReweight genReweight = GenReweight("genReweight");
    PFCandCollection pfCandidates = PFCandCollection("pfCandidates", 2048);
    RecoVertexCollection vertices = RecoVertexCollection("vertices", 64);
    SecondaryVertexCollection secondaryVertices = SecondaryVertexCollection("secondaryVertices", 64);
    PackedTrackCollection tracks = PackedTrackCollection("tracks", 1024);
    SuperClusterCollection superClusters = SuperClusterCollection("superClusters", 64);
    ElectronCollection electrons = ElectronCollection("electrons", 32);
    MuonCollection muons = MuonCollection("muons", 32);  ///< sortedby=pt
    TauCollection taus = TauCollection("taus", 64);
    PhotonCollection photons = PhotonCollection("photons", 32);
    JetCollection chsAK4Jets = JetCollection("chsAK4Jets", 64);
    JetCollection puppiAK4Jets = JetCollection("puppiAK4Jets", 64);
    FatJetCollection puppiAK8Jets = FatJetCollection("puppiAK8Jets", 8);
    MicroJetCollection puppiAK8Subjets = MicroJetCollection("puppiAK8Subjets", 64);
    FatJetCollection puppiCA15Jets = FatJetCollection("puppiCA15Jets", 8);
    MicroJetCollection puppiCA15Subjets = MicroJetCollection("puppiCA15Subjets", 64);
    GenJetCollection ak4GenJets = GenJetCollection("ak4GenJets", 64);
    GenJetCollection ak8GenJets = GenJetCollection("ak8GenJets", 32);
    GenJetCollection ca15GenJets = GenJetCollection("ca15GenJets", 32);
    GenParticleCollection genParticles = GenParticleCollection("genParticles", 256);
    ProtonCollection protons = ProtonCollection("protons", 32);
    RecoMet pfMet = RecoMet("pfMet");
    RecoMet puppiMet = RecoMet("puppiMet");
    Met rawMet = Met("rawMet");
    Met caloMet = Met("caloMet");
    Met noMuMet = Met("noMuMet");
    Met noHFMet = Met("noHFMet");
    Met trkMet = Met("trkMet");
    Met neutralMet = Met("neutralMet");
    Met photonMet = Met("photonMet");
    Met hfMet = Met("hfMet");
    Met genMet = Met("genMet");
    MetFilters metFilters = MetFilters("metFilters");
    Recoil recoil = Recoil("recoil");

    Float_t rho{};
    Float_t rhoCentralCalo{};

    static utils::BranchList getListOfBranches(Bool_t direct = kFALSE);

  protected:
    void doSetStatus_(TTree&, utils::BranchList const&) override;
    utils::BranchList doGetStatus_(TTree&) const override;
    utils::BranchList doGetBranchNames_() const override;
    void doSetAddress_(TTree&, utils::BranchList const&, Bool_t setStatus) override;
    void doBook_(TTree&, utils::BranchList const&) override;
    void doGetEntry_(TTree&) override;
    void doInit_() override;
    void doUnlink_(TTree&) override;

  public:
    /* BEGIN CUSTOM Event.h.classdef */
    /* END CUSTOM */
  };

  /* BEGIN CUSTOM Event.h.global */
  /* END CUSTOM */

}

#endif
