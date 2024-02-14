#ifndef HFJETTAGGINGSYSTRACKSELECTION_H
#define HFJETTAGGINGSYSTRACKSELECTION_H

#include <TH1F.h>
#include <TString.h>
#include "CanvasHandler.h"
#include "DataPoint.h"

class HfJetTaggingSysTrackSelectionAnalysis {
  public:
    HfJetTaggingSysTrackSelectionAnalysis(const std::vector<TString> &rootSim, bool doData, bool doMC, bool dopartLevel) {
///      if (doData) {
///        LoadData(rootSim);
///      }
      if (doMC) {
        if(!LoadSimTS(rootSim)) {
          return;
        }
        InitHistogramTS();
        ProjectionHistTS();
        NormalizedHistogramTS();
      }

    }
    ~HfJetTaggingSysTrackSelectionAnalysis();

    //// FUNCTION ////
    int LoadSimTS(const std::vector<TString> &rootFiles);
    void InitHistogramTS();
    void ProjectionHistTS();
    void NormalizedHistogramTS();

    // fucntion
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);
    void DrawIncJetTrackPtTrackSelection(bool doLog, int radius);

    TH3F* h3simjetPtTrackPtFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3simjetPtSignImpXYSigFlavour[HfJetTagging::numTrackSelection];
    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];

  protected:
    CanvasHandler* canvasHandler;
    int canvasNum=0;

  private:

};

HfJetTaggingSysTrackSelectionAnalysis::~HfJetTaggingSysTrackSelectionAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysTrackSelectionAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysTrackSelectionAnalysis::LoadSimTS(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxTrackSelection = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    h3simjetPtTrackPtFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
    h3simjetPtSignImpXYSigFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
    maxTrackSelection++;
  }

  return 1;
}

void HfJetTaggingSysTrackSelectionAnalysis::InitHistogramTS() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
      hsimjetTrackPt[flavour][ts] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, ts), "", h3simjetPtTrackPtFlavour[ts]->GetNbinsY(), h3simjetPtTrackPtFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[ts]->GetNbinsY()));
      hsimjetSignImpXYSig[flavour][ts] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, ts), "", h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsY()));

    }
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::ProjectionHistTS() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projTrackPt[HfJetTagging::numTrackSelection];
  TH1F* projSignImpXYSig[HfJetTagging::numTrackSelection];
  for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int ts=0; ts<HfJetTagging::numTrackSelection; ts++) {
      projTrackPt[ts] = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour[ts]->ProjectionY(Form("projTrackPt_%d_%d", binFlavour, ts), 1, h3simjetPtTrackPtFlavour[ts]->GetNbinsX(), binFlavour, binFlavour));
      projSignImpXYSig[ts] = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour[ts]->ProjectionY(Form("projSignImpXYSig_%d_%d", binFlavour, ts), 1, h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsX(), binFlavour, binFlavour));
      
      // inclusive
      hsimjetTrackPt[0][ts]->Add(projTrackPt[ts]);
      hsimjetSignImpXYSig[0][ts]->Add(projSignImpXYSig[ts]);

      // jet flavour
      hsimjetTrackPt[flavour][ts] = reinterpret_cast<TH1F*>(projTrackPt[ts]->Clone());
      hsimjetSignImpXYSig[flavour][ts] = reinterpret_cast<TH1F*>(projSignImpXYSig[ts]->Clone());
    }

  }
}

void HfJetTaggingSysTrackSelectionAnalysis::NormalizedHistogramTS() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
      hsimjetNormalizedTrackPt[flavour][ts] = (TH1F*) hsimjetTrackPt[flavour][ts]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, ts));
      hsimjetNormalizedSignImpXYSig[flavour][ts] = (TH1F*) hsimjetSignImpXYSig[flavour][ts]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, ts));

      hsimjetNormalizedTrackPt[flavour][ts]->Scale(1. / hsimjetNormalizedTrackPt[flavour][ts]->GetEntries());
      hsimjetNormalizedSignImpXYSig[flavour][ts]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][ts]->GetEntries());
    }
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingSysTrackSelectionAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if(doLeg) leg->Draw();
}

void HfJetTaggingSysTrackSelectionAnalysis::DrawIncJetTrackPtTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedTrackPt[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/incjet/trackselection/trackmomentum.pdf\")", canvasNum - 1));

}

#endif // HFJETTAGGINGSYSTRACKSELECTIONANALYSIS_H
