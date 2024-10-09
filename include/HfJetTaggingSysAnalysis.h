#ifndef HFJETTAGGINGSYSANALYSIS_H
#define HFJETTAGGINGSYSANALYSIS_H

#include <TH1F.h>
#include <TString.h>
#include "CanvasHandler.h"
#include "DataPoint.h"
#include "HfJetTaggingUtilities.h"

class HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysAnalysis();

    void initConfig();
    
    // Set
    void setFillData(bool fillData);
    void setFillMCD(bool fillMCD);
    void setFillMCP(bool fillMCP);

    // Get
    const int* getErrorShower() const {
      return errorShower;
    }
    const int* getErrorRadius() const {
      return errorRadius;
    }
    const int* getErrorTS() const {
      return errorTS;
    }

    // fucntion

  protected:
    CanvasHandler* canHan;
    int nc=0;
    bool fillData = false;
    bool fillMCD = false;
    bool fillMCP = false;
    TString dirFig = false;
    int errorShower[HfJetTagging::nBinsJetPt];
    int errorRadius[HfJetTagging::nBinsJetPt];
    int errorTS[HfJetTagging::nBinsJetPt];
    /// ... ///
    

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;

};

HfJetTaggingSysAnalysis::~HfJetTaggingSysAnalysis() {
}

void HfJetTaggingSysAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);

  dirFig = "fig";
  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  } 
  dirData = Form("%s/%s/data/%s/sys", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/sys", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  //dirDataVsSim = Form("fig/%s/dataVSsim/%s_%s/sys", SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE);
  gSystem->mkdir(dirSim, kTRUE);
  //gSystem->mkdir(dirDataVsSim, kTRUE);
}

// Set function
void HfJetTaggingSysAnalysis::setFillData(bool mfillData) {
  fillData = mfillData;
  if (fillData) {
    std::cout << "Fill Data ON " << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillMCD(bool mfillMCD) {
  fillMCD = mfillMCD;
  if (fillMCD) {
    std::cout << "Fill MCD ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillMCP(bool mfillMCP) {
  fillMCP = mfillMCP;
  if (fillMCP) {
    std::cout << "Fill MCP ON" << std::endl;
  }
}


#endif // HFJETTAGGINGSYSANALYSIS_H
