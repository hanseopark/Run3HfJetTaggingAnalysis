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
//#include "JetAnalysis.h"
//#include "HfJetTaggingAnalysis.h"
//#include "HfJetTaggingTCAnalysis.h"

class HfJetTaggingJPAnalysis {
  public:
    HfJetTaggingJPAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMC, TString triggerNAME, bool dopartLevel) {
      initConfig(triggerNAME.Data());
      if (doData) {
				if (!loadDataJPQA(rootData.Data())) {
          return;
        }
      	initHistogramForNormalizationJPQAData();
      	projectionHistJPQAData();
      	normalizedHistogramJPQAData();
			}
      if (doMC) {
				if (!loadSimJPQA(rootSim.Data())) {
          return;
        }
      	initHistogramForNormalizationJPQAMC();
      	projectionHistJPQAMC();
        //NegLogHist();
      	normalizedHistogramJPQAMC();
			}
      saveHistogramJPQA("JPQA.root", doData, doMC, dopartLevel);
    }
    ~HfJetTaggingJPAnalysis();

    // function
    ///Basic
    void initConfig(TString triggerNAME);
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
    
    /// Draw
    void histColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    std::vector<HistogramData> histList;
    void drawCombined(int num, const std::vector<HistogramData>& histList, bool withLeg, double legendxmin, double ymin, double xmax, double ymax);

    int canvasNum = 20000;
    CanvasHandler* canvasHandler;
    void drawDataJetJP(bool doLog, int binJetPt);
    void drawDataJetNegLogJP(bool doLog, int binJetPt);
    void drawDataJetJPN1(bool doLog, int binJetPt, float cutImp);
    void drawDataJetNegLogJPN1(bool doLog, int binJetPt, float cutImp);
    void drawDataJetJPN2(bool doLog, int binJetPt, float cutImp);
    void drawDataJetNegLogJPN2(bool doLog, int binJetPt, float cutImp);
    void drawDataJetJPN3(bool doLog, int binJetPt, float cutImp);
    void drawDataJetNegLogJPN3(bool doLog, int binJetPt, float cutImp);

    void drawSimJetJP(bool withInc, bool doLog, int binJetPt);
    void drawSimJetNegLogJP(bool withInc, bool doLog, int binJetPt);
    void drawSimJetJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetRef();
    void drawSimJetEffiN1(float cutImp);
    void drawSimJetEffiN2(float cutImp);
    void drawSimJetEffiN3(float cutImp);
    void drawSimJetPurityN1(float cutImp);
    void drawSimJetPurityN2(float cutImp);
    void drawSimJetPurityN3(float cutImp);
    void drawSimJetEffiAndPurity(float cutImp, int binJetPt);
    void drawTemplateFit();

  protected:
    TH2F* h2dataTagjetPtJP;
    TH2F* h2dataTagjetPtNegLogJP;
    TH2F* h2dataTagjetPtJPN1;
    TH2F* h2dataTagjetPtNegLogJPN1;
    TH2F* h2dataTagjetPtJPN2;
    TH2F* h2dataTagjetPtNegLogJPN2;
    TH2F* h2dataTagjetPtJPN3;
    TH2F* h2dataTagjetPtNegLogJPN3;

    TH2F* h2simTagjetPtFlavour;
    TH3F* h3simTagjetPtJPFlavour;
    TH3F* h3simTagjetPtNegLogJPFlavour;
    TH3F* h3simTagjetPtJPN1Flavour;
    TH3F* h3simTagjetPtNegLogJPN1Flavour;
    TH3F* h3simTagjetPtJPN2Flavour;
    TH3F* h3simTagjetPtNegLogJPN2Flavour;
    TH3F* h3simTagjetPtJPN3Flavour;
    TH3F* h3simTagjetPtNegLogJPN3Flavour;

    TH1F* hdataTagjetJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNegLogJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJP[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJPN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJPN2[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedJPN3[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalizedNegLogJPN3[HfJetTagging::nBinsJetPt+1];


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
    TString triggerName;

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
void HfJetTaggingJPAnalysis::initConfig(TString triggerNAME) {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

  //gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  TString dirData = Form("fig/data/%s/jp", DATASET.Data());
  TString dirSim = Form("fig/sim/%s/jp", SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
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

  std::cout << "Load completed JP MC data" << std::endl;
  return 1;
}

void HfJetTaggingJPAnalysis::initHistogramForNormalizationJPQAData() {
  for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
		hdataTagjetJP[jetPt] = new TH1F(Form("hdataTagjetJP_%d",  jetPt), "", h2dataTagjetPtJP->GetNbinsY(), h2dataTagjetPtJP->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJP->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJP->GetNbinsY()));
		hdataTagjetNegLogJP[jetPt] = new TH1F(Form("hdataTagjetNegLogJP_%d", jetPt), "", h2dataTagjetPtNegLogJP->GetNbinsY(), h2dataTagjetPtNegLogJP->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJP->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJP->GetNbinsY()));
		hdataTagjetJPN1[jetPt] = new TH1F(Form("hdataTagjetJP_N1_%d", jetPt), "", h2dataTagjetPtJPN1->GetNbinsY(), h2dataTagjetPtJPN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJPN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJPN1->GetNbinsY()));
		hdataTagjetNegLogJPN1[jetPt] = new TH1F(Form("hdataTagjetNegLogJP_N1_%d", jetPt), "", h2dataTagjetPtNegLogJPN1->GetNbinsY(), h2dataTagjetPtNegLogJPN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJPN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJPN1->GetNbinsY()));
		hdataTagjetJPN2[jetPt] = new TH1F(Form("hdataTagjetJP_N2_%d", jetPt), "", h2dataTagjetPtJPN2->GetNbinsY(), h2dataTagjetPtJPN2->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJPN2->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJPN2->GetNbinsY()));
		hdataTagjetNegLogJPN2[jetPt] = new TH1F(Form("hdataTagjetNegLogJP_N2_%d", jetPt), "", h2dataTagjetPtNegLogJPN2->GetNbinsY(), h2dataTagjetPtNegLogJPN2->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJPN2->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJPN2->GetNbinsY()));
		hdataTagjetJPN3[jetPt] = new TH1F(Form("hdataTagjetJP_N3_%d", jetPt), "", h2dataTagjetPtJPN3->GetNbinsY(), h2dataTagjetPtJPN3->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtJPN3->GetYaxis()->GetBinUpEdge(h2dataTagjetPtJPN3->GetNbinsY()));
		hdataTagjetNegLogJPN3[jetPt] = new TH1F(Form("hdataTagjetNegLogJP_N3_%d", jetPt), "", h2dataTagjetPtNegLogJPN3->GetNbinsY(), h2dataTagjetPtNegLogJPN3->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtNegLogJPN3->GetYaxis()->GetBinUpEdge(h2dataTagjetPtNegLogJPN3->GetNbinsY()));
  }
}

