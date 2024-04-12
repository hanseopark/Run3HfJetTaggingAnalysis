#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <TH1.h>
#include <TString.h>
#include <TMath.h>

//global var
TString DATASET="initdata";
TString SIMSET="initsim";

namespace CANOPT {
  const double MARKERSIZE=0.4;
  const double LEG[4]={0.7,0.7,0.9,0.9}; // xmin, ymin, xmax, ymax
  
}

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

  const int nBinsJetR = 3;
  const double binsJetR[nBinsJetR + 1] = {
  0,
  0.4,
  0.5,
  0.6};
  const int nBinsJetNTracks = 10;
  const int binsJetNTracks[nBinsJetNTracks + 1] = {
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  9,
  10};

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
    const double RHO[4]={-0.02,200.0,1.0e-6,1.0};
    const double RHOM[4]={-0.02,50.0,1.0e-6,1.0};
    const double DELTAJETPT[4]={-10.0,10.0,1.0e-5,0.15};
    const double DELTAJETETA[4]={-0.1f,0.1f,1.0e-7,0.1};
    const double DELTAJETPHI[4]={-0.1f,0.1f,1.0e-7,0.1};
  } // namespace REFHIST
} // namespace GeneralJet

namespace HfJetTagging{

  enum JetFlavour {
    None = 0,   // Not used, as histogram bins start from 1
    Charm = 1,
    Beauty = 2,
    LightFlavour = 3
  };

  const int nFlavour = 3;
  const int cutJetPt = 10;
  const int startJetPt = 0;
  const int nBinsJetPt = 6;
  const double binsJetPt[nBinsJetPt + 1] = {
  0,
  10,
  20,
  40,
  60,
  80,
  100};
  //200};
  const int startTrackPt = 0;
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

  const int numTrackSelection =2;
  const int numTrigger =5;
  const int numPass =4;
  const int numTagger =10;

  const int NumShower = 2;

