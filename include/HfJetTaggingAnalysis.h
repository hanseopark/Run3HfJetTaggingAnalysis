#ifndef HFJETTAGGINGANALYSIS_H
#define HFJETTAGGINGANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"
//#include "JetAnalysis.h"

/// Now it works itself withtout JetAnalysis.h(GeneralQA) seperatively
/// If histograms were saved by same root file,
/// In future, it should be merged by class HfJetTaggingAnalysis : public JetAnalysis
/// So the functions have to be made by different name of funciton in JetAnalysis.h

class HfJetTaggingAnalysis {
  public:
    HfJetTaggingAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMC, bool dopartLevel) {
      if (doData) {
				if (!LoadDataFlavourQA(rootData.Data())) {
          return;
        }
      	InitHistogramForNormalizationFlavourQAData();
      	ProjectionHistFlavourQAData();
      	CloneNormalizedHistogramFlavourQAData();
      	NormalizedHistogramFlavourQAData();
			}
      if (doMC) {
				if (!LoadSimFlavourQA(rootSim.Data())) {
          return;
        }
      	InitHistogramForNormalizationFlavourQAMC();
      	ProjectionHistFlavourQAMC();
      	CloneNormalizedHistogramFlavourQAMC();
      	NormalizedHistogramFlavourQAMC();
			}
    }
    ~HfJetTaggingAnalysis();

    // function
		/// Basic
    int LoadDataFlavourQA(TString rootData);
    int LoadSimFlavourQA(TString rootSim);
    void InitHistogramForNormalizationFlavourQAData();
    void InitHistogramForNormalizationFlavourQAMC();
    void ProjectionHistFlavourQAData();
    void ProjectionHistFlavourQAMC();
    void CloneNormalizedHistogramFlavourQAData();
    void CloneNormalizedHistogramFlavourQAMC();
    void NormalizedHistogramFlavourQAData();
    void NormalizedHistogramFlavourQAMC();
    void SaveHistogramFlavourQA(TString rootFile, bool doData, bool doMC);

		/// Draw
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    std::vector<HistogramData> histList;
    void DrawCombined(int num, const std::vector<HistogramData>& histList, double legendxmin, double ymin, double xmax, double ymax);
		void DrawDataTagJetPt(bool doLog);
		void DrawDataTagTrackPt(bool doLog, int binJetPt);
		void DrawDataTagTrackEta(bool doLog, int binJetPt);
		void DrawDataTagTrackPhi(bool doLog, int binJetPt);
		void DrawDataTagImpXY(bool doLog, int binJetPt, int binTrackPt);
		void DrawDataTagSignImpXY(bool doLog, int binJetPt, int binTrackPt);
		void DrawDataTagImpXYSig(bool doLog, int binJetPt, int binTrackPt);
		void DrawDataTagSignImpXYSig(bool doLog, int binJetPt, int binTrackPt);

    void DrawTaggedJetTrackPt(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedFlavourJetTrackPt(bool doLog, int flavour, int startJetPt);
    void DrawTaggedJetTrackEta(bool withInc, bool doLog);
    void DrawTaggedFlavourJetTrackEta(bool doLog, int flavour, int startJetPt);
    void DrawTaggedJetTrackPhi(bool withInc, bool doLog);
    void DrawTaggedFlavourJetTrackPhi(bool doLog, int flavour, int startJetPt);
    void DrawTaggedJetImpXY(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXY(bool withInc, bool doLog);
    void DrawTaggedJetImpXYSignificance(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYSignificance(bool withInc, bool doLog);
    void DrawTaggedJetImpXYZ(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYZ(bool withInc, bool doLog);
    void DrawTaggedJetImpXYZSignificance(bool withInc, bool doLog);
    void DrawTaggedJetSignImpXYZSignificance(bool withInc, bool doLog);

    // histogram
		/// Data
		TH1F* hdataTagjetPt;
		TH1F* hdataTagjetTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetTrackPhi[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetImpXY[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetSignImpXY[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		/// MC
    TH1F* hsimTagjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimtrackPtImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];

  protected:
    // draw option. It should be moved to JetAnalysis.h when itself will be merged
    int canvasNum = 0;
    CanvasHandler* canvasHandler;
    
    // histogram
		/// data
    TH3F* h3dataTagjetPtTrackPtTrackEta;
    TH3F* h3dataTagjetPtTrackPtTrackPhi;
    TH3F* h3dataTagjetPtTrackPtImpXY;
    TH3F* h3dataTagjetPtTrackPtSignImpXY;
    TH3F* h3dataTagjetPtTrackPtImpXYSig;
    TH3F* h3dataTagjetPtTrackPtSignImpXYSig;

		//// normalized
		TH1F* hdataTagjetNormalizedPt;
		TH1F* hdataTagjetNormalizedTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedTrackPhi[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedImpXY[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetNormalizedSignImpXY[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetNormalizedImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetNormalizedSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		/// MC
    TH3F* h3simTagjetPtTrackPtFlavour;
    TH3F* h3simTagjetPtTrackEtaFlavour;
    TH3F* h3simTagjetPtTrackPhiFlavour;
    TH3F* h3simTagjetPtImpXYFlavour;
    TH3F* h3simTagjetPtSignImpXYFlavour;
    TH3F* h3simTagjetPtImpXYSigFlavour;
    TH3F* h3simTagjetPtSignImpXYSigFlavour;
    TH3F* h3simTagjetPtImpZFlavour;
    TH3F* h3simTagjetPtSignImpZFlavour;
    TH3F* h3simTagjetPtImpZSigFlavour;
    TH3F* h3simTagjetPtSignImpZSigFlavour;
    TH3F* h3simTagjetPtImpXYZFlavour;
    TH3F* h3simTagjetPtSignImpXYZFlavour;
    TH3F* h3simTagjetPtImpXYZSigFlavour;
    TH3F* h3simTagjetPtSignImpXYZSigFlavour;

    //// normalized
    TH1F* hsimTagjetNormalizedTrackPt[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedTrackEta[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedTrackPhi[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXY[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXY[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXYSig[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXYSig[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpZ[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpZ[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpZSig[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpZSig[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXYZ[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXYZ[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXYZSig[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXYZSig[HfJetTagging::nFlavour][HfJetTagging::nBinsJetPt+1];

  private:


};

HfJetTaggingAnalysis::~HfJetTaggingAnalysis() {
	if (h3simTagjetPtImpXYFlavour) delete h3simTagjetPtImpXYFlavour;
}

int HfJetTaggingAnalysis::LoadDataFlavourQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-tc-charged";

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  h3dataTagjetPtTrackPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_eta", taskName.Data())));
  h3dataTagjetPtTrackPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_phi", taskName.Data())));
  h3dataTagjetPtTrackPtImpXY = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_impact_parameter_xy", taskName.Data())));
  h3dataTagjetPtTrackPtSignImpXY = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xy", taskName.Data())));
  h3dataTagjetPtTrackPtImpXYSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_impact_parameter_xy_significance", taskName.Data())));
  h3dataTagjetPtTrackPtSignImpXYSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xy_significance", taskName.Data())));

  std::cout << "Load completed Flavour Real data" << std::endl;
  return 1;
}

int HfJetTaggingAnalysis::LoadSimFlavourQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-tc-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  h3simTagjetPtTrackPtFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskName.Data())));
  h3simTagjetPtTrackEtaFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskName.Data())));
  h3simTagjetPtTrackPhiFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskName.Data())));
  h3simTagjetPtImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_flavour", taskName.Data())));
  h3simTagjetPtImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_significance_flavour", taskName.Data())));
  h3simTagjetPtSignImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_flavour", taskName.Data())));
  h3simTagjetPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskName.Data())));
  h3simTagjetPtImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_flavour", taskName.Data())));
  h3simTagjetPtImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_significance_flavour", taskName.Data())));
  h3simTagjetPtSignImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_flavour", taskName.Data())));
  h3simTagjetPtSignImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_significance_flavour", taskName.Data())));
  h3simTagjetPtImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_flavour", taskName.Data())));
  h3simTagjetPtImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_significance_flavour", taskName.Data())));
  h3simTagjetPtSignImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_flavour", taskName.Data())));
  h3simTagjetPtSignImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_significance_flavour", taskName.Data())));

  std::cout << "Load completed Flavour MC data" << std::endl;
  return 1;
}

void HfJetTaggingAnalysis::InitHistogramForNormalizationFlavourQAData() {
	hdataTagjetPt = new TH1F("hdataTagjetPt", "", h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsX()));
	for (int jetPt =0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
		hdataTagjetTrackPt[jetPt] = new TH1F(Form("hdataTagjetTrackPt_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
		hdataTagjetTrackEta[jetPt] = new TH1F(Form("hdataTagjetTrackEta_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsZ(), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
		hdataTagjetTrackPhi[jetPt] = new TH1F(Form("hdataTagjetTrackPhi_%d", jetPt), "", h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ(), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));
		for (int trackPt =0; trackPt < HfJetTagging::nBinsTrackPt+1; trackPt++) {
			hdataTagjetImpXY[jetPt][trackPt] = new TH1F(Form("hdataTagjetImpXY_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtImpXY->GetNbinsZ(), h3dataTagjetPtTrackPtImpXY->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtImpXY->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtImpXY->GetNbinsZ()));
			hdataTagjetSignImpXY[jetPt][trackPt] = new TH1F(Form("hdataTagjetSignImpXY_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXY->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXY->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXY->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXY->GetNbinsZ()));
			hdataTagjetImpXYSig[jetPt][trackPt] = new TH1F(Form("hdataTagjetImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtImpXYSig->GetNbinsZ()));
			hdataTagjetSignImpXYSig[jetPt][trackPt] = new TH1F(Form("hdataTagjetSignImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ()));
		}
	}
}

void HfJetTaggingAnalysis::InitHistogramForNormalizationFlavourQAMC() {
  std::cout << "Init histogram" << std::endl;
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetTrackPt[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackPt_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackPtFlavour->GetNbinsY(), h3simTagjetPtTrackPtFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPtFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPtFlavour->GetNbinsY()));
			hsimTagjetTrackEta[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackEta_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackEtaFlavour->GetNbinsY(), h3simTagjetPtTrackEtaFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackEtaFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackEtaFlavour->GetNbinsY()));
			hsimTagjetTrackPhi[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackPhi_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackPhiFlavour->GetNbinsY(), h3simTagjetPtTrackPhiFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPhiFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPhiFlavour->GetNbinsY()));
			hsimTagjetImpXY[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXY_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYFlavour->GetNbinsY(), h3simTagjetPtImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYFlavour->GetNbinsY()));
			hsimTagjetSignImpXY[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXY_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYFlavour->GetNbinsY(), h3simTagjetPtSignImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYFlavour->GetNbinsY()));
			hsimTagjetImpXYSig[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXYSig_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYSigFlavour->GetNbinsY(), h3simTagjetPtImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYSigFlavour->GetNbinsY()));
			hsimTagjetSignImpXYSig[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYSigFlavour->GetNbinsY(), h3simTagjetPtSignImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYSigFlavour->GetNbinsY()));
			hsimTagjetImpZ[flavour][jetPt] = new TH1F(Form("hsimTagjetImpZ_%d_%d", flavour, jetPt), "", h3simTagjetPtImpZFlavour->GetNbinsY(), h3simTagjetPtImpZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpZFlavour->GetNbinsY()));
			hsimTagjetSignImpZ[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpZ_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpZFlavour->GetNbinsY(), h3simTagjetPtSignImpZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpZFlavour->GetNbinsY()));
			hsimTagjetImpZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetImpZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtImpZSigFlavour->GetNbinsY(), h3simTagjetPtImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpZSigFlavour->GetNbinsY()));
			hsimTagjetSignImpZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpZSigFlavour->GetNbinsY(), h3simTagjetPtSignImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpZSigFlavour->GetNbinsY()));
			hsimTagjetImpXYZ[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXYZ_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYZFlavour->GetNbinsY(), h3simTagjetPtImpXYZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYZFlavour->GetNbinsY()));
			hsimTagjetSignImpXYZ[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXYZ_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYZFlavour->GetNbinsY(), h3simTagjetPtSignImpXYZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYZFlavour->GetNbinsY()));
			hsimTagjetImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXYZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYZSigFlavour->GetNbinsY(), h3simTagjetPtImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYZSigFlavour->GetNbinsY()));
			hsimTagjetSignImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXYZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYZSigFlavour->GetNbinsY(), h3simTagjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYZSigFlavour->GetNbinsY()));
		}
	}
}

