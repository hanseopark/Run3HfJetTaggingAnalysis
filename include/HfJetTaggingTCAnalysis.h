#ifndef HFJETTAGGINGTCANALYSIS_H
#define HFJETTAGGINGTCANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "JetAnalysis.h"

class HfJetTaggingTCAnalysis : public JetAnalysis{
  public:
    //HfJetTaggingTCAnalysis(const TString rootFile, const TString taskName, bool doMC) {
    HfJetTaggingTCAnalysis(const TString &rootFileTC, const TString &rootFileSV2Prong, const TString &rootFileSV3Prong, const TString &taskTC, const TString &taskSV, bool doMC, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong) : JetAnalysis(rootFileTC, rootFileSV2Prong, rootFileSV3Prong, taskTC, taskSV, doMC, doTC, doJP, doSV2Prong, doSV3Prong){
      if (doMC) LoadSim(rootFileTC.Data(), taskTC.Data(), doTC, doJP);
      else LoadData(rootFileTC.Data(), taskTC.Data());
      InitHistogram(doTC, doJP);
      NormalizedHistogram(doTC, doJP);
    }
//    HfJetTaggingTCAnalysis(const TString &rootFileTC, const TString &rootFileSV2Prong, const TString &rootFileSV3Prong, const TString &taskName, bool doMC, bool doTC, bool doJP, bool doSV2Prong, bool doSV3Prong, const TString &cutSelection) : JetAnalysis(rootFileTC, rootFileSV2Prong, rootFileSV3Prong, taskName, doMC, doTC, doJP, doSV2Prong, doSV3Prong, cutSelection){
//      if (doMC) LoadSim(rootFileTC.Data(), taskName.Data(), doTC, doJP);
//      else LoadData(rootFileTC.Data(), taskName.Data());
//    }
    ~HfJetTaggingTCAnalysis();

    int LoadSim(TString file, TString task, bool doTC, bool doJP);
    void InitHistogram(bool doTC, bool doJP);
    void NormalizedHistogram(bool doTC, bool doJP);
    int LoadData(TString file, TString task);
    void SaveHistogram(TString file);

    // Draw
    void DrawCombined(int num, const std::vector<HistogramData>& histList, double legendxmin, double ymin, double xmax, double ymax);
    void DrawTaggedJetTrackPt(bool withInc);
    void DrawTaggedJetTrackEta(bool withInc);
    void DrawTaggedJetTrackPhi(bool withInc);
    void DrawTaggedJetImpXY(bool withInc);
    void DrawTaggedJetSignImpXY(bool withInc);
    void DrawTaggedJetImpXYSignificance(bool withInc);
    void DrawTaggedJetSignImpXYSignificance(bool withInc);
    void DrawTaggedJetImpXYZ(bool withInc);
    void DrawTaggedJetSignImpXYZ(bool withInc);
    void DrawTaggedJetImpXYZSignificance(bool withInc);
    void DrawTaggedJetSignImpXYZSignificance(bool withInc);

    // Track counting
    void DrawTaggedJetImpXYN1();
    void DrawTaggedJetSignImpXYN1();
    void DrawTaggedJetImpXYSignificanceN1();
    void DrawTaggedJetSignImpXYSignificanceN1();
    void DrawTaggedJetImpXYN2();
    void DrawTaggedJetSignImpXYN2();
    void DrawTaggedJetImpXYSignificanceN2();
    void DrawTaggedJetSignImpXYSignificanceN2();
    void DrawTaggedJetImpXYN3();
    void DrawTaggedJetSignImpXYN3();
    void DrawTaggedJetImpXYSignificanceN3();
    void DrawTaggedJetSignImpXYSignificanceN3();

    // JP
    void DrawTaggedJetProbability();
    void DrawTaggedJetProbabilityLog();

    // histogram
    // common
    TH1D* hsimPdgCode;
    TH1D* hsimStatusCode;

    TH1D* hsimlfjetTrackPt;
    TH1D* hsimlfjetTrackPhi;
    TH1D* hsimlfjetTrackEta;

    TH1D* hsimcjetTrackPt;
    TH1D* hsimcjetTrackPhi;
    TH1D* hsimcjetTrackEta;

    TH1D* hsimbjetTrackPt;
    TH1D* hsimbjetTrackPhi;
    TH1D* hsimbjetTrackEta;

    // related Impact parameter

    TH1D* hsimlfjetImpXY;
    TH1D* hsimlfjetImpXYSignificance;
    TH1D* hsimlfjetSignImpXY;
    TH1D* hsimlfjetSignImpXYSignificance;
    TH1D* hsimlfjetPtSignImpXYSignificance;
    TH1D* hsimlfjetImpXYZ;
    TH1D* hsimlfjetSignImpXYZ;
    TH1D* hsimlfjetImpXYZSignificance;
    TH1D* hsimlfjetSignImpXYZSignificance;

    TH1D* hsimcjetImpXY;
    TH1D* hsimcjetImpXYSignificance;
    TH1D* hsimcjetSignImpXY;
    TH1D* hsimcjetSignImpXYSignificance;
    TH1D* hsimcjetPtSignImpXYSignificance;
    TH1D* hsimcjetImpXYZ;
    TH1D* hsimcjetImpXYZSignificance;
    TH1D* hsimcjetSignImpXYZ;
    TH1D* hsimcjetSignImpXYZSignificance;

    TH1D* hsimbjetImpXY;
    TH1D* hsimbjetImpXYSignificance;
    TH1D* hsimbjetSignImpXY;
    TH1D* hsimbjetSignImpXYSignificance;
    TH1D* hsimbjetPtSignImpXYSignificance;
    TH1D* hsimbjetImpXYZ;
    TH1D* hsimbjetImpXYZSignificance;
    TH1D* hsimbjetSignImpXYZ;
    TH1D* hsimbjetSignImpXYZSignificance;

    // related Track Counting
    TH1D* hsimlfjetImpXYN1;
    TH1D* hsimlfjetImpXYN2;
    TH1D* hsimlfjetImpXYN3;
    TH1D* hsimlfjetSignImpXYN1;
    TH1D* hsimlfjetSignImpXYN2;
    TH1D* hsimlfjetSignImpXYN3;
    TH1D* hsimlfjetImpXYZN1;
    TH1D* hsimlfjetImpXYZN2;
    TH1D* hsimlfjetImpXYZN3;
    TH1D* hsimlfjetImpXYZSignificanceN1;
    TH1D* hsimlfjetImpXYZSignificanceN2;
    TH1D* hsimlfjetImpXYZSignificanceN3;
    TH1D* hsimcjetSignImpXYN1;
    TH1D* hsimcjetSignImpXYN2;
    TH1D* hsimcjetSignImpXYN3;

    TH1D* hsimlfjetImpXYSignificanceN1;
    TH1D* hsimlfjetImpXYSignificanceN2;
    TH1D* hsimlfjetImpXYSignificanceN3;
    TH1D* hsimlfjetPtSignImpXYSignificanceN1;
    TH1D* hsimlfjetPtSignImpXYSignificanceN2;
    TH1D* hsimlfjetPtSignImpXYSignificanceN3;
    TH1D* hsimlfjetSignImpXYSignificanceN1;
    TH1D* hsimlfjetSignImpXYSignificanceN2;
    TH1D* hsimlfjetSignImpXYSignificanceN3;

    TH1D* hsimcjetImpXYN1;
    TH1D* hsimcjetImpXYN2;
    TH1D* hsimcjetImpXYN3;
    TH1D* hsimcjetImpXYSignificanceN1;
    TH1D* hsimcjetImpXYSignificanceN2;
    TH1D* hsimcjetImpXYSignificanceN3;
    TH1D* hsimcjetSignImpXYSignificanceN1;
    TH1D* hsimcjetSignImpXYSignificanceN2;
    TH1D* hsimcjetSignImpXYSignificanceN3;
    TH1D* hsimcjetPtSignImpXYSignificanceN1;
    TH1D* hsimcjetPtSignImpXYSignificanceN2;
    TH1D* hsimcjetPtSignImpXYSignificanceN3;
    TH1D* hsimcjetImpXYZN1;
    TH1D* hsimcjetImpXYZN2;
    TH1D* hsimcjetImpXYZN3;
    TH1D* hsimcjetImpXYZSignificanceN1;
    TH1D* hsimcjetImpXYZSignificanceN2;
    TH1D* hsimcjetImpXYZSignificanceN3;

    TH1D* hsimbjetImpXYN1;
    TH1D* hsimbjetImpXYN2;
    TH1D* hsimbjetImpXYN3;
    TH1D* hsimbjetImpXYSignificanceN1;
    TH1D* hsimbjetImpXYSignificanceN2;
    TH1D* hsimbjetImpXYSignificanceN3;
    TH1D* hsimbjetSignImpXYN1;
    TH1D* hsimbjetSignImpXYN2;
    TH1D* hsimbjetSignImpXYN3;
    TH1D* hsimbjetSignImpXYSignificanceN1;
    TH1D* hsimbjetSignImpXYSignificanceN2;
    TH1D* hsimbjetSignImpXYSignificanceN3;
    TH1D* hsimbjetPtSignImpXYSignificanceN1;
    TH1D* hsimbjetPtSignImpXYSignificanceN2;
    TH1D* hsimbjetPtSignImpXYSignificanceN3;
    TH1D* hsimbjetImpXYZN1;
    TH1D* hsimbjetImpXYZN2;
    TH1D* hsimbjetImpXYZN3;
    TH1D* hsimbjetImpXYZSignificanceN1;
    TH1D* hsimbjetImpXYZSignificanceN2;
    TH1D* hsimbjetImpXYZSignificanceN3;

    // related Resolution function
    TH1D* hsimlfjetSignImpXYSignificanceClass1;
    TH1D* hsimlfjetSignImpXYSignificanceClass2;
    TH1D* hsimlfjetSignImpXYSignificanceClass3;
    TH1D* hsimcjetSignImpXYSignificanceClass1;
    TH1D* hsimcjetSignImpXYSignificanceClass2;
    TH1D* hsimcjetSignImpXYSignificanceClass3;
    TH1D* hsimbjetSignImpXYSignificanceClass1;
    TH1D* hsimbjetSignImpXYSignificanceClass2;
    TH1D* hsimbjetSignImpXYSignificanceClass3;

    // related Jet Probability
    TH1D* hsimlfjetJP;
    TH1D* hsimlfjetJPLog;
    TH2D* hsimlfjetPtJP;
    TH2D* hsimlfjetPtJPLog;
    TH1D* hsimcjetJP;
    TH1D* hsimcjetJPLog;
    TH2D* hsimcjetPtJP;
    TH2D* hsimcjetPtJPLog;
    TH1D* hsimbjetJP;
    TH1D* hsimbjetJPLog;
    TH2D* hsimbjetPtJP;
    TH2D* hsimbjetPtJPLog;

    TF1* fJP;
    TF1* fJPtemplate;

    // Normalized
    TH1D* hsimlfjetNormalizedTrackPt;
    TH1D* hsimlfjetNormalizedTrackPhi;
    TH1D* hsimlfjetNormalizedTrackEta;

    TH1D* hsimcjetNormalizedTrackPt;
    TH1D* hsimcjetNormalizedTrackPhi;
    TH1D* hsimcjetNormalizedTrackEta;

    TH1D* hsimbjetNormalizedTrackPt;
    TH1D* hsimbjetNormalizedTrackPhi;
    TH1D* hsimbjetNormalizedTrackEta;

    // related Impact parameter
    TH1D* hsimlfjetNormalizedImpXY;
    TH1D* hsimlfjetNormalizedImpXYSignificance;
    TH1D* hsimlfjetNormalizedSignImpXY;
    TH1D* hsimlfjetNormalizedSignImpXYSignificance;
    TH1D* hsimlfjetNormalizedPtSignImpXYSignificance;
    TH1D* hsimlfjetNormalizedImpXYZ;
    TH1D* hsimlfjetNormalizedImpXYZSignificance;
    TH1D* hsimlfjetNormalizedSignImpXYZ;
    TH1D* hsimlfjetNormalizedSignImpXYZSignificance;

    TH1D* hsimcjetNormalizedImpXY;
    TH1D* hsimcjetNormalizedImpXYSignificance;
    TH1D* hsimcjetNormalizedSignImpXY;
    TH1D* hsimcjetNormalizedSignImpXYSignificance;
    TH1D* hsimcjetNormalizedPtSignImpXYSignificance;
    TH1D* hsimcjetNormalizedImpXYZ;
    TH1D* hsimcjetNormalizedImpXYZSignificance;
    TH1D* hsimcjetNormalizedSignImpXYZ;
    TH1D* hsimcjetNormalizedSignImpXYZSignificance;

