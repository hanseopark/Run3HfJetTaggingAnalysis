#ifndef HFJETTAGGINGSVANALYSIS_H
#define HFJETTAGGINGSVANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"
//#include "JetAnalysis.h"

class HfJetTaggingSVAnalysis {
  public:
    HfJetTaggingSVAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMC, TString triggerNAME, bool dopartLevel) {
      InitConfig(triggerNAME.Data());
      if (doData) {
        if (!LoadDataSVQA(rootData.Data())) {
          return;
        }
        InitHistogramForNormalizationSVQAData();
        ProjectionHistSVQAData();
        NormalizedHistogramSVQAData();
      }
      if (doMC) {
        if (!LoadSimSVQA(rootSim.Data())) {
          return;
        }
        std::cout<<__LINE__<<std::endl;
        InitHistogramForNormalizationSVQAMC();
        std::cout<<__LINE__<<std::endl;
        ProjectionHistSVQAMC();
        std::cout<<__LINE__<<std::endl;
        NormalizedHistogramSVQAMC();
      }
      SaveHistogramSVQA("SVQA.root", doData, doMC, dopartLevel);

    }
    ~HfJetTaggingSVAnalysis();

    void InitConfig(TString triggerNAME);
    int LoadDataSVQA(TString rootData);
    int LoadSimSVQA(TString rootSim);
    void InitHistogramForNormalizationSVQAData();
    void InitHistogramForNormalizationSVQAMC();
    void ProjectionHistSVQAData();
    void ProjectionHistSVQAMC();
    void NormalizedHistogramSVQAData();
    void NormalizedHistogramSVQAMC();
    void SaveHistogramSVQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // Draw
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    std::vector<HistogramData> histList;
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool withLeg, double legendxmin, double ymin, double xmax, double ymax);

    int canvasNum = 0;
    CanvasHandler* canvasHandler;
    void DrawTaggedJet2ProngLxy(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngLxyz(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngSxy(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngSxyz(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngRawLxy(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngRawLxyz(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngRawSxy(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngRawSxyz(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngRawsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngRawsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJet2ProngSxyCutsigmaLxy(bool withInc, bool doLog);
    void DrawTaggedJet2ProngsigmaLxyCutSxy(bool withInc, bool doLog);

  protected:
    TH3F* h3simTagjetPt2ProngLxyFlavour;
    TH3F* h3simTagjetPt2ProngLxyzFlavour;
    TH3F* h3simTagjetPt2ProngSxyFlavour;
    TH3F* h3simTagjetPt2ProngSxyzFlavour;
    TH3F* h3simTagjetPt2ProngsigmaLxyFlavour;
    TH3F* h3simTagjetPt2ProngsigmaLxyzFlavour;
    TH3F* h3simTagjetPt3ProngLxyFlavour;
    TH3F* h3simTagjetPt3ProngLxyzFlavour;
    TH3F* h3simTagjetPt3ProngSxyFlavour;
    TH3F* h3simTagjetPt3ProngSxyzFlavour;
    TH3F* h3simTagjet2ProngSxysigmaLxyFlavour;
    TH3F* h3simTagjet2ProngSxyzsigmaLxyzFlavour;
    TH1F* hsimTagjet2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet2ProngSxyCutsigmaLxy[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjet2ProngsigmaLxyCutSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjet2ProngSxyzCutsigmaLxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjet2ProngsigmaLxyzCutSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjet3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjet3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized2ProngSxyCutsigmaLxy[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjetNormalized2ProngsigmaLxyCutSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjetNormalized2ProngSxyzCutsigmaLxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjetNormalized2ProngsigmaLxyzCutSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjetNormalized3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalized3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  private:
    TLatex latex;
    TString triggerName;

};

HfJetTaggingSVAnalysis::~HfJetTaggingSVAnalysis() {
  if (h3simTagjetPt2ProngLxyFlavour) delete h3simTagjetPt2ProngLxyFlavour;
  if (h3simTagjetPt2ProngLxyzFlavour) delete h3simTagjetPt2ProngLxyzFlavour;
  if (h3simTagjetPt2ProngSxyFlavour) delete h3simTagjetPt2ProngSxyFlavour;
  if (h3simTagjetPt2ProngSxyzFlavour) delete h3simTagjetPt2ProngSxyzFlavour;
  if (h3simTagjetPt2ProngsigmaLxyFlavour) delete h3simTagjetPt2ProngsigmaLxyFlavour;
  if (h3simTagjetPt2ProngsigmaLxyzFlavour) delete h3simTagjetPt2ProngsigmaLxyzFlavour;
  if (h3simTagjetPt3ProngLxyFlavour) delete h3simTagjetPt3ProngLxyFlavour;
  if (h3simTagjetPt3ProngLxyzFlavour) delete h3simTagjetPt3ProngLxyzFlavour;
  if (h3simTagjetPt3ProngSxyFlavour) delete h3simTagjetPt3ProngSxyFlavour;
  if (h3simTagjetPt3ProngSxyzFlavour) delete h3simTagjetPt3ProngSxyzFlavour;
  if (h3simTagjet2ProngSxysigmaLxyFlavour) delete h3simTagjet2ProngSxysigmaLxyFlavour;
  if (h3simTagjet2ProngSxyzsigmaLxyzFlavour) delete h3simTagjet2ProngSxyzsigmaLxyzFlavour;

  for (int flavour = 0; flavour < HfJetTagging::nFlavour + 1; ++flavour) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt + 1; ++jetPt) {
      if (hsimTagjet2ProngLxy[flavour][jetPt]) delete hsimTagjet2ProngLxy[flavour][jetPt];
      if (hsimTagjet2ProngLxyz[flavour][jetPt]) delete hsimTagjet2ProngLxyz[flavour][jetPt];
      if (hsimTagjet2ProngSxy[flavour][jetPt]) delete hsimTagjet2ProngSxy[flavour][jetPt];
      if (hsimTagjet2ProngSxyz[flavour][jetPt]) delete hsimTagjet2ProngSxyz[flavour][jetPt];
      if (hsimTagjet2ProngsigmaLxy[flavour][jetPt]) delete hsimTagjet2ProngsigmaLxy[flavour][jetPt];
      if (hsimTagjet2ProngsigmaLxyz[flavour][jetPt]) delete hsimTagjet2ProngsigmaLxyz[flavour][jetPt];
      if (hsimTagjet3ProngLxy[flavour][jetPt]) delete hsimTagjet3ProngLxy[flavour][jetPt];
      if (hsimTagjet3ProngLxyz[flavour][jetPt]) delete hsimTagjet3ProngLxyz[flavour][jetPt];
      if (hsimTagjet3ProngSxy[flavour][jetPt]) delete hsimTagjet3ProngSxy[flavour][jetPt];
      if (hsimTagjet3ProngSxyz[flavour][jetPt]) delete hsimTagjet3ProngSxyz[flavour][jetPt];
      if (hsimTagjetNormalized2ProngLxy[flavour][jetPt]) delete hsimTagjetNormalized2ProngLxy[flavour][jetPt];
      if (hsimTagjetNormalized2ProngLxyz[flavour][jetPt]) delete hsimTagjetNormalized2ProngLxyz[flavour][jetPt];
      if (hsimTagjetNormalized2ProngSxy[flavour][jetPt]) delete hsimTagjetNormalized2ProngSxy[flavour][jetPt];
      if (hsimTagjetNormalized2ProngSxyz[flavour][jetPt]) delete hsimTagjetNormalized2ProngSxyz[flavour][jetPt];
      if (hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt]) delete hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt];
      if (hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt]) delete hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt];
      if (hsimTagjetNormalized3ProngLxy[flavour][jetPt]) delete hsimTagjetNormalized3ProngLxy[flavour][jetPt];
      if (hsimTagjetNormalized3ProngLxyz[flavour][jetPt]) delete hsimTagjetNormalized3ProngLxyz[flavour][jetPt];
      if (hsimTagjetNormalized3ProngSxy[flavour][jetPt]) delete hsimTagjetNormalized3ProngSxy[flavour][jetPt];
      if (hsimTagjetNormalized3ProngSxyz[flavour][jetPt]) delete hsimTagjetNormalized3ProngSxyz[flavour][jetPt];
    }
  }
}

void HfJetTaggingSVAnalysis::InitConfig(TString triggerNAME) {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  triggerName=triggerNAME.Data();

  //TString dirData = Form("fig/data/%s/sv", triggerName.Data());
  //gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  TString dirSim = Form("fig/sim/%s/sv", SIMSET.Data());
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSVAnalysis::LoadDataSVQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, SV QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-tc-charged";

  return 1;
}

int HfJetTaggingSVAnalysis::LoadSimSVQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, SV QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  h3simTagjetPt2ProngLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxy_flavour", taskName.Data())));
  h3simTagjetPt2ProngLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxyz_flavour", taskName.Data())));
  h3simTagjetPt2ProngSxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxy_flavour", taskName.Data())));
  h3simTagjetPt2ProngSxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxyz_flavour", taskName.Data())));
  h3simTagjetPt2ProngsigmaLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxy_flavour", taskName.Data())));
  h3simTagjetPt2ProngsigmaLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxyz_flavour", taskName.Data())));
  h3simTagjet2ProngSxysigmaLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_2prong_Sxy_sigmaLxy_flavour", taskName.Data())));
  h3simTagjet2ProngSxyzsigmaLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_2prong_Sxyz_sigmaLxyz_flavour", taskName.Data())));

  std::cout << "Load completed SV MC data" << std::endl;
  return 1;
}

void HfJetTaggingSVAnalysis::InitHistogramForNormalizationSVQAData() {
}

void HfJetTaggingSVAnalysis::InitHistogramForNormalizationSVQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimTagjet2ProngSxyCutsigmaLxy[flavour] = new TH1F(Form("hsimTagjet2ProngSxyCutsigmaLxy_%d", flavour), "", h3simTagjet2ProngSxysigmaLxyFlavour->GetNbinsX(), h3simTagjet2ProngSxysigmaLxyFlavour->GetXaxis()->GetBinLowEdge(1), h3simTagjet2ProngSxysigmaLxyFlavour->GetXaxis()->GetBinUpEdge(h3simTagjet2ProngSxysigmaLxyFlavour->GetNbinsX()));
		hsimTagjet2ProngsigmaLxyCutSxy[flavour] = new TH1F(Form("hsimTagjet2ProngsigmaLxyCutSxy_%d", flavour), "", h3simTagjet2ProngSxysigmaLxyFlavour->GetNbinsY(), h3simTagjet2ProngSxysigmaLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjet2ProngSxysigmaLxyFlavour->GetYaxis()->GetBinUpEdge(h3simTagjet2ProngSxysigmaLxyFlavour->GetNbinsY()));
		hsimTagjet2ProngSxyzCutsigmaLxyz[flavour] = new TH1F(Form("hsimTagjet2ProngSxyzCutsigmaLxyz_%d", flavour), "", h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetNbinsX(), h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetXaxis()->GetBinLowEdge(1), h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetXaxis()->GetBinUpEdge(h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetNbinsX()));
		hsimTagjet2ProngsigmaLxyzCutSxyz[flavour] = new TH1F(Form("hsimTagjet2ProngsigmaLxyzCutSxyz_%d", flavour), "", h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetNbinsY(), h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simTagjet2ProngSxyzsigmaLxyzFlavour->GetNbinsY()));
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjet2ProngLxy[flavour][jetPt] = new TH1F(Form("hsimTagjet2ProngLxy_%d_%d", flavour, jetPt), "", h3simTagjetPt2ProngLxyFlavour->GetNbinsY(), h3simTagjetPt2ProngLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngLxyFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngLxyFlavour->GetNbinsY()));
			hsimTagjet2ProngLxyz[flavour][jetPt] = new TH1F(Form("hsimTagjet2ProngLxyz_%d_%d", flavour, jetPt), "", h3simTagjetPt2ProngLxyzFlavour->GetNbinsY(), h3simTagjetPt2ProngLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngLxyzFlavour->GetNbinsY()));
			hsimTagjet2ProngSxy[flavour][jetPt] = new TH1F(Form("hsimTagjet2ProngSxy_%d_%d", flavour, jetPt), "", h3simTagjetPt2ProngSxyFlavour->GetNbinsY(), h3simTagjetPt2ProngSxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngSxyFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngSxyFlavour->GetNbinsY()));
			hsimTagjet2ProngSxyz[flavour][jetPt] = new TH1F(Form("hsimTagjet2ProngSxyz_%d_%d", flavour, jetPt), "", h3simTagjetPt2ProngSxyzFlavour->GetNbinsY(), h3simTagjetPt2ProngSxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngSxyzFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngSxyzFlavour->GetNbinsY()));
			hsimTagjet2ProngsigmaLxy[flavour][jetPt] = new TH1F(Form("hsimTagjet2ProngsigmaLxy_%d_%d", flavour, jetPt), "", h3simTagjetPt2ProngsigmaLxyFlavour->GetNbinsY(), h3simTagjetPt2ProngsigmaLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngsigmaLxyFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngsigmaLxyFlavour->GetNbinsY()));
			hsimTagjet2ProngsigmaLxyz[flavour][jetPt] = new TH1F(Form("hsimTagjet2ProngsigmaLxyz_%d_%d", flavour, jetPt), "", h3simTagjetPt2ProngsigmaLxyzFlavour->GetNbinsY(), h3simTagjetPt2ProngsigmaLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPt2ProngsigmaLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPt2ProngsigmaLxyzFlavour->GetNbinsY()));
    }
  }
}

