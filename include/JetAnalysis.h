#ifndef JETANALYSIS_H
#define JETANALYSIS_H

#include <TH1.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

// TODO::
// data and particle level projection name is not perfect

class JetAnalysis {
  public:
    JetAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMCD, bool doMCP, TString trigger) {
      initConfig();
    }

    ~JetAnalysis();

    // function
    /// Basic
    void initConfig();
    int loadDataGeneralQA(TString rootData);
    int loadSimGeneralQA(TString rootSim);
    void initHistogramForNormalizationGeneralQAData();
    void initHistogramForNormalizationGeneralQAMC();
    void projectionHistGeneralQAData();
    void projectionHistGeneralQAMC();
    void clonenormalizedHistogramGeneralQAData();
    void clonenormalizedHistogramGeneralQAMC();
    void normalizedHistogramGeneralQAData();
    void normalizedHistogramGeneralQAMC();
    void SaveHistogramGeneralQA(TString rootFile, bool doData, bool doMC, bool doMCP);

    /// Set
    void setFillData(bool fillData);
    void setFillMCD(bool fillMCD);
    void setFillMCP(bool fillMCP);
    void setFillMatched(bool fillMatched);

    // Draw option
    void drawDataJetPt(bool doLog, int binJetR);
    void drawDataJetEta(bool doLog, int binJetPt, int binJetR);
    void drawDataJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawDataJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawDataJetArea(bool doLog, int binJetPt, int binJetR);
    void drawDataJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawDataJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawDataJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void drawDataJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);

    void drawSimJetPt(bool doLog, int binJetR);
    void drawSimJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawSimJetArea(bool doLog, int binJetPt, int binJetR);
    void drawSimJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawSimJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawSimJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);

    void drawSimPartJetPt(bool doLog, int binJetR);
    void drawSimPartJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimPartJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimPartJetNTracks(bool doLog, int binJetPt, int binJetR);
    //void drawSimPartJetArea(bool doLog, int binJetPt, int binJetR);
    void drawSimPartJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawSimPartJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawSimPartJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    //void drawSimPartJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);
    void DrawRatioDataMCGenJetPt(bool doLog, int binJetR);

    // histogram from root file
    /// data, mcd
    TH1F* hdataJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hdataJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    TH1F* hsimJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    /// mcp
    TH1F* hsimPartJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    //TH1F* hsimPartJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimPartJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

  protected:
    // draw option
    int nc=0;
    CanvasHandler* canHan;
    int nEvent = -1;
    TString dirFig = "fig";
    bool fillData = false;
    bool fillMCD = false;
    bool fillMCP = false;
    bool fillMatched = false;

    // histogram
    /// Data
    TH1F* hdataJetPt;
    TH1F* hdataJetEta;
    TH1F* hdataJetPhi;
    TH1F* hdataJetNTracks;
    TH2F* h2dataJetCentralityjetPt;
    TH2F* h2dataJetCentralityjetEta;
    TH2F* h2dataJetCentralityjetPhi;
    TH2F* h2dataJetCentralityjetNTracks;
    TH3F* h3dataJetRjetPtjetCentrality;
    TH3F* h3dataJetRjetPtjetEta;
    TH3F* h3dataJetRjetPtjetPhi;
    TH3F* h3dataJetRjetEtajetPhi;
    TH3F* h3dataJetRjetPtjetNTracks;
    TH3F* h3dataJetRjetPtjetArea;
    TH3F* h3dataJetRjetPtTrackPt;
    TH3F* h3dataJetRjetPtTrackEta;
    TH3F* h3dataJetRjetPtTrackPhi;
    TH3F* h3dataJetRjetPtLeadingTrackPt;
    TH1F* hdataJetPhat;
    TH1F* hdataJetPtCut;

