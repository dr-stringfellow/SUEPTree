#include "../interface/Lepton.h"

/*static*/
suep::utils::BranchList
suep::Lepton::getListOfBranches()
{
  utils::BranchList blist;
  blist += ParticleP::getListOfBranches();
  blist += {"pfPt", "charge", "loose", "medium", "tight", "hltsafe", "chIso", "nhIso", "phIso", "puIso", "dxy", "dz", "matchedPF_", "matchedGen_", "vertex_"};
  return blist;
}

void
suep::Lepton::datastore::allocate(UInt_t _nmax)
{
  ParticleP::datastore::allocate(_nmax);

  pfPt = new Float_t[nmax_];
  charge = new Char_t[nmax_];
  loose = new Bool_t[nmax_];
  medium = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  hltsafe = new Bool_t[nmax_];
  chIso = new Float_t[nmax_];
  nhIso = new Float_t[nmax_];
  phIso = new Float_t[nmax_];
  puIso = new Float_t[nmax_];
  dxy = new Float_t[nmax_];
  dz = new Float_t[nmax_];
  matchedPF_ = new Short_t[nmax_];
  matchedGen_ = new Short_t[nmax_];
  vertex_ = new Short_t[nmax_];
}

void
suep::Lepton::datastore::deallocate()
{
  ParticleP::datastore::deallocate();

  delete [] pfPt;
  pfPt = 0;
  delete [] charge;
  charge = 0;
  delete [] loose;
  loose = 0;
  delete [] medium;
  medium = 0;
  delete [] tight;
  tight = 0;
  delete [] hltsafe;
  hltsafe = 0;
  delete [] chIso;
  chIso = 0;
  delete [] nhIso;
  nhIso = 0;
  delete [] phIso;
  phIso = 0;
  delete [] puIso;
  puIso = 0;
  delete [] dxy;
  dxy = 0;
  delete [] dz;
  dz = 0;
  delete [] matchedPF_;
  matchedPF_ = 0;
  delete [] matchedGen_;
  matchedGen_ = 0;
  delete [] vertex_;
  vertex_ = 0;
}

void
suep::Lepton::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  ParticleP::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "pfPt", _branches);
  utils::setStatus(_tree, _name, "charge", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "medium", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "hltsafe", _branches);
  utils::setStatus(_tree, _name, "chIso", _branches);
  utils::setStatus(_tree, _name, "nhIso", _branches);
  utils::setStatus(_tree, _name, "phIso", _branches);
  utils::setStatus(_tree, _name, "puIso", _branches);
  utils::setStatus(_tree, _name, "dxy", _branches);
  utils::setStatus(_tree, _name, "dz", _branches);
  utils::setStatus(_tree, _name, "matchedPF_", _branches);
  utils::setStatus(_tree, _name, "matchedGen_", _branches);
  utils::setStatus(_tree, _name, "vertex_", _branches);
}

suep::utils::BranchList
suep::Lepton::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(ParticleP::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "pfPt"));
  blist.push_back(utils::getStatus(_tree, _name, "charge"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "medium"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "hltsafe"));
  blist.push_back(utils::getStatus(_tree, _name, "chIso"));
  blist.push_back(utils::getStatus(_tree, _name, "nhIso"));
  blist.push_back(utils::getStatus(_tree, _name, "phIso"));
  blist.push_back(utils::getStatus(_tree, _name, "puIso"));
  blist.push_back(utils::getStatus(_tree, _name, "dxy"));
  blist.push_back(utils::getStatus(_tree, _name, "dz"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedPF_"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGen_"));
  blist.push_back(utils::getStatus(_tree, _name, "vertex_"));

  return blist;
}

void
suep::Lepton::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  ParticleP::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "pfPt", pfPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "charge", charge, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "medium", medium, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "hltsafe", hltsafe, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chIso", chIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhIso", nhIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "phIso", phIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puIso", puIso, _branches, _setStatus);
  utils::setAddress(_tree, _name, "dxy", dxy, _branches, _setStatus);
  utils::setAddress(_tree, _name, "dz", dz, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedPF_", matchedPF_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGen_", matchedGen_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "vertex_", vertex_, _branches, _setStatus);
}

