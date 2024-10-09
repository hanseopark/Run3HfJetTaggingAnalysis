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
    jpObj->loadDataJPQA(rootdata.Data());
    jpObj->initHistogramForNormalizationJPQAData();
    jpObj->projectionHistJPQAData();
    jpObj->normalizedHistogramJPQAData();
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      jpObj->drawDataJetJP(false, binJetPt);
      jpObj->drawDataJetJPN1(false, binJetPt, cutImp);
      jpObj->drawDataJetJPN2(false, binJetPt, cutImp);
      jpObj->drawDataJetJPN3(false, binJetPt, cutImp);
      jpObj->drawDataJetNegLogJP(doLog, binJetPt);
      jpObj->drawDataJetNegLogJPN1(doLog, binJetPt, cutImp);
      jpObj->drawDataJetNegLogJPN2(doLog, binJetPt, cutImp);
      jpObj->drawDataJetNegLogJPN3(doLog, binJetPt, cutImp);
    }
  }

  if (doMCD) {
    jpObj->loadSimJPQA(rootsim.Data());
    jpObj->initHistogramForNormalizationJPQAMC();
    jpObj->projectionHistJPQAMC();
    jpObj->normalizedHistogramJPQAMC();
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      jpObj->drawSimJetJP(false, false, binJetPt);
      jpObj->drawSimJetJPN1(withInc, false, binJetPt, cutImp);
      jpObj->drawSimJetJPN2(withInc, false, binJetPt, cutImp);
      jpObj->drawSimJetJPN3(withInc, false, binJetPt, cutImp);
      jpObj->drawSimJetNegLogJP(withInc, doLog, binJetPt);
      jpObj->drawSimJetNegLogJPN1(withInc, doLog, binJetPt, cutImp);
      jpObj->drawSimJetNegLogJPN2(withInc, doLog, binJetPt, cutImp);
      jpObj->drawSimJetNegLogJPN3(withInc, doLog, binJetPt, cutImp);
      jpObj->drawSimJetNegLogJPN4x1(false, doLog, binJetPt, cutImp);
    }
    if (fillEffi) {
      jpObj->drawSimJetRef();
      jpObj->drawSimJetEffiN1(cutImp);
      jpObj->drawSimJetEffiN2(cutImp);
      jpObj->drawSimJetEffiN3(cutImp);
      jpObj->drawSimJetEffiNx(cutImp);
      jpObj->drawSimJetPurityN1(cutImp);
      jpObj->drawSimJetPurityN2(cutImp);
      jpObj->drawSimJetPurityN3(cutImp);
      jpObj->drawSimJetPurityNx(cutImp);
    }
  }
  if ((doData && doTempFit) && doMCD) {
    jpObj->drawTemplateFit();
    jpObj->drawDataJetEffiN1(cutImp);
    jpObj->drawDataJetEffiN2(cutImp);
    jpObj->drawDataJetEffiN3(cutImp);
    jpObj->drawDataJetPurityN1(cutImp);
    jpObj->drawDataJetPurityN2(cutImp);
    jpObj->drawDataJetPurityN3(cutImp);
  }
}

void plotJP(
    TString rootdata="", 
    TString rootsim="", 
    TString sourceSet="",
    TString dataSet="",
    TString simSet="",
    TString triggerName="", 
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
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  plotJPQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doTrackProb, doTempFit, doEffi);
}
