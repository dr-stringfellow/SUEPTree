#include "../interface/EventBase.h"

suep::EventBase::EventBase() :
  TreeEntry()
{
  std::vector<Object*> myObjects{{&triggers, &partons, &genVertex}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&partons}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventBase.cc.ctor */
  objects_.push_back(&triggerObjects);
  collections_.push_back(&triggerObjects);
  rng.setSeedAddress(&eventNumber);
  /* END CUSTOM */
}

suep::EventBase::EventBase(EventBase const& _src) :
  TreeEntry(_src),
  triggers(_src.triggers),
  partons(_src.partons),
  genVertex(_src.genVertex),
  runNumber(_src.runNumber),
  lumiNumber(_src.lumiNumber),
  eventNumber(_src.eventNumber),
  isData(_src.isData),
  weight(_src.weight),
  npv(_src.npv),
  npvTrue(_src.npvTrue)
{
  std::vector<Object*> myObjects{{&triggers, &partons, &genVertex}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&partons}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  /* BEGIN CUSTOM EventBase.cc.copy_ctor */
  run = _src.run;
  objects_.push_back(&triggerObjects);
  rng = _src.rng;
  rng.setSeedAddress(&eventNumber);
  /* END CUSTOM */
}

suep::EventBase::~EventBase()
{
  /* BEGIN CUSTOM EventBase.cc.dtor */
  /* END CUSTOM */
}

suep::EventBase&
suep::EventBase::operator=(EventBase const& _src)
{
  TreeEntry::operator=(_src);

  /* BEGIN CUSTOM EventBase.cc.operator= */
  run = _src.run;
  rng = _src.rng;
  rng.setSeedAddress(&eventNumber);
  triggerObjects = _src.triggerObjects;

  readRunTree_ = _src.readRunTree_;
  /* END CUSTOM */

  runNumber = _src.runNumber;
  lumiNumber = _src.lumiNumber;
  eventNumber = _src.eventNumber;
  isData = _src.isData;
  weight = _src.weight;
  npv = _src.npv;
  npvTrue = _src.npvTrue;

  triggers = _src.triggers;
  partons = _src.partons;
  genVertex = _src.genVertex;

  return *this;
}

void
suep::EventBase::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventBase.cc.print */
  if (_level >= 3) {
    EventBase::dump(_out);
  }
  else if (_level == 2) {
    // debug level
    _out << "runNumber = " << runNumber << std::endl;
    _out << "lumiNumber = " << lumiNumber << std::endl;
    _out << "eventNumber = " << eventNumber << std::endl;
    _out << "isData = " << isData << std::endl;
    _out << "weight = " << weight << std::endl;
  }
  else
    return;
  /* END CUSTOM */
}

void
suep::EventBase::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "runNumber = " << runNumber << std::endl;
  _out << "lumiNumber = " << lumiNumber << std::endl;
  _out << "eventNumber = " << eventNumber << std::endl;
  _out << "isData = " << isData << std::endl;
  _out << "weight = " << weight << std::endl;
  _out << "npv = " << npv << std::endl;
  _out << "npvTrue = " << npvTrue << std::endl;

  triggers.dump(_out);
  partons.dump(_out);
  genVertex.dump(_out);

}
/*static*/
suep::utils::BranchList
suep::EventBase::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += {"runNumber", "lumiNumber", "eventNumber", "isData", "weight", "npv", "npvTrue"};
  if (!_direct) {
    blist += HLTBits::getListOfBranches().fullNames("triggers");
    blist += Parton::getListOfBranches().fullNames("partons");
    blist += Vertex::getListOfBranches().fullNames("genVertex");
  }
  /* BEGIN CUSTOM EventBase.cc.getListOfBranches_ */
  if (!_direct)
    blist += HLTObject::getListOfBranches().fullNames("triggerObjects");
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
suep::EventBase::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, "", "runNumber", _branches);
  utils::setStatus(_tree, "", "lumiNumber", _branches);
  utils::setStatus(_tree, "", "eventNumber", _branches);
  utils::setStatus(_tree, "", "isData", _branches);
  utils::setStatus(_tree, "", "weight", _branches);
  utils::setStatus(_tree, "", "npv", _branches);
  utils::setStatus(_tree, "", "npvTrue", _branches);
}

/*protected*/
suep::utils::BranchList
suep::EventBase::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, "", "runNumber"));
  blist.push_back(utils::getStatus(_tree, "", "lumiNumber"));
  blist.push_back(utils::getStatus(_tree, "", "eventNumber"));
  blist.push_back(utils::getStatus(_tree, "", "isData"));
  blist.push_back(utils::getStatus(_tree, "", "weight"));
  blist.push_back(utils::getStatus(_tree, "", "npv"));
  blist.push_back(utils::getStatus(_tree, "", "npvTrue"));
  return blist;
}

