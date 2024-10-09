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

void plotSysShowerHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
  std::vector<TString> rootFiles;
  rootFiles.push_back(Form("%s/AnalysisResults_shower_1.root", pwd.Data())); // include shower
  rootFiles.push_back(Form("%s/AnalysisResults_shower_0.root", pwd.Data())); // without shower

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;
  
  HfJetTaggingSysShowerAnalysis *HfJetTagSysShowerObj = new HfJetTaggingSysShowerAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysShowerObj->drawIncJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawCharmJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawBeautyJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawLfJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawIncJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawCharmJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawBeautyJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->drawLfJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);

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

  HfJetTaggingSysRadiusAnalysis *HfJetTagSysRadiusObj = new HfJetTaggingSysRadiusAnalysis(rootFiles, doData, doMC, dopartLevel);
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
  HfJetTaggingSysTrackSelectionAnalysis *tsObj = new HfJetTaggingSysTrackSelectionAnalysis();
  tsObj->setFillData(doData);
  tsObj->setFillMCD(doMCD);
  tsObj->setFillMCP(dopartLevel);
  tsObj->setFillIPxy(true);
  tsObj->setFillTrackEffi(true);
  tsObj->loadSimTS(rootFiles);
  tsObj->initHistogramTS();
  tsObj->projectionHistTS();
  tsObj->normalizedHistogramTS();
  tsObj->drawIncJetTrackPtTrackSelection(doLog, HfJetTagging::numTrackSelection);
  tsObj->drawIncJetTrackEtaTrackSelection(doLog, HfJetTagging::numTrackSelection);
  tsObj->drawIncJetTrackPhiTrackSelection(doLog, HfJetTagging::numTrackSelection);

  tsObj->drawIncJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);
  tsObj->drawCharmJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);
  tsObj->drawBeautyJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);
  tsObj->drawLfJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);

  tsObj->drawTrackEffi(HfJetTagging::numTrackSelection);

}

void plotSysTriggerHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
  std::vector<TString> rootFiles;

  // include root file to get systematic uncertainty and plots compared when it has different parameters
  rootFiles.push_back(Form("%s/AnalysisResults_globalTracks.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_bbbarJet.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_ccbarJet.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_bbbar.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_ccbar.root", pwd.Data()));

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;

  HfJetTaggingSysTriggerAnalysis *HfJetTagSysTriggerObj = new HfJetTaggingSysTriggerAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysTriggerObj->drawIncJetTrackPtTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJetTrackEtaTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJetTrackPhiTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJet2ProngLxyTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJet2ProngLxyzTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJet2ProngsigmaLxyTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJet2ProngsigmaLxyzTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJet2ProngSxyTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawIncJet2ProngSxyzTrigger(doLog, HfJetTagging::numTrigger);

  HfJetTagSysTriggerObj->drawIncJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawCharmJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawBeautyJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawLfJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawTagJetEntriesTrigger(HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawTagJetTrackEntriesTrigger(HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawTagJetNormEntriesTrigger(HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->drawTagJetNormTrackEntriesTrigger(HfJetTagging::numTrigger);

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

  HfJetTaggingSysPassAnalysis *HfJetTagSysPassObj = new HfJetTaggingSysPassAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysPassObj->drawIncJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
  HfJetTagSysPassObj->drawCharmJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
  HfJetTagSysPassObj->drawBeautyJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
  HfJetTagSysPassObj->drawLfJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
}

void plotSysTaggerHfJetTagging() {
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
  rootFiles.push_back(Form("%s/AnalysisResults_5_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_5_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_6_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_6_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_7_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_7_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_8_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_8_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_9_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_9_5.root", pwd.Data()));

//  for (int i = 0; i <= 4; ++i) {
//    for (int j = 0; j <= 5; j += 5) {
//      rootFiles.push_back(Form("%s/AnalysisResults_JP_%d_%d.root", pwd.Data(), i, j));
//    }
//  }

  bool doData = false;
  bool doMCD = true;
  bool dopartLevel = false;
  bool doLog = false;

  HfJetTaggingSysTaggerAnalysis *taggerObj = new HfJetTaggingSysTaggerAnalysis();
  taggerObj->setFillData(doData);
  taggerObj->setFillMCD(doMCD);
  taggerObj->setFillMCP(dopartLevel);
  taggerObj->loadSimTagger(rootFiles);
  taggerObj->initHistogramTagger();
  taggerObj->projectionHistTagger();
  taggerObj->normalizedHistogramTagger();

  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
    taggerObj->drawEffiN1(doLog, binJetPt);
    taggerObj->drawEffiN2(doLog, binJetPt);
    taggerObj->drawEffiN3(doLog, binJetPt);
    taggerObj->drawEffiNx(doLog, binJetPt);
    taggerObj->drawPurityN1(doLog, binJetPt);
    taggerObj->drawPurityN2(doLog, binJetPt);
    taggerObj->drawPurityN3(doLog, binJetPt);
    taggerObj->drawPurityNx(doLog, binJetPt);
    //taggerObj->drawGraphEffiAndPurity(doLog, binJetPt);
  }
}

void plotSysQuarkHadronHfJetTagging() {
  TString pwd=Form("%s/%s/sim/%s/sys/quarkhadron", TAGSET.Data(), SOURCESET.Data(), SIMSET.Data());
  std::cout << "qh" << std::endl;
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

  HfJetTaggingSysTaggerAnalysis *taggerObj = new HfJetTaggingSysTaggerAnalysis();
  taggerObj->setFillData(doData);
  taggerObj->setFillMCD(doMCD);
  taggerObj->setFillMCP(dopartLevel);
  taggerObj->loadSimTagger(rootFiles);
  taggerObj->initHistogramTagger();
  taggerObj->projectionHistTagger();
  taggerObj->normalizedHistogramTagger();

  taggerObj->drawEffiN1(doLog, 5);
  taggerObj->drawEffiN2(doLog, 5);
  taggerObj->drawEffiN3(doLog, 5);
  taggerObj->drawEffiNx(doLog, 5);
  taggerObj->drawPurityN1(doLog, 5);
  taggerObj->drawPurityN2(doLog, 5);
  taggerObj->drawPurityN3(doLog, 5);
  taggerObj->drawPurityNx(doLog, 5);
  taggerObj->drawEffiAndPurityNx(doLog, 3);
  taggerObj->drawGraphEffiAndPurity(doLog, 0);
}


void plotSys(
                         TString sourceSet = "",
                         TString dataSet = "",
                         TString simSet = "",
                         TString triggerName = "",
                         TString suffixSet = "",
                         TString doShower = "false", 
                         TString doRadius = "false", 
                         TString doTS = "false", 
                         TString doTrigger = "false", 
                         TString doPass = "false", 
                         TString doTagger = "false",
                         TString doQuarkHadronLevel = "false"
                         //TString doSVTopoCut = "false"
                         ) {
  globalStyle();
  TRIGGERNAME = triggerName.Data();
  SOURCESET = sourceSet.Data();
  DATASET = dataSet.Data();
  SIMSET = simSet.Data();
  SUFFIXSET = suffixSet.Data();

  if (doShower.CompareTo("true")==0) plotSysShowerHfJetTagging();
  if (doRadius.CompareTo("true")==0) plotSysRadiusHfJetTagging();
  if (doTS.CompareTo("true")==0)     plotSysTrackSelectionHfJetTagging();
  if (doTrigger.CompareTo("true")==0)     plotSysTriggerHfJetTagging();
  if (doPass.CompareTo("true")==0)     plotSysPassHfJetTagging();
  if (doTagger.CompareTo("true")==0)     plotSysTaggerHfJetTagging();
  if (doQuarkHadronLevel.CompareTo("true")==0)     plotSysQuarkHadronHfJetTagging();
  //if (doTagger.CompareTo("true")==0)     plotSysSVTopoCut();
}
