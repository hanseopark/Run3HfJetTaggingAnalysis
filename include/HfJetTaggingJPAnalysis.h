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

    // jp
    /// data
    int loadDataJPQA(TString rootData);
    void initHistJPData();
    void projectionHistJPQAData();
    void initJPData(TString rootData);

    /// mc
    int loadSimJPQA(TString rootSim);
    void initHistJPMC();
    void projectionHistJPQAMC();
    void initJPMC(TString rootSim);
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
    CanvasHandler* canHan;
    //// data
    void drawDataJP(bool doLog, int binJetPt);
    void drawDataNegLogJP(bool doLog, int binJetPt);
    void drawDatataggedjetJPN1(bool doLog, int binJetPt, float cutImp);
    void drawDatataggedjetNegLogJPN1(bool doLog, int binJetPt, float cutImp);
    void drawDatataggedjetJPN2(bool doLog, int binJetPt, float cutImp);
    void drawDatataggedjetNegLogJPN2(bool doLog, int binJetPt, float cutImp);
    void drawDatataggedjetJPN3(bool doLog, int binJetPt, float cutImp);
    void drawDatataggedjetNegLogJPN3(bool doLog, int binJetPt, float cutImp);
    void drawDataNegLogJPN4x1(bool doLog, int binJetPt, float cutImp);

    //// mc
    void drawSimTrackProb(bool withInc, bool doLog, int binJetPt);
    void drawSimJP(bool withInc, bool doLog, int binJetPt);
    void drawSimNegLogJP(bool withInc, bool doLog, int binJetPt);
    void drawSimtaggedjetJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimtaggedjetNegLogJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimtaggedjetJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimtaggedjetNegLogJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimtaggedjetJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimtaggedjetNegLogJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimNegLogJPN4x1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJPRef();
    void drawSimJPEffiN1(float cutImp);
    void drawSimJPEffiN2(float cutImp);
    void drawSimJPEffiN3(float cutImp);
    void drawSimJPEffiNx(float cutImp);
    void drawSimJPPurityN1(float cutImp);
    void drawSimJPPurityN2(float cutImp);
    void drawSimJPPurityN3(float cutImp);
    void drawSimJPPurityNx(float cutImp);
    void drawSimJPEffiAndPurity(float cutImp, int binJetPt);
    void drawTemplateFit();
    void drawDataJetEffiN1(float cutImp);
    void drawDataJetEffiN2(float cutImp);
    void drawDataJetEffiN3(float cutImp);
    void drawDataJetEffiNx(float cutImp);
    void drawDataJetPurityN1(float cutImp);
    void drawDataJetPurityN2(float cutImp);
    void drawDataJetPurityN3(float cutImp);

  protected:
    // hist from root (Data)
    TH2F* h2datajetPtJP;
    TH2F* h2datajetPtNegLogJP;
    TH2F* h2datataggedjetPtJPN1;
    TH2F* h2datataggedjetPtNegLogJPN1;
    TH2F* h2datataggedjetPtJPN2;
    TH2F* h2datataggedjetPtNegLogJPN2;
    TH2F* h2datataggedjetPtJPN3;
    TH2F* h2datataggedjetPtNegLogJPN3;

    // hist (Data)
    TH1F* hdatajetPosTrackProb;
    TH1F* hdatajetNegTrackProb;
    TH1F* hdatajetJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNegLogJPN3[HfJetTagging::nBinsJetPt+1];

    /// norm
    TH1F* hdatajetNormNEventsJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEventsJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEventsJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEventsJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEventsNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEventsNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEventsNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEventsNegLogJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormAreaJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormAreaJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormAreaJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormAreaJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormAreaNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormAreaNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormAreaNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormAreaNegLogJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJetsJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJetsJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJetsJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJetsJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJetsNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJetsNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJetsNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJetsNegLogJPN3[HfJetTagging::nBinsJetPt+1];

    // hist from root (MC)
    TH2F* h2simjetPosTPFlavour;
    TH2F* h2simjetNegTPFlavour;
    TH2F* h2simjetPtFlavour;
    TH3F* h3simjetPtJPFlavour;
    TH3F* h3simjetPtNegLogJPFlavour;
    TH3F* h3simtaggedjetPtJPN1Flavour;
    TH3F* h3simtaggedjetPtNegLogJPN1Flavour;
    TH3F* h3simtaggedjetPtJPN2Flavour;
    TH3F* h3simtaggedjetPtNegLogJPN2Flavour;
    TH3F* h3simtaggedjetPtJPN3Flavour;
    TH3F* h3simtaggedjetPtNegLogJPN3Flavour;

    // hist (MC)
    TH1F* hsimjetPosTrackProb[HfJetTagging::nFlavour];
    TH1F* hsimjetNegTrackProb[HfJetTagging::nFlavour];
    TH1F* hsimjetJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    // norm
    TH1F* hsimjetNormNEventsJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEventsJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEventsNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEventsJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEventsNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEventsJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEventsNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormAreaJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormAreaNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormAreaJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormAreaNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormAreaJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormAreaNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJetsJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJetsNegLogJPN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJetsJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJetsNegLogJPN2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJetsJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJetsNegLogJPN3[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimRefTagger[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN3[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN3[HfJetTagging::nFlavour+1];
    
    // effi
    TH1F* hdataJPEffiN1[HfJetTagging::nFlavour+1];
    TH1F* hdataJPEffiN2[HfJetTagging::nFlavour+1];
    TH1F* hdataJPEffiN3[HfJetTagging::nFlavour+1];
    TH1F* hdataJPPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hdataJPPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hdataJPPurityN3[HfJetTagging::nFlavour+1];
  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    bool fillTP = false;
    bool fillTF = false;
    bool fillEffi = false;

};

//HfJetTaggingJPAnalysis::~HfJetTaggingJPAnalysis() {
//  delete h3simjetPtJPFlavour;
//  for (int flavour=0; flavour < HfJetTagging::nFlavour; flavour++) {
//    for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
//      delete hsimjetJP[flavour][binJetPt];
//      delete hsimjetNegLogJP[flavour][binJetPt];
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
  h2datajetPtJP = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_JP", taskName.Data())));
  h2datajetPtNegLogJP = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_neg_log_JP", taskName.Data())));
  h2datataggedjetPtJPN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_JP_N1", taskName.Data())));
  h2datataggedjetPtNegLogJPN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_neg_log_JP_N1", taskName.Data())));
  h2datataggedjetPtJPN2 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_JP_N2", taskName.Data())));
  h2datataggedjetPtNegLogJPN2 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_neg_log_JP_N2", taskName.Data())));
  h2datataggedjetPtJPN3 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_JP_N3", taskName.Data())));
  h2datataggedjetPtNegLogJPN3 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_neg_log_JP_N3", taskName.Data())));

  return 1;
}

void HfJetTaggingJPAnalysis::initHistJPData() {
  for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
    hdatajetJP[jetPt] = new TH1F(Form("hdatajetJP_%d",  jetPt), "", h2datajetPtJP->GetNbinsY(), h2datajetPtJP->GetYaxis()->GetBinLowEdge(1), h2datajetPtJP->GetYaxis()->GetBinUpEdge(h2datajetPtJP->GetNbinsY()));
    hdatataggedjetJPN1[jetPt] = new TH1F(Form("hdatajetJP_N1_%d", jetPt), "", h2datataggedjetPtJPN1->GetNbinsY(), h2datataggedjetPtJPN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPtJPN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPtJPN1->GetNbinsY()));
    hdatataggedjetJPN2[jetPt] = new TH1F(Form("hdatajetJP_N2_%d", jetPt), "", h2datataggedjetPtJPN2->GetNbinsY(), h2datataggedjetPtJPN2->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPtJPN2->GetYaxis()->GetBinUpEdge(h2datataggedjetPtJPN2->GetNbinsY()));
    hdatataggedjetJPN3[jetPt] = new TH1F(Form("hdatajetJP_N3_%d", jetPt), "", h2datataggedjetPtJPN3->GetNbinsY(), h2datataggedjetPtJPN3->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPtJPN3->GetYaxis()->GetBinUpEdge(h2datataggedjetPtJPN3->GetNbinsY()));
    hdatajetNegLogJP[jetPt] = new TH1F(Form("hdatajetNegLogJP_%d", jetPt), "", h2datajetPtNegLogJP->GetNbinsY(), h2datajetPtNegLogJP->GetYaxis()->GetBinLowEdge(1), h2datajetPtNegLogJP->GetYaxis()->GetBinUpEdge(h2datajetPtNegLogJP->GetNbinsY()));
    hdatataggedjetNegLogJPN1[jetPt] = new TH1F(Form("hdatajetNegLogJP_N1_%d", jetPt), "", h2datataggedjetPtNegLogJPN1->GetNbinsY(), h2datataggedjetPtNegLogJPN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPtNegLogJPN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPtNegLogJPN1->GetNbinsY()));
    hdatataggedjetNegLogJPN2[jetPt] = new TH1F(Form("hdatajetNegLogJP_N2_%d", jetPt), "", h2datataggedjetPtNegLogJPN2->GetNbinsY(), h2datataggedjetPtNegLogJPN2->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPtNegLogJPN2->GetYaxis()->GetBinUpEdge(h2datataggedjetPtNegLogJPN2->GetNbinsY()));
    hdatataggedjetNegLogJPN3[jetPt] = new TH1F(Form("hdatajetNegLogJP_N3_%d", jetPt), "", h2datataggedjetPtNegLogJPN3->GetNbinsY(), h2datataggedjetPtNegLogJPN3->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPtNegLogJPN3->GetYaxis()->GetBinUpEdge(h2datataggedjetPtNegLogJPN3->GetNbinsY()));
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

