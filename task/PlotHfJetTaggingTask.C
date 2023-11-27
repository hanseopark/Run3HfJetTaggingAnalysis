#include "../include/HfJetTaggingAnalysis.h"
#include "../include/JetAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingTask(TString rootsim="") {
  TString taskName = "jet-taggerhf-tc-charged";
  bool doMC = true;
  bool doJP = false;
  bool withInc = true;
  HfJetTaggingAnalysis *HfJetTagObj = new HfJetTaggingAnalysis(rootsim.Data(), taskName.Data(), doMC, doJP);

  // General Plot QA
  HfJetTagObj->DrawTaggedJetTrackPt(withInc);
  HfJetTagObj->DrawTaggedJetTrackEta(withInc);
  HfJetTagObj->DrawTaggedJetTrackPhi(withInc);
  HfJetTagObj->DrawTaggedJetImpXY(withInc);
  HfJetTagObj->DrawTaggedJetSignImpXY(withInc);
  HfJetTagObj->DrawTaggedJetImpXYSignificance(withInc);
  HfJetTagObj->DrawTaggedJetSignImpXYSignificance(withInc);
  HfJetTagObj->DrawTaggedJetImpXYZ(withInc);
  HfJetTagObj->DrawTaggedJetSignImpXYZ(withInc);
  HfJetTagObj->DrawTaggedJetImpXYZSignificance(withInc);
  HfJetTagObj->DrawTaggedJetSignImpXYZSignificance(withInc);


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
  if (doJP) {
    HfJetTagObj->DrawTaggedJetProbability();
    HfJetTagObj->DrawTaggedJetProbabilityLog();
  }

  // Template Fit
  //HfJetTaggingTemplateFit& HfJetTagFitObj = dynamic_cast<HfJetTaggingAnalysis&>(*HfJetTagObj);
  //HfJetTaggingTemplateFIt *HfJetTagFitObj = new HfJetTaggingTemplateFit(rootsim.Data(), taskName.Data(), true);
}