    TH1D* hsimbjetNormalizedImpXY;
    TH1D* hsimbjetNormalizedImpXYSignificance;
    TH1D* hsimbjetNormalizedSignImpXY;
    TH1D* hsimbjetNormalizedSignImpXYSignificance;
    TH1D* hsimbjetNormalizedPtSignImpXYSignificance;
    TH1D* hsimbjetNormalizedImpXYZ;
    TH1D* hsimbjetNormalizedImpXYZSignificance;
    TH1D* hsimbjetNormalizedSignImpXYZ;
    TH1D* hsimbjetNormalizedSignImpXYZSignificance;

    // related Track Counting
    TH1D* hsimlfjetNormalizedImpXYN1;
    TH1D* hsimlfjetNormalizedImpXYN2;
    TH1D* hsimlfjetNormalizedImpXYN3;
    TH1D* hsimlfjetNormalizedSignImpXYN1;
    TH1D* hsimlfjetNormalizedSignImpXYN2;
    TH1D* hsimlfjetNormalizedSignImpXYN3;
    TH1D* hsimlfjetNormalizedImpXYZN1;
    TH1D* hsimlfjetNormalizedImpXYZN2;
    TH1D* hsimlfjetNormalizedImpXYZN3;
    TH1D* hsimlfjetNormalizedImpXYZSignificanceN1;
    TH1D* hsimlfjetNormalizedImpXYZSignificanceN2;
    TH1D* hsimlfjetNormalizedImpXYZSignificanceN3;
    TH1D* hsimcjetNormalizedSignImpXYN1;
    TH1D* hsimcjetNormalizedSignImpXYN2;
    TH1D* hsimcjetNormalizedSignImpXYN3;

    TH1D* hsimlfjetNormalizedImpXYSignificanceN1;
    TH1D* hsimlfjetNormalizedImpXYSignificanceN2;
    TH1D* hsimlfjetNormalizedImpXYSignificanceN3;
    TH1D* hsimlfjetNormalizedPtSignImpXYSignificanceN1;
    TH1D* hsimlfjetNormalizedPtSignImpXYSignificanceN2;
    TH1D* hsimlfjetNormalizedPtSignImpXYSignificanceN3;
    TH1D* hsimlfjetNormalizedSignImpXYSignificanceN1;
    TH1D* hsimlfjetNormalizedSignImpXYSignificanceN2;
    TH1D* hsimlfjetNormalizedSignImpXYSignificanceN3;

    TH1D* hsimcjetNormalizedImpXYN1;
    TH1D* hsimcjetNormalizedImpXYN2;
    TH1D* hsimcjetNormalizedImpXYN3;
    TH1D* hsimcjetNormalizedImpXYSignificanceN1;
    TH1D* hsimcjetNormalizedImpXYSignificanceN2;
    TH1D* hsimcjetNormalizedImpXYSignificanceN3;
    TH1D* hsimcjetNormalizedSignImpXYSignificanceN1;
    TH1D* hsimcjetNormalizedSignImpXYSignificanceN2;
    TH1D* hsimcjetNormalizedSignImpXYSignificanceN3;
    TH1D* hsimcjetNormalizedPtSignImpXYSignificanceN1;
    TH1D* hsimcjetNormalizedPtSignImpXYSignificanceN2;
    TH1D* hsimcjetNormalizedPtSignImpXYSignificanceN3;
    TH1D* hsimcjetNormalizedImpXYZN1;
    TH1D* hsimcjetNormalizedImpXYZN2;
    TH1D* hsimcjetNormalizedImpXYZN3;
    TH1D* hsimcjetNormalizedImpXYZSignificanceN1;
    TH1D* hsimcjetNormalizedImpXYZSignificanceN2;
    TH1D* hsimcjetNormalizedImpXYZSignificanceN3;

    TH1D* hsimbjetNormalizedImpXYN1;
    TH1D* hsimbjetNormalizedImpXYN2;
    TH1D* hsimbjetNormalizedImpXYN3;
    TH1D* hsimbjetNormalizedImpXYSignificanceN1;
    TH1D* hsimbjetNormalizedImpXYSignificanceN2;
    TH1D* hsimbjetNormalizedImpXYSignificanceN3;
    TH1D* hsimbjetNormalizedSignImpXYN1;
    TH1D* hsimbjetNormalizedSignImpXYN2;
    TH1D* hsimbjetNormalizedSignImpXYN3;
    TH1D* hsimbjetNormalizedSignImpXYSignificanceN1;
    TH1D* hsimbjetNormalizedSignImpXYSignificanceN2;
    TH1D* hsimbjetNormalizedSignImpXYSignificanceN3;
    TH1D* hsimbjetNormalizedPtSignImpXYSignificanceN1;
    TH1D* hsimbjetNormalizedPtSignImpXYSignificanceN2;
    TH1D* hsimbjetNormalizedPtSignImpXYSignificanceN3;
    TH1D* hsimbjetNormalizedImpXYZN1;
    TH1D* hsimbjetNormalizedImpXYZN2;
    TH1D* hsimbjetNormalizedImpXYZN3;
    TH1D* hsimbjetNormalizedImpXYZSignificanceN1;
    TH1D* hsimbjetNormalizedImpXYZSignificanceN2;
    TH1D* hsimbjetNormalizedImpXYZSignificanceN3;

    // related Resolution function
    TH1D* hsimlfjetNormalizedSignImpXYSignificanceClass1;
    TH1D* hsimlfjetNormalizedSignImpXYSignificanceClass2;
    TH1D* hsimlfjetNormalizedSignImpXYSignificanceClass3;
    TH1D* hsimcjetNormalizedSignImpXYSignificanceClass1;
    TH1D* hsimcjetNormalizedSignImpXYSignificanceClass2;
    TH1D* hsimcjetNormalizedSignImpXYSignificanceClass3;
    TH1D* hsimbjetNormalizedSignImpXYSignificanceClass1;
    TH1D* hsimbjetNormalizedSignImpXYSignificanceClass2;
    TH1D* hsimbjetNormalizedSignImpXYSignificanceClass3;

    // related jetNormalized Probability
    TH1D* hsimlfjetNormalizedJP;
    TH1D* hsimlfjetNormalizedJPLog;
    TH2D* hsimlfjetNormalizedPtJP;
    TH2D* hsimlfjetNormalizedPtJPLog;
    TH1D* hsimcjetNormalizedJP;
    TH1D* hsimcjetNormalizedJPLog;
    TH2D* hsimcjetNormalizedPtJP;
    TH2D* hsimcjetNormalizedPtJPLog;
    TH1D* hsimbjetNormalizedJP;
    TH1D* hsimbjetNormalizedJPLog;
    TH2D* hsimbjetNormalizedPtJP;
    TH2D* hsimbjetNormalizedPtJPLog;

  private:

};

