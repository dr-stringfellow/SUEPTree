#include "../interface/ArrayBase.h"

void
suep::ArrayBase::setStatus(TTree& _tree, utils::BranchList const& _branches)
{
  getData().setStatus(_tree, name_, _branches);
}

suep::utils::BranchList
suep::ArrayBase::getStatus(TTree& _tree) const
{
  return getData().getStatus(_tree, name_);
}

suep::utils::BranchList
suep::ArrayBase::getBranchNames(Bool_t _fullName/* = kTRUE*/, Bool_t/* = kFALSE*/) const
{
  if (_fullName)
    return getData().getBranchNames(name_);
  else
    return getData().getBranchNames("");
}

UInt_t
suep::ArrayBase::setAddress(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/, Bool_t _setStatus/* = kTRUE*/)
{
  getData().setAddress(_tree, name_, _branches, _setStatus);

  return registerInput_(_tree);
}

void
suep::ArrayBase::book(TTree& _tree, utils::BranchList const& _branches/* = {"*"}*/)
{
  getData().book(_tree, name_, _branches, false);
}

void
suep::ArrayBase::init()
{
  for (unsigned iP(0); iP != getData().nmax(); ++iP)
    elemAt(iP).init();
}
