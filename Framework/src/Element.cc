#include "../interface/Element.h"
#include "../interface/ArrayBase.h"

suep::Element::StoreManager suep::Element::gStore;

/*protected*/
suep::Element::Element(ArrayBase* _array)
{
  gStore.emplace(this, _array);
}

suep::Element::~Element()
{
  delete &gStore.getArray(this);
  gStore.erase(this);
}

char const*
suep::Element::getName() const
{
  // Must return an empty string when called for a non-singlet instance (i.e. a member of a Container)
  auto oItr(gStore.find(this));
  if (oItr == gStore.end())
    return "";
  else
    return oItr->second->getName();
}

void
suep::Element::setName(char const* _name)
{
  gStore.getArray(this).setName(_name);
}

void
suep::Element::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  auto& array(gStore.getArray(this));
  array.getData().setStatus(_tree, array.getName(), _branches);
}

suep::utils::BranchList
suep::Element::getStatus(TTree& _tree) const
{
  auto& array(gStore.getArray(this));
  return array.getData().getStatus(_tree, array.getName());
}

suep::utils::BranchList
suep::Element::getBranchNames(Bool_t _fullName/* = kTRUE*/, Bool_t/* = kFALSE*/) const
{
  auto& array(gStore.getArray(this));
  if (_fullName)
    return array.getData().getBranchNames(array.getName());
  else
    return array.getData().getBranchNames();
}

UInt_t
suep::Element::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  return gStore.getArray(this).setAddress(_tree, _branches, _setStatus);
}

void
suep::Element::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  doBook_(_tree, gStore.getName(this), _branches);
}

Int_t
suep::Element::getEntry(TTree& _tree, Long64_t _entry, Bool_t _localEntry/* = kFALSE*/)
{
  return gStore.getArray(this).getEntry(_tree, _entry, _localEntry);
}

Int_t
suep::Element::getEntry(UInt_t _treeId, Long64_t _entry, Bool_t _localEntry/* = kFALSE*/)
{
  return gStore.getArray(this).getEntry(_treeId, _entry, _localEntry);
}

suep::ArrayBase&
suep::Element::StoreManager::getArray(Element const* _obj) const
{
  try {
    return *at(_obj);
  }
  catch (std::out_of_range&) {
    std::cerr << "!!! EXCEPTION !!!" << std::endl;
    std::cerr << "Data was requested for a non-singlet " << _obj->typeName() << " instance." << std::endl;
    std::cerr << "This should not happen under normal circumstances and indicates a bug in" << std::endl;
    std::cerr << "the framework. Contact a SUEP expert to fix the issue." << std::endl;
    throw;
  }
}

char const*
suep::Element::StoreManager::getName(Element const* _obj) const
{
  return getArray(_obj).getName();
}
