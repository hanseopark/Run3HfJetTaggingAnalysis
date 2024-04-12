#ifndef JETRHOAREASUBANALYSIS_H
#define JETRHOAREASUBANALYSIS_H

#include <TH1.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

// TODO::
// data and particle level projection name is not perfect

class JetRhoAreaSubAnalysis {
  public:
    JetRhoAreaSubAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMCD, bool doDataRhoAreaSub, bool doRho, TString trigger) {
      initConfig(trigger.Data());
      if (doData) {
        if (!loadDataGeneralRhoAreaSubQA(rootData.Data(), doDataRhoAreaSub, doRho)) {
          return;
        }
        initHistogramForNormalizationGeneralRhoAreaSubQAData(doDataRhoAreaSub, doRho);
      	projectionHistGeneralRhoAreaSubQAData(doDataRhoAreaSub, doRho);
      	cloneNormalizedHistogramGeneralRhoAreaSubQAData(doDataRhoAreaSub, doRho);
      	normalizedHistogramGeneralRhoAreaSubQAData(doDataRhoAreaSub, doRho);
      }
      if (doMCD) {
        if (!loadSimGeneralRhoAreaSubQA(rootSim.Data(), doRho)) {
          return;
        }
        initHistogramForNormalizationGeneralRhoAreaSubQAMC(doRho);
      	projectionHistGeneralRhoAreaSubQAMC(doRho);
      	cloneNormalizedHistogramGeneralRhoAreaSubQAMC(doRho);
      	normalizedHistogramGeneralRhoAreaSubQAMC(doRho);
      }
      saveHistogramGeneralRhoAreaSubQA("GeneralJetRhoAreaSubQA.root", doData, doMCD, doDataRhoAreaSub, doRho);
    }

    ~JetRhoAreaSubAnalysis();

    // function
    void initConfig(TString triggerNAME);
    int loadDataGeneralRhoAreaSubQA(TString rootData, bool doDataRhoAreaSub, bool doRho);
    int loadSimGeneralRhoAreaSubQA(TString rootSim, bool doRho);
    void initHistogramForNormalizationGeneralRhoAreaSubQAData(bool doDataRhoAreaSub, bool doRho);
    void initHistogramForNormalizationGeneralRhoAreaSubQAMC(bool doRho);
    void projectionHistGeneralRhoAreaSubQAData(bool doDataRhoAreaSub, bool doRho);
    void projectionHistGeneralRhoAreaSubQAMC(bool doRho);
    void cloneNormalizedHistogramGeneralRhoAreaSubQAData(bool doDataRhoAreaSub, bool doRho);
    void cloneNormalizedHistogramGeneralRhoAreaSubQAMC(bool doRho);
    void normalizedHistogramGeneralRhoAreaSubQAData(bool doDataRhoAreaSub, bool doRho);
    void normalizedHistogramGeneralRhoAreaSubQAMC(bool doRho);
    void saveHistogramGeneralRhoAreaSubQA(TString rootFile, bool doData, bool doMCD, bool doDataRhoAreaSub, bool doRho);

    // Draw option
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void drawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);
    void drawDataGenRhoAreaSubJetPt(bool doLog, int binJetR);
    void drawDataGenRhoAreaSubJetEta(bool doLog, int binJetPt, int binJetR);
    void drawDataGenRhoAreaSubJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawDataGenRhoAreaSubJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawDataGenRhoAreaSubJetArea(bool doLog, int binJetPt, int binJetR);
    void drawDataGenRhoAreaSubJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawDataGenRhoAreaSubJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawDataGenRhoAreaSubJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetRho(bool doLog, int binNTracks);
    void drawDataGenJetRhoM(bool doLog, int binNTracks);
    void drawDataGenJetPtComparedToRhoAreaSub(bool doLog, int binJetR);
    void drawSimGenJetRho(bool doLog, int binNTracks);
    void drawSimGenJetRhoM(bool doLog, int binNTracks);

    void drawRatioDataMCGenJetPt(bool doLog, int binJetR);

    // histogram from root file
    /// DATA
    TH1F* hdataGenJetPt;
    TH1F* hdataGenJetPtRhoAreaSub[GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetEtaRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetPhiRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetNTracksRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetAreaRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetTrackPtRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetTrackEtaRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetTrackPhiRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetRho[GeneralJet::nBinsJetNTracks];
    TH1F* hdataGenJetRhoM[GeneralJet::nBinsJetNTracks];

    /// MCD
    TH1F* hsimGenJetRho[GeneralJet::nBinsJetNTracks];
    TH1F* hsimGenJetRhoM[GeneralJet::nBinsJetNTracks];

  protected:
    // draw option
    int canvasNum=0;
    CanvasHandler* canvasHandler;

    // histogram
    /// Data
    //// Data: RhoAreaSub
    TH1F* h1dataGenJetPtRhoAreaSub;
    TH1F* h1dataGenJetEtaRhoAreaSub;
    TH1F* h1dataGenJetPhiRhoAreaSub;
    TH1F* h1dataGenJetNTracksRhoAreaSub;
    TH2F* h2dataGenCentralityJetPtRhoAreaSub;
    TH2F* h2dataGenCentralityJetEtaRhoAreaSub;
    TH2F* h2dataGenCentralityJetPhiRhoAreaSub;
    TH2F* h2dataGenCentralityJetNTracksRhoAreaSub;
    TH3F* h3dataGenJetRJetPtCentralityRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetEtaRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetPhiRhoAreaSub;
    TH3F* h3dataGenJetRJetEtaJetPhiRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetNTracksRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetAreaRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetTrackPtRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetTrackEtaRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetTrackPhiRhoAreaSub;
    TH3F* h3dataGenJetRJetPtJetPtRhoAreaSub;
    TH2F* h2dataGenCentralityJetNTracks;
    TH2F* h2dataGenJetNTracksJetRho;
    TH2F* h2dataGenJetNTracksJetRhoM;
    TH2F* h2dataGenCentralityJetRho;
    TH2F* h2dataGenCentralityJetRhoM;

    /// MC
    TH2F* h2simGenCentralityJetNTracks;
    TH2F* h2simGenJetNTracksJetRho;
    TH2F* h2simGenJetNTracksJetRhoM;
    TH2F* h2simGenCentralityJetRho;
    TH2F* h2simGenCentralityJetRhoM;

    // Normalized histogram
    /// data, mcd
    TH1F* hdataGenNormalizedJetPt;
    TH1F* hdataGenNormalizedJetPtRhoAreaSub[GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetEtaRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetPhiRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetNTracksRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetAreaRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetTrackPtRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetTrackEtaRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetTrackPhiRhoAreaSub[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetRho[GeneralJet::nBinsJetNTracks];
    TH1F* hdataGenNormalizedJetRhoM[GeneralJet::nBinsJetNTracks];

    /// MCD
    TH1F* hsimGenNormalizedJetRho[GeneralJet::nBinsJetNTracks];
    TH1F* hsimGenNormalizedJetRhoM[GeneralJet::nBinsJetNTracks];

  private:
    std::vector<HistogramData> histList;
    TLatex latex;
    TString triggerName;

};

JetRhoAreaSubAnalysis::~JetRhoAreaSubAnalysis() {
}

void JetRhoAreaSubAnalysis::initConfig(TString trigger) {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  triggerName = trigger.Data();
  TString dirData = "fig/data/general/rhoareasub";
  TString dirSim = Form("fig/sim/%s/general/rhoareasub", triggerName.Data());
  TString dirDataVsSim = Form("fig/dataVSsim/%s/general/rhoareasub", triggerName.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int JetRhoAreaSubAnalysis::loadDataGeneralRhoAreaSubQA(TString rootData, bool doDataRhoAreaSub, bool doRho) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";

  hdataGenJetPt = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_pt", taskJetQA.Data())));
  if (doDataRhoAreaSub) {
    h1dataGenJetPtRhoAreaSub = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_pt_rhoareasubtracted", taskJetQA.Data())));
    h1dataGenJetEtaRhoAreaSub = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_eta_rhoareasubtracted", taskJetQA.Data())));
    h1dataGenJetPhiRhoAreaSub = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_phi_rhoareasubtracted", taskJetQA.Data())));
    h1dataGenJetNTracksRhoAreaSub = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_ntracks_rhoareasubtracted", taskJetQA.Data())));
    h2dataGenCentralityJetPtRhoAreaSub = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_jet_pt_rhoareasubtracted", taskJetQA.Data())));
    h2dataGenCentralityJetEtaRhoAreaSub = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_jet_eta_rhoareasubtracted", taskJetQA.Data())));
    h2dataGenCentralityJetPhiRhoAreaSub = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_jet_phi_rhoareasubtracted", taskJetQA.Data())));
    h2dataGenCentralityJetNTracksRhoAreaSub = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_jet_ntracks_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtCentralityRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_centrality_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetEtaRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetPhiRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
    h3dataGenJetRJetEtaJetPhiRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetNTracksRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetAreaRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetTrackPtRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetTrackEtaRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetTrackPhiRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi_rhoareasubtracted", taskJetQA.Data())));
    h3dataGenJetRJetPtJetPtRhoAreaSub = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_pt_rhoareasubtracted", taskJetQA.Data())));
  }
  if (doRho) {
    h2dataGenCentralityJetNTracks = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_ntracks", taskJetQA.Data())));
    h2dataGenJetNTracksJetRho = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_ntracks_rho", taskJetQA.Data())));
    h2dataGenJetNTracksJetRhoM = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_ntracks_rhom", taskJetQA.Data())));
    h2dataGenCentralityJetRho = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_rho", taskJetQA.Data())));
    h2dataGenCentralityJetRhoM = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_rhom", taskJetQA.Data())));
  }

  return 1;
}

int JetRhoAreaSubAnalysis::loadSimGeneralRhoAreaSubQA(TString rootSim, bool doRho = false) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";

  if (doRho) {
    h2simGenCentralityJetNTracks = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_ntracks", taskJetQA.Data())));
    h2simGenJetNTracksJetRho = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_ntracks_rho", taskJetQA.Data())));
    h2simGenJetNTracksJetRhoM = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_ntracks_rhom", taskJetQA.Data())));
    h2simGenCentralityJetRho = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_rho", taskJetQA.Data())));
    h2simGenCentralityJetRhoM = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_centrality_rhom", taskJetQA.Data())));
  }

  std::cout << "Load completed General Jet QA MC" << std::endl;
  return 1;
}

void JetRhoAreaSubAnalysis::initHistogramForNormalizationGeneralRhoAreaSubQAData(bool doDataRhoAreaSub, bool doRho) {
  if (doDataRhoAreaSub) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hdataGenJetPtRhoAreaSub[binJetR] = new TH1F(Form("hdataGenJetPtRhoAreaSub_%d", binJetR), "", h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsY(), h3dataGenJetRJetPtJetEtaRhoAreaSub->GetYaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetEtaRhoAreaSub->GetYaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsY()));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hdataGenJetEtaRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetEtaRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetEtaRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetEtaRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsZ()));
        hdataGenJetPhiRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetPhiRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetPhiRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetPhiRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetPhiRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetPhiRhoAreaSub->GetNbinsZ()));
        hdataGenJetNTracksRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetNTracksRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetNbinsZ()));
        hdataGenJetAreaRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetAreaRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetAreaRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetAreaRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsZ()));
        hdataGenJetTrackPtRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetTrackPtRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetNbinsZ()));
        hdataGenJetTrackEtaRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetTrackEtaRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetNbinsZ()));
        hdataGenJetTrackPhiRhoAreaSub[binJetPt][binJetR] = new TH1F(Form("hdataGenJetTrackPhiRhoAreaSub_%d_%d", binJetPt, binJetR), "", h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetNbinsZ(), h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetZaxis()->GetBinUpEdge(h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetNbinsZ()));
      }
    }

  }
  if (doRho) {
    for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      hdataGenJetRho[binJetNTracks] = new TH1F(Form("hdataGenJetRho_%d", binJetNTracks), "", h2dataGenJetNTracksJetRho->GetNbinsY(), h2dataGenJetNTracksJetRho->GetYaxis()->GetBinLowEdge(1), h2dataGenJetNTracksJetRho->GetYaxis()->GetBinUpEdge(h2dataGenJetNTracksJetRho->GetNbinsY()));
      hdataGenJetRhoM[binJetNTracks] = new TH1F(Form("hdataGenJetRhoM_%d", binJetNTracks), "", h2dataGenJetNTracksJetRhoM->GetNbinsY(), h2dataGenJetNTracksJetRhoM->GetYaxis()->GetBinLowEdge(1), h2dataGenJetNTracksJetRhoM->GetYaxis()->GetBinUpEdge(h2dataGenJetNTracksJetRhoM->GetNbinsY()));
    }
  }
}