void HfJetTaggingSVAnalysis::ProjectionHistSVQAData() {
}

void HfJetTaggingSVAnalysis::ProjectionHistSVQAMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
		TH1F* proj2ProngLxy = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyFlavour->ProjectionY(Form("proj2ProngLxy_%d", binFlavour), 1, h3simTagjetPt2ProngLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* proj2ProngLxyz = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyzFlavour->ProjectionY(Form("proj2ProngLxyz_%d", binFlavour), 1, h3simTagjetPt2ProngLxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* proj2ProngSxy = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyFlavour->ProjectionY(Form("proj2ProngSxy_%d", binFlavour), 1, h3simTagjetPt2ProngSxyFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* proj2ProngSxyz = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyzFlavour->ProjectionY(Form("proj2ProngSxyz_%d", binFlavour), 1, h3simTagjetPt2ProngSxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* proj2ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyFlavour->ProjectionY(Form("proj2ProngsigmaLxy_%d", binFlavour), 1, h3simTagjetPt2ProngsigmaLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* proj2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyzFlavour->ProjectionY(Form("proj2ProngsigmaLxyz_%d", binFlavour), 1, h3simTagjetPt2ProngsigmaLxyzFlavour->GetNbinsX(), binFlavour, binFlavour));

		hsimTagjet2ProngLxy[0][0]->Add(proj2ProngLxy);
		hsimTagjet2ProngLxyz[0][0]->Add(proj2ProngLxyz);
		hsimTagjet2ProngLxy[0][0]->Add(proj2ProngLxy);
		hsimTagjet2ProngLxyz[0][0]->Add(proj2ProngLxyz);
		hsimTagjet2ProngsigmaLxy[0][0]->Add(proj2ProngsigmaLxy);
		hsimTagjet2ProngsigmaLxyz[0][0]->Add(proj2ProngsigmaLxyz);
		hsimTagjet2ProngLxy[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngLxy->Clone(Form("hsimTagjet2ProngLxy_%d_0", flavour)));
		hsimTagjet2ProngLxyz[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngLxyz->Clone(Form("hsimTagjet2ProngLxyz_%d_0", flavour)));
		hsimTagjet2ProngSxy[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngSxy->Clone(Form("hsimTagjet2ProngSxy_%d_0", flavour)));
		hsimTagjet2ProngSxyz[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngSxyz->Clone(Form("hsimTagjet2ProngSxyz_%d_0", flavour)));
		hsimTagjet2ProngsigmaLxy[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxy->Clone(Form("hsimTagjet2ProngsigmaLxy_%d_0", flavour)));
		hsimTagjet2ProngsigmaLxyz[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyz->Clone(Form("hsimTagjet2ProngsigmaLxyz_%d_0", flavour)));

    int cutbin2ProngsigmaLxy = h3simTagjet2ProngSxysigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::CUT::sigmaLxy);
		TH1F* proj2ProngSxyCutsigmaLxy = reinterpret_cast<TH1F*> (h3simTagjet2ProngSxysigmaLxyFlavour->ProjectionX(Form("proj2ProngSxyCutsigmaLxy_%d", binFlavour), 1, cutbin2ProngsigmaLxy, binFlavour, binFlavour));
		hsimTagjet2ProngSxyCutsigmaLxy[flavour] = reinterpret_cast<TH1F*>(proj2ProngSxyCutsigmaLxy->Clone(Form("hsimTagjet2ProngSxyCutsigmaLxy_%d", flavour))); 
    hsimTagjet2ProngSxyCutsigmaLxy[flavour]->Add(proj2ProngSxyCutsigmaLxy);

    int cutbin2ProngSxy = h3simTagjet2ProngSxysigmaLxyFlavour->GetYaxis()->FindBin(HfJetTagging::CUT::Sxy);
		TH1F* proj2ProngsigmaLxyCutSxy = reinterpret_cast<TH1F*> (h3simTagjet2ProngSxysigmaLxyFlavour->ProjectionY(Form("proj2ProngsigmaLxyCutSxy_%d", binFlavour), cutbin2ProngSxy, h3simTagjet2ProngSxysigmaLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
		hsimTagjet2ProngsigmaLxyCutSxy[flavour] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyCutSxy->Clone(Form("hsimTagjet2ProngsigmaLxyCutSxy_%d", flavour))); 
    hsimTagjet2ProngsigmaLxyCutSxy[flavour]->Add(proj2ProngsigmaLxyCutSxy);

		for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
			int leftbinJetPt2ProngLxy = h3simTagjetPt2ProngLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPt2ProngLxy = h3simTagjetPt2ProngLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRange2ProngLxy = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyFlavour->ProjectionY(Form("projJetPtRange2ProngLxy_%d_%d", binJetPt, flavour), leftbinJetPt2ProngLxy, rightbinJetPt2ProngLxy, binFlavour, binFlavour));
			hsimTagjet2ProngLxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxy->Clone(Form("hsimTagjet2ProngLxy_%d_%d", flavour, binJetPt))); 
			hsimTagjet2ProngLxy[0][binJetPt]->Add(projJetPtRange2ProngLxy);

			int leftbinJetPt2ProngLxyz = h3simTagjetPt2ProngLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPt2ProngLxyz = h3simTagjetPt2ProngLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRange2ProngLxyz = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngLxyzFlavour->ProjectionY(Form("projJetPtRange2ProngLxyz_%d_%d", binJetPt, flavour), leftbinJetPt2ProngLxyz, rightbinJetPt2ProngLxyz, binFlavour, binFlavour));
			hsimTagjet2ProngLxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxyz->Clone(Form("hsimTagjet2ProngLxyz_%d_%d", flavour, binJetPt))); 
			hsimTagjet2ProngLxyz[0][binJetPt]->Add(projJetPtRange2ProngLxyz);

      int leftbinJetPt2ProngSxy = h3simTagjetPt2ProngSxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPt2ProngSxy = h3simTagjetPt2ProngSxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRange2ProngSxy = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyFlavour->ProjectionY(Form("projJetPtRange2ProngSxy_%d_%d", binJetPt, flavour), leftbinJetPt2ProngSxy, rightbinJetPt2ProngSxy, binFlavour, binFlavour));
			hsimTagjet2ProngSxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxy->Clone(Form("hsimTagjet2ProngSxy_%d_%d", flavour, binJetPt))); 
			hsimTagjet2ProngSxy[0][binJetPt]->Add(projJetPtRange2ProngSxy);

			int leftbinJetPt2ProngSxyz = h3simTagjetPt2ProngSxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPt2ProngSxyz = h3simTagjetPt2ProngSxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRange2ProngSxyz = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngSxyzFlavour->ProjectionY(Form("projJetPtRange2ProngSxyz_%d_%d", binJetPt, flavour), leftbinJetPt2ProngSxyz, rightbinJetPt2ProngSxyz, binFlavour, binFlavour));
			hsimTagjet2ProngSxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyz->Clone(Form("hsimTagjet2ProngSxyz_%d_%d", flavour, binJetPt))); 
			hsimTagjet2ProngSxyz[0][binJetPt]->Add(projJetPtRange2ProngSxyz);

			int leftbinJetPt2ProngsigmaLxy = h3simTagjetPt2ProngsigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPt2ProngsigmaLxy = h3simTagjetPt2ProngsigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRange2ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyFlavour->ProjectionY(Form("projJetPtRange2ProngsigmaLxy_%d_%d", binJetPt, flavour), leftbinJetPt2ProngsigmaLxy, rightbinJetPt2ProngsigmaLxy, binFlavour, binFlavour));
			hsimTagjet2ProngsigmaLxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxy->Clone(Form("hsimTagjet2ProngsigmaLxy_%d_%d", flavour, binJetPt))); 
			hsimTagjet2ProngsigmaLxy[0][binJetPt]->Add(projJetPtRange2ProngsigmaLxy);

			int leftbinJetPt2ProngsigmaLxyz = h3simTagjetPt2ProngsigmaLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPt2ProngsigmaLxyz = h3simTagjetPt2ProngsigmaLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRange2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simTagjetPt2ProngsigmaLxyzFlavour->ProjectionY(Form("projJetPtRange2ProngsigmaLxyz_%d_%d", binJetPt, flavour), leftbinJetPt2ProngsigmaLxyz, rightbinJetPt2ProngsigmaLxyz, binFlavour, binFlavour));
			hsimTagjet2ProngsigmaLxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxyz->Clone(Form("hsimTagjet2ProngsigmaLxyz_%d_%d", flavour, binJetPt))); 
			hsimTagjet2ProngsigmaLxyz[0][binJetPt]->Add(projJetPtRange2ProngsigmaLxyz);

    }
  }
}

