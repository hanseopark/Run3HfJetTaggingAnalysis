#include "../include/DataPoint.h"
#include "../include/HfJetTaggingJPAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingJPQA(TString rootdata, TString rootsim) {
  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool withInc = false;
  bool doLog = false;

  HfJetTaggingJPAnalysis *HfJetTagJPObj = new HfJetTaggingJPAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, dopartLevel);
  HfJetTagJPObj->DrawTaggedJetJP(withInc, doLog, 0);
  HfJetTagJPObj->DrawTaggedJetNegLogJP(withInc, doLog, 0);

}

void PlotHfJetJPTaggingTask(TString rootdata="", TString rootsim="") {
  PlotHfJetTaggingJPQA(rootdata.Data(), rootsim.Data());
}

