#include <iostream>
#include <vector>
#include "../include/DataPoint.h"
#include "TFile.h"
#include "TString.h"
#include "../include/HfJetTaggingSysShowerAnalysis.h"
#include "../include/HfJetTaggingSysRadiusAnalysis.h"
#include "../include/HfJetTaggingSysTrackSelectionAnalysis.h"
#include "../include/HfJetTaggingSysTriggerAnalysis.h"
#include "../include/HfJetTaggingSysPassAnalysis.h"
#include "../include/HfJetTaggingSysTaggerAnalysis.h"
#include "../include/HfJetTaggingSysTrack2Coll.h"
#include "../include/HfJetTaggingSysTrackTuner.h"
#include "../include/HfJetTaggingSysMerge.h"

void plotSysShowerHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
  std::vector<TString> rootFiles;
  rootFiles.push_back(Form("%s/AnalysisResults_shower_1.root", pwd.Data())); // include shower
  rootFiles.push_back(Form("%s/AnalysisResults_shower_0.root", pwd.Data())); // without shower

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;
  
}

void plotSysRadiusHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
  std::vector<TString> rootFiles;

  // include root file to get systematic uncertainty and plots compared when it has different parameters
  rootFiles.push_back(Form("%s/AnalysisResults_radius_0_1.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_radius_0_2.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_radius_0_3.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_radius_0_4.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_radius_0_5.root", pwd.Data()));

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;

//  HfJetTagSysRadiusObj->drawIncJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawCharmJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawBeautyJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawLfJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawIncJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawCharmJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawBeautyJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->drawLfJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
  
}

void plotSysTrackSelectionHfJetTagging() {
  TString pwd=Form("%s/%s/sim/%s/sys/trksel", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());
  std::cout << "file pwd: " << pwd.Data() << std::endl;
  std::vector<TString> rootFiles;

  // include root file to get systematic uncertainty and plots compared when it has different parameters
  rootFiles.push_back(Form("%s/AnalysisResults_globalTracks.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_QualityTracks.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_uniformTracks.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_uniformTracksWoDca.root", pwd.Data()));
  //rootFiles.push_back(Form("%s/AnalysisResults_TrackTunerOn.root", pwd.Data()));
  //rootFiles.push_back(Form("%s/AnalysisResults_hybridTracksJE.root", pwd.Data()));

  bool doData = false;
  bool doMCD = true;
  bool dopartLevel = false;
  bool doLog = true;

  //HfJetTaggingSysTrackSelectionAnalysis *tsObj = new HfJetTaggingSysTrackSelectionAnalysis(rootFiles, doData, doMC, dopartLevel);

}

void plotSysTriggerHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
}

void plotSysPassHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";

  std::vector<TString> rootFiles;

  // include root file to get systematic uncertainty and plots compared when it has different parameters
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_IP.root", pwd.Data())); // apass4
  rootFiles.push_back(Form("%s/LHC23d1k/AnalysisResults_IP.root", pwd.Data())); // apass4
  rootFiles.push_back(Form("%s/LHC23k2d/AnalysisResults_IP.root", pwd.Data())); // apass4
  rootFiles.push_back(Form("%s/LHC24b1/AnalysisResults_IP.root", pwd.Data())); // apass6

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;

}

void plotSysTaggerHfJetTagging() {
  TString pwd=Form("%s/%s/sim/%s/sys/tagger", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());

  std::vector<TString> rootFiles;

  bool doData = false;
  bool doMCD = true;
  bool dopartLevel = false;
  bool doLog = false;

}

void plotSysQuarkHadronHfJetTagging() {
  TString pwd=Form("%s/%s/sim/%s/sys/quarkhadron", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());
  std::cout << "qh" << std::endl;
}