//    //// Data: EvtWiseConstSubJets
//    TH1F* hdataJetPtEvtWiseConstSubJets;
//    TH1F* hdataJetEtaEvtWiseConstSubJets;
//    TH1F* hdataJetPhiEvtWiseConstSubJets;
//    TH1F* hdataJetNTracksEvtWiseConstSubJets;
//    TH2F* h2dataJetCentralityjetPtEvtWiseConstSubJets;
//    TH2F* h2dataJetCentralityjetEtaEvtWiseConstSubJets;
//    TH2F* h2dataJetCentralityjetPhiEvtWiseConstSubJets;
//    TH2F* h2dataJetCentralityjetNTracksEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtjetCentralityEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtjetEtaEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtjetPhiEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetEtajetPhiEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtjetNTracksEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtjetAreaEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtTrackPtEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtTrackEtaEvtWiseConstSubJets;
//    TH3F* h3dataJetRjetPtTrackPhiEvtWiseConstSubJets;

    /// MC
    //// MC: MCD
    TH1F* hsimJetPt;
    TH1F* hsimJetEta;
    TH1F* hsimJetPhi;
    TH1F* hsimJetNTracks;
    TH1F* h2simJetCentralityjetPt;
    TH1F* h2simJetCentralityjetEta;
    TH1F* h2simJetCentralityjetPhi;
    TH1F* h2simJetCentralityjetNTracks;
    TH3F* h3simJetRjetPtjetCentrality;
    TH3F* h3simJetRjetPtjetEta;
    TH3F* h3simJetRjetPtjetPhi;
    TH3F* h3simJetRjetEtajetPhi;
    TH3F* h3simJetRjetPtjetNTracks;
    TH3F* h3simJetRjetPtjetArea;
    TH3F* h3simJetRjetPtTrackPt;
    TH3F* h3simJetRjetPtTrackEta;
    TH3F* h3simJetRjetPtTrackPhi;
    TH3F* h3simJetRjetPtLeadingTrackPt;
    TH1F* hsimJetPhat;
    TH1F* hsimJetPtCut;

    //// MC: MCP
    TH1F* hsimPartJetPt;
    TH1F* hsimPartJetEta;
    TH1F* hsimPartJetPhi;
    TH1F* hsimPartJetNTracks;
    TH3F* h3simPartJetRjetPtjetEta;
    TH3F* h3simPartJetRjetPtjetPhi;
    TH3F* h3simPartJetRjetEtajetPhi;
    TH3F* h3simPartJetRjetPtjetNTracks;
    TH3F* h3simPartJetRjetPtjetArea;
    TH3F* h3simPartJetRjetPtTrackPt;
    TH3F* h3simPartJetRjetPtTrackEta;
    TH3F* h3simPartJetRjetPtTrackPhi;
    TH3F* h3simPartJetRjetPtLeadingTrackPt;
    TH1F* hsimPartJetPhat;
    TH1F* hsimPartJetPtCut;

    // Normalized histogram
    /// data, mcd
    TH1F* hdataNormalizedJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataNormalizedJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    TH1F* hsimNormalizedJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    /// mcp
    TH1F* hsimNormalizedPartJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimNormalizedPartJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;

};

