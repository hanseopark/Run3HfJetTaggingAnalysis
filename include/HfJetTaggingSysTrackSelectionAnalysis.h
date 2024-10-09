#ifndef HFJETTAGGINGSYSTRACKSELECTION_H
#define HFJETTAGGINGSYSTRACKSELECTION_H

#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

class HfJetTaggingSysTrackSelectionAnalysis : public HfJetTaggingSysAnalysis{
  public:
    HfJetTaggingSysTrackSelectionAnalysis() : HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysTrackSelectionAnalysis();

    //// FUNCTION ////
    void initConfig();
    int loadSimTS(const std::vector<TString> &rootFiles);
    void initHistogramTS();
    void projectionHistTS();
    void normalizedHistogramTS();

    // Set
    void setFillIPxy(bool fillIPxy);
    void setFillTrackEffi(bool fillTrackEffi);
    void setFillSV(bool fillSV);

    // Get

    // fucntion
    void drawIncJetTrackPtTrackSelection(bool doLog, int numts);
    void drawIncJetTrackEtaTrackSelection(bool doLog, int numts);
    void drawIncJetTrackPhiTrackSelection(bool doLog, int numts);
    void drawIncJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void drawCharmJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void drawBeautyJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void drawLfJetSignImpXYSigTrackSelection(bool doLog, int numts);
    void drawTrackEffi(int numts);

  protected:
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

    TH3F* h3PartPtPartEtaPartPhi[HfJetTagging::numTrackSelection];
    TH3F* h3PartPtPartEtaPartPhiAssoPrimary[HfJetTagging::numTrackSelection];

    TH1F* hPartPt[HfJetTagging::numTrackSelection];
    TH1F* hPartPtAssoPrimary[HfJetTagging::numTrackSelection];

    TH3F* h3simTagjetPt3ProngSxyFlavour;
    TH3F* h3simTagjetPt3ProngSxyN1Flavour;
    TH3F* h3simTagjetPt3ProngSxyN1FlavourCutSxyAndsigmaLxy;

  private:
    TLatex latexNoNDC;
    TLatex latex;
    TString dirData;
    TString dirSim;
    bool fillIPxy=false;
    bool fillTrackEffi=false;
    bool fillSV=false;

};

HfJetTaggingSysTrackSelectionAnalysis::~HfJetTaggingSysTrackSelectionAnalysis() {
  std::cout<< " " << std::endl;
}

void HfJetTaggingSysTrackSelectionAnalysis::initConfig() {
  //latex.SetNDC(); // Use normalized coordinates
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  dirData = Form("fig/%s/data/%s/sys/trksel", SOURCESET.Data(), DATASET.Data());
  dirSim = Form("fig/%s/sim/%s/sys/trksel", SOURCESET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

//int HfJetTaggingSysTrackSelectionAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysTrackSelectionAnalysis::loadSimTS(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  const TString &taskTrackEffi = "track-efficiency";
  int maxTrackSelection = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      return 0;
    }
    std::cout << "file pwd: " << rootFile.Data() << std::endl;
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    if (fillIPxy) {
      h3simjetPtTrackPtFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
      h3simjetPtTrackEtaFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskName.Data())));
      h3simjetPtTrackPhiFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskName.Data())));
      h3simjetPtSignImpXYSigFlavour[maxTrackSelection] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
    }
    if (fillTrackEffi) {
      h3PartPtPartEtaPartPhi[maxTrackSelection] = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_particle_pt_particle_eta_particle_phi_mcpartofinterest", taskTrackEffi.Data())));
      h3PartPtPartEtaPartPhiAssoPrimary[maxTrackSelection] = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_particle_pt_particle_eta_particle_phi_associatedtrack_primary", taskTrackEffi.Data())));
    }
    if (fillSV) {

    }
    maxTrackSelection++;
  }

  return 1;
}

