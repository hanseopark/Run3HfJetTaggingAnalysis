#ifndef HFJETTAGGINGSYSPASSANALYSIS_H
#define HFJETTAGGINGSYSPASSANALYSIS_H

#include <TH1F.h>
#include <TString.h>
#include "CanvasHandler.h"
#include "DataPoint.h"

class HfJetTaggingSysPassAnalysis {
  public:
    HfJetTaggingSysPassAnalysis(const std::vector<TString> &rootSim, bool doData, bool doMC, bool dopartLevel) {
///      if (doData) {
///        LoadData(rootSim);
///      }
      initConfig();
      if (doMC) {
        if(!loadSimPass(rootSim)) {
          return;
        }
        initHistogramPass();
        projectionHistPass();
        normalizedHistogramPass();
      }
      //saveHistogram("sysPass.root", doData, doMC, dopartLevel);

    }
    ~HfJetTaggingSysPassAnalysis();

    //// FUNCTION ////
    void initConfig();
    int loadSimPass(const std::vector<TString> &rootFiles);
    void initHistogramPass();
    void projectionHistPass();
    void normalizedHistogramPass();
    void saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // fucntion
    void drawIncJetTrackPtPass(bool doLog, int numPass);
    void drawIncJetTrackEtaPass(bool doLog, int numPass);
    void drawIncJetTrackPhiPass(bool doLog, int numPass);
    void drawIncJetSignImpXYSigPass(bool doLog, int numPass);
    void drawIncJet2ProngLxyPass(bool doLog, int numPass);
    void drawIncJet2ProngLxyzPass(bool doLog, int numPass);
    void drawIncJet2ProngsigmaLxyPass(bool doLog, int numPass);
    void drawIncJet2ProngsigmaLxyzPass(bool doLog, int numPass);
    void drawIncJet2ProngSxyPass(bool doLog, int numPass);
    void drawIncJet2ProngSxyzPass(bool doLog, int numPass);
    void drawCharmJetSignImpXYSigPass(bool doLog, int numPass);
    void drawBeautyJetSignImpXYSigPass(bool doLog, int numPass);
    void drawLfJetSignImpXYSigPass(bool doLog, int numPass);
    void drawTagJetEntriesPass(int numPass);
    void drawTagJetNormEntriesPass(int numPass);
    void drawTagJetTrackEntriesPass(int numPass);
    void drawTagJetNormTrackEntriesPass(int numPass);

  protected:
    CanvasHandler* canHan;
    int cn=0;
    TH3F* h3datajetPtTrackPtFlavour[HfJetTagging::numPass];
    TH3F* h3datajetPtTrackEtaFlavour[HfJetTagging::numPass];
    TH3F* h3datajetPtTrackPhiFlavour[HfJetTagging::numPass];
    TH3F* h3datajetPtSignImpXYSigFlavour[HfJetTagging::numPass];

    TH2F* h2simTagjetPtFlavour[HfJetTagging::numPass];
    TH2F* h2simTagjetEtaFlavour[HfJetTagging::numPass];
    TH2F* h2simTagjetPhiFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPtTrackPtFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPtTrackEtaFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPtTrackPhiFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPtSignImpXYSigFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPt2ProngLxyFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPt2ProngLxyzFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPt2ProngsigmaLxyFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPt2ProngsigmaLxyzFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPt2ProngSxyFlavour[HfJetTagging::numPass];
    TH3F* h3simTagjetPt2ProngSxyzFlavour[HfJetTagging::numPass];

    TH1F* hsimTagjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjet2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjet2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjet2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjet2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjet2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjet2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetEntries[HfJetTagging::numPass];
    TH1F* hsimTagjetTrackEntries[HfJetTagging::numPass];
    TH1F* hsimTagjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalizedTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalizedTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalized2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalized2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalized2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalized2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalized2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalized2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::numPass];
    TH1F* hsimTagjetNormalizedEntries[HfJetTagging::numPass];
    TH1F* hsimTagjetNormalizedTrackEntries[HfJetTagging::numPass];

  private:
    TLatex latex;

};

