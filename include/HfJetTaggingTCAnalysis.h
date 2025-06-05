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
    HfJetTaggingTCAnalysis() : HfJetTaggingAnalysis() {
      initConfig();
    }
    ~HfJetTaggingTCAnalysis();

    // function
    /// basic
    void initConfig();

    // tc hist
    /// data
    int loadDataTCQA(TString rootData);
    void initHistTCData();
    void projectionHistTCQAData();
    void initTCData(TString rootData);

    /// mc
    int loadSimTCQA(TString rootSim);
    void initHistTCMC();
    void projectionHistTCQAMC();
    void initTCMC(TString rootSim);

    void saveHistogramTCQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // Set
    void setFillEffi(bool fillEffi);
    void setFillTest(bool fillTest);

    // Calculation
    double calculateEffiSignedImpXYSig(TH1F* huntagjet, TH1F* htagjet, int binJetPt, float cutImp);
    double calculatePurity(int flavour, int binJetPt, TH1F* htagjet[][HfJetTagging::nBinsJetPt+1], float cutImp);

    // Draw
    std::vector<HistogramData> histList;
    void drawDataJetSignImpXYSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawDataJetSignImpXYSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawDataJetSignImpXYSignificanceN3(bool withInc, bool doLog, int binJetPt);

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

    // histogram
    //TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    //TH1F* hsimjetSignImpXYSigRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigRun2DefN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigRun2DefN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigRun2DefN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  protected:
    int nc = 10000;
    CanvasHandler* canHan;
    // Histogram
    /// Data

    /// MC
    //TH3F* h3simjetPtSignImpXYSigFlavour;
    TH3F* h3simjetPtSignImpXYSigFlavourN1;
    TH3F* h3simjetPtSignImpXYSigFlavourN2;
    TH3F* h3simjetPtSignImpXYSigFlavourN3;
    //TH3F* h3simjetPtSignImpZSigFlavour;
    TH3F* h3simjetPtSignImpZSigFlavourN1;
    TH3F* h3simjetPtSignImpZSigFlavourN2;
    TH3F* h3simjetPtSignImpZSigFlavourN3;
    //TH3F* h3simjetPtSignImpXYZSigFlavour;
    TH3F* h3simjetPtSignImpXYZSigFlavourN1;
    TH3F* h3simjetPtSignImpXYZSigFlavourN2;
    TH3F* h3simjetPtSignImpXYZSigFlavourN3;
    //TH3F* h3simjetPtSignImpXYSigFlavourRun2Def;
    TH3F* h3simjetPtSignImpXYSigFlavourRun2DefN1;
    TH3F* h3simjetPtSignImpXYSigFlavourRun2DefN2;
    TH3F* h3simjetPtSignImpXYSigFlavourRun2DefN3;

    //// Normalized
    TH1F* hsimjetNormNEventsSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjetNormNEventsSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjetNormNEventsSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYZSigN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYZSigN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYZSigN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    // Reconstruction efficience and purity
    TH1F* hsimjetEffiTaggerPointN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetEffiTaggerPointN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetEffiTaggerPointN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetEffiNoTagger[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEffiSignImpXYSigN1[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEffiSignImpXYSigN2[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEffiSignImpXYSigN3[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPurityTaggerPointN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetPurityTaggerPointN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetPurityTaggerPointN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPurityN3[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEffiAndPurityTaggerPointN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetEffiAndPurityTaggerPointN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetEffiAndPurityTaggerPointN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjetEffiSignImpXYSigRun2DefN1[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEffiSignImpXYSigRun2DefN2[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEffiSignImpXYSigRun2DefN3[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPurityRun2DefN1[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPurityRun2DefN2[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPurityRun2DefN3[HfJetTagging::nFlavour+1];

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

void HfJetTaggingTCAnalysis::initHistTCData() {
}

void HfJetTaggingTCAnalysis::projectionHistTCQAData() {
}
void HfJetTaggingTCAnalysis::initTCData(TString rootData) {
  loadDataTCQA(rootData.Data());
  initHistTCData();
  projectionHistTCQAData();
  //rebinHistMCTCQAMC();
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
      //h3simjetPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
      h3simjetPtSignImpXYSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
      h3simjetPtSignImpXYSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
      h3simjetPtSignImpXYSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
    }
    if (fillIPz) {
      //h3simjetPtSignImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
      h3simjetPtSignImpZSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
      h3simjetPtSignImpZSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
      h3simjetPtSignImpZSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
    }
    if (fillIPxyz) {
      //h3simjetPtSignImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
      h3simjetPtSignImpXYZSigFlavourN1 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskName.Data())));
      h3simjetPtSignImpXYZSigFlavourN2 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskName.Data())));
      h3simjetPtSignImpXYZSigFlavourN3 = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskName.Data())));
    }
  }
  if (fillMCP) {
    // std
  }

  return 1;
}