void plotSysTrackTunerHfJetTagging() {
  TString pwd=Form("%s/%s/sim/%s/sys/tracktuner", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());
  std::vector<std::pair<TString, TString>> ipFiles;
  ipFiles.push_back(std::make_pair(Form("%s/AnalysisResults_ip_wTuner.root", pwd.Data()), "with TrackTuner"));
  ipFiles.push_back(std::make_pair(Form("%s/AnalysisResults_ip_woTuner.root", pwd.Data()), "without TrackTuner"));
  std::cout << "track tuner" << std::endl;
  HfJetTaggingSysTrackTuner *ipObj = new HfJetTaggingSysTrackTuner();
  ipObj->setFillMCD(true);
  ipObj->setFillIPxy(true);
  ipObj->initAnalysis(ipFiles);
  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
    // ip
    ipObj->drawSimJetImpXY(true, true, binJetPt);
    ipObj->drawSimJetSignImpXY(true, true, binJetPt);
    ipObj->drawSimJetImpXYSignificance(true, true, binJetPt);
    ipObj->drawSimJetSignImpXYSignificance(true, true, binJetPt);
  }
  ipObj->savePara();

  std::vector<std::pair<TString, TString>> svFiles;
  svFiles.push_back(std::make_pair(Form("%s/AnalysisResults_sv_wTuner.root", pwd.Data()), "with TrackTuner"));
  svFiles.push_back(std::make_pair(Form("%s/AnalysisResults_sv_woTuner.root", pwd.Data()), "without TrackTuner"));

  int currentNC = ipObj->getNC();
  HfJetTaggingSysTrackTuner *svObj = new HfJetTaggingSysTrackTuner(currentNC);
  svObj->setFillMCD(true);
  svObj->setFillIPxy(false);
  svObj->setFillSV(true);
  svObj->initAnalysis(svFiles);

  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
    // sv
    svObj->drawSim3ProngRawLxy(true, true, binJetPt);
    svObj->drawSim3ProngRawsigmaLxy(true, true, binJetPt);
    svObj->drawSim3ProngRawSxy(true, true, binJetPt);
    svObj->drawSim3ProngRawSxyN1(true, true, binJetPt);
    svObj->drawSim3ProngRawMassN1(true, true, binJetPt);
    svObj->drawSim3ProngtaggedjetRawSxyN1(true, true, binJetPt);
    svObj->drawSim3ProngtaggedjetRawMassN1(true, true, binJetPt);
    svObj->drawSim3ProngLxy(true, true, binJetPt);
    svObj->drawSim3ProngsigmaLxy(true, true, binJetPt);
    svObj->drawSim3ProngSxy(true, true, binJetPt);
    svObj->drawSim3ProngSxyN1(true, true, binJetPt);
    svObj->drawSim3ProngMassN1(true, true, binJetPt);
    svObj->drawSim3ProngtaggedjetSxyN1(true, true, binJetPt);
    svObj->drawSim3ProngtaggedjetMassN1(true, true, binJetPt);
  }
  svObj->savePara();
}

void plotSysTrack2CollHfJetTagging() {
  // data
  TString pwdData=Form("%s/%s/data/%s/sys/track2coll", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());
  std::vector<std::pair<TString, TString>> rootDatas;
  rootDatas.push_back(std::make_pair(Form("%s/AnalysisResults_wTrack2Coll.root", pwdData.Data()), "with Track2Coll"));
  rootDatas.push_back(std::make_pair(Form("%s/AnalysisResults_woTrack2Coll.root", pwdData.Data()), "without Track2Coll"));
  HfJetTaggingSysTrack2Coll *t2lData = new HfJetTaggingSysTrack2Coll();
  t2lData->setFillData(true);
  t2lData->setFillIPxy(true);
  t2lData->setFillSV(true);
  t2lData->initAnalysis(rootDatas);
  std::cout << "t2l (Data)" << std::endl;
  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
  }

  // mc
  TString pwdSim=Form("%s/%s/sim/%s/sys/track2coll", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());
  std::vector<std::pair<TString, TString>> rootSims;
  rootSims.push_back(std::make_pair(Form("%s/AnalysisResults_wTrack2Coll.root", pwdSim.Data()), "with Track2Coll"));
  rootSims.push_back(std::make_pair(Form("%s/AnalysisResults_woTrack2Coll.root", pwdSim.Data()), "without Track2Coll"));
  HfJetTaggingSysTrack2Coll *t2lSim = new HfJetTaggingSysTrack2Coll();
  t2lSim->setFillMCD(true);
  t2lSim->setFillIPxy(false);
  t2lSim->setFillSV(true);
  t2lSim->initAnalysis(rootSims);
  std::cout << "t2l (MC)" << std::endl;
  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
    t2lSim->drawSim3ProngLxy(true, true, binJetPt);
    t2lSim->drawSim3ProngsigmaLxy(true, true, binJetPt);
    t2lSim->drawSim3ProngSxy(true, true, binJetPt);
    t2lSim->drawSim3ProngSxyN1(true, true, binJetPt);
    t2lSim->drawSim3ProngMassN1(true, true, binJetPt);
    t2lSim->drawSim3ProngtaggedjetSxyN1(true, true, binJetPt);
    t2lSim->drawSim3ProngtaggedjetMassN1(true, true, binJetPt);
  }
  t2lSim->savePara();


}



