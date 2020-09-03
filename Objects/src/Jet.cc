#include "../interface/Jet.h"

/*static*/
suep::utils::BranchList
suep::Jet::getListOfBranches()
{
  utils::BranchList blist;
  blist += MicroJet::getListOfBranches();
  blist += {"rawPt", "ptCorrUp", "ptCorrDown", "ptSmear", "ptSmearUp", "ptSmearDown", "area", "nhf", "chf", "cef", "nef", "puid", "loose", "tight", "tightLepVeto", "matchedGenJet_", "constituents_", "secondaryVertex_"};
  return blist;
}

void
suep::Jet::datastore::allocate(UInt_t _nmax)
{
  MicroJet::datastore::allocate(_nmax);

  rawPt = new Float_t[nmax_];
  ptCorrUp = new Float_t[nmax_];
  ptCorrDown = new Float_t[nmax_];
  ptSmear = new Float_t[nmax_];
  ptSmearUp = new Float_t[nmax_];
  ptSmearDown = new Float_t[nmax_];
  area = new Float_t[nmax_];
  nhf = new Float_t[nmax_];
  chf = new Float_t[nmax_];
  cef = new Float_t[nmax_];
  nef = new Float_t[nmax_];
  puid = new Float_t[nmax_];
  loose = new Bool_t[nmax_];
  tight = new Bool_t[nmax_];
  tightLepVeto = new Bool_t[nmax_];
  matchedGenJet_ = new Short_t[nmax_];
  constituents_ = new std::vector<std::vector<Short_t>>(nmax_);
  secondaryVertex_ = new Short_t[nmax_];
}

void
suep::Jet::datastore::deallocate()
{
  MicroJet::datastore::deallocate();

  delete [] rawPt;
  rawPt = 0;
  delete [] ptCorrUp;
  ptCorrUp = 0;
  delete [] ptCorrDown;
  ptCorrDown = 0;
  delete [] ptSmear;
  ptSmear = 0;
  delete [] ptSmearUp;
  ptSmearUp = 0;
  delete [] ptSmearDown;
  ptSmearDown = 0;
  delete [] area;
  area = 0;
  delete [] nhf;
  nhf = 0;
  delete [] chf;
  chf = 0;
  delete [] cef;
  cef = 0;
  delete [] nef;
  nef = 0;
  delete [] puid;
  puid = 0;
  delete [] loose;
  loose = 0;
  delete [] tight;
  tight = 0;
  delete [] tightLepVeto;
  tightLepVeto = 0;
  delete [] matchedGenJet_;
  matchedGenJet_ = 0;
  delete constituents_;
  constituents_ = 0;
  delete [] secondaryVertex_;
  secondaryVertex_ = 0;
}

void
suep::Jet::datastore::setStatus(TTree& _tree, TString const& _name, utils::BranchList const& _branches)
{
  MicroJet::datastore::setStatus(_tree, _name, _branches);

  utils::setStatus(_tree, _name, "rawPt", _branches);
  utils::setStatus(_tree, _name, "ptCorrUp", _branches);
  utils::setStatus(_tree, _name, "ptCorrDown", _branches);
  utils::setStatus(_tree, _name, "ptSmear", _branches);
  utils::setStatus(_tree, _name, "ptSmearUp", _branches);
  utils::setStatus(_tree, _name, "ptSmearDown", _branches);
  utils::setStatus(_tree, _name, "area", _branches);
  utils::setStatus(_tree, _name, "nhf", _branches);
  utils::setStatus(_tree, _name, "chf", _branches);
  utils::setStatus(_tree, _name, "cef", _branches);
  utils::setStatus(_tree, _name, "nef", _branches);
  utils::setStatus(_tree, _name, "puid", _branches);
  utils::setStatus(_tree, _name, "loose", _branches);
  utils::setStatus(_tree, _name, "tight", _branches);
  utils::setStatus(_tree, _name, "tightLepVeto", _branches);
  utils::setStatus(_tree, _name, "matchedGenJet_", _branches);
  utils::setStatus(_tree, _name, "constituents_", _branches);
  utils::setStatus(_tree, _name, "secondaryVertex_", _branches);
}