void HfJetTaggingTCAnalysis::initHistTCMC() {
  if (fillMCD) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      if (fillEffi) {
        hsimjetEffiSignImpXYSigN1[flavour] = new TH1F(Form("hsimjetEffiSignImpXYSigN1_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimjetEffiSignImpXYSigN2[flavour] = new TH1F(Form("hsimjetEffiSignImpXYSigN2_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimjetEffiSignImpXYSigN3[flavour] = new TH1F(Form("hsimjetEffiSignImpXYSigN3_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimjetPurityN1[flavour] = new TH1F(Form("hsimjetPurityN1_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimjetPurityN2[flavour] = new TH1F(Form("hsimjetPurityN2_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimjetPurityN3[flavour] = new TH1F(Form("hsimjetPurityN3_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt; binJetPt++) {
          hsimjetEffiTaggerPointN1[flavour][binJetPt] = new TH1F(Form("hsimjetEffiTaggerPointN1_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetEffiTaggerPointN2[flavour][binJetPt] = new TH1F(Form("hsimjetEffiTaggerPointN2_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetEffiTaggerPointN3[flavour][binJetPt] = new TH1F(Form("hsimjetEffiTaggerPointN3_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetPurityTaggerPointN1[flavour][binJetPt] = new TH1F(Form("hsimjetPurityTaggerPointN1_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetPurityTaggerPointN2[flavour][binJetPt] = new TH1F(Form("hsimjetPurityTaggerPointN2_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetPurityTaggerPointN3[flavour][binJetPt] = new TH1F(Form("hsimjetPurityTaggerPointN3_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetEffiAndPurityTaggerPointN1[flavour][binJetPt] = new TH1F(Form("hsimjetEffiAndPurityTaggerPointN1_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetEffiAndPurityTaggerPointN2[flavour][binJetPt] = new TH1F(Form("hsimjetEffiAndPurityTaggerPointN2_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
          hsimjetEffiAndPurityTaggerPointN3[flavour][binJetPt] = new TH1F(Form("hsimjetEffiAndPurityTaggerPointN3_%d_%d", flavour, binJetPt), "", HfJetTagging::numTaggerIP, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP);
        }
      }
      if (fillTest) {
        hsimjetEffiNoTagger[flavour] = new TH1F(Form("hsimjetEffiNoTagger_%d", flavour), "",  HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      }
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillIPxy) {
          //hsimjetSignImpXYSig[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYSigFlavour->GetNbinsY(), h3simjetPtSignImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour->GetNbinsY()));
          hsimjetSignImpXYSigN1[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYSigN1_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYSigFlavourN1->GetNbinsY(), h3simjetPtSignImpXYSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavourN1->GetNbinsY()));
          hsimjetSignImpXYSigN2[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYSigN2_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYSigFlavourN2->GetNbinsY(), h3simjetPtSignImpXYSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavourN2->GetNbinsY()));
          hsimjetSignImpXYSigN3[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYSigN3_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYSigFlavourN3->GetNbinsY(), h3simjetPtSignImpXYSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavourN3->GetNbinsY()));
        }
        if (fillIPz) {
          //hsimjetSignImpZSig[flavour][jetPt] = new TH1F(Form("hsimjetSignImpZSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpZSigFlavour->GetNbinsY(), h3simjetPtSignImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigFlavour->GetNbinsY()));
          hsimjetSignImpZSigN1[flavour][jetPt] = new TH1F(Form("hsimjetSignImpZSigN1_%d_%d", flavour, jetPt), "", h3simjetPtSignImpZSigFlavourN1->GetNbinsY(), h3simjetPtSignImpZSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigFlavourN1->GetNbinsY()));
          hsimjetSignImpZSigN2[flavour][jetPt] = new TH1F(Form("hsimjetSignImpZSigN2_%d_%d", flavour, jetPt), "", h3simjetPtSignImpZSigFlavourN2->GetNbinsY(), h3simjetPtSignImpZSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigFlavourN2->GetNbinsY()));
          hsimjetSignImpZSigN3[flavour][jetPt] = new TH1F(Form("hsimjetSignImpZSigN3_%d_%d", flavour, jetPt), "", h3simjetPtSignImpZSigFlavourN3->GetNbinsY(), h3simjetPtSignImpZSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigFlavourN3->GetNbinsY()));
        }
        if (fillIPxyz) {
          //hsimjetSignImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYZSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYZSigFlavour->GetNbinsY(), h3simjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigFlavour->GetNbinsY()));
          hsimjetSignImpXYZSigN1[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYZSigN1_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYZSigFlavourN1->GetNbinsY(), h3simjetPtSignImpXYZSigFlavourN1->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigFlavourN1->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigFlavourN1->GetNbinsY()));
          hsimjetSignImpXYZSigN2[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYZSigN2_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYZSigFlavourN2->GetNbinsY(), h3simjetPtSignImpXYZSigFlavourN2->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigFlavourN2->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigFlavourN2->GetNbinsY()));
          hsimjetSignImpXYZSigN3[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYZSigN3_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYZSigFlavourN3->GetNbinsY(), h3simjetPtSignImpXYZSigFlavourN3->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigFlavourN3->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigFlavourN3->GetNbinsY()));
        }
      }
    }
  }
  if (fillMCP) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillIPxy) {
          //std 
        }
      }
    }
  }
}

