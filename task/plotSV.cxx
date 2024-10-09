#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include "../include/HfJetTaggingJPAnalysis.h"
#include "../include/HfJetTaggingSVAnalysis.h"
#include <TString.h>

void plotSVQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillRun2Def=false, bool fillTest=false, bool do2Prong=false, bool do3Prong=false, bool fillN1=false, bool fillEffi=false) {

  HfJetTaggingSVAnalysis *svObj = new HfJetTaggingSVAnalysis();
  svObj->setFillData(doData);
  svObj->setFillMCD(doMCD);
  svObj->setFillMCP(doMCP);
  svObj->setFillRun2Def(fillRun2Def);
  svObj->setFillTest(fillTest);
  svObj->setFill2Prong(do2Prong);
  svObj->setFill3Prong(do3Prong);
  svObj->setFillN1(fillN1);
  svObj->setFillEffi(fillEffi);

  if (doData) {
    svObj->loadDataSVQA(rootdata.Data());
    svObj->initHistogramForNormalizationSVQAData();
    svObj->projectionHistSVQAData();
    svObj->normalizedHistogramSVQAData();
    if (do2Prong) {
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        svObj->drawData2ProngLxy(doLog, binJetPt);
        svObj->drawData2ProngLxyz(doLog, binJetPt);
        svObj->drawData2ProngsigmaLxy(doLog, binJetPt);
        svObj->drawData2ProngsigmaLxyz(doLog, binJetPt);
        svObj->drawData2ProngSxy(doLog, binJetPt);
        svObj->drawData2ProngSxyz(doLog, binJetPt);
      }
    }
    if (do3Prong) {
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        svObj->drawData3ProngLxy(doLog, binJetPt);
        svObj->drawData3ProngLxyz(doLog, binJetPt);
        svObj->drawData3ProngsigmaLxy(doLog, binJetPt);
        svObj->drawData3ProngsigmaLxyz(doLog, binJetPt);
        svObj->drawData3ProngSxy(doLog, binJetPt);
        svObj->drawData3ProngSxyz(doLog, binJetPt);
      }
    }
  }
  if (doMCD) {
    svObj->loadSimSVQA(rootsim.Data());
    svObj->initHistogramForNormalizationSVQAMC();
    svObj->projectionHistSVQAMC();
    svObj->normalizedHistogramSVQAMC();
    if (fillEffi) {
      svObj->loadSimIPQA(rootsim.Data());
      svObj->initHistogramForNormalizationIPQAMC();
      svObj->projectionHistIPQAMC();
      svObj->normalizedHistogramIPQAMC();
    }
    //svObj->drawSimJetPt(withInc, doLog);
    if (do2Prong) {
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        svObj->drawSim2ProngLxy(withInc, doLog, binJetPt);
        svObj->drawSim2ProngLxyz(withInc, doLog, binJetPt);
        svObj->drawSim2ProngSxy(withInc, doLog, binJetPt);
        svObj->drawSim2ProngSxyz(withInc, doLog, binJetPt);
        svObj->drawSim2ProngsigmaLxy(withInc, doLog, binJetPt);
        svObj->drawSim2ProngsigmaLxyz(withInc, doLog, binJetPt);
        if (fillN1) {
          svObj->drawSim2ProngSxyN1(withInc, doLog, binJetPt);
          svObj->drawSim2ProngSxyzN1(withInc, doLog, binJetPt);
          svObj->drawSim2ProngMassN1(false, doLog, binJetPt);
          if (fillEffi) {
            svObj->drawSim2ProngEffiSxyN1(HfJetTagging::CUT::Sxy);
            svObj->drawSim2ProngEffiSxyzN1(HfJetTagging::CUT::Sxyz);
            svObj->drawSim2ProngPuritySxyN1(HfJetTagging::CUT::Sxy);
            svObj->drawSim2ProngPuritySxyzN1(HfJetTagging::CUT::Sxyz);
          }
        }
        if (fillEffi) {
          //svObj->drawSim2ProngEffiSxy(HfJetTagging::CUT::Sxy);
          //svObj->drawSim2ProngEffiSxyz(HfJetTagging::CUT::Sxyz);
          //svObj->drawSim2ProngPuritySxy(HfJetTagging::CUT::Sxy);
          //svObj->drawSim2ProngPuritySxyz(HfJetTagging::CUT::Sxyz);
        }
        if (fillTest) {
          svObj->drawSim2ProngChi2(withInc, doLog, binJetPt);
        }
      }
    } // do2Prong
    if (do3Prong) {
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        svObj->drawSim3ProngLxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngLxyz(withInc, doLog, binJetPt);
        svObj->drawSim3ProngSxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngSxyz(withInc, doLog, binJetPt);
        svObj->drawSim3ProngsigmaLxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngsigmaLxyz(withInc, doLog, binJetPt);
        svObj->drawSim3ProngRawSxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngRawSxyz(withInc, doLog, binJetPt);
        if (fillN1) {
          svObj->drawSim3ProngSxyN1(false, doLog, binJetPt);
          svObj->drawSim3ProngSxyzN1(withInc, doLog, binJetPt);
          svObj->drawSim3ProngMassN1(false, doLog, binJetPt);
          svObj->drawSim3ProngRawMassN1(false, doLog, binJetPt);
          svObj->drawSim3ProngRawSxyN1(withInc, doLog, binJetPt);
          svObj->drawSim3ProngRawSxyzN1(withInc, doLog, binJetPt);
          svObj->drawSimtaggedjet3ProngEffiSxyN1(HfJetTagging::CUT::Sxy);
          svObj->drawSimtaggedjet3ProngPuritySxyN1(HfJetTagging::CUT::Sxy);
          svObj->drawTemplateFitMCN1();
          svObj->drawTemplateFitMCtaggedjetN1();
          if (fillRun2Def) {
            svObj->drawSimtaggedjet3ProngEffiSxyN1Run2Def(HfJetTagging::CUT::Sxy);
            svObj->drawSimtaggedjet3ProngPuritySxyN1Run2Def(HfJetTagging::CUT::Sxy);
            svObj->drawTemplateFitMCN1Run2Def();
            svObj->drawTemplateFitMCtaggedjetN1Run2Def();
          }
          if (fillEffi) {
            svObj->drawSim3ProngEffiSxyN1(HfJetTagging::CUT::Sxy);
            svObj->drawSim3ProngPuritySxyN1(HfJetTagging::CUT::Sxy);
            svObj->drawSim3ProngEffiAndPuritySxyN1(HfJetTagging::CUT::Sxy);
            for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt; binJetPt++) {
              svObj->drawSim3ProngEffiSxyN1Tagger(binJetPt);
              svObj->drawSim3ProngPuritySxyN1Tagger(binJetPt);
            }
          }
          if (fillRun2Def) {
            svObj->drawSim3ProngSxyN1Run2Def(false, doLog, binJetPt);
            svObj->drawSim3ProngSxyzN1Run2Def(withInc, doLog, binJetPt);
            svObj->drawSim3ProngMassN1Run2Def(false, doLog, binJetPt);
            svObj->drawSim3ProngRawMassN1Run2Def(false, doLog, binJetPt);
            if (fillEffi) {
              //svObj->loadSimIPQA(rootsim.Data());
              //svObj->initHistogramForNormalizationIPQAMC();
              //svObj->projectionHistIPQAMC();
              //svObj->normalizedHistogramIPQAMC();
              svObj->drawSim3ProngEffiSxyN1Run2Def(HfJetTagging::CUT::Sxy);
              svObj->drawSim3ProngPuritySxyN1Run2Def(HfJetTagging::CUT::Sxy);
            }
          }
        }
        if (fillEffi) {
          //svObj->drawSim3ProngEffiSxy(HfJetTagging::CUT::Sxy);
          //svObj->drawSim3ProngEffiSxyz(HfJetTagging::CUT::Sxyz);
          //svObj->drawSim3ProngPuritySxy(HfJetTagging::CUT::Sxy);
          //svObj->drawSim3ProngPuritySxyz(HfJetTagging::CUT::Sxyz);
        }
        if (fillTest) {
          svObj->drawSim3ProngChi2(withInc, doLog, binJetPt);
        }
      }
    } // do3Prong
  } // doMCD
  if ((doData && doMCD) && do2Prong) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      svObj->drawDataVsSim2ProngLxy(doLog, binJetPt);
      svObj->drawDataVsSim2ProngLxyz(doLog, binJetPt);
      svObj->drawDataVsSim2ProngsigmaLxy(doLog, binJetPt);
      svObj->drawDataVsSim2ProngsigmaLxyz(doLog, binJetPt);
      svObj->drawDataVsSim2ProngSxy(doLog, binJetPt);
      svObj->drawDataVsSim2ProngSxyz(doLog, binJetPt);
    }
  }
  if ((doData && doMCD) && do3Prong) {
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      svObj->drawDataVsSim3ProngLxy(doLog, binJetPt);
      svObj->drawDataVsSim3ProngLxyz(doLog, binJetPt);
      svObj->drawDataVsSim3ProngsigmaLxy(doLog, binJetPt);
      svObj->drawDataVsSim3ProngsigmaLxyz(doLog, binJetPt);
      svObj->drawDataVsSim3ProngSxy(doLog, binJetPt);
      svObj->drawDataVsSim3ProngSxyz(doLog, binJetPt);
    }
  }

}

void plotSV (
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
    bool doTest=false,
    bool do2Prong=false,
    bool do3Prong=false,
    bool doN1=false,
    bool doEffiAndPurity=false
    ) 
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  plotSVQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doRun2Def, doTest, do2Prong, do3Prong, doN1, doEffiAndPurity);
}