void
suep::Lepton::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  ParticleP::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "pfPt", size, 'F', pfPt, _branches);
  utils::book(_tree, _name, "charge", size, 'B', charge, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "medium", size, 'O', medium, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "hltsafe", size, 'O', hltsafe, _branches);
  utils::book(_tree, _name, "chIso", size, 'F', chIso, _branches);
  utils::book(_tree, _name, "nhIso", size, 'F', nhIso, _branches);
  utils::book(_tree, _name, "phIso", size, 'F', phIso, _branches);
  utils::book(_tree, _name, "puIso", size, 'F', puIso, _branches);
  utils::book(_tree, _name, "dxy", size, 'F', dxy, _branches);
  utils::book(_tree, _name, "dz", size, 'F', dz, _branches);
  utils::book(_tree, _name, "matchedPF_", size, 'S', matchedPF_, _branches);
  utils::book(_tree, _name, "matchedGen_", size, 'S', matchedGen_, _branches);
  utils::book(_tree, _name, "vertex_", size, 'S', vertex_, _branches);
}

void
suep::Lepton::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  ParticleP::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "pfPt");
  utils::resetAddress(_tree, _name, "charge");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "medium");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "hltsafe");
  utils::resetAddress(_tree, _name, "chIso");
  utils::resetAddress(_tree, _name, "nhIso");
  utils::resetAddress(_tree, _name, "phIso");
  utils::resetAddress(_tree, _name, "puIso");
  utils::resetAddress(_tree, _name, "dxy");
  utils::resetAddress(_tree, _name, "dz");
  utils::resetAddress(_tree, _name, "matchedPF_");
  utils::resetAddress(_tree, _name, "matchedGen_");
  utils::resetAddress(_tree, _name, "vertex_");
}

void
suep::Lepton::datastore::resizeVectors_(UInt_t _size)
{
  ParticleP::datastore::resizeVectors_(_size);

}


suep::utils::BranchList
suep::Lepton::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Lepton::getListOfBranches().fullNames(_name);
}

