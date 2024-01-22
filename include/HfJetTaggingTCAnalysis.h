#ifndef HFJETTAGGINGTCANALYSIS_H
#define HFJETTAGGINGTCANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"
//#include "JetAnalysis.h"

/// Now it works itself withtout JetAnalysis.h(GeneralQA) seperatively
/// If histograms were saved by same root file,
/// In future, it should be merged by class HfJetTaggingTCAnalysis : public JetAnalysis
/// So the functions have to be made by different name of funciton in JetAnalysis.h

class HfJetTaggingTCAnalysis {
  public:
    //HfJetTaggingTCAnalysis(const TString rootFile, const TString taskName, bool doMC) {
    HfJetTaggingTCAnalysis(TString rootData, TString rootSim, bool doData, bool doMC, bool dopartLevel) {
      if (doData) {
        if(!LoadDataTCQA(rootData.Data())) {
          return;
        }
        InitHistogramForProjectionTCQAData();
      	ProjectionHistTCQAData();
      	CloneNormalizedHistogramTCQAData();
      	NormalizedHistogramTCQAData();
      }
      if (doMC) {
        if(!LoadSimTCQA(rootSim.Data())) {
          return;
        }
        InitHistogramForProjectionTCQAMC();
      	ProjectionHistTCQAMC();
      	CloneNormalizedHistogramTCQAMC();
      	NormalizedHistogramTCQAMC();
      }
    }
//    HfJetTaggingTCAnalysis(const TString &rootFileTC, const TString &rootFileSV2Prong, const TString &rootFileSV3Prong, const TString &taskName, bool doMC, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong, const TString &cutSelection) : JetAnalysis(rootFileTC, rootFileSV2Prong, rootFileSV3Prong, taskName, doMC, doTC, doJP, doSV2Prong, doSV3Prong, cutSelection){
//      if (doMC) LoadSimTCQA(rootFileTC.Data(), taskName.Data(), doTC, doJP);
//      else LoadDataTCQA(rootFileTC.Data(), taskName.Data());
//    }
    ~HfJetTaggingTCAnalysis();

    int LoadDataTCQA(TString rootData);
    int LoadSimTCQA(TString rootSim);
    void InitHistogramForProjectionTCQAData();
    void InitHistogramForProjectionTCQAMC();
    void ProjectionHistTCQAData();
    void ProjectionHistTCQAMC();
    void CloneNormalizedHistogramTCQAData();
    void CloneNormalizedHistogramTCQAMC();
    void NormalizedHistogramTCQAData();
    void NormalizedHistogramTCQAMC();

    void SaveHistogramTCQA(TString file);

