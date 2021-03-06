#include "../interface/Particle.h"

/*static*/
suep::utils::BranchList
suep::Particle::getListOfBranches()
{
  utils::BranchList blist;
  return blist;
}

void
suep::Particle::datastore::allocate(UInt_t _nmax)
{
  Element::datastore::allocate(_nmax);

}

void
suep::Particle::datastore::deallocate()
{
  Element::datastore::deallocate();

}

void
suep::Particle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Element::datastore::setStatus(_tree, _name, _branches);

}

suep::utils::BranchList
suep::Particle::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Element::datastore::getStatus(_tree, _name));


  return blist;
}

void
suep::Particle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Element::datastore::setAddress(_tree, _name, _branches, _setStatus);

}

void
suep::Particle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Element::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

}

void
suep::Particle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Element::datastore::releaseTree(_tree, _name);

}

void
suep::Particle::datastore::resizeVectors_(UInt_t _size)
{
  Element::datastore::resizeVectors_(_size);

}


suep::utils::BranchList
suep::Particle::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Particle::getListOfBranches().fullNames(_name);
}

suep::Particle::Particle(datastore& _data, UInt_t _idx) :
  Element(_data, _idx)
{
}

suep::Particle::Particle(ArrayBase* _array) :
  Element(_array)
{
}

suep::Particle::~Particle()
{
  destructor();
}

void
suep::Particle::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Particle.cc.destructor */
  /* END CUSTOM */
}

suep::Particle&
suep::Particle::operator=(Particle const& _src)
{

  /* BEGIN CUSTOM Particle.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::Particle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
}

void
suep::Particle::doInit_()
{

  /* BEGIN CUSTOM Particle.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::Particle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Particle.cc.print */
  Particle::dump(_out);
  /* END CUSTOM */
}

void
suep::Particle::dump(std::ostream& _out/* = std::cout*/) const
{
}


/* BEGIN CUSTOM Particle.cc.global */
/* END CUSTOM */
