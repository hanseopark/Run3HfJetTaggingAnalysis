#ifndef JETMATCHEDANALYSIS_H
#define JETMATCHEDANALYSIS_H

#include <TH1.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

// TODO::
// data and particle level projection name is not perfect

class JetMatchedAnalysis {
  public:
    JetMatchedAnalysis(const TString rootSim, TString triggerName="") {
      initConfig(triggerName.Data());
      if (!loadSimMatchederalMatchedQA(rootSim.Data())) {
        return;
      }
      initHistogramForNormalizationGeneralMatchedQAMC();
      projectionHistGeneralMatchedQAMC();
      cloneNormalizedHistogramGeneralMatchedQAMC();
      normalizedHistogramGeneralMatchedQAMC();
      saveHistogramGeneralMatchedQA("GeneralJetMatchedQA.root");
    }

    ~JetMatchedAnalysis();

    // function
    void initConfig(TString triggerNAME);
    int loadSimMatchederalMatchedQA(TString rootSim);
    void initHistogramForNormalizationGeneralMatchedQAMC();
    void projectionHistGeneralMatchedQAMC();
    void cloneNormalizedHistogramGeneralMatchedQAMC();
    void normalizedHistogramGeneralMatchedQAMC();
    void saveHistogramGeneralMatchedQA(TString rootFile);

