#ifndef JETANALYSIS_H
#define JETANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

class JetAnalysis {
  public:
    JetAnalysis(const TString rootFile, const TString taskName, bool doMC, bool doJP) {
      LoadSimIncJet(rootFile.Data(), taskName.Data(), doJP);
      InitHistogramIncJet(doJP);
      NormalizedHistogramIncJet(doJP);
    }
    JetAnalysis(const TString rootFile, const TString taskName, bool doMC, bool doJP, const TString cutSelection); 
    ~JetAnalysis();

    // function
    void HistColorStyle(TH1D* h1, int mc, int ms, double mS, int lc, int ls);
    int LoadSimIncJet(TString rootFile, TString taskName, bool doJP);
    void InitHistogramIncJet(bool doJP);
    void NormalizedHistogramIncJet(bool doJP);

    int canvasNum=0;
    CanvasHandler* canvasHandler;

    // Histogram
    TH1D* hsimincjetTrackPt;
    TH1D* hsimincjetTrackPhi;
    TH1D* hsimincjetTrackEta;

    TH1D* hsimincjetImpXY;
    TH1D* hsimincjetSignImpXY;
    TH1D* hsimincjetImpXYSignificance;
    TH1D* hsimincjetSignImpXYSignificance;

    TH1D* hsimincjetPtSignImpXYSignificance;

    // related Track Counting
    TH1D* hsimincjetImpXYN1;
    TH1D* hsimincjetSignImpXYN1;
    TH1D* hsimincjetImpXYSignificanceN1;
    TH1D* hsimincjetSignImpXYSignificanceN1;
    TH1D* hsimincjetImpXYN2;
    TH1D* hsimincjetSignImpXYN2;
    TH1D* hsimincjetImpXYSignificanceN2;
    TH1D* hsimincjetSignImpXYSignificanceN2;
    TH1D* hsimincjetImpXYN3;
    TH1D* hsimincjetSignImpXYN3;
    TH1D* hsimincjetImpXYSignificanceN3;
    TH1D* hsimincjetSignImpXYSignificanceN3;

    TH1D* hsimincjetPtSignImpXYSignificanceN1;
    TH1D* hsimincjetPtSignImpXYSignificanceN2;
    TH1D* hsimincjetPtSignImpXYSignificanceN3;

    // related Jet Probability
    TH1D* hsimincjetJP;
    TH1D* hsimincjetJPLog;
    TH2D* hsimincjetPtJP;
    TH2D* hsimincjetPtJPLog;

    // Normalization
    TH1D* hsimincjetNormalizedTrackPt;
    TH1D* hsimincjetNormalizedTrackPhi;
    TH1D* hsimincjetNormalizedTrackEta;
    TH1D* hsimincjetNormalizedImpXY;
    TH1D* hsimincjetNormalizedSignImpXY;
    TH1D* hsimincjetNormalizedImpXYSignificance;
    TH1D* hsimincjetNormalizedSignImpXYSignificance;
    TH1D* hsimincjetNormalizedPtSignImpXYSignificance;

    // related Track Counting
    TH1D* hsimincjetNormalizedImpXYN1;
    TH1D* hsimincjetNormalizedSignImpXYN1;
    TH1D* hsimincjetNormalizedImpXYSignificanceN1;
    TH1D* hsimincjetNormalizedSignImpXYSignificanceN1;
    TH1D* hsimincjetNormalizedImpXYN2;
    TH1D* hsimincjetNormalizedSignImpXYN2;
    TH1D* hsimincjetNormalizedImpXYSignificanceN2;
    TH1D* hsimincjetNormalizedSignImpXYSignificanceN2;
    TH1D* hsimincjetNormalizedImpXYN3;
    TH1D* hsimincjetNormalizedSignImpXYN3;
    TH1D* hsimincjetNormalizedImpXYSignificanceN3;
    TH1D* hsimincjetNormalizedSignImpXYSignificanceN3;

    TH1D* hsimincjetNormalizedPtSignImpXYSignificanceN1;
    TH1D* hsimincjetNormalizedPtSignImpXYSignificanceN2;
    TH1D* hsimincjetNormalizedPtSignImpXYSignificanceN3;

