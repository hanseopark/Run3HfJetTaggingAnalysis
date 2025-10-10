#ifndef HFJETTAGGINGSYSMERGE_H
#define HFJETTAGGINGSYSMERGE_H

#include <TH1F.h>
#include <TString.h>
#include <vector>
#include <array>
#include "CanvasHandler.h"
#include "DataPoint.h"
#include "HfJetTaggingUtilities.h"

class HfJetTaggingSysMerge {
  public:
    HfJetTaggingSysMerge() {
      initConfig();
    }
    HfJetTaggingSysMerge(int nccc) {
      initConfig();
      gnc=nccc;
    }
    ~HfJetTaggingSysMerge();

    void initConfig();
    int processSetUp(const std::vector<std::pair<TString, TString>> &rootFiles);
    int loadSysFiles(const std::vector<std::pair<TString, TString>> &rootFiles);
    void initHist();
    void initAnalysis(const std::vector<std::pair<TString, TString>> &rootFiles);
    void savePara();

    // set
    void setFillTP(bool fillTP);
    void setFillUnfolding(bool fillUnfolding);
    void setFillSVCont(bool fillSVCont);
    void setFillTrackEffi(bool fillTrackEffi);
    void setFillPtReso(bool fillPtReso);
    void setSysTaggerPoint(TH1F* grsysTP);;
    void setSysUnfolding(TH1F* grsysUnfolding);
    void setSysSVCont(TH1F* grsysSVCont);

    // get
    int getNC();
    void getSysUnfolding();

    // calculate
    void calSysTaggerPoint();

    // draw
    void drawSysTP();
    void drawSysUnfolding();
    void drawSysSVCont();
    void drawSysTrackEffi();
    void drawSysPtReso();
    void drawSysTotal();
    void saveText();
    void saveRoot();

    // hist from root
    std::vector<TH1F*> hdataEventSel;
    std::vector<TH1F*> hdatajetPt;
    std::vector<TH1F*> hdatajetPtRebin;
    std::vector<TH1F*> hdatabjetEffi;
    std::vector<TH1F*> hdatabjetPurity;
    std::vector<TH1F*> hdatabjetXSection;
    TH1F* hsysSVUnfolding;
    TH1F* hsysSVUnfoldingParam;
    TH1F* hsysSVUnfoldingMethods;
    TH1F* hsysSVUnfoldingPer;
    TH1F* hsysSVUnfoldingParamPer;
    TH1F* hsysSVUnfoldingMethodsPer;
    std::vector<TGraphAsymmErrors*> grdatabjetXSection;
    std::vector<TGraphAsymmErrors*> grdatabjetXSectionSysUnfolding;

    // hist and graph of sys
    std::vector<TH1F*> hsysSVTotal;
    TH1F* hsysSVTP;
    TGraphAsymmErrors* grsysSVUnfolding;
    TGraphAsymmErrors* grsysSVTP;
    TGraphAsymmErrors* grsysSVCont;
    TGraphAsymmErrors* grsysSVPtReso;
    TGraphAsymmErrors* grsysSVTotal;

  private:
    bool fillTP; // tagger point
    bool fillUnfolding; // unfolding (methods, param)
    bool fillSVCont; // contaminton of seconadry vertex
    bool fillTrackEffi; // todo
    bool fillPtReso; // momentum smearing
    /// ...

  protected:
    int nc=gnc;
    int numFiles = 0;
    std::vector<std::pair<TString, TString>> files;
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;
    CanvasHandler* canHan;
    bool debug = false;
};

HfJetTaggingSysMerge::~HfJetTaggingSysMerge() {
}

// init
void HfJetTaggingSysMerge::initConfig() {

  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  TString dirFig = "fig";
  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  }
  dirData = Form("%s/%s/data/%s/sys/merge", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/sys/merge", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE);
  gSystem->mkdir(dirSim, kTRUE);
}

// Set function
void HfJetTaggingSysMerge::setFillTP(bool mfillTP) {
  fillTP = mfillTP;
  if (fillTP) {
    std::cout<< "fill systematic uncertainty of tagger point" << std::endl;
  }
}

void HfJetTaggingSysMerge::setFillUnfolding(bool mfillUnfolding) {
  fillUnfolding = mfillUnfolding;
  if (fillUnfolding) {
    std::cout<< "fill systematic uncertainty of unfolding" << std::endl;
  }
}

void HfJetTaggingSysMerge::setFillSVCont(bool mfillSVCont) {
  fillSVCont = mfillSVCont;
  if (fillSVCont) {
    std::cout<< "fill systematic uncertainty of sv contamination" << std::endl;
  }
}

void HfJetTaggingSysMerge::setFillTrackEffi(bool mfillTrackEffi) {
  fillTrackEffi = mfillTrackEffi;
  if (fillTrackEffi) {
    std::cout<< "fill systematic uncertainty of tracking efficiency" << std::endl;
  }
}

