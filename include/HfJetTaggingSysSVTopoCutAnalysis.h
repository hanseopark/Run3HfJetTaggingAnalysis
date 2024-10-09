#ifndef HFJETTAGGINGSYSTAGGERANALYSIS_H
#define HFJETTAGGINGSYSTAGGERANALYSIS_H


#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

class HfJetTaggingSysSVTopoCutAnalysis : public HfJetTaggingSysAnalysis{
  public:
    HfJetTaggingSysSVTopoCutAnalysis() : HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysSVTopoCutAnalysis();

    //// FUNCTION ////
    void initConfig();
    int loadSimSVTopoCut(const std::vector<TString> &rootFiles);
    void initHistogramSVTopoCut();
    void projectionHistSVTopoCut();
    void normalizedHistogramSVTopoCut();
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
    void drawGraphEffiAndPurity(bool doLog, int binJetPt);
    
  protected:
    TH3F* h3simTagjetPtJPFlavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtNegLogJPFlavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtJPN1Flavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtNegLogJPN1Flavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtJPN2Flavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtNegLogJPN2Flavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtJPN3Flavour[HfJetTagging::numSVTopoCut];
    TH3F* h3simTagjetPtNegLogJPN3Flavour[HfJetTagging::numSVTopoCut];

    TH1F* hsimTagjetJP[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJP[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN1[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN1[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN2[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN2[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN3[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN3[HfJetTagging::numSVTopoCut][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimJPEffiN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN3[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN1[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN2[HfJetTagging::nFlavour+1];
    TH1F* hsimJPPurityN3[HfJetTagging::nFlavour+1];

  private:
    TLatex latexNoNDC;
    TLatex latex;
    TString dirData;
    TString dirSim;
};

HfJetTaggingSysSVTopoCutAnalysis::~HfJetTaggingSysSVTopoCutAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysSVTopoCutAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysSVTopoCutAnalysis::initConfig() {
  //latex.SetNDC(); // Use normalized coordinates
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  dirData = Form("fig/%s/data/%s/sys/tagger", SOURCESET.Data(), DATASET.Data());
  dirSim = Form("fig/%s/sim/%s/sys/tagger", SOURCESET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSysSVTopoCutAnalysis::loadSimSVTopoCut(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxSVTopoCut = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      std::cout << Form("%s ", rootFile.Data()) << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    
    h3simTagjetPtNegLogJPFlavour[maxSVTopoCut] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN1Flavour[maxSVTopoCut] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N1_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN2Flavour[maxSVTopoCut] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N2_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN3Flavour[maxSVTopoCut] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N3_flavour", taskName.Data())));
    maxSVTopoCut++;
  }
  std::cout<<"MC loaded"<<std::endl;

  return 1;
}

void HfJetTaggingSysSVTopoCutAnalysis::initHistogramSVTopoCut() {
  for (int tagger =0; tagger < HfJetTagging::numSVTopoCut; tagger++) {
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
        hsimTagjetNegLogJP[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJP_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPFlavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPFlavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPFlavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPFlavour[tagger]->GetNbinsY()));
        hsimTagjetNegLogJPN1[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPN1Flavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPN1Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN1Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN1Flavour[tagger]->GetNbinsY()));
        hsimTagjetNegLogJPN2[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPN2Flavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPN2Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN2Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN2Flavour[tagger]->GetNbinsY()));
        hsimTagjetNegLogJPN3[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPN3Flavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPN3Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN3Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN3Flavour[tagger]->GetNbinsY()));
      }
    }
  }
}

void HfJetTaggingSysSVTopoCutAnalysis::projectionHistSVTopoCut() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
		  TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour[tagger]->ProjectionY(Form("projNegLogJP_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPFlavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN1Flavour[tagger]->ProjectionY(Form("projNegLogJPN1_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPN1Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN2Flavour[tagger]->ProjectionY(Form("projNegLogJPN2_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPN2Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN3Flavour[tagger]->ProjectionY(Form("projNegLogJPN3_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPN3Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));

		  hsimTagjetNegLogJP[tagger][0][0]->Add(projNegLogJP);
		  hsimTagjetNegLogJP[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_%d_0", tagger, flavour)));
		  hsimTagjetNegLogJPN1[tagger][0][0]->Add(projNegLogJPN1);
		  hsimTagjetNegLogJPN1[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone(Form("hsimTagjetNegLogJPN1_%d_%d_0", tagger, flavour)));
		  hsimTagjetNegLogJPN2[tagger][0][0]->Add(projNegLogJPN2);
		  hsimTagjetNegLogJPN2[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone(Form("hsimTagjetNegLogJPN2_%d_%d_0", tagger, flavour)));
		  hsimTagjetNegLogJPN3[tagger][0][0]->Add(projNegLogJPN3);
		  hsimTagjetNegLogJPN3[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone(Form("hsimTagjetNegLogJPN3_%d_%d_0", tagger, flavour)));
      delete projNegLogJP;
      delete projNegLogJPN1;
      delete projNegLogJPN2;
      delete projNegLogJPN3;
      for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        int leftbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJP_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, binFlavour, binFlavour));
        hsimTagjetNegLogJP[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJP[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJP);

        int leftbinJetPtNegLogJPN1 = h3simTagjetPtNegLogJPN1Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN1 = h3simTagjetPtNegLogJPN1Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN1Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1, binFlavour, binFlavour));
        hsimTagjetNegLogJPN1[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hsimTagjetNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJPN1[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN1);

        int leftbinJetPtNegLogJPN2 = h3simTagjetPtNegLogJPN2Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN2 = h3simTagjetPtNegLogJPN2Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN2Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2, binFlavour, binFlavour));
        hsimTagjetNegLogJPN2[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hsimTagjetNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJPN2[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN2);

        int leftbinJetPtNegLogJPN3 = h3simTagjetPtNegLogJPN3Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN3 = h3simTagjetPtNegLogJPN3Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN3Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3, binFlavour, binFlavour));
        hsimTagjetNegLogJPN3[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hsimTagjetNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJPN3[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN3);

        delete projJetPtRangeNegLogJP;
        delete projJetPtRangeNegLogJPN1;
        delete projJetPtRangeNegLogJPN2;
        delete projJetPtRangeNegLogJPN3;
      }
    }
  }
}

