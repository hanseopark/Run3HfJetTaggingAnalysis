#ifndef HFJETTAGGINGSYSTRIGGER_H
#define HFJETTAGGINGSYSTRIGGER_H

#include <TH1F.h>
#include <TString.h>
#include "CanvasHandler.h"
#include "DataPoint.h"

class HfJetTaggingSysTriggerAnalysis {
  public:
    HfJetTaggingSysTriggerAnalysis(const std::vector<TString> &rootSim, bool doData, bool doMC, bool dopartLevel) {
///      if (doData) {
///        LoadData(rootSim);
///      }
      if (doMC) {
        if(!LoadSimTrigger(rootSim)) {
          return;
        }
        initHistogramTrigger();
        projectionHistTrigger();
        normalizedHistogramTrigger();
      }
      saveHistogram("sysTrigger.root", doData, doMC, dopartLevel);

    }
    ~HfJetTaggingSysTriggerAnalysis();

    //// FUNCTION ////
    int LoadSimTrigger(const std::vector<TString> &rootFiles);
    void initHistogramTrigger();
    void projectionHistTrigger();
    void normalizedHistogramTrigger();
    void saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // fucntion
    void drawIncJetTrackPtTrigger(bool doLog, int numTrigger);
    void drawIncJetTrackEtaTrigger(bool doLog, int numTrigger);
    void drawIncJetTrackPhiTrigger(bool doLog, int numTrigger);
    void drawIncJetSignImpXYSigTrigger(bool doLog, int numTrigger);
    void drawIncJet2ProngLxyTrigger(bool doLog, int numTrigger);
    void drawIncJet2ProngLxyzTrigger(bool doLog, int numTrigger);
    void drawIncJet2ProngsigmaLxyTrigger(bool doLog, int numTrigger);
    void drawIncJet2ProngsigmaLxyzTrigger(bool doLog, int numTrigger);
    void drawIncJet2ProngSxyTrigger(bool doLog, int numTrigger);
    void drawIncJet2ProngSxyzTrigger(bool doLog, int numTrigger);
    void drawCharmJetSignImpXYSigTrigger(bool doLog, int numTrigger);
    void drawBeautyJetSignImpXYSigTrigger(bool doLog, int numTrigger);
    void drawLfJetSignImpXYSigTrigger(bool doLog, int numTrigger);
    void drawTagJetEntriesTrigger(int numTrigger);
    void drawTagJetNormEntriesTrigger(int numTrigger);
    void drawTagJetTrackEntriesTrigger(int numTrigger);
    void drawTagJetNormTrackEntriesTrigger(int numTrigger);

  protected:
    CanvasHandler* canHan;
    int cn=0;
    TH3F* h3datajetPtTrackPtFlavour[HfJetTagging::numTrigger];
    TH3F* h3datajetPtTrackEtaFlavour[HfJetTagging::numTrigger];
    TH3F* h3datajetPtTrackPhiFlavour[HfJetTagging::numTrigger];
    TH3F* h3datajetPtSignImpXYSigFlavour[HfJetTagging::numTrigger];

    TH2F* h2simTagjetPtFlavour[HfJetTagging::numTrigger];
    TH2F* h2simTagjetEtaFlavour[HfJetTagging::numTrigger];
    TH2F* h2simTagjetPhiFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPtTrackPtFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPtTrackEtaFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPtTrackPhiFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPtSignImpXYSigFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPt2ProngLxyFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPt2ProngLxyzFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPt2ProngsigmaLxyFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPt2ProngsigmaLxyzFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPt2ProngSxyFlavour[HfJetTagging::numTrigger];
    TH3F* h3simTagjetPt2ProngSxyzFlavour[HfJetTagging::numTrigger];

