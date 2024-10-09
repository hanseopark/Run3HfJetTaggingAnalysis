#ifndef HFJETTAGGINGTCANALYSIS_H
#define HFJETTAGGINGTCANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "HfJetTaggingAnalysis.h"
#include "HfJetTaggingUtilities.h"
//#include "JetAnalysis.h"

/// Now it works itself withtout JetAnalysis.h(GeneralQA) seperatively
/// If histograms were saved by same root file,
/// In future, it should be merged by class HfJetTaggingTCAnalysis : public JetAnalysis
/// So the functions have to be made by different name of funciton in JetAnalysis.h

class HfJetTaggingTCAnalysis : public HfJetTaggingAnalysis {
  public:
    HfJetTaggingTCAnalysis() {
      initConfig();
    }
    ~HfJetTaggingTCAnalysis();

    void initConfig();
    int loadDataTCQA(TString rootData);
    int loadSimTCQA(TString rootSim);
    void initHistogramForNormalizationTCQAData();
    void initHistogramForNormalizationTCQAMC();
    void projectionHistTCQAData();
    void projectionHistTCQAMC();
    void normalizedHistogramTCQAData();
    void normalizedHistogramTCQAMC();

    void saveHistogramTCQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // Set
    void setFillEffi(bool fillEffi);
    void setFillTest(bool fillTest);

    // Calculation
    double calculateEffiSignedImpXYSig(TH1F* huntagjet, TH1F* htagjet, int binJetPt, float cutImp);
    double calculatePurity(int flavour, int binJetPt, TH1F* htagjet[][HfJetTagging::nBinsJetPt+1], float cutImp);

