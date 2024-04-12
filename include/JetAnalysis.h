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
      InitConfig(trigger.Data());
      if (doData) {
        if (!loadDataGeneralQA(rootData.Data())) {
          return;
        }
        initHistogramForNormalizationGeneralQAData();
      	projectionHistGeneralQAData();
      	clonenormalizedHistogramGeneralQAData();
      	normalizedHistogramGeneralQAData();
      }
      if (doMCD) {
        if (!loadSimGeneralQA(rootSim.Data(), doMCP)) {
          return;
        }
        initHistogramForNormalizationGeneralQAMC(doMCP);
      	projectionHistGeneralQAMC(doMCP);
      	clonenormalizedHistogramGeneralQAMC(doMCP);
      	normalizedHistogramGeneralQAMC(doMCP);
      }
      //SaveHistogramGeneralQA("GeneralJetQA.root", doData, doMCD, doMCP);
    }

    ~JetAnalysis();

    // function
    void InitConfig(TString triggerNAME);
    int loadDataGeneralQA(TString rootData);
    int loadSimGeneralQA(TString rootSim, bool doMCP);
    void initHistogramForNormalizationGeneralQAData();
    void initHistogramForNormalizationGeneralQAMC(bool doMCP);
    void projectionHistGeneralQAData();
    void projectionHistGeneralQAMC(bool doMCP);
    void clonenormalizedHistogramGeneralQAData();
    void clonenormalizedHistogramGeneralQAMC(bool doMCP);
    void normalizedHistogramGeneralQAData();
    void normalizedHistogramGeneralQAMC(bool doMCP);
    void SaveHistogramGeneralQA(TString rootFile, bool doData, bool doMC, bool doMCP);

    // Draw option
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);
    void drawDataGenJetPt(bool doLog, int binJetR);
    void drawDataGenJetEta(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetArea(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void drawDataGenJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);

    void drawSimGenJetPt(bool doLog, int binJetR);
    void drawSimGenJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetNTracks(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetArea(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimGenJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);

    void drawSimGenPartJetPt(bool doLog, int binJetR);
    void drawSimGenPartJetEta(bool doLog, int binJetPt, int binJetR);
    void drawSimGenPartJetPhi(bool doLog, int binJetPt, int binJetR);
    void drawSimGenPartJetNTracks(bool doLog, int binJetPt, int binJetR);
    //void drawSimGenPartJetArea(bool doLog, int binJetPt, int binJetR);
    void drawSimGenPartJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void drawSimGenPartJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void drawSimGenPartJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    //void drawSimGenPartJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);
    void DrawRatioDataMCGenJetPt(bool doLog, int binJetR);

    // histogram from root file
    /// data, mcd
    TH1F* hdataGenJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    TH1F* hsimGenJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    /// mcp
    TH1F* hsimGenPartJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    //TH1F* hsimGenPartJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenPartJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

  protected:
    // draw option
    int canvasNum=0;
    CanvasHandler* canvasHandler;

    // histogram
    /// Data
    TH1F* h1dataGenJetPt;
    TH1F* h1dataGenJetEta;
    TH1F* h1dataGenJetPhi;
    TH1F* h1dataGenJetNTracks;
    TH2F* h2dataGenJetCentralityjetPt;
    TH2F* h2dataGenJetCentralityjetEta;
    TH2F* h2dataGenJetCentralityjetPhi;
    TH2F* h2dataGenJetCentralityjetNTracks;
    TH3F* h3dataGenJetRjetPtjetCentrality;
    TH3F* h3dataGenJetRjetPtjetEta;
    TH3F* h3dataGenJetRjetPtjetPhi;
    TH3F* h3dataGenJetRjetEtajetPhi;
    TH3F* h3dataGenJetRjetPtjetNTracks;
    TH3F* h3dataGenJetRjetPtjetArea;
    TH3F* h3dataGenJetRjetPtTrackPt;
    TH3F* h3dataGenJetRjetPtTrackEta;
    TH3F* h3dataGenJetRjetPtTrackPhi;
    TH3F* h3dataGenJetRjetPtLeadingTrackPt;
    TH1F* h1dataGenJetPhat;
    TH1F* h1dataGenJetPtCut;

//    //// Data: EvtWiseConstSubJets
//    TH1F* h1dataGenJetPtEvtWiseConstSubJets;
//    TH1F* h1dataGenJetEtaEvtWiseConstSubJets;
//    TH1F* h1dataGenJetPhiEvtWiseConstSubJets;
//    TH1F* h1dataGenJetNTracksEvtWiseConstSubJets;
//    TH2F* h2dataGenJetCentralityjetPtEvtWiseConstSubJets;
//    TH2F* h2dataGenJetCentralityjetEtaEvtWiseConstSubJets;
//    TH2F* h2dataGenJetCentralityjetPhiEvtWiseConstSubJets;
//    TH2F* h2dataGenJetCentralityjetNTracksEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtjetCentralityEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtjetEtaEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtjetPhiEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetEtajetPhiEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtjetNTracksEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtjetAreaEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtTrackPtEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtTrackEtaEvtWiseConstSubJets;
//    TH3F* h3dataGenJetRjetPtTrackPhiEvtWiseConstSubJets;

    /// MC
    //// MC: MCD
    TH1F* h1simGenJetPt;
    TH1F* h1simGenJetEta;
    TH1F* h1simGenJetPhi;
    TH1F* h1simGenJetNTracks;
    TH1F* h2simGenJetCentralityjetPt;
    TH1F* h2simGenJetCentralityjetEta;
    TH1F* h2simGenJetCentralityjetPhi;
    TH1F* h2simGenJetCentralityjetNTracks;
    TH3F* h3simGenJetRjetPtjetCentrality;
    TH3F* h3simGenJetRjetPtjetEta;
    TH3F* h3simGenJetRjetPtjetPhi;
    TH3F* h3simGenJetRjetEtajetPhi;
    TH3F* h3simGenJetRjetPtjetNTracks;
    TH3F* h3simGenJetRjetPtjetArea;
    TH3F* h3simGenJetRjetPtTrackPt;
    TH3F* h3simGenJetRjetPtTrackEta;
    TH3F* h3simGenJetRjetPtTrackPhi;
    TH3F* h3simGenJetRjetPtLeadingTrackPt;
    TH1F* h1simGenJetPhat;
    TH1F* h1simGenJetPtCut;

    //// MC: MCP
    TH1F* h1simGenPartJetPt;
    TH1F* h1simGenPartJetEta;
    TH1F* h1simGenPartJetPhi;
    TH1F* h1simGenPartJetNTracks;
    TH3F* h3simGenPartJetRjetPtjetEta;
    TH3F* h3simGenPartJetRjetPtjetPhi;
    TH3F* h3simGenPartJetRjetEtajetPhi;
    TH3F* h3simGenPartJetRjetPtjetNTracks;
    TH3F* h3simGenPartJetRjetPtjetArea;
    TH3F* h3simGenPartJetRjetPtTrackPt;
    TH3F* h3simGenPartJetRjetPtTrackEta;
    TH3F* h3simGenPartJetRjetPtTrackPhi;
    TH3F* h3simGenPartJetRjetPtLeadingTrackPt;
    TH1F* h1simGenPartJetPhat;
    TH1F* h1simGenPartJetPtCut;

    // Normalized histogram
    /// data, mcd
    TH1F* hdataGenNormalizedJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenNormalizedJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    TH1F* hsimGenNormalizedJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    /// mcp
    TH1F* hsimGenNormalizedPartJetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenNormalizedPartJetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

  private:
    std::vector<HistogramData> histList;
    TLatex latex;
    TString triggerName;

};

JetAnalysis::~JetAnalysis() {
  // Delete data histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hdataGenJetPt[binJetR]) delete hdataGenJetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hdataGenJetEta[binJetPt][binJetR]) delete hdataGenJetEta[binJetPt][binJetR];
      if (hdataGenJetPhi[binJetPt][binJetR]) delete hdataGenJetPhi[binJetPt][binJetR];
      if (hdataGenJetNTracks[binJetPt][binJetR]) delete hdataGenJetNTracks[binJetPt][binJetR];
      if (hdataGenJetArea[binJetPt][binJetR]) delete hdataGenJetArea[binJetPt][binJetR];
      if (hdataGenJetTrackPt[binJetPt][binJetR]) delete hdataGenJetTrackPt[binJetPt][binJetR];
      if (hdataGenJetTrackEta[binJetPt][binJetR]) delete hdataGenJetTrackEta[binJetPt][binJetR];
      if (hdataGenJetTrackPhi[binJetPt][binJetR]) delete hdataGenJetTrackPhi[binJetPt][binJetR];
      if (hdataGenJetLeadingTrackPt[binJetPt][binJetR]) delete hdataGenJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hsimGenJetPt[binJetR]) delete hsimGenJetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenJetEta[binJetPt][binJetR]) delete hsimGenJetEta[binJetPt][binJetR];
      if (hsimGenJetPhi[binJetPt][binJetR]) delete hsimGenJetPhi[binJetPt][binJetR];
      if (hsimGenJetNTracks[binJetPt][binJetR]) delete hsimGenJetNTracks[binJetPt][binJetR];
      if (hsimGenJetArea[binJetPt][binJetR]) delete hsimGenJetArea[binJetPt][binJetR];
      if (hsimGenJetTrackPt[binJetPt][binJetR]) delete hsimGenJetTrackPt[binJetPt][binJetR];
      if (hsimGenJetTrackEta[binJetPt][binJetR]) delete hsimGenJetTrackEta[binJetPt][binJetR];
      if (hsimGenJetTrackPhi[binJetPt][binJetR]) delete hsimGenJetTrackPhi[binJetPt][binJetR];
      if (hsimGenJetLeadingTrackPt[binJetPt][binJetR]) delete hsimGenJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete particle level histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hsimGenPartJetPt[binJetR]) delete hsimGenPartJetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenPartJetEta[binJetPt][binJetR]) delete hsimGenPartJetEta[binJetPt][binJetR];
      if (hsimGenPartJetPhi[binJetPt][binJetR]) delete hsimGenPartJetPhi[binJetPt][binJetR];
      if (hsimGenPartJetNTracks[binJetPt][binJetR]) delete hsimGenPartJetNTracks[binJetPt][binJetR];
      //if (hsimGenPartJetArea[binJetPt][binJetR]) delete hsimGenPartJetArea[binJetPt][binJetR];
      if (hsimGenPartJetTrackPt[binJetPt][binJetR]) delete hsimGenPartJetTrackPt[binJetPt][binJetR];
      if (hsimGenPartJetTrackEta[binJetPt][binJetR]) delete hsimGenPartJetTrackEta[binJetPt][binJetR];
      if (hsimGenPartJetTrackPhi[binJetPt][binJetR]) delete hsimGenPartJetTrackPhi[binJetPt][binJetR];
      if (hsimGenPartJetLeadingTrackPt[binJetPt][binJetR]) delete hsimGenPartJetLeadingTrackPt[binJetPt][binJetR];
    }
  }
  // Delete cloned data histograms
  if (h3dataGenJetRjetPtjetEta) delete h3dataGenJetRjetPtjetEta;
  if (h3dataGenJetRjetPtjetPhi) delete h3dataGenJetRjetPtjetPhi;
  if (h3dataGenJetRjetEtajetPhi) delete h3dataGenJetRjetEtajetPhi;
  if (h3dataGenJetRjetPtjetNTracks) delete h3dataGenJetRjetPtjetNTracks;
  if (h3dataGenJetRjetPtjetArea) delete h3dataGenJetRjetPtjetArea;
  if (h3dataGenJetRjetPtTrackPt) delete h3dataGenJetRjetPtTrackPt;
  if (h3dataGenJetRjetPtTrackEta) delete h3dataGenJetRjetPtTrackEta;
  if (h3dataGenJetRjetPtTrackPhi) delete h3dataGenJetRjetPtTrackPhi;
  if (h3dataGenJetRjetPtLeadingTrackPt) delete h3dataGenJetRjetPtLeadingTrackPt;

  // Delete cloned MC histograms
  if (h3simGenJetRjetPtjetEta) delete h3simGenJetRjetPtjetEta;
  if (h3simGenJetRjetPtjetPhi) delete h3simGenJetRjetPtjetPhi;
  if (h3simGenJetRjetEtajetPhi) delete h3simGenJetRjetEtajetPhi;
  if (h3simGenJetRjetPtjetNTracks) delete h3simGenJetRjetPtjetNTracks;
  if (h3simGenJetRjetPtjetArea) delete h3simGenJetRjetPtjetArea;
  if (h3simGenJetRjetPtTrackPt) delete h3simGenJetRjetPtTrackPt;
  if (h3simGenJetRjetPtTrackEta) delete h3simGenJetRjetPtTrackEta;
  if (h3simGenJetRjetPtTrackPhi) delete h3simGenJetRjetPtTrackPhi;
  if (h3simGenJetRjetPtLeadingTrackPt) delete h3simGenJetRjetPtLeadingTrackPt;

  // Delete cloned particle level histograms
  if (h3simGenPartJetRjetPtjetEta) delete h3simGenPartJetRjetPtjetEta;
  if (h3simGenPartJetRjetPtjetPhi) delete h3simGenPartJetRjetPtjetPhi;
  if (h3simGenPartJetRjetEtajetPhi) delete h3simGenPartJetRjetEtajetPhi;
  if (h3simGenPartJetRjetPtjetNTracks) delete h3simGenPartJetRjetPtjetNTracks;
  if (h3simGenPartJetRjetPtTrackPt) delete h3simGenPartJetRjetPtTrackPt;
  if (h3simGenPartJetRjetPtTrackEta) delete h3simGenPartJetRjetPtTrackEta;
  if (h3simGenPartJetRjetPtTrackPhi) delete h3simGenPartJetRjetPtTrackPhi;
  
  // Delete Normalized data histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hdataGenNormalizedJetEta[binJetPt][binJetR]) delete hdataGenNormalizedJetEta[binJetPt][binJetR];
      if (hdataGenNormalizedJetPhi[binJetPt][binJetR]) delete hdataGenNormalizedJetPhi[binJetPt][binJetR];
      if (hdataGenNormalizedJetNTracks[binJetPt][binJetR]) delete hdataGenNormalizedJetNTracks[binJetPt][binJetR];
      if (hdataGenNormalizedJetArea[binJetPt][binJetR]) delete hdataGenNormalizedJetArea[binJetPt][binJetR];
      if (hdataGenNormalizedJetTrackPt[binJetPt][binJetR]) delete hdataGenNormalizedJetTrackPt[binJetPt][binJetR];
      if (hdataGenNormalizedJetTrackEta[binJetPt][binJetR]) delete hdataGenNormalizedJetTrackEta[binJetPt][binJetR];
      if (hdataGenNormalizedJetTrackPhi[binJetPt][binJetR]) delete hdataGenNormalizedJetTrackPhi[binJetPt][binJetR];
      if (hdataGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]) delete hdataGenNormalizedJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete Normalized MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenNormalizedJetEta[binJetPt][binJetR]) delete hsimGenNormalizedJetEta[binJetPt][binJetR];
      if (hsimGenNormalizedJetPhi[binJetPt][binJetR]) delete hsimGenNormalizedJetPhi[binJetPt][binJetR];
      if (hsimGenNormalizedJetNTracks[binJetPt][binJetR]) delete hsimGenNormalizedJetNTracks[binJetPt][binJetR];
      if (hsimGenNormalizedJetArea[binJetPt][binJetR]) delete hsimGenNormalizedJetArea[binJetPt][binJetR];
      if (hsimGenNormalizedJetTrackPt[binJetPt][binJetR]) delete hsimGenNormalizedJetTrackPt[binJetPt][binJetR];
      if (hsimGenNormalizedJetTrackEta[binJetPt][binJetR]) delete hsimGenNormalizedJetTrackEta[binJetPt][binJetR];
      if (hsimGenNormalizedJetTrackPhi[binJetPt][binJetR]) delete hsimGenNormalizedJetTrackPhi[binJetPt][binJetR];
      if (hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]) delete hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete Normalized MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenNormalizedPartJetEta[binJetPt][binJetR]) delete hsimGenNormalizedPartJetEta[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetPhi[binJetPt][binJetR]) delete hsimGenNormalizedPartJetPhi[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetNTracks[binJetPt][binJetR]) delete hsimGenNormalizedPartJetNTracks[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetArea[binJetPt][binJetR]) delete hsimGenNormalizedPartJetArea[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR]) delete hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR]) delete hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR]) delete hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR];
      if (hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR]) delete hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR];
    }
  }
}