void HfJetTaggingJPAnalysis::projectionHistJPQAData() {
  TH1F *projJP = reinterpret_cast<TH1F*> (h2datajetPtJP->ProjectionY("projJP", 1, h2datajetPtJP->GetNbinsX()));
  TH1F *projJPN1 = reinterpret_cast<TH1F*> (h2datataggedjetPtJPN1->ProjectionY("projJPN1", 1, h2datataggedjetPtJPN1->GetNbinsX()));
  TH1F *projJPN2 = reinterpret_cast<TH1F*> (h2datataggedjetPtJPN2->ProjectionY("projJPN2", 1, h2datataggedjetPtJPN2->GetNbinsX()));
  TH1F *projJPN3 = reinterpret_cast<TH1F*> (h2datataggedjetPtJPN3->ProjectionY("projJPN3", 1, h2datataggedjetPtJPN3->GetNbinsX()));
  TH1F *projNegLogJP = reinterpret_cast<TH1F*> (h2datajetPtNegLogJP->ProjectionY("projNegLogJP", 1, h2datajetPtNegLogJP->GetNbinsX()));
  TH1F *projNegLogJPN1 = reinterpret_cast<TH1F*> (h2datataggedjetPtNegLogJPN1->ProjectionY("projNegLogJPN1", 1, h2datataggedjetPtNegLogJPN1->GetNbinsX()));
  TH1F *projNegLogJPN2 = reinterpret_cast<TH1F*> (h2datataggedjetPtNegLogJPN2->ProjectionY("projNegLogJPN2", 1, h2datataggedjetPtNegLogJPN2->GetNbinsX()));
  TH1F *projNegLogJPN3 = reinterpret_cast<TH1F*> (h2datataggedjetPtNegLogJPN3->ProjectionY("projNegLogJPN3", 1, h2datataggedjetPtNegLogJPN3->GetNbinsX()));

  hdatajetJP[0] = reinterpret_cast<TH1F*>(projJP->Clone("hdatajetJP")); 
  hdatataggedjetJPN1[0] = reinterpret_cast<TH1F*>(projJPN1->Clone("hdatataggedjetJPN1")); 
  hdatataggedjetJPN2[0] = reinterpret_cast<TH1F*>(projJPN2->Clone("hdatataggedjetJPN2")); 
  hdatataggedjetJPN3[0] = reinterpret_cast<TH1F*>(projJPN3->Clone("hdatataggedjetJPN3")); 
  hdatajetNegLogJP[0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone("hdatajetNegLogJP")); 
  hdatataggedjetNegLogJPN1[0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone("hdatataggedjetNegLogJPN1")); 
  hdatataggedjetNegLogJPN2[0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone("hdatataggedjetNegLogJPN2")); 
  hdatataggedjetNegLogJPN3[0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone("hdatataggedjetNegLogJPN3")); 


  for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    int leftbinJetPtJP = h2datajetPtJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJP = h2datajetPtJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJP = reinterpret_cast<TH1F*> (h2datajetPtJP->ProjectionY(Form("projJetPtRangeJP_%d", binJetPt), leftbinJetPtJP, rightbinJetPtJP));
    hdatajetJP[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJP->Clone(Form("hdatajetJP_%d", binJetPt))); 

    int leftbinJetPtJPN1 = h2datataggedjetPtJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJPN1 = h2datataggedjetPtJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJPN1 = reinterpret_cast<TH1F*> (h2datataggedjetPtJPN1->ProjectionY(Form("projJetPtRangeJPN1_%d", binJetPt), leftbinJetPtJPN1, rightbinJetPtJPN1));
    hdatataggedjetJPN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN1->Clone(Form("hdatataggedjetJPN1_%d", binJetPt))); 

    int leftbinJetPtJPN2 = h2datataggedjetPtJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJPN2 = h2datataggedjetPtJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJPN2 = reinterpret_cast<TH1F*> (h2datataggedjetPtJPN2->ProjectionY(Form("projJetPtRangeJPN2_%d", binJetPt), leftbinJetPtJPN2, rightbinJetPtJPN2));
    hdatataggedjetJPN2[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN2->Clone(Form("hdatataggedjetJPN2_%d", binJetPt))); 

    int leftbinJetPtJPN3 = h2datataggedjetPtJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtJPN3 = h2datataggedjetPtJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeJPN3 = reinterpret_cast<TH1F*> (h2datataggedjetPtJPN3->ProjectionY(Form("projJetPtRangeJPN3_%d", binJetPt), leftbinJetPtJPN3, rightbinJetPtJPN3));
    hdatataggedjetJPN3[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN3->Clone(Form("hdatataggedjetJPN3_%d", binJetPt))); 

    int leftbinJetPtNegLogJP = h2datajetPtNegLogJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJP = h2datajetPtNegLogJP->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h2datajetPtNegLogJP->ProjectionY(Form("projJetPtRangeNegLogJP_%d", binJetPt), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP));
    hdatajetNegLogJP[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hdatajetNegLogJP_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN1 = h2datataggedjetPtNegLogJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN1 = h2datataggedjetPtNegLogJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h2datataggedjetPtNegLogJPN1->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d", binJetPt), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1));
    hdatataggedjetNegLogJPN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hdatataggedjetNegLogJPN1_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN2 = h2datataggedjetPtNegLogJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN2 = h2datataggedjetPtNegLogJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h2datataggedjetPtNegLogJPN2->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d", binJetPt), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2));
    hdatataggedjetNegLogJPN2[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hdatataggedjetNegLogJPN2_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN3 = h2datataggedjetPtNegLogJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN3 = h2datataggedjetPtNegLogJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h2datataggedjetPtNegLogJPN3->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d", binJetPt), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3));
    hdatataggedjetNegLogJPN3[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hdatataggedjetNegLogJPN3_%d", binJetPt))); 
  }
}

void HfJetTaggingJPAnalysis::initJPData(TString rootData) {
  loadDataJPQA(rootData.Data());
  initHistJPData();
  projectionHistJPQAData();
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
  h2simjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskName.Data())));
  h3simjetPtJPFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_JP_flavour", taskName.Data())));
  h3simjetPtNegLogJPFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
  h3simtaggedjetPtJPN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_JP_N1_flavour", taskName.Data())));
  h3simtaggedjetPtNegLogJPN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_neg_log_JP_N1_flavour", taskName.Data())));
  h3simtaggedjetPtJPN2Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_JP_N2_flavour", taskName.Data())));
  h3simtaggedjetPtNegLogJPN2Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_neg_log_JP_N2_flavour", taskName.Data())));
  h3simtaggedjetPtJPN3Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_JP_N3_flavour", taskName.Data())));
  h3simtaggedjetPtNegLogJPN3Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_neg_log_JP_N3_flavour", taskName.Data())));

  if (fillTP) {
    h2simjetPosTPFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_pos_track_probability_flavour", taskNameTP.Data())));
    h2simjetNegTPFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_neg_track_probability_flavour", taskNameTP.Data())));
    std::cout << "Load completed JP MC data with TP" << std::endl;
  }

  std::cout << "Load completed JP MC data" << std::endl;
  return 1;
}

void HfJetTaggingJPAnalysis::initHistJPMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimRefTagger[flavour] = new TH1F(Form("hsimRefTagger_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    if (fillTF) {
      hsimjetPosTrackProb[flavour] = new TH1F(Form("hsimPostTrackProb_%d", flavour), "", h2simjetPosTPFlavour->GetNbinsX(), h2simjetPosTPFlavour->GetXaxis()->GetBinLowEdge(1), h2simjetPosTPFlavour->GetXaxis()->GetBinUpEdge(h2simjetPosTPFlavour->GetNbinsX()));
      hsimjetNegTrackProb[flavour] = new TH1F(Form("hsimNegtTrackProb_%d", flavour), "", h2simjetNegTPFlavour->GetNbinsX(), h2simjetNegTPFlavour->GetXaxis()->GetBinLowEdge(1), h2simjetNegTPFlavour->GetXaxis()->GetBinUpEdge(h2simjetNegTPFlavour->GetNbinsX()));
    }
		hsimJPEffiN1[flavour] = new TH1F(Form("hsimJPEffiN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPEffiN2[flavour] = new TH1F(Form("hsimJPEffiN2_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPEffiN3[flavour] = new TH1F(Form("hsimJPEffiN3_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPPurityN1[flavour] = new TH1F(Form("hsimJPPurityN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPPurityN2[flavour] = new TH1F(Form("hsimJPPurityN2_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		hsimJPPurityN3[flavour] = new TH1F(Form("hsimJPPurityN3_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimjetJP[flavour][jetPt] = new TH1F(Form("hsimjetJP_%d_%d", flavour, jetPt), "", h3simjetPtJPFlavour->GetNbinsY(), h3simjetPtJPFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtJPFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtJPFlavour->GetNbinsY()));
			hsimjetNegLogJP[flavour][jetPt] = new TH1F(Form("hsimjetNegLogJP_%d_%d", flavour, jetPt), "", h3simjetPtNegLogJPFlavour->GetNbinsY(), h3simjetPtNegLogJPFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPFlavour->GetNbinsY()));
			hsimtaggedjetJPN1[flavour][jetPt] = new TH1F(Form("hsimjetJP_N1_%d_%d", flavour, jetPt), "", h3simtaggedjetPtJPN1Flavour->GetNbinsY(), h3simtaggedjetPtJPN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPtJPN1Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPtJPN1Flavour->GetNbinsY()));
			hsimtaggedjetNegLogJPN1[flavour][jetPt] = new TH1F(Form("hsimtaggedjetNegLogJPN1_%d_%d", flavour, jetPt), "", h3simtaggedjetPtNegLogJPN1Flavour->GetNbinsY(), h3simtaggedjetPtNegLogJPN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPtNegLogJPN1Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPtNegLogJPN1Flavour->GetNbinsY()));
			hsimtaggedjetJPN2[flavour][jetPt] = new TH1F(Form("hsimjetJP_N2_%d_%d", flavour, jetPt), "", h3simtaggedjetPtJPN2Flavour->GetNbinsY(), h3simtaggedjetPtJPN2Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPtJPN2Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPtJPN2Flavour->GetNbinsY()));
			hsimtaggedjetNegLogJPN2[flavour][jetPt] = new TH1F(Form("hsimtaggedjetNegLogJPN2_%d_%d", flavour, jetPt), "", h3simtaggedjetPtNegLogJPN2Flavour->GetNbinsY(), h3simtaggedjetPtNegLogJPN2Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPtNegLogJPN2Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPtNegLogJPN2Flavour->GetNbinsY()));
			hsimtaggedjetJPN3[flavour][jetPt] = new TH1F(Form("hsimjetJP_N3_%d_%d", flavour, jetPt), "", h3simtaggedjetPtJPN3Flavour->GetNbinsY(), h3simtaggedjetPtJPN3Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPtJPN3Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPtJPN3Flavour->GetNbinsY()));
			hsimtaggedjetNegLogJPN3[flavour][jetPt] = new TH1F(Form("hsimtaggedjetNegLogJPN3_%d_%d", flavour, jetPt), "", h3simtaggedjetPtNegLogJPN3Flavour->GetNbinsY(), h3simtaggedjetPtNegLogJPN3Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPtNegLogJPN3Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPtNegLogJPN3Flavour->GetNbinsY()));
    }
  }
}

