#include "../interface/Parton.h"

/*static*/
suep::utils::BranchList
suep::Parton::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleM::getListOfBranches();
  blist += {"pdgid"};
  return blist;
}

void
suep::Parton::datastore::allocate(UInt_t _nmax)
{
  ParticleM::datastore::allocate(_nmax);

  pdgid = new Int_t[nmax_];
}

void
suep::Parton::datastore::deallocate()
{
  ParticleM::datastore::deallocate();

  delete [] pdgid;
  pdgid = 0;
}

void
suep::Parton::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleM::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pdgid", _branches);
}

suep::utils::BranchList
suep::Parton::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleM::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pdgid"));

  return blist;
}

void
suep::Parton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleM::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pdgid", pdgid, _branches, _setStatus);
}

void
suep::Parton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleM::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pdgid", size, 'I', pdgid, _branches);
}

void
suep::Parton::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleM::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pdgid");
}

void
suep::Parton::datastore::resizeVectors_(UInt_t _size)
{
  ParticleM::datastore::resizeVectors_(_size);

}


suep::utils::BranchList
suep::Parton::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Parton::getListOfBranches().fullNames(_name);
}

suep::Parton::Parton(char const* _name/* = ""*/) :
  ParticleM(new PartonArray(1, _name)),
  pdgid(gStore.getData(this).pdgid[0])
{
}

suep::Parton::Parton(Parton const& _src) :
  ParticleM(new PartonArray(1, _src.getName())),
  pdgid(gStore.getData(this).pdgid[0])
{
  operator=(_src);
}

suep::Parton::Parton(datastore& _data, UInt_t _idx) :
  ParticleM(_data, _idx),
  pdgid(_data.pdgid[_idx])
{
}

suep::Parton::Parton(ArrayBase* _array) :
  ParticleM(_array),
  pdgid(gStore.getData(this).pdgid[0])
{
}

suep::Parton::~Parton()
{
  destructor();
}

void
suep::Parton::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Parton.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    ParticleM::destructor(kTRUE);
}

suep::Parton&
suep::Parton::operator=(Parton const& _src)
{
  ParticleM::operator=(_src);

  pdgid = _src.pdgid;

  /* BEGIN CUSTOM Parton.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::Parton::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleM::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pdgid", "", 'I', &pdgid, _branches);
}

void
suep::Parton::doInit_()
{
  ParticleM::doInit_();

  pdgid = 0;

  /* BEGIN CUSTOM Parton.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::Parton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Parton.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::Parton::dump(std::ostream& _out/* = std::cout*/) const
{
  ParticleM::dump(_out);

  _out << "pdgid = " << pdgid << std::endl;
}

/* BEGIN CUSTOM Parton.cc.global */
/* END CUSTOM */