void HfJetTaggingTCAnalysis::projectionHistTCQAMC() {
  if (fillMCD) {
    HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      if (fillIPxy) {
        //TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binFlavour), 1, h3simjetPtSignImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigN1 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavourN1->ProjectionY(Form("projSignImpXYSigN1_%d", binFlavour), 1, h3simjetPtSignImpXYSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigN2 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavourN2->ProjectionY(Form("projSignImpXYSigN2_%d", binFlavour), 1, h3simjetPtSignImpXYSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigN3 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavourN3->ProjectionY(Form("projSignImpXYSigN3_%d", binFlavour), 1, h3simjetPtSignImpXYSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
        //hsimjetSignImpXYSig[0][0]->Add(projSignImpXYSig);
        hsimjetSignImpXYSigN1[0][0]->Add(projSignImpXYSigN1);
        hsimjetSignImpXYSigN2[0][0]->Add(projSignImpXYSigN2);
        hsimjetSignImpXYSigN3[0][0]->Add(projSignImpXYSigN3);
        //hsimjetSignImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone(Form("hsimjetSignImpXYSig_%d_0", flavour)));
        hsimjetSignImpXYSigN1[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN1->Clone(Form("hsimjetSignImpXYSigN1_%d_0", flavour)));
        hsimjetSignImpXYSigN2[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN2->Clone(Form("hsimjetSignImpXYSigN2_%d_0", flavour)));
        hsimjetSignImpXYSigN3[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN3->Clone());
      }
      if (fillIPz) {
        //TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigFlavour->ProjectionY(Form("projSignImpZSig_%d", binFlavour), 1, h3simjetPtSignImpZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSigN1 = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigFlavourN1->ProjectionY(Form("projSignImpZSigN1_%d", binFlavour), 1, h3simjetPtSignImpZSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSigN2 = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigFlavourN2->ProjectionY(Form("projSignImpZSigN2_%d", binFlavour), 1, h3simjetPtSignImpZSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSigN3 = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigFlavourN3->ProjectionY(Form("projSignImpZSigN3_%d", binFlavour), 1, h3simjetPtSignImpZSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
        //hsimjetSignImpZSig[0][0]->Add(projSignImpZSig);
        hsimjetSignImpZSigN1[0][0]->Add(projSignImpZSigN1);
        hsimjetSignImpZSigN2[0][0]->Add(projSignImpZSigN2);
        hsimjetSignImpZSigN3[0][0]->Add(projSignImpZSigN3);
        //hsimjetSignImpZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone());
        hsimjetSignImpZSigN1[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN1->Clone());
        hsimjetSignImpZSigN2[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN2->Clone(Form("hsimjetSignImpZSigN2_%d_0", flavour)));
        hsimjetSignImpZSigN3[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN3->Clone());
      }
      if (fillIPxyz) {
        //TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigFlavour->ProjectionY(Form("projSignImpXYZSig_%d", binFlavour), 1, h3simjetPtSignImpXYZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSigN1 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigFlavourN1->ProjectionY(Form("projSignImpXYZSigN1_%d", binFlavour), 1, h3simjetPtSignImpXYZSigFlavourN1->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSigN2 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigFlavourN2->ProjectionY(Form("projSignImpXYZSigN2_%d", binFlavour), 1, h3simjetPtSignImpXYZSigFlavourN2->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSigN3 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigFlavourN3->ProjectionY(Form("projSignImpXYZSigN3_%d", binFlavour), 1, h3simjetPtSignImpXYZSigFlavourN3->GetNbinsX(), binFlavour, binFlavour));
        //hsimjetSignImpXYZSig[0][0]->Add(projSignImpXYZSig);
        hsimjetSignImpXYZSigN1[0][0]->Add(projSignImpXYZSigN1);
        hsimjetSignImpXYZSigN2[0][0]->Add(projSignImpXYZSigN2);
        hsimjetSignImpXYZSigN3[0][0]->Add(projSignImpXYZSigN3);
        //hsimjetSignImpXYZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone());
        hsimjetSignImpXYZSigN1[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN1->Clone());
        hsimjetSignImpXYZSigN2[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN2->Clone());
        hsimjetSignImpXYZSigN3[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN3->Clone());
      }

      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (fillIPxy) {
//          int leftbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
//          int rightbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
//          TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binFlavour, binFlavour));
//          hsimjetSignImpXYSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone(Form("hsimjetSignImpXYSig_%d_%d", flavour, binJetPt)));
//          hsimjetSignImpXYSig[0][binJetPt]->Add(projJetPtRangeSignImpXYSig);

          int leftbinJetPtSignImpXYSigN1 = h3simjetPtSignImpXYSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSigN1 = h3simjetPtSignImpXYSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSigN1 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpXYSigN1_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSigN1, rightbinJetPtSignImpXYSigN1, binFlavour, binFlavour));
          hsimjetSignImpXYSigN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN1->Clone(Form("hsimjetSignImpXYSigN1_%d_%d", flavour, binJetPt)));
          hsimjetSignImpXYSigN1[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN1);

          int leftbinJetPtSignImpXYSigN2 = h3simjetPtSignImpXYSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSigN2 = h3simjetPtSignImpXYSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSigN2 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpXYSigN2_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSigN2, rightbinJetPtSignImpXYSigN2, binFlavour, binFlavour));
          hsimjetSignImpXYSigN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN2->Clone(Form("hsimjetSignImpXYSigN2_%d_%d", flavour, binJetPt)));
          hsimjetSignImpXYSigN2[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN2);

          int leftbinJetPtSignImpXYSigN3 = h3simjetPtSignImpXYSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSigN3 = h3simjetPtSignImpXYSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSigN3 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpXYSigN3_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYSigN3, rightbinJetPtSignImpXYSigN3, binFlavour, binFlavour));
          hsimjetSignImpXYSigN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN3->Clone());
          hsimjetSignImpXYSigN3[0][binJetPt]->Add(projJetPtRangeSignImpXYSigN3);
        }
        if (fillIPz) {
//          int leftbinJetPtSignImpZSig = h3simjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
//          int rightbinJetPtSignImpZSig = h3simjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
//          TH1F* projJetPtRangeSignImpZSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpZSig_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, binFlavour, binFlavour));
//          hsimjetSignImpZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSig->Clone(Form("hsimjetSignImpZSig_%d_%d", flavour, binJetPt)));
//          hsimjetSignImpZSig[0][binJetPt]->Add(projJetPtRangeSignImpZSig);

          int leftbinJetPtSignImpZSigN1 = h3simjetPtSignImpZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSigN1 = h3simjetPtSignImpZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSigN1 = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpZSigN1_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSigN1, rightbinJetPtSignImpZSigN1, binFlavour, binFlavour));
          hsimjetSignImpZSigN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN1->Clone());
          hsimjetSignImpZSigN1[0][binJetPt]->Add(projJetPtRangeSignImpZSigN1);

          int leftbinJetPtSignImpZSigN2 = h3simjetPtSignImpZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSigN2 = h3simjetPtSignImpZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSigN2 = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpZSigN2_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSigN2, rightbinJetPtSignImpZSigN2, binFlavour, binFlavour));
          hsimjetSignImpZSigN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN2->Clone());
          hsimjetSignImpZSigN2[0][binJetPt]->Add(projJetPtRangeSignImpZSigN2);

          int leftbinJetPtSignImpZSigN3 = h3simjetPtSignImpZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSigN3 = h3simjetPtSignImpZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSigN3 = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpZSigN3_%d_%d", binJetPt, flavour), leftbinJetPtSignImpZSigN3, rightbinJetPtSignImpZSigN3, binFlavour, binFlavour));
          hsimjetSignImpZSigN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN3->Clone());
          hsimjetSignImpZSigN3[0][binJetPt]->Add(projJetPtRangeSignImpZSigN3);
        }
        if (fillIPxyz) {
//          int leftbinJetPtSignImpXYZSig = h3simjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
//          int rightbinJetPtSignImpXYZSig = h3simjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
//          TH1F* projJetPtRangeSignImpXYZSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZSig_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, binFlavour, binFlavour));
//          hsimjetSignImpXYZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSig->Clone(Form("hsimjetSignImpXYZSig_%d_%d", flavour, binJetPt)));
//          hsimjetSignImpXYZSig[0][binJetPt]->Add(projJetPtRangeSignImpXYZSig);

          int leftbinJetPtSignImpXYZSigN1 = h3simjetPtSignImpXYZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSigN1 = h3simjetPtSignImpXYZSigFlavourN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSigN1 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigFlavourN1->ProjectionY(Form("projJetPtRagneSignImpXYZSigN1_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSigN1, rightbinJetPtSignImpXYZSigN1, binFlavour, binFlavour));
          hsimjetSignImpXYZSigN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN1->Clone());
          hsimjetSignImpXYZSigN1[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN1);

          int leftbinJetPtSignImpXYZSigN2 = h3simjetPtSignImpXYZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSigN2 = h3simjetPtSignImpXYZSigFlavourN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSigN2 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigFlavourN2->ProjectionY(Form("projJetPtRagneSignImpXYZSigN2_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSigN2, rightbinJetPtSignImpXYZSigN2, binFlavour, binFlavour));
          hsimjetSignImpXYZSigN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN2->Clone());
          hsimjetSignImpXYZSigN2[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN2);

          int leftbinJetPtSignImpXYZSigN3 = h3simjetPtSignImpXYZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSigN3 = h3simjetPtSignImpXYZSigFlavourN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSigN3 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigFlavourN3->ProjectionY(Form("projJetPtRagneSignImpXYZSigN3_%d_%d", binJetPt, flavour), leftbinJetPtSignImpXYZSigN3, rightbinJetPtSignImpXYZSigN3, binFlavour, binFlavour));
          hsimjetSignImpXYZSigN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN3->Clone());
          hsimjetSignImpXYZSigN3[0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN3);
        }
      }
    }
  }
}