    // Draw
    std::vector<HistogramData> histList;
    void drawSimJetSignImpXYSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN3(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN3x1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN4x1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN3(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN3x1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN3(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN3x1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetEffiSignImpXYSigN1(float cutImp);
    void drawSimJetEffiSignImpXYSigN2(float cutImp);
    void drawSimJetEffiSignImpXYSigN3(float cutImp);
    void drawSimJetEffiSignImpXYSigNx(float cutImp);
    void drawSimJetEffiSignImpXYSigN3x1(float cutImp);
    void drawSimJetEffiSignImpXYSigNxTagger(int binJetPt);
    void drawSimJetEffiNoTagger();
    void drawSimJetPurityN1(float cutImp);
    void drawSimJetPurityN2(float cutImp);
    void drawSimJetPurityN3(float cutImp);
    void drawSimJetPurityNx(float cutImp);
    void drawSimJetPurityNxTagger(int binJetPt);
    void drawSimJetPurityN3x1(float cutImp);
    void drawSimJetEffiAndPurityNxTagger(int binJetPt);

    // Histogram
    //// Projeceted
    TH1F* hsimTCjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimTCjetSignImpXYSigRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigRun2DefN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigRun2DefN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetSignImpXYSigRun2DefN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
  protected:
    int nc = 10000;
    CanvasHandler* canHan;
    // Histogram
    /// Data

    /// MC
    TH3F* h3simTCjetPtSignImpXYSigFlavour;
    TH3F* h3simTCjetPtSignImpXYSigFlavourN1;
    TH3F* h3simTCjetPtSignImpXYSigFlavourN2;
    TH3F* h3simTCjetPtSignImpXYSigFlavourN3;
    TH3F* h3simTCjetPtSignImpZSigFlavour;
    TH3F* h3simTCjetPtSignImpZSigFlavourN1;
    TH3F* h3simTCjetPtSignImpZSigFlavourN2;
    TH3F* h3simTCjetPtSignImpZSigFlavourN3;
    TH3F* h3simTCjetPtSignImpXYZSigFlavour;
    TH3F* h3simTCjetPtSignImpXYZSigFlavourN1;
    TH3F* h3simTCjetPtSignImpXYZSigFlavourN2;
    TH3F* h3simTCjetPtSignImpXYZSigFlavourN3;
    TH3F* h3simTCjetPtSignImpXYSigFlavourRun2Def;
    TH3F* h3simTCjetPtSignImpXYSigFlavourRun2DefN1;
    TH3F* h3simTCjetPtSignImpXYSigFlavourRun2DefN2;
    TH3F* h3simTCjetPtSignImpXYSigFlavourRun2DefN3;

    //// Normalized
    TH1F* hsimTCjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetNormalizedSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    
    // Reconstruction efficience and purity
    TH1F* hsimTCjetEffiTaggerPointN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetEffiTaggerPointN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetEffiTaggerPointN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetEffiNoTagger[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetEffiSignImpXYSigN1[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetEffiSignImpXYSigN2[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetEffiSignImpXYSigN3[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetPurityTaggerPointN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetPurityTaggerPointN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetPurityTaggerPointN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetPurityN3[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetEffiAndPurityTaggerPointN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetEffiAndPurityTaggerPointN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTCjetEffiAndPurityTaggerPointN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimTCjetEffiSignImpXYSigN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetEffiSignImpXYSigN2Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetEffiSignImpXYSigN3Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetPurityN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetPurityN2Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimTCjetPurityN3Run2Def[HfJetTagging::nFlavour+1];

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;

    bool fillEffi = false;
    bool fillTest = false;
    int numCanXYNX[3] = {-1}; 
    int numCanXYZNX[3] = {-1}; 
    int numCanZNX[3] = {-1}; 

};

HfJetTaggingTCAnalysis::~HfJetTaggingTCAnalysis() {

}

void HfJetTaggingTCAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  dirSim = Form("%s/%s/sim/%s/tc", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingTCAnalysis::loadDataTCQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";

  return 1;
}

int HfJetTaggingTCAnalysis::loadSimTCQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TString taskName = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim, "READ");
  if (fillMCD) {
    if (fillIPxy) {
      h3simTCjetPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
      h3simTCjetPtSignImpXYSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
      h3simTCjetPtSignImpXYSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
      h3simTCjetPtSignImpXYSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
    }
    if (fillIPz) {
      h3simTCjetPtSignImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
      h3simTCjetPtSignImpZSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
      h3simTCjetPtSignImpZSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
      h3simTCjetPtSignImpZSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
    }
    if (fillIPxyz) {
      h3simTCjetPtSignImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
      h3simTCjetPtSignImpXYZSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
      h3simTCjetPtSignImpXYZSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
      h3simTCjetPtSignImpXYZSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
    }
  }
  if (fillMCP) {
    if (fillIPxy) {
      h3simTCjetPtSignImpXYSigFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_run2", taskName.Data())));
      h3simTCjetPtSignImpXYSigFlavourRun2DefN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_run2_N1", taskName.Data())));
      h3simTCjetPtSignImpXYSigFlavourRun2DefN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_run2_N2", taskName.Data())));
      h3simTCjetPtSignImpXYSigFlavourRun2DefN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_run2_N3", taskName.Data())));
    }
  }

  return 1;
}

void HfJetTaggingTCAnalysis::initHistogramForNormalizationTCQAData() {
}

void HfJetTaggingTCAnalysis::initHistogramForNormalizationTCQAMC() {
  if (fillMCD) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      if (fillIPxy) {
        hsimTCjetEffiSignImpXYSigN1[flavour] = new TH1F(Form("hsimTCjetEffiSignImpXYSigN1_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimTCjetEffiSignImpXYSigN2[flavour] = new TH1F(Form("hsimTCjetEffiSignImpXYSigN2_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimTCjetEffiSignImpXYSigN3[flavour] = new TH1F(Form("hsimTCjetEffiSignImpXYSigN3_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      }
      if (fillEffi) {
        hsimTCjetPurityN1[flavour] = new TH1F(Form("hsimTCjetPurityN1_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimTCjetPurityN2[flavour] = new TH1F(Form("hsimTCjetPurityN2_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimTCjetPurityN3[flavour] = new TH1F(Form("hsimTCjetPurityN3_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt; binJetPt++) {
          hsimTCjetEffiTaggerPointN1[flavour][binJetPt] = new TH1F(Form("hsimTCjetEffiTaggerPointN1_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetEffiTaggerPointN2[flavour][binJetPt] = new TH1F(Form("hsimTCjetEffiTaggerPointN2_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetEffiTaggerPointN3[flavour][binJetPt] = new TH1F(Form("hsimTCjetEffiTaggerPointN3_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetPurityTaggerPointN1[flavour][binJetPt] = new TH1F(Form("hsimTCjetPurityTaggerPointN1_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetPurityTaggerPointN2[flavour][binJetPt] = new TH1F(Form("hsimTCjetPurityTaggerPointN2_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetPurityTaggerPointN3[flavour][binJetPt] = new TH1F(Form("hsimTCjetPurityTaggerPointN3_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetEffiAndPurityTaggerPointN1[flavour][binJetPt] = new TH1F(Form("hsimTCjetEffiAndPurityTaggerPointN1_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetEffiAndPurityTaggerPointN2[flavour][binJetPt] = new TH1F(Form("hsimTCjetEffiAndPurityTaggerPointN2_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimTCjetEffiAndPurityTaggerPointN3[flavour][binJetPt] = new TH1F(Form("hsimTCjetEffiAndPurityTaggerPointN3_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
        }
      }
      if (fillTest) {
        hsimTCjetEffiNoTagger[flavour] = new TH1F(Form("hsimTCjetEffiNoTagger_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      }
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillIPxy) {
          hsimTCjetSignImpXYSig[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavour->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavour->GetNbinsY()));
          hsimTCjetSignImpXYSigN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourN1->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourN1->GetNbinsY()));
          hsimTCjetSignImpXYSigN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourN2->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourN2->GetNbinsY()));
          hsimTCjetSignImpXYSigN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourN3->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourN3->GetNbinsY()));
        }
        if (fillIPz) {
          hsimTCjetSignImpZSig[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSig_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavour->GetNbinsY(), h3simTCjetPtSignImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavour->GetNbinsY()));
          hsimTCjetSignImpZSigN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavourN1->GetNbinsY(), h3simTCjetPtSignImpZSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavourN1->GetNbinsY()));
          hsimTCjetSignImpZSigN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavourN2->GetNbinsY(), h3simTCjetPtSignImpZSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavourN2->GetNbinsY()));
          hsimTCjetSignImpZSigN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpZSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpZSigFlavourN3->GetNbinsY(), h3simTCjetPtSignImpZSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpZSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpZSigFlavourN3->GetNbinsY()));
        }
        if (fillIPxyz) {
          hsimTCjetSignImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSig_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavour->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavour->GetNbinsY()));
          hsimTCjetSignImpXYZSigN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavourN1->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavourN1->GetNbinsY()));
          hsimTCjetSignImpXYZSigN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavourN2->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavourN2->GetNbinsY()));
          hsimTCjetSignImpXYZSigN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYZSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYZSigFlavourN3->GetNbinsY(), h3simTCjetPtSignImpXYZSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYZSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYZSigFlavourN3->GetNbinsY()));
        }
      }
    }
  }
  if (fillMCP) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {

      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillIPxy) {
          hsimTCjetSignImpXYSigRun2Def[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourRun2Def->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourRun2Def->GetNbinsY()));
          hsimTCjetSignImpXYSigRun2DefN1[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN1_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourRun2DefN1->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourRun2DefN1->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourRun2DefN1->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourRun2DefN1->GetNbinsY()));
          hsimTCjetSignImpXYSigRun2DefN2[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN2_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourRun2DefN2->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourRun2DefN2->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourRun2DefN2->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourRun2DefN2->GetNbinsY()));
          hsimTCjetSignImpXYSigRun2DefN3[flavour][jetPt] = new TH1F(Form("hsimTCjetSignImpXYSigN3_%d_%d", flavour, jetPt), "", h3simTCjetPtSignImpXYSigFlavourRun2DefN3->GetNbinsY(), h3simTCjetPtSignImpXYSigFlavourRun2DefN3->GetYaxis()->GetBinLowEdge(1), h3simTCjetPtSignImpXYSigFlavourRun2DefN3->GetYaxis()->GetBinUpEdge(h3simTCjetPtSignImpXYSigFlavourRun2DefN3->GetNbinsY()));
        }
      }
    }
  }
}

