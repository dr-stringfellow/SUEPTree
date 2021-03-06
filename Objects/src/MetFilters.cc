#include "../interface/MetFilters.h"

/*static*/
suep::utils::BranchList
suep::MetFilters::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"globalHalo16", "hbhe", "hbheIso", "ecalDeadCell", "goodVertices", "badsc", "badMuons", "duplicateMuons", "badPFMuons", "badChargedHadrons", "ecalBadCalib"};
  return blist;
}

suep::MetFilters::MetFilters(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

suep::MetFilters::MetFilters(MetFilters const& _src) :
  Singlet(_src),
  globalHalo16(_src.globalHalo16),
  hbhe(_src.hbhe),
  hbheIso(_src.hbheIso),
  ecalDeadCell(_src.ecalDeadCell),
  goodVertices(_src.goodVertices),
  badsc(_src.badsc),
  badMuons(_src.badMuons),
  duplicateMuons(_src.duplicateMuons),
  badPFMuons(_src.badPFMuons),
  badChargedHadrons(_src.badChargedHadrons),
  ecalBadCalib(_src.ecalBadCalib)
{
  globalHalo16 = _src.globalHalo16;
  hbhe = _src.hbhe;
  hbheIso = _src.hbheIso;
  ecalDeadCell = _src.ecalDeadCell;
  goodVertices = _src.goodVertices;
  badsc = _src.badsc;
  badMuons = _src.badMuons;
  duplicateMuons = _src.duplicateMuons;
  badPFMuons = _src.badPFMuons;
  badChargedHadrons = _src.badChargedHadrons;
  ecalBadCalib = _src.ecalBadCalib;
}

suep::MetFilters::~MetFilters()
{
}

suep::MetFilters&
suep::MetFilters::operator=(MetFilters const& _src)
{
  globalHalo16 = _src.globalHalo16;
  hbhe = _src.hbhe;
  hbheIso = _src.hbheIso;
  ecalDeadCell = _src.ecalDeadCell;
  goodVertices = _src.goodVertices;
  badsc = _src.badsc;
  badMuons = _src.badMuons;
  duplicateMuons = _src.duplicateMuons;
  badPFMuons = _src.badPFMuons;
  badChargedHadrons = _src.badChargedHadrons;
  ecalBadCalib = _src.ecalBadCalib;

  /* BEGIN CUSTOM MetFilters.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::MetFilters::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "globalHalo16", _branches);
  utils::setStatus(_tree, name_, "hbhe", _branches);
  utils::setStatus(_tree, name_, "hbheIso", _branches);
  utils::setStatus(_tree, name_, "ecalDeadCell", _branches);
  utils::setStatus(_tree, name_, "goodVertices", _branches);
  utils::setStatus(_tree, name_, "badsc", _branches);
  utils::setStatus(_tree, name_, "badMuons", _branches);
  utils::setStatus(_tree, name_, "duplicateMuons", _branches);
  utils::setStatus(_tree, name_, "badPFMuons", _branches);
  utils::setStatus(_tree, name_, "badChargedHadrons", _branches);
  utils::setStatus(_tree, name_, "ecalBadCalib", _branches);
}

suep::utils::BranchList
suep::MetFilters::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "globalHalo16"));
  blist.push_back(utils::getStatus(_tree, name_, "hbhe"));
  blist.push_back(utils::getStatus(_tree, name_, "hbheIso"));
  blist.push_back(utils::getStatus(_tree, name_, "ecalDeadCell"));
  blist.push_back(utils::getStatus(_tree, name_, "goodVertices"));
  blist.push_back(utils::getStatus(_tree, name_, "badsc"));
  blist.push_back(utils::getStatus(_tree, name_, "badMuons"));
  blist.push_back(utils::getStatus(_tree, name_, "duplicateMuons"));
  blist.push_back(utils::getStatus(_tree, name_, "badPFMuons"));
  blist.push_back(utils::getStatus(_tree, name_, "badChargedHadrons"));
  blist.push_back(utils::getStatus(_tree, name_, "ecalBadCalib"));

  return blist;
}

void
suep::MetFilters::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "globalHalo16", &globalHalo16, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbhe", &hbhe, _branches, _setStatus);
  utils::setAddress(_tree, name_, "hbheIso", &hbheIso, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ecalDeadCell", &ecalDeadCell, _branches, _setStatus);
  utils::setAddress(_tree, name_, "goodVertices", &goodVertices, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badsc", &badsc, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badMuons", &badMuons, _branches, _setStatus);
  utils::setAddress(_tree, name_, "duplicateMuons", &duplicateMuons, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badPFMuons", &badPFMuons, _branches, _setStatus);
  utils::setAddress(_tree, name_, "badChargedHadrons", &badChargedHadrons, _branches, _setStatus);
  utils::setAddress(_tree, name_, "ecalBadCalib", &ecalBadCalib, _branches, _setStatus);
}

void
suep::MetFilters::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "globalHalo16", "", 'O', &globalHalo16, _branches);
  utils::book(_tree, name_, "hbhe", "", 'O', &hbhe, _branches);
  utils::book(_tree, name_, "hbheIso", "", 'O', &hbheIso, _branches);
  utils::book(_tree, name_, "ecalDeadCell", "", 'O', &ecalDeadCell, _branches);
  utils::book(_tree, name_, "goodVertices", "", 'O', &goodVertices, _branches);
  utils::book(_tree, name_, "badsc", "", 'O', &badsc, _branches);
  utils::book(_tree, name_, "badMuons", "", 'O', &badMuons, _branches);
  utils::book(_tree, name_, "duplicateMuons", "", 'O', &duplicateMuons, _branches);
  utils::book(_tree, name_, "badPFMuons", "", 'O', &badPFMuons, _branches);
  utils::book(_tree, name_, "badChargedHadrons", "", 'O', &badChargedHadrons, _branches);
  utils::book(_tree, name_, "ecalBadCalib", "", 'O', &ecalBadCalib, _branches);
}

void
suep::MetFilters::doInit_()
{
  globalHalo16 = false;
  hbhe = false;
  hbheIso = false;
  ecalDeadCell = false;
  goodVertices = false;
  badsc = false;
  badMuons = false;
  duplicateMuons = false;
  badPFMuons = false;
  badChargedHadrons = false;
  ecalBadCalib = false;

  /* BEGIN CUSTOM MetFilters.cc.doInit_ */
  /* END CUSTOM */
}

suep::utils::BranchList
suep::MetFilters::doGetBranchNames_(Bool_t _fullName) const
{
  if (_fullName)
    return getListOfBranches().fullNames(name_);
  else
    return getListOfBranches().fullNames();
}

void
suep::MetFilters::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM MetFilters.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::MetFilters::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "globalHalo16 = " << globalHalo16 << std::endl;
  _out << "hbhe = " << hbhe << std::endl;
  _out << "hbheIso = " << hbheIso << std::endl;
  _out << "ecalDeadCell = " << ecalDeadCell << std::endl;
  _out << "goodVertices = " << goodVertices << std::endl;
  _out << "badsc = " << badsc << std::endl;
  _out << "badMuons = " << badMuons << std::endl;
  _out << "duplicateMuons = " << duplicateMuons << std::endl;
  _out << "badPFMuons = " << badPFMuons << std::endl;
  _out << "badChargedHadrons = " << badChargedHadrons << std::endl;
  _out << "ecalBadCalib = " << ecalBadCalib << std::endl;
}


/* BEGIN CUSTOM MetFilters.cc.global */
/* END CUSTOM */
