#include "../interface/EventTPEG.h"

suep::EventTPEG::EventTPEG() :
  EventTP()
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPEG.cc.ctor */
  /* END CUSTOM */
}

suep::EventTPEG::EventTPEG(EventTPEG const& _src) :
  EventTP(_src),
  tags(_src.tags),
  probes(_src.probes)
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPEG.cc.copy_ctor */
  /* END CUSTOM */
}

suep::EventTPEG::~EventTPEG()
{
  /* BEGIN CUSTOM EventTPEG.cc.dtor */
  /* END CUSTOM */
}

suep::EventTPEG&
suep::EventTPEG::operator=(EventTPEG const& _src)
{
  EventTP::operator=(_src);

  /* BEGIN CUSTOM EventTPEG.cc.operator= */
  /* END CUSTOM */

  tags = _src.tags;
  probes = _src.probes;

  return *this;
}

void
suep::EventTPEG::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTPEG.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::EventTPEG::dump(std::ostream& _out/* = std::cout*/) const
{
  EventTP::dump(_out);

  tags.dump(_out);
  probes.dump(_out);

}
/*static*/
suep::utils::BranchList
suep::EventTPEG::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventTP::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += Electron::getListOfBranches().fullNames("tags");
    blist += XPhoton::getListOfBranches().fullNames("probes");
  }
  /* BEGIN CUSTOM EventTPEG.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
suep::EventTPEG::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doSetStatus_(_tree, _branches);
}

/*protected*/
suep::utils::BranchList
suep::EventTPEG::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventTP::doGetStatus_(_tree);

  return blist;
}

/*protected*/
suep::utils::BranchList
suep::EventTPEG::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
suep::EventTPEG::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventTP::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
suep::EventTPEG::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doBook_(_tree, _branches);

}

/*protected*/
void
suep::EventTPEG::doGetEntry_(TTree& _tree)
{
  EventTP::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventTPEG.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
suep::EventTPEG::doInit_()
{
  EventTP::doInit_();

  /* BEGIN CUSTOM EventTPEG.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::EventTPEG::doUnlink_(TTree& _tree)
{
  EventTP::doUnlink_(_tree);

  /* BEGIN CUSTOM EventTPEG.cc.doUnlink_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTPEG.cc.global */
/* END CUSTOM */