    // Draw
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    std::vector<HistogramData> histList;
    void DrawCombined(int num, const std::vector<HistogramData>& histList, double legendxmin, double ymin, double xmax, double ymax);
    void DrawTaggedJetSignImpXYSignificanceN1(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYSignificanceN2(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYSignificanceN3(bool withInc, bool doLog);
    void DrawTaggedJetSignImpZSignificanceN1(bool withInc, bool doLog);
    void DrawTaggedJetSignImpZSignificanceN2(bool withInc, bool doLog);
    void DrawTaggedJetSignImpZSignificanceN3(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYZSignificanceN1(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYZSignificanceN2(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYZSignificanceN3(bool withInc, bool doLog);





    // Histogram
    //// Projeceted
    TH1F* hsimTCjetSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  protected:
    int canvasNum = 0;
    CanvasHandler* canvasHandler;
    // Histogram
    /// Data

    /// MC
    TH3F* h3simTCjetPtSignImpXYSigFlavourN1;
    TH3F* h3simTCjetPtSignImpXYSigFlavourN2;
    TH3F* h3simTCjetPtSignImpXYSigFlavourN3;
    TH3F* h3simTCjetPtSignImpZSigFlavourN1;
    TH3F* h3simTCjetPtSignImpZSigFlavourN2;
    TH3F* h3simTCjetPtSignImpZSigFlavourN3;
    TH3F* h3simTCjetPtSignImpXYZSigFlavourN1;
    TH3F* h3simTCjetPtSignImpXYZSigFlavourN2;
    TH3F* h3simTCjetPtSignImpXYZSigFlavourN3;

    //// Normalized
    TH1F* hsimTCjetNormalizedSignImpXYSigN1[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYSigN2[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYSigN3[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSigN1[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSigN2[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSigN3[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSigN1[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSigN2[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSigN3[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];

  private:

};

HfJetTaggingTCAnalysis::~HfJetTaggingTCAnalysis() {

}

int HfJetTaggingTCAnalysis::LoadDataTCQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-tc-charged";

  return 1;
}

int HfJetTaggingTCAnalysis::LoadSimTCQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TString taskName = "jet-taggerhf-tc-charged";

  TFile* fin;
  fin = TFile::Open(rootSim, "READ");

  h3simTCjetPtSignImpXYSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
  h3simTCjetPtSignImpXYSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
  h3simTCjetPtSignImpXYSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
  h3simTCjetPtSignImpZSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
  h3simTCjetPtSignImpZSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
  h3simTCjetPtSignImpZSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
  h3simTCjetPtSignImpXYZSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
  h3simTCjetPtSignImpXYZSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
  h3simTCjetPtSignImpXYZSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));

  return 1;
}

void HfJetTaggingTCAnalysis::InitHistogramForProjectionTCQAData() {
}

void HfJetTaggingTCAnalysis::InitHistogramForProjectionTCQAMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hsimTCjetSignImpXYSigN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourN1->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourN1->GetNbinsY()));
      hsimTCjetSignImpXYSigN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourN2->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourN2->GetNbinsY()));
      hsimTCjetSignImpXYSigN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourN3->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourN3->GetNbinsY()));
      hsimTCjetSignImpZSigN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavourN1->GetNbinsY(), h3simTCjetPtSignImpZSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavourN1->GetNbinsY()));
      hsimTCjetSignImpZSigN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavourN2->GetNbinsY(), h3simTCjetPtSignImpZSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavourN2->GetNbinsY()));
      hsimTCjetSignImpZSigN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavourN3->GetNbinsY(), h3simTCjetPtSignImpZSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavourN3->GetNbinsY()));
      hsimTCjetSignImpXYZSigN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavourN1->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavourN1->GetNbinsY()));
      hsimTCjetSignImpXYZSigN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavourN2->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavourN2->GetNbinsY()));
      hsimTCjetSignImpXYZSigN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavourN3->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavourN3->GetNbinsY()));
    }
  }
}

void HfJetTaggingTCAnalysis::ProjectionHistTCQAData() {
}