void JetAnalysis::InitConfig(TString trigger) {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  triggerName = trigger.Data();
  TString dirData = "fig/data/general";
  TString dirSim = Form("fig/sim/%s/general", triggerName.Data());
  TString dirDataVsSim = Form("fig/dataVSsim/%s/general", triggerName.Data());
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

  h3dataGenJetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta", taskJetQA.Data())));
  h3dataGenJetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
  h3dataGenJetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi", taskJetQA.Data())));
  h3dataGenJetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks", taskJetQA.Data())));
  h3dataGenJetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area", taskJetQA.Data())));
  h3dataGenJetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt", taskJetQA.Data())));
  h3dataGenJetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta", taskJetQA.Data())));
  h3dataGenJetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi", taskJetQA.Data())));
  h3dataGenJetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_leadingtrack_pt", taskJetQA.Data())));

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

  h3simGenJetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta", taskJetQA.Data())));
  h3simGenJetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
  h3simGenJetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi", taskJetQA.Data())));
  h3simGenJetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks", taskJetQA.Data())));
  h3simGenJetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area", taskJetQA.Data())));
  h3simGenJetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt", taskJetQA.Data())));
  h3simGenJetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta", taskJetQA.Data())));
  h3simGenJetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi", taskJetQA.Data())));
  h3simGenJetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_leadingtrack_pt", taskJetQA.Data())));

  if (doMCP) {
    h3simGenPartJetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_eta_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
    h3simGenPartJetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_eta_part_jet_phi_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_ntracks_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_area_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_pt_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_eta_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_phi_part", taskJetQA.Data())));
    h3simGenPartJetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_leadingtrack_pt_part", taskJetQA.Data())));
  }

  std::cout << "Load completed General Jet QA MC" << std::endl;
  return 1;
}

