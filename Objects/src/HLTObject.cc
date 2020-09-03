#include "../interface/HLTObject.h"

/*static*/
suep::utils::BranchList
suep::HLTObject::getListOfBranches()
{
  utils::BranchList blist;
  blist += PackedParticle::getListOfBranches();
  blist += {"filters"};
  return blist;
}

void
suep::HLTObject::datastore::allocate(UInt_t _nmax)
{
  PackedParticle::datastore::allocate(_nmax);

  filters = new std::vector<std::vector<UShort_t>>(nmax_);
}

void
suep::HLTObject::datastore::deallocate()
{
  PackedParticle::datastore::deallocate();

  delete filters;
  filters = 0;
}

void
suep::HLTObject::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  PackedParticle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "filters", _branches);
}

suep::utils::BranchList
suep::HLTObject::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(PackedParticle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "filters"));

  return blist;
}

void
suep::HLTObject::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  PackedParticle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "filters", &filters, _branches, _setStatus);
}

void
suep::HLTObject::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  PackedParticle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "filters", "std::vector<std::vector<UShort_t>>", &filters, _branches);
}

void
suep::HLTObject::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  PackedParticle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "filters");
}

void
suep::HLTObject::datastore::resizeVectors_(UInt_t _size)
{
  PackedParticle::datastore::resizeVectors_(_size);

  filters->resize(_size);
}


suep::utils::BranchList
suep::HLTObject::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return HLTObject::getListOfBranches().fullNames(_name);
}

suep::HLTObject::HLTObject(char const* _name/* = ""*/) :
  PackedParticle(new HLTObjectArray(1, _name)),
  filters(&(*gStore.getData(this).filters)[0])
{
}

suep::HLTObject::HLTObject(HLTObject const& _src) :
  PackedParticle(new HLTObjectArray(1, _src.getName())),
  filters(&(*gStore.getData(this).filters)[0])
{
  operator=(_src);
}

suep::HLTObject::HLTObject(datastore& _data, UInt_t _idx) :
  PackedParticle(_data, _idx),
  filters(&(*_data.filters)[_idx])
{
}

suep::HLTObject::HLTObject(ArrayBase* _array) :
  PackedParticle(_array),
  filters(&(*gStore.getData(this).filters)[0])
{
}

suep::HLTObject::~HLTObject()
{
  destructor();
}

void
suep::HLTObject::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM HLTObject.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    PackedParticle::destructor(kTRUE);
}

suep::HLTObject&
suep::HLTObject::operator=(HLTObject const& _src)
{
  PackedParticle::operator=(_src);

  *filters = *_src.filters;

  /* BEGIN CUSTOM HLTObject.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::HLTObject::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  PackedParticle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "filters", "std::vector<UShort_t>", &filters, _branches);
}

void
suep::HLTObject::doInit_()
{
  PackedParticle::doInit_();

  *filters = std::vector<UShort_t>();

  /* BEGIN CUSTOM HLTObject.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::HLTObject::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM HLTObject.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::HLTObject::dump(std::ostream& _out/* = std::cout*/) const
{
  PackedParticle::dump(_out);

  _out << "filters = (std::vector<UShort_t> object)" << std::endl;
}

/* BEGIN CUSTOM HLTObject.cc.global */
/* END CUSTOM */
