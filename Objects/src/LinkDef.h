#include "SUEPTree/Objects/interface/Particle.h"
#include "SUEPTree/Objects/interface/Proton.h"
#include "SUEPTree/Objects/interface/Vertex.h"
#include "SUEPTree/Objects/interface/RecoVertex.h"
#include "SUEPTree/Objects/interface/PackedTrack.h"
#include "SUEPTree/Objects/interface/SuperCluster.h"
#include "SUEPTree/Objects/interface/GenParticleBase.h"
#include "SUEPTree/Objects/interface/PFCandBase.h"
#include "SUEPTree/Objects/interface/PackedParticle.h"
#include "SUEPTree/Objects/interface/ParticleP.h"
#include "SUEPTree/Objects/interface/ParticleM.h"
#include "SUEPTree/Objects/interface/SecondaryVertex.h"
#include "SUEPTree/Objects/interface/PFCand.h"
#include "SUEPTree/Objects/interface/UnpackedPFCand.h"
#include "SUEPTree/Objects/interface/Parton.h"
#include "SUEPTree/Objects/interface/GenParticle.h"
#include "SUEPTree/Objects/interface/UnpackedGenParticle.h"
#include "SUEPTree/Objects/interface/Lepton.h"
#include "SUEPTree/Objects/interface/Electron.h"
#include "SUEPTree/Objects/interface/Muon.h"
#include "SUEPTree/Objects/interface/Tau.h"
#include "SUEPTree/Objects/interface/Photon.h"
#include "SUEPTree/Objects/interface/GenJet.h"
#include "SUEPTree/Objects/interface/MicroJet.h"
#include "SUEPTree/Objects/interface/Jet.h"
#include "SUEPTree/Objects/interface/FatJet.h"
#include "SUEPTree/Objects/interface/Met.h"
#include "SUEPTree/Objects/interface/RecoMet.h"
#include "SUEPTree/Objects/interface/MetFilters.h"
#include "SUEPTree/Objects/interface/HLTBits.h"
#include "SUEPTree/Objects/interface/HLTObject.h"
#include "SUEPTree/Objects/interface/GenReweight.h"
#include "SUEPTree/Objects/interface/Recoil.h"
#include "SUEPTree/Objects/interface/EventBase.h"
#include "SUEPTree/Objects/interface/Event.h"
#include "SUEPTree/Objects/interface/Run.h"
#include "SUEPTree/Objects/interface/PackingHelper.h"

#ifdef __CLING__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclass;
#pragma link C++ nestedtypedef;
#pragma link C++ namespace suep;