HfJetTaggingTCAnalysis::~HfJetTaggingTCAnalysis() {

  // common
  if (hsimPdgCode) delete hsimPdgCode;
  if (hsimStatusCode) delete hsimStatusCode;
  if (hsimlfjetTrackPt) delete hsimlfjetTrackPt;
  if (hsimlfjetTrackPhi) delete hsimlfjetTrackPhi;
  if (hsimlfjetTrackEta) delete hsimlfjetTrackEta;
  if (hsimcjetTrackPt) delete hsimcjetTrackPt;
  if (hsimcjetTrackPhi) delete hsimcjetTrackPhi;
  if (hsimcjetTrackEta) delete hsimcjetTrackEta;
  if (hsimbjetTrackPt) delete hsimbjetTrackPt;
  if (hsimbjetTrackPhi) delete hsimbjetTrackPhi;
  if (hsimbjetTrackEta) delete hsimbjetTrackEta;

  // related to Impact parameter
  if (hsimlfjetImpXY) delete hsimlfjetImpXY;
  if (hsimlfjetImpXYSignificance) delete hsimlfjetImpXYSignificance;
  if (hsimlfjetSignImpXY) delete hsimlfjetSignImpXY;
  if (hsimlfjetSignImpXYSignificance) delete hsimlfjetSignImpXYSignificance;
  if (hsimlfjetPtSignImpXYSignificance) delete hsimlfjetPtSignImpXYSignificance;
  if (hsimlfjetImpXYZ) delete hsimlfjetImpXYZ;
  if (hsimlfjetImpXYZSignificance) delete hsimlfjetImpXYZSignificance;
  if (hsimlfjetSignImpXYZ) delete hsimlfjetSignImpXYZ;
  if (hsimlfjetSignImpXYZSignificance) delete hsimlfjetSignImpXYZSignificance;

  if (hsimcjetImpXY) delete hsimcjetImpXY;
  if (hsimcjetImpXYSignificance) delete hsimcjetImpXYSignificance;
  if (hsimcjetSignImpXY) delete hsimcjetSignImpXY;
  if (hsimcjetSignImpXYSignificance) delete hsimcjetSignImpXYSignificance;
  if (hsimcjetPtSignImpXYSignificance) delete hsimcjetPtSignImpXYSignificance;
  if (hsimcjetImpXYZ) delete hsimcjetImpXYZ;
  if (hsimcjetSignImpXYZ) delete hsimcjetSignImpXYZ;
  if (hsimcjetImpXYZSignificance) delete hsimcjetImpXYZSignificance;
  if (hsimcjetSignImpXYZSignificance) delete hsimcjetSignImpXYZSignificance;

  if (hsimbjetImpXY) delete hsimbjetImpXY;
  if (hsimbjetImpXYSignificance) delete hsimbjetImpXYSignificance;
  if (hsimbjetSignImpXY) delete hsimbjetSignImpXY;
  if (hsimbjetSignImpXYSignificance) delete hsimbjetSignImpXYSignificance;
  if (hsimbjetPtSignImpXYSignificance) delete hsimbjetPtSignImpXYSignificance;
  if (hsimbjetImpXYZ) delete hsimbjetImpXYZ;
  if (hsimbjetImpXYZSignificance) delete hsimbjetImpXYZSignificance;
  if (hsimbjetSignImpXYZ) delete hsimbjetSignImpXYZ;
  if (hsimbjetSignImpXYZSignificance) delete hsimbjetSignImpXYZSignificance;

  // related to Track Counting

  if (hsimlfjetImpXYN1) delete hsimlfjetImpXYN1;
  if (hsimlfjetImpXYN2) delete hsimlfjetImpXYN2;
  if (hsimlfjetImpXYN3) delete hsimlfjetImpXYN3;
  if (hsimlfjetSignImpXYN1) delete hsimlfjetSignImpXYN1;
  if (hsimlfjetSignImpXYN2) delete hsimlfjetSignImpXYN2;
  if (hsimlfjetSignImpXYN3) delete hsimlfjetSignImpXYN3;
  if (hsimlfjetImpXYZSignificanceN1) delete hsimlfjetImpXYZSignificanceN1;
  if (hsimlfjetImpXYZSignificanceN2) delete hsimlfjetImpXYZSignificanceN2;
  if (hsimlfjetImpXYZSignificanceN3) delete hsimlfjetImpXYZSignificanceN3;
  if (hsimcjetSignImpXYN1) delete hsimcjetSignImpXYN1;
  if (hsimcjetSignImpXYN2) delete hsimcjetSignImpXYN2;
  if (hsimcjetSignImpXYN3) delete hsimcjetSignImpXYN3;
  if (hsimlfjetImpXYZN1) delete hsimlfjetImpXYZN1;
  if (hsimlfjetImpXYZN2) delete hsimlfjetImpXYZN2;
  if (hsimlfjetImpXYZN3) delete hsimlfjetImpXYZN3;
  if (hsimlfjetImpXYSignificanceN1) delete hsimlfjetImpXYSignificanceN1;
  if (hsimlfjetImpXYSignificanceN2) delete hsimlfjetImpXYSignificanceN2;
  if (hsimlfjetImpXYSignificanceN3) delete hsimlfjetImpXYSignificanceN3;
  if (hsimlfjetPtSignImpXYSignificanceN1) delete hsimlfjetPtSignImpXYSignificanceN1;
  if (hsimlfjetPtSignImpXYSignificanceN2) delete hsimlfjetPtSignImpXYSignificanceN2;
  if (hsimlfjetPtSignImpXYSignificanceN3) delete hsimlfjetPtSignImpXYSignificanceN3;
  if (hsimlfjetSignImpXYSignificanceN1) delete hsimlfjetSignImpXYSignificanceN1;
  if (hsimlfjetSignImpXYSignificanceN2) delete hsimlfjetSignImpXYSignificanceN2;
  if (hsimlfjetSignImpXYSignificanceN3) delete hsimlfjetSignImpXYSignificanceN3;
  if (hsimcjetImpXYN1) delete hsimcjetImpXYN1;
  if (hsimcjetImpXYN2) delete hsimcjetImpXYN2;
  if (hsimcjetImpXYN3) delete hsimcjetImpXYN3;
  if (hsimcjetImpXYSignificanceN1) delete hsimcjetImpXYSignificanceN1;
  if (hsimcjetImpXYSignificanceN2) delete hsimcjetImpXYSignificanceN2;
  if (hsimcjetImpXYSignificanceN3) delete hsimcjetImpXYSignificanceN3;
  if (hsimcjetSignImpXYSignificanceN1) delete hsimcjetSignImpXYSignificanceN1;
  if (hsimcjetSignImpXYSignificanceN2) delete hsimcjetSignImpXYSignificanceN2;
  if (hsimcjetSignImpXYSignificanceN3) delete hsimcjetSignImpXYSignificanceN3;
  if (hsimcjetPtSignImpXYSignificanceN1) delete hsimcjetPtSignImpXYSignificanceN1;
  if (hsimcjetPtSignImpXYSignificanceN2) delete hsimcjetPtSignImpXYSignificanceN2;
  if (hsimcjetPtSignImpXYSignificanceN3) delete hsimcjetPtSignImpXYSignificanceN3;
  if (hsimbjetImpXYN1) delete hsimbjetImpXYN1;
  if (hsimbjetImpXYN2) delete hsimbjetImpXYN2;
  if (hsimbjetImpXYN3) delete hsimbjetImpXYN3;
  if (hsimbjetImpXYSignificanceN1) delete hsimbjetImpXYSignificanceN1;
  if (hsimbjetImpXYSignificanceN2) delete hsimbjetImpXYSignificanceN2;
  if (hsimbjetImpXYSignificanceN3) delete hsimbjetImpXYSignificanceN3;
  if (hsimbjetSignImpXYN1) delete hsimbjetSignImpXYN1;
  if (hsimbjetSignImpXYN2) delete hsimbjetSignImpXYN2;
  if (hsimbjetSignImpXYN3) delete hsimbjetSignImpXYN3;
  if (hsimbjetSignImpXYSignificanceN1) delete hsimbjetSignImpXYSignificanceN1;
  if (hsimbjetSignImpXYSignificanceN2) delete hsimbjetSignImpXYSignificanceN2;
  if (hsimbjetSignImpXYSignificanceN3) delete hsimbjetSignImpXYSignificanceN3;
  if (hsimbjetPtSignImpXYSignificanceN1) delete hsimbjetPtSignImpXYSignificanceN1;
  if (hsimbjetPtSignImpXYSignificanceN2) delete hsimbjetPtSignImpXYSignificanceN2;
  if (hsimbjetPtSignImpXYSignificanceN3) delete hsimbjetPtSignImpXYSignificanceN3;
  if (hsimbjetImpXYZN1) delete hsimbjetImpXYZN1;
  if (hsimbjetImpXYZN2) delete hsimbjetImpXYZN2;
  if (hsimbjetImpXYZN3) delete hsimbjetImpXYZN3;
  if (hsimbjetImpXYZSignificanceN1) delete hsimbjetImpXYZSignificanceN1;
  if (hsimbjetImpXYZSignificanceN2) delete hsimbjetImpXYZSignificanceN2;
  if (hsimbjetImpXYZSignificanceN3) delete hsimbjetImpXYZSignificanceN3;

  // related to Resolution function
  if (hsimlfjetSignImpXYSignificanceClass1) delete hsimlfjetSignImpXYSignificanceClass1;
  if (hsimlfjetSignImpXYSignificanceClass2) delete hsimlfjetSignImpXYSignificanceClass2;
  if (hsimlfjetSignImpXYSignificanceClass3) delete hsimlfjetSignImpXYSignificanceClass3;
  if (hsimcjetSignImpXYSignificanceClass1) delete hsimcjetSignImpXYSignificanceClass1;
  if (hsimcjetSignImpXYSignificanceClass2) delete hsimcjetSignImpXYSignificanceClass2;
  if (hsimcjetSignImpXYSignificanceClass3) delete hsimcjetSignImpXYSignificanceClass3;
  if (hsimbjetSignImpXYSignificanceClass1) delete hsimbjetSignImpXYSignificanceClass1;
  if (hsimbjetSignImpXYSignificanceClass2) delete hsimbjetSignImpXYSignificanceClass2;
  if (hsimbjetSignImpXYSignificanceClass3) delete hsimbjetSignImpXYSignificanceClass3;

  // related to Jet probability
  if (hsimlfjetJP) delete hsimlfjetJP;
  if (hsimlfjetJPLog) delete hsimlfjetJPLog;
  if (hsimlfjetPtJP) delete hsimlfjetPtJP;
  if (hsimlfjetPtJPLog) delete hsimlfjetPtJPLog;
  if (hsimcjetJP) delete hsimcjetJP;
  if (hsimcjetJPLog) delete hsimcjetJPLog;
  if (hsimcjetPtJP) delete hsimcjetPtJP;
  if (hsimcjetPtJPLog) delete hsimcjetPtJPLog;
  if (hsimbjetJP) delete hsimbjetJP;
  if (hsimbjetJPLog) delete hsimbjetJPLog;
  if (hsimbjetPtJP) delete hsimbjetPtJP;
  if (hsimbjetPtJPLog) delete hsimbjetPtJPLog;

  // Normalized
  // Delete normalized histograms
  if (hsimlfjetNormalizedTrackPt) delete hsimlfjetNormalizedTrackPt;
  if (hsimlfjetNormalizedTrackPhi) delete hsimlfjetNormalizedTrackPhi;
  if (hsimlfjetNormalizedTrackEta) delete hsimlfjetNormalizedTrackEta;

  if (hsimcjetNormalizedTrackPt) delete hsimcjetNormalizedTrackPt;
  if (hsimcjetNormalizedTrackPhi) delete hsimcjetNormalizedTrackPhi;
  if (hsimcjetNormalizedTrackEta) delete hsimcjetNormalizedTrackEta;

  if (hsimbjetNormalizedTrackPt) delete hsimbjetNormalizedTrackPt;
  if (hsimbjetNormalizedTrackPhi) delete hsimbjetNormalizedTrackPhi;
  if (hsimbjetNormalizedTrackEta) delete hsimbjetNormalizedTrackEta;

  if (hsimlfjetNormalizedImpXY) delete hsimlfjetNormalizedImpXY;
  if (hsimlfjetNormalizedImpXYSignificance) delete hsimlfjetNormalizedImpXYSignificance;
  if (hsimlfjetNormalizedSignImpXY) delete hsimlfjetNormalizedSignImpXY;
  if (hsimlfjetNormalizedSignImpXYSignificance) delete hsimlfjetNormalizedSignImpXYSignificance;
  if (hsimlfjetNormalizedPtSignImpXYSignificance) delete hsimlfjetNormalizedPtSignImpXYSignificance;

  if (hsimlfjetNormalizedImpXYZ) delete hsimlfjetNormalizedImpXYZ;
  if (hsimlfjetNormalizedImpXYZSignificance) delete hsimlfjetNormalizedImpXYZSignificance;

  if (hsimcjetNormalizedImpXY) delete hsimcjetNormalizedImpXY;
  if (hsimcjetNormalizedImpXYSignificance) delete hsimcjetNormalizedImpXYSignificance;
  if (hsimcjetNormalizedSignImpXY) delete hsimcjetNormalizedSignImpXY;
  if (hsimcjetNormalizedSignImpXYSignificance) delete hsimcjetNormalizedSignImpXYSignificance;
  if (hsimcjetNormalizedPtSignImpXYSignificance) delete hsimcjetNormalizedPtSignImpXYSignificance;

  if (hsimcjetNormalizedImpXYZ) delete hsimcjetNormalizedImpXYZ;
  if (hsimcjetNormalizedImpXYZSignificance) delete hsimcjetNormalizedImpXYZSignificance;

  if (hsimbjetNormalizedImpXY) delete hsimbjetNormalizedImpXY;
  if (hsimbjetNormalizedImpXYSignificance) delete hsimbjetNormalizedImpXYSignificance;
  if (hsimbjetNormalizedSignImpXY) delete hsimbjetNormalizedSignImpXY;
  if (hsimbjetNormalizedSignImpXYSignificance) delete hsimbjetNormalizedSignImpXYSignificance;
  if (hsimbjetNormalizedPtSignImpXYSignificance) delete hsimbjetNormalizedPtSignImpXYSignificance;

  if (hsimbjetNormalizedImpXYZ) delete hsimbjetNormalizedImpXYZ;
  if (hsimbjetNormalizedImpXYZSignificance) delete hsimbjetNormalizedImpXYZSignificance;
  if (hsimlfjetNormalizedImpXYN1) delete hsimlfjetNormalizedImpXYN1;
  if (hsimlfjetNormalizedImpXYN2) delete hsimlfjetNormalizedImpXYN2;
  if (hsimlfjetNormalizedImpXYN3) delete hsimlfjetNormalizedImpXYN3;
  if (hsimlfjetNormalizedSignImpXYN1) delete hsimlfjetNormalizedSignImpXYN1;
  if (hsimlfjetNormalizedSignImpXYN2) delete hsimlfjetNormalizedSignImpXYN2;
  if (hsimlfjetNormalizedSignImpXYN3) delete hsimlfjetNormalizedSignImpXYN3;
  if (hsimlfjetNormalizedImpXYZN1) delete hsimlfjetNormalizedImpXYZN1;
  if (hsimlfjetNormalizedImpXYZN2) delete hsimlfjetNormalizedImpXYZN2;
  if (hsimlfjetNormalizedImpXYZN3) delete hsimlfjetNormalizedImpXYZN3;
  if (hsimlfjetNormalizedImpXYZSignificanceN1) delete hsimlfjetNormalizedImpXYZSignificanceN1;
  if (hsimlfjetNormalizedImpXYZSignificanceN2) delete hsimlfjetNormalizedImpXYZSignificanceN2;
  if (hsimlfjetNormalizedImpXYZSignificanceN3) delete hsimlfjetNormalizedImpXYZSignificanceN3;

  if (hsimcjetNormalizedSignImpXYN1) delete hsimcjetNormalizedSignImpXYN1;
  if (hsimcjetNormalizedSignImpXYN2) delete hsimcjetNormalizedSignImpXYN2;
  if (hsimcjetNormalizedSignImpXYN3) delete hsimcjetNormalizedSignImpXYN3;
  if (hsimcjetNormalizedImpXYN1) delete hsimcjetNormalizedImpXYN1;
  if (hsimcjetNormalizedImpXYN2) delete hsimcjetNormalizedImpXYN2;
  if (hsimcjetNormalizedImpXYN3) delete hsimcjetNormalizedImpXYN3;
  if (hsimcjetNormalizedImpXYSignificanceN1) delete hsimcjetNormalizedImpXYSignificanceN1;
  if (hsimcjetNormalizedImpXYSignificanceN2) delete hsimcjetNormalizedImpXYSignificanceN2;
  if (hsimcjetNormalizedImpXYSignificanceN3) delete hsimcjetNormalizedImpXYSignificanceN3;
  if (hsimcjetNormalizedSignImpXYSignificanceN1) delete hsimcjetNormalizedSignImpXYSignificanceN1;
  if (hsimcjetNormalizedSignImpXYSignificanceN2) delete hsimcjetNormalizedSignImpXYSignificanceN2;
  if (hsimcjetNormalizedSignImpXYSignificanceN3) delete hsimcjetNormalizedSignImpXYSignificanceN3;
  if (hsimcjetNormalizedPtSignImpXYSignificanceN1) delete hsimcjetNormalizedPtSignImpXYSignificanceN1;
  if (hsimcjetNormalizedPtSignImpXYSignificanceN2) delete hsimcjetNormalizedPtSignImpXYSignificanceN2;
  if (hsimcjetNormalizedPtSignImpXYSignificanceN3) delete hsimcjetNormalizedPtSignImpXYSignificanceN3;

  if (hsimbjetNormalizedImpXYN1) delete hsimbjetNormalizedImpXYN1;
  if (hsimbjetNormalizedImpXYN2) delete hsimbjetNormalizedImpXYN2;
  if (hsimbjetNormalizedImpXYN3) delete hsimbjetNormalizedImpXYN3;
  if (hsimbjetNormalizedImpXYSignificanceN1) delete hsimbjetNormalizedImpXYSignificanceN1;
  if (hsimbjetNormalizedImpXYSignificanceN2) delete hsimbjetNormalizedImpXYSignificanceN2;
  if (hsimbjetNormalizedImpXYSignificanceN3) delete hsimbjetNormalizedImpXYSignificanceN3;
  if (hsimbjetNormalizedSignImpXYN1) delete hsimbjetNormalizedSignImpXYN1;
  if (hsimbjetNormalizedSignImpXYN2) delete hsimbjetNormalizedSignImpXYN2;
  if (hsimbjetNormalizedSignImpXYN3) delete hsimbjetNormalizedSignImpXYN3;
  if (hsimbjetNormalizedSignImpXYSignificanceN1) delete hsimbjetNormalizedSignImpXYSignificanceN1;
  if (hsimbjetNormalizedSignImpXYSignificanceN2) delete hsimbjetNormalizedSignImpXYSignificanceN2;
  if (hsimbjetNormalizedSignImpXYSignificanceN3) delete hsimbjetNormalizedSignImpXYSignificanceN3;
  if (hsimbjetNormalizedPtSignImpXYSignificanceN1) delete hsimbjetNormalizedPtSignImpXYSignificanceN1;
  if (hsimbjetNormalizedPtSignImpXYSignificanceN2) delete hsimbjetNormalizedPtSignImpXYSignificanceN2;
  if (hsimbjetNormalizedPtSignImpXYSignificanceN3) delete hsimbjetNormalizedPtSignImpXYSignificanceN3;

  if (hsimlfjetNormalizedSignImpXYSignificanceClass1) delete hsimlfjetNormalizedSignImpXYSignificanceClass1;
  if (hsimlfjetNormalizedSignImpXYSignificanceClass2) delete hsimlfjetNormalizedSignImpXYSignificanceClass2;
  if (hsimlfjetNormalizedSignImpXYSignificanceClass3) delete hsimlfjetNormalizedSignImpXYSignificanceClass3;

  if (hsimcjetNormalizedSignImpXYSignificanceClass1) delete hsimcjetNormalizedSignImpXYSignificanceClass1;
  if (hsimcjetNormalizedSignImpXYSignificanceClass2) delete hsimcjetNormalizedSignImpXYSignificanceClass2;
  if (hsimcjetNormalizedSignImpXYSignificanceClass3) delete hsimcjetNormalizedSignImpXYSignificanceClass3;

  if (hsimbjetNormalizedSignImpXYSignificanceClass1) delete hsimbjetNormalizedSignImpXYSignificanceClass1;
  if (hsimbjetNormalizedSignImpXYSignificanceClass2) delete hsimbjetNormalizedSignImpXYSignificanceClass2;
  if (hsimbjetNormalizedSignImpXYSignificanceClass3) delete hsimbjetNormalizedSignImpXYSignificanceClass3;
  if (hsimlfjetNormalizedJP) delete hsimlfjetNormalizedJP;
  if (hsimlfjetNormalizedJPLog) delete hsimlfjetNormalizedJPLog;
  if (hsimlfjetNormalizedPtJP) delete hsimlfjetNormalizedPtJP;
  if (hsimlfjetNormalizedPtJPLog) delete hsimlfjetNormalizedPtJPLog;

  if (hsimcjetNormalizedJP) delete hsimcjetNormalizedJP;
  if (hsimcjetNormalizedJPLog) delete hsimcjetNormalizedJPLog;
  if (hsimcjetNormalizedPtJP) delete hsimcjetNormalizedPtJP;
  if (hsimcjetNormalizedPtJPLog) delete hsimcjetNormalizedPtJPLog;

  if (hsimbjetNormalizedJP) delete hsimbjetNormalizedJP;
  if (hsimbjetNormalizedJPLog) delete hsimbjetNormalizedJPLog;
  if (hsimbjetNormalizedPtJP) delete hsimbjetNormalizedPtJP;
  if (hsimbjetNormalizedPtJPLog) delete hsimbjetNormalizedPtJPLog;

}

