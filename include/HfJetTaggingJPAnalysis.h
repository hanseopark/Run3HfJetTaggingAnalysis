#ifndef HFJETTAGGINGJPANALYSIS_H
#define HFJETTAGGINGJPANALYSIS_H

#include "TH1D.h"
#include "TString.h"
#include "DataPoint.h"
#include "CanvasHandler.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"
#include "HfJetTaggingUtilities.h"
//#include "JetAnalysis.h"
#include "HfJetTaggingAnalysis.h"

class HfJetTaggingJPAnalysis : public HfJetTaggingAnalysis {
  public:
    HfJetTaggingJPAnalysis() {
      initConfig();
    }
    ~HfJetTaggingJPAnalysis();

    // function
    ///Basic
    void initConfig();
    int loadDataJPQA(TString rootData);
    int loadSimJPQA(TString rootSim);
    void initHistogramForNormalizationJPQAData();
    void initHistogramForNormalizationJPQAMC();
    void projectionHistJPQAData();
    void projectionHistJPQAMC();
    //void NegLogHist();
    void normalizedHistogramJPQAData();
    void normalizedHistogramJPQAMC();
    void saveHistogramJPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // calculattion
    float getLifeTimeRefTagger(TH1F* hJP, TH1F* hJetPt, int binJetPt);
    float getEfficiency(TH1F* htaggedJet, TH1F* huntaggedJet);
    float getPurity(TH1F* htaggedbJet, TH1F* htaggedIncJet);
    
    // set
    void setFillTP(bool fillTP);
    void setFillTF(bool fillTF);
    void setFillEffi(bool fillEffi);

    // get

    /// Draw
    std::vector<HistogramData> histList;

    int nc = 20000;
    CanvasHandler* canHan;
    void drawDataJetJP(bool doLog, int binJetPt);
    void drawDataJetNegLogJP(bool doLog, int binJetPt);
    void drawDataJetJPN1(bool doLog, int binJetPt, float cutImp);
    void drawDataJetNegLogJPN1(bool doLog, int binJetPt, float cutImp);
    void drawDataJetJPN2(bool doLog, int binJetPt, float cutImp);
    void drawDataJetNegLogJPN2(bool doLog, int binJetPt, float cutImp);
    void drawDataJetJPN3(bool doLog, int binJetPt, float cutImp);
    void drawDataJetNegLogJPN3(bool doLog, int binJetPt, float cutImp);

    void drawSimJetTrackProb(bool withInc, bool doLog, int binJetPt);
    void drawSimJetJP(bool withInc, bool doLog, int binJetPt);
    void drawSimJetNegLogJP(bool withInc, bool doLog, int binJetPt);
    void drawSimJetJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN4x1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetRef();
    void drawSimJetEffiN1(float cutImp);
    void drawSimJetEffiN2(float cutImp);
    void drawSimJetEffiN3(float cutImp);
    void drawSimJetEffiNx(float cutImp);
    void drawSimJetPurityN1(float cutImp);
    void drawSimJetPurityN2(float cutImp);
    void drawSimJetPurityN3(float cutImp);
    void drawSimJetPurityNx(float cutImp);
    void drawSimJetEffiAndPurity(float cutImp, int binJetPt);
    void drawTemplateFit();
    void drawDataJetEffiN1(float cutImp);
    void drawDataJetEffiN2(float cutImp);
    void drawDataJetEffiN3(float cutImp);
    void drawDataJetEffiNx(float cutImp);
    void drawDataJetPurityN1(float cutImp);
    void drawDataJetPurityN2(float cutImp);
    void drawDataJetPurityN3(float cutImp);

  protected:
    TH2F* h2dataTagjetPtJP;
    TH2F* h2dataTagjetPtNegLogJP;
    TH2F* h2dataTagjetPtJPN1;
    TH2F* h2dataTagjetPtNegLogJPN1;
    TH2F* h2dataTagjetPtJPN2;
    TH2F* h2dataTagjetPtNegLogJPN2;
    TH2F* h2dataTagjetPtJPN3;
    TH2F* h2dataTagjetPtNegLogJPN3;

    TH2F* h2simTagjetPosTPFlavour;
    TH2F* h2simTagjetNegTPFlavour;
    TH2F* h2simTagjetPtFlavour;
    TH3F* h3simTagjetPtJPFlavour;
    TH3F* h3simTagjetPtNegLogJPFlavour;
    TH3F* h3simTagjetPtJPN1Flavour;
    TH3F* h3simTagjetPtNegLogJPN1Flavour;
    TH3F* h3simTagjetPtJPN2Flavour;
    TH3F* h3simTagjetPtNegLogJPN2Flavour;
    TH3F* h3simTagjetPtJPN3Flavour;
    TH3F* h3simTagjetPtNegLogJPN3Flavour;

    TH1F* hdataTagjetPosTrackProb;
    TH1F* hdataTagjetNegTrackProb;
    TH1F* hdataTagjetJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataJPEffiN1[HfJetTagging::nFlavour+1];
    TH1F* hdataJPEffiN2[HfJetTagging::nFlavour+1];
    TH1F* hdataJPEffiN3[HfJetTagging::nFlavour+1];
    TH1F* hdataJPPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hdataJPPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hdataJPPurityN3[HfJetTagging::nFlavour+1];

    TH1F* hsimTagjetPosTrackProb[HfJetTagging::nFlavour];
    TH1F* hsimTagjetNegTrackProb[HfJetTagging::nFlavour];
    TH1F* hsimTagjetPt[HfJetTagging::nFlavour];
    TH1F* hsimTagjetJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimTagjetNormalizedJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimRefTagger[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN3[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN3[HfJetTagging::nFlavour+1];
    
  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    bool fillTP = false;
    bool fillTF = false;
    bool fillEffi = false;

};

//HfJetTaggingJPAnalysis::~HfJetTaggingJPAnalysis() {
//  delete h3simTagjetPtJPFlavour;
//  for (int flavour=0; flavour < HfJetTagging::nFlavour; flavour++) {
//    for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
//      delete hsimTagjetJP[flavour][binJetPt];
//      delete hsimTagjetNegLogJP[flavour][binJetPt];
//      delete hsimTagjetNormalizedJP[flavour][binJetPt];
//      delete hsimTagjetNormalizedNegLogJP[flavour][binJetPt];
//    }
//  }
//}
//

void HfJetTaggingJPAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

  //gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  TString dirFig = "fig";
  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  } 
  dirData = Form("%s/%s/data/%s/jp", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/jp", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingJPAnalysis::loadDataJPQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, JP QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  h2dataTagjetPtJP = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_JP", taskName.Data())));
  h2dataTagjetPtNegLogJP = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_neg_log_JP", taskName.Data())));
  h2dataTagjetPtJPN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_JP_N1", taskName.Data())));
  h2dataTagjetPtNegLogJPN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_neg_log_JP_N1", taskName.Data())));
  h2dataTagjetPtJPN2 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_JP_N2", taskName.Data())));
  h2dataTagjetPtNegLogJPN2 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_neg_log_JP_N2", taskName.Data())));
  h2dataTagjetPtJPN3 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_JP_N3", taskName.Data())));
  h2dataTagjetPtNegLogJPN3 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_neg_log_JP_N3", taskName.Data())));

  return 1;
}

int HfJetTaggingJPAnalysis::loadSimJPQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, JP QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";
  TString taskNameTP = "jet-taggerhf-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  h2simTagjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskName.Data())));
  h3simTagjetPtJPFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_JP_flavour", taskName.Data())));
  h3simTagjetPtNegLogJPFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
  h3simTagjetPtJPN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_JP_N1_flavour", taskName.Data())));
  h3simTagjetPtNegLogJPN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N1_flavour", taskName.Data())));
  h3simTagjetPtJPN2Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_JP_N2_flavour", taskName.Data())));
  h3simTagjetPtNegLogJPN2Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N2_flavour", taskName.Data())));
  h3simTagjetPtJPN3Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_JP_N3_flavour", taskName.Data())));
  h3simTagjetPtNegLogJPN3Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N3_flavour", taskName.Data())));

  if (fillTP) {
    h2simTagjetPosTPFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_pos_track_probability_flavour", taskNameTP.Data())));
    h2simTagjetNegTPFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_neg_track_probability_flavour", taskNameTP.Data())));
    std::cout << "Load completed JP MC data with TP" << std::endl;
  }

  std::cout << "Load completed JP MC data" << std::endl;
  return 1;
}