    TH1D* hsimincjetNormalizedJP;
    TH1D* hsimincjetNormalizedJPLog;
    TH2D* hsimincjetNormalizedPtJP;
    TH2D* hsimincjetNormalizedPtJPLog;

  private:
    std::vector<HistogramData> histList;

};

JetAnalysis::~JetAnalysis() {
  if (hsimincjetTrackPt) delete hsimincjetTrackPt;
  if (hsimincjetTrackPhi) delete hsimincjetTrackPhi;
  if (hsimincjetTrackEta) delete hsimincjetTrackEta;
  if (hsimincjetImpXY) delete hsimincjetImpXY;
  if (hsimincjetSignImpXY) delete hsimincjetSignImpXY;
  if (hsimincjetImpXYSignificance) delete hsimincjetImpXYSignificance;
  if (hsimincjetSignImpXYSignificance) delete hsimincjetSignImpXYSignificance;
  if (hsimincjetImpXYN1) delete hsimincjetImpXYN1;
  if (hsimincjetSignImpXYN1) delete hsimincjetSignImpXYN1;
  if (hsimincjetImpXYSignificanceN1) delete hsimincjetImpXYSignificanceN1;
  if (hsimincjetSignImpXYSignificanceN1) delete hsimincjetSignImpXYSignificanceN1;
  if (hsimincjetImpXYN2) delete hsimincjetImpXYN2;
  if (hsimincjetSignImpXYN2) delete hsimincjetSignImpXYN2;
  if (hsimincjetImpXYSignificanceN2) delete hsimincjetImpXYSignificanceN2;
  if (hsimincjetSignImpXYSignificanceN2) delete hsimincjetSignImpXYSignificanceN2;
  if (hsimincjetImpXYN3) delete hsimincjetImpXYN3;
  if (hsimincjetSignImpXYN3) delete hsimincjetSignImpXYN3;
  if (hsimincjetImpXYSignificanceN3) delete hsimincjetImpXYSignificanceN3;
  if (hsimincjetSignImpXYSignificanceN3) delete hsimincjetSignImpXYSignificanceN3;
  if (hsimincjetPtSignImpXYSignificance) delete hsimincjetPtSignImpXYSignificance;
  if (hsimincjetPtSignImpXYSignificanceN1) delete hsimincjetPtSignImpXYSignificanceN1;
  if (hsimincjetPtSignImpXYSignificanceN2) delete hsimincjetPtSignImpXYSignificanceN2;
  if (hsimincjetPtSignImpXYSignificanceN3) delete hsimincjetPtSignImpXYSignificanceN3;
  if (hsimincjetJP) delete hsimincjetJP;
  if (hsimincjetJPLog) delete hsimincjetJPLog;
  if (hsimincjetPtJP) delete hsimincjetPtJP;
  if (hsimincjetPtJPLog) delete hsimincjetPtJPLog;

  if (hsimincjetNormalizedImpXY) delete hsimincjetNormalizedImpXY;
  if (hsimincjetNormalizedSignImpXY) delete hsimincjetNormalizedSignImpXY;
  if (hsimincjetNormalizedImpXYSignificance) delete hsimincjetNormalizedImpXYSignificance;
  if (hsimincjetNormalizedSignImpXYSignificance) delete hsimincjetNormalizedSignImpXYSignificance;
  if (hsimincjetNormalizedImpXYN1) delete hsimincjetNormalizedImpXYN1;
  if (hsimincjetNormalizedSignImpXYN1) delete hsimincjetNormalizedSignImpXYN1;
  if (hsimincjetNormalizedImpXYSignificanceN1) delete hsimincjetNormalizedImpXYSignificanceN1;
  if (hsimincjetNormalizedSignImpXYSignificanceN1) delete hsimincjetNormalizedSignImpXYSignificanceN1;
  if (hsimincjetNormalizedImpXYN2) delete hsimincjetNormalizedImpXYN2;
  if (hsimincjetNormalizedSignImpXYN2) delete hsimincjetNormalizedSignImpXYN2;
  if (hsimincjetNormalizedImpXYSignificanceN2) delete hsimincjetNormalizedImpXYSignificanceN2;
  if (hsimincjetNormalizedSignImpXYSignificanceN2) delete hsimincjetNormalizedSignImpXYSignificanceN2;
  if (hsimincjetNormalizedImpXYN3) delete hsimincjetNormalizedImpXYN3;
  if (hsimincjetNormalizedSignImpXYN3) delete hsimincjetNormalizedSignImpXYN3;
  if (hsimincjetNormalizedImpXYSignificanceN3) delete hsimincjetNormalizedImpXYSignificanceN3;
  if (hsimincjetNormalizedSignImpXYSignificanceN3) delete hsimincjetNormalizedSignImpXYSignificanceN3;


  if (hsimincjetNormalizedPtSignImpXYSignificance) delete hsimincjetNormalizedPtSignImpXYSignificance;
  if (hsimincjetNormalizedPtSignImpXYSignificanceN1) delete hsimincjetNormalizedPtSignImpXYSignificanceN1;
  if (hsimincjetNormalizedPtSignImpXYSignificanceN2) delete hsimincjetNormalizedPtSignImpXYSignificanceN2;
  if (hsimincjetNormalizedPtSignImpXYSignificanceN3) delete hsimincjetNormalizedPtSignImpXYSignificanceN3;

  if (hsimincjetNormalizedJP) delete hsimincjetNormalizedJP;
  if (hsimincjetNormalizedJPLog) delete hsimincjetNormalizedJPLog;
  if (hsimincjetNormalizedPtJP) delete hsimincjetNormalizedPtJP;
  if (hsimincjetNormalizedPtJPLog) delete hsimincjetNormalizedPtJPLog;

}