void JetAnalysis::initHistogramForNormalizationGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataGenJetPt[binJetR] = new TH1F(Form("hdataGenJetPt_%d", binJetR), "", h3dataGenJetRjetPtjetEta->GetNbinsY(), h3dataGenJetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3dataGenJetRjetPtjetEta->GetNbinsY()));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataGenJetEta[binJetPt][binJetR] = new TH1F(Form("hdataGenJetEta_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtjetEta->GetNbinsZ(), h3dataGenJetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtjetEta->GetNbinsZ()));
      hdataGenJetPhi[binJetPt][binJetR] = new TH1F(Form("hdataGenJetPhi_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtjetPhi->GetNbinsZ(), h3dataGenJetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtjetPhi->GetNbinsZ()));
      hdataGenJetNTracks[binJetPt][binJetR] = new TH1F(Form("hdataGenJetNTracks_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtjetNTracks->GetNbinsZ(), h3dataGenJetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtjetNTracks->GetNbinsZ()));
      hdataGenJetArea[binJetPt][binJetR] = new TH1F(Form("hdataGenJetArea_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtjetArea->GetNbinsZ(), h3dataGenJetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtjetArea->GetNbinsZ()));
      hdataGenJetTrackPt[binJetPt][binJetR] = new TH1F(Form("hdataGenJetTrackPt_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtTrackPt->GetNbinsZ(), h3dataGenJetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtTrackPt->GetNbinsZ()));
      hdataGenJetTrackEta[binJetPt][binJetR] = new TH1F(Form("hdataGenJetTrackEta_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtTrackEta->GetNbinsZ(), h3dataGenJetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtTrackEta->GetNbinsZ()));
      hdataGenJetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hdataGenJetTrackPhi_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtTrackPhi->GetNbinsZ(), h3dataGenJetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtTrackPhi->GetNbinsZ()));
      hdataGenJetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hdataGenJetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3dataGenJetRjetPtLeadingTrackPt->GetNbinsZ(), h3dataGenJetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3dataGenJetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3dataGenJetRjetPtLeadingTrackPt->GetNbinsZ()));
    }
  }
}

void JetAnalysis::initHistogramForNormalizationGeneralQAMC(bool doMCP = false) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimGenJetPt[binJetR] = new TH1F(Form("hsimGenJetPt_%d", binJetR), "", h3simGenJetRjetPtjetEta->GetNbinsY(), h3simGenJetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3simGenJetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3simGenJetRjetPtjetEta->GetNbinsY()));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimGenJetEta[binJetPt][binJetR] = new TH1F(Form("hsimGenJetEta_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtjetEta->GetNbinsZ(), h3simGenJetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtjetEta->GetNbinsZ()));

      hsimGenJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenJetPhi_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtjetPhi->GetNbinsZ(), h3simGenJetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtjetPhi->GetNbinsZ()));
      hsimGenJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimGenJetNTracks_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtjetNTracks->GetNbinsZ(), h3simGenJetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtjetNTracks->GetNbinsZ()));
      hsimGenJetArea[binJetPt][binJetR] = new TH1F(Form("hsimGenJetArea_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtjetArea->GetNbinsZ(), h3simGenJetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtjetArea->GetNbinsZ()));
      hsimGenJetTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenJetTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtTrackPt->GetNbinsZ(), h3simGenJetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtTrackPt->GetNbinsZ()));
      hsimGenJetTrackEta[binJetPt][binJetR] = new TH1F(Form("hsimGenJetTrackEta_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtTrackEta->GetNbinsZ(), h3simGenJetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtTrackEta->GetNbinsZ()));
      hsimGenJetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenJetTrackPhi_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtTrackPhi->GetNbinsZ(), h3simGenJetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtTrackPhi->GetNbinsZ()));
      hsimGenJetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenJetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenJetRjetPtLeadingTrackPt->GetNbinsZ(), h3simGenJetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenJetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3simGenJetRjetPtLeadingTrackPt->GetNbinsZ()));
    }
  }
  if (doMCP) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenPartJetPt[binJetR] = new TH1F(Form("hsimGenPartJetPt_%d", binJetR), "", h3simGenPartJetRjetPtjetEta->GetNbinsY(), h3simGenPartJetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3simGenPartJetRjetPtjetEta->GetNbinsY()));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimGenPartJetEta[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetEta_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtjetEta->GetNbinsZ(), h3simGenPartJetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtjetEta->GetNbinsZ()));
        hsimGenPartJetPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetPhi_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtjetPhi->GetNbinsZ(), h3simGenPartJetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtjetPhi->GetNbinsZ()));
        hsimGenPartJetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetNTracks_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtjetNTracks->GetNbinsZ(), h3simGenPartJetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtjetNTracks->GetNbinsZ()));
        //hsimGenPartJetArea[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetArea_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtjetArea->GetNbinsZ(), h3simGenPartJetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtjetArea->GetNbinsZ()));
        hsimGenPartJetTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtTrackPt->GetNbinsZ(), h3simGenPartJetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtTrackPt->GetNbinsZ()));
        hsimGenPartJetTrackEta[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetTrackEta_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtTrackEta->GetNbinsZ(), h3simGenPartJetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtTrackEta->GetNbinsZ()));
        hsimGenPartJetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetTrackPhi_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtTrackPhi->GetNbinsZ(), h3simGenPartJetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtTrackPhi->GetNbinsZ()));
        //hsimGenPartJetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenPartJetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenPartJetRjetPtLeadingTrackPt->GetNbinsZ(), h3simGenPartJetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenPartJetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3simGenPartJetRjetPtLeadingTrackPt->GetNbinsZ()));
      }
    }
  }
}

