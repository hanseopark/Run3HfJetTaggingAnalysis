#include "../include/DataPoint.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingTCQA(TString rootdata, TString rootsim) {
  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool withInc = true;
  bool doLog = true;

  HfJetTaggingTCAnalysis *HfJetTagTCObj = new HfJetTaggingTCAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, dopartLevel);
  HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN1(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN2(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpXYSignificanceN3(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpZSignificanceN1(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpZSignificanceN2(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpZSignificanceN3(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpXYZSignificanceN1(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpXYZSignificanceN2(withInc, doLog);
  HfJetTagTCObj->DrawTaggedJetSignImpXYZSignificanceN3(withInc, doLog);

}

void PlotHfJetTCTaggingTask(TString rootdata="", TString rootsim="") {
  PlotHfJetTaggingTCQA(rootdata.Data(), rootsim.Data());
}

