#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include "../include/HfJetTaggingUnfolding.h"
#include <TString.h>

void plotUnfoldQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillMatched=false, bool fillTest = false, bool fillIPxy=true, bool fillIPz=false, bool fillIPxyz=false, bool fitForJP=false, bool fillEffiAndPurity=false, bool fillValidation=false, bool fillUnfolding=false) {

  HfJetTaggingAnalysis *unfoldObj = new HfJetTaggingAnalysis();
  unfoldObj->setFillData(doData);
  unfoldObj->setFillMCD(doMCD);
  unfoldObj->setFillMCP(doMCP);
  unfoldObj->setFillMatched(fillMatched);
  unfoldObj->setFillTest(fillTest);
  unfoldObj->setFillIPxy(fillIPxy);
  unfoldObj->setFillIPz(fillIPz);
  unfoldObj->setFillIPxyz(fillIPxyz);

  if (doData) {
    unfoldObj->initCommonHistData(rootdata.Data());
    unfoldObj->loadDataIPQA(rootdata.Data());
    unfoldObj->initHistogramForNormalizationIPQAData();
    unfoldObj->projectionHistIPQAData();
    unfoldObj->normalizedHistogramIPQAData();
    unfoldObj->drawDataJetPt(doLog);
    unfoldObj->drawDataJetEta(doLog);
    unfoldObj->drawDataJetPhi(doLog);
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      unfoldObj->drawDataTrackPt(doLog, binJetPt);
      unfoldObj->drawDataTrackEta(doLog, binJetPt);
      unfoldObj->drawDataTrackPhi(doLog, binJetPt);
      if (fillIPxy) {
        unfoldObj->drawDataImpXY(doLog, binJetPt);
        unfoldObj->drawDataSignImpXY(doLog, binJetPt);
        unfoldObj->drawDataImpXYSig(doLog, binJetPt);
        unfoldObj->drawDataSignImpXYSig(doLog, binJetPt, 0);
        unfoldObj->drawDataImpXY4x1(doLog, binJetPt);
        unfoldObj->drawDataImpXY2x2(doLog, binJetPt);
        if (fitForJP) {
          unfoldObj->fitDataJetSignImpXYSignificance(doLog);
        }
      }
      if (fillIPz) {
        unfoldObj->drawDataImpZ(doLog, binJetPt);
        unfoldObj->drawDataSignImpZ(doLog, binJetPt);
        unfoldObj->drawDataImpZSig(doLog, binJetPt);
        unfoldObj->drawDataSignImpZSig(doLog, binJetPt, 0);
        unfoldObj->drawDataImpZ4x1(doLog, binJetPt);
        unfoldObj->drawDataImpZ2x2(doLog, binJetPt);
      }
      if (fillIPxyz) {
        unfoldObj->drawDataImpXYZ(doLog, binJetPt);
        unfoldObj->drawDataSignImpXYZ(doLog, binJetPt);
        unfoldObj->drawDataImpXYZSig(doLog, binJetPt);
        unfoldObj->drawDataSignImpXYZSig(doLog, binJetPt, 0);
        unfoldObj->drawDataImpXYZ4x1(doLog, binJetPt);
        unfoldObj->drawDataImpXYZ2x2(doLog, binJetPt);
      }
      //      for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
      //        unfoldObj->drawDataSignImpXYSig(doLog, binJetPt, binTrackPt);
      //        unfoldObj->drawDataSignImpZSig(doLog, binJetPt, binTrackPt);
      //        unfoldObj->drawDataSignImpXYZSig(doLog, binJetPt, binTrackPt);
      //      }
    }
  }

  if (doMCD || doMCP) {
    unfoldObj->initCommonHistMC(rootsim.Data());
    unfoldObj->loadSimIPQA(rootsim.Data());
    unfoldObj->initHistogramForNormalizationIPQAMC();
    unfoldObj->projectionHistIPQAMC();
    unfoldObj->normalizedHistogramIPQAMC();
    if (doMCD) {
      unfoldObj->drawSimJetPt(withInc, doLog);
      unfoldObj->drawSimJetEta(withInc, doLog);
      unfoldObj->drawSimJetPhi(withInc, doLog);
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        unfoldObj->drawSimJetTrackPt(false, doLog, binJetPt);
        unfoldObj->drawSimJetTrackEta(withInc, doLog, binJetPt);
        unfoldObj->drawSimJetTrackPhi(withInc, doLog, binJetPt);
        if (fillIPxy) {
          unfoldObj->drawSimJetImpXY(false, doLog, binJetPt);
          unfoldObj->drawSimJetSignImpXY(false, doLog, binJetPt);
          unfoldObj->drawSimJetImpXYSignificance(false, doLog, binJetPt);
          unfoldObj->drawSimJetSignImpXYSignificance(false, doLog, binJetPt);
          unfoldObj->drawSimJetImpXY2x2(false, doLog, binJetPt);
        }
        if (fillIPz) {
          unfoldObj->drawSimJetImpZ(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetSignImpZ(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetImpZSignificance(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetSignImpZSignificance(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetImpZ2x2(withInc, doLog, binJetPt);
        }
        if (fillIPxyz) {
          unfoldObj->drawSimJetImpXYZ(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetSignImpXYZ(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetImpXYZSignificance(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetSignImpXYZSignificance(withInc, doLog, binJetPt);
          unfoldObj->drawSimJetImpXYZ2x2(withInc, doLog, binJetPt);
        }
      }
      for (int flavour =0; flavour < HfJetTagging::nFlavour+1; flavour++) {
        unfoldObj->drawSimFlavourJetTrackPt(doLog, flavour, HfJetTagging::startJetPt);
        unfoldObj->drawSimFlavourJetTrackEta(doLog, flavour, HfJetTagging::startJetPt);
        unfoldObj->drawSimFlavourJetTrackPhi(doLog, flavour, HfJetTagging::startJetPt);
        if (fillIPxy) {
          unfoldObj->drawSimFlavourTrackImpXY(doLog, flavour, HfJetTagging::startTrackPt);
          unfoldObj->drawSimFlavourTrackSignImpXY(doLog, flavour, HfJetTagging::startTrackPt);
          unfoldObj->drawSimFlavourTrackImpXYSig(doLog, flavour, HfJetTagging::startTrackPt);
          unfoldObj->drawSimFlavourTrackSignImpXYSig(doLog, flavour, HfJetTagging::startTrackPt);
        }
        if (fillMatched) {
          unfoldObj->drawJetEfficiency(doLog, flavour);
          unfoldObj->drawJetPurity(doLog, flavour);
          unfoldObj->drawSimRawJetPtMatched(doLog, flavour);
          unfoldObj->drawSimResMat(false, flavour);
        }
//        if (doUnfolding && fillMatched) {
//          unfoldObj->unfoldingJet(doLog, flavour);
//        }
        if (doMCP) {
          unfoldObj->drawSimFlavourJetpartJetPt(doLog, flavour);
          unfoldObj->drawSimFlavourRawJetpartJetPt(doLog, flavour);
        }
      }
      if (fitForJP && fillIPxy) {
        unfoldObj->fitIncJetSignImpXYSignificance(doLog);
        unfoldObj->fitCharmJetSignImpXYSignificance(doLog);
        unfoldObj->fitBeautyJetSignImpXYSignificance(doLog);
        unfoldObj->fitLfJetSignImpXYSignificance(doLog);
        unfoldObj->fitTaggedJetSignImpXYSignificance(withInc, doLog);
      }
    }
    if (doMCP) {
      unfoldObj->drawSimpartJetPt(withInc, doLog);
      unfoldObj->drawSimpartJetEta(withInc, doLog);
      unfoldObj->drawSimpartJetPhi(withInc, doLog);
      if (fillTest) {
        unfoldObj->drawSimpartFlavourMatchingEffi();
      }
    }
    if (fillTest) {
      unfoldObj->drawSimFlavourMatchingEffi();
      unfoldObj->drawSimMatchedFlavourMatchingEffi();
    }
    if (fillValidation) {

    }
  }

  if (doData && doMCD) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
      if (fillIPxy) {
        unfoldObj->drawDataVsSimJetImpXY(doLog, binJetPt);
        unfoldObj->drawDataVsSimJetSignImpXY(doLog, binJetPt);
        unfoldObj->drawDataVsSimJetImpXYSig(doLog, binJetPt);
        unfoldObj->drawDataVsSimJetSignImpXYSig(doLog, binJetPt, 0);
      }
//      if (doUnfolding && fillMatched) {
//        for (int flavour =0; flavour < HfJetTagging::nFlavour+1; flavour++) {
//          unfoldObj->unfoldingJetWithData(doLog, flavour);
//        }
//      }
    }
  }
}

void plotIP(
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
    bool doMatched=false,
    bool doTest=false,
    bool doIPxy=true,
    bool doIPz =false,
    bool doIPxyz=false,
    bool doFitForJP=false,
    bool doEffiAndPurity=false,
    bool doValidation=false,
    bool doUnfolding=false
    )
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  FIGURESET = figureName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  plotUnfoldQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doMatched, doTest, doIPxy, doIPz, doIPxyz, doFitForJP, doEffiAndPurity, doValidation, doUnfolding);
}
