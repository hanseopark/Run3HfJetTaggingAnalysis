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

void PlotSysShowerHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
  std::vector<TString> rootFiles;
  rootFiles.push_back(Form("%s/AnalysisResults_shower_1.root", pwd.Data())); // include shower
  rootFiles.push_back(Form("%s/AnalysisResults_shower_0.root", pwd.Data())); // without shower

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;
  
  HfJetTaggingSysShowerAnalysis *HfJetTagSysShowerObj = new HfJetTaggingSysShowerAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysShowerObj->DrawIncJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawCharmJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawBeautyJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawLfJetTrackPtShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawIncJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawCharmJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawBeautyJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);
  HfJetTagSysShowerObj->DrawLfJetSignImpXYSignificanceShower(doLog, HfJetTagging::NumShower);

}

void PlotSysRadiusHfJetTagging() {
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
//  HfJetTagSysRadiusObj->DrawIncJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawCharmJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawBeautyJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawLfJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawIncJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawCharmJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawBeautyJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
//  HfJetTagSysRadiusObj->DrawLfJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
  
}

void PlotSysTrackSelectionHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel";
  std::vector<TString> rootFiles;

  // include root file to get systematic uncertainty and plots compared when it has different parameters
  rootFiles.push_back(Form("%s/AnalysisResults_globalTracks.root", pwd.Data()));
  rootFiles.push_back(Form("%s/AnalysisResults_QualityTracks.root", pwd.Data()));
  //rootFiles.push_back(Form("%s/AnalysisResults_TrackTunerOn.root", pwd.Data()));
  //rootFiles.push_back(Form("%s/AnalysisResults_hybridTracksJE.root", pwd.Data()));

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;

  HfJetTaggingSysTrackSelectionAnalysis *HfJetTagSysTrackSelectionObj = new HfJetTaggingSysTrackSelectionAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysTrackSelectionObj->DrawIncJetTrackPtTrackSelection(doLog, HfJetTagging::numTrackSelection);
  HfJetTagSysTrackSelectionObj->DrawIncJetTrackEtaTrackSelection(doLog, HfJetTagging::numTrackSelection);
  HfJetTagSysTrackSelectionObj->DrawIncJetTrackPhiTrackSelection(doLog, HfJetTagging::numTrackSelection);

  HfJetTagSysTrackSelectionObj->DrawIncJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);
  HfJetTagSysTrackSelectionObj->DrawCharmJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);
  HfJetTagSysTrackSelectionObj->DrawBeautyJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);
  HfJetTagSysTrackSelectionObj->DrawLfJetSignImpXYSigTrackSelection(doLog, HfJetTagging::numTrackSelection);

}

void PlotSysTriggerHfJetTagging() {
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
  HfJetTagSysTriggerObj->DrawIncJetTrackPtTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJetTrackEtaTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJetTrackPhiTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJet2ProngLxyTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJet2ProngLxyzTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJet2ProngsigmaLxyTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJet2ProngsigmaLxyzTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJet2ProngSxyTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawIncJet2ProngSxyzTrigger(doLog, HfJetTagging::numTrigger);

  HfJetTagSysTriggerObj->DrawIncJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawCharmJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawBeautyJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawLfJetSignImpXYSigTrigger(doLog, HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawTagJetEntriesTrigger(HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawTagJetTrackEntriesTrigger(HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawTagJetNormEntriesTrigger(HfJetTagging::numTrigger);
  HfJetTagSysTriggerObj->DrawTagJetNormTrackEntriesTrigger(HfJetTagging::numTrigger);

}

void PlotSysPassHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HY/sim";
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
  HfJetTagSysPassObj->DrawIncJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
  HfJetTagSysPassObj->DrawCharmJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
  HfJetTagSysPassObj->DrawBeautyJetSignImpXYSigPass(doLog, HfJetTagging::numPass);
  HfJetTagSysPassObj->DrawLfJetSignImpXYSigPass(doLog, HfJetTagging::numPass);

}

void PlotSysTaggerHfJetTagging() {
  TString pwd="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/local/sim";
  std::vector<TString> rootFiles;
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_0_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_0_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_1_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_1_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_2_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_2_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_3_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_3_5.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_4_0.root", pwd.Data()));
  rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_4_5.root", pwd.Data()));
  //rootFiles.push_back(Form("%s/LHC23d4/AnalysisResults_JP_5_0.root", pwd.Data()));

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = false;

  HfJetTaggingSysTaggerAnalysis *HfJetTagSysTaggerObj = new HfJetTaggingSysTaggerAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysTaggerObj->drawGraphEffiAndPurity(doLog, 0);

}

void PlotSysHfJetTagging(TString doShower = "false", TString doRadius = "false", TString doTS = "false", TString doTrigger = "false", TString doPass = "false", TString doTagger = "false") {
  if (doShower.CompareTo("true")==0) PlotSysShowerHfJetTagging();
  if (doRadius.CompareTo("true")==0) PlotSysRadiusHfJetTagging();
  if (doTS.CompareTo("true")==0)     PlotSysTrackSelectionHfJetTagging();
  if (doTrigger.CompareTo("true")==0)     PlotSysTriggerHfJetTagging();
  if (doPass.CompareTo("true")==0)     PlotSysPassHfJetTagging();
  if (doTagger.CompareTo("true")==0)     PlotSysTaggerHfJetTagging();
}
