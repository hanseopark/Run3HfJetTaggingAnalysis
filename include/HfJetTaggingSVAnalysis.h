#ifndef HFJETTAGGINGSVANALYSIS_H
#define HFJETTAGGINGSVANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "JetAnalysis.h"

class HfJetTaggingSVAnalysis : public JetAnalysis{
  public:
    HfJetTaggingSVAnalysis(const TString &rootFileTC, const TString &rootFileSV2Prong, const TString &rootFileSV3Prong, const TString &taskTC, const TString &taskSV, bool doMC, bool doSV2Prong, bool doSV3Prong) : JetAnalysis(rootFileTC, rootFileSV2Prong, rootFileSV3Prong, taskTC, taskSV, doMC, false, false, doSV2Prong, doSV3Prong){
      if (doMC) LoadSim(rootFileSV2Prong.Data(), rootFileSV3Prong.Data(), taskSV.Data(), doSV2Prong, doSV3Prong);
      else LoadData(rootFileSV2Prong.Data(), taskSV.Data()); // TODO
      InitHistogram(doSV2Prong, doSV3Prong);
      NormalizedHistogram(doSV2Prong, doSV3Prong);
    }
    //HfJetTaggingSVAnalysis(const TString &rootFile, const TString &taskName, bool doMC, const TString &cutSelection) : JetAnalysis(rootFile, taskName, doMC, cutSelection){
      //if (doMC) LoadSim(rootFile.Data(), taskName.Data());
      //else LoadData(rootFile.Data(), taskName.Data());
    //}
    ~HfJetTaggingSVAnalysis();

    int LoadSim(TString file2prong, TString file3prong, TString task, bool doSV2Prong, bool doSV3Prong);
    void InitHistogram(bool doSV2Prong, bool doSV3Prong);
    void NormalizedHistogram(bool doSV2Prong, bool doSV3Prong);
    int LoadData(TString file, TString task);
    void SaveHistogram(TString file);

    // Draw
    void DrawCombined(int num, const std::vector<HistogramData>& histList, double legendxmin, double ymin, double xmax, double ymax);
    void DrawTaggedJet2ProngLxy(bool withInc);
    void DrawTaggedJet2ProngSxy(bool withInc);
    void DrawTaggedJet2ProngLxyz(bool withInc);
    void DrawTaggedJet2ProngSxyz(bool withInc);
    void DrawTaggedJet3ProngLxy(bool withInc);
    void DrawTaggedJet3ProngSxy(bool withInc);
    void DrawTaggedJet3ProngLxyz(bool withInc);
    void DrawTaggedJet3ProngSxyz(bool withInc);

    TH1D* hsimlfjet2ProngLxy;
    TH1D* hsimlfjet2ProngSxy;
    TH1D* hsimlfjet2ProngLxyz;
    TH1D* hsimlfjet2ProngSxyz;
    TH1D* hsimcjet2ProngLxy;
    TH1D* hsimcjet2ProngSxy;
    TH1D* hsimcjet2ProngLxyz;
    TH1D* hsimcjet2ProngSxyz;
    TH1D* hsimbjet2ProngLxy;
    TH1D* hsimbjet2ProngSxy;
    TH1D* hsimbjet2ProngLxyz;
    TH1D* hsimbjet2ProngSxyz;
    TH1D* hsimlfjet3ProngLxy;
    TH1D* hsimlfjet3ProngSxy;
    TH1D* hsimlfjet3ProngLxyz;
    TH1D* hsimlfjet3ProngSxyz;
    TH1D* hsimcjet3ProngLxy;
    TH1D* hsimcjet3ProngSxy;
    TH1D* hsimcjet3ProngLxyz;
    TH1D* hsimcjet3ProngSxyz;
    TH1D* hsimbjet3ProngLxy;
    TH1D* hsimbjet3ProngSxy;
    TH1D* hsimbjet3ProngLxyz;
    TH1D* hsimbjet3ProngSxyz;

