#ifndef JETANALYSIS_H
#define JETANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

class JetAnalysis {
  public:
    JetAnalysis(const TString rootFileTC, TString rootFileSV2Prong, TString rootFileSV3Prong, const TString taskTC, const TString taskSV, bool doMC, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong) {
      if (doMC) LoadSimIncJet(rootFileTC.Data(), rootFileSV2Prong.Data(), rootFileSV3Prong.Data(), taskTC.Data(), taskSV.Data(), doTC, doJP, doSV2Prong, doSV3Prong);
      InitHistogramIncJet(doTC, doJP, doSV2Prong, doSV3Prong);
      NormalizedHistogramIncJet(doTC, doJP, doSV2Prong, doSV3Prong);
    }

    //JetAnalysis(const TString rootFileTC, TString rootFileSV2Prong, const TString taskTC, const TString taskSV, bool doMC, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong, const TString cutSelection); 
    ~JetAnalysis();

    // function
    void HistColorStyle(TH1D* h1, int mc, int ms, double mS, int lc, int ls);
    int LoadSimIncJet(TString rootFileTC, TString rootFileSV2Prong, TString rootFileSV3Prong, TString taskTC, TString taskSV, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong);
    void InitHistogramIncJet(bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong);
    void NormalizedHistogramIncJet(bool doTC, bool doJP, bool SV2Prong, bool doSV3Prong);

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
    TH2D* hsimincjetPtSignImpXYSignificance;

    TH1D* hsimincjetImpXYZ;
    TH1D* hsimincjetSignImpXYZ;
    TH1D* hsimincjetImpXYZSignificance;
    TH1D* hsimincjetSignImpXYZSignificance;

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
    TH2D* hsimincjetNormalizedPtSignImpXYSignificance;
    TH1D* hsimincjetNormalizedImpXYZ;
    TH1D* hsimincjetNormalizedSignImpXYZ;
    TH1D* hsimincjetNormalizedImpXYZSignificance;
    TH1D* hsimincjetNormalizedSignImpXYZSignificance;

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

    TH1D* hsimsinjet2ProngLxy;
    TH1D* hsimincjet2ProngSxy;
    TH1D* hsimsinjet2ProngLxyz;
    TH1D* hsimincjet2ProngSxyz;
    TH1D* hsimincjet2ProngNormalizedLxy;
    TH1D* hsimincjet2ProngNormalizedSxy;
    TH1D* hsimincjet2ProngNormalizedLxyz;
    TH1D* hsimincjet2ProngNormalizedSxyz;
    TH1D* hsimsinjet3ProngLxy;
    TH1D* hsimincjet3ProngSxy;
    TH1D* hsimsinjet3ProngLxyz;
    TH1D* hsimincjet3ProngSxyz;
    TH1D* hsimincjet3ProngNormalizedLxy;
    TH1D* hsimincjet3ProngNormalizedSxy;
    TH1D* hsimincjet3ProngNormalizedLxyz;
    TH1D* hsimincjet3ProngNormalizedSxyz;

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
  if (hsimincjetImpXYZ) delete hsimincjetImpXYZ;
  if (hsimincjetSignImpXYZ) delete hsimincjetSignImpXYZ;
  if (hsimincjetImpXYZSignificance) delete hsimincjetImpXYZSignificance;
  if (hsimincjetSignImpXYZSignificance) delete hsimincjetSignImpXYZSignificance;

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

  if (hsimsinjet2ProngLxy) delete hsimsinjet2ProngLxy;
  if (hsimincjet2ProngSxy) delete hsimincjet2ProngSxy;
  if (hsimsinjet2ProngLxyz) delete hsimsinjet2ProngLxyz;
  if (hsimincjet2ProngSxyz) delete hsimincjet2ProngSxyz;
  if (hsimsinjet3ProngLxy) delete hsimsinjet3ProngLxy;
  if (hsimincjet3ProngSxy) delete hsimincjet3ProngSxy;
  if (hsimsinjet3ProngLxyz) delete hsimsinjet3ProngLxyz;
  if (hsimincjet3ProngSxyz) delete hsimincjet3ProngSxyz;

}