    // Draw option
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void drawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);
    void drawCombined2D(int num, const std::vector<Histogram2DData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);

    void drawSimMatchedGeoPartJetPtJetPt(bool doLog, int binJetR);
    void drawSimMatchedGeoPartJetEtaJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPartJetPhiJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPartJetNTracksJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedPtPartJetPtJetPt(bool doLog, int binJetR);
    void drawSimMatchedPtPartJetEtaJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedPtPartJetPhiJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedPtPartJetNTracksJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPtPartJetPtJetPt(bool doLog, int binJetR);
    void drawSimMatchedGeoPtPartJetEtaJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPtPartJetPhiJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPtPartJetNTracksJetNTracks(bool doLog, int binJetPt, int binJetR);

    void drawSimMatchedGeoDiffJetPt(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoDiffJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoDiffJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedPtDiffJetPt(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedPtDiffJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedPtDiffJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPtDiffJetPt(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPtDiffJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimMatchedGeoPtDiffJetPhi(bool doLog, int binJetPt, int binJetR);
    bool selectedJetR();

    /// histogram
    TH2F* h2simMatchedGeoPartJetPtJetPt[GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedGeoPartJetEtaJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedGeoPartJetPhiJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedGeoPartJetNTracksJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimMatchedGeoDiffJetPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoDiffJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoDiffJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    //TH1F* hsimMatchedGeoDiffJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt

    TH2F* h2simMatchedPtPartJetPtJetPt[GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedPtPartJetEtaJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedPtPartJetPhiJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedPtPartJetNTracksJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimMatchedPtDiffJetPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedPtDiffJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedPtDiffJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    //TH1F* hsimMatchedPtDiffJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt

    TH2F* h2simMatchedGeoPtPartJetPtJetPt[GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedGeoPtPartJetEtaJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedGeoPtPartJetPhiJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH2F* h2simMatchedGeoPtPartJetNTracksJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimMatchedGeoPtDiffJetPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoPtDiffJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoPtDiffJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    //TH1F* hsimMatchedGeoPtDiffJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt

    /// Normalized histogram
    TH1F* hsimMatchedGeoNormalizedDiffJetPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoNormalizedDiffJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoNormalizedDiffJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    //TH1F* hsimMatchedGeoNormalizedDiffJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedPtNormalizedDiffJetPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedPtNormalizedDiffJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedPtNormalizedDiffJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    //TH1F* hsimMatchedPtNormalizedDiffJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoPtNormalizedDiffJetPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoPtNormalizedDiffJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    TH1F* hsimMatchedGeoPtNormalizedDiffJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt
    //TH1F* hsimMatchedGeoPtNormalizedDiffJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1]; // partjetpt

  protected:
    // draw option
    int canvasNum=0;
    CanvasHandler* canvasHandler;

    // histogram from root file
    /// Matched geo
    TH3F* h3simMatchedGeoJetRPartJetPtJetPt;
    TH3F* h3simMatchedGeoJetRPartJetEtaJetEta;
    TH3F* h3simMatchedGeoJetRPartJetPhiJetPhi;
    TH3F* h3simMatchedGeoJetRPartJetNTracksJetNTracks;
    TH3F* h3simMatchedGeoJetRPartJetPtDiffJetPt;
    TH3F* h3simMatchedGeoJetRPartJetPtDiffJetEta;
    TH3F* h3simMatchedGeoJetRPartJetPtDiffJetPhi;
    //TH3F* h3simMatchedGeoJetRPartJetPtDiffJetNTracks;
    TH3F* h3simMatchedGeoPartJetPtPartJetEtaJetEta;
    TH3F* h3simMatchedGeoPartJetPtPartJetPhiJetPhi;
    TH3F* h3simMatchedGeoPartJetPtPartJetNTracksJetNTracks;

    // tag pt tag eta base pt
    // base is mcd, tag is mcp

    // Matched pT
    TH3F* h3simMatchedPtJetRPartJetPtJetPt;
    TH3F* h3simMatchedPtJetRPartJetEtaJetEta;
    TH3F* h3simMatchedPtJetRPartJetPhiJetPhi;
    TH3F* h3simMatchedPtJetRPartJetNTracksJetNTracks;
    TH3F* h3simMatchedPtJetRPartJetPtDiffJetPt;
    TH3F* h3simMatchedPtJetRPartJetPtDiffJetEta;
    TH3F* h3simMatchedPtJetRPartJetPtDiffJetPhi;
    //TH3F* h3simMatchedPtJetRPartJetPtDiffJetNTracks;
    TH3F* h3simMatchedPtPartJetPtPartJetEtaJetEta;
    TH3F* h3simMatchedPtPartJetPtPartJetPhiJetPhi;
    TH3F* h3simMatchedPtPartJetPtPartJetNTracksJetNTracks;

    // Matched geopT
    TH3F* h3simMatchedGeoPtJetRPartJetPtJetPt;
    TH3F* h3simMatchedGeoPtJetRPartJetEtaJetEta;
    TH3F* h3simMatchedGeoPtJetRPartJetPhiJetPhi;
    TH3F* h3simMatchedGeoPtJetRPartJetNTracksJetNTracks;
    TH3F* h3simMatchedGeoPtJetRPartJetPtDiffJetPt;
    TH3F* h3simMatchedGeoPtJetRPartJetPtDiffJetEta;
    TH3F* h3simMatchedGeoPtJetRPartJetPtDiffJetPhi;
    //TH3F* h3simMatchedGeoPtJetRPartJetPtDiffJetNTracks;
    TH3F* h3simMatchedGeoPtPartJetPtPartJetEtaJetEta;
    TH3F* h3simMatchedGeoPtPartJetPtPartJetPhiJetPhi;
    TH3F* h3simMatchedGeoPtPartJetPtPartJetNTracksJetNTracks;

  private:
    std::vector<HistogramData> histList;
    TLatex latex;
    TString triggerName;

};

JetMatchedAnalysis::~JetMatchedAnalysis() {
}

void JetMatchedAnalysis::initConfig(TString trigger) {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

  triggerName = trigger.Data();
  TString dirSim = Form("fig/sim/%s/general/matched", triggerName.Data());
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int JetMatchedAnalysis::loadSimMatchederalMatchedQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";

  // matchedgeo
  h3simMatchedGeoJetRPartJetPtJetPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_pt_base_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoJetRPartJetEtaJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_tag_jet_eta_base_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoJetRPartJetPhiJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_phi_tag_jet_phi_base_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoJetRPartJetNTracksJetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_ntracks_tag_jet_ntracks_base_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoJetRPartJetPtDiffJetPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_pt_base_diff_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoJetRPartJetPtDiffJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_eta_base_diff_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoJetRPartJetPtDiffJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_phi_base_diff_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoPartJetPtPartJetEtaJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_eta_tag_jet_eta_base_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoPartJetPtPartJetPhiJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_phi_tag_jet_phi_base_matchedgeo", taskJetQA.Data())));
  h3simMatchedGeoPartJetPtPartJetNTracksJetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_ntracks_tag_jet_ntracks_base_matchedgeo", taskJetQA.Data())));

  // matchedpt
  h3simMatchedPtJetRPartJetPtJetPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_pt_base_matchedpt", taskJetQA.Data())));
  h3simMatchedPtJetRPartJetEtaJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_tag_jet_eta_base_matchedpt", taskJetQA.Data())));
  h3simMatchedPtJetRPartJetPhiJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_phi_tag_jet_phi_base_matchedpt", taskJetQA.Data())));
  h3simMatchedPtJetRPartJetNTracksJetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_ntracks_tag_jet_ntracks_base_matchedpt", taskJetQA.Data())));
  h3simMatchedPtJetRPartJetPtDiffJetPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_pt_base_diff_matchedpt", taskJetQA.Data())));
  h3simMatchedPtJetRPartJetPtDiffJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_eta_base_diff_matchedpt", taskJetQA.Data())));
  h3simMatchedPtJetRPartJetPtDiffJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_phi_base_diff_matchedpt", taskJetQA.Data())));
  h3simMatchedPtPartJetPtPartJetEtaJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_eta_tag_jet_eta_base_matchedpt", taskJetQA.Data())));
  h3simMatchedPtPartJetPtPartJetPhiJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_phi_tag_jet_phi_base_matchedpt", taskJetQA.Data())));
  h3simMatchedPtPartJetPtPartJetNTracksJetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_ntracks_tag_jet_ntracks_base_matchedpt", taskJetQA.Data())));

  // matchedgeopt
  h3simMatchedGeoPtJetRPartJetPtJetPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_pt_base_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtJetRPartJetEtaJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_tag_jet_eta_base_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtJetRPartJetPhiJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_phi_tag_jet_phi_base_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtJetRPartJetNTracksJetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_ntracks_tag_jet_ntracks_base_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtJetRPartJetPtDiffJetPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_pt_base_diff_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtJetRPartJetPtDiffJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_eta_base_diff_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtJetRPartJetPtDiffJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_tag_jet_phi_base_diff_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtPartJetPtPartJetEtaJetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_eta_tag_jet_eta_base_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtPartJetPtPartJetPhiJetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_phi_tag_jet_phi_base_matchedgeopt", taskJetQA.Data())));
  h3simMatchedGeoPtPartJetPtPartJetNTracksJetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_tag_jet_ntracks_tag_jet_ntracks_base_matchedgeopt", taskJetQA.Data())));

  std::cout << "Load completed General Jet QA MC" << std::endl;
  return 1;
}

void JetMatchedAnalysis::initHistogramForNormalizationGeneralMatchedQAMC() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    h2simMatchedGeoPartJetPtJetPt[binJetR] = new TH2F(Form("h2simMatchedGeoPartJetPtJetPt_%d", binJetR), "", h3simMatchedGeoJetRPartJetPtJetPt->GetNbinsY(), h3simMatchedGeoJetRPartJetPtJetPt->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPtJetPt->GetYaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPtJetPt->GetNbinsY()), h3simMatchedGeoJetRPartJetPtJetPt->GetNbinsZ(), h3simMatchedGeoJetRPartJetPtJetPt->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPtJetPt->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPtJetPt->GetNbinsZ()));
    h2simMatchedPtPartJetPtJetPt[binJetR] = new TH2F(Form("h2simMatchedPtPartJetPtJetPt_%d", binJetR), "", h3simMatchedPtJetRPartJetPtJetPt->GetNbinsY(), h3simMatchedPtJetRPartJetPtJetPt->GetYaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPtJetPt->GetYaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPtJetPt->GetNbinsY()), h3simMatchedPtJetRPartJetPtJetPt->GetNbinsZ(), h3simMatchedPtJetRPartJetPtJetPt->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPtJetPt->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPtJetPt->GetNbinsZ()));
    h2simMatchedGeoPtPartJetPtJetPt[binJetR] = new TH2F(Form("h2simMatchedGeoPtPartJetPtJetPt_%d", binJetR), "", h3simMatchedGeoPtJetRPartJetPtJetPt->GetNbinsY(), h3simMatchedGeoPtJetRPartJetPtJetPt->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPtJetPt->GetYaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPtJetPt->GetNbinsY()), h3simMatchedGeoPtJetRPartJetPtJetPt->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetPtJetPt->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPtJetPt->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPtJetPt->GetNbinsZ()));

    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      h2simMatchedGeoPartJetEtaJetEta[binJetPt][binJetR] = new TH2F(Form("h2simMatchedGeoPartJetEtaJetEta_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetEtaJetEta->GetNbinsY(), h3simMatchedGeoJetRPartJetEtaJetEta->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetEtaJetEta->GetYaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetEtaJetEta->GetNbinsY()), h3simMatchedGeoJetRPartJetEtaJetEta->GetNbinsZ(), h3simMatchedGeoJetRPartJetEtaJetEta->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetEtaJetEta->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetEtaJetEta->GetNbinsZ()));
      h2simMatchedGeoPartJetPhiJetPhi[binJetPt][binJetR] = new TH2F(Form("h2simMatchedGeoPartJetPhiJetPhi_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetPhiJetPhi->GetNbinsY(), h3simMatchedGeoJetRPartJetPhiJetPhi->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPhiJetPhi->GetYaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPhiJetPhi->GetNbinsY()), h3simMatchedGeoJetRPartJetPhiJetPhi->GetNbinsZ(), h3simMatchedGeoJetRPartJetPhiJetPhi->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPhiJetPhi->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPhiJetPhi->GetNbinsZ()));
      h2simMatchedGeoPartJetNTracksJetNTracks[binJetPt][binJetR] = new TH2F(Form("h2simMatchedGeoPartJetNTracksJetNTracks_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetNbinsY(), h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetYaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetNbinsY()), h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetNbinsZ(), h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetNTracksJetNTracks->GetNbinsZ()));
      hsimMatchedGeoDiffJetPt[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoDiffJetPt_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetPtDiffJetPt->GetNbinsZ(), h3simMatchedGeoJetRPartJetPtDiffJetPt->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPtDiffJetPt->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPtDiffJetPt->GetNbinsZ()));
      hsimMatchedGeoDiffJetEta[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoDiffJetEta_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetPtDiffJetEta->GetNbinsZ(), h3simMatchedGeoJetRPartJetPtDiffJetEta->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPtDiffJetEta->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPtDiffJetEta->GetNbinsZ()));
      hsimMatchedGeoDiffJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoDiffJetPhi_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetNbinsZ(), h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetNbinsZ()));
      //hsimMatchedGeoDiffJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoDiffJetNTracks_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoJetRPartJetPtDiffJetNTracks->GetNbinsZ(), h3simMatchedGeoJetRPartJetPtDiffJetNTracks->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoJetRPartJetPtDiffJetNTracks->GetZaxis()->GetBinUpEdge(h3simMatchedGeoJetRPartJetPtDiffJetNTracks->GetNbinsZ()));
      h2simMatchedPtPartJetEtaJetEta[binJetPt][binJetR] = new TH2F(Form("h2simMatchedPtPartJetEtaJetEta_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetEtaJetEta->GetNbinsY(), h3simMatchedPtJetRPartJetEtaJetEta->GetYaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetEtaJetEta->GetYaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetEtaJetEta->GetNbinsY()), h3simMatchedPtJetRPartJetEtaJetEta->GetNbinsZ(), h3simMatchedPtJetRPartJetEtaJetEta->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetEtaJetEta->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetEtaJetEta->GetNbinsZ()));
      h2simMatchedPtPartJetPhiJetPhi[binJetPt][binJetR] = new TH2F(Form("h2simMatchedPtPartJetPhiJetPhi_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetPhiJetPhi->GetNbinsY(), h3simMatchedPtJetRPartJetPhiJetPhi->GetYaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPhiJetPhi->GetYaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPhiJetPhi->GetNbinsY()), h3simMatchedPtJetRPartJetPhiJetPhi->GetNbinsZ(), h3simMatchedPtJetRPartJetPhiJetPhi->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPhiJetPhi->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPhiJetPhi->GetNbinsZ()));
      h2simMatchedPtPartJetNTracksJetNTracks[binJetPt][binJetR] = new TH2F(Form("h2simMatchedPtPartJetNTracksJetNTracks_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetNTracksJetNTracks->GetNbinsY(), h3simMatchedPtJetRPartJetNTracksJetNTracks->GetYaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetNTracksJetNTracks->GetYaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetNTracksJetNTracks->GetNbinsY()), h3simMatchedPtJetRPartJetNTracksJetNTracks->GetNbinsZ(), h3simMatchedPtJetRPartJetNTracksJetNTracks->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetNTracksJetNTracks->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetNTracksJetNTracks->GetNbinsZ()));
      hsimMatchedPtDiffJetPt[binJetPt][binJetR] = new TH1F(Form("hsimMatchedPtDiffJetPt_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetPtDiffJetPt->GetNbinsZ(), h3simMatchedPtJetRPartJetPtDiffJetPt->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPtDiffJetPt->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPtDiffJetPt->GetNbinsZ()));
      hsimMatchedPtDiffJetEta[binJetPt][binJetR] = new TH1F(Form("hsimMatchedPtDiffJetEta_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetPtDiffJetEta->GetNbinsZ(), h3simMatchedPtJetRPartJetPtDiffJetEta->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPtDiffJetEta->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPtDiffJetEta->GetNbinsZ()));
      hsimMatchedPtDiffJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimMatchedPtDiffJetPhi_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetPtDiffJetPhi->GetNbinsZ(), h3simMatchedPtJetRPartJetPtDiffJetPhi->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPtDiffJetPhi->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPtDiffJetPhi->GetNbinsZ()));
      //hsimMatchedPtDiffJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimMatchedPtDiffJetNTracks_%d_%d", binJetPt, binJetR), "", h3simMatchedPtJetRPartJetPtDiffJetNTracks->GetNbinsZ(), h3simMatchedPtJetRPartJetPtDiffJetNTracks->GetZaxis()->GetBinLowEdge(1), h3simMatchedPtJetRPartJetPtDiffJetNTracks->GetZaxis()->GetBinUpEdge(h3simMatchedPtJetRPartJetPtDiffJetNTracks->GetNbinsZ()));

      h2simMatchedGeoPtPartJetEtaJetEta[binJetPt][binJetR] = new TH2F(Form("h2simMatchedGeoPtPartJetEtaJetEta_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetEtaJetEta->GetNbinsY(), h3simMatchedGeoPtJetRPartJetEtaJetEta->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetEtaJetEta->GetYaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetEtaJetEta->GetNbinsY()), h3simMatchedGeoPtJetRPartJetEtaJetEta->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetEtaJetEta->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetEtaJetEta->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetEtaJetEta->GetNbinsZ()));
      h2simMatchedGeoPtPartJetPhiJetPhi[binJetPt][binJetR] = new TH2F(Form("h2simMatchedGeoPtPartJetPhiJetPhi_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetNbinsY(), h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetYaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetNbinsY()), h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPhiJetPhi->GetNbinsZ()));
      h2simMatchedGeoPtPartJetNTracksJetNTracks[binJetPt][binJetR] = new TH2F(Form("h2simMatchedGeoPtPartJetNTracksJetNTracks_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetNbinsY(), h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetYaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetYaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetNbinsY()), h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->GetNbinsZ()));

      hsimMatchedGeoPtDiffJetPt[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoPtDiffJetPt_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetPtDiffJetPt->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetPtDiffJetPt->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPtDiffJetPt->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPtDiffJetPt->GetNbinsZ()));
      hsimMatchedGeoPtDiffJetEta[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoPtDiffJetEta_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetPtDiffJetEta->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetPtDiffJetEta->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPtDiffJetEta->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPtDiffJetEta->GetNbinsZ()));
      hsimMatchedGeoPtDiffJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoPtDiffJetPhi_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->GetNbinsZ()));
      //hsimMatchedGeoPtDiffJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimMatchedGeoPtDiffJetNTracks_%d_%d", binJetPt, binJetR), "", h3simMatchedGeoPtJetRPartJetPtDiffJetNTracks->GetNbinsZ(), h3simMatchedGeoPtJetRPartJetPtDiffJetNTracks->GetZaxis()->GetBinLowEdge(1), h3simMatchedGeoPtJetRPartJetPtDiffJetNTracks->GetZaxis()->GetBinUpEdge(h3simMatchedGeoPtJetRPartJetPtDiffJetNTracks->GetNbinsZ()));
    }
  }
}

void JetMatchedAnalysis::projectionHistGeneralMatchedQAMC() {
  TH1F *projMatchedGeoDiffJetPt = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetPt->ProjectionZ("projMatchedGeoDiffJetPt", 1, h3simMatchedGeoJetRPartJetPtDiffJetPt->GetNbinsX(), 1, h3simMatchedGeoJetRPartJetPtDiffJetPt->GetNbinsY()));
  TH1F *projMatchedGeoDiffJetEta = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetEta->ProjectionZ("projMatchedGeoDiffJetEta", 1, h3simMatchedGeoJetRPartJetPtDiffJetEta->GetNbinsX(), 1, h3simMatchedGeoJetRPartJetPtDiffJetEta->GetNbinsY()));
  TH1F *projMatchedGeoDiffJetPhi = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetPhi->ProjectionZ("projMatchedGeoDiffJetPhi", 1, h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetNbinsX(), 1, h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetNbinsY()));
  hsimMatchedGeoDiffJetPt[0][0] = reinterpret_cast<TH1F*>(projMatchedGeoDiffJetPt->Clone("hsimMatchedGeoDiffJetPt_0_0"));
  hsimMatchedGeoDiffJetEta[0][0] = reinterpret_cast<TH1F*>(projMatchedGeoDiffJetEta->Clone("hsimMatchedGeoDiffJetEta_0_0"));
  hsimMatchedGeoDiffJetPhi[0][0] = reinterpret_cast<TH1F*>(projMatchedGeoDiffJetPhi->Clone("hsimMatchedGeoDiffJetPhi_0_0"));

  TH1F *projMatchedPtDiffJetPt = reinterpret_cast<TH1F*> (h3simMatchedPtJetRPartJetPtDiffJetPt->ProjectionZ("projMatchedPtDiffJetPt", 1, h3simMatchedPtJetRPartJetPtDiffJetPt->GetNbinsX(), 1, h3simMatchedPtJetRPartJetPtDiffJetPt->GetNbinsY()));
  TH1F *projMatchedPtDiffJetEta = reinterpret_cast<TH1F*> (h3simMatchedPtJetRPartJetPtDiffJetEta->ProjectionZ("projMatchedPtDiffJetEta", 1, h3simMatchedPtJetRPartJetPtDiffJetEta->GetNbinsX(), 1, h3simMatchedPtJetRPartJetPtDiffJetEta->GetNbinsY()));
  TH1F *projMatchedPtDiffJetPhi = reinterpret_cast<TH1F*> (h3simMatchedPtJetRPartJetPtDiffJetPhi->ProjectionZ("projMatchedPtDiffJetPhi", 1, h3simMatchedPtJetRPartJetPtDiffJetPhi->GetNbinsX(), 1, h3simMatchedPtJetRPartJetPtDiffJetPhi->GetNbinsY()));
  hsimMatchedPtDiffJetPt[0][0] = reinterpret_cast<TH1F*>(projMatchedPtDiffJetPt->Clone("hsimMatchedPtDiffJetPt_0_0"));
  hsimMatchedPtDiffJetEta[0][0] = reinterpret_cast<TH1F*>(projMatchedPtDiffJetEta->Clone("hsimMatchedPtDiffJetEta_0_0"));
  hsimMatchedPtDiffJetPhi[0][0] = reinterpret_cast<TH1F*>(projMatchedPtDiffJetPhi->Clone("hsimMatchedPtDiffJetPhi_0_0"));

  TH1F *projMatchedGeoPtDiffJetPt = reinterpret_cast<TH1F*> (h3simMatchedGeoPtJetRPartJetPtDiffJetPt->ProjectionZ("projMatchedGeoPtDiffJetPt", 1, h3simMatchedGeoPtJetRPartJetPtDiffJetPt->GetNbinsX(), 1, h3simMatchedGeoPtJetRPartJetPtDiffJetPt->GetNbinsY()));
  TH1F *projMatchedGeoPtDiffJetEta = reinterpret_cast<TH1F*> (h3simMatchedGeoPtJetRPartJetPtDiffJetEta->ProjectionZ("projMatchedGeoPtDiffJetEta", 1, h3simMatchedGeoPtJetRPartJetPtDiffJetEta->GetNbinsX(), 1, h3simMatchedGeoPtJetRPartJetPtDiffJetEta->GetNbinsY()));
  TH1F *projMatchedGeoPtDiffJetPhi = reinterpret_cast<TH1F*> (h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->ProjectionZ("projMatchedGeoPtDiffJetPhi", 1, h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->GetNbinsX(), 1, h3simMatchedGeoPtJetRPartJetPtDiffJetPhi->GetNbinsY()));
  hsimMatchedGeoPtDiffJetPt[0][0] = reinterpret_cast<TH1F*>(projMatchedGeoPtDiffJetPt->Clone("hsimMatchedGeoPtDiffJetPt_0_0"));
  hsimMatchedGeoPtDiffJetEta[0][0] = reinterpret_cast<TH1F*>(projMatchedGeoPtDiffJetEta->Clone("hsimMatchedGeoPtDiffJetEta_0_0"));
  hsimMatchedGeoPtDiffJetPhi[0][0] = reinterpret_cast<TH1F*>(projMatchedGeoPtDiffJetPhi->Clone("hsimMatchedGeoPtDiffJetPhi_0_0"));

  TH2F *projMatchedGeoJetPt = reinterpret_cast<TH2F*> (h3simMatchedGeoJetRPartJetPtJetPt->Project3D("yz"));
  TH2F *projMatchedGeoJetEta = reinterpret_cast<TH2F*> (h3simMatchedGeoJetRPartJetEtaJetEta->Project3D("yz"));
  TH2F *projMatchedGeoJetPhi = reinterpret_cast<TH2F*> (h3simMatchedGeoJetRPartJetPhiJetPhi->Project3D("yz"));
  TH2F *projMatchedGeoJetNTracks = reinterpret_cast<TH2F*> (h3simMatchedGeoJetRPartJetNTracksJetNTracks->Project3D("yz"));
  h2simMatchedGeoPartJetPtJetPt[0] = reinterpret_cast<TH2F*>(projMatchedGeoJetPt->Clone("h2simMatchedGeoPartJetPtJetPt_0"));
  h2simMatchedGeoPartJetEtaJetEta[0][0] = reinterpret_cast<TH2F*>(projMatchedGeoJetEta->Clone("h2simMatchedGeoPartJetEtaJetEta_0_0"));
  h2simMatchedGeoPartJetPhiJetPhi[0][0] = reinterpret_cast<TH2F*>(projMatchedGeoJetPhi->Clone("h2simMatchedGeoPartJetPhiJetPhi_0_0"));
  h2simMatchedGeoPartJetNTracksJetNTracks[0][0] = reinterpret_cast<TH2F*>(projMatchedGeoJetNTracks->Clone("h2simMatchedGeoPartJetNTracksJetNTracks_0_0"));

  TH2F *projMatchedPtJetPt = reinterpret_cast<TH2F*> (h3simMatchedPtJetRPartJetPtJetPt->Project3D("yz"));
  TH2F *projMatchedPtJetEta = reinterpret_cast<TH2F*> (h3simMatchedPtJetRPartJetEtaJetEta->Project3D("yz"));
  TH2F *projMatchedPtJetPhi = reinterpret_cast<TH2F*> (h3simMatchedPtJetRPartJetPhiJetPhi->Project3D("yz"));
  TH2F *projMatchedPtJetNTracks = reinterpret_cast<TH2F*> (h3simMatchedPtJetRPartJetNTracksJetNTracks->Project3D("yz"));
  h2simMatchedPtPartJetPtJetPt[0] = reinterpret_cast<TH2F*>(projMatchedPtJetPt->Clone("h2simMatchedPtPartJetPtJetPt_0"));
  h2simMatchedPtPartJetEtaJetEta[0][0] = reinterpret_cast<TH2F*>(projMatchedPtJetEta->Clone("h2simMatchedPtPartJetEtaJetEta_0_0"));
  h2simMatchedPtPartJetPhiJetPhi[0][0] = reinterpret_cast<TH2F*>(projMatchedPtJetPhi->Clone("h2simMatchedPtPartJetPhiJetPhi_0_0"));
  h2simMatchedPtPartJetNTracksJetNTracks[0][0] = reinterpret_cast<TH2F*>(projMatchedPtJetNTracks->Clone("h2simMatchedPtPartJetNTracksJetNTracks_0_0"));

  TH2F *projMatchedGeoPtJetPt = reinterpret_cast<TH2F*> (h3simMatchedGeoPtJetRPartJetPtJetPt->Project3D("yz"));
  TH2F *projMatchedGeoPtJetEta = reinterpret_cast<TH2F*> (h3simMatchedGeoPtJetRPartJetEtaJetEta->Project3D("yz"));
  TH2F *projMatchedGeoPtJetPhi = reinterpret_cast<TH2F*> (h3simMatchedGeoPtJetRPartJetPhiJetPhi->Project3D("yz"));
  TH2F *projMatchedGeoPtJetNTracks = reinterpret_cast<TH2F*> (h3simMatchedGeoPtJetRPartJetNTracksJetNTracks->Project3D("yz"));
  h2simMatchedGeoPtPartJetPtJetPt[0] = reinterpret_cast<TH2F*>(projMatchedGeoPtJetPt->Clone("h2simMatchedGeoPtPartJetPtJetPt_0"));
  h2simMatchedGeoPtPartJetEtaJetEta[0][0] = reinterpret_cast<TH2F*>(projMatchedGeoPtJetEta->Clone("h2simMatchedGeoPtPartJetEtaJetEta_0_0"));
  h2simMatchedGeoPtPartJetPhiJetPhi[0][0] = reinterpret_cast<TH2F*>(projMatchedGeoPtJetPhi->Clone("h2simMatchedGeoPtPartJetPhiJetPhi_0_0"));
  h2simMatchedGeoPtPartJetNTracksJetNTracks[0][0] = reinterpret_cast<TH2F*>(projMatchedGeoPtJetNTracks->Clone("h2simMatchedGeoPtPartJetNTracksJetNTracks_0_0"));

  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // DiffJetPt
    int leftbinJetRForDiffJetPt = h3simMatchedGeoJetRPartJetPtDiffJetPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForDiffJetPt = h3simMatchedGeoJetRPartJetPtDiffJetPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projMatchedGeoJetRRangeDiffJetPt = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetPt->ProjectionZ(Form("projMatchedGeoJetRRangeDiffJetPt_%d", binJetR), leftbinJetRForDiffJetPt, rightbinJetRForDiffJetPt, 1, h3simMatchedGeoJetRPartJetPtDiffJetPt->GetNbinsY()));
    hsimMatchedGeoDiffJetPt[0][binJetR] = reinterpret_cast<TH1F*>(projMatchedGeoJetRRangeDiffJetPt->Clone(Form("hsimMatchedGeoDiffJetPt_0_%d", binJetR)));

    // DiffJetEta
    int leftbinJetRForDiffJetEta = h3simMatchedGeoJetRPartJetPtDiffJetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForDiffJetEta = h3simMatchedGeoJetRPartJetPtDiffJetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projMatchedGeoJetRRangeDiffJetEta = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetEta->ProjectionZ(Form("projMatchedGeoJetRRangeDiffJetEta_%d", binJetR), leftbinJetRForDiffJetEta, rightbinJetRForDiffJetEta, 1, h3simMatchedGeoJetRPartJetPtDiffJetEta->GetNbinsY()));
    hsimMatchedGeoDiffJetEta[0][binJetR] = reinterpret_cast<TH1F*>(projMatchedGeoJetRRangeDiffJetEta->Clone(Form("hsimMatchedGeoDiffJetEta_0_%d", binJetR)));

    // DiffJetPhi
    int leftbinJetRForDiffJetPhi = h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForDiffJetPhi = h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projMatchedGeoJetRRangeDiffJetPhi = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetPhi->ProjectionZ(Form("projMatchedGeoJetRRangeDiffJetPhi_%d", binJetR), leftbinJetRForDiffJetPhi, rightbinJetRForDiffJetPhi, 1, h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetNbinsY()));
    hsimMatchedGeoDiffJetPhi[0][binJetR] = reinterpret_cast<TH1F*>(projMatchedGeoJetRRangeDiffJetPhi->Clone(Form("hsimMatchedGeoDiffJetPhi_0_%d", binJetR)));

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      // DiffJetPt
      int leftbinJetPtForDiffJetPt = h3simMatchedGeoJetRPartJetPtDiffJetPt->GetXaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForDiffJetPt = h3simMatchedGeoJetRPartJetPtDiffJetPt->GetXaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projMatchedGeoJetRRangeJetPtRangeDiffJetPt = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetPt->ProjectionZ(Form("projMatchedGeoJetRRangeDiffJetPt_%d", binJetR), leftbinJetRForDiffJetPt, rightbinJetRForDiffJetPt, leftbinJetPtForDiffJetPt, rightbinJetPtForDiffJetPt));
      hsimMatchedGeoDiffJetPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projMatchedGeoJetRRangeJetPtRangeDiffJetPt->Clone(Form("hsimMatchedGeoDiffJetPt_%d_%d", binJetPt, binJetR)));

      hsimMatchedGeoDiffJetPt[binJetPt][0]->Add(projMatchedGeoJetRRangeJetPtRangeDiffJetPt);

      // DiffJetEta
      int leftbinJetPtForDiffJetEta = h3simMatchedGeoJetRPartJetPtDiffJetEta->GetXaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForDiffJetEta = h3simMatchedGeoJetRPartJetPtDiffJetEta->GetXaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projMatchedGeoJetRRangeJetPtRangeDiffJetEta = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetEta->ProjectionZ(Form("projMatchedGeoJetRRangeDiffJetEta_%d", binJetR), leftbinJetRForDiffJetEta, rightbinJetRForDiffJetEta, leftbinJetPtForDiffJetEta, rightbinJetPtForDiffJetEta));
      hsimMatchedGeoDiffJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projMatchedGeoJetRRangeJetPtRangeDiffJetEta->Clone(Form("hsimMatchedGeoDiffJetEta_%d_%d", binJetPt, binJetR)));
      hsimMatchedGeoDiffJetEta[binJetPt][0]->Add(projMatchedGeoJetRRangeJetPtRangeDiffJetEta);

      // DiffJetPhi
      int leftbinJetPtForDiffJetPhi = h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetXaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForDiffJetPhi = h3simMatchedGeoJetRPartJetPtDiffJetPhi->GetXaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projMatchedGeoJetRRangeJetPtRangeDiffJetPhi = reinterpret_cast<TH1F*> (h3simMatchedGeoJetRPartJetPtDiffJetPhi->ProjectionZ(Form("projMatchedGeoJetRRangeDiffJetPhi_%d", binJetR), leftbinJetRForDiffJetPhi, rightbinJetRForDiffJetPhi, leftbinJetPtForDiffJetPhi, rightbinJetPtForDiffJetPhi));
      hsimMatchedGeoDiffJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projMatchedGeoJetRRangeJetPtRangeDiffJetPhi->Clone(Form("hsimMatchedGeoDiffJetPhi_%d_%d", binJetPt, binJetR)));
      hsimMatchedGeoDiffJetPhi[binJetPt][0]->Add(projMatchedGeoJetRRangeJetPtRangeDiffJetPhi);
    }
  }
}