void HfJetTaggingTCAnalysis::InitHistogram(bool doTC, bool doJP) {
  if (doTC) {
    hsimlfjetNormalizedTrackPt = (TH1D*) hsimlfjetTrackPt->Clone("hsimlfjetNormalizedTrackPt");
    hsimlfjetNormalizedTrackPhi = (TH1D*)hsimlfjetTrackPhi->Clone("hsimlfjetNormalizedTrackPhi");
    hsimlfjetNormalizedTrackEta = (TH1D*)hsimlfjetTrackEta->Clone("hsimlfjetNormalizedTrackEta");

    hsimcjetNormalizedTrackPt = (TH1D*)hsimcjetTrackPt->Clone("hsimcjetNormalizedTrackPt");
    hsimcjetNormalizedTrackPhi = (TH1D*)hsimcjetTrackPhi->Clone("hsimcjetNormalizedTrackPhi");
    hsimcjetNormalizedTrackEta = (TH1D*)hsimcjetTrackEta->Clone("hsimcjetNormalizedTrackEta");

    hsimbjetNormalizedTrackPt = (TH1D*)hsimbjetTrackPt->Clone("hsimbjetNormalizedTrackPt");
    hsimbjetNormalizedTrackPhi = (TH1D*)hsimbjetTrackPhi->Clone("hsimbjetNormalizedTrackPhi");
    hsimbjetNormalizedTrackEta = (TH1D*)hsimbjetTrackEta->Clone("hsimbjetNormalizedTrackEta");

    // related Impact parameter
    hsimlfjetNormalizedImpXY = (TH1D*)hsimlfjetImpXY->Clone("hsimlfjetNormalizedImpXY");
    hsimlfjetNormalizedImpXYSignificance = (TH1D*)hsimlfjetImpXYSignificance->Clone("hsimlfjetNormalizedImpXYSignificance");
    hsimlfjetNormalizedSignImpXY = (TH1D*)hsimlfjetSignImpXY->Clone("hsimlfjetNormalizedSignImpXY");
    hsimlfjetNormalizedSignImpXYSignificance = (TH1D*)hsimlfjetSignImpXYSignificance->Clone("hsimlfjetNormalizedSignImpXYSignificance");
    hsimlfjetNormalizedPtSignImpXYSignificance = (TH1D*)hsimlfjetPtSignImpXYSignificance->Clone("hsimlfjetNormalizedPtSignImpXYSignificance");
    hsimlfjetNormalizedImpXYZ = (TH1D*)hsimlfjetImpXYZ->Clone("hsimlfjetNormalizedImpXYZ");
    hsimlfjetNormalizedImpXYZSignificance = (TH1D*)hsimlfjetImpXYZSignificance->Clone("hsimlfjetNormalizedImpXYZSignificance");
    hsimlfjetNormalizedSignImpXYZ = (TH1D*)hsimlfjetSignImpXYZ->Clone("hsimlfjetNormalizedSignImpXYZ");
    hsimlfjetNormalizedSignImpXYZSignificance = (TH1D*)hsimlfjetSignImpXYZSignificance->Clone("hsimlfjetNormalizedSignImpXYZSignificance");

    hsimcjetNormalizedImpXY = (TH1D*)hsimcjetImpXY->Clone("hsimcjetNormalizedImpXY");
    hsimcjetNormalizedImpXYSignificance = (TH1D*)hsimcjetImpXYSignificance->Clone("hsimcjetNormalizedImpXYSignificance");
    hsimcjetNormalizedSignImpXY = (TH1D*)hsimcjetSignImpXY->Clone("hsimcjetNormalizedSignImpXY");
    hsimcjetNormalizedSignImpXYSignificance = (TH1D*)hsimcjetSignImpXYSignificance->Clone("hsimcjetNormalizedSignImpXYSignificance");
    hsimcjetNormalizedPtSignImpXYSignificance = (TH1D*)hsimcjetPtSignImpXYSignificance->Clone("hsimcjetNormalizedPtSignImpXYSignificance");
    hsimcjetNormalizedImpXYZ = (TH1D*)hsimcjetImpXYZ->Clone("hsimcjetNormalizedImpXYZ");
    hsimcjetNormalizedImpXYZSignificance = (TH1D*)hsimcjetImpXYZSignificance->Clone("hsimcjetNormalizedImpXYZSignificance");
    hsimcjetNormalizedSignImpXYZ = (TH1D*)hsimcjetSignImpXYZ->Clone("hsimcjetNormalizedSignImpXYZ");
    hsimcjetNormalizedSignImpXYZSignificance = (TH1D*)hsimcjetSignImpXYZSignificance->Clone("hsimcjetNormalizedSignImpXYZSignificance");

    hsimbjetNormalizedImpXY = (TH1D*)hsimbjetImpXY->Clone("hsimbjetNormalizedImpXY");
    hsimbjetNormalizedImpXYSignificance = (TH1D*)hsimbjetImpXYSignificance->Clone("hsimbjetNormalizedImpXYSignificance");
    hsimbjetNormalizedSignImpXY = (TH1D*)hsimbjetSignImpXY->Clone("hsimbjetNormalizedSignImpXY");
    hsimbjetNormalizedSignImpXYSignificance = (TH1D*)hsimbjetSignImpXYSignificance->Clone("hsimbjetNormalizedSignImpXYSignificance");
    hsimbjetNormalizedPtSignImpXYSignificance = (TH1D*)hsimbjetPtSignImpXYSignificance->Clone("hsimbjetNormalizedPtSignImpXYSignificance");
    hsimbjetNormalizedImpXYZ = (TH1D*)hsimbjetImpXYZ->Clone("hsimbjetNormalizedImpXYZ");
    hsimbjetNormalizedImpXYZSignificance = (TH1D*)hsimbjetImpXYZSignificance->Clone("hsimbjetNormalizedImpXYZSignificance");
    hsimbjetNormalizedSignImpXYZ = (TH1D*)hsimbjetSignImpXYZ->Clone("hsimbjetNormalizedSignImpXYZ");
    hsimbjetNormalizedSignImpXYZSignificance = (TH1D*)hsimbjetSignImpXYZSignificance->Clone("hsimbjetNormalizedSignImpXYZSignificance");

    // related Track Counting
    hsimlfjetNormalizedImpXYN1 = (TH1D*)hsimlfjetImpXYN1->Clone("hsimlfjetNormalizedImpXYN1");
    hsimlfjetNormalizedImpXYN2 = (TH1D*)hsimlfjetImpXYN2->Clone("hsimlfjetNormalizedImpXYN2");
    hsimlfjetNormalizedImpXYN3 = (TH1D*)hsimlfjetImpXYN3->Clone("hsimlfjetNormalizedImpXYN3");
    hsimlfjetNormalizedSignImpXYN1 = (TH1D*)hsimlfjetSignImpXYN1->Clone("hsimlfjetNormalizedSignImpXYN1");
    hsimlfjetNormalizedSignImpXYN2 = (TH1D*)hsimlfjetSignImpXYN2->Clone("hsimlfjetNormalizedSignImpXYN2");
    hsimlfjetNormalizedSignImpXYN3 = (TH1D*)hsimlfjetSignImpXYN3->Clone("hsimlfjetNormalizedSignImpXYN3");
    hsimlfjetNormalizedImpXYZN1 = (TH1D*)hsimlfjetImpXYZN1->Clone("hsimlfjetNormalizedImpXYZN1");
    hsimlfjetNormalizedImpXYZN2 = (TH1D*)hsimlfjetImpXYZN2->Clone("hsimlfjetNormalizedImpXYZN2");
    hsimlfjetNormalizedImpXYZN3 = (TH1D*)hsimlfjetImpXYZN3->Clone("hsimlfjetNormalizedImpXYZN3");
    hsimlfjetNormalizedImpXYZSignificanceN1 = (TH1D*)hsimlfjetImpXYZSignificanceN1->Clone("hsimlfjetNormalizedImpXYZSignificanceN1");
    hsimlfjetNormalizedImpXYZSignificanceN2 = (TH1D*)hsimlfjetImpXYZSignificanceN2->Clone("hsimlfjetNormalizedImpXYZSignificanceN2");
    hsimlfjetNormalizedImpXYZSignificanceN3 = (TH1D*)hsimlfjetImpXYZSignificanceN3->Clone("hsimlfjetNormalizedImpXYZSignificanceN3");

    hsimcjetNormalizedSignImpXYN1 = (TH1D*)hsimcjetSignImpXYN1->Clone("hsimcjetNormalizedSignImpXYN1");
    hsimcjetNormalizedSignImpXYN2 = (TH1D*)hsimcjetSignImpXYN2->Clone("hsimcjetNormalizedSignImpXYN2");
    hsimcjetNormalizedSignImpXYN3 = (TH1D*)hsimcjetSignImpXYN3->Clone("hsimcjetNormalizedSignImpXYN3");

    hsimlfjetNormalizedImpXYSignificanceN1 = (TH1D*)hsimlfjetImpXYSignificanceN1->Clone("hsimlfjetNormalizedImpXYSignificanceN1");
    hsimlfjetNormalizedImpXYSignificanceN2 = (TH1D*)hsimlfjetImpXYSignificanceN2->Clone("hsimlfjetNormalizedImpXYSignificanceN2");
    hsimlfjetNormalizedImpXYSignificanceN3 = (TH1D*)hsimlfjetImpXYSignificanceN3->Clone("hsimlfjetNormalizedImpXYSignificanceN3");
    //  hsimlfjetNormalizedPtSignImpXYSignificanceN1 = (TH1D*)hsimlfjetPtSignImpXYSignificanceN1->Clone("hsimlfjetNormalizedPtSignImpXYSignificanceN1");
    //  hsimlfjetNormalizedPtSignImpXYSignificanceN2 = (TH1D*)hsimlfjetPtSignImpXYSignificanceN2->Clone("hsimlfjetNormalizedPtSignImpXYSignificanceN2");
    //  hsimlfjetNormalizedPtSignImpXYSignificanceN3 = (TH1D*)hsimlfjetPtSignImpXYSignificanceN3->Clone("hsimlfjetNormalizedPtSignImpXYSignificanceN3");
    hsimlfjetNormalizedSignImpXYSignificanceN1 = (TH1D*)hsimlfjetSignImpXYSignificanceN1->Clone("hsimlfjetNormalizedSignImpXYSignificanceN1");
    hsimlfjetNormalizedSignImpXYSignificanceN2 = (TH1D*)hsimlfjetSignImpXYSignificanceN2->Clone("hsimlfjetNormalizedSignImpXYSignificanceN2");
    hsimlfjetNormalizedSignImpXYSignificanceN3 = (TH1D*)hsimlfjetSignImpXYSignificanceN3->Clone("hsimlfjetNormalizedSignImpXYSignificanceN3");

    hsimcjetNormalizedImpXYN1 = (TH1D*)hsimcjetImpXYN1->Clone("hsimcjetNormalizedImpXYN1");
    hsimcjetNormalizedImpXYN2 = (TH1D*)hsimcjetImpXYN2->Clone("hsimcjetNormalizedImpXYN2");
    hsimcjetNormalizedImpXYN3 = (TH1D*)hsimcjetImpXYN3->Clone("hsimcjetNormalizedImpXYN3");
    hsimcjetNormalizedImpXYSignificanceN1 = (TH1D*)hsimcjetImpXYSignificanceN1->Clone("hsimcjetNormalizedImpXYSignificanceN1");
    hsimcjetNormalizedImpXYSignificanceN2 = (TH1D*)hsimcjetImpXYSignificanceN2->Clone("hsimcjetNormalizedImpXYSignificanceN2");
    hsimcjetNormalizedImpXYSignificanceN3 = (TH1D*)hsimcjetImpXYSignificanceN3->Clone("hsimcjetNormalizedImpXYSignificanceN3");
    hsimcjetNormalizedSignImpXYSignificanceN1 = (TH1D*)hsimcjetSignImpXYSignificanceN1->Clone("hsimcjetNormalizedSignImpXYSignificanceN1");
    hsimcjetNormalizedSignImpXYSignificanceN2 = (TH1D*)hsimcjetSignImpXYSignificanceN2->Clone("hsimcjetNormalizedSignImpXYSignificanceN2");
    hsimcjetNormalizedSignImpXYSignificanceN3 = (TH1D*)hsimcjetSignImpXYSignificanceN3->Clone("hsimcjetNormalizedSignImpXYSignificanceN3");
    //  hsimcjetNormalizedPtSignImpXYSignificanceN1 = (TH1D*)hsimcjetPtSignImpXYSignificanceN1->Clone("hsimcjetNormalizedPtSignImpXYSignificanceN1");
    //  hsimcjetNormalizedPtSignImpXYSignificanceN2 = (TH1D*)hsimcjetPtSignImpXYSignificanceN2->Clone("hsimcjetNormalizedPtSignImpXYSignificanceN2");
    //  hsimcjetNormalizedPtSignImpXYSignificanceN3 = (TH1D*)hsimcjetPtSignImpXYSignificanceN3->Clone("hsimcjetNormalizedPtSignImpXYSignificanceN3");

    hsimbjetNormalizedImpXYN1 = (TH1D*)hsimbjetImpXYN1->Clone("hsimbjetNormalizedImpXYN1");
    hsimbjetNormalizedImpXYN2 = (TH1D*)hsimbjetImpXYN2->Clone("hsimbjetNormalizedImpXYN2");
    hsimbjetNormalizedImpXYN3 = (TH1D*)hsimbjetImpXYN3->Clone("hsimbjetNormalizedImpXYN3");
    hsimbjetNormalizedImpXYSignificanceN1 = (TH1D*)hsimbjetImpXYSignificanceN1->Clone("hsimbjetNormalizedImpXYSignificanceN1");
    hsimbjetNormalizedImpXYSignificanceN2 = (TH1D*)hsimbjetImpXYSignificanceN2->Clone("hsimbjetNormalizedImpXYSignificanceN2");
    hsimbjetNormalizedImpXYSignificanceN3 = (TH1D*)hsimbjetImpXYSignificanceN3->Clone("hsimbjetNormalizedImpXYSignificanceN3");
    hsimbjetNormalizedSignImpXYN1 = (TH1D*)hsimbjetSignImpXYN1->Clone("hsimbjetNormalizedSignImpXYN1");
    hsimbjetNormalizedSignImpXYN2 = (TH1D*)hsimbjetSignImpXYN2->Clone("hsimbjetNormalizedSignImpXYN2");
    hsimbjetNormalizedSignImpXYN3 = (TH1D*)hsimbjetSignImpXYN3->Clone("hsimbjetNormalizedSignImpXYN3");
    hsimbjetNormalizedSignImpXYSignificanceN1 = (TH1D*)hsimbjetSignImpXYSignificanceN1->Clone("hsimbjetNormalizedSignImpXYSignificanceN1");
    hsimbjetNormalizedSignImpXYSignificanceN2 = (TH1D*)hsimbjetSignImpXYSignificanceN2->Clone("hsimbjetNormalizedSignImpXYSignificanceN2");
    hsimbjetNormalizedSignImpXYSignificanceN3 = (TH1D*)hsimbjetSignImpXYSignificanceN3->Clone("hsimbjetNormalizedSignImpXYSignificanceN3");
    //  hsimbjetNormalizedPtSignImpXYSignificanceN1 = (TH1D*)hsimbjetPtSignImpXYSignificanceN1->Clone("hsimbjetNormalizedPtSignImpXYSignificanceN1");
    //  hsimbjetNormalizedPtSignImpXYSignificanceN2 = (TH1D*)hsimbjetPtSignImpXYSignificanceN2->Clone("hsimbjetNormalizedPtSignImpXYSignificanceN2");
    //  hsimbjetNormalizedPtSignImpXYSignificanceN3 = (TH1D*)hsimbjetPtSignImpXYSignificanceN3->Clone("hsimbjetNormalizedPtSignImpXYSignificanceN3");
    //
    //  // related Resolution function
    //  hsimlfjetNormalizedSignImpXYSignificanceClass1 = (TH1D*)hsimlfjetSignImpXYSignificanceClass1->Clone("hsimlfjetNormalizedSignImpXYSignificanceClass1");
    //  hsimlfjetNormalizedSignImpXYSignificanceClass2 = (TH1D*)hsimlfjetSignImpXYSignificanceClass2->Clone("hsimlfjetNormalizedSignImpXYSignificanceClass2");
    //  hsimlfjetNormalizedSignImpXYSignificanceClass3 = (TH1D*)hsimlfjetSignImpXYSignificanceClass3->Clone("hsimlfjetNormalizedSignImpXYSignificanceClass3");
    //
    //  hsimcjetNormalizedSignImpXYSignificanceClass1 = (TH1D*)hsimcjetSignImpXYSignificanceClass1->Clone("hsimcjetNormalizedSignImpXYSignificanceClass1");
    //  hsimcjetNormalizedSignImpXYSignificanceClass2 = (TH1D*)hsimcjetSignImpXYSignificanceClass2->Clone("hsimcjetNormalizedSignImpXYSignificanceClass2");
    //  hsimcjetNormalizedSignImpXYSignificanceClass3 = (TH1D*)hsimcjetSignImpXYSignificanceClass3->Clone("hsimcjetNormalizedSignImpXYSignificanceClass3");
    //
    //  hsimbjetNormalizedSignImpXYSignificanceClass1 = (TH1D*)hsimbjetSignImpXYSignificanceClass1->Clone("hsimbjetNormalizedSignImpXYSignificanceClass1");
    //  hsimbjetNormalizedSignImpXYSignificanceClass2 = (TH1D*)hsimbjetSignImpXYSignificanceClass2->Clone("hsimbjetNormalizedSignImpXYSignificanceClass2");
    //  hsimbjetNormalizedSignImpXYSignificanceClass3 = (TH1D*)hsimbjetSignImpXYSignificanceClass3->Clone("hsimbjetNormalizedSignImpXYSignificanceClass3");

    // related jetNormalized Probability
    if (doJP) {
      hsimlfjetNormalizedJP = (TH1D*)hsimlfjetJP->Clone("hsimlfjetNormalizedJP");
      hsimlfjetNormalizedJPLog = (TH1D*)hsimlfjetJPLog->Clone("hsimlfjetNormalizedJPLog");
      hsimlfjetNormalizedPtJP = (TH2D*)hsimlfjetPtJP->Clone("hsimlfjetNormalizedPtJP");
      hsimlfjetNormalizedPtJPLog = (TH2D*)hsimlfjetPtJPLog->Clone("hsimlfjetNormalizedPtJPLog");

      hsimcjetNormalizedJP = (TH1D*)hsimcjetJP->Clone("hsimcjetNormalizedJP");
      hsimcjetNormalizedJPLog = (TH1D*)hsimcjetJPLog->Clone("hsimcjetNormalizedJPLog");
      hsimcjetNormalizedPtJP = (TH2D*)hsimcjetPtJP->Clone("hsimcjetNormalizedPtJP");
      hsimcjetNormalizedPtJPLog = (TH2D*)hsimcjetPtJPLog->Clone("hsimcjetNormalizedPtJPLog");

      hsimbjetNormalizedJP = (TH1D*)hsimbjetJP->Clone("hsimbjetNormalizedJP");
      hsimbjetNormalizedJPLog = (TH1D*)hsimbjetJPLog->Clone("hsimbjetNormalizedJPLog");
      hsimbjetNormalizedPtJP = (TH2D*)hsimbjetPtJP->Clone("hsimbjetNormalizedPtJP");
      hsimbjetNormalizedPtJPLog = (TH2D*)hsimbjetPtJPLog->Clone("hsimbjetNormalizedPtJPLog");
    }
  }
}