void HfJetTaggingAnalysis::ProjectionHistFlavourQAData() {

	TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
	TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY("projJetTrackPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
	TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
	TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsY()));
	TH1F* projImpXY = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtImpXY->ProjectionZ("projJetImpXY", 1, h3dataTagjetPtTrackPtImpXY->GetNbinsX(), 1, h3dataTagjetPtTrackPtImpXY->GetNbinsY()));
	TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXY->ProjectionZ("projJetSignImpXY", 1, h3dataTagjetPtTrackPtSignImpXY->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpXY->GetNbinsY()));
	TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtImpXYSig->ProjectionZ("projJetImpXYSig", 1, h3dataTagjetPtTrackPtImpXYSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtImpXYSig->GetNbinsY()));
	TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYSig->ProjectionZ("projJetSignImpXYSig", 1, h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsY()));

	hdataTagjetPt = reinterpret_cast<TH1F*>(projJetPt->Clone());
	hdataTagjetTrackPt[0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
	hdataTagjetTrackEta[0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
	hdataTagjetTrackPhi[0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
	hdataTagjetImpXY[0][0] = reinterpret_cast<TH1F*>(projImpXY->Clone());
	hdataTagjetSignImpXY[0][0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone());
	hdataTagjetImpXYSig[0][0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone());
	hdataTagjetSignImpXYSig[0][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone());

	for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
		int leftbinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
		int rightbinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
		TH1F* projJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY(Form("projJetPtRangeTrackPt_%d", binJetPt), leftbinJetPt, rightbinJetPt, 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
		TH1F* projJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ(Form("projJetPtRangeTrackEta_%d", binJetPt), leftbinJetPt, rightbinJetPt, 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
		TH1F* projJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ(Form("projJetPtRangeTrackPhi_%d", binJetPt), leftbinJetPt, rightbinJetPt, 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));

		hdataTagjetTrackPt[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPt->Clone());
		hdataTagjetTrackEta[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackEta->Clone());
		hdataTagjetTrackPhi[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPhi->Clone());
		for (int binTrackPt =1; binTrackPt<HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
			int leftbinTrackPt = h3dataTagjetPtTrackPtImpXY->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1]);
			int rightbinTrackPt = h3dataTagjetPtTrackPtImpXY->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt]);
			TH1F* projJetPtRangeTrackPtRangeImpXY  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtImpXY->ProjectionZ(Form("projJetPtRangeTrackPtRangeImpXY_%d_%d", binJetPt, binTrackPt), leftbinJetPt, rightbinJetPt, leftbinTrackPt, rightbinTrackPt));
			TH1F* projJetPtRangeTrackPtRangeSignImpXY  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXY->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpXY_%d_%d", binJetPt, binTrackPt), leftbinJetPt, rightbinJetPt, leftbinTrackPt, rightbinTrackPt));
			TH1F* projJetPtRangeTrackPtRangeImpXYSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtImpXYSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeImpXYSig_%d_%d", binJetPt, binTrackPt), leftbinJetPt, rightbinJetPt, leftbinTrackPt, rightbinTrackPt));
			TH1F* projJetPtRangeTrackPtRangeSignImpXYSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpXYSig_%d_%d", binJetPt, binTrackPt), leftbinJetPt, rightbinJetPt, leftbinTrackPt, rightbinTrackPt));

			hdataTagjetImpXY[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeImpXY->Clone());
			hdataTagjetSignImpXY[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpXY->Clone());
			hdataTagjetImpXYSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeImpXYSig->Clone());
			hdataTagjetSignImpXYSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpXYSig->Clone());

		}
	}
}

