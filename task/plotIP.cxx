#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

void plotIPQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillRun2Def, bool fillIPxy=true, bool fillIPz=false, bool fillIPxyz=false, bool fitForJP=false, bool fillEffiAndPurity=false, bool doUnfolding=false) {

  HfJetTaggingAnalysis *ipObj = new HfJetTaggingAnalysis();
  ipObj->setFillData(doData);
  ipObj->setFillMCD(doMCD);
  ipObj->setFillMCP(doMCP);
  ipObj->setFillRun2Def(fillRun2Def);
  ipObj->setFillIPxy(fillIPxy);
  ipObj->setFillIPz(fillIPz);
  ipObj->setFillIPxyz(fillIPxyz);

  if (doData) {
    ipObj->loadDataIPQA(rootdata.Data());
    ipObj->initHistogramForNormalizationIPQAData();
    ipObj->projectionHistIPQAData();
    ipObj->normalizedHistogramIPQAData();
    ipObj->drawDataJetPt(doLog);
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
    ipObj->loadSimIPQA(rootsim.Data());
    ipObj->initHistogramForNormalizationIPQAMC();
    ipObj->projectionHistIPQAMC();
    ipObj->normalizedHistogramIPQAMC();
    if (doMCD) {
      ipObj->drawSimJetPt(withInc, doLog);
      if (fillRun2Def) {
        ipObj->drawSimJetEta(withInc, doLog);
        ipObj->drawSimJetPhi(withInc, doLog);
      }
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
        //for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
        //}
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
        if (doMCP) {
          ipObj->drawSimFlavourJetpartJetPt(doLog, flavour);
          ipObj->drawSimFlavourRawJetpartJetPt(doLog, flavour);
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
    }
    if (fillEffiAndPurity) {
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (fillIPxy) {
          ipObj->drawSimJetImpXYRun2Def(false, doLog, binJetPt);
          //ipObj->drawSimJetSignImpXYRun2Def(false, doLog, binJetPt);
          //ipObj->drawSimJetImpXYSignificanceRun2Def(false, doLog, binJetPt);
          //ipObj->drawSimJetSignImpXYSignificanceRun2Def(false, doLog, binJetPt);
          //ipObj->drawSimJetImpXY2x2Run2Def(false, doLog, binJetPt);
        }
      }
    }
    if (doUnfolding) {
      ipObj->unfoldingJet(0);
    }
  }

  if (doData && doMCD) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
      if (fillIPxy) {
        ipObj->drawDataVsMCTagJetImpXY(doLog, binJetPt);
        ipObj->drawDataVsMCTagJetSignImpXY(doLog, binJetPt);
        ipObj->drawDataVsMCTagJetImpXYSig(doLog, binJetPt);
        ipObj->drawDataVsMCTagJetSignImpXYSig(doLog, binJetPt, 0);
      }
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
    TString suffix="",
    bool withInc=false, 
    bool doLog=false,
    bool doData=false, 
    bool doMCD=false, 
    bool doMCP=false,
    bool doRun2Def=false,
    bool doIPxy=true,
    bool doIPz =false,
    bool doIPxyz=false,
    bool doFitForJP=false,
    bool doEffiAndPurity=false,
    bool doUnfolding=false
    )
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  plotIPQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doRun2Def, doIPxy, doIPz, doIPxyz, doFitForJP, doEffiAndPurity, doUnfolding);
}
