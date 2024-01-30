#ifndef HFJETTAGGINGSYSANALYSIS_H
#define HFJETTAGGINGSYSANALYSIS_H

#include <TH1F.h>
#include <TString.h>
#include "DataPoint.h"

class HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysAnalysis(bool doData, bool doMC, bool dopartLevel);
    ~HfJetTaggingSysAnalysis();

    // fucntion
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    int canvasNum=0;
  protected:

  private:
    static const int temp =-1;


};

HfJetTaggingSysAnalysis::HfJetTaggingSysAnalysis(bool doData, bool doMC, bool dopartLevel) {
  std::cout<< " " << std::endl;
}

HfJetTaggingSysAnalysis::~HfJetTaggingSysAnalysis() {
  std::cout<< " " << std::endl;
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

#endif // HFJETTAGGINGSYSANALYSIS_H
