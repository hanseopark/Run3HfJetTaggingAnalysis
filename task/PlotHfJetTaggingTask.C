#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

//void PlotHfJetTaggingTask(TString rootsim="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/ChargedBMeson/Dev/HFJetsWork/MC/DetectorLevel/AnalysisResults.root") {
void PlotHfJetTaggingTask(TString rootsim="") {
  //TString rootsim = Form("/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/ChargedBMeson/Dev/HFJetsWork/MC/DetectorLevel/AnalysisResults.root");
  TString taskName = "hf-tagging-task";
  HfJetTaggingAnalysis *HfJetTagObj = new HfJetTaggingAnalysis(rootsim.Data(), taskName.Data(), true);
  //HfJetTagObj->InitHistogram(rootsim.Data(), taskName.Data());
  // General Plot QA
  HfJetTagObj->DrawJetTrackPt();
  HfJetTagObj->DrawJetTrackEta();
  HfJetTagObj->DrawJetTrackPhi();
}

