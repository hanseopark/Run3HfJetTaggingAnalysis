#include "../include/HfJetTaggingTemplateFit.h"
#include <TString.h>

void TemplateFitHfJetTaggingTask(TString rootsim="") {
  TString taskName = "hf-tagging-task";
  HfJetTaggingTemplateFit *HfJetTagFitObj = new HfJetTaggingTemplateFit(rootsim.Data(), taskName.Data(), true);
  HfJetTagFitObj->Fit();

  // Call the function through the base class pointer
  //HfJetTaggingAnalysis* basePtr = &*HfJetTagFitObj;
  //basePtr->DrawTaggedJetProbabilityLog();

  // Template Fit
}