void plotSysSVTopoCut() { // TODO
  TString pwd=Form("%s/%s/sim/%s/sys/tagger", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());

  std::vector<TString> rootFiles;
  rootFiles.push_back(Form("%s/AnalysisResults_0_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_0_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_1_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_1_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_2_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_2_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_3_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_3_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_4_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_4_5.root", pwd.Data()));

//  for (int i = 0; i <= 4; ++i) {
//    for (int j = 0; j <= 5; j += 5) {
//      rootFiles.push_back(Form("%s/AnalysisResults_JP_%d_%d.root", pwd.Data(), i, j));
//    }
//  }

  bool doData = false;
  bool doMCD = true;
  bool dopartLevel = false;
  bool doLog = false;

}

void mergeSysSVTotal() {
  TString pwd=Form("%s/%s/sys", TAGSET.Data(), SOURCESET.Data());

  // for unfolding
  HfJetTaggingSysMerge* svunfold = new HfJetTaggingSysMerge();
  std::vector<std::pair<TString, TString>> unfoldFiles;
  unfoldFiles.push_back(std::make_pair(Form("%s/%s_%s_unfold.root", pwd.Data(), DATASET.Data(), SIMSET.Data()), "unfold"));

  svunfold->initAnalysis(unfoldFiles);
  svunfold->getSysUnfolding();
  svunfold->drawSysUnfolding();
  svunfold->savePara();
  int currentNC = svunfold->getNC();

  // for tagger point
  HfJetTaggingSysMerge* svtp = new HfJetTaggingSysMerge(currentNC);
  std::vector<std::pair<TString, TString>> tpFiles;
  tpFiles.push_back(std::make_pair(Form("%s/%s_%s_tp30.root", pwd.Data(), DATASET.Data(), SIMSET.Data()), "tagger point (30)"));
  tpFiles.push_back(std::make_pair(Form("%s/%s_%s_tp40.root", pwd.Data(), DATASET.Data(), SIMSET.Data()), "tagger point (40)"));
  tpFiles.push_back(std::make_pair(Form("%s/%s_%s_tp50.root", pwd.Data(), DATASET.Data(), SIMSET.Data()), "tagger point (50)"));

  svtp->initAnalysis(tpFiles);
  svtp->calSysTaggerPoint();
  svtp->drawSysTP();

  // for others

  // for total
  HfJetTaggingSysMerge* svTotal = new HfJetTaggingSysMerge();
  svTotal->setFillTP(true);
  svTotal->setFillUnfolding(true);
  svTotal->setFillSVCont(false); // todo
  svTotal->setSysUnfolding(svunfold->hsysSVUnfolding);
  svTotal->setSysTaggerPoint(svtp->hsysSVTP);
  svTotal->drawSysTotal();

}


void plotSys (
    TString sourceSet = "",
    TString dataSet = "",
    TString simSet = "",
    TString triggerName = "",
    TString figureName="", 
    TString suffix = "",
    TString doShower = "false", 
    TString doRadius = "false", 
    TString doTS = "false", 
    TString doTrigger = "false", 
    TString doPass = "false", 
    TString doTagger = "false",
    TString doQuarkHadronLevel = "false",
    TString doTrackTuner = "false",
    TString doTrack2Coll = "false",
    TString doMergeSV = "false"
    //TString doSVTopoCut = "false"
    ) {
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  FIGURESET = figureName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffix.Data();

  if (doShower.CompareTo("true")==0) plotSysShowerHfJetTagging();
  if (doRadius.CompareTo("true")==0) plotSysRadiusHfJetTagging();
  if (doTS.CompareTo("true")==0)     plotSysTrackSelectionHfJetTagging();
  if (doTrigger.CompareTo("true")==0)     plotSysTriggerHfJetTagging();
  if (doPass.CompareTo("true")==0)     plotSysPassHfJetTagging();
  if (doTagger.CompareTo("true")==0)     plotSysTaggerHfJetTagging();
  if (doQuarkHadronLevel.CompareTo("true")==0)     plotSysQuarkHadronHfJetTagging();
  if (doTrackTuner.CompareTo("true")==0)     plotSysTrackTunerHfJetTagging();
  if (doTrack2Coll.CompareTo("true")==0)     plotSysTrack2CollHfJetTagging();
  if (doMergeSV.CompareTo("true")==0)     mergeSysSVTotal();
  //if (doTagger.CompareTo("true")==0)     plotSysSVTopoCut();
}