suep::utils::BranchList
suep::Jet::datastore::getStatus(TTree& _tree, TString const& _name) const
{
  utils::BranchList blist(MicroJet::datastore::getStatus(_tree, _name));

  blist.push_back(utils::getStatus(_tree, _name, "rawPt"));
  blist.push_back(utils::getStatus(_tree, _name, "ptCorrUp"));
  blist.push_back(utils::getStatus(_tree, _name, "ptCorrDown"));
  blist.push_back(utils::getStatus(_tree, _name, "ptSmear"));
  blist.push_back(utils::getStatus(_tree, _name, "ptSmearUp"));
  blist.push_back(utils::getStatus(_tree, _name, "ptSmearDown"));
  blist.push_back(utils::getStatus(_tree, _name, "area"));
  blist.push_back(utils::getStatus(_tree, _name, "nhf"));
  blist.push_back(utils::getStatus(_tree, _name, "chf"));
  blist.push_back(utils::getStatus(_tree, _name, "cef"));
  blist.push_back(utils::getStatus(_tree, _name, "nef"));
  blist.push_back(utils::getStatus(_tree, _name, "puid"));
  blist.push_back(utils::getStatus(_tree, _name, "loose"));
  blist.push_back(utils::getStatus(_tree, _name, "tight"));
  blist.push_back(utils::getStatus(_tree, _name, "tightLepVeto"));
  blist.push_back(utils::getStatus(_tree, _name, "matchedGenJet_"));
  blist.push_back(utils::getStatus(_tree, _name, "constituents_"));
  blist.push_back(utils::getStatus(_tree, _name, "secondaryVertex_"));

  return blist;
}

