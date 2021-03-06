#ifndef SUEPTree_Objects_GenJet_h
#define SUEPTree_Objects_GenJet_h
#include "Constants.h"
#include "ParticleM.h"
#include "../../Framework/interface/Array.h"
#include "../../Framework/interface/Collection.h"
#include "../../Framework/interface/Ref.h"
#include "../../Framework/interface/RefVector.h"
#include "GenParticleBase.h"

namespace suep {

  class GenJet : public ParticleM {
  public:
    struct datastore : public ParticleM::datastore {
      datastore() : ParticleM::datastore() {}
      ~datastore() { deallocate(); }

      Short_t* pdgid{0};
      Short_t* partonFlavor{0};
      Short_t* numB{0};
      Short_t* numC{0};
      ContainerBase const* matchedBHadronsContainer_{0};
      std::vector<std::vector<Short_t>>* matchedBHadrons_{0};
      ContainerBase const* matchedCHadronsContainer_{0};
      std::vector<std::vector<Short_t>>* matchedCHadrons_{0};

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

    typedef Array<GenJet> array_type;
    typedef Collection<GenJet> collection_type;

    typedef ParticleM base_type;

    GenJet(char const* name = "");
    GenJet(GenJet const&);
    GenJet(datastore&, UInt_t idx);
    ~GenJet();
    GenJet& operator=(GenJet const&);

    static char const* typeName() { return "GenJet"; }

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    Short_t& pdgid; ///< Filled with hadron flavor
    Short_t& partonFlavor;
    Short_t& numB;
    Short_t& numC;
    RefVector<GenParticleBase> matchedBHadrons;
    RefVector<GenParticleBase> matchedCHadrons;

    /* BEGIN CUSTOM GenJet.h.classdef */
    /* END CUSTOM */

    static utils::BranchList getListOfBranches();

    void destructor(Bool_t recursive = kFALSE);

  protected:
    GenJet(ArrayBase*);

    void doBook_(TTree&, TString const&, utils::BranchList const& = {"*"}) override;
    void doInit_() override;
  };

  typedef Array<GenJet> GenJetArray;
  typedef Collection<GenJet> GenJetCollection;
  typedef Ref<GenJet> GenJetRef;
  typedef RefVector<GenJet> GenJetRefVector;

  /* BEGIN CUSTOM GenJet.h.global */
  /* END CUSTOM */

}

#endif
