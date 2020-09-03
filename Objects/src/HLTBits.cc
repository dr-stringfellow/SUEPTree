#include "../interface/HLTBits.h"

/*static*/
suep::utils::BranchList
suep::HLTBits::getListOfBranches()
{
  utils::BranchList blist;
  blist += {"words"};
  return blist;
}

suep::HLTBits::HLTBits(char const* _name/* = ""*/) :
  Singlet(_name)
{
}

suep::HLTBits::HLTBits(HLTBits const& _src) :
  Singlet(_src)
{
  std::memcpy(words, _src.words, sizeof(UInt_t) * 32);
}

suep::HLTBits::~HLTBits()
{
}

suep::HLTBits&
suep::HLTBits::operator=(HLTBits const& _src)
{
  std::memcpy(words, _src.words, sizeof(UInt_t) * 32);

  /* BEGIN CUSTOM HLTBits.cc.operator= */
  /* END CUSTOM */

  return *this;
}

void
suep::HLTBits::doSetStatus_(TTree& _tree, utils::BranchList const& _branches)
{
  utils::setStatus(_tree, name_, "words", _branches);
}

suep::utils::BranchList
suep::HLTBits::doGetStatus_(TTree& _tree) const
{
  utils::BranchList blist;

  blist.push_back(utils::getStatus(_tree, name_, "words"));

  return blist;
}

void
suep::HLTBits::doSetAddress_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  utils::setAddress(_tree, name_, "words", words, _branches, _setStatus);
}

void
suep::HLTBits::doBook_(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  utils::book(_tree, name_, "words", TString::Format("[32]"), 'i', words, _branches);
}

void
suep::HLTBits::doInit_()
{
  for (auto& p0 : words) p0 = 0;

  /* BEGIN CUSTOM HLTBits.cc.doInit_ */
  /* END CUSTOM */
}

suep::utils::BranchList
suep::HLTBits::doGetBranchNames_(Bool_t _fullName) const
{
  if (_fullName)
    return getListOfBranches().fullNames(name_);
  else
    return getListOfBranches().fullNames();
}

void
suep::HLTBits::print(std::ostream& _out/* = std::cout*/, UInt_t _level/* = 1*/) const
{
  /* BEGIN CUSTOM HLTBits.cc.print */
  dump(_out);
  /* END CUSTOM */
}

void
suep::HLTBits::dump(std::ostream& _out/* = std::cout*/) const
{
  _out << "words = " << words << std::endl;
}


/* BEGIN CUSTOM HLTBits.cc.global */
/* END CUSTOM */
