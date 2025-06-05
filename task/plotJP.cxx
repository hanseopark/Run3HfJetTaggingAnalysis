#include "../include/DataPoint.h"
#include "../include/HfJetTaggingJPAnalysis.h"
#include <TString.h>

void plotJPQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool doTrackProb=false, bool doTempFit=false, bool fillEffi=false) {

  HfJetTaggingJPAnalysis *jpObj = new HfJetTaggingJPAnalysis();
  jpObj->setFillData(doData);
  jpObj->setFillMCD(doMCD);
  jpObj->setFillMCP(doMCP);
  //jpObj->setFillTP(doTrackProb);
  jpObj->setFillTF(doTempFit);
  jpObj->setFillEffi(fillEffi);
  float cutImp = 2.5;

  if (doData) {
    jpObj->initJPData(rootdata.Data());
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      jpObj->drawDataJP(false, binJetPt);
      jpObj->drawDatataggedjetJPN1(false, binJetPt, cutImp);
      jpObj->drawDatataggedjetJPN2(false, binJetPt, cutImp);
      jpObj->drawDatataggedjetJPN3(false, binJetPt, cutImp);
      jpObj->drawDataNegLogJP(doLog, binJetPt);
      jpObj->drawDatataggedjetNegLogJPN1(doLog, binJetPt, cutImp);
      jpObj->drawDatataggedjetNegLogJPN2(doLog, binJetPt, cutImp);
      jpObj->drawDatataggedjetNegLogJPN3(doLog, binJetPt, cutImp);
      jpObj->drawDataNegLogJPN4x1(doLog, binJetPt, cutImp);
    }
  }

  if (doMCD) {
    jpObj->initJPMC(rootsim.Data());
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      jpObj->drawSimJP(false, false, binJetPt);
      jpObj->drawSimtaggedjetJPN1(withInc, false, binJetPt, cutImp);
      jpObj->drawSimtaggedjetJPN2(withInc, false, binJetPt, cutImp);
      jpObj->drawSimtaggedjetJPN3(withInc, false, binJetPt, cutImp);
      jpObj->drawSimNegLogJP(withInc, doLog, binJetPt);
      jpObj->drawSimtaggedjetNegLogJPN1(withInc, doLog, binJetPt, cutImp);
      jpObj->drawSimtaggedjetNegLogJPN2(withInc, doLog, binJetPt, cutImp);
      jpObj->drawSimtaggedjetNegLogJPN3(withInc, doLog, binJetPt, cutImp);
      jpObj->drawSimNegLogJPN4x1(false, doLog, binJetPt, cutImp);
    }
    if (fillEffi) {
      jpObj->drawSimJPRef();
      jpObj->drawSimJPEffiN1(cutImp);
      jpObj->drawSimJPEffiN2(cutImp);
      jpObj->drawSimJPEffiN3(cutImp);
      jpObj->drawSimJPEffiNx(cutImp);
      jpObj->drawSimJPPurityN1(cutImp);
      jpObj->drawSimJPPurityN2(cutImp);
      jpObj->drawSimJPPurityN3(cutImp);
      jpObj->drawSimJPPurityNx(cutImp);
    }
  }
//  if ((doData && doTempFit) && doMCD) {
//    jpObj->drawTemplateFit();
//    jpObj->drawDataJetEffiN1(cutImp);
//    jpObj->drawDataJetEffiN2(cutImp);
//    jpObj->drawDataJetEffiN3(cutImp);
//    jpObj->drawDataJetPurityN1(cutImp);
//    jpObj->drawDataJetPurityN2(cutImp);
//    jpObj->drawDataJetPurityN3(cutImp);
//  }
}

void plotJP (
    TString rootdata="", 
    TString rootsim="", 
    TString sourceSet="",
    TString dataSet="",
    TString simSet="",
    TString triggerName="", 
    TString figureName="", 
    TString suffix="", 
    bool withInc=false, 
    bool doLog=false,
    bool doData=false, 
    bool doMCD=false, 
    bool doMCP=false,
    bool doTrackProb=false,
    bool doTempFit=false,
    bool doEffi=false
    )
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  FIGURESET = figureName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  plotJPQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doTrackProb, doTempFit, doEffi);
}
