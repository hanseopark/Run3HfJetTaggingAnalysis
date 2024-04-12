#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include "../include/HfJetTaggingJPAnalysis.h"
#include "../include/HfJetTaggingSVAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingGeneralQA(TString rootdata="", TString rootsim="", bool doData=true, bool doMC=false, bool fitForJP=false, TString triggerName="", bool doMCP=false, bool withInc=true, bool doLog=true) {

  // General Plot QA
  /// Each parameter distribution when compared jet flavour if you want to be able to add inclusive
  HfJetTaggingAnalysis *HfJetTagObj = new HfJetTaggingAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, triggerName.Data(), doMCP);
  if (doData) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      HfJetTagObj->drawDataJetPt(doLog);
      HfJetTagObj->drawDataTrackPt(doLog, binJetPt);
      HfJetTagObj->drawDataTrackEta(doLog, binJetPt);
      HfJetTagObj->drawDataTrackPhi(doLog, binJetPt);
      HfJetTagObj->drawDataImpXY(doLog, binJetPt);
      HfJetTagObj->drawDataSignImpXY(doLog, binJetPt);
      HfJetTagObj->drawDataImpXYSig(doLog, binJetPt);
      HfJetTagObj->drawDataImpZ(doLog, binJetPt);
      HfJetTagObj->drawDataSignImpZ(doLog, binJetPt);
      HfJetTagObj->drawDataImpZSig(doLog, binJetPt);
      HfJetTagObj->drawDataImpXYZ(doLog, binJetPt);
      HfJetTagObj->drawDataSignImpXYZ(doLog, binJetPt);
      HfJetTagObj->drawDataImpXYZSig(doLog, binJetPt);
      HfJetTagObj->drawDataSignImpXYSig(doLog, binJetPt, 0);
      HfJetTagObj->drawDataSignImpZSig(doLog, binJetPt, 0);
      HfJetTagObj->drawDataSignImpXYZSig(doLog, binJetPt, 0);
      HfJetTagObj->drawDataImpXY4x1(doLog, binJetPt);
      HfJetTagObj->drawDataImpXY2x2(doLog, binJetPt);
      HfJetTagObj->drawDataImpZ4x1(doLog, binJetPt);
      HfJetTagObj->drawDataImpZ2x2(doLog, binJetPt);
      HfJetTagObj->drawDataImpXYZ4x1(doLog, binJetPt);
      HfJetTagObj->drawDataImpXYZ2x2(doLog, binJetPt);
