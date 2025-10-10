#ifndef HFJETTAGGINGSYSSVCONT_H
#define HFJETTAGGINGSYSSVCONT_H

#include <TH1F.h>
#include <TString.h>
#include "HfJetTaggingSysAnalysis.h"

class HfJetTaggingSysSVContAnalysis : public HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysSVContAnalysis() : HfJetTaggingSysAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSysSVContAnalysis();

    //// FUNCTION ////
    void initConfig();
    void loadDataSVCont(TString rootData);
    void initHistSVContData();
    void projectionHistSVContData();
    void rebinHistSVContData();
    void initSVContData(TString rootData);

    void loadSimSVCont(TString rootSim);
    void initHistSVContSim();
    void projectionHistSVContSim();
    void rebinHistSVContSim();
    void initSVContSim(TString rootSim);

    // Set
    void setFillSVCont(bool fillSVCont);

    TH2F* h2datatrackPtImpXY;
    THnF* hnsimJetPtTrackPtImpXYPriFlavour;
    THnF* hnsimJetPtTrackPtImpXYSecFlavour;
    TH3F* h3simjetPtFracSecPtPerJetFlavour;

    TH1F* hdatajetImpXYSVCont[HfJetTagging::nBinsTrackPt+1];
  protected:
    bool fillSVCont = false;

  //priavte:
};

HfJetTaggingSysSVContAnalysis::~HfJetTaggingSysSVContAnalysis() {
  std::cout << " " << std::endl;
}

void HfJetTaggingSysSVContAnalysis::loadDataSVCont(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, sys SV contamination QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";
  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  if (fillData && fillSVCont) {
    h2datatrackPtImpXY = reinterpret_cast<TH2F*> (fin->Get(Form("%s/h2_track_pt_impact_parameter_xy", taskName.Data())));
  }
  std::cout << "Load completed sys of SV contamination" << std::endl;
}

void HfJetTaggingSysSVContAnalysis::initHistSVContData() {
  if (fillData && fillSVCont) {
    for (int trackPt = 0; trackPt < HfJetTagging::nBinsTrackPt+1; trackPt++) {
      hdatajetImpXYSVCont[trackPt] = new TH1F(Form("hdatajetImpXYSVCont_%d", trackPt), "", h2datatrackPtImpXY->GetNBinsY(), h2datatrackPtImpXY->GetYaxis()->GetBinLowEdge(1), h2datatrackPtImpXY->GetYaxis()->GetBinUpEdge(h2datatrackPtImpXy->GetNbinsY()));
    }
  }
}

void HfJetTaggingSysSVContAnalysis::projectionHistSVContData() {
}

void HfJetTaggingSysSVContAnalysis::rebinHistSVContData() {
}

void HfJetTaggingSysSVContAnalysis::initSVContData(TString rootData) {
}

void HfJetTaggingSysSVContAnalysis::loadSimSVCont(TString rootSim) {
}

void HfJetTaggingSysSVContAnalysis::initHistSVContSim() {
}

void HfJetTaggingSysSVContAnalysis::projectionHistSVContSim() {
}

void HfJetTaggingSysSVContAnalysis::rebinHistSVContSim() {
}

void HfJetTaggingSysSVContAnalysis::initSVContSim(TString rootSim) {
}

#endif // HFJETTAGGINGSYSSVCONTANALYSIS_H
