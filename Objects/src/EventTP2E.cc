#include "../interface/EventTP2E.h"

suep::EventTP2E::EventTP2E() :
  EventTP()
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTP2E.cc.ctor */
  /* END CUSTOM */
}

suep::EventTP2E::EventTP2E(EventTP2E const& _src) :
  EventTP(_src),
  tags(_src.tags),
  probes(_src.probes)
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTP2E.cc.copy_ctor */
  /* END CUSTOM */
}

suep::EventTP2E::~EventTP2E()
{
  /* BEGIN CUSTOM EventTP2E.cc.dtor */
  /* END CUSTOM */
}

suep::EventTP2E&
suep::EventTP2E::operator=(EventTP2E const& _src)
{
  EventTP::operator=(_src);

  /* BEGIN CUSTOM EventTP2E.cc.operator= */
  /* END CUSTOM */

  tags = _src.tags;
  probes = _src.probes;

  return *this;
}

void
suep::EventTP2E::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTP2E.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::EventTP2E::dump(std::ostream& _out/* = std::cout*/) const
{
  EventTP::dump(_out);

  tags.dump(_out);
  probes.dump(_out);

}
/*static*/
suep::utils::BranchList
suep::EventTP2E::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventTP::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += Electron::getListOfBranches().fullNames("tags");
    blist += Electron::getListOfBranches().fullNames("probes");
  }
  /* BEGIN CUSTOM EventTP2E.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
suep::EventTP2E::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doSetStatus_(_tree, _branches);
}

/*protected*/
suep::utils::BranchList
suep::EventTP2E::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventTP::doGetStatus_(_tree);

  return blist;
}

/*protected*/
suep::utils::BranchList
suep::EventTP2E::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
suep::EventTP2E::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventTP::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
suep::EventTP2E::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doBook_(_tree, _branches);

}

/*protected*/
void
suep::EventTP2E::doGetEntry_(TTree& _tree)
{
  EventTP::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventTP2E.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
suep::EventTP2E::doInit_()
{
  EventTP::doInit_();

  /* BEGIN CUSTOM EventTP2E.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::EventTP2E::doUnlink_(TTree& _tree)
{
  EventTP::doUnlink_(_tree);

  /* BEGIN CUSTOM EventTP2E.cc.doUnlink_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTP2E.cc.global */
/* END CUSTOM */