void JetRhoAreaSubAnalysis::initHistogramForNormalizationGeneralRhoAreaSubQAMC(bool doRho = false) {
  if (doRho) {
    for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      hsimGenJetRho[binJetNTracks] = new TH1F(Form("hsimGenJetRho_%d", binJetNTracks), "", h2simGenJetNTracksJetRho->GetNbinsY(), h2simGenJetNTracksJetRho->GetYaxis()->GetBinLowEdge(1), h2simGenJetNTracksJetRho->GetYaxis()->GetBinUpEdge(h2simGenJetNTracksJetRho->GetNbinsY()));
      hsimGenJetRhoM[binJetNTracks] = new TH1F(Form("hsimGenJetRhoM_%d", binJetNTracks), "", h2simGenJetNTracksJetRhoM->GetNbinsY(), h2simGenJetNTracksJetRhoM->GetYaxis()->GetBinLowEdge(1), h2simGenJetNTracksJetRhoM->GetYaxis()->GetBinUpEdge(h2simGenJetNTracksJetRhoM->GetNbinsY()));
    }
  }
}

void JetRhoAreaSubAnalysis::projectionHistGeneralRhoAreaSubQAData(bool doRhoAreaSub=false, bool doRho=false) {

  if (doRhoAreaSub) {
    TH1F *projJetPt = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetEtaRhoAreaSub->ProjectionY("projJetPt", 1, h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsZ()));
    TH1F *projJetEta = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetEtaRhoAreaSub->ProjectionZ("projJetEta", 1, h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsY()));
    TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetPhiRhoAreaSub->ProjectionZ("projJetPhi", 1, h3dataGenJetRJetPtJetPhiRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetPhiRhoAreaSub->GetNbinsY()));
    TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetNTracksRhoAreaSub->ProjectionZ("projJetNTracks", 1, h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetNbinsY()));
    TH1F *projJetArea = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetAreaRhoAreaSub->ProjectionZ("projJetArea", 1, h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsY()));
    TH1F *projJetTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetTrackPtRhoAreaSub->ProjectionZ("projJetTrackPt", 1, h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetNbinsY()));
    TH1F *projJetTrackEta = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->ProjectionZ("projJetTrackEta", 1, h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetNbinsY()));
    TH1F *projJetTrackPhi = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->ProjectionZ("projJetTrackPhi", 1, h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetNbinsX(), 1, h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetNbinsY()));

    hdataGenJetPtRhoAreaSub[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
    hdataGenJetEtaRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
    hdataGenJetPhiRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
    hdataGenJetNTracksRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
    hdataGenJetAreaRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
    hdataGenJetTrackPtRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetTrackPt->Clone());
    hdataGenJetTrackEtaRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetTrackEta->Clone());
    hdataGenJetTrackPhiRhoAreaSub[0][0] = reinterpret_cast<TH1F*>(projJetTrackPhi->Clone());

    for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      // jet pt
      int leftbinJetRForJetPt = h3dataGenJetRJetPtJetEtaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPt = h3dataGenJetRJetPtJetEtaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetEtaRhoAreaSub->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsZ()));
      hdataGenJetPtRhoAreaSub[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

      // jet eta
      int leftbinJetRForJetEta = h3dataGenJetRJetPtJetEtaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetEta = h3dataGenJetRJetPtJetEtaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetEtaRhoAreaSub->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3dataGenJetRJetPtJetEtaRhoAreaSub->GetNbinsZ()));
      hdataGenJetEtaRhoAreaSub[0][binJetR]->Add(projJetRRangeJetEta);

      // jet phi
      int leftbinJetRForJetPhi = h3dataGenJetRJetPtJetPhiRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPhi = h3dataGenJetRJetPtJetPhiRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetPhiRhoAreaSub->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3dataGenJetRJetPtJetPhiRhoAreaSub->GetNbinsZ()));
      hdataGenJetPhiRhoAreaSub[0][binJetR]->Add(projJetRRangeJetPhi);

      // number of tracks
      int leftbinJetRForJetNTracks = h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetNTracks = h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetNTracksRhoAreaSub->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetNbinsZ()));
      hdataGenJetNTracksRhoAreaSub[0][binJetR]->Add(projJetRRangeJetNTracks);

      // jet area
      int leftbinJetRForJetArea = h3dataGenJetRJetPtJetAreaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetArea = h3dataGenJetRJetPtJetAreaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetAreaRhoAreaSub->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsZ()));
      hdataGenJetAreaRhoAreaSub[0][binJetR]->Add(projJetRRangeJetArea);

      // track pt
      int leftbinJetRForTrackPt = h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPt = h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetAreaRhoAreaSub->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsZ()));
      hdataGenJetTrackPtRhoAreaSub[0][binJetR]->Add(projJetRRangeTrackPt);

      // track eta
      int leftbinJetRForTrackEta = h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackEta = h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetAreaRhoAreaSub->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsZ()));
      hdataGenJetTrackEtaRhoAreaSub[0][binJetR]->Add(projJetRRangeTrackEta);

      // track phi
      int leftbinJetRForTrackPhi = h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPhi = h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetAreaRhoAreaSub->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3dataGenJetRJetPtJetAreaRhoAreaSub->GetNbinsZ()));
      hdataGenJetTrackPhiRhoAreaSub[0][binJetR]->Add(projJetRRangeTrackPhi);

      for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
        // jet eta
        int leftbinJetPtForJetEta = h3dataGenJetRJetPtJetEtaRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetEta = h3dataGenJetRJetPtJetEtaRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetEtaRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeJetEta_%d_%d", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
        hdataGenJetEtaRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
        hdataGenJetEtaRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

        // jet phi
        int leftbinJetPtForJetPhi = h3dataGenJetRJetPtJetPhiRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetPhi = h3dataGenJetRJetPtJetPhiRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetPhiRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
        hdataGenJetPhiRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
        hdataGenJetPhiRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

        // number of tracks
        int leftbinJetPtForJetNTracks = h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetNTracks = h3dataGenJetRJetPtJetNTracksRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetNTracksRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
        hdataGenJetNTracksRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
        hdataGenJetNTracksRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

        // jet area
        int leftbinJetPtForJetArea = h3dataGenJetRJetPtJetAreaRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetArea = h3dataGenJetRJetPtJetAreaRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetAreaRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetR, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
        hdataGenJetAreaRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
        hdataGenJetAreaRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

        // track pt
        int leftbinJetPtForTrackPt = h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackPt = h3dataGenJetRJetPtJetTrackPtRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetTrackPtRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
        hdataGenJetTrackPtRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
        hdataGenJetTrackPtRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

        // track eta
        int leftbinJetPtForTrackEta = h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackEta = h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetTrackEtaRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
        hdataGenJetTrackEtaRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
        hdataGenJetTrackEtaRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

        // track phi
        int leftbinJetPtForTrackPhi = h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackPhi = h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataGenJetRJetPtJetTrackPhiRhoAreaSub->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
        hdataGenJetTrackPhiRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
        hdataGenJetTrackPhiRhoAreaSub[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      }
    }
  }
  if (doRho) {
    TH1F *projJetRho = reinterpret_cast<TH1F*> (h2dataGenJetNTracksJetRho->ProjectionY("projJetRho", 1, h2dataGenJetNTracksJetRho->GetNbinsX()));
    TH1F *projJetRhoM = reinterpret_cast<TH1F*> (h2dataGenJetNTracksJetRhoM->ProjectionY("projJetRhoM", 1, h2dataGenJetNTracksJetRhoM->GetNbinsX()));

    hdataGenJetRho[0] = reinterpret_cast<TH1F*>(projJetRho->Clone());
    hdataGenJetRhoM[0] = reinterpret_cast<TH1F*>(projJetRhoM->Clone());
    for (int binJetNTracks=1; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      // Rho
      int leftbinJetRho = h2dataGenJetNTracksJetRho->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks-1]);
      int rightbinJetRho = h2dataGenJetNTracksJetRho->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks]);
      TH1F* projJetRhoRangeJetNTracks = reinterpret_cast<TH1F*> (h2dataGenJetNTracksJetRho->ProjectionY(Form("projJetRhoRangeJetNTracks_%d", binJetNTracks), leftbinJetRho, rightbinJetRho));
      hdataGenJetRho[binJetNTracks] = reinterpret_cast<TH1F*> (projJetRhoRangeJetNTracks);

      // RhoM
      int leftbinJetRhoM = h2dataGenJetNTracksJetRhoM->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks-1]);
      int rightbinJetRhoM = h2dataGenJetNTracksJetRhoM->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks]);
      TH1F* projJetRhoMRangeJetNTracks = reinterpret_cast<TH1F*> (h2dataGenJetNTracksJetRhoM->ProjectionY(Form("projJetRhoMRangeJetNTracks_%d", binJetNTracks), leftbinJetRhoM, rightbinJetRhoM));
      hdataGenJetRhoM[binJetNTracks] = reinterpret_cast<TH1F*> (projJetRhoMRangeJetNTracks);

    }
  }
}

