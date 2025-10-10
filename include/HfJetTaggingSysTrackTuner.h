#ifndef HFJETTAGGINGSYSTRACKTUNER_H
#define HFJETTAGGINGSYSTRACKTUNER_H

#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

/*
To change Template to "analysis"

*/

class HfJetTaggingSysTrackTuner : public HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysTrackTuner() : HfJetTaggingSysAnalysis() {
      initConfigTrackTuner();
    }
    HfJetTaggingSysTrackTuner(int nccc) : HfJetTaggingSysAnalysis(nccc) {
      initConfigTrackTuner();
    }
    ~HfJetTaggingSysTrackTuner();

    //// FUNCTION ////
    void initConfigTrackTuner();

    // Set

    // Get

    // Draw
    void drawEffiN1(bool doLog, int binJetPt);
   
  protected:

  private:
};

HfJetTaggingSysTrackTuner::~HfJetTaggingSysTrackTuner() {
}

//int HfJetTaggingSysTrackTuner::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysTrackTuner::initConfigTrackTuner() {
  //latex.SetNDC(); // Use normalized coordinates
  TString nameAnalysis = "tracktuner";
  dirData = Form("%s/%s/data/%s/sys/%s", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), nameAnalysis.Data());
  dirSim = Form("%s/%s/sim/%s/sys/%s", dirFig.Data(), SOURCESET.Data(), SIMSET.Data(), nameAnalysis.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}




#endif // HFJETTAGGINGSYSTRACKTUNER_H