void HfJetTaggingJPAnalysis::projectionHistJPQAMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];

		TH1F* projJP = reinterpret_cast<TH1F*> (h3simjetPtJPFlavour->ProjectionY(Form("projJP_%d", flavour), 1, h3simjetPtJPFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPFlavour->ProjectionY(Form("projNegLogJP_%d", flavour), 1, h3simjetPtNegLogJPFlavour->GetNbinsX(), binFlavour, binFlavour));
		hsimjetJP[0][0]->Add(projJP);
		hsimjetJP[flavour][0] = reinterpret_cast<TH1F*>(projJP->Clone(Form("hsimjetJP_%d_0", flavour)));
		hsimjetNegLogJP[0][0]->Add(projNegLogJP);
		hsimjetNegLogJP[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimjetNegLogJP_%d_0", flavour)));

		TH1F* projJPN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPtJPN1Flavour->ProjectionY(Form("projJPN1_%d", flavour), 1, h3simtaggedjetPtJPN1Flavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJPN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPtNegLogJPN1Flavour->ProjectionY(Form("projNegLogJPN1_%d", flavour), 1, h3simtaggedjetPtNegLogJPN1Flavour->GetNbinsX(), binFlavour, binFlavour));
		hsimtaggedjetJPN1[0][0]->Add(projJPN1);
		hsimtaggedjetJPN1[flavour][0] = reinterpret_cast<TH1F*>(projJPN1->Clone(Form("hsimtaggedjetJPN1_%d_0", flavour)));
		hsimtaggedjetNegLogJPN1[0][0]->Add(projNegLogJPN1);
		hsimtaggedjetNegLogJPN1[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone(Form("hsimtaggedjetNegLogJPN1_%d_0", flavour)));

		TH1F* projJPN2 = reinterpret_cast<TH1F*> (h3simtaggedjetPtJPN2Flavour->ProjectionY(Form("projJPN2_%d", flavour), 1, h3simtaggedjetPtJPN2Flavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJPN2 = reinterpret_cast<TH1F*> (h3simtaggedjetPtNegLogJPN2Flavour->ProjectionY(Form("projNegLogJPN2_%d", flavour), 1, h3simtaggedjetPtNegLogJPN2Flavour->GetNbinsX(), binFlavour, binFlavour));
		hsimtaggedjetJPN2[0][0]->Add(projJPN2);
		hsimtaggedjetJPN2[flavour][0] = reinterpret_cast<TH1F*>(projJPN2->Clone(Form("hsimtaggedjetJPN2_%d_0", flavour)));
		hsimtaggedjetNegLogJPN2[0][0]->Add(projNegLogJPN2);
		hsimtaggedjetNegLogJPN2[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone(Form("hsimtaggedjetNegLogJPN2_%d_0", flavour)));

    TH1F* projJPN3 = reinterpret_cast<TH1F*> (h3simtaggedjetPtJPN3Flavour->ProjectionY(Form("projJPN3_%d", flavour), 1, h3simtaggedjetPtJPN3Flavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJPN3 = reinterpret_cast<TH1F*> (h3simtaggedjetPtNegLogJPN3Flavour->ProjectionY(Form("projNegLogJPN3_%d", flavour), 1, h3simtaggedjetPtNegLogJPN3Flavour->GetNbinsX(), binFlavour, binFlavour));
		hsimtaggedjetJPN3[0][0]->Add(projJPN3);
		hsimtaggedjetJPN3[flavour][0] = reinterpret_cast<TH1F*>(projJPN3->Clone(Form("hsimtaggedjetJPN3_%d_0", flavour)));
		hsimtaggedjetNegLogJPN3[0][0]->Add(projNegLogJPN3);
		hsimtaggedjetNegLogJPN3[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone(Form("hsimtaggedjetNegLogJPN3_%d_0", flavour)));

		for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
			int leftbinJetPtJP = h3simjetPtJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJP = h3simjetPtJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJP = reinterpret_cast<TH1F*> (h3simjetPtJPFlavour->ProjectionY(Form("projJetPtRangeJP_%d_%d", binJetPt, flavour), leftbinJetPtJP, rightbinJetPtJP, binFlavour, binFlavour));
			hsimjetJP[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJP->Clone(Form("hsimjetJP_%d_%d", flavour, binJetPt))); 
			hsimjetJP[0][binJetPt]->Add(projJetPtRangeJP);

			int leftbinJetPtNegLogJP = h3simjetPtNegLogJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJP = h3simjetPtNegLogJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPFlavour->ProjectionY(Form("projJetPtRangeNegLogJP_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, binFlavour, binFlavour));
			hsimjetNegLogJP[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hsimjetNegLogJP_%d_%d", flavour, binJetPt))); 
			hsimjetNegLogJP[0][binJetPt]->Add(projJetPtRangeNegLogJP);

			int leftbinJetPtJPN1 = h3simtaggedjetPtJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJPN1 = h3simtaggedjetPtJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJPN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPtJPN1Flavour->ProjectionY(Form("projJetPtRangeJPN1_%d_%d", binJetPt, flavour), leftbinJetPtJPN1, rightbinJetPtJPN1, binFlavour, binFlavour));
			hsimtaggedjetJPN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN1->Clone(Form("hsimtaggedjetJPN1_%d_%d", flavour, binJetPt))); 
			hsimtaggedjetJPN1[0][binJetPt]->Add(projJetPtRangeJPN1);

			int leftbinJetPtNegLogJPN1 = h3simtaggedjetPtNegLogJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJPN1 = h3simtaggedjetPtNegLogJPN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPtNegLogJPN1Flavour->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1, binFlavour, binFlavour));
			hsimtaggedjetNegLogJPN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hsimtaggedjetNegLogJPN1_%d_%d", flavour, binJetPt))); 
			hsimtaggedjetNegLogJPN1[0][binJetPt]->Add(projJetPtRangeNegLogJPN1);

			int leftbinJetPtJPN2 = h3simtaggedjetPtJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJPN2 = h3simtaggedjetPtJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJPN2 = reinterpret_cast<TH1F*> (h3simtaggedjetPtJPN2Flavour->ProjectionY(Form("projJetPtRangeJPN2_%d_%d", binJetPt, flavour), leftbinJetPtJPN2, rightbinJetPtJPN2, binFlavour, binFlavour));
			hsimtaggedjetJPN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN2->Clone(Form("hsimtaggedjetJPN2_%d_%d", flavour, binJetPt))); 
			hsimtaggedjetJPN2[0][binJetPt]->Add(projJetPtRangeJPN2);

			int leftbinJetPtNegLogJPN2 = h3simtaggedjetPtNegLogJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJPN2 = h3simtaggedjetPtNegLogJPN2Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h3simtaggedjetPtNegLogJPN2Flavour->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2, binFlavour, binFlavour));
			hsimtaggedjetNegLogJPN2[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hsimtaggedjetNegLogJPN2_%d_%d", flavour, binJetPt))); 
			hsimtaggedjetNegLogJPN2[0][binJetPt]->Add(projJetPtRangeNegLogJPN2);

			int leftbinJetPtJPN3 = h3simtaggedjetPtJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtJPN3 = h3simtaggedjetPtJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeJPN3 = reinterpret_cast<TH1F*> (h3simtaggedjetPtJPN3Flavour->ProjectionY(Form("projJetPtRangeJPN3_%d_%d", binJetPt, flavour), leftbinJetPtJPN3, rightbinJetPtJPN3, binFlavour, binFlavour));
			hsimtaggedjetJPN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJPN3->Clone(Form("hsimtaggedjetJPN3_%d_%d", flavour, binJetPt))); 
			hsimtaggedjetJPN3[0][binJetPt]->Add(projJetPtRangeJPN3);

			int leftbinJetPtNegLogJPN3 = h3simtaggedjetPtNegLogJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtNegLogJPN3 = h3simtaggedjetPtNegLogJPN3Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h3simtaggedjetPtNegLogJPN3Flavour->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d_%d", binJetPt, binFlavour), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3, binFlavour, binFlavour));
			hsimtaggedjetNegLogJPN3[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hsimtaggedjetNegLogJPN3_%d_%d", flavour, binJetPt))); 
			hsimtaggedjetNegLogJPN3[0][binJetPt]->Add(projJetPtRangeNegLogJPN3);
    }
  }
}

void HfJetTaggingJPAnalysis::initJPMC(TString rootSim) {
  loadSimJPQA(rootSim.Data());
  initHistJPMC();
  projectionHistJPQAMC();
}

