#include "../include/DataPoint.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingTCQA(TString rootdata, TString rootsim) {
  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool withInc = true;
  bool doLog = true;

  double cutImpForEffi = 1.0;
  double cutImpForPurity = 1.0;
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
  HfJetTagTCObj->DrawTaggedJetEffiSignImpXYSigN1(cutImpForEffi);
  HfJetTagTCObj->DrawTaggedJetEffiSignImpXYSigN2(cutImpForEffi);
  HfJetTagTCObj->DrawTaggedJetEffiSignImpXYSigN3(cutImpForEffi);
  HfJetTagTCObj->DrawTaggedJetPurityN1(cutImpForPurity);
  HfJetTagTCObj->DrawTaggedJetPurityN2(cutImpForPurity);
  HfJetTagTCObj->DrawTaggedJetPurityN3(cutImpForPurity);

}

void PlotHfJetTCTaggingTask(TString rootdata="", TString rootsim="") {
  PlotHfJetTaggingTCQA(rootdata.Data(), rootsim.Data());
}

