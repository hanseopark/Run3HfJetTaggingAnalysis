#include "../include/DataPoint.h"
#include "../include/JetAnalysis.h"
#include <TString.h>

void PlotJetAnalysisGeneralQA(TString rootdata="", TString rootsim="") {
  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool withInc = false;
  bool doLog = true;

  JetAnalysis *jetObj = new JetAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, dopartLevel);
  for (int binJetR =0; binJetR < GeneralJet::nBinsJetR; binJetR++) {
    jetObj->DrawSimGenJetPt(doLog, binJetR);
    for (int binJetPt=0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
      jetObj->DrawSimGenJetEta(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetPhi(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetNTracks(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetArea(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetTrackPt(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetTrackEta(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetTrackPhi(doLog, binJetPt, binJetR);
      jetObj->DrawSimGenJetLeadingTrackPt(doLog, binJetPt, binJetR);
    }
  }
}

void PlotJetAnalysisTask(TString rootdata="", TString rootsim="") {
  PlotJetAnalysisGeneralQA(rootdata.Data(), rootsim.Data());

}