void HfJetTaggingJPAnalysis::saveHistogramJPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hsimjetJP[flavour][jetPt]->Write();
      hsimjetNegLogJP[flavour][jetPt]->Write();
      hsimtaggedjetNegLogJPN1[flavour][jetPt]->Write();
      hsimtaggedjetNegLogJPN2[flavour][jetPt]->Write();
      hsimtaggedjetNegLogJPN3[flavour][jetPt]->Write();
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
void HfJetTaggingJPAnalysis::drawDataJP(bool doLog = true, int binJetPt=0) {
  hdatajetNormAreaJP[binJetPt] = (TH1F*) hdatajetJP[binJetPt]->Clone();
  hdatajetNormAreaJP[binJetPt]->Scale(1. / hdatajetNormAreaJP[binJetPt]->Integral());
  hdatajetNormNEventsJP[binJetPt] = (TH1F*) hdatajetJP[binJetPt]->Clone();
  hdatajetNormNEventsJP[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsJP[binJetPt] = (TH1F*) hdatajetJP[binJetPt]->Clone();
  hdatajetNormNJetsJP[binJetPt]->Scale(1. / ndataJets[binJetPt]);
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajetJP[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaJP[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEventsJP[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJetsJP[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProb_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProb_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataNegLogJP(bool doLog = true, int binJetPt=0) {
  hdatajetNormAreaNegLogJP[binJetPt] = (TH1F*) hdatajetNegLogJP[binJetPt]->Clone();
  hdatajetNormAreaNegLogJP[binJetPt]->Scale(1. / hdatajetNormAreaNegLogJP[binJetPt]->Integral());
  hdatajetNormNEventsNegLogJP[binJetPt] = (TH1F*) hdatajetNegLogJP[binJetPt]->Clone();
  hdatajetNormNEventsNegLogJP[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsNegLogJP[binJetPt] = (TH1F*) hdatajetNegLogJP[binJetPt]->Clone();
  hdatajetNormNJetsNegLogJP[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajetNegLogJP[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaNegLogJP[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEventsNegLogJP[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJetsNegLogJP[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLog_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDatataggedjetJPN1(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  hdatataggedjetNormAreaJPN1[binJetPt] = (TH1F*) hdatataggedjetJPN1[binJetPt]->Clone();
  hdatataggedjetNormAreaJPN1[binJetPt]->Scale(1. / hdatataggedjetNormAreaJPN1[binJetPt]->Integral());
  hdatataggedjetNormNEventsJPN1[binJetPt] = (TH1F*) hdatataggedjetJPN1[binJetPt]->Clone();
  hdatataggedjetNormNEventsJPN1[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJetsJPN1[binJetPt] = (TH1F*) hdatataggedjetJPN1[binJetPt]->Clone();
  hdatataggedjetNormNJetsJPN1[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjetJPN1[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormAreaJPN1[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEventsJPN1[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJetsJPN1[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::X_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::X_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN1NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDatataggedjetNegLogJPN1(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  hdatataggedjetNormAreaNegLogJPN1[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN1[binJetPt]->Clone();
  hdatataggedjetNormAreaNegLogJPN1[binJetPt]->Scale(1. / hdatataggedjetNormAreaNegLogJPN1[binJetPt]->Integral());
  hdatataggedjetNormNEventsNegLogJPN1[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN1[binJetPt]->Clone();
  hdatataggedjetNormNEventsNegLogJPN1[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJetsNegLogJPN1[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN1[binJetPt]->Clone();
  hdatataggedjetNormNJetsNegLogJPN1[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjetNegLogJPN1[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormAreaNegLogJPN1[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEventsNegLogJPN1[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJetsNegLogJPN1[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN1NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDatataggedjetJPN2(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  hdatataggedjetNormAreaJPN2[binJetPt] = (TH1F*) hdatataggedjetJPN2[binJetPt]->Clone();
  hdatataggedjetNormAreaJPN2[binJetPt]->Scale(1. / hdatataggedjetNormAreaJPN2[binJetPt]->Integral());
  hdatataggedjetNormNEventsJPN2[binJetPt] = (TH1F*) hdatataggedjetJPN2[binJetPt]->Clone();
  hdatataggedjetNormNEventsJPN2[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJetsJPN2[binJetPt] = (TH1F*) hdatataggedjetJPN2[binJetPt]->Clone();
  hdatataggedjetNormNJetsJPN2[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjetJPN2[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormAreaJPN2[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEventsJPN2[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJetsJPN2[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN2_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN2NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingJPAnalysis::drawDatataggedjetNegLogJPN2(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  hdatataggedjetNormAreaNegLogJPN2[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN2[binJetPt]->Clone();
  hdatataggedjetNormAreaNegLogJPN2[binJetPt]->Scale(1. / hdatataggedjetNormAreaNegLogJPN2[binJetPt]->Integral());
  hdatataggedjetNormNEventsNegLogJPN2[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN2[binJetPt]->Clone();
  hdatataggedjetNormNEventsNegLogJPN2[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJetsNegLogJPN2[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN2[binJetPt]->Clone();
  hdatataggedjetNormNJetsNegLogJPN2[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjetNegLogJPN2[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormAreaNegLogJPN2[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEventsNegLogJPN2[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJetsNegLogJPN2[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN2_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN2NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDatataggedjetJPN3(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  hdatataggedjetNormAreaJPN3[binJetPt] = (TH1F*) hdatataggedjetJPN3[binJetPt]->Clone();
  hdatataggedjetNormAreaJPN3[binJetPt]->Scale(1. / hdatataggedjetNormAreaJPN3[binJetPt]->Integral());
  hdatataggedjetNormNEventsJPN3[binJetPt] = (TH1F*) hdatataggedjetJPN3[binJetPt]->Clone();
  hdatataggedjetNormNEventsJPN3[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJetsJPN3[binJetPt] = (TH1F*) hdatataggedjetJPN3[binJetPt]->Clone();
  hdatataggedjetNormNJetsJPN3[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjetJPN3[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormAreaJPN3[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEventsJPN3[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJetsJPN3[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN3_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN3NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDatataggedjetNegLogJPN3(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  hdatataggedjetNormAreaNegLogJPN3[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN3[binJetPt]->Clone();
  hdatataggedjetNormAreaNegLogJPN3[binJetPt]->Scale(1. / hdatataggedjetNormAreaNegLogJPN3[binJetPt]->Integral());
  hdatataggedjetNormNEventsNegLogJPN3[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN3[binJetPt]->Clone();
  hdatataggedjetNormNEventsNegLogJPN3[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJetsNegLogJPN3[binJetPt] = (TH1F*) hdatataggedjetNegLogJPN3[binJetPt]->Clone();
  hdatataggedjetNormNJetsNegLogJPN3[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjetNegLogJPN3[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormAreaNegLogJPN3[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEventsNegLogJPN3[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJetsNegLogJPN3[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN3_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN3NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataNegLogJPN4x1(bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> histList;
  histList.push_back({hdatajetNegLogJP[binJetPt], ""});

  std::vector<HistogramData> histListN1;
  histListN1.push_back({hdatataggedjetNegLogJPN1[binJetPt], ""});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hdatataggedjetNegLogJPN2[binJetPt], ""});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hdatataggedjetNegLogJPN3[binJetPt], ""});

  canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.15);

  //canHan->drawPadMxNCombined(nc, 0, 0, histList, true, doLog, true, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", HfJetTagging::Y_AXIS_JP);
  canHan->drawPadMxNCombined(nc, 0, 0, histList, true, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", HfJetTagging::Y_AXIS_NEG_JP);
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
  latexSimJetInfoForJP(0.43, 0.94, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  //latexSimJetInfo(0.40, 0.94, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  latex.DrawLatex(0.74, 0.92, "#scale[1.8]{untagged jet}");

  canHan->drawPadMxNCombined(nc, 1, 0, histListN1, true, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", "");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
  latex.DrawLatex(0.08, 0.92, Form("#scale[1.8]{S#it{d}_{#it{XY}} > %0.1f}", cutImp));
  latex.DrawLatex(0.38, 0.92, Form("#scale[1.8]{1^{st} largest %s^{track} tagged jet}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 2, 0, histListN2, true, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", "");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
  latex.DrawLatex(0.37, 0.92, Form("#scale[1.8]{2^{nd} largest %s^{track} tagged jet}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  canHan->drawPadMxNCombined(nc, 3, 0, histListN3, true, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], HfJetTagging::X_AXIS_JP, "");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
  latex.DrawLatex(0.35, 0.92, Form("#scale[1.8]{3^{rd} largest %s^{track} tagged jet}", HfJetTagging::X_AXIS_IMPXY[3].Data()));

  gROOT->ProcessLine(Form("cc%d->Update();", nc));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN4x1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}



void HfJetTaggingJPAnalysis::drawSimTrackProb(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;

}


void HfJetTaggingJPAnalysis::drawSimJP(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaJP[flavour][binJetPt] = (TH1F*) hsimjetJP[flavour][binJetPt]->Clone();
    hsimjetNormAreaJP[flavour][binJetPt]->Scale(1. / hsimjetNormAreaJP[flavour][binJetPt]->Integral());
    hsimjetNormNEventsJP[flavour][binJetPt] = (TH1F*) hsimjetJP[flavour][binJetPt]->Clone();
    hsimjetNormNEventsJP[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsJP[flavour][binJetPt] = (TH1F*) hsimjetJP[flavour][binJetPt]->Clone();
    hsimjetNormNJetsJP[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetJP[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetJP[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetJP[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaJP[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaJP[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaJP[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsJP[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsJP[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsJP[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsJP[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsJP[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsJP[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsJP[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProb_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimNegLogJP(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaNegLogJP[flavour][binJetPt] = (TH1F*) hsimjetNegLogJP[flavour][binJetPt]->Clone();
    hsimjetNormAreaNegLogJP[flavour][binJetPt]->Scale(1. / hsimjetNormAreaNegLogJP[flavour][binJetPt]->Integral());
    hsimjetNormNEventsNegLogJP[flavour][binJetPt] = (TH1F*) hsimjetNegLogJP[flavour][binJetPt]->Clone();
    hsimjetNormNEventsNegLogJP[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsNegLogJP[flavour][binJetPt] = (TH1F*) hsimjetNegLogJP[flavour][binJetPt]->Clone();
    hsimjetNormNJetsNegLogJP[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetNegLogJP[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetNegLogJP[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaNegLogJP[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaNegLogJP[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsNegLogJP[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsNegLogJP[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsNegLogJP[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsNegLogJP[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLog_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimtaggedjetJPN1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormAreaJPN1[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormAreaJPN1[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormAreaJPN1[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEventsJPN1[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEventsJPN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJetsJPN1[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJetsJPN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjetJPN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjetJPN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjetJPN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjetJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormAreaJPN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJetsJPN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimtaggedjetNegLogJPN1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormAreaNegLogJPN1[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormAreaNegLogJPN1[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormAreaNegLogJPN1[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEventsNegLogJPN1[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEventsNegLogJPN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJetsNegLogJPN1[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJetsNegLogJPN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjetNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingJPAnalysis::drawSimtaggedjetJPN2(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormAreaJPN2[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN2[flavour][binJetPt]->Clone();
    hsimtaggedjetNormAreaJPN2[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormAreaJPN2[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEventsJPN2[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN2[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEventsJPN2[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJetsJPN2[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN2[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJetsJPN2[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjetJPN2[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjetJPN2[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjetJPN2[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjetJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormAreaJPN2[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN2[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN2[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN2[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN2[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN2[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJetsJPN2[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN2[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN2[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN2NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimtaggedjetNegLogJPN2(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormAreaNegLogJPN2[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN2[flavour][binJetPt]->Clone();
    hsimtaggedjetNormAreaNegLogJPN2[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormAreaNegLogJPN2[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEventsNegLogJPN2[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN2[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEventsNegLogJPN2[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJetsNegLogJPN2[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN2[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJetsNegLogJPN2[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjetNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_NEG_JP, HfJetTagging::Y_AXIS_NEG_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN2NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimtaggedjetJPN3(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormAreaJPN3[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN3[flavour][binJetPt]->Clone();
    hsimtaggedjetNormAreaJPN3[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormAreaJPN3[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEventsJPN3[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN3[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEventsJPN3[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJetsJPN3[flavour][binJetPt] = (TH1F*) hsimtaggedjetJPN3[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJetsJPN3[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjetJPN3[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjetJPN3[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjetJPN3[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjetJPN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormAreaJPN3[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN3[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN3[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormAreaJPN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN3[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN3[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN3[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsJPN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJetsJPN3[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN3[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN3[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJetsJPN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbN3NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimtaggedjetNegLogJPN3(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormAreaNegLogJPN3[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN3[flavour][binJetPt]->Clone();
    hsimtaggedjetNormAreaNegLogJPN3[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormAreaNegLogJPN3[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEventsNegLogJPN3[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN3[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEventsNegLogJPN3[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJetsNegLogJPN3[flavour][binJetPt] = (TH1F*) hsimtaggedjetNegLogJPN3[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJetsNegLogJPN3[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjetNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjetNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormAreaNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEventsNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJetsNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN3_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], HfJetTagging::X_AXIS_JP, HfJetTagging::Y_AXIS_JP);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetProbNegLogN3NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimNegLogJPN4x1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimjetNegLogJP[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimjetNegLogJP[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimjetNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN1;
  histListN1.push_back({hsimtaggedjetNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  histListN1.push_back({hsimtaggedjetNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  histListN1.push_back({hsimtaggedjetNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  histListN1.push_back({hsimtaggedjetNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN2;
  histListN2.push_back({hsimtaggedjetNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  histListN2.push_back({hsimtaggedjetNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  histListN2.push_back({hsimtaggedjetNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  histListN2.push_back({hsimtaggedjetNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListN3;
  histListN3.push_back({hsimtaggedjetNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  histListN3.push_back({hsimtaggedjetNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  histListN3.push_back({hsimtaggedjetNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  histListN3.push_back({hsimtaggedjetNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.15);

  //canHan->drawPadMxNCombined(nc, 0, 0, histList, withInc, doLog, true, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", HfJetTagging::Y_AXIS_JP);
  canHan->drawPadMxNCombined(nc, 0, 0, histList, withInc, doLog, false, HfJetTagging::REFHIST::RAWLOGJP[0], HfJetTagging::REFHIST::RAWLOGJP[1], HfJetTagging::REFHIST::RAWLOGJP[2], HfJetTagging::REFHIST::RAWLOGJP[3], "", HfJetTagging::Y_AXIS_NEG_JP);
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

void HfJetTaggingJPAnalysis::drawSimJPRef() {
	std::vector<HistogramData> normHist;

  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //float refTagger = this->getLifeTimeRefTagger(hsimjetNegLogJP[flavour][binJetPt], hsimjetPt[flavour], binJetPt);
      float refTagger = this->getLifeTimeRefTagger(hsimjetNegLogJP[flavour][binJetPt], hsimjetJP[flavour][binJetPt], binJetPt);
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

void HfJetTaggingJPAnalysis::drawSimJPEffiN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN1 = taggingutilities::getEfficiency(hsimtaggedjetNegLogJPN1[flavour][binJetPt], hsimjetNegLogJP[flavour][binJetPt]);
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

void HfJetTaggingJPAnalysis::drawSimJPEffiN2(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt

      float effiN2 = taggingutilities::getEfficiency(hsimtaggedjetNegLogJPN2[flavour][binJetPt], hsimjetNegLogJP[flavour][binJetPt]);
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

void HfJetTaggingJPAnalysis::drawSimJPEffiN3(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt

      float effiN3 = taggingutilities::getEfficiency(hsimtaggedjetNegLogJPN3[flavour][binJetPt],hsimjetNegLogJP[flavour][binJetPt]);
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

void HfJetTaggingJPAnalysis::drawSimJPEffiNx(float cutImp) {
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

void HfJetTaggingJPAnalysis::drawSimJPPurityN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN1 = taggingutilities::getPurity(hsimtaggedjetNegLogJPN1[flavour][binJetPt],hsimtaggedjetNegLogJPN1[0][binJetPt]);
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

void HfJetTaggingJPAnalysis::drawSimJPPurityN2(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN2 = taggingutilities::getPurity(hsimtaggedjetNegLogJPN2[flavour][binJetPt],hsimtaggedjetNegLogJPN2[0][binJetPt]);
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

void HfJetTaggingJPAnalysis::drawSimJPPurityN3(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN3 = taggingutilities::getPurity(hsimtaggedjetNegLogJPN3[flavour][binJetPt],hsimtaggedjetNegLogJPN3[0][binJetPt]);
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

void HfJetTaggingJPAnalysis::drawSimJPPurityNx(float cutImp) {
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

//void HfJetTaggingJPAnalysis::drawTemplateFit() {
//  RooRealVar jetProb("jetProb", "-ln(JP)", 0, 20);
//  const int rebinFactor = 20;
//  double newBins[rebinFactor+1] = {0};
//  for (int i = 0; i <= rebinFactor; ++i) {
//    newBins[i] = i;
//  }
//  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
//    if (binJetPt==1) continue;
//    //if (binJetPt>1) continue;
//    TH1F* hsimincjetNegLogJPRebin = (TH1F*) hsimjetNegLogJP[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJP", newBins);
//    TH1F* hsimcjetNegLogJPRebin = (TH1F*) hsimjetNegLogJP[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJP", newBins);
//    TH1F* hsimbjetNegLogJPRebin = (TH1F*) hsimjetNegLogJP[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJP", newBins);
//    TH1F* hsimlfjetNegLogJPRebin = (TH1F*) hsimjetNegLogJP[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJP", newBins);
//    TH1F* hdatajetNegLogJPRebin = (TH1F*) hdatajetNegLogJP[0][binJetPt]->Rebin(rebinFactor, "hdatajetNegLogJP", newBins);
//    TH1F* hsimincjetNegLogJPN1Rebin = (TH1F*) hsimtaggedjetNegLogJPN1[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJPN1", newBins);
//    TH1F* hsimcjetNegLogJPN1Rebin = (TH1F*) hsimtaggedjetNegLogJPN1[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJPN1", newBins);
//    TH1F* hsimbjetNegLogJPN1Rebin = (TH1F*) hsimtaggedjetNegLogJPN1[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJPN1", newBins);
//    TH1F* hsimlfjetNegLogJPN1Rebin = (TH1F*) hsimtaggedjetNegLogJPN1[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJPN1", newBins);
//    TH1F* hdatataggedjetNegLogJPN1Rebin = (TH1F*) hdatataggedjetNegLogJPN1[0][binJetPt]->Rebin(rebinFactor, "hdatataggedjetNegLogJPN1", newBins);
//    TH1F* hsimincjetNegLogJPN2Rebin = (TH1F*) hsimtaggedjetNegLogJPN2[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJPN2", newBins);
//    TH1F* hsimcjetNegLogJPN2Rebin = (TH1F*) hsimtaggedjetNegLogJPN2[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJPN2", newBins);
//    TH1F* hsimbjetNegLogJPN2Rebin = (TH1F*) hsimtaggedjetNegLogJPN2[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJPN2", newBins);
//    TH1F* hsimlfjetNegLogJPN2Rebin = (TH1F*) hsimtaggedjetNegLogJPN2[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJPN2", newBins);
//    TH1F* hdatataggedjetNegLogJPN2Rebin = (TH1F*) hdatataggedjetNegLogJPN2[0][binJetPt]->Rebin(rebinFactor, "hdatataggedjetNegLogJPN2", newBins);
//    TH1F* hsimincjetNegLogJPN3Rebin = (TH1F*) hsimtaggedjetNegLogJPN3[0][binJetPt]->Rebin(rebinFactor, "hsimincjetNegLogJPN3", newBins);
//    TH1F* hsimcjetNegLogJPN3Rebin = (TH1F*) hsimtaggedjetNegLogJPN3[1][binJetPt]->Rebin(rebinFactor, "hsimcjetNegLogJPN3", newBins);
//    TH1F* hsimbjetNegLogJPN3Rebin = (TH1F*) hsimtaggedjetNegLogJPN3[2][binJetPt]->Rebin(rebinFactor, "hsimbjetNegLogJPN3", newBins);
//    TH1F* hsimlfjetNegLogJPN3Rebin = (TH1F*) hsimtaggedjetNegLogJPN3[3][binJetPt]->Rebin(rebinFactor, "hsimlfjetNegLogJPN3", newBins);
//    TH1F* hdatataggedjetNegLogJPN3Rebin = (TH1F*) hdatataggedjetNegLogJPN3[0][binJetPt]->Rebin(rebinFactor, "hdatataggedjetNegLogJPN3", newBins);
//
////    TH1F* hsimincjetNegLogJP = (TH1F*) hsimjetNegLogJP[0][binJetPt]->Clone();
////    TH1F* hsimcjetNegLogJP = (TH1F*) hsimjetNegLogJP[1][binJetPt]->Clone();
////    TH1F* hsimbjetNegLogJP = (TH1F*) hsimjetNegLogJP[2][binJetPt]->Clone();
////    TH1F* hsimlfjetNegLogJP = (TH1F*) hsimjetNegLogJP[3][binJetPt]->Clone();
////    TH1F* hdatajetNegLogJP = (TH1F*) hdatajetNegLogJP[0][binJetPt]->Clone();
////    TH1F* hsimincjetNegLogJPN1 = (TH1F*) hsimtaggedjetNegLogJPN1[0][binJetPt]->Clone();
////    TH1F* hsimcjetNegLogJPN1 = (TH1F*) hsimtaggedjetNegLogJPN1[1][binJetPt]->Clone();
////    TH1F* hsimbjetNegLogJPN1 = (TH1F*) hsimtaggedjetNegLogJPN1[2][binJetPt]->Clone();
////    TH1F* hsimlfjetNegLogJPN1 = (TH1F*) hsimtaggedjetNegLogJPN1[3][binJetPt]->Clone();
////    TH1F* hdatataggedjetNegLogJPN1 = (TH1F*) hdatataggedjetNegLogJPN1[0][binJetPt]->Clone();
////    TH1F* hsimincjetNegLogJPN2 = (TH1F*) hsimtaggedjetNegLogJPN2[0][binJetPt]->Clone();
////    TH1F* hsimcjetNegLogJPN2 = (TH1F*) hsimtaggedjetNegLogJPN2[1][binJetPt]->Clone();
////    TH1F* hsimbjetNegLogJPN2 = (TH1F*) hsimtaggedjetNegLogJPN2[2][binJetPt]->Clone();
////    TH1F* hsimlfjetNegLogJPN2 = (TH1F*) hsimtaggedjetNegLogJPN2[3][binJetPt]->Clone();
////    TH1F* hdatataggedjetNegLogJPN2 = (TH1F*) hdatataggedjetNegLogJPN2[0][binJetPt]->Clone();
////    TH1F* hsimincjetNegLogJPN3 = (TH1F*) hsimtaggedjetNegLogJPN3[0][binJetPt]->Clone();
////    TH1F* hsimcjetNegLogJPN3 = (TH1F*) hsimtaggedjetNegLogJPN3[1][binJetPt]->Clone();
////    TH1F* hsimbjetNegLogJPN3 = (TH1F*) hsimtaggedjetNegLogJPN3[2][binJetPt]->Clone();
////    TH1F* hsimlfjetNegLogJPN3 = (TH1F*) hsimtaggedjetNegLogJPN3[3][binJetPt]->Clone();
////    TH1F* hdatataggedjetNegLogJPN3 = (TH1F*) hdatataggedjetNegLogJPN3[0][binJetPt]->Clone();
//
//
//    std::cout << "Debug" <<std::endl;
//    std::cout << "data yield: " << hdatajetNegLogJP[0][binJetPt]->Integral("width") << std::endl;
//    std::cout << "data yield (N1): " << hdatataggedjetNegLogJPN1[0][binJetPt]->Integral("width") << std::endl;
//    std::cout << "data yield (N2): " << hdatataggedjetNegLogJPN2[0][binJetPt]->Integral("width") << std::endl;
//    std::cout << "data yield (N3): " << hdatataggedjetNegLogJPN3[0][binJetPt]->Integral("width") << std::endl;
//    
//
//    RooDataHist mcincjetNegLogJP("mcincjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPRebin)); 
//    RooDataHist mccjetNegLogJP("mccjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPRebin));
//    RooDataHist mcbjetNegLogJP("mcbjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPRebin));
//    RooDataHist mclfjetNegLogJP("mclfjetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPRebin));
//    RooDataHist mccjetNegLogJPForData("mccjetNegLogJPForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPRebin));
//    RooDataHist mcbjetNegLogJPForData("mcbjetNegLogJPForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPRebin));
//    RooDataHist mclfjetNegLogJPForData("mclfjetNegLogJPForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPRebin));
//    RooDataHist datajetNegLogJP("datajetNegLogJP", "Data Hist", jetProb, RooFit::Import(*hdatajetNegLogJPRebin)); 
//
//    RooDataHist mcincjetNegLogJPN1("mcincjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPN1Rebin)); 
//    RooDataHist mccjetNegLogJPN1("mccjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN1Rebin));
//    RooDataHist mcbjetNegLogJPN1("mcbjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN1Rebin));
//    RooDataHist mclfjetNegLogJPN1("mclfjetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN1Rebin));
//    RooDataHist mccjetNegLogJPN1ForData("mccjetNegLogJPN1ForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN1Rebin));
//    RooDataHist mcbjetNegLogJPN1ForData("mcbjetNegLogJPN1ForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN1Rebin));
//    RooDataHist mclfjetNegLogJPN1ForData("mclfjetNegLogJPN1ForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN1Rebin));
//    RooDataHist datajetNegLogJPN1("datajetNegLogJPN1", "Data Hist", jetProb, RooFit::Import(*hdatataggedjetNegLogJPN1Rebin)); 
//
//    RooDataHist mcincjetNegLogJPN2("mcincjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPN2Rebin)); 
//    RooDataHist mccjetNegLogJPN2("mccjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN2Rebin));
//    RooDataHist mcbjetNegLogJPN2("mcbjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN2Rebin));
//    RooDataHist mclfjetNegLogJPN2("mclfjetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN2Rebin));
//    RooDataHist mccjetNegLogJPN2ForData("mccjetNegLogJPN2ForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN2Rebin));
//    RooDataHist mcbjetNegLogJPN2ForData("mcbjetNegLogJPN2ForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN2Rebin));
//    RooDataHist mclfjetNegLogJPN2ForData("mclfjetNegLogJPN2ForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN2Rebin));
//    RooDataHist datajetNegLogJPN2("datajetNegLogJPN2", "Data Hist", jetProb, RooFit::Import(*hdatataggedjetNegLogJPN2Rebin)); 
//
//    if (mccjetNegLogJPN2ForData.numEntries() == 0) {
//      std::cerr << "Error: Histogram has zero entries." << std::endl;
//    }
//
//
//    RooDataHist mcincjetNegLogJPN3("mcincjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimincjetNegLogJPN3Rebin)); 
//    RooDataHist mccjetNegLogJPN3("mccjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN3Rebin));
//    RooDataHist mcbjetNegLogJPN3("mcbjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN3Rebin));
//    RooDataHist mclfjetNegLogJPN3("mclfjetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN3Rebin));
//    RooDataHist mccjetNegLogJPN3ForData("mccjetNegLogJPN3ForData", "Data Hist", jetProb, RooFit::Import(*hsimcjetNegLogJPN3Rebin));
//    RooDataHist mcbjetNegLogJPN3ForData("mcbjetNegLogJPN3ForData", "Data Hist", jetProb, RooFit::Import(*hsimbjetNegLogJPN3Rebin));
//    RooDataHist mclfjetNegLogJPN3ForData("mclfjetNegLogJPN3ForData", "Data Hist", jetProb, RooFit::Import(*hsimlfjetNegLogJPN3Rebin));
//    RooDataHist datajetNegLogJPN3("datajetNegLogJPN3", "Data Hist", jetProb, RooFit::Import(*hdatataggedjetNegLogJPN3Rebin)); 
//
//    // Create a histogram PDF using the data histogram
//    RooHistPdf histPdfcjetNegLogJP("histPdfcjetNegLogJP", "Histogram PDF", jetProb, mccjetNegLogJP);
//    RooHistPdf histPdfbjetNegLogJP("histPdfbjetNegLogJP", "Histogram PDF", jetProb, mcbjetNegLogJP);
//    RooHistPdf histPdflfjetNegLogJP("histPdflfjetNegLogJP", "Histogram PDF", jetProb, mclfjetNegLogJP);
//    RooHistPdf histPdfcjetNegLogJPForData("histPdfcjetNegLogJPForData", "Histogram PDF", jetProb, mccjetNegLogJPForData);
//    RooHistPdf histPdfbjetNegLogJPForData("histPdfbjetNegLogJPForData", "Histogram PDF", jetProb, mcbjetNegLogJPForData);
//    RooHistPdf histPdflfjetNegLogJPForData("histPdflfjetNegLogJPForData", "Histogram PDF", jetProb, mclfjetNegLogJPForData);
//
//    RooHistPdf histPdfcjetNegLogJPN1("histPdfcjetNegLogJPN1", "Histogram PDF", jetProb, mccjetNegLogJPN1);
//    RooHistPdf histPdfbjetNegLogJPN1("histPdfbjetNegLogJPN1", "Histogram PDF", jetProb, mcbjetNegLogJPN1);
//    RooHistPdf histPdflfjetNegLogJPN1("histPdflfjetNegLogJPN1", "Histogram PDF", jetProb, mclfjetNegLogJPN1);
//    RooHistPdf histPdfcjetNegLogJPN1ForData("histPdfcjetNegLogJPN1ForData", "Histogram PDF", jetProb, mccjetNegLogJPN1ForData);
//    RooHistPdf histPdfbjetNegLogJPN1ForData("histPdfbjetNegLogJPN1ForData", "Histogram PDF", jetProb, mcbjetNegLogJPN1ForData);
//    RooHistPdf histPdflfjetNegLogJPN1ForData("histPdflfjetNegLogJPN1ForData", "Histogram PDF", jetProb, mclfjetNegLogJPN1ForData);
//
//    RooHistPdf histPdfcjetNegLogJPN2("histPdfcjetNegLogJPN2", "Histogram PDF", jetProb, mccjetNegLogJPN2);
//    RooHistPdf histPdfbjetNegLogJPN2("histPdfbjetNegLogJPN2", "Histogram PDF", jetProb, mcbjetNegLogJPN2);
//    RooHistPdf histPdflfjetNegLogJPN2("histPdflfjetNegLogJPN2", "Histogram PDF", jetProb, mclfjetNegLogJPN2);
//    RooHistPdf histPdfcjetNegLogJPN2ForData("histPdfcjetNegLogJPN2ForData", "Histogram PDF", jetProb, mccjetNegLogJPN2ForData);
//    if (histPdfcjetNegLogJPN2ForData.getVal() == 0) {
//      std::cerr << "Error: PDF evaluates to zero." << std::endl;
//    }
//    RooHistPdf histPdfbjetNegLogJPN2ForData("histPdfbjetNegLogJPN2ForData", "Histogram PDF", jetProb, mcbjetNegLogJPN2ForData);
//    RooHistPdf histPdflfjetNegLogJPN2ForData("histPdflfjetNegLogJPN2ForData", "Histogram PDF", jetProb, mclfjetNegLogJPN2ForData);
//
//    RooHistPdf histPdfcjetNegLogJPN3("histPdfcjetNegLogJPN3", "Histogram PDF", jetProb, mccjetNegLogJPN3);
//    RooHistPdf histPdfbjetNegLogJPN3("histPdfbjetNegLogJPN3", "Histogram PDF", jetProb, mcbjetNegLogJPN3);
//    RooHistPdf histPdflfjetNegLogJPN3("histPdflfjetNegLogJPN3", "Histogram PDF", jetProb, mclfjetNegLogJPN3);
//    RooHistPdf histPdfcjetNegLogJPN3ForData("histPdfcjetNegLogJPN3ForData", "Histogram PDF", jetProb, mccjetNegLogJPN3ForData);
//    RooHistPdf histPdfbjetNegLogJPN3ForData("histPdfbjetNegLogJPN3ForData", "Histogram PDF", jetProb, mcbjetNegLogJPN3ForData);
//    RooHistPdf histPdflfjetNegLogJPN3ForData("histPdflfjetNegLogJPN3ForData", "Histogram PDF", jetProb, mclfjetNegLogJPN3ForData);
//
//    // Define relative normalization factors 
//    int incjetNegLogJPYield = mccjetNegLogJP.sumEntries()+mcbjetNegLogJP.sumEntries()+mclfjetNegLogJP.sumEntries();
//    int incjetNegLogJPN1Yield = mccjetNegLogJPN1.sumEntries()+mcbjetNegLogJPN1.sumEntries()+mclfjetNegLogJPN1.sumEntries();
//    int incjetNegLogJPN2Yield = mccjetNegLogJPN2.sumEntries()+mcbjetNegLogJPN2.sumEntries()+mclfjetNegLogJPN2.sumEntries();
//    int incjetNegLogJPN3Yield = mccjetNegLogJPN3.sumEntries()+mcbjetNegLogJPN3.sumEntries()+mclfjetNegLogJPN3.sumEntries();
//    RooRealVar cjetNegLogJPYield("cjetNegLogJPYield", "cjet Yield", hsimjetNegLogJP[1][0]->Integral(1, hsimjetNegLogJP[1][0]->GetNbinsX()), 0, incjetNegLogJPYield);
//    RooRealVar bjetNegLogJPYield("bjetNegLogJPYield", "bjet Yield", hsimjetNegLogJP[2][0]->Integral(1, hsimjetNegLogJP[2][0]->GetNbinsX()), 0, incjetNegLogJPYield);
//    RooRealVar lfjetNegLogJPYield("lfjetNegLogJPYield", "lfjet Yield", hsimjetNegLogJP[3][0]->Integral(1, hsimjetNegLogJP[3][0]->GetNbinsX()), 0, incjetNegLogJPYield);
//    RooRealVar cjetNegLogJPN1Yield("cjetNegLogJPN1Yield", "cjet Yield", hsimtaggedjetNegLogJPN1[1][0]->Integral(1, hsimtaggedjetNegLogJPN1[1][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
//    RooRealVar bjetNegLogJPN1Yield("bjetNegLogJPN1Yield", "bjet Yield", hsimtaggedjetNegLogJPN1[2][0]->Integral(1, hsimtaggedjetNegLogJPN1[2][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
//    RooRealVar lfjetNegLogJPN1Yield("lfjetNegLogJPN1Yield", "lfjet Yield", hsimtaggedjetNegLogJPN1[3][0]->Integral(1, hsimtaggedjetNegLogJPN1[3][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
//    RooRealVar cjetNegLogJPN2Yield("cjetNegLogJPN2Yield", "cjet Yield", hsimtaggedjetNegLogJPN2[1][0]->Integral(1, hsimtaggedjetNegLogJPN2[1][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
//    RooRealVar bjetNegLogJPN2Yield("bjetNegLogJPN2Yield", "bjet Yield", hsimtaggedjetNegLogJPN2[2][0]->Integral(1, hsimtaggedjetNegLogJPN2[2][0]->GetNbinsX()), 0, incjetNegLogJPN1Yield);
//    RooRealVar lfjetNegLogJPN2Yield("lfjetNegLogJPN2Yield", "lfjet Yield", hsimtaggedjetNegLogJPN2[3][0]->Integral(1, hsimtaggedjetNegLogJPN2[3][0]->GetNbinsX()), 0, incjetNegLogJPN2Yield);
//    RooRealVar cjetNegLogJPN3Yield("cjetNegLogJPN3Yield", "cjet Yield", hsimtaggedjetNegLogJPN3[1][0]->Integral(1, hsimtaggedjetNegLogJPN3[1][0]->GetNbinsX()), 0, incjetNegLogJPN3Yield);
//    RooRealVar bjetNegLogJPN3Yield("bjetNegLogJPN3Yield", "bjet Yield", hsimtaggedjetNegLogJPN3[2][0]->Integral(1, hsimtaggedjetNegLogJPN3[2][0]->GetNbinsX()), 0, incjetNegLogJPN3Yield);
//    RooRealVar lfjetNegLogJPN3Yield("lfjetNegLogJPN3Yield", "lfjet Yield", hsimtaggedjetNegLogJPN3[3][0]->Integral(1, hsimtaggedjetNegLogJPN3[3][0]->GetNbinsX()), 0, incjetNegLogJPN3Yield);
//
//    int incjetNegLogJPYieldForData = hdatajetNegLogJPRebin->Integral("width");
//    int incjetNegLogJPN1YieldForData = hdatataggedjetNegLogJPN1Rebin->Integral("width");
//    int incjetNegLogJPN2YieldForData = hdatataggedjetNegLogJPN2Rebin->Integral("width");
//    int incjetNegLogJPN3YieldForData = hdatataggedjetNegLogJPN3Rebin->Integral("width");
//    RooRealVar cjetNegLogJPYieldForData("cjetNegLogJPYieldForData", "cjet Yield", hsimjetNegLogJP[1][0]->Integral(1, hsimjetNegLogJP[1][0]->GetNbinsX() / incjetNegLogJPYield * incjetNegLogJPYield), 0.01*incjetNegLogJPYieldForData, incjetNegLogJPYieldForData);
//    RooRealVar bjetNegLogJPYieldForData("bjetNegLogJPYieldForData", "bjet Yield", 100*hsimjetNegLogJP[2][0]->Integral(1, hsimjetNegLogJP[2][0]->GetNbinsX() / incjetNegLogJPYield * incjetNegLogJPYield), 0.01*incjetNegLogJPYieldForData, incjetNegLogJPYieldForData);
//    RooRealVar lfjetNegLogJPYieldForData("lfjetNegLogJPYieldForData", "lfjet Yield", hsimjetNegLogJP[3][0]->Integral(1, hsimjetNegLogJP[3][0]->GetNbinsX() / incjetNegLogJPYield * incjetNegLogJPYieldForData), 0.01*incjetNegLogJPYieldForData, incjetNegLogJPYieldForData);
//
////    RooRealVar cjetNegLogJPN1YieldForData("cjetNegLogJPN1YieldForData", "cjet Yield", hsimtaggedjetNegLogJPN1[1][0]->Integral(1, hsimtaggedjetNegLogJPN1[1][0]->GetNbinsX()), 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
////    RooRealVar bjetNegLogJPN1YieldForData("bjetNegLogJPN1YieldForData", "bjet Yield", hsimtaggedjetNegLogJPN1[2][0]->Integral(1, hsimtaggedjetNegLogJPN1[2][0]->GetNbinsX()), 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
////    RooRealVar lfjetNegLogJPN1YieldForData("lfjetNegLogJPN1YieldForData", "lfjet Yield", hsimtaggedjetNegLogJPN1[3][0]->Integral(1, hsimtaggedjetNegLogJPN1[3][0]->GetNbinsX()), 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
//    RooRealVar cjetNegLogJPN1YieldForData("cjetNegLogJPN1YieldForData", "cjet Yield", hsimtaggedjetNegLogJPN1[1][0]->Integral(1, hsimtaggedjetNegLogJPN1[1][0]->GetNbinsX()) / incjetNegLogJPN1Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
//    RooRealVar bjetNegLogJPN1YieldForData("bjetNegLogJPN1YieldForData", "bjet Yield", hsimtaggedjetNegLogJPN1[2][0]->Integral(1, hsimtaggedjetNegLogJPN1[2][0]->GetNbinsX()) / incjetNegLogJPN1Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
//    RooRealVar lfjetNegLogJPN1YieldForData("lfjetNegLogJPN1YieldForData", "lfjet Yield", hsimtaggedjetNegLogJPN1[3][0]->Integral(1, hsimtaggedjetNegLogJPN1[3][0]->GetNbinsX()) / incjetNegLogJPN1Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN1YieldForData, incjetNegLogJPN1YieldForData);
//
//    RooRealVar cjetNegLogJPN2YieldForData("cjetNegLogJPN2YieldForData", "cjet Yield", hsimtaggedjetNegLogJPN2[1][0]->Integral(1, hsimtaggedjetNegLogJPN2[1][0]->GetNbinsX()) / incjetNegLogJPN2Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN2YieldForData, incjetNegLogJPN2YieldForData);
//    RooRealVar bjetNegLogJPN2YieldForData("bjetNegLogJPN2YieldForData", "bjet Yield", hsimtaggedjetNegLogJPN2[2][0]->Integral(1, hsimtaggedjetNegLogJPN2[2][0]->GetNbinsX()) / incjetNegLogJPN2Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN2YieldForData, incjetNegLogJPN2YieldForData);
//    RooRealVar lfjetNegLogJPN2YieldForData("lfjetNegLogJPN2YieldForData", "lfjet Yield", hsimtaggedjetNegLogJPN2[3][0]->Integral(1, hsimtaggedjetNegLogJPN2[3][0]->GetNbinsX()) / incjetNegLogJPN2Yield * incjetNegLogJPN2YieldForData, 0.01*incjetNegLogJPN2YieldForData, incjetNegLogJPN2YieldForData);
//
//    RooRealVar cjetNegLogJPN3YieldForData("cjetNegLogJPN3YieldForData", "cjet Yield", hsimtaggedjetNegLogJPN3[1][0]->Integral(1, hsimtaggedjetNegLogJPN3[1][0]->GetNbinsX()) / incjetNegLogJPN3Yield * incjetNegLogJPN3YieldForData, 0.01*incjetNegLogJPN3YieldForData, incjetNegLogJPN3YieldForData);
//    RooRealVar bjetNegLogJPN3YieldForData("bjetNegLogJPN3YieldForData", "bjet Yield", hsimtaggedjetNegLogJPN3[2][0]->Integral(1, hsimtaggedjetNegLogJPN3[2][0]->GetNbinsX()) / incjetNegLogJPN3Yield * incjetNegLogJPN3YieldForData, 0.01*incjetNegLogJPN3YieldForData, incjetNegLogJPN3YieldForData);
//    RooRealVar lfjetNegLogJPN3YieldForData("lfjetNegLogJPN3YieldForData", "lfjet Yield", hsimtaggedjetNegLogJPN3[3][0]->Integral(1, hsimtaggedjetNegLogJPN3[3][0]->GetNbinsX()) / incjetNegLogJPN3Yield * incjetNegLogJPN3YieldForData, 0.01*incjetNegLogJPN3YieldForData, incjetNegLogJPN3YieldForData);
//
//    // Perform the fit to the data
//    RooAddPdf modelFitMC("modelFitMC", "Total PDF", RooArgList(histPdfcjetNegLogJP, histPdfbjetNegLogJP, histPdflfjetNegLogJP), RooArgList(cjetNegLogJPYield, bjetNegLogJPYield, lfjetNegLogJPYield));
//    RooAddPdf modelN1FitMC("modelN1FitMC", "Total PDF", RooArgList(histPdfcjetNegLogJPN1, histPdfbjetNegLogJPN1, histPdflfjetNegLogJPN1), RooArgList(cjetNegLogJPN1Yield, bjetNegLogJPN1Yield, lfjetNegLogJPN1Yield));
//    RooAddPdf modelN2FitMC("modelN2FitMC", "Total PDF", RooArgList(histPdfcjetNegLogJPN2, histPdfbjetNegLogJPN2, histPdflfjetNegLogJPN2), RooArgList(cjetNegLogJPN2Yield, bjetNegLogJPN2Yield, lfjetNegLogJPN2Yield));
//    RooAddPdf modelN3FitMC("modelN3FitMC", "Total PDF", RooArgList(histPdfcjetNegLogJPN3, histPdfbjetNegLogJPN3, histPdflfjetNegLogJPN3), RooArgList(cjetNegLogJPN3Yield, bjetNegLogJPN3Yield, lfjetNegLogJPN3Yield));
//    RooAddPdf modelFitData("modelFitData", "Total PDF", RooArgList(histPdfcjetNegLogJPForData, histPdfbjetNegLogJPForData, histPdflfjetNegLogJPForData), RooArgList(cjetNegLogJPYieldForData, bjetNegLogJPYieldForData, lfjetNegLogJPYieldForData));
//    RooAddPdf modelN1FitData("modelN1FitData", "Total PDF", RooArgList(histPdfcjetNegLogJPN1ForData, histPdfbjetNegLogJPN1ForData, histPdflfjetNegLogJPN1ForData), RooArgList(cjetNegLogJPN1YieldForData, bjetNegLogJPN1YieldForData, lfjetNegLogJPN1YieldForData));
//    RooAddPdf modelN2FitData("modelN2FitData", "Total PDF", RooArgList(histPdfcjetNegLogJPN2ForData, histPdfbjetNegLogJPN2ForData, histPdflfjetNegLogJPN2ForData), RooArgList(cjetNegLogJPN2YieldForData, bjetNegLogJPN2YieldForData, lfjetNegLogJPN2YieldForData));
//    RooAddPdf modelN3FitData("modelN3FitData", "Total PDF", RooArgList(histPdfcjetNegLogJPN3ForData, histPdfbjetNegLogJPN3ForData, histPdflfjetNegLogJPN3ForData), RooArgList(cjetNegLogJPN3YieldForData, bjetNegLogJPN3YieldForData, lfjetNegLogJPN3YieldForData));
//
//    std::cout << "START MC FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPYield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPYield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPYield.getVal() << std::endl;
//    RooFitResult* fitMC = modelFitMC.fitTo(mcincjetNegLogJP, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "cjet yield after: " << cjetNegLogJPYield.getVal() << std::endl;
//    std::cout << "bjet yield after: " << bjetNegLogJPYield.getVal() << std::endl;
//    std::cout << "lfjet yield after: " << lfjetNegLogJPYield.getVal() << std::endl;
//    std::cout << "END MC FITTING" << std::endl;
//    std::cout << "START MC (N1) FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPN1Yield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN1Yield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN1Yield.getVal() << std::endl;
//    RooFitResult* fitN1MC = modelN1FitMC.fitTo(mcincjetNegLogJPN1, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "cjet yield before: " << cjetNegLogJPN1Yield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN1Yield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN1Yield.getVal() << std::endl;
//    std::cout << "END MC (N1) FITTING" << std::endl;
//    std::cout << "START MC (N2) FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPN2Yield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN2Yield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN2Yield.getVal() << std::endl;
//    RooFitResult* fitN2MC = modelN2FitMC.fitTo(mcincjetNegLogJPN2, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "cjet yield before: " << cjetNegLogJPN2Yield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN2Yield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN2Yield.getVal() << std::endl;
//    std::cout << "END MC (N2) FITTING" << std::endl;
//    std::cout << "START MC (N3) FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPN3Yield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN3Yield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN3Yield.getVal() << std::endl;
//    RooFitResult* fitN3MC = modelN3FitMC.fitTo(mcincjetNegLogJPN3, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "cjet yield before: " << cjetNegLogJPN3Yield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN3Yield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN3Yield.getVal() << std::endl;
//    std::cout << "END MC (N3) FITTING" << std::endl;
//
//    std::cout << "START DATA FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPYieldForData.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPYieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPYieldForData.getVal() << std::endl;
//    RooFitResult* fitData = modelFitData.fitTo(datajetNegLogJP, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "incjet yield: " <<  incjetNegLogJPYieldForData << std::endl;
//    std::cout << "cjet yield after: " << cjetNegLogJPYieldForData.getVal() << std::endl;
//    std::cout << "bjet yield after: " << bjetNegLogJPYieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield after: " << lfjetNegLogJPYieldForData.getVal() << std::endl;
//    std::cout << "END DATA FITTING" << std::endl;
//    std::cout << "START DATA (N1) FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPN1YieldForData.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN1YieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN1YieldForData.getVal() << std::endl;
//    RooFitResult* fitN1Data = modelN1FitData.fitTo(datajetNegLogJPN1, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "incjet yield: " <<  incjetNegLogJPN1YieldForData << std::endl;
//    std::cout << "cjet yield after: " << cjetNegLogJPN1YieldForData.getVal() << std::endl;
//    std::cout << "bjet yield after: " << bjetNegLogJPN1YieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield after: " << lfjetNegLogJPN1YieldForData.getVal() << std::endl;
//    std::cout << "END DATA (N1) FITTING" << std::endl;
//    std::cout << "START DATA (N2) FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPN2YieldForData.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN2YieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN2YieldForData.getVal() << std::endl;
//    RooFitResult* fitN2Data = modelN2FitData.fitTo(datajetNegLogJPN2, RooFit::Minos(kTRUE), RooFit::Save(true));
//    std::cout << "incjet yield: " <<  incjetNegLogJPN2YieldForData << std::endl;
//    std::cout << "cjet yield after: " << cjetNegLogJPN2YieldForData.getVal() << std::endl;
//    std::cout << "bjet yield after: " << bjetNegLogJPN2YieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield after: " << lfjetNegLogJPN2YieldForData.getVal() << std::endl;
//    if (!fitN2Data || fitN2Data->status() != 0) {
//      std::cerr << "Error: Fit did not converge." << std::endl;
//    }
//    std::cout << "END DATA (N2) FITTING" << std::endl;
//    std::cout << "START DATA (N3) FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetNegLogJPN3YieldForData.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetNegLogJPN3YieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetNegLogJPN3YieldForData.getVal() << std::endl;
//
//    RooFitResult* fitN3Data = modelN3FitData.fitTo(datajetNegLogJPN3, RooFit::Minos(kFALSE), RooFit::Save(true));
//    std::cout << "incjet yield: " <<  incjetNegLogJPN3YieldForData << std::endl;
//    std::cout << "cjet yield after: " << cjetNegLogJPN3YieldForData.getVal() << std::endl;
//    std::cout << "bjet yield after: " << bjetNegLogJPN3YieldForData.getVal() << std::endl;
//    std::cout << "lfjet yield after: " << lfjetNegLogJPN3YieldForData.getVal() << std::endl;
//    std::cout << "END DATA (N3) FITTING" << std::endl;
//
//    std::cout<<"fit MC: " << std::endl;
//    fitMC->Print();
//
//    std::cout<<"fit data: " << std::endl;
//    fitData->Print();
//
//    std::cout<<"fit N1 MC: " << std::endl;
//    fitN1MC->Print();
//
//    std::cout<<"fit N1 data: " << std::endl;
//    fitN1Data->Print();
//
//    std::cout<<"fit N2 MC: " << std::endl;
//    fitN2MC->Print();
//
//    std::cout<<"fit N2 data: " << std::endl;
//    fitN2Data->Print();
//
//    std::cout<<"fit N3 MC: " << std::endl;
//    fitN3MC->Print();
//
//    std::cout<<"fit N3 data: " << std::endl;
//    fitN3Data->Print();
//
//    RooPlot* frameMC = jetProb.frame();
//    mcincjetNegLogJP.plotOn(frameMC, RooFit::DrawOption(""));
//    modelFitMC.plotOn(frameMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelFitMC"));
//    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfcjetNegLogJP"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfbjetNegLogJP"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelFitMC.plotOn(frameMC, RooFit::Components("histPdflfjetNegLogJP"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameMC->GetYaxis()->SetRangeUser(1, incjetNegLogJPYield);
//
//    RooPlot* frameMCN1 = jetProb.frame();
//    mcincjetNegLogJPN1.plotOn(frameMCN1, RooFit::DrawOption(""));
//    modelN1FitMC.plotOn(frameMCN1, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelN1FitMC"));
//    modelN1FitMC.plotOn(frameMCN1, RooFit::Components("histPdfcjetNegLogJPN1"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelN1FitMC.plotOn(frameMCN1, RooFit::Components("histPdfbjetNegLogJPN1"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelN1FitMC.plotOn(frameMCN1, RooFit::Components("histPdflfjetNegLogJPN1"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameMCN1->GetYaxis()->SetRangeUser(1, incjetNegLogJPN1Yield);
//
//    RooPlot* frameMCN2 = jetProb.frame();
//    mcincjetNegLogJPN2.plotOn(frameMCN2, RooFit::DrawOption(""));
//    modelN2FitMC.plotOn(frameMCN2, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelFit"));
//    modelN2FitMC.plotOn(frameMCN2, RooFit::Components("histPdfcjetNegLogJPN2"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelN2FitMC.plotOn(frameMCN2, RooFit::Components("histPdfbjetNegLogJPN2"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelN2FitMC.plotOn(frameMCN2, RooFit::Components("histPdflfjetNegLogJPN2"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameMCN2->GetYaxis()->SetRangeUser(1, incjetNegLogJPN2Yield);
//
//    RooPlot* frameMCN3 = jetProb.frame();
//    mcincjetNegLogJPN3.plotOn(frameMCN3, RooFit::DrawOption(""));
//    modelN3FitMC.plotOn(frameMCN3, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("modelFit"));
//    modelN3FitMC.plotOn(frameMCN3, RooFit::Components("histPdfcjetNegLogJPN3"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelN3FitMC.plotOn(frameMCN3, RooFit::Components("histPdfbjetNegLogJPN3"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelN3FitMC.plotOn(frameMCN3, RooFit::Components("histPdflfjetNegLogJPN3"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameMCN3->GetYaxis()->SetRangeUser(1, incjetNegLogJPN3Yield);
//
//    RooPlot* frameData = jetProb.frame();
//    datajetNegLogJP.plotOn(frameData, RooFit::DrawOption(""));
//    modelFitData.plotOn(frameData, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
//    modelFitData.plotOn(frameData, RooFit::Components("histPdfcjetNegLogJPForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelFitData.plotOn(frameData, RooFit::Components("histPdfbjetNegLogJPForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelFitData.plotOn(frameData, RooFit::Components("histPdflfjetNegLogJPForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameData->GetYaxis()->SetRangeUser(1, incjetNegLogJPYieldForData);
//
//    RooPlot* frameDataN1 = jetProb.frame();
//    datajetNegLogJPN1.plotOn(frameDataN1, RooFit::DrawOption(""));
//    modelN1FitData.plotOn(frameDataN1, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
//    modelN1FitData.plotOn(frameDataN1, RooFit::Components("histPdfcjetNegLogJPN1ForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelN1FitData.plotOn(frameDataN1, RooFit::Components("histPdfbjetNegLogJPN1ForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelN1FitData.plotOn(frameDataN1, RooFit::Components("histPdflfjetNegLogJPN1ForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameDataN1->GetYaxis()->SetRangeUser(1, incjetNegLogJPN1YieldForData);
//
//    RooPlot* frameDataN2 = jetProb.frame();
//    datajetNegLogJPN2.plotOn(frameDataN2, RooFit::DrawOption(""));
//    modelN2FitData.plotOn(frameDataN2, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
//    modelN2FitData.plotOn(frameDataN2, RooFit::Components("histPdfcjetNegLogJPN2ForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelN2FitData.plotOn(frameDataN2, RooFit::Components("histPdfbjetNegLogJPN2ForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelN2FitData.plotOn(frameDataN2, RooFit::Components("histPdflfjetNegLogJPN2ForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameDataN2->GetYaxis()->SetRangeUser(1, incjetNegLogJPN2YieldForData);
//
//    RooPlot* frameDataN3 = jetProb.frame();
//    datajetNegLogJPN3.plotOn(frameDataN3, RooFit::DrawOption(""));
//    modelN3FitData.plotOn(frameDataN3, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray+2), RooFit::DrawOption(""));
//    modelN3FitData.plotOn(frameDataN3, RooFit::Components("histPdfcjetNegLogJPN3ForData"), RooFit::DrawOption(""), RooFit::LineColor(kGreen));
//    modelN3FitData.plotOn(frameDataN3, RooFit::Components("histPdfbjetNegLogJPN3ForData"), RooFit::DrawOption(""), RooFit::LineColor(kRed));
//    modelN3FitData.plotOn(frameDataN3, RooFit::Components("histPdflfjetNegLogJPN3ForData"), RooFit::DrawOption(""), RooFit::LineColor(kBlue));
//    frameDataN3->GetYaxis()->SetRangeUser(1, incjetNegLogJPN3YieldForData);
//
//    // Draw the frame
//    TCanvas canvasMC("canvasMC", "Template Fit");
//    gPad->SetLogy();
//    frameMC->Draw();
//    canvasMC.SaveAs(Form("fig/sim/%s/jp/template_fit_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]) ));
//
//    TCanvas canvasMCN1("canvasMCN1", "Template Fit");
//    gPad->SetLogy();
//    frameMCN1->Draw();
//    canvasMCN1.SaveAs(Form("fig/sim/%s/jp/template_fit_N1_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    TCanvas canvasMCN2("canvasMCN2", "Template Fit");
//    gPad->SetLogy();
//    frameMCN2->Draw();
//    canvasMCN2.SaveAs(Form("fig/sim/%s/jp/template_fit_N2_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    TCanvas canvasMCN3("canvasMCN3", "Template Fit");
//    gPad->SetLogy();
//    frameMCN3->Draw();
//    canvasMCN3.SaveAs(Form("fig/sim/%s/jp/template_fit_N3_mc_%d.png", SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    TCanvas canvasData("canvasData", "Template Fit");
//    gPad->SetLogy();
//    frameData->Draw();
//    canvasData.SaveAs(Form("fig/data/%s/jp/template_fit_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    TCanvas canvasDataN1("canvasDataN1", "Template Fit");
//    canvasDataN1.cd();
//    gPad->SetLogy();
//    frameDataN1->Draw();
//    canvasDataN1.SaveAs(Form("fig/data/%s/jp/template_fit_N1_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    TCanvas canvasDataN2("canvasDataN2", "Template Fit");
//    canvasDataN2.cd();
//    gPad->SetLogy();
//    frameDataN2->Draw();
//    canvasDataN2.SaveAs(Form("fig/data/%s/jp/template_fit_N2_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    TCanvas canvasDataN3("canvasDataN3", "Template Fit");
//    canvasDataN3.cd();
//    gPad->SetLogy();
//    frameDataN3->Draw();
//    canvasDataN3.SaveAs(Form("fig/data/%s/jp/template_fit_N3_data_%d.png", DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.12);
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
//    gPad->SetLogy();
//    frameMC->Draw();
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
//    gPad->SetLogy();
//    frameMCN1->Draw();
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
//    gPad->SetLogy();
//    frameMCN2->Draw();
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
//    gPad->SetLogy();
//    frameMCN3->Draw();
//    gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/template_fit_N4x1_mc_%d.png\")", nc++, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.12);
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
//    gPad->SetLogy();
//    frameData->Draw();
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 1, 0));
//    gPad->SetLogy();
//    frameDataN1->Draw();
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 2, 0));
//    gPad->SetLogy();
//    frameDataN2->Draw();
//    gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 3, 0));
//    gPad->SetLogy();
//    frameDataN3->Draw();
//    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template_fit_N4x1_data_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//
//    // make pdf histogram from template fit
//    std::cout << "Drive method: creating pdf histogram" << std::endl;
//    hdatajetNegLogJP[1][binJetPt] = (TH1F*) modelFitData.createHistogram(Form("hdatajetNegLogJP_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPForData"));
//    hdatajetNegLogJP[2][binJetPt] = (TH1F*) modelFitData.createHistogram(Form("hdatajetNegLogJP_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPForData"));
//    hdatajetNegLogJP[3][binJetPt] = (TH1F*) modelFitData.createHistogram(Form("hdatajetNegLogJP_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPForData"));
//    hdatataggedjetNegLogJPN1[1][binJetPt] = (TH1F*) modelN1FitData.createHistogram(Form("hdatataggedjetNegLogJPN1_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPN1ForData"));
//    hdatataggedjetNegLogJPN1[2][binJetPt] = (TH1F*) modelN1FitData.createHistogram(Form("hdatataggedjetNegLogJPN1_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPN1ForData"));
//    hdatataggedjetNegLogJPN1[3][binJetPt] = (TH1F*) modelN1FitData.createHistogram(Form("hdatataggedjetNegLogJPN1_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPN1ForData"));
//    hdatataggedjetNegLogJPN2[1][binJetPt] = (TH1F*) modelN2FitData.createHistogram(Form("hdatataggedjetNegLogJPN2_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPN2ForData"));
//    hdatataggedjetNegLogJPN2[2][binJetPt] = (TH1F*) modelN2FitData.createHistogram(Form("hdatataggedjetNegLogJPN2_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPN2ForData"));
//    hdatataggedjetNegLogJPN2[3][binJetPt] = (TH1F*) modelN2FitData.createHistogram(Form("hdatataggedjetNegLogJPN2_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPN2ForData"));
//    hdatataggedjetNegLogJPN3[1][binJetPt] = (TH1F*) modelN3FitData.createHistogram(Form("hdatataggedjetNegLogJPN3_1_%d", binJetPt), jetProb, RooFit::Components("histPdfcjetNegLogJPN3ForData"));
//    hdatataggedjetNegLogJPN3[2][binJetPt] = (TH1F*) modelN3FitData.createHistogram(Form("hdatataggedjetNegLogJPN3_2_%d", binJetPt), jetProb, RooFit::Components("histPdfbjetNegLogJPN3ForData"));
//    hdatataggedjetNegLogJPN3[3][binJetPt] = (TH1F*) modelN3FitData.createHistogram(Form("hdatataggedjetNegLogJPN3_3_%d", binJetPt), jetProb, RooFit::Components("histPdflfjetNegLogJPN3ForData"));
//    std::cout << "Drive method: finisihed" << std::endl;
//  }
//}

void HfJetTaggingJPAnalysis::drawDataJetEffiN1(float cutImp) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN1 = taggingutilities::getEfficiency(hdatataggedjetNegLogJPN1[binJetPt],hdatajetNegLogJP[binJetPt]);
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
      float effiN2 = taggingutilities::getEfficiency(hdatataggedjetNegLogJPN2[binJetPt],hdatajetNegLogJP[binJetPt]);
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
      float effiN3 = taggingutilities::getEfficiency(hdatataggedjetNegLogJPN3[binJetPt],hdatajetNegLogJP[binJetPt]);
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
      htemp->Add(hdatataggedjetNegLogJPN1[binJetPt]);
      htemp->Add(hdatataggedjetNegLogJPN1[binJetPt]);
      htemp->Add(hdatataggedjetNegLogJPN1[binJetPt]);
      //float purityN1 = taggingutilities::getPurity(hdatataggedjetNegLogJPN1[flavour][binJetPt],hdatataggedjetNegLogJPN1[0][binJetPt]);
      float purityN1 = taggingutilities::getPurity(hdatataggedjetNegLogJPN1[binJetPt], htemp);
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
      htemp->Add(hdatataggedjetNegLogJPN2[binJetPt]);
      htemp->Add(hdatataggedjetNegLogJPN2[binJetPt]);
      htemp->Add(hdatataggedjetNegLogJPN2[binJetPt]);
      //float purityN2 = taggingutilities::getPurity(hdatataggedjetNegLogJPN2[flavour][binJetPt],hdatataggedjetNegLogJPN2[0][binJetPt]);
      float purityN2 = taggingutilities::getPurity(hdatataggedjetNegLogJPN2[binJetPt], htemp);
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
      htemp->Add(hdatataggedjetNegLogJPN3[binJetPt]);
      htemp->Add(hdatataggedjetNegLogJPN3[binJetPt]);
      htemp->Add(hdatataggedjetNegLogJPN3[binJetPt]);
      //float purityN3 = taggingutilities::getPurity(hdatataggedjetNegLogJPN3[flavour][binJetPt],hdatataggedjetNegLogJPN3[0][binJetPt]);
      float purityN3 = taggingutilities::getPurity(hdatataggedjetNegLogJPN3[binJetPt], htemp);
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

//void HfJetTaggingJPAnalysis::drawSimEffiAndPurityNx(TH1F* hImpNx, TH1F*hbasejet[][HfJetTagging::nBinsJetPt+1], float cutImp, int flavour, int binJetPt) {
//  // it needs TGraph
//  TGraph *gN1 = new TGraph();
//  std::vector<std::vector<float>> effiAndPurity
//  effi = static_cast<float>(calculateEffiSignedImpXYSig(hImpNx, cutImp));
//  purity = static_cast<float>(calculatePurity(flavour, binJetPt, hbaseImpNx, cutImp));
//  hsimtaggedjetNegLogJPN1->
//
//}

#endif // HFJETTAGGINGJPANALYSIS_H 