void HfJetTaggingTCAnalysis::projectionHistTCQAData() {
}

void HfJetTaggingTCAnalysis::projectionHistTCQAMC() {
  if (fillMCD) {
    HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      if (fillIPxy) {
        TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigN1 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavourN1->ProjectionY(Form("projSignImpXYSigN1_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigN2 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavourN2->ProjectionY(Form("projSignImpXYSigN2_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigN3 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYSigFlavourN3->ProjectionY(Form("projSignImpXYSigN3_%d", binFlavour), 1, h3simTCjetPtSignImpXYSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
        hsimTCjetSignImpXYSig[0][0]->Add(projSignImpXYSig);
        hsimTCjetSignImpXYSigN1[0][0]->Add(projSignImpXYSigN1);
        hsimTCjetSignImpXYSigN2[0][0]->Add(projSignImpXYSigN2);
        hsimTCjetSignImpXYSigN3[0][0]->Add(projSignImpXYSigN3);
        hsimTCjetSignImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone(Form("hsimTCjetSignImpXYSig_%d_0", flavour)));
        hsimTCjetSignImpXYSigN1[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN1->Clone(Form("hsimTCjetSignImpXYSigN1_%d_0", flavour)));
        hsimTCjetSignImpXYSigN2[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN2->Clone(Form("hsimTCjetSignImpXYSigN2_%d_0", flavour)));
        hsimTCjetSignImpXYSigN3[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN3->Clone());
      }
      if (fillIPz) {
        TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavour->ProjectionY(Form("projSignImpZSig_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSigN1 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavourN1->ProjectionY(Form("projSignImpZSigN1_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSigN2 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavourN2->ProjectionY(Form("projSignImpZSigN2_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSigN3 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpZSigFlavourN3->ProjectionY(Form("projSignImpZSigN3_%d", binFlavour), 1, h3simTCjetPtSignImpZSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
        hsimTCjetSignImpZSig[0][0]->Add(projSignImpZSig);
        hsimTCjetSignImpZSigN1[0][0]->Add(projSignImpZSigN1);
        hsimTCjetSignImpZSigN2[0][0]->Add(projSignImpZSigN2);
        hsimTCjetSignImpZSigN3[0][0]->Add(projSignImpZSigN3);
        hsimTCjetSignImpZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone());
        hsimTCjetSignImpZSigN1[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN1->Clone());
        hsimTCjetSignImpZSigN2[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN2->Clone(Form("hsimTCjetSignImpZSigN2_%d_0", flavour)));
        hsimTCjetSignImpZSigN3[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN3->Clone());
      }
      if (fillIPxyz) {
        TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavour->ProjectionY(Form("projSignImpXYZSig_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSigN1 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavourN1->ProjectionY(Form("projSignImpXYZSigN1_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSigN2 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavourN2->ProjectionY(Form("projSignImpXYZSigN2_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSigN3 = reinterpret_cast<TH1F*> (h3simTCjetPtSignImpXYZSigFlavourN3->ProjectionY(Form("projSignImpXYZSigN3_%d", binFlavour), 1, h3simTCjetPtSignImpXYZSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
        hsimTCjetSignImpXYZSig[0][0]->Add(projSignImpXYZSig);
        hsimTCjetSignImpXYZSigN1[0][0]->Add(projSignImpXYZSigN1);
        hsimTCjetSignImpXYZSigN2[0][0]->Add(projSignImpXYZSigN2);
        hsimTCjetSignImpXYZSigN3[0][0]->Add(projSignImpXYZSigN3);
        hsimTCjetSignImpXYZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone());
        hsimTCjetSignImpXYZSigN1[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN1->Clone());
        hsimTCjetSignImpXYZSigN2[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN2->Clone());
        hsimTCjetSignImpXYZSigN3[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN3->Clone());
      }

      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (fillIPxy) {
          int leftbinJetPtSignImpXYSig = h3simTCjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSig = h3simTCjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binFlavour, binFlavour));
          hsimTCjetSignImpXYSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone(Form("hsimTCjetSignImpXYSig_%d_%d", flavour, binJetPt)));
          hsimTCjetSignImpXYSig[0][binJetPt]->Add(projJetPtRangeSignImpXYSig);

          int leftbinJetPtSignImpXYSigN1 = h3simTCjetPtSignImpXYSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSigN1 = h3simTCjetPtSignImpXYSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSigN1 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpXYSigN1_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSigN1, rightbinJetPtSignImpXYSigN1, binFlavour, binFlavour));
          hsimTCjetSignImpXYSigN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN1->Clone(Form("hsimTCjetSignImpXYSigN1_%d_%d", flavour, binJetPt)));
          hsimTCjetSignImpXYSigN1[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN1);

          int leftbinJetPtSignImpXYSigN2 = h3simTCjetPtSignImpXYSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSigN2 = h3simTCjetPtSignImpXYSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSigN2 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpXYSigN2_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSigN2, rightbinJetPtSignImpXYSigN2, binFlavour, binFlavour));
          hsimTCjetSignImpXYSigN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN2->Clone(Form("hsimTCjetSignImpXYSigN2_%d_%d", flavour, binJetPt)));
          hsimTCjetSignImpXYSigN2[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN2);

          int leftbinJetPtSignImpXYSigN3 = h3simTCjetPtSignImpXYSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSigN3 = h3simTCjetPtSignImpXYSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSigN3 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpXYSigN3_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSigN3, rightbinJetPtSignImpXYSigN3, binFlavour, binFlavour));
          hsimTCjetSignImpXYSigN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN3->Clone());
          hsimTCjetSignImpXYSigN3[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN3);
        }
        if (fillIPz) {
          int leftbinJetPtSignImpZSig = h3simTCjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSig = h3simTCjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSig = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpZSig_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, binFlavour, binFlavour));
          hsimTCjetSignImpZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSig->Clone(Form("hsimTCjetSignImpZSig_%d_%d", flavour, binJetPt)));
          hsimTCjetSignImpZSig[0][binJetPt]->Add(projJetPtRangeSignImpZSig);

          int leftbinJetPtSignImpZSigN1 = h3simTCjetPtSignImpZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSigN1 = h3simTCjetPtSignImpZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSigN1 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpZSigN1_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSigN1, rightbinJetPtSignImpZSigN1, binFlavour, binFlavour));
          hsimTCjetSignImpZSigN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN1->Clone());
          hsimTCjetSignImpZSigN1[0][binJetPt]->Add(projJetPtRangeSignImpZSigN1);

          int leftbinJetPtSignImpZSigN2 = h3simTCjetPtSignImpZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSigN2 = h3simTCjetPtSignImpZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSigN2 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpZSigN2_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSigN2, rightbinJetPtSignImpZSigN2, binFlavour, binFlavour));
          hsimTCjetSignImpZSigN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN2->Clone());
          hsimTCjetSignImpZSigN2[0][binJetPt]->Add(projJetPtRangeSignImpZSigN2);

          int leftbinJetPtSignImpZSigN3 = h3simTCjetPtSignImpZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSigN3 = h3simTCjetPtSignImpZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSigN3 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpZSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpZSigN3_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSigN3, rightbinJetPtSignImpZSigN3, binFlavour, binFlavour));
          hsimTCjetSignImpZSigN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN3->Clone());
          hsimTCjetSignImpZSigN3[0][binJetPt]->Add(projJetPtRangeSignImpZSigN3);
        }
        if (fillIPxyz) {
          int leftbinJetPtSignImpXYZSig = h3simTCjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSig = h3simTCjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSig = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZSig_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, binFlavour, binFlavour));
          hsimTCjetSignImpXYZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSig->Clone(Form("hsimTCjetSignImpXYZSig_%d_%d", flavour, binJetPt)));
          hsimTCjetSignImpXYZSig[0][binJetPt]->Add(projJetPtRangeSignImpXYZSig);

          int leftbinJetPtSignImpXYZSigN1 = h3simTCjetPtSignImpXYZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSigN1 = h3simTCjetPtSignImpXYZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSigN1 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpXYZSigN1_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSigN1, rightbinJetPtSignImpXYZSigN1, binFlavour, binFlavour));
          hsimTCjetSignImpXYZSigN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN1->Clone());
          hsimTCjetSignImpXYZSigN1[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN1);

          int leftbinJetPtSignImpXYZSigN2 = h3simTCjetPtSignImpXYZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSigN2 = h3simTCjetPtSignImpXYZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSigN2 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpXYZSigN2_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSigN2, rightbinJetPtSignImpXYZSigN2, binFlavour, binFlavour));
          hsimTCjetSignImpXYZSigN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN2->Clone());
          hsimTCjetSignImpXYZSigN2[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN2);

          int leftbinJetPtSignImpXYZSigN3 = h3simTCjetPtSignImpXYZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSigN3 = h3simTCjetPtSignImpXYZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSigN3 = reinterpret_cast<TH1F*>(h3simTCjetPtSignImpXYZSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpXYZSigN3_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSigN3, rightbinJetPtSignImpXYZSigN3, binFlavour, binFlavour));
          hsimTCjetSignImpXYZSigN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN3->Clone());
          hsimTCjetSignImpXYZSigN3[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN3);
        }
      }
    }
  }
}