void JetRhoAreaSubAnalysis::projectionHistGeneralRhoAreaSubQAMC(bool doRho= false) {
  if (doRho) {
    TH1F *projJetRho = reinterpret_cast<TH1F*> (h2simGenJetNTracksJetRho->ProjectionY("projJetRho", 1, h2simGenJetNTracksJetRho->GetNbinsX()));
    TH1F *projJetRhoM = reinterpret_cast<TH1F*> (h2simGenJetNTracksJetRhoM->ProjectionY("projJetRhoM", 1, h2simGenJetNTracksJetRhoM->GetNbinsX()));

    hsimGenJetRho[0] = reinterpret_cast<TH1F*>(projJetRho->Clone());
    hsimGenJetRhoM[0] = reinterpret_cast<TH1F*>(projJetRhoM->Clone());
    for (int binJetNTracks=1; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      // Rho
      int leftbinJetRho = h2simGenJetNTracksJetRho->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks-1]);
      int rightbinJetRho = h2simGenJetNTracksJetRho->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks]);
      TH1F* projJetRhoRangeJetNTracks = reinterpret_cast<TH1F*> (h2simGenJetNTracksJetRho->ProjectionY(Form("projJetRhoRangeJetNTracks_%d", binJetNTracks), leftbinJetRho, rightbinJetRho));
      hsimGenJetRho[binJetNTracks] = reinterpret_cast<TH1F*> (projJetRhoRangeJetNTracks);

      // RhoM
      int leftbinJetRhoM = h2simGenJetNTracksJetRhoM->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks-1]);
      int rightbinJetRhoM = h2simGenJetNTracksJetRhoM->GetXaxis()->FindBin(GeneralJet::binsJetNTracks[binJetNTracks]);
      TH1F* projJetRhoMRangeJetNTracks = reinterpret_cast<TH1F*> (h2simGenJetNTracksJetRhoM->ProjectionY(Form("projJetRhoMRangeJetNTracks_%d", binJetNTracks), leftbinJetRhoM, rightbinJetRhoM));
      hsimGenJetRhoM[binJetNTracks] = reinterpret_cast<TH1F*> (projJetRhoMRangeJetNTracks);
    }
  }
}