void HfJetTaggingTCAnalysis::ProjectionHistTCQAMC() {
  int binsToFlavour[] = {1, 2, 3}; // 1: charm, 2: beauty, 3: light flavour
  int numBinsToFlavour = sizeof(binsToFlavour) / sizeof(binsToFlavour[0]);
  for (int i=0; i<numBinsToFlavour; i++) {
    int binFlavour = binsToFlavour[i];
    TH1F* projSignImpXYSigN1 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavourN1->ProjectionY(Form("projSignImpXYSigN1_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpXYSigN2 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavourN2->ProjectionY(Form("projSignImpXYSigN2_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpXYSigN3 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavourN3->ProjectionY(Form("projSignImpXYSigN3_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpZSigN1 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavourN1->ProjectionY(Form("projSignImpZSigN1_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpZSigN2 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavourN2->ProjectionY(Form("projSignImpZSigN2_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpZSigN3 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavourN3->ProjectionY(Form("projSignImpZSigN3_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpXYZSigN1 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavourN1->ProjectionY(Form("projSignImpXYZSigN1_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpXYZSigN2 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavourN2->ProjectionY(Form("projSignImpXYZSigN2_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
    TH1F* projSignImpXYZSigN3 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavourN3->ProjectionY(Form("projSignImpXYZSigN3_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));

    // inclusive
    hsimTCjetSignImpXYSigN1[0][0]->Add(projSignImpXYSigN1);
    hsimTCjetSignImpXYSigN2[0][0]->Add(projSignImpXYSigN2);
    hsimTCjetSignImpXYSigN3[0][0]->Add(projSignImpXYSigN3);
    hsimTCjetSignImpZSigN1[0][0]->Add(projSignImpZSigN1);
    hsimTCjetSignImpZSigN2[0][0]->Add(projSignImpZSigN2);
    hsimTCjetSignImpZSigN3[0][0]->Add(projSignImpZSigN3);
    hsimTCjetSignImpXYZSigN1[0][0]->Add(projSignImpXYZSigN1);
    hsimTCjetSignImpXYZSigN2[0][0]->Add(projSignImpXYZSigN2);
    hsimTCjetSignImpXYZSigN3[0][0]->Add(projSignImpXYZSigN3);

    // jet flavour
    hsimTCjetSignImpXYSigN1[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN1->Clone());
    hsimTCjetSignImpXYSigN2[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN2->Clone());
    hsimTCjetSignImpXYSigN3[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN3->Clone());
    hsimTCjetSignImpZSigN1[i+1][0] = reinterpret_cast<TH1F*>(projSignImpZSigN1->Clone());
    hsimTCjetSignImpZSigN2[i+1][0] = reinterpret_cast<TH1F*>(projSignImpZSigN2->Clone());
    hsimTCjetSignImpZSigN3[i+1][0] = reinterpret_cast<TH1F*>(projSignImpZSigN3->Clone());
    hsimTCjetSignImpXYZSigN1[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN1->Clone());
    hsimTCjetSignImpXYZSigN2[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN2->Clone());
    hsimTCjetSignImpXYZSigN3[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN3->Clone());


    for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {

      int leftbinJetPtSignImpXYSigN1 = h3simTCjetPtSignImpXYSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpXYSigN1 = h3simTCjetPtSignImpXYSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpXYSigN1 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpXYSigN1_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYSigN1, rightbinJetPtSignImpXYSigN1, binFlavour, binFlavour));
      hsimTCjetSignImpXYSigN1[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN1->Clone());
      hsimTCjetSignImpXYSigN1[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN1);

      int leftbinJetPtSignImpXYSigN2 = h3simTCjetPtSignImpXYSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpXYSigN2 = h3simTCjetPtSignImpXYSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpXYSigN2 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpXYSigN2_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYSigN2, rightbinJetPtSignImpXYSigN2, binFlavour, binFlavour));
      hsimTCjetSignImpXYSigN2[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN2->Clone());
      hsimTCjetSignImpXYSigN2[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN2);

      int leftbinJetPtSignImpXYSigN3 = h3simTCjetPtSignImpXYSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpXYSigN3 = h3simTCjetPtSignImpXYSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpXYSigN3 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpXYSigN3_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYSigN3, rightbinJetPtSignImpXYSigN3, binFlavour, binFlavour));
      hsimTCjetSignImpXYSigN3[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN3->Clone());
      hsimTCjetSignImpXYSigN3[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN3);

      int leftbinJetPtSignImpZSigN1 = h3simTCjetPtSignImpZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpZSigN1 = h3simTCjetPtSignImpZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpZSigN1 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpZSigN1_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZSigN1, rightbinJetPtSignImpZSigN1, binFlavour, binFlavour));
      hsimTCjetSignImpZSigN1[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN1->Clone());
      hsimTCjetSignImpZSigN1[0][binJetPt]->Add(projJetPtRangeSignImpZSigN1);

      int leftbinJetPtSignImpZSigN2 = h3simTCjetPtSignImpZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpZSigN2 = h3simTCjetPtSignImpZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpZSigN2 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpZSigN2_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZSigN2, rightbinJetPtSignImpZSigN2, binFlavour, binFlavour));
      hsimTCjetSignImpZSigN2[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN2->Clone());
      hsimTCjetSignImpZSigN2[0][binJetPt]->Add(projJetPtRangeSignImpZSigN2);

      int leftbinJetPtSignImpZSigN3 = h3simTCjetPtSignImpZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpZSigN3 = h3simTCjetPtSignImpZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpZSigN3 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpZSigN3_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZSigN3, rightbinJetPtSignImpZSigN3, binFlavour, binFlavour));
      hsimTCjetSignImpZSigN3[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN3->Clone());
      hsimTCjetSignImpZSigN3[0][binJetPt]->Add(projJetPtRangeSignImpZSigN3);

      int leftbinJetPtSignImpXYZSigN1 = h3simTCjetPtSignImpXYZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpXYZSigN1 = h3simTCjetPtSignImpXYZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpXYZSigN1 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpXYZSigN1_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZSigN1, rightbinJetPtSignImpXYZSigN1, binFlavour, binFlavour));
      hsimTCjetSignImpXYZSigN1[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN1->Clone());
      hsimTCjetSignImpXYZSigN1[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN1);

      int leftbinJetPtSignImpXYZSigN2 = h3simTCjetPtSignImpXYZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpXYZSigN2 = h3simTCjetPtSignImpXYZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpXYZSigN2 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpXYZSigN2_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZSigN2, rightbinJetPtSignImpXYZSigN2, binFlavour, binFlavour));
      hsimTCjetSignImpXYZSigN2[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN2->Clone());
      hsimTCjetSignImpXYZSigN2[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN2);

      int leftbinJetPtSignImpXYZSigN3 = h3simTCjetPtSignImpXYZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
      int rightbinJetPtSignImpXYZSigN3 = h3simTCjetPtSignImpXYZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
      TH1F* projJetPtRangeSignImpXYZSigN3 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpXYZSigN3_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZSigN3, rightbinJetPtSignImpXYZSigN3, binFlavour, binFlavour));
      hsimTCjetSignImpXYZSigN3[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN3->Clone());
      hsimTCjetSignImpXYZSigN3[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN3);

    }
  }
}

