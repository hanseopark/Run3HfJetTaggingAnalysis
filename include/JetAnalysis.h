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
    //JetAnalysis(const TString rootFileGeneralQA, TString rootFileSV2Prong, TString rootFileSV3Prong, const TString taskTC, const TString taskSV, bool doMC, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong) {
    JetAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMC, bool dopartLevel) {
      if (doData) {
        LoadDataGeneralQA(rootData.Data());
        InitHistogramForNormalizationGeneralQAData();
      	ProjectionHistGeneralQAData();
      	CloneNormalizedHistogramGeneralQAData();
      	NormalizedHistogramGeneralQAData();
      }
      if (doMC) {
        LoadSimGeneralQA(rootSim.Data(), dopartLevel);
        InitHistogramForNormalizationGeneralQAMC(dopartLevel);
      	ProjectionHistGeneralQAMC(dopartLevel);
      	CloneNormalizedHistogramGeneralQAMC(dopartLevel);
      	NormalizedHistogramGeneralQAMC(dopartLevel);
      }
      SaveHistogramGeneralQA("GeneralJetQA.root", doData, doMC, dopartLevel);
    }

    ~JetAnalysis();

    // function
    int LoadDataGeneralQA(TString rootData);
    int LoadSimGeneralQA(TString rootSim, bool dopartLevel);
    void InitHistogramForNormalizationGeneralQAData();
    void InitHistogramForNormalizationGeneralQAMC(bool dopartLevel);
    void ProjectionHistGeneralQAData();
    void ProjectionHistGeneralQAMC(bool dopartLevel);
    void CloneNormalizedHistogramGeneralQAData();
    void CloneNormalizedHistogramGeneralQAMC(bool dopartLevel);
    void NormalizedHistogramGeneralQAData();
    void NormalizedHistogramGeneralQAMC(bool dopartLevel);
    void SaveHistogramGeneralQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // Draw option
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);
    void DrawDataGenJetPt(bool doLog, int binJetR);
    void DrawDataGenJetEta(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetPhi(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetNTracks(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetArea(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void DrawDataGenJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);

    void DrawSimGenJetPt(bool doLog, int binJetR);
    void DrawSimGenJetEta(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetPhi(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetNTracks(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetArea(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);

    void DrawSimGenPartJetPt(bool doLog, int binJetR);
    void DrawSimGenPartJetEta(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetPhi(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetNTracks(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetArea(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetTrackPt(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetTrackEta(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetTrackPhi(bool doLog, int binJetPt, int binJetR);
    void DrawSimGenPartJetLeadingTrackPt(bool doLog, int binJetPt, int binJetR);
    void DrawRatioDataMCGenJetPt(bool doLog, int binJetR);

    // histogram from root file
    /// data, mcd
    TH1F* hdataGenjetPt[GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    TH1F* hsimGenjetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    /// mcp
    TH1F* hsimGenpartjetPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

  protected:
    // draw option
    int canvasNum=0;
    CanvasHandler* canvasHandler;

    // histogram
    /// data
    TH3F* h3dataGenjetRjetPtjetEta;
    TH3F* h3dataGenjetRjetPtjetPhi;
    TH3F* h3dataGenjetRjetEtajetPhi;
    TH3F* h3dataGenjetRjetPtjetNTracks;
    TH3F* h3dataGenjetRjetPtjetArea;
    TH3F* h3dataGenjetRjetPtTrackPt;
    TH3F* h3dataGenjetRjetPtTrackEta;
    TH3F* h3dataGenjetRjetPtTrackPhi;
    TH3F* h3dataGenjetRjetPtLeadingTrackPt;

    /// MC
    TH3F* h3simGenjetRjetPtjetEta;
    TH3F* h3simGenjetRjetPtjetPhi;
    TH3F* h3simGenjetRjetEtajetPhi;
    TH3F* h3simGenjetRjetPtjetNTracks;
    TH3F* h3simGenjetRjetPtjetArea;
    TH3F* h3simGenjetRjetPtTrackPt;
    TH3F* h3simGenjetRjetPtTrackEta;
    TH3F* h3simGenjetRjetPtTrackPhi;
    TH3F* h3simGenjetRjetPtLeadingTrackPt;

    //// particle level
    TH3F* h3simGenpartjetRjetPtjetEta;
    TH3F* h3simGenpartjetRjetPtjetPhi;
    TH3F* h3simGenpartjetRjetEtajetPhi;
    TH3F* h3simGenpartjetRjetPtjetNTracks;
    TH3F* h3simGenpartjetRjetPtjetArea;
    TH3F* h3simGenpartjetRjetPtTrackPt;
    TH3F* h3simGenpartjetRjetPtTrackEta;
    TH3F* h3simGenpartjetRjetPtTrackPhi;
    TH3F* h3simGenpartjetRjetPtLeadingTrackPt;

    // Normalized histogram
    /// data, mcd
    TH1F* hdataGenjetNormalizedPt[GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hdataGenjetNormalizedLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    TH1F* hsimGenjetNormalizedPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenjetNormalizedLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

    /// mcp
    TH1F* hsimGenpartjetNormalizedPt[GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedNTracks[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedArea[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedTrackEta[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedTrackPhi[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];
    TH1F* hsimGenpartjetNormalizedLeadingTrackPt[GeneralJet::nBinsJetPt+1][GeneralJet::nBinsJetR+1];

  private:
    std::vector<HistogramData> histList;

};

JetAnalysis::~JetAnalysis() {
  // Delete data histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hdataGenjetPt[binJetR]) delete hdataGenjetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hdataGenjetEta[binJetPt][binJetR]) delete hdataGenjetEta[binJetPt][binJetR];
      if (hdataGenjetPhi[binJetPt][binJetR]) delete hdataGenjetPhi[binJetPt][binJetR];
      if (hdataGenjetNTracks[binJetPt][binJetR]) delete hdataGenjetNTracks[binJetPt][binJetR];
      if (hdataGenjetArea[binJetPt][binJetR]) delete hdataGenjetArea[binJetPt][binJetR];
      if (hdataGenjetTrackPt[binJetPt][binJetR]) delete hdataGenjetTrackPt[binJetPt][binJetR];
      if (hdataGenjetTrackEta[binJetPt][binJetR]) delete hdataGenjetTrackEta[binJetPt][binJetR];
      if (hdataGenjetTrackPhi[binJetPt][binJetR]) delete hdataGenjetTrackPhi[binJetPt][binJetR];
      if (hdataGenjetLeadingTrackPt[binJetPt][binJetR]) delete hdataGenjetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hsimGenjetPt[binJetR]) delete hsimGenjetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenjetEta[binJetPt][binJetR]) delete hsimGenjetEta[binJetPt][binJetR];
      if (hsimGenjetPhi[binJetPt][binJetR]) delete hsimGenjetPhi[binJetPt][binJetR];
      if (hsimGenjetNTracks[binJetPt][binJetR]) delete hsimGenjetNTracks[binJetPt][binJetR];
      if (hsimGenjetArea[binJetPt][binJetR]) delete hsimGenjetArea[binJetPt][binJetR];
      if (hsimGenjetTrackPt[binJetPt][binJetR]) delete hsimGenjetTrackPt[binJetPt][binJetR];
      if (hsimGenjetTrackEta[binJetPt][binJetR]) delete hsimGenjetTrackEta[binJetPt][binJetR];
      if (hsimGenjetTrackPhi[binJetPt][binJetR]) delete hsimGenjetTrackPhi[binJetPt][binJetR];
      if (hsimGenjetLeadingTrackPt[binJetPt][binJetR]) delete hsimGenjetLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete particle level histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    if (hsimGenpartjetPt[binJetR]) delete hsimGenpartjetPt[binJetR];
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenpartjetEta[binJetPt][binJetR]) delete hsimGenpartjetEta[binJetPt][binJetR];
      if (hsimGenpartjetPhi[binJetPt][binJetR]) delete hsimGenpartjetPhi[binJetPt][binJetR];
      if (hsimGenpartjetNTracks[binJetPt][binJetR]) delete hsimGenpartjetNTracks[binJetPt][binJetR];
      if (hsimGenpartjetArea[binJetPt][binJetR]) delete hsimGenpartjetArea[binJetPt][binJetR];
      if (hsimGenpartjetTrackPt[binJetPt][binJetR]) delete hsimGenpartjetTrackPt[binJetPt][binJetR];
      if (hsimGenpartjetTrackEta[binJetPt][binJetR]) delete hsimGenpartjetTrackEta[binJetPt][binJetR];
      if (hsimGenpartjetTrackPhi[binJetPt][binJetR]) delete hsimGenpartjetTrackPhi[binJetPt][binJetR];
      if (hsimGenpartjetLeadingTrackPt[binJetPt][binJetR]) delete hsimGenpartjetLeadingTrackPt[binJetPt][binJetR];
    }
  }
  // Delete cloned data histograms
  if (h3dataGenjetRjetPtjetEta) delete h3dataGenjetRjetPtjetEta;
  if (h3dataGenjetRjetPtjetPhi) delete h3dataGenjetRjetPtjetPhi;
  if (h3dataGenjetRjetEtajetPhi) delete h3dataGenjetRjetEtajetPhi;
  if (h3dataGenjetRjetPtjetNTracks) delete h3dataGenjetRjetPtjetNTracks;
  if (h3dataGenjetRjetPtjetArea) delete h3dataGenjetRjetPtjetArea;
  if (h3dataGenjetRjetPtTrackPt) delete h3dataGenjetRjetPtTrackPt;
  if (h3dataGenjetRjetPtTrackEta) delete h3dataGenjetRjetPtTrackEta;
  if (h3dataGenjetRjetPtTrackPhi) delete h3dataGenjetRjetPtTrackPhi;
  if (h3dataGenjetRjetPtLeadingTrackPt) delete h3dataGenjetRjetPtLeadingTrackPt;

  // Delete cloned MC histograms
  if (h3simGenjetRjetPtjetEta) delete h3simGenjetRjetPtjetEta;
  if (h3simGenjetRjetPtjetPhi) delete h3simGenjetRjetPtjetPhi;
  if (h3simGenjetRjetEtajetPhi) delete h3simGenjetRjetEtajetPhi;
  if (h3simGenjetRjetPtjetNTracks) delete h3simGenjetRjetPtjetNTracks;
  if (h3simGenjetRjetPtjetArea) delete h3simGenjetRjetPtjetArea;
  if (h3simGenjetRjetPtTrackPt) delete h3simGenjetRjetPtTrackPt;
  if (h3simGenjetRjetPtTrackEta) delete h3simGenjetRjetPtTrackEta;
  if (h3simGenjetRjetPtTrackPhi) delete h3simGenjetRjetPtTrackPhi;
  if (h3simGenjetRjetPtLeadingTrackPt) delete h3simGenjetRjetPtLeadingTrackPt;

  // Delete cloned particle level histograms
  if (h3simGenpartjetRjetPtjetEta) delete h3simGenpartjetRjetPtjetEta;
  if (h3simGenpartjetRjetPtjetPhi) delete h3simGenpartjetRjetPtjetPhi;
  if (h3simGenpartjetRjetEtajetPhi) delete h3simGenpartjetRjetEtajetPhi;
  if (h3simGenpartjetRjetPtjetNTracks) delete h3simGenpartjetRjetPtjetNTracks;
  if (h3simGenpartjetRjetPtTrackPt) delete h3simGenpartjetRjetPtTrackPt;
  if (h3simGenpartjetRjetPtTrackEta) delete h3simGenpartjetRjetPtTrackEta;
  if (h3simGenpartjetRjetPtTrackPhi) delete h3simGenpartjetRjetPtTrackPhi;
  
  // Delete Normalized data histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hdataGenjetNormalizedEta[binJetPt][binJetR]) delete hdataGenjetNormalizedEta[binJetPt][binJetR];
      if (hdataGenjetNormalizedPhi[binJetPt][binJetR]) delete hdataGenjetNormalizedPhi[binJetPt][binJetR];
      if (hdataGenjetNormalizedNTracks[binJetPt][binJetR]) delete hdataGenjetNormalizedNTracks[binJetPt][binJetR];
      if (hdataGenjetNormalizedArea[binJetPt][binJetR]) delete hdataGenjetNormalizedArea[binJetPt][binJetR];
      if (hdataGenjetNormalizedTrackPt[binJetPt][binJetR]) delete hdataGenjetNormalizedTrackPt[binJetPt][binJetR];
      if (hdataGenjetNormalizedTrackEta[binJetPt][binJetR]) delete hdataGenjetNormalizedTrackEta[binJetPt][binJetR];
      if (hdataGenjetNormalizedTrackPhi[binJetPt][binJetR]) delete hdataGenjetNormalizedTrackPhi[binJetPt][binJetR];
      if (hdataGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]) delete hdataGenjetNormalizedLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete Normalized MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenjetNormalizedEta[binJetPt][binJetR]) delete hsimGenjetNormalizedEta[binJetPt][binJetR];
      if (hsimGenjetNormalizedPhi[binJetPt][binJetR]) delete hsimGenjetNormalizedPhi[binJetPt][binJetR];
      if (hsimGenjetNormalizedNTracks[binJetPt][binJetR]) delete hsimGenjetNormalizedNTracks[binJetPt][binJetR];
      if (hsimGenjetNormalizedArea[binJetPt][binJetR]) delete hsimGenjetNormalizedArea[binJetPt][binJetR];
      if (hsimGenjetNormalizedTrackPt[binJetPt][binJetR]) delete hsimGenjetNormalizedTrackPt[binJetPt][binJetR];
      if (hsimGenjetNormalizedTrackEta[binJetPt][binJetR]) delete hsimGenjetNormalizedTrackEta[binJetPt][binJetR];
      if (hsimGenjetNormalizedTrackPhi[binJetPt][binJetR]) delete hsimGenjetNormalizedTrackPhi[binJetPt][binJetR];
      if (hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]) delete hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR];
    }
  }

  // Delete Normalized MC histograms
  for (int binJetR = 0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    for (int binJetPt = 0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      if (hsimGenpartjetNormalizedEta[binJetPt][binJetR]) delete hsimGenpartjetNormalizedEta[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedPhi[binJetPt][binJetR]) delete hsimGenpartjetNormalizedPhi[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedNTracks[binJetPt][binJetR]) delete hsimGenpartjetNormalizedNTracks[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedArea[binJetPt][binJetR]) delete hsimGenpartjetNormalizedArea[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedTrackPt[binJetPt][binJetR]) delete hsimGenpartjetNormalizedTrackPt[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedTrackEta[binJetPt][binJetR]) delete hsimGenpartjetNormalizedTrackEta[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedTrackPhi[binJetPt][binJetR]) delete hsimGenpartjetNormalizedTrackPhi[binJetPt][binJetR];
      if (hsimGenpartjetNormalizedLeadingTrackPt[binJetPt][binJetR]) delete hsimGenpartjetNormalizedLeadingTrackPt[binJetPt][binJetR];
    }
  }
}

int JetAnalysis::LoadDataGeneralQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";

  h3dataGenjetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta", taskJetQA.Data())));
  h3dataGenjetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
  h3dataGenjetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi", taskJetQA.Data())));
  h3dataGenjetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks", taskJetQA.Data())));
  h3dataGenjetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area", taskJetQA.Data())));
  h3dataGenjetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt", taskJetQA.Data())));
  h3dataGenjetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta", taskJetQA.Data())));
  h3dataGenjetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi", taskJetQA.Data())));
  h3dataGenjetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_leadingtrack_pt", taskJetQA.Data())));

  return 1;
}

int JetAnalysis::LoadSimGeneralQA(TString rootSim, bool dopartLevel = false) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  TString taskJetQA = "jet-finder-charged-qa";

  h3simGenjetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_eta", taskJetQA.Data())));
  h3simGenjetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
  h3simGenjetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_eta_jet_phi", taskJetQA.Data())));
  h3simGenjetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_ntracks", taskJetQA.Data())));
  h3simGenjetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_area", taskJetQA.Data())));
  h3simGenjetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_pt", taskJetQA.Data())));
  h3simGenjetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_eta", taskJetQA.Data())));
  h3simGenjetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_track_phi", taskJetQA.Data())));
  h3simGenjetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_leadingtrack_pt", taskJetQA.Data())));

  if (dopartLevel) {
    h3simGenpartjetRjetPtjetEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_eta_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtjetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_jet_pt_jet_phi", taskJetQA.Data())));
    h3simGenpartjetRjetEtajetPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_eta_part_jet_phi_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtjetNTracks = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_ntracks_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtjetArea = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_jet_area_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_pt_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_eta_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_track_phi_part", taskJetQA.Data())));
    h3simGenpartjetRjetPtLeadingTrackPt = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_r_part_jet_pt_part_leadingtrack_pt_part", taskJetQA.Data())));
  }

  std::cout << "Load completed General Jet QA MC" << std::endl;
  return 1;
}

void JetAnalysis::InitHistogramForNormalizationGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataGenjetPt[binJetR] = new TH1F(Form("hdataGenjetPt_%d", binJetR), "", h3dataGenjetRjetPtjetEta->GetNbinsY(), h3dataGenjetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3dataGenjetRjetPtjetEta->GetNbinsY()));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataGenjetEta[binJetPt][binJetR] = new TH1F(Form("hdataGenjetEta_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtjetEta->GetNbinsZ(), h3dataGenjetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtjetEta->GetNbinsZ()));
      hdataGenjetPhi[binJetPt][binJetR] = new TH1F(Form("hdataGenjetPhi_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtjetPhi->GetNbinsZ(), h3dataGenjetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtjetPhi->GetNbinsZ()));
      hdataGenjetNTracks[binJetPt][binJetR] = new TH1F(Form("hdataGenjetNTracks_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtjetNTracks->GetNbinsZ(), h3dataGenjetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtjetNTracks->GetNbinsZ()));
      hdataGenjetArea[binJetPt][binJetR] = new TH1F(Form("hdataGenjetArea_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtjetArea->GetNbinsZ(), h3dataGenjetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtjetArea->GetNbinsZ()));
      hdataGenjetTrackPt[binJetPt][binJetR] = new TH1F(Form("hdataGenjetTrackPt_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtTrackPt->GetNbinsZ(), h3dataGenjetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtTrackPt->GetNbinsZ()));
      hdataGenjetTrackEta[binJetPt][binJetR] = new TH1F(Form("hdataGenjetTrackEta_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtTrackEta->GetNbinsZ(), h3dataGenjetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtTrackEta->GetNbinsZ()));
      hdataGenjetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hdataGenjetTrackPhi_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtTrackPhi->GetNbinsZ(), h3dataGenjetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtTrackPhi->GetNbinsZ()));
      hdataGenjetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hdataGenjetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3dataGenjetRjetPtLeadingTrackPt->GetNbinsZ(), h3dataGenjetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3dataGenjetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3dataGenjetRjetPtLeadingTrackPt->GetNbinsZ()));
    }
  }
}

void JetAnalysis::InitHistogramForNormalizationGeneralQAMC(bool dopartLevel = false) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimGenjetPt[binJetR] = new TH1F(Form("hsimGenjetPt_%d", binJetR), "", h3simGenjetRjetPtjetEta->GetNbinsY(), h3simGenjetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3simGenjetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3simGenjetRjetPtjetEta->GetNbinsY()));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {

      hsimGenjetEta[binJetPt][binJetR] = new TH1F(Form("hsimGenjetEta_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtjetEta->GetNbinsZ(), h3simGenjetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtjetEta->GetNbinsZ()));

      hsimGenjetPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenjetPhi_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtjetPhi->GetNbinsZ(), h3simGenjetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtjetPhi->GetNbinsZ()));
      hsimGenjetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimGenjetNTracks_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtjetNTracks->GetNbinsZ(), h3simGenjetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtjetNTracks->GetNbinsZ()));
      hsimGenjetArea[binJetPt][binJetR] = new TH1F(Form("hsimGenjetArea_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtjetArea->GetNbinsZ(), h3simGenjetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtjetArea->GetNbinsZ()));
      hsimGenjetTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenjetTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtTrackPt->GetNbinsZ(), h3simGenjetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtTrackPt->GetNbinsZ()));
      hsimGenjetTrackEta[binJetPt][binJetR] = new TH1F(Form("hsimGenjetTrackEta_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtTrackEta->GetNbinsZ(), h3simGenjetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtTrackEta->GetNbinsZ()));
      hsimGenjetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenjetTrackPhi_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtTrackPhi->GetNbinsZ(), h3simGenjetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtTrackPhi->GetNbinsZ()));
      hsimGenjetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenjetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenjetRjetPtLeadingTrackPt->GetNbinsZ(), h3simGenjetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenjetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3simGenjetRjetPtLeadingTrackPt->GetNbinsZ()));
    }
  }
  if (dopartLevel) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenpartjetPt[binJetR] = new TH1F(Form("hsimGenpartjetPt_%d", binJetR), "", h3simGenpartjetRjetPtjetEta->GetNbinsY(), h3simGenpartjetRjetPtjetEta->GetYaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtjetEta->GetYaxis()->GetBinUpEdge(h3simGenpartjetRjetPtjetEta->GetNbinsY()));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimGenpartjetEta[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetEta_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtjetEta->GetNbinsZ(), h3simGenpartjetRjetPtjetEta->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtjetEta->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtjetEta->GetNbinsZ()));
        hsimGenpartjetPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetPhi_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtjetPhi->GetNbinsZ(), h3simGenpartjetRjetPtjetPhi->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtjetPhi->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtjetPhi->GetNbinsZ()));
        hsimGenpartjetNTracks[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetNTracks_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtjetNTracks->GetNbinsZ(), h3simGenpartjetRjetPtjetNTracks->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtjetNTracks->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtjetNTracks->GetNbinsZ()));
        hsimGenpartjetArea[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetArea_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtjetArea->GetNbinsZ(), h3simGenpartjetRjetPtjetArea->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtjetArea->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtjetArea->GetNbinsZ()));
        hsimGenpartjetTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtTrackPt->GetNbinsZ(), h3simGenpartjetRjetPtTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtTrackPt->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtTrackPt->GetNbinsZ()));
        hsimGenpartjetTrackEta[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetTrackEta_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtTrackEta->GetNbinsZ(), h3simGenpartjetRjetPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtTrackEta->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtTrackEta->GetNbinsZ()));
        hsimGenpartjetTrackPhi[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetTrackPhi_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtTrackPhi->GetNbinsZ(), h3simGenpartjetRjetPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtTrackPhi->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtTrackPhi->GetNbinsZ()));
        hsimGenpartjetLeadingTrackPt[binJetPt][binJetR] = new TH1F(Form("hsimGenpartjetLeadingTrackPt_%d_%d", binJetPt, binJetR), "", h3simGenpartjetRjetPtLeadingTrackPt->GetNbinsZ(), h3simGenpartjetRjetPtLeadingTrackPt->GetZaxis()->GetBinLowEdge(1), h3simGenpartjetRjetPtLeadingTrackPt->GetZaxis()->GetBinUpEdge(h3simGenpartjetRjetPtLeadingTrackPt->GetNbinsZ()));
      }
    }
  }
}