int JetAnalysis::LoadSimIncJet(TString rootFile, TString taskHfJetTagging, bool doJP) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootFile, "READ");
  TString taskJetQA = "jet-finder-qa";
  //TString taskHfJetTagging = "hf-tagging-task";

  hsimincjetTrackPt = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_track_pt", taskHfJetTagging.Data())));
  hsimincjetTrackPhi = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_track_phi", taskHfJetTagging.Data())));
  hsimincjetTrackEta = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_track_eta", taskHfJetTagging.Data())));
  hsimincjetImpXY = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy", taskHfJetTagging.Data())));
  hsimincjetSignImpXY = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy", taskHfJetTagging.Data())));
  hsimincjetImpXYSignificance = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance", taskHfJetTagging.Data())));
  hsimincjetSignImpXYSignificance = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance", taskHfJetTagging.Data())));
  hsimincjetImpXYN1 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_N1", taskHfJetTagging.Data())));
  hsimincjetSignImpXYN1 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_N1", taskHfJetTagging.Data())));
  hsimincjetImpXYSignificanceN1 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance_N1", taskHfJetTagging.Data())));
  hsimincjetSignImpXYSignificanceN1 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance_N1", taskHfJetTagging.Data())));
  hsimincjetImpXYN2 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_N2", taskHfJetTagging.Data())));
  hsimincjetSignImpXYN2 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_N2", taskHfJetTagging.Data())));
  hsimincjetImpXYSignificanceN2 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance_N2", taskHfJetTagging.Data())));
  hsimincjetSignImpXYSignificanceN2 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance_N2", taskHfJetTagging.Data())));
  hsimincjetImpXYN3 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_N3", taskHfJetTagging.Data())));
  hsimincjetSignImpXYN3 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_N3", taskHfJetTagging.Data())));
  hsimincjetImpXYSignificanceN3 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance_N3", taskHfJetTagging.Data())));
  hsimincjetSignImpXYSignificanceN3 = reinterpret_cast<TH1D*>(fin->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance_N3", taskHfJetTagging.Data())));

  hsimincjetPtSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_inc_jet_pt_sign_impact_parameter_xy_significance", taskHfJetTagging.Data()));

  if (doJP) {
    hsimincjetJP = (TH1D*)fin->Get(Form("%s/h_inc_jet_JP", taskHfJetTagging.Data()));
    hsimincjetJPLog = (TH1D*)fin->Get(Form("%s/h_inc_jet_JP_Log", taskHfJetTagging.Data()));
    hsimincjetPtJP = (TH2D*)fin->Get(Form("%s/h_inc_jet_pt_JP", taskHfJetTagging.Data()));
    hsimincjetPtJPLog = (TH2D*)fin->Get(Form("%s/h_inc_jet_pt_JP_Log", taskHfJetTagging.Data()));
  }

  return 1;
}