HfJetTaggingSysPassAnalysis::~HfJetTaggingSysPassAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysPassAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysPassAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

}

int HfJetTaggingSysPassAnalysis::loadSimPass(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxPass = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    h2simTagjetPtFlavour[maxPass] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskName.Data())));
    if (!h2simTagjetPtFlavour[maxPass]) {
      std::cout << "Error: Histogram h2_jet_pt_flavour not found in " << rootFile << std::endl;
      return 0;
    }
    h2simTagjetEtaFlavour[maxPass] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_flavour", taskName.Data())));
    if (!h2simTagjetEtaFlavour[maxPass]) {
      std::cout << "Error: Histogram h3_jet_eta_flavour not found in " << rootFile << std::endl;
      return 0;
    }
    h2simTagjetPhiFlavour[maxPass] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_flavour", taskName.Data())));
    if (!h2simTagjetPhiFlavour[maxPass]) {
      std::cout << "Error: Histogram h3_jet_phi_flavour not found in " << rootFile << std::endl;
      return 0;
    }
    h3simTagjetPtTrackPtFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
    if (!h3simTagjetPtTrackPtFlavour[maxPass]) {
      std::cout << "Error: Histogram h3_jet_pt_track_pt_flavour not found in " << rootFile << std::endl;
      return 0;
    }
    h3simTagjetPtTrackEtaFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskName.Data())));
    if (!h3simTagjetPtTrackEtaFlavour[maxPass]) {
      std::cout << "Error: Histogram h3_jet_pt_track_eta_flavour not found in " << rootFile << std::endl;
      return 0;
    }
    h3simTagjetPtTrackPhiFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskName.Data())));
    h3simTagjetPtSignImpXYSigFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
//    h3simTagjetPt2ProngLxyFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxy_flavour", taskName.Data())));
//    h3simTagjetPt2ProngLxyzFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxyz_flavour", taskName.Data())));
//    h3simTagjetPt2ProngSxyFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxy_flavour", taskName.Data())));
//    h3simTagjetPt2ProngSxyzFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxyz_flavour", taskName.Data())));
//    h3simTagjetPt2ProngsigmaLxyFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxy_flavour", taskName.Data())));
//    h3simTagjetPt2ProngsigmaLxyzFlavour[maxPass] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxyz_flavour", taskName.Data())));
    maxPass++;
  }
  std::cout<<"MC loaded"<<std::endl;

  return 1;
}

void HfJetTaggingSysPassAnalysis::initHistogramPass() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int pass =0; pass < HfJetTagging::numPass; pass++) {
      hsimTagjetTrackPt[flavour][pass] = new TH1F(Form("hsimTagjetTrackPt_%d_%d", flavour, pass), "", h3simTagjetPtTrackPtFlavour[pass]->GetNbinsY(), h3simTagjetPtTrackPtFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPtFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPtFlavour[pass]->GetNbinsY()));
      hsimTagjetTrackEta[flavour][pass] = new TH1F(Form("hsimTagjetTrackEta_%d_%d", flavour, pass), "", h3simTagjetPtTrackEtaFlavour[pass]->GetNbinsY(), h3simTagjetPtTrackEtaFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackEtaFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackEtaFlavour[pass]->GetNbinsY()));
      hsimTagjetTrackPhi[flavour][pass] = new TH1F(Form("hsimTagjetTrackPhi_%d_%d", flavour, pass), "", h3simTagjetPtTrackPhiFlavour[pass]->GetNbinsY(), h3simTagjetPtTrackPhiFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPhiFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPhiFlavour[pass]->GetNbinsY()));
      hsimTagjetSignImpXYSig[flavour][pass] = new TH1F(Form("hsimTagjetSignImpXYSig_%d_%d", flavour, pass), "", h3simTagjetPtSignImpXYSigFlavour[pass]->GetNbinsY(), h3simTagjetPtSignImpXYSigFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYSigFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYSigFlavour[pass]->GetNbinsY()));