void JetAnalysis::ProjectionHistGeneralQAData() {
  TH1F *projJetPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetEta->ProjectionY("projJetPt", 1, h3dataGenjetRjetPtjetEta->GetNbinsX(), 1, h3dataGenjetRjetPtjetEta->GetNbinsZ()));
  TH1F *projJetEta = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3dataGenjetRjetPtjetEta->GetNbinsX(), 1, h3dataGenjetRjetPtjetEta->GetNbinsY()));
  TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3dataGenjetRjetPtjetPhi->GetNbinsX(), 1, h3dataGenjetRjetPtjetPhi->GetNbinsY()));
  TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3dataGenjetRjetPtjetNTracks->GetNbinsX(), 1, h3dataGenjetRjetPtjetNTracks->GetNbinsY()));
  TH1F *projJetArea = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3dataGenjetRjetPtjetArea->GetNbinsX(), 1, h3dataGenjetRjetPtjetArea->GetNbinsY()));
  TH1F *projJetTrackPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtTrackPt->ProjectionZ("projJetTrackPt", 1, h3dataGenjetRjetPtTrackPt->GetNbinsX(), 1, h3dataGenjetRjetPtTrackPt->GetNbinsY()));
  TH1F *projJetTrackEta = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataGenjetRjetPtTrackEta->GetNbinsX(), 1, h3dataGenjetRjetPtTrackEta->GetNbinsY()));
  TH1F *projJetTrackPhi = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataGenjetRjetPtTrackPhi->GetNbinsX(), 1, h3dataGenjetRjetPtTrackPhi->GetNbinsY()));
  TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3dataGenjetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3dataGenjetRjetPtLeadingTrackPt->GetNbinsY()));

  hdataGenjetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
  hdataGenjetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
  hdataGenjetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
  hdataGenjetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
  hdataGenjetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
  hdataGenjetTrackPt[0][0] = reinterpret_cast<TH1F*>(projJetTrackPt->Clone());
  hdataGenjetTrackEta[0][0] = reinterpret_cast<TH1F*>(projJetTrackEta->Clone());
  hdataGenjetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projJetTrackPhi->Clone());
  hdataGenjetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());

  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // jet pt
    int leftbinJetRForJetPt = h3dataGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPt = h3dataGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3dataGenjetRjetPtjetEta->GetNbinsZ()));
    hdataGenjetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());
  
    // jet eta
    int leftbinJetRForJetEta = h3dataGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetEta = h3dataGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3dataGenjetRjetPtjetEta->GetNbinsZ()));
    hdataGenjetEta[0][binJetR]->Add(projJetRRangeJetEta);

    // jet phi
    int leftbinJetRForJetPhi = h3dataGenjetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPhi = h3dataGenjetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3dataGenjetRjetPtjetPhi->GetNbinsZ()));
    hdataGenjetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

    // number of tracks
    int leftbinJetRForJetNTracks = h3dataGenjetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetNTracks = h3dataGenjetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3dataGenjetRjetPtjetNTracks->GetNbinsZ()));
    hdataGenjetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

    // jet area
    int leftbinJetRForJetArea = h3dataGenjetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetArea = h3dataGenjetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3dataGenjetRjetPtjetArea->GetNbinsZ()));
    hdataGenjetArea[0][binJetR]->Add(projJetRRangeJetArea);

    // track pt
    int leftbinJetRForTrackPt = h3dataGenjetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPt = h3dataGenjetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3dataGenjetRjetPtjetArea->GetNbinsZ()));
    hdataGenjetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

    // track eta
    int leftbinJetRForTrackEta = h3dataGenjetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackEta = h3dataGenjetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3dataGenjetRjetPtjetArea->GetNbinsZ()));
    hdataGenjetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

    // track phi
    int leftbinJetRForTrackPhi = h3dataGenjetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPhi = h3dataGenjetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3dataGenjetRjetPtjetArea->GetNbinsZ()));
    hdataGenjetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

    // leading track pt
    int leftbinJetRForLeadingTrackPt = h3dataGenjetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForLeadingTrackPt = h3dataGenjetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3dataGenjetRjetPtjetArea->GetNbinsZ()));
    hdataGenjetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
      // jet eta
      int leftbinJetPtForJetEta = h3dataGenjetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetEta = h3dataGenjetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJetEta_%d_%d", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
      hdataGenjetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
      hdataGenjetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

      // jet phi
      int leftbinJetPtForJetPhi = h3dataGenjetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetPhi = h3dataGenjetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetPhi->ProjectionZ(Form("projJetPtRangeJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
      hdataGenjetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
      hdataGenjetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

      // number of tracks
      int leftbinJetPtForJetNTracks = h3dataGenjetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetNTracks = h3dataGenjetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
      hdataGenjetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
      hdataGenjetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

      // jet area
      int leftbinJetPtForJetArea = h3dataGenjetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetArea = h3dataGenjetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetR, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
      hdataGenjetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
      hdataGenjetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

      // track pt
      int leftbinJetPtForTrackPt = h3dataGenjetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPt = h3dataGenjetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
      hdataGenjetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
      hdataGenjetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

      // track eta
      int leftbinJetPtForTrackEta = h3dataGenjetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackEta = h3dataGenjetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
      hdataGenjetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
      hdataGenjetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

      // track phi
      int leftbinJetPtForTrackPhi = h3dataGenjetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPhi = h3dataGenjetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
      hdataGenjetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
      hdataGenjetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      // leading track pt
      int leftbinJetPtForLeadingTrackPt = h3dataGenjetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForLeadingTrackPt = h3dataGenjetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3dataGenjetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
      hdataGenjetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
      hdataGenjetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
    }
  }
}

