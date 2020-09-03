#include <iostream>
#include <vector>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"

int main (int argc, char* argv []) {

  if (argc != 2) {
    std::cerr << "Single argument must be a Panda file." << std::endl;
    return 1;
  }

  auto* infile = TFile::Open(argv[1]);

  if (not infile) {
    std::cerr << "File didn't open" << std::endl;
    return 2;
  }

  auto* intree = static_cast<TTree*>(infile->Get("hlt"));

  if (not intree) {
    std::cerr << "Tree 'hlt' not found" << std::endl;
    return 3;
  }

  std::vector<TString>* paths {nullptr};

  intree->SetBranchAddress("paths", &paths);
  intree->GetEntry(0);

  for (auto path : *paths)
    std::cout << path << std::endl;

  infile->Close();

  return 0;

}
