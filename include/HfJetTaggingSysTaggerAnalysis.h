#ifndef HFJETTAGGINGSYSTAGGERANALYSIS_H
#define HFJETTAGGINGSYSTAGGERANALYSIS_H


#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

class HfJetTaggingSysTaggerAnalysis : public HfJetTaggingSysAnalysis{
  public:
    HfJetTaggingSysTaggerAnalysis() : HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysTaggerAnalysis();

    //// FUNCTION ////
    void initConfig();
    int loadSimTagger(const std::vector<TString> &rootFiles);
    void initHistogramTagger();
    void projectionHistTagger();
    void normalizedHistogramTagger();
    void saveHistogram(TString rootFile, bool doData, bool doMCD, bool doMCP);

    // Set

    // Get

    // Draw
    void drawEffiN1(bool doLog, int binJetPt);
    void drawEffiN2(bool doLog, int binJetPt);
    void drawEffiN3(bool doLog, int binJetPt);
    void drawEffiNx(bool doLog, int binJetPt);
    void drawPurityN1(bool doLog, int binJetPt);
    void drawPurityN2(bool doLog, int binJetPt);
    void drawPurityN3(bool doLog, int binJetPt);
    void drawPurityNx(bool doLog, int binJetPt);
    void drawEffiAndPurityNx(bool doLog, int binJetPt);
    void drawGraphEffiAndPurity(bool doLog, int binJetPt);
    
