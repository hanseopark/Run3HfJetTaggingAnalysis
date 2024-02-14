#ifndef HFJETTAGGINGSYSANALYSIS_H
#define HFJETTAGGINGSYSANALYSIS_H

#include <TH1F.h>
#include <TString.h>
#include "CanvasHandler.h"
#include "DataPoint.h"

class HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysAnalysis(const std::vector<TString> &rootSim, bool doData, bool doMC, bool dopartLevel) {
///      if (doData) {
///        LoadData(rootSim);
///      }
      if (doMC) {
        if(!LoadSim(rootSim)) {
          return;
        }
        InitHistogram();
        ProjectionHist();
        NormalizedHistogram();
      }

    }
    ~HfJetTaggingSysAnalysis();

    //// FUNCTION ////
    int LoadSim(const std::vector<TString> &rootFiles);
    void InitHistogram();
    void ProjectionHist();
    void NormalizedHistogram();

    // fucntion
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);

  protected:
    CanvasHandler* canvasHandler;
    int canvasNum=0;

  private:

};

HfJetTaggingSysAnalysis::~HfJetTaggingSysAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

int HfJetTaggingSysAnalysis::LoadSim(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      return 0;
    }
  }

  return 1;
}

void HfJetTaggingSysAnalysis::InitHistogram() {

}

void HfJetTaggingSysAnalysis::ProjectionHist() {

}

void HfJetTaggingSysAnalysis::NormalizedHistogram() {

}

void HfJetTaggingSysAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingSysAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if(doLog) leg->Draw();
}

#endif // HFJETTAGGINGSYSANALYSIS_H