void HfJetTaggingSVAnalysis::NormalizedHistogramSVQAData() {
}

void HfJetTaggingSVAnalysis::NormalizedHistogramSVQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimTagjetNormalized2ProngSxyCutsigmaLxy[flavour] = reinterpret_cast<TH1F*> (hsimTagjet2ProngSxyCutsigmaLxy[flavour]->Clone(Form("hsimTagjetNormalized2ProngSxyCutsigmaLxy_%d", flavour)));
		hsimTagjetNormalized2ProngsigmaLxyCutSxy[flavour] = reinterpret_cast<TH1F*> (hsimTagjet2ProngsigmaLxyCutSxy[flavour]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxyCutSxy_%d", flavour)));
		hsimTagjetNormalized2ProngSxyCutsigmaLxy[flavour]->Scale(1. / hsimTagjetNormalized2ProngSxyCutsigmaLxy[flavour]->GetEntries());
		hsimTagjetNormalized2ProngsigmaLxyCutSxy[flavour]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxyCutSxy[flavour]->GetEntries());
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetNormalized2ProngLxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjet2ProngLxy[flavour][jetPt]->Clone(Form("hsimTagjetNormalized2ProngLxy_%d_%d", flavour, jetPt)));
			hsimTagjetNormalized2ProngLxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjet2ProngLxyz[flavour][jetPt]->Clone(Form("hsimTagjetNormalized2ProngLxyz_%d_%d", flavour, jetPt)));
			hsimTagjetNormalized2ProngSxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjet2ProngSxy[flavour][jetPt]->Clone(Form("hsimTagjetNormalized2ProngSxy_%d_%d", flavour, jetPt)));
			hsimTagjetNormalized2ProngSxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjet2ProngSxyz[flavour][jetPt]->Clone(Form("hsimTagjetNormalized2ProngSxyz_%d_%d", flavour, jetPt)));
			hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjet2ProngsigmaLxy[flavour][jetPt]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxy_%d_%d", flavour, jetPt)));
			hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjet2ProngsigmaLxyz[flavour][jetPt]->Clone(Form("hsimTagjetNormalized2ProngsigmaLxyz_%d_%d", flavour, jetPt)));

      // Scale
			hsimTagjetNormalized2ProngLxy[flavour][jetPt]->Scale(1. / hsimTagjetNormalized2ProngLxy[flavour][jetPt]->GetEntries());
			hsimTagjetNormalized2ProngLxyz[flavour][jetPt]->Scale(1. / hsimTagjetNormalized2ProngLxyz[flavour][jetPt]->GetEntries());
			hsimTagjetNormalized2ProngSxy[flavour][jetPt]->Scale(1. / hsimTagjetNormalized2ProngSxy[flavour][jetPt]->GetEntries());
			hsimTagjetNormalized2ProngSxyz[flavour][jetPt]->Scale(1. / hsimTagjetNormalized2ProngSxyz[flavour][jetPt]->GetEntries());
			hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt]->GetEntries());
			hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt]->Scale(1. / hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt]->GetEntries());
    }
  }
}