void HfJetTaggingTCAnalysis::NormalizedHistogram(bool doTC, bool doJP) {
  if (doTC) {
    hsimlfjetNormalizedTrackPt->Scale(1. / hsimlfjetNormalizedTrackPt->GetEntries());
    hsimlfjetNormalizedTrackPhi->Scale(1. / hsimlfjetNormalizedTrackPhi->GetEntries());
    hsimlfjetNormalizedTrackEta->Scale(1. / hsimlfjetNormalizedTrackEta->GetEntries());

    hsimcjetNormalizedTrackPt->Scale(1. / hsimcjetNormalizedTrackPt->GetEntries());
    hsimcjetNormalizedTrackPhi->Scale(1. / hsimcjetNormalizedTrackPhi->GetEntries());
    hsimcjetNormalizedTrackEta->Scale(1. / hsimcjetNormalizedTrackEta->GetEntries());

    hsimbjetNormalizedTrackPt->Scale(1. / hsimbjetNormalizedTrackPt->GetEntries());
    hsimbjetNormalizedTrackPhi->Scale(1. / hsimbjetNormalizedTrackPhi->GetEntries());
    hsimbjetNormalizedTrackEta->Scale(1. / hsimbjetNormalizedTrackEta->GetEntries());

    hsimlfjetNormalizedImpXY->Scale(1. / hsimlfjetNormalizedImpXY->GetEntries());
    hsimcjetNormalizedImpXY->Scale(1. / hsimcjetNormalizedImpXY->GetEntries());
    hsimbjetNormalizedImpXY->Scale(1. / hsimbjetNormalizedImpXY->GetEntries());
    hsimlfjetNormalizedSignImpXY->Scale(1. / hsimlfjetNormalizedSignImpXY->GetEntries());
    hsimcjetNormalizedSignImpXY->Scale(1. / hsimcjetNormalizedSignImpXY->GetEntries());
    hsimbjetNormalizedSignImpXY->Scale(1. / hsimbjetNormalizedSignImpXY->GetEntries());

    hsimlfjetNormalizedImpXYSignificance->Scale(1. / hsimlfjetNormalizedImpXYSignificance->GetEntries());
    hsimlfjetNormalizedSignImpXYSignificance->Scale(1. / hsimlfjetNormalizedSignImpXYSignificance->GetEntries());
    //hsimlfjetNormalizedPtSignImpXYSignificance->Scale(1. / hsimlfjetNormalizedPtSignImpXYSignificance->GetEntries());

    hsimcjetNormalizedImpXYSignificance->Scale  (1. / hsimcjetNormalizedImpXYSignificance->GetEntries());
    hsimcjetNormalizedSignImpXYSignificance->Scale(1. / hsimcjetNormalizedSignImpXYSignificance->GetEntries());
    //hsimcjetNormalizedPtSignImpXYSignificance->Scale(1. / hsimcjetNormalizedPtSignImpXYSignificance->GetEntries());

    hsimbjetNormalizedImpXYSignificance->Scale(1. / hsimbjetNormalizedImpXYSignificance->GetEntries());
    hsimbjetNormalizedSignImpXYSignificance->Scale(1. / hsimbjetNormalizedSignImpXYSignificance->GetEntries());
    //hsimbjetNormalizedPtSignImpXYSignificance->Scale(1. / hsimbjetNormalizedPtSignImpXYSignificance->GetEntries());

    hsimlfjetNormalizedImpXYZ->Scale(1. / hsimlfjetNormalizedImpXYZ->GetEntries());
    hsimlfjetNormalizedSignImpXYZ->Scale(1. / hsimlfjetNormalizedSignImpXYZ->GetEntries());
    hsimlfjetNormalizedImpXYZSignificance->Scale(1. / hsimlfjetNormalizedImpXYZSignificance->GetEntries());
    hsimlfjetNormalizedSignImpXYZSignificance->Scale(1. / hsimlfjetNormalizedSignImpXYZSignificance->GetEntries());

    hsimcjetNormalizedImpXYZ->Scale(1. / hsimcjetNormalizedImpXYZ->GetEntries());
    hsimcjetNormalizedSignImpXYZ->Scale(1. / hsimcjetNormalizedSignImpXYZ->GetEntries());
    hsimcjetNormalizedImpXYZSignificance->Scale(1. / hsimcjetNormalizedImpXYZSignificance->GetEntries());
    hsimcjetNormalizedSignImpXYZSignificance->Scale(1. / hsimcjetNormalizedSignImpXYZSignificance->GetEntries());

    hsimbjetNormalizedImpXYZ->Scale(1. / hsimbjetNormalizedImpXYZ->GetEntries());
    hsimbjetNormalizedSignImpXYZ->Scale(1. / hsimbjetNormalizedSignImpXYZ->GetEntries());
    hsimbjetNormalizedImpXYZSignificance->Scale(1. / hsimbjetNormalizedImpXYZSignificance->GetEntries());
    hsimbjetNormalizedSignImpXYZSignificance->Scale(1. / hsimbjetNormalizedSignImpXYZSignificance->GetEntries());

    hsimlfjetNormalizedImpXYN1->Scale(1. / hsimlfjetNormalizedImpXYN1->GetEntries());
    hsimlfjetNormalizedImpXYN2->Scale(1. / hsimlfjetNormalizedImpXYN2->GetEntries());
    hsimlfjetNormalizedImpXYN3->Scale(1. / hsimlfjetNormalizedImpXYN3->GetEntries());
    hsimlfjetNormalizedSignImpXYN1->Scale(1. / hsimlfjetNormalizedSignImpXYN1->GetEntries());
    hsimlfjetNormalizedSignImpXYN2->Scale(1. / hsimlfjetNormalizedSignImpXYN2->GetEntries());
    hsimlfjetNormalizedSignImpXYN3->Scale(1. / hsimlfjetNormalizedSignImpXYN3->GetEntries());
    hsimlfjetNormalizedImpXYZN1->Scale(1. / hsimlfjetNormalizedImpXYZN1->GetEntries());
    hsimlfjetNormalizedImpXYZN2->Scale(1. / hsimlfjetNormalizedImpXYZN2->GetEntries());
    hsimlfjetNormalizedImpXYZN3->Scale(1. / hsimlfjetNormalizedImpXYZN3->GetEntries());
    hsimlfjetNormalizedImpXYZSignificanceN1->Scale(1. / hsimlfjetNormalizedImpXYZSignificanceN1->GetEntries());
    hsimlfjetNormalizedImpXYZSignificanceN2->Scale(1. / hsimlfjetNormalizedImpXYZSignificanceN2->GetEntries());
    hsimlfjetNormalizedImpXYZSignificanceN3->Scale(1. / hsimlfjetNormalizedImpXYZSignificanceN3->GetEntries());

    hsimcjetNormalizedSignImpXYN1->Scale(1. / hsimcjetNormalizedSignImpXYN1->GetEntries());
    hsimcjetNormalizedSignImpXYN2->Scale(1. / hsimcjetNormalizedSignImpXYN2->GetEntries());
    hsimcjetNormalizedSignImpXYN3->Scale(1. / hsimcjetNormalizedSignImpXYN3->GetEntries());

    hsimlfjetNormalizedImpXYSignificanceN1->Scale(1. / hsimlfjetNormalizedImpXYSignificanceN1->GetEntries());
    hsimlfjetNormalizedImpXYSignificanceN2->Scale(1. / hsimlfjetNormalizedImpXYSignificanceN2->GetEntries());
    hsimlfjetNormalizedImpXYSignificanceN3->Scale(1. / hsimlfjetNormalizedImpXYSignificanceN3->GetEntries());
    //hsimlfjetNormalizedPtSignImpXYSignificanceN1->Scale(1. / hsimlfjetNormalizedPtSignImpXYSignificanceN1->GetEntries());
    //hsimlfjetNormalizedPtSignImpXYSignificanceN2->Scale(1. / hsimlfjetNormalizedPtSignImpXYSignificanceN2->GetEntries());
    //hsimlfjetNormalizedPtSignImpXYSignificanceN3->Scale(1. / hsimlfjetNormalizedPtSignImpXYSignificanceN3->GetEntries());
    hsimlfjetNormalizedSignImpXYSignificanceN1->Scale(1. / hsimlfjetNormalizedSignImpXYSignificanceN1->GetEntries());
    hsimlfjetNormalizedSignImpXYSignificanceN2->Scale(1. / hsimlfjetNormalizedSignImpXYSignificanceN2->GetEntries());
    hsimlfjetNormalizedSignImpXYSignificanceN3->Scale(1. / hsimlfjetNormalizedSignImpXYSignificanceN3->GetEntries());

    hsimcjetNormalizedImpXYN1->Scale(1. / hsimcjetNormalizedImpXYN1->GetEntries());
    hsimcjetNormalizedImpXYN2->Scale(1. / hsimcjetNormalizedImpXYN2->GetEntries());
    hsimcjetNormalizedImpXYN3->Scale(1. / hsimcjetNormalizedImpXYN3->GetEntries());
    hsimcjetNormalizedImpXYSignificanceN1->Scale(1. / hsimcjetNormalizedImpXYSignificanceN1->GetEntries());
    hsimcjetNormalizedImpXYSignificanceN2->Scale(1. / hsimcjetNormalizedImpXYSignificanceN2->GetEntries());
    hsimcjetNormalizedImpXYSignificanceN3->Scale(1. / hsimcjetNormalizedImpXYSignificanceN3->GetEntries());
    hsimcjetNormalizedSignImpXYSignificanceN1->Scale(1. / hsimcjetNormalizedSignImpXYSignificanceN1->GetEntries());
    hsimcjetNormalizedSignImpXYSignificanceN2->Scale(1. / hsimcjetNormalizedSignImpXYSignificanceN2->GetEntries());
    hsimcjetNormalizedSignImpXYSignificanceN3->Scale(1. / hsimcjetNormalizedSignImpXYSignificanceN3->GetEntries());
    //hsimcjetNormalizedPtSignImpXYSignificanceN1->Scale(1. / hsimcjetNormalizedPtSignImpXYSignificanceN1->GetEntries());
    //hsimcjetNormalizedPtSignImpXYSignificanceN2->Scale(1. / hsimcjetNormalizedPtSignImpXYSignificanceN2->GetEntries());
    //hsimcjetNormalizedPtSignImpXYSignificanceN3->Scale(1. / hsimcjetNormalizedPtSignImpXYSignificanceN3->GetEntries());

    hsimbjetNormalizedImpXYN1->Scale(1. / hsimbjetNormalizedImpXYN1->GetEntries());
    hsimbjetNormalizedImpXYN2->Scale(1. / hsimbjetNormalizedImpXYN2->GetEntries());
    hsimbjetNormalizedImpXYN3->Scale(1. / hsimbjetNormalizedImpXYN3->GetEntries());
    hsimbjetNormalizedImpXYSignificanceN1->Scale(1. / hsimbjetNormalizedImpXYSignificanceN1->GetEntries());
    hsimbjetNormalizedImpXYSignificanceN2->Scale(1. / hsimbjetNormalizedImpXYSignificanceN2->GetEntries());
    hsimbjetNormalizedImpXYSignificanceN3->Scale(1. / hsimbjetNormalizedImpXYSignificanceN3->GetEntries());
    hsimbjetNormalizedSignImpXYN1->Scale(1. / hsimbjetNormalizedSignImpXYN1->GetEntries());
    hsimbjetNormalizedSignImpXYN2->Scale(1. / hsimbjetNormalizedSignImpXYN2->GetEntries());
    hsimbjetNormalizedSignImpXYN3->Scale(1. / hsimbjetNormalizedSignImpXYN3->GetEntries());
    hsimbjetNormalizedSignImpXYSignificanceN1->Scale(1. / hsimbjetNormalizedSignImpXYSignificanceN1->GetEntries());
    hsimbjetNormalizedSignImpXYSignificanceN2->Scale(1. / hsimbjetNormalizedSignImpXYSignificanceN2->GetEntries());
    hsimbjetNormalizedSignImpXYSignificanceN3->Scale(1. / hsimbjetNormalizedSignImpXYSignificanceN3->GetEntries());
    //hsimbjetNormalizedPtSignImpXYSignificanceN1->Scale(1. / hsimbjetNormalizedPtSignImpXYSignificanceN1->GetEntries());
    //hsimbjetNormalizedPtSignImpXYSignificanceN2->Scale(1. / hsimbjetNormalizedPtSignImpXYSignificanceN2->GetEntries());
    //hsimbjetNormalizedPtSignImpXYSignificanceN3->Scale(1. / hsimbjetNormalizedPtSignImpXYSignificanceN3->GetEntries());

    //  // Scaling histograms for NormalizedSignImpXYSignificanceClass1, NormalizedSignImpXYSignificanceClass2, and NormalizedSignImpXYSignificanceClass3
    //  hsimlfjetNormalizedSignImpXYSignificanceClass1->Scale(1. / hsimlfjetNormalizedSignImpXYSignificanceClass1->GetEntries());
    //  hsimlfjetNormalizedSignImpXYSignificanceClass2->Scale(1. / hsimlfjetNormalizedSignImpXYSignificanceClass2->GetEntries());
    //  hsimlfjetNormalizedSignImpXYSignificanceClass3->Scale(1. / hsimlfjetNormalizedSignImpXYSignificanceClass3->GetEntries());
    //
    //  hsimcjetNormalizedSignImpXYSignificanceClass1->Scale(1. / hsimcjetNormalizedSignImpXYSignificanceClass1->GetEntries());
    //  hsimcjetNormalizedSignImpXYSignificanceClass2->Scale(1. / hsimcjetNormalizedSignImpXYSignificanceClass2->GetEntries());
    //  hsimcjetNormalizedSignImpXYSignificanceClass3->Scale(1. / hsimcjetNormalizedSignImpXYSignificanceClass3->GetEntries());
    //
    //  hsimbjetNormalizedSignImpXYSignificanceClass1->Scale(1. / hsimbjetNormalizedSignImpXYSignificanceClass1->GetEntries());
    //  hsimbjetNormalizedSignImpXYSignificanceClass2->Scale(1. / hsimbjetNormalizedSignImpXYSignificanceClass2->GetEntries());
    //  hsimbjetNormalizedSignImpXYSignificanceClass3->Scale(1. / hsimbjetNormalizedSignImpXYSignificanceClass3->GetEntries());

    if (doJP) {
      hsimlfjetNormalizedJP->Scale(1. / hsimlfjetNormalizedJP->GetEntries());
      hsimlfjetNormalizedJPLog->Scale(1. / hsimlfjetNormalizedJPLog->GetEntries());

      hsimcjetNormalizedJP->Scale(1. / hsimcjetNormalizedJP->GetEntries());
      hsimcjetNormalizedJPLog->Scale(1. / hsimcjetNormalizedJPLog->GetEntries());

      hsimbjetNormalizedJP->Scale(1. / hsimbjetNormalizedJP->GetEntries());
      hsimbjetNormalizedJPLog->Scale(1. / hsimbjetNormalizedJPLog->GetEntries());
    }
  }
}

