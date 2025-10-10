#ifndef HFJETTAGGINGSYSQUARKHADRONLEVEL_H
#define HFJETTAGGINGSYSQUARKHADRONLEVEL_H

#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

class HfJetTaggingSysQuarkHadronLevel : public HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysQuarkHadronLevelAnalysis() : HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysQuarkHadronLevelAnalysis();

    //// FUNCTION ////
    void initConfig();
    int loadSimQuarkHadronLevel(const std::vector<TString> &rootFiles);
    void initHistogramQuarkHadronLevel();
    void projectionHistQuarkHadronLevel();
    void normalizedHistogramQuarkHadronLevel();
    void saveHistogram(TString rootFile, bool doData, bool doMCD, bool doMCP);

    // Set

    // Get

    // Draw
    void drawEffiN1(bool doLog, int binJetPt);
    
  protected:
    TH3F* h2simjetPtFlavour[HfJetTagging::numQuarkHadronLevel];
    TH3F* h3simjetPtSignImpXYSigFlavourN1[HfJetTagging::numQuarkHadronLevel];
    TH3F* h3simjetPtSignImpXYSigFlavourN2[HfJetTagging::numQuarkHadronLevel];
    TH3F* h3simjetPtSignImpXYSigFlavourN3[HfJetTagging::numQuarkHadronLevel];

    TH1F* hsimjetPt[HfJetTagging::numQuarkHadronLevel][HfJetTagging::nFlavour+1];
    TH1F* hsimjetSignImpXYSigN1[HfJetTagging::numQuarkHadronLevel][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigN2[HfJetTagging::numQuarkHadronLevel][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigN3[HfJetTagging::numQuarkHadronLevel][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  private:
    TLatex latexNoNDC;
    TLatex latex;
    TString dirData;
    TString dirSim;
};

HfJetTaggingSysQuarkHadronLevelAnalysis::~HfJetTaggingSysQuarkHadronLevelAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysQuarkHadronLevelAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysQuarkHadronLevelAnalysis::initConfig() {
  //latex.SetNDC(); // Use normalized coordinates
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  TString nameAnalysis = "quarkHadronLevel";
  dirData = Form("fig/%s/data/%s/sys/%s", SOURCESET.Data(), DATASET.Data(), nameAnalysis.Data());
  dirSim = Form("fig/%s/sim/%s/sys/%s", SOURCESET.Data(), SIMSET.Data(), nameAnalysis.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSysQuarkHadronLevelAnalysis::loadSimQuarkHadronLevel(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxQuarkHadronLevel = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      std::cout << Form("%s ", rootFile.Data()) << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    
    h3simjetPtNegLogJPFlavour[maxQuarkHadronLevel] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
    maxQuarkHadronLevel++;
  }
  std::cout<<"MC loaded"<<std::endl;

  return 1;
}

void HfJetTaggingSysQuarkHadronLevelAnalysis::initHistogramQuarkHadronLevel() {
  for (int tagger =0; tagger < HfJetTagging::numQuarkHadronLevel; tagger++) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      if (tagger<1) {
        hsimJPEffiN1[flavour] = new TH1F(Form("hsimJPEffiN1_%d", flavour), "", 10, -0.25, 4.75);
        hsimJPEffiN2[flavour] = new TH1F(Form("hsimJPEffiN2_%d", flavour), "", 10, -0.25, 4.75);
        hsimJPEffiN3[flavour] = new TH1F(Form("hsimJPEffiN3_%d", flavour), "", 10, -0.25, 4.75);
        hsimJPPurityN1[flavour] = new TH1F(Form("hsimJPPurityN1_%d", flavour), "", 10, -0.25, 4.75);
        hsimJPPurityN2[flavour] = new TH1F(Form("hsimJPPurityN2_%d", flavour), "", 10, -0.25, 4.75);
        hsimJPPurityN3[flavour] = new TH1F(Form("hsimJPPurityN3_%d", flavour), "", 10, -0.25, 4.75);
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

void HfJetTaggingSysQuarkHadronLevelAnalysis::projectionHistQuarkHadronLevel() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  for (int tagger=0; tagger<HfJetTagging::numQuarkHadronLevel; tagger++) {
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

void HfJetTaggingSysQuarkHadronLevelAnalysis::normalizedHistogramQuarkHadronLevel() {
}

void HfJetTaggingSysQuarkHadronLevelAnalysis::saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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

void HfJetTaggingSysQuarkHadronLevelAnalysis::drawEffiN1(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numQuarkHadronLevel; tagger++) {
      float effiN1 = taggingutilities::getEfficiency(hsimjetNegLogJPN1[tagger][flavour][binJetPt],hsimjetNegLogJP[tagger][flavour][binJetPt]);
      if (effiN1 < 0) continue;
      hsimJPEffiN1[flavour]->SetBinContent(tagger+1, effiN1);
    }
    normHist.push_back({hsimJPEffiN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=1");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiJPN1.pdf\")", nc++, dirSim.Data()));
}

#endif // HFJETTAGGINGSYSQUARKHADRONLEVEL_H