void HfJetTaggingJPAnalysis::initHistogramForNormalizationJPQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimRefTagger[flavour] = new TH1F(Form("hsimRefTagger_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
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
  hdataTagjetNegLogJP[0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone("hdataTagjetNegLogJP")); 
  hdataTagjetNegLogJPN1[0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone("hdataTagjetNegLogJPN1")); 
  hdataTagjetNegLogJPN2[0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone("hdataTagjetNegLogJPN2")); 
  hdataTagjetNegLogJPN3[0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone("hdataTagjetNegLogJPN3")); 


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
    hdataTagjetNegLogJP[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hdataTagjetNegLogJP_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN1 = h2dataTagjetPtNegLogJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN1 = h2dataTagjetPtNegLogJPN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN1->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d", binJetPt), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1));
    hdataTagjetNegLogJPN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hdataTagjetNegLogJPN1_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN2 = h2dataTagjetPtNegLogJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN2 = h2dataTagjetPtNegLogJPN2->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN2->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d", binJetPt), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2));
    hdataTagjetNegLogJPN2[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hdataTagjetNegLogJPN2_%d", binJetPt))); 

    int leftbinJetPtNegLogJPN3 = h2dataTagjetPtNegLogJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtNegLogJPN3 = h2dataTagjetPtNegLogJPN3->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h2dataTagjetPtNegLogJPN3->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d", binJetPt), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3));
    hdataTagjetNegLogJPN3[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hdataTagjetNegLogJPN3_%d", binJetPt))); 

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
    hdataTagjetNormalizedNegLogJP[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJP[jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJP_%d", jetPt)));
    hdataTagjetNormalizedJPN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJPN1[jetPt]->Clone(Form("hdataTagjetNormalizedJPN1_%d", jetPt)));
    hdataTagjetNormalizedNegLogJPN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJPN1[jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJPN1_%d", jetPt)));
    hdataTagjetNormalizedJPN2[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJPN2[jetPt]->Clone(Form("hdataTagjetNormalizedJPN2_%d", jetPt)));
    hdataTagjetNormalizedNegLogJPN2[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJPN2[jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJPN2_%d", jetPt)));
    hdataTagjetNormalizedJPN3[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetJPN3[jetPt]->Clone(Form("hdataTagjetNormalizedJPN3_%d", jetPt)));
    hdataTagjetNormalizedNegLogJPN3[jetPt] = reinterpret_cast<TH1F*> (hdataTagjetNegLogJPN3[jetPt]->Clone(Form("hdataTagjetNormalizedNegLogJPN3_%d", jetPt)));

    // Scale
    hdataTagjetNormalizedJP[jetPt]->Scale(1. / hdataTagjetNormalizedJP[jetPt]->GetEntries());
    hdataTagjetNormalizedNegLogJP[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJP[jetPt]->GetEntries());
    hdataTagjetNormalizedJPN1[jetPt]->Scale(1. / hdataTagjetNormalizedJPN1[jetPt]->GetEntries());
    hdataTagjetNormalizedNegLogJPN1[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJPN1[jetPt]->GetEntries());
    hdataTagjetNormalizedJPN2[jetPt]->Scale(1. / hdataTagjetNormalizedJPN2[jetPt]->GetEntries());
    hdataTagjetNormalizedNegLogJPN2[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJPN2[jetPt]->GetEntries());
    hdataTagjetNormalizedJPN3[jetPt]->Scale(1. / hdataTagjetNormalizedJPN3[jetPt]->GetEntries());
    hdataTagjetNormalizedNegLogJPN3[jetPt]->Scale(1. / hdataTagjetNormalizedNegLogJPN3[jetPt]->GetEntries());
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
			hsimTagjetNormalizedJP[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJP[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedNegLogJP[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJP[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedJPN1[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJPN1[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedNegLogJPN1[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJPN1[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedJPN2[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJPN2[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedNegLogJPN2[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJPN2[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedJPN3[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJPN3[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedNegLogJPN3[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJPN3[flavour][jetPt]->GetEntries());
    }
  }
}

void HfJetTaggingJPAnalysis::saveHistogramJPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hsimTagjetNegLogJP[flavour][jetPt]->Write();
      hsimTagjetNegLogJPN1[flavour][jetPt]->Write();
      hsimTagjetNegLogJPN2[flavour][jetPt]->Write();
      hsimTagjetNegLogJPN3[flavour][jetPt]->Write();
    }
  }
  fout->Close();
  delete fout;
}

// Draw function
void HfJetTaggingJPAnalysis::histColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingJPAnalysis::drawCombined(int num, const std::vector<HistogramData>& histograms, bool withLeg, double xmin=0, double ymin=0, double xmax=1, double ymax=1){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->histColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (withLeg) leg->Draw();
}

void HfJetTaggingJPAnalysis::drawDataJetJP(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedJP[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProb_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJP(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedNegLogJP[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbNegLog_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetJPN1(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedJPN1[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbN1_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJPN1(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedNegLogJPN1[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbNegLogN1_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetJPN2(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedJPN2[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbN2_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJPN2(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedNegLogJPN2[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbNegLogN2_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetJPN3(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedJPN3[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbN3_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawDataJetNegLogJPN3(bool doLog = true, int binJetPt=0, float cutImp=2.5) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedNegLogJPN3[binJetPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/jp/jetProbNegLogN3_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJP(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedJP[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedJP[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedJP[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedJP[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProb_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}



void HfJetTaggingJPAnalysis::drawSimJetNegLogJP(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJP[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJP[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbNegLog_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJPN1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedJPN1[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN1[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN1[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN1[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbN1_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN1(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedNegLogJPN1[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN1[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN1[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN1[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=1");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbNegLogN1_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJPN2(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedJPN2[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN2[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN2[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN2[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbN2_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN2(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedNegLogJPN2[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN2[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN2[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN2[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=2");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbNegLogN2_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetJPN3(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedJPN3[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN3[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN3[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedJPN3[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbN3_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingJPAnalysis::drawSimJetNegLogJPN3(bool withInc = false, bool doLog = true, int binJetPt=0, float cutImp=1.0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedNegLogJPN3[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN3[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN3[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJPN3[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9, "N=3");
  latex.DrawLatex(0.5, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/jetProbNegLogN3_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

float HfJetTaggingJPAnalysis::getLifeTimeRefTagger(TH1F* hJP, TH1F* hJetPt, int binJetPt) {
  int numOfJetforJP = hJP->Integral(1, hJP->GetNbinsX());
  int numOfJet =  hJetPt->GetEntries();
  int leftbin = HfJetTagging::binsJetPt[binJetPt-1];
  int rightbin = HfJetTagging::binsJetPt[binJetPt];
  //int numOfJet =  hJetPt->Integral(leftbin, rightbin);

  std::cout << "jp entries: " << numOfJetforJP << " jet entries: " << numOfJet << std::endl;
  if (numOfJet==0) return -1;
  
  auto ref=  static_cast<float> ((float) numOfJetforJP / numOfJet);
  return ref;
}

float HfJetTaggingJPAnalysis::getEfficiency(TH1F* hNegLogJPNx, TH1F* hNegLogJPUntagged) {
  // it needs code defence
  int numOfbJetBeforeTagger = hNegLogJPUntagged->Integral(1, hNegLogJPUntagged->GetNbinsX());
  int numOfbJetAfterTagger = hNegLogJPNx->Integral(1, hNegLogJPNx->GetNbinsX());
  if (numOfbJetBeforeTagger==0) return -1;
  float effi = static_cast<float>((float)numOfbJetAfterTagger / numOfbJetBeforeTagger);
  return effi;
}

float HfJetTaggingJPAnalysis::getPurity(TH1F* hNegLogJPTaggedbJet, TH1F* hNegLogJPTaggedIncJet) {
  // it needs defence
  int numOfbjet = hNegLogJPTaggedbJet->GetEntries();
  int numOfincjet = hNegLogJPTaggedIncJet->GetEntries();
  if (numOfincjet == 0 ) return -1;
  float purity = static_cast<float>((float)numOfbjet/numOfincjet);
  return purity;
}

void HfJetTaggingJPAnalysis::drawSimJetRef() {
	std::vector<HistogramData> NormHistList;

  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //float refTagger = this->getLifeTimeRefTagger(hsimTagjetNegLogJP[flavour][binJetPt], hsimTagjetPt[flavour], binJetPt);
      float refTagger = this->getLifeTimeRefTagger(hsimTagjetNegLogJP[flavour][binJetPt], hsimTagjetJP[flavour][binJetPt], binJetPt);
      hsimRefTagger[flavour]->SetBinContent(binJetPt, refTagger);
    }
	  NormHistList.push_back({hsimRefTagger[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "#it{p_{T}^{jet}}", "C_{b}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/lifeTimeRefTagger.pdf\")", canvasNum - 1, SIMSET.Data()));

}

void HfJetTaggingJPAnalysis::drawSimJetEffiN1(float cutImp) {
	std::vector<HistogramData> NormHistList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effiN1 = this->getEfficiency(hsimTagjetNegLogJPN1[flavour][binJetPt],hsimTagjetNegLogJP[flavour][binJetPt]);
      if (effiN1 < 0) continue;
      hsimJPEffiN1[flavour]->SetBinContent(binJetPt, effiN1);
    }
	  NormHistList.push_back({hsimJPEffiN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "#it{p_{T}^{jet}}", "#epsilon");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/EffiJPN1.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetEffiN2(float cutImp) {
	std::vector<HistogramData> NormHistList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt

      float effiN2 = this->getEfficiency(hsimTagjetNegLogJPN2[flavour][binJetPt],hsimTagjetNegLogJP[flavour][binJetPt]);
      if (effiN2 < 0) continue;
      hsimJPEffiN2[flavour]->SetBinContent(binJetPt, effiN2);
    }
	  NormHistList.push_back({hsimJPEffiN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "#it{p_{T}^{jet}}", "#epsilon");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=2");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/EffiJPN2.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetEffiN3(float cutImp) {
	std::vector<HistogramData> NormHistList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt

      float effiN3 = this->getEfficiency(hsimTagjetNegLogJPN3[flavour][binJetPt],hsimTagjetNegLogJP[flavour][binJetPt]);
      if (effiN3 < 0) continue;
      hsimJPEffiN3[flavour]->SetBinContent(binJetPt, effiN3);
    }
	  NormHistList.push_back({hsimJPEffiN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "#it{p_{T}^{jet}}", "#epsilon");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=3");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/EffiJPN3.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityN1(float cutImp) {
	std::vector<HistogramData> NormHistList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN1 = this->getPurity(hsimTagjetNegLogJPN1[flavour][binJetPt],hsimTagjetNegLogJPN1[0][binJetPt]);
      hsimJPPurityN1[flavour]->SetBinContent(binJetPt, purityN1);
    }
	  NormHistList.push_back({hsimJPPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "#it{p_{T}^{jet}}", "purity");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=1");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/PurityJPN1.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityN2(float cutImp) {
	std::vector<HistogramData> NormHistList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN2 = this->getPurity(hsimTagjetNegLogJPN2[flavour][binJetPt],hsimTagjetNegLogJPN2[0][binJetPt]);
      hsimJPPurityN2[flavour]->SetBinContent(binJetPt, purityN2);
    }
	  NormHistList.push_back({hsimJPPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "#it{p_{T}^{jet}}", "purity");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=2");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/PurityJPN2.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingJPAnalysis::drawSimJetPurityN3(float cutImp) {
	std::vector<HistogramData> NormHistList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purityN3 = this->getPurity(hsimTagjetNegLogJPN3[flavour][binJetPt],hsimTagjetNegLogJPN3[0][binJetPt]);
      hsimJPPurityN3[flavour]->SetBinContent(binJetPt, purityN3);
    }
	  NormHistList.push_back({hsimJPPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "#it{p_{T}^{jet}}", "purity");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.00, "N=3");
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutImp));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/jp/PurityJPN3.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingJPAnalysis::drawTemplateFit() {
  RooRealVar jetProb("jetProb", "Jet Probaility", 0, 10);

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