  protected:
    TH1F* hsimJPEffiN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN3[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN3[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiAndPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiAndPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiAndPurityN3[HfJetTagging::nFlavour+1];

  private:
    TLatex latexNoNDC;
    TLatex latex;
    TString dirData;
    TString dirSim;
};

HfJetTaggingSysTaggerAnalysis::~HfJetTaggingSysTaggerAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysTaggerAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysTaggerAnalysis::initConfig() {
  //latex.SetNDC(); // Use normalized coordinates
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  dirData = Form("%s/%s/data/%s/sys/tagger", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/sys/tagger", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSysTaggerAnalysis::loadSimTagger(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxTagger = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      std::cout << Form("%s ", rootFile.Data()) << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    
    h3simjetPtNegLogJPFlavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
    h3simjetPtNegLogJPN1Flavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N1_flavour", taskName.Data())));
    h3simjetPtNegLogJPN2Flavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N2_flavour", taskName.Data())));
    h3simjetPtNegLogJPN3Flavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N3_flavour", taskName.Data())));
    maxTagger++;
  }
  std::cout<<"MC loaded"<<std::endl;

  return 1;
}

void HfJetTaggingSysTaggerAnalysis::initHistogramTagger() {
  for (int tagger =0; tagger < HfJetTagging::numTaggerIP; tagger++) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      if (tagger<1) {
        hsimJPEffiN1[flavour] = new TH1F(Form("hsimJPEffiN1_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPEffiN2[flavour] = new TH1F(Form("hsimJPEffiN2_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPEffiN3[flavour] = new TH1F(Form("hsimJPEffiN3_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPPurityN1[flavour] = new TH1F(Form("hsimJPPurityN1_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPPurityN2[flavour] = new TH1F(Form("hsimJPPurityN2_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPPurityN3[flavour] = new TH1F(Form("hsimJPPurityN3_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPEffiAndPurityN1[flavour] = new TH1F(Form("hsimJPEffiAndPurityN1_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPEffiAndPurityN2[flavour] = new TH1F(Form("hsimJPEffiAndPurityN2_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
        hsimJPEffiAndPurityN3[flavour] = new TH1F(Form("hsimJPEffiAndPurityN3_%d", flavour), "", HfJetTagging::numTaggerIP, -0.25, 9.75);
      }
      for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        hsimjetNegLogJP[tagger][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJP_%d_%d_%d", tagger, flavour, binJetPt), "", h3simjetPtNegLogJPFlavour[tagger]->GetNbinsY(), h3simjetPtNegLogJPFlavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPFlavour[tagger]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPFlavour[tagger]->GetNbinsY()));
        hsimjetNegLogJPN1[tagger][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt), "", h3simjetPtNegLogJPN1Flavour[tagger]->GetNbinsY(), h3simjetPtNegLogJPN1Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPN1Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPN1Flavour[tagger]->GetNbinsY()));
        hsimjetNegLogJPN2[tagger][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt), "", h3simjetPtNegLogJPN2Flavour[tagger]->GetNbinsY(), h3simjetPtNegLogJPN2Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPN2Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPN2Flavour[tagger]->GetNbinsY()));
        hsimjetNegLogJPN3[tagger][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt), "", h3simjetPtNegLogJPN3Flavour[tagger]->GetNbinsY(), h3simjetPtNegLogJPN3Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPN3Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPN3Flavour[tagger]->GetNbinsY()));
      }
    }
  }
}

void HfJetTaggingSysTaggerAnalysis::projectionHistTagger() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
		  TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPFlavour[tagger]->ProjectionY(Form("projNegLogJP_%d_%d", tagger, flavour), 1, h3simjetPtNegLogJPFlavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN1 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN1Flavour[tagger]->ProjectionY(Form("projNegLogJPN1_%d_%d", tagger, flavour), 1, h3simjetPtNegLogJPN1Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN2 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN2Flavour[tagger]->ProjectionY(Form("projNegLogJPN2_%d_%d", tagger, flavour), 1, h3simjetPtNegLogJPN2Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN3 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN3Flavour[tagger]->ProjectionY(Form("projNegLogJPN3_%d_%d", tagger, flavour), 1, h3simjetPtNegLogJPN3Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));

		  hsimjetNegLogJP[tagger][0][0]->Add(projNegLogJP);
		  hsimjetNegLogJP[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimjetNegLogJP_%d_%d_0", tagger, flavour)));
		  hsimjetNegLogJPN1[tagger][0][0]->Add(projNegLogJPN1);
		  hsimjetNegLogJPN1[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone(Form("hsimjetNegLogJPN1_%d_%d_0", tagger, flavour)));
		  hsimjetNegLogJPN2[tagger][0][0]->Add(projNegLogJPN2);
		  hsimjetNegLogJPN2[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone(Form("hsimjetNegLogJPN2_%d_%d_0", tagger, flavour)));
		  hsimjetNegLogJPN3[tagger][0][0]->Add(projNegLogJPN3);
		  hsimjetNegLogJPN3[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone(Form("hsimjetNegLogJPN3_%d_%d_0", tagger, flavour)));
      delete projNegLogJP;
      delete projNegLogJPN1;
      delete projNegLogJPN2;
      delete projNegLogJPN3;
      for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        int leftbinJetPtNegLogJP = h3simjetPtNegLogJPFlavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJP = h3simjetPtNegLogJPFlavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPFlavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJP_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, binFlavour, binFlavour));
        hsimjetNegLogJP[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hsimjetNegLogJP_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimjetNegLogJP[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJP);

        int leftbinJetPtNegLogJPN1 = h3simjetPtNegLogJPN1Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN1 = h3simjetPtNegLogJPN1Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN1Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1, binFlavour, binFlavour));
        hsimjetNegLogJPN1[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hsimjetNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimjetNegLogJPN1[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN1);

        int leftbinJetPtNegLogJPN2 = h3simjetPtNegLogJPN2Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN2 = h3simjetPtNegLogJPN2Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN2Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2, binFlavour, binFlavour));
        hsimjetNegLogJPN2[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hsimjetNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimjetNegLogJPN2[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN2);

        int leftbinJetPtNegLogJPN3 = h3simjetPtNegLogJPN3Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN3 = h3simjetPtNegLogJPN3Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN3Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3, binFlavour, binFlavour));
        hsimjetNegLogJPN3[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hsimjetNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimjetNegLogJPN3[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN3);

        delete projJetPtRangeNegLogJP;
        delete projJetPtRangeNegLogJPN1;
        delete projJetPtRangeNegLogJPN2;
        delete projJetPtRangeNegLogJPN3;
      }
    }
  }
}

void HfJetTaggingSysTaggerAnalysis::normalizedHistogramTagger() {
}