#pragma link C++ class suep::Particle;
#pragma link C++ class suep::Proton;
#pragma link C++ class suep::Vertex;
#pragma link C++ class suep::RecoVertex;
#pragma link C++ class suep::PackedTrack;
#pragma link C++ class suep::SuperCluster;
#pragma link C++ class suep::GenParticleBase;
#pragma link C++ class suep::PFCandBase;
#pragma link C++ class suep::PackedParticle;
#pragma link C++ class suep::ParticleP;
#pragma link C++ class suep::ParticleM;
#pragma link C++ class suep::SecondaryVertex;
#pragma link C++ class suep::PFCand;
#pragma link C++ class suep::UnpackedPFCand;
#pragma link C++ class suep::Parton;
#pragma link C++ class suep::GenParticle;
#pragma link C++ class suep::UnpackedGenParticle;
#pragma link C++ class suep::Lepton;
#pragma link C++ class suep::Electron;
#pragma link C++ class suep::Muon;
#pragma link C++ class suep::Tau;
#pragma link C++ class suep::Photon;
#pragma link C++ class suep::GenJet;
#pragma link C++ class suep::MicroJet;
#pragma link C++ class suep::Jet;
#pragma link C++ class suep::FatJet;
#pragma link C++ class suep::Met;
#pragma link C++ class suep::RecoMet;
#pragma link C++ class suep::MetFilters;
#pragma link C++ class suep::HLTBits;
#pragma link C++ class suep::HLTObject;
#pragma link C++ class std::vector<UShort_t>+;
#pragma link C++ class std::vector<std::vector<UShort_t>>+;
#pragma link C++ class suep::GenReweight;
#pragma link C++ class suep::Recoil;
#pragma link C++ class suep::Array<suep::Particle>;
#pragma link C++ class suep::Collection<suep::Particle>;
#pragma link C++ class suep::Ref<suep::Particle>;
#pragma link C++ class suep::RefVector<suep::Particle>;
#pragma link C++ class suep::Array<suep::Proton>;
#pragma link C++ class suep::Collection<suep::Proton>;
#pragma link C++ class suep::Ref<suep::Proton>;
#pragma link C++ class suep::RefVector<suep::Proton>;
#pragma link C++ class suep::Array<suep::Vertex>;
#pragma link C++ class suep::Collection<suep::Vertex>;
#pragma link C++ class suep::Ref<suep::Vertex>;
#pragma link C++ class suep::RefVector<suep::Vertex>;
#pragma link C++ class suep::Array<suep::RecoVertex>;
#pragma link C++ class suep::Collection<suep::RecoVertex>;
#pragma link C++ class suep::Ref<suep::RecoVertex>;
#pragma link C++ class suep::RefVector<suep::RecoVertex>;
#pragma link C++ class suep::Array<suep::PackedTrack>;
#pragma link C++ class suep::Collection<suep::PackedTrack>;
#pragma link C++ class suep::Ref<suep::PackedTrack>;
#pragma link C++ class suep::RefVector<suep::PackedTrack>;
#pragma link C++ class suep::Array<suep::SuperCluster>;
#pragma link C++ class suep::Collection<suep::SuperCluster>;
#pragma link C++ class suep::Ref<suep::SuperCluster>;
#pragma link C++ class suep::RefVector<suep::SuperCluster>;
#pragma link C++ class suep::Array<suep::GenParticleBase>;
#pragma link C++ class suep::Collection<suep::GenParticleBase>;
#pragma link C++ class suep::Ref<suep::GenParticleBase>;
#pragma link C++ class suep::RefVector<suep::GenParticleBase>;
#pragma link C++ class suep::Array<suep::PFCandBase>;
#pragma link C++ class suep::Collection<suep::PFCandBase>;
#pragma link C++ class suep::Ref<suep::PFCandBase>;
#pragma link C++ class suep::RefVector<suep::PFCandBase>;
#pragma link C++ class suep::Array<suep::PackedParticle>;
#pragma link C++ class suep::Collection<suep::PackedParticle>;
#pragma link C++ class suep::Ref<suep::PackedParticle>;
#pragma link C++ class suep::RefVector<suep::PackedParticle>;
#pragma link C++ class suep::Array<suep::ParticleP>;
#pragma link C++ class suep::Collection<suep::ParticleP>;
#pragma link C++ class suep::Ref<suep::ParticleP>;
#pragma link C++ class suep::RefVector<suep::ParticleP>;
#pragma link C++ class suep::Array<suep::ParticleM>;
#pragma link C++ class suep::Collection<suep::ParticleM>;
#pragma link C++ class suep::Ref<suep::ParticleM>;
#pragma link C++ class suep::RefVector<suep::ParticleM>;
#pragma link C++ class suep::Array<suep::SecondaryVertex>;
#pragma link C++ class suep::Collection<suep::SecondaryVertex>;
#pragma link C++ class suep::Ref<suep::SecondaryVertex>;
#pragma link C++ class suep::RefVector<suep::SecondaryVertex>;
#pragma link C++ class suep::Array<suep::PFCand>;
#pragma link C++ class suep::Collection<suep::PFCand>;
#pragma link C++ class suep::Ref<suep::PFCand>;
#pragma link C++ class suep::RefVector<suep::PFCand>;
#pragma link C++ class suep::Array<suep::UnpackedPFCand>;
#pragma link C++ class suep::Collection<suep::UnpackedPFCand>;
#pragma link C++ class suep::Ref<suep::UnpackedPFCand>;
#pragma link C++ class suep::RefVector<suep::UnpackedPFCand>;
#pragma link C++ class suep::Array<suep::Parton>;
#pragma link C++ class suep::Collection<suep::Parton>;
#pragma link C++ class suep::Ref<suep::Parton>;
#pragma link C++ class suep::RefVector<suep::Parton>;
#pragma link C++ class suep::Array<suep::GenParticle>;
#pragma link C++ class suep::Collection<suep::GenParticle>;
#pragma link C++ class suep::Ref<suep::GenParticle>;
#pragma link C++ class suep::RefVector<suep::GenParticle>;
#pragma link C++ class suep::Array<suep::UnpackedGenParticle>;
#pragma link C++ class suep::Collection<suep::UnpackedGenParticle>;
#pragma link C++ class suep::Ref<suep::UnpackedGenParticle>;
#pragma link C++ class suep::RefVector<suep::UnpackedGenParticle>;
#pragma link C++ class suep::Array<suep::Lepton>;
#pragma link C++ class suep::Collection<suep::Lepton>;
#pragma link C++ class suep::Ref<suep::Lepton>;
#pragma link C++ class suep::RefVector<suep::Lepton>;
#pragma link C++ class suep::Array<suep::Electron>;
#pragma link C++ class suep::Collection<suep::Electron>;
#pragma link C++ class suep::Ref<suep::Electron>;
#pragma link C++ class suep::RefVector<suep::Electron>;
#pragma link C++ class suep::Array<suep::Muon>;
#pragma link C++ class suep::Collection<suep::Muon>;
#pragma link C++ class suep::Ref<suep::Muon>;
#pragma link C++ class suep::RefVector<suep::Muon>;
#pragma link C++ class suep::Array<suep::Tau>;
#pragma link C++ class suep::Collection<suep::Tau>;
#pragma link C++ class suep::Ref<suep::Tau>;
#pragma link C++ class suep::RefVector<suep::Tau>;
#pragma link C++ class suep::Array<suep::Photon>;
#pragma link C++ class suep::Collection<suep::Photon>;
#pragma link C++ class suep::Ref<suep::Photon>;
#pragma link C++ class suep::RefVector<suep::Photon>;
#pragma link C++ class suep::Array<suep::GenJet>;
#pragma link C++ class suep::Collection<suep::GenJet>;
#pragma link C++ class suep::Ref<suep::GenJet>;
#pragma link C++ class suep::RefVector<suep::GenJet>;
#pragma link C++ class suep::Array<suep::MicroJet>;
#pragma link C++ class suep::Collection<suep::MicroJet>;
#pragma link C++ class suep::Ref<suep::MicroJet>;
#pragma link C++ class suep::RefVector<suep::MicroJet>;
#pragma link C++ class suep::Array<suep::Jet>;
#pragma link C++ class suep::Collection<suep::Jet>;
#pragma link C++ class suep::Ref<suep::Jet>;
#pragma link C++ class suep::RefVector<suep::Jet>;
#pragma link C++ class suep::Array<suep::FatJet>;
#pragma link C++ class suep::Collection<suep::FatJet>;
#pragma link C++ class suep::Ref<suep::FatJet>;
#pragma link C++ class suep::RefVector<suep::FatJet>;
#pragma link C++ class suep::Array<suep::HLTObject>;
#pragma link C++ class suep::Collection<suep::HLTObject>;
#pragma link C++ class suep::Ref<suep::HLTObject>;
#pragma link C++ class suep::RefVector<suep::HLTObject>;
#pragma link C++ typedef suep::ParticleArray;
#pragma link C++ typedef suep::ParticleCollection;
#pragma link C++ typedef suep::ParticleRef;
#pragma link C++ typedef suep::ParticleRefVector;
#pragma link C++ typedef suep::ProtonArray;
#pragma link C++ typedef suep::ProtonCollection;
#pragma link C++ typedef suep::ProtonRef;
#pragma link C++ typedef suep::ProtonRefVector;
#pragma link C++ typedef suep::VertexArray;
#pragma link C++ typedef suep::VertexCollection;
#pragma link C++ typedef suep::VertexRef;
#pragma link C++ typedef suep::VertexRefVector;
#pragma link C++ typedef suep::RecoVertexArray;
#pragma link C++ typedef suep::RecoVertexCollection;
#pragma link C++ typedef suep::RecoVertexRef;
#pragma link C++ typedef suep::RecoVertexRefVector;
#pragma link C++ typedef suep::PackedTrackArray;
#pragma link C++ typedef suep::PackedTrackCollection;
#pragma link C++ typedef suep::PackedTrackRef;
#pragma link C++ typedef suep::PackedTrackRefVector;
#pragma link C++ typedef suep::SuperClusterArray;
#pragma link C++ typedef suep::SuperClusterCollection;
#pragma link C++ typedef suep::SuperClusterRef;
#pragma link C++ typedef suep::SuperClusterRefVector;
#pragma link C++ typedef suep::GenParticleBaseArray;
#pragma link C++ typedef suep::GenParticleBaseCollection;
#pragma link C++ typedef suep::GenParticleBaseRef;
#pragma link C++ typedef suep::GenParticleBaseRefVector;
#pragma link C++ typedef suep::PFCandBaseArray;
#pragma link C++ typedef suep::PFCandBaseCollection;
#pragma link C++ typedef suep::PFCandBaseRef;
#pragma link C++ typedef suep::PFCandBaseRefVector;
#pragma link C++ typedef suep::PackedParticleArray;
#pragma link C++ typedef suep::PackedParticleCollection;
#pragma link C++ typedef suep::PackedParticleRef;
#pragma link C++ typedef suep::PackedParticleRefVector;
#pragma link C++ typedef suep::ParticlePArray;
#pragma link C++ typedef suep::ParticlePCollection;
#pragma link C++ typedef suep::ParticlePRef;
#pragma link C++ typedef suep::ParticlePRefVector;
#pragma link C++ typedef suep::ParticleMArray;
#pragma link C++ typedef suep::ParticleMCollection;
#pragma link C++ typedef suep::ParticleMRef;
#pragma link C++ typedef suep::ParticleMRefVector;
#pragma link C++ typedef suep::SecondaryVertexArray;
#pragma link C++ typedef suep::SecondaryVertexCollection;
#pragma link C++ typedef suep::SecondaryVertexRef;
#pragma link C++ typedef suep::SecondaryVertexRefVector;
#pragma link C++ typedef suep::PFCandArray;
#pragma link C++ typedef suep::PFCandCollection;
#pragma link C++ typedef suep::PFCandRef;
#pragma link C++ typedef suep::PFCandRefVector;
#pragma link C++ typedef suep::UnpackedPFCandArray;
#pragma link C++ typedef suep::UnpackedPFCandCollection;
#pragma link C++ typedef suep::UnpackedPFCandRef;
#pragma link C++ typedef suep::UnpackedPFCandRefVector;
#pragma link C++ typedef suep::PartonArray;
#pragma link C++ typedef suep::PartonCollection;
#pragma link C++ typedef suep::PartonRef;
#pragma link C++ typedef suep::PartonRefVector;
#pragma link C++ typedef suep::GenParticleArray;
#pragma link C++ typedef suep::GenParticleCollection;
#pragma link C++ typedef suep::GenParticleRef;
#pragma link C++ typedef suep::GenParticleRefVector;
#pragma link C++ typedef suep::UnpackedGenParticleArray;
#pragma link C++ typedef suep::UnpackedGenParticleCollection;
#pragma link C++ typedef suep::UnpackedGenParticleRef;
#pragma link C++ typedef suep::UnpackedGenParticleRefVector;
#pragma link C++ typedef suep::LeptonArray;
#pragma link C++ typedef suep::LeptonCollection;
#pragma link C++ typedef suep::LeptonRef;
#pragma link C++ typedef suep::LeptonRefVector;
#pragma link C++ typedef suep::ElectronArray;
#pragma link C++ typedef suep::ElectronCollection;
#pragma link C++ typedef suep::ElectronRef;
#pragma link C++ typedef suep::ElectronRefVector;
#pragma link C++ typedef suep::MuonArray;
#pragma link C++ typedef suep::MuonCollection;
#pragma link C++ typedef suep::MuonRef;
#pragma link C++ typedef suep::MuonRefVector;
#pragma link C++ typedef suep::TauArray;
#pragma link C++ typedef suep::TauCollection;
#pragma link C++ typedef suep::TauRef;
#pragma link C++ typedef suep::TauRefVector;
#pragma link C++ typedef suep::PhotonArray;
#pragma link C++ typedef suep::PhotonCollection;
#pragma link C++ typedef suep::PhotonRef;
#pragma link C++ typedef suep::PhotonRefVector;
#pragma link C++ typedef suep::GenJetArray;
#pragma link C++ typedef suep::GenJetCollection;
#pragma link C++ typedef suep::GenJetRef;
#pragma link C++ typedef suep::GenJetRefVector;
#pragma link C++ typedef suep::MicroJetArray;
#pragma link C++ typedef suep::MicroJetCollection;
#pragma link C++ typedef suep::MicroJetRef;
#pragma link C++ typedef suep::MicroJetRefVector;
#pragma link C++ typedef suep::JetArray;
#pragma link C++ typedef suep::JetCollection;
#pragma link C++ typedef suep::JetRef;
#pragma link C++ typedef suep::JetRefVector;
#pragma link C++ typedef suep::FatJetArray;
#pragma link C++ typedef suep::FatJetCollection;
#pragma link C++ typedef suep::FatJetRef;
#pragma link C++ typedef suep::FatJetRefVector;
#pragma link C++ typedef suep::HLTObjectArray;
#pragma link C++ typedef suep::HLTObjectCollection;
#pragma link C++ typedef suep::HLTObjectRef;
#pragma link C++ typedef suep::HLTObjectRefVector;
#pragma link C++ class suep::EventBase;
#pragma link C++ class suep::Event;
#pragma link C++ class suep::Run;
#pragma link C++ class suep::PackingHelper;

#endif
