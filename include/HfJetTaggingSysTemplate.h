#ifndef HFJETTAGGINGSYSTEMPLATE_H
#define HFJETTAGGINGSYSTEMPLATE_H

#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

/*
To change Template to "analysis"

*/

class HfJetTaggingSysTemplate : public HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysTemplateAnalysis() : HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysTemplateAnalysis();

    //// FUNCTION ////
    void initConfig();
    int loadSimTemplate(const std::vector<TString> &rootFiles);
    void initHistogramTemplate();
    void projectionHistTemplate();
    void normalizedHistogramTemplate();
    void saveHistogram(TString rootFile, bool doData, bool doMCD, bool doMCP);

    // Set

    // Get

    // Draw
    void drawEffiN1(bool doLog, int binJetPt);
    
  protected:
    TH3F* h3simTagjetPtJPFlavour[HfJetTagging::numTemplate];

    TH1F* hsimTagjetJP[HfJetTagging::numTemplate][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  private:
    TLatex latexNoNDC;
    TLatex latex;
    TString dirData;
    TString dirSim;
};

HfJetTaggingSysTemplateAnalysis::~HfJetTaggingSysTemplateAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysTemplateAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysTemplateAnalysis::initConfig() {
  //latex.SetNDC(); // Use normalized coordinates
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  TString nameAnalysis = "Template";
  dirData = Form("fig/%s/data/%s/sys/%s", SOURCESET.Data(), DATASET.Data(), nameAnalysis.Data());
  dirSim = Form("fig/%s/sim/%s/sys/%s", SOURCESET.Data(), SIMSET.Data(), nameAnalysis.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSysTemplateAnalysis::loadSimTemplate(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxTemplate = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      std::cout << Form("%s ", rootFile.Data()) << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    
    h3simTagjetPtNegLogJPFlavour[maxTemplate] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN1Flavour[maxTemplate] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N1_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN2Flavour[maxTemplate] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N2_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN3Flavour[maxTemplate] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N3_flavour", taskName.Data())));
    maxTemplate++;
  }
  std::cout<<"MC loaded"<<std::endl;

  return 1;
}

void HfJetTaggingSysTemplateAnalysis::initHistogramTemplate() {
  for (int tagger =0; tagger < HfJetTagging::numTemplate; tagger++) {
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

void HfJetTaggingSysTemplateAnalysis::projectionHistTemplate() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  for (int tagger=0; tagger<HfJetTagging::numTemplate; tagger++) {
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

void HfJetTaggingSysTemplateAnalysis::normalizedHistogramTemplate() {
}

void HfJetTaggingSysTemplateAnalysis::saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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

void HfJetTaggingSysTemplateAnalysis::drawEffiN1(bool doLog, int binJetPt) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int tagger=0; tagger<HfJetTagging::numTemplate; tagger++) {
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

#endif // HFJETTAGGINGSYSTEMPLATE_H
