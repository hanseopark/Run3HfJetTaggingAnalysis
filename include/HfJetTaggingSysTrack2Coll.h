#ifndef HFJETTAGGINGSYSTRACK2COLL_H
#define HFJETTAGGINGSYSTRACK2COLL_H

#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

/*
To change Template to "analysis"

*/

class HfJetTaggingSysTrack2Coll : public HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysTrack2Coll() : HfJetTaggingSysAnalysis() {
      initConfigTrack2Coll();
    }
    ~HfJetTaggingSysTrack2Coll();

    //// FUNCTION ////
    void initConfigTrack2Coll();

    // Set

    // Get

    // Draw
    void drawEffiN1(bool doLog, int binJetPt);
   
  protected:

  private:
};

HfJetTaggingSysTrack2Coll::~HfJetTaggingSysTrack2Coll() {
}

//int HfJetTaggingSysTrack2Coll::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysTrack2Coll::initConfigTrack2Coll() {
  //latex.SetNDC(); // Use normalized coordinates
  TString nameAnalysis = "track2coll";
  dirData = Form("%s/%s/data/%s/sys/%s", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), nameAnalysis.Data());
  dirSim = Form("%s/%s/sim/%s/sys/%s", dirFig.Data(), SOURCESET.Data(), SIMSET.Data(), nameAnalysis.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}




#endif // HFJETTAGGINGSYSTRACK2COLL_H