void HfJetTaggingJPAnalysis::initHistogramForNormalizationJPQAData() {
  for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
		hdataTagjetJP[jetPt] = new TH1F(Form("hdataTagjetJP_%d",  jetPt), "", h2dataTagjetPtJP->GetNbinsY(), h2dataTagjetPtJP->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJP->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJP->GetNbinsY()));
		hdataTagjetJPN1[jetPt] = new TH1F(Form("hdataTagjetJP_N1_%d", jetPt), "", h2dataTagjetPtJPN1->GetNbinsY(), h2dataTagjetPtJPN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJPN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJPN1->GetNbinsY()));
		hdataTagjetJPN2[jetPt] = new TH1F(Form("hdataTagjetJP_N2_%d", jetPt), "", h2dataTagjetPtJPN2->GetNbinsY(), h2dataTagjetPtJPN2->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJPN2->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJPN2->GetNbinsY()));
		hdataTagjetJPN3[jetPt] = new TH1F(Form("hdataTagjetJP_N3_%d", jetPt), "", h2dataTagjetPtJPN3->GetNbinsY(), h2dataTagjetPtJPN3->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJPN3->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJPN3->GetNbinsY()));
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hdataTagjetNegLogJP[flavour][jetPt] = new TH1F(Form("hdataTagjetNegLogJP_%d_%d", flavour, jetPt), "", h2dataTagjetPtNegLogJP->GetNbinsY(), h2dataTagjetPtNegLogJP->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJP->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJP->GetNbinsY()));
      hdataTagjetNegLogJPN1[flavour][jetPt] = new TH1F(Form("hdataTagjetNegLogJP_N1_%d_%d", flavour, jetPt), "", h2dataTagjetPtNegLogJPN1->GetNbinsY(), h2dataTagjetPtNegLogJPN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJPN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJPN1->GetNbinsY()));
      hdataTagjetNegLogJPN2[flavour][jetPt] = new TH1F(Form("hdataTagjetNegLogJP_N2_%d_%d", flavour, jetPt), "", h2dataTagjetPtNegLogJPN2->GetNbinsY(), h2dataTagjetPtNegLogJPN2->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJPN2->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJPN2->GetNbinsY()));
      hdataTagjetNegLogJPN3[flavour][jetPt] = new TH1F(Form("hdataTagjetNegLogJP_N3_%d_%d", flavour, jetPt), "", h2dataTagjetPtNegLogJPN3->GetNbinsY(), h2dataTagjetPtNegLogJPN3->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJPN3->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJPN3->GetNbinsY()));
    }
  }
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hdataJPEffiN1[flavour] = new TH1F(Form("hdataJPEffiN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdataJPEffiN2[flavour] = new TH1F(Form("hdataJPEffiN2_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdataJPEffiN3[flavour] = new TH1F(Form("hdataJPEffiN3_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdataJPPurityN1[flavour] = new TH1F(Form("hdataJPPurityN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdataJPPurityN2[flavour] = new TH1F(Form("hdataJPPurityN2_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdataJPPurityN3[flavour] = new TH1F(Form("hdataJPPurityN3_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
  }
}

void HfJetTaggingJPAnalysis::initHistogramForNormalizationJPQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimRefTagger[flavour] = new TH1F(Form("hsimRefTagger_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    if (fillTF) {
      hsimTagjetPosTrackProb[flavour] = new TH1F(Form("hsimPostTrackProb_%d", flavour), "", h2simTagjetPosTPFlavour->GetNbinsX(), h2simTagjetPosTPFlavour->GetXaxis()->GetBinLowEdge(1), h2simTagjetPosTPFlavour->GetXaxis()->GetBinUpEdge(h2simTagjetPosTPFlavour->GetNbinsX()));
      hsimTagjetNegTrackProb[flavour] = new TH1F(Form("hsimNegtTrackProb_%d", flavour), "", h2simTagjetNegTPFlavour->GetNbinsX(), h2simTagjetNegTPFlavour->GetXaxis()->GetBinLowEdge(1), h2simTagjetNegTPFlavour->GetXaxis()->GetBinUpEdge(h2simTagjetNegTPFlavour->GetNbinsX()));
    }
		hsimJPEffiN1[flavour] = new TH1F(Form("hsimJPEffiN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPEffiN2[flavour] = new TH1F(Form("hsimJPEffiN2_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPEffiN3[flavour] = new TH1F(Form("hsimJPEffiN3_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPPurityN1[flavour] = new TH1F(Form("hsimJPPurityN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPPurityN2[flavour] = new TH1F(Form("hsimJPPurityN2_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPPurityN3[flavour] = new TH1F(Form("hsimJPPurityN3_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimTagjetPt[flavour] = new TH1F(Form("hsimTagjetJP_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetJP[flavour][jetPt] = new TH1F(Form("hsimTagjetJP_%d_%d", flavour, jetPt), "", h3simTagjetPtJPFlavour->GetNbinsY(), h3simTagjetPtJPFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtJPFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtJPFlavour->GetNbinsY()));
			hsimTagjetNegLogJP[flavour][jetPt] = new TH1F(Form("hsimTagjetNegLogJP_%d_%d", flavour, jetPt), "", h3simTagjetPtNegLogJPFlavour->GetNbinsY(), h3simTagjetPtNegLogJPFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPFlavour->GetNbinsY()));
			hsimTagjetJPN1[flavour][jetPt] = new TH1F(Form("hsimTagjetJP_N1_%d_%d", flavour, jetPt), "", h3simTagjetPtJPN1Flavour->GetNbinsY(), h3simTagjetPtJPN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtJPN1Flavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtJPN1Flavour->GetNbinsY()));
			hsimTagjetNegLogJPN1[flavour][jetPt] = new TH1F(Form("hsimTagjetNegLogJPN1_%d_%d", flavour, jetPt), "", h3simTagjetPtNegLogJPN1Flavour->GetNbinsY(), h3simTagjetPtNegLogJPN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN1Flavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN1Flavour->GetNbinsY()));
			hsimTagjetJPN2[flavour][jetPt] = new TH1F(Form("hsimTagjetJP_N2_%d_%d", flavour, jetPt), "", h3simTagjetPtJPN2Flavour->GetNbinsY(), h3simTagjetPtJPN2Flavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtJPN2Flavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtJPN2Flavour->GetNbinsY()));
			hsimTagjetNegLogJPN2[flavour][jetPt] = new TH1F(Form("hsimTagjetNegLogJPN2_%d_%d", flavour, jetPt), "", h3simTagjetPtNegLogJPN2Flavour->GetNbinsY(), h3simTagjetPtNegLogJPN2Flavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN2Flavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN2Flavour->GetNbinsY()));
			hsimTagjetJPN3[flavour][jetPt] = new TH1F(Form("hsimTagjetJP_N3_%d_%d", flavour, jetPt), "", h3simTagjetPtJPN3Flavour->GetNbinsY(), h3simTagjetPtJPN3Flavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtJPN3Flavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtJPN3Flavour->GetNbinsY()));
			hsimTagjetNegLogJPN3[flavour][jetPt] = new TH1F(Form("hsimTagjetNegLogJPN3_%d_%d", flavour, jetPt), "", h3simTagjetPtNegLogJPN3Flavour->GetNbinsY(), h3simTagjetPtNegLogJPN3Flavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN3Flavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN3Flavour->GetNbinsY()));
    }
  }
}

void HfJetTaggingJPAnalysis::projectionHistJPQAData() {
  TH1F *projJP = reinterpret_cast<TH1F*> (h2dataTagjetPtJP->ProjectionY("projJP", 1, h2dataTagjetPtJP->GetNbinsX()));
  TH1F *projJPN1 = reinterpret_cast<TH1F*> (h2dataTagjetPtJPN1->ProjectionY("projJPN1", 1, h2dataTagjetPtJPN1->GetNbinsX()));
  TH1F *projJPN2 = reinterpret_cast<TH1F*> (h2dataTagjetPtJPN2->ProjectionY("projJPN2", 1, h2dataTagjetPtJPN2->GetNbinsX()));
  TH1F *projJPN3 = reinterpret_cast<TH1F*> (h2dataTagjetPtJPN3->ProjectionY("projJPN3", 1, h2dataTagjetPtJPN3->GetNbinsX()));
  TH1F *projNegLogJP = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJP->ProjectionY("projNegLogJP", 1, h2dataTagjetPtNegLogJP->GetNbinsX()));
  TH1F *projNegLogJPN1 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN1->ProjectionY("projNegLogJPN1", 1, h2dataTagjetPtNegLogJPN1->GetNbinsX()));
  TH1F *projNegLogJPN2 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN2->ProjectionY("projNegLogJPN2", 1, h2dataTagjetPtNegLogJPN2->GetNbinsX()));
  TH1F *projNegLogJPN3 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN3->ProjectionY("projNegLogJPN3", 1, h2dataTagjetPtNegLogJPN3->GetNbinsX()));

  hdataTagjetJP[0] = reinterpret_cast<TH1F*>(projJP->Clone("hdataTagjetJP")); 
  hdataTagjetJPN1[0] = reinterpret_cast<TH1F*>(projJPN1->Clone("hdataTagjetJPN1")); 
  hdataTagjetJPN2[0] = reinterpret_cast<TH1F*>(projJPN2->Clone("hdataTagjetJPN2")); 
  hdataTagjetJPN3[0] = reinterpret_cast<TH1F*>(projJPN3->Clone("hdataTagjetJPN3")); 
  hdataTagjetNegLogJP[0][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone("hdataTagjetNegLogJP")); 
  hdataTagjetNegLogJPN1[0][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone("hdataTagjetNegLogJPN1")); 
  hdataTagjetNegLogJPN2[0][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone("hdataTagjetNegLogJPN2")); 
  hdataTagjetNegLogJPN3[0][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone("hdataTagjetNegLogJPN3")); 


  for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    int leftbinJetPtJP = h2dataTagjetPtJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJP = h2dataTagjetPtJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJP = reinterpret_cast<TH1F*> (h2dataTagjetPtJP->ProjectionY(Form("projJetPtRangeJP_%d", binJetPt), leftbinJetPtJP, rightbinJetPtJP));
    hdataTagjetJP[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJP->Clone(Form("hdataTagjetJP_%d", binJetPt))); 

    int leftbinJetPtJPN1 = h2dataTagjetPtJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJPN1 = h2dataTagjetPtJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJPN1 = reinterpret_cast<TH1F*> (h2dataTagjetPtJPN1->ProjectionY(Form("projJetPtRangeJPN1_%d", binJetPt), leftbinJetPtJPN1, rightbinJetPtJPN1));
    hdataTagjetJPN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN1->Clone(Form("hdataTagjetJPN1_%d", binJetPt))); 

    int leftbinJetPtJPN2 = h2dataTagjetPtJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJPN2 = h2dataTagjetPtJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJPN2 = reinterpret_cast<TH1F*> (h2dataTagjetPtJPN2->ProjectionY(Form("projJetPtRangeJPN2_%d", binJetPt), leftbinJetPtJPN2, rightbinJetPtJPN2));
    hdataTagjetJPN2[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN2->Clone(Form("hdataTagjetJPN2_%d", binJetPt))); 

    int leftbinJetPtJPN3 = h2dataTagjetPtJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJPN3 = h2dataTagjetPtJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJPN3 = reinterpret_cast<TH1F*> (h2dataTagjetPtJPN3->ProjectionY(Form("projJetPtRangeJPN3_%d", binJetPt), leftbinJetPtJPN3, rightbinJetPtJPN3));
    hdataTagjetJPN3[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN3->Clone(Form("hdataTagjetJPN3_%d", binJetPt))); 

    int leftbinJetPtNegLogJP = h2dataTagjetPtNegLogJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJP = h2dataTagjetPtNegLogJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJP->ProjectionY(Form("projJetPtRangeNegLogJP_%d", binJetPt), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP));
    hdataTagjetNegLogJP[0][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hdataTagjetNegLogJP_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN1 = h2dataTagjetPtNegLogJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN1 = h2dataTagjetPtNegLogJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN1->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d", binJetPt), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1));
    hdataTagjetNegLogJPN1[0][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hdataTagjetNegLogJPN1_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN2 = h2dataTagjetPtNegLogJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN2 = h2dataTagjetPtNegLogJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN2->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d", binJetPt), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2));
    hdataTagjetNegLogJPN2[0][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hdataTagjetNegLogJPN2_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN3 = h2dataTagjetPtNegLogJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN3 = h2dataTagjetPtNegLogJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN3->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d", binJetPt), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3));
    hdataTagjetNegLogJPN3[0][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hdataTagjetNegLogJPN3_%d", binJetPt))); 

  }
}

void HfJetTaggingJPAnalysis::projectionHistJPQAMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    TH1F* projJetPt = reinterpret_cast<TH1F*> (h2simTagjetPtFlavour->ProjectionX(Form("projJetPt_%d", flavour), binFlavour, binFlavour));
		hsimTagjetPt[0]->Add(projJetPt);
    hsimTagjetPt[flavour] = reinterpret_cast<TH1F*> (projJetPt->Clone(Form("hsimTagjetPt_%d", flavour)));

		TH1F* projJP = reinterpret_cast<TH1F*> (h3simTagjetPtJPFlavour->ProjectionY(Form("projJP_%d", flavour), 1, h3simTagjetPtJPFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour->ProjectionY(Form("projNegLogJP_%d", flavour), 1, h3simTagjetPtNegLogJPFlavour->GetNbinsX(), binFlavour, binFlavour));
		hsimTagjetJP[0][0]->Add(projJP);
		hsimTagjetJP[flavour][0] = reinterpret_cast<TH1F*>(projJP->Clone(Form("hsimTagjetJP_%d_0", flavour)));
		hsimTagjetNegLogJP[0][0]->Add(projNegLogJP);
		hsimTagjetNegLogJP[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_0", flavour)));

		TH1F* projJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtJPN1Flavour->ProjectionY(Form("projJPN1_%d", flavour), 1, h3simTagjetPtJPN1Flavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN1Flavour->ProjectionY(Form("projNegLogJPN1_%d", flavour), 1, h3simTagjetPtNegLogJPN1Flavour->GetNbinsX(), binFlavour, binFlavour));
		hsimTagjetJPN1[0][0]->Add(projJPN1);
		hsimTagjetJPN1[flavour][0] = reinterpret_cast<TH1F*>(projJPN1->Clone(Form("hsimTagjetJPN1_%d_0", flavour)));
		hsimTagjetNegLogJPN1[0][0]->Add(projNegLogJPN1);
		hsimTagjetNegLogJPN1[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone(Form("hsimTagjetNegLogJPN1_%d_0", flavour)));

		TH1F* projJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtJPN2Flavour->ProjectionY(Form("projJPN2_%d", flavour), 1, h3simTagjetPtJPN2Flavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN2Flavour->ProjectionY(Form("projNegLogJPN2_%d", flavour), 1, h3simTagjetPtNegLogJPN2Flavour->GetNbinsX(), binFlavour, binFlavour));
		hsimTagjetJPN2[0][0]->Add(projJPN2);
		hsimTagjetJPN2[flavour][0] = reinterpret_cast<TH1F*>(projJPN2->Clone(Form("hsimTagjetJPN2_%d_0", flavour)));
		hsimTagjetNegLogJPN2[0][0]->Add(projNegLogJPN2);
		hsimTagjetNegLogJPN2[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone(Form("hsimTagjetNegLogJPN2_%d_0", flavour)));

    TH1F* projJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtJPN3Flavour->ProjectionY(Form("projJPN3_%d", flavour), 1, h3simTagjetPtJPN3Flavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN3Flavour->ProjectionY(Form("projNegLogJPN3_%d", flavour), 1, h3simTagjetPtNegLogJPN3Flavour->GetNbinsX(), binFlavour, binFlavour));
		hsimTagjetJPN3[0][0]->Add(projJPN3);
		hsimTagjetJPN3[flavour][0] = reinterpret_cast<TH1F*>(projJPN3->Clone(Form("hsimTagjetJPN3_%d_0", flavour)));
		hsimTagjetNegLogJPN3[0][0]->Add(projNegLogJPN3);
		hsimTagjetNegLogJPN3[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone(Form("hsimTagjetNegLogJPN3_%d_0", flavour)));

		for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
			int leftbinJetPtJP = h3simTagjetPtJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJP = h3simTagjetPtJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJP = reinterpret_cast<TH1F*> (h3simTagjetPtJPFlavour->ProjectionY(Form("projJetPtRangeJP_%d_%d", binJetPt, flavour), leftbinJetPtJP, rightbinJetPtJP, binFlavour, binFlavour));
			hsimTagjetJP[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJP->Clone(Form("hsimTagjetJP_%d_%d", flavour, binJetPt))); 
			hsimTagjetJP[0][binJetPt]->Add(projJetPtRangeJP);

			int leftbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour->ProjectionY(Form("projJetPtRangeNegLogJP_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, binFlavour, binFlavour));
			hsimTagjetNegLogJP[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_%d", flavour, binJetPt))); 
			hsimTagjetNegLogJP[0][binJetPt]->Add(projJetPtRangeNegLogJP);

			int leftbinJetPtJPN1 = h3simTagjetPtJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJPN1 = h3simTagjetPtJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtJPN1Flavour->ProjectionY(Form("projJetPtRangeJPN1_%d_%d", binJetPt, flavour), leftbinJetPtJPN1, rightbinJetPtJPN1, binFlavour, binFlavour));
			hsimTagjetJPN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN1->Clone(Form("hsimTagjetJPN1_%d_%d", flavour, binJetPt))); 
			hsimTagjetJPN1[0][binJetPt]->Add(projJetPtRangeJPN1);

			int leftbinJetPtNegLogJPN1 = h3simTagjetPtNegLogJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJPN1 = h3simTagjetPtNegLogJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN1Flavour->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1, binFlavour, binFlavour));
			hsimTagjetNegLogJPN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hsimTagjetNegLogJPN1_%d_%d", flavour, binJetPt))); 
			hsimTagjetNegLogJPN1[0][binJetPt]->Add(projJetPtRangeNegLogJPN1);

			int leftbinJetPtJPN2 = h3simTagjetPtJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJPN2 = h3simTagjetPtJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtJPN2Flavour->ProjectionY(Form("projJetPtRangeJPN2_%d_%d", binJetPt, flavour), leftbinJetPtJPN2, rightbinJetPtJPN2, binFlavour, binFlavour));
			hsimTagjetJPN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN2->Clone(Form("hsimTagjetJPN2_%d_%d", flavour, binJetPt))); 
			hsimTagjetJPN2[0][binJetPt]->Add(projJetPtRangeJPN2);

			int leftbinJetPtNegLogJPN2 = h3simTagjetPtNegLogJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJPN2 = h3simTagjetPtNegLogJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN2Flavour->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2, binFlavour, binFlavour));
			hsimTagjetNegLogJPN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hsimTagjetNegLogJPN2_%d_%d", flavour, binJetPt))); 
			hsimTagjetNegLogJPN2[0][binJetPt]->Add(projJetPtRangeNegLogJPN2);

			int leftbinJetPtJPN3 = h3simTagjetPtJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJPN3 = h3simTagjetPtJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtJPN3Flavour->ProjectionY(Form("projJetPtRangeJPN3_%d_%d", binJetPt, flavour), leftbinJetPtJPN3, rightbinJetPtJPN3, binFlavour, binFlavour));
			hsimTagjetJPN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN3->Clone(Form("hsimTagjetJPN3_%d_%d", flavour, binJetPt))); 
			hsimTagjetJPN3[0][binJetPt]->Add(projJetPtRangeJPN3);

			int leftbinJetPtNegLogJPN3 = h3simTagjetPtNegLogJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJPN3 = h3simTagjetPtNegLogJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN3Flavour->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3, binFlavour, binFlavour));
			hsimTagjetNegLogJPN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hsimTagjetNegLogJPN3_%d_%d", flavour, binJetPt))); 
			hsimTagjetNegLogJPN3[0][binJetPt]->Add(projJetPtRangeNegLogJPN3);

    }
  }
}