int JetAnalysis::LoadSimIncJet(TString rootFileTC, TString rootFileSV2Prong, TString rootFileSV3Prong, TString taskTC, TString taskSV, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong) {
  if (gSystem->AccessPathName(rootFileTC.Data())) {
    std::cout << "Input file (TC MC) not found!" << std::endl;
    return 0;
  }
  if (gSystem->AccessPathName(rootFileSV2Prong.Data())) {
    std::cout << "Input file (SV 2Prong MC) not found!" << std::endl;
    return 0;
  }
  if (gSystem->AccessPathName(rootFileSV3Prong.Data())) {
    std::cout << "Input file (SV 3Prong MC) not found!" << std::endl;
    return 0;
  }
  TFile* finTC; TFile* finSV2Prong; TFile* finSV3Prong;
  finTC = TFile::Open(rootFileTC, "READ");
  finSV2Prong = TFile::Open(rootFileSV2Prong, "READ");
  finSV3Prong = TFile::Open(rootFileSV3Prong, "READ");
  TString taskJetQA = "jet-finder-qa";
  taskTC = "jet-taggerhf-tc-charged";
  //if (taskTC=="") taskTC = "jet-taggerhf-tc-charged";
  //If (taskSV=="") taskSV = "jet-taggerhf-sv-charged";

  if (doTC) {
    hsimincjetTrackPt = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_track_pt", taskTC.Data())));
    hsimincjetTrackPhi = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_track_phi", taskTC.Data())));
    hsimincjetTrackEta = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_track_eta", taskTC.Data())));
    hsimincjetImpXY = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy", taskTC.Data())));
    hsimincjetSignImpXY = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy", taskTC.Data())));
    hsimincjetImpXYSignificance = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance", taskTC.Data())));
    hsimincjetSignImpXYSignificance = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance", taskTC.Data())));
    hsimincjetImpXYZ = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xyz", taskTC.Data())));
    hsimincjetSignImpXYZ = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xyz", taskTC.Data())));
    hsimincjetImpXYZSignificance = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xyz_significance", taskTC.Data())));
    hsimincjetSignImpXYZSignificance = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xyz_significance", taskTC.Data())));
    hsimincjetImpXYN1 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_N1", taskTC.Data())));
    hsimincjetSignImpXYN1 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_N1", taskTC.Data())));
    hsimincjetImpXYSignificanceN1 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance_N1", taskTC.Data())));
    hsimincjetSignImpXYSignificanceN1 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance_N1", taskTC.Data())));
    hsimincjetImpXYN2 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_N2", taskTC.Data())));
    hsimincjetSignImpXYN2 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_N2", taskTC.Data())));
    hsimincjetImpXYSignificanceN2 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance_N2", taskTC.Data())));
    hsimincjetSignImpXYSignificanceN2 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance_N2", taskTC.Data())));
    hsimincjetImpXYN3 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_N3", taskTC.Data())));
    hsimincjetSignImpXYN3 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_N3", taskTC.Data())));
    hsimincjetImpXYSignificanceN3 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_impact_parameter_xy_significance_N3", taskTC.Data())));
    hsimincjetSignImpXYSignificanceN3 = reinterpret_cast<TH1D*>(finTC->Get(Form("%s/h_inc_jet_sign_impact_parameter_xy_significance_N3", taskTC.Data())));

    hsimincjetPtSignImpXYSignificance = (TH2D*)finTC->Get(Form("%s/h_inc_jet_pt_sign_impact_parameter_xy_significance", taskTC.Data()));

    if (doJP) {
      hsimincjetJP = (TH1D*)finTC->Get(Form("%s/h_inc_jet_JP", taskTC.Data()));
      hsimincjetJPLog = (TH1D*)finTC->Get(Form("%s/h_inc_jet_JP_Log", taskTC.Data()));
      hsimincjetPtJP = (TH2D*)finTC->Get(Form("%s/h_inc_jet_pt_JP", taskTC.Data()));
      hsimincjetPtJPLog = (TH2D*)finTC->Get(Form("%s/h_inc_jet_pt_JP_Log", taskTC.Data()));
    }
  }

  if (doSV2Prong) {
    hsimsinjet2ProngLxy = (TH1D*)finSV2Prong->Get(Form("%s/h_inc_jet_2prong_Lxy", taskSV.Data()));
    hsimincjet2ProngSxy = (TH1D*)finSV2Prong->Get(Form("%s/h_inc_jet_2prong_Sxy", taskSV.Data()));
    hsimsinjet2ProngLxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_inc_jet_2prong_Lxyz", taskSV.Data()));
    hsimincjet2ProngSxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_inc_jet_2prong_Sxyz", taskSV.Data()));
  }

  if (doSV3Prong) {
    hsimsinjet3ProngLxy = (TH1D*)finSV3Prong->Get(Form("%s/h_inc_jet_3prong_Lxy", taskSV.Data()));
    hsimincjet3ProngSxy = (TH1D*)finSV3Prong->Get(Form("%s/h_inc_jet_3prong_Sxy", taskSV.Data()));
    hsimsinjet3ProngLxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_inc_jet_3prong_Lxyz", taskSV.Data()));
    hsimincjet3ProngSxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_inc_jet_3prong_Sxyz", taskSV.Data()));
  }

  return 1;
}

