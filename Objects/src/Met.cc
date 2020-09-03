#include "../interface/Met.h"

/*static*/
suep::utils::BranchList
suep::Met::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"pt", "phi"};
  return blist;
}

suep::Met::Met(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

suep::Met::Met(Met const& _src) :
  Singlet(_src),
  pt(_src.pt),
  phi(_src.phi)
{
  pt = _src.pt;
  phi = _src.phi;
}

suep::Met::~Met()
{
}

suep::Met&
suep::Met::operator=(Met const& _src)
{
  pt = _src.pt;
  phi = _src.phi;

  /* BEGIN CUSTOM Met.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::Met::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "pt", _branches);
  utils::setStatus(_tree, name_, "phi", _branches);
}

suep::utils::BranchList
suep::Met::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "pt"));
  blist.push_back(utils::getStatus(_tree, name_, "phi"));

  return blist;
}

void
suep::Met::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "pt", &pt, _branches, _setStatus);
  utils::setAddress(_tree, name_, "phi", &phi, _branches, _setStatus);
}

void
suep::Met::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "pt", "", 'F', &pt, _branches);
  utils::book(_tree, name_, "phi", "", 'F', &phi, _branches);
}

void
suep::Met::doInit_()
{
  pt = 0.;
  phi = 0.;

  /* BEGIN CUSTOM Met.cc.doInit_ */
  /* END CUSTOM */
}

suep::utils::BranchList
suep::Met::doGetBranchNames_(Bool_t _fullName) const
{
  if (_fullName)
    return getListOfBranches().fullNames(name_);
  else
    return getListOfBranches().fullNames();
}

void
suep::Met::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM Met.cc.print */
  _out << getName() << std::endl;
  Met::dump(_out);
  /* END CUSTOM */
}

void
suep::Met::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "pt = " << pt << std::endl;
  _out << "phi = " << phi << std::endl;
}


/* BEGIN CUSTOM Met.cc.global */
/* END CUSTOM */