//      for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
//        HfJetTagObj->drawDataSignImpXYSig(doLog, binJetPt, binTrackPt);
//        HfJetTagObj->drawDataSignImpZSig(doLog, binJetPt, binTrackPt);
//        HfJetTagObj->drawDataSignImpXYZSig(doLog, binJetPt, binTrackPt);
//      }
    }
  }

  if (doMC) {
    HfJetTagObj->drawSimJetPt(withInc, doLog);
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      HfJetTagObj->drawSimJetTrackPt(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetTrackEta(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetTrackPhi(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpXY(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetSignImpXY(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpXYSignificance(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetSignImpXYSignificance(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpXY2x2(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpZ(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetSignImpZ(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpZSignificance(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetSignImpZSignificance(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpZ2x2(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpXYZ(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetSignImpXYZ(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpXYZSignificance(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetSignImpXYZSignificance(withInc, doLog, binJetPt);
      HfJetTagObj->drawSimJetImpXYZ2x2(withInc, doLog, binJetPt);
      //for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
      //}
    }
    for (int flavour =1; flavour < HfJetTagging::nFlavour+1; flavour++) {
      HfJetTagObj->drawSimFlavourJetTrackPt(doLog, flavour, HfJetTagging::startJetPt);
      HfJetTagObj->drawSimFlavourJetTrackEta(doLog, flavour, HfJetTagging::startJetPt);
      HfJetTagObj->drawSimFlavourJetTrackPhi(doLog, flavour, HfJetTagging::startJetPt);
    }
    if (fitForJP) {
      HfJetTagObj->fitDataJetSignImpXYSignificance(doLog);
      HfJetTagObj->fitincJetSignImpXYSignificance(doLog);
      HfJetTagObj->fitcJetSignImpXYSignificance(doLog);
      HfJetTagObj->fitbJetSignImpXYSignificance(doLog);
      HfJetTagObj->fitlfJetSignImpXYSignificance(doLog);
      HfJetTagObj->fitTaggedJetSignImpXYSignificance(withInc, doLog);
    }
  }

  if (doData && doMC) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
      //for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
        //HfJetTagObj->DrawDataVsMCTagJetSignImpXYSig(doLog, binJetPt, binTrackPt);
        HfJetTagObj->drawDataVsMCTagJetImpXY(doLog, binJetPt);
        HfJetTagObj->drawDataVsMCTagJetSignImpXY(doLog, binJetPt);
        HfJetTagObj->drawDataVsMCTagJetImpXYSig(doLog, binJetPt);
        HfJetTagObj->drawDataVsMCTagJetSignImpXYSig(doLog, binJetPt, 0);
      //}
    }
  }

//  if (doTemplateFit) { // Template Fit
//  //HfJetTaggingTemplateFit& HfJetTagFitObj = dynamic_cast<HfJetTaggingAnalysis&>(*HfJetTagTCObj);
//  //HfJetTaggingTemplateFIt *HfJetTagFitObj = new HfJetTaggingTemplateFit(rootsim.Data(), taskTC.Data(), true);
//  }
}

void PlotHfJetTaggingTCQA(TString rootdata="", TString rootsim="", bool doData=true, bool doMC=false, TString triggerName="", bool dopartLevel=false, bool withInc=true, bool doLog=true) {

  HfJetTaggingTCAnalysis *HfJetTagTCObj = new HfJetTaggingTCAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, triggerName.Data(), dopartLevel);
  for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    HfJetTagTCObj->drawSimJetSignImpXYSignificanceN1(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpXYSignificanceN2(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpXYSignificanceN3(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpXYSignificanceN3x1(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpZSignificanceN1(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpZSignificanceN2(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpZSignificanceN3(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpXYZSignificanceN1(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpXYZSignificanceN2(withInc, doLog, binJetPt);
    HfJetTagTCObj->drawSimJetSignImpXYZSignificanceN3(withInc, doLog, binJetPt);
    //for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    //}
  }
  double cutImpForEffi = 2.5;
  double cutImpForPurity = 2.5;
  HfJetTagTCObj->drawSimJetEffiSignImpXYSigN1(cutImpForEffi);
  HfJetTagTCObj->drawSimJetEffiSignImpXYSigN2(cutImpForEffi);
  HfJetTagTCObj->drawSimJetEffiSignImpXYSigN3(cutImpForEffi);
  HfJetTagTCObj->drawSimJetEffiSignImpXYSigN3x1(cutImpForEffi);
  HfJetTagTCObj->drawSimJetPurityN1(cutImpForPurity);
  HfJetTagTCObj->drawSimJetPurityN2(cutImpForPurity);
  HfJetTagTCObj->drawSimJetPurityN3(cutImpForPurity);
  HfJetTagTCObj->drawSimJetPurityN3x1(cutImpForPurity);
}

void PlotHfJetTaggingJPQA(TString rootdata="", TString rootsim="", bool doData=false, bool doMC=false, TString triggerName="", bool doMCP=false, bool withInc=true, bool doLog=true) {

  float cutImp = 1.0;
  HfJetTaggingJPAnalysis *HfJetTagJPObj = new HfJetTaggingJPAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, triggerName.Data(), doMCP);
  for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    HfJetTagJPObj->drawDataJetJP(false, binJetPt);
    HfJetTagJPObj->drawDataJetNegLogJP(doLog, binJetPt);
    HfJetTagJPObj->drawDataJetJPN1(false, binJetPt, cutImp);
    HfJetTagJPObj->drawDataJetNegLogJPN1(doLog, binJetPt, cutImp);
    HfJetTagJPObj->drawDataJetJPN2(false, binJetPt, cutImp);
    HfJetTagJPObj->drawDataJetNegLogJPN2(doLog, binJetPt, cutImp);
    HfJetTagJPObj->drawDataJetJPN3(false, binJetPt, cutImp);
    HfJetTagJPObj->drawDataJetNegLogJPN3(doLog, binJetPt, cutImp);

    HfJetTagJPObj->drawSimJetJP(withInc, false, binJetPt);
    HfJetTagJPObj->drawSimJetNegLogJP(withInc, doLog, binJetPt);
    HfJetTagJPObj->drawSimJetJPN1(withInc, false, binJetPt, cutImp);
    HfJetTagJPObj->drawSimJetNegLogJPN1(withInc, doLog, binJetPt, cutImp);
    HfJetTagJPObj->drawSimJetJPN2(withInc, false, binJetPt, cutImp);
    HfJetTagJPObj->drawSimJetNegLogJPN2(withInc, doLog, binJetPt, cutImp);
    HfJetTagJPObj->drawSimJetJPN3(withInc, false, binJetPt, cutImp);
    HfJetTagJPObj->drawSimJetNegLogJPN3(withInc, doLog, binJetPt, cutImp);
    HfJetTagJPObj->drawSimJetRef();
    HfJetTagJPObj->drawSimJetEffiN1(cutImp);
    HfJetTagJPObj->drawSimJetEffiN2(cutImp);
    HfJetTagJPObj->drawSimJetPurityN1(cutImp);
    //for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
    //}
  }
}

void PlotHfJetTaggingSVQA(TString rootdata="", TString rootsim="", bool doData=true, bool doMC=false, TString triggerName="", bool doMCP=false, bool withInc=true, bool doLog=true) {

  HfJetTaggingSVAnalysis *HfJetTagSVObj = new HfJetTaggingSVAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, triggerName.Data(), doMCP);
  for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    HfJetTagSVObj->DrawTaggedJet2ProngLxy(withInc, doLog, binJetPt);
    HfJetTagSVObj->DrawTaggedJet2ProngLxyz(withInc, doLog, binJetPt);
    HfJetTagSVObj->DrawTaggedJet2ProngSxy(withInc, doLog, binJetPt);
    HfJetTagSVObj->DrawTaggedJet2ProngSxyz(withInc, doLog, binJetPt);
  }

}




void PlotHfJetTaggingTask(
    TString rootdata="", 
    TString rootsim="", 
    bool doIPData=false, 
    bool doIPMCD=false, 
    bool fitForJP = false,
    bool doTC =false, 
    bool doTemplateFit =false,
    bool doJPData=true,
    bool doJPMCD=false,
    bool doSV2ProngMCD=false,
    bool doSV3ProngMCD=false,
    TString triggerName="", 
    bool doMCP=false, 
    bool withInc=false, 
    bool doLog=false,
    TString dataSet="",
    TString simSet="") 
{
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  if (doIPData || doIPMCD) {
    PlotHfJetTaggingGeneralQA(rootdata.Data(), rootsim.Data(), doIPData, doIPMCD, fitForJP, triggerName.Data(), doMCP, withInc, doLog);
  }
  if (doTC) {
    PlotHfJetTaggingTCQA(rootdata.Data(), rootsim.Data(), doIPData, doIPMCD, triggerName.Data(), doMCP, withInc, doLog);
  }
  if (doJPData || doJPMCD) {
    PlotHfJetTaggingJPQA(rootdata.Data(), rootsim.Data(), doJPData, doJPMCD, triggerName.Data(), doMCP, withInc, doLog);
  }
  if (doSV2ProngMCD) {
    PlotHfJetTaggingSVQA(rootdata.Data(), rootsim.Data(), false, doSV2ProngMCD, triggerName.Data(), doMCP, withInc, doLog);
  }
  if (doSV3ProngMCD) {

  }
}




