void JetRhoAreaSubAnalysis::cloneNormalizedHistogramGeneralRhoAreaSubQAData(bool doRhoAreaSub = false, bool doRho = false) {
  hdataGenNormalizedJetPt = reinterpret_cast<TH1F*>(hdataGenJetPt->Clone("hdataGenNormalizedJetPt"));
  if (doRhoAreaSub) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hdataGenNormalizedJetPtRhoAreaSub[binJetR] = reinterpret_cast<TH1F*>(hdataGenJetPtRhoAreaSub[binJetR]->Clone(Form("hdataGenNormalizedJetPtRhoAreaSub_%d", binJetR)));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hdataGenNormalizedJetEtaRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetEtaRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetEtaRhoAreaSub_%d_%d", binJetPt, binJetR)));
        hdataGenNormalizedJetPhiRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetPhiRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetPhiRhoAreaSub_%d_%d", binJetPt, binJetR)));
        hdataGenNormalizedJetNTracksRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetNTracksRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetNTracksRhoAreaSub_%d_%d", binJetPt, binJetR)));
        hdataGenNormalizedJetAreaRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetAreaRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetAreaRhoAreaSub_%d_%d", binJetPt, binJetR)));
        hdataGenNormalizedJetTrackPtRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetTrackPtRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetTrackPtRhoAreaSub_%d_%d", binJetPt, binJetR)));
        hdataGenNormalizedJetTrackEtaRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetTrackEtaRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetTrackEtaRhoAreaSub_%d_%d", binJetPt, binJetR)));
        hdataGenNormalizedJetTrackPhiRhoAreaSub[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetTrackPhiRhoAreaSub[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetTrackPhiRhoAreaSub_%d_%d", binJetPt, binJetR)));
      }
    }
  }
  if (doRho) {
    for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      hdataGenNormalizedJetRho[binJetNTracks] = reinterpret_cast<TH1F*> (hdataGenJetRho[binJetNTracks]->Clone(Form("hdataGenNormalizedJetRho_%d", binJetNTracks)));
      hdataGenNormalizedJetRhoM[binJetNTracks] = reinterpret_cast<TH1F*> (hdataGenJetRho[binJetNTracks]->Clone(Form("hdataGenNormalizedJetRhoM_%d", binJetNTracks)));
    }
  }
}

