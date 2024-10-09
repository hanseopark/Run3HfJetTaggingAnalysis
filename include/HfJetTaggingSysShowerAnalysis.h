#ifndef HFJETTAGGINGSYSSHOWERANALYSIS_H
#define HFJETTAGGINGSYSSHOWERANALYSIS_H

#include <iostream>
#include <vector>
#include "CanvasHandler.h"
#include "DataPoint.h"
#include <TH1F.h>
#include <TString.h>
#include <TSystem.h>

class HfJetTaggingSysShowerAnalysis {
  public:
    HfJetTaggingSysShowerAnalysis(const std::vector<TString> &rootSimShower, bool doData, bool doMC, bool dopartLevel) {
      //if (doData) {
      //  LoadDataShower(rootSimShower.Data()); // TODO
      //}
      if (doMC) {
        if(!loadSimShower(rootSimShower)) {
          return;
        }
        initHistogram();
        projectionHist();
        normalizedHistogram();
      }
    }
    ~HfJetTaggingSysShowerAnalysis();

    //// FUNCTION ////
    // int LoadDataShower(TString rootFile);
    int loadSimShower(const std::vector<TString> &rootFiles);
    void initHistogram();
    void projectionHist();
    void normalizedHistogram();

    /// Draw ///
    void drawIncJetTrackPtShower(bool doLog, int shower);
    void drawCharmJetTrackPtShower(bool doLog, int shower);
    void drawBeautyJetTrackPtShower(bool doLog, int shower);
    void drawLfJetTrackPtShower(bool doLog, int shower);
    void drawIncJetSignImpXYSignificanceShower(bool doLog, int shower);
    void drawCharmJetSignImpXYSignificanceShower(bool doLog, int shower);
    void drawBeautyJetSignImpXYSignificanceShower(bool doLog, int shower);
    void drawLfJetSignImpXYSignificanceShower(bool doLog, int shower);
    
    /// Histogram
    TH3F* h3simjetPtTrackPtFlavour[HfJetTagging::NumShower];
    TH3F* h3simjetPtSignImpXYSigFlavour[HfJetTagging::NumShower];
    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    TH1F* hsimjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    
  protected:
    CanvasHandler* canHan;
    int cn=0;

  private:

};

//int HfJetTaggingSysShowerAnalysis::LoadDataShower(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysShowerAnalysis::loadSimShower(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int shower=0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (Shower MC) not found!" << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    h3simjetPtTrackPtFlavour[shower] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
    h3simjetPtSignImpXYSigFlavour[shower] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
    shower++;
  }
  return 1;
}

void HfJetTaggingSysShowerAnalysis::initHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int shower =0; shower < HfJetTagging::NumShower; shower++) {
      hsimjetTrackPt[flavour][shower] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, shower), "", h3simjetPtTrackPtFlavour[shower]->GetNbinsY(), h3simjetPtTrackPtFlavour[shower]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[shower]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[shower]->GetNbinsY()));
      hsimjetSignImpXYSig[flavour][shower] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, shower), "", h3simjetPtSignImpXYSigFlavour[shower]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[shower]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[shower]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[shower]->GetNbinsY()));
    }
  }
}

void HfJetTaggingSysShowerAnalysis::projectionHist() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projTrackPt[HfJetTagging::NumShower];
  TH1F* projSignImpXYSig[HfJetTagging::NumShower];
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int shower=0; shower<HfJetTagging::NumShower; shower++) {
      projTrackPt[shower] = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour[shower]->ProjectionY(Form("projTrackPt_%d_%d", binFlavour, shower), 1, h3simjetPtTrackPtFlavour[shower]->GetNbinsX(), binFlavour, binFlavour));
      projSignImpXYSig[shower] = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour[shower]->ProjectionY(Form("projSignImpXYSig_%d_%d", binFlavour, shower), 1, h3simjetPtSignImpXYSigFlavour[shower]->GetNbinsX(), binFlavour, binFlavour));
      
      // inclusive
      hsimjetTrackPt[0][shower]->Add(projTrackPt[shower]);
      hsimjetSignImpXYSig[0][shower]->Add(projSignImpXYSig[shower]);

      // jet flavour
      hsimjetTrackPt[flavour][shower] = reinterpret_cast<TH1F*>(projTrackPt[shower]->Clone());
      hsimjetSignImpXYSig[flavour][shower] = reinterpret_cast<TH1F*>(projSignImpXYSig[shower]->Clone());
    }
  }
}

void HfJetTaggingSysShowerAnalysis::normalizedHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int shower =0; shower < HfJetTagging::NumShower; shower++) {
      hsimjetNormalizedTrackPt[flavour][shower] = reinterpret_cast<TH1F*> (hsimjetTrackPt[flavour][shower]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, shower)));
      hsimjetNormalizedSignImpXYSig[flavour][shower] = reinterpret_cast<TH1F*> (hsimjetSignImpXYSig[flavour][shower]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, shower)));
      hsimjetNormalizedTrackPt[flavour][shower]->Scale(1. / hsimjetNormalizedTrackPt[flavour][shower]->GetEntries());
      hsimjetNormalizedSignImpXYSig[flavour][shower]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][shower]->Integral());
    }
  }
}

void HfJetTaggingSysShowerAnalysis::drawIncJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[0][shower], HfJetTagging::SYS::SHOWER[shower]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/shower/trackmomentum.pdf\")", cn++));
}

void HfJetTaggingSysShowerAnalysis::drawCharmJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[1][shower], HfJetTagging::SYS::SHOWER[shower]}); // 1: charm
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/shower/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysShowerAnalysis::drawBeautyJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/shower/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysShowerAnalysis::drawLfJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/shower/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysShowerAnalysis::drawIncJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[0][shower], HfJetTagging::SYS::SHOWER[shower]}); // 0: inclusive
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/shower/SignImpXYSignificance.pdf\")", cn));
}

void HfJetTaggingSysShowerAnalysis::drawCharmJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[1][shower], HfJetTagging::SYS::SHOWER[shower]}); // 1: charm
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/shower/SignImpXYSignificance.pdf\")", cn++));
}

void HfJetTaggingSysShowerAnalysis::drawBeautyJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/shower/SignImpXYSignificance.pdf\")", cn));
}

void HfJetTaggingSysShowerAnalysis::drawLfJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> normHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[3][shower], HfJetTagging::SYS::SHOWER[shower]}); // 3: lf
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/shower/SignImpXYSignificance.pdf\")", cn++));
}
#endif // HFJETTAGGINGSYSSHOWERANALYSIS_H
