#include "../include/DataPoint.h"
#include "../include/JetAnalysis.h"
#include "../include/JetRhoAreaSubAnalysis.h"
#include "../include/JetMatchedAnalysis.h"
#include <TString.h>

void plotJetGeneralQA(TString rootdata="", TString rootsim="", bool doData=true, bool doMCD=false, bool doMCP=false, TString triggerName="", bool withInc=true, bool doLog=true) {

  JetAnalysis *jetObj = new JetAnalysis(rootdata.Data(), rootsim.Data(), doData, doMCD, doMCP, triggerName.Data());
  if (doData) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR; binJetR++) {
      jetObj->drawDataGenJetPt(doLog, binJetR);
      for (int binJetPt=0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
        jetObj->drawDataGenJetEta(doLog, binJetPt, binJetR);
        jetObj->drawDataGenJetPhi(doLog, binJetPt, binJetR);
      }
    }
  }
  if (doMCD) {
    for (int binJetR =0; binJetR < GeneralJet::nBinsJetR; binJetR++) {
      jetObj->drawSimGenJetPt(doLog, binJetR);
      for (int binJetPt=0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
        jetObj->drawSimGenJetEta(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetPhi(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetNTracks(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetArea(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetTrackPt(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetTrackEta(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetTrackPhi(doLog, binJetPt, binJetR);
        jetObj->drawSimGenJetLeadingTrackPt(doLog, binJetPt, binJetR);
      }
    }
    if (doMCP) {
      for (int binJetR =0; binJetR < GeneralJet::nBinsJetR; binJetR++) {
        jetObj->drawSimGenPartJetPt(doLog, binJetR);
        for (int binJetPt=0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
        jetObj->drawSimGenPartJetEta(doLog, binJetPt, binJetR);
        jetObj->drawSimGenPartJetPhi(doLog, binJetPt, binJetR);
        jetObj->drawSimGenPartJetPhi(doLog, binJetPt, binJetR);
        jetObj->drawSimGenPartJetNTracks(doLog, binJetPt, binJetR);
        jetObj->drawSimGenPartJetTrackPt(doLog, binJetPt, binJetR);
        jetObj->drawSimGenPartJetTrackEta(doLog, binJetPt, binJetR);
        jetObj->drawSimGenPartJetTrackPhi(doLog, binJetPt, binJetR);
        }
      }
    }
  }
}

void plotJetRhoAreaSub(TString rootdata="", TString rootsim="", bool doData=true, bool doMC=false, bool doDataRhoAreaSub=false, bool doRho=false, TString triggerName="", bool withInc=true, bool doLog=true) {
  JetRhoAreaSubAnalysis *jetBkgObj = new JetRhoAreaSubAnalysis(rootdata.Data(), rootsim.Data(), doData, doMC, doDataRhoAreaSub, doRho, triggerName.Data());
  if (doData && (doDataRhoAreaSub || doRho)) {
    if (doRho) {
      jetBkgObj->drawDataGenJetRho(doLog, 0);
      jetBkgObj->drawDataGenJetRhoM(doLog, 0);
    } else {
      for (int binJetR =0; binJetR < GeneralJet::nBinsJetR; binJetR++) {
        jetBkgObj->drawDataGenRhoAreaSubJetPt(doLog, binJetR);
        jetBkgObj->drawDataGenJetPtComparedToRhoAreaSub(doLog, binJetR);
        for (int binJetPt=0; binJetPt < GeneralJet::nBinsJetPt; binJetPt++) {
          jetBkgObj->drawDataGenRhoAreaSubJetEta(doLog, binJetPt, binJetR);
          jetBkgObj->drawDataGenRhoAreaSubJetPhi(doLog, binJetPt, binJetR);
          jetBkgObj->drawDataGenRhoAreaSubJetNTracks(doLog, binJetPt, binJetR);
          jetBkgObj->drawDataGenRhoAreaSubJetArea(doLog, binJetPt, binJetR);
          jetBkgObj->drawDataGenRhoAreaSubJetTrackPt(doLog, binJetPt, binJetR);
          jetBkgObj->drawDataGenRhoAreaSubJetTrackEta(doLog, binJetPt, binJetR);
          jetBkgObj->drawDataGenRhoAreaSubJetTrackPhi(doLog, binJetPt, binJetR);
        }
      }
    }
  }

  if (doMC && doRho) {
    jetBkgObj->drawSimGenJetRho(doLog, 0);
    jetBkgObj->drawSimGenJetRhoM(doLog, 0);
  }
}

void plotJetMatched(TString rootsim="", TString triggerName="", bool withInc=true, bool doLog=true) {
  doLog=false;
  JetMatchedAnalysis *jetMatchedObj = new JetMatchedAnalysis(rootsim.Data(), triggerName.Data());
  jetMatchedObj->drawSimMatchedGeoPartJetPtJetPt(doLog, 0); // only binJetR=0;
  jetMatchedObj->drawSimMatchedGeoPartJetEtaJetEta(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedGeoPartJetPhiJetPhi(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedGeoPartJetNTracksJetNTracks(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedPtPartJetPtJetPt(doLog, 0); // only binJetR=0;
  jetMatchedObj->drawSimMatchedPtPartJetEtaJetEta(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedPtPartJetPhiJetPhi(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedPtPartJetNTracksJetNTracks(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedGeoPtPartJetPtJetPt(doLog, 0); // only binJetR=0;
  jetMatchedObj->drawSimMatchedGeoPtPartJetEtaJetEta(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedGeoPtPartJetPhiJetPhi(doLog, 0, 0); // only binJetPt, binJetR = 0;
  jetMatchedObj->drawSimMatchedGeoPtPartJetNTracksJetNTracks(doLog, 0, 0); // only binJetPt, binJetR = 0;

  jetMatchedObj->drawSimMatchedGeoDiffJetPt(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedGeoDiffJetEta(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedGeoDiffJetPhi(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedPtDiffJetPt(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedPtDiffJetEta(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedPtDiffJetPhi(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedGeoPtDiffJetPt(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedGeoPtDiffJetEta(doLog, 0, 0);
  jetMatchedObj->drawSimMatchedGeoPtDiffJetPhi(doLog, 0, 0);

}

void plotJetEvtWiseConstSub(TString rootdata="", TString rootsim="", bool doDataEvtWiseConstSub=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetSubMatched(TString rootdata="", TString rootsim="", bool doDataSubMatched=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetWeighted(TString rootdata="", TString rootsim="", bool doMCDWeighted=false, bool doMCPWeighted=false, bool doMCPMCDMatchedWeighted=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetTrigger(TString rootdata="", TString rootsim="", bool doDataTrigger=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetTracks(TString rootdata="", TString rootsim="", bool doTracks=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetTracksWeighted(TString rootdata="", TString rootsim="", bool doTracks=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetTracksSub(TString rootdata="", TString rootsim="", bool doTracksSub=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJetRandomCone(TString rootdata="", TString rootsim="", bool doRandomCone=false, TString triggerName="", bool withInc=true, bool doLog=true) {
}

void plotJet (
    TString rootdata = "",
    TString rootsim = "",
    bool doData = false,
    bool doDataRhoAreaSub = false,
    bool doDataEvtWiseConstSub = false,
    bool doDataSubMatched = false,
    bool doMCD = false,
    bool doMCDWeighted = false,
    bool doMCP = false,
    bool doMCPWeighted = false,
    bool doMCPMCDMatched = false,
    bool doMCPMCDMatchedWeighted = false,
    bool doDataTrigger = false,
    bool doTracks = false,
    bool doTracksWeighted = false,
    bool doTracksSub = false,
    bool doRho = false,
    bool doRandomCone = false,
    TString triggerName = "",
    bool withInc = false,
    bool doLog = false
    ) 
{
  //plotJetGeneralQA(rootdata.Data(), rootsim.Data(), doData, doMCD, doMCP, triggerName.Data(), withInc, doLog);

  if (doDataRhoAreaSub || doRho) {
    std::cout<<__LINE__<<std::endl;
    plotJetRhoAreaSub(rootdata.Data(), rootsim.Data(), doData, doMCD, doDataRhoAreaSub, doRho, triggerName.Data(), withInc, doLog);
  }
  if (doMCD && doMCP && doMCPMCDMatched) {
    plotJetMatched(rootsim.Data(), triggerName.Data(), withInc, doLog);
  }

  // Add additional conditions for other functions as needed
}