void JetRhoAreaSubAnalysis::cloneNormalizedHistogramGeneralRhoAreaSubQAMC(bool doRho=false) {
  if (doRho) {
    for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      hsimGenNormalizedJetRho[binJetNTracks] = reinterpret_cast<TH1F*> (hsimGenJetRho[binJetNTracks]->Clone(Form("hsimGenNormalizedJetRho_%d", binJetNTracks)));
      hsimGenNormalizedJetRhoM[binJetNTracks] = reinterpret_cast<TH1F*> (hsimGenJetRho[binJetNTracks]->Clone(Form("hsimGenNormalizedJetRhoM_%d", binJetNTracks)));
    }
  }
}

void JetRhoAreaSubAnalysis::normalizedHistogramGeneralRhoAreaSubQAData(bool doRhoAreaSub=false, bool doRho=false) {
  hdataGenNormalizedJetPt->Scale(1. / hdataGenNormalizedJetPt->Integral());
  if (doRhoAreaSub) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hdataGenNormalizedJetPtRhoAreaSub[binJetR]->Scale(1. / hdataGenNormalizedJetPtRhoAreaSub[binJetR]->Integral());
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hdataGenNormalizedJetEtaRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetEtaRhoAreaSub[binJetPt][binJetR]->Integral());
        hdataGenNormalizedJetPhiRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetPhiRhoAreaSub[binJetPt][binJetR]->Integral());
        hdataGenNormalizedJetNTracksRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetNTracksRhoAreaSub[binJetPt][binJetR]->Integral());
        hdataGenNormalizedJetAreaRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetAreaRhoAreaSub[binJetPt][binJetR]->Integral());
        hdataGenNormalizedJetTrackPtRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetTrackPtRhoAreaSub[binJetPt][binJetR]->Integral());
        hdataGenNormalizedJetTrackEtaRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetTrackEtaRhoAreaSub[binJetPt][binJetR]->Integral());
        hdataGenNormalizedJetTrackPhiRhoAreaSub[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetTrackPhiRhoAreaSub[binJetPt][binJetR]->Integral());
      }
    }
  }
  if (doRho) {
    for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      hdataGenNormalizedJetRho[binJetNTracks]->Scale(1. / hdataGenNormalizedJetRho[binJetNTracks]->GetEntries());
      hdataGenNormalizedJetRhoM[binJetNTracks]->Scale(1. / hdataGenNormalizedJetRhoM[binJetNTracks]->GetEntries());
    }
  }
}

