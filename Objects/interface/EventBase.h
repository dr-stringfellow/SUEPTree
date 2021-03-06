#ifndef SUEPTree_Objects_EventBase_h
#define SUEPTree_Objects_EventBase_h
#include "../../Framework/interface/TreeEntry.h"
#include "Constants.h"
#include "HLTBits.h"
#include "Parton.h"
#include "Vertex.h"
#include "Run.h"
#include "TList.h"
#include "TFile.h"
#include "TKey.h"
#include "HLTObjectStore.h"
#include "GenParticleBase.h"
#include "SUEPTree/Framework/interface/RRNG.h"

namespace suep {

  class EventBase : public TreeEntry {
  public:
    EventBase();
    EventBase(EventBase const&);
    ~EventBase();
    EventBase& operator=(EventBase const&);

    void print(std::ostream& = std::cout, UInt_t level = 1) const override;
    void dump(std::ostream& = std::cout) const override;

    virtual GenParticleBaseCollection const* genParticleCollection() const { return nullptr; }
    virtual GenParticleBaseCollection* genParticleCollection() { return nullptr; }

    HLTBits triggers = HLTBits("triggers");
    PartonCollection partons = PartonCollection("partons", 8);
    Vertex genVertex = Vertex("genVertex");

    UInt_t runNumber{};
    UInt_t lumiNumber{};
    ULong64_t eventNumber{};
    Bool_t isData{};
    Float_t weight{};
    UShort_t npv{};
    UShort_t npvTrue{};

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
    /* BEGIN CUSTOM EventBase.h.classdef */

    //! Current run object.
    Run run;

    //! Turn run synch feature on/off (default on)
    void setReadRunTree(Bool_t s) { readRunTree_ = s; }

    //! Use to declare a trigger path to be used in the analysis. Returns a token for the path.
    /*!
     * Call this function before the event loop for each trigger you will be using. The return value
     * is an integer unique to the path, and can be passed to triggerFired() in the event loop to retrieve
     * the trigger decision of the event.
     *
     * \param path   HLT path
     */
    UInt_t registerTrigger(char const* path) { return run.registerTrigger(path); }

    //! Trigger decision of the event.
    /*!
     * Pass the trigger token returned by registerTrigger().
     *
     * \param token   Token returned by registerTrigger()
     */
    Bool_t triggerFired(UInt_t token) const;

    //! Trigger object collection with additional features.
    HLTObjectStore triggerObjects = HLTObjectStore("triggerObjects");

    //! Use to declare a trigger filter name (key in the triggerObjects map) to be used in the analysis.
    /*!
     * By default, all trigger objects are loaded into the triggerObjects map at each call to getEntry.
     * Once a call to this function is made, only the objects for the registered filter will be loaded.
     */
    void registerTriggerObjects(char const* filter) { triggerObjects.registerFilter(filter); }

    //! Repeatable random number generator, initialized to be empty
    RRNG rng{0,0,nullptr};

  private:
    //! Update the triggerFilterMask at run transitions
    void setTriggerFilters_();

    //! Flag to set run synch feature on/off
    Bool_t readRunTree_{kTRUE};

    //! List of run trees linked to the run object.
    /*!
     event chain -> tree number, run tree
     */
    std::map<TTree*, std::pair<Int_t, TTree*>> runTrees_;

    /* END CUSTOM */
  };

  /* BEGIN CUSTOM EventBase.h.global */
  /* END CUSTOM */

}

#endif