void HfJetTaggingTCAnalysis::SaveHistogram(TString outFile) {
  TFile *fout = TFile::Open(outFile.Data(),"recreate");
  if (!fout) return;
  hsimlfjetNormalizedTrackPt->Write();
  hsimlfjetNormalizedTrackPhi->Write();
  hsimlfjetNormalizedTrackEta->Write();
  hsimcjetNormalizedTrackPt->Write();
  hsimcjetNormalizedTrackPhi->Write();
  hsimcjetNormalizedTrackEta->Write();
  hsimbjetNormalizedTrackPt->Write();
  hsimbjetNormalizedTrackPhi->Write();
  hsimbjetNormalizedTrackEta->Write();
  hsimincjetNormalizedImpXYSignificance->Write();
  hsimincjetNormalizedSignImpXYSignificance->Write();
  hsimincjetNormalizedPtSignImpXYSignificance->Write();
  hsimlfjetNormalizedImpXY->Write();
  hsimlfjetNormalizedImpXYSignificance->Write();
  hsimlfjetNormalizedSignImpXY->Write();
  hsimlfjetNormalizedSignImpXYSignificance->Write();
  hsimlfjetNormalizedPtSignImpXYSignificance->Write();
  hsimlfjetNormalizedImpXYZ->Write();
  hsimlfjetNormalizedImpXYZSignificance->Write();
  hsimcjetNormalizedImpXY->Write();
  hsimcjetNormalizedImpXYSignificance->Write();
  hsimcjetNormalizedSignImpXY->Write();
  hsimcjetNormalizedSignImpXYSignificance->Write();
  hsimcjetNormalizedPtSignImpXYSignificance->Write();
  hsimcjetNormalizedImpXYZ->Write();
  hsimcjetNormalizedImpXYZSignificance->Write();
  hsimbjetNormalizedImpXY->Write();
  hsimbjetNormalizedImpXYSignificance->Write();
  hsimbjetNormalizedSignImpXY->Write();
  hsimbjetNormalizedSignImpXYSignificance->Write();
  hsimbjetNormalizedPtSignImpXYSignificance->Write();
  hsimbjetNormalizedImpXYZ->Write();
  hsimbjetNormalizedImpXYZSignificance->Write();
  hsimincjetNormalizedPtSignImpXYSignificanceN1->Write();
  hsimincjetNormalizedPtSignImpXYSignificanceN2->Write();
  hsimincjetNormalizedPtSignImpXYSignificanceN3->Write();
  hsimlfjetNormalizedImpXYN1->Write();
  hsimlfjetNormalizedImpXYN2->Write();
  hsimlfjetNormalizedImpXYN3->Write();
  hsimlfjetNormalizedSignImpXYN1->Write();
  hsimlfjetNormalizedSignImpXYN2->Write();
  hsimlfjetNormalizedSignImpXYN3->Write();
  hsimlfjetNormalizedImpXYZN1->Write();
  hsimlfjetNormalizedImpXYZN2->Write();
  hsimlfjetNormalizedImpXYZN3->Write();
  hsimlfjetNormalizedImpXYZSignificanceN1->Write();
  hsimlfjetNormalizedImpXYZSignificanceN2->Write();
  hsimlfjetNormalizedImpXYZSignificanceN3->Write();
  hsimcjetNormalizedSignImpXYN1->Write();
  hsimcjetNormalizedSignImpXYN2->Write();
  hsimcjetNormalizedSignImpXYN3->Write();
  hsimlfjetNormalizedImpXYSignificanceN1->Write();
  hsimlfjetNormalizedImpXYSignificanceN2->Write();
  hsimlfjetNormalizedImpXYSignificanceN3->Write();
  hsimlfjetNormalizedPtSignImpXYSignificanceN1->Write();
  hsimlfjetNormalizedPtSignImpXYSignificanceN2->Write();
  hsimlfjetNormalizedPtSignImpXYSignificanceN3->Write();
  hsimlfjetNormalizedSignImpXYSignificanceN1->Write();
  hsimlfjetNormalizedSignImpXYSignificanceN2->Write();
  hsimlfjetNormalizedSignImpXYSignificanceN3->Write();
  hsimcjetNormalizedImpXYN1->Write();
  hsimcjetNormalizedImpXYN2->Write();
  hsimcjetNormalizedImpXYN3->Write();
  hsimcjetNormalizedImpXYSignificanceN1->Write();
  hsimcjetNormalizedImpXYSignificanceN2->Write();
  hsimcjetNormalizedImpXYSignificanceN3->Write();
  hsimcjetNormalizedSignImpXYSignificanceN1->Write();
  hsimcjetNormalizedSignImpXYSignificanceN2->Write();
  hsimcjetNormalizedSignImpXYSignificanceN3->Write();
  hsimcjetNormalizedPtSignImpXYSignificanceN1->Write();
  hsimcjetNormalizedPtSignImpXYSignificanceN2->Write();
  hsimcjetNormalizedPtSignImpXYSignificanceN3->Write();
  hsimcjetNormalizedImpXYZN1->Write();
  hsimcjetNormalizedImpXYZN2->Write();
  hsimcjetNormalizedImpXYZN3->Write();
  hsimcjetNormalizedImpXYZSignificanceN1->Write();
  hsimcjetNormalizedImpXYZSignificanceN2->Write();
  hsimcjetNormalizedImpXYZSignificanceN3->Write();
  hsimbjetNormalizedImpXYN1->Write();
  hsimbjetNormalizedImpXYN2->Write();
  hsimbjetNormalizedImpXYN3->Write();
  hsimbjetNormalizedImpXYSignificanceN1->Write();
  hsimbjetNormalizedImpXYSignificanceN2->Write();
  hsimbjetNormalizedImpXYSignificanceN3->Write();
  hsimbjetNormalizedSignImpXYN1->Write();
  hsimbjetNormalizedSignImpXYN2->Write();
  hsimbjetNormalizedSignImpXYN3->Write();
  hsimbjetNormalizedSignImpXYSignificanceN1->Write();
  hsimbjetNormalizedSignImpXYSignificanceN2->Write();
  hsimbjetNormalizedSignImpXYSignificanceN3->Write();
  //hsimbjetNormalizedPtSignImpXYSignificanceN1->Write();
  //hsimbjetNormalizedPtSignImpXYSignificanceN2->Write();
  //hsimbjetNormalizedPtSignImpXYSignificanceN3->Write();
  hsimbjetNormalizedImpXYZN1->Write();
  hsimbjetNormalizedImpXYZN2->Write();
  hsimbjetNormalizedImpXYZN3->Write();
  hsimbjetNormalizedImpXYZSignificanceN1->Write();
  hsimbjetNormalizedImpXYZSignificanceN2->Write();
  hsimbjetNormalizedImpXYZSignificanceN3->Write();
  hsimlfjetNormalizedSignImpXYSignificanceClass1->Write();
  hsimlfjetNormalizedSignImpXYSignificanceClass2->Write();
  hsimlfjetNormalizedSignImpXYSignificanceClass3->Write();
  hsimcjetNormalizedSignImpXYSignificanceClass1->Write();
  hsimcjetNormalizedSignImpXYSignificanceClass2->Write();
  hsimcjetNormalizedSignImpXYSignificanceClass3->Write();
  hsimbjetNormalizedSignImpXYSignificanceClass1->Write();
  hsimbjetNormalizedSignImpXYSignificanceClass2->Write();
  hsimbjetNormalizedSignImpXYSignificanceClass3->Write();

  delete fout;
}