    // Normalized
    TH1D* hsimlfjet2ProngNormalizedLxy;
    TH1D* hsimlfjet2ProngNormalizedSxy;
    TH1D* hsimlfjet2ProngNormalizedLxyz;
    TH1D* hsimlfjet2ProngNormalizedSxyz;
    TH1D* hsimcjet2ProngNormalizedLxy;
    TH1D* hsimcjet2ProngNormalizedSxy;
    TH1D* hsimcjet2ProngNormalizedLxyz;
    TH1D* hsimcjet2ProngNormalizedSxyz;
    TH1D* hsimbjet2ProngNormalizedLxy;
    TH1D* hsimbjet2ProngNormalizedSxy;
    TH1D* hsimbjet2ProngNormalizedLxyz;
    TH1D* hsimbjet2ProngNormalizedSxyz;
    TH1D* hsimlfjet3ProngNormalizedLxy;
    TH1D* hsimlfjet3ProngNormalizedSxy;
    TH1D* hsimlfjet3ProngNormalizedLxyz;
    TH1D* hsimlfjet3ProngNormalizedSxyz;
    TH1D* hsimcjet3ProngNormalizedLxy;
    TH1D* hsimcjet3ProngNormalizedSxy;
    TH1D* hsimcjet3ProngNormalizedLxyz;
    TH1D* hsimcjet3ProngNormalizedSxyz;
    TH1D* hsimbjet3ProngNormalizedLxy;
    TH1D* hsimbjet3ProngNormalizedSxy;
    TH1D* hsimbjet3ProngNormalizedLxyz;
    TH1D* hsimbjet3ProngNormalizedSxyz;

  private:

};

HfJetTaggingSVAnalysis::~HfJetTaggingSVAnalysis() {
  if (hsimlfjet2ProngLxy) delete hsimlfjet2ProngLxy;
  if (hsimlfjet2ProngSxy) delete hsimlfjet2ProngSxy;
  if (hsimlfjet2ProngLxyz) delete hsimlfjet2ProngLxyz;
  if (hsimlfjet2ProngSxyz) delete hsimlfjet2ProngSxyz;
  if (hsimcjet2ProngLxy) delete hsimcjet2ProngLxy;
  if (hsimcjet2ProngSxy) delete hsimcjet2ProngSxy;
  if (hsimcjet2ProngLxyz) delete hsimcjet2ProngLxyz;
  if (hsimcjet2ProngSxyz) delete hsimcjet2ProngSxyz;
  if (hsimbjet2ProngLxy) delete hsimbjet2ProngLxy;
  if (hsimbjet2ProngSxy) delete hsimbjet2ProngSxy;
  if (hsimbjet2ProngLxyz) delete hsimbjet2ProngLxyz;
  if (hsimbjet2ProngSxyz) delete hsimbjet2ProngSxyz;

}

