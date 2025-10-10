#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include "../include/HfJetTaggingJPAnalysis.h"
#include "../include/HfJetTaggingSVAnalysis.h"
#include <TString.h>

void plotSVQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillTest=false, bool do2Prong=false, bool do3Prong=false, bool fillN1=false, bool loadResMat=false, bool fillEffi=false, bool fillEffiWithIP=false, bool withPOWHEG=false, bool fillSys = false, bool loadExtSys = false) {

  HfJetTaggingSVAnalysis *svObj = new HfJetTaggingSVAnalysis();
  if (withPOWHEG) {
    svObj->initModel(Form("%s/%s.root", MODELSET.Data(), PWHG_CT18NLODIJET.Data()));
    //svObj->initModel(Form("%s/%s", MODELSET.Data(), PWHG_TEMP.Data()));
    //svObj->initModel(Form("%s/%s", MODELSET.Data(), "Pythia8JetSpectra_temp.root"));
    //svObj->initModel(Form("%s/%s", MODELSET.Data(), "Pythia8JetSpectra_hadron.root"));
    //svObj->initModel(Form("%s/%s", MODELSET.Data(), "Pythia8JetSpectra_hard_hadron.root"));
  }

  svObj->setFillData(doData);
  svObj->setFillMCD(doMCD);
  svObj->setFillMCP(doMCP);
  svObj->setFillTest(fillTest);
  svObj->setFill2Prong(do2Prong);
  svObj->setFill3Prong(do3Prong);
  svObj->setFillN1(fillN1);
  svObj->setFillEffi(fillEffi);
  svObj->setFillEffiWithIP(fillEffiWithIP);
  svObj->inputResultRun2();
  if (loadResMat) {
    //svObj->initExternalUnfold("resMat_LHC25a2b_hadron_dist.root");
    //svObj->initExternalUnfold(Form("resMat_%s_%s.root", SIMSET.Data(), SUFFIXSET.Data()));
    svObj->initExternalUnfold(Form("resMat_LHC25a2b_%s.root", SUFFIXSET.Data()));
  }

  if (doData) {
    svObj->initSVData(rootdata.Data());
    svObj->initCommonHistData(rootdata.Data());
    svObj->drawDataJetPt(doLog);
    svObj->drawDataJetEta(doLog);
    svObj->drawDataJetPhi(doLog);
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
        if (fillN1) {
          svObj->drawData3ProngSxyN1(doLog, binJetPt);
          svObj->drawData3ProngSxyzN1(doLog, binJetPt);
          svObj->drawData3ProngMassN1(doLog, binJetPt);
          svObj->drawDatataggedjet3ProngMassN1(doLog, binJetPt);
        }
      }
    }
  }
  if (doMCD) {
    svObj->initSVMC(rootsim.Data());
    svObj->initCommonHistMC(rootsim.Data());
    if (fillEffiWithIP) {
      svObj->initIPMC(rootsim.Data());
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
            svObj->drawSim2ProngPuritySxyN1(HfJetTagging::CUT::Sxy);
          }
        }
      }
    } // do2Prong
    if (do3Prong) {
    std::cout << __LINE__ << std::endl;
      svObj->drawSimJetPt(withInc, doLog);
      svObj->drawSimJetEta(withInc, doLog);
      svObj->drawSimJetPhi(withInc, doLog);
      for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        svObj->drawSim3ProngLxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngLxyz(withInc, doLog, binJetPt);
        svObj->drawSim3ProngSxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngSxyz(withInc, doLog, binJetPt);
        svObj->drawSim3ProngsigmaLxy(withInc, doLog, binJetPt);
        svObj->drawSim3ProngsigmaLxyz(withInc, doLog, binJetPt);
        if (fillN1) {
          svObj->drawSim3ProngSxyN1(false, doLog, binJetPt);
          svObj->drawSim3ProngSxyzN1(withInc, doLog, binJetPt);
          svObj->drawSim3ProngMassN1(false, doLog, binJetPt);
          svObj->drawSimtaggedjet3ProngMassN1(false, doLog, binJetPt);
//          svObj->drawSimtaggedjet3ProngSxyN1(false, doLog, binJetPt);
          if (fillEffi) {
            svObj->drawSim3ProngEffiSxyN1(HfJetTagging::CUT::Sxy);
            svObj->drawSim3ProngEffiSxyN1wSys();
            svObj->drawSim3ProngPuritySxyN1(HfJetTagging::CUT::Sxy);
            svObj->drawSim3ProngPuritySxyN1wSys();
//            //svObj->drawSim3ProngEffiAndPuritySxyN1(HfJetTagging::CUT::Sxy);
////            for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt; binJetPt++) {
////              svObj->drawSim3ProngEffiSxyN1Tagger(binJetPt);
////              svObj->drawSim3ProngPuritySxyN1Tagger(binJetPt);
////            }
          }
        }
      }
      if (fillEffi) {
        svObj->drawSimtaggedjet3ProngPurityMassN1(HfJetTagging::CUT::SxyByHY); // cut info sets by myself
        svObj->drawSimtaggedjet3ProngEffiMassN1(HfJetTagging::CUT::SxyByHY); // cut info sets by myself
      }
      // template fit
      svObj->drawTemplateFitMCN1();
      svObj->drawTemplateFitMCtaggedjetN1(HfJetTagging::CUT::SxyByHY);

      // for cross section
      svObj->setSim3ProngEffiTagged(HfJetTagging::CUT::Sxy);
      svObj->setSim3ProngPurityTagged(HfJetTagging::CUT::Sxy);
      svObj->closureTestSVMC(doLog);
      svObj->drawSimSV3ProngCrossSection(doLog);
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
    svObj->drawDataVsSimJetPt(doLog);
    for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      svObj->drawDataVsSim3ProngLxy(doLog, binJetPt);
      svObj->drawDataVsSim3ProngLxyz(doLog, binJetPt);
      svObj->drawDataVsSim3ProngsigmaLxy(doLog, binJetPt);
      svObj->drawDataVsSim3ProngsigmaLxyz(doLog, binJetPt);
      svObj->drawDataVsSim3ProngSxy(doLog, binJetPt);
      svObj->drawDataVsSim3ProngSxyz(doLog, binJetPt);
      if (fillN1) {
        svObj->drawDataVsSim3ProngSxyN1(doLog, binJetPt);
        svObj->drawDataVsSim3ProngSxyzN1(doLog, binJetPt);
        svObj->drawDataVsSim3ProngMassN1(doLog, binJetPt);
        svObj->drawDataVsSimtaggedjet3ProngMassN1(doLog, binJetPt);
      }
    }
    if (fillN1) {
      svObj->drawTemplateFitDataWithMCtaggedjetN1();
      svObj->drawTemplateFitDataWithMCtaggedjetN1Dep();
      //svObj->drawDataSV3ProngFlavourFraction();
      //svObj->drawDataVsSimSV3ProngFlavourFraction();
    }
    //svObj->closureTestSV(doLog);
    svObj->drawDataSV3ProngCrossSection(doLog, 4, 6);
    svObj->drawDataVsSimSV3ProngCrossSection(doLog);
    if (fillSys) svObj->drawDataSV3ProngSys(loadExtSys);
    svObj->drawDataSV3ProngCrossSectionWithSys(loadExtSys, fillSys);
    svObj->saveHistogramSVQA(Form("%s_%s_%s.root", DATASET.Data(), SIMSET.Data(), SUFFIXSET.Data()), fillSys);
    svObj->saveSVXSectionWithSys(Form("%s_%s_%s.root", DATASET.Data(), SIMSET.Data(), PWHG_CT18NLODIJET.Data()), fillSys);
  }
}

void plotSV (
    TString rootdata="",  // 1
    TString rootsim="",  // 2
    TString sourceSet="", // 3
    TString dataSet="", // 4
    TString simSet="", // 5
    TString triggerName="",  // 6
    TString figureName="",  // 7 
    TString suffix="", // 8
    bool withInc=false,  // 9
    bool doLog=false, // 10
    bool doData=false, 
    bool doMCD=false, 
    bool doMCP=false,
    bool doTest=false,
    bool do2Prong=false,
    bool do3Prong=false,
    bool doN1=false,
    bool loadResMat=false,
    bool doEffiAndPurity=false,
    bool doEffiAndPurityWithIP=false,
    bool withPOWHEG=false,
    bool fillSys=false,
    bool loadExtSys=false
    ) 
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  FIGURESET = figureName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  plotSVQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doTest, do2Prong, do3Prong, doN1, loadResMat, doEffiAndPurity, doEffiAndPurityWithIP, withPOWHEG, fillSys, loadExtSys);
}