void HfJetTaggingTCAnalysis::CloneNormalizedHistogramTCQAData() {
}


void HfJetTaggingTCAnalysis::CloneNormalizedHistogramTCQAMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSigN1[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSigN1_%d_%d", flavour, jetPt)));
      hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSigN2[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSigN2_%d_%d", flavour, jetPt)));
      hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSigN3[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSigN3_%d_%d", flavour, jetPt)));
      hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSigN1[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSigN1_%d_%d", flavour, jetPt)));
      hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSigN2[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSigN2_%d_%d", flavour, jetPt)));
      hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSigN3[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSigN3_%d_%d", flavour, jetPt)));
      hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSigN1[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSigN1_%d_%d", flavour, jetPt)));
hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSigN2[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSigN2_%d_%d", flavour, jetPt)));
hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSigN3[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSigN3_%d_%d", flavour, jetPt)));

    }
  }
}

void HfJetTaggingTCAnalysis::NormalizedHistogramTCQAData() {
}


void HfJetTaggingTCAnalysis::NormalizedHistogramTCQAMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt]->Integral());
      hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt]->Integral());
    }
  }
}

void HfJetTaggingTCAnalysis::SaveHistogramTCQA(TString outFile) {
  TFile *fout = TFile::Open(outFile.Data(),"recreate");
  if (!fout) return;
//  for (int flavour=0; flavour<HfJetTagging::nFlavour+1; flavour++) {
//    //if (!gSystem->AccessPathName(Form("%s/%s", outFile.Data(), HfJetTagging::FLAVOUR[flavour].Data()))) {
//    fout->mkdir(Form("%sJet", HfJetTagging::FLAVOUR[flavour].Data()));
//    //}
//    for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
//      hsimTCjetTrackPt[flavour][binJetPt]->Write(Form("%sJet/histTrackPt_binJetPt_%d", HfJetTagging::FLAVOUR[flavour].Data(), binJetPt));
//      hsimTCjetImpXY[flavour][binJetPt]->Write(Form("%sJet/histImpXY_binJetPt_%d", HfJetTagging::FLAVOUR[flavour].Data(), binJetPt));
//      hsimTCjetImpXYSig[flavour][binJetPt]->Write(Form("%sJet/histImpXYSig_binJetPt_%d", HfJetTagging::FLAVOUR[flavour].Data(), binJetPt));
//      //hsimTCjetImpXYSig[flavour][binJetPt]->Write(Form("%s/", HfJetTagging::FLAVOUR[flavour].Data()) + TString(hsimTCjetImpXYSig[flavour][binJetPt]->GetName()));
//      
//    }
//  }
  delete fout;
}

