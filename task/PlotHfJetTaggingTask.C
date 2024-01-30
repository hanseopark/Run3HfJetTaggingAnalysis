#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingGeneralQA(TString rootdata="", TString rootsim="") {
  TString taskTC = "jet-taggerhf-tc-charged";
  TString taskSV = "jet-taggerhf-sv-charged";
  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doJP = false;
  bool doSV2Prong = false;
  bool doSV3Prong = false;
  bool doTemplateFit = false;
  bool withInc = true;
  bool doLog = true;

  HfJetTaggingAnalysis *HfJetTagObj = new HfJetTaggingAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, dopartLevel);

  // General Plot QA
  /// Each parameter distribution when compared jet flavour if you want to be able to add inclusive
  /// Data
  if (doData) {
    HfJetTagObj->DrawDataTagJetPt(doLog);
    HfJetTagObj->DrawDataTagTrackPt(doLog, 0);
    HfJetTagObj->DrawDataTagTrackEta(doLog, 0);
    HfJetTagObj->DrawDataTagTrackPhi(doLog, 0);
  }

  /// MC
  if (doMC) {
    HfJetTagObj->DrawTaggedJetTrackPt(withInc, doLog, 0);
    HfJetTagObj->DrawTaggedJetTrackEta(withInc, doLog);
    HfJetTagObj->DrawTaggedJetTrackPhi(withInc, doLog);
    HfJetTagObj->DrawTaggedJetImpXY(withInc, doLog);
    HfJetTagObj->DrawTaggedJetSignImpXY(withInc, doLog);
    HfJetTagObj->DrawTaggedJetImpXYSignificance(withInc, doLog);
    HfJetTagObj->DrawTaggedJetSignImpXYSignificance(withInc, doLog);
    HfJetTagObj->DrawTaggedJetImpZ(withInc, doLog);
    HfJetTagObj->DrawTaggedJetSignImpZ(withInc, doLog);
    HfJetTagObj->DrawTaggedJetImpZSignificance(withInc, doLog);
    HfJetTagObj->DrawTaggedJetSignImpZSignificance(withInc, doLog);
    HfJetTagObj->DrawTaggedJetImpXYZ(withInc, doLog);
    HfJetTagObj->DrawTaggedJetSignImpXYZ(withInc, doLog);
    HfJetTagObj->DrawTaggedJetImpXYZSignificance(withInc, doLog);
    HfJetTagObj->DrawTaggedJetSignImpXYZSignificance(withInc, doLog);
    for (int flavour =1; flavour < HfJetTagging::nFlavour+1; flavour++) {
      HfJetTagObj->DrawTaggedFlavourJetTrackPt(doLog, flavour, HfJetTagging::startJetPt);
    }
  }

  //HfJetTagObj->SaveHistogramFlavourQA("FlavourQA.root", true, false);

//  // For MC data
//  if (doTC) { /// IP and TC method
//    HfJetTaggingTCAnalysis *HfJetTagTCObj = new HfJetTaggingTCAnalysis(rootsimTC.Data(), rootsimSV2Prong.Data(), rootsimSV3Prong.Data(), taskTC.Data(), taskSV.Data(), doMC, doTC, doJP, doSV2Prong, doSV3Prong);
//    // General Plot QA
//    /// Each parameter distribution when compared jet flavour if you want to be able to add inclusive
//    HfJetTagTCObj->DrawTaggedJetTrackPt(withInc, doLog, 0);
//    HfJetTagTCObj->DrawTaggedJetTrackEta(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetTrackPhi(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetImpXY(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetSignImpXY(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetImpXYSignificance(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificance(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetImpXYZ(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetSignImpXYZ(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetImpXYZSignificance(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetSignImpXYZSignificance(withInc, doLog);
//
//    /// Each parameter distribution in jet flavour when compared jet pT range 
//    for (int i=1; i<4; i++) { // 1: charm, 2: beauty, 3: light flavour
//      HfJetTagTCObj->DrawTaggedFlavourJetTrackPt(doLog, i, HfJetTagging::startJetPt);
//      HfJetTagTCObj->DrawTaggedFlavourJetTrackEta(doLog, i, HfJetTagging::startJetPt);
//      HfJetTagTCObj->DrawTaggedFlavourJetTrackPhi(doLog, i, HfJetTagging::startJetPt);
//    }
//    // TC
//    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN1(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN2(withInc, doLog);
//    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN3(withInc, doLog);
//
////    // Track counting
////    HfJetTagTCObj->DrawTaggedJetImpXYN1(doLog);
////    HfJetTagTCObj->DrawTaggedJetSignImpXYN1(doLog);
////    HfJetTagTCObj->DrawTaggedJetImpXYSignificanceN1(doLog);
////    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN1(doLog);
////    HfJetTagTCObj->DrawTaggedJetImpXYN2(doLog);
////    HfJetTagTCObj->DrawTaggedJetSignImpXYN2(doLog);
////    HfJetTagTCObj->DrawTaggedJetImpXYSignificanceN2(doLog);
////    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN2(doLog);
////    HfJetTagTCObj->DrawTaggedJetImpXYN3(doLog);
////    HfJetTagTCObj->DrawTaggedJetSignImpXYN3(doLog);
////    HfJetTagTCObj->DrawTaggedJetImpXYSignificanceN3(doLog);
////    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN3(doLog);
////
////    // JP
////    if (doJP) {
////      HfJetTagTCObj->DrawTaggedJetProbability();
////      HfJetTagTCObj->DrawTaggedJetProbabilityLog();
////    }
//    HfJetTagTCObj->SaveHistogram("tc.root");
//  }
//
////  if (doSV2Prong || doSV3Prong) {
////    HfJetTaggingSVAnalysis *HfJetTagSVObj = new HfJetTaggingSVAnalysis(rootsimTC.Data(), rootsimSV2Prong.Data(), rootsimSV3Prong.Data(), taskTC.Data(), taskSV.Data(), doMC, doSV2Prong, doSV3Prong);
////    if (doSV2Prong) {
////      HfJetTagSVObj->DrawTaggedJet2ProngLxy(false, doLog);
////      HfJetTagSVObj->DrawTaggedJet2ProngSxy(false, doLog);
////      HfJetTagSVObj->DrawTaggedJet2ProngLxyz(false, doLog);
////      HfJetTagSVObj->DrawTaggedJet2ProngSxyz(false, doLog);
////    }
////    if (doSV3Prong) {
////      HfJetTagSVObj->DrawTaggedJet3ProngLxy(false, doLog);
////      HfJetTagSVObj->DrawTaggedJet3ProngSxy(false, doLog);
////      HfJetTagSVObj->DrawTaggedJet3ProngLxyz(false, doLog);
////      HfJetTagSVObj->DrawTaggedJet3ProngSxyz(false, doLog);
////    }
////  }
//
//  if (doTemplateFit) { // Template Fit
//  //HfJetTaggingTemplateFit& HfJetTagFitObj = dynamic_cast<HfJetTaggingAnalysis&>(*HfJetTagTCObj);
//  //HfJetTaggingTemplateFIt *HfJetTagFitObj = new HfJetTaggingTemplateFit(rootsim.Data(), taskTC.Data(), true);
//  }
}

void PlotHfJetTaggingTask(TString rootdata="", TString rootsim="") {
  PlotHfJetTaggingGeneralQA(rootdata.Data(), rootsim.Data());
}