int HfJetTaggingSVAnalysis::LoadSim(TString rootFileSV2Prong, TString rootFileSV3Prong, TString taskName, bool doSV2Prong, bool doSV3Prong) {
  if (gSystem->AccessPathName(rootFileSV2Prong.Data())) {
    std::cout << "Input file (SV 2Prong MC) not found!" << std::endl;
    std::cout << rootFileSV2Prong.Data() << std::endl;
    return 0;
  }
  if (gSystem->AccessPathName(rootFileSV3Prong.Data())) {
    std::cout << "Input file (SV 3Prong MC) not found!" << std::endl;
    std::cout << rootFileSV3Prong.Data() << std::endl;
    return 0;
  }
  TFile* finSV2Prong; TFile* finSV3Prong;
  finSV2Prong = TFile::Open(rootFileSV2Prong, "READ");
  finSV3Prong = TFile::Open(rootFileSV3Prong, "READ");
  taskName = "jet-taggerhf-sv-charged";
  if (doSV2Prong) {
    hsimlfjet2ProngLxy = (TH1D*)finSV2Prong->Get(Form("%s/h_lfjet_2prong_Lxy", taskName.Data()));
    hsimlfjet2ProngSxy = (TH1D*)finSV2Prong->Get(Form("%s/h_lfjet_2prong_Sxy", taskName.Data()));
    hsimlfjet2ProngLxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_lfjet_2prong_Lxyz", taskName.Data()));
    hsimlfjet2ProngSxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_lfjet_2prong_Sxyz", taskName.Data()));
    hsimcjet2ProngLxy = (TH1D*)finSV2Prong->Get(Form("%s/h_cjet_2prong_Lxy", taskName.Data()));
    hsimcjet2ProngSxy = (TH1D*)finSV2Prong->Get(Form("%s/h_cjet_2prong_Sxy", taskName.Data()));
    hsimcjet2ProngLxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_cjet_2prong_Lxyz", taskName.Data()));
    hsimcjet2ProngSxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_cjet_2prong_Sxyz", taskName.Data()));
    hsimbjet2ProngLxy = (TH1D*)finSV2Prong->Get(Form("%s/h_bjet_2prong_Lxy", taskName.Data()));
    hsimbjet2ProngSxy = (TH1D*)finSV2Prong->Get(Form("%s/h_bjet_2prong_Sxy", taskName.Data()));
    hsimbjet2ProngLxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_bjet_2prong_Lxyz", taskName.Data()));
    hsimbjet2ProngSxyz = (TH1D*)finSV2Prong->Get(Form("%s/h_bjet_2prong_Sxyz", taskName.Data()));
  } else {
    std::cout << "Don't load SV 2Prong MC data" << std::endl;
  }
  if (doSV3Prong) {
    hsimlfjet3ProngLxy = (TH1D*)finSV3Prong->Get(Form("%s/h_lfjet_3prong_Lxy", taskName.Data()));
    hsimlfjet3ProngSxy = (TH1D*)finSV3Prong->Get(Form("%s/h_lfjet_3prong_Sxy", taskName.Data()));
    hsimlfjet3ProngLxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_lfjet_3prong_Lxyz", taskName.Data()));
    hsimlfjet3ProngSxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_lfjet_3prong_Sxyz", taskName.Data()));
    hsimcjet3ProngLxy = (TH1D*)finSV3Prong->Get(Form("%s/h_cjet_3prong_Lxy", taskName.Data()));
    hsimcjet3ProngSxy = (TH1D*)finSV3Prong->Get(Form("%s/h_cjet_3prong_Sxy", taskName.Data()));
    hsimcjet3ProngLxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_cjet_3prong_Lxyz", taskName.Data()));
    hsimcjet3ProngSxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_cjet_3prong_Sxyz", taskName.Data()));
    hsimbjet3ProngLxy = (TH1D*)finSV3Prong->Get(Form("%s/h_bjet_3prong_Lxy", taskName.Data()));
    hsimbjet3ProngSxy = (TH1D*)finSV3Prong->Get(Form("%s/h_bjet_3prong_Sxy", taskName.Data()));
    hsimbjet3ProngLxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_bjet_3prong_Lxyz", taskName.Data()));
    hsimbjet3ProngSxyz = (TH1D*)finSV3Prong->Get(Form("%s/h_bjet_3prong_Sxyz", taskName.Data()));
  } else {
    std::cout << "Don't load SV 3Prong MC data" << std::endl;
  }
  std::cout << "Load completed MC data" << std::endl;
  return 1;
}

int HfJetTaggingSVAnalysis::LoadData(TString rootFile, TString taskName) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (DATA) not found!" << std::endl;
    return 0;
  }

  return 1;
}

