#ifndef SUEPTree_Objects_ParticleM_h
#define SUEPTree_Objects_ParticleM_h
#include "Constants.h"
#include "Particle.h"
#include "PtEtaPhiMMixin.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace suep {

  class ParticleM : public Particle, public PtEtaPhiMMixin {
  public:
    struct datastore : public Particle::datastore, public PtEtaPhiMMixin::datastore {
      datastore() : Particle::datastore(), PtEtaPhiMMixin::datastore() {}
      ~datastore() { deallocate(); }

      /* PtEtaPhiMMixin
      Float_t* pt_{0};
      Float_t* eta_{0};
      Float_t* phi_{0};
      Float_t* mass_{0};
      */

      void allocate(UInt_t n) override;
      void deallocate() override;
      void setStatus(TTree&, TString const&, utils::BranchList const&) override;
      utils::BranchList getStatus(TTree&, TString const&) const override;
      utils::BranchList getBranchNames(TString const& = "") const override;
      void setAddress(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t setStatus = kTRUE) override;
      void book(TTree&, TString const&, utils::BranchList const& = {"*"}, Bool_t dynamic = kTRUE) override;
      void releaseTree(TTree&, TString const&) override;
      void resizeVectors_(UInt_t) override;
    };

    typedef Array<ParticleM> array_type;
    typedef Collection<ParticleM> collection_type;

    typedef Particle base_type;

    ParticleM(char const* name = "");
    ParticleM(ParticleM const&);
    ParticleM(datastore&, UInt_t idx);
    ~ParticleM();
    ParticleM& operator=(ParticleM const&);

    static char const* typeName() { return "ParticleM"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    double pt() const override { return pt_; }
    double eta() const override { return eta_; }
    double phi() const override { return phi_; }
    double m() const override { return mass_; }
    void setPtEtaPhiM(double pt, double eta, double phi, double m) override;
    void setXYZE(double px, double py, double pz, double e) override;

  protected:
    /* PtEtaPhiMMixin
    Float_t& pt_;
    Float_t& eta_;
    Float_t& phi_;
    Float_t& mass_;
    */

  public:
    /* BEGIN CUSTOM ParticleM.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    ParticleM(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<ParticleM> ParticleMArray;
  typedef Collection<ParticleM> ParticleMCollection;
  typedef Ref<ParticleM> ParticleMRef;
  typedef RefVector<ParticleM> ParticleMRefVector;

  /* BEGIN CUSTOM ParticleM.h.global */
  /* END CUSTOM */

}

#endif
