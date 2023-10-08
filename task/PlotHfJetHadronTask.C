#include "../include/HfJetHadronAnalysis.h"
#include <TString.h>

void PlotHfJetHadronTask(TString rootsim="") {
  TString taskName = "hf-tagging-task"; // Temp
  HfJetHadronAnalysis *HfJetHadronObj = new HfJetHadronAnalysis(rootsim.Data(), taskName.Data(), true);

  // General Plot QA

}