void HfJetTaggingAnalysis::ProjectionHistFlavourQAMC() {
	int binsToFlavour[] = {1, 2, 3}; // 1: charm, 2: beauty, 3: light flavour
	int numBinsToFlavour = sizeof(binsToFlavour) / sizeof(binsToFlavour[0]);
	for (int i=0; i<numBinsToFlavour; i++) {
		int binZ = binsToFlavour[i];
		TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPtFlavour->ProjectionY(Form("projTrackPt_%d", binZ), 1, h3simTagjetPtTrackPtFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour->ProjectionY(Form("projTrackEta_%d", binZ), 1, h3simTagjetPtTrackEtaFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPhiFlavour->ProjectionY(Form("projTrackPhi_%d", binZ), 1, h3simTagjetPtTrackPhiFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projImpXY = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYFlavour->ProjectionY(Form("projImpXY_%d", binZ), 1, h3simTagjetPtImpXYFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYFlavour->ProjectionY(Form("projSignImpXY_%d", binZ), 1, h3simTagjetPtSignImpXYFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYSigFlavour->ProjectionY(Form("projImpXYSig_%d", binZ), 1, h3simTagjetPtImpXYSigFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binZ), 1, h3simTagjetPtSignImpXYSigFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projImpZ = reinterpret_cast<TH1F*> (h3simTagjetPtImpZFlavour->ProjectionY(Form("projImpZ_%d", binZ), 1, h3simTagjetPtImpZFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projSignImpZ = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpZFlavour->ProjectionY(Form("projSignImpZ_%d", binZ), 1, h3simTagjetPtSignImpZFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projImpZSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpZSigFlavour->ProjectionY(Form("projImpZSig_%d", binZ), 1, h3simTagjetPtImpZSigFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpZSigFlavour->ProjectionY(Form("projSignImpZSig_%d", binZ), 1, h3simTagjetPtSignImpZSigFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projImpXYZ = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYZFlavour->ProjectionY(Form("projImpXYZ_%d", binZ), 1, h3simTagjetPtImpXYZFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projSignImpXYZ = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYZFlavour->ProjectionY(Form("projSignImpXYZ_%d", binZ), 1, h3simTagjetPtSignImpXYZFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projImpXYZSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYZSigFlavour->ProjectionY(Form("projImpXYZSig_%d", binZ), 1, h3simTagjetPtImpXYZSigFlavour->GetNbinsX(), binZ, binZ));
		TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYZSigFlavour->ProjectionY(Form("projSignImpXYZSig_%d", binZ), 1, h3simTagjetPtSignImpXYZSigFlavour->GetNbinsX(), binZ, binZ));

		// inclusive
		hsimTagjetTrackPt[0][0]->Add(projTrackPt);
		hsimTagjetTrackEta[0][0]->Add(projTrackEta);
		hsimTagjetTrackPhi[0][0]->Add(projTrackPhi);
		hsimTagjetImpXY[0][0]->Add(projImpXY);
		hsimTagjetSignImpXY[0][0]->Add(projSignImpXY);
		hsimTagjetImpXYSig[0][0]->Add(projImpXYSig);
		hsimTagjetSignImpXYSig[0][0]->Add(projSignImpXYSig);
		hsimTagjetImpZ[0][0]->Add(projImpZ);
		hsimTagjetSignImpZ[0][0]->Add(projSignImpZ);
		hsimTagjetImpZSig[0][0]->Add(projImpZSig);
		hsimTagjetSignImpZSig[0][0]->Add(projSignImpZSig);
		hsimTagjetImpXYZ[0][0]->Add(projImpXYZ);
		hsimTagjetSignImpXYZ[0][0]->Add(projSignImpXYZ);
		hsimTagjetImpXYZSig[0][0]->Add(projImpXYZSig);
		hsimTagjetSignImpXYZSig[0][0]->Add(projSignImpXYZSig);

		// jet flavour
		hsimTagjetTrackPt[i+1][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
		hsimTagjetTrackEta[i+1][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
		hsimTagjetTrackPhi[i+1][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
		hsimTagjetImpXY[i+1][0] = reinterpret_cast<TH1F*>(projImpXY->Clone());
		hsimTagjetSignImpXY[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone());
		hsimTagjetImpXYSig[i+1][0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone());
		hsimTagjetSignImpXYSig[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone());
		hsimTagjetImpZ[i+1][0] = reinterpret_cast<TH1F*>(projImpZ->Clone());
		hsimTagjetSignImpZ[i+1][0] = reinterpret_cast<TH1F*>(projSignImpZ->Clone());
		hsimTagjetImpZSig[i+1][0] = reinterpret_cast<TH1F*>(projImpZSig->Clone());
		hsimTagjetSignImpZSig[i+1][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone());
		hsimTagjetImpXYZ[i+1][0] = reinterpret_cast<TH1F*>(projImpXYZ->Clone());
		hsimTagjetSignImpXYZ[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYZ->Clone());
		hsimTagjetImpXYZSig[i+1][0] = reinterpret_cast<TH1F*>(projImpXYZSig->Clone());
		hsimTagjetSignImpXYZSig[i+1][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone());

		for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
			int leftbinJetPtTrackPt = h3simTagjetPtTrackPtFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtTrackPt = h3simTagjetPtTrackPtFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPtFlavour->ProjectionY(Form("projJetPtRangeTrackPt_%d_%d", binJetPt, binZ), leftbinJetPtTrackPt, rightbinJetPtTrackPt, binZ, binZ));
			hsimTagjetTrackPt[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPt->Clone()); 
			hsimTagjetTrackPt[0][binJetPt]->Add(projJetPtRangeTrackPt);
			//std::cout << "binJetPt: " << binJetPt << " left x value: " << h3simTagjetPtTrackPtFlavour->GetXaxis()->GetBinCenter(leftbinJetPtTrackPt) << " right x value: " << h3simTagjetPtTrackPtFlavour->GetXaxis()->GetBinCenter(rightbinJetPtTrackPt) << std::endl;
			//histogram->GetXaxis()->GetBinCenter(binNumber)

			int leftbinJetPtTrackEta = h3simTagjetPtTrackEtaFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtTrackEta = h3simTagjetPtTrackEtaFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour->ProjectionY(Form("projJetPtRagneTrackEta_%d_%d", binJetPt, binZ), leftbinJetPtTrackEta, rightbinJetPtTrackEta, binZ, binZ));
			hsimTagjetTrackEta[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackEta->Clone());
			hsimTagjetTrackEta[0][binJetPt]->Add(projJetPtRangeTrackEta);

			int leftbinJetPtTrackPhi = h3simTagjetPtTrackPhiFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtTrackPhi = h3simTagjetPtTrackPhiFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPhiFlavour->ProjectionY(Form("projJetPtRagneTrackPhi_%d_%d", binJetPt, binZ), leftbinJetPtTrackPhi, rightbinJetPtTrackPhi, binZ, binZ));
			hsimTagjetTrackPhi[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPhi->Clone());
			hsimTagjetTrackPhi[0][binJetPt]->Add(projJetPtRangeTrackPhi);

			int leftbinJetPtImpXY = h3simTagjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtImpXY = h3simTagjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeImpXY = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYFlavour->ProjectionY(Form("projJetPtRagneImpXY_%d_%d", binJetPt, binZ), leftbinJetPtImpXY, rightbinJetPtImpXY, binZ, binZ));
			hsimTagjetImpXY[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone());
			hsimTagjetImpXY[0][binJetPt]->Add(projJetPtRangeImpXY);

			int leftbinJetPtSignImpXY = h3simTagjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtSignImpXY = h3simTagjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeSignImpXY = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYFlavour->ProjectionY(Form("projJetPtRagneSignImpXY_%d_%d", binJetPt, binZ), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY, binZ, binZ));
			hsimTagjetSignImpXY[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone());
			hsimTagjetSignImpXY[0][binJetPt]->Add(projJetPtRangeSignImpXY);

			int leftbinJetPtImpXYSig = h3simTagjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtImpXYSig = h3simTagjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeImpXYSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYSigFlavour->ProjectionY(Form("projJetPtRagneImpXYSig_%d_%d", binJetPt, binZ), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig, binZ, binZ));
			hsimTagjetImpXYSig[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone());
			hsimTagjetImpXYSig[0][binJetPt]->Add(projJetPtRangeImpXYSig);

			int leftbinJetPtSignImpXYSig = h3simTagjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtSignImpXYSig = h3simTagjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d", binJetPt, binZ), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binZ, binZ));
			hsimTagjetSignImpXYSig[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone());
			hsimTagjetSignImpXYSig[0][binJetPt]->Add(projJetPtRangeSignImpXYSig);

			int leftbinJetPtImpZ = h3simTagjetPtImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtImpZ = h3simTagjetPtImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeImpZ = reinterpret_cast<TH1F*>(h3simTagjetPtImpZFlavour->ProjectionY(Form("projJetPtRagneImpZ_%d_%d", binJetPt, binZ), leftbinJetPtImpZ, rightbinJetPtImpZ, binZ, binZ));
			hsimTagjetImpZ[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZ->Clone());
			hsimTagjetImpZ[0][binJetPt]->Add(projJetPtRangeImpZ);

			int leftbinJetPtSignImpZ = h3simTagjetPtSignImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtSignImpZ = h3simTagjetPtSignImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeSignImpZ = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpZFlavour->ProjectionY(Form("projJetPtRagneSignImpZ_%d_%d", binJetPt, binZ), leftbinJetPtSignImpZ, rightbinJetPtSignImpZ, binZ, binZ));
			hsimTagjetSignImpZ[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZ->Clone());
			hsimTagjetSignImpZ[0][binJetPt]->Add(projJetPtRangeSignImpZ);
			int leftbinJetPtImpZSig = h3simTagjetPtImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtImpZSig = h3simTagjetPtImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeImpZSig = reinterpret_cast<TH1F*>(h3simTagjetPtImpZSigFlavour->ProjectionY(Form("projJetPtRagneImpZSig_%d_%d", binJetPt, binZ), leftbinJetPtImpZSig, rightbinJetPtImpZSig, binZ, binZ));
			hsimTagjetImpZSig[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZSig->Clone());
			hsimTagjetImpZSig[0][binJetPt]->Add(projJetPtRangeImpZSig);

			int leftbinJetPtSignImpZSig = h3simTagjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtSignImpZSig = h3simTagjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeSignImpZSig = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpZSig_%d_%d", binJetPt, binZ), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, binZ, binZ));
			hsimTagjetSignImpZSig[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSig->Clone());
			hsimTagjetSignImpZSig[0][binJetPt]->Add(projJetPtRangeSignImpZSig);
			int leftbinJetPtImpXYZ = h3simTagjetPtImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtImpXYZ = h3simTagjetPtImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeImpXYZ = reinterpret_cast<TH1F*>(h3simTagjetPtImpXYZFlavour->ProjectionY(Form("projJetPtRagneImpXYZ_%d_%d", binJetPt, binZ), leftbinJetPtImpXYZ, rightbinJetPtImpXYZ, binZ, binZ));
			hsimTagjetImpXYZ[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZ->Clone());
			hsimTagjetImpXYZ[0][binJetPt]->Add(projJetPtRangeImpXYZ);

			int leftbinJetPtSignImpXYZ = h3simTagjetPtSignImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtSignImpXYZ = h3simTagjetPtSignImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeSignImpXYZ = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYZFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZ_%d_%d", binJetPt, binZ), leftbinJetPtSignImpXYZ, rightbinJetPtSignImpXYZ, binZ, binZ));
			hsimTagjetSignImpXYZ[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZ->Clone());
			hsimTagjetSignImpXYZ[0][binJetPt]->Add(projJetPtRangeSignImpXYZ);
			int leftbinJetPtImpXYZSig = h3simTagjetPtImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtImpXYZSig = h3simTagjetPtImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeImpXYZSig = reinterpret_cast<TH1F*>(h3simTagjetPtImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneImpXYZSig_%d_%d", binJetPt, binZ), leftbinJetPtImpXYZSig, rightbinJetPtImpXYZSig, binZ, binZ));
			hsimTagjetImpXYZSig[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZSig->Clone());
			hsimTagjetImpXYZSig[0][binJetPt]->Add(projJetPtRangeImpXYZSig);

			int leftbinJetPtSignImpXYZSig = h3simTagjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtSignImpXYZSig = h3simTagjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeSignImpXYZSig = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZSig_%d_%d", binJetPt, binZ), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, binZ, binZ));
			hsimTagjetSignImpXYZSig[i+1][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSig->Clone());
			hsimTagjetSignImpXYZSig[0][binJetPt]->Add(projJetPtRangeSignImpXYZSig);
		}
	}
}

void HfJetTaggingAnalysis::CloneNormalizedHistogramFlavourQAData() {
	hdataTagjetNormalizedPt = (TH1F*) hdataTagjetPt->Clone("hdataTagjetNormalizedPt");
	for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
		hdataTagjetNormalizedTrackPt[binJetPt] = (TH1F*) hdataTagjetTrackPt[binJetPt]->Clone(Form("hdataTagjetNormalizedTrackPt_%d", binJetPt));
		hdataTagjetNormalizedTrackEta[binJetPt] = (TH1F*) hdataTagjetTrackEta[binJetPt]->Clone(Form("hdataTagjetNormalizedTrackEta_%d", binJetPt));
		hdataTagjetNormalizedTrackPhi[binJetPt] = (TH1F*) hdataTagjetTrackPhi[binJetPt]->Clone(Form("hdataTagjetNormalizedTrackPhi_%d", binJetPt));
		for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
			hdataTagjetNormalizedImpXY[binJetPt][binTrackPt] = (TH1F*) hdataTagjetImpXY[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedImpXY_%d_%d", binJetPt, binTrackPt));
			hdataTagjetNormalizedSignImpXY[binJetPt][binTrackPt] = (TH1F*) hdataTagjetSignImpXY[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedSignImpXY_%d_%d", binJetPt, binTrackPt));
			hdataTagjetNormalizedImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdataTagjetImpXYSig[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedImpXYSig_%d_%d", binJetPt, binTrackPt));
			hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdataTagjetSignImpXYSig[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedSignImpXYSig_%d_%d", binJetPt, binTrackPt));
		}
	}
}

void HfJetTaggingAnalysis::CloneNormalizedHistogramFlavourQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetNormalizedTrackPt[flavour][jetPt] = (TH1F*) hsimTagjetTrackPt[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedTrackPt_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedTrackEta[flavour][jetPt] = (TH1F*) hsimTagjetTrackEta[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedTrackEta_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedTrackPhi[flavour][jetPt] = (TH1F*) hsimTagjetTrackPhi[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedTrackPhi_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXY[flavour][jetPt] = (TH1F*) hsimTagjetImpXY[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXY_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXY[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXY[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXY_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXYSig[flavour][jetPt] = (TH1F*) hsimTagjetImpXYSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXYSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXYSig[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXYSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXYSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpZ[flavour][jetPt] = (TH1F*) hsimTagjetImpZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpZ[flavour][jetPt] = (TH1F*) hsimTagjetSignImpZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpZSig[flavour][jetPt] = (TH1F*) hsimTagjetImpZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpZSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpZSig[flavour][jetPt] = (TH1F*) hsimTagjetSignImpZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpZSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXYZ[flavour][jetPt] = (TH1F*) hsimTagjetImpXYZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXYZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXYZ[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXYZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXYZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXYZSig[flavour][jetPt] = (TH1F*) hsimTagjetImpXYZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXYZSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXYZSig[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXYZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXYZSig_%d_%d", flavour, jetPt));
		}
	}
}

void HfJetTaggingAnalysis::NormalizedHistogramFlavourQAData() {
	hdataTagjetNormalizedPt->Scale(1. / hdataTagjetNormalizedPt->Integral());
	for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
		hdataTagjetNormalizedTrackPt[binJetPt]->Scale(1. / hdataTagjetNormalizedTrackPt[binJetPt]->Integral());
		hdataTagjetNormalizedTrackEta[binJetPt]->Scale(1. / hdataTagjetNormalizedTrackEta[binJetPt]->Integral());
		hdataTagjetNormalizedTrackPhi[binJetPt]->Scale(1. / hdataTagjetNormalizedTrackPhi[binJetPt]->Integral());
		for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
			hdataTagjetNormalizedImpXY[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedImpXY[binJetPt][binTrackPt]->Integral());
			hdataTagjetNormalizedSignImpXY[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedSignImpXY[binJetPt][binTrackPt]->Integral());
			hdataTagjetNormalizedImpXYSig[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedImpXYSig[binJetPt][binTrackPt]->Integral());
			hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Integral());
		}
	}
}

void HfJetTaggingAnalysis::NormalizedHistogramFlavourQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetNormalizedTrackPt[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedTrackPt[flavour][jetPt]->Integral());
			hsimTagjetNormalizedTrackEta[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedTrackEta[flavour][jetPt]->Integral());
			hsimTagjetNormalizedTrackPhi[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedTrackPhi[flavour][jetPt]->Integral());
			hsimTagjetNormalizedImpXY[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXY[flavour][jetPt]->Integral());
			hsimTagjetNormalizedSignImpXY[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXY[flavour][jetPt]->Integral());
			hsimTagjetNormalizedImpXYSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXYSig[flavour][jetPt]->Integral());
			hsimTagjetNormalizedSignImpXYSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXYSig[flavour][jetPt]->Integral());
			hsimTagjetNormalizedImpZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpZ[flavour][jetPt]->Integral());
			hsimTagjetNormalizedSignImpZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpZ[flavour][jetPt]->Integral());
			hsimTagjetNormalizedImpZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpZSig[flavour][jetPt]->Integral());
			hsimTagjetNormalizedSignImpZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpZSig[flavour][jetPt]->Integral());
			hsimTagjetNormalizedImpXYZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXYZ[flavour][jetPt]->Integral());
			hsimTagjetNormalizedSignImpXYZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXYZ[flavour][jetPt]->Integral());
			hsimTagjetNormalizedImpXYZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXYZSig[flavour][jetPt]->Integral());
			hsimTagjetNormalizedSignImpXYZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXYZSig[flavour][jetPt]->GetEntries());
		}
	}
}

