#ifndef JETANALYSIS_H
#define JETANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

class JetAnalysis {
  public:
    JetAnalysis(const TString rootFile, const TString taskName, bool doMC) {
    }
    JetAnalysis(const TString rootFile, const TString taskName, bool doMC, const TString cutSelection); 
    ~JetAnalysis();

    void HistColorStyle(TH1D* h1, int mc, int ms, double mS, int lc, int ls);

  private:
    std::vector<HistogramData> histList;
    int asdfasdf;
    int canvasNum=0;

};

JetAnalysis::~JetAnalysis() {}

void JetAnalysis::HistColorStyle(TH1D* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}


#endif // JETANALYSIS_H