void HfJetTaggingSysTrackSelectionAnalysis::initHistogramTS() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
      if (fillIPxy) {
        hsimjetTrackPt[flavour][ts] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, ts), "", h3simjetPtTrackPtFlavour[ts]->GetNbinsY(), h3simjetPtTrackPtFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour[ts]->GetNbinsY()));
        hsimjetTrackEta[flavour][ts] = new TH1F(Form("hsimjetTrackEta_%d_%d", flavour, ts), "", h3simjetPtTrackEtaFlavour[ts]->GetNbinsY(), h3simjetPtTrackEtaFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackEtaFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackEtaFlavour[ts]->GetNbinsY()));
        hsimjetTrackPhi[flavour][ts] = new TH1F(Form("hsimjetTrackPhi_%d_%d", flavour, ts), "", h3simjetPtTrackPhiFlavour[ts]->GetNbinsY(), h3simjetPtTrackPhiFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPhiFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPhiFlavour[ts]->GetNbinsY()));
        hsimjetSignImpXYSig[flavour][ts] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, ts), "", h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[ts]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[ts]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[ts]->GetNbinsY()));
      }

    }
  }
  for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
    if (fillTrackEffi) {
      hPartPt[ts] = new TH1F(Form("hPartPt_%d", ts), "", h3PartPtPartEtaPartPhi[ts]->GetNbinsX(), h3PartPtPartEtaPartPhi[ts]->GetXaxis()->GetBinLowEdge(1), h3PartPtPartEtaPartPhi[ts]->GetXaxis()->GetBinUpEdge(h3PartPtPartEtaPartPhi[ts]->GetNbinsX()));
      hPartPtAssoPrimary[ts] = new TH1F(Form("hPartPtAssoPrimary_%d", ts), "", h3PartPtPartEtaPartPhiAssoPrimary[ts]->GetNbinsX(), h3PartPtPartEtaPartPhiAssoPrimary[ts]->GetXaxis()->GetBinLowEdge(1), h3PartPtPartEtaPartPhiAssoPrimary[ts]->GetXaxis()->GetBinUpEdge(h3PartPtPartEtaPartPhiAssoPrimary[ts]->GetNbinsX()));
    }
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::projectionHistTS() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projTrackPt[HfJetTagging::numTrackSelection];
  TH1F* projTrackEta[HfJetTagging::numTrackSelection];
  TH1F* projTrackPhi[HfJetTagging::numTrackSelection];
  TH1F* projSignImpXYSig[HfJetTagging::numTrackSelection];
  for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int ts=0; ts<HfJetTagging::numTrackSelection; ts++) {
      if (fillIPxy) {
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
  for (int ts=0; ts<HfJetTagging::numTrackSelection; ts++) {
    if (fillTrackEffi) {
      TH1F* projPartPt = (TH1F*) h3PartPtPartEtaPartPhi[ts]->ProjectionX("projPartPt", 1, h3PartPtPartEtaPartPhi[ts]->GetNbinsY(), 1, h3PartPtPartEtaPartPhi[ts]->GetNbinsZ());
      TH1F* projPartPtAssoPrimary = (TH1F*) h3PartPtPartEtaPartPhiAssoPrimary[ts]->ProjectionX("projPartPtAssoPrimary", 1, h3PartPtPartEtaPartPhiAssoPrimary[ts]->GetNbinsY(), 1, h3PartPtPartEtaPartPhiAssoPrimary[ts]->GetNbinsZ());
      hPartPt[ts] = reinterpret_cast<TH1F*>(projPartPt->Clone("hPartPt"));
      hPartPtAssoPrimary[ts] = reinterpret_cast<TH1F*>(projPartPtAssoPrimary->Clone("hPartPtAssoPrimary"));
    }
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::normalizedHistogramTS() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int ts =0; ts < HfJetTagging::numTrackSelection; ts++) {
      if (fillIPxy) {
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
}

void HfJetTaggingSysTrackSelectionAnalysis::setFillIPxy(bool mfillIPxy) {
  fillIPxy = mfillIPxy;
  if (fillIPxy) {
    std::cout << "Fill IP xy " << std::endl;
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::setFillTrackEffi(bool mfillTrackEffi) {
  fillTrackEffi = mfillTrackEffi;
  if (fillData) {
    std::cout << "Fill track matching efficiency " << std::endl;
  }
}

void HfJetTaggingSysTrackSelectionAnalysis::setFillSV(bool mfillSV) {
  fillSV = mfillSV;
  if (fillSV) {
    std::cout << "Fill SV " << std::endl;
  }
}

// Draw
void HfJetTaggingSysTrackSelectionAnalysis::drawIncJetTrackPtTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedTrackPt[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/trackmomentum.pdf\")", nc++, dirSim.Data()));

}

void HfJetTaggingSysTrackSelectionAnalysis::drawIncJetTrackEtaTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedTrackEta[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/tracketa.pdf\")", nc++, dirSim.Data()));

}

void HfJetTaggingSysTrackSelectionAnalysis::drawIncJetTrackPhiTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedTrackPhi[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/trackphi.pdf\")", nc++, dirSim.Data()));

}

void HfJetTaggingSysTrackSelectionAnalysis::drawIncJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[0][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/signImpXYSig.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysTrackSelectionAnalysis::drawCharmJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[1][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 1: charm
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/signImpXYSig.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysTrackSelectionAnalysis::drawBeautyJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[2][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 2: Beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/signImpXYSig.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysTrackSelectionAnalysis::drawLfJetSignImpXYSigTrackSelection(bool doLog = true, int Num = HfJetTagging::numTrackSelection) {
  std::vector<HistogramData> normHistList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    normHistList.push_back({hsimjetNormalizedSignImpXYSig[2][ts], HfJetTagging::SYS::TRACKSELECTION[ts]}); // 2: Lf
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(normHistList.size(), normHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/signImpXYSig.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSysTrackSelectionAnalysis::drawTrackEffi(int Num = HfJetTagging::numTrackSelection) {
  TH1F* heffi[Num];
  int rebinNum = 4;
	std::vector<HistogramData> histList;
  for (int ts =0; ts<HfJetTagging::numTrackSelection; ts++) {
    hPartPt[ts]->Rebin(rebinNum);
    hPartPtAssoPrimary[ts]->Rebin(rebinNum);
    //heffi[ts] = (TH1F*) hPartPtAssoPrimary[ts]->Clone();
    //heffi[ts]->Divide(hPartPt[ts]);
    heffi[ts] = (TH1F*) hPartPt[ts]->Clone();
    heffi[ts]->Divide(hPartPtAssoPrimary[ts]);
    histList.push_back({heffi[ts], HfJetTagging::SYS::TRACKSELECTION[ts]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, GeneralJet::REFHIST::TRACKEFFI[0], GeneralJet::REFHIST::TRACKEFFI[1], GeneralJet::REFHIST::TRACKEFFI[2], GeneralJet::REFHIST::TRACKEFFI[3], "#it{p}_{T}", "#epsilon");
  canHan->drawCombined(histList.size(), histList, true, true, 0.6, 0.7, GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackEffiAssoPrimary.pdf\")", nc++, dirSim.Data()));
}

#endif // HFJETTAGGINGSYSTRACKSELECTIONANALYSIS_H