int HfJetTaggingTCAnalysis::LoadSim(TString rootFile, TString taskName, bool doTC, bool doJP) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  taskName = "jet-taggerhf-tc-charged";

  TFile* fin;
  fin = TFile::Open(rootFile, "READ");
  if (doTC) {
    hsimPdgCode = (TH1D*)fin->Get(Form("%s/h_jet_track_mother_pdgcode", taskName.Data()));
    hsimStatusCode = (TH1D*)fin->Get(Form("%s/h_jet_track_mother_statuscode", taskName.Data()));
    hsimbjetTrackPt = (TH1D*)fin->Get(Form("%s/h_bjet_track_pt", taskName.Data()));
    hsimcjetTrackPt = (TH1D*)fin->Get(Form("%s/h_cjet_track_pt", taskName.Data()));
    hsimlfjetTrackPt = (TH1D*)fin->Get(Form("%s/h_lfjet_track_pt", taskName.Data()));
    hsimbjetTrackPhi = (TH1D*)fin->Get(Form("%s/h_bjet_track_phi", taskName.Data()));
    hsimcjetTrackPhi = (TH1D*)fin->Get(Form("%s/h_cjet_track_phi", taskName.Data()));
    hsimlfjetTrackPhi = (TH1D*)fin->Get(Form("%s/h_lfjet_track_phi", taskName.Data()));
    hsimbjetTrackEta = (TH1D*)fin->Get(Form("%s/h_bjet_track_eta", taskName.Data()));
    hsimcjetTrackEta = (TH1D*)fin->Get(Form("%s/h_cjet_track_eta", taskName.Data()));
    hsimlfjetTrackEta = (TH1D*)fin->Get(Form("%s/h_lfjet_track_eta", taskName.Data()));

    // inclusive
    // impact parameter
    // bjet
    hsimbjetImpXY = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy", taskName.Data()));
    hsimbjetImpXYN1 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_N1", taskName.Data()));
    hsimbjetImpXYN2 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_N2", taskName.Data()));
    hsimbjetImpXYN3 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_N3", taskName.Data()));
    hsimbjetSignImpXY = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy", taskName.Data()));
    hsimbjetSignImpXYN1 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_N1", taskName.Data()));
    hsimbjetSignImpXYN2 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_N2", taskName.Data()));
    hsimbjetSignImpXYN3 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_N3", taskName.Data()));

    hsimbjetImpXYZ = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz", taskName.Data()));
    hsimbjetImpXYZN1 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_N1", taskName.Data()));
    hsimbjetImpXYZN2 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_N2", taskName.Data()));
    hsimbjetImpXYZN3 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_N3", taskName.Data()));
    hsimbjetSignImpXYZ = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xyz", taskName.Data()));

    // cjet
    hsimcjetImpXY = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy", taskName.Data()));
    hsimcjetImpXYN1 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_N1", taskName.Data()));
    hsimcjetImpXYN2 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_N2", taskName.Data()));
    hsimcjetImpXYN3 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_N3", taskName.Data()));
    hsimcjetSignImpXY = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy", taskName.Data()));
    hsimcjetSignImpXYN1 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_N1", taskName.Data()));
    hsimcjetSignImpXYN2 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_N2", taskName.Data()));
    hsimcjetSignImpXYN3 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_N3", taskName.Data()));

    hsimcjetImpXYZ = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz", taskName.Data()));
    hsimcjetImpXYZN1 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_N1", taskName.Data()));
    hsimcjetImpXYZN2 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_N2", taskName.Data()));
    hsimcjetImpXYZN3 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_N3", taskName.Data()));
    hsimcjetSignImpXYZ = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xyz", taskName.Data()));

    // lfjet

    hsimlfjetImpXY = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy", taskName.Data()));
    hsimlfjetImpXYN1 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_N1", taskName.Data()));
    hsimlfjetImpXYN2 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_N2", taskName.Data()));
    hsimlfjetImpXYN3 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_N3", taskName.Data()));
    hsimlfjetSignImpXY = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy", taskName.Data()));
    hsimlfjetSignImpXYN1 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_N1", taskName.Data()));
    hsimlfjetSignImpXYN2 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_N2", taskName.Data()));
    hsimlfjetSignImpXYN3 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_N3", taskName.Data()));

    hsimlfjetImpXYZ = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz", taskName.Data()));
    hsimlfjetImpXYZN1 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_N1", taskName.Data()));
    hsimlfjetImpXYZN2 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_N2", taskName.Data()));
    hsimlfjetImpXYZN3 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_N3", taskName.Data()));
    hsimlfjetSignImpXYZ = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xyz", taskName.Data()));

    // impact parameter significance
    // bjet
    hsimbjetImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_significance", taskName.Data()));
    hsimbjetImpXYSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_significance_N1", taskName.Data()));
    hsimbjetImpXYSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_significance_N2", taskName.Data()));
    hsimbjetImpXYSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xy_significance_N3", taskName.Data()));
    hsimbjetSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance", taskName.Data()));
    hsimbjetPtSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_bjet_pt_sign_impact_parameter_xy_significance", taskName.Data()));
    hsimbjetSignImpXYSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance_N1", taskName.Data()));
    hsimbjetSignImpXYSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance_N2", taskName.Data()));
    hsimbjetSignImpXYSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance_N3", taskName.Data()));

    hsimbjetImpXYZSignificance = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_significance", taskName.Data()));
    hsimbjetImpXYZSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_significance_N1", taskName.Data()));
    hsimbjetImpXYZSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_significance_N2", taskName.Data()));
    hsimbjetImpXYZSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_bjet_impact_parameter_xyz_significance_N3", taskName.Data()));
    hsimbjetSignImpXYZSignificance = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xyz_significance", taskName.Data()));

    // cjet
    hsimcjetImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_significance", taskName.Data()));
    hsimcjetImpXYSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_significance_N1", taskName.Data()));
    hsimcjetImpXYSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_significance_N2", taskName.Data()));
    hsimcjetImpXYSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xy_significance_N3", taskName.Data()));
    hsimcjetSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance", taskName.Data()));
    hsimcjetPtSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_cjet_pt_sign_impact_parameter_xy_significance", taskName.Data()));
    hsimcjetSignImpXYSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance_N1", taskName.Data()));
    hsimcjetSignImpXYSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance_N2", taskName.Data()));
    hsimcjetSignImpXYSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance_N3", taskName.Data()));

    hsimcjetImpXYZSignificance = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_significance", taskName.Data()));
    hsimcjetImpXYZSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_significance_N1", taskName.Data()));
    hsimcjetImpXYZSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_significance_N2", taskName.Data()));
    hsimcjetImpXYZSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_cjet_impact_parameter_xyz_significance_N3", taskName.Data()));
    hsimcjetSignImpXYZSignificance = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xyz_significance", taskName.Data()));

    // lfjet
    hsimlfjetImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_significance", taskName.Data()));
    hsimlfjetImpXYSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_significance_N1", taskName.Data()));
    hsimlfjetImpXYSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_significance_N2", taskName.Data()));
    hsimlfjetImpXYSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xy_significance_N3", taskName.Data()));
    hsimlfjetSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance", taskName.Data()));
    hsimlfjetPtSignImpXYSignificance = (TH1D*)fin->Get(Form("%s/h_lfjet_pt_sign_impact_parameter_xy_significance", taskName.Data()));
    hsimlfjetSignImpXYSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance_N1", taskName.Data()));
    hsimlfjetSignImpXYSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance_N2", taskName.Data()));
    hsimlfjetSignImpXYSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance_N3", taskName.Data()));

    hsimlfjetImpXYZSignificance = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_significance", taskName.Data()));
    hsimlfjetImpXYZSignificanceN1 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_significance_N1", taskName.Data()));
    hsimlfjetImpXYZSignificanceN2 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_significance_N2", taskName.Data()));
    hsimlfjetImpXYZSignificanceN3 = (TH1D*)fin->Get(Form("%s/h_lfjet_impact_parameter_xyz_significance_N3", taskName.Data()));
    hsimlfjetSignImpXYZSignificance = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xyz_significance", taskName.Data()));

    // Jet Probability
    if (doJP) {
      hsimlfjetSignImpXYSignificanceClass1 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance_class1", taskName.Data()));
      hsimlfjetSignImpXYSignificanceClass2 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance_class2", taskName.Data()));
      hsimlfjetSignImpXYSignificanceClass3 = (TH1D*)fin->Get(Form("%s/h_lfjet_sign_impact_parameter_xy_significance_class3", taskName.Data()));
      hsimcjetSignImpXYSignificanceClass1 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance_class1", taskName.Data()));
      hsimcjetSignImpXYSignificanceClass2 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance_class2", taskName.Data()));
      hsimcjetSignImpXYSignificanceClass3 = (TH1D*)fin->Get(Form("%s/h_cjet_sign_impact_parameter_xy_significance_class3", taskName.Data()));
      hsimbjetSignImpXYSignificanceClass1 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance_class1", taskName.Data()));
      hsimbjetSignImpXYSignificanceClass2 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance_class2", taskName.Data()));
      hsimbjetSignImpXYSignificanceClass3 = (TH1D*)fin->Get(Form("%s/h_bjet_sign_impact_parameter_xy_significance_class3", taskName.Data()));

      hsimbjetJP = (TH1D*)fin->Get(Form("%s/h_bjet_JP", taskName.Data()));
      hsimbjetJPLog = (TH1D*)fin->Get(Form("%s/h_bjet_JP_Log", taskName.Data()));
      hsimbjetPtJP = (TH2D*)fin->Get(Form("%s/h_bjet_pt_JP", taskName.Data()));
      hsimbjetPtJPLog = (TH2D*)fin->Get(Form("%s/h_bjet_pt_JP_Log", taskName.Data()));
      hsimcjetJP = (TH1D*)fin->Get(Form("%s/h_cjet_JP", taskName.Data()));
      hsimcjetJPLog = (TH1D*)fin->Get(Form("%s/h_cjet_JP_Log", taskName.Data()));
      hsimcjetPtJP = (TH2D*)fin->Get(Form("%s/h_cjet_pt_JP", taskName.Data()));
      hsimcjetPtJPLog = (TH2D*)fin->Get(Form("%s/h_cjet_pt_JP_Log", taskName.Data()));
      hsimlfjetJP = (TH1D*)fin->Get(Form("%s/h_lfjet_JP", taskName.Data()));
      hsimlfjetJPLog = (TH1D*)fin->Get(Form("%s/h_lfjet_JP_Log", taskName.Data()));
      hsimlfjetPtJP = (TH2D*)fin->Get(Form("%s/h_lfjet_pt_JP", taskName.Data()));
      hsimlfjetPtJPLog = (TH2D*)fin->Get(Form("%s/h_lfjet_pt_JP_Log", taskName.Data()));
    }
  } else {
    std::cout << "don't load TC MC histogram" << std::endl;
  }

  std::cout << "Load completed MC data" << std::endl;
  return 1;
}

