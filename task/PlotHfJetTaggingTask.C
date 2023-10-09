#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingTask(TString rootsim="") {
  TString taskName = "hf-tagging-task";
  HfJetTaggingAnalysis *HfJetTagObj = new HfJetTaggingAnalysis(rootsim.Data(), taskName.Data(), true);

  // General Plot QA
  HfJetTagObj->DrawTaggedJetTrackPt();
  HfJetTagObj->DrawTaggedJetTrackEta();
  HfJetTagObj->DrawTaggedJetTrackPhi();
  HfJetTagObj->DrawTaggedJetImpXY();
  HfJetTagObj->DrawTaggedJetSignImpXY();
  HfJetTagObj->DrawTaggedJetImpXYSignificance();
  HfJetTagObj->DrawTaggedJetSignImpXYSignificance();
  HfJetTagObj->DrawTaggedJetImpXYZ();
  HfJetTagObj->DrawTaggedJetSignImpXYZ();
  HfJetTagObj->DrawTaggedJetImpXYZSignificance();
  HfJetTagObj->DrawTaggedJetSignImpXYZSignificance();


  // Track counting
  HfJetTagObj->DrawTaggedJetImpXYN1();
  HfJetTagObj->DrawTaggedJetSignImpXYN1();
  HfJetTagObj->DrawTaggedJetImpXYSignificanceN1();
  HfJetTagObj->DrawTaggedJetSignImpXYSignificanceN1();
  HfJetTagObj->DrawTaggedJetImpXYN2();
  HfJetTagObj->DrawTaggedJetSignImpXYN2();
  HfJetTagObj->DrawTaggedJetImpXYSignificanceN2();
  HfJetTagObj->DrawTaggedJetSignImpXYSignificanceN2();
  HfJetTagObj->DrawTaggedJetImpXYN3();
  HfJetTagObj->DrawTaggedJetSignImpXYN3();
  HfJetTagObj->DrawTaggedJetImpXYSignificanceN3();
  HfJetTagObj->DrawTaggedJetSignImpXYSignificanceN3();

  // JP
  HfJetTagObj->DrawTaggedJetProbability();
  HfJetTagObj->DrawTaggedJetProbabilityLog();
}