void HfJetTaggingTCAnalysis::initTCMC(TString rootSim) {
  loadSimTCQA(rootSim.Data());
  initHistTCMC();
  projectionHistTCQAMC();
  //rebinHistMCTCQAMC();
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
          hsimjetSignImpXYSigN1[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYSigN2[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYSigN3[binFlavour][binJetPt]->Write();
          hsimjetSignImpZSigN1[binFlavour][binJetPt]->Write();
          hsimjetSignImpZSigN2[binFlavour][binJetPt]->Write();
          hsimjetSignImpZSigN3[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYZSigN1[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYZSigN2[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYZSigN3[binFlavour][binJetPt]->Write();
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
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN1[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYSigN1[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYSigN1[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN1[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYSigN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN1[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYSigN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  //latex.DrawLatex(0.7, 0.7, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latex.DrawLatex(0.67, 0.65, Form("#scale[1.5]{1^{st} largest %s}", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  //latex.DrawLatex(0.7, 0.7, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latex.DrawLatex(0.67, 0.65, Form("#scale[1.5]{1^{st} largest %s}", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[0] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN2[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYSigN2[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYSigN2[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN2[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYSigN2[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN2[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYSigN2[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[1] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[1] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN2NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN3(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN3[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYSigN3[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYSigN3[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN3[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYSigN3[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSigN3[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYSigN3[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::X_AXIS_IMPXY[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[2] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::X_AXIS_IMPXY[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  numCanXYNX[2] = nc;
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceN3NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYSignificanceN3x1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListN1;
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

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
  histList.push_back({hsimjetNormAreaSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimjetNormAreaSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimjetNormAreaSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimjetNormAreaSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN1;
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[0][binJetPt], HfJetTagging::INCJET});
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[1][binJetPt], HfJetTagging::CJET});
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[2][binJetPt], HfJetTagging::BJET});
  histListN1.push_back({hsimjetNormAreaSignImpXYSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[0][binJetPt], HfJetTagging::INCJET});
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[1][binJetPt], HfJetTagging::CJET});
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[2][binJetPt], HfJetTagging::BJET});
  histListN2.push_back({hsimjetNormAreaSignImpXYSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[0][binJetPt], HfJetTagging::INCJET});
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[1][binJetPt], HfJetTagging::CJET});
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[2][binJetPt], HfJetTagging::BJET});
  histListN3.push_back({hsimjetNormAreaSignImpXYSigN3[3][binJetPt], HfJetTagging::LFJET});

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

