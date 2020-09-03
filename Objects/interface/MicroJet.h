#ifndef SUEPTree_Objects_MicroJet_h
#define SUEPTree_Objects_MicroJet_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace panda {

  class MicroJet : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

      Float_t* csv{0};
      Float_t* qgl{0};
      Float_t* cmva{0};
      Float_t* deepCSVudsg{0};
      Float_t* deepCSVb{0};
      Float_t* deepCSVc{0};
      Float_t* deepCSVbb{0};
      Float_t* deepCSVcc{0};
      Float_t* deepCMVAudsg{0};
      Float_t* deepCMVAb{0};
      Float_t* deepCMVAc{0};
      Float_t* deepCMVAbb{0};
      Float_t* deepCMVAcc{0};

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

    typedef Array<MicroJet> array_type;
    typedef Collection<MicroJet> collection_type;

    typedef ParticleM base_type;

    MicroJet(char const* name = "");
    MicroJet(MicroJet const&);
    MicroJet(datastore&, UInt_t idx);
    ~MicroJet();
    MicroJet& operator=(MicroJet const&);

    static char const* typeName() { return "MicroJet"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Float_t& csv;
    Float_t& qgl;
    Float_t& cmva;
    Float_t& deepCSVudsg;
    Float_t& deepCSVb;
    Float_t& deepCSVc;
    Float_t& deepCSVbb;
    Float_t& deepCSVcc;
    Float_t& deepCMVAudsg;
    Float_t& deepCMVAb;
    Float_t& deepCMVAc;
    Float_t& deepCMVAbb;
    Float_t& deepCMVAcc;

    /* BEGIN CUSTOM MicroJet.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    MicroJet(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<MicroJet> MicroJetArray;
  typedef Collection<MicroJet> MicroJetCollection;
  typedef Ref<MicroJet> MicroJetRef;
  typedef RefVector<MicroJet> MicroJetRefVector;

  /* BEGIN CUSTOM MicroJet.h.global */
  /* END CUSTOM */

}

#endif