suep::Lepton::Lepton(char const* _name/* = ""*/) :
  ParticleP(new LeptonArray(1, _name)),
  pfPt(gStore.getData(this).pfPt[0]),
  charge(gStore.getData(this).charge[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  hltsafe(gStore.getData(this).hltsafe[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  puIso(gStore.getData(this).puIso[0]),
  dxy(gStore.getData(this).dxy[0]),
  dz(gStore.getData(this).dz[0]),
  matchedPF(gStore.getData(this).matchedPFContainer_, gStore.getData(this).matchedPF_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0]),
  vertex(gStore.getData(this).vertexContainer_, gStore.getData(this).vertex_[0])
{
}

suep::Lepton::Lepton(Lepton const& _src) :
  ParticleP(new LeptonArray(1, _src.getName())),
  pfPt(gStore.getData(this).pfPt[0]),
  charge(gStore.getData(this).charge[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  hltsafe(gStore.getData(this).hltsafe[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  puIso(gStore.getData(this).puIso[0]),
  dxy(gStore.getData(this).dxy[0]),
  dz(gStore.getData(this).dz[0]),
  matchedPF(gStore.getData(this).matchedPFContainer_, gStore.getData(this).matchedPF_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0]),
  vertex(gStore.getData(this).vertexContainer_, gStore.getData(this).vertex_[0])
{
  operator=(_src);
}

suep::Lepton::Lepton(datastore& _data, UInt_t _idx) :
  ParticleP(_data, _idx),
  pfPt(_data.pfPt[_idx]),
  charge(_data.charge[_idx]),
  loose(_data.loose[_idx]),
  medium(_data.medium[_idx]),
  tight(_data.tight[_idx]),
  hltsafe(_data.hltsafe[_idx]),
  chIso(_data.chIso[_idx]),
  nhIso(_data.nhIso[_idx]),
  phIso(_data.phIso[_idx]),
  puIso(_data.puIso[_idx]),
  dxy(_data.dxy[_idx]),
  dz(_data.dz[_idx]),
  matchedPF(_data.matchedPFContainer_, _data.matchedPF_[_idx]),
  matchedGen(_data.matchedGenContainer_, _data.matchedGen_[_idx]),
  vertex(_data.vertexContainer_, _data.vertex_[_idx])
{
}

suep::Lepton::Lepton(ArrayBase* _array) :
  ParticleP(_array),
  pfPt(gStore.getData(this).pfPt[0]),
  charge(gStore.getData(this).charge[0]),
  loose(gStore.getData(this).loose[0]),
  medium(gStore.getData(this).medium[0]),
  tight(gStore.getData(this).tight[0]),
  hltsafe(gStore.getData(this).hltsafe[0]),
  chIso(gStore.getData(this).chIso[0]),
  nhIso(gStore.getData(this).nhIso[0]),
  phIso(gStore.getData(this).phIso[0]),
  puIso(gStore.getData(this).puIso[0]),
  dxy(gStore.getData(this).dxy[0]),
  dz(gStore.getData(this).dz[0]),
  matchedPF(gStore.getData(this).matchedPFContainer_, gStore.getData(this).matchedPF_[0]),
  matchedGen(gStore.getData(this).matchedGenContainer_, gStore.getData(this).matchedGen_[0]),
  vertex(gStore.getData(this).vertexContainer_, gStore.getData(this).vertex_[0])
{
}

suep::Lepton::~Lepton()
{
  destructor();
}

void
suep::Lepton::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Lepton.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    ParticleP::destructor(kTRUE);
}

suep::Lepton&
suep::Lepton::operator=(Lepton const& _src)
{
  ParticleP::operator=(_src);

  pfPt = _src.pfPt;
  charge = _src.charge;
  loose = _src.loose;
  medium = _src.medium;
  tight = _src.tight;
  hltsafe = _src.hltsafe;
  chIso = _src.chIso;
  nhIso = _src.nhIso;
  phIso = _src.phIso;
  puIso = _src.puIso;
  dxy = _src.dxy;
  dz = _src.dz;
  matchedPF = _src.matchedPF;
  matchedGen = _src.matchedGen;
  vertex = _src.vertex;

  /* BEGIN CUSTOM Lepton.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::Lepton::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  ParticleP::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "pfPt", "", 'F', &pfPt, _branches);
  utils::book(_tree, _name, "charge", "", 'B', &charge, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "medium", "", 'O', &medium, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "hltsafe", "", 'O', &hltsafe, _branches);
  utils::book(_tree, _name, "chIso", "", 'F', &chIso, _branches);
  utils::book(_tree, _name, "nhIso", "", 'F', &nhIso, _branches);
  utils::book(_tree, _name, "phIso", "", 'F', &phIso, _branches);
  utils::book(_tree, _name, "puIso", "", 'F', &puIso, _branches);
  utils::book(_tree, _name, "dxy", "", 'F', &dxy, _branches);
  utils::book(_tree, _name, "dz", "", 'F', &dz, _branches);
  utils::book(_tree, _name, "matchedPF_", "", 'S', gStore.getData(this).matchedPF_, _branches);
  utils::book(_tree, _name, "matchedGen_", "", 'S', gStore.getData(this).matchedGen_, _branches);
  utils::book(_tree, _name, "vertex_", "", 'S', gStore.getData(this).vertex_, _branches);
}

void
suep::Lepton::doInit_()
{
  ParticleP::doInit_();

  pfPt = -1.;
  charge = 0;
  loose = false;
  medium = false;
  tight = false;
  hltsafe = false;
  chIso = 0.;
  nhIso = 0.;
  phIso = 0.;
  puIso = 0.;
  dxy = 0.;
  dz = 0.;
  matchedPF.init();
  matchedGen.init();
  vertex.init();

  /* BEGIN CUSTOM Lepton.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::Lepton::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Lepton.cc.print */
  if (_level >= 3) {
    Lepton::dump(_out);
  }
  else if (_level == 2) {
    ParticleP::print(_out, _level);

    _out << "pfPt = " << pfPt << std::endl;
    _out << "charge = " << charge << std::endl;
    _out << "loose = " << loose << std::endl;
    _out << "medium = " << medium << std::endl;
    _out << "tight = " << tight << std::endl;
  }
  else
    return;
  /* END CUSTOM */
}

void
suep::Lepton::dump(std::ostream& _out/* = std::cout*/) const
{
  ParticleP::dump(_out);

  _out << "pfPt = " << pfPt << std::endl;
  _out << "charge = " << static_cast<const Int_t>(charge) << std::endl;
  _out << "loose = " << loose << std::endl;
  _out << "medium = " << medium << std::endl;
  _out << "tight = " << tight << std::endl;
  _out << "hltsafe = " << hltsafe << std::endl;
  _out << "chIso = " << chIso << std::endl;
  _out << "nhIso = " << nhIso << std::endl;
  _out << "phIso = " << phIso << std::endl;
  _out << "puIso = " << puIso << std::endl;
  _out << "dxy = " << dxy << std::endl;
  _out << "dz = " << dz << std::endl;
  _out << "matchedPF = " << matchedPF << std::endl;
  _out << "matchedGen = " << matchedGen << std::endl;
  _out << "vertex = " << vertex << std::endl;
}


/* BEGIN CUSTOM Lepton.cc.global */
/* END CUSTOM */