//			hsimTagjet2ProngLxy[flavour][pass] = new TH1F(Form("hsimTagjet2ProngLxy_%d_%d", flavour, pass), "", h3simTagjetPt2ProngLxyFlavour[pass]->GetNbinsY(), h3simTagjetPt2ProngLxyFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngLxyFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngLxyFlavour[pass]->GetNbinsY()));
//			hsimTagjet2ProngLxyz[flavour][pass] = new TH1F(Form("hsimTagjet2ProngLxyz_%d_%d", flavour, pass), "", h3simTagjetPt2ProngLxyzFlavour[pass]->GetNbinsY(), h3simTagjetPt2ProngLxyzFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngLxyzFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngLxyzFlavour[pass]->GetNbinsY()));
//			hsimTagjet2ProngSxy[flavour][pass] = new TH1F(Form("hsimTagjet2ProngSxy_%d_%d", flavour, pass), "", h3simTagjetPt2ProngSxyFlavour[pass]->GetNbinsY(), h3simTagjetPt2ProngSxyFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngSxyFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngSxyFlavour[pass]->GetNbinsY()));
//			hsimTagjet2ProngSxyz[flavour][pass] = new TH1F(Form("hsimTagjet2ProngSxyz_%d_%d", flavour, pass), "", h3simTagjetPt2ProngSxyzFlavour[pass]->GetNbinsY(), h3simTagjetPt2ProngSxyzFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngSxyzFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngSxyzFlavour[pass]->GetNbinsY()));
//			hsimTagjet2ProngsigmaLxy[flavour][pass] = new TH1F(Form("hsimTagjet2ProngsigmaLxy_%d_%d", flavour, pass), "", h3simTagjetPt2ProngsigmaLxyFlavour[pass]->GetNbinsY(), h3simTagjetPt2ProngsigmaLxyFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngsigmaLxyFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngsigmaLxyFlavour[pass]->GetNbinsY()));
//			hsimTagjet2ProngsigmaLxyz[flavour][pass] = new TH1F(Form("hsimTagjet2ProngsigmaLxyz_%d_%d", flavour, pass), "", h3simTagjetPt2ProngsigmaLxyzFlavour[pass]->GetNbinsY(), h3simTagjetPt2ProngsigmaLxyzFlavour[pass]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngsigmaLxyzFlavour[pass]->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngsigmaLxyzFlavour[pass]->GetNbinsY()));
    }
  }
  for (int pass =0; pass < HfJetTagging::numPass; pass++) {
    hsimTagjetEntries[pass] = new TH1F(Form("hsimTagjetEntries_%d", pass), "", 3, 0.5, 3.5);
    hsimTagjetTrackEntries[pass] = new TH1F(Form("hsimTagjetTrackEntries_%d", pass), "", 3, 0.5, 3.5);
  }
}

