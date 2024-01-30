#include <iostream>
#include <vector>
#include "../include/DataPoint.h"
#include "TFile.h"
#include "TString.h"
#include "../include/HfJetTaggingSysShowerAnalysis.h"
#include "../include/HfJetTaggingSysRadiusAnalysis.h"

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
//  TString taskTC = "jet-taggerhf-tc-charged";

  bool doData = false;
  bool doMC = true;
  bool dopartLevel = false;
  bool doLog = true;

  HfJetTaggingSysRadiusAnalysis *HfJetTagSysRadiusObj = new HfJetTaggingSysRadiusAnalysis(rootFiles, doData, doMC, dopartLevel);
  HfJetTagSysRadiusObj->DrawIncJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawCharmJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawBeautyJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawLfJetTrackPtRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawIncJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawCharmJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawBeautyJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
  HfJetTagSysRadiusObj->DrawLfJetSignImpXYSignificanceRadius(doLog, HfJetTagging::MaxRadius);
  //HfJetTaggingSysRadiusAnalysis *HfJetTagSysRadiusObj = new HfJetTaggingSysRadiusAnalysis(Form("%s/AnalysisResults_radius_0_1.root", pwd.Data()), doMC);
  //TString temp = "temp";
  //HfJetTaggingSysRadiusAnalysis *HfJetTagSysRadiusObj = new HfJetTaggingSysRadiusAnalysis(temp.Data(), doMC);
  
}


void PlotSysHfJetTagging(TString doShower = "false", TString doRadius = "false") {
  if (doShower.CompareTo("true")==0) PlotSysShowerHfJetTagging();
  if (doRadius.CompareTo("true")==0) PlotSysRadiusHfJetTagging();
}