void JetAnalysis::projectionHistGeneralQAData() {
  TH1F *projJetPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetEta->ProjectionY("projJetPt", 1, h3dataGenJetRjetPtjetEta->GetNbinsX(), 1, h3dataGenJetRjetPtjetEta->GetNbinsZ()));
  TH1F *projJetEta = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3dataGenJetRjetPtjetEta->GetNbinsX(), 1, h3dataGenJetRjetPtjetEta->GetNbinsY()));
  TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3dataGenJetRjetPtjetPhi->GetNbinsX(), 1, h3dataGenJetRjetPtjetPhi->GetNbinsY()));
  TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3dataGenJetRjetPtjetNTracks->GetNbinsX(), 1, h3dataGenJetRjetPtjetNTracks->GetNbinsY()));
  TH1F *projJetArea = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3dataGenJetRjetPtjetArea->GetNbinsX(), 1, h3dataGenJetRjetPtjetArea->GetNbinsY()));
  TH1F *projJetTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtTrackPt->ProjectionZ("projJetTrackPt", 1, h3dataGenJetRjetPtTrackPt->GetNbinsX(), 1, h3dataGenJetRjetPtTrackPt->GetNbinsY()));
  TH1F *projJetTrackEta = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataGenJetRjetPtTrackEta->GetNbinsX(), 1, h3dataGenJetRjetPtTrackEta->GetNbinsY()));
  TH1F *projJetTrackPhi = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataGenJetRjetPtTrackPhi->GetNbinsX(), 1, h3dataGenJetRjetPtTrackPhi->GetNbinsY()));
  TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3dataGenJetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3dataGenJetRjetPtLeadingTrackPt->GetNbinsY()));

  hdataGenJetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
  hdataGenJetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
  hdataGenJetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
  hdataGenJetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
  hdataGenJetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
  hdataGenJetTrackPt[0][0] = reinterpret_cast<TH1F*>(projJetTrackPt->Clone());
  hdataGenJetTrackEta[0][0] = reinterpret_cast<TH1F*>(projJetTrackEta->Clone());
  hdataGenJetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projJetTrackPhi->Clone());
  hdataGenJetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());

  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // jet pt
    int leftbinJetRForJetPt = h3dataGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPt = h3dataGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3dataGenJetRjetPtjetEta->GetNbinsZ()));
    hdataGenJetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());
  
    // jet eta
    int leftbinJetRForJetEta = h3dataGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetEta = h3dataGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3dataGenJetRjetPtjetEta->GetNbinsZ()));
    hdataGenJetEta[0][binJetR]->Add(projJetRRangeJetEta);

    // jet phi
    int leftbinJetRForJetPhi = h3dataGenJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPhi = h3dataGenJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3dataGenJetRjetPtjetPhi->GetNbinsZ()));
    hdataGenJetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

    // number of tracks
    int leftbinJetRForJetNTracks = h3dataGenJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetNTracks = h3dataGenJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3dataGenJetRjetPtjetNTracks->GetNbinsZ()));
    hdataGenJetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

    // jet area
    int leftbinJetRForJetArea = h3dataGenJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetArea = h3dataGenJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3dataGenJetRjetPtjetArea->GetNbinsZ()));
    hdataGenJetArea[0][binJetR]->Add(projJetRRangeJetArea);

    // track pt
    int leftbinJetRForTrackPt = h3dataGenJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPt = h3dataGenJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3dataGenJetRjetPtjetArea->GetNbinsZ()));
    hdataGenJetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

    // track eta
    int leftbinJetRForTrackEta = h3dataGenJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackEta = h3dataGenJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3dataGenJetRjetPtjetArea->GetNbinsZ()));
    hdataGenJetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

    // track phi
    int leftbinJetRForTrackPhi = h3dataGenJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPhi = h3dataGenJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3dataGenJetRjetPtjetArea->GetNbinsZ()));
    hdataGenJetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

    // leading track pt
    int leftbinJetRForLeadingTrackPt = h3dataGenJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForLeadingTrackPt = h3dataGenJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3dataGenJetRjetPtjetArea->GetNbinsZ()));
    hdataGenJetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
      // jet eta
      int leftbinJetPtForJetEta = h3dataGenJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetEta = h3dataGenJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJetEta_%d_%d", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
      hdataGenJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
      hdataGenJetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

      // jet phi
      int leftbinJetPtForJetPhi = h3dataGenJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetPhi = h3dataGenJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetPhi->ProjectionZ(Form("projJetPtRangeJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
      hdataGenJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
      hdataGenJetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

      // number of tracks
      int leftbinJetPtForJetNTracks = h3dataGenJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetNTracks = h3dataGenJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
      hdataGenJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
      hdataGenJetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

      // jet area
      int leftbinJetPtForJetArea = h3dataGenJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetArea = h3dataGenJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetR, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
      hdataGenJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
      hdataGenJetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

      // track pt
      int leftbinJetPtForTrackPt = h3dataGenJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPt = h3dataGenJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
      hdataGenJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
      hdataGenJetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

      // track eta
      int leftbinJetPtForTrackEta = h3dataGenJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackEta = h3dataGenJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
      hdataGenJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
      hdataGenJetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

      // track phi
      int leftbinJetPtForTrackPhi = h3dataGenJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPhi = h3dataGenJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
      hdataGenJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
      hdataGenJetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      // leading track pt
      int leftbinJetPtForLeadingTrackPt = h3dataGenJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForLeadingTrackPt = h3dataGenJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataGenJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
      hdataGenJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
      hdataGenJetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
    }
  }
}

