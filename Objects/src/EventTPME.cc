#include "../interface/EventTPME.h"

suep::EventTPME::EventTPME() :
  EventTP()
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPME.cc.ctor */
  /* END CUSTOM */
}

suep::EventTPME::EventTPME(EventTPME const& _src) :
  EventTP(_src),
  tags(_src.tags),
  probes(_src.probes)
{
  std::vector<Object*> myObjects{{&tags, &probes}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&tags, &probes}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());
  /* BEGIN CUSTOM EventTPME.cc.copy_ctor */
  /* END CUSTOM */
}

suep::EventTPME::~EventTPME()
{
  /* BEGIN CUSTOM EventTPME.cc.dtor */
  /* END CUSTOM */
}

suep::EventTPME&
suep::EventTPME::operator=(EventTPME const& _src)
{
  EventTP::operator=(_src);

  /* BEGIN CUSTOM EventTPME.cc.operator= */
  /* END CUSTOM */

  tags = _src.tags;
  probes = _src.probes;

  return *this;
}

void
suep::EventTPME::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventTPME.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::EventTPME::dump(std::ostream& _out/* = std::cout*/) const
{
  EventTP::dump(_out);

  tags.dump(_out);
  probes.dump(_out);

}
/*static*/
suep::utils::BranchList
suep::EventTPME::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventTP::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += Muon::getListOfBranches().fullNames("tags");
    blist += Electron::getListOfBranches().fullNames("probes");
  }
  /* BEGIN CUSTOM EventTPME.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
suep::EventTPME::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doSetStatus_(_tree, _branches);
}

/*protected*/
suep::utils::BranchList
suep::EventTPME::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventTP::doGetStatus_(_tree);

  return blist;
}

/*protected*/
suep::utils::BranchList
suep::EventTPME::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
suep::EventTPME::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventTP::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
suep::EventTPME::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventTP::doBook_(_tree, _branches);

}

/*protected*/
void
suep::EventTPME::doGetEntry_(TTree& _tree)
{
  EventTP::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventTPME.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
suep::EventTPME::doInit_()
{
  EventTP::doInit_();

  /* BEGIN CUSTOM EventTPME.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::EventTPME::doUnlink_(TTree& _tree)
{
  EventTP::doUnlink_(_tree);

  /* BEGIN CUSTOM EventTPME.cc.doUnlink_ */
  /* END CUSTOM */
}


/* BEGIN CUSTOM EventTPME.cc.global */
/* END CUSTOM */