  const TString FLAVOUR[4] = {"inclusive", "c", "b", "lf"};
  const TString FLAVOURJET[4] = {"inclusive jet", "c jet", "b jet", "lf jet"};
  const TString INCJET="inclusive jet";
  const TString LFJET="lf jet";
  const TString CJET="c jet";
  const TString BJET="b jet";
  const TString X_AXIS_IMPXY[4] = {"IP_{XY} [#mum]",
                                   "sIP_{XY} [#mum]",
                                   "IPs_{XY} [#mum]",
                                   "sIPs_{XY} [#mum]"};
  const TString Y_AXIS_IMPXY[4] = {"#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XY}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{sXY}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XY}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}"};
  const TString X_AXIS_IMPZ[4] = {"IP_{Z} [#mum]",
                                   "sIP_{Z} [#mum]",
                                   "IPs_{Z} [#mum]",
                                   "sIPs_{Z} [#mum]"};
  const TString Y_AXIS_IMPZ[4] = {"#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{Z}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{sZ}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{Z}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{Z}}}"};
  const TString X_AXIS_IMPXYZ[4] = {"IP_{XYZ} [#mum]",
                                   "sIP_{XYZ} [#mum]",
                                   "IPs_{XYZ} [#mum]",
                                   "sIPs_{XYZ} [#mum]"};
  const TString Y_AXIS_IMPXYZ[4] = {"#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XYZ}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{sXYZ}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XYZ}}}",
                                   "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XYZ}}}"};
  const int INCJETCOLOR=1;
  const int LFJETCOLOR=2;
  const int CJETCOLOR=3;
  const int BJETCOLOR=4;
  const double MARKERSIZE=0.4;
  const double LEG[4]={0.7,0.7,0.9,0.9}; // xmin, ymin, xmax, ymax
  namespace SYS { // As regard of systematic uncertainty
    const TString RADIUS[5] = {"#DeltaR < 0.1", "#DeltaR < 0.2", "#DeltaR < 0.3", "#DeltaR < 0.4", "#DeltaR < 0.5"};
    const TString SHOWER[2] = {"with gluon spliting", "remove gluon spliting"};
    const TString TRACKSELECTION[numTrackSelection] = {"globalTracks", "QualityTracks"};
    const TString TRIGGER[numTrigger] = {"Jet", "bbbarJet", "ccbarJet", "bbbar", "ccbar"};
    const TString PASS[numPass] = {"JetJet", "apass4", "apass4highIR", "apass6"};
    const float binsTagger[numTagger] = { 
      0.0, 0.5, 1.0, 1.5, 2.0,
      2.5, 3.0, 3.5, 4.0, 4.5
    };
  }
  namespace CUT {
    const float sigmaLxy = 0.03; //cm
    const float Sxy = 7.;
  } // namespace CUT
  namespace REFHIST { // xmin, xmax, ymin, ymax
    const double RATIO[4] = {-0.1, 0.1, 0.5, 1.5};
    const double JETPT[4] = {-0.02,100.0,1.0e-9,1.15};
    const double TRACKPT[4]={-0.02,100.0,1.0e-5,0.15};
    const double TRACKPTASJETPT[4]={-0.02,100.0,1.0e-5,1.0e-1};
    const double TRACKETA[4]={-1.f,1.f,1.0e-7,0.1};
    const double TRACKETAASJETPT[4]={-1.f,1.f,1.0e-7,0.1};
    const double TRACKPHI[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
    const double TRACKPHIASJETPT[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
    const double IPXY[4]={-400,400,1.0e-6,0.1};
    const double IPZ[4]={-400,400,1.0e-6,0.1};
    const double IPXYZ[4]={-1000,1000,1.0e-5,1.0};
    const double IPXYSIG[4]={-40,40,1.0e-6,0.1};
    const double IPZSIG[4]={-40,40,1.0e-6,0.1};
    const double IPXYZSIG[4]={-100,100,1.0e-6,0.1};
    const double JP[4]={-0.01,1.0,1.0e-5,0.1};
    const double LOGJP[4]={-0.01,10,1.0e-5,0.1};
    const double LXY[4]={-0.01,1.0,1.0e-5,1.0};
    const double SXY[4]={-0.01,100,1.0e-5,1.0};
    const double LXYZ[4]={-0.01,1.0,1.0e-5,1.0};
    const double SXYZ[4]={-0.01,100,1.0e-5,1.0};
    const double sigmaLXY[4]={-0.01,0.1,1.0e-5,1.0};
    const double sigmaLXYZ[4]={-0.01,0.1,1.0e-5,1.0};
    
    const double EFFI[4] = {-0.02, 100.0, 0, 1.0};
    const double PURITY[4] = {-0.02, 200.0, 0, 1.0};

  } // namespace REFHIST
  const double REFIPXY[4][4] = {
    {REFHIST::IPXY[0], REFHIST::IPXY[1], REFHIST::IPXY[2], REFHIST::IPXY[3]},
    {REFHIST::IPXY[0], REFHIST::IPXY[1], REFHIST::IPXY[2], REFHIST::IPXY[3]},
    {REFHIST::IPXYSIG[0], REFHIST::IPXYSIG[1], REFHIST::IPXYSIG[2], REFHIST::IPXYSIG[3]},
    {REFHIST::IPXYSIG[0], REFHIST::IPXYSIG[1], REFHIST::IPXYSIG[2], REFHIST::IPXYSIG[3]}
  };
  const double REFIPZ[4][4] = {
    {REFHIST::IPZ[0], REFHIST::IPZ[1], REFHIST::IPZ[2], REFHIST::IPZ[3]},
    {REFHIST::IPZ[0], REFHIST::IPZ[1], REFHIST::IPZ[2], REFHIST::IPZ[3]},
    {REFHIST::IPZSIG[0], REFHIST::IPZSIG[1], REFHIST::IPZSIG[2], REFHIST::IPZSIG[3]},
    {REFHIST::IPZSIG[0], REFHIST::IPZSIG[1], REFHIST::IPZSIG[2], REFHIST::IPZSIG[3]}
  };
  const double REFIPXYZ[4][4] = {
    {REFHIST::IPXYZ[0], REFHIST::IPXYZ[1], REFHIST::IPXYZ[2], REFHIST::IPXYZ[3]},
    {REFHIST::IPXYZ[0], REFHIST::IPXYZ[1], REFHIST::IPXYZ[2], REFHIST::IPXYZ[3]},
    {REFHIST::IPXYZSIG[0], REFHIST::IPXYZSIG[1], REFHIST::IPXYZSIG[2], REFHIST::IPXYZSIG[3]},
    {REFHIST::IPXYZSIG[0], REFHIST::IPXYZSIG[1], REFHIST::IPXYZSIG[2], REFHIST::IPXYZSIG[3]}
  };
} // namespace HfJetTagging


struct HistogramData {
  TH1F* hist;
  TString classification;
  TString description;
  // You can add more members if needed
};

struct Histogram2DData {
  TH2F* hist;
  TString classification;
  TString description;
  // You can add more members if needed
};

#endif // DATAPOINT_H