void JetAnalysis::projectionHistGeneralQAMC(bool doMCP= false) {

  TH1F *projJetPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetEta->ProjectionY("projJetPt", 1, h3simGenJetRjetPtjetEta->GetNbinsX(), 1, h3simGenJetRjetPtjetEta->GetNbinsZ()));
  TH1F *projJetEta = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3simGenJetRjetPtjetEta->GetNbinsX(), 1, h3simGenJetRjetPtjetEta->GetNbinsY()));
  TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3simGenJetRjetPtjetPhi->GetNbinsX(), 1, h3simGenJetRjetPtjetPhi->GetNbinsY()));
  TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3simGenJetRjetPtjetNTracks->GetNbinsX(), 1, h3simGenJetRjetPtjetNTracks->GetNbinsY()));
  TH1F *projJetArea = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3simGenJetRjetPtjetArea->GetNbinsX(), 1, h3simGenJetRjetPtjetArea->GetNbinsY()));
  TH1F *projTrackPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackPt->ProjectionZ("projTrackPt", 1, h3simGenJetRjetPtTrackPt->GetNbinsX(), 1, h3simGenJetRjetPtTrackPt->GetNbinsY()));
  TH1F *projTrackEta = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackEta->ProjectionZ("projTrackEta", 1, h3simGenJetRjetPtTrackEta->GetNbinsX(), 1, h3simGenJetRjetPtTrackEta->GetNbinsY()));
  TH1F *projTrackPhi = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackPhi->ProjectionZ("projTrackPhi", 1, h3simGenJetRjetPtTrackPhi->GetNbinsX(), 1, h3simGenJetRjetPtTrackPhi->GetNbinsY()));
  TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3simGenJetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3simGenJetRjetPtLeadingTrackPt->GetNbinsY()));

  hsimGenJetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
  hsimGenJetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
  hsimGenJetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
  hsimGenJetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
  hsimGenJetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
  hsimGenJetTrackPt[0][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
  hsimGenJetTrackEta[0][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
  hsimGenJetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
  hsimGenJetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());


  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // jet pt
    int leftbinJetRForJetPt = h3simGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPt = h3simGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3simGenJetRjetPtjetEta->GetNbinsZ()));
    hsimGenJetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

    // jet eta
    int leftbinJetRForJetEta = h3simGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetEta = h3simGenJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3simGenJetRjetPtjetEta->GetNbinsZ()));
    hsimGenJetEta[0][binJetR]->Add(projJetRRangeJetEta);

    // jet phi
    int leftbinJetRForJetPhi = h3simGenJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPhi = h3simGenJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3simGenJetRjetPtjetPhi->GetNbinsZ()));
    hsimGenJetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

    // number of tracks
    int leftbinJetRForJetNTracks = h3simGenJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetNTracks = h3simGenJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3simGenJetRjetPtjetNTracks->GetNbinsZ()));
    hsimGenJetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

    // jet area
    int leftbinJetRForJetArea = h3simGenJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetArea = h3simGenJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3simGenJetRjetPtjetArea->GetNbinsZ()));
    hsimGenJetArea[0][binJetR]->Add(projJetRRangeJetArea);

    // track pt
    int leftbinJetRForTrackPt = h3simGenJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPt = h3simGenJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackPt->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3simGenJetRjetPtTrackPt->GetNbinsZ()));
    hsimGenJetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

    // track eta
    int leftbinJetRForTrackEta = h3simGenJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackEta = h3simGenJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackEta->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3simGenJetRjetPtTrackEta->GetNbinsZ()));
    hsimGenJetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

    // track phi
    int leftbinJetRForTrackPhi = h3simGenJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPhi = h3simGenJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackPhi->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3simGenJetRjetPtTrackPhi->GetNbinsZ()));
    hsimGenJetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

    // leading track pt
    int leftbinJetRForLeadingTrackPt = h3simGenJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForLeadingTrackPt = h3simGenJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3simGenJetRjetPtLeadingTrackPt->GetNbinsZ()));
    hsimGenJetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      // jet eta
      int leftbinJetPtForJetEta = h3simGenJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetEta = h3simGenJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJeEta_%d_%d)", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
      hsimGenJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
      hsimGenJetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

      // jet phi
      int leftbinJetPtForJetPhi = h3simGenJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetPhi = h3simGenJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetPhi->ProjectionZ(Form("projJetPtRagneJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
      hsimGenJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
      hsimGenJetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

      // number of tracks
      int leftbinJetPtForJetNTracks = h3simGenJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetNTracks = h3simGenJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
      hsimGenJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
      hsimGenJetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

      // jet area
      int leftbinJetPtForJetArea = h3simGenJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetArea = h3simGenJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3simGenJetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetPt, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
      hsimGenJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
      hsimGenJetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

      // track pt
      int leftbinJetPtForTrackPt = h3simGenJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPt = h3simGenJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
      hsimGenJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
      hsimGenJetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

      // track eta
      int leftbinJetPtForTrackEta = h3simGenJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackEta = h3simGenJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
      hsimGenJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
      hsimGenJetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

      // track phi
      int leftbinJetPtForTrackPhi = h3simGenJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPhi = h3simGenJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenJetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
      hsimGenJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
      hsimGenJetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      // leading track pt
      int leftbinJetPtForLeadingTrackPt = h3simGenJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForLeadingTrackPt = h3simGenJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
      hsimGenJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
      hsimGenJetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
    }
  }

  if (doMCP) {
    TH1F *projJetPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetEta->ProjectionY("projJetPt", 1, h3simGenPartJetRjetPtjetEta->GetNbinsX(), 1, h3simGenPartJetRjetPtjetEta->GetNbinsZ()));
    TH1F *projJetEta = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3simGenPartJetRjetPtjetEta->GetNbinsX(), 1, h3simGenPartJetRjetPtjetEta->GetNbinsY()));
    TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3simGenPartJetRjetPtjetPhi->GetNbinsX(), 1, h3simGenPartJetRjetPtjetPhi->GetNbinsY()));
    TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3simGenPartJetRjetPtjetNTracks->GetNbinsX(), 1, h3simGenPartJetRjetPtjetNTracks->GetNbinsY()));
    //TH1F *projJetArea = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3simGenPartJetRjetPtjetArea->GetNbinsX(), 1, h3simGenPartJetRjetPtjetArea->GetNbinsY()));
    TH1F *projTrackPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackPt->ProjectionZ("projTrackPt", 1, h3simGenPartJetRjetPtTrackPt->GetNbinsX(), 1, h3simGenPartJetRjetPtTrackPt->GetNbinsY()));
    TH1F *projTrackEta = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackEta->ProjectionZ("projTrackEta", 1, h3simGenPartJetRjetPtTrackEta->GetNbinsX(), 1, h3simGenPartJetRjetPtTrackEta->GetNbinsY()));
    TH1F *projTrackPhi = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackPhi->ProjectionZ("projTrackPhi", 1, h3simGenPartJetRjetPtTrackPhi->GetNbinsX(), 1, h3simGenPartJetRjetPtTrackPhi->GetNbinsY()));
    //TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3simGenPartJetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3simGenPartJetRjetPtLeadingTrackPt->GetNbinsY()));

    hsimGenPartJetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
    hsimGenPartJetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
    hsimGenPartJetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
    hsimGenPartJetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
    //hsimGenPartJetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
    hsimGenPartJetTrackPt[0][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
    hsimGenPartJetTrackEta[0][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
    hsimGenPartJetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
    //hsimGenPartJetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());
    for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      // jet pt
      int leftbinJetRForJetPt = h3simGenPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPt = h3simGenPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3simGenPartJetRjetPtjetEta->GetNbinsZ()));
      hsimGenPartJetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

      // jet eta
      int leftbinJetRForJetEta = h3simGenPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetEta = h3simGenPartJetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3simGenPartJetRjetPtjetEta->GetNbinsZ()));
      hsimGenPartJetEta[0][binJetR]->Add(projJetRRangeJetEta);

      // jet phi
      int leftbinJetRForJetPhi = h3simGenPartJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPhi = h3simGenPartJetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3simGenPartJetRjetPtjetPhi->GetNbinsZ()));
      hsimGenPartJetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

      // number of tracks
      int leftbinJetRForJetNTracks = h3simGenPartJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetNTracks = h3simGenPartJetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3simGenPartJetRjetPtjetNTracks->GetNbinsZ()));
      hsimGenPartJetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

