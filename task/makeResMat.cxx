#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

void makeResMatTask(TString rootdata="", TString rootsim="", bool withInc=false, bool doLog=true, bool doData=true, bool doMCD=false, bool doMCP=true, bool fillMatched=false, bool fillTest = false) {
  HfJetTaggingAnalysis *rmObj = new HfJetTaggingAnalysis();
  rmObj->setFillMCD(doMCD);
  rmObj->setFillMatched(fillMatched);
  if (doMCD || doMCP) {
    rmObj->initCommonHistMC(rootsim.Data());
    rmObj->initIPMC(rootsim.Data());
    for (int flavour =0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      rmObj->drawSimResMat(flavour);
    }
  }
  rmObj->saveHistogramUnfold(Form("resMat_%s_%s.root", SIMSET.Data(), SUFFIXSET.Data()), doData, doMCD, doMCP);
}

void makeResMat (
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
    bool doTest=false
    )
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  FIGURESET = figureName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();
  makeResMatTask(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP, doMatched, doTest);
}
