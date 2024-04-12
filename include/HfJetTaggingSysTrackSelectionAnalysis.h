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
    void DrawIncJetTrackPtTrackSelection(bool doLog, int numts);
    void DrawIncJetTrackEtaTrackSelection(bool doLog, int numts);
    void DrawIncJetTrackPhiTrackSelection(bool doLog, int numts);
    void DrawIncJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void DrawCharmJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void DrawBeautyJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void DrawLfJetSignImpXYSigTrackSelection(bool doLog, int numts);

    TH3F* h3datajetPtTrackPtFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3datajetPtTrackEtaFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3datajetPtTrackPhiFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3datajetPtSignImpXYSigFlavour[HfJetTagging::numTrackSelection];

    TH3F* h3simjetPtTrackPtFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3simjetPtTrackEtaFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3simjetPtTrackPhiFlavour[HfJetTagging::numTrackSelection];
    TH3F* h3simjetPtSignImpXYSigFlavour[HfJetTagging::numTrackSelection];

    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetNormalizedTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
    TH1F* hsimjetNormalizedTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::numTrackSelection];
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
    h3simjetPtTrackEtaFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskName.Data())));
    h3simjetPtTrackPhiFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskName.Data())));
    h3simjetPtSignImpXYSigFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
    maxTrackSelection++;
  }

  return 1;
}

void HfJetTaggingSysTrackSelectionAnalysis::InitHistogramTS() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
      hsimjetTrackPt[flavour][ts] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, ts), "", h3simjetPtTrackPtFlavour[ts]->GetNbinsY(), h3simjetPtTrackPtFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[ts]->GetNbinsY()));
      hsimjetTrackEta[flavour][ts] = new TH1F(Form("hsimjetTrackEta_%d_%d", flavour, ts), "", h3simjetPtTrackEtaFlavour[ts]->GetNbinsY(), h3simjetPtTrackEtaFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackEtaFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackEtaFlavour[ts]->GetNbinsY()));
      hsimjetTrackPhi[flavour][ts] = new TH1F(Form("hsimjetTrackPhi_%d_%d", flavour, ts), "", h3simjetPtTrackPhiFlavour[ts]->GetNbinsY(), h3simjetPtTrackPhiFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPhiFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPhiFlavour[ts]->GetNbinsY()));
      hsimjetSignImpXYSig[flavour][ts] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, ts), "", h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsY()));

    }
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::ProjectionHistTS() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projTrackPt[HfJetTagging::numTrackSelection];
  TH1F* projTrackEta[HfJetTagging::numTrackSelection];
  TH1F* projTrackPhi[HfJetTagging::numTrackSelection];
  TH1F* projSignImpXYSig[HfJetTagging::numTrackSelection];
  for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int ts=0; ts<HfJetTagging::numTrackSelection; ts++) {
      projTrackPt[ts] = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour[ts]->ProjectionY(Form("projTrackPt_%d_%d", binFlavour, ts), 1, h3simjetPtTrackPtFlavour[ts]->GetNbinsX(), binFlavour, binFlavour));
      projTrackEta[ts] = reinterpret_cast<TH1F*> (h3simjetPtTrackEtaFlavour[ts]->ProjectionY(Form("projTrackEta_%d_%d", binFlavour, ts), 1, h3simjetPtTrackEtaFlavour[ts]->GetNbinsX(), binFlavour, binFlavour));
      projTrackPhi[ts] = reinterpret_cast<TH1F*> (h3simjetPtTrackPhiFlavour[ts]->ProjectionY(Form("projTrackPhi_%d_%d", binFlavour, ts), 1, h3simjetPtTrackPhiFlavour[ts]->GetNbinsX(), binFlavour, binFlavour));
      projSignImpXYSig[ts] = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour[ts]->ProjectionY(Form("projSignImpXYSig_%d_%d", binFlavour, ts), 1, h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsX(), binFlavour, binFlavour));
      
      // inclusive
      hsimjetTrackPt[0][ts]->Add(projTrackPt[ts]);
      hsimjetTrackEta[0][ts]->Add(projTrackEta[ts]);
      hsimjetTrackPhi[0][ts]->Add(projTrackPhi[ts]);
      hsimjetSignImpXYSig[0][ts]->Add(projSignImpXYSig[ts]);

      // jet flavour
      hsimjetTrackPt[flavour][ts] = reinterpret_cast<TH1F*>(projTrackPt[ts]->Clone());
      hsimjetTrackEta[flavour][ts] = reinterpret_cast<TH1F*>(projTrackEta[ts]->Clone());
      hsimjetTrackPhi[flavour][ts] = reinterpret_cast<TH1F*>(projTrackPhi[ts]->Clone());
      hsimjetSignImpXYSig[flavour][ts] = reinterpret_cast<TH1F*>(projSignImpXYSig[ts]->Clone());
    }

  }
}

void HfJetTaggingSysTrackSelectionAnalysis::NormalizedHistogramTS() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
      hsimjetNormalizedTrackPt[flavour][ts] = (TH1F*) hsimjetTrackPt[flavour][ts]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, ts));
      hsimjetNormalizedTrackEta[flavour][ts] = (TH1F*) hsimjetTrackEta[flavour][ts]->Clone(Form("hsimjetNormalizedTrackEta_%d_%d", flavour, ts));
      hsimjetNormalizedTrackPhi[flavour][ts] = (TH1F*) hsimjetTrackPhi[flavour][ts]->Clone(Form("hsimjetNormalizedTrackPhi_%d_%d", flavour, ts));
      hsimjetNormalizedSignImpXYSig[flavour][ts] = (TH1F*) hsimjetSignImpXYSig[flavour][ts]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, ts));

      hsimjetNormalizedTrackPt[flavour][ts]->Scale(1. / hsimjetNormalizedTrackPt[flavour][ts]->GetEntries());
      hsimjetNormalizedTrackEta[flavour][ts]->Scale(1. / hsimjetNormalizedTrackEta[flavour][ts]->GetEntries());
      hsimjetNormalizedTrackPhi[flavour][ts]->Scale(1. / hsimjetNormalizedTrackPhi[flavour][ts]->GetEntries());
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
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trackselection/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysTrackSelectionAnalysis::DrawIncJetTrackEtaTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedTrackEta[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trackselection/tracketa.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysTrackSelectionAnalysis::DrawIncJetTrackPhiTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedTrackPhi[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trackselection/trackphi.pdf\")", canvasNum - 1));

}

void HfJetTaggingSysTrackSelectionAnalysis::DrawIncJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trackselection/signImpXYSig.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysTrackSelectionAnalysis::DrawCharmJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[1][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 1: charm
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/trackselection/signImpXYSig.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysTrackSelectionAnalysis::DrawBeautyJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[2][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 2: Beauty
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/trackselection/signImpXYSig.pdf\")", canvasNum - 1));
}

void HfJetTaggingSysTrackSelectionAnalysis::DrawLfJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> NormHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    NormHistList.push_back({hsimjetNormalizedSignImpXYSig[2][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 2: Lf
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/trackselection/signImpXYSig.pdf\")", canvasNum - 1));
}
#endif // HFJETTAGGINGSYSTRACKSELECTIONANALYSIS_H