void HfJetTaggingSysPassAnalysis::projectionHistPass() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  TH1F* projJetPt[HfJetTagging::numPass];
  TH1F* projTrackPt[HfJetTagging::numPass];
  TH1F* projTrackEta[HfJetTagging::numPass];
  TH1F* projTrackPhi[HfJetTagging::numPass];
  TH1F* projSignImpXYSig[HfJetTagging::numPass];
  TH1F* proj2ProngLxy[HfJetTagging::numPass];
  TH1F* proj2ProngLxyz[HfJetTagging::numPass];
  TH1F* proj2ProngsigmaLxy[HfJetTagging::numPass];
  TH1F* proj2ProngsigmaLxyz[HfJetTagging::numPass];
  TH1F* proj2ProngSxy[HfJetTagging::numPass];
  TH1F* proj2ProngSxyz[HfJetTagging::numPass];

  for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    for (int pass=0; pass<HfJetTagging::numPass; pass++) {
      projJetPt[pass] = reinterpret_cast<TH1F*> (h2simTagjetPtFlavour[pass]->ProjectionX(Form("projJetPt_%d_%d", binFlavour, pass), binFlavour, binFlavour));
      projTrackPt[pass] = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPtFlavour[pass]->ProjectionY(Form("projTrackPt_%d_%d", binFlavour, pass), 1, h3simTagjetPtTrackPtFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
      projTrackEta[pass] = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour[pass]->ProjectionY(Form("projTrackEta_%d_%d", binFlavour, pass), 1, h3simTagjetPtTrackEtaFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
      projTrackPhi[pass] = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPhiFlavour[pass]->ProjectionY(Form("projTrackPhi_%d_%d", binFlavour, pass), 1, h3simTagjetPtTrackPhiFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
      projSignImpXYSig[pass] = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYSigFlavour[pass]->ProjectionY(Form("projSignImpXYSig_%d_%d", binFlavour, pass), 1, h3simTagjetPtSignImpXYSigFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
//      proj2ProngLxy[pass] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyFlavour[pass]->ProjectionY(Form("proj2ProngLxy_%d_%d", binFlavour, pass), 1, h3simTagjetPt2ProngLxyFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
//      proj2ProngLxyz[pass] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyzFlavour[pass]->ProjectionY(Form("proj2ProngLxyz_%d_%d", binFlavour, pass), 1, h3simTagjetPt2ProngLxyzFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
//      proj2ProngsigmaLxy[pass] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyFlavour[pass]->ProjectionY(Form("proj2ProngsigmaLxy_%d_%d", binFlavour, pass), 1, h3simTagjetPt2ProngsigmaLxyFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
//      proj2ProngsigmaLxyz[pass] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyzFlavour[pass]->ProjectionY(Form("proj2ProngsigmaLxyz_%d_%d", binFlavour, pass), 1, h3simTagjetPt2ProngsigmaLxyzFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
//      proj2ProngSxy[pass] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyFlavour[pass]->ProjectionY(Form("proj2ProngSxy_%d_%d", binFlavour, pass), 1, h3simTagjetPt2ProngSxyFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
//      proj2ProngSxyz[pass] = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyzFlavour[pass]->ProjectionY(Form("proj2ProngSxyz_%d_%d", binFlavour, pass), 1, h3simTagjetPt2ProngSxyzFlavour[pass]->GetNbinsX(), binFlavour, binFlavour));
      
      // inclusive
      hsimTagjetTrackPt[0][pass]->Add(projTrackPt[pass]);
      hsimTagjetTrackEta[0][pass]->Add(projTrackEta[pass]);
      hsimTagjetTrackPhi[0][pass]->Add(projTrackPhi[pass]);
      hsimTagjetSignImpXYSig[0][pass]->Add(projSignImpXYSig[pass]);
//      hsimTagjet2ProngLxy[0][pass]->Add(proj2ProngLxy[pass]);
//      hsimTagjet2ProngLxyz[0][pass]->Add(proj2ProngLxyz[pass]);
//      hsimTagjet2ProngsigmaLxy[0][pass]->Add(proj2ProngsigmaLxy[pass]);
//      hsimTagjet2ProngsigmaLxyz[0][pass]->Add(proj2ProngsigmaLxyz[pass]);
//      hsimTagjet2ProngSxy[0][pass]->Add(proj2ProngSxy[pass]);
//      hsimTagjet2ProngSxyz[0][pass]->Add(proj2ProngSxyz[pass]);

      // jet flavour
      hsimTagjetTrackPt[flavour][pass] = reinterpret_cast<TH1F*>(projTrackPt[pass]->Clone());
      hsimTagjetTrackEta[flavour][pass] = reinterpret_cast<TH1F*>(projTrackEta[pass]->Clone());
      hsimTagjetTrackPhi[flavour][pass] = reinterpret_cast<TH1F*>(projTrackPhi[pass]->Clone());
      hsimTagjetSignImpXYSig[flavour][pass] = reinterpret_cast<TH1F*>(projSignImpXYSig[pass]->Clone());
//      hsimTagjet2ProngLxy[flavour][pass] = reinterpret_cast<TH1F*>(proj2ProngLxy[pass]->Clone());
//      hsimTagjet2ProngLxyz[flavour][pass] = reinterpret_cast<TH1F*>(proj2ProngLxyz[pass]->Clone());
//      hsimTagjet2ProngsigmaLxy[flavour][pass] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxy[pass]->Clone());
//      hsimTagjet2ProngsigmaLxyz[flavour][pass] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyz[pass]->Clone());
//      hsimTagjet2ProngSxy[flavour][pass] = reinterpret_cast<TH1F*>(proj2ProngSxy[pass]->Clone());
//      hsimTagjet2ProngSxyz[flavour][pass] = reinterpret_cast<TH1F*>(proj2ProngSxyz[pass]->Clone());
      //std::cout<<hsimTagjetTrackEntries[pass]->GetBinContent(flavour) << std::endl;
    }
  }
}

void HfJetTaggingSysPassAnalysis::normalizedHistogramPass() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int pass =0; pass < HfJetTagging::numPass; pass++) {
      hsimTagjetNormalizedTrackPt[flavour][pass] = (TH1F*) hsimTagjetTrackPt[flavour][pass]->Clone(Form("hsimTagjetNormalizedTrackPt_%d_%d", flavour, pass));
      hsimTagjetNormalizedTrackEta[flavour][pass] = (TH1F*) hsimTagjetTrackEta[flavour][pass]->Clone(Form("hsimTagjetNormalizedTrackEta_%d_%d", flavour, pass));
      hsimTagjetNormalizedTrackPhi[flavour][pass] = (TH1F*) hsimTagjetTrackPhi[flavour][pass]->Clone(Form("hsimTagjetNormalizedTrackPhi_%d_%d", flavour, pass));
      hsimTagjetNormalizedSignImpXYSig[flavour][pass] = (TH1F*) hsimTagjetSignImpXYSig[flavour][pass]->Clone(Form("hsimTagjetNormalizedSignImpXYSig_%d_%d", flavour, pass));
//      hsimTagjetNormalized2ProngLxy[flavour][pass] = (TH1F*) hsimTagjet2ProngLxy[flavour][pass]->Clone(Form("hsimTagjetNormalized2ProngLxy_%d_%d", flavour, pass));
//      hsimTagjetNormalized2ProngLxyz[flavour][pass] = (TH1F*) hsimTagjet2ProngLxyz[flavour][pass]->Clone(Form("hsimTagjetNormalized2ProngLxyz_%d_%d", flavour, pass));
//      hsimTagjetNormalized2ProngsigmaLxy[flavour][pass] = (TH1F*) hsimTagjet2ProngsigmaLxy[flavour][pass]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxy_%d_%d", flavour, pass));
//      hsimTagjetNormalized2ProngsigmaLxyz[flavour][pass] = (TH1F*) hsimTagjet2ProngsigmaLxyz[flavour][pass]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxyz_%d_%d", flavour, pass));
//      hsimTagjetNormalized2ProngSxy[flavour][pass] = (TH1F*) hsimTagjet2ProngSxy[flavour][pass]->Clone(Form("hsimTagjetNormalized2ProngSxy_%d_%d", flavour, pass));
//      hsimTagjetNormalized2ProngSxyz[flavour][pass] = (TH1F*) hsimTagjet2ProngSxyz[flavour][pass]->Clone(Form("hsimTagjetNormalized2ProngSxyz_%d_%d", flavour, pass));

      hsimTagjetNormalizedTrackPt[flavour][pass]->Scale(1. / hsimTagjetNormalizedTrackPt[flavour][pass]->GetEntries());
      hsimTagjetNormalizedTrackEta[flavour][pass]->Scale(1. / hsimTagjetNormalizedTrackEta[flavour][pass]->GetEntries());
      hsimTagjetNormalizedTrackPhi[flavour][pass]->Scale(1. / hsimTagjetNormalizedTrackPhi[flavour][pass]->GetEntries());
      hsimTagjetNormalizedSignImpXYSig[flavour][pass]->Scale(1. / hsimTagjetNormalizedSignImpXYSig[flavour][pass]->GetEntries());
//      hsimTagjetNormalized2ProngLxy[flavour][pass]->Scale(1. / hsimTagjetNormalized2ProngLxy[flavour][pass]->GetEntries());
//      hsimTagjetNormalized2ProngLxyz[flavour][pass]->Scale(1. / hsimTagjetNormalized2ProngLxyz[flavour][pass]->GetEntries());
//      hsimTagjetNormalized2ProngsigmaLxy[flavour][pass]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxy[flavour][pass]->GetEntries());
//      hsimTagjetNormalized2ProngsigmaLxyz[flavour][pass]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxyz[flavour][pass]->GetEntries());
//      hsimTagjetNormalized2ProngSxy[flavour][pass]->Scale(1. / hsimTagjetNormalized2ProngSxy[flavour][pass]->GetEntries());
//      hsimTagjetNormalized2ProngSxyz[flavour][pass]->Scale(1. / hsimTagjetNormalized2ProngSxyz[flavour][pass]->GetEntries());
    }
  }
  for (int pass =0; pass < HfJetTagging::numPass; pass++) {
    hsimTagjetNormalizedEntries[pass] = (TH1F*) hsimTagjetEntries[pass]->Clone(Form("hsimTagjetNoramlizedEntries_%d", pass));
    hsimTagjetNormalizedEntries[pass]->Scale(1. / (hsimTagjetEntries[pass]->GetBinContent(1)+hsimTagjetEntries[pass]->GetBinContent(2)+hsimTagjetEntries[pass]->GetBinContent(3)));
    hsimTagjetNormalizedTrackEntries[pass] = (TH1F*) hsimTagjetTrackEntries[pass]->Clone(Form("hsimTagjetNormalizedTrackEntries_%d", pass));
    hsimTagjetNormalizedTrackEntries[pass]->Scale(1. / (hsimTagjetTrackEntries[pass]->GetBinContent(1)+hsimTagjetTrackEntries[pass]->GetBinContent(2)+hsimTagjetTrackEntries[pass]->GetBinContent(3)));
  }
}

