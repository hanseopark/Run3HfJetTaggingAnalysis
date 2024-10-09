#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <TH1.h>
#include <TString.h>
#include <TMath.h>

//global var
TString TAGSET="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets";
TString TRIGGERNAME="";
TString SOURCESET="hy"; // hy or local
TString DATASET="initdata";
TString SIMSET="initsim";
TString SUFFIXSET="";

void globalStyle() {
  cout << "Setting style!" << endl;

  //gROOT->SetBatch(true);
  gStyle->Reset("Plain");
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetCanvasColor(10);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetFrameLineWidth(1);
  gStyle->SetFrameFillColor(kWhite);
  gStyle->SetPadColor(10);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetHistLineWidth(1);
  gStyle->SetHistLineColor(kRed);
  gStyle->SetFuncWidth(2);
  gStyle->SetFuncColor(kGreen);
  gStyle->SetLineWidth(2);
  gStyle->SetPaintTextFormat("cf");

//  gStyle->SetLabelSize(0.045,"xyz");
//  gStyle->SetLabelOffset(0.01,"y");
//  gStyle->SetLabelOffset(0.01,"x");
//  gStyle->SetLabelColor(kBlack,"xyz");
//  gStyle->SetTitleSize(0.05,"xyz");
//  gStyle->SetTitleOffset(1.25,"y");
//  gStyle->SetTitleOffset(1.2,"x");
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetTextSizePixels(26);
  gStyle->SetTextFont(42);
  //  gStyle->SetTickLength(0.04,"X");  gStyle->SetTickLength(0.04,"Y");

  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFillColor(kWhite);
  //  gStyle->SetFillColor(kWhite);
  gStyle->SetLegendFont(42);
}

namespace CANOPT {
  const double MARKERSIZE=0.8;
  const double FLAVOURMARKERSIZE[4]={0.8, 0.8, 0.8, 0.8};
    const double LEG[4]={0.7,0.7,0.95,0.95}; // xmin, ymin, xmax, ymax
    
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

