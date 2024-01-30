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
        if(!LoadSimRadius(rootSimRadius)) {
          return;
        }
        InitHistogram();
        ProjectionHist();
        NormalizedHistogram();
      }
    }
    ~HfJetTaggingSysRadiusAnalysis();

    //// FUNCTION ////
    // int LoadDataRadius(TString rootFile);
    int LoadSimRadius(const std::vector<TString> &rootFiles);
    void InitHistogram();
    void ProjectionHist();
    void NormalizedHistogram();

    /// Draw ///
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, double legendxmin, double ymin, double xmax, double ymax);
    void DrawIncJetTrackPtRadius(bool doLog, int radius);
    void DrawCharmJetTrackPtRadius(bool doLog, int radius);
    void DrawBeautyJetTrackPtRadius(bool doLog, int radius);
    void DrawLfJetTrackPtRadius(bool doLog, int radius);
    void DrawIncJetSignImpXYSignificanceRadius(bool doLog, int radius);
    void DrawCharmJetSignImpXYSignificanceRadius(bool doLog, int radius);
    void DrawBeautyJetSignImpXYSignificanceRadius(bool doLog, int radius);
    void DrawLfJetSignImpXYSignificanceRadius(bool doLog, int radius);
    
    /// Histogram
    TH3F* h3simjetPtTrackPtFlavour[HfJetTagging::MaxRadius];
    TH3F* h3simjetPtSignImpXYSigFlavour[HfJetTagging::MaxRadius];
    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    TH1F* hsimjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::MaxRadius];
    
    //rangeRadius
  
  protected:
    CanvasHandler* canvasHandler;
    int canvasNum=0;

  private:

};

//int HfJetTaggingSysRadiusAnalysis::LoadDataRadius(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysRadiusAnalysis::LoadSimRadius(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-tc-charged";
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

void HfJetTaggingSysRadiusAnalysis::InitHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int radius =0; radius < HfJetTagging::MaxRadius; radius++) {
      hsimjetTrackPt[flavour][radius] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, radius), "", h3simjetPtTrackPtFlavour[radius]->GetNbinsY(), h3simjetPtTrackPtFlavour[radius]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[radius]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[radius]->GetNbinsY()));
      hsimjetSignImpXYSig[flavour][radius] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, radius), "", h3simjetPtSignImpXYSigFlavour[radius]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[radius]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[radius]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[radius]->GetNbinsY()));
    }
  }
}

void HfJetTaggingSysRadiusAnalysis::ProjectionHist() {
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

void HfJetTaggingSysRadiusAnalysis::NormalizedHistogram() {
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
void HfJetTaggingSysRadiusAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingSysRadiusAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, double xmin, double ymin, double xmax, double ymax) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  leg->Draw();
}

void HfJetTaggingSysRadiusAnalysis::DrawIncJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[0][radius], HfJetTagging::SYS::RADIUS[radius]}); // 0: inclusive
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/radius/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysRadiusAnalysis::DrawCharmJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[1][radius], HfJetTagging::SYS::RADIUS[radius]}); // 1: charm
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/cjet/radius/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysRadiusAnalysis::DrawBeautyJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[2][radius], HfJetTagging::SYS::RADIUS[radius]}); // 2: beauty
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/bjet/radius/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysRadiusAnalysis::DrawLfJetTrackPtRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[2][radius], HfJetTagging::SYS::RADIUS[radius]}); // 2: beauty
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/lfjet/radius/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysRadiusAnalysis::DrawIncJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[0][radius], HfJetTagging::SYS::RADIUS[radius]}); // 0: inclusive
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/radius/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysRadiusAnalysis::DrawCharmJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[1][radius], HfJetTagging::SYS::RADIUS[radius]}); // 1: charm
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/cjet/radius/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysRadiusAnalysis::DrawBeautyJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[2][radius], HfJetTagging::SYS::RADIUS[radius]}); // 2: beauty
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/bjet/radius/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysRadiusAnalysis::DrawLfJetSignImpXYSignificanceRadius(bool doLog = true, int Num = HfJetTagging::MaxRadius) {
  std::vector<HistogramData> NormHistList;
  for (int radius =0; radius<HfJetTagging::MaxRadius; radius++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[3][radius], HfJetTagging::SYS::RADIUS[radius]}); // 3: lf
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/lfjet/radius/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

#endif // HFJETTAGGINGSYSRADIUSANALYSIS_H