void HfJetTaggingSysPassAnalysis::saveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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
    for (int pass =0; pass < HfJetTagging::numPass; pass++) {
      hsimTagjetEntries[pass]->Write();
      hsimTagjetNormalizedEntries[pass]->Write();
    }
  }

}

void HfJetTaggingSysPassAnalysis::drawIncJetTrackPtPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPt[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/trackmomentum.pdf\")", cn++));

}

void HfJetTaggingSysPassAnalysis::drawIncJetTrackEtaPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackEta[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/tracketa.pdf\")", cn++));

}

void HfJetTaggingSysPassAnalysis::drawIncJetTrackPhiPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPhi[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/trackphi.pdf\")", cn++));

}

void HfJetTaggingSysPassAnalysis::drawIncJetSignImpXYSigPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.3, 0.90, "Inclusive jet (MC)");
  latex.DrawLatex(0.3, 0.85, "Charged jet");
  latex.DrawLatex(0.3, 0.80, "p_{T}^{jet} > 10 GeV/c");
  latex.DrawLatex(0.3, 0.75, "R=0.4");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/signImpXYSig.pdf\")", cn++));
}

//void HfJetTaggingSysPassAnalysis::drawIncJet2ProngLxyPass(bool doLog = true, int Num = HfJetTagging::numPass) {
//  std::vector<HistogramData> NormHistList;
//  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
//    NormHistList.push_back({hsimTagjetNormalized2ProngLxy[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
//  }
//  canHan = new CanvasHandler();
//  canHan->createCanvas(cn);
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
//  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/2ProngLxy.pdf\")", cn++));
//
//}
//
//void HfJetTaggingSysPassAnalysis::drawIncJet2ProngLxyzPass(bool doLog = true, int Num = HfJetTagging::numPass) {
//  std::vector<HistogramData> NormHistList;
//  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
//    NormHistList.push_back({hsimTagjetNormalized2ProngLxyz[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
//  }
//  canHan = new CanvasHandler();
//  canHan->createCanvas(cn);
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
//  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/2ProngLxyz.pdf\")", cn++));
//
//}
//
//void HfJetTaggingSysPassAnalysis::drawIncJet2ProngsigmaLxyPass(bool doLog = true, int Num = HfJetTagging::numPass) {
//  std::vector<HistogramData> NormHistList;
//  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
//    NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxy[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
//  }
//  canHan = new CanvasHandler();
//  canHan->createCanvas(cn);
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::sigmaLXY[0], HfJetTagging::REFHIST::sigmaLXY[1], HfJetTagging::REFHIST::sigmaLXY[2], HfJetTagging::REFHIST::sigmaLXY[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
//  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/2ProngsigmaLxy.pdf\")", cn++));
//
//}
//
//void HfJetTaggingSysPassAnalysis::drawIncJet2ProngsigmaLxyzPass(bool doLog = true, int Num = HfJetTagging::numPass) {
//  std::vector<HistogramData> NormHistList;
//  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
//    NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyz[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
//  }
//  canHan = new CanvasHandler();
//  canHan->createCanvas(cn);
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::sigmaLXYZ[0], HfJetTagging::REFHIST::sigmaLXYZ[1], HfJetTagging::REFHIST::sigmaLXYZ[2], HfJetTagging::REFHIST::sigmaLXYZ[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
//  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/2ProngsigmaLxyz.pdf\")", cn++));
//
//}
//
//void HfJetTaggingSysPassAnalysis::drawIncJet2ProngSxyPass(bool doLog = true, int Num = HfJetTagging::numPass) {
//  std::vector<HistogramData> NormHistList;
//  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
//    NormHistList.push_back({hsimTagjetNormalized2ProngSxy[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
//  }
//  canHan = new CanvasHandler();
//  canHan->createCanvas(cn);
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
//  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/2ProngSxy.pdf\")", cn++));
//
//}
//
//void HfJetTaggingSysPassAnalysis::drawIncJet2ProngSxyzPass(bool doLog = true, int Num = HfJetTagging::numPass) {
//  std::vector<HistogramData> NormHistList;
//  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
//    NormHistList.push_back({hsimTagjetNormalized2ProngSxyz[0][pass], HfJetTagging::SYS::PASS[pass]}); // 0: inclusive
//  }
//  canHan = new CanvasHandler();
//  canHan->createCanvas(cn);
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
//  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/incjet/pass/2ProngSxyz.pdf\")", cn++));
//
//}

void HfJetTaggingSysPassAnalysis::drawCharmJetSignImpXYSigPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[1][pass], HfJetTagging::SYS::PASS[pass]}); // 1: charm
  }
  int num = hsimTagjetNormalizedSignImpXYSig[1][1]->GetEntries();
  std::cout << "charm jet entri: " << num << std::endl;
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.3, 0.90, "Charm jet (MC)");
  latex.DrawLatex(0.3, 0.85, "Charged jet");
  latex.DrawLatex(0.3, 0.80, "p_{T}^{jet} > 10 GeV/c");
  latex.DrawLatex(0.3, 0.75, "R=0.4");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/cjet/pass/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysPassAnalysis::drawBeautyJetSignImpXYSigPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[2][pass], HfJetTagging::SYS::PASS[pass]}); // 2: Beauty
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.3, 0.90, "Beauty jet (MC)");
  latex.DrawLatex(0.3, 0.85, "Charged jet");
  latex.DrawLatex(0.3, 0.80, "p_{T}^{jet} > 10 GeV/c");
  latex.DrawLatex(0.3, 0.75, "R=0.4");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/pass/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysPassAnalysis::drawLfJetSignImpXYSigPass(bool doLog = true, int Num = HfJetTagging::numPass) {
  std::vector<HistogramData> NormHistList;
  for (int pass =0; pass<HfJetTagging::numPass; pass++) {
    NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[2][pass], HfJetTagging::SYS::PASS[pass]}); // 2: Lf
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(cn, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  canHan->drawCombined(NormHistList.size(), NormHistList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.3, 0.90, "light flavour jet (MC)");
  latex.DrawLatex(0.3, 0.85, "Charged jet");
  latex.DrawLatex(0.3, 0.80, "p_{T}^{jet} > 10 GeV/c");
  latex.DrawLatex(0.3, 0.75, "R=0.4");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/pass/signImpXYSig.pdf\")", cn++));
}

