#include "../include/HfJetTaggingTCAnalysis.h"
#include "../include/HfJetTaggingSVAnalysis.h"
#include "../include/JetAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingTask(TString rootsimTC="", TString rootsimSV2Prong="", TString rootsimSV3Prong="") {
  TString taskTC = "jet-taggerhf-tc-charged";
  TString taskSV = "jet-taggerhf-sv-charged";
  bool doMC = true;
  bool doTC = true;
  bool doJP = false;
  bool doSV2Prong = true;
  bool doSV3Prong = true;
  bool withInc = true;

  if (doTC) { /// IP and TC method
    HfJetTaggingTCAnalysis *HfJetTagTCObj = new HfJetTaggingTCAnalysis(rootsimTC.Data(), rootsimSV2Prong.Data(), rootsimSV3Prong.Data(), taskTC.Data(), taskSV.Data(), doMC, doTC, doJP, doSV2Prong, doSV3Prong);
    // General Plot QA
    HfJetTagTCObj->DrawTaggedJetTrackPt(withInc);
    HfJetTagTCObj->DrawTaggedJetTrackEta(withInc);
    HfJetTagTCObj->DrawTaggedJetTrackPhi(withInc);
    HfJetTagTCObj->DrawTaggedJetImpXY(withInc);
    HfJetTagTCObj->DrawTaggedJetSignImpXY(withInc);
    HfJetTagTCObj->DrawTaggedJetImpXYSignificance(withInc);
    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificance(withInc);
    HfJetTagTCObj->DrawTaggedJetImpXYZ(withInc);
    HfJetTagTCObj->DrawTaggedJetSignImpXYZ(withInc);
    HfJetTagTCObj->DrawTaggedJetImpXYZSignificance(withInc);
    HfJetTagTCObj->DrawTaggedJetSignImpXYZSignificance(withInc);


    // Track counting
    HfJetTagTCObj->DrawTaggedJetImpXYN1();
    HfJetTagTCObj->DrawTaggedJetSignImpXYN1();
    HfJetTagTCObj->DrawTaggedJetImpXYSignificanceN1();
    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN1();
    HfJetTagTCObj->DrawTaggedJetImpXYN2();
    HfJetTagTCObj->DrawTaggedJetSignImpXYN2();
    HfJetTagTCObj->DrawTaggedJetImpXYSignificanceN2();
    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN2();
    HfJetTagTCObj->DrawTaggedJetImpXYN3();
    HfJetTagTCObj->DrawTaggedJetSignImpXYN3();
    HfJetTagTCObj->DrawTaggedJetImpXYSignificanceN3();
    HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN3();

    // JP
    if (doJP) {
      HfJetTagTCObj->DrawTaggedJetProbability();
      HfJetTagTCObj->DrawTaggedJetProbabilityLog();
    }
  }

  if (doSV2Prong || doSV3Prong) {
    HfJetTaggingSVAnalysis *HfJetTagSVObj = new HfJetTaggingSVAnalysis(rootsimTC.Data(), rootsimSV2Prong.Data(), rootsimSV3Prong.Data(), taskTC.Data(), taskSV.Data(), doMC, doSV2Prong, doSV3Prong);
    if (doSV2Prong) {
      HfJetTagSVObj->DrawTaggedJet2ProngLxy(false);
      HfJetTagSVObj->DrawTaggedJet2ProngSxy(false);
      HfJetTagSVObj->DrawTaggedJet2ProngLxyz(false);
      HfJetTagSVObj->DrawTaggedJet2ProngSxyz(false);
    }
    if (doSV3Prong) {
      HfJetTagSVObj->DrawTaggedJet3ProngLxy(false);
      HfJetTagSVObj->DrawTaggedJet3ProngSxy(false);
      HfJetTagSVObj->DrawTaggedJet3ProngLxyz(false);
      HfJetTagSVObj->DrawTaggedJet3ProngSxyz(false);
    }
  }

    // Template Fit
  //HfJetTaggingTemplateFit& HfJetTagFitObj = dynamic_cast<HfJetTaggingAnalysis&>(*HfJetTagTCObj);
  //HfJetTaggingTemplateFIt *HfJetTagFitObj = new HfJetTaggingTemplateFit(rootsim.Data(), taskTC.Data(), true);
}