void HfJetTaggingSysSVTopoCutAnalysis::normalizedHistogramSVTopoCut() {
}

void HfJetTaggingSysSVTopoCutAnalysis::saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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

void HfJetTaggingSysSVTopoCutAnalysis::drawEffiN1(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
      float effiN1 = taggingutilities::getEfficiency(hsimTagjetNegLogJPN1[tagger][flavour][binJetPt],hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
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

void HfJetTaggingSysSVTopoCutAnalysis::drawEffiN2(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
      float effiN2 = taggingutilities::getEfficiency(hsimTagjetNegLogJPN2[tagger][flavour][binJetPt],hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      if (effiN2 < 0) continue;
      hsimJPEffiN2[flavour]->SetBinContent(tagger+1, effiN2);
    }
    normHist.push_back({hsimJPEffiN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=2");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiJPN2.pdf\")", nc++, dirSim.Data()));
}
void HfJetTaggingSysSVTopoCutAnalysis::drawEffiN3(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
      float effiN3 = taggingutilities::getEfficiency(hsimTagjetNegLogJPN3[tagger][flavour][binJetPt],hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      if (effiN3 < 0) continue;
      hsimJPEffiN3[flavour]->SetBinContent(tagger+1, effiN3);
    }
    normHist.push_back({hsimJPEffiN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=3");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiJPN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysSVTopoCutAnalysis::drawEffiNx(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimJPEffiN1[2], "N=1"});
  normHist.push_back({hsimJPEffiN3[2], "N=3"});
  normHist.push_back({hsimJPEffiN2[2], "N=2"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/EffiJPNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysSVTopoCutAnalysis::drawPurityN1(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
      float purityN1 = taggingutilities::getPurity(hsimTagjetNegLogJPN1[tagger][flavour][binJetPt],hsimTagjetNegLogJPN1[tagger][0][binJetPt]);
      hsimJPPurityN1[flavour]->SetBinContent(tagger+1, purityN1);
    }
    normHist.push_back({hsimJPPurityN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "Purity");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=3");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/purityN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysSVTopoCutAnalysis::drawPurityN2(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
      float purityN2 = taggingutilities::getPurity(hsimTagjetNegLogJPN2[tagger][flavour][binJetPt],hsimTagjetNegLogJPN2[tagger][0][binJetPt]);
      hsimJPPurityN2[flavour]->SetBinContent(tagger+1, purityN2);
    }
    normHist.push_back({hsimJPPurityN2[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "Purity");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=3");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/purityN2.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysSVTopoCutAnalysis::drawPurityN3(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
      float purityN3 = taggingutilities::getPurity(hsimTagjetNegLogJPN3[tagger][flavour][binJetPt],hsimTagjetNegLogJPN3[tagger][0][binJetPt]);
      hsimJPPurityN3[flavour]->SetBinContent(tagger+1, purityN3);
    }
    normHist.push_back({hsimJPPurityN3[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "Purity");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.7, 0.9-0.00, "N=3");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/purityN3.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysSVTopoCutAnalysis::drawPurityNx(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimJPPurityN1[2], "N=1"});
  normHist.push_back({hsimJPPurityN3[2], "N=3"});
  normHist.push_back({hsimJPPurityN2[2], "N=2"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, -0.25, 4.75, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (#it{S}_{xy})", "#epsilon");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/purityNx.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysSVTopoCutAnalysis::drawGraphEffiAndPurity(bool doLog, int binJetPt) {
  float xN1[HfJetTagging::numSVTopoCut], yN1[HfJetTagging::numSVTopoCut];
  float xN2[HfJetTagging::numSVTopoCut], yN2[HfJetTagging::numSVTopoCut];
  float xN3[HfJetTagging::numSVTopoCut], yN3[HfJetTagging::numSVTopoCut];
  for (int tagger=0; tagger<HfJetTagging::numSVTopoCut; tagger++) {
    for (int flavour=1; flavour<HfJetTagging::nFlavour+1; flavour++) {
      if (flavour!=2) continue; // only b-jet
      float effiN1= taggingutilities::getEfficiency(hsimTagjetNegLogJPN1[tagger][flavour][binJetPt], hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN1 = taggingutilities::getPurity(hsimTagjetNegLogJPN1[tagger][flavour][binJetPt],hsimTagjetNegLogJPN1[tagger][0][binJetPt]);
      float effiN2= taggingutilities::getEfficiency(hsimTagjetNegLogJPN2[tagger][flavour][binJetPt], hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN2 = taggingutilities::getPurity(hsimTagjetNegLogJPN2[tagger][flavour][binJetPt],hsimTagjetNegLogJPN2[tagger][0][binJetPt]);
      float effiN3= taggingutilities::getEfficiency(hsimTagjetNegLogJPN3[tagger][flavour][binJetPt], hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN3 = taggingutilities::getPurity(hsimTagjetNegLogJPN3[tagger][flavour][binJetPt],hsimTagjetNegLogJPN3[tagger][0][binJetPt]);
      xN1[tagger] = effiN1;
      yN1[tagger] = purityN1;
      xN2[tagger] = effiN2;
      yN2[tagger] = purityN2;
      xN3[tagger] = effiN3;
      yN3[tagger] = purityN3;
      std::cout << "N1 tagger point: " << HfJetTagging::SYS::binsSVTopoCut[tagger] << " effi: " << effiN1 << " purity: " << purityN1 << std::endl;
      std::cout << "N2 tagger point: " << HfJetTagging::SYS::binsSVTopoCut[tagger] << " effi: " << effiN2 << " purity: " << purityN2 << std::endl;
      std::cout << "N3 tagger point: " << HfJetTagging::SYS::binsSVTopoCut[tagger] << " effi: " << effiN3 << " purity: " << purityN3 << std::endl;
    }
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  auto gN1 = new TGraph(HfJetTagging::numSVTopoCut, xN1, yN1);
  auto gN2 = new TGraph(HfJetTagging::numSVTopoCut, xN2, yN2);
  auto gN3 = new TGraph(HfJetTagging::numSVTopoCut, xN3, yN3);

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

  for (int i=0; i<HfJetTagging::numSVTopoCut; i++) {
    latexNoNDC.DrawLatex(xN1[i]+0.005, yN1[i]+0.005, Form("%0.1f", HfJetTagging::SYS::binsSVTopoCut[i]));
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