    const double LEG[4]={0.6,0.6,0.9,0.9}; // xmin, ymin, xmax, ymax
    const double MARKERSIZE=1.5;
    namespace REFHIST { // xmin, xmax, ymin, ymax
      const double JETPT[4] = {-0.02,200.0,1.0e-3,0.15};
      const double JETETA[4] = {-1.f,1.1f,1.0e-7,0.1};
      const double JETPHI[4] = {-0.02,2*TMath::Pi(),1.0e-3,0.1};
      const double JETAREA[4] = {-0.02,200.0,1.0e-9,0.15};
      const double JETNTRACKS[4] = {-0.02,50.0,1.0e-9,0.15};
      const double TRACKPT[4]={-0.02,100.0,1.0e-9,0.15};
      const double TRACKPTASJETPT[4]={-0.02,100.0,1.0e-8,1.0e-4};
      const double TRACKETA[4]={-1.f,1.f,1.0e-5, 1.15};
      const double TRACKETAASJETPT[4]={-1.f,1.f,1.0e-7,0.1};
      const double TRACKPHI[4]={-0.02,2*TMath::Pi(),1.0e-3,0.1};
      const double TRACKPHIASJETPT[4]={-0.02,2*TMath::Pi(),1.0e-3,0.1};
      const double RHO[4]={-0.02,200.0,1.0e-6,1.0};
      const double RHOM[4]={-0.02,50.0,1.0e-6,1.0};
      const double DELTAJETPT[4]={-10.0,10.0,1.0e-5,0.15};
      const double DELTAJETETA[4]={-0.1f,0.1f,1.0e-7,0.1};
      const double DELTAJETPHI[4]={-0.1f,0.1f,1.0e-7,0.1};
      const double TRACKEFFI[4] = {-0.02, 10.0, -0.1, 2.0};
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
    const int startTrackPt = 0;
    const int nBinsTrackPt = 2;
    const double binsTrackPt[nBinsTrackPt + 1] = {
    0,
    2.0,
    100.0,
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

    const int numTrackSelection =4;
    const int numTrigger =5;
    const int numPass =4;
    const int numTaggerIP =20;
    const float binWidthTaggerIP = 10.0 / numTaggerIP;
    const int numTaggerSV =20;
    const float xlowTaggerIP =  -binWidthTaggerIP / 2.0;
    const float xupTaggerIP =  100.0 -binWidthTaggerIP / 2.0;
    const float binWidthTaggerSV = 100.0 / numTaggerSV;
    const float xlowTaggerSV =  -binWidthTaggerSV / 2.0;
    const float xupTaggerSV =  100.0 -binWidthTaggerSV / 2.0;
    const int numSVTopoSxy =4;
    const int numSVToposigmaLxy =4;

    const int NumShower = 2;

    const TString FLAVOUR[4] = {"inc", "c", "b", "lf"};
    const TString FLAVOURJET[4] = {"inclusive jet", "charm jet", "beauty jet", "light-flavour jet"};
    const TString INCJET="inclusive jet";
    const TString LFJET="light-flavour jet";
    const TString CJET="charm jet";
    const TString BJET="beauty jet";
    const int colorFlavour[4]={kBlack, kGreen+3, kRed+1, kBlue+1};
    const int markerStyleFlavour[4]={kFullStar, kFullCircle, kFullDiamond, kFullCross};
    //const float markerSizeFlavour[4]={1.0,0.7,1.0,1.0};
    const float markerSizeFlavour[4]={1.2,0.9,1.2,1.2};
  //  const TString X_AXIS_IMPXY[4] = {"IP_{XY} [#mum]",
  //                                   "sIP_{XY} [#mum]",
  //                                   "IPs_{XY}",
  //                                   "sIPs_{XY}"};
  //  const TString X_AXIS_IMPXY[4] = {"#it{DCA}_{XY} [#mum]",
  //                                   "signed #it{DCA}_{XY} [#mum]",
  //                                   "#it{DCA}_{XY} /#it{#sigma}_{DCA_{XY}}",
  //                                   "signed #it{DCA}_{XY} /#it{#sigma}_{DCA_{XY}}"};
    const TString X_AXIS_TRACKPT = "#it{p}_{T}^{track}";
    const TString Y_AXIS_TRACKPT = "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d#it{p}_{T}^{track}}";
    const TString X_AXIS_TRACKETA = "#it{#eta}_{track}";
    const TString Y_AXIS_TRACKETA = "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d#it{#eta}_{track}}";
    const TString X_AXIS_TRACKPHI = "#it{#phi}_{track}";
    const TString Y_AXIS_TRACKPHI = "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d#it{#phi}_{track}}";
    const TString X_AXIS_JETPT = "#it{p}_{T}^{jet}";
    const TString Y_AXIS_JETPT = "#frac{1}{#it{N}_{jet}} #frac{d#it{N_{jet}}}{d#it{p}_{T}^{jet}}";
    const TString X_AXIS_JETETA = "#it{#eta}_{jet}";
    const TString Y_AXIS_JETETA = "#frac{1}{#it{N}_{jet}} #frac{d#it{N}_{jet}}{d#it{#eta}_{jet}}";
    const TString X_AXIS_JETPHI = "#it{#phi}_{jet}";
    const TString Y_AXIS_JETPHI = "#frac{1}{#it{N}_{jet}} #frac{d#it{N}_{jet}}{d#it{#phi}_{jet}}";
    const TString X_AXIS_IMPXY[4] = {"#it{DCA}_{XY} [#mum]",
                                     "S#it{DCA}_{XY} [#mum]",
                                     "#it{d}_{#it{XY}}",
                                     "S#it{d}_{#it{XY}}"};
    const TString Y_AXIS_IMPXY[4] = {"#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d#it{DCA}_XY}}}",
                                     "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{dS#it{DCA}_{XY}}",
                                     "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d(#it{d}_{#it{XY}})}",
                                     "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d(S#it{d}_{#it{XY}})}"};
    const TString X_AXIS_IMPZ[4] = {"IP_{Z} [#mum]",
                                     "sIP_{Z} [#mum]",
                                     "IPs_{Z}",
                                     "sIPs_{Z}"};
    const TString Y_AXIS_IMPZ[4] = {"#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{Z}}}",
                                     "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{sZ}}}",
                                     "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{Z}}}",
                                     "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{Z}}}"};
    const TString X_AXIS_IMPXYZ[4] = {"IP_{XYZ} [#mum]",
                                     "sIP_{XYZ} [#mum]",
                                     "IPs_{XYZ}",
                                     "sIPs_{XYZ}"};
    const TString Y_AXIS_IMPXYZ[4] = {"#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XYZ}}}",
                                     "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{sXYZ}}}",
                                     "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XYZ}}}",
                                     "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XYZ}}}"};
    const TString X_AXIS_IMPXY_NX[3] = {"S#it{d}_{#it{XY}}^{N_{1}}",
                                        "S#it{d}_{#it{XY}}^{N_{2}}",
                                        "S#it{d}_{#it{XY}}^{N_{3}}"};
    const TString Y_AXIS_IMPXY_NX[3] = {"#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d(S#it{d}_{#it{XY}}^{N_{1}})}",
                                        "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d(S#it{d}_{#it{XY}}^{N_{2}})}",
                                        "#frac{1}{#it{N}_{track}} #frac{d#it{N}_{track}}{d(S#it{d}_{#it{XY}}^{N_{3}})}"};

    const TString X_AXIS_LXY = "#it{L}_{XY} [cm]";
    const TString X_AXIS_SIGMALXY = "#it{#sigma}_{XY} [cm]";
    const TString X_AXIS_SXY = "S#it{L}_{XY}";
    const TString X_AXIS_LXYZ = "#it{L}_{XYZ} [cm]";
    const TString X_AXIS_SIGMALXYZ = "#it{#sigma}_{XYZ} [cm]";
    const TString X_AXIS_SXYZ = "#it{S}_{XYZ}";
    const TString X_AXIS_CHI2 = "#it{#chi}^{2}";
    const TString X_AXIS_MASS = "Invariant mass of secondary vertex (GeV/#it{c}^{2})";

    const TString AXIS_PROB = "Probaiblity distribution";
    const TString AXIS_YIELD = "yield";
    const TString AXIS_RATIO = "Data/MC";
    //const TString X_AXIS_JP = "#minusln(#it{P}_{jet}";
    const TString X_AXIS_JP = "#font[122]{-}ln(JP)";
    const TString X_AXIS_NEG_JP = "#font[122]{-}ln(JP)";
    const TString Y_AXIS_JP = "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{JP}}";
    const TString Y_AXIS_NEG_JP = "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{#font[122]{-}ln(JP)}}";
    const TString AXIS_ENTRIES = "Entries";
    const TString AXIS_EFFI = "Tagging efficiency";
    const TString AXIS_BEAUTY_EFFI = "#epsilon_{b}";
    const TString AXIS_PURITY = "Purity";
    const TString AXIS_BEAUTY_PURITY = "b-jet purity";
    const int INCJETCOLOR=1;
    const int LFJETCOLOR=2;
    const int CJETCOLOR=3;
    const int BJETCOLOR=4;
    const double MARKERSIZE=1.5;
    const double LEG[4]={0.65,0.70,0.86,0.91}; // xmin, ymin, xmax, ymax
    namespace SYS { // As regard of systematic uncertainty
      const TString RADIUS[5] = {"#DeltaR < 0.1", "#DeltaR < 0.2", "#DeltaR < 0.3", "#DeltaR < 0.4", "#DeltaR < 0.5"};
      const TString SHOWER[2] = {"with gluon spliting", "remove gluon spliting"};
      const TString TRACKSELECTION[numTrackSelection] = {"globalTracks", "QualityTracks", "uniformTracks", "uniformTracksWoDca"};
      const TString TRIGGER[numTrigger] = {"Jet", "bbbarJet", "ccbarJet", "bbbar", "ccbar"};
      const TString PASS[numPass] = {"JetJet", "apass4", "apass4highIR", "apass6"};
      const float binsTaggerIP[numTaggerIP] = { 
        0.0, 0.5, 1.0, 1.5, 2.0,
        2.5, 3.0, 3.5, 4.0, 4.5,
        5.0, 5.5, 6.0, 6.5, 7.0,
        7.5, 8.0, 8.5, 9.0, 9.5
      };
      const float binsTaggerSV[numTaggerSV] = { 
         0.0,  5.0, 10.0, 15.0, 20.0,
        25.0, 30.0, 35.0, 40.0, 45.0,
        50.0, 55.0, 60.0, 65.0, 70.0,
        75.0, 80.0, 85.0, 90.0, 95.0
      };

      const float binsSVTopoSxy[numSVTopoSxy] = { 
        6.0, 7.0, 8.0, 9.0
      };
      const float binsSVToposigmaLxy[numSVToposigmaLxy] = { 
        0.02, 0.03, 0.04, 0.05
      };

    }
    namespace CUT {
      const float sigmaLxy = 0.03; //cm
      const float Sxy = 30.;
      const float sigmaLxyz = 0.03; //cm
      const float Sxyz = 7.;
    } // namespace CUT
    namespace REFHIST { // xmin, xmax, ymin, ymax
      const double RATIO[4] = {-0.1, 0.1, 0.45, 1.55};
      const double JETPT[4] = {-0.02,100.0,1.0e-6,1.15};
      const double JETETA[4] = {-1.f,1.f,1.0e-3,1.15};
      const double JETPHI[4] = {-0.02,2*TMath::Pi(),1.0e-6,1.15};
      const double TRACKPT[4]={-0.02,100.0,1.0e-5,0.15};
      const double TRACKPTASJETPT[4]={-0.02,100.0,1.0e-5,1.0e-1};
      const double TRACKETA[4]={-1.f,1.f,1.0e-5,1.15};
      const double TRACKETAASJETPT[4]={-1.f,1.f,1.0e-7,0.1};
      const double TRACKPHI[4]={-0.02,2*TMath::Pi(),1.0e-4,0.1};
      const double TRACKPHIASJETPT[4]={-0.02,2*TMath::Pi(),1.0e-7,0.1};
      const double IPXY[4]={-400,400,1.0e-6,0.1};
      const double IPZ[4]={-400,400,1.0e-6,0.1};
      const double IPXYZ[4]={-600,600,1.0e-5,1.0};
      const double IPXYSIG[4]={-100,100,1.0e-6,1.2*0.1};
      //const double IPXYSIG[4]={-150,150,1.0e-6,1.2*0.1};
      const double IPXYSIG3x1[4]={-102,102,1.0e-6,1.2*0.1};
      const double IPZSIG[4]={-40,40,1.0e-6,0.1};
      const double IPXYZSIG[4]={-60,60,1.0e-6,0.1};
      const double JP[4]={-0.01,1.0,1.0e-5,1.0};
      const double LOGJP[4]={1.7*-0.1,1.02*20,1.0e-5,8.0*1};
      const double RAWLOGJP[4]={6.0*-0.1,1.02*20,6,0.8*1.0e+8};
      const double LXY[4]={-0.01,10.0,2*1.0e-6,1.2};
      const double SXY[4]={-0.01,100,0.2*1.0e-4,1.2*10};
      //const double SXY[4]={-0.01,300,0.2*1.0e-4,0.01};
      //const double SXY[4]={0,500,0.2*1.0e-5,1.2*10};
      const double LXYZ[4]={-0.01,10.0,0.6*1.0e-5,1.2};
      const double SXYZ[4]={-0.01,100,0.6*1.0e-5,1.2};
      const double SIGMALXY[4]={-0.01,0.1,0.6*1.0e-8,1.0};
      const double SIGMALXYZ[4]={-0.01,0.1,0.6*1.0e-7,1.0};
      const double CHI2[4]={-0.01, 100, 1.0e-7, 10.0};
      const double MASS[4]={-0.01,5,0.6*1.0e-4,1.2*10};
      const double RAWLXY[4]={-0.01,10,1e-1,1e+6};
      const double RAWLXYZ[4]={-0.01,10,1e-1,1e+6};
      const double RAWSIGMALXY[4]={-0.01,0.1,1e-1,1e+6};
      const double RAWSIGMALXYZ[4]={-0.01,0.1,1e-1,1e+6};
      const double RAWSXY[4]={-0.01,200,1e-1,1e+6};
      const double RAWSXYZ[4]={-0.01,100,1e-1,1e+6};

      const double EFFI[4] = {-0.02, 100.0, 0, 1.6};
      const double PURITY[4] = {-0.02, 100.0, 0, 1.5};

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
  namespace NOM { // xmin, xmax: integral range
    const double LXY[2] = {0, 100};
    const double SIGMALXY[2] = {0, 0.05};
    const double SXY[2] = {0, 100};
    const double LXYZ[2] = {0, 100};
    const double SIGMALXYZ[2] = {0, 0.05};
    const double SXYZ[2] = {0, 100};
    

  }
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

