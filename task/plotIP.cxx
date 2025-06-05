#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

void plotIPQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillMatched=false, bool fillTest = false, bool fillIPxy=true, bool fillIPz=false, bool fillIPxyz=false, bool fitForJP=false, bool fillEffiAndPurity=false, bool fillValidation=false, bool fillUnfolding=false) {

  HfJetTaggingAnalysis *ipObj = new HfJetTaggingAnalysis();
  ipObj->setFillData(doData);
  ipObj->setFillMCD(doMCD);
  ipObj->setFillMCP(doMCP);
  ipObj->setFillMatched(fillMatched);
  ipObj->setFillTest(fillTest);
  ipObj->setFillIPxy(fillIPxy);
  ipObj->setFillIPz(fillIPz);
  ipObj->setFillIPxyz(fillIPxyz);

  if (doData) {
    ipObj->initCommonHistData(rootdata.Data());
    ipObj->initIPData(rootdata.Data());
    ipObj->drawDataJetPt(doLog);
    ipObj->drawDataJetEta(doLog);
    ipObj->drawDataJetPhi(doLog);
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      ipObj->drawDataTrackPt(doLog, binJetPt);
      ipObj->drawDataTrackEta(doLog, binJetPt);
      ipObj->drawDataTrackPhi(doLog, binJetPt);
      if (fillIPxy) {
        ipObj->drawDataImpXY(doLog, binJetPt);
        ipObj->drawDataSignImpXY(doLog, binJetPt);
        ipObj->drawDataImpXYSig(doLog, binJetPt);
        ipObj->drawDataSignImpXYSig(doLog, binJetPt, 0);
        ipObj->drawDataImpXY4x1(doLog, binJetPt);
        ipObj->drawDataImpXY2x2(doLog, binJetPt);
        if (fitForJP) {
          ipObj->fitDataJetSignImpXYSignificance(doLog);
        }
      }
      if (fillIPz) {
        ipObj->drawDataImpZ(doLog, binJetPt);
        ipObj->drawDataSignImpZ(doLog, binJetPt);
        ipObj->drawDataImpZSig(doLog, binJetPt);
        ipObj->drawDataSignImpZSig(doLog, binJetPt, 0);
        ipObj->drawDataImpZ4x1(doLog, binJetPt);
        ipObj->drawDataImpZ2x2(doLog, binJetPt);
      }
      if (fillIPxyz) {
        ipObj->drawDataImpXYZ(doLog, binJetPt);
        ipObj->drawDataSignImpXYZ(doLog, binJetPt);
        ipObj->drawDataImpXYZSig(doLog, binJetPt);
        ipObj->drawDataSignImpXYZSig(doLog, binJetPt, 0);
        ipObj->drawDataImpXYZ4x1(doLog, binJetPt);
        ipObj->drawDataImpXYZ2x2(doLog, binJetPt);
      }
      //      for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
      //        ipObj->drawDataSignImpXYSig(doLog, binJetPt, binTrackPt);
      //        ipObj->drawDataSignImpZSig(doLog, binJetPt, binTrackPt);
      //        ipObj->drawDataSignImpXYZSig(doLog, binJetPt, binTrackPt);
      //      }
    }
  }

  if (doMCD || doMCP) {
    ipObj->initCommonHistMC(rootsim.Data());
    ipObj->initIPMC(rootsim.Data());
    if (doMCD) {
      ipObj->drawSimJetPt(withInc, doLog);
      ipObj->drawSimJetEta(withInc, doLog);
      ipObj->drawSimJetPhi(withInc, doLog);
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        ipObj->drawSimJetTrackPt(false, doLog, binJetPt);
        ipObj->drawSimJetTrackEta(withInc, doLog, binJetPt);
        ipObj->drawSimJetTrackPhi(withInc, doLog, binJetPt);
        if (fillIPxy) {
          ipObj->drawSimJetImpXY(false, doLog, binJetPt);
          ipObj->drawSimJetSignImpXY(false, doLog, binJetPt);
          ipObj->drawSimJetImpXYSignificance(false, doLog, binJetPt);
          ipObj->drawSimJetSignImpXYSignificance(false, doLog, binJetPt);
          ipObj->drawSimJetImpXY2x2(false, doLog, binJetPt);
        }
        if (fillIPz) {
          ipObj->drawSimJetImpZ(withInc, doLog, binJetPt);
          ipObj->drawSimJetSignImpZ(withInc, doLog, binJetPt);
          ipObj->drawSimJetImpZSignificance(withInc, doLog, binJetPt);
          ipObj->drawSimJetSignImpZSignificance(withInc, doLog, binJetPt);
          ipObj->drawSimJetImpZ2x2(withInc, doLog, binJetPt);
        }
        if (fillIPxyz) {
          ipObj->drawSimJetImpXYZ(withInc, doLog, binJetPt);
          ipObj->drawSimJetSignImpXYZ(withInc, doLog, binJetPt);
          ipObj->drawSimJetImpXYZSignificance(withInc, doLog, binJetPt);
          ipObj->drawSimJetSignImpXYZSignificance(withInc, doLog, binJetPt);
          ipObj->drawSimJetImpXYZ2x2(withInc, doLog, binJetPt);
        }
      }
      for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt<HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
        ipObj->drawSimTrackImpXY(withInc, doLog, binTrackPt);
        ipObj->drawSimTrackSignImpXY(withInc, doLog, binTrackPt);
        ipObj->drawSimTrackImpXYSig(withInc, doLog, binTrackPt);
        ipObj->drawSimTrackSignImpXYSig(withInc, doLog, binTrackPt);
      }
      for (int flavour =0; flavour < HfJetTagging::nFlavour+1; flavour++) {
        ipObj->drawSimFlavourJetTrackPt(doLog, flavour, HfJetTagging::startJetPt);
        ipObj->drawSimFlavourJetTrackEta(doLog, flavour, HfJetTagging::startJetPt);
        ipObj->drawSimFlavourJetTrackPhi(doLog, flavour, HfJetTagging::startJetPt);
        if (fillIPxy) {
          ipObj->drawSimFlavourTrackImpXY(doLog, flavour, HfJetTagging::startTrackPt);
          ipObj->drawSimFlavourTrackSignImpXY(doLog, flavour, HfJetTagging::startTrackPt);
          ipObj->drawSimFlavourTrackImpXYSig(doLog, flavour, HfJetTagging::startTrackPt);
          ipObj->drawSimFlavourTrackSignImpXYSig(doLog, flavour, HfJetTagging::startTrackPt);
        }
        if (fillMatched) {
          ipObj->drawJetEfficiency(doLog, flavour);
          ipObj->drawJetPurity(doLog, flavour);
          ipObj->drawSimRawJetPtMatched(doLog, flavour);
          ipObj->drawSimResMat(flavour);
          if (fillUnfolding) {
            ipObj->unfoldingJet(doLog, flavour);
            ipObj->initExternalUnfold("ExternalResMat.root");
            ipObj->unfoldingJet(doLog, flavour, 4, 16, true);
          }
        }
      }
      if (fitForJP && fillIPxy) {
        ipObj->fitIncJetSignImpXYSignificance(doLog);
        ipObj->fitCharmJetSignImpXYSignificance(doLog);
        ipObj->fitBeautyJetSignImpXYSignificance(doLog);
        ipObj->fitLfJetSignImpXYSignificance(doLog);
        ipObj->fitTaggedJetSignImpXYSignificance(withInc, doLog);
      }
    }
    if (doMCP) {
      ipObj->drawSimpartJetPt(withInc, doLog);
      ipObj->drawSimpartJetEta(withInc, doLog);
      ipObj->drawSimpartJetPhi(withInc, doLog);
      if (fillTest) {
        ipObj->drawSimpartFlavourMatchingEffi();
      }
    }
    if (doMCD && doMCP) {
      for (int flavour =0; flavour < HfJetTagging::nFlavour+1; flavour++) {
        ipObj->drawSimFlavourJetpartJetPt(doLog, flavour);
      }
    }
    if (fillTest) {
      ipObj->drawSimFlavourMatchingEffi();
      ipObj->drawSimMatchedFlavourMatchingEffi();
    }
    if (fillValidation) {

    }
  }

  if (doData && doMCD) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
      if (fillIPxy) {
        ipObj->drawDataVsSimJetImpXY(doLog, binJetPt);
        ipObj->drawDataVsSimJetSignImpXY(doLog, binJetPt);
        ipObj->drawDataVsSimJetImpXYSig(doLog, binJetPt);
        ipObj->drawDataVsSimJetSignImpXYSig(doLog, binJetPt, 0);
      }
      if (fillUnfolding && fillMatched) {
        for (int flavour =0; flavour < HfJetTagging::nFlavour+1; flavour++) {
          ipObj->unfoldingJetWithData(doLog, flavour);
        }
      }
    }
  }
  ipObj->saveHistogramIPQA("IPQA.root", doData, doMCD, doMCP);
  //ipObj->saveHistogramUnfold("ExternalResMat.root", doData, doMCD, doMCP);
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
  plotIPQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doMatched, doTest, doIPxy, doIPz, doIPxyz, doFitForJP, doEffiAndPurity, doValidation, doUnfolding);
}