void HfJetTaggingAnalysis::SaveHistogramFlavourQA(TString rootFile, bool doData, bool doMC) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

	if (doData) {
  	dir = fout->GetDirectory("data");
  	if (!dir) {
    	dir = fout->mkdir("data");
    	dir->cd();
  	}

		hdataTagjetPt->Write();
		for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
			hdataTagjetTrackPt[binJetPt]->Write();
			hdataTagjetTrackEta[binJetPt]->Write();
			hdataTagjetTrackPhi[binJetPt]->Write();
			for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
				hdataTagjetImpXY[binJetPt][binTrackPt]->Write();
				hdataTagjetSignImpXY[binJetPt][binTrackPt]->Write();
				hdataTagjetImpXYSig[binJetPt][binTrackPt]->Write();
				hdataTagjetSignImpXYSig[binJetPt][binTrackPt]->Write();
			}
		}
	}

	if (doMC) {
  	dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
  	}

	}

	delete fout;
}

// Draw function
void HfJetTaggingAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, double xmin, double ymin, double xmax, double ymax){
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

void HfJetTaggingAnalysis::DrawDataTagJetPt(bool doLog) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedPt, "abc"});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], "jet p_{T}", "#frac{1}{N} #frac{dN}{dp_{T}}");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/jetmomentum.pdf\")", canvasNum - 1));
}