void HfJetTaggingSysPassAnalysis::drawTagJetEntriesPass(int Num = HfJetTagging::numPass) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e+1, 1e+10, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int pass = 0; pass < HfJetTagging::numPass; pass++) {
    hsimTagjetEntries[pass]->SetLineColor(pass+1); // Set different colors
    hs->Add(hsimTagjetEntries[pass]);
    legend->AddEntry(hsimTagjetEntries[pass], HfJetTagging::SYS::PASS[pass], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/pass/jetentries.pdf\")", cn++));
}

void HfJetTaggingSysPassAnalysis::drawTagJetNormEntriesPass(int Num = HfJetTagging::numPass) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e-2, 1.0, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int pass = 0; pass < HfJetTagging::numPass; pass++) {
    hsimTagjetNormalizedEntries[pass]->SetLineColor(pass+1); // Set different colors
    hs->Add(hsimTagjetNormalizedEntries[pass]);
    legend->AddEntry(hsimTagjetNormalizedEntries[pass], HfJetTagging::SYS::PASS[pass], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/pass/normJetentries.pdf\")", cn++));
}

void HfJetTaggingSysPassAnalysis::drawTagJetTrackEntriesPass(int Num = HfJetTagging::numPass) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e+1, 1e+10, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int pass = 0; pass < HfJetTagging::numPass; pass++) {
    hsimTagjetTrackEntries[pass]->SetLineColor(pass+1); // Set different colors
    hs->Add(hsimTagjetTrackEntries[pass]);
    legend->AddEntry(hsimTagjetTrackEntries[pass], HfJetTagging::SYS::PASS[pass], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/pass/trackentries.pdf\")", cn++));
}

void HfJetTaggingSysPassAnalysis::drawTagJetNormTrackEntriesPass(int Num = HfJetTagging::numPass) {
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, 0, 5, 1e-2, 1.0, "flavour", "Entries");
  THStack *hs = new THStack("hs","Stacked histograms");
  TLegend *legend = new TLegend(HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  // Assuming hsimTagjetEntries is an array/vector of TH1F*
  for (int pass = 0; pass < HfJetTagging::numPass; pass++) {
    hsimTagjetNormalizedTrackEntries[pass]->SetLineColor(pass+1); // Set different colors
    hs->Add(hsimTagjetNormalizedTrackEntries[pass]);
    legend->AddEntry(hsimTagjetNormalizedTrackEntries[pass], HfJetTagging::SYS::PASS[pass], "l");
  }
  hs->Draw("same nostack"); // Use "nostack" to overlay without stacking
  legend->Draw();
  gPad->SetLogy();
  gPad->Modified();
  gPad->Update();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/lfjet/pass/normTrackentries.pdf\")", cn++));
}

#endif // HFJETTAGGINGSYSPASSANALYSIS_H