JetAnalysis::~JetAnalysis() {
  // Delete data histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hdataJetPt[binJetR]) delete hdataJetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hdataJetEta[binJetPt][binJetR]) delete hdataJetEta[binJetPt][binJetR];
      if (hdataJetPhi[binJetPt][binJetR]) delete hdataJetPhi[binJetPt][binJetR];
      if (hdataJetNTracks[binJetPt][binJetR]) delete hdataJetNTracks[binJetPt][binJetR];
      if (hdataJetArea[binJetPt][binJetR]) delete hdataJetArea[binJetPt][binJetR];
      if (hdataJetTrackPt[binJetPt][binJetR]) delete hdataJetTrackPt[binJetPt][binJetR];
      if (hdataJetTrackEta[binJetPt][binJetR]) delete hdataJetTrackEta[binJetPt][binJetR];
      if (hdataJetTrackPhi[binJetPt][binJetR]) delete hdataJetTrackPhi[binJetPt][binJetR];
      if (hdataJetLeadingTrackPt[binJetPt][binJetR]) delete hdataJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hsimJetPt[binJetR]) delete hsimJetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimJetEta[binJetPt][binJetR]) delete hsimJetEta[binJetPt][binJetR];
      if (hsimJetPhi[binJetPt][binJetR]) delete hsimJetPhi[binJetPt][binJetR];
      if (hsimJetNTracks[binJetPt][binJetR]) delete hsimJetNTracks[binJetPt][binJetR];
      if (hsimJetArea[binJetPt][binJetR]) delete hsimJetArea[binJetPt][binJetR];
      if (hsimJetTrackPt[binJetPt][binJetR]) delete hsimJetTrackPt[binJetPt][binJetR];
      if (hsimJetTrackEta[binJetPt][binJetR]) delete hsimJetTrackEta[binJetPt][binJetR];
      if (hsimJetTrackPhi[binJetPt][binJetR]) delete hsimJetTrackPhi[binJetPt][binJetR];
      if (hsimJetLeadingTrackPt[binJetPt][binJetR]) delete hsimJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete particle level histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hsimPartJetPt[binJetR]) delete hsimPartJetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimPartJetEta[binJetPt][binJetR]) delete hsimPartJetEta[binJetPt][binJetR];
      if (hsimPartJetPhi[binJetPt][binJetR]) delete hsimPartJetPhi[binJetPt][binJetR];
      if (hsimPartJetNTracks[binJetPt][binJetR]) delete hsimPartJetNTracks[binJetPt][binJetR];
      //if (hsimPartJetArea[binJetPt][binJetR]) delete hsimPartJetArea[binJetPt][binJetR];
      if (hsimPartJetTrackPt[binJetPt][binJetR]) delete hsimPartJetTrackPt[binJetPt][binJetR];
      if (hsimPartJetTrackEta[binJetPt][binJetR]) delete hsimPartJetTrackEta[binJetPt][binJetR];
      if (hsimPartJetTrackPhi[binJetPt][binJetR]) delete hsimPartJetTrackPhi[binJetPt][binJetR];
      if (hsimPartJetLeadingTrackPt[binJetPt][binJetR]) delete hsimPartJetLeadingTrackPt[binJetPt][binJetR];
    }
  }
  // Delete cloned data histograms
  if (h3dataJetRjetPtjetEta) delete h3dataJetRjetPtjetEta;
  if (h3dataJetRjetPtjetPhi) delete h3dataJetRjetPtjetPhi;
  if (h3dataJetRjetEtajetPhi) delete h3dataJetRjetEtajetPhi;
  if (h3dataJetRjetPtjetNTracks) delete h3dataJetRjetPtjetNTracks;
  if (h3dataJetRjetPtjetArea) delete h3dataJetRjetPtjetArea;
  if (h3dataJetRjetPtTrackPt) delete h3dataJetRjetPtTrackPt;
  if (h3dataJetRjetPtTrackEta) delete h3dataJetRjetPtTrackEta;
  if (h3dataJetRjetPtTrackPhi) delete h3dataJetRjetPtTrackPhi;
  if (h3dataJetRjetPtLeadingTrackPt) delete h3dataJetRjetPtLeadingTrackPt;

  // Delete cloned MC histograms
  if (h3simJetRjetPtjetEta) delete h3simJetRjetPtjetEta;
  if (h3simJetRjetPtjetPhi) delete h3simJetRjetPtjetPhi;
  if (h3simJetRjetEtajetPhi) delete h3simJetRjetEtajetPhi;
  if (h3simJetRjetPtjetNTracks) delete h3simJetRjetPtjetNTracks;
  if (h3simJetRjetPtjetArea) delete h3simJetRjetPtjetArea;
  if (h3simJetRjetPtTrackPt) delete h3simJetRjetPtTrackPt;
  if (h3simJetRjetPtTrackEta) delete h3simJetRjetPtTrackEta;
  if (h3simJetRjetPtTrackPhi) delete h3simJetRjetPtTrackPhi;
  if (h3simJetRjetPtLeadingTrackPt) delete h3simJetRjetPtLeadingTrackPt;

  // Delete cloned particle level histograms
  if (h3simPartJetRjetPtjetEta) delete h3simPartJetRjetPtjetEta;
  if (h3simPartJetRjetPtjetPhi) delete h3simPartJetRjetPtjetPhi;
  if (h3simPartJetRjetEtajetPhi) delete h3simPartJetRjetEtajetPhi;
  if (h3simPartJetRjetPtjetNTracks) delete h3simPartJetRjetPtjetNTracks;
  if (h3simPartJetRjetPtTrackPt) delete h3simPartJetRjetPtTrackPt;
  if (h3simPartJetRjetPtTrackEta) delete h3simPartJetRjetPtTrackEta;
  if (h3simPartJetRjetPtTrackPhi) delete h3simPartJetRjetPtTrackPhi;
  
  // Delete Normalized data histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hdataNormalizedJetEta[binJetPt][binJetR]) delete hdataNormalizedJetEta[binJetPt][binJetR];
      if (hdataNormalizedJetPhi[binJetPt][binJetR]) delete hdataNormalizedJetPhi[binJetPt][binJetR];
      if (hdataNormalizedJetNTracks[binJetPt][binJetR]) delete hdataNormalizedJetNTracks[binJetPt][binJetR];
      if (hdataNormalizedJetArea[binJetPt][binJetR]) delete hdataNormalizedJetArea[binJetPt][binJetR];
      if (hdataNormalizedJetTrackPt[binJetPt][binJetR]) delete hdataNormalizedJetTrackPt[binJetPt][binJetR];
      if (hdataNormalizedJetTrackEta[binJetPt][binJetR]) delete hdataNormalizedJetTrackEta[binJetPt][binJetR];
      if (hdataNormalizedJetTrackPhi[binJetPt][binJetR]) delete hdataNormalizedJetTrackPhi[binJetPt][binJetR];
      if (hdataNormalizedJetLeadingTrackPt[binJetPt][binJetR]) delete hdataNormalizedJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete Normalized MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimNormalizedJetEta[binJetPt][binJetR]) delete hsimNormalizedJetEta[binJetPt][binJetR];
      if (hsimNormalizedJetPhi[binJetPt][binJetR]) delete hsimNormalizedJetPhi[binJetPt][binJetR];
      if (hsimNormalizedJetNTracks[binJetPt][binJetR]) delete hsimNormalizedJetNTracks[binJetPt][binJetR];
      if (hsimNormalizedJetArea[binJetPt][binJetR]) delete hsimNormalizedJetArea[binJetPt][binJetR];
      if (hsimNormalizedJetTrackPt[binJetPt][binJetR]) delete hsimNormalizedJetTrackPt[binJetPt][binJetR];
      if (hsimNormalizedJetTrackEta[binJetPt][binJetR]) delete hsimNormalizedJetTrackEta[binJetPt][binJetR];
      if (hsimNormalizedJetTrackPhi[binJetPt][binJetR]) delete hsimNormalizedJetTrackPhi[binJetPt][binJetR];
      if (hsimNormalizedJetLeadingTrackPt[binJetPt][binJetR]) delete hsimNormalizedJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete Normalized MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimNormalizedPartJetEta[binJetPt][binJetR]) delete hsimNormalizedPartJetEta[binJetPt][binJetR];
      if (hsimNormalizedPartJetPhi[binJetPt][binJetR]) delete hsimNormalizedPartJetPhi[binJetPt][binJetR];
      if (hsimNormalizedPartJetNTracks[binJetPt][binJetR]) delete hsimNormalizedPartJetNTracks[binJetPt][binJetR];
      if (hsimNormalizedPartJetArea[binJetPt][binJetR]) delete hsimNormalizedPartJetArea[binJetPt][binJetR];
      if (hsimNormalizedPartJetTrackPt[binJetPt][binJetR]) delete hsimNormalizedPartJetTrackPt[binJetPt][binJetR];
      if (hsimNormalizedPartJetTrackEta[binJetPt][binJetR]) delete hsimNormalizedPartJetTrackEta[binJetPt][binJetR];
      if (hsimNormalizedPartJetTrackPhi[binJetPt][binJetR]) delete hsimNormalizedPartJetTrackPhi[binJetPt][binJetR];
      if (hsimNormalizedPartJetLeadingTrackPt[binJetPt][binJetR]) delete hsimNormalizedPartJetLeadingTrackPt[binJetPt][binJetR];
    }
  }
}

void JetAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  TString dirData = Form("%s/%s/data/%s/general", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  TString dirSim = Form("%s/%s/sim/%s/general", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  TString dirDataVsSim Form("%s/%s/dataVssim/%s_%s/general", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int JetAnalysis::loadDataGeneralQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";
  if (doChJetQA) {
    h3dataJetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta", taskJetQA.Data())));
    h3dataJetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
    h3dataJetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi", taskJetQA.Data())));
    h3dataJetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks", taskJetQA.Data())));
    h3dataJetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area", taskJetQA.Data())));
    h3dataJetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt", taskJetQA.Data())));
    h3dataJetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta", taskJetQA.Data())));
    h3dataJetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi", taskJetQA.Data())));
    h3dataJetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_leadingtrack_pt", taskJetQA.Data())));
  }

  std::cout << "Load completed General Jet QA Data" << std::endl;
  return 1;
}

int JetAnalysis::loadSimGeneralQA(TString rootSim, bool doMCP = false) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";

    h3simJetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta", taskJetQA.Data())));
    h3simJetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
    h3simJetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi", taskJetQA.Data())));
    h3simJetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks", taskJetQA.Data())));
    h3simJetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area", taskJetQA.Data())));
    h3simJetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt", taskJetQA.Data())));
    h3simJetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta", taskJetQA.Data())));
    h3simJetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi", taskJetQA.Data())));
    h3simJetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_leadingtrack_pt", taskJetQA.Data())));

  if (doMCP) {
    h3simPartJetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_eta_part", taskJetQA.Data())));
    h3simPartJetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
    h3simPartJetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_eta_part_jet_phi_part", taskJetQA.Data())));
    h3simPartJetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_ntracks_part", taskJetQA.Data())));
    h3simPartJetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_area_part", taskJetQA.Data())));
    h3simPartJetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_pt_part", taskJetQA.Data())));
    h3simPartJetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_eta_part", taskJetQA.Data())));
    h3simPartJetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_phi_part", taskJetQA.Data())));
    h3simPartJetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_leadingtrack_pt_part", taskJetQA.Data())));
  }

  std::cout << "Load completed General Jet QA MC" << std::endl;
  return 1;
}

void JetAnalysis::initHistogramForNormalizationGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataJetPt[binJetR] = new TH1F(Form("hdataJetPt_%d", binJetR), "", h3dataJetRjetPtjetEta->GetNbinsY(), h3dataJetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3dataJetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3dataJetRjetPtjetEta->GetNbinsY()));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataJetEta[binJetPt][binJetR] = new TH1F(Form("hdataJetEta_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtjetEta->GetNbinsZ(), h3dataJetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtjetEta->GetNbinsZ()));
      hdataJetPhi[binJetPt][binJetR] = new TH1F(Form("hdataJetPhi_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtjetPhi->GetNbinsZ(), h3dataJetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtjetPhi->GetNbinsZ()));
      hdataJetNTracks[binJetPt][binJetR] = new TH1F(Form("hdataJetNTracks_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtjetNTracks->GetNbinsZ(), h3dataJetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtjetNTracks->GetNbinsZ()));
      hdataJetArea[binJetPt][binJetR] = new TH1F(Form("hdataJetArea_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtjetArea->GetNbinsZ(), h3dataJetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtjetArea->GetNbinsZ()));
      hdataJetTrackPt[binJetPt][binJetR] = new TH1F(Form("hdataJetTrackPt_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtTrackPt->GetNbinsZ(), h3dataJetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtTrackPt->GetNbinsZ()));
      hdataJetTrackEta[binJetPt][binJetR] = new TH1F(Form("hdataJetTrackEta_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtTrackEta->GetNbinsZ(), h3dataJetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtTrackEta->GetNbinsZ()));
      hdataJetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hdataJetTrackPhi_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtTrackPhi->GetNbinsZ(), h3dataJetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtTrackPhi->GetNbinsZ()));
      hdataJetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hdataJetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3dataJetRjetPtLeadingTrackPt->GetNbinsZ(), h3dataJetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3dataJetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3dataJetRjetPtLeadingTrackPt->GetNbinsZ()));
    }
  }
}

void JetAnalysis::initHistogramForNormalizationGeneralQAMC(bool doMCP = false) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimJetPt[binJetR] = new TH1F(Form("hsimJetPt_%d", binJetR), "", h3simJetRjetPtjetEta->GetNbinsY(), h3simJetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3simJetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3simJetRjetPtjetEta->GetNbinsY()));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimJetEta[binJetPt][binJetR] = new TH1F(Form("hsimJetEta_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtjetEta->GetNbinsZ(), h3simJetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3simJetRjetPtjetEta->GetNbinsZ()));

      hsimJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimJetPhi_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtjetPhi->GetNbinsZ(), h3simJetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3simJetRjetPtjetPhi->GetNbinsZ()));
      hsimJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimJetNTracks_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtjetNTracks->GetNbinsZ(), h3simJetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3simJetRjetPtjetNTracks->GetNbinsZ()));
      hsimJetArea[binJetPt][binJetR] = new TH1F(Form("hsimJetArea_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtjetArea->GetNbinsZ(), h3simJetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3simJetRjetPtjetArea->GetNbinsZ()));
      hsimJetTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimJetTrackPt_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtTrackPt->GetNbinsZ(), h3simJetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3simJetRjetPtTrackPt->GetNbinsZ()));
      hsimJetTrackEta[binJetPt][binJetR] = new TH1F(Form("hsimJetTrackEta_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtTrackEta->GetNbinsZ(), h3simJetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3simJetRjetPtTrackEta->GetNbinsZ()));
      hsimJetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hsimJetTrackPhi_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtTrackPhi->GetNbinsZ(), h3simJetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3simJetRjetPtTrackPhi->GetNbinsZ()));
      hsimJetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimJetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3simJetRjetPtLeadingTrackPt->GetNbinsZ(), h3simJetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3simJetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3simJetRjetPtLeadingTrackPt->GetNbinsZ()));
    }
  }
  if (doMCP) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimPartJetPt[binJetR] = new TH1F(Form("hsimPartJetPt_%d", binJetR), "", h3simPartJetRjetPtjetEta->GetNbinsY(), h3simPartJetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3simPartJetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3simPartJetRjetPtjetEta->GetNbinsY()));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimPartJetEta[binJetPt][binJetR] = new TH1F(Form("hsimPartJetEta_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtjetEta->GetNbinsZ(), h3simPartJetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtjetEta->GetNbinsZ()));
        hsimPartJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimPartJetPhi_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtjetPhi->GetNbinsZ(), h3simPartJetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtjetPhi->GetNbinsZ()));
        hsimPartJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimPartJetNTracks_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtjetNTracks->GetNbinsZ(), h3simPartJetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtjetNTracks->GetNbinsZ()));
        //hsimPartJetArea[binJetPt][binJetR] = new TH1F(Form("hsimPartJetArea_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtjetArea->GetNbinsZ(), h3simPartJetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtjetArea->GetNbinsZ()));
        hsimPartJetTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimPartJetTrackPt_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtTrackPt->GetNbinsZ(), h3simPartJetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtTrackPt->GetNbinsZ()));
        hsimPartJetTrackEta[binJetPt][binJetR] = new TH1F(Form("hsimPartJetTrackEta_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtTrackEta->GetNbinsZ(), h3simPartJetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtTrackEta->GetNbinsZ()));
        hsimPartJetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hsimPartJetTrackPhi_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtTrackPhi->GetNbinsZ(), h3simPartJetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtTrackPhi->GetNbinsZ()));
        //hsimPartJetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimPartJetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3simPartJetRjetPtLeadingTrackPt->GetNbinsZ(), h3simPartJetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3simPartJetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3simPartJetRjetPtLeadingTrackPt->GetNbinsZ()));
      }
    }
  }
}

