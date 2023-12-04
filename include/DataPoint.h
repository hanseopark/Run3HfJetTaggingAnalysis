#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <TH1.h>
#include <TString.h>
#include <TMath.h>

namespace HfJetTagging{
  const int nBinsJetPt = 18;
  const double binsJetPt[nBinsJetPt + 1] = {
  0,
  2.0,
  4.0,
  10.0,
  15.0,
  20.0,
  25.0,
  30.0,
  35.0,
  40.0,
  45.0,
  50.0,
  55.0,
  60.0,
  65.0,
  70.0,
  80.0,
  90.0,
  100.0};
  const TString INCJET="inclusive jet";
  const TString LFJET="lf jet";
  const TString CJET="c jet";
  const TString BJET="b jet";
  const int INCJETCOLOR=1;
  const int LFJETCOLOR=2;
  const int CJETCOLOR=3;
  const int BJETCOLOR=4;
  const double MARKERSIZE=0.4;
  const double LEG[4]={0.7,0.7,0.9,0.9}; // xmin, ymin, xmax, ymax
  namespace REFHIST { // xmin, xmax, ymin, ymax
    const double TRACKPT[4]={-0.02,100.0,-1.0e-7,0.15};
    const double TRACKETA[4]={-1.f,1.f,-1.0e-7,0.1};
    const double TRACKPHI[4]={-0.02,2*TMath::Pi(),-1.0e-7,0.1};
    const double IPXY[4]={-0.04,0.04,1.0e-6,1.0};
    const double IPXYZ[4]={-0.1,0.1,1.0e-5,1.0};
    const double IPXYSIG[4]={-20,20,1.0e-5,1.0};
    const double IPXYZSIG[4]={-100,100,1.0e-5,0.1};
    const double JP[4]={-0.01,1.0,1.0e-5,0.1};
    const double LOGJP[4]={-0.01,10,1.0e-5,0.1};
    const double LXY[4]={-0.01,0.1,1.0e-5,1.0};
    const double SXY[4]={-0.01,50,1.0e-5,1.0};
    const double LXYZ[4]={-0.01,0.1,1.0e-5,1.0};
    const double SXYZ[4]={-0.01,50,1.0e-5,1.0};

  } // namespace REFHIST
} // namespace HfJetTagging


struct HistogramData {
  TH1D* hist;
  TString classification;
  TString description;
  // You can add more members if needed
};

#endif // DATAPOINT_H