//      // jet area
//      int leftbinJetRForJetArea = h3simGenPartJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
//      int rightbinJetRForJetArea = h3simGenPartJetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
//      TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3simGenPartJetRjetPtjetArea->GetNbinsZ()));
//      hsimGenPartJetArea[0][binJetR]->Add(projJetRRangeJetArea);

      // track pt
      int leftbinJetRForTrackPt = h3simGenPartJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPt = h3simGenPartJetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackPt->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3simGenPartJetRjetPtTrackPt->GetNbinsZ()));
      hsimGenPartJetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

      // track eta
      int leftbinJetRForTrackEta = h3simGenPartJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackEta = h3simGenPartJetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackEta->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3simGenPartJetRjetPtTrackEta->GetNbinsZ()));
      hsimGenPartJetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

      // track phi
      int leftbinJetRForTrackPhi = h3simGenPartJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPhi = h3simGenPartJetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackPhi->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3simGenPartJetRjetPtTrackPhi->GetNbinsZ()));
      hsimGenPartJetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

//      // leading track pt
//      int leftbinJetRForLeadingTrackPt = h3simGenPartJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
//      int rightbinJetRForLeadingTrackPt = h3simGenPartJetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
//      TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3simGenPartJetRjetPtLeadingTrackPt->GetNbinsZ()));
//      hsimGenPartJetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

      for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        // jet eta
        int leftbinJetPtForJetEta = h3simGenPartJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetEta = h3simGenPartJetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJetEta_%d_%d", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
        hsimGenPartJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
        hsimGenPartJetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

        // jet phi
        int leftbinJetPtForJetPhi = h3simGenPartJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetPhi = h3simGenPartJetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetPhi->ProjectionZ(Form("projJetPtRangeJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
        hsimGenPartJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
        hsimGenPartJetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

        // number of tracks
        int leftbinJetPtForJetNTracks = h3simGenPartJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetNTracks = h3simGenPartJetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
        hsimGenPartJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
        hsimGenPartJetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

//        // jet area
//        int leftbinJetPtForJetArea = h3simGenPartJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
//        int rightbinJetPtForJetArea = h3simGenPartJetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
//        TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetPt, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
//        hsimGenPartJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
//        hsimGenPartJetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

        // track pt
        int leftbinJetPtForTrackPt = h3simGenPartJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackPt = h3simGenPartJetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
        hsimGenPartJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
        hsimGenPartJetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

        // track eta
        int leftbinJetPtForTrackEta = h3simGenPartJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackEta = h3simGenPartJetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
        hsimGenPartJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
        hsimGenPartJetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

        // track phi
        int leftbinJetPtForTrackPhi = h3simGenPartJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackPhi = h3simGenPartJetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
        hsimGenPartJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
        hsimGenPartJetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

//        // leading track pt
//        int leftbinJetPtForLeadingTrackPt = h3simGenPartJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
//        int rightbinJetPtForLeadingTrackPt = h3simGenPartJetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
//        TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenPartJetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
//        hsimGenPartJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
//        hsimGenPartJetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
      }
    }
  }
}

