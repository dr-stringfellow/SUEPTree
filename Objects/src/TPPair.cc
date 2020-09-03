#include "../interface/TPPair.h"

/*static*/
suep::utils::BranchList
suep::TPPair::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"mass", "mass2"};
  return blist;
}

void
suep::TPPair::datastore::allocate(UInt_t _nmax)
{
  Element::datastore::allocate(_nmax);

  mass = new Float_t[nmax_];
  mass2 = new Float_t[nmax_];
}

void
suep::TPPair::datastore::deallocate()
{
  Element::datastore::deallocate();

  delete [] mass;
  mass = 0;
  delete [] mass2;
  mass2 = 0;
}

void
suep::TPPair::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "mass", _branches);
  utils::setStatus(_tree, _name, "mass2", _branches);
}

suep::utils::BranchList
suep::TPPair::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Element::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "mass"));
  blist.push_back(utils::getStatus(_tree, _name, "mass2"));

  return blist;
}

void
suep::TPPair::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "mass", mass, _branches, _setStatus);
  utils::setAddress(_tree, _name, "mass2", mass2, _branches, _setStatus);
}

void
suep::TPPair::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Element::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "mass", size, 'F', mass, _branches);
  utils::book(_tree, _name, "mass2", size, 'F', mass2, _branches);
}

void
suep::TPPair::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Element::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "mass");
  utils::resetAddress(_tree, _name, "mass2");
}

void
suep::TPPair::datastore::resizeVectors_(UInt_t _size)
{
  Element::datastore::resizeVectors_(_size);

}


suep::utils::BranchList
suep::TPPair::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return TPPair::getListOfBranches().fullNames(_name);
}

suep::TPPair::TPPair(char const* _name/* = ""*/) :
  Element(new TPPairArray(1, _name)),
  mass(gStore.getData(this).mass[0]),
  mass2(gStore.getData(this).mass2[0])
{
}

suep::TPPair::TPPair(TPPair const& _src) :
  Element(new TPPairArray(1, _src.getName())),
  mass(gStore.getData(this).mass[0]),
  mass2(gStore.getData(this).mass2[0])
{
  operator=(_src);
}

suep::TPPair::TPPair(datastore& _data, UInt_t _idx) :
  Element(_data, _idx),
  mass(_data.mass[_idx]),
  mass2(_data.mass2[_idx])
{
}

suep::TPPair::TPPair(ArrayBase* _array) :
  Element(_array),
  mass(gStore.getData(this).mass[0]),
  mass2(gStore.getData(this).mass2[0])
{
}

suep::TPPair::~TPPair()
{
  destructor();
}

void
suep::TPPair::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM TPPair.cc.destructor */
  /* END CUSTOM */
}

suep::TPPair&
suep::TPPair::operator=(TPPair const& _src)
{
  mass = _src.mass;
  mass2 = _src.mass2;

  /* BEGIN CUSTOM TPPair.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::TPPair::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, _name, "mass", "", 'F', &mass, _branches);
  utils::book(_tree, _name, "mass2", "", 'F', &mass2, _branches);
}

void
suep::TPPair::doInit_()
{
  mass = 0.;
  mass2 = 0.;

  /* BEGIN CUSTOM TPPair.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::TPPair::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM TPPair.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::TPPair::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "mass = " << mass << std::endl;
  _out << "mass2 = " << mass2 << std::endl;
}

/* BEGIN CUSTOM TPPair.cc.global */
/* END CUSTOM */
