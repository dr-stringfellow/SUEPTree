#include <iostream>
#include <exception>

#include <boost/filesystem.hpp>

#include "PandaTree/Utils/interface/JECCorrector.h"


using namespace panda;


namespace {

  // Used to initialize the JetCorrectionParameters
  std::vector<JetCorrectorParameters> load_params (const std::string& files_base, const std::string& jet_type) {

    std::vector<JetCorrectorParameters> output {};

    const std::vector<std::string> levels = {
      "L1FastJet",
      "L2Relative",
      "L3Absolute",
      "L2L3Residual"
    };

    for (const auto& level : levels) {

      const std::string correction_file = files_base + "_" + level + "_" + jet_type + ".txt";

      if (not boost::filesystem::exists(correction_file)) {
        std::cerr << "Cannot find correction file: " << correction_file << std::endl;
        throw std::runtime_error {"No file"};
      }

      output.emplace_back(correction_file);
    }

    return output;

  }

}


JECCorrector::JECCorrector (const std::string& files_base, const std::string& jet_type) :
  m_corrector_params {load_params(files_base, jet_type)},
  m_corrector {m_corrector_params} {}


void JECCorrector::update_event (const panda::Event& event, const panda::JetCollection& jets, const RecoMet& met) {

  // Copy jets over
  m_corrected_jets = jets;
  m_corrected_met = met;

  TVector2 new_met {met.v()};
  TVector2 met_correction {};

  for (auto& jet : m_corrected_jets) {

    // FactorizedJetCorrectorCalculator is stupid and resets these every time
    m_corrector.setNPV(event.npv);
    m_corrector.setRho(event.rho);

    m_corrector.setJetEta(jet.eta());
    m_corrector.setJetPt(jet.rawPt);
    m_corrector.setJetE(jet.e());
    m_corrector.setJetPhi(jet.phi());
    m_corrector.setJetEMF(jet.cef + jet.nef); // Check that this is right
    m_corrector.setJetA(jet.area);

    auto scale = m_corrector.getCorrection();

    auto new_pt = scale * jet.rawPt;

    // Use minus new so that we don't have to flip phi.
    // This takes out the old correction and adds the new correction back in
    met_correction.SetMagPhi(jet.pt() - new_pt, jet.phi());

    new_met += met_correction;

    jet.setPtEtaPhiM(new_pt, jet.eta(), jet.phi(), jet.m());
  }

  m_corrected_jets.sort(panda::Particle::PtGreater);

  // Change stored MET
  m_corrected_met.setXY(new_met.X(), new_met.Y());

}


const JetCollection& JECCorrector::get_jets () const {

  return m_corrected_jets;

}


const RecoMet& JECCorrector::get_met () const {

  return m_corrected_met;

}
