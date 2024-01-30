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
        if(!LoadSimShower(rootSimShower)) {
          return;
        }
        InitHistogram();
        ProjectionHist();
        NormalizedHistogram();
      }
    }
    ~HfJetTaggingSysShowerAnalysis();

    //// FUNCTION ////
    // int LoadDataShower(TString rootFile);
    int LoadSimShower(const std::vector<TString> &rootFiles);
    void InitHistogram();
    void ProjectionHist();
    void NormalizedHistogram();

    /// Draw ///
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, double legendxmin, double ymin, double xmax, double ymax);
    void DrawIncJetTrackPtShower(bool doLog, int shower);
    void DrawCharmJetTrackPtShower(bool doLog, int shower);
    void DrawBeautyJetTrackPtShower(bool doLog, int shower);
    void DrawLfJetTrackPtShower(bool doLog, int shower);
    void DrawIncJetSignImpXYSignificanceShower(bool doLog, int shower);
    void DrawCharmJetSignImpXYSignificanceShower(bool doLog, int shower);
    void DrawBeautyJetSignImpXYSignificanceShower(bool doLog, int shower);
    void DrawLfJetSignImpXYSignificanceShower(bool doLog, int shower);
    
    /// Histogram
    TH3F* h3simjetPtTrackPtFlavour[HfJetTagging::NumShower];
    TH3F* h3simjetPtSignImpXYSigFlavour[HfJetTagging::NumShower];
    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    TH1F* hsimjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::NumShower];
    
  protected:
    CanvasHandler* canvasHandler;
    int canvasNum=0;

  private:

};

//int HfJetTaggingSysShowerAnalysis::LoadDataShower(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysShowerAnalysis::LoadSimShower(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-tc-charged";
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

void HfJetTaggingSysShowerAnalysis::InitHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int shower =0; shower < HfJetTagging::NumShower; shower++) {
      hsimjetTrackPt[flavour][shower] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, shower), "", h3simjetPtTrackPtFlavour[shower]->GetNbinsY(), h3simjetPtTrackPtFlavour[shower]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[shower]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[shower]->GetNbinsY()));
      hsimjetSignImpXYSig[flavour][shower] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, shower), "", h3simjetPtSignImpXYSigFlavour[shower]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[shower]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[shower]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[shower]->GetNbinsY()));
    }
  }
}

void HfJetTaggingSysShowerAnalysis::ProjectionHist() {
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

void HfJetTaggingSysShowerAnalysis::NormalizedHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int shower =0; shower < HfJetTagging::NumShower; shower++) {
      hsimjetNormalizedTrackPt[flavour][shower] = reinterpret_cast<TH1F*> (hsimjetTrackPt[flavour][shower]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, shower)));
      hsimjetNormalizedSignImpXYSig[flavour][shower] = reinterpret_cast<TH1F*> (hsimjetSignImpXYSig[flavour][shower]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, shower)));
      hsimjetNormalizedTrackPt[flavour][shower]->Scale(1. / hsimjetNormalizedTrackPt[flavour][shower]->GetEntries());
      hsimjetNormalizedSignImpXYSig[flavour][shower]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][shower]->Integral());
    }
  }
}

// Draw function
void HfJetTaggingSysShowerAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingSysShowerAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, double xmin, double ymin, double xmax, double ymax){
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

void HfJetTaggingSysShowerAnalysis::DrawIncJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[0][shower], HfJetTagging::SYS::SHOWER[shower]}); // 0: inclusive
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/shower/trackmomentum.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawCharmJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[1][shower], HfJetTagging::SYS::SHOWER[shower]}); // 1: charm
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/cjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawBeautyJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/bjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawLfJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/lfjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawIncJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[0][shower], HfJetTagging::SYS::SHOWER[shower]}); // 0: inclusive
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawCharmJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[1][shower], HfJetTagging::SYS::SHOWER[shower]}); // 1: charm
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/cjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawBeautyJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/bjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawLfJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[3][shower], HfJetTagging::SYS::SHOWER[shower]}); // 3: lf
  }

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/lfjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}
#endif // HFJETTAGGINGSYSSHOWERANALYSIS_H
