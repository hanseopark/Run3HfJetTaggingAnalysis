#include <TString.h>
#include "../include/DataPoint.h"
#include "../include/JetTrackEffiAnalysis.h"

void plotTrackEffiTask(TString rootData, TString rootSim, bool withInc, bool doLog, bool doData, bool doMCD, bool doMCP) {
  JetTrackEffiAnalysis *trkObj  = new JetTrackEffiAnalysis();
  trkObj->setFillData(doData);
  trkObj->setFillMC(doMCD);
  trkObj->loadSimGeneralTrackEffiQA(rootSim.Data());
  trkObj->initHistogramForNormalizationGeneralTrackEffiQAMC();
  trkObj->projectionHistGeneralTrackEffiQAMC();
  trkObj->drawTrackEffi();
}

void plotTrackEffi(
    TString rootdata = "",
    TString rootsim = "",
    TString sourceSet = "",
    TString dataSet = "",
    TString simSet = "",
    TString triggerName="", 
    bool withInc=false,
    bool doLog=false,
    bool doData=false,
    bool doMCD=false,
    bool doMCP=false
    ) 
{
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  plotTrackEffiTask(rootdata.Data(), rootsim.Data(), withInc, doLog, doData, doMCD, doMCP);
}