void JetAnalysis::InitHistogramIncJet(bool doJP) {
  hsimincjetNormalizedTrackPt = reinterpret_cast<TH1D*>(hsimincjetImpXY->Clone("hsimincjetNormalizedTrackPt"));
  hsimincjetNormalizedTrackPhi = reinterpret_cast<TH1D*>(hsimincjetImpXY->Clone("hsimincjetNormalizedTrackPhi"));
  hsimincjetNormalizedTrackEta = reinterpret_cast<TH1D*>(hsimincjetImpXY->Clone("hsimincjetNormalizedTrackEta"));
  hsimincjetNormalizedImpXY = reinterpret_cast<TH1D*>(hsimincjetImpXY->Clone("hsimincjetNormalizedImpXY"));
  hsimincjetNormalizedImpXYSignificance = (TH1D*)hsimincjetImpXYSignificance->Clone("hsimincjetNormalizedImpXYSignificance");
  hsimincjetNormalizedSignImpXY = (TH1D*)hsimincjetSignImpXY->Clone("hsimincjetNormalizedSignImpXY");
  hsimincjetNormalizedSignImpXYSignificance = (TH1D*)hsimincjetSignImpXYSignificance->Clone("hsimincjetNormalizedSignImpXYSignificance");
  hsimincjetNormalizedImpXYN1 = (TH1D*)hsimincjetImpXYN1->Clone("hsimincjetNormalizedImpXYN1");
  hsimincjetNormalizedImpXYSignificanceN1 = (TH1D*)hsimincjetImpXYSignificanceN1->Clone("hsimincjetNormalizedImpXYSignificanceN1");
  hsimincjetNormalizedSignImpXYN1 = (TH1D*)hsimincjetSignImpXYN1->Clone("hsimincjetNormalizedSignImpXYN1");
  hsimincjetNormalizedSignImpXYSignificanceN1 = (TH1D*)hsimincjetSignImpXYSignificanceN1->Clone("hsimincjetNormalizedSignImpXYSignificanceN1");
  hsimincjetNormalizedImpXYN2 = (TH1D*)hsimincjetImpXYN2->Clone("hsimincjetNormalizedImpXYN2");
  hsimincjetNormalizedImpXYSignificanceN2 = (TH1D*)hsimincjetImpXYSignificanceN2->Clone("hsimincjetNormalizedImpXYSignificanceN2");
  hsimincjetNormalizedSignImpXYN2 = (TH1D*)hsimincjetSignImpXYN2->Clone("hsimincjetNormalizedSignImpXYN2");
  hsimincjetNormalizedSignImpXYSignificanceN2 = (TH1D*)hsimincjetSignImpXYSignificanceN2->Clone("hsimincjetNormalizedSignImpXYSignificanceN2");
  hsimincjetNormalizedImpXYN3 = (TH1D*)hsimincjetImpXYN3->Clone("hsimincjetNormalizedImpXYN3");
  hsimincjetNormalizedImpXYSignificanceN3 = (TH1D*)hsimincjetImpXYSignificanceN3->Clone("hsimincjetNormalizedImpXYSignificanceN3");
  hsimincjetNormalizedSignImpXYN3 = (TH1D*)hsimincjetSignImpXYN3->Clone("hsimincjetNormalizedSignImpXYN3");
  hsimincjetNormalizedSignImpXYSignificanceN3 = (TH1D*)hsimincjetSignImpXYSignificanceN3->Clone("hsimincjetNormalizedSignImpXYSignificanceN3");


  //  hsimincjetNormalizedPtSignImpXYSignificanceN1 = (TH1D*)hsimincjetPtSignImpXYSignificanceN1->Clone("hsimincjetNormalizedPtSignImpXYSignificanceN1");
  //  hsimincjetNormalizedPtSignImpXYSignificanceN2 = (TH1D*)hsimincjetPtSignImpXYSignificanceN2->Clone("hsimincjetNormalizedPtSignImpXYSignificanceN2");
  //  hsimincjetNormalizedPtSignImpXYSignificanceN3 = (TH1D*)hsimincjetPtSignImpXYSignificanceN3->Clone("hsimincjetNormalizedPtSignImpXYSignificanceN3");

  if (doJP) {
    hsimincjetNormalizedJP = (TH1D*)hsimincjetJP->Clone("hsimincjetNormalizedJP");
    hsimincjetNormalizedJPLog = (TH1D*)hsimincjetJPLog->Clone("hsimincjetNormalizedJPLog");
    hsimincjetNormalizedPtJP = (TH2D*)hsimincjetPtJP->Clone("hsimincjetNormalizedPtJP");
    hsimincjetNormalizedPtJPLog = (TH2D*)hsimincjetPtJPLog->Clone("hsimincjetNormalizedPtJPLog");
  }
}

