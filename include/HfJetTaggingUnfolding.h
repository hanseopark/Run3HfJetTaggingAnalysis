#ifndef HFJETTAGGINGUNFOLDING_H
#define HFJETTAGGINGUNFOLDING_H

#if !(defined(__CINT__) || defined(__CLING__)) || defined(__ACLIC__)
#include <fstream>
#include "TH1F.h"
#include <TString.h>
//#include "JetAnalysis.h"

// for UNFOLDING
#include "RooUnfoldResponse.h"
#include "RooUnfoldiBayes.h"
#endif

#include "DataPoint.h"
#include "CanvasHandler.h"

class HfJetTaggingUnfolding : public HfJetTaggingAnalysis {
  public:
    HfJetTaggingUnfolding() : HfJetTaggingAnalysis() {
      initConfig();
    }
    ~HfJetTaggingUnfolding();

    void initConfig();
    void unfoldingJet(bool doLog, int flavour);
    void unfoldingJetWithData(bool doLog, int flavour);

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;

};

void HfJetTaggingUnfolding::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  TString dirFig = "fig";

  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  } 

  //TString dirData = Form("fig/data/%s/sv", TRIGGERNAME.Data());
  //gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  dirData = Form("%s/%s/data/%s/unfold", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/unfold", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  dirDataVsSim = Form("%s/%s/dataVSsim/%s_%s/unfold", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
     
}

void HfJetTaggingUnfolding::unfoldingJet(bool doLog, int flavour) {
  // It needs RooUnfold
  //gSystem->Load("/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Analysis/RooUnfold/build/libRooUnfold.dylib");
  
  if (!(fillMCD && fillMCP && fillMatched)) {
    return;
  }

//  TH1F* hsimjetPtMatchedRebin; 
//  hsimjetPtMatchedRebin = reinterpret_cast<TH1F*>(hsimjetPtMatched[flavour]->Clone());
//  hsimjetPtMatchedRebin->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
//
//  TH1F* hsimpartjetPtMatchedRebin; 
//  hsimpartjetPtMatchedRebin = reinterpret_cast<TH1F*>(hsimpartjetPtMatched[flavour]->Clone());
//  hsimpartjetPtMatchedRebin->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);

  RooUnfoldResponse resMat(hsimjetPtMatched[flavour], hsimpartjetPtMatched[flavour], h2simjetPtpartjetPtMatched[flavour], "", "", false);

  // Bayesain unfolding
  int n_iter=10;
  //RooUnfoldBayes unfold(&resMat, hdatajetPt, n_iter);
  RooUnfoldBayes unfold(&resMat, hsimjetPtMatched[flavour], n_iter);
  TH1F* unfolded_jetPt = (TH1F*) unfold.Hunfold();

	std::vector<HistogramData> histList;
	histList.push_back({unfolded_jetPt, "unfolded"});
	histList.push_back({hsimjetPt[flavour], "det"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histList.size(), histList, true, true);
  //this->drawCombined(histList.size(), histList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexDataJetInfo(0.2, 0.9);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfolded_jetmomentum.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingUnfolding::unfoldingJetWithData(bool doLog, int flavour) {
  
  if (!fillData) {
    std::cout<< "There are no datas" <<std::endl;
    return;
  }
  if (!fillMCD) {
    std::cout << "MCD off" << std::endl;
    return;
  }

//  TH1F* hsimjetPtMatchedRebin; 
//  hsimjetPtMatchedRebin = reinterpret_cast<TH1F*>(hsimjetPtMatched[flavour]->Clone());
//  hsimjetPtMatchedRebin = (TH1F*) hsimjetPtMatchedRebin->Rebin(unfold::nBinsJetPt, "", unfold::binsJetPt);
//
//  TH1F* hsimpartjetPtMatchedRebin; 
//  hsimpartjetPtMatchedRebin = reinterpret_cast<TH1F*>(hsimpartjetPtMatched[flavour]->Clone());
//  hsimpartjetPtMatchedRebin = (TH1F*) hsimpartjetPtMatchedRebin->Rebin(unfold::nBinsJetPt, "", unfold::binsJetPt);

  RooUnfoldResponse resMat(hsimjetPtMatched[flavour], hsimpartjetPtMatched[flavour], h2simjetPtpartjetPtMatched[flavour], "", "", false);

  // Bayesain unfolding
  TH1F* hdatajetPtRebin = (TH1F*) hdatajetPt->Rebin(unfold::nBinsJetPt, "", unfold::binsJetPt);
  int n_iter=10;
  //RooUnfoldBayes unfoldBayes(&resMat, hdatajetPtRebin, n_iter);
  RooUnfoldBayes unfoldBayes(&resMat, hdatajetPt, n_iter);
  //RooUnfoldSvd unfoldSVD(&resMat, hdatajetPtRebin, 16);
  RooUnfoldSvd unfoldSVD(&resMat, hdatajetPt, 16);
  //unfoldBayes.PrintTable(); // Unfolded results
  //unfoldSVD.PrintTable(); // Unfolded results
  TH1F* unfolded_bayes_jetPt = (TH1F*) unfoldBayes.Hunfold();
  TH1F* unfolded_svd_jetPt = (TH1F*) unfoldSVD.Hunfold();

  RooUnfoldBayes refold(&resMat, unfolded_bayes_jetPt, n_iter);
  TH1F* refolded_jetPt = (TH1F*) refold.Hunfold();

  std::cout << "data mean: " << hdatajetPtRebin->GetMean() << std::endl;
  //std::cout << "mean: " << refolded_jetPt->GetMean() << std::endl;

	std::vector<HistogramData> histList;
	histList.push_back({unfolded_bayes_jetPt, "unfolded Bayes"});
	//histList.push_back({unfolded_svd_jetPt, "unfolded SVD"});
	//histList.push_back({refolded_jetPt, "refolded"});
	//histList.push_back({hdatajetPtRebin, "raw jet"});
	histList.push_back({hdatajetPt, "raw jet"});
	//histList.push_back({hsimjetPtMatchedRebin, "MCD jet"});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], 1.2e+4*unfolded_jetPt->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], 1.2e+4*hdatajetPtRebin->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 1.2e+4*refolded_jetPt->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histList.size(), histList, true, true);
  //latexDataJetInfo(0.2, 0.9);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfolded_jetmomentum.pdf\")", nc++, dirDataVsSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

#endif // HFJETTAGGINGUNFOLDING_H 