void HfJetTaggingSVAnalysis::SaveHistogramSVQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile, "RECREATE");
  if (!fout->IsOpen()) {
    std::cerr << "Error: Could not open the ROOT file for writing: " << rootFile << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

  if (doMC) {
 	  dir = fout->GetDirectory("data");
  	if (!dir) {
    	dir = fout->mkdir("data");
    	dir->cd();
  	}
  }
  if (doMC) {
  	dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
    }
    for (int flavour = 0; flavour < HfJetTagging::nFlavour + 1; ++flavour) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt + 1; ++jetPt) {
        if (hsimTagjet2ProngLxy[flavour][jetPt]) hsimTagjet2ProngLxy[flavour][jetPt]->Write();
        if (hsimTagjet2ProngLxyz[flavour][jetPt]) hsimTagjet2ProngLxyz[flavour][jetPt]->Write();
        if (hsimTagjet2ProngSxy[flavour][jetPt]) hsimTagjet2ProngSxy[flavour][jetPt]->Write();
        if (hsimTagjet2ProngSxyz[flavour][jetPt]) hsimTagjet2ProngSxyz[flavour][jetPt]->Write();
        if (hsimTagjet2ProngsigmaLxy[flavour][jetPt]) hsimTagjet2ProngsigmaLxy[flavour][jetPt]->Write();
        if (hsimTagjet2ProngsigmaLxyz[flavour][jetPt]) hsimTagjet2ProngsigmaLxyz[flavour][jetPt]->Write();
//        if (hsimTagjet3ProngLxy[flavour][jetPt]) hsimTagjet3ProngLxy[flavour][jetPt]->Write();
//        if (hsimTagjet3ProngLxyz[flavour][jetPt]) hsimTagjet3ProngLxyz[flavour][jetPt]->Write();
//        if (hsimTagjet3ProngSxy[flavour][jetPt]) hsimTagjet3ProngSxy[flavour][jetPt]->Write();
//        if (hsimTagjet3ProngSxyz[flavour][jetPt]) hsimTagjet3ProngSxyz[flavour][jetPt]->Write();
        if (hsimTagjetNormalized2ProngLxy[flavour][jetPt]) hsimTagjetNormalized2ProngLxy[flavour][jetPt]->Write();
        if (hsimTagjetNormalized2ProngLxyz[flavour][jetPt]) hsimTagjetNormalized2ProngLxyz[flavour][jetPt]->Write();
        if (hsimTagjetNormalized2ProngSxy[flavour][jetPt]) hsimTagjetNormalized2ProngSxy[flavour][jetPt]->Write();
        if (hsimTagjetNormalized2ProngSxyz[flavour][jetPt]) hsimTagjetNormalized2ProngSxyz[flavour][jetPt]->Write();
        if (hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt]) hsimTagjetNormalized2ProngsigmaLxy[flavour][jetPt]->Write();
        if (hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt]) hsimTagjetNormalized2ProngsigmaLxyz[flavour][jetPt]->Write();
