#include "../interface/EventTPEM.h"

suep::EventTPEM::EventTPEM() :
  EventTP()
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPEM.cc.ctor */
  /* END CUSTOM */
}

suep::EventTPEM::EventTPEM(EventTPEM const& _src) :
  EventTP(_src),
  tags(_src.tags),
  probes(_src.probes)
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPEM.cc.copy_ctor */
  /* END CUSTOM */
}

suep::EventTPEM::~EventTPEM()
{
  /* BEGIN CUSTOM EventTPEM.cc.dtor */
  /* END CUSTOM */
}

suep::EventTPEM&
suep::EventTPEM::operator=(EventTPEM const& _src)
{
  EventTP::operator=(_src);

  /* BEGIN CUSTOM EventTPEM.cc.operator= */
  /* END CUSTOM */

  tags = _src.tags;
  probes = _src.probes;

  return *this;
}

void
suep::EventTPEM::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTPEM.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::EventTPEM::dump(std::ostream& _out/* = std::cout*/) const
{
  EventTP::dump(_out);

  tags.dump(_out);
  probes.dump(_out);

}
/*static*/
suep::utils::BranchList
suep::EventTPEM::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventTP::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += Electron::getListOfBranches().fullNames("tags");
    blist += Muon::getListOfBranches().fullNames("probes");
  }
  /* BEGIN CUSTOM EventTPEM.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
suep::EventTPEM::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doSetStatus_(_tree, _branches);
}

/*protected*/
suep::utils::BranchList
suep::EventTPEM::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventTP::doGetStatus_(_tree);

  return blist;
}

/*protected*/
suep::utils::BranchList
suep::EventTPEM::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
suep::EventTPEM::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventTP::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
suep::EventTPEM::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doBook_(_tree, _branches);

}

/*protected*/
void
suep::EventTPEM::doGetEntry_(TTree& _tree)
{
  EventTP::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventTPEM.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
suep::EventTPEM::doInit_()
{
  EventTP::doInit_();

  /* BEGIN CUSTOM EventTPEM.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::EventTPEM::doUnlink_(TTree& _tree)
{
  EventTP::doUnlink_(_tree);

  /* BEGIN CUSTOM EventTPEM.cc.doUnlink_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTPEM.cc.global */
/* END CUSTOM */