void JetAnalysis::ProjectionHistGeneralQAMC(bool dopartLevel= false) {

  TH1F *projJetPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetEta->ProjectionY("projJetPt", 1, h3simGenjetRjetPtjetEta->GetNbinsX(), 1, h3simGenjetRjetPtjetEta->GetNbinsZ()));
  TH1F *projJetEta = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3simGenjetRjetPtjetEta->GetNbinsX(), 1, h3simGenjetRjetPtjetEta->GetNbinsY()));
  TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3simGenjetRjetPtjetPhi->GetNbinsX(), 1, h3simGenjetRjetPtjetPhi->GetNbinsY()));
  TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3simGenjetRjetPtjetNTracks->GetNbinsX(), 1, h3simGenjetRjetPtjetNTracks->GetNbinsY()));
  TH1F *projJetArea = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3simGenjetRjetPtjetArea->GetNbinsX(), 1, h3simGenjetRjetPtjetArea->GetNbinsY()));
  TH1F *projTrackPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackPt->ProjectionZ("projTrackPt", 1, h3simGenjetRjetPtTrackPt->GetNbinsX(), 1, h3simGenjetRjetPtTrackPt->GetNbinsY()));
  TH1F *projTrackEta = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackEta->ProjectionZ("projTrackEta", 1, h3simGenjetRjetPtTrackEta->GetNbinsX(), 1, h3simGenjetRjetPtTrackEta->GetNbinsY()));
  TH1F *projTrackPhi = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackPhi->ProjectionZ("projTrackPhi", 1, h3simGenjetRjetPtTrackPhi->GetNbinsX(), 1, h3simGenjetRjetPtTrackPhi->GetNbinsY()));
  TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3simGenjetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3simGenjetRjetPtLeadingTrackPt->GetNbinsY()));

  hsimGenjetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
  hsimGenjetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
  hsimGenjetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
  hsimGenjetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
  hsimGenjetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
  hsimGenjetTrackPt[0][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
  hsimGenjetTrackEta[0][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
  hsimGenjetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
  hsimGenjetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());


  for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    // jet pt
    int leftbinJetRForJetPt = h3simGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPt = h3simGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3simGenjetRjetPtjetEta->GetNbinsZ()));
    hsimGenjetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

    // jet eta
    int leftbinJetRForJetEta = h3simGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetEta = h3simGenjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3simGenjetRjetPtjetEta->GetNbinsZ()));
    hsimGenjetEta[0][binJetR]->Add(projJetRRangeJetEta);

    // jet phi
    int leftbinJetRForJetPhi = h3simGenjetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetPhi = h3simGenjetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3simGenjetRjetPtjetPhi->GetNbinsZ()));
    hsimGenjetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

    // number of tracks
    int leftbinJetRForJetNTracks = h3simGenjetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetNTracks = h3simGenjetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3simGenjetRjetPtjetNTracks->GetNbinsZ()));
    hsimGenjetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

    // jet area
    int leftbinJetRForJetArea = h3simGenjetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForJetArea = h3simGenjetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3simGenjetRjetPtjetArea->GetNbinsZ()));
    hsimGenjetArea[0][binJetR]->Add(projJetRRangeJetArea);

    // track pt
    int leftbinJetRForTrackPt = h3simGenjetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPt = h3simGenjetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackPt->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3simGenjetRjetPtTrackPt->GetNbinsZ()));
    hsimGenjetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

    // track eta
    int leftbinJetRForTrackEta = h3simGenjetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackEta = h3simGenjetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackEta->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3simGenjetRjetPtTrackEta->GetNbinsZ()));
    hsimGenjetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

    // track phi
    int leftbinJetRForTrackPhi = h3simGenjetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForTrackPhi = h3simGenjetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackPhi->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3simGenjetRjetPtTrackPhi->GetNbinsZ()));
    hsimGenjetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

    // leading track pt
    int leftbinJetRForLeadingTrackPt = h3simGenjetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
    int rightbinJetRForLeadingTrackPt = h3simGenjetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
    TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3simGenjetRjetPtLeadingTrackPt->GetNbinsZ()));
    hsimGenjetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

    for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      // jet eta
      int leftbinJetPtForJetEta = h3simGenjetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetEta = h3simGenjetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJeEta_%d_%d)", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
      hsimGenjetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
      hsimGenjetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

      // jet phi
      int leftbinJetPtForJetPhi = h3simGenjetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetPhi = h3simGenjetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetPhi->ProjectionZ(Form("projJetPtRagneJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
      hsimGenjetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
      hsimGenjetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

      // number of tracks
      int leftbinJetPtForJetNTracks = h3simGenjetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetNTracks = h3simGenjetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
      hsimGenjetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
      hsimGenjetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

      // jet area
      int leftbinJetPtForJetArea = h3simGenjetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForJetArea = h3simGenjetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3simGenjetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetPt, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
      hsimGenjetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
      hsimGenjetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

      // track pt
      int leftbinJetPtForTrackPt = h3simGenjetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPt = h3simGenjetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
      hsimGenjetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
      hsimGenjetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

      // track eta
      int leftbinJetPtForTrackEta = h3simGenjetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackEta = h3simGenjetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
      hsimGenjetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
      hsimGenjetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

      // track phi
      int leftbinJetPtForTrackPhi = h3simGenjetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForTrackPhi = h3simGenjetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenjetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
      hsimGenjetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
      hsimGenjetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

      // leading track pt
      int leftbinJetPtForLeadingTrackPt = h3simGenjetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
      int rightbinJetPtForLeadingTrackPt = h3simGenjetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
      TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenjetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
      hsimGenjetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
      hsimGenjetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
    }
  }

  if (dopartLevel) {
    TH1F *projJetPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetEta->ProjectionY("projJetPt", 1, h3simGenpartjetRjetPtjetEta->GetNbinsX(), 1, h3simGenpartjetRjetPtjetEta->GetNbinsZ()));
    TH1F *projJetEta = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetEta->ProjectionZ("projJetEta", 1, h3simGenpartjetRjetPtjetEta->GetNbinsX(), 1, h3simGenpartjetRjetPtjetEta->GetNbinsY()));
    TH1F *projJetPhi = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetPhi->ProjectionZ("projJetPhi", 1, h3simGenpartjetRjetPtjetPhi->GetNbinsX(), 1, h3simGenpartjetRjetPtjetPhi->GetNbinsY()));
    TH1F *projJetNTracks = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetNTracks->ProjectionZ("projJetNTracks", 1, h3simGenpartjetRjetPtjetNTracks->GetNbinsX(), 1, h3simGenpartjetRjetPtjetNTracks->GetNbinsY()));
    TH1F *projJetArea = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetArea->ProjectionZ("projJetArea", 1, h3simGenpartjetRjetPtjetArea->GetNbinsX(), 1, h3simGenpartjetRjetPtjetArea->GetNbinsY()));
    TH1F *projTrackPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackPt->ProjectionZ("projTrackPt", 1, h3simGenpartjetRjetPtTrackPt->GetNbinsX(), 1, h3simGenpartjetRjetPtTrackPt->GetNbinsY()));
    TH1F *projTrackEta = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackEta->ProjectionZ("projTrackEta", 1, h3simGenpartjetRjetPtTrackEta->GetNbinsX(), 1, h3simGenpartjetRjetPtTrackEta->GetNbinsY()));
    TH1F *projTrackPhi = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackPhi->ProjectionZ("projTrackPhi", 1, h3simGenpartjetRjetPtTrackPhi->GetNbinsX(), 1, h3simGenpartjetRjetPtTrackPhi->GetNbinsY()));
    TH1F *projLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtLeadingTrackPt->ProjectionZ("projLeadingTrackPt", 1, h3simGenpartjetRjetPtLeadingTrackPt->GetNbinsX(), 1, h3simGenpartjetRjetPtLeadingTrackPt->GetNbinsY()));

    hsimGenpartjetPt[0] = reinterpret_cast<TH1F*>(projJetPt->Clone());
    hsimGenpartjetEta[0][0] = reinterpret_cast<TH1F*>(projJetEta->Clone());
    hsimGenpartjetPhi[0][0] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
    hsimGenpartjetNTracks[0][0] = reinterpret_cast<TH1F*>(projJetNTracks->Clone());
    hsimGenpartjetArea[0][0] = reinterpret_cast<TH1F*>(projJetArea->Clone());
    hsimGenpartjetTrackPt[0][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
    hsimGenpartjetTrackEta[0][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
    hsimGenpartjetTrackPhi[0][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
    hsimGenpartjetLeadingTrackPt[0][0] = reinterpret_cast<TH1F*>(projLeadingTrackPt->Clone());
    for (int binJetR =1; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      // jet pt
      int leftbinJetRForJetPt = h3simGenpartjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPt = h3simGenpartjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetEta->ProjectionY(Form("projJetRRangeJetPt_%d", binJetR), leftbinJetRForJetPt, rightbinJetRForJetPt, 1, h3simGenpartjetRjetPtjetEta->GetNbinsZ()));
      hsimGenpartjetPt[binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPt->Clone());

      // jet eta
      int leftbinJetRForJetEta = h3simGenpartjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetEta = h3simGenpartjetRjetPtjetEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetEta = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetEta->ProjectionZ(Form("projJetRRangeJetEta_%d", binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, 1, h3simGenpartjetRjetPtjetEta->GetNbinsZ()));
      hsimGenpartjetEta[0][binJetR]->Add(projJetRRangeJetEta);

      // jet phi
      int leftbinJetRForJetPhi = h3simGenpartjetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetPhi = h3simGenpartjetRjetPtjetPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetPhi->ProjectionZ(Form("projJetRRangeJetPhi_%d", binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, 1, h3simGenpartjetRjetPtjetPhi->GetNbinsZ()));
      hsimGenpartjetPhi[0][binJetR]->Add(projJetRRangeJetPhi);

      // number of tracks
      int leftbinJetRForJetNTracks = h3simGenpartjetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetNTracks = h3simGenpartjetRjetPtjetNTracks->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetNTracks->ProjectionZ(Form("projJetRRangeJetNTracks_%d", binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, 1, h3simGenpartjetRjetPtjetNTracks->GetNbinsZ()));
      hsimGenpartjetNTracks[0][binJetR]->Add(projJetRRangeJetNTracks);

      // jet area
      int leftbinJetRForJetArea = h3simGenpartjetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForJetArea = h3simGenpartjetRjetPtjetArea->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeJetArea = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetArea->ProjectionZ(Form("projJetRRangeJetArea_%d", binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, 1, h3simGenpartjetRjetPtjetArea->GetNbinsZ()));
      hsimGenpartjetArea[0][binJetR]->Add(projJetRRangeJetArea);

      // track pt
      int leftbinJetRForTrackPt = h3simGenpartjetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPt = h3simGenpartjetRjetPtTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackPt->ProjectionZ(Form("projJetRRangeTrackPt_%d", binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, 1, h3simGenpartjetRjetPtTrackPt->GetNbinsZ()));
      hsimGenpartjetTrackPt[0][binJetR]->Add(projJetRRangeTrackPt);

      // track eta
      int leftbinJetRForTrackEta = h3simGenpartjetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackEta = h3simGenpartjetRjetPtTrackEta->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackEta->ProjectionZ(Form("projJetRRangeTrackEta_%d", binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, 1, h3simGenpartjetRjetPtTrackEta->GetNbinsZ()));
      hsimGenpartjetTrackEta[0][binJetR]->Add(projJetRRangeTrackEta);

      // track phi
      int leftbinJetRForTrackPhi = h3simGenpartjetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForTrackPhi = h3simGenpartjetRjetPtTrackPhi->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackPhi->ProjectionZ(Form("projJetRRangeTrackPhi_%d", binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, 1, h3simGenpartjetRjetPtTrackPhi->GetNbinsZ()));
      hsimGenpartjetTrackPhi[0][binJetR]->Add(projJetRRangeTrackPhi);

      // leading track pt
      int leftbinJetRForLeadingTrackPt = h3simGenpartjetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR-1]);
      int rightbinJetRForLeadingTrackPt = h3simGenpartjetRjetPtLeadingTrackPt->GetXaxis()->FindBin(GeneralJet::binsJetR[binJetR]);
      TH1F* projJetRRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetRRangeLeadingTrackPt_%d", binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, 1, h3simGenpartjetRjetPtLeadingTrackPt->GetNbinsZ()));
      hsimGenpartjetLeadingTrackPt[0][binJetR]->Add(projJetRRangeLeadingTrackPt);

      for (int binJetPt =1; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        // jet eta
        int leftbinJetPtForJetEta = h3simGenpartjetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetEta = h3simGenpartjetRjetPtjetEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetEta = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetEta->ProjectionZ(Form("projJetPtRangeJetRRangeJetEta_%d_%d", binJetPt, binJetR), leftbinJetRForJetEta, rightbinJetRForJetEta, leftbinJetPtForJetEta, rightbinJetPtForJetEta));
        hsimGenpartjetEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetEta->Clone());
        hsimGenpartjetEta[binJetPt][0]->Add(projJetRRangeJetPtRangeJetEta);

        // jet phi
        int leftbinJetPtForJetPhi = h3simGenpartjetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetPhi = h3simGenpartjetRjetPtjetPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetPhi = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetPhi->ProjectionZ(Form("projJetPtRangeJetRRangeJetPhi_%d_%d", binJetPt, binJetR), leftbinJetRForJetPhi, rightbinJetRForJetPhi, leftbinJetPtForJetPhi, rightbinJetPtForJetPhi));
        hsimGenpartjetPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetPhi->Clone());
        hsimGenpartjetPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeJetPhi);

        // number of tracks
        int leftbinJetPtForJetNTracks = h3simGenpartjetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetNTracks = h3simGenpartjetRjetPtjetNTracks->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetNTracks = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetNTracks->ProjectionZ(Form("projJetPtRangeJetRRangeJetNTracks_%d_%d", binJetPt, binJetR), leftbinJetRForJetNTracks, rightbinJetRForJetNTracks, leftbinJetPtForJetNTracks, rightbinJetPtForJetNTracks));
        hsimGenpartjetNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetNTracks->Clone());
        hsimGenpartjetNTracks[binJetPt][0]->Add(projJetRRangeJetPtRangeJetNTracks);

        // jet area
        int leftbinJetPtForJetArea = h3simGenpartjetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForJetArea = h3simGenpartjetRjetPtjetArea->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeJetArea = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtjetArea->ProjectionZ(Form("projJetPtRangeJetRRangeJetArea_%d_%d", binJetPt, binJetR), leftbinJetRForJetArea, rightbinJetRForJetArea, leftbinJetPtForJetArea, rightbinJetPtForJetArea));
        hsimGenpartjetArea[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeJetArea->Clone());
        hsimGenpartjetArea[binJetPt][0]->Add(projJetRRangeJetPtRangeJetArea);

        // track pt
        int leftbinJetPtForTrackPt = h3simGenpartjetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackPt = h3simGenpartjetRjetPtTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPt, rightbinJetRForTrackPt, leftbinJetPtForTrackPt, rightbinJetPtForTrackPt));
        hsimGenpartjetTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPt->Clone());
        hsimGenpartjetTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPt);

        // track eta
        int leftbinJetPtForTrackEta = h3simGenpartjetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackEta = h3simGenpartjetRjetPtTrackEta->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackEta->ProjectionZ(Form("projJetPtRangeJetRRangeTrackEta_%d_%d", binJetPt, binJetR), leftbinJetRForTrackEta, rightbinJetRForTrackEta, leftbinJetPtForTrackEta, rightbinJetPtForTrackEta));
        hsimGenpartjetTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackEta->Clone());
        hsimGenpartjetTrackEta[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackEta);

        // track phi
        int leftbinJetPtForTrackPhi = h3simGenpartjetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForTrackPhi = h3simGenpartjetRjetPtTrackPhi->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtTrackPhi->ProjectionZ(Form("projJetPtRangeJetRRangeTrackPhi_%d_%d", binJetPt, binJetR), leftbinJetRForTrackPhi, rightbinJetRForTrackPhi, leftbinJetPtForTrackPhi, rightbinJetPtForTrackPhi));
        hsimGenpartjetTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeTrackPhi->Clone());
        hsimGenpartjetTrackPhi[binJetPt][0]->Add(projJetRRangeJetPtRangeTrackPhi);

        // leading track pt
        int leftbinJetPtForLeadingTrackPt = h3simGenpartjetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt-1]);
        int rightbinJetPtForLeadingTrackPt = h3simGenpartjetRjetPtLeadingTrackPt->GetYaxis()->FindBin(GeneralJet::binsJetPt[binJetPt]);
        TH1F* projJetRRangeJetPtRangeLeadingTrackPt = reinterpret_cast<TH1F*> (h3simGenpartjetRjetPtLeadingTrackPt->ProjectionZ(Form("projJetPtRangeJetRRangeLeadingTrackPt_%d_%d", binJetPt, binJetR), leftbinJetRForLeadingTrackPt, rightbinJetRForLeadingTrackPt, leftbinJetPtForLeadingTrackPt, rightbinJetPtForLeadingTrackPt));
        hsimGenpartjetLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*> (projJetRRangeJetPtRangeLeadingTrackPt->Clone());
        hsimGenpartjetLeadingTrackPt[binJetPt][0]->Add(projJetRRangeJetPtRangeLeadingTrackPt);
      }
    }
  }
}