void HfJetTaggingTCAnalysis::normalizedHistogramTCQAData() {
}

void HfJetTaggingTCAnalysis::normalizedHistogramTCQAMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      if (fillIPxy) {
        hsimTCjetNormalizedSignImpXYSig[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSig[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSig_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSigN1[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSigN1_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSigN2[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSigN2_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYSigN3[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYSigN3_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYSig[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSig[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt]->Integral());
        if (hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization XY N1, Intergral: "<< hsimTCjetNormalizedSignImpXYSigN1[flavour][jetPt]->Integral() << std::endl;
        if (hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization XY N2, Intergral: "<< hsimTCjetNormalizedSignImpXYSigN2[flavour][jetPt]->Integral() << std::endl;
        if (hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization XY N3, Intergral: "<< hsimTCjetNormalizedSignImpXYSigN3[flavour][jetPt]->Integral() << std::endl;
      }
      if (fillIPz) {
        hsimTCjetNormalizedSignImpZSig[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSig[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSig_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSigN1[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSigN1_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSigN2[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSigN2_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpZSigN3[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpZSigN3_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpZSig[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSig[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt]->Integral());
        if (hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization Z N1, Intergral: "<< hsimTCjetNormalizedSignImpZSigN1[flavour][jetPt]->Integral() << std::endl;
        if (hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization Z N2, Intergral: "<< hsimTCjetNormalizedSignImpZSigN2[flavour][jetPt]->Integral() << std::endl;
        if (hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization Z N3, Intergral: "<< hsimTCjetNormalizedSignImpZSigN3[flavour][jetPt]->Integral() << std::endl;
      }
      if (fillIPxyz) {
        hsimTCjetNormalizedSignImpXYZSig[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSig[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSig_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSigN1[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSigN1_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSigN2[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSigN2_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTCjetSignImpXYZSigN3[flavour][jetPt]->Clone(Form("hsimTCjetNormalizedSignImpXYZSigN3_%d_%d", flavour, jetPt)));
        hsimTCjetNormalizedSignImpXYZSig[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSig[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt]->Integral());
        hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt]->Scale(1. / hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt]->Integral());
        if (hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization XYZ N1, Intergral: "<< hsimTCjetNormalizedSignImpXYZSigN1[flavour][jetPt]->Integral() << std::endl;
        if (hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization XYZ N2, Intergral: "<< hsimTCjetNormalizedSignImpXYZSigN2[flavour][jetPt]->Integral() << std::endl;
        if (hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt]->Integral()>1.00006) std::cout<< "ERROR: Not performing nomalization XYZ N3, Intergral: "<< hsimTCjetNormalizedSignImpXYZSigN3[flavour][jetPt]->Integral() << std::endl;
      }
    }
  }
}

void HfJetTaggingTCAnalysis::saveHistogramTCQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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
  }

  if (doMC) {
    dir = fout->GetDirectory("sim");
    if (!dir) {
      dir = fout->mkdir("sim");
      dir->cd();
      for (int binFlavour =0; binFlavour < HfJetTagging::nFlavour+1; binFlavour++) {
        for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
          hsimTCjetSignImpXYSigN1[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpXYSigN2[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpXYSigN3[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpZSigN1[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpZSigN2[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpZSigN3[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpXYZSigN1[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpXYZSigN2[binFlavour][binJetPt]->Write();
          hsimTCjetSignImpXYZSigN3[binFlavour][binJetPt]->Write();

          // Normalized
          hsimTCjetNormalizedSignImpXYSigN1[binFlavour][binJetPt]->Write(Form("hsimTCjetNormazliedSignImpXYSigN1_%d_%d", binFlavour, binJetPt));
          hsimTCjetNormalizedSignImpXYSigN2[binFlavour][binJetPt]->Write();
          hsimTCjetNormalizedSignImpXYSigN3[binFlavour][binJetPt]->Write();
          hsimTCjetNormalizedSignImpZSigN1[binFlavour][binJetPt]->Write();
          hsimTCjetNormalizedSignImpZSigN2[binFlavour][binJetPt]->Write(Form("hsimTCjetNormalizedSignImpZSigN2_%d_%d", binFlavour, binJetPt));
          hsimTCjetNormalizedSignImpZSigN3[binFlavour][binJetPt]->Write();
          hsimTCjetNormalizedSignImpXYZSigN1[binFlavour][binJetPt]->Write();
          hsimTCjetNormalizedSignImpXYZSigN2[binFlavour][binJetPt]->Write();
          hsimTCjetNormalizedSignImpXYZSigN3[binFlavour][binJetPt]->Write();
        }
      }
    }
  }
  fout->Close();
  delete fout;
}

// Set function
void HfJetTaggingTCAnalysis::setFillEffi(bool mfillEffi) {
  fillEffi = mfillEffi;
  if (fillEffi) {
    std::cout << "fill effi and purity" << std::endl;
  }
}

void HfJetTaggingTCAnalysis::setFillTest(bool mfillTest) {
  fillTest = mfillTest;
}

// Draw function
void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  //latex.DrawLatex(0.7, 0.7, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latex.DrawLatex(0.67, 0.65, Form("#scale[1.5]{1^{st} largest %s}", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[0] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN2(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTCjetNormalizedSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[1] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN3(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  if(withInc) normHist.push_back({hsimTCjetNormalizedSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::X_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[2] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

//void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN3x1(bool withInc = false, bool doLog = true, int binJetPt=0) {
//  canHan = new CanvasHandler();
//  canHan->createCanvas(nc++);
//  int canN[3] ={-1};
//  canN[0] = nc-1;
//  canHan->createCanvas(nc++);
//  canN[1] = nc-1;
//  canHan->createCanvas(nc++);
//  canN[2] = nc-1;
//
//  canHan->createCanvas3x1(nc++);
//  int can3x1 = nc-1;
//
//  for (int mpad=0; mpad<3; mpad++) {
//    gROOT->ProcessLine(Form("mpad%d_%d->cd()", canN[mpad], mpad));
//    gROOT->ProcessLine(Form("cc%d->Draw()", numCanXYNX[mpad]));
//  }
//  gROOT->ProcessLine(Form("cc%d->Update()", can3x1));
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/tc/SignImpXYSignificanceN3x1_%d.pdf\")", can3x1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN3x1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListN1;
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvasMxN(nc, 3, 1, 0, 0, 2400, 600, 0.07, 0.02, 0.05, 0.16);
  //latexSimJetInfoForTC(0.10, 0.9, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  canHan->drawPadMxNCombined(nc, 0, 0, histListN1, withInc, doLog, true, HfJetTagging::REFHIST::IPXYSIG3x1[0], HfJetTagging::REFHIST::IPXYSIG3x1[1], HfJetTagging::REFHIST::IPXYSIG3x1[2], HfJetTagging::REFHIST::IPXYSIG3x1[3], "", HfJetTagging::Y_AXIS_IMPXY[3]);
  //latexSimJetInfo(0.20, 0.9, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  latexSimJetInfoForTC(0.23, 0.9, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
  latex.DrawLatex(0.75, 0.9, Form("#scale[1.8]{1^{st} largest %s}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 1, 0, histListN2, withInc, doLog, false, HfJetTagging::REFHIST::IPXYSIG3x1[0], HfJetTagging::REFHIST::IPXYSIG3x1[1], HfJetTagging::REFHIST::IPXYSIG3x1[2], HfJetTagging::REFHIST::IPXYSIG3x1[3], "", HfJetTagging::Y_AXIS_IMPXY[3]);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
  latex.DrawLatex(0.70, 0.9, Form("#scale[1.8]{2^{nd} largest %s}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 2, 0, histListN3, withInc, doLog, false, HfJetTagging::REFHIST::IPXYSIG3x1[0], HfJetTagging::REFHIST::IPXYSIG3x1[1], HfJetTagging::REFHIST::IPXYSIG3x1[2], HfJetTagging::REFHIST::IPXYSIG3x1[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
  latex.DrawLatex(0.65, 0.9, Form("#scale[1.8]{3^{rd} largest %s}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  gROOT->ProcessLine(Form("cc%d->Update();", nc));

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN3x1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN4x1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimTCjetNormalizedSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimTCjetNormalizedSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimTCjetNormalizedSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimTCjetNormalizedSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN1;
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  histListN1.push_back({hsimTCjetNormalizedSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  histListN2.push_back({hsimTCjetNormalizedSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  histListN3.push_back({hsimTCjetNormalizedSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.05, 0.05, 0.12);
  canHan->drawPadMxNCombined(nc, 0, 0, histList, withInc, doLog, true, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "", HfJetTagging::Y_AXIS_IMPXY[3]);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
  latexSimJetInfo(0.25, 0.9, 0, "PYTHIA8 Jet-Jet trigger", "Anti-#it{k}_{T}", "Charged", 0.4, "this simulation");

  canHan->drawPadMxNCombined(nc, 1, 0, histListN1, withInc, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "", HfJetTagging::Y_AXIS_IMPXY[3]);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
  latex.DrawLatex(0.05, 0.9, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 2, 0, histListN2, withInc, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "", HfJetTagging::Y_AXIS_IMPXY[3]);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
  latex.DrawLatex(0.05, 0.9, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 3, 0, histListN3, withInc, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
  latex.DrawLatex(0.05, 0.9, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN4x1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpZSignificanceN1(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpZSignificanceN2(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpZSignificanceN3(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN3[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN3[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpZSigN3[3][0], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::X_AXIS_IMPZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYZSignificanceN1(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYZSignificanceN2(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYZSignificanceN3(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN3[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN3[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTCjetNormalizedSignImpXYZSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

double HfJetTaggingTCAnalysis::calculateEffiSignedImpXYSig(TH1F* huntagjet, TH1F* htagjet, int binJetPt, float cutImp = 2.5) {
  int cuttagBin = htagjet->FindBin(cutImp);

  TH1F* hrebinuntagjet = (TH1F*) huntagjet->Rebin(HfJetTagging::nBinsJetPt,"REBIN", HfJetTagging::binsJetPt);
  double numunTagjet = hrebinuntagjet->GetBinContent(binJetPt);
  double numcutTagjet = htagjet->Integral(cuttagBin, htagjet->GetNbinsX());

  std::cout << "jet Pt: " << HfJetTagging::binsJetPt[binJetPt] << " unttagged: " << numunTagjet << " tagjet: " << numcutTagjet << std::endl;
  double effi = -1;
  // Check if numTagjet is not zero to avoid division by zero
  if (numunTagjet != 0) {
    effi = static_cast<double> (numcutTagjet / numunTagjet);
    // It's still a good idea to check if the efficiency is within expected bounds
    if (effi < 0 || effi > 1) {
      std::cout << "Warning: Efficiency is over 1 or less than 0, " << effi << std::endl;
      effi = -1; // Or handle this case as needed
    }
  } else {
    std::cout << "Warning: Total number of tag jets is zero, efficiency is undefined." << std::endl;
  }

  if (std::isnan(effi)) return -1;
  return effi;
}

double HfJetTaggingTCAnalysis::calculatePurity(int specificFlavour, int binJetPt, TH1F* hbasejet[][HfJetTagging::nBinsJetPt+1], float cutImp = 2.5) {
  if (specificFlavour <= 0 || specificFlavour > HfJetTagging::nFlavour) {
    std::cerr << "Invalid specific flavour provided." << std::endl;
    return -1;
  }
  if (binJetPt < 0 || binJetPt > HfJetTagging::nBinsJetPt) {
    std::cerr << "Invalid jet pt provided." << std::endl;
    return -1;
  }

  int binTargetjet = hbasejet[specificFlavour][binJetPt]->FindBin(cutImp);
  double purity = -1;
  purity = hbasejet[specificFlavour][binJetPt]->Integral(binTargetjet, hbasejet[specificFlavour][binJetPt]->GetNbinsX());

  double sumBase = 0;

  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    int binBasejet = hbasejet[flavour][binJetPt]->FindBin(cutImp);
    double integral = hbasejet[flavour][binJetPt]->Integral(binBasejet, hbasejet[flavour][binJetPt]->GetNbinsX());
    sumBase +=integral;
  }
  // Check if sumBase is not zero to avoid division by zero
  if (sumBase != 0) {
    purity /= sumBase;
  } else {
    std::cerr << "Warning: Total base sum is zero, purity is undefined." << std::endl;
  }

  if (std::isnan(purity)) return -1;
  return purity;
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN1(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      std::cout<< HfJetTagging::binsJetPt[binJetPt-1] <<" < jetPt < " << HfJetTagging::binsJetPt[binJetPt] <<std::endl;
//      float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimTCjetSignImpXYSigN1[flavour][binJetPt], binJetPt, cutImp);
//      if (effi < 0) continue;
//      hsimTCjetEffiSignImpXYSigN1[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimTCjetEffiSignImpXYSigN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN2(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      double effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimTCjetSignImpXYSigN2[flavour][binJetPt], binJetPt, cutImp);
      hsimTCjetEffiSignImpXYSigN2[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimTCjetEffiSignImpXYSigN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN3(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      double effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimTCjetSignImpXYSigN3[flavour][binJetPt], binJetPt, cutImp);
      hsimTCjetEffiSignImpXYSigN3[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimTCjetEffiSignImpXYSigN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigNx(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimTCjetEffiSignImpXYSigN1[flavour], "N=1"});
	normHist.push_back({hsimTCjetEffiSignImpXYSigN2[flavour], "N=2"});
	normHist.push_back({hsimTCjetEffiSignImpXYSigN3[flavour], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_BEAUTY_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.045*7, Form("tagger point (%s)=%0.1f", HfJetTagging::X_AXIS_IMPXY[3].Data(), cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigNxTagger(int binJetPt=0) {
  //if (binJetPt < 1) return; // 0 is inclusive jet pt
	std::vector<HistogramData> histNx;
  int flavour = 2; // bjet

  for (int binTagger=0; binTagger<HfJetTagging::numTaggerIP; binTagger++) {
    float cutImp = HfJetTagging::SYS::binsTaggerIP[binTagger];
    float effiN1 = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimTCjetSignImpXYSigN1[flavour][binJetPt], binJetPt, cutImp);
    if (effiN1 < 0) continue;
    hsimTCjetEffiTaggerPointN1[flavour][binJetPt]->SetBinContent(binTagger+1, effiN1);

    float effiN2 = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimTCjetSignImpXYSigN2[flavour][binJetPt], binJetPt, cutImp);
    if (effiN2 < 0) continue;
    hsimTCjetEffiTaggerPointN2[flavour][binJetPt]->SetBinContent(binTagger+1, effiN2);

    float effiN3 = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimTCjetSignImpXYSigN3[flavour][binJetPt], binJetPt, cutImp);
    if (effiN3 < 0) continue;
    hsimTCjetEffiTaggerPointN3[flavour][binJetPt]->SetBinContent(binTagger+1, effiN3);
  }
  histNx.push_back({hsimTCjetEffiTaggerPointN1[flavour][binJetPt], "N=1"});
  histNx.push_back({hsimTCjetEffiTaggerPointN2[flavour][binJetPt], "N=2"});
  histNx.push_back({hsimTCjetEffiTaggerPointN3[flavour][binJetPt], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP + HfJetTagging::binWidthTaggerIP, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", HfJetTagging::AXIS_BEAUTY_EFFI);
  canHan->drawCombined(histNx.size(), histNx, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN3x1(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimTCjetEffiSignImpXYSigN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimTCjetEffiSignImpXYSigN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimTCjetEffiSignImpXYSigN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  canHan = new CanvasHandler();
  canHan->createCanvas3x1(nc);
  for (int mpad=0; mpad<3; mpad++) {
    canHan->drawPad(normHist, false, nc, mpad, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
    latex.DrawLatex(0.2, 0.9, Form("N=%d", mpad+1));
    latex.DrawLatex(0.2, 0.86, Form("tagger point (sIPs)=%0.1f", cutImp));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN3x1.pdf\")", nc++, dirSim.Data()));
}

//void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigNX(float cutImp = 2.5) {
//}

void HfJetTaggingTCAnalysis::drawSimJetPurityN1(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //double purity = this->calculatePurity(flavour, binJetPt, hsimTCjetSignImpXYSigN1, cutImp);
      double purity = this->calculatePurity(flavour, binJetPt, hsimTCjetNormalizedSignImpXYSigN1, cutImp);
      hsimTCjetPurityN1[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimTCjetPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityN2(float cutImp=2.5) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //double purity = this->calculatePurity(flavour, binJetPt, hsimTCjetSignImpXYSigN2, cutImp);
      double purity = this->calculatePurity(flavour, binJetPt, hsimTCjetNormalizedSignImpXYSigN2, cutImp);
      hsimTCjetPurityN2[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimTCjetPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityN3(float cutImp=2.5) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //double purity = this->calculatePurity(flavour, binJetPt, hsimTCjetSignImpXYSigN3, cutImp);
      double purity = this->calculatePurity(flavour, binJetPt, hsimTCjetNormalizedSignImpXYSigN3, cutImp);
      hsimTCjetPurityN3[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimTCjetPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityNx(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimTCjetPurityN1[flavour], "N=1"});
	normHist.push_back({hsimTCjetPurityN2[flavour], "N=2"});
	normHist.push_back({hsimTCjetPurityN3[flavour], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_BEAUTY_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.045*7, Form("tagger point (%s)=%0.1f", HfJetTagging::X_AXIS_IMPXY[3].Data(), cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityNxTagger(int binJetPt=0) {
  //if (binJetPt < 1) return; // 0 is inclusive jet pt
	std::vector<HistogramData> histNx;
  int flavour = 2; // bjet

  for (int binTagger=0; binTagger<HfJetTagging::numTaggerIP; binTagger++) {
    float cutImp = HfJetTagging::SYS::binsTaggerIP[binTagger];
    double purityN1 = taggingutilities::getPurityDirect(flavour, binJetPt, hsimTCjetSignImpXYSigN1, cutImp);
    if (purityN1 < 0) continue;
    hsimTCjetPurityTaggerPointN1[flavour][binJetPt]->SetBinContent(binTagger+1, purityN1);

    double purityN2 = taggingutilities::getPurityDirect(flavour, binJetPt, hsimTCjetSignImpXYSigN2, cutImp);
    if (purityN2 < 0) continue;
    hsimTCjetPurityTaggerPointN2[flavour][binJetPt]->SetBinContent(binTagger+1, purityN2);

    double purityN3 = taggingutilities::getPurityDirect(flavour, binJetPt, hsimTCjetSignImpXYSigN3, cutImp);
    if (purityN3 < 0) continue;
    hsimTCjetPurityTaggerPointN3[flavour][binJetPt]->SetBinContent(binTagger+1, purityN3);
  }
  histNx.push_back({hsimTCjetPurityTaggerPointN1[flavour][binJetPt], "N=1"});
  histNx.push_back({hsimTCjetPurityTaggerPointN2[flavour][binJetPt], "N=2"});
  histNx.push_back({hsimTCjetPurityTaggerPointN3[flavour][binJetPt], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP+HfJetTagging::binWidthTaggerIP, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", HfJetTagging::AXIS_BEAUTY_PURITY);
  canHan->drawCombined(histNx.size(), histNx, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityN3x1(float cutImp=2.5) {
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimTCjetPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimTCjetPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimTCjetPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  canHan = new CanvasHandler();
  canHan->createCanvas3x1(nc);
  for (int mpad=0; mpad<3; mpad++) {
    canHan->drawPad(normHist, false, nc, mpad, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
    latex.DrawLatex(0.2, 0.9, Form("N=%d", mpad+1));
    latex.DrawLatex(0.2, 0.86, Form("tagging point=%0.1f", cutImp));
  }
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN3x1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiAndPurityNxTagger(int binJetPt) {
  if (binJetPt < 1) return; // 0 is inclusive jet pt
	std::vector<HistogramData> histNx;
  int flavour = 2; // bjet

  for (int binTagger=0; binTagger<HfJetTagging::numTaggerIP; binTagger++) {
    float cutImp = HfJetTagging::SYS::binsTaggerIP[binTagger];
    double effiN1 = hsimTCjetEffiTaggerPointN1[flavour][binJetPt]->GetBinContent(binTagger+1);
    double effiN2 = hsimTCjetEffiTaggerPointN2[flavour][binJetPt]->GetBinContent(binTagger+1);
    double effiN3 = hsimTCjetEffiTaggerPointN3[flavour][binJetPt]->GetBinContent(binTagger+1);
    double purityN1 = hsimTCjetPurityTaggerPointN1[flavour][binJetPt]->GetBinContent(binTagger+1);
    double purityN2 = hsimTCjetPurityTaggerPointN2[flavour][binJetPt]->GetBinContent(binTagger+1);
    double purityN3 = hsimTCjetPurityTaggerPointN3[flavour][binJetPt]->GetBinContent(binTagger+1);
    hsimTCjetEffiAndPurityTaggerPointN1[flavour][binJetPt]->SetBinContent(binTagger+1, purityN1 / effiN1);
    hsimTCjetEffiAndPurityTaggerPointN2[flavour][binJetPt]->SetBinContent(binTagger+1, purityN2 / effiN2);
    hsimTCjetEffiAndPurityTaggerPointN3[flavour][binJetPt]->SetBinContent(binTagger+1, purityN3 / effiN3);
  }
  histNx.push_back({hsimTCjetEffiAndPurityTaggerPointN1[flavour][binJetPt], "N=1"});
  histNx.push_back({hsimTCjetEffiAndPurityTaggerPointN2[flavour][binJetPt], "N=2"});
  histNx.push_back({hsimTCjetEffiAndPurityTaggerPointN3[flavour][binJetPt], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3]*10, "tagger point (#it{S}_{xy})", HfJetTagging::AXIS_BEAUTY_PURITY);
  canHan->drawCombined(histNx.size(), histNx, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiAndPurityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}


#endif // HFJETTAGGINGTCANALYSIS_H 