void JetRhoAreaSubAnalysis::normalizedHistogramGeneralRhoAreaSubQAMC(bool doRho=false) {
  if (doRho) {
    for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
      hsimGenNormalizedJetRho[binJetNTracks]->Scale(1. / hsimGenNormalizedJetRho[binJetNTracks]->GetEntries());
      hsimGenNormalizedJetRhoM[binJetNTracks]->Scale(1. / hsimGenNormalizedJetRhoM[binJetNTracks]->GetEntries());
    }
  }
}

void JetRhoAreaSubAnalysis::saveHistogramGeneralRhoAreaSubQA(TString rootFile, bool doData, bool doMC, bool doRhoAreaSub, bool doRho) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

  if (doData) {
    dir = fout->GetDirectory("data");
    if (!dir) {
      dir = fout->mkdir("data");
      dir->cd();
    }

    if (doRhoAreaSub) {
      for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
        hdataGenJetPtRhoAreaSub[binJetR]->Write();
        for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
          hdataGenJetEtaRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenJetPhiRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenJetNTracksRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenJetAreaRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenJetTrackPtRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenJetTrackEtaRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenJetTrackPhiRhoAreaSub[binJetPt][binJetR]->Write();

          hdataGenNormalizedJetEtaRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenNormalizedJetPhiRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenNormalizedJetNTracksRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenNormalizedJetAreaRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenNormalizedJetTrackPtRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenNormalizedJetTrackEtaRhoAreaSub[binJetPt][binJetR]->Write();
          hdataGenNormalizedJetTrackPhiRhoAreaSub[binJetPt][binJetR]->Write();
        }
      }

    }
    if (doRho) {
      for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
        hdataGenJetRho[binJetNTracks]->Write();
        hdataGenJetRhoM[binJetNTracks]->Write();
        hdataGenNormalizedJetRho[binJetNTracks]->Write();
        hdataGenNormalizedJetRhoM[binJetNTracks]->Write();
      }
    }
  }

  if (doMC) {
    dir = fout->GetDirectory("sim");
    if (!dir) {
      dir = fout->mkdir("sim");
      dir->cd();
    }
     if (doRho) {
      for (int binJetNTracks =0; binJetNTracks < GeneralJet::nBinsJetNTracks+1; binJetNTracks++) {
        hsimGenJetRho[binJetNTracks]->Write();
        hsimGenJetRhoM[binJetNTracks]->Write();
        hsimGenNormalizedJetRho[binJetNTracks]->Write();
        hsimGenNormalizedJetRhoM[binJetNTracks]->Write();
      }
    }   
  }

  delete fout;
}