void HfJetTaggingSysTaggerAnalysis::saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  TDirectory* dir;

  if (doMC) {
    dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
  	}
  }
}

void HfJetTaggingSysTaggerAnalysis::drawEffiN1(bool doLog, int binJetPt) {
  std::vector<HistogramData> histList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
      float effiN1 = taggingutilities::getEfficiency(hsimjetNegLogJPN1[tagger][flavour][binJetPt],hsimjetNegLogJP[tagger][flavour][binJetPt]);
      if (effiN1 < 0) continue;
      hsimJPEffiN1[flavour]->SetBinContent(tagger+1, effiN1);
    }
    histList.push_back({hsimJPEffiN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(histList.size(), histList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=1");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN1_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawEffiN2(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
      float effiN2 = taggingutilities::getEfficiency(hsimjetNegLogJPN2[tagger][flavour][binJetPt],hsimjetNegLogJP[tagger][flavour][binJetPt]);
      if (effiN2 < 0) continue;
      hsimJPEffiN2[flavour]->SetBinContent(tagger+1, effiN2);
    }
    normHist.push_back({hsimJPEffiN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=2");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN2_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawEffiN3(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
      float effiN3 = taggingutilities::getEfficiency(hsimjetNegLogJPN3[tagger][flavour][binJetPt],hsimjetNegLogJP[tagger][flavour][binJetPt]);
      if (effiN3 < 0) continue;
      hsimJPEffiN3[flavour]->SetBinContent(tagger+1, effiN3);
    }
    normHist.push_back({hsimJPEffiN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=3");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiJPN3_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawEffiNx(bool doLog, int binJetPt) {
  std::vector<HistogramData> cjetHist;
  cjetHist.push_back({hsimJPEffiN1[1], "N=1"});
  cjetHist.push_back({hsimJPEffiN2[1], "N=2"});
  cjetHist.push_back({hsimJPEffiN3[1], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon_{c}");
  canHan->drawCombined(cjetHist.size(), cjetHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/EffiJPNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));

  std::vector<HistogramData> bjetHist;
  bjetHist.push_back({hsimJPEffiN1[2], "N=1"});
  bjetHist.push_back({hsimJPEffiN2[2], "N=2"});
  bjetHist.push_back({hsimJPEffiN3[2], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon_{b}");
  canHan->drawCombined(bjetHist.size(), bjetHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiJPNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));

  std::vector<HistogramData> lfjetHist;
  lfjetHist.push_back({hsimJPEffiN1[3], "N=1"});
  lfjetHist.push_back({hsimJPEffiN2[3], "N=2"});
  lfjetHist.push_back({hsimJPEffiN3[3], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon_{lf}");
  canHan->drawCombined(lfjetHist.size(), lfjetHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/EffiJPNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawPurityN1(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
      float purityN1 = taggingutilities::getPurity(hsimjetNegLogJPN1[tagger][flavour][binJetPt],hsimjetNegLogJPN1[tagger][0][binJetPt]);
      hsimJPPurityN1[flavour]->SetBinContent(tagger+1, purityN1);
    }
    normHist.push_back({hsimJPPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", "Purity");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.67, 0.9-0.02, "#scale[1.5]{N=1}");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/purityN1_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawPurityN2(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
      float purityN2 = taggingutilities::getPurity(hsimjetNegLogJPN2[tagger][flavour][binJetPt],hsimjetNegLogJPN2[tagger][0][binJetPt]);
      hsimJPPurityN2[flavour]->SetBinContent(tagger+1, purityN2);
    }
    normHist.push_back({hsimJPPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", "Purity");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.67, 0.9-0.02, "#scale[1.5]{N=2}");
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/purityN2_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawPurityN3(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
      float purityN3 = taggingutilities::getPurity(hsimjetNegLogJPN3[tagger][flavour][binJetPt],hsimjetNegLogJPN3[tagger][0][binJetPt]);
      hsimJPPurityN3[flavour]->SetBinContent(tagger+1, purityN3);
    }
    normHist.push_back({hsimJPPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", "Purity");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.67, 0.9-0.02, "#scale[1.5]{N=3}");
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/purityN3_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawPurityNx(bool doLog, int binJetPt) {
  std::vector<HistogramData> cjetHist;
  cjetHist.push_back({hsimJPPurityN1[1], "N=1"});
  cjetHist.push_back({hsimJPPurityN2[1], "N=2"});
  cjetHist.push_back({hsimJPPurityN3[1], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", "purity");
  canHan->drawCombined(cjetHist.size(), cjetHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/purityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));

  std::vector<HistogramData> bjetHist;
  bjetHist.push_back({hsimJPPurityN1[2], "N=1"});
  bjetHist.push_back({hsimJPPurityN2[2], "N=2"});
  bjetHist.push_back({hsimJPPurityN3[2], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", "purity");
  canHan->drawCombined(bjetHist.size(), bjetHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/purityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));

  std::vector<HistogramData> lfjetHist;
  lfjetHist.push_back({hsimJPPurityN1[3], "N=1"});
  lfjetHist.push_back({hsimJPPurityN2[3], "N=2"});
  lfjetHist.push_back({hsimJPPurityN3[3], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (#it{S}_{xy})", "purity");
  canHan->drawCombined(lfjetHist.size(), lfjetHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/purityNx_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSysTaggerAnalysis::drawEffiAndPurityNx(bool doLog, int binJetPt) {
  std::vector<HistogramData> histList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger =0; tagger < HfJetTagging::numTaggerIP; tagger++) {
      float effiN1 = hsimJPEffiN1[flavour]->GetBinContent(tagger+1);
      float effiN2 = hsimJPEffiN2[flavour]->GetBinContent(tagger+1);
      float effiN3 = hsimJPEffiN3[flavour]->GetBinContent(tagger+1);
      float purityN1 = hsimJPPurityN1[flavour]->GetBinContent(tagger+1);
      float purityN2 = hsimJPPurityN2[flavour]->GetBinContent(tagger+1);
      float purityN3 = hsimJPPurityN3[flavour]->GetBinContent(tagger+1);
      hsimJPEffiAndPurityN1[flavour]->SetBinContent(tagger+1, purityN1 / effiN1);
      hsimJPEffiAndPurityN2[flavour]->SetBinContent(tagger+1, purityN2 / effiN2);
      hsimJPEffiAndPurityN3[flavour]->SetBinContent(tagger+1, purityN3 / effiN3);
    }
  }
  histList.push_back({hsimJPEffiAndPurityN1[2], "N=1"});
  histList.push_back({hsimJPEffiAndPurityN2[2], "N=2"});
  histList.push_back({hsimJPEffiAndPurityN3[2], "N=3"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 9.75, HfJetTagging::REFHIST::EFFI[2], 10*HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#frac{P_{b}}{#epsilon_{b}}");
  canHan->drawCombined(histList.size(), histList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/effiAndpurityNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysTaggerAnalysis::drawGraphEffiAndPurity(bool doLog, int binJetPt) {
  float xN1[HfJetTagging::numTaggerIP], yN1[HfJetTagging::numTaggerIP];
  float xN2[HfJetTagging::numTaggerIP], yN2[HfJetTagging::numTaggerIP];
  float xN3[HfJetTagging::numTaggerIP], yN3[HfJetTagging::numTaggerIP];
  for (int tagger=0; tagger<HfJetTagging::numTaggerIP; tagger++) {
    for (int flavour=1; flavour<HfJetTagging::nFlavour+1; flavour++) {
      if (flavour!=2) continue; // only b-jet
      float effiN1= taggingutilities::getEfficiency(hsimjetNegLogJPN1[tagger][flavour][binJetPt], hsimjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN1 = taggingutilities::getPurity(hsimjetNegLogJPN1[tagger][flavour][binJetPt],hsimjetNegLogJPN1[tagger][0][binJetPt]);
      float effiN2= taggingutilities::getEfficiency(hsimjetNegLogJPN2[tagger][flavour][binJetPt], hsimjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN2 = taggingutilities::getPurity(hsimjetNegLogJPN2[tagger][flavour][binJetPt],hsimjetNegLogJPN2[tagger][0][binJetPt]);
      float effiN3= taggingutilities::getEfficiency(hsimjetNegLogJPN3[tagger][flavour][binJetPt], hsimjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN3 = taggingutilities::getPurity(hsimjetNegLogJPN3[tagger][flavour][binJetPt],hsimjetNegLogJPN3[tagger][0][binJetPt]);
      xN1[tagger] = effiN1;
      yN1[tagger] = purityN1;
      xN2[tagger] = effiN2;
      yN2[tagger] = purityN2;
      xN3[tagger] = effiN3;
      yN3[tagger] = purityN3;
      std::cout << "N1 tagger point: " << HfJetTagging::SYS::binsTaggerIP[tagger] << " effi: " << effiN1 << " purity: " << purityN1 << std::endl;
      std::cout << "N2 tagger point: " << HfJetTagging::SYS::binsTaggerIP[tagger] << " effi: " << effiN2 << " purity: " << purityN2 << std::endl;
      std::cout << "N3 tagger point: " << HfJetTagging::SYS::binsTaggerIP[tagger] << " effi: " << effiN3 << " purity: " << purityN3 << std::endl;
    }
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  auto gN1 = new TGraph(HfJetTagging::numTaggerIP, xN1, yN1);
  auto gN2 = new TGraph(HfJetTagging::numTaggerIP, xN2, yN2);
  auto gN3 = new TGraph(HfJetTagging::numTaggerIP, xN3, yN3);

  gN1->SetName("gN1");
  gN1->SetTitle("N1 tagger");
  gN1->SetMarkerStyle(21);
  gN1->SetDrawOption("AP");
  gN1->SetLineColor(2);
  gN1->SetLineWidth(4);
  gN1->SetFillStyle(0);
  gN1->GetXaxis()->SetRangeUser(0, 1);
  gN1->GetYaxis()->SetRangeUser(0, 0.2);
  gN1->GetXaxis()->SetNdivisions(510);  // 10 primary + 1 secondary per decade
  gN1->GetYaxis()->SetNdivisions(510);

  gN1->GetXaxis()->SetTitle("#epsilon");
  gN1->GetYaxis()->SetTitle("purity");

  gN2->SetName("gN2");
  gN2->SetTitle("N2 tagger");
  gN2->SetMarkerStyle(22);
  gN2->SetMarkerColor(3);
  gN2->SetDrawOption("P");
  gN2->SetLineColor(3);
  gN2->SetLineWidth(4);
  gN2->SetFillStyle(0);
  gN2->GetXaxis()->SetRangeUser(0, 1);
  gN2->GetYaxis()->SetRangeUser(0, 1);

  gN3->SetName("gN3");
  gN3->SetTitle("N3 tagger");
  gN3->SetMarkerStyle(23);
  gN3->SetLineColor(4);
  gN3->SetMarkerColor(4);
  gN3->SetLineWidth(4);
  gN3->SetFillStyle(0);
  gN3->GetXaxis()->SetRangeUser(0, 1);
  gN3->GetYaxis()->SetRangeUser(0, 1);

  //gN1->Draw("AC*");
//  TMultiGraph *mg = new TMultiGraph();
//  mg->Add(gN1);
//  mg->Add(gN2);
//  mg->Add(gN3);
//  mg->Draw("ALP");
  if (doLog) {
    gPad->SetLogx();
    gPad->SetLogy();
  }
  gN1->Draw("ALP");
  gN2->Draw("same LP");
  gN3->Draw("same LP");

  for (int i=0; i<HfJetTagging::numTaggerIP; i++) {
    latexNoNDC.DrawLatex(xN1[i]+0.005, yN1[i]+0.005, Form("%0.1f", HfJetTagging::SYS::binsTaggerIP[i]));
  }
  TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg->AddEntry(gN1, "N=1", "lp");
  leg->AddEntry(gN2, "N=2", "lp");
  leg->AddEntry(gN3, "N=3", "lp");
  leg->Draw();
  //gN2->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiAndPurityJPNx.pdf\")", nc++, dirSim.Data()));
}

#endif // HFJETTAGGINGSYSTAGGERANALYSIS_H