void HfJetTaggingSysMerge::setFillPtReso(bool mfillPtReso) {
  fillPtReso = mfillPtReso;
  if (fillPtReso) {
    std::cout<< "fill systematic uncertainty of track smearing" << std::endl;
  }
}


void HfJetTaggingSysMerge::setSysTaggerPoint(TH1F* hsysTP) {
  hsysSVTP = (TH1F*) hsysTP->Clone();
  std::cout << "done sys tp" << std::endl;
  std::cout << hsysSVTP->GetMean() << std::endl;
}

void HfJetTaggingSysMerge::setSysUnfolding(TH1F* hsysUnfolding) {
  hsysSVUnfolding = (TH1F*) hsysUnfolding->Clone();
  std::cout << "done sys unfolding" << std::endl;
  std::cout << hsysSVUnfolding->GetMean() << std::endl;
}

void HfJetTaggingSysMerge::setSysSVCont(TH1F* grsysSVCont) {
}

int HfJetTaggingSysMerge::processSetUp(const std::vector<std::pair<TString, TString>> &rootFiles) {
  numFiles = rootFiles.size();
  if (numFiles < 1) {
    std::cout << "no input file" << std::endl;
    return 0;
  }
  hdataEventSel.resize(numFiles);
  hdatajetPt.resize(numFiles);
  hdatajetPtRebin.resize(numFiles);
  hdatabjetEffi.resize(numFiles);
  hdatabjetPurity.resize(numFiles);
  hdatabjetXSection.resize(numFiles);
  grdatabjetXSection.resize(numFiles);
  grdatabjetXSectionSysUnfolding.resize(numFiles);
  return 1;
}