/*protected*/
suep::utils::BranchList
suep::EventBase::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
suep::EventBase::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  utils::setAddress(_tree, "", "runNumber", &runNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "lumiNumber", &lumiNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "eventNumber", &eventNumber, _branches, _setStatus);
  utils::setAddress(_tree, "", "isData", &isData, _branches, _setStatus);
  utils::setAddress(_tree, "", "weight", &weight, _branches, _setStatus);
  utils::setAddress(_tree, "", "npv", &npv, _branches, _setStatus);
  utils::setAddress(_tree, "", "npvTrue", &npvTrue, _branches, _setStatus);
}

/*protected*/
void
suep::EventBase::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::book(_tree, "", "runNumber", "", 'i', &runNumber, _branches);
  utils::book(_tree, "", "lumiNumber", "", 'i', &lumiNumber, _branches);
  utils::book(_tree, "", "eventNumber", "", 'l', &eventNumber, _branches);
  utils::book(_tree, "", "isData", "", 'O', &isData, _branches);
  utils::book(_tree, "", "weight", "", 'F', &weight, _branches);
  utils::book(_tree, "", "npv", "", 's', &npv, _branches);
  utils::book(_tree, "", "npvTrue", "", 's', &npvTrue, _branches);
}

/*protected*/
void
suep::EventBase::doGetEntry_(TTree& _tree)
{
  /* BEGIN CUSTOM EventBase.cc.doGetEntry_ */
  if (readRunTree_ && _tree.GetCurrentFile() && runNumber != 0) {
    // If our Run object is enabled, we need to check for file transitions

    auto rItr(runTrees_.find(&_tree));
    if (rItr == runTrees_.end()) {
      // First time dealing with this tree
      rItr = runTrees_.emplace(&_tree, std::make_pair<Int_t, TTree*>(-1, 0)).first;
    }

    if (_tree.GetTreeNumber() == rItr->second.first) {
      // We are on the same tree. Just check for run number transition (and update the trigger table if necessary)
      if (run.findEntry(*rItr->second.second, runNumber)) {
        // there was a run transition
        setTriggerFilters_();
      }
    }
    else {
      // There was a file transition in the input
      rItr->second.first = _tree.GetTreeNumber();

      // First check that the runNumber branch is turned on
      if (_tree.GetBranchStatus("runNumber")) {
        auto& file(*_tree.GetCurrentFile());

        // read out the runs tree
        // using GetKey to create a "fresh" object - Get can fetch an in-memory object that may already be in use
        auto* key(file.GetKey("runs"));
        if (!key) {
          std::cerr << "File " << file.GetName() << " does not have a run tree." << std::endl;
          std::cerr << "If this is not a problem, turn off run tree synchronization" << std::endl;
          std::cerr << "by calling setReadRunTree(false) on the event object." << std::endl;
          throw std::runtime_error("InputError");
        }

        auto* runTree(static_cast<TTree*>(key->ReadObj()));

        rItr->second.second = runTree;

        run.setAddress(*runTree);
        run.init();
        run.resetCache();

        // Now cue the run object to the given run number
        run.findEntry(*rItr->second.second, runNumber);

        setTriggerFilters_();
      }
      else {
        rItr->second.second = 0;
        std::cerr << "Branch runNumber is turned off in the input events tree. Skipping run update." << std::endl;
      }
    }
  }

  if (triggerObjects.size() != 0 && run.hlt.filters)
    triggerObjects.makeMap();

  rng.generate();

  /* END CUSTOM */
}

void
suep::EventBase::doInit_()
{
  runNumber = 0;
  lumiNumber = 0;
  eventNumber = 0;
  isData = false;
  weight = 0.;
  npv = 0;
  npvTrue = 0;
  /* BEGIN CUSTOM EventBase.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::EventBase::doUnlink_(TTree& _tree)
{
  /* BEGIN CUSTOM EventBase.cc.doUnlink_ */
  runTrees_.erase(&_tree);
  /* END CUSTOM */
}



/* BEGIN CUSTOM EventBase.cc.global */

Bool_t
suep::EventBase::triggerFired(UInt_t _token) const
{
  UInt_t idx(run.getTriggerIndex(_token));
  if (idx < run.triggerSize())
    return triggers.pass(idx);
  else
    return false;
}

void
suep::EventBase::setTriggerFilters_()
{
  if (triggerObjects.size() == 0 || !run.hlt.filters)
    return;

  triggerObjects.setFilterObjectKeys(*run.hlt.filters);
}

/* END CUSTOM */