int HfJetTaggingTCAnalysis::LoadData(TString rootFile, TString taskName) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }

  //if (taskName.CompareTo("hf-tagging-task")>0 || taskName.CompareTo("hf-tagging-task")<0) {
    //taskName = "hf-tagging-task";
  //}

  return 1;
}

void HfJetTaggingTCAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, double xmin, double ymin, double xmax, double ymax){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1D *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  leg->Draw();
}

void HfJetTaggingTCAnalysis::DrawTaggedJetTrackPt(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedTrackPt, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedTrackPt, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedTrackPt, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedTrackPt, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "track p_{T}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/trackmomentum.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetTrackEta(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedTrackEta, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedTrackEta, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedTrackEta, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedTrackEta, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "track #eta", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/tracketa.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetTrackPhi(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedTrackPhi, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedTrackPhi, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedTrackPhi, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedTrackPhi, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "track #phi", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/trackphi.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetImpXY(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedImpXY, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXY, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXY, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXY, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXY.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXY(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedSignImpXY, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXY, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXY, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXY, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "Signed IP_{XY} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXY.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYSignificance(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedImpXYSignificance, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYSignificance, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYSignificance, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYSignificance, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificance(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedSignImpXYSignificance, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYSignificance, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYSignificance, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYSignificance, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYZ(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedImpXYZ, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYZ, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYZ, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYZ, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "IP_{XYZ} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYZ.pdf\")", canvasNum - 1));

}

void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYZ(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedSignImpXYZ, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYZ, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYZ, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYZ, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "Signed IP_{XYZ} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZ.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYZSignificance(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedImpXYZSignificance, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYZSignificance, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYZSignificance, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYZSignificance, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "IPs_{XYZ}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYZSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYZSignificance(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjetNormalizedSignImpXYZSignificance, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYZSignificance, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYZSignificance, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYZSignificance, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "Signed IPs_{XYZ}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYZSignificance.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYN1(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYN1, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYN1, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYN1, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYN1, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY}^{N_{1}} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYN1.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYN2(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYN2, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYN2, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYN2, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYN2, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY}^{N_{2}} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYN2.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYN3(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYN3, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYN3, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYN3, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYN3, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY}^{N_{3}} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYN3.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYN1(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedSignImpXYN1, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYN1, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYN1, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYN1, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "Signed IP_{XY}^{N_{1}} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYN1.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYN2(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedSignImpXYN2, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYN2, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYN2, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYN2, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "Signed IP_{XY}^{N_{2}} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYN2.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYN3(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYN3, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYN3, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYN3, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYN3, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "Signed IP_{XY}^{N_{3}} [cm]", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYN3.pdf\")", canvasNum - 1));
}

void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYSignificanceN1(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYSignificanceN1, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYSignificanceN1, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYSignificanceN1, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYSignificanceN1, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY}^{N_{1}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYSignificanceN1.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYSignificanceN2(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYSignificanceN2, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYSignificanceN2, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYSignificanceN2, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYSignificanceN2, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY}^{N_{2}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYSignificanceN2.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetImpXYSignificanceN3(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedImpXYSignificanceN3, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedImpXYSignificanceN3, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedImpXYSignificanceN3, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedImpXYSignificanceN3, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY}^{N_{3}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/ImpXYSignificanceN3.pdf\")", canvasNum - 1));
}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificanceN1(){
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimincjetNormalizedSignImpXYSignificanceN1, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYSignificanceN1, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYSignificanceN1, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYSignificanceN1, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{1}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificanceN1.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificanceN2(){
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimincjetNormalizedSignImpXYSignificanceN2, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYSignificanceN2, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYSignificanceN2, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYSignificanceN2, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{2}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificanceN2.pdf\")", canvasNum - 1));

}
void HfJetTaggingTCAnalysis::DrawTaggedJetSignImpXYSignificanceN3(){
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimincjetNormalizedSignImpXYSignificanceN3, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedSignImpXYSignificanceN3, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedSignImpXYSignificanceN3, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedSignImpXYSignificanceN3, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}^{N_{3}}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/SignImpXYSignificanceN3.pdf\")", canvasNum - 1));
}

void HfJetTaggingTCAnalysis::DrawTaggedJetProbability(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedJP, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedJP, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedJP, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedJP, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/JetProbability.pdf\")", canvasNum - 1));
}
void HfJetTaggingTCAnalysis::DrawTaggedJetProbabilityLog(){
  std::vector<HistogramData> NormHistList;
  //NormHistList.push_back({hsimincjetNormalizedJPLog, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjetNormalizedJPLog, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjetNormalizedJPLog, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjetNormalizedJPLog, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/JetProbabilityLog.pdf\")", canvasNum - 1));
}

#endif // HFJETTAGGINGTCANALYSIS_H 