void JetAnalysis::CloneNormalizedHistogramGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataGenjetNormalizedPt[binJetR] = reinterpret_cast<TH1F*>(hdataGenjetPt[binJetR]->Clone(Form("hdataGenjetNormalizedPt_%d", binJetR)));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataGenjetNormalizedEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetEta[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedEta_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetPhi[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedPhi_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetNTracks[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedNTracks_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedArea[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetArea[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedArea_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetTrackPt[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedTrackPt_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetTrackEta[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedTrackEta_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetTrackPhi[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedTrackPhi_%d_%d", binJetPt, binJetR)));
      hdataGenjetNormalizedLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hdataGenjetLeadingTrackPt[binJetPt][binJetR]->Clone(Form("hdataGenjetNormalizedLeadingTrackPt_%d_%d", binJetPt, binJetR)));
    }
  }
}

void JetAnalysis::CloneNormalizedHistogramGeneralQAMC(bool dopartLevel) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimGenjetNormalizedPt[binJetR] = reinterpret_cast<TH1F*>(hsimGenjetPt[binJetR]->Clone(Form("hsimGenjetNormalizedPt_%d", binJetR)));
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimGenjetNormalizedEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetEta[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedEta_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetPhi[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedPhi_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetNTracks[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedNTracks_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedArea[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetArea[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedArea_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedTrackPt_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetTrackEta[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedTrackEta_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetTrackPhi[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedTrackPhi_%d_%d", binJetPt, binJetR)));
      hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenjetLeadingTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenjetNormalizedLeadingTrackPt_%d_%d", binJetPt, binJetR)));
    }
  }
  if (dopartLevel) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenpartjetNormalizedPt[binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetPt[binJetR]->Clone(Form("hsimGenpartjetNormalizedPt_%d", binJetR)));
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimGenpartjetNormalizedEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetEta[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedEta_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetPhi[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedPhi_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedNTracks[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetNTracks[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedNTracks_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedArea[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetArea[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedArea_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedTrackPt_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedTrackEta[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetTrackEta[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedTrackEta_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedTrackPhi[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetTrackPhi[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedTrackPhi_%d_%d", binJetPt, binJetR)));
        hsimGenpartjetNormalizedLeadingTrackPt[binJetPt][binJetR] = reinterpret_cast<TH1F*>(hsimGenpartjetLeadingTrackPt[binJetPt][binJetR]->Clone(Form("hsimGenpartjetNormalizedLeadingTrackPt_%d_%d", binJetPt, binJetR)));
      }
    }
  }
}

void JetAnalysis::NormalizedHistogramGeneralQAData() {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hdataGenjetNormalizedPt[binJetR]->Scale(1. / hdataGenjetNormalizedPt[binJetR]->Integral());
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hdataGenjetNormalizedEta[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedEta[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedPhi[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedPhi[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedNTracks[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedNTracks[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedArea[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedArea[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedTrackPt[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedTrackPt[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedTrackEta[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedTrackEta[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedTrackPhi[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedTrackPhi[binJetPt][binJetR]->Integral());
      hdataGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Scale(1. / hdataGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Integral());
    }
  }
}

void JetAnalysis::NormalizedHistogramGeneralQAMC(bool dopartLevel=false) {
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
    hsimGenjetNormalizedPt[binJetR]->Scale(1. / hsimGenjetNormalizedPt[binJetR]->GetEntries());
    for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
      hsimGenjetNormalizedEta[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedEta[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedPhi[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedPhi[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedNTracks[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedNTracks[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedArea[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedArea[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedTrackPt[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedTrackEta[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedTrackEta[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedTrackPhi[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedTrackPhi[binJetPt][binJetR]->Integral());
      hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Integral());
    }
  }
  if (dopartLevel) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR+1; binJetR++) {
      hsimGenpartjetNormalizedPt[binJetR]->Scale(1. / hsimGenpartjetNormalizedPt[binJetR]->Integral());
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
        hsimGenpartjetNormalizedEta[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedEta[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedPhi[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedPhi[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedNTracks[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedNTracks[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedArea[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedArea[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedTrackPt[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedTrackEta[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedTrackEta[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedTrackPhi[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedTrackPhi[binJetPt][binJetR]->Integral());
        hsimGenpartjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Scale(1. / hsimGenpartjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Integral());
      }
    }
  }
}

void JetAnalysis::SaveHistogramGeneralQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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
      hdataGenjetPt[binJetR]->Write();
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hdataGenjetEta[binJetPt][binJetR]->Write();
        hdataGenjetPhi[binJetPt][binJetR]->Write();
        hdataGenjetNTracks[binJetPt][binJetR]->Write();
        hdataGenjetArea[binJetPt][binJetR]->Write();
        hdataGenjetTrackPt[binJetPt][binJetR]->Write();
        hdataGenjetTrackEta[binJetPt][binJetR]->Write();
        hdataGenjetTrackPhi[binJetPt][binJetR]->Write();
        hdataGenjetLeadingTrackPt[binJetPt][binJetR]->Write();

        hdataGenjetNormalizedEta[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedPhi[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedNTracks[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedArea[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedTrackPt[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedTrackEta[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedTrackPhi[binJetPt][binJetR]->Write();
        hdataGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Write();
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
      hsimGenjetPt[binJetR]->Write();
      hsimGenjetNormalizedPt[binJetR]->Write();
      if (dopartLevel) {
        hsimGenpartjetPt[binJetR]->Write();
        hsimGenpartjetNormalizedPt[binJetR]->Write();
      }
      for (int binJetPt =0; binJetPt < GeneralJet::nBinsJetPt+1; binJetPt++) {
        hsimGenjetEta[binJetPt][binJetR]->Write();
        hsimGenjetPhi[binJetPt][binJetR]->Write();
        hsimGenjetNTracks[binJetPt][binJetR]->Write();
        hsimGenjetArea[binJetPt][binJetR]->Write();
        hsimGenjetTrackPt[binJetPt][binJetR]->Write();
        hsimGenjetTrackEta[binJetPt][binJetR]->Write();
        hsimGenjetTrackPhi[binJetPt][binJetR]->Write();
        hsimGenjetLeadingTrackPt[binJetPt][binJetR]->Write();

        hsimGenjetNormalizedEta[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedPhi[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedNTracks[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedArea[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedTrackPt[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedTrackEta[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedTrackPhi[binJetPt][binJetR]->Write();
        hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Write();

        if (dopartLevel) {
          hsimGenpartjetEta[binJetPt][binJetR]->Write();
          hsimGenpartjetPhi[binJetPt][binJetR]->Write();
          hsimGenpartjetNTracks[binJetPt][binJetR]->Write();
          hsimGenpartjetArea[binJetPt][binJetR]->Write();
          hsimGenpartjetTrackPt[binJetPt][binJetR]->Write();
          hsimGenpartjetTrackEta[binJetPt][binJetR]->Write();
          hsimGenpartjetTrackPhi[binJetPt][binJetR]->Write();
          hsimGenpartjetLeadingTrackPt[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedEta[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedPhi[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedNTracks[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedArea[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedTrackPt[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedTrackEta[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedTrackPhi[binJetPt][binJetR]->Write();
          hsimGenpartjetNormalizedLeadingTrackPt[binJetPt][binJetR]->Write();
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

void JetAnalysis::DrawDataGenJetPt(bool doLog = true, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenjetNormalizedPt[binJetR], ""});
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], " #it{p}_{T}^{jet}", "1/#it{N_{jet}} d#it{N_{jet}}/d#it{p}_{T}^{jet}");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jetmomentum_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

// Data
void JetAnalysis::DrawDataGenJetEta(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenjetNormalizedEta[binJetPt][binJetR], ""});
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#eta", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{#eta}^{jet}");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jeteta_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

void JetAnalysis::DrawDataGenJetPhi(bool doLog = true, int binJetPt =0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataGenjetNormalizedEta[binJetPt][binJetR], ""});
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#eta", "1/#it{N_{jet}}d#it{N_{jet}}/d#it{#eta}^{jet}");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/general/jeteta_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR])));
}

// MC
void JetAnalysis::DrawSimGenJetPt(bool doLog = true, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedPt[binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/jetmomentum.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/resolution/jetmomentum_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetEta(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETETA[0], GeneralJet::REFHIST::JETETA[1], GeneralJet::REFHIST::JETETA[2], GeneralJet::REFHIST::JETETA[3], "#it{#eta}_{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#eta}_{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/jeteta.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/jeteta_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetPhi(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETPHI[0], GeneralJet::REFHIST::JETPHI[1], GeneralJet::REFHIST::JETPHI[2], GeneralJet::REFHIST::JETPHI[3], "#it{#phi_{jet}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#phi}_{jet}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/jetphi.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/jetphi_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetNTracks(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedNTracks[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETNTRACKS[0], GeneralJet::REFHIST::JETNTRACKS[1], GeneralJet::REFHIST::JETNTRACKS[2], GeneralJet::REFHIST::JETNTRACKS[3], "#it{N_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{N_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/jetntracks.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/jetntracks_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetArea(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedArea[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::JETAREA[0], GeneralJet::REFHIST::JETAREA[1], GeneralJet::REFHIST::JETAREA[2], GeneralJet::REFHIST::JETAREA[3], "#it{A_{jet}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{A_{jet}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/jetarea.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/jetarea_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetTrackPt(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedTrackPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p_{T}^{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/trackpt.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/trackpt_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetTrackEta(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedTrackEta[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKETA[0], GeneralJet::REFHIST::TRACKETA[1], GeneralJet::REFHIST::TRACKETA[2], GeneralJet::REFHIST::TRACKETA[3], "#it{#eta_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#eta_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/tracketa.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/tracketa_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetTrackPhi(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedTrackPhi[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPHI[0], GeneralJet::REFHIST::TRACKPHI[1], GeneralJet::REFHIST::TRACKPHI[2], GeneralJet::REFHIST::TRACKPHI[3], "#it{#phi_{track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#phi_{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/trackphi.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/trackphi_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawSimGenJetLeadingTrackPt(bool doLog = true, int binJetPt = 0, int binJetR=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hsimGenjetNormalizedLeadingTrackPt[binJetPt][binJetR], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, GeneralJet::REFHIST::TRACKPT[0], GeneralJet::REFHIST::TRACKPT[1], GeneralJet::REFHIST::TRACKPT[2], GeneralJet::REFHIST::TRACKPT[3], "#it{p_{T}^{leading track}}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{leading track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  if (binJetPt == 0 && binJetR == 0) {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/leadingtrackpt.pdf\")", canvasNum - 1));
  } else {
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/mix/leadingtrackpt_%d_%d.pdf\")", canvasNum - 1, static_cast<int>(GeneralJet::binsJetPt[binJetPt]), static_cast<int>(GeneralJet::binsJetR[binJetR])));
  }
}

void JetAnalysis::DrawRatioDataMCGenJetPt(bool doLog = false, int binJetR =0) {
  TH1F *hRatio = static_cast<TH1F*>(hdataGenjetNormalizedPt[binJetR]->Clone("hRatio"));
  hRatio->Divide(hsimGenjetNormalizedPt[binJetR]);
  canvasHandler = new CanvasHandler();
  canvasHandler->drawUpperPad(hsimGenjetNormalizedPt[binJetR], canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "","#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}");
  canvasHandler->drawLowerPad(hRatio, canvasNum, GeneralJet::REFHIST::JETPT[0], GeneralJet::REFHIST::JETPT[1], GeneralJet::REFHIST::JETPT[2], GeneralJet::REFHIST::JETPT[3], "#it{p}_{T}^{jet}");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/general/temp.pdf\")", canvasNum));
  canvasNum++;
}

#endif // JETANALYSIS_H
