#ifndef HFJETTAGGINGSYSRADIUSANALYSIS_H
#define HFJETTAGGINGSYSRADIUSANALYSIS_H

#include <iostream>
#include <vector>
#include "CanvasHandler.h"
#include "DataPoint.h"
#include <TH1F.h>
#include <TString.h>
#include <TSystem.h>


class HfJetTaggingSysRadiusAnalysis {
  public:
    HfJetTaggingSysRadiusAnalysis(const std::vector<TString> &rootSimRadius, bool doData, bool doMC, bool dopartLevel) {
//      if (doData) {
//        LoadDataRadius(rootSimRadius);
//      }
      if (doMC) {
        if(!loadSimRadius(rootSimRadius)) {
          return;
        }
        initHistogram();
        //projectionHist();
        //normalizedHistogram();
      }
    }
    ~HfJetTaggingSysRadiusAnalysis();

    //// FUNCTION ////
    // int LoadDataRadius(TString rootFile);
    int loadSimRadius(const std::vector<TString> &rootFiles);
    void initHistogram();
    void projectionHist();
    void normalizedHistogram();

    /// Draw ///
    void drawIncJetTrackPtRadius(bool doLog, int radius);
    void drawCharmJetTrackPtRadius(bool doLog, int radius);
    void drawBeautyJetTrackPtRadius(bool doLog, int radius);
    void drawLfJetTrackPtRadius(bool doLog, int radius);
    void drawIncJetSignImpXYSignificanceRadius(bool doLog, int radius);
    void drawCharmJetSignImpXYSignificanceRadius(bool doLog, int radius);
    void drawBeautyJetSignImpXYSignificanceRadius(bool doLog, int radius);
    void drawLfJetSignImpXYSignificanceRadius(bool doLog, int radius);
    
    /// Histogram
    TH3F* h3simjetPtTrackPtFlavour[HfJetTagging::MaxRadius];
    TH3F* h3simjetPtSignImpXYSigFlavour[HfJetTagging::MaxRadius];
    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    TH1F* hsimjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    
    //rangeRadius
  
  protected:
    CanvasHandler* canHan;
    int cn=0;

  private:

};

//int HfJetTaggingSysRadiusAnalysis::LoadDataRadius(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysRadiusAnalysis::loadSimRadius(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxRadius=0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (Radius MC) not found!" << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    h3simjetPtTrackPtFlavour[maxRadius] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
    h3simjetPtSignImpXYSigFlavour[maxRadius] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
    maxRadius++;
  }
  return 1;
}

void HfJetTaggingSysRadiusAnalysis::initHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int radius =0; radius < HfJetTagging::MaxRadius; radius++) {
      hsimjetTrackPt[flavour][radius] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, radius), "", h3simjetPtTrackPtFlavour[radius]->GetNbinsY(), h3simjetPtTrackPtFlavour[radius]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[radius]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[radius]->GetNbinsY()));
      hsimjetSignImpXYSig[flavour][radius] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, radius), "", h3simjetPtSignImpXYSigFlavour[radius]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[radius]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[radius]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[radius]->GetNbinsY()));
    }
  }
}

void HfJetTaggingSysRadiusAnalysis::projectionHist() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projTrackPt[HfJetTagging::MaxRadius];
  TH1F* projSignImpXYSig[HfJetTagging::MaxRadius];
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int radius=0; radius<HfJetTagging::MaxRadius; radius++) {
      projTrackPt[radius] = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour[radius]->ProjectionY(Form("projTrackPt_%d_%d", binFlavour, radius), 1, h3simjetPtTrackPtFlavour[radius]->GetNbinsX(), binFlavour, binFlavour));
      projSignImpXYSig[radius] = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour[radius]->ProjectionY(Form("projSignImpXYSig_%d_%d", binFlavour, radius), 1, h3simjetPtSignImpXYSigFlavour[radius]->GetNbinsX(), binFlavour, binFlavour));
      
      // inclusive
      hsimjetTrackPt[0][radius]->Add(projTrackPt[radius]);
      hsimjetSignImpXYSig[0][radius]->Add(projSignImpXYSig[radius]);

      // jet flavour
      hsimjetTrackPt[flavour][radius] = reinterpret_cast<TH1F*>(projTrackPt[radius]->Clone());
      hsimjetSignImpXYSig[flavour][radius] = reinterpret_cast<TH1F*>(projSignImpXYSig[radius]->Clone());
    }

  }
}

void HfJetTaggingSysRadiusAnalysis::normalizedHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int radius =0; radius < HfJetTagging::MaxRadius; radius++) {
      hsimjetNormalizedTrackPt[flavour][radius] = (TH1F*) hsimjetTrackPt[flavour][radius]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, radius));
      hsimjetNormalizedSignImpXYSig[flavour][radius] = (TH1F*) hsimjetSignImpXYSig[flavour][radius]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, radius));
      hsimjetNormalizedTrackPt[flavour][radius]->Scale(1. / hsimjetNormalizedTrackPt[flavour][radius]->GetEntries());
      hsimjetNormalizedSignImpXYSig[flavour][radius]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][radius]->Integral());
    }
  }
}

// Draw function
void HfJetTaggingSysRadiusAnalysis::drawIncJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[0][radius], HfJetTagging::SYS::RADIUS[radius]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/radius/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysRadiusAnalysis::drawCharmJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[1][radius], HfJetTagging::SYS::RADIUS[radius]}); // 1: charm
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/radius/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysRadiusAnalysis::drawBeautyJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[2][radius], HfJetTagging::SYS::RADIUS[radius]}); // 2: beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/radius/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysRadiusAnalysis::drawLfJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[2][radius], HfJetTagging::SYS::RADIUS[radius]}); // 2: beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/radius/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysRadiusAnalysis::drawIncJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[0][radius], HfJetTagging::SYS::RADIUS[radius]}); // 0: inclusive
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/radius/SignImpXYSignificance.pdf\")", cn++));
}

void HfJetTaggingSysRadiusAnalysis::drawCharmJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[1][radius], HfJetTagging::SYS::RADIUS[radius]}); // 1: charm
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/radius/SignImpXYSignificance.pdf\")", cn++));
}

void HfJetTaggingSysRadiusAnalysis::drawBeautyJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[2][radius], HfJetTagging::SYS::RADIUS[radius]}); // 2: beauty
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/radius/SignImpXYSignificance.pdf\")", cn++));
}

void HfJetTaggingSysRadiusAnalysis::drawLfJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> normHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[3][radius], HfJetTagging::SYS::RADIUS[radius]}); // 3: lf
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/radius/SignImpXYSignificance.pdf\")", cn++));
}

#endif // HFJETTAGGINGSYSRADIUSANALYSIS_H