//        if (hsimTagjetNormalized3ProngLxy[flavour][jetPt]) hsimTagjetNormalized3ProngLxy[flavour][jetPt]->Write();
//        if (hsimTagjetNormalized3ProngLxyz[flavour][jetPt]) hsimTagjetNormalized3ProngLxyz[flavour][jetPt]->Write();
//        if (hsimTagjetNormalized3ProngSxy[flavour][jetPt]) hsimTagjetNormalized3ProngSxy[flavour][jetPt]->Write();
//        if (hsimTagjetNormalized3ProngSxyz[flavour][jetPt]) hsimTagjetNormalized3ProngSxyz[flavour][jetPt]->Write();
      }
    }
  }
}

// Draw function
void HfJetTaggingSVAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingSVAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, bool withLeg, double xmin=0, double ymin=0, double xmax=1, double ymax=1){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (withLeg) leg->Draw();
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "L_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngLxy_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngLxyz(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], "L_{xyz}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngLxyz_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngSxy(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "S_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngSxy_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngSxyz(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], "S_{xyz}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngSxyz_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::sigmaLXY[0], HfJetTagging::REFHIST::sigmaLXY[1], HfJetTagging::REFHIST::sigmaLXY[2], HfJetTagging::REFHIST::sigmaLXY[3], "#sigma_{L_{xy}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngsigmaLxy_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::sigmaLXYZ[0], HfJetTagging::REFHIST::sigmaLXYZ[1], HfJetTagging::REFHIST::sigmaLXYZ[2], HfJetTagging::REFHIST::sigmaLXYZ[3], "#sigma_{L_{xyz}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngsigmaLxyz_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngSxyCutsigmaLxy(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngSxyCutsigmaLxy[0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxyCutsigmaLxy[1], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxyCutsigmaLxy[2], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngSxyCutsigmaLxy[3], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "S_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
//  latexSimSet();
//  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngSxyCutsigmaLxy.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngsigmaLxyCutSxy(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyCutSxy[0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyCutSxy[1], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyCutSxy[2], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalized2ProngsigmaLxyCutSxy[3], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::sigmaLXY[0], HfJetTagging::REFHIST::sigmaLXY[1], HfJetTagging::REFHIST::sigmaLXY[2], HfJetTagging::REFHIST::sigmaLXY[3], "#sigma_{L_{xy}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
//  latexSimSet();
//  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/2ProngsigmaLxyCutSxy.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngRawSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjet2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjet2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjet2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjet2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  //canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "S_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  latex.DrawLatex(0.2, 0.7, "2prong candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/sv/raw2ProngSxy_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}



#endif // HFJETTAGGINGSVANALYSIS_H 