void
suep::Jet::datastore::setAddress(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  MicroJet::datastore::setAddress(_tree, _name, _branches, _setStatus);

  utils::setAddress(_tree, _name, "rawPt", rawPt, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrUp", ptCorrUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptCorrDown", ptCorrDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmear", ptSmear, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearUp", ptSmearUp, _branches, _setStatus);
  utils::setAddress(_tree, _name, "ptSmearDown", ptSmearDown, _branches, _setStatus);
  utils::setAddress(_tree, _name, "area", area, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nhf", nhf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "chf", chf, _branches, _setStatus);
  utils::setAddress(_tree, _name, "cef", cef, _branches, _setStatus);
  utils::setAddress(_tree, _name, "nef", nef, _branches, _setStatus);
  utils::setAddress(_tree, _name, "puid", puid, _branches, _setStatus);
  utils::setAddress(_tree, _name, "loose", loose, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tight", tight, _branches, _setStatus);
  utils::setAddress(_tree, _name, "tightLepVeto", tightLepVeto, _branches, _setStatus);
  utils::setAddress(_tree, _name, "matchedGenJet_", matchedGenJet_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "constituents_", &constituents_, _branches, _setStatus);
  utils::setAddress(_tree, _name, "secondaryVertex_", secondaryVertex_, _branches, _setStatus);
}

void
suep::Jet::datastore::book(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _dynamic/* = kTRUE*/)
{
  MicroJet::datastore::book(_tree, _name, _branches, _dynamic);

  TString size(_dynamic ? "[" + _name + ".size]" : TString::Format("[%d]", nmax_));

  utils::book(_tree, _name, "rawPt", size, 'F', rawPt, _branches);
  utils::book(_tree, _name, "ptCorrUp", size, 'F', ptCorrUp, _branches);
  utils::book(_tree, _name, "ptCorrDown", size, 'F', ptCorrDown, _branches);
  utils::book(_tree, _name, "ptSmear", size, 'F', ptSmear, _branches);
  utils::book(_tree, _name, "ptSmearUp", size, 'F', ptSmearUp, _branches);
  utils::book(_tree, _name, "ptSmearDown", size, 'F', ptSmearDown, _branches);
  utils::book(_tree, _name, "area", size, 'F', area, _branches);
  utils::book(_tree, _name, "nhf", size, 'F', nhf, _branches);
  utils::book(_tree, _name, "chf", size, 'F', chf, _branches);
  utils::book(_tree, _name, "cef", size, 'F', cef, _branches);
  utils::book(_tree, _name, "nef", size, 'F', nef, _branches);
  utils::book(_tree, _name, "puid", size, 'F', puid, _branches);
  utils::book(_tree, _name, "loose", size, 'O', loose, _branches);
  utils::book(_tree, _name, "tight", size, 'O', tight, _branches);
  utils::book(_tree, _name, "tightLepVeto", size, 'O', tightLepVeto, _branches);
  utils::book(_tree, _name, "matchedGenJet_", size, 'S', matchedGenJet_, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<std::vector<Short_t>>", &constituents_, _branches);
  utils::book(_tree, _name, "secondaryVertex_", size, 'S', secondaryVertex_, _branches);
}

void
suep::Jet::datastore::releaseTree(TTree& _tree, TString const& _name)
{
  MicroJet::datastore::releaseTree(_tree, _name);

  utils::resetAddress(_tree, _name, "rawPt");
  utils::resetAddress(_tree, _name, "ptCorrUp");
  utils::resetAddress(_tree, _name, "ptCorrDown");
  utils::resetAddress(_tree, _name, "ptSmear");
  utils::resetAddress(_tree, _name, "ptSmearUp");
  utils::resetAddress(_tree, _name, "ptSmearDown");
  utils::resetAddress(_tree, _name, "area");
  utils::resetAddress(_tree, _name, "nhf");
  utils::resetAddress(_tree, _name, "chf");
  utils::resetAddress(_tree, _name, "cef");
  utils::resetAddress(_tree, _name, "nef");
  utils::resetAddress(_tree, _name, "puid");
  utils::resetAddress(_tree, _name, "loose");
  utils::resetAddress(_tree, _name, "tight");
  utils::resetAddress(_tree, _name, "tightLepVeto");
  utils::resetAddress(_tree, _name, "matchedGenJet_");
  utils::resetAddress(_tree, _name, "constituents_");
  utils::resetAddress(_tree, _name, "secondaryVertex_");
}

void
suep::Jet::datastore::resizeVectors_(UInt_t _size)
{
  MicroJet::datastore::resizeVectors_(_size);

  constituents_->resize(_size);
}


suep::utils::BranchList
suep::Jet::datastore::getBranchNames(TString const& _name/* = ""*/) const
{
  return Jet::getListOfBranches().fullNames(_name);
}

suep::Jet::Jet(char const* _name/* = ""*/) :
  MicroJet(new JetArray(1, _name)),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  area(gStore.getData(this).area[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  cef(gStore.getData(this).cef[0]),
  nef(gStore.getData(this).nef[0]),
  puid(gStore.getData(this).puid[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  tightLepVeto(gStore.getData(this).tightLepVeto[0]),
  matchedGenJet(gStore.getData(this).matchedGenJetContainer_, gStore.getData(this).matchedGenJet_[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0]),
  secondaryVertex(gStore.getData(this).secondaryVertexContainer_, gStore.getData(this).secondaryVertex_[0])
{
}

suep::Jet::Jet(Jet const& _src) :
  MicroJet(new JetArray(1, _src.getName())),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  area(gStore.getData(this).area[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  cef(gStore.getData(this).cef[0]),
  nef(gStore.getData(this).nef[0]),
  puid(gStore.getData(this).puid[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  tightLepVeto(gStore.getData(this).tightLepVeto[0]),
  matchedGenJet(gStore.getData(this).matchedGenJetContainer_, gStore.getData(this).matchedGenJet_[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0]),
  secondaryVertex(gStore.getData(this).secondaryVertexContainer_, gStore.getData(this).secondaryVertex_[0])
{
  operator=(_src);
}

suep::Jet::Jet(datastore& _data, UInt_t _idx) :
  MicroJet(_data, _idx),
  rawPt(_data.rawPt[_idx]),
  ptCorrUp(_data.ptCorrUp[_idx]),
  ptCorrDown(_data.ptCorrDown[_idx]),
  ptSmear(_data.ptSmear[_idx]),
  ptSmearUp(_data.ptSmearUp[_idx]),
  ptSmearDown(_data.ptSmearDown[_idx]),
  area(_data.area[_idx]),
  nhf(_data.nhf[_idx]),
  chf(_data.chf[_idx]),
  cef(_data.cef[_idx]),
  nef(_data.nef[_idx]),
  puid(_data.puid[_idx]),
  loose(_data.loose[_idx]),
  tight(_data.tight[_idx]),
  tightLepVeto(_data.tightLepVeto[_idx]),
  matchedGenJet(_data.matchedGenJetContainer_, _data.matchedGenJet_[_idx]),
  constituents(_data.constituentsContainer_, (*_data.constituents_)[_idx]),
  secondaryVertex(_data.secondaryVertexContainer_, _data.secondaryVertex_[_idx])
{
}

suep::Jet::Jet(ArrayBase* _array) :
  MicroJet(_array),
  rawPt(gStore.getData(this).rawPt[0]),
  ptCorrUp(gStore.getData(this).ptCorrUp[0]),
  ptCorrDown(gStore.getData(this).ptCorrDown[0]),
  ptSmear(gStore.getData(this).ptSmear[0]),
  ptSmearUp(gStore.getData(this).ptSmearUp[0]),
  ptSmearDown(gStore.getData(this).ptSmearDown[0]),
  area(gStore.getData(this).area[0]),
  nhf(gStore.getData(this).nhf[0]),
  chf(gStore.getData(this).chf[0]),
  cef(gStore.getData(this).cef[0]),
  nef(gStore.getData(this).nef[0]),
  puid(gStore.getData(this).puid[0]),
  loose(gStore.getData(this).loose[0]),
  tight(gStore.getData(this).tight[0]),
  tightLepVeto(gStore.getData(this).tightLepVeto[0]),
  matchedGenJet(gStore.getData(this).matchedGenJetContainer_, gStore.getData(this).matchedGenJet_[0]),
  constituents(gStore.getData(this).constituentsContainer_, (*gStore.getData(this).constituents_)[0]),
  secondaryVertex(gStore.getData(this).secondaryVertexContainer_, gStore.getData(this).secondaryVertex_[0])
{
}

suep::Jet::~Jet()
{
  destructor();
}

void
suep::Jet::destructor(Bool_t _recursive/* = kFALSE*/)
{
  /* BEGIN CUSTOM Jet.cc.destructor */
  /* END CUSTOM */

  if (_recursive)
    MicroJet::destructor(kTRUE);
}

suep::Jet&
suep::Jet::operator=(Jet const& _src)
{
  MicroJet::operator=(_src);

  rawPt = _src.rawPt;
  ptCorrUp = _src.ptCorrUp;
  ptCorrDown = _src.ptCorrDown;
  ptSmear = _src.ptSmear;
  ptSmearUp = _src.ptSmearUp;
  ptSmearDown = _src.ptSmearDown;
  area = _src.area;
  nhf = _src.nhf;
  chf = _src.chf;
  cef = _src.cef;
  nef = _src.nef;
  puid = _src.puid;
  loose = _src.loose;
  tight = _src.tight;
  tightLepVeto = _src.tightLepVeto;
  matchedGenJet = _src.matchedGenJet;
  constituents = _src.constituents;
  secondaryVertex = _src.secondaryVertex;

  /* BEGIN CUSTOM Jet.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::Jet::doBook_(TTree& _tree, TString const& _name, utils::BranchList const& _branches/* = {"*"}*/)
{
  MicroJet::doBook_(_tree, _name, _branches);

  utils::book(_tree, _name, "rawPt", "", 'F', &rawPt, _branches);
  utils::book(_tree, _name, "ptCorrUp", "", 'F', &ptCorrUp, _branches);
  utils::book(_tree, _name, "ptCorrDown", "", 'F', &ptCorrDown, _branches);
  utils::book(_tree, _name, "ptSmear", "", 'F', &ptSmear, _branches);
  utils::book(_tree, _name, "ptSmearUp", "", 'F', &ptSmearUp, _branches);
  utils::book(_tree, _name, "ptSmearDown", "", 'F', &ptSmearDown, _branches);
  utils::book(_tree, _name, "area", "", 'F', &area, _branches);
  utils::book(_tree, _name, "nhf", "", 'F', &nhf, _branches);
  utils::book(_tree, _name, "chf", "", 'F', &chf, _branches);
  utils::book(_tree, _name, "cef", "", 'F', &cef, _branches);
  utils::book(_tree, _name, "nef", "", 'F', &nef, _branches);
  utils::book(_tree, _name, "puid", "", 'F', &puid, _branches);
  utils::book(_tree, _name, "loose", "", 'O', &loose, _branches);
  utils::book(_tree, _name, "tight", "", 'O', &tight, _branches);
  utils::book(_tree, _name, "tightLepVeto", "", 'O', &tightLepVeto, _branches);
  utils::book(_tree, _name, "matchedGenJet_", "", 'S', gStore.getData(this).matchedGenJet_, _branches);
  utils::book(_tree, _name, "constituents_", "std::vector<Short_t>", &constituents.indices(), _branches);
  utils::book(_tree, _name, "secondaryVertex_", "", 'S', gStore.getData(this).secondaryVertex_, _branches);
}

void
suep::Jet::doInit_()
{
  MicroJet::doInit_();

  rawPt = 0.;
  ptCorrUp = 0.;
  ptCorrDown = 0.;
  ptSmear = 0.;
  ptSmearUp = 0.;
  ptSmearDown = 0.;
  area = 0.;
  nhf = 0.;
  chf = 0.;
  cef = 0.;
  nef = 0.;
  puid = 0.;
  loose = false;
  tight = false;
  tightLepVeto = false;
  matchedGenJet.init();
  constituents.init();
  secondaryVertex.init();

  /* BEGIN CUSTOM Jet.cc.doInit_ */
  /* END CUSTOM */
}

void
suep::Jet::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Jet.cc.print */
  if (_level >= 3) {
    Jet::dump(_out);
  }
  else if (_level == 2) {
    MicroJet::print(_out, _level);

    _out << "rawPt = " << rawPt << std::endl;
    _out << "area = " << area << std::endl;
    _out << "nhf = " << nhf << std::endl;
    _out << "chf = " << chf << std::endl;
    _out << "puid = " << puid << std::endl;
    _out << "loose = " << loose << std::endl;
    _out << "tight = " << tight << std::endl;
  }
  else
    return;
  /* END CUSTOM */
}

void
suep::Jet::dump(std::ostream& _out/* = std::cout*/) const
{
  MicroJet::dump(_out);

  _out << "rawPt = " << rawPt << std::endl;
  _out << "ptCorrUp = " << ptCorrUp << std::endl;
  _out << "ptCorrDown = " << ptCorrDown << std::endl;
  _out << "ptSmear = " << ptSmear << std::endl;
  _out << "ptSmearUp = " << ptSmearUp << std::endl;
  _out << "ptSmearDown = " << ptSmearDown << std::endl;
  _out << "area = " << area << std::endl;
  _out << "nhf = " << nhf << std::endl;
  _out << "chf = " << chf << std::endl;
  _out << "cef = " << cef << std::endl;
  _out << "nef = " << nef << std::endl;
  _out << "puid = " << puid << std::endl;
  _out << "loose = " << loose << std::endl;
  _out << "tight = " << tight << std::endl;
  _out << "tightLepVeto = " << tightLepVeto << std::endl;
  _out << "matchedGenJet = " << matchedGenJet << std::endl;
  _out << "constituents = " << constituents << std::endl;
  _out << "secondaryVertex = " << secondaryVertex << std::endl;
}

/* BEGIN CUSTOM Jet.cc.global */
/* END CUSTOM */
