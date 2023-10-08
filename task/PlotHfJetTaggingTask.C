#include "../include/HfJetTaggingAnalysis.h"
#include <TString.h>

void PlotHfJetTaggingTask(TString rootsim="") {
  TString taskName = "hf-tagging-task";
  HfJetTaggingAnalysis *HfJetTagObj = new HfJetTaggingAnalysis(rootsim.Data(), taskName.Data(), true);

  // General Plot QA
  HfJetTagObj->DrawTaggedJetTrackPt();
  HfJetTagObj->DrawTaggedJetTrackEta();
  HfJetTagObj->DrawTaggedJetTrackPhi();
}