void HfJetTaggingSVAnalysis::InitHistogram(bool doSV2Prong, bool doSV3Prong) {
  if (doSV2Prong) {
    hsimlfjet2ProngNormalizedLxy = (TH1D*) hsimlfjet2ProngLxy->Clone("hsimlfjet2ProngLxy");
    hsimlfjet2ProngNormalizedSxy = (TH1D*) hsimlfjet2ProngSxy->Clone("hsimlfjet2ProngSxy");
    hsimlfjet2ProngNormalizedLxyz = (TH1D*) hsimlfjet2ProngLxyz->Clone("hsimlfjet2ProngLxyz");
    hsimlfjet2ProngNormalizedSxyz = (TH1D*) hsimlfjet2ProngSxyz->Clone("hsimlfjet2ProngSxyz");
    hsimcjet2ProngNormalizedLxy = (TH1D*) hsimcjet2ProngLxy->Clone("hsimcjet2ProngLxy");
    hsimcjet2ProngNormalizedSxy = (TH1D*) hsimcjet2ProngSxy->Clone("hsimcjet2ProngSxy");
    hsimcjet2ProngNormalizedLxyz = (TH1D*) hsimcjet2ProngLxyz->Clone("hsimcjet2ProngLxyz");
    hsimcjet2ProngNormalizedSxyz = (TH1D*) hsimcjet2ProngSxyz->Clone("hsimcjet2ProngSxyz");
    hsimbjet2ProngNormalizedLxy = (TH1D*) hsimbjet2ProngLxy->Clone("hsimbjet2ProngLxy");
    hsimbjet2ProngNormalizedSxy = (TH1D*) hsimbjet2ProngSxy->Clone("hsimbjet2ProngSxy");
    hsimbjet2ProngNormalizedLxyz = (TH1D*) hsimbjet2ProngLxyz->Clone("hsimbjet2ProngLxyz");
    hsimbjet2ProngNormalizedSxyz = (TH1D*) hsimbjet2ProngSxyz->Clone("hsimbjet2ProngSxyz");
  }
  
  if (doSV3Prong) {
    hsimlfjet3ProngNormalizedLxy = (TH1D*) hsimlfjet3ProngLxy->Clone("hsimlfjet3ProngLxy");
    hsimlfjet3ProngNormalizedSxy = (TH1D*) hsimlfjet3ProngSxy->Clone("hsimlfjet3ProngSxy");
    hsimlfjet3ProngNormalizedLxyz = (TH1D*) hsimlfjet3ProngLxyz->Clone("hsimlfjet3ProngLxyz");
    hsimlfjet3ProngNormalizedSxyz = (TH1D*) hsimlfjet3ProngSxyz->Clone("hsimlfjet3ProngSxyz");
    hsimcjet3ProngNormalizedLxy = (TH1D*) hsimcjet3ProngLxy->Clone("hsimcjet3ProngLxy");
    hsimcjet3ProngNormalizedSxy = (TH1D*) hsimcjet3ProngSxy->Clone("hsimcjet3ProngSxy");
    hsimcjet3ProngNormalizedLxyz = (TH1D*) hsimcjet3ProngLxyz->Clone("hsimcjet3ProngLxyz");
    hsimcjet3ProngNormalizedSxyz = (TH1D*) hsimcjet3ProngSxyz->Clone("hsimcjet3ProngSxyz");
    hsimbjet3ProngNormalizedLxy = (TH1D*) hsimbjet3ProngLxy->Clone("hsimbjet3ProngLxy");
    hsimbjet3ProngNormalizedSxy = (TH1D*) hsimbjet3ProngSxy->Clone("hsimbjet3ProngSxy");
    hsimbjet3ProngNormalizedLxyz = (TH1D*) hsimbjet3ProngLxyz->Clone("hsimbjet3ProngLxyz");
    hsimbjet3ProngNormalizedSxyz = (TH1D*) hsimbjet3ProngSxyz->Clone("hsimbjet3ProngSxyz");
  }
}