void JetAnalysis::projectionHistGeneralQAData() {
  TH1F *projJetPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetEta->ProjectionY("projJetPt", 1, h3dataJetRjetPtjetEta->GetNbinsX(), 1, h3dataJetRjetPtjetEta->GetNbinsZ()));
  TH1F *projJetEta = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3dataJetRjetPtjetEta->GetNbinsX(), 1, h3dataJetRjetPtjetEta->GetNbinsY()));
  TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3dataJetRjetPtjetPhi->GetNbinsX(), 1, h3dataJetRjetPtjetPhi->GetNbinsY()));
  TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3dataJetRjetPtjetNTracks->GetNbinsX(), 1, h3dataJetRjetPtjetNTracks->GetNbinsY()));
  TH1F *projJetArea = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3dataJetRjetPtjetArea->GetNbinsX(), 1, h3dataJetRjetPtjetArea->GetNbinsY()));
  TH1F *projJetTrackPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtTrackPt->ProjectionZ("projJetTrackPt", 1, h3dataJetRjetPtTrackPt->GetNbinsX(), 1, h3dataJetRjetPtTrackPt->GetNbinsY()));
  TH1F *projJetTrackEta = reinterpret_cast<TH1F*> (h3dataJetRjetPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataJetRjetPtTrackEta->GetNbinsX(), 1, h3dataJetRjetPtTrackEta->GetNbinsY()));
  TH1F *projJetTrackPhi = reinterpret_cast<TH1F*> (h3dataJetRjetPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataJetRjetPtTrackPhi->GetNbinsX(), 1, h3dataJetRjetPtTrackPhi->GetNbinsY()));
  TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3dataJetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3dataJetRjetPtLeadingTrackPt->GetNbinsY()));

  hdataJetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
  hdataJetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
  hdataJetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
  hdataJetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
  hdataJetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
  hdataJetTrackPt[0][0] = reinterpret_cast<TH1F*>(projJetTrackPt->Clone());
  hdataJetTrackEta[0][0] = reinterpret_cast<TH1F*>(projJetTrackEta->Clone());
  hdataJetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projJetTrackPhi->Clone());
  hdataJetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());

  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // jet pt
    int leftbinJetRForJetPt = h3dataJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPt = h3dataJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3dataJetRjetPtjetEta->GetNbinsZ()));
    hdataJetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());
  
    // jet eta
    int leftbinJetRForJetEta = h3dataJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetEta = h3dataJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3dataJetRjetPtjetEta->GetNbinsZ()));
    hdataJetEta[0][binJetR]->Add(projJetRRangeJetEta);

    // jet phi
    int leftbinJetRForJetPhi = h3dataJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPhi = h3dataJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3dataJetRjetPtjetPhi->GetNbinsZ()));
    hdataJetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

    // number of tracks
    int leftbinJetRForJetNTracks = h3dataJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetNTracks = h3dataJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3dataJetRjetPtjetNTracks->GetNbinsZ()));
    hdataJetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

    // jet area
    int leftbinJetRForJetArea = h3dataJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetArea = h3dataJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3dataJetRjetPtjetArea->GetNbinsZ()));
    hdataJetArea[0][binJetR]->Add(projJetRRangeJetArea);

    // track pt
    int leftbinJetRForTrackPt = h3dataJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPt = h3dataJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3dataJetRjetPtjetArea->GetNbinsZ()));
    hdataJetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

    // track eta
    int leftbinJetRForTrackEta = h3dataJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackEta = h3dataJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3dataJetRjetPtjetArea->GetNbinsZ()));
    hdataJetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

    // track phi
    int leftbinJetRForTrackPhi = h3dataJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPhi = h3dataJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3dataJetRjetPtjetArea->GetNbinsZ()));
    hdataJetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

    // leading track pt
    int leftbinJetRForLeadingTrackPt = h3dataJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForLeadingTrackPt = h3dataJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3dataJetRjetPtjetArea->GetNbinsZ()));
    hdataJetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
      // jet eta
      int leftbinJetPtForJetEta = h3dataJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetEta = h3dataJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJetEta_%d_%d", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
      hdataJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
      hdataJetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

      // jet phi
      int leftbinJetPtForJetPhi = h3dataJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetPhi = h3dataJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetPhi->ProjectionZ(Form("projJetPtRangeJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
      hdataJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
      hdataJetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

      // number of tracks
      int leftbinJetPtForJetNTracks = h3dataJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetNTracks = h3dataJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
      hdataJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
      hdataJetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

      // jet area
      int leftbinJetPtForJetArea = h3dataJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetArea = h3dataJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3dataJetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetR, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
      hdataJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
      hdataJetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

      // track pt
      int leftbinJetPtForTrackPt = h3dataJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPt = h3dataJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
      hdataJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
      hdataJetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

      // track eta
      int leftbinJetPtForTrackEta = h3dataJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackEta = h3dataJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataJetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
      hdataJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
      hdataJetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

      // track phi
      int leftbinJetPtForTrackPhi = h3dataJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPhi = h3dataJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataJetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
      hdataJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
      hdataJetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      // leading track pt
      int leftbinJetPtForLeadingTrackPt = h3dataJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForLeadingTrackPt = h3dataJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
      hdataJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
      hdataJetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
    }
  }
}