void HfJetTaggingAnalysis::DrawDataTagTrackPt(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedTrackPt[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/trackmomentum_%d.pdf\")", canvasNum - 1, static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::DrawDataTagTrackEta(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedTrackEta[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "track p_{T}", "Probability distribution");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/tracketa_%d.pdf\")", canvasNum - 1, static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::DrawDataTagTrackPhi(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedTrackPhi[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "track p_{T}", "Probability distribution");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/trackphi_%d.pdf\")", canvasNum - 1, static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::DrawTaggedJetTrackPt(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedTrackPt[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPt[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPt[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPt[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/trackmomentum_%d.pdf\")", canvasNum - 1, static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::DrawTaggedFlavourJetTrackPt(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> NormHistList;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPt[flavour][binJetPt+1], Form("%d<jet pT<%d",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPTASJETPT[0], HfJetTagging::REFHIST::TRACKPTASJETPT[1], HfJetTagging::REFHIST::TRACKPTASJETPT[2], HfJetTagging::REFHIST::TRACKPTASJETPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%sjet/trackmomentum.pdf\")", canvasNum - 1, HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::DrawTaggedJetTrackEta(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedTrackEta[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackEta[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackEta[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackEta[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "track #eta", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/tracketa.pdf\")", canvasNum - 1));

}

void HfJetTaggingAnalysis::DrawTaggedFlavourJetTrackEta(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> NormHistList;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackEta[flavour][binJetPt+1], Form("%d<jet #eta<%d",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETAASJETPT[0], HfJetTagging::REFHIST::TRACKETAASJETPT[1], HfJetTagging::REFHIST::TRACKETAASJETPT[2], HfJetTagging::REFHIST::TRACKETAASJETPT[3], "track #eta", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%sjet/tracketa.pdf\")", canvasNum - 1, HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::DrawTaggedJetTrackPhi(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedTrackPhi[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPhi[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPhi[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPhi[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "track #phi", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/trackphi.pdf\")", canvasNum - 1));

}

void HfJetTaggingAnalysis::DrawTaggedFlavourJetTrackPhi(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> NormHistList;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPhi[flavour][binJetPt+1], Form("%d<jet #phi<%d",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHIASJETPT[0], HfJetTagging::REFHIST::TRACKPHIASJETPT[1], HfJetTagging::REFHIST::TRACKPHIASJETPT[2], HfJetTagging::REFHIST::TRACKPHIASJETPT[3], "track #phi", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%sjet/trackphi.pdf\")", canvasNum - 1, HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::DrawTaggedJetImpXY(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXY[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY} [#mum]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXY.pdf\")", canvasNum - 1));
}

void HfJetTaggingAnalysis::DrawTaggedJetSignImpXY(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXY[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "Signed IP_{XY} [#mum]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXY.pdf\")", canvasNum - 1));

}
void HfJetTaggingAnalysis::DrawTaggedJetImpXYSignificance(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXYSig[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingAnalysis::DrawTaggedJetSignImpXYSignificance(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingAnalysis::DrawTaggedJetImpXYZ(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXYZ[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZ[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZ[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZ[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "IP_{XYZ} [#mum]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYZ.pdf\")", canvasNum - 1));

}

void HfJetTaggingAnalysis::DrawTaggedJetSignImpXYZ(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "Signed IP_{XYZ} [#mum]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZ.pdf\")", canvasNum - 1));

}
void HfJetTaggingAnalysis::DrawTaggedJetImpXYZSignificance(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "IPs_{XYZ}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYZSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingAnalysis::DrawTaggedJetSignImpXYZSignificance(bool withInc = false, bool doLog = true){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "Signed IPs_{XYZ}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZSignificance.pdf\")", canvasNum - 1));

}


#endif // HFJETTAGGINGANALYSIS_H 