void JetMatchedAnalysis::cloneNormalizedHistogramGeneralMatchedQAMC() {

  hsimMatchedPtNormalizedDiffJetPt[0][0] = reinterpret_cast<TH1F*> (hsimMatchedPtDiffJetPt[0][0]->Clone(Form("hsimMatchedPtNormalizedDiffJetPt_%d_%d", 0, 0)));
  hsimMatchedPtNormalizedDiffJetEta[0][0] = reinterpret_cast<TH1F*> (hsimMatchedPtDiffJetEta[0][0]->Clone(Form("hsimMatchedPtNormalizedDiffJetEta_%d_%d", 0, 0)));
  hsimMatchedPtNormalizedDiffJetPhi[0][0] = reinterpret_cast<TH1F*> (hsimMatchedPtDiffJetPhi[0][0]->Clone(Form("hsimMatchedPtNormalizedDiffJetPhi_%d_%d", 0, 0)));
  hsimMatchedGeoPtNormalizedDiffJetPt[0][0] = reinterpret_cast<TH1F*> (hsimMatchedGeoPtDiffJetPt[0][0]->Clone(Form("hsimMatchedGeoPtNormalizedDiffJetPt_%d_%d", 0, 0)));
  hsimMatchedGeoPtNormalizedDiffJetEta[0][0] = reinterpret_cast<TH1F*> (hsimMatchedGeoPtDiffJetEta[0][0]->Clone(Form("hsimMatchedGeoPtNormalizedDiffJetEta_%d_%d", 0, 0)));
  hsimMatchedGeoPtNormalizedDiffJetPhi[0][0] = reinterpret_cast<TH1F*> (hsimMatchedGeoPtDiffJetPhi[0][0]->Clone(Form("hsimMatchedGeoPtNormalizedDiffJetPhi_%d_%d", 0, 0)));
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimMatchedGeoNormalizedDiffJetPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (hsimMatchedGeoDiffJetPt[binJetPt][binJetR]->Clone(Form("hsimMatchedGeoNormalizedDiffJetPt_%d_%d", binJetPt, binJetR)));
      hsimMatchedGeoNormalizedDiffJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (hsimMatchedGeoDiffJetEta[binJetPt][binJetR]->Clone(Form("hsimMatchedGeoNormalizedDiffJetEta_%d_%d", binJetPt, binJetR)));
      hsimMatchedGeoNormalizedDiffJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (hsimMatchedGeoDiffJetPhi[binJetPt][binJetR]->Clone(Form("hsimMatchedGeoNormalizedDiffJetPhi_%d_%d", binJetPt, binJetR)));
    }
  }
}