// Draw function
void HfJetTaggingTCAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingTCAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, double xmin, double ymin, double xmax, double ymax) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++) {
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  leg->Draw();
}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificanceN1(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN1[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN1[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN1[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN1[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{1}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificanceN1.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificanceN2(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN2[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN2[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN2[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN2[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{2}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificanceN2.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificanceN3(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN3[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN3[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN3[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYSigN3[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{3}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificanceN3.pdf\")", canvasNum - 1));
}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpZSignificanceN1(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN1[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN1[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN1[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN1[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{1}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpZSignificanceN1.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpZSignificanceN2(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN2[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN2[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN2[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN2[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{2}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpZSignificanceN2.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpZSignificanceN3(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN3[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN3[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN3[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpZSigN3[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{3}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpZSignificanceN3.pdf\")", canvasNum - 1));
}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYZSignificanceN1(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN1[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN1[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN1[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN1[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{1}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZSignificanceN1.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYZSignificanceN2(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN2[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN2[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN2[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN2[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{2}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZSignificanceN2.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYZSignificanceN3(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN3[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN3[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN3[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTCjetNormalizedSignImpXYZSigN3[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{3}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZSignificanceN3.pdf\")", canvasNum - 1));
}

//
//void HfJetTaggingTCAnalysis::DrawTaggedJetProbability(){
//  std::vector<HistogramData> NormHistList;
//  //NormHistList.push_back({hsimincjetNormalizedJP, HfJetTagging::INCJET});
//  NormHistList.push_back({hsimlfjetNormalizedJP, HfJetTagging::LFJET});
//  NormHistList.push_back({hsimcjetNormalizedJP, HfJetTagging::CJET});
//  NormHistList.push_back({hsimbjetNormalizedJP, HfJetTagging::BJET});
//
//  canvasHandler = new CanvasHandler();
//  canvasHandler->createCanvas(canvasNum++);
//  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "Probability distribution");
//  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/JetProbability.pdf\")", canvasNum - 1));
//}
//void HfJetTaggingTCAnalysis::DrawTaggedJetProbabilityLog(){
//  std::vector<HistogramData> NormHistList;
//  //NormHistList.push_back({hsimincjetNormalizedJPLog, HfJetTagging::INCJET});
//  NormHistList.push_back({hsimlfjetNormalizedJPLog, HfJetTagging::LFJET});
//  NormHistList.push_back({hsimcjetNormalizedJPLog, HfJetTagging::CJET});
//  NormHistList.push_back({hsimbjetNormalizedJPLog, HfJetTagging::BJET});
//
//  canvasHandler = new CanvasHandler();
//  canvasHandler->createCanvas(canvasNum++);
//  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "Probability distribution");
//  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/JetProbabilityLog.pdf\")", canvasNum - 1));
//}

#endif // HFJETTAGGINGTCANALYSIS_H 

