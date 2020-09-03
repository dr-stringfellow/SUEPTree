#include "../interface/PackedParticle.h"

/*static*/
suep::utils::BranchList
suep::PackedParticle::getListOfBranches()
{
  utils::BranchList blist;
  blist += Particle::getListOfBranches();
  blist += PackedMomentumMixin::getListOfBranches();
  return blist;
}

void
suep::PackedParticle::datastore::allocate(UInt_t _nmax)
{
  Particle::datastore::allocate(_nmax);

  packedPt = new UShort_t[nmax_];
  packedEta = new Short_t[nmax_];
  packedPhi = new Short_t[nmax_];
  packedM = new UShort_t[nmax_];
}

void
suep::PackedParticle::datastore::deallocate()
{
  Particle::datastore::deallocate();

  delete [] packedPt;
  packedPt = 0;
  delete [] packedEta;
  packedEta = 0;
  delete [] packedPhi;
  packedPhi = 0;
  delete [] packedM;
  packedM = 0;
}

void
suep::PackedParticle::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  Particle::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "packedPt", _branches);
  utils::setStatus(_tree, _name, "packedEta", _branches);
  utils::setStatus(_tree, _name, "packedPhi", _branches);
  utils::setStatus(_tree, _name, "packedM", _branches);
}

suep::utils::BranchList
suep::PackedParticle::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(Particle::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "packedPt"));
  blist.push_back(utils::getStatus(_tree, _name, "packedEta"));
  blist.push_back(utils::getStatus(_tree, _name, "packedPhi"));
  blist.push_back(utils::getStatus(_tree, _name, "packedM"));

  return blist;
}

void
suep::PackedParticle::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  Particle::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "packedPt", packedPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedEta", packedEta, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedPhi", packedPhi, _branches, _setStatus);
  utils::setAddress(_tree, _name, "packedM", packedM, _branches, _setStatus);
}

void
suep::PackedParticle::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  Particle::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "packedPt", size, 's', packedPt, _branches);
  utils::book(_tree, _name, "packedEta", size, 'S', packedEta, _branches);
  utils::book(_tree, _name, "packedPhi", size, 'S', packedPhi, _branches);
  utils::book(_tree, _name, "packedM", size, 's', packedM, _branches);
}

void
suep::PackedParticle::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  Particle::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "packedPt");
  utils::resetAddress(_tree, _name, "packedEta");
  utils::resetAddress(_tree, _name, "packedPhi");
  utils::resetAddress(_tree, _name, "packedM");
}

void
suep::PackedParticle::datastore::resizeVectors_(UInt_t _size)
{
  Particle::datastore::resizeVectors_(_size);

}


suep::utils::BranchList
suep::PackedParticle::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return PackedParticle::getListOfBranches().fullNames(_name);
}

suep::PackedParticle::PackedParticle(char const* _name/* = ""*/) :
  Particle(new PackedParticleArray(1, _name)),
  PackedMomentumMixin(gStore.getData(this), 0)
{
}

suep::PackedParticle::PackedParticle(PackedParticle const& _src) :
  Particle(new PackedParticleArray(1, _src.getName())),
  PackedMomentumMixin(gStore.getData(this), 0)
{
  operator=(_src);
}

suep::PackedParticle::PackedParticle(datastore& _data, UInt_t _idx) :
  Particle(_data, _idx),
  PackedMomentumMixin(_data, _idx)
{
}

suep::PackedParticle::PackedParticle(ArrayBase* _array) :
  Particle(_array),
  PackedMomentumMixin(gStore.getData(this), 0)
{
}

suep::PackedParticle::~PackedParticle()
{
  destructor();
}

void
suep::PackedParticle::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM PackedParticle.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    Particle::destructor(kTRUE);
}

suep::PackedParticle&
suep::PackedParticle::operator=(PackedParticle const& _src)
{
  Particle::operator=(_src);

  packedPt = _src.packedPt;
  packedEta = _src.packedEta;
  packedPhi = _src.packedPhi;
  packedM = _src.packedM;

  /* BEGIN CUSTOM PackedParticle.cc.operator= */
  pt_ = _src.pt_;
  eta_ = _src.eta_;
  phi_ = _src.phi_;
  mass_ = _src.mass_;
  unpacked_ = _src.unpacked_;
  /* END CUSTOM */

  return *this;
}

void
suep::PackedParticle::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  Particle::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "packedPt", "", 's', &packedPt, _branches);
  utils::book(_tree, _name, "packedEta", "", 'S', &packedEta, _branches);
  utils::book(_tree, _name, "packedPhi", "", 'S', &packedPhi, _branches);
  utils::book(_tree, _name, "packedM", "", 's', &packedM, _branches);
}

void
suep::PackedParticle::doInit_()
{
  Particle::doInit_();

  packedPt = 0;
  packedEta = 0;
  packedPhi = 0;
  packedM = 0;

  /* BEGIN CUSTOM PackedParticle.cc.doInit_ */
  pt_ = 0.;
  eta_ = 0.;
  phi_ = 0.;
  mass_ = 0.;
  unpacked_ = kFALSE;
  /* END CUSTOM */
}

void
suep::PackedParticle::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM PackedParticle.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::PackedParticle::dump(std::ostream& _out/* = std::cout*/) const
{
  Particle::dump(_out);

  _out << "packedPt = " << packedPt << std::endl;
  _out << "packedEta = " << packedEta << std::endl;
  _out << "packedPhi = " << packedPhi << std::endl;
  _out << "packedM = " << packedM << std::endl;
}


/* BEGIN CUSTOM PackedParticle.cc.global */
/* END CUSTOM */