// Draw function
void JetRhoAreaSubAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void JetRhoAreaSubAnalysis::drawCombined(int num, const std::vector<HistogramData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax){
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

// Data
void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetPt(bool doLog = true, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetPtRhoAreaSub[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], " #it{p}_{T}^{jet}", "1/#it{N_{jet}} d#it{N_{jet}}/d#it{p}_{T}^{jet}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetR > 0) latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/rhoareasub/jetmomentum_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetEta(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetEtaRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETETA[0], GeneralJet::REFHIST::JETETA[1], GeneralJet::REFHIST::JETETA[2], GeneralJet::REFHIST::JETETA[3], "#eta", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{#eta}^{jet}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/rhoareasub/jeteta_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetPhi(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetPhiRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPHI[0], GeneralJet::REFHIST::JETPHI[1], GeneralJet::REFHIST::JETPHI[2], GeneralJet::REFHIST::JETPHI[3], "#phi", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{#phi}^{jet}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/rhoareasub/jetphi_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetNTracks(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetNTracksRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETNTRACKS[0], GeneralJet::REFHIST::JETNTRACKS[1], GeneralJet::REFHIST::JETNTRACKS[2], GeneralJet::REFHIST::JETNTRACKS[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{N_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/rhoareasub/jetNTracks_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetArea(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetAreaRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETAREA[0], GeneralJet::REFHIST::JETAREA[1], GeneralJet::REFHIST::JETAREA[2], GeneralJet::REFHIST::JETAREA[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{N_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/rhoareasub/jetArea_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetTrackPt(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackPtRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{track}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/rhoareasub/jetTrackPt_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetTrackEta(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackEtaRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKETA[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#eta_{track}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/rhoareasub/jetTrackEta_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));


}

void JetRhoAreaSubAnalysis::drawDataGenRhoAreaSubJetTrackPhi(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackPhiRhoAreaSub[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPHI[0], GeneralJet::REFHIST::TRACKPHI[1], GeneralJet::REFHIST::TRACKPHI[2], GeneralJet::REFHIST::TRACKPHI[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#phi_{track}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/rhoareasub/jetTrackPhi_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetRhoAreaSubAnalysis::drawDataGenJetRho(bool doLog = true, int binNTracks =0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetRho[binNTracks], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::RHO[0], GeneralJet::REFHIST::RHO[1], GeneralJet::REFHIST::RHO[2], GeneralJet::REFHIST::RHO[3], "#rho", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#it{#rho}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binNTracks > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d <= nTracks < %d", static_cast<int>(GeneralJet::binsJetNTracks[binNTracks-1]), static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/rhoareasub/rho_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
}

void JetRhoAreaSubAnalysis::drawDataGenJetRhoM(bool doLog = true, int binNTracks =0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetRhoM[binNTracks], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::RHOM[0], GeneralJet::REFHIST::RHOM[1], GeneralJet::REFHIST::RHOM[2], GeneralJet::REFHIST::RHOM[3], "#rhoM", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#it{#rhoM}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binNTracks > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d <= nTracks < %d", static_cast<int>(GeneralJet::binsJetNTracks[binNTracks-1]), static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/rhoareasub/rhoM_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
}

void JetRhoAreaSubAnalysis::drawDataGenJetPtComparedToRhoAreaSub(bool doLog = true, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetPt, "raw"});
	NormHistList.push_back({hdataGenNormalizedJetPtRhoAreaSub[binJetR], "Bkg subtracted"});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], " #it{p}_{T}^{jet}", "1/#it{N_{jet}} d#it{N_{jet}}/d#it{p}_{T}^{jet}");
  this->drawCombined(NormHistList.size(), NormHistList, true, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetR > 0) latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/rhoareasub/jetmomentumCompareToRaw_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

