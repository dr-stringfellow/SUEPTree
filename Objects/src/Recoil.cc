#include "../interface/Recoil.h"

TString suep::Recoil::CategoryName[] = {
  "rMET",
  "rMonoMu",
  "rMonoE",
  "rDiMu",
  "rDiE",
  "rGamma"
};

/*static*/
suep::utils::BranchList
suep::Recoil::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"met", "monoMu", "monoE", "diMu", "diE", "gamma", "max"};
  return blist;
}

suep::Recoil::Recoil(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

suep::Recoil::Recoil(Recoil const& _src) :
  Singlet(_src),
  met(_src.met),
  monoMu(_src.monoMu),
  monoE(_src.monoE),
  diMu(_src.diMu),
  diE(_src.diE),
  gamma(_src.gamma),
  max(_src.max)
{
  met = _src.met;
  monoMu = _src.monoMu;
  monoE = _src.monoE;
  diMu = _src.diMu;
  diE = _src.diE;
  gamma = _src.gamma;
  max = _src.max;
}

suep::Recoil::~Recoil()
{
}

suep::Recoil&
suep::Recoil::operator=(Recoil const& _src)
{
  met = _src.met;
  monoMu = _src.monoMu;
  monoE = _src.monoE;
  diMu = _src.diMu;
  diE = _src.diE;
  gamma = _src.gamma;
  max = _src.max;

  /* BEGIN CUSTOM Recoil.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::Recoil::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "met", _branches);
  utils::setStatus(_tree, name_, "monoMu", _branches);
  utils::setStatus(_tree, name_, "monoE", _branches);
  utils::setStatus(_tree, name_, "diMu", _branches);
  utils::setStatus(_tree, name_, "diE", _branches);
  utils::setStatus(_tree, name_, "gamma", _branches);
  utils::setStatus(_tree, name_, "max", _branches);
}

suep::utils::BranchList
suep::Recoil::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "met"));
  blist.push_back(utils::getStatus(_tree, name_, "monoMu"));
  blist.push_back(utils::getStatus(_tree, name_, "monoE"));
  blist.push_back(utils::getStatus(_tree, name_, "diMu"));
  blist.push_back(utils::getStatus(_tree, name_, "diE"));
  blist.push_back(utils::getStatus(_tree, name_, "gamma"));
  blist.push_back(utils::getStatus(_tree, name_, "max"));

  return blist;
}

void
suep::Recoil::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "met", &met, _branches, _setStatus);
  utils::setAddress(_tree, name_, "monoMu", &monoMu, _branches, _setStatus);
  utils::setAddress(_tree, name_, "monoE", &monoE, _branches, _setStatus);
  utils::setAddress(_tree, name_, "diMu", &diMu, _branches, _setStatus);
  utils::setAddress(_tree, name_, "diE", &diE, _branches, _setStatus);
  utils::setAddress(_tree, name_, "gamma", &gamma, _branches, _setStatus);
  utils::setAddress(_tree, name_, "max", &max, _branches, _setStatus);
}

void
suep::Recoil::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "met", "", 'O', &met, _branches);
  utils::book(_tree, name_, "monoMu", "", 'O', &monoMu, _branches);
  utils::book(_tree, name_, "monoE", "", 'O', &monoE, _branches);
  utils::book(_tree, name_, "diMu", "", 'O', &diMu, _branches);
  utils::book(_tree, name_, "diE", "", 'O', &diE, _branches);
  utils::book(_tree, name_, "gamma", "", 'O', &gamma, _branches);
  utils::book(_tree, name_, "max", "", 'F', &max, _branches);
}

void
suep::Recoil::doInit_()
{
  met = false;
  monoMu = false;
  monoE = false;
  diMu = false;
  diE = false;
  gamma = false;
  max = 0.;

  /* BEGIN CUSTOM Recoil.cc.doInit_ */
  /* END CUSTOM */
}

suep::utils::BranchList
suep::Recoil::doGetBranchNames_(Bool_t _fullName) const
{
  if (_fullName)
    return getListOfBranches().fullNames(name_);
  else
    return getListOfBranches().fullNames();
}

void
suep::Recoil::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Recoil.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::Recoil::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "met = " << met << std::endl;
  _out << "monoMu = " << monoMu << std::endl;
  _out << "monoE = " << monoE << std::endl;
  _out << "diMu = " << diMu << std::endl;
  _out << "diE = " << diE << std::endl;
  _out << "gamma = " << gamma << std::endl;
  _out << "max = " << max << std::endl;
}


/* BEGIN CUSTOM Recoil.cc.global */
/* END CUSTOM */