    TH1F* hsimTagjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjet2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjet2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjet2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjet2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjet2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjet2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetEntries[HfJetTagging::numTrigger];
    TH1F* hsimTagjetTrackEntries[HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalizedTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalizedTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalized2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalized2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalized2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalized2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalized2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalized2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalizedEntries[HfJetTagging::numTrigger];
    TH1F* hsimTagjetNormalizedTrackEntries[HfJetTagging::numTrigger];

  private:
    TLatex latex;

};

HfJetTaggingSysTriggerAnalysis::~HfJetTaggingSysTriggerAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysTriggerAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysTriggerAnalysis::LoadSimTrigger(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxTrigger = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    h2simTagjetPtFlavour[maxTrigger] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskName.Data())));
    h2simTagjetEtaFlavour[maxTrigger] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h3_jet_eta_flavour", taskName.Data())));
    h2simTagjetPhiFlavour[maxTrigger] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h3_jet_phi_flavour", taskName.Data())));
    h3simTagjetPtTrackPtFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
    h3simTagjetPtTrackEtaFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskName.Data())));
    h3simTagjetPtTrackPhiFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskName.Data())));
    h3simTagjetPtSignImpXYSigFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
    h3simTagjetPt2ProngLxyFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxy_flavour", taskName.Data())));
    h3simTagjetPt2ProngLxyzFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxyz_flavour", taskName.Data())));
    h3simTagjetPt2ProngSxyFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxy_flavour", taskName.Data())));
    h3simTagjetPt2ProngSxyzFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxyz_flavour", taskName.Data())));
    h3simTagjetPt2ProngsigmaLxyFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxy_flavour", taskName.Data())));
    h3simTagjetPt2ProngsigmaLxyzFlavour[maxTrigger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxyz_flavour", taskName.Data())));
    maxTrigger++;
  }

  return 1;
}

void HfJetTaggingSysTriggerAnalysis::initHistogramTrigger() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int trigger =0; trigger < HfJetTagging::numTrigger; trigger++) {
      hsimTagjetTrackPt[flavour][trigger] = new TH1F(Form("hsimTagjetTrackPt_%d_%d", flavour, trigger), "", h3simTagjetPtTrackPtFlavour[trigger]->GetNbinsY(), h3simTagjetPtTrackPtFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPtFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPtFlavour[trigger]->GetNbinsY()));
      hsimTagjetTrackEta[flavour][trigger] = new TH1F(Form("hsimTagjetTrackEta_%d_%d", flavour, trigger), "", h3simTagjetPtTrackEtaFlavour[trigger]->GetNbinsY(), h3simTagjetPtTrackEtaFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackEtaFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackEtaFlavour[trigger]->GetNbinsY()));
      hsimTagjetTrackPhi[flavour][trigger] = new TH1F(Form("hsimTagjetTrackPhi_%d_%d", flavour, trigger), "", h3simTagjetPtTrackPhiFlavour[trigger]->GetNbinsY(), h3simTagjetPtTrackPhiFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPhiFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPhiFlavour[trigger]->GetNbinsY()));
      hsimTagjetSignImpXYSig[flavour][trigger] = new TH1F(Form("hsimTagjetSignImpXYSig_%d_%d", flavour, trigger), "", h3simTagjetPtSignImpXYSigFlavour[trigger]->GetNbinsY(), h3simTagjetPtSignImpXYSigFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYSigFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYSigFlavour[trigger]->GetNbinsY()));
			hsimTagjet2ProngLxy[flavour][trigger] = new TH1F(Form("hsimTagjet2ProngLxy_%d_%d", flavour, trigger), "", h3simTagjetPt2ProngLxyFlavour[trigger]->GetNbinsY(), h3simTagjetPt2ProngLxyFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngLxyFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngLxyFlavour[trigger]->GetNbinsY()));
			hsimTagjet2ProngLxyz[flavour][trigger] = new TH1F(Form("hsimTagjet2ProngLxyz_%d_%d", flavour, trigger), "", h3simTagjetPt2ProngLxyzFlavour[trigger]->GetNbinsY(), h3simTagjetPt2ProngLxyzFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngLxyzFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngLxyzFlavour[trigger]->GetNbinsY()));
			hsimTagjet2ProngSxy[flavour][trigger] = new TH1F(Form("hsimTagjet2ProngSxy_%d_%d", flavour, trigger), "", h3simTagjetPt2ProngSxyFlavour[trigger]->GetNbinsY(), h3simTagjetPt2ProngSxyFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngSxyFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngSxyFlavour[trigger]->GetNbinsY()));
			hsimTagjet2ProngSxyz[flavour][trigger] = new TH1F(Form("hsimTagjet2ProngSxyz_%d_%d", flavour, trigger), "", h3simTagjetPt2ProngSxyzFlavour[trigger]->GetNbinsY(), h3simTagjetPt2ProngSxyzFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngSxyzFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngSxyzFlavour[trigger]->GetNbinsY()));
			hsimTagjet2ProngsigmaLxy[flavour][trigger] = new TH1F(Form("hsimTagjet2ProngsigmaLxy_%d_%d", flavour, trigger), "", h3simTagjetPt2ProngsigmaLxyFlavour[trigger]->GetNbinsY(), h3simTagjetPt2ProngsigmaLxyFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngsigmaLxyFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngsigmaLxyFlavour[trigger]->GetNbinsY()));
			hsimTagjet2ProngsigmaLxyz[flavour][trigger] = new TH1F(Form("hsimTagjet2ProngsigmaLxyz_%d_%d", flavour, trigger), "", h3simTagjetPt2ProngsigmaLxyzFlavour[trigger]->GetNbinsY(), h3simTagjetPt2ProngsigmaLxyzFlavour[trigger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngsigmaLxyzFlavour[trigger]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngsigmaLxyzFlavour[trigger]->GetNbinsY()));
    }
  }
  for (int trigger =0; trigger < HfJetTagging::numTrigger; trigger++) {
    hsimTagjetEntries[trigger] = new TH1F(Form("hsimTagjetEntries_%d", trigger), "", 3, 0.5, 3.5);
    hsimTagjetTrackEntries[trigger] = new TH1F(Form("hsimTagjetTrackEntries_%d", trigger), "", 3, 0.5, 3.5);
  }
}