void JetAnalysis::projectionHistGeneralQAMC(bool doMCP= false) {

  TH1F *projJetPt = reinterpret_cast<TH1F*> (h3simJetRjetPtjetEta->ProjectionY("projJetPt", 1, h3simJetRjetPtjetEta->GetNbinsX(), 1, h3simJetRjetPtjetEta->GetNbinsZ()));
  TH1F *projJetEta = reinterpret_cast<TH1F*> (h3simJetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3simJetRjetPtjetEta->GetNbinsX(), 1, h3simJetRjetPtjetEta->GetNbinsY()));
  TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3simJetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3simJetRjetPtjetPhi->GetNbinsX(), 1, h3simJetRjetPtjetPhi->GetNbinsY()));
  TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3simJetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3simJetRjetPtjetNTracks->GetNbinsX(), 1, h3simJetRjetPtjetNTracks->GetNbinsY()));
  TH1F *projJetArea = reinterpret_cast<TH1F*> (h3simJetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3simJetRjetPtjetArea->GetNbinsX(), 1, h3simJetRjetPtjetArea->GetNbinsY()));
  TH1F *projTrackPt = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackPt->ProjectionZ("projTrackPt", 1, h3simJetRjetPtTrackPt->GetNbinsX(), 1, h3simJetRjetPtTrackPt->GetNbinsY()));
  TH1F *projTrackEta = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackEta->ProjectionZ("projTrackEta", 1, h3simJetRjetPtTrackEta->GetNbinsX(), 1, h3simJetRjetPtTrackEta->GetNbinsY()));
  TH1F *projTrackPhi = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackPhi->ProjectionZ("projTrackPhi", 1, h3simJetRjetPtTrackPhi->GetNbinsX(), 1, h3simJetRjetPtTrackPhi->GetNbinsY()));
  TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3simJetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3simJetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3simJetRjetPtLeadingTrackPt->GetNbinsY()));

  hsimJetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
  hsimJetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
  hsimJetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
  hsimJetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
  hsimJetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
  hsimJetTrackPt[0][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
  hsimJetTrackEta[0][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
  hsimJetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
  hsimJetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());


  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // jet pt
    int leftbinJetRForJetPt = h3simJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPt = h3simJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3simJetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3simJetRjetPtjetEta->GetNbinsZ()));
    hsimJetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

    // jet eta
    int leftbinJetRForJetEta = h3simJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetEta = h3simJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3simJetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3simJetRjetPtjetEta->GetNbinsZ()));
    hsimJetEta[0][binJetR]->Add(projJetRRangeJetEta);

    // jet phi
    int leftbinJetRForJetPhi = h3simJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPhi = h3simJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3simJetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3simJetRjetPtjetPhi->GetNbinsZ()));
    hsimJetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

    // number of tracks
    int leftbinJetRForJetNTracks = h3simJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetNTracks = h3simJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3simJetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3simJetRjetPtjetNTracks->GetNbinsZ()));
    hsimJetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

    // jet area
    int leftbinJetRForJetArea = h3simJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetArea = h3simJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3simJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3simJetRjetPtjetArea->GetNbinsZ()));
    hsimJetArea[0][binJetR]->Add(projJetRRangeJetArea);

    // track pt
    int leftbinJetRForTrackPt = h3simJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPt = h3simJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackPt->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3simJetRjetPtTrackPt->GetNbinsZ()));
    hsimJetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

    // track eta
    int leftbinJetRForTrackEta = h3simJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackEta = h3simJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackEta->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3simJetRjetPtTrackEta->GetNbinsZ()));
    hsimJetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

    // track phi
    int leftbinJetRForTrackPhi = h3simJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPhi = h3simJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackPhi->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3simJetRjetPtTrackPhi->GetNbinsZ()));
    hsimJetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

    // leading track pt
    int leftbinJetRForLeadingTrackPt = h3simJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForLeadingTrackPt = h3simJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3simJetRjetPtLeadingTrackPt->GetNbinsZ()));
    hsimJetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      // jet eta
      int leftbinJetPtForJetEta = h3simJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetEta = h3simJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3simJetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJeEta_%d_%d)", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
      hsimJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
      hsimJetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

      // jet phi
      int leftbinJetPtForJetPhi = h3simJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetPhi = h3simJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3simJetRjetPtjetPhi->ProjectionZ(Form("projJetPtRagneJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
      hsimJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
      hsimJetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

      // number of tracks
      int leftbinJetPtForJetNTracks = h3simJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetNTracks = h3simJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3simJetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
      hsimJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
      hsimJetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

      // jet area
      int leftbinJetPtForJetArea = h3simJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetArea = h3simJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3simJetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetPt, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
      hsimJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
      hsimJetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

      // track pt
      int leftbinJetPtForTrackPt = h3simJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPt = h3simJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
      hsimJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
      hsimJetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

      // track eta
      int leftbinJetPtForTrackEta = h3simJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackEta = h3simJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
      hsimJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
      hsimJetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

      // track phi
      int leftbinJetPtForTrackPhi = h3simJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPhi = h3simJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simJetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
      hsimJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
      hsimJetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      // leading track pt
      int leftbinJetPtForLeadingTrackPt = h3simJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForLeadingTrackPt = h3simJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
      hsimJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
      hsimJetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
    }
  }

  if (doMCP) {
    TH1F *projJetPt = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetEta->ProjectionY("projJetPt", 1, h3simPartJetRjetPtjetEta->GetNbinsX(), 1, h3simPartJetRjetPtjetEta->GetNbinsZ()));
    TH1F *projJetEta = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3simPartJetRjetPtjetEta->GetNbinsX(), 1, h3simPartJetRjetPtjetEta->GetNbinsY()));
    TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3simPartJetRjetPtjetPhi->GetNbinsX(), 1, h3simPartJetRjetPtjetPhi->GetNbinsY()));
    TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3simPartJetRjetPtjetNTracks->GetNbinsX(), 1, h3simPartJetRjetPtjetNTracks->GetNbinsY()));
    //TH1F *projJetArea = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3simPartJetRjetPtjetArea->GetNbinsX(), 1, h3simPartJetRjetPtjetArea->GetNbinsY()));
    TH1F *projTrackPt = reinterpret_cast<TH1F*> (h3simPartJetRjetPtTrackPt->ProjectionZ("projTrackPt", 1, h3simPartJetRjetPtTrackPt->GetNbinsX(), 1, h3simPartJetRjetPtTrackPt->GetNbinsY()));
    TH1F *projTrackEta = reinterpret_cast<TH1F*> (h3simPartJetRjetPtTrackEta->ProjectionZ("projTrackEta", 1, h3simPartJetRjetPtTrackEta->GetNbinsX(), 1, h3simPartJetRjetPtTrackEta->GetNbinsY()));
    TH1F *projTrackPhi = reinterpret_cast<TH1F*> (h3simPartJetRjetPtTrackPhi->ProjectionZ("projTrackPhi", 1, h3simPartJetRjetPtTrackPhi->GetNbinsX(), 1, h3simPartJetRjetPtTrackPhi->GetNbinsY()));
    //TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3simPartJetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3simPartJetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3simPartJetRjetPtLeadingTrackPt->GetNbinsY()));

    hsimPartJetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
    hsimPartJetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
    hsimPartJetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
    hsimPartJetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
    //hsimPartJetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
    hsimPartJetTrackPt[0][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
    hsimPartJetTrackEta[0][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
    hsimPartJetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
    //hsimPartJetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());
    for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      // jet pt
      int leftbinJetRForJetPt = h3simPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPt = h3simPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3simPartJetRjetPtjetEta->GetNbinsZ()));
      hsimPartJetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

      // jet eta
      int leftbinJetRForJetEta = h3simPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetEta = h3simPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3simPartJetRjetPtjetEta->GetNbinsZ()));
      hsimPartJetEta[0][binJetR]->Add(projJetRRangeJetEta);

      // jet phi
      int leftbinJetRForJetPhi = h3simPartJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPhi = h3simPartJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3simPartJetRjetPtjetPhi->GetNbinsZ()));
      hsimPartJetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

      // number of tracks
      int leftbinJetRForJetNTracks = h3simPartJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetNTracks = h3simPartJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3simPartJetRjetPtjetNTracks->GetNbinsZ()));
      hsimPartJetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

//      // jet area
//      int leftbinJetRForJetArea = h3simPartJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
//      int rightbinJetRForJetArea = h3simPartJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
//      TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3simPartJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3simPartJetRjetPtjetArea->GetNbinsZ()));
//      hsimPartJetArea[0][binJetR]->Add(projJetRRangeJetArea);

      // track pt
      int leftbinJetRForTrackPt = h3simPartJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPt = h3simPartJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3simPartJetRjetPtTrackPt->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3simPartJetRjetPtTrackPt->GetNbinsZ()));
      hsimPartJetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

      // track eta
      int leftbinJetRForTrackEta = h3simPartJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackEta = h3simPartJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3simPartJetRjetPtTrackEta->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3simPartJetRjetPtTrackEta->GetNbinsZ()));
      hsimPartJetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

      // track phi
      int leftbinJetRForTrackPhi = h3simPartJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPhi = h3simPartJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3simPartJetRjetPtTrackPhi->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3simPartJetRjetPtTrackPhi->GetNbinsZ()));
      hsimPartJetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

//      // leading track pt
//      int leftbinJetRForLeadingTrackPt = h3simPartJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
//      int rightbinJetRForLeadingTrackPt = h3simPartJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