void JetMatchedAnalysis::normalizedHistogramGeneralMatchedQAMC() {

  hsimMatchedPtNormalizedDiffJetPt[0][0]->Scale(1. / hsimMatchedPtDiffJetPt[0][0]->GetEntries());
  hsimMatchedPtNormalizedDiffJetEta[0][0]->Scale(1. / hsimMatchedPtDiffJetEta[0][0]->GetEntries());
  hsimMatchedPtNormalizedDiffJetPhi[0][0]->Scale(1. / hsimMatchedPtDiffJetPhi[0][0]->GetEntries());
  hsimMatchedGeoPtNormalizedDiffJetPt[0][0]->Scale(1. / hsimMatchedGeoPtDiffJetPt[0][0]->GetEntries());
  hsimMatchedGeoPtNormalizedDiffJetEta[0][0]->Scale(1. / hsimMatchedGeoPtDiffJetEta[0][0]->GetEntries());
  hsimMatchedGeoPtNormalizedDiffJetPhi[0][0]->Scale(1. / hsimMatchedGeoPtDiffJetPhi[0][0]->GetEntries());
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimMatchedGeoNormalizedDiffJetPt[binJetPt][binJetR]->Scale(1. / hsimMatchedGeoDiffJetPt[binJetPt][binJetR]->GetEntries());
      hsimMatchedGeoNormalizedDiffJetEta[binJetPt][binJetR]->Scale(1. / hsimMatchedGeoDiffJetEta[binJetPt][binJetR]->GetEntries());
      hsimMatchedGeoNormalizedDiffJetPhi[binJetPt][binJetR]->Scale(1. / hsimMatchedGeoDiffJetPhi[binJetPt][binJetR]->GetEntries());
    }
  }
}