//void HfJetTaggingJPAnalysis::NegLogHist() {
//	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
//		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
//      hsimTagjetNegLogJP[flavour][jetPt] = (TH1F*)hsimTagjetJP[flavour][jetPt]->Clone(Form("hsimTagjetNegLogJP_%d_%d", flavour, jetPt));
//      int nBinsX = hsimTagjetNegLogJP[flavour][jetPt]->GetNbinsX();
//      for (int iBin = 0; iBin <= nBinsX + 1; ++iBin) { // Include underflow and overflow
//        double originalValue = hsimTagjetNegLogJP[flavour][jetPt]->GetBinContent(iBin);
//        double logValue = -1; // Default value for undefined log
//
//        // Calculate -log(value) only for positive values
//        if (originalValue > 0) {
//          logValue = -TMath::Log(originalValue);
//        }
//
//        // Set the new bin content
//        hsimTagjetNegLogJP[flavour][jetPt]->SetBinContent(iBin, logValue);
//      }
//    }
//  }
//}

void HfJetTaggingJPAnalysis::normalizedHistogramJPQAData() {
  for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
    hdataTagjetNormalizedJP[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJP[jetPt]->Clone(Form("hdataTagjetNormalizedJP_%d", jetPt)));
    hdataTagjetNormalizedNegLogJP[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJP[0][jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJP_%d", jetPt)));
    hdataTagjetNormalizedJPN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJPN1[jetPt]->Clone(Form("hdataTagjetNormalizedJPN1_%d", jetPt)));
    hdataTagjetNormalizedNegLogJPN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJPN1[0][jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJPN1_%d", jetPt)));
    hdataTagjetNormalizedJPN2[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJPN2[jetPt]->Clone(Form("hdataTagjetNormalizedJPN2_%d", jetPt)));
    hdataTagjetNormalizedNegLogJPN2[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJPN2[0][jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJPN2_%d", jetPt)));
    hdataTagjetNormalizedJPN3[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJPN3[jetPt]->Clone(Form("hdataTagjetNormalizedJPN3_%d", jetPt)));
    hdataTagjetNormalizedNegLogJPN3[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJPN3[0][jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJPN3_%d", jetPt)));

    // Scale
    hdataTagjetNormalizedJP[jetPt]->Scale(1. / hdataTagjetNormalizedJP[jetPt]->Integral("width"));
    hdataTagjetNormalizedNegLogJP[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJP[jetPt]->Integral("width"));
    hdataTagjetNormalizedJPN1[jetPt]->Scale(1. / hdataTagjetNormalizedJPN1[jetPt]->Integral("width"));
    hdataTagjetNormalizedNegLogJPN1[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJPN1[jetPt]->Integral("width"));
    hdataTagjetNormalizedJPN2[jetPt]->Scale(1. / hdataTagjetNormalizedJPN2[jetPt]->Integral("width"));
    hdataTagjetNormalizedNegLogJPN2[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJPN2[jetPt]->Integral("width"));
    hdataTagjetNormalizedJPN3[jetPt]->Scale(1. / hdataTagjetNormalizedJPN3[jetPt]->Integral("width"));
    hdataTagjetNormalizedNegLogJPN3[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJPN3[jetPt]->Integral("width"));
  }
}

void HfJetTaggingJPAnalysis::normalizedHistogramJPQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetNormalizedJP[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetJP[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedJP_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedNegLogJP[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetNegLogJP[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedNegLogJP_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedJPN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetJPN1[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedJPN1_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedNegLogJPN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetNegLogJPN1[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedNegLogJPN1_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedJPN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetJPN2[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedJPN2_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedNegLogJPN2[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetNegLogJPN2[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedNegLogJPN2_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedJPN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetJPN3[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedJPN3_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedNegLogJPN3[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetNegLogJPN3[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedNegLogJPN3_%d_%d", flavour, jetPt)));

      // Scale
			hsimTagjetNormalizedJP[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJP[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedNegLogJP[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJP[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedJPN1[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJPN1[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedNegLogJPN1[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJPN1[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedJPN2[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJPN2[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedNegLogJPN2[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJPN2[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedJPN3[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJPN3[flavour][jetPt]->Integral("width"));
			hsimTagjetNormalizedNegLogJPN3[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJPN3[flavour][jetPt]->Integral("width"));
    }
  }
}

void HfJetTaggingJPAnalysis::saveHistogramJPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hsimTagjetJP[flavour][jetPt]->Write();
      hsimTagjetNegLogJP[flavour][jetPt]->Write();
      hsimTagjetNegLogJPN1[flavour][jetPt]->Write();
      hsimTagjetNegLogJPN2[flavour][jetPt]->Write();
      hsimTagjetNegLogJPN3[flavour][jetPt]->Write();
    }
  }
  fout->Close();
  delete fout;
}

// Set function
void HfJetTaggingJPAnalysis::setFillTP(bool mfillTP) {
  fillTP = mfillTP;
  if (fillTP) {
    std::cout << "do track probabiltiy" << std::endl;
  }
}

void HfJetTaggingJPAnalysis::setFillTF(bool mfillTF) {
  fillTF = mfillTF;
  if (fillTF) {
    std::cout << "do template fitting" << std::endl;
  }
}


void HfJetTaggingJPAnalysis::setFillEffi(bool mfillEffi) {
  fillEffi = mfillEffi;
  if (fillEffi) {
    std::cout << "fill effi and purity" << std::endl;
  }
}

// Draw function
void HfJetTaggingJPAnalysis::drawDataJetJP(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedJP[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProb_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJP(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedNegLogJP[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLog_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetJPN1(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedJPN1[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::X_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJPN1(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedNegLogJPN1[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetJPN2(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedJPN2[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN2_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJPN2(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedNegLogJPN2[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN2_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetJPN3(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedJPN3[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN3_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJPN3(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalizedNegLogJPN3[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN3_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetTrackProb(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTagjetNormalizedJP[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedJP[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedJP[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedJP[3][binJetPt], HfJetTagging::LFJET});

}


void HfJetTaggingJPAnalysis::drawSimJetJP(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimTagjetNormalizedJP[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedJP[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedJP[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedJP[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProb_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}



void HfJetTaggingJPAnalysis::drawSimJetNegLogJP(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJP[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJP[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLog_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJPN1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedJPN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedJPN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedJPN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedJPN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJPN2(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedJPN2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedJPN2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedJPN2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedJPN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN2(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJPN3(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedJPN3[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedJPN3[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedJPN3[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedJPN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN3(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimTagjetNormalizedNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimTagjetNormalizedNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN4x1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> histList;
//  histList.push_back({hsimTagjetNormalizedNegLogJP[0][binJetPt], HfJetTagging::INCJET});
//  histList.push_back({hsimTagjetNormalizedNegLogJP[1][binJetPt], HfJetTagging::CJET});
//  histList.push_back({hsimTagjetNormalizedNegLogJP[2][binJetPt], HfJetTagging::BJET});
//  histList.push_back({hsimTagjetNormalizedNegLogJP[3][binJetPt], HfJetTagging::LFJET});
  histList.push_back({hsimTagjetNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimTagjetNegLogJP[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimTagjetNegLogJP[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimTagjetNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN1;
  histListN1.push_back({hsimTagjetNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  histListN1.push_back({hsimTagjetNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  histListN1.push_back({hsimTagjetNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  histListN1.push_back({hsimTagjetNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hsimTagjetNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  histListN2.push_back({hsimTagjetNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  histListN2.push_back({hsimTagjetNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  histListN2.push_back({hsimTagjetNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hsimTagjetNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  histListN3.push_back({hsimTagjetNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  histListN3.push_back({hsimTagjetNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  histListN3.push_back({hsimTagjetNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.15);

  //canHan->drawPadMxNCombined(nc, 0, 0, histList, withInc, doLog, true, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", HfJetTagging::Y_AXIS_JP);
  canHan->drawPadMxNCombined(nc, 0, 0, histList, withInc, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", HfJetTagging::Y_AXIS_JP);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
  latexSimJetInfoForJP(0.43, 0.94, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  //latexSimJetInfo(0.40, 0.94, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  latex.DrawLatex(0.74, 0.92, "#scale[1.8]{untagged jet}");

  canHan->drawPadMxNCombined(nc, 1, 0, histListN1, withInc, doLog, true, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", "");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
  latex.DrawLatex(0.08, 0.92, Form("#scale[1.8]{S#it{d}_{#it{XY}} > %0.1f}", cutImp));
  latex.DrawLatex(0.38, 0.92, Form("#scale[1.8]{1^{st} largest %s^{track} tagged jet}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 2, 0, histListN2, withInc, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", "");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
  latex.DrawLatex(0.37, 0.92, Form("#scale[1.8]{2^{nd} largest %s^{track} tagged jet}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 3, 0, histListN3, withInc, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], HfJetTagging::X_AXIS_JP, "");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
  latex.DrawLatex(0.35, 0.92, Form("#scale[1.8]{3^{rd} largest %s^{track} tagged jet}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  gROOT->ProcessLine(Form("cc%d->Update();", nc));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN4x1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

float HfJetTaggingJPAnalysis::getLifeTimeRefTagger(TH1F* hJP, TH1F* hJetPt, int binJetPt) {
  int numOfJetforJP = hJP->Integral(1, hJP->GetNbinsX());
  int numOfJet =  hJetPt->Integral();
  int leftbin = HfJetTagging::binsJetPt[binJetPt-1];
  int rightbin = HfJetTagging::binsJetPt[binJetPt];
  //int numOfJet =  hJetPt->Integral(leftbin, rightbin);

  if (numOfJet==0) return -1;
  
  auto ref=  static_cast<float> ((float) numOfJetforJP / numOfJet);
  return ref;
}

void HfJetTaggingJPAnalysis::drawSimJetRef() {
	std::vector<HistogramData> normHist;

  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //float refTagger = this->getLifeTimeRefTagger(hsimTagjetNegLogJP[flavour][binJetPt], hsimTagjetPt[flavour], binJetPt);
      float refTagger = this->getLifeTimeRefTagger(hsimTagjetNegLogJP[flavour][binJetPt], hsimTagjetJP[flavour][binJetPt], binJetPt);
      hsimRefTagger[flavour]->SetBinContent(binJetPt, refTagger);
    }
	  normHist.push_back({hsimRefTagger[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "C_{b}");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lifeTimeRefTagger.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetEffiN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN1 = taggingutilities::getEfficiency(hsimTagjetNegLogJPN1[flavour][binJetPt],hsimTagjetNegLogJP[flavour][binJetPt]);
      if (effiN1 < 0) continue;
      hsimJPEffiN1[flavour]->SetBinContent(binJetPt, effiN1);
    }
	  normHist.push_back({hsimJPEffiN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetEffiN2(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt

      float effiN2 = taggingutilities::getEfficiency(hsimTagjetNegLogJPN2[flavour][binJetPt],hsimTagjetNegLogJP[flavour][binJetPt]);
      if (effiN2 < 0) continue;
      hsimJPEffiN2[flavour]->SetBinContent(binJetPt, effiN2);
    }
	  normHist.push_back({hsimJPEffiN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=2");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetEffiN3(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt

      float effiN3 = taggingutilities::getEfficiency(hsimTagjetNegLogJPN3[flavour][binJetPt],hsimTagjetNegLogJP[flavour][binJetPt]);
      if (effiN3 < 0) continue;
      hsimJPEffiN3[flavour]->SetBinContent(binJetPt, effiN3);
    }
	  normHist.push_back({hsimJPEffiN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=3");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetEffiNx(float cutImp) {
	std::vector<HistogramData> histIncJet;
	std::vector<HistogramData> histCharmJet;
	std::vector<HistogramData> histBeautyJet;
	std::vector<HistogramData> histLfJet;
	histIncJet.push_back({hsimJPEffiN1[0], "N=1"});
	histIncJet.push_back({hsimJPEffiN2[0], "N=2"});
	histIncJet.push_back({hsimJPEffiN3[0], "N=3"});
	histCharmJet.push_back({hsimJPEffiN1[1], "N=1"});
	histCharmJet.push_back({hsimJPEffiN2[1], "N=2"});
	histCharmJet.push_back({hsimJPEffiN3[1], "N=3"});
	histBeautyJet.push_back({hsimJPEffiN1[2], "N=1"});
	histBeautyJet.push_back({hsimJPEffiN2[2], "N=2"});
	histBeautyJet.push_back({hsimJPEffiN3[2], "N=3"});
	histLfJet.push_back({hsimJPEffiN1[3], "N=1"});
	histLfJet.push_back({hsimJPEffiN2[3], "N=2"});
	histLfJet.push_back({hsimJPEffiN3[3], "N=3"});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histIncJet.size(), histIncJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/EffiJPNx.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histCharmJet.size(), histCharmJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/EffiJPNx.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histBeautyJet.size(), histBeautyJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiJPNx.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histLfJet.size(), histLfJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/EffiJPNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN1 = taggingutilities::getPurity(hsimTagjetNegLogJPN1[flavour][binJetPt],hsimTagjetNegLogJPN1[0][binJetPt]);
      hsimJPPurityN1[flavour]->SetBinContent(binJetPt, purityN1);
    }
	  normHist.push_back({hsimJPPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityJPN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityN2(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN2 = taggingutilities::getPurity(hsimTagjetNegLogJPN2[flavour][binJetPt],hsimTagjetNegLogJPN2[0][binJetPt]);
      hsimJPPurityN2[flavour]->SetBinContent(binJetPt, purityN2);
    }
	  normHist.push_back({hsimJPPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=2");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityJPN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityN3(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN3 = taggingutilities::getPurity(hsimTagjetNegLogJPN3[flavour][binJetPt],hsimTagjetNegLogJPN3[0][binJetPt]);
      hsimJPPurityN3[flavour]->SetBinContent(binJetPt, purityN3);
    }
	  normHist.push_back({hsimJPPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=3");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityJPN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityNx(float cutImp) {
	std::vector<HistogramData> histIncJet;
	std::vector<HistogramData> histCharmJet;
	std::vector<HistogramData> histBeautyJet;
	std::vector<HistogramData> histLfJet;
	histIncJet.push_back({hsimJPPurityN1[0], "N=1"});
	histIncJet.push_back({hsimJPPurityN2[0], "N=2"});
	histIncJet.push_back({hsimJPPurityN3[0], "N=3"});
	histCharmJet.push_back({hsimJPPurityN1[1], "N=1"});
	histCharmJet.push_back({hsimJPPurityN2[1], "N=2"});
	histCharmJet.push_back({hsimJPPurityN3[1], "N=3"});
	histBeautyJet.push_back({hsimJPPurityN1[2], "N=1"});
	histBeautyJet.push_back({hsimJPPurityN2[2], "N=2"});
	histBeautyJet.push_back({hsimJPPurityN3[2], "N=3"});
	histLfJet.push_back({hsimJPPurityN1[3], "N=1"});
	histLfJet.push_back({hsimJPPurityN2[3], "N=2"});
	histLfJet.push_back({hsimJPPurityN3[3], "N=3"});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histIncJet.size(), histIncJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/purityJPNx.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histCharmJet.size(), histCharmJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/purityJPNx.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histBeautyJet.size(), histBeautyJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/purityJPNx.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histLfJet.size(), histLfJet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/purityJPNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingJPAnalysis::drawTemplateFit() {
  RooRealVar jetProb("jetProb", "-ln(JP)", 0, 20);
  const int rebinFactor = 20;
  double newBins[rebinFactor+1] = {0};
  for (int i = 0; i <= rebinFactor; ++i) {
    newBins[i] = i;
  }
  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;
    //if (binJetPt>1) continue;
    TH1F* hsimincjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJP", newBins);
    TH1F* hsimcjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJP", newBins);
    TH1F* hsimbjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJP", newBins);
    TH1F* hsimlfjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJP", newBins);
    TH1F* hdatajetNegLogJP = (TH1F*) hdataTagjetNegLogJP[0][binJetPt]->Rebin(rebinFactor, "hdatajetNegLogJP", newBins);
    TH1F* hsimincjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJPN1", newBins);
    TH1F* hsimcjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJPN1", newBins);
    TH1F* hsimbjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJPN1", newBins);
    TH1F* hsimlfjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJPN1", newBins);
    TH1F* hdatajetNegLogJPN1 = (TH1F*) hdataTagjetNegLogJPN1[0][binJetPt]->Rebin(rebinFactor, "hdatajetNegLogJPN1", newBins);
    TH1F* hsimincjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJPN2", newBins);
    TH1F* hsimcjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJPN2", newBins);
    TH1F* hsimbjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJPN2", newBins);
    TH1F* hsimlfjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJPN2", newBins);
    TH1F* hdatajetNegLogJPN2 = (TH1F*) hdataTagjetNegLogJPN2[0][binJetPt]->Rebin(rebinFactor, "hdatajetNegLogJPN2", newBins);
    TH1F* hsimincjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJPN3", newBins);
    TH1F* hsimcjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJPN3", newBins);
    TH1F* hsimbjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJPN3", newBins);
    TH1F* hsimlfjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJPN3", newBins);
    TH1F* hdatajetNegLogJPN3 = (TH1F*) hdataTagjetNegLogJPN3[0][binJetPt]->Rebin(rebinFactor, "hdatajetNegLogJPN3", newBins);

//    TH1F* hsimincjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[0][binJetPt]->Clone();
//    TH1F* hsimcjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[1][binJetPt]->Clone();
//    TH1F* hsimbjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[2][binJetPt]->Clone();
//    TH1F* hsimlfjetNegLogJP = (TH1F*) hsimTagjetNegLogJP[3][binJetPt]->Clone();
//    TH1F* hdatajetNegLogJP = (TH1F*) hdataTagjetNegLogJP[0][binJetPt]->Clone();
//    TH1F* hsimincjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[0][binJetPt]->Clone();
//    TH1F* hsimcjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[1][binJetPt]->Clone();
//    TH1F* hsimbjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[2][binJetPt]->Clone();
//    TH1F* hsimlfjetNegLogJPN1 = (TH1F*) hsimTagjetNegLogJPN1[3][binJetPt]->Clone();
//    TH1F* hdatajetNegLogJPN1 = (TH1F*) hdataTagjetNegLogJPN1[0][binJetPt]->Clone();
//    TH1F* hsimincjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[0][binJetPt]->Clone();
//    TH1F* hsimcjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[1][binJetPt]->Clone();
//    TH1F* hsimbjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[2][binJetPt]->Clone();
//    TH1F* hsimlfjetNegLogJPN2 = (TH1F*) hsimTagjetNegLogJPN2[3][binJetPt]->Clone();
//    TH1F* hdatajetNegLogJPN2 = (TH1F*) hdataTagjetNegLogJPN2[0][binJetPt]->Clone();
//    TH1F* hsimincjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[0][binJetPt]->Clone();
//    TH1F* hsimcjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[1][binJetPt]->Clone();
//    TH1F* hsimbjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[2][binJetPt]->Clone();
//    TH1F* hsimlfjetNegLogJPN3 = (TH1F*) hsimTagjetNegLogJPN3[3][binJetPt]->Clone();
//    TH1F* hdatajetNegLogJPN3 = (TH1F*) hdataTagjetNegLogJPN3[0][binJetPt]->Clone();


    std::cout << "Debug" <<std::endl;
    std::cout << "data yield: " << hdataTagjetNegLogJP[0][binJetPt]->Integral("width") << std::endl;
    std::cout << "data yield (N1): " << hdataTagjetNegLogJPN1[0][binJetPt]->Integral("width") << std::endl;
    std::cout << "data yield (N2): " << hdataTagjetNegLogJPN2[0][binJetPt]->Integral("width") << std::endl;
    std::cout << "data yield (N3): " << hdataTagjetNegLogJPN3[0][binJetPt]->Integral("width") << std::endl;
    

    RooDataHist mcincjetNegLogJP("mcincjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJP)); 
    RooDataHist mccjetNegLogJP("mccjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJP));
    RooDataHist mcbjetNegLogJP("mcbjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJP));
    RooDataHist mclfjetNegLogJP("mclfjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJP));
    RooDataHist mccjetNegLogJPForData("mccjetNegLogJPForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJP));
    RooDataHist mcbjetNegLogJPForData("mcbjetNegLogJPForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJP));
    RooDataHist mclfjetNegLogJPForData("mclfjetNegLogJPForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJP));
    RooDataHist datajetNegLogJP("datajetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hdatajetNegLogJP)); 

    RooDataHist mcincjetNegLogJPN1("mcincjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPN1)); 
    RooDataHist mccjetNegLogJPN1("mccjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN1));
    RooDataHist mcbjetNegLogJPN1("mcbjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN1));
    RooDataHist mclfjetNegLogJPN1("mclfjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN1));
    RooDataHist mccjetNegLogJPN1ForData("mccjetNegLogJPN1ForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN1));
    RooDataHist mcbjetNegLogJPN1ForData("mcbjetNegLogJPN1ForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN1));
    RooDataHist mclfjetNegLogJPN1ForData("mclfjetNegLogJPN1ForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN1));
    RooDataHist datajetNegLogJPN1("datajetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hdatajetNegLogJPN1)); 

    RooDataHist mcincjetNegLogJPN2("mcincjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPN2)); 
    RooDataHist mccjetNegLogJPN2("mccjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN2));
    RooDataHist mcbjetNegLogJPN2("mcbjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN2));
    RooDataHist mclfjetNegLogJPN2("mclfjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN2));
    RooDataHist mccjetNegLogJPN2ForData("mccjetNegLogJPN2ForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN2));
    RooDataHist mcbjetNegLogJPN2ForData("mcbjetNegLogJPN2ForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN2));
    RooDataHist mclfjetNegLogJPN2ForData("mclfjetNegLogJPN2ForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN2));
    RooDataHist datajetNegLogJPN2("datajetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hdatajetNegLogJPN2)); 

    if (mccjetNegLogJPN2ForData.numEntries() == 0) {
      std::cerr << "Error: Histogram has zero entries." << std::endl;
    }


    RooDataHist mcincjetNegLogJPN3("mcincjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPN3)); 
    RooDataHist mccjetNegLogJPN3("mccjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN3));
    RooDataHist mcbjetNegLogJPN3("mcbjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN3));
    RooDataHist mclfjetNegLogJPN3("mclfjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN3));
    RooDataHist mccjetNegLogJPN3ForData("mccjetNegLogJPN3ForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN3));
    RooDataHist mcbjetNegLogJPN3ForData("mcbjetNegLogJPN3ForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN3));
    RooDataHist mclfjetNegLogJPN3ForData("mclfjetNegLogJPN3ForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN3));
    RooDataHist datajetNegLogJPN3("datajetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hdatajetNegLogJPN3)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetNegLogJP("histPdfcjetNegLogJP", "Histogram PDF", jetProb, mccjetNegLogJP);
    RooHistPdf histPdfbjetNegLogJP("histPdfbjetNegLogJP", "Histogram PDF", jetProb, mcbjetNegLogJP);
    RooHistPdf histPdflfjetNegLogJP("histPdflfjetNegLogJP", "Histogram PDF", jetProb, mclfjetNegLogJP);
    RooHistPdf histPdfcjetNegLogJPForData("histPdfcjetNegLogJPForData", "Histogram PDF", jetProb, mccjetNegLogJPForData);
    RooHistPdf histPdfbjetNegLogJPForData("histPdfbjetNegLogJPForData", "Histogram PDF", jetProb, mcbjetNegLogJPForData);
    RooHistPdf histPdflfjetNegLogJPForData("histPdflfjetNegLogJPForData", "Histogram PDF", jetProb, mclfjetNegLogJPForData);

    RooHistPdf histPdfcjetNegLogJPN1("histPdfcjetNegLogJPN1", "Histogram PDF", jetProb, mccjetNegLogJPN1);
    RooHistPdf histPdfbjetNegLogJPN1("histPdfbjetNegLogJPN1", "Histogram PDF", jetProb, mcbjetNegLogJPN1);
    RooHistPdf histPdflfjetNegLogJPN1("histPdflfjetNegLogJPN1", "Histogram PDF", jetProb, mclfjetNegLogJPN1);
    RooHistPdf histPdfcjetNegLogJPN1ForData("histPdfcjetNegLogJPN1ForData", "Histogram PDF", jetProb, mccjetNegLogJPN1ForData);
    RooHistPdf histPdfbjetNegLogJPN1ForData("histPdfbjetNegLogJPN1ForData", "Histogram PDF", jetProb, mcbjetNegLogJPN1ForData);
    RooHistPdf histPdflfjetNegLogJPN1ForData("histPdflfjetNegLogJPN1ForData", "Histogram PDF", jetProb, mclfjetNegLogJPN1ForData);

    RooHistPdf histPdfcjetNegLogJPN2("histPdfcjetNegLogJPN2", "Histogram PDF", jetProb, mccjetNegLogJPN2);
    RooHistPdf histPdfbjetNegLogJPN2("histPdfbjetNegLogJPN2", "Histogram PDF", jetProb, mcbjetNegLogJPN2);
    RooHistPdf histPdflfjetNegLogJPN2("histPdflfjetNegLogJPN2", "Histogram PDF", jetProb, mclfjetNegLogJPN2);
    RooHistPdf histPdfcjetNegLogJPN2ForData("histPdfcjetNegLogJPN2ForData", "Histogram PDF", jetProb, mccjetNegLogJPN2ForData);
    if (histPdfcjetNegLogJPN2ForData.getVal() == 0) {
      std::cerr << "Error: PDF evaluates to zero." << std::endl;
    }
    RooHistPdf histPdfbjetNegLogJPN2ForData("histPdfbjetNegLogJPN2ForData", "Histogram PDF", jetProb, mcbjetNegLogJPN2ForData);
    RooHistPdf histPdflfjetNegLogJPN2ForData("histPdflfjetNegLogJPN2ForData", "Histogram PDF", jetProb, mclfjetNegLogJPN2ForData);

    RooHistPdf histPdfcjetNegLogJPN3("histPdfcjetNegLogJPN3", "Histogram PDF", jetProb, mccjetNegLogJPN3);
    RooHistPdf histPdfbjetNegLogJPN3("histPdfbjetNegLogJPN3", "Histogram PDF", jetProb, mcbjetNegLogJPN3);
    RooHistPdf histPdflfjetNegLogJPN3("histPdflfjetNegLogJPN3", "Histogram PDF", jetProb, mclfjetNegLogJPN3);
    RooHistPdf histPdfcjetNegLogJPN3ForData("histPdfcjetNegLogJPN3ForData", "Histogram PDF", jetProb, mccjetNegLogJPN3ForData);
    RooHistPdf histPdfbjetNegLogJPN3ForData("histPdfbjetNegLogJPN3ForData", "Histogram PDF", jetProb, mcbjetNegLogJPN3ForData);
    RooHistPdf histPdflfjetNegLogJPN3ForData("histPdflfjetNegLogJPN3ForData", "Histogram PDF", jetProb, mclfjetNegLogJPN3ForData);

    // Define relative normalization factors 
    int incjetNegLogJPYield = mccjetNegLogJP.sumEntries()+mcbjetNegLogJP.sumEntries()+mclfjetNegLogJP.sumEntries();
    int incjetNegLogJPN1Yield = mccjetNegLogJPN1.sumEntries()+mcbjetNegLogJPN1.sumEntries()+mclfjetNegLogJPN1.sumEntries();
    int incjetNegLogJPN2Yield = mccjetNegLogJPN2.sumEntries()+mcbjetNegLogJPN2.sumEntries()+mclfjetNegLogJPN2.sumEntries();
    int incjetNegLogJPN3Yield = mccjetNegLogJPN3.sumEntries()+mcbjetNegLogJPN3.sumEntries()+mclfjetNegLogJPN3.sumEntries();
    RooRealVar cjetNegLogJPYield("cjetNegLogJPYield", "cjet Yield", hsimTagjetNegLogJP[1][0]->Integral(1, hsimTagjetNegLogJP[1][0]->GetNbinsX()), 0, incjetNegLogJPYield);
    RooRealVar bjetNegLogJPYield("bjetNegLogJPYield", "bjet Yield", hsimTagjetNegLogJP[2][0]->Integral(1, hsimTagjetNegLogJP[2][0]->GetNbinsX()), 0, incjetNegLogJPYield);
    RooRealVar lfjetNegLogJPYield("lfjetNegLogJPYield", "lfjet Yield", hsimTagjetNegLogJP[3][0]->Integral(1, hsimTagjetNegLogJP[3][0]->GetNbinsX()), 0, incjetNegLogJPYield);
    RooRealVar cjetNegLogJPN1Yield("cjetNegLogJPN1Yield", "cjet Yield", hsimTagjetNegLogJPN1[1][0]->Integral(1, hsimTagjetNegLogJPN1[1][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
    RooRealVar bjetNegLogJPN1Yield("bjetNegLogJPN1Yield", "bjet Yield", hsimTagjetNegLogJPN1[2][0]->Integral(1, hsimTagjetNegLogJPN1[2][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
    RooRealVar lfjetNegLogJPN1Yield("lfjetNegLogJPN1Yield", "lfjet Yield", hsimTagjetNegLogJPN1[3][0]->Integral(1, hsimTagjetNegLogJPN1[3][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
    RooRealVar cjetNegLogJPN2Yield("cjetNegLogJPN2Yield", "cjet Yield", hsimTagjetNegLogJPN2[1][0]->Integral(1, hsimTagjetNegLogJPN2[1][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
    RooRealVar bjetNegLogJPN2Yield("bjetNegLogJPN2Yield", "bjet Yield", hsimTagjetNegLogJPN2[2][0]->Integral(1, hsimTagjetNegLogJPN2[2][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
    RooRealVar lfjetNegLogJPN2Yield("lfjetNegLogJPN2Yield", "lfjet Yield", hsimTagjetNegLogJPN2[3][0]->Integral(1, hsimTagjetNegLogJPN2[3][0]->GetNbinsX()), 0, incjetNegLogJPN2Yield);
    RooRealVar cjetNegLogJPN3Yield("cjetNegLogJPN3Yield", "cjet Yield", hsimTagjetNegLogJPN3[1][0]->Integral(1, hsimTagjetNegLogJPN3[1][0]->GetNbinsX()), 0, incjetNegLogJPN3Yield);
    RooRealVar bjetNegLogJPN3Yield("bjetNegLogJPN3Yield", "bjet Yield", hsimTagjetNegLogJPN3[2][0]->Integral(1, hsimTagjetNegLogJPN3[2][0]->GetNbinsX()), 0, incjetNegLogJPN3Yield);
    RooRealVar lfjetNegLogJPN3Yield("lfjetNegLogJPN3Yield", "lfjet Yield", hsimTagjetNegLogJPN3[3][0]->Integral(1, hsimTagjetNegLogJPN3[3][0]->GetNbinsX()), 0, incjetNegLogJPN3Yield);

    int incjetNegLogJPYieldForData = hdatajetNegLogJP->Integral("width");
    int incjetNegLogJPN1YieldForData = hdatajetNegLogJPN1->Integral("width");
    int incjetNegLogJPN2YieldForData = hdatajetNegLogJPN2->Integral("width");
    int incjetNegLogJPN3YieldForData = hdatajetNegLogJPN3->Integral("width");
    RooRealVar cjetNegLogJPYieldForData("cjetNegLogJPYieldForData", "cjet Yield", hsimTagjetNegLogJP[1][0]->Integral(1, hsimTagjetNegLogJP[1][0]->GetNbinsX() / incjetNegLogJPYield * incjetNegLogJPYield), 0.01*incjetNegLogJPYieldForData, incjetNegLogJPYieldForData);
    RooRealVar bjetNegLogJPYieldForData("bjetNegLogJPYieldForData", "bjet Yield", 100*hsimTagjetNegLogJP[2][0]->Integral(1, hsimTagjetNegLogJP[2][0]->GetNbinsX() / incjetNegLogJPYield * incjetNegLogJPYield), 0.01*incjetNegLogJPYieldForData, incjetNegLogJPYieldForData);
    RooRealVar lfjetNegLogJPYieldForData("lfjetNegLogJPYieldForData", "lfjet Yield", hsimTagjetNegLogJP[3][0]->Integral(1, hsimTagjetNegLogJP[3][0]->GetNbinsX() / incjetNegLogJPYield * incjetNegLogJPYieldForData), 0.01*incjetNegLogJPYieldForData, incjetNegLogJPYieldForData);

//    RooRealVar cjetNegLogJPN1YieldForData("cjetNegLogJPN1YieldForData", "cjet Yield", hsimTagjetNegLogJPN1[1][0]->Integral(1, hsimTagjetNegLogJPN1[1][0]->GetNbinsX()), 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
//    RooRealVar bjetNegLogJPN1YieldForData("bjetNegLogJPN1YieldForData", "bjet Yield", hsimTagjetNegLogJPN1[2][0]->Integral(1, hsimTagjetNegLogJPN1[2][0]->GetNbinsX()), 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
//    RooRealVar lfjetNegLogJPN1YieldForData("lfjetNegLogJPN1YieldForData", "lfjet Yield", hsimTagjetNegLogJPN1[3][0]->Integral(1, hsimTagjetNegLogJPN1[3][0]->GetNbinsX()), 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
    RooRealVar cjetNegLogJPN1YieldForData("cjetNegLogJPN1YieldForData", "cjet Yield", hsimTagjetNegLogJPN1[1][0]->Integral(1, hsimTagjetNegLogJPN1[1][0]->GetNbinsX()) / incjetNegLogJPN1Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
    RooRealVar bjetNegLogJPN1YieldForData("bjetNegLogJPN1YieldForData", "bjet Yield", hsimTagjetNegLogJPN1[2][0]->Integral(1, hsimTagjetNegLogJPN1[2][0]->GetNbinsX()) / incjetNegLogJPN1Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
    RooRealVar lfjetNegLogJPN1YieldForData("lfjetNegLogJPN1YieldForData", "lfjet Yield", hsimTagjetNegLogJPN1[3][0]->Integral(1, hsimTagjetNegLogJPN1[3][0]->GetNbinsX()) / incjetNegLogJPN1Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);

    RooRealVar cjetNegLogJPN2YieldForData("cjetNegLogJPN2YieldForData", "cjet Yield", hsimTagjetNegLogJPN2[1][0]->Integral(1, hsimTagjetNegLogJPN2[1][0]->GetNbinsX()) / incjetNegLogJPN2Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN2YieldForData, incjetNegLogJPN2YieldForData);
    RooRealVar bjetNegLogJPN2YieldForData("bjetNegLogJPN2YieldForData", "bjet Yield", hsimTagjetNegLogJPN2[2][0]->Integral(1, hsimTagjetNegLogJPN2[2][0]->GetNbinsX()) / incjetNegLogJPN2Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN2YieldForData, incjetNegLogJPN2YieldForData);
    RooRealVar lfjetNegLogJPN2YieldForData("lfjetNegLogJPN2YieldForData", "lfjet Yield", hsimTagjetNegLogJPN2[3][0]->Integral(1, hsimTagjetNegLogJPN2[3][0]->GetNbinsX()) / incjetNegLogJPN2Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN2YieldForData, incjetNegLogJPN2YieldForData);

    RooRealVar cjetNegLogJPN3YieldForData("cjetNegLogJPN3YieldForData", "cjet Yield", hsimTagjetNegLogJPN3[1][0]->Integral(1, hsimTagjetNegLogJPN3[1][0]->GetNbinsX()) / incjetNegLogJPN3Yield * incjetNegLogJPN3YieldForData, 0.01*incjetNegLogJPN3YieldForData, incjetNegLogJPN3YieldForData);
    RooRealVar bjetNegLogJPN3YieldForData("bjetNegLogJPN3YieldForData", "bjet Yield", hsimTagjetNegLogJPN3[2][0]->Integral(1, hsimTagjetNegLogJPN3[2][0]->GetNbinsX()) / incjetNegLogJPN3Yield * incjetNegLogJPN3YieldForData, 0.01*incjetNegLogJPN3YieldForData, incjetNegLogJPN3YieldForData);
    RooRealVar lfjetNegLogJPN3YieldForData("lfjetNegLogJPN3YieldForData", "lfjet Yield", hsimTagjetNegLogJPN3[3][0]->Integral(1, hsimTagjetNegLogJPN3[3][0]->GetNbinsX()) / incjetNegLogJPN3Yield * incjetNegLogJPN3YieldForData, 0.01*incjetNegLogJPN3YieldForData, incjetNegLogJPN3YieldForData);

    // Perform the fit to the data
    RooAddPdf modelFitMC("modelFitMC", "Total PDF", RooArgList(histPdfcjetNegLogJP, histPdfbjetNegLogJP, histPdflfjetNegLogJP), RooArgList(cjetNegLogJPYield, bjetNegLogJPYield, lfjetNegLogJPYield));
    RooAddPdf modelN1FitMC("modelN1FitMC", "Total PDF", RooArgList(histPdfcjetNegLogJPN1, histPdfbjetNegLogJPN1, histPdflfjetNegLogJPN1), RooArgList(cjetNegLogJPN1Yield, bjetNegLogJPN1Yield, lfjetNegLogJPN1Yield));
    RooAddPdf modelN2FitMC("modelN2FitMC", "Total PDF", RooArgList(histPdfcjetNegLogJPN2, histPdfbjetNegLogJPN2, histPdflfjetNegLogJPN2), RooArgList(cjetNegLogJPN2Yield, bjetNegLogJPN2Yield, lfjetNegLogJPN2Yield));
    RooAddPdf modelN3FitMC("modelN3FitMC", "Total PDF", RooArgList(histPdfcjetNegLogJPN3, histPdfbjetNegLogJPN3, histPdflfjetNegLogJPN3), RooArgList(cjetNegLogJPN3Yield, bjetNegLogJPN3Yield, lfjetNegLogJPN3Yield));
    RooAddPdf modelFitData("modelFitData", "Total PDF", RooArgList(histPdfcjetNegLogJPForData, histPdfbjetNegLogJPForData, histPdflfjetNegLogJPForData), RooArgList(cjetNegLogJPYieldForData, bjetNegLogJPYieldForData, lfjetNegLogJPYieldForData));
    RooAddPdf modelN1FitData("modelN1FitData", "Total PDF", RooArgList(histPdfcjetNegLogJPN1ForData, histPdfbjetNegLogJPN1ForData, histPdflfjetNegLogJPN1ForData), RooArgList(cjetNegLogJPN1YieldForData, bjetNegLogJPN1YieldForData, lfjetNegLogJPN1YieldForData));
    RooAddPdf modelN2FitData("modelN2FitData", "Total PDF", RooArgList(histPdfcjetNegLogJPN2ForData, histPdfbjetNegLogJPN2ForData, histPdflfjetNegLogJPN2ForData), RooArgList(cjetNegLogJPN2YieldForData, bjetNegLogJPN2YieldForData, lfjetNegLogJPN2YieldForData));
    RooAddPdf modelN3FitData("modelN3FitData", "Total PDF", RooArgList(histPdfcjetNegLogJPN3ForData, histPdfbjetNegLogJPN3ForData, histPdflfjetNegLogJPN3ForData), RooArgList(cjetNegLogJPN3YieldForData, bjetNegLogJPN3YieldForData, lfjetNegLogJPN3YieldForData));

    std::cout << "START MC FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPYield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPYield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPYield.getVal() << std::endl;
    RooFitResult* fitMC = modelFitMC.fitTo(mcincjetNegLogJP, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "cjet yield after: " << cjetNegLogJPYield.getVal() << std::endl;
    std::cout << "bjet yield after: " << bjetNegLogJPYield.getVal() << std::endl;
    std::cout << "lfjet yield after: " << lfjetNegLogJPYield.getVal() << std::endl;
    std::cout << "END MC FITTING" << std::endl;
    std::cout << "START MC (N1) FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPN1Yield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN1Yield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN1Yield.getVal() << std::endl;
    RooFitResult* fitN1MC = modelN1FitMC.fitTo(mcincjetNegLogJPN1, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "cjet yield before: " << cjetNegLogJPN1Yield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN1Yield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN1Yield.getVal() << std::endl;
    std::cout << "END MC (N1) FITTING" << std::endl;
    std::cout << "START MC (N2) FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPN2Yield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN2Yield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN2Yield.getVal() << std::endl;
    RooFitResult* fitN2MC = modelN2FitMC.fitTo(mcincjetNegLogJPN2, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "cjet yield before: " << cjetNegLogJPN2Yield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN2Yield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN2Yield.getVal() << std::endl;
    std::cout << "END MC (N2) FITTING" << std::endl;
    std::cout << "START MC (N3) FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPN3Yield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN3Yield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN3Yield.getVal() << std::endl;
    RooFitResult* fitN3MC = modelN3FitMC.fitTo(mcincjetNegLogJPN3, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "cjet yield before: " << cjetNegLogJPN3Yield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN3Yield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN3Yield.getVal() << std::endl;
    std::cout << "END MC (N3) FITTING" << std::endl;

    std::cout << "START DATA FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPYieldForData.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPYieldForData.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPYieldForData.getVal() << std::endl;
    RooFitResult* fitData = modelFitData.fitTo(datajetNegLogJP, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "incjet yield: " <<  incjetNegLogJPYieldForData << std::endl;
    std::cout << "cjet yield after: " << cjetNegLogJPYieldForData.getVal() << std::endl;
    std::cout << "bjet yield after: " << bjetNegLogJPYieldForData.getVal() << std::endl;
    std::cout << "lfjet yield after: " << lfjetNegLogJPYieldForData.getVal() << std::endl;
    std::cout << "END DATA FITTING" << std::endl;
    std::cout << "START DATA (N1) FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPN1YieldForData.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN1YieldForData.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN1YieldForData.getVal() << std::endl;
    RooFitResult* fitN1Data = modelN1FitData.fitTo(datajetNegLogJPN1, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "incjet yield: " <<  incjetNegLogJPN1YieldForData << std::endl;
    std::cout << "cjet yield after: " << cjetNegLogJPN1YieldForData.getVal() << std::endl;
    std::cout << "bjet yield after: " << bjetNegLogJPN1YieldForData.getVal() << std::endl;
    std::cout << "lfjet yield after: " << lfjetNegLogJPN1YieldForData.getVal() << std::endl;
    std::cout << "END DATA (N1) FITTING" << std::endl;
    std::cout << "START DATA (N2) FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPN2YieldForData.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN2YieldForData.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN2YieldForData.getVal() << std::endl;
    RooFitResult* fitN2Data = modelN2FitData.fitTo(datajetNegLogJPN2, RooFit::Minos(kTRUE), RooFit::Save(true));
    std::cout << "incjet yield: " <<  incjetNegLogJPN2YieldForData << std::endl;
    std::cout << "cjet yield after: " << cjetNegLogJPN2YieldForData.getVal() << std::endl;
    std::cout << "bjet yield after: " << bjetNegLogJPN2YieldForData.getVal() << std::endl;
    std::cout << "lfjet yield after: " << lfjetNegLogJPN2YieldForData.getVal() << std::endl;
    if (!fitN2Data || fitN2Data->status() != 0) {
      std::cerr << "Error: Fit did not converge." << std::endl;
    }
    std::cout << "END DATA (N2) FITTING" << std::endl;
    std::cout << "START DATA (N3) FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetNegLogJPN3YieldForData.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetNegLogJPN3YieldForData.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetNegLogJPN3YieldForData.getVal() << std::endl;

    RooFitResult* fitN3Data = modelN3FitData.fitTo(datajetNegLogJPN3, RooFit::Minos(kFALSE), RooFit::Save(true));
    std::cout << "incjet yield: " <<  incjetNegLogJPN3YieldForData << std::endl;
    std::cout << "cjet yield after: " << cjetNegLogJPN3YieldForData.getVal() << std::endl;
    std::cout << "bjet yield after: " << bjetNegLogJPN3YieldForData.getVal() << std::endl;
    std::cout << "lfjet yield after: " << lfjetNegLogJPN3YieldForData.getVal() << std::endl;
    std::cout << "END DATA (N3) FITTING" << std::endl;

    std::cout<<"fit MC: " << std::endl;
    fitMC->Print();

    std::cout<<"fit data: " << std::endl;
    fitData->Print();

    std::cout<<"fit N1 MC: " << std::endl;
    fitN1MC->Print();

    std::cout<<"fit N1 data: " << std::endl;
    fitN1Data->Print();

    std::cout<<"fit N2 MC: " << std::endl;
    fitN2MC->Print();

    std::cout<<"fit N2 data: " << std::endl;
    fitN2Data->Print();

    std::cout<<"fit N3 MC: " << std::endl;
    fitN3MC->Print();

    std::cout<<"fit N3 data: " << std::endl;
    fitN3Data->Print();

    RooPlot* frameMC = jetProb.frame();
    mcincjetNegLogJP.plotOn(frameMC, RooFit::DrawOption(""));
    modelFitMC.plotOn(frameMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelFitMC"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfcjetNegLogJP"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfbjetNegLogJP"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdflfjetNegLogJP"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameMC->GetYaxis()->SetRangeUser(1, incjetNegLogJPYield);

    RooPlot* frameMCN1 = jetProb.frame();
    mcincjetNegLogJPN1.plotOn(frameMCN1, RooFit::DrawOption(""));
    modelN1FitMC.plotOn(frameMCN1, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelN1FitMC"));
    modelN1FitMC.plotOn(frameMCN1, RooFit::Components("histPdfcjetNegLogJPN1"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelN1FitMC.plotOn(frameMCN1, RooFit::Components("histPdfbjetNegLogJPN1"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelN1FitMC.plotOn(frameMCN1, RooFit::Components("histPdflfjetNegLogJPN1"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameMCN1->GetYaxis()->SetRangeUser(1, incjetNegLogJPN1Yield);

    RooPlot* frameMCN2 = jetProb.frame();
    mcincjetNegLogJPN2.plotOn(frameMCN2, RooFit::DrawOption(""));
    modelN2FitMC.plotOn(frameMCN2, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelFit"));
    modelN2FitMC.plotOn(frameMCN2, RooFit::Components("histPdfcjetNegLogJPN2"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelN2FitMC.plotOn(frameMCN2, RooFit::Components("histPdfbjetNegLogJPN2"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelN2FitMC.plotOn(frameMCN2, RooFit::Components("histPdflfjetNegLogJPN2"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameMCN2->GetYaxis()->SetRangeUser(1, incjetNegLogJPN2Yield);

    RooPlot* frameMCN3 = jetProb.frame();
    mcincjetNegLogJPN3.plotOn(frameMCN3, RooFit::DrawOption(""));
    modelN3FitMC.plotOn(frameMCN3, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelFit"));
    modelN3FitMC.plotOn(frameMCN3, RooFit::Components("histPdfcjetNegLogJPN3"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelN3FitMC.plotOn(frameMCN3, RooFit::Components("histPdfbjetNegLogJPN3"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelN3FitMC.plotOn(frameMCN3, RooFit::Components("histPdflfjetNegLogJPN3"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameMCN3->GetYaxis()->SetRangeUser(1, incjetNegLogJPN3Yield);

    RooPlot* frameData = jetProb.frame();
    datajetNegLogJP.plotOn(frameData, RooFit::DrawOption(""));
    modelFitData.plotOn(frameData, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
    modelFitData.plotOn(frameData, RooFit::Components("histPdfcjetNegLogJPForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelFitData.plotOn(frameData, RooFit::Components("histPdfbjetNegLogJPForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelFitData.plotOn(frameData, RooFit::Components("histPdflfjetNegLogJPForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameData->GetYaxis()->SetRangeUser(1, incjetNegLogJPYieldForData);

    RooPlot* frameDataN1 = jetProb.frame();
    datajetNegLogJPN1.plotOn(frameDataN1, RooFit::DrawOption(""));
    modelN1FitData.plotOn(frameDataN1, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
    modelN1FitData.plotOn(frameDataN1, RooFit::Components("histPdfcjetNegLogJPN1ForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelN1FitData.plotOn(frameDataN1, RooFit::Components("histPdfbjetNegLogJPN1ForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelN1FitData.plotOn(frameDataN1, RooFit::Components("histPdflfjetNegLogJPN1ForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameDataN1->GetYaxis()->SetRangeUser(1, incjetNegLogJPN1YieldForData);

    RooPlot* frameDataN2 = jetProb.frame();
    datajetNegLogJPN2.plotOn(frameDataN2, RooFit::DrawOption(""));
    modelN2FitData.plotOn(frameDataN2, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
    modelN2FitData.plotOn(frameDataN2, RooFit::Components("histPdfcjetNegLogJPN2ForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelN2FitData.plotOn(frameDataN2, RooFit::Components("histPdfbjetNegLogJPN2ForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelN2FitData.plotOn(frameDataN2, RooFit::Components("histPdflfjetNegLogJPN2ForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameDataN2->GetYaxis()->SetRangeUser(1, incjetNegLogJPN2YieldForData);

    RooPlot* frameDataN3 = jetProb.frame();
    datajetNegLogJPN3.plotOn(frameDataN3, RooFit::DrawOption(""));
    modelN3FitData.plotOn(frameDataN3, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
    modelN3FitData.plotOn(frameDataN3, RooFit::Components("histPdfcjetNegLogJPN3ForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
    modelN3FitData.plotOn(frameDataN3, RooFit::Components("histPdfbjetNegLogJPN3ForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
    modelN3FitData.plotOn(frameDataN3, RooFit::Components("histPdflfjetNegLogJPN3ForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
    frameDataN3->GetYaxis()->SetRangeUser(1, incjetNegLogJPN3YieldForData);

    // Draw the frame
    TCanvas canvasMC("canvasMC", "Template Fit");
    gPad->SetLogy();
    frameMC->Draw();
    canvasMC.SaveAs(Form("fig/sim/%s/jp/template_fit_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]) ));

    TCanvas canvasMCN1("canvasMCN1", "Template Fit");
    gPad->SetLogy();
    frameMCN1->Draw();
    canvasMCN1.SaveAs(Form("fig/sim/%s/jp/template_fit_N1_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    TCanvas canvasMCN2("canvasMCN2", "Template Fit");
    gPad->SetLogy();
    frameMCN2->Draw();
    canvasMCN2.SaveAs(Form("fig/sim/%s/jp/template_fit_N2_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    TCanvas canvasMCN3("canvasMCN3", "Template Fit");
    gPad->SetLogy();
    frameMCN3->Draw();
    canvasMCN3.SaveAs(Form("fig/sim/%s/jp/template_fit_N3_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    TCanvas canvasData("canvasData", "Template Fit");
    gPad->SetLogy();
    frameData->Draw();
    canvasData.SaveAs(Form("fig/data/%s/jp/template_fit_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    TCanvas canvasDataN1("canvasDataN1", "Template Fit");
    canvasDataN1.cd();
    gPad->SetLogy();
    frameDataN1->Draw();
    canvasDataN1.SaveAs(Form("fig/data/%s/jp/template_fit_N1_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    TCanvas canvasDataN2("canvasDataN2", "Template Fit");
    canvasDataN2.cd();
    gPad->SetLogy();
    frameDataN2->Draw();
    canvasDataN2.SaveAs(Form("fig/data/%s/jp/template_fit_N2_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    TCanvas canvasDataN3("canvasDataN3", "Template Fit");
    canvasDataN3.cd();
    gPad->SetLogy();
    frameDataN3->Draw();
    canvasDataN3.SaveAs(Form("fig/data/%s/jp/template_fit_N3_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.12);
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
    gPad->SetLogy();
    frameMC->Draw();
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
    gPad->SetLogy();
    frameMCN1->Draw();
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
    gPad->SetLogy();
    frameMCN2->Draw();
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
    gPad->SetLogy();
    frameMCN3->Draw();
    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/template_fit_N4x1_mc_%d.png\")", nc++, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.12);
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
    gPad->SetLogy();
    frameData->Draw();
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
    gPad->SetLogy();
    frameDataN1->Draw();
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
    gPad->SetLogy();
    frameDataN2->Draw();
    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
    gPad->SetLogy();
    frameDataN3->Draw();
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template_fit_N4x1_data_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    // make pdf histogram from template fit
    std::cout << "Drive method: creating pdf histogram" << std::endl;
    hdataTagjetNegLogJP[1][binJetPt] = (TH1F*) modelFitData.createHistogram(Form("hdatajetNegLogJP_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPForData"));
    hdataTagjetNegLogJP[2][binJetPt] = (TH1F*) modelFitData.createHistogram(Form("hdatajetNegLogJP_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPForData"));
    hdataTagjetNegLogJP[3][binJetPt] = (TH1F*) modelFitData.createHistogram(Form("hdatajetNegLogJP_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPForData"));
    hdataTagjetNegLogJPN1[1][binJetPt] = (TH1F*) modelN1FitData.createHistogram(Form("hdatajetNegLogJPN1_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPN1ForData"));
    hdataTagjetNegLogJPN1[2][binJetPt] = (TH1F*) modelN1FitData.createHistogram(Form("hdatajetNegLogJPN1_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPN1ForData"));
    hdataTagjetNegLogJPN1[3][binJetPt] = (TH1F*) modelN1FitData.createHistogram(Form("hdatajetNegLogJPN1_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPN1ForData"));
    hdataTagjetNegLogJPN2[1][binJetPt] = (TH1F*) modelN2FitData.createHistogram(Form("hdatajetNegLogJPN2_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPN2ForData"));
    hdataTagjetNegLogJPN2[2][binJetPt] = (TH1F*) modelN2FitData.createHistogram(Form("hdatajetNegLogJPN2_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPN2ForData"));
    hdataTagjetNegLogJPN2[3][binJetPt] = (TH1F*) modelN2FitData.createHistogram(Form("hdatajetNegLogJPN2_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPN2ForData"));
    hdataTagjetNegLogJPN3[1][binJetPt] = (TH1F*) modelN3FitData.createHistogram(Form("hdatajetNegLogJPN3_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPN3ForData"));
    hdataTagjetNegLogJPN3[2][binJetPt] = (TH1F*) modelN3FitData.createHistogram(Form("hdatajetNegLogJPN3_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPN3ForData"));
    hdataTagjetNegLogJPN3[3][binJetPt] = (TH1F*) modelN3FitData.createHistogram(Form("hdatajetNegLogJPN3_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPN3ForData"));
    std::cout << "Drive method: finisihed" << std::endl;
  }
}

void HfJetTaggingJPAnalysis::drawDataJetEffiN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN1 = taggingutilities::getEfficiency(hdataTagjetNegLogJPN1[flavour][binJetPt],hdataTagjetNegLogJP[flavour][binJetPt]);
      if (effiN1 < 0) continue;
      hdataJPEffiN1[flavour]->SetBinContent(binJetPt, effiN1);
    }
	  normHist.push_back({hdataJPEffiN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN1.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingJPAnalysis::drawDataJetEffiN2(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN2 = taggingutilities::getEfficiency(hdataTagjetNegLogJPN2[flavour][binJetPt],hdataTagjetNegLogJP[flavour][binJetPt]);
      if (effiN2 < 0) continue;
      hdataJPEffiN2[flavour]->SetBinContent(binJetPt, effiN2);
    }
	  normHist.push_back({hdataJPEffiN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=2");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN2.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingJPAnalysis::drawDataJetEffiN3(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN3 = taggingutilities::getEfficiency(hdataTagjetNegLogJPN3[flavour][binJetPt],hdataTagjetNegLogJP[flavour][binJetPt]);
      if (effiN3 < 0) continue;
      hdataJPEffiN3[flavour]->SetBinContent(binJetPt, effiN3);
    }
	  normHist.push_back({hdataJPEffiN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=3");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN3.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingJPAnalysis::drawDataJetPurityN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      TH1F* htemp = new TH1F();
      htemp->Add(hdataTagjetNegLogJPN1[1][binJetPt]);
      htemp->Add(hdataTagjetNegLogJPN1[2][binJetPt]);
      htemp->Add(hdataTagjetNegLogJPN1[3][binJetPt]);
      //float purityN1 = taggingutilities::getPurity(hdataTagjetNegLogJPN1[flavour][binJetPt],hdataTagjetNegLogJPN1[0][binJetPt]);
      float purityN1 = taggingutilities::getPurity(hdataTagjetNegLogJPN1[flavour][binJetPt], htemp);
      hdataJPPurityN1[flavour]->SetBinContent(binJetPt, purityN1);
    }
	  normHist.push_back({hdataJPPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityJPN1.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingJPAnalysis::drawDataJetPurityN2(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      TH1F* htemp = new TH1F();
      htemp->Add(hdataTagjetNegLogJPN2[1][binJetPt]);
      htemp->Add(hdataTagjetNegLogJPN2[2][binJetPt]);
      htemp->Add(hdataTagjetNegLogJPN2[3][binJetPt]);
      //float purityN2 = taggingutilities::getPurity(hdataTagjetNegLogJPN2[flavour][binJetPt],hdataTagjetNegLogJPN2[0][binJetPt]);
      float purityN2 = taggingutilities::getPurity(hdataTagjetNegLogJPN2[flavour][binJetPt], htemp);
      hdataJPPurityN2[flavour]->SetBinContent(binJetPt, purityN2);
    }
	  normHist.push_back({hdataJPPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityJPN2.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingJPAnalysis::drawDataJetPurityN3(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      TH1F* htemp = new TH1F();
      htemp->Add(hdataTagjetNegLogJPN3[1][binJetPt]);
      htemp->Add(hdataTagjetNegLogJPN3[2][binJetPt]);
      htemp->Add(hdataTagjetNegLogJPN3[3][binJetPt]);
      //float purityN3 = taggingutilities::getPurity(hdataTagjetNegLogJPN3[flavour][binJetPt],hdataTagjetNegLogJPN3[0][binJetPt]);
      float purityN3 = taggingutilities::getPurity(hdataTagjetNegLogJPN3[flavour][binJetPt], htemp);
      hdataJPPurityN3[flavour]->SetBinContent(binJetPt, purityN3);
    }
	  normHist.push_back({hdataJPPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityJPN3.pdf\")", nc++, dirData.Data()));
}

//void HfJetTaggingJPAnalysis::drawSimJetEffiAndPurityNx(TH1F* hImpNx, TH1F*hbasejet[][HfJetTagging::nBinsJetPt+1], float cutImp, int flavour, int binJetPt) {
//  // it needs TGraph
//  TGraph *gN1 = new TGraph();
//  std::vector<std::vector<float>> effiAndPurity
//  effi = static_cast<float>(calculateEffiSignedImpXYSig(hImpNx, cutImp));
//  purity = static_cast<float>(calculatePurity(flavour, binJetPt, hbaseImpNx, cutImp));
//  hsimTagjetNegLogJPN1->
//
//}

#endif // HFJETTAGGINGJPANALYSIS_H 
