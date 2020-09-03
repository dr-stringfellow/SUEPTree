#ifndef SUEPTree_Objects_Parton_h
#define SUEPTree_Objects_Parton_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"

namespace suep {

  class Parton : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

      Int_t* pdgid{0};

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

    typedef Array<Parton> array_type;
    typedef Collection<Parton> collection_type;

    typedef ParticleM base_type;

    Parton(char const* name = "");
    Parton(Parton const&);
    Parton(datastore&, UInt_t idx);
    ~Parton();
    Parton& operator=(Parton const&);

    static char const* typeName() { return "Parton"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Int_t& pdgid;

    /* BEGIN CUSTOM Parton.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    Parton(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<Parton> PartonArray;
  typedef Collection<Parton> PartonCollection;
  typedef Ref<Parton> PartonRef;
  typedef RefVector<Parton> PartonRefVector;

  /* BEGIN CUSTOM Parton.h.global */
  /* END CUSTOM */

}

#endif