void HfJetTaggingTCAnalysis::drawSimJetSignImpZSignificanceN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpZSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN1[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpZSigN1[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpZSigN1[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpZSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN1[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpZSigN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpZSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN1[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpZSigN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpZSigN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpZSigN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpZSigN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpZSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpZSignificanceN2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpZSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN2[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpZSigN2[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpZSigN2[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpZSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN2[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpZSigN2[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpZSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN2[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpZSigN2[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpZSigN2[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpZSigN2[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpZSigN2[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpZSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN2[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN2[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN2[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN2[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN2[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN2[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN2NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingTCAnalysis::drawSimJetSignImpZSignificanceN3(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpZSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN3[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpZSigN3[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpZSigN3[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpZSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN3[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpZSigN3[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpZSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSigN3[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpZSigN3[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpZSigN3[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpZSigN3[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpZSigN3[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpZSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN3[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN3[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpZSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN3[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN3[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN3[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN3[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::X_AXIS_IMPZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::X_AXIS_IMPZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXY[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceN3NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYZSignificanceN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYZSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN1[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYZSigN1[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYZSigN1[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYZSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN1[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYZSigN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYZSigN1[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN1[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYZSigN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYZSigN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYZSigN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYZSigN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYZSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("1^{st} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYZSignificanceN2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYZSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN2[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYZSigN2[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYZSigN2[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYZSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN2[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYZSigN2[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYZSigN2[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN2[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYZSigN2[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYZSigN2[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYZSigN2[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYZSigN2[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYZSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN2[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN2[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN2[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN2[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN2[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN2[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN2[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("2^{nd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN2NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingTCAnalysis::drawSimJetSignImpXYZSignificanceN3(bool withInc = false, bool doLog = true, int binJetPt=0){
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYZSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN3[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYZSigN3[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYZSigN3[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYZSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN3[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYZSigN3[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYZSigN3[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSigN3[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYZSigN3[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYZSigN3[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYZSigN3[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYZSigN3[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYZSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN3[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN3[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN3[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN3[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSigN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN3[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN3[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN3[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSigN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.2, 0.9-0.24, Form("3^{rd} largest %s", HfJetTagging::X_AXIS_IMPXYZ[3].Data()));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceN3NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

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
  std::cout << "Efficiency of IP for N1" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetEffiSignImpXYSigN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = hsimjetSignImpXYSigN1[flavour][binJetPt]->Integral(hsimjetSignImpXYSigN1[flavour][binJetPt]->FindBin(cutImp), -1);
      if (effi <0.001) continue;
      effi = effi / hsimjetSignImpXYSigN1[flavour][binJetPt]->Integral(1, -1);
      if (effi < 0) continue;
      hsimjetEffiSignImpXYSigN1[flavour]->SetBinContent(binJetPt, effi);
      hsimjetEffiSignImpXYSigN1[flavour]->SetBinError(binJetPt, 0); // TODO
    }
	  histList.push_back({hsimjetEffiSignImpXYSigN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("1^{st} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN2(float cutImp = 2.5) {
  std::cout << "Efficiency of IP for N2" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetEffiSignImpXYSigN2[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = hsimjetSignImpXYSigN2[flavour][binJetPt]->Integral(hsimjetSignImpXYSigN2[flavour][binJetPt]->FindBin(cutImp), -1);
      if (effi <0.001) continue;
      effi = effi / hsimjetSignImpXYSigN2[flavour][binJetPt]->Integral(1, -1);
      if (effi < 0) continue;
      hsimjetEffiSignImpXYSigN2[flavour]->SetBinContent(binJetPt, effi);
      hsimjetEffiSignImpXYSigN2[flavour]->SetBinError(binJetPt, 0);
    }
	  histList.push_back({hsimjetEffiSignImpXYSigN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("2^{nd} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN3(float cutImp = 2.5) {
  std::cout << "Efficiency of IP for N3" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetEffiSignImpXYSigN3[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = hsimjetSignImpXYSigN3[flavour][binJetPt]->Integral(hsimjetSignImpXYSigN3[flavour][binJetPt]->FindBin(cutImp), -1);
      if (effi <0.001) continue;
      effi = effi / hsimjetSignImpXYSigN3[flavour][binJetPt]->Integral(1, -1);
      if (effi < 0) continue;
      hsimjetEffiSignImpXYSigN3[flavour]->SetBinContent(binJetPt, effi);
      hsimjetEffiSignImpXYSigN3[flavour]->SetBinError(binJetPt, 0);
    }
	  histList.push_back({hsimjetEffiSignImpXYSigN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("3^{rd} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigNx(float cutImp = 2.5) {
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimjetEffiSignImpXYSigN1[flavour], "N=1"});
	normHist.push_back({hsimjetEffiSignImpXYSigN2[flavour], "N=2"});
	normHist.push_back({hsimjetEffiSignImpXYSigN3[flavour], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_BEAUTY_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  //latex.DrawLatex(0.17, 0.89-0.055*4, Form("3^{rd} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigNxTagger(int binJetPt=0) {
  //if (binJetPt < 1) return; // 0 is inclusive jet pt
	std::vector<HistogramData> histNx;
  int flavour = 2; // bjet

  for (int binTagger=0; binTagger<HfJetTagging::numTaggerIP; binTagger++) {
    float cutImp = HfJetTagging::SYS::binsTaggerIP[binTagger];
    float effiN1 = hsimjetSignImpXYSigN1[flavour][binJetPt]->Integral(hsimjetSignImpXYSigN1[flavour][binJetPt]->FindBin(cutImp), -1);
    if (effiN1 <0.001) continue;
    effiN1 = effiN1 / hsimjetSignImpXYSigN1[flavour][binJetPt]->Integral(1, -1);
    if (effiN1 < 0) continue;
    hsimjetEffiTaggerPointN1[flavour][binJetPt]->SetBinContent(binTagger+1, effiN1);
    hsimjetEffiTaggerPointN1[flavour][binJetPt]->SetBinError(binTagger+1, 0); // TODO

    float effiN2 = hsimjetSignImpXYSigN2[flavour][binJetPt]->Integral(hsimjetSignImpXYSigN2[flavour][binJetPt]->FindBin(cutImp), -1);
    if (effiN2 <0.001) continue;
    effiN2 = effiN2 / hsimjetSignImpXYSigN2[flavour][binJetPt]->Integral(1, -1);
    if (effiN2 < 0) continue;
    hsimjetEffiTaggerPointN2[flavour][binJetPt]->SetBinContent(binTagger+1, effiN2);
    hsimjetEffiTaggerPointN2[flavour][binJetPt]->SetBinError(binTagger+1, 0); // TODO

    float effiN3 = hsimjetSignImpXYSigN3[flavour][binJetPt]->Integral(hsimjetSignImpXYSigN3[flavour][binJetPt]->FindBin(cutImp), -1);
    if (effiN3 <0.001) continue;
    effiN3 = effiN3 / hsimjetSignImpXYSigN3[flavour][binJetPt]->Integral(1, -1);
    if (effiN3 < 0) continue;
    hsimjetEffiTaggerPointN3[flavour][binJetPt]->SetBinContent(binTagger+1, effiN3);
    hsimjetEffiTaggerPointN3[flavour][binJetPt]->SetBinError(binTagger+1, 0); // TODO
  }
  histNx.push_back({hsimjetEffiTaggerPointN1[flavour][binJetPt], "N=1"});
  histNx.push_back({hsimjetEffiTaggerPointN2[flavour][binJetPt], "N=2"});
  histNx.push_back({hsimjetEffiTaggerPointN3[flavour][binJetPt], "N=3"});
  canHan = new CanvasHandler();
  //canHan->createCanvas(nc);
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP + HfJetTagging::binWidthTaggerIP, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (sIPs)", HfJetTagging::AXIS_BEAUTY_EFFI);
  canHan->drawCombined(histNx.size(), histNx, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingTCAnalysis::drawSimJetEffiSignImpXYSigN3x1(float cutImp = 2.5) {
  // This figures do not need
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimjetEffiSignImpXYSigN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimjetEffiSignImpXYSigN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimjetEffiSignImpXYSigN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
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
  std::cout << "Purity of IP for N1" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetPurityN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjetSignImpXYSigN1, cutImp);
      if (purity < 0) continue;
      hsimjetPurityN1[flavour]->SetBinContent(binJetPt, purity);
      hsimjetPurityN1[flavour]->SetBinError(binJetPt, 0); // TODO
    }
	  histList.push_back({hsimjetPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("1^{st} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityN2(float cutImp=2.5) {
  std::cout << "Purity of IP for N2" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetPurityN2[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //double purity = this->calculatePurity(flavour, binJetPt, hsimjetSignImpXYSigN2, cutImp);
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjetSignImpXYSigN2, cutImp);
      if (purity < 0) continue;
      hsimjetPurityN2[flavour]->SetBinContent(binJetPt, purity);
      hsimjetPurityN2[flavour]->SetBinError(binJetPt, 0); // TODO
    }
	  histList.push_back({hsimjetPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("2^{nd} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityN3(float cutImp=2.5) {
  std::cout << "Purity of IP for N3" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetPurityN3[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjetSignImpXYSigN3, cutImp);
      if (purity < 0) continue;
      hsimjetPurityN3[flavour]->SetBinContent(binJetPt, purity);
      hsimjetPurityN3[flavour]->SetBinError(binJetPt, 0); // TODO
    }
	  histList.push_back({hsimjetPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("3^{rd} largest candidate (sIPs > %0.1f)", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityNx(float cutImp = 2.5) {
  std::cout << "Purity of IP for Nx" << std::endl;
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimjetPurityN1[flavour], "N=1"});
	normHist.push_back({hsimjetPurityN2[flavour], "N=2"});
	normHist.push_back({hsimjetPurityN3[flavour], "N=3"});
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
    float purityN1 = taggingutilities::getPurity(flavour, binJetPt, hsimjetSignImpXYSigN1, cutImp);
    if (purityN1 < 0) continue;
    hsimjetPurityTaggerPointN1[flavour][binJetPt]->SetBinContent(binTagger+1, purityN1);
    hsimjetPurityTaggerPointN1[flavour][binJetPt]->SetBinError(binTagger+1, 0); // TODO

    float purityN2 = taggingutilities::getPurity(flavour, binJetPt, hsimjetSignImpXYSigN2, cutImp);
    if (purityN2 < 0) continue;
    hsimjetPurityTaggerPointN2[flavour][binJetPt]->SetBinContent(binTagger+1, purityN2);
    hsimjetPurityTaggerPointN2[flavour][binJetPt]->SetBinError(binTagger+1, 0); // TODO

    float purityN3 = taggingutilities::getPurity(flavour, binJetPt, hsimjetSignImpXYSigN3, cutImp);
    if (purityN3 < 0) continue;
    hsimjetPurityTaggerPointN3[flavour][binJetPt]->SetBinContent(binTagger+1, purityN3);
    hsimjetPurityTaggerPointN3[flavour][binJetPt]->SetBinError(binTagger+1, 0); // TODO
  }
  histNx.push_back({hsimjetPurityTaggerPointN1[flavour][binJetPt], "N=1"});
  histNx.push_back({hsimjetPurityTaggerPointN2[flavour][binJetPt], "N=2"});
  histNx.push_back({hsimjetPurityTaggerPointN3[flavour][binJetPt], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::xlowTaggerIP, HfJetTagging::xupTaggerIP+HfJetTagging::binWidthTaggerIP, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", HfJetTagging::AXIS_BEAUTY_PURITY);
  canHan->drawCombined(histNx.size(), histNx, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingTCAnalysis::drawSimJetPurityN3x1(float cutImp=2.5) {
  // NO NEED
	std::vector<HistogramData> normHist;
  int flavour = 2; // bjet
	normHist.push_back({hsimjetPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimjetPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
	normHist.push_back({hsimjetPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
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
    double effiN1 = hsimjetEffiTaggerPointN1[flavour][binJetPt]->GetBinContent(binTagger+1);
    double effiN2 = hsimjetEffiTaggerPointN2[flavour][binJetPt]->GetBinContent(binTagger+1);
    double effiN3 = hsimjetEffiTaggerPointN3[flavour][binJetPt]->GetBinContent(binTagger+1);
    double purityN1 = hsimjetPurityTaggerPointN1[flavour][binJetPt]->GetBinContent(binTagger+1);
    double purityN2 = hsimjetPurityTaggerPointN2[flavour][binJetPt]->GetBinContent(binTagger+1);
    double purityN3 = hsimjetPurityTaggerPointN3[flavour][binJetPt]->GetBinContent(binTagger+1);
    hsimjetEffiAndPurityTaggerPointN1[flavour][binJetPt]->SetBinContent(binTagger+1, purityN1 / effiN1);
    hsimjetEffiAndPurityTaggerPointN2[flavour][binJetPt]->SetBinContent(binTagger+1, purityN2 / effiN2);
    hsimjetEffiAndPurityTaggerPointN3[flavour][binJetPt]->SetBinContent(binTagger+1, purityN3 / effiN3);
  }
  histNx.push_back({hsimjetEffiAndPurityTaggerPointN1[flavour][binJetPt], "N=1"});
  histNx.push_back({hsimjetEffiAndPurityTaggerPointN2[flavour][binJetPt], "N=2"});
  histNx.push_back({hsimjetEffiAndPurityTaggerPointN3[flavour][binJetPt], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3]*10, "tagger point (#it{S}_{xy})", HfJetTagging::AXIS_BEAUTY_PURITY);
  canHan->drawCombined(histNx.size(), histNx, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiAndPurityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

#endif // HFJETTAGGINGTCANALYSIS_H 