void HfJetTaggingSVAnalysis::NormalizedHistogram(bool doSV2Prong, bool doSV3Prong) {
  if (doSV2Prong) {
    hsimlfjet2ProngNormalizedLxy->Scale(1. / hsimlfjet2ProngNormalizedLxy->GetEntries());
    hsimlfjet2ProngNormalizedSxy->Scale(1. / hsimlfjet2ProngNormalizedSxy->GetEntries());
    hsimlfjet2ProngNormalizedLxyz->Scale(1. / hsimlfjet2ProngNormalizedLxyz->GetEntries());
    hsimlfjet2ProngNormalizedSxyz->Scale(1. / hsimlfjet2ProngNormalizedSxyz->GetEntries());
    hsimcjet2ProngNormalizedLxy->Scale(1. / hsimcjet2ProngNormalizedLxy->GetEntries());
    hsimcjet2ProngNormalizedSxy->Scale(1. / hsimcjet2ProngNormalizedSxy->GetEntries());
    hsimcjet2ProngNormalizedLxyz->Scale(1. / hsimcjet2ProngNormalizedLxyz->GetEntries());
    hsimcjet2ProngNormalizedSxyz->Scale(1. / hsimcjet2ProngNormalizedSxyz->GetEntries());
    hsimbjet2ProngNormalizedLxy->Scale(1. / hsimbjet2ProngNormalizedLxy->GetEntries());
    hsimbjet2ProngNormalizedSxy->Scale(1. / hsimbjet2ProngNormalizedSxy->GetEntries());
    hsimbjet2ProngNormalizedLxyz->Scale(1. / hsimbjet2ProngNormalizedLxyz->GetEntries());
    hsimbjet2ProngNormalizedSxyz->Scale(1. / hsimbjet2ProngNormalizedSxyz->GetEntries());
  }
  if (doSV3Prong) {
    hsimlfjet3ProngNormalizedLxy->Scale(1. / hsimlfjet3ProngNormalizedLxy->GetEntries());
    hsimlfjet3ProngNormalizedSxy->Scale(1. / hsimlfjet3ProngNormalizedSxy->GetEntries());
    hsimlfjet3ProngNormalizedLxyz->Scale(1. / hsimlfjet3ProngNormalizedLxyz->GetEntries());
    hsimlfjet3ProngNormalizedSxyz->Scale(1. / hsimlfjet3ProngNormalizedSxyz->GetEntries());
    hsimcjet3ProngNormalizedLxy->Scale(1. / hsimcjet3ProngNormalizedLxy->GetEntries());
    hsimcjet3ProngNormalizedSxy->Scale(1. / hsimcjet3ProngNormalizedSxy->GetEntries());
    hsimcjet3ProngNormalizedLxyz->Scale(1. / hsimcjet3ProngNormalizedLxyz->GetEntries());
    hsimcjet3ProngNormalizedSxyz->Scale(1. / hsimcjet3ProngNormalizedSxyz->GetEntries());
    hsimbjet3ProngNormalizedLxy->Scale(1. / hsimbjet3ProngNormalizedLxy->GetEntries());
    hsimbjet3ProngNormalizedSxy->Scale(1. / hsimbjet3ProngNormalizedSxy->GetEntries());
    hsimbjet3ProngNormalizedLxyz->Scale(1. / hsimbjet3ProngNormalizedLxyz->GetEntries());
    hsimbjet3ProngNormalizedSxyz->Scale(1. / hsimbjet3ProngNormalizedSxyz->GetEntries());
  }
}

