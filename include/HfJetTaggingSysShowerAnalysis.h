#ifndef HFJETTAGGINGSYSSHOWERANALYSIS_H
#define HFJETTAGGINGSYSSHOWERANALYSIS_H

#include <iostream>
#include <vector>
#include "DataPoint.h"
#include <TH1F.h>
#include <TString.h>
#include <TSystem.h>


class HfJetTaggingSysShowerAnalysis : public HfJetTaggingSysAnalysis{
  public:
    HfJetTaggingSysShowerAnalysis(const std::vector<TString> &rootSimShower, bool doMC) : HfJetTaggingSysAnalysis(doMC){
      if (doMC) LoadSimShower(rootSimShower);
      // else LoadDataShower(rootSimShower.Data()); // TODO
      InitHistogram();
      ProjectionHist();
      CloneNormalizedHistogram();
      NormalizedHistogram();

    }
    ~HfJetTaggingSysShowerAnalysis();

    //// FUNCTION ////
    // int LoadDataShower(TString rootFile);
    int LoadSimShower(const std::vector<TString> &rootFiles);
    void InitHistogram();
    void ProjectionHist();
    void CloneNormalizedHistogram();
    void NormalizedHistogram();

    /// Draw ///
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
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    h3simjetPtTrackPtFlavour[shower] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
    h3simjetPtSignImpXYSigFlavour[shower] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_significance_xy_flavour", taskName.Data())));
    shower++;
  }
  return 0;
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
  int binsToFlavour[] = {1, 2, 3}; // 1: charm, 2: beauty, 3: light flavour
  int numBinsToFlavour = sizeof(binsToFlavour) / sizeof(binsToFlavour[0]);
  TH1F* projTrackPt[HfJetTagging::NumShower];
  TH1F* projSignImpXYSig[HfJetTagging::NumShower];
  for (int flavour=0; flavour<numBinsToFlavour; flavour++) {
    for (int shower=0; shower<HfJetTagging::NumShower; shower++) {
      int binZ = binsToFlavour[flavour];
      projTrackPt[shower] = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour[shower]->ProjectionY(Form("projTrackPt_%d_%d", binZ, shower), 1, h3simjetPtTrackPtFlavour[shower]->GetNbinsX(), binZ, binZ));
      projSignImpXYSig[shower] = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour[shower]->ProjectionY(Form("projSignImpXYSig_%d_%d", binZ, shower), 1, h3simjetPtSignImpXYSigFlavour[shower]->GetNbinsX(), binZ, binZ));
      
      // inclusive
      hsimjetTrackPt[0][shower]->Add(projTrackPt[shower]);
      hsimjetSignImpXYSig[0][shower]->Add(projSignImpXYSig[shower]);

      // jet flavour
      hsimjetTrackPt[flavour+1][shower] = reinterpret_cast<TH1F*>(projTrackPt[shower]->Clone());
      hsimjetSignImpXYSig[flavour+1][shower] = reinterpret_cast<TH1F*>(projSignImpXYSig[shower]->Clone());
    }
  }
}

void HfJetTaggingSysShowerAnalysis::CloneNormalizedHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int shower =0; shower < HfJetTagging::NumShower; shower++) {
      hsimjetNormalizedTrackPt[flavour][shower] = (TH1F*) hsimjetTrackPt[flavour][shower]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, shower));
      hsimjetNormalizedSignImpXYSig[flavour][shower] = (TH1F*) hsimjetSignImpXYSig[flavour][shower]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, shower));
    }
  }
}

void HfJetTaggingSysShowerAnalysis::NormalizedHistogram() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int shower =0; shower < HfJetTagging::NumShower; shower++) {
      hsimjetNormalizedTrackPt[flavour][shower]->Scale(1. / hsimjetNormalizedTrackPt[flavour][shower]->GetEntries());
      hsimjetNormalizedSignImpXYSig[flavour][shower]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][shower]->Integral());
    }
  }
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
  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawCharmJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[1][shower], HfJetTagging::SYS::SHOWER[shower]}); // 1: charm
  }
  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/cjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawBeautyJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }
  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/bjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawLfJetTrackPtShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }
  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/lfjet/shower/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysShowerAnalysis::DrawIncJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[0][shower], HfJetTagging::SYS::SHOWER[shower]}); // 0: inclusive
  }

  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawCharmJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[1][shower], HfJetTagging::SYS::SHOWER[shower]}); // 1: charm
  }

  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/cjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawBeautyJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[2][shower], HfJetTagging::SYS::SHOWER[shower]}); // 2: beauty
  }

  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/bjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysShowerAnalysis::DrawLfJetSignImpXYSignificanceShower(bool doLog = true, int Num = HfJetTagging::NumShower) {
  std::vector<HistogramData> NormHistList;
  for (int shower =0; shower<HfJetTagging::NumShower; shower++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[3][shower], HfJetTagging::SYS::SHOWER[shower]}); // 3: lf
  }

  canvasHandler = new CanvasHandler(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/lfjet/shower/SignImpXYSignificance.pdf\")", canvasNum - 1));
}

#endif // HFJETTAGGINGSYSSHOWERANALYSIS_H
