void JetMatchedAnalysis::saveHistogramGeneralMatchedQA(TString rootFile) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

  dir = fout->GetDirectory("sim");
  if (!dir) {
    dir = fout->mkdir("sim");
    dir->cd();
  }

  h2simMatchedGeoPartJetPtJetPt[0]->Write();
  h2simMatchedGeoPartJetEtaJetEta[0][0]->Write();
  h2simMatchedGeoPartJetPhiJetPhi[0][0]->Write();
  h2simMatchedGeoPartJetNTracksJetNTracks[0][0]->Write();
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimMatchedGeoDiffJetPt[binJetPt][binJetR]->Write();
    }
  }

  delete fout;
}

// Draw function
void JetMatchedAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void JetMatchedAnalysis::drawCombined(int num, const std::vector<HistogramData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, GeneralJet::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (doLeg) leg->Draw();
}

void JetMatchedAnalysis::drawCombined2D(int num, const std::vector<Histogram2DData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH2F *hist = histograms[i].hist;
//    this->HistColorStyle(hist, i+1, i+20, GeneralJet::MARKERSIZE, i+1, 1);
//    TString clfi = histograms[i].classification;
//    leg->AddEntry(hist, clfi.Data(), "lep");
    //hist->SetOption("colztext");
    hist->Draw("same colz");
  }
  if (doLeg) leg->Draw();
}
// MC
void JetMatchedAnalysis::drawSimMatchedGeoPartJetPtJetPt(bool doLog = true, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPartJetPtJetPt[binJetR]->GetXaxis()->SetTitle("#it{p}_{T}^{jet_{part}}");
  h2simMatchedGeoPartJetPtJetPt[binJetR]->GetYaxis()->SetTitle("#it{p}_{T}^{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPartJetPtJetPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeopartjetptjetpt_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPartJetEtaJetEta(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPartJetEtaJetEta[binJetPt][binJetR]->GetXaxis()->SetTitle("#eta_{jet_{part}}");
  h2simMatchedGeoPartJetEtaJetEta[binJetPt][binJetR]->GetYaxis()->SetTitle("#eta_{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPartJetEtaJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeopartjetetajeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPartJetPhiJetPhi(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPartJetPhiJetPhi[binJetPt][binJetR]->GetXaxis()->SetTitle("#phi_{jet_{part}}");
  h2simMatchedGeoPartJetPhiJetPhi[binJetPt][binJetR]->GetYaxis()->SetTitle("#phi_{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPartJetPhiJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeopartjetphijetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPartJetNTracksJetNTracks(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPartJetNTracksJetNTracks[binJetPt][binJetR]->GetXaxis()->SetTitle("N_{track}^{jet_{part}}");
  h2simMatchedGeoPartJetNTracksJetNTracks[binJetPt][binJetR]->GetYaxis()->SetTitle("N_{track}^{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPartJetNTracksJetNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeopartjetntracksjetntracks_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtPartJetPtJetPt(bool doLog = true, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedPtPartJetPtJetPt[binJetR]->GetXaxis()->SetTitle("#it{p}_{T}^{jet_{part}}");
  h2simMatchedPtPartJetPtJetPt[binJetR]->GetYaxis()->SetTitle("#it{p}_{T}^{jet_{det}}");
  NormHistList.push_back({h2simMatchedPtPartJetPtJetPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtpartjetptjetpt_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtPartJetEtaJetEta(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedPtPartJetEtaJetEta[binJetPt][binJetR]->GetXaxis()->SetTitle("#eta_{jet_{part}}");
  h2simMatchedPtPartJetEtaJetEta[binJetPt][binJetR]->GetYaxis()->SetTitle("#eta_{jet_{det}}");
  NormHistList.push_back({h2simMatchedPtPartJetEtaJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtpartjetetajeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtPartJetPhiJetPhi(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedPtPartJetPhiJetPhi[binJetPt][binJetR]->GetXaxis()->SetTitle("#phi_{jet_{part}}");
  h2simMatchedPtPartJetPhiJetPhi[binJetPt][binJetR]->GetYaxis()->SetTitle("#phi_{jet_{det}}");
  NormHistList.push_back({h2simMatchedPtPartJetPhiJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtpartjetphijetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtPartJetNTracksJetNTracks(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedPtPartJetNTracksJetNTracks[binJetPt][binJetR]->GetXaxis()->SetTitle("N_{track}^{jet_{part}}");
  h2simMatchedPtPartJetNTracksJetNTracks[binJetPt][binJetR]->GetYaxis()->SetTitle("N_{track}^{jet_{det}}");
  NormHistList.push_back({h2simMatchedPtPartJetNTracksJetNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtpartjetntracksjetntracks_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPtPartJetPtJetPt(bool doLog = true, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPtPartJetPtJetPt[binJetR]->GetXaxis()->SetTitle("#it{p}_{T}^{jet_{part}}");
  h2simMatchedGeoPtPartJetPtJetPt[binJetR]->GetYaxis()->SetTitle("#it{p}_{T}^{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPtPartJetPtJetPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtpartjetptjetpt_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPtPartJetEtaJetEta(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPtPartJetEtaJetEta[binJetPt][binJetR]->GetXaxis()->SetTitle("#eta_{jet_{part}}");
  h2simMatchedGeoPtPartJetEtaJetEta[binJetPt][binJetR]->GetYaxis()->SetTitle("#eta_{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPtPartJetEtaJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtpartjetetajeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPtPartJetPhiJetPhi(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPtPartJetPhiJetPhi[binJetPt][binJetR]->GetXaxis()->SetTitle("#phi_{jet_{part}}");
  h2simMatchedGeoPtPartJetPhiJetPhi[binJetPt][binJetR]->GetYaxis()->SetTitle("#phi_{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPtPartJetPhiJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtpartjetphijetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPtPartJetNTracksJetNTracks(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<Histogram2DData> NormHistList;
  h2simMatchedGeoPtPartJetNTracksJetNTracks[binJetPt][binJetR]->GetXaxis()->SetTitle("N_{track}^{jet_{part}}");
  h2simMatchedGeoPtPartJetNTracksJetNTracks[binJetPt][binJetR]->GetYaxis()->SetTitle("N_{track}^{jet_{det}}");
  NormHistList.push_back({h2simMatchedGeoPtPartJetNTracksJetNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++, 0, 0, 800, 600, 0.12, 0.12, 0.05, 0.12);
  gStyle->SetOptStat(111);
  //if (doLog) gPad->SetLogx();
  //if (doLog) gPad->SetLogy();
  if (doLog) gPad->SetLogz();
  //canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], "#it{p}_{T}^{jet_{part}}", "#it{p}_{T}^{jet_{det}}");
  this->drawCombined2D(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtpartjetntracksjetntracks_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoDiffJetPt(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedGeoNormalizedDiffJetPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETPT[0], GeneralJet::REFHIST::DELTAJETPT[1], GeneralJet::REFHIST::DELTAJETPT[2], GeneralJet::REFHIST::DELTAJETPT[3], "#Delta#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}}#frac{jetd#it{N_{jet}}}{d#Delta#it{p}_{T}^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoDiffjetpt_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoDiffJetEta(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedGeoNormalizedDiffJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETETA[0], GeneralJet::REFHIST::DELTAJETETA[1], GeneralJet::REFHIST::DELTAJETETA[2], GeneralJet::REFHIST::DELTAJETETA[3], "#Delta#eta^{jet}", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#Delta#eta^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoDiffjeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoDiffJetPhi(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedGeoNormalizedDiffJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETPHI[0], GeneralJet::REFHIST::DELTAJETPHI[1], GeneralJet::REFHIST::DELTAJETPHI[2], GeneralJet::REFHIST::DELTAJETPHI[3], "#Delta#phi^{jet}", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#Delta#phi^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoDiffjetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtDiffJetPt(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedPtNormalizedDiffJetPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETPT[0], GeneralJet::REFHIST::DELTAJETPT[1], GeneralJet::REFHIST::DELTAJETPT[2], GeneralJet::REFHIST::DELTAJETPT[3], "#Delta#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}}#frac{jetd#it{N_{jet}}}{d#Delta#it{p}_{T}^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtDiffjetpt_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtDiffJetEta(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedPtNormalizedDiffJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETETA[0], GeneralJet::REFHIST::DELTAJETETA[1], GeneralJet::REFHIST::DELTAJETETA[2], GeneralJet::REFHIST::DELTAJETETA[3], "#Delta#eta^{jet}", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#Delta#eta^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtDiffjeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedPtDiffJetPhi(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedPtNormalizedDiffJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETPHI[0], GeneralJet::REFHIST::DELTAJETPHI[1], GeneralJet::REFHIST::DELTAJETPHI[2], GeneralJet::REFHIST::DELTAJETPHI[3], "#Delta#phi^{jet}", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#Delta#phi^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedPtDiffjetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}
void JetMatchedAnalysis::drawSimMatchedGeoPtDiffJetPt(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedGeoPtNormalizedDiffJetPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETPT[0], GeneralJet::REFHIST::DELTAJETPT[1], GeneralJet::REFHIST::DELTAJETPT[2], GeneralJet::REFHIST::DELTAJETPT[3], "#Delta#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}}#frac{jetd#it{N_{jet}}}{d#Delta#it{p}_{T}^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtDiffjetpt_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPtDiffJetEta(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedGeoPtNormalizedDiffJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETETA[0], GeneralJet::REFHIST::DELTAJETETA[1], GeneralJet::REFHIST::DELTAJETETA[2], GeneralJet::REFHIST::DELTAJETETA[3], "#Delta#eta^{jet}", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#Delta#eta^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtDiffjeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetMatchedAnalysis::drawSimMatchedGeoPtDiffJetPhi(bool doLog = true, int binJetPt=0, int binJetR =0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimMatchedGeoPtNormalizedDiffJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::DELTAJETPHI[0], GeneralJet::REFHIST::DELTAJETPHI[1], GeneralJet::REFHIST::DELTAJETPHI[2], GeneralJet::REFHIST::DELTAJETPHI[3], "#Delta#phi^{jet}", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#Delta#phi^{jet}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet_{part}} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet_{det}} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/matched/matchedGeoPtDiffjetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

#endif // JETMATCHEDANALYSIS_H