void HfJetTaggingSysTriggerAnalysis::projectionHistTrigger() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projJetPt[HfJetTagging::numTrigger];
  TH1F* projTrackPt[HfJetTagging::numTrigger];
  TH1F* projTrackEta[HfJetTagging::numTrigger];
  TH1F* projTrackPhi[HfJetTagging::numTrigger];
  TH1F* projSignImpXYSig[HfJetTagging::numTrigger];
  TH1F* proj2ProngLxy[HfJetTagging::numTrigger];
  TH1F* proj2ProngLxyz[HfJetTagging::numTrigger];
  TH1F* proj2ProngsigmaLxy[HfJetTagging::numTrigger];
  TH1F* proj2ProngsigmaLxyz[HfJetTagging::numTrigger];
  TH1F* proj2ProngSxy[HfJetTagging::numTrigger];
  TH1F* proj2ProngSxyz[HfJetTagging::numTrigger];

  for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int trigger=0; trigger<HfJetTagging::numTrigger; trigger++) {
      projJetPt[trigger] = reinterpret_cast<TH1F*> (h2simTagjetPtFlavour[trigger]->ProjectionX(Form("projJetPt_%d_%d", binFlavour, trigger), binFlavour, binFlavour));
      projTrackPt[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPtFlavour[trigger]->ProjectionY(Form("projTrackPt_%d_%d", binFlavour, trigger), 1, h3simTagjetPtTrackPtFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      projTrackEta[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour[trigger]->ProjectionY(Form("projTrackEta_%d_%d", binFlavour, trigger), 1, h3simTagjetPtTrackEtaFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      projTrackPhi[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPhiFlavour[trigger]->ProjectionY(Form("projTrackPhi_%d_%d", binFlavour, trigger), 1, h3simTagjetPtTrackPhiFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      projSignImpXYSig[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYSigFlavour[trigger]->ProjectionY(Form("projSignImpXYSig_%d_%d", binFlavour, trigger), 1, h3simTagjetPtSignImpXYSigFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      proj2ProngLxy[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyFlavour[trigger]->ProjectionY(Form("proj2ProngLxy_%d_%d", binFlavour, trigger), 1, h3simTagjetPt2ProngLxyFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      proj2ProngLxyz[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyzFlavour[trigger]->ProjectionY(Form("proj2ProngLxyz_%d_%d", binFlavour, trigger), 1, h3simTagjetPt2ProngLxyzFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      proj2ProngsigmaLxy[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyFlavour[trigger]->ProjectionY(Form("proj2ProngsigmaLxy_%d_%d", binFlavour, trigger), 1, h3simTagjetPt2ProngsigmaLxyFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      proj2ProngsigmaLxyz[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyzFlavour[trigger]->ProjectionY(Form("proj2ProngsigmaLxyz_%d_%d", binFlavour, trigger), 1, h3simTagjetPt2ProngsigmaLxyzFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      proj2ProngSxy[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyFlavour[trigger]->ProjectionY(Form("proj2ProngSxy_%d_%d", binFlavour, trigger), 1, h3simTagjetPt2ProngSxyFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      proj2ProngSxyz[trigger] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyzFlavour[trigger]->ProjectionY(Form("proj2ProngSxyz_%d_%d", binFlavour, trigger), 1, h3simTagjetPt2ProngSxyzFlavour[trigger]->GetNbinsX(), binFlavour, binFlavour));
      
      // inclusive
      hsimTagjetTrackPt[0][trigger]->Add(projTrackPt[trigger]);
      hsimTagjetTrackEta[0][trigger]->Add(projTrackEta[trigger]);
      hsimTagjetTrackPhi[0][trigger]->Add(projTrackPhi[trigger]);
      hsimTagjetSignImpXYSig[0][trigger]->Add(projSignImpXYSig[trigger]);
      hsimTagjet2ProngLxy[0][trigger]->Add(proj2ProngLxy[trigger]);
      hsimTagjet2ProngLxyz[0][trigger]->Add(proj2ProngLxyz[trigger]);
      hsimTagjet2ProngsigmaLxy[0][trigger]->Add(proj2ProngsigmaLxy[trigger]);
      hsimTagjet2ProngsigmaLxyz[0][trigger]->Add(proj2ProngsigmaLxyz[trigger]);
      hsimTagjet2ProngSxy[0][trigger]->Add(proj2ProngSxy[trigger]);
      hsimTagjet2ProngSxyz[0][trigger]->Add(proj2ProngSxyz[trigger]);

      // jet flavour
      hsimTagjetTrackPt[flavour][trigger] = reinterpret_cast<TH1F*>(projTrackPt[trigger]->Clone());
      std::cout << "track: " << hsimTagjetTrackPt[flavour][trigger]->GetEntries() << std::endl;
      hsimTagjetTrackEta[flavour][trigger] = reinterpret_cast<TH1F*>(projTrackEta[trigger]->Clone());
      hsimTagjetTrackPhi[flavour][trigger] = reinterpret_cast<TH1F*>(projTrackPhi[trigger]->Clone());
      hsimTagjetSignImpXYSig[flavour][trigger] = reinterpret_cast<TH1F*>(projSignImpXYSig[trigger]->Clone());
      hsimTagjet2ProngLxy[flavour][trigger] = reinterpret_cast<TH1F*>(proj2ProngLxy[trigger]->Clone());
      std::cout << "prong: " << hsimTagjet2ProngLxy[flavour][trigger]->GetEntries() << std::endl;
      hsimTagjet2ProngLxyz[flavour][trigger] = reinterpret_cast<TH1F*>(proj2ProngLxyz[trigger]->Clone());
      hsimTagjet2ProngsigmaLxy[flavour][trigger] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxy[trigger]->Clone());
      hsimTagjet2ProngsigmaLxyz[flavour][trigger] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyz[trigger]->Clone());
      hsimTagjet2ProngSxy[flavour][trigger] = reinterpret_cast<TH1F*>(proj2ProngSxy[trigger]->Clone());
      hsimTagjet2ProngSxyz[flavour][trigger] = reinterpret_cast<TH1F*>(proj2ProngSxyz[trigger]->Clone());
      hsimTagjetEntries[trigger]->SetBinContent(flavour, projJetPt[trigger]->GetEntries());
      std::cout<< "jet: " << hsimTagjetEntries[trigger]->GetBinContent(flavour) << std::endl;
      hsimTagjetTrackEntries[trigger]->SetBinContent(flavour, projTrackPhi[trigger]->GetEntries());
      //std::cout<<hsimTagjetTrackEntries[trigger]->GetBinContent(flavour) << std::endl;
    }
  }
}

void HfJetTaggingSysTriggerAnalysis::normalizedHistogramTrigger() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int trigger =0; trigger < HfJetTagging::numTrigger; trigger++) {
      hsimTagjetNormalizedTrackPt[flavour][trigger] = (TH1F*) hsimTagjetTrackPt[flavour][trigger]->Clone(Form("hsimTagjetNormalizedTrackPt_%d_%d", flavour, trigger));
      hsimTagjetNormalizedTrackEta[flavour][trigger] = (TH1F*) hsimTagjetTrackEta[flavour][trigger]->Clone(Form("hsimTagjetNormalizedTrackEta_%d_%d", flavour, trigger));
      hsimTagjetNormalizedTrackPhi[flavour][trigger] = (TH1F*) hsimTagjetTrackPhi[flavour][trigger]->Clone(Form("hsimTagjetNormalizedTrackPhi_%d_%d", flavour, trigger));
      hsimTagjetNormalizedSignImpXYSig[flavour][trigger] = (TH1F*) hsimTagjetSignImpXYSig[flavour][trigger]->Clone(Form("hsimTagjetNormalizedSignImpXYSig_%d_%d", flavour, trigger));
      hsimTagjetNormalized2ProngLxy[flavour][trigger] = (TH1F*) hsimTagjet2ProngLxy[flavour][trigger]->Clone(Form("hsimTagjetNormalized2ProngLxy_%d_%d", flavour, trigger));
      hsimTagjetNormalized2ProngLxyz[flavour][trigger] = (TH1F*) hsimTagjet2ProngLxyz[flavour][trigger]->Clone(Form("hsimTagjetNormalized2ProngLxyz_%d_%d", flavour, trigger));
      hsimTagjetNormalized2ProngsigmaLxy[flavour][trigger] = (TH1F*) hsimTagjet2ProngsigmaLxy[flavour][trigger]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxy_%d_%d", flavour, trigger));
      hsimTagjetNormalized2ProngsigmaLxyz[flavour][trigger] = (TH1F*) hsimTagjet2ProngsigmaLxyz[flavour][trigger]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxyz_%d_%d", flavour, trigger));
      hsimTagjetNormalized2ProngSxy[flavour][trigger] = (TH1F*) hsimTagjet2ProngSxy[flavour][trigger]->Clone(Form("hsimTagjetNormalized2ProngSxy_%d_%d", flavour, trigger));
      hsimTagjetNormalized2ProngSxyz[flavour][trigger] = (TH1F*) hsimTagjet2ProngSxyz[flavour][trigger]->Clone(Form("hsimTagjetNormalized2ProngSxyz_%d_%d", flavour, trigger));

      hsimTagjetNormalizedTrackPt[flavour][trigger]->Scale(1. / hsimTagjetNormalizedTrackPt[flavour][trigger]->GetEntries());
      hsimTagjetNormalizedTrackEta[flavour][trigger]->Scale(1. / hsimTagjetNormalizedTrackEta[flavour][trigger]->GetEntries());
      hsimTagjetNormalizedTrackPhi[flavour][trigger]->Scale(1. / hsimTagjetNormalizedTrackPhi[flavour][trigger]->GetEntries());
      hsimTagjetNormalizedSignImpXYSig[flavour][trigger]->Scale(1. / hsimTagjetNormalizedSignImpXYSig[flavour][trigger]->GetEntries());
      hsimTagjetNormalized2ProngLxy[flavour][trigger]->Scale(1. / hsimTagjetNormalized2ProngLxy[flavour][trigger]->GetEntries());
      hsimTagjetNormalized2ProngLxyz[flavour][trigger]->Scale(1. / hsimTagjetNormalized2ProngLxyz[flavour][trigger]->GetEntries());
      hsimTagjetNormalized2ProngsigmaLxy[flavour][trigger]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxy[flavour][trigger]->GetEntries());
      hsimTagjetNormalized2ProngsigmaLxyz[flavour][trigger]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxyz[flavour][trigger]->GetEntries());
      hsimTagjetNormalized2ProngSxy[flavour][trigger]->Scale(1. / hsimTagjetNormalized2ProngSxy[flavour][trigger]->GetEntries());
      hsimTagjetNormalized2ProngSxyz[flavour][trigger]->Scale(1. / hsimTagjetNormalized2ProngSxyz[flavour][trigger]->GetEntries());
    }
  }
  for (int trigger =0; trigger < HfJetTagging::numTrigger; trigger++) {
    hsimTagjetNormalizedEntries[trigger] = (TH1F*) hsimTagjetEntries[trigger]->Clone(Form("hsimTagjetNoramlizedEntries_%d", trigger));
    hsimTagjetNormalizedEntries[trigger]->Scale(1. / (hsimTagjetEntries[trigger]->GetBinContent(1)+hsimTagjetEntries[trigger]->GetBinContent(2)+hsimTagjetEntries[trigger]->GetBinContent(3)));
    hsimTagjetNormalizedTrackEntries[trigger] = (TH1F*) hsimTagjetTrackEntries[trigger]->Clone(Form("hsimTagjetNormalizedTrackEntries_%d", trigger));
    hsimTagjetNormalizedTrackEntries[trigger]->Scale(1. / (hsimTagjetTrackEntries[trigger]->GetBinContent(1)+hsimTagjetTrackEntries[trigger]->GetBinContent(2)+hsimTagjetTrackEntries[trigger]->GetBinContent(3)));
  }
}

void HfJetTaggingSysTriggerAnalysis::saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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
    for (int trigger =0; trigger < HfJetTagging::numTrigger; trigger++) {
      hsimTagjetEntries[trigger]->Write();
      hsimTagjetNormalizedEntries[trigger]->Write();
    }
  }

}

void HfJetTaggingSysTriggerAnalysis::drawIncJetTrackPtTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPt[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJetTrackEtaTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackEta[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/tracketa.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJetTrackPhiTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPhi[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/trackphi.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJetSignImpXYSigTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawIncJet2ProngLxyTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalized2ProngLxy[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/2ProngLxy.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJet2ProngLxyzTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalized2ProngLxyz[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/2ProngLxyz.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJet2ProngsigmaLxyTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxy[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/2ProngsigmaLxy.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJet2ProngsigmaLxyzTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyz[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/2ProngsigmaLxyz.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJet2ProngSxyTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalized2ProngSxy[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/2ProngSxy.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawIncJet2ProngSxyzTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalized2ProngSxyz[0][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/trigger/2ProngSxyz.pdf\")", cn++));

}

void HfJetTaggingSysTriggerAnalysis::drawCharmJetSignImpXYSigTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[1][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 1: charm
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/trigger/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawBeautyJetSignImpXYSigTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[2][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 2: Beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/trigger/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawLfJetSignImpXYSigTrigger(bool doLog = true, int Num = HfJetTagging::numTrigger) {
  std::vector<HistogramData> NormHistList;
  for (int trigger =0; trigger<HfJetTagging::numTrigger; trigger++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[2][trigger], HfJetTagging::SYS::TRIGGER[trigger]}); // 2: Lf
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/trigger/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawTagJetEntriesTrigger(int Num = HfJetTagging::numTrigger) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e+1, 1e+10, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int trigger = 0; trigger < HfJetTagging::numTrigger; trigger++) {
    hsimTagjetEntries[trigger]->SetLineColor(trigger+1); // Set different colors
    hs->Add(hsimTagjetEntries[trigger]);
    legend->AddEntry(hsimTagjetEntries[trigger], HfJetTagging::SYS::TRIGGER[trigger], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/trigger/jetentries.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawTagJetNormEntriesTrigger(int Num = HfJetTagging::numTrigger) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e-2, 1.0, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int trigger = 0; trigger < HfJetTagging::numTrigger; trigger++) {
    hsimTagjetNormalizedEntries[trigger]->SetLineColor(trigger+1); // Set different colors
    hs->Add(hsimTagjetNormalizedEntries[trigger]);
    legend->AddEntry(hsimTagjetNormalizedEntries[trigger], HfJetTagging::SYS::TRIGGER[trigger], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/trigger/normJetentries.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawTagJetTrackEntriesTrigger(int Num = HfJetTagging::numTrigger) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e+1, 1e+10, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int trigger = 0; trigger < HfJetTagging::numTrigger; trigger++) {
    hsimTagjetTrackEntries[trigger]->SetLineColor(trigger+1); // Set different colors
    hs->Add(hsimTagjetTrackEntries[trigger]);
    legend->AddEntry(hsimTagjetTrackEntries[trigger], HfJetTagging::SYS::TRIGGER[trigger], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/trigger/trackentries.pdf\")", cn++));
}

void HfJetTaggingSysTriggerAnalysis::drawTagJetNormTrackEntriesTrigger(int Num = HfJetTagging::numTrigger) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e-2, 1.0, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int trigger = 0; trigger < HfJetTagging::numTrigger; trigger++) {
    hsimTagjetNormalizedTrackEntries[trigger]->SetLineColor(trigger+1); // Set different colors
    hs->Add(hsimTagjetNormalizedTrackEntries[trigger]);
    legend->AddEntry(hsimTagjetNormalizedTrackEntries[trigger], HfJetTagging::SYS::TRIGGER[trigger], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/trigger/normTrackentries.pdf\")", cn++));
}

#endif // HFJETTAGGINGSYSTRIGGERANALYSIS_H
