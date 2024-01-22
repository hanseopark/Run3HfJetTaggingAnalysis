#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <TH1.h>
#include <TString.h>
#include <TMath.h>

namespace GeneralJet {
  const int nBinsJetPt = 8;
  const int binsJetPt[nBinsJetPt + 1] = {
  0,
  5,
  10,
  20,
  40,
  60,
  80,
  100,
  200};

  const int nBinsJetR = 1;
  const int binsJetR[nBinsJetR + 1] = {
  0,
  1};

  const double LEG[4]={0.7,0.7,0.9,0.9}; // xmin, ymin, xmax, ymax
  const double MARKERSIZE=0.4;
  namespace REFHIST { // xmin, xmax, ymin, ymax
    const double JETPT[4] = {-0.02,200.0,1.0e-9,0.15};
    const double JETETA[4] = {-1.f,1.1f,1.0e-7,0.1};
    const double JETPHI[4] = {-0.02,2*TMath::Pi(),1.0e-7,0.1};
    const double JETAREA[4] = {-0.02,200.0,1.0e-9,0.15};
    const double JETNTRACKS[4] = {-0.02,50.0,1.0e-9,0.15};
    const double TRACKPT[4]={-0.02,100.0,1.0e-5,0.15};
    const double TRACKPTASJETPT[4]={-0.02,100.0,1.0e-8,1.0e-4};
    const double TRACKETA[4]={-1.f,1.f,1.0e-7,0.1};
    const double TRACKETAASJETPT[4]={-1.f,1.f,1.0e-7,0.1};
    const double TRACKPHI[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
    const double TRACKPHIASJETPT[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
  } // namespace REFHIST
} // namespace GeneralJet

namespace HfJetTagging{
  const int nFlavour = 3;
  const int startJetPt = 2;
  const int nBinsJetPt = 8;
  const int binsJetPt[nBinsJetPt + 1] = {
  0,
  5,
  10,
  20,
  40,
  60,
  80,
  100,
  200};
  const int nBinsTrackPt = 6;
  const double binsTrackPt[nBinsTrackPt + 1] = {
  0,
  0.5,
  1.0,
  1.5,
  2.0,
  2.5,
  3.0
  };

  const int MaxRadius =5;
  const double rangeRadius[MaxRadius + 1] = {
  0,
  0.1,
  0.2,
  0.3,
  0.4,
  0.5
  };

  const int NumShower = 2;

  const TString FLAVOUR[4] = {"inclusive", "lf", "c", "b"};
  const TString FLAVOURJET[4] = {"inclusive jet", "lf jet", "c jet", "b jet"};
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
  namespace SYS { // As regard of systematic uncertainty
    const TString RADIUS[5] = {"#DeltaR < 0.1", "#DeltaR < 0.2", "#DeltaR < 0.3", "#DeltaR < 0.4", "#DeltaR < 0.5"};
    const TString SHOWER[2] = {"with gluon spliting", "without gluon spliting"};

  }
  namespace REFHIST { // xmin, xmax, ymin, ymax
    const double JETPT[4] = {-0.02,200.0,1.0e-9,1.15};
    const double TRACKPT[4]={-0.02,100.0,1.0e-5,0.15};
    const double TRACKPTASJETPT[4]={-0.02,100.0,1.0e-8,1.0e-4};
    const double TRACKETA[4]={-1.f,1.f,1.0e-7,0.1};
    const double TRACKETAASJETPT[4]={-1.f,1.f,1.0e-7,0.1};
    const double TRACKPHI[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
    const double TRACKPHIASJETPT[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
    const double IPXY[4]={-400,400,1.0e-6,0.1};
    const double IPXYZ[4]={-1000,1000,1.0e-5,1.0};
    const double IPXYSIG[4]={-20,20,1.0e-5,0.1};
    const double IPXYZSIG[4]={-10000,10000,1.0e-5,0.1};
    const double JP[4]={-0.01,1.0,1.0e-5,0.1};
    const double LOGJP[4]={-0.01,10,1.0e-5,0.1};
    const double LXY[4]={-0.01,0.1,1.0e-5,1.0};
    const double SXY[4]={-0.01,50,1.0e-5,1.0};
    const double LXYZ[4]={-0.01,0.1,1.0e-5,1.0};
    const double SXYZ[4]={-0.01,50,1.0e-5,1.0};

  } // namespace REFHIST
} // namespace HfJetTagging


struct HistogramData {
  TH1F* hist;
  TString classification;
  TString description;
  // You can add more members if needed
};

#endif // DATAPOINT_H