int HfJetTaggingSysMerge::loadSysFiles(const std::vector<std::pair<TString, TString>> &rootFiles) {
  const TString &taskData = "data";
  int numFile = 0;
  for (const auto& rootFile : rootFiles) {
    const TString fileName = rootFile.first;
    const TString fileDesc = rootFile.second;
    if (gSystem->AccessPathName(fileName)) {
      std::cout << "Input file (Data) not found!" << std::endl;
      std::cout << Form("%s ", fileName.Data()) << std::endl;
      return 0;
    }
    files.push_back(std::make_pair(fileName, fileDesc));
    TFile* fin;
    fin = TFile::Open(fileName, "READ");
    if (!fin || fin->IsZombie()) {
      std::cerr << "Failed to open file: " << fileName << std::endl;
      continue;
    }
    std::cout << "opened file: " << fileName.Data() << std::endl;
    hdataEventSel[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hdatanEvents", taskData.Data())));
    hdatajetPt[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_pt", taskData.Data())));
    hdatajetPtRebin[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hdatajetPtRebin", taskData.Data())));
    hdatabjetEffi[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hdatabjetEffi", taskData.Data())));
    hdatabjetPurity[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hdatabjetPurity", taskData.Data())));
    hdatabjetXSection[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hdatabjetXSection", taskData.Data())));
    grdatabjetXSection[numFile] = reinterpret_cast<TGraphAsymmErrors*>(fin->Get(Form("%s/grdatabjetXSection", taskData.Data())));
    if (fileDesc.CompareTo("unfold")==0) { // only unfodinbg
      grdatabjetXSectionSysUnfolding[numFile] = reinterpret_cast<TGraphAsymmErrors*>(fin->Get(Form("%s/grdatabjetXSectionSysUnfolding", taskData.Data())));
      hsysSVUnfolding = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hsysSVUnfolding", taskData.Data())));
      hsysSVUnfoldingParam = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hsysSVUnfoldingParam", taskData.Data())));
      hsysSVUnfoldingMethods = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hsysSVUnfoldingMethods", taskData.Data())));
      hsysSVUnfoldingPer = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hsysSVUnfoldingPer", taskData.Data())));
      hsysSVUnfoldingParamPer = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hsysSVUnfoldingPerParam", taskData.Data())));
      hsysSVUnfoldingMethodsPer = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hsysSVUnfoldingPerMethods", taskData.Data())));
    }
    numFile++;
  }
  return 1;
}

void HfJetTaggingSysMerge::initHist() {
//  for (int numFile =0; numFile < numFiles; numFile++) {
//    hsysSVTotal.push_back(new TH1F(Form("hsysSVTotal_%d", numFile), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt));
//  }
  hsysSVTP = new TH1F("hsysSVTP", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
}

void HfJetTaggingSysMerge::initAnalysis(const std::vector<std::pair<TString, TString>> &rootFiles) {
  processSetUp(rootFiles);
  loadSysFiles(rootFiles);
  initHist();
}

void HfJetTaggingSysMerge::savePara() {
  gnc=nc;
}

int HfJetTaggingSysMerge::getNC() {
  return gnc;
}

void HfJetTaggingSysMerge::getSysUnfolding() {
  grsysSVUnfolding = (TGraphAsymmErrors*) grdatabjetXSectionSysUnfolding[0]->Clone("grsysSVUnfolding");
  grsysSVUnfolding->SetTitle("Unfolding Systematic Uncertainty; #it{p}_{T}^{jet} (GeV/#it{c}); Systematic Uncertainty");
  std::cout << "Systematic uncertainty graph grsysSVUnfolding gotten successfully.\n";
}

// calculate
void HfJetTaggingSysMerge::calSysTaggerPoint() {

  const int nFiles = files.size();
  if (nFiles == 0) {
    std::cerr << "No input files loaded!\n";
    return;
  }

  const int nPoints = grdatabjetXSection[0]->GetN();
  std::vector<double> jetPt(nPoints);
  std::vector<double> sysError(nPoints);
  double sysErrorPer;

  for (int nPoint = 0; nPoint < nPoints; nPoint++) {
    double ptRef, yRef;
    grdatabjetXSection[0]->GetPoint(nPoint, ptRef, yRef);
    jetPt[nPoint] = ptRef;

    std::vector<double> xsecVariations;

    for (int nFile = 0; nFile < nFiles; nFile++) {
      if (!grdatabjetXSection[nFile]) {
        std::cout << "no bjet xsection" << ", nPoint:" << nPoint << ", num of file: " << nFile << std::endl;
        continue;
      }
      double pt, xsec;
      grdatabjetXSection[nFile]->GetPoint(nPoint, pt, xsec);
      xsecVariations.push_back(xsec);
    }

    double mean = std::accumulate(xsecVariations.begin(), xsecVariations.end(), 0.0) / xsecVariations.size();
    double rms = 0;
    for (const auto& val : xsecVariations) {
      rms += std::pow(val - mean, 2);
    }
    rms = std::sqrt(rms / xsecVariations.size());

    sysError[nPoint] = rms;
    sysErrorPer = rms / mean;
    if (debug) {
      std::cout << "xsec: " << xsecVariations[0] << ", " << xsecVariations[1] << ", " << xsecVariations[2] << ", rms: " << rms << ", sys error per ref: " << sysErrorPer << std::endl;
    }
    if (rms == 0) continue;
    hsysSVTP->SetBinContent(nPoint+1, sysErrorPer);
  }

  grsysSVTP = new TGraphAsymmErrors(nPoints, &jetPt[0], &sysError[0], nullptr, nullptr, nullptr, nullptr);
  grsysSVTP->SetName("grsysSVTP");
  grsysSVTP->SetTitle("Tagger Systematic Uncertainty; #it{p}_{T}^{jet} (GeV/#it{c}); Systematic Uncertainty");

  std::cout << "Systematic uncertainty graph grsysSVTP created successfully.\n";
}

//void HfJetTaggingSysMerge::
// draw
void HfJetTaggingSysMerge::drawSysTP() {
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180);
  //gPad->SetLogy();
  //grsysSVTP->Draw("SAME A P S; Z ; 5");
  //grsysSVTP->Draw();
  hsysSVTP->Draw("PL");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/sysTaggerPointCut.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingSysMerge::drawSysUnfolding() {
  std::vector<HistogramData> histUnfolding;
  histUnfolding.push_back({hsysSVUnfoldingPer,"unfolding total"});
  histUnfolding.push_back({hsysSVUnfoldingParamPer,"unfolding SVD parameters"});
  histUnfolding.push_back({hsysSVUnfoldingMethodsPer,"unfolding methods (Bayes, SVD)"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180);
  //gPad->SetLogy();
  canHan->drawCombined(histUnfolding.size(), histUnfolding, true, true, 0.6, 0.6, 0.9, 0.9, 0.060, "PL");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/sysUnfolding.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180);
  //gPad->SetLogy();
  hsysSVUnfoldingParamPer->Draw("PL");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/sysUnfoldingParam.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180);
  //gPad->SetLogy();
  hsysSVUnfoldingParamPer->Draw("PL");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/sysUnfoldingMethods.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingSysMerge::drawSysSVCont() {
}

void HfJetTaggingSysMerge::drawSysTrackEffi() {
}

void HfJetTaggingSysMerge::drawSysPtReso() {
}

void HfJetTaggingSysMerge::drawSysTotal() {
  std::vector<HistogramData> histTotal;
  if (fillTP) histTotal.push_back({hsysSVTP, "tagging cut"});
  if (fillUnfolding) histTotal.push_back({hsysSVUnfolding, "unfolding"});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180);
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.0, 1.0, HfJetTagging::X_AXIS_JETPT, "(%)");
  canHan->drawCombined(histTotal.size(), histTotal, true, true, 0.6, 0.6, 0.9, 0.9, 0.060, "PL");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/sysTotalPer.pdf\")", nc++, dirData.Data()));
}

#endif // HFJETTAGGINGSYSMERGE_H