void JetAnalysis::InitHistogramIncJet(bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong) {
  if (doTC) {
    hsimincjetNormalizedTrackPt = reinterpret_cast<TH1D*>(hsimincjetTrackPt->Clone("hsimincjetNormalizedTrackPt"));
    hsimincjetNormalizedTrackPhi = reinterpret_cast<TH1D*>(hsimincjetTrackPhi->Clone("hsimincjetNormalizedTrackPhi"));
    hsimincjetNormalizedTrackEta = reinterpret_cast<TH1D*>(hsimincjetTrackEta->Clone("hsimincjetNormalizedTrackEta"));
    hsimincjetNormalizedImpXY = reinterpret_cast<TH1D*>(hsimincjetImpXY->Clone("hsimincjetNormalizedImpXY"));
    hsimincjetNormalizedImpXYSignificance = (TH1D*)hsimincjetImpXYSignificance->Clone("hsimincjetNormalizedImpXYSignificance");
    hsimincjetNormalizedSignImpXY = (TH1D*)hsimincjetSignImpXY->Clone("hsimincjetNormalizedSignImpXY");
    hsimincjetNormalizedSignImpXYSignificance = (TH1D*)hsimincjetSignImpXYSignificance->Clone("hsimincjetNormalizedSignImpXYSignificance");
    hsimincjetNormalizedImpXYZ = reinterpret_cast<TH1D*>(hsimincjetImpXYZ->Clone("hsimincjetNormalizedImpXYZ"));
    hsimincjetNormalizedImpXYZSignificance = (TH1D*)hsimincjetImpXYZSignificance->Clone("hsimincjetNormalizedImpXYZSignificance");
    hsimincjetNormalizedSignImpXYZ = (TH1D*)hsimincjetSignImpXYZ->Clone("hsimincjetNormalizedSignImpXYZ");
    hsimincjetNormalizedSignImpXYZSignificance = (TH1D*)hsimincjetSignImpXYZSignificance->Clone("hsimincjetNormalizedSignImpXYZSignificance");
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
 
  if (doSV2Prong) {
    hsimincjet2ProngNormalizedLxy = (TH1D*) hsimsinjet2ProngLxy->Clone("hsimsinjet2ProngLxy");
    hsimincjet2ProngNormalizedSxy = (TH1D*) hsimincjet2ProngSxy->Clone("hsimincjet2ProngSxy");
    hsimincjet2ProngNormalizedLxyz = (TH1D*) hsimsinjet2ProngLxyz->Clone("hsimsinjet2ProngLxyz");
    hsimincjet2ProngNormalizedSxyz = (TH1D*) hsimincjet2ProngSxyz->Clone("hsimincjet2ProngSxyz");
  }
  if (doSV3Prong) {
    hsimincjet3ProngNormalizedLxy = (TH1D*) hsimsinjet3ProngLxy->Clone("hsimsinjet3ProngLxy");
    hsimincjet3ProngNormalizedSxy = (TH1D*) hsimincjet3ProngSxy->Clone("hsimincjet3ProngSxy");
    hsimincjet3ProngNormalizedLxyz = (TH1D*) hsimsinjet3ProngLxyz->Clone("hsimsinjet3ProngLxyz");
    hsimincjet3ProngNormalizedSxyz = (TH1D*) hsimincjet3ProngSxyz->Clone("hsimincjet3ProngSxyz");
  }
}

void JetAnalysis::NormalizedHistogramIncJet(bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong) {
  if (doTC) {
    hsimincjetNormalizedImpXY->Scale(1. / hsimincjetNormalizedImpXY->GetEntries());
    hsimincjetNormalizedImpXYSignificance->Scale(1. / hsimincjetNormalizedImpXYSignificance->GetEntries());
    hsimincjetNormalizedSignImpXY->Scale(1. / hsimincjetNormalizedSignImpXY->GetEntries());
    hsimincjetNormalizedSignImpXYSignificance->Scale(1. / hsimincjetNormalizedSignImpXYSignificance->GetEntries());
    hsimincjetNormalizedImpXYZ->Scale(1. / hsimincjetNormalizedImpXYZ->GetEntries());
    hsimincjetNormalizedImpXYZSignificance->Scale(1. / hsimincjetNormalizedImpXYZSignificance->GetEntries());
    hsimincjetNormalizedSignImpXYZ->Scale(1. / hsimincjetNormalizedSignImpXYZ->GetEntries());
    hsimincjetNormalizedSignImpXYZSignificance->Scale(1. / hsimincjetNormalizedSignImpXYZSignificance->GetEntries());
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
  if (doSV2Prong) {
    hsimincjet2ProngNormalizedLxy->Scale(1. / hsimincjet2ProngNormalizedLxy->GetEntries());
    hsimincjet2ProngNormalizedSxy->Scale(1. / hsimincjet2ProngNormalizedSxy->GetEntries());
    hsimincjet2ProngNormalizedLxyz->Scale(1. / hsimincjet2ProngNormalizedLxyz->GetEntries());
    hsimincjet2ProngNormalizedSxyz->Scale(1. / hsimincjet2ProngNormalizedSxyz->GetEntries());
  }

  if (doSV3Prong) {
    hsimincjet3ProngNormalizedLxy->Scale(1. / hsimincjet3ProngNormalizedLxy->GetEntries());
    hsimincjet3ProngNormalizedSxy->Scale(1. / hsimincjet3ProngNormalizedSxy->GetEntries());
    hsimincjet3ProngNormalizedLxyz->Scale(1. / hsimincjet3ProngNormalizedLxyz->GetEntries());
    hsimincjet3ProngNormalizedSxyz->Scale(1. / hsimincjet3ProngNormalizedSxyz->GetEntries());
  }
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
