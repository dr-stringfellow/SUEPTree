#include "../interface/EventSV.h"

suep::EventSV::EventSV() :
  EventBase()
{
  std::vector<Object*> myObjects{{&secondaryVertices, &tracks, &muons, &genParticles}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&secondaryVertices, &tracks, &muons, &genParticles}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  secondaryVertices.data.daughtersContainer_ = &tracks;
  /* BEGIN CUSTOM EventSV.cc.ctor */
  /* END CUSTOM */
}

suep::EventSV::EventSV(EventSV const& _src) :
  EventBase(_src),
  secondaryVertices(_src.secondaryVertices),
  tracks(_src.tracks),
  muons(_src.muons),
  genParticles(_src.genParticles)
{
  std::vector<Object*> myObjects{{&secondaryVertices, &tracks, &muons, &genParticles}};
  objects_.insert(objects_.end(), myObjects.begin(), myObjects.end());
  std::vector<CollectionBase*> myCollections{{&secondaryVertices, &tracks, &muons, &genParticles}};
  collections_.insert(collections_.end(), myCollections.begin(), myCollections.end());

  secondaryVertices.data.daughtersContainer_ = &tracks;
  /* BEGIN CUSTOM EventSV.cc.copy_ctor */
  /* END CUSTOM */
}

suep::EventSV::~EventSV()
{
  /* BEGIN CUSTOM EventSV.cc.dtor */
  /* END CUSTOM */
}

suep::EventSV&
suep::EventSV::operator=(EventSV const& _src)
{
  EventBase::operator=(_src);

  /* BEGIN CUSTOM EventSV.cc.operator= */
  /* END CUSTOM */

  secondaryVertices = _src.secondaryVertices;
  tracks = _src.tracks;
  muons = _src.muons;
  genParticles = _src.genParticles;

  secondaryVertices.data.daughtersContainer_ = &tracks;

  return *this;
}

void
suep::EventSV::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM EventSV.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::EventSV::dump(std::ostream& _out/* = std::cout*/) const
{
  EventBase::dump(_out);

  secondaryVertices.dump(_out);
  tracks.dump(_out);
  muons.dump(_out);
  genParticles.dump(_out);

}
/*static*/
suep::utils::BranchList
suep::EventSV::getListOfBranches(Bool_t _direct/* = kFALSE*/)
{
  utils::BranchList blist;
  blist += EventBase::getListOfBranches(_direct);

  blist += {};
  if (!_direct) {
    blist += CorrectedSecondaryVertex::getListOfBranches().fullNames("secondaryVertices");
    blist += SVDaughter::getListOfBranches().fullNames("tracks");
    blist += Muon::getListOfBranches().fullNames("muons");
    blist += UnpackedGenParticle::getListOfBranches().fullNames("genParticles");
  }
  /* BEGIN CUSTOM EventSV.cc.getListOfBranches_ */
  /* END CUSTOM */
  return blist;
}

/*protected*/
void
suep::EventSV::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doSetStatus_(_tree, _branches);
}

/*protected*/
suep::utils::BranchList
suep::EventSV::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;
  blist += EventBase::doGetStatus_(_tree);

  return blist;
}

/*protected*/
suep::utils::BranchList
suep::EventSV::doGetBranchNames_() const
{
  return getListOfBranches(true);
}

/*protected*/
void
suep::EventSV::doSetAddress_(TTree& _tree, utils::BranchList const& _branches, Bool_t _setStatus)
{
  EventBase::doSetAddress_(_tree, _branches, _setStatus);

}

/*protected*/
void
suep::EventSV::doBook_(TTree& _tree, utils::BranchList const& _branches)
{
  EventBase::doBook_(_tree, _branches);

}

/*protected*/
void
suep::EventSV::doGetEntry_(TTree& _tree)
{
  EventBase::doGetEntry_(_tree);

  /* BEGIN CUSTOM EventSV.cc.doGetEntry_ */
  /* END CUSTOM */
}

void
suep::EventSV::doInit_()
{
  EventBase::doInit_();

  /* BEGIN CUSTOM EventSV.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::EventSV::doUnlink_(TTree& _tree)
{
  EventBase::doUnlink_(_tree);

  /* BEGIN CUSTOM EventSV.cc.doUnlink_ */
  /* END CUSTOM */
}



/* BEGIN CUSTOM EventSV.cc.global */
/* END CUSTOM */