void JetAnalysis::clonenormalizedHistogramGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataGenNormalizedJetPt[binJetR] = reinterpret_cast<TH1F*>(hdataGenJetPt[binJetR]->Clone(Form("hdataGenNormalizedJetPt_%d", binJetR)));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataGenNormalizedJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetEta[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetEta_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetPhi[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetPhi_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetNTracks[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetNTracks_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetArea[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetArea_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetTrackPt[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetTrackPt_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetTrackEta[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetTrackEta_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetTrackPhi[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetTrackPhi_%d_%d", binJetPt, binJetR)));
      hdataGenNormalizedJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenJetLeadingTrackPt[binJetPt][binJetR]->Clone(Form("hdataGenNormalizedJetLeadingTrackPt_%d_%d", binJetPt, binJetR)));
    }
  }
}

void JetAnalysis::clonenormalizedHistogramGeneralQAMC(bool doMCP) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimGenNormalizedJetPt[binJetR] = reinterpret_cast<TH1F*>(hsimGenJetPt[binJetR]->Clone(Form("hsimGenNormalizedJetPt_%d", binJetR)));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimGenNormalizedJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetEta[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetEta_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetPhi[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetPhi_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetNTracks[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetNTracks_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetArea[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetArea_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetTrackPt_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetTrackEta[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetTrackEta_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetTrackPhi[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetTrackPhi_%d_%d", binJetPt, binJetR)));
      hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenJetLeadingTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedJetLeadingTrackPt_%d_%d", binJetPt, binJetR)));
    }
  }
  if (doMCP) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenNormalizedPartJetPt[binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetPt[binJetR]->Clone(Form("hsimGenNormalizedPartJetPt_%d", binJetR)));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimGenNormalizedPartJetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetEta[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetEta_%d_%d", binJetPt, binJetR)));
        hsimGenNormalizedPartJetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetPhi[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetPhi_%d_%d", binJetPt, binJetR)));
        hsimGenNormalizedPartJetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetNTracks[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetNTracks_%d_%d", binJetPt, binJetR)));
        //hsimGenNormalizedPartJetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetArea[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetArea_%d_%d", binJetPt, binJetR)));
        hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetTrackPt_%d_%d", binJetPt, binJetR)));
        hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetTrackEta[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetTrackEta_%d_%d", binJetPt, binJetR)));
        hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetTrackPhi[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetTrackPhi_%d_%d", binJetPt, binJetR)));
        //hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenPartJetLeadingTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenNormalizedPartJetLeadingTrackPt_%d_%d", binJetPt, binJetR)));
      }
    }
  }
}

void JetAnalysis::normalizedHistogramGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataGenNormalizedJetPt[binJetR]->Scale(1. / hdataGenNormalizedJetPt[binJetR]->Integral());
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataGenNormalizedJetEta[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetEta[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetPhi[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetPhi[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetNTracks[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetNTracks[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetArea[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetArea[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetTrackPt[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetTrackPt[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetTrackEta[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetTrackEta[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetTrackPhi[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetTrackPhi[binJetPt][binJetR]->Integral());
      hdataGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]->Scale(1. / hdataGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]->Integral());
    }
  }
}

void JetAnalysis::normalizedHistogramGeneralQAMC(bool doMCP=false) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimGenNormalizedJetPt[binJetR]->Scale(1. / hsimGenNormalizedJetPt[binJetR]->GetEntries());
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimGenNormalizedJetEta[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetEta[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetPhi[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetPhi[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetNTracks[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetNTracks[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetArea[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetArea[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetTrackPt[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetTrackEta[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetTrackEta[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetTrackPhi[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetTrackPhi[binJetPt][binJetR]->Integral());
      hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]->Integral());
    }
  }
  if (doMCP) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenNormalizedPartJetPt[binJetR]->Scale(1. / hsimGenNormalizedPartJetPt[binJetR]->Integral());
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
        hsimGenNormalizedPartJetEta[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetEta[binJetPt][binJetR]->Integral());
        hsimGenNormalizedPartJetPhi[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetPhi[binJetPt][binJetR]->Integral());
        hsimGenNormalizedPartJetNTracks[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetNTracks[binJetPt][binJetR]->Integral());
        //hsimGenNormalizedPartJetArea[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetArea[binJetPt][binJetR]->Integral());
        hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR]->Integral());
        hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR]->Integral());
        hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR]->Integral());
        //hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR]->Integral());
      }
    }
  }
}

void JetAnalysis::SaveHistogramGeneralQA(TString rootFile, bool doData, bool doMC, bool doMCP) {
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

    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hdataGenJetPt[binJetR]->Write();
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hdataGenJetEta[binJetPt][binJetR]->Write();
        hdataGenJetPhi[binJetPt][binJetR]->Write();
        hdataGenJetNTracks[binJetPt][binJetR]->Write();
        hdataGenJetArea[binJetPt][binJetR]->Write();
        hdataGenJetTrackPt[binJetPt][binJetR]->Write();
        hdataGenJetTrackEta[binJetPt][binJetR]->Write();
        hdataGenJetTrackPhi[binJetPt][binJetR]->Write();
        hdataGenJetLeadingTrackPt[binJetPt][binJetR]->Write();

        hdataGenNormalizedJetEta[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetPhi[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetNTracks[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetArea[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetTrackPt[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetTrackEta[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetTrackPhi[binJetPt][binJetR]->Write();
        hdataGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]->Write();
      }
    }
  }

  if (doMC) {
    dir = fout->GetDirectory("sim");
    if (!dir) {
      dir = fout->mkdir("sim");
      dir->cd();
    }
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenJetPt[binJetR]->Write();
      hsimGenNormalizedJetPt[binJetR]->Write();
      if (doMCP) {
        hsimGenPartJetPt[binJetR]->Write();
        hsimGenNormalizedPartJetPt[binJetR]->Write();
      }
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimGenJetEta[binJetPt][binJetR]->Write();
        hsimGenJetPhi[binJetPt][binJetR]->Write();
        hsimGenJetNTracks[binJetPt][binJetR]->Write();
        hsimGenJetArea[binJetPt][binJetR]->Write();
        hsimGenJetTrackPt[binJetPt][binJetR]->Write();
        hsimGenJetTrackEta[binJetPt][binJetR]->Write();
        hsimGenJetTrackPhi[binJetPt][binJetR]->Write();
        hsimGenJetLeadingTrackPt[binJetPt][binJetR]->Write();

        hsimGenNormalizedJetEta[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetPhi[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetNTracks[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetArea[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetTrackPt[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetTrackEta[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetTrackPhi[binJetPt][binJetR]->Write();
        hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR]->Write();

        if (doMCP) {
          hsimGenPartJetEta[binJetPt][binJetR]->Write();
          hsimGenPartJetPhi[binJetPt][binJetR]->Write();
          hsimGenPartJetNTracks[binJetPt][binJetR]->Write();
          //hsimGenPartJetArea[binJetPt][binJetR]->Write();
          hsimGenPartJetTrackPt[binJetPt][binJetR]->Write();
          hsimGenPartJetTrackEta[binJetPt][binJetR]->Write();
          hsimGenPartJetTrackPhi[binJetPt][binJetR]->Write();
          hsimGenPartJetLeadingTrackPt[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetEta[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetPhi[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetNTracks[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetArea[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR]->Write();
          hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR]->Write();
        }
      }
    }
  }

  delete fout;
}

// Draw function
void JetAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void JetAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax){
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
void JetAnalysis::drawDataGenJetPt(bool doLog = true, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], " #it{p}_{T}^{jet}", "1/#it{N_{jet}} d#it{N_{jet}}/d#it{p}_{T}^{jet}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetR > 0) latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetmomentum_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawDataGenJetEta(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETETA[0], GeneralJet::REFHIST::JETETA[1], GeneralJet::REFHIST::JETETA[2], GeneralJet::REFHIST::JETETA[3], "#eta", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{#eta}^{jet}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jeteta_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawDataGenJetPhi(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPHI[0], GeneralJet::REFHIST::JETPHI[1], GeneralJet::REFHIST::JETPHI[2], GeneralJet::REFHIST::JETPHI[3], "#phi", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{#phi}^{jet}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetphi_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawDataGenJetNTracks(bool doLog = true, int binJetPt =0, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETNTRACKS[0], GeneralJet::REFHIST::JETNTRACKS[1], GeneralJet::REFHIST::JETNTRACKS[2], GeneralJet::REFHIST::JETNTRACKS[3], "#it{N}_{track}", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{N}_{track}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetntracks_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetAnalysis::drawDataGenJetArea(bool doLog = true, int binJetPt =0, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetArea[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETAREA[0], GeneralJet::REFHIST::JETAREA[1], GeneralJet::REFHIST::JETAREA[2], GeneralJet::REFHIST::JETAREA[3], "#it{A}", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{A}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetArea_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetAnalysis::drawDataGenJetTrackPt(bool doLog = true, int binJetPt =0, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "it{p}_{T}^{track}", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{p}_{T}^{track}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetTrackPt_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetAnalysis::drawDataGenJetTrackEta(bool doLog = true, int binJetPt =0, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKETA[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#eta", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{p}_{T}^{track}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetTrackEta_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetAnalysis::drawDataGenJetTrackPhi(bool doLog = true, int binJetPt =0, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPHI[0], GeneralJet::REFHIST::TRACKPHI[1], GeneralJet::REFHIST::TRACKPHI[2], GeneralJet::REFHIST::TRACKPHI[3], "#phi", "1/#it{N_{jet}}d#it{N_{jet}}/d#phi}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetTrackEta_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

void JetAnalysis::drawDataGenJetLeadingTrackPt(bool doLog = true, int binJetPt =0, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenNormalizedJetTrackPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p}_{T}", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{p}_{T}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{p}_{T}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<double>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetLeadingTrackPt_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));

}

// MC
void JetAnalysis::drawSimGenJetPt(bool doLog = true, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetR > 0) latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jetmomentum_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawSimGenJetEta(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETETA[0], GeneralJet::REFHIST::JETETA[1], GeneralJet::REFHIST::JETETA[2], GeneralJet::REFHIST::JETETA[3], "#it{#eta}_{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#eta}_{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawSimGenJetPhi(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPHI[0], GeneralJet::REFHIST::JETPHI[1], GeneralJet::REFHIST::JETPHI[2], GeneralJet::REFHIST::JETPHI[3], "#it{#phi_{jet}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#phi}_{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawSimGenJetNTracks(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETNTRACKS[0], GeneralJet::REFHIST::JETNTRACKS[1], GeneralJet::REFHIST::JETNTRACKS[2], GeneralJet::REFHIST::JETNTRACKS[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{N_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jetntracks_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenJetArea(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetArea[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETAREA[0], GeneralJet::REFHIST::JETAREA[1], GeneralJet::REFHIST::JETAREA[2], GeneralJet::REFHIST::JETAREA[3], "#it{A_{jet}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{A_{jet}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jetarea_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenJetTrackPt(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetTrackPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p_{T}^{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jettrackpt_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenJetTrackEta(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetTrackEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKETA[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#it{#eta_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#eta_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jettracketa_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenJetTrackPhi(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetTrackPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPHI[0], GeneralJet::REFHIST::TRACKPHI[1], GeneralJet::REFHIST::TRACKPHI[2], GeneralJet::REFHIST::TRACKPHI[3], "#it{#phi_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#phi_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jettrackphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenJetLeadingTrackPt(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedJetLeadingTrackPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p_{T}^{leading track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{leading track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/jetleadingtrackpt_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenPartJetPt(bool doLog = true, int binJetR=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimGenNormalizedPartJetPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  latex.DrawLatex(0.3, 0.95, "particle level jet");
  if (binJetR > 0) latex.DrawLatex(0.3, 0.9, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjetmomentum_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawSimGenPartJetEta(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedPartJetEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETETA[0], GeneralJet::REFHIST::JETETA[1], GeneralJet::REFHIST::JETETA[2], GeneralJet::REFHIST::JETETA[3], "#it{#eta}_{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#eta}_{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  latex.DrawLatex(0.3, 0.95, "particle level jet");
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjeteta_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawSimGenPartJetPhi(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedPartJetPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPHI[0], GeneralJet::REFHIST::JETPHI[1], GeneralJet::REFHIST::JETPHI[2], GeneralJet::REFHIST::JETPHI[3], "#it{#phi_{jet}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#phi}_{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  latex.DrawLatex(0.3, 0.95, "particle level jet");
  if (binJetPt > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
  }
  if (binJetR > 0) {
    latex.DrawLatex(0.3, 0.85, Form("%0.1f < #it{R}^{jet} < %0.1f", static_cast<double>(GeneralJet::binsJetR[binJetR-1]), static_cast<double>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjetphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR]*10) % 10));
}

void JetAnalysis::drawSimGenPartJetNTracks(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedPartJetNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETNTRACKS[0], GeneralJet::REFHIST::JETNTRACKS[1], GeneralJet::REFHIST::JETNTRACKS[2], GeneralJet::REFHIST::JETNTRACKS[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{N_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjetntracks_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

//void JetAnalysis::drawSimGenPartJetArea(bool doLog = true, int binJetPt = 0, int binJetR=0) {
//	std::vector<HistogramData> NormHistList;
//	NormHistList.push_back({hsimGenNormalizedPartJetArea[binJetPt][binJetR], ""});
//  canvasHandler = new CanvasHandler();
//  canvasHandler->createCanvas(canvasNum++);
//  if (doLog) gPad->SetLogy();
//  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETAREA[0], GeneralJet::REFHIST::JETAREA[1], GeneralJet::REFHIST::JETAREA[2], GeneralJet::REFHIST::JETAREA[3], "#it{A_{jet}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{A_{jet}}}");
//  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
//  if (binJetPt > 0 || binJetR > 0) {
//    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
//    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
//  }
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/partjetarea_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
//}

void JetAnalysis::drawSimGenPartJetTrackPt(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedPartJetTrackPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p_{T}^{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjettrackpt_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenPartJetTrackEta(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedPartJetTrackEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKETA[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#it{#eta_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#eta_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjettracketa_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(),static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::drawSimGenPartJetTrackPhi(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenNormalizedPartJetTrackPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPHI[0], GeneralJet::REFHIST::TRACKPHI[1], GeneralJet::REFHIST::TRACKPHI[2], GeneralJet::REFHIST::TRACKPHI[3], "#it{#phi_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#phi_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt > 0 || binJetR > 0) {
    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/general/partjettrackphi_%d_%d.pdf\")", canvasNum - 1, triggerName.Data(), static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

//void JetAnalysis::drawSimGenPartJetLeadingTrackPt(bool doLog = true, int binJetPt = 0, int binJetR=0) {
//	std::vector<HistogramData> NormHistList;
//	NormHistList.push_back({hsimGenNormalizedPartJetLeadingTrackPt[binJetPt][binJetR], ""});
//  canvasHandler = new CanvasHandler();
//  canvasHandler->createCanvas(canvasNum++);
//  if (doLog) gPad->SetLogy();
//  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p_{T}^{leading track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{leading track}}}");
//  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
//  if (binJetPt > 0 || binJetR > 0) {
//    latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(GeneralJet::binsJetPt[binJetPt-1]), static_cast<int>(GeneralJet::binsJetPt[binJetPt])));
//    latex.DrawLatex(0.3, 0.85, Form("%d < #it{R}^{jet} < %d", static_cast<int>(GeneralJet::binsJetR[binJetR-1]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
//  }
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/partjetleadingtrackpt_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
//}

// data and MC
void JetAnalysis::DrawRatioDataMCGenJetPt(bool doLog = false, int binJetR =0) {
  TH1F *hRatio = static_cast<TH1F*>(hdataGenNormalizedJetPt[binJetR]->Clone("hRatio"));
  hRatio->Divide(hsimGenNormalizedJetPt[binJetR]);
  canvasHandler = new CanvasHandler();
  canvasHandler->drawUpperPad(hsimGenNormalizedJetPt[binJetR], canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "","#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}");
  canvasHandler->drawLowerPad(hRatio, canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "#it{p}_{T}^{jet}");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/general/temp.pdf\")", canvasNum));
  canvasNum++;
}


#endif // JETANALYSIS_H