// MC
void JetRhoAreaSubAnalysis::drawSimGenJetRho(bool doLog = true, int binNTracks =0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetRho[binNTracks], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::RHO[0], GeneralJet::REFHIST::RHO[1], GeneralJet::REFHIST::RHO[2], GeneralJet::REFHIST::RHO[3], "#rho", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#it{#rho}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binNTracks > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d <= nTracks < %d", static_cast<int>(GeneralJet::binsJetNTracks[binNTracks-1]), static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/rhoareasub/rho_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
}

void JetRhoAreaSubAnalysis::drawSimGenJetRhoM(bool doLog = true, int binNTracks =0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetRhoM[binNTracks], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::RHOM[0], GeneralJet::REFHIST::RHOM[1], GeneralJet::REFHIST::RHOM[2], GeneralJet::REFHIST::RHOM[3], "#rhoM", "#frac{1}{#it{N_{jet}}}#frac{d#it{N_{jet}}}{d#it{#rhoM}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binNTracks > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d <= nTracks < %d", static_cast<int>(GeneralJet::binsJetNTracks[binNTracks-1]), static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/rhoareasub/rhoM_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetNTracks[binNTracks])));
}

//void JetRhoAreaSubAnalysis::drawRatioDataMCGenJetPt(bool doLog = false, int binJetR =0) {
//  TH1F *hRatio = static_cast<TH1F*>(hdataGenNormalizedJetPtRhoAreaSub[binJetR]->Clone("hRatio"));
//  hRatio->Divide(hsimGenNormalizedJetPt[binJetR]);
//  canvasHandler = new CanvasHandler();
//  canvasHandler->drawUpperPad(hsimGenNormalizedJetPt[binJetR], canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "","#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}");
//  canvasHandler->drawLowerPad(hRatio, canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "#it{p}_{T}^{jet}");
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/general/temp.pdf\")", canvasNum));
//  canvasNum++;
//}

#endif // JETRHOAREASUBANALYSIS_H
