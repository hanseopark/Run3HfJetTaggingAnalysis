#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include <TString.h>

void plotTCQA(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillIPxy=true, bool fillIPz=false, bool fillIPxyz=false, bool fillEffi=false) {

  HfJetTaggingTCAnalysis *tcObj = new HfJetTaggingTCAnalysis();
  //tcObj->setFillData(doData);
  tcObj->setFillMCD(doMCD);
  tcObj->setFillMCP(false);
  tcObj->setFillIPxy(fillIPxy);
  tcObj->setFillIPz(fillIPz);
  tcObj->setFillIPxyz(fillIPxyz);
  tcObj->setFillEffi(fillEffi);
  if (fillEffi) {
    tcObj->initCommonHistMC(rootsim.Data());
    tcObj->initIPMC(rootsim.Data());
  }

  if (!doMCD) {
    std::cout<<" it has to incluede MC sample" << std::endl;
    return;
  }
  tcObj->initTCMC(rootsim.Data());

  for (int binJetPt=HfJetTagging::startJetPt; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (fillIPxy) {
      tcObj->drawSimJetSignImpXYSignificanceN1(false, doLog, binJetPt);
      tcObj->drawSimJetSignImpXYSignificanceN2(withInc, doLog, binJetPt);
      tcObj->drawSimJetSignImpXYSignificanceN3(withInc, doLog, binJetPt);
      tcObj->drawSimJetSignImpXYSignificanceN3x1(false, doLog, binJetPt);
      //tcObj->drawSimJetSignImpXYSignificanceN4x1(false, doLog, binJetPt);
    }
    if (fillIPz) {
      tcObj->drawSimJetSignImpZSignificanceN1(withInc, doLog, binJetPt);
      tcObj->drawSimJetSignImpZSignificanceN2(withInc, doLog, binJetPt);
      tcObj->drawSimJetSignImpZSignificanceN3(withInc, doLog, binJetPt);
    }
    if (fillIPxyz) {
      tcObj->drawSimJetSignImpXYZSignificanceN1(withInc, doLog, binJetPt);
      tcObj->drawSimJetSignImpXYZSignificanceN2(withInc, doLog, binJetPt);
      tcObj->drawSimJetSignImpXYZSignificanceN3(withInc, doLog, binJetPt);
    }
    //for (int binTrackPt=HfJetTagging::startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    //}
  }
  if (fillEffi) {
    double cutImpForEffi = 2.5;
    double cutImpForPurity = 2.5;
    if (fillIPxy) {
      tcObj->drawSimJetEffiSignImpXYSigN1(cutImpForEffi);
      tcObj->drawSimJetEffiSignImpXYSigN2(cutImpForEffi);
      tcObj->drawSimJetEffiSignImpXYSigN3(cutImpForEffi);
      tcObj->drawSimJetEffiSignImpXYSigNx(cutImpForEffi);
      tcObj->drawSimJetEffiSignImpXYSigN3x1(cutImpForEffi);
      tcObj->drawSimJetPurityN1(cutImpForPurity);
      tcObj->drawSimJetPurityN2(cutImpForPurity);
      tcObj->drawSimJetPurityN3(cutImpForPurity);
      tcObj->drawSimJetPurityNx(cutImpForPurity);
      tcObj->drawSimJetPurityN3x1(cutImpForPurity);
      for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt; binJetPt++) {
        tcObj->drawSimJetEffiSignImpXYSigNxTagger(binJetPt);
        tcObj->drawSimJetPurityNxTagger(binJetPt);
        tcObj->drawSimJetEffiAndPurityNxTagger(binJetPt);
      }
    }
  }
}

void plotTC(
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
    bool doIPxy=true,
    bool doIPz =false,
    bool doIPxyz=false,
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
  plotTCQA(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doIPxy, doIPz, doIPxyz, doEffi);
}