void HfJetTaggingSVAnalysis::SaveHistogram(TString outFile) {
  TFile *fout = TFile::Open(outFile.Data(),"recreate");
  if (!fout) return;
  hsimlfjet2ProngNormalizedLxy->Write();
  hsimlfjet2ProngNormalizedSxy->Write();
  hsimlfjet2ProngNormalizedLxyz->Write();
  hsimlfjet2ProngNormalizedSxyz->Write();
  hsimcjet2ProngNormalizedLxy->Write();
  hsimcjet2ProngNormalizedSxy->Write();
  hsimcjet2ProngNormalizedLxyz->Write();
  hsimcjet2ProngNormalizedSxyz->Write();
  hsimbjet2ProngNormalizedLxy->Write();
  hsimbjet2ProngNormalizedSxy->Write();
  hsimbjet2ProngNormalizedLxyz->Write();
  hsimbjet2ProngNormalizedSxyz->Write();
  hsimlfjet3ProngNormalizedLxy->Write();
  hsimlfjet3ProngNormalizedSxy->Write();
  hsimlfjet3ProngNormalizedLxyz->Write();
  hsimlfjet3ProngNormalizedSxyz->Write();
  hsimcjet3ProngNormalizedLxy->Write();
  hsimcjet3ProngNormalizedSxy->Write();
  hsimcjet3ProngNormalizedLxyz->Write();
  hsimcjet3ProngNormalizedSxyz->Write();
  hsimbjet3ProngNormalizedLxy->Write();
  hsimbjet3ProngNormalizedSxy->Write();
  hsimbjet3ProngNormalizedLxyz->Write();
  hsimbjet3ProngNormalizedSxyz->Write();


  delete fout;
}

void HfJetTaggingSVAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, double xmin, double ymin, double xmax, double ymax){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1D *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  leg->Draw();
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngLxy(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet2ProngNormalizedLxy, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet2ProngNormalizedLxy, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet2ProngNormalizedLxy, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet2ProngNormalizedLxy, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "L_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/2ProngLxy.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngSxy(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet2ProngNormalizedSxy, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet2ProngNormalizedSxy, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet2ProngNormalizedSxy, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet2ProngNormalizedSxy, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "S_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/2ProngSxy.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngLxyz(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet2ProngNormalizedLxyz, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet2ProngNormalizedLxyz, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet2ProngNormalizedLxyz, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet2ProngNormalizedLxyz, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], "L_{xyz}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/2ProngLxyz.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet2ProngSxyz(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet2ProngNormalizedSxyz, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet2ProngNormalizedSxyz, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet2ProngNormalizedSxyz, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet2ProngNormalizedSxyz, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], "S_{xyz}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/2ProngSxyz.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet3ProngLxy(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet3ProngNormalizedLxy, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet3ProngNormalizedLxy, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet3ProngNormalizedLxy, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet3ProngNormalizedLxy, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "L_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/3ProngLxy.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet3ProngSxy(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet3ProngNormalizedSxy, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet3ProngNormalizedSxy, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet3ProngNormalizedSxy, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet3ProngNormalizedSxy, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "S_{xy}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/3ProngSxy.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet3ProngLxyz(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet3ProngNormalizedLxyz, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet3ProngNormalizedLxyz, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet3ProngNormalizedLxyz, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet3ProngNormalizedLxyz, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], "L_{xyz}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/3ProngLxyz.pdf\")", canvasNum - 1));
}

void HfJetTaggingSVAnalysis::DrawTaggedJet3ProngSxyz(bool withInc = false){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimincjet3ProngNormalizedSxyz, HfJetTagging::INCJET});
  NormHistList.push_back({hsimlfjet3ProngNormalizedSxyz, HfJetTagging::LFJET});
  NormHistList.push_back({hsimcjet3ProngNormalizedSxyz, HfJetTagging::CJET});
  NormHistList.push_back({hsimbjet3ProngNormalizedSxyz, HfJetTagging::BJET});

  canvasHandler = new CanvasHandler(canvasNum++);
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], "S_{xyz}", "Probability distribution");
  this->DrawCombined(NormHistList.size(), NormHistList, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/3ProngSxyz.pdf\")", canvasNum - 1));
}

#endif // HFJETTAGGINGSVANALYSIS_H 