void JetAnalysis::NormalizedHistogramIncJet(bool doJP) {
  hsimincjetNormalizedImpXY->Scale(1. / hsimincjetNormalizedImpXY->GetEntries());
  hsimincjetNormalizedImpXYSignificance->Scale(1. / hsimincjetNormalizedImpXYSignificance->GetEntries());
  hsimincjetNormalizedSignImpXY->Scale(1. / hsimincjetNormalizedSignImpXY->GetEntries());
  hsimincjetNormalizedSignImpXYSignificance->Scale(1. / hsimincjetNormalizedSignImpXYSignificance->GetEntries());
  hsimincjetNormalizedImpXYN1->Scale(1. / hsimincjetNormalizedImpXYN1->GetEntries());
  hsimincjetNormalizedImpXYSignificanceN1->Scale(1. / hsimincjetNormalizedImpXYSignificanceN1->GetEntries());
  hsimincjetNormalizedSignImpXYN1->Scale(1. / hsimincjetNormalizedSignImpXYN1->GetEntries());
  hsimincjetNormalizedSignImpXYSignificanceN1->Scale(1. / hsimincjetNormalizedSignImpXYSignificanceN1->GetEntries());
  hsimincjetNormalizedImpXYN2->Scale(1. / hsimincjetNormalizedImpXYN2->GetEntries());
  hsimincjetNormalizedImpXYSignificanceN2->Scale(1. / hsimincjetNormalizedImpXYSignificanceN2->GetEntries());
  hsimincjetNormalizedSignImpXYN2->Scale(1. / hsimincjetNormalizedSignImpXYN2->GetEntries());
  hsimincjetNormalizedSignImpXYSignificanceN2->Scale(1. / hsimincjetNormalizedSignImpXYSignificanceN2->GetEntries());
  hsimincjetNormalizedImpXYN3->Scale(1. / hsimincjetNormalizedImpXYN3->GetEntries());
  hsimincjetNormalizedImpXYSignificanceN3->Scale(1. / hsimincjetNormalizedImpXYSignificanceN3->GetEntries());
  hsimincjetNormalizedSignImpXYN3->Scale(1. / hsimincjetNormalizedSignImpXYN3->GetEntries());
  hsimincjetNormalizedSignImpXYSignificanceN3->Scale(1. / hsimincjetNormalizedSignImpXYSignificanceN3->GetEntries());

  if (doJP) {
    hsimincjetNormalizedJP->Scale(1. / hsimincjetNormalizedJP->GetEntries());
    hsimincjetNormalizedJPLog->Scale(1. / hsimincjetNormalizedJPLog->GetEntries());
  }

  //hsimincjetNormalizedPtSignImpXYSignificanceN1->Scale(1. / hsimincjetNormalizedPtSignImpXYSignificanceN1->GetEntries());
  //hsimincjetNormalizedPtSignImpXYSignificanceN2->Scale(1. / hsimincjetNormalizedPtSignImpXYSignificanceN2->GetEntries());
  //hsimincjetNormalizedPtSignImpXYSignificanceN3->Scale(1. / hsimincjetNormalizedPtSignImpXYSignificanceN3->GetEntries());
}



void JetAnalysis::HistColorStyle(TH1D* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

#endif // JETANALYSIS_H
