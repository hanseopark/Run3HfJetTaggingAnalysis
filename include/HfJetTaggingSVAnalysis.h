#ifndef HFJETTAGGINGSVANALYSIS_H
#define HFJETTAGGINGSVANALYSIS_H

#include <iostream>
#include <tuple>
#include <TH1D.h>
#include <TString.h>
#include "HfJetTaggingAnalysis.h"

// for RooFit
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"

class HfJetTaggingSVAnalysis : public HfJetTaggingAnalysis {
  public:
    HfJetTaggingSVAnalysis() : HfJetTaggingAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSVAnalysis();

    // function
    /// basic
    void initConfig();

    // sv hist
    ///data
    int loadDataSV(TString rootData);
    void initHistSVData();
    void projectionHistSVData();
    void rebinHistSVData();
    void initSVData(TString rootData);

    /// mc
    int loadSimSV(TString rootSim);
    void initHistSVMC();
    void projectionHistSVMC();
    void rebinHistSVMC();
    void initSVMC(TString rootData);

    void saveHistogramSVQA(TString rootfile, bool doSys);
    

    // Set
    void setFill2Prong(bool fill2Prong);
    void setFill3Prong(bool fill3Prong);
    void setFillN1(bool fillN1);
    void setFillEffi(bool fillEffi);
    void setFillEffiWithIP(bool fillEffiWithIP);
    void setData3ProngPurity(const float cutSxy);
    void setSim3ProngEffiDirect(const float cutSxy);
    void setSim3ProngPurityDirect(const float cutSxy);
    void setSim3ProngEffiTagged(const float cutSxy);
    void setSim3ProngPurityTagged(const float cutSxy);

    // Draw
    CanvasHandler* canHan;
    // Data 2-prongs
    void drawData2ProngLxy(bool doLog, int binJetPt);
    void drawData2ProngLxyz(bool doLog, int binJetPt);
    void drawData2ProngSxy(bool doLog, int binJetPt);
    void drawData2ProngSxyz(bool doLog, int binJetPt);
    void drawData2ProngsigmaLxy(bool doLog, int binJetPt);
    void drawData2ProngsigmaLxyz(bool doLog, int binJetPt);
    void drawDatataggedjet2ProngEffiMassN1(const float cutSxy);
    void drawDatataggedjet2ProngPurityMassN1(const float cutSxy);

    // Data 3-prongs
    void drawData3ProngLxy(bool doLog, int binJetPt);
    void drawData3ProngLxyz(bool doLog, int binJetPt);
    void drawData3ProngSxy(bool doLog, int binJetPt);
    void drawData3ProngSxyz(bool doLog, int binJetPt);
    void drawData3ProngsigmaLxy(bool doLog, int binJetPt);
    void drawData3ProngsigmaLxyz(bool doLog, int binJetPt);
    void drawData3ProngSxyN1(bool doLog, int binJetPt);
    void drawData3ProngSxyzN1(bool doLog, int binJetPt);
    void drawData3ProngMassN1(bool doLog, int binJetPt);
    void drawDatataggedjet3ProngMassN1(bool doLog, int binJetPt);
    void drawDatataggedjet3ProngEffiMassN1(const float cutSxy);
    void drawDatataggedjet3ProngPurityMassN1(const float cutSxy);
    void drawDataSV3ProngCrossSection(bool doLog, int n_iter, int n_reg);
    void drawDataSV3ProngCrossSectionWithSys(bool loadExtSys, bool withSys);
    void drawDataSV3ProngFlavourFraction();

    // MC 2-prongs
    void drawSim2ProngLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngSxy(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngSxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim2ProngEffiSxyN1(const float cutSxy);
    void drawSim2ProngEffiSxyzN1(const float cutSxyz);
    void drawSim2ProngEffiSxyN1Tagger(int binJetPt);
    void drawSim2ProngPuritySxyN1(const float cutSxy);
    void drawSim2ProngPuritySxyzN1(const float cutSxyz);
    void drawSim2ProngPuritySxyN1Tagger(int binJetPt);
    void drawSim2ProngEffiAndPuritySxyN1(const float custSxy);

    // MC 3-prongs
    void drawSim3ProngLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngEffiSxyN1(const float cutSxy);
    void drawSim3ProngEffiSxyN1wSys();
    void drawSim3ProngEffiSxyzN1(const float cutSxyz);
    void drawSim3ProngEffiSxyN1WithIP(const float cutSxy);
    void drawSim3ProngEffiSxyzN1WithIP(const float cutSxyz);
    void drawSim3ProngPuritySxyN1(const float cutSxy);
    void drawSim3ProngPuritySxyN1wSys();
    void drawSim3ProngPuritySxyzN1(const float cutSxyz);
    void drawSim3ProngPuritySxyN1WithIP(const float cutSxy);
    void drawSim3ProngPuritySxyzN1WithIP(const float cutSxyz);
    void drawSim3ProngEffiSxyN1Tagger(int binJetPt);
    void drawSim3ProngPuritySxyN1Tagger(int binJetPt);
    void drawSim3ProngEffiAndPuritySxyN1(const float custSxy);
    void drawSimtaggedjet3ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSimtaggedjet3ProngSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSimtaggedjet3ProngMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSimtaggedjet3ProngEffiMassN1(const float cutSxy);
    void drawSimtaggedjet3ProngPurityMassN1(const float cutSxy);
    void drawSimSV3ProngCrossSection(bool doLog);
    void drawSimSV3ProngFlavourFraction();

    // DataVsMC 2-Prongs
    void drawDataVsSim2ProngLxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngLxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngSxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngSxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngsigmaLxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngsigmaLxyz(bool doLog, int binJetPt);
    void drawDataVsSimtaggedjet2ProngEffiMassN1(const float cutSxy);
    void drawDataVsSimtaggedjet2ProngPurityMassN1(const float cutSxy);

    // DataVsMC 3-Prongs
    void drawDataVsSim3ProngLxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngLxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngsigmaLxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngsigmaLxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxyN1(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxyzN1(bool doLog, int binJetPt);
    void drawDataVsSim3ProngMassN1(bool doLog, int binJetPt);
    void drawDataVsSimtaggedjet3ProngMassN1(bool doLog, int binJetPt);
    void drawDataVsSimSV3ProngCrossSection(bool doLog);
    void drawDataVsSimSV3ProngFlavourFraction();

    // templtae fit
    void drawTemplateFitMCN1();
    void drawTemplateFitMCtaggedjetN1(const float cutSxy);

    void drawTemplateFitDataWithMCtaggedjetN1();
    void drawTemplateFitDataWithMCtaggedjetN1Dep();

    void unfoldingJetSV(bool doLog, int flavour);
    void closureTestSVMC(bool doLog);
    void closureTestSV(bool doLog);

    // systematic uncertainty
    void loadExtSys();
    void saveSys();
    void calSysTotal();
    void calSysTaggerPoint();
    void calSysSecondaryContamination();
    void calSysUnfolding();
    void calSysUnfoldingMethods();
    void calSysUnfoldingSvdParam();
    void drawDataSV3ProngSys(bool loadExtSys);
    void saveSVXSectionWithSys(TString rootfile, bool doSys);

    /*
    void calSys...();

    */

  protected:
    TH1F* hsimSVEffi2ProngSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi2ProngSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi2ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi2ProngSxyzN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity2ProngSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity2ProngSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity2ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity2ProngSxyzN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyN1wSys[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyzN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyTaggerPoint[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimSVPurity3ProngSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyN1wSys[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyzN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyTaggerPoint[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimSVEffiAndPurity3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjetSVEffi3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjetSVPurity3ProngSxyN1[HfJetTagging::nFlavour+1];

    // hist from root (Data)
    TH2F* h2datajetPt2ProngLxy;
    TH2F* h2datajetPt2ProngLxyz;
    TH2F* h2datajetPt2ProngSxy;
    TH2F* h2datajetPt2ProngSxyz;
    TH2F* h2datajetPt2ProngsigmaLxy;
    TH2F* h2datajetPt2ProngsigmaLxyz;
    TH2F* h2datajet2ProngSxysigmaLxy;
    TH2F* h2datajet2ProngSxyzsigmaLxyz;
    TH2F* h2datajetPt2ProngSxyN1;
    TH2F* h2datajetPt2ProngSxyzN1;
    TH2F* h2datajetPt2ProngMassN1;
    TH2F* h2datataggedjetPt2ProngSxyN1;
    TH2F* h2datataggedjetPt2ProngSxyzN1;
    TH2F* h2datataggedjetPt2ProngMassN1;

    TH2F* h2datajetPt3ProngLxy;
    TH2F* h2datajetPt3ProngLxyz;
    TH2F* h2datajetPt3ProngSxy;
    TH2F* h2datajetPt3ProngSxyz;
    TH2F* h2datajetPt3ProngsigmaLxy;
    TH2F* h2datajetPt3ProngsigmaLxyz;
    TH2F* h2datajet3ProngSxysigmaLxy;
    TH2F* h2datajet3ProngSxyzsigmaLxyz;
    TH2F* h2datajetPt3ProngSxyN1;
    TH2F* h2datajetPt3ProngSxyzN1;
    TH2F* h2datajetPt3ProngMassN1;
    TH2F* h2datajetPt3ProngMassXyzN1;
    TH2F* h2datataggedjetPt3ProngSxyN1;
    TH2F* h2datataggedjetPt3ProngSxyzN1;
    TH2F* h2datataggedjetPt3ProngMassN1;
    TH2F* h2datataggedjetPt3ProngMassXyzN1;

    // hist (Data)
    /// 2prong
    TH1F* hdatajet2ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjet2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjet2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjet2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEvents2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJets2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormArea2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEvents2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJets2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormArea2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEvents2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJets2ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormArea2ProngMassN1[HfJetTagging::nBinsJetPt+1];

    TH1F* hdatataggedjetSVEffi2ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hdatataggedjetSVPurity2ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hdatajet2ProngRawYield;
    TH1F* hdatajet2ProngYieldEffiAndPurity;
    TH1F* hdatajet2ProngYieldEffiAndPurityUnfold;
    TH1F* hdatajet2ProngCrossSection;
    
    /// 3prong
    TH1F* hdatajet3ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajet3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjet3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjet3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjet3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEvents3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJets3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormArea3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEvents3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJets3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormArea3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEvents3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJets3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormArea3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNEvents3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormNJets3ProngMassN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatataggedjetNormArea3ProngMassN1[HfJetTagging::nBinsJetPt+1];

    TH1F* hdatataggedjetSVEffi3ProngSxyN1woTemplateFit[HfJetTagging::nFlavour+1];
    TH1F* hdatataggedjetSVEffi3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hdatataggedjetSVPurity3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hdatajet3ProngFlavourFraction[HfJetTagging::nFlavour+1];
    TH1F* hdatataggedjetSVFlavourFraction[HfJetTagging::nFlavour+1];
    TH1F* hdatajet3ProngRawYield;
    TH1F* hdatajet3ProngNormYield;
    TH1F* hdatajet3ProngYieldEffiAndPurity;
    TH1F* hdatajet3ProngUnfoldedBayesYieldEffiAndPurity;
    TH1F* hdatajet3ProngUnfoldedSvdYieldEffiAndPurity;
    TH1F* hdatajet3ProngCrossSection;
    TH1F* hdatajet3ProngCrossSectionwoUnfold;
    TH1F* hdatajet3ProngCrossSectionFromBayes;
    TH1F* hdatajet3ProngCrossSectionFromMCEffiAndPurity;
    TGraphAsymmErrors* grdatajet3ProngXSection;
    TGraphAsymmErrors* grdatajet3ProngXSectionSys;
    TGraphAsymmErrors* grdatajet3ProngXSectionSysUnfolding;
    TGraphAsymmErrors* grsysSVUnfoldingParam;
    TGraphAsymmErrors* grsysSVUnfoldingMethods;
    TGraphAsymmErrors* grsysSVUnfolding;

    // hist from root (MC)
    TH3F* h3simjetPt2ProngLxyFlavour;
    TH3F* h3simjetPt2ProngLxyzFlavour;
    TH3F* h3simjetPt2ProngSxyFlavour;
    TH3F* h3simjetPt2ProngSxyzFlavour;
    TH3F* h3simjetPt2ProngsigmaLxyFlavour;
    TH3F* h3simjetPt2ProngsigmaLxyzFlavour;
    TH3F* h3simjet2ProngSxysigmaLxyFlavour;
    TH3F* h3simjet2ProngSxyzsigmaLxyzFlavour;
    TH3F* h3simjetPt2ProngSxyN1Flavour;
    TH3F* h3simjetPt2ProngSxyzN1Flavour;
    TH3F* h3simjetPt2ProngMassN1Flavour;
    TH3F* h3simjetPt2ProngChi2Flavour;

    TH3F* h3simjetPt3ProngLxyFlavour;
    TH3F* h3simjetPt3ProngLxyzFlavour;
    TH3F* h3simjetPt3ProngSxyFlavour;
    TH3F* h3simjetPt3ProngSxyzFlavour;
    TH3F* h3simjetPt3ProngsigmaLxyFlavour;
    TH3F* h3simjetPt3ProngsigmaLxyzFlavour;
    TH3F* h3simjet3ProngSxysigmaLxyFlavour;
    TH3F* h3simjet3ProngSxyzsigmaLxyzFlavour;
    TH3F* h3simjetPt3ProngSxyN1Flavour;
    TH3F* h3simjetPt3ProngSxyzN1Flavour;
    TH3F* h3simjetPt3ProngMassN1Flavour;
    TH3F* h3simtaggedjetPt3ProngSxyN1Flavour;
    TH3F* h3simtaggedjetPt3ProngSxyzN1Flavour;
    TH3F* h3simtaggedjetPt3ProngMassN1Flavour;
    TH3F* h3simjetPt3ProngChi2Flavour;

    // hist (MC)
    TH1F* hsimjet2ProngPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjet2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet2ProngChi2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjet3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjet3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjet3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjet3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjet3ProngPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjet3ProngRawYield[HfJetTagging::nFlavour+1];
    TH1F* hsimjet3ProngNormYield[HfJetTagging::nFlavour+1];
    TH1F* hsimjet3ProngNormYieldEffiAndPurity[HfJetTagging::nFlavour+1];
    TH1F* hsimjet3ProngNormYieldEffiAndPurityUnfold[HfJetTagging::nFlavour+1];
    TH1F* hsimjet3ProngCrossSection[HfJetTagging::nFlavour+1];
    TH1F* hsimjet3ProngFlavourFraction[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjet3ProngFlavourFraction[HfJetTagging::nFlavour+1];

    TH1F* hsimjetNormNEvents2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEvents2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJets2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormArea2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEvents2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJets2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormArea2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEvents2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJets2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormArea2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjetNormNEvents3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEvents3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJets3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormArea3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEvents3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJets3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormArea3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEvents3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJets3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormArea3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNEvents3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormNJets3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormArea3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    // for systematic uncertaitny
    TH1F* hsysSVTotal;
    TH1F* hsysSVTaggerPoint;
    TH1F* hsysSVSecondaryContamination;
    TH1F* hsysSVUnfolding;
    TH1F* hsysSVUnfoldingMethods;
    TH1F* hsysSVUnfoldingBayesParam;
    TH1F* hsysSVUnfoldingSvdParam;
    TH1F* hsysSVUnfoldingPer;
    TH1F* hsysSVUnfoldingPerMethods;
    TH1F* hsysSVUnfoldingPerBayesParam;
    TH1F* hsysSVUnfoldingPerSvdParam;

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;
    bool fill2Prong = false;
    bool fill3Prong = false;
    bool fillN1 = false;
    bool fillEffi = false;
    bool fillEffiWithIP = false;
};

HfJetTaggingSVAnalysis::~HfJetTaggingSVAnalysis() {
  if (h3simjetPt2ProngLxyFlavour) delete h3simjetPt2ProngLxyFlavour;
  if (h3simjetPt2ProngLxyzFlavour) delete h3simjetPt2ProngLxyzFlavour;
  if (h3simjetPt2ProngSxyFlavour) delete h3simjetPt2ProngSxyFlavour;
  if (h3simjetPt2ProngSxyzFlavour) delete h3simjetPt2ProngSxyzFlavour;
  if (h3simjetPt2ProngsigmaLxyFlavour) delete h3simjetPt2ProngsigmaLxyFlavour;
  if (h3simjetPt2ProngsigmaLxyzFlavour) delete h3simjetPt2ProngsigmaLxyzFlavour;
  if (h3simjetPt3ProngLxyFlavour) delete h3simjetPt3ProngLxyFlavour;
  if (h3simjetPt3ProngLxyzFlavour) delete h3simjetPt3ProngLxyzFlavour;
  if (h3simjetPt3ProngSxyFlavour) delete h3simjetPt3ProngSxyFlavour;
  if (h3simjetPt3ProngSxyzFlavour) delete h3simjetPt3ProngSxyzFlavour;
  if (h3simjet2ProngSxysigmaLxyFlavour) delete h3simjet2ProngSxysigmaLxyFlavour;
  if (h3simjet2ProngSxyzsigmaLxyzFlavour) delete h3simjet2ProngSxyzsigmaLxyzFlavour;

  for (int flavour = 0; flavour < HfJetTagging::nFlavour + 1; ++flavour) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt + 1; ++jetPt) {
      if (hsimjet2ProngLxy[flavour][jetPt]) delete hsimjet2ProngLxy[flavour][jetPt];
      if (hsimjet2ProngLxyz[flavour][jetPt]) delete hsimjet2ProngLxyz[flavour][jetPt];
      if (hsimjet2ProngSxy[flavour][jetPt]) delete hsimjet2ProngSxy[flavour][jetPt];
      if (hsimjet2ProngSxyz[flavour][jetPt]) delete hsimjet2ProngSxyz[flavour][jetPt];
      if (hsimjet2ProngsigmaLxy[flavour][jetPt]) delete hsimjet2ProngsigmaLxy[flavour][jetPt];
      if (hsimjet2ProngsigmaLxyz[flavour][jetPt]) delete hsimjet2ProngsigmaLxyz[flavour][jetPt];
      if (hsimjet3ProngLxy[flavour][jetPt]) delete hsimjet3ProngLxy[flavour][jetPt];
      if (hsimjet3ProngLxyz[flavour][jetPt]) delete hsimjet3ProngLxyz[flavour][jetPt];
      if (hsimjet3ProngSxy[flavour][jetPt]) delete hsimjet3ProngSxy[flavour][jetPt];
      if (hsimjet3ProngSxyz[flavour][jetPt]) delete hsimjet3ProngSxyz[flavour][jetPt];
    }
  }
}

void HfJetTaggingSVAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  TString dirFig = "fig";
  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  } 

  //TString dirData = Form("fig/data/%s/sv", TRIGGERNAME.Data());
  //gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  dirData = Form("%s/%s/data/%s/sv", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/sv", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  dirDataVsSim = Form("%s/%s/dataVSsim/%s_%s/sv", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(Form("%s/taggedjet", dirData.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/taggedjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/taggedjet", dirDataVsSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
                                                                    //gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSVAnalysis::loadDataSV(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, SV QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";
  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  if (fillData && fill2Prong) {
    h2datajetPt2ProngLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Lxy", taskName.Data())));
    h2datajetPt2ProngLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Lxyz", taskName.Data())));
    h2datajetPt2ProngSxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxy", taskName.Data())));
    h2datajetPt2ProngSxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxyz", taskName.Data())));
    h2datajetPt2ProngsigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_sigmaLxy", taskName.Data())));
    h2datajetPt2ProngsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_sigmaLxyz", taskName.Data())));
    h2datajet2ProngSxysigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_2prong_Sxy_sigmaLxy", taskName.Data())));
    h2datajet2ProngSxyzsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_2prong_Sxyz_sigmaLxyz", taskName.Data())));
    h2datajetPt2ProngLxy->Sumw2();
    if (fillN1) {
      h2datajetPt2ProngSxyN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxy_N1", taskName.Data())));
      h2datajetPt2ProngSxyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxyz_N1", taskName.Data())));
      h2datajetPt2ProngMassN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_mass_N1", taskName.Data())));
      h2datataggedjetPt2ProngSxyN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_2prong_Sxy_N1", taskName.Data())));
      h2datataggedjetPt2ProngSxyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_2prong_Sxyz_N1", taskName.Data())));
      h2datataggedjetPt2ProngMassN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_2prong_mass_N1", taskName.Data())));
    }
  }
  if (fillData && fill3Prong) {
    h2datajetPt3ProngLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Lxy", taskName.Data())));
    h2datajetPt3ProngLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Lxyz", taskName.Data())));
    h2datajetPt3ProngSxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxy", taskName.Data())));
    h2datajetPt3ProngSxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxyz", taskName.Data())));
    h2datajetPt3ProngsigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_sigmaLxy", taskName.Data())));
    h2datajetPt3ProngsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_sigmaLxyz", taskName.Data())));
    h2datajet3ProngSxysigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_3prong_Sxy_sigmaLxy", taskName.Data())));
    h2datajet3ProngSxyzsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_3prong_Sxyz_sigmaLxyz", taskName.Data())));
    h2datajetPt3ProngLxy->Sumw2();
    h2datajetPt3ProngLxyz->Sumw2();
    h2datajetPt3ProngSxy->Sumw2();
    h2datajetPt3ProngSxyz->Sumw2();
    h2datajetPt3ProngsigmaLxy->Sumw2();
    h2datajetPt3ProngsigmaLxyz->Sumw2();
    //h2datajet3ProngSxysigmaLxy->Sumw2();
    //h2datajet3ProngSxyzsigmaLxyz->Sumw2();
    if (fillN1) {
      h2datajetPt3ProngSxyN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxy_N1", taskName.Data())));
      h2datajetPt3ProngSxyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxyz_N1", taskName.Data())));
      h2datajetPt3ProngMassN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_mass_N1", taskName.Data())));
      h2datajetPt3ProngMassXyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_mass_xyz_N1", taskName.Data())));
      h2datataggedjetPt3ProngSxyN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_3prong_Sxy_N1", taskName.Data())));
      h2datataggedjetPt3ProngSxyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_3prong_Sxyz_N1", taskName.Data())));
      h2datataggedjetPt3ProngMassN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_3prong_mass_N1", taskName.Data())));
      h2datataggedjetPt3ProngMassXyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_taggedjet_pt_3prong_mass_xyz_N1", taskName.Data())));
      h2datajetPt3ProngSxyN1->Sumw2();
      h2datajetPt3ProngSxyzN1->Sumw2();
      h2datajetPt3ProngMassN1->Sumw2();
      h2datajetPt3ProngMassXyzN1->Sumw2();
      h2datataggedjetPt3ProngSxyN1->Sumw2();
      h2datataggedjetPt3ProngSxyzN1->Sumw2();
      h2datataggedjetPt3ProngMassN1->Sumw2();
      h2datataggedjetPt3ProngMassXyzN1->Sumw2();
    }
  }
  std::cout << "Load completed SV data" << std::endl;
  return 1;
}

void HfJetTaggingSVAnalysis::initHistSVData() {
  if (fillData && fill2Prong) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hdatajet2ProngLxy[jetPt] = new TH1F(Form("hdatajet2ProngLxy_%d", jetPt), "", h2datajetPt2ProngLxy->GetNbinsY(), h2datajetPt2ProngLxy->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngLxy->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngLxy->GetNbinsY()));
      hdatajet2ProngLxyz[jetPt] = new TH1F(Form("hdatajet2ProngLxyz_%d", jetPt), "", h2datajetPt2ProngLxyz->GetNbinsY(), h2datajetPt2ProngLxyz->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngLxyz->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngLxyz->GetNbinsY()));
      hdatajet2ProngSxy[jetPt] = new TH1F(Form("hdatajet2ProngSxy_%d", jetPt), "", h2datajetPt2ProngSxy->GetNbinsY(), h2datajetPt2ProngSxy->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngSxy->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngSxy->GetNbinsY()));
      hdatajet2ProngSxyz[jetPt] = new TH1F(Form("hdatajet2ProngSxyz_%d", jetPt), "", h2datajetPt2ProngSxyz->GetNbinsY(), h2datajetPt2ProngSxyz->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngSxyz->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngSxyz->GetNbinsY()));
      hdatajet2ProngsigmaLxy[jetPt] = new TH1F(Form("hdatajet2ProngsigmaLxy_%d", jetPt), "", h2datajetPt2ProngsigmaLxy->GetNbinsY(), h2datajetPt2ProngsigmaLxy->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngsigmaLxy->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngsigmaLxy->GetNbinsY()));
      hdatajet2ProngsigmaLxyz[jetPt] = new TH1F(Form("hdatajet2ProngsigmaLxyz_%d", jetPt), "", h2datajetPt2ProngsigmaLxyz->GetNbinsY(), h2datajetPt2ProngsigmaLxyz->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngsigmaLxyz->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngsigmaLxyz->GetNbinsY()));
      if (fillN1) {
        hdatajet2ProngSxyN1[jetPt] = new TH1F(Form("hdatajet2ProngSxyN1_%d", jetPt), "", h2datajetPt2ProngSxyN1->GetNbinsY(), h2datajetPt2ProngSxyN1->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngSxyN1->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngSxyN1->GetNbinsY()));
        hdatajet2ProngSxyzN1[jetPt] = new TH1F(Form("hdatajet2ProngSxyzN1_%d", jetPt), "", h2datajetPt2ProngSxyzN1->GetNbinsY(), h2datajetPt2ProngSxyzN1->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngSxyzN1->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngSxyzN1->GetNbinsY()));
        hdatajet2ProngMassN1[jetPt] = new TH1F(Form("hdatajet2ProngMassN1_%d", jetPt), "", h2datajetPt2ProngMassN1->GetNbinsY(), h2datajetPt2ProngMassN1->GetYaxis()->GetBinLowEdge(1), h2datajetPt2ProngMassN1->GetYaxis()->GetBinUpEdge(h2datajetPt2ProngMassN1->GetNbinsY()));
        hdatataggedjet2ProngSxyN1[jetPt] = new TH1F(Form("hdatataggedjet2ProngSxyN1_%d", jetPt), "", h2datataggedjetPt2ProngSxyN1->GetNbinsY(), h2datataggedjetPt2ProngSxyN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPt2ProngSxyN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPt2ProngSxyN1->GetNbinsY()));
        hdatataggedjet2ProngSxyzN1[jetPt] = new TH1F(Form("hdatataggedjet2ProngSxyzN1_%d", jetPt), "", h2datataggedjetPt2ProngSxyzN1->GetNbinsY(), h2datataggedjetPt2ProngSxyzN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPt2ProngSxyzN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPt2ProngSxyzN1->GetNbinsY()));
        hdatataggedjet2ProngMassN1[jetPt] = new TH1F(Form("hdatataggedjet2ProngMassN1_%d", jetPt), "", h2datataggedjetPt2ProngMassN1->GetNbinsY(), h2datataggedjetPt2ProngMassN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPt2ProngMassN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPt2ProngMassN1->GetNbinsY()));
      }
    }
  }
  if (fillData && fill3Prong) {
    hdatajet3ProngRawYield = new TH1F("hdatajet3ProngRawYield", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngRawYield->Sumw2();
    hdatajet3ProngYieldEffiAndPurity = new TH1F("hdatajet3ProngYieldEffiAndPurity", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngUnfoldedBayesYieldEffiAndPurity = new TH1F("hdatajet3ProngUnfoldedBayesYieldEffiAndPurity", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngUnfoldedSvdYieldEffiAndPurity = new TH1F("hdatajet3ProngUnfoldedSvdYieldEffiAndPurity", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngCrossSection = new TH1F("hdatajet3ProngCrossSection", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngCrossSectionwoUnfold = new TH1F("hdatajet3ProngCrossSectionwoUnfold", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngCrossSectionFromBayes = new TH1F("hdatajet3ProngCrossSectionFromBayes", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    hdatajet3ProngCrossSectionFromMCEffiAndPurity = new TH1F("hdatajet3ProngCrossSectionFromMCEffiAndPurity", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hdatataggedjetSVEffi3ProngSxyN1woTemplateFit[flavour] = new TH1F(Form("hdatataggedjetSVEffi3ProngSxyN1woTemplateFit_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hdatataggedjetSVEffi3ProngSxyN1[flavour] = new TH1F(Form("hdatataggedjetSVEffi3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hdatataggedjetSVEffi3ProngSxyN1[flavour]->Sumw2();
      hdatataggedjetSVPurity3ProngSxyN1[flavour] = new TH1F(Form("hdatataggedjetSVPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hdatataggedjetSVPurity3ProngSxyN1[flavour]->Sumw2();
      hdatajet3ProngFlavourFraction[flavour] = new TH1F(Form("hdatajet3ProngFlavourFraction_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
    }
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hdatajet3ProngLxy[jetPt] = new TH1F(Form("hdatajet3ProngLxy_%d", jetPt), "", h2datajetPt3ProngLxy->GetNbinsY(), h2datajetPt3ProngLxy->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngLxy->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngLxy->GetNbinsY()));
      hdatajet3ProngLxyz[jetPt] = new TH1F(Form("hdatajet3ProngLxyz_%d", jetPt), "", h2datajetPt3ProngLxyz->GetNbinsY(), h2datajetPt3ProngLxyz->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngLxyz->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngLxyz->GetNbinsY()));
      hdatajet3ProngSxy[jetPt] = new TH1F(Form("hdatajet3ProngSxy_%d", jetPt), "", h2datajetPt3ProngSxy->GetNbinsY(), h2datajetPt3ProngSxy->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngSxy->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngSxy->GetNbinsY()));
      hdatajet3ProngSxyz[jetPt] = new TH1F(Form("hdatajet3ProngSxyz_%d", jetPt), "", h2datajetPt3ProngSxyz->GetNbinsY(), h2datajetPt3ProngSxyz->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngSxyz->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngSxyz->GetNbinsY()));
      hdatajet3ProngsigmaLxy[jetPt] = new TH1F(Form("hdatajet3ProngsigmaLxy_%d", jetPt), "", h2datajetPt3ProngsigmaLxy->GetNbinsY(), h2datajetPt3ProngsigmaLxy->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngsigmaLxy->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngsigmaLxy->GetNbinsY()));
      hdatajet3ProngsigmaLxyz[jetPt] = new TH1F(Form("hdatajet3ProngsigmaLxyz_%d", jetPt), "", h2datajetPt3ProngsigmaLxyz->GetNbinsY(), h2datajetPt3ProngsigmaLxyz->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngsigmaLxyz->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngsigmaLxyz->GetNbinsY()));
      if (fillN1) {
        hdatajet3ProngSxyN1[jetPt] = new TH1F(Form("hdatajet3ProngSxyN1_%d", jetPt), "", h2datajetPt3ProngSxyN1->GetNbinsY(), h2datajetPt3ProngSxyN1->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngSxyN1->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngSxyN1->GetNbinsY()));
        hdatajet3ProngSxyzN1[jetPt] = new TH1F(Form("hdatajet3ProngSxyzN1_%d", jetPt), "", h2datajetPt3ProngSxyzN1->GetNbinsY(), h2datajetPt3ProngSxyzN1->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngSxyzN1->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngSxyzN1->GetNbinsY()));
        hdatajet3ProngMassN1[jetPt] = new TH1F(Form("hdatajet3ProngMassN1_%d", jetPt), "", h2datajetPt3ProngMassN1->GetNbinsY(), h2datajetPt3ProngMassN1->GetYaxis()->GetBinLowEdge(1), h2datajetPt3ProngMassN1->GetYaxis()->GetBinUpEdge(h2datajetPt3ProngMassN1->GetNbinsY()));
        hdatataggedjet3ProngSxyN1[jetPt] = new TH1F(Form("hdatataggedjet3ProngSxyN1_%d", jetPt), "", h2datataggedjetPt3ProngSxyN1->GetNbinsY(), h2datataggedjetPt3ProngSxyN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPt3ProngSxyN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPt3ProngSxyN1->GetNbinsY()));
        hdatataggedjet3ProngSxyzN1[jetPt] = new TH1F(Form("hdatataggedjet3ProngSxyzN1_%d", jetPt), "", h2datataggedjetPt3ProngSxyzN1->GetNbinsY(), h2datataggedjetPt3ProngSxyzN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPt3ProngSxyzN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPt3ProngSxyzN1->GetNbinsY()));
        hdatataggedjet3ProngMassN1[jetPt] = new TH1F(Form("hdatataggedjet3ProngMassN1_%d", jetPt), "", h2datataggedjetPt3ProngMassN1->GetNbinsY(), h2datataggedjetPt3ProngMassN1->GetYaxis()->GetBinLowEdge(1), h2datataggedjetPt3ProngMassN1->GetYaxis()->GetBinUpEdge(h2datataggedjetPt3ProngMassN1->GetNbinsY()));
      }
    }
  }
}

void HfJetTaggingSVAnalysis::projectionHistSVData() {
  if (fillData && fill2Prong) {
    TH1F* proj2ProngLxy = reinterpret_cast<TH1F*> (h2datajetPt2ProngLxy->ProjectionY("proj2ProngLxy", 1, h2datajetPt2ProngLxy->GetNbinsX()));
    TH1F* proj2ProngLxyz = reinterpret_cast<TH1F*> (h2datajetPt2ProngLxyz->ProjectionY("proj2ProngLxyz", 1, h2datajetPt2ProngLxyz->GetNbinsX()));
    TH1F* proj2ProngSxy = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxy->ProjectionY("proj2ProngSxy", 1, h2datajetPt2ProngSxy->GetNbinsX()));
    TH1F* proj2ProngSxyz = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxyz->ProjectionY("proj2ProngSxyz", 1, h2datajetPt2ProngSxyz->GetNbinsX()));
    TH1F* proj2ProngsigmaLxy = reinterpret_cast<TH1F*> (h2datajetPt2ProngsigmaLxy->ProjectionY("proj2ProngsigmaLxy", 1, h2datajetPt2ProngsigmaLxy->GetNbinsX()));
    TH1F* proj2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2datajetPt2ProngsigmaLxyz->ProjectionY("proj2ProngsigmaLxyz", 1, h2datajetPt2ProngsigmaLxyz->GetNbinsX()));

    hdatajet2ProngLxy[0] = reinterpret_cast<TH1F*>(proj2ProngLxy->Clone("hdatajet2ProngLxy_0"));
    hdatajet2ProngLxyz[0] = reinterpret_cast<TH1F*>(proj2ProngLxyz->Clone("hdatajet2ProngLxyz_0"));
    hdatajet2ProngSxy[0] = reinterpret_cast<TH1F*>(proj2ProngSxy->Clone("hdatajet2ProngSxy_0"));
    hdatajet2ProngSxyz[0] = reinterpret_cast<TH1F*>(proj2ProngSxyz->Clone("hdatajet2ProngSxyz_0"));
    hdatajet2ProngsigmaLxy[0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxy->Clone("hdatajet2ProngsigmaLxy_0"));
    hdatajet2ProngsigmaLxyz[0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyz->Clone("hdatajet2ProngsigmaLxyz_0"));

    if (fillN1) {
      TH1F* proj2ProngSxyN1 = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxyN1->ProjectionY("proj2ProngSxyN1", 1, h2datajetPt2ProngSxyN1->GetNbinsX()));
      TH1F* proj2ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxyzN1->ProjectionY("proj2ProngSxyzN1", 1, h2datajetPt2ProngSxyzN1->GetNbinsX()));
      TH1F* proj2ProngMassN1 = reinterpret_cast<TH1F*> (h2datajetPt2ProngMassN1->ProjectionY("proj2ProngMassN1", 1, h2datajetPt2ProngMassN1->GetNbinsX()));
      TH1F* projtaggedjet2ProngSxyN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt2ProngSxyN1->ProjectionY("projtaggedjet2ProngSxyN1", 1, h2datataggedjetPt2ProngSxyN1->GetNbinsX()));
      TH1F* projtaggedjet2ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt2ProngSxyzN1->ProjectionY("projtaggedjet2ProngSxyzN1", 1, h2datataggedjetPt2ProngSxyzN1->GetNbinsX()));
      TH1F* projtaggedjet2ProngMassN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt2ProngMassN1->ProjectionY("projtaggedjet2ProngMassN1", 1, h2datataggedjetPt2ProngMassN1->GetNbinsX()));
      hdatajet2ProngSxyN1[0] = reinterpret_cast<TH1F*>(proj2ProngSxyN1->Clone("hdatajet2ProngSxyN1_0"));
      hdatajet2ProngSxyzN1[0] = reinterpret_cast<TH1F*>(proj2ProngSxyzN1->Clone("hdatajet2ProngSxyzN1_0"));
      hdatajet2ProngMassN1[0] = reinterpret_cast<TH1F*>(proj2ProngMassN1->Clone("hdatajet2ProngMassN1_0"));
      hdatataggedjet2ProngSxyN1[0] = reinterpret_cast<TH1F*>(proj2ProngSxyN1->Clone("hdatataggedjet2ProngSxyN1_0"));
      hdatataggedjet2ProngSxyzN1[0] = reinterpret_cast<TH1F*>(proj2ProngSxyzN1->Clone("hdatataggedjet2ProngSxyzN1_0"));
      hdatataggedjet2ProngMassN1[0] = reinterpret_cast<TH1F*>(proj2ProngMassN1->Clone("hdatataggedjet2ProngMassN1_0"));
    }
    for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      int leftbinJetPt2ProngLxy = h2datajetPt2ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngLxy = h2datajetPt2ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngLxy = reinterpret_cast<TH1F*> (h2datajetPt2ProngLxy->ProjectionY(Form("projJetPtRange2ProngLxy_%d", binJetPt), leftbinJetPt2ProngLxy, rightbinJetPt2ProngLxy));
      hdatajet2ProngLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxy->Clone(Form("hsimjet2ProngLxy_%d", binJetPt))); 

      int leftbinJetPt2ProngLxyz = h2datajetPt2ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngLxyz = h2datajetPt2ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngLxyz = reinterpret_cast<TH1F*> (h2datajetPt2ProngLxyz->ProjectionY(Form("projJetPtRange2ProngLxyz_%d", binJetPt), leftbinJetPt2ProngLxyz, rightbinJetPt2ProngLxyz));
      hdatajet2ProngLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxyz->Clone(Form("hsimjet2ProngLxyz_%d", binJetPt))); 

      int leftbinJetPt2ProngSxy = h2datajetPt2ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngSxy = h2datajetPt2ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngSxy = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxy->ProjectionY(Form("projJetPtRange2ProngSxy_%d", binJetPt), leftbinJetPt2ProngSxy, rightbinJetPt2ProngSxy));
      hdatajet2ProngSxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxy->Clone(Form("hsimjet2ProngSxy_%d", binJetPt))); 

      int leftbinJetPt2ProngSxyz = h2datajetPt2ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngSxyz = h2datajetPt2ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngSxyz = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxyz->ProjectionY(Form("projJetPtRange2ProngSxyz_%d", binJetPt), leftbinJetPt2ProngSxyz, rightbinJetPt2ProngSxyz));
      hdatajet2ProngSxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyz->Clone(Form("hsimjet2ProngSxyz_%d", binJetPt))); 

      int leftbinJetPt2ProngsigmaLxy = h2datajetPt2ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngsigmaLxy = h2datajetPt2ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngsigmaLxy = reinterpret_cast<TH1F*> (h2datajetPt2ProngsigmaLxy->ProjectionY(Form("projJetPtRange2ProngsigmaLxy_%d", binJetPt), leftbinJetPt2ProngsigmaLxy, rightbinJetPt2ProngsigmaLxy));
      hdatajet2ProngsigmaLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxy->Clone(Form("hsimjet2ProngsigmaLxy_%d", binJetPt))); 

      int leftbinJetPt2ProngsigmaLxyz = h2datajetPt2ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngsigmaLxyz = h2datajetPt2ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2datajetPt2ProngsigmaLxyz->ProjectionY(Form("projJetPtRange2ProngsigmaLxyz_%d", binJetPt), leftbinJetPt2ProngsigmaLxyz, rightbinJetPt2ProngsigmaLxyz));
      hdatajet2ProngsigmaLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxyz->Clone(Form("hsimjet2ProngsigmaLxyz_%d", binJetPt))); 

      if (fillN1) {
        int leftbinJetPt2ProngSxyN1 = h2datajetPt2ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngSxyN1 = h2datajetPt2ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngSxyN1 = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxyN1->ProjectionY(Form("projJetPtRange2ProngSxyN1_%d", binJetPt), leftbinJetPt2ProngSxyN1, rightbinJetPt2ProngSxyN1));
        hdatajet2ProngSxyN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyN1->Clone(Form("hdatajet2ProngSxyN1_%d", binJetPt))); 

        int leftbinJetPt2ProngSxyzN1 = h2datajetPt2ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngSxyzN1 = h2datajetPt2ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datajetPt2ProngSxyzN1->ProjectionY(Form("projJetPtRange2ProngSxyzN1_%d", binJetPt), leftbinJetPt2ProngSxyzN1, rightbinJetPt2ProngSxyzN1));
        hdatajet2ProngSxyzN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyzN1->Clone(Form("hdatajet2ProngSxyzN1_%d", binJetPt))); 

        int leftbinJetPt2ProngMassN1 = h2datajetPt2ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngMassN1 = h2datajetPt2ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngMassN1 = reinterpret_cast<TH1F*> (h2datajetPt2ProngMassN1->ProjectionY(Form("projJetPtRange2ProngMassN1_%d", binJetPt), leftbinJetPt2ProngMassN1, rightbinJetPt2ProngMassN1));
        hdatajet2ProngMassN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngMassN1->Clone(Form("hdatajet2ProngMassN1_%d", binJetPt))); 

        int leftbintaggedjetJetPt2ProngSxyN1 = h2datataggedjetPt2ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbintaggedjetJetPt2ProngSxyN1 = h2datataggedjetPt2ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projtaggedjetJetPtRange2ProngSxyN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt2ProngSxyN1->ProjectionY(Form("projJetPtRange2ProngSxyN1_%d", binJetPt), leftbintaggedjetJetPt2ProngSxyN1, rightbintaggedjetJetPt2ProngSxyN1));
        hdatataggedjet2ProngSxyN1[binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange2ProngSxyN1->Clone(Form("hdatataggedjet2ProngSxyN1_%d", binJetPt))); 

        int leftbintaggedjetJetPt2ProngSxyzN1 = h2datataggedjetPt2ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbintaggedjetJetPt2ProngSxyzN1 = h2datataggedjetPt2ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projtaggedjetJetPtRange2ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt2ProngSxyzN1->ProjectionY(Form("projJetPtRange2ProngSxyzN1_%d", binJetPt), leftbintaggedjetJetPt2ProngSxyzN1, rightbintaggedjetJetPt2ProngSxyzN1));
        hdatataggedjet2ProngSxyzN1[binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange2ProngSxyzN1->Clone(Form("hdatataggedjet2ProngSxyzN1_%d", binJetPt))); 

        int leftbintaggedjetJetPt2ProngMassN1 = h2datataggedjetPt2ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbintaggedjetJetPt2ProngMassN1 = h2datataggedjetPt2ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projtaggedjetJetPtRange2ProngMassN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt2ProngMassN1->ProjectionY(Form("projJetPtRange2ProngMassN1_%d", binJetPt), leftbintaggedjetJetPt2ProngMassN1, rightbintaggedjetJetPt2ProngMassN1));
        hdatataggedjet2ProngMassN1[binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange2ProngMassN1->Clone(Form("hdatataggedjet2ProngMassN1_%d", binJetPt))); 
      }
    }
  }
  if (fillData && fill3Prong) {
    TH1F* proj3ProngLxy = reinterpret_cast<TH1F*> (h2datajetPt3ProngLxy->ProjectionY("proj3ProngLxy", 1, h2datajetPt3ProngLxy->GetNbinsX()));
    TH1F* proj3ProngLxyz = reinterpret_cast<TH1F*> (h2datajetPt3ProngLxyz->ProjectionY("proj3ProngLxyz", 1, h2datajetPt3ProngLxyz->GetNbinsX()));
    TH1F* proj3ProngSxy = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxy->ProjectionY("proj3ProngSxy", 1, h2datajetPt3ProngSxy->GetNbinsX()));
    TH1F* proj3ProngSxyz = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxyz->ProjectionY("proj3ProngSxyz", 1, h2datajetPt3ProngSxyz->GetNbinsX()));
    TH1F* proj3ProngsigmaLxy = reinterpret_cast<TH1F*> (h2datajetPt3ProngsigmaLxy->ProjectionY("proj3ProngsigmaLxy", 1, h2datajetPt3ProngsigmaLxy->GetNbinsX()));
    TH1F* proj3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2datajetPt3ProngsigmaLxyz->ProjectionY("proj3ProngsigmaLxyz", 1, h2datajetPt3ProngsigmaLxyz->GetNbinsX()));

    hdatajet3ProngLxy[0] = reinterpret_cast<TH1F*>(proj3ProngLxy->Clone("hdatajet3ProngLxy_0"));
    hdatajet3ProngLxyz[0] = reinterpret_cast<TH1F*>(proj3ProngLxyz->Clone("hdatajet3ProngLxyz_0"));
    hdatajet3ProngSxy[0] = reinterpret_cast<TH1F*>(proj3ProngSxy->Clone("hdatajet3ProngSxy_0"));
    hdatajet3ProngSxyz[0] = reinterpret_cast<TH1F*>(proj3ProngSxyz->Clone("hdatajet3ProngSxyz_0"));
    hdatajet3ProngsigmaLxy[0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxy->Clone("hdatajet3ProngsigmaLxy_0"));
    hdatajet3ProngsigmaLxyz[0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxyz->Clone("hdatajet3ProngsigmaLxyz_0"));

    if (fillN1) {
      TH1F* proj3ProngSxyN1 = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxyN1->ProjectionY("proj3ProngSxyN1", 1, h2datajetPt3ProngSxyN1->GetNbinsX()));
      TH1F* proj3ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxyzN1->ProjectionY("proj3ProngSxyzN1", 1, h2datajetPt3ProngSxyzN1->GetNbinsX()));
      TH1F* proj3ProngMassN1 = reinterpret_cast<TH1F*> (h2datajetPt3ProngMassN1->ProjectionY("proj3ProngMassN1", 1, h2datajetPt3ProngMassN1->GetNbinsX()));
      TH1F* projtaggedjet3ProngSxyN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt3ProngSxyN1->ProjectionY("projtaggedjet3ProngSxyN1", 1, h2datataggedjetPt3ProngSxyN1->GetNbinsX()));
      TH1F* projtaggedjet3ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt3ProngSxyzN1->ProjectionY("projtaggedjet3ProngSxyzN1", 1, h2datataggedjetPt3ProngSxyzN1->GetNbinsX()));
      TH1F* projtaggedjet3ProngMassN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt3ProngMassN1->ProjectionY("projtaggedjet3ProngMassN1", 1, h2datataggedjetPt3ProngMassN1->GetNbinsX()));
      hdatajet3ProngSxyN1[0] = reinterpret_cast<TH1F*>(proj3ProngSxyN1->Clone("hdatajet3ProngSxyN1_0"));
      hdatajet3ProngSxyzN1[0] = reinterpret_cast<TH1F*>(proj3ProngSxyzN1->Clone("hdatajet3ProngSxyzN1_0"));
      hdatajet3ProngMassN1[0] = reinterpret_cast<TH1F*>(proj3ProngMassN1->Clone("hdatajet3ProngMassN1_0"));
      hdatataggedjet3ProngSxyN1[0] = reinterpret_cast<TH1F*>(proj3ProngSxyN1->Clone("hdatataggedjet3ProngSxyN1_0"));
      hdatataggedjet3ProngSxyzN1[0] = reinterpret_cast<TH1F*>(proj3ProngSxyzN1->Clone("hdatataggedjet3ProngSxyzN1_0"));
      hdatataggedjet3ProngMassN1[0] = reinterpret_cast<TH1F*>(proj3ProngMassN1->Clone("hdatataggedjet3ProngMassN1_0"));
    }

    for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      int leftbinJetPt3ProngLxy = h2datajetPt3ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngLxy = h2datajetPt3ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngLxy = reinterpret_cast<TH1F*> (h2datajetPt3ProngLxy->ProjectionY(Form("projJetPtRange3ProngLxy_%d", binJetPt), leftbinJetPt3ProngLxy, rightbinJetPt3ProngLxy));
      hdatajet3ProngLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxy->Clone(Form("hsimjet3ProngLxy_%d", binJetPt))); 

      int leftbinJetPt3ProngLxyz = h2datajetPt3ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngLxyz = h2datajetPt3ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngLxyz = reinterpret_cast<TH1F*> (h2datajetPt3ProngLxyz->ProjectionY(Form("projJetPtRange3ProngLxyz_%d", binJetPt), leftbinJetPt3ProngLxyz, rightbinJetPt3ProngLxyz));
      hdatajet3ProngLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxyz->Clone(Form("hsimjet3ProngLxyz_%d", binJetPt))); 

      int leftbinJetPt3ProngSxy = h2datajetPt3ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngSxy = h2datajetPt3ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngSxy = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxy->ProjectionY(Form("projJetPtRange3ProngSxy_%d", binJetPt), leftbinJetPt3ProngSxy, rightbinJetPt3ProngSxy));
      hdatajet3ProngSxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxy->Clone(Form("hsimjet3ProngSxy_%d", binJetPt))); 

      int leftbinJetPt3ProngSxyz = h2datajetPt3ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngSxyz = h2datajetPt3ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngSxyz = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxyz->ProjectionY(Form("projJetPtRange3ProngSxyz_%d", binJetPt), leftbinJetPt3ProngSxyz, rightbinJetPt3ProngSxyz));
      hdatajet3ProngSxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyz->Clone(Form("hsimjet3ProngSxyz_%d", binJetPt))); 

      int leftbinJetPt3ProngsigmaLxy = h2datajetPt3ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngsigmaLxy = h2datajetPt3ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngsigmaLxy = reinterpret_cast<TH1F*> (h2datajetPt3ProngsigmaLxy->ProjectionY(Form("projJetPtRange3ProngsigmaLxy_%d", binJetPt), leftbinJetPt3ProngsigmaLxy, rightbinJetPt3ProngsigmaLxy));
      hdatajet3ProngsigmaLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxy->Clone(Form("hsimjet3ProngsigmaLxy_%d", binJetPt))); 

      int leftbinJetPt3ProngsigmaLxyz = h2datajetPt3ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngsigmaLxyz = h2datajetPt3ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2datajetPt3ProngsigmaLxyz->ProjectionY(Form("projJetPtRange3ProngsigmaLxyz_%d", binJetPt), leftbinJetPt3ProngsigmaLxyz, rightbinJetPt3ProngsigmaLxyz));
      hdatajet3ProngsigmaLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxyz->Clone(Form("hsimjet3ProngsigmaLxyz_%d", binJetPt))); 

      if (fillN1) {
        int leftbinJetPt3ProngSxyN1 = h2datajetPt3ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngSxyN1 = h2datajetPt3ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxyN1->ProjectionY(Form("projJetPtRange3ProngSxyN1_%d", binJetPt), leftbinJetPt3ProngSxyN1, rightbinJetPt3ProngSxyN1));
        hdatajet3ProngSxyN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyN1->Clone(Form("hdatajet3ProngSxyN1_%d", binJetPt))); 

        int leftbinJetPt3ProngSxyzN1 = h2datajetPt3ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngSxyzN1 = h2datajetPt3ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datajetPt3ProngSxyzN1->ProjectionY(Form("projJetPtRange3ProngSxyzN1_%d", binJetPt), leftbinJetPt3ProngSxyzN1, rightbinJetPt3ProngSxyzN1));
        hdatajet3ProngSxyzN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyzN1->Clone(Form("hdatajet3ProngSxyzN1_%d", binJetPt))); 

        int leftbinJetPt3ProngMassN1 = h2datajetPt3ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngMassN1 = h2datajetPt3ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*> (h2datajetPt3ProngMassN1->ProjectionY(Form("projJetPtRange3ProngMassN1_%d", binJetPt), leftbinJetPt3ProngMassN1, rightbinJetPt3ProngMassN1));
        hdatajet3ProngMassN1[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngMassN1->Clone(Form("hdatajet3ProngMassN1_%d", binJetPt))); 

        int leftbintaggedjetJetPt3ProngSxyN1 = h2datataggedjetPt3ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbintaggedjetJetPt3ProngSxyN1 = h2datataggedjetPt3ProngSxyN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projtaggedjetJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt3ProngSxyN1->ProjectionY(Form("projJetPtRange3ProngSxyN1_%d", binJetPt), leftbintaggedjetJetPt3ProngSxyN1, rightbintaggedjetJetPt3ProngSxyN1));
        hdatataggedjet3ProngSxyN1[binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange3ProngSxyN1->Clone(Form("hdatataggedjet3ProngSxyN1_%d", binJetPt))); 

        int leftbintaggedjetJetPt3ProngSxyzN1 = h2datataggedjetPt3ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbintaggedjetJetPt3ProngSxyzN1 = h2datataggedjetPt3ProngSxyzN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projtaggedjetJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt3ProngSxyzN1->ProjectionY(Form("projJetPtRange3ProngSxyzN1_%d", binJetPt), leftbintaggedjetJetPt3ProngSxyzN1, rightbintaggedjetJetPt3ProngSxyzN1));
        hdatataggedjet3ProngSxyzN1[binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange3ProngSxyzN1->Clone(Form("hdatataggedjet3ProngSxyzN1_%d", binJetPt))); 

        int leftbintaggedjetJetPt3ProngMassN1 = h2datataggedjetPt3ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbintaggedjetJetPt3ProngMassN1 = h2datataggedjetPt3ProngMassN1->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projtaggedjetJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*> (h2datataggedjetPt3ProngMassN1->ProjectionY(Form("projJetPtRange3ProngMassN1_%d", binJetPt), leftbintaggedjetJetPt3ProngMassN1, rightbintaggedjetJetPt3ProngMassN1));
        hdatataggedjet3ProngMassN1[binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange3ProngMassN1->Clone(Form("hdatataggedjet3ProngMassN1_%d", binJetPt))); 
      }
    }
  }
}

void HfJetTaggingSVAnalysis::rebinHistSVData() {
}

void HfJetTaggingSVAnalysis::initSVData(TString rootData) {
  loadDataSV(rootData.Data());
  initHistSVData();
  projectionHistSVData();
  //rebinHistSVData();
}

int HfJetTaggingSVAnalysis::loadSimSV(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, SV QA) not found!" << std::endl;
    return 0;
  }
  //TString taskName = "jet-taggerhf-qa-charged_id16721";
  TString taskName = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  if (fillMCD && fill2Prong) {
    h3simjetPt2ProngLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxy_flavour", taskName.Data())));
    h3simjetPt2ProngLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Lxyz_flavour", taskName.Data())));
    h3simjetPt2ProngSxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxy_flavour", taskName.Data())));
    h3simjetPt2ProngSxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxyz_flavour", taskName.Data())));
    h3simjetPt2ProngsigmaLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxy_flavour", taskName.Data())));
    h3simjetPt2ProngsigmaLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_sigmaLxyz_flavour", taskName.Data())));
    h3simjet2ProngSxysigmaLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_2prong_Sxy_sigmaLxy_flavour", taskName.Data())));
    h3simjet2ProngSxyzsigmaLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_2prong_Sxyz_sigmaLxyz_flavour", taskName.Data())));
    if (fillN1) {
      h3simjetPt2ProngSxyN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxy_N1_flavour", taskName.Data())));
      h3simjetPt2ProngSxyzN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_Sxyz_N1_flavour", taskName.Data())));
      h3simjetPt2ProngMassN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_2prong_mass_N1_flavour", taskName.Data())));
    }
    if (fillTest) {
      h3simjetPt2ProngChi2Flavour =reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_jet_pt_2prong_chi2_flavour", taskName.Data())));
    }
  }
  if (fillMCD && fill3Prong) {
    h3simjetPt3ProngLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Lxy_flavour", taskName.Data())));
    h3simjetPt3ProngLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Lxyz_flavour", taskName.Data())));
    h3simjetPt3ProngSxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_flavour", taskName.Data())));
    h3simjetPt3ProngSxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_flavour", taskName.Data())));
    h3simjetPt3ProngsigmaLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_sigmaLxy_flavour", taskName.Data())));
    h3simjetPt3ProngsigmaLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_sigmaLxyz_flavour", taskName.Data())));
    h3simjet3ProngSxysigmaLxyFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_3prong_Sxy_sigmaLxy_flavour", taskName.Data())));
    h3simjet3ProngSxyzsigmaLxyzFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_3prong_Sxyz_sigmaLxyz_flavour", taskName.Data())));
    h3simjetPt3ProngLxyFlavour->Sumw2();
    h3simjetPt3ProngLxyzFlavour->Sumw2();
    h3simjetPt3ProngSxyFlavour->Sumw2();
    h3simjetPt3ProngSxyzFlavour->Sumw2();
    h3simjetPt3ProngsigmaLxyFlavour->Sumw2();
    h3simjetPt3ProngsigmaLxyzFlavour->Sumw2();
    if (fillN1) {
      h3simjetPt3ProngSxyN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_N1_flavour", taskName.Data())));
      h3simjetPt3ProngSxyzN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_N1_flavour", taskName.Data())));
      h3simjetPt3ProngMassN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_mass_N1_flavour", taskName.Data())));
      h3simtaggedjetPt3ProngSxyN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxy_N1_flavour", taskName.Data())));
      h3simtaggedjetPt3ProngSxyzN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxyz_N1_flavour", taskName.Data())));
      h3simtaggedjetPt3ProngMassN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_mass_N1_flavour", taskName.Data())));
      h3simjetPt3ProngSxyN1Flavour->Sumw2();
      h3simjetPt3ProngSxyzN1Flavour->Sumw2();
      h3simjetPt3ProngMassN1Flavour->Sumw2();
      h3simtaggedjetPt3ProngSxyN1Flavour->Sumw2();
      h3simtaggedjetPt3ProngSxyzN1Flavour->Sumw2();
      h3simtaggedjetPt3ProngMassN1Flavour->Sumw2();
    }
    if (fillTest) {
      h3simjetPt3ProngChi2Flavour =reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_jet_pt_3prong_chi2_flavour", taskName.Data())));
    }
  }
  std::cout << "Load completed SV MC" << std::endl;
  return 1;
}

void HfJetTaggingSVAnalysis::initHistSVMC() {
  if (fillMCD && fill2Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjet2ProngPt[flavour] = new TH1F(Form("hsimjet2ProngPt_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi2ProngSxy[flavour] = new TH1F(Form("hsimSVEffi2ProngSxy_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi2ProngSxyz[flavour] = new TH1F(Form("hsimSVEffi2ProngSxyz_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi2ProngSxyN1[flavour] = new TH1F(Form("hsimSVEffi2ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi2ProngSxyzN1[flavour] = new TH1F(Form("hsimSVEffi2ProngSxyzN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity2ProngSxy[flavour] = new TH1F(Form("hsimSVPurity2ProngSxy_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity2ProngSxyz[flavour] = new TH1F(Form("hsimSVPurity2ProngSxyz_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity2ProngSxyN1[flavour] = new TH1F(Form("hsimSVPurity2ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity2ProngSxyzN1[flavour] = new TH1F(Form("hsimSVPurity2ProngSxyzN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        hsimjet2ProngLxy[flavour][jetPt] = new TH1F(Form("hsimjet2ProngLxy_%d_%d", flavour, jetPt), "", h3simjetPt2ProngLxyFlavour->GetNbinsY(), h3simjetPt2ProngLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngLxyFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngLxyFlavour->GetNbinsY()));
        hsimjet2ProngLxyz[flavour][jetPt] = new TH1F(Form("hsimjet2ProngLxyz_%d_%d", flavour, jetPt), "", h3simjetPt2ProngLxyzFlavour->GetNbinsY(), h3simjetPt2ProngLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngLxyzFlavour->GetNbinsY()));
        hsimjet2ProngSxy[flavour][jetPt] = new TH1F(Form("hsimjet2ProngSxy_%d_%d", flavour, jetPt), "", h3simjetPt2ProngSxyFlavour->GetNbinsY(), h3simjetPt2ProngSxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngSxyFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngSxyFlavour->GetNbinsY()));
        hsimjet2ProngSxyz[flavour][jetPt] = new TH1F(Form("hsimjet2ProngSxyz_%d_%d", flavour, jetPt), "", h3simjetPt2ProngSxyzFlavour->GetNbinsY(), h3simjetPt2ProngSxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngSxyzFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngSxyzFlavour->GetNbinsY()));
        hsimjet2ProngsigmaLxy[flavour][jetPt] = new TH1F(Form("hsimjet2ProngsigmaLxy_%d_%d", flavour, jetPt), "", h3simjetPt2ProngsigmaLxyFlavour->GetNbinsY(), h3simjetPt2ProngsigmaLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngsigmaLxyFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngsigmaLxyFlavour->GetNbinsY()));
        hsimjet2ProngsigmaLxyz[flavour][jetPt] = new TH1F(Form("hsimjet2ProngsigmaLxyz_%d_%d", flavour, jetPt), "", h3simjetPt2ProngsigmaLxyzFlavour->GetNbinsY(), h3simjetPt2ProngsigmaLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngsigmaLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngsigmaLxyzFlavour->GetNbinsY()));
        if (fillN1) {
          hsimjet2ProngSxyN1[flavour][jetPt] = new TH1F(Form("hsimjet2ProngSxyN1_%d_%d", flavour, jetPt), "", h3simjetPt2ProngSxyN1Flavour->GetNbinsY(), h3simjetPt2ProngSxyN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngSxyN1Flavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngSxyN1Flavour->GetNbinsY()));
          hsimjet2ProngSxyzN1[flavour][jetPt] = new TH1F(Form("hsimjet2ProngSxyzN1_%d_%d", flavour, jetPt), "", h3simjetPt2ProngSxyzN1Flavour->GetNbinsY(), h3simjetPt2ProngSxyzN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngSxyzN1Flavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngSxyzN1Flavour->GetNbinsY()));
          hsimjet2ProngMassN1[flavour][jetPt] = new TH1F(Form("hsimjet2ProngMassN1_%d_%d", flavour, jetPt), "", h3simjetPt2ProngMassN1Flavour->GetNbinsY(), h3simjetPt2ProngMassN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt2ProngMassN1Flavour->GetYaxis()->GetBinUpEdge(h3simjetPt2ProngMassN1Flavour->GetNbinsY()));
        }
      }
    }
  } // end fillMCD && fill2Prong
  if (fillMCD && fill3Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjet3ProngRawYield[flavour] = new TH1F(Form("hsimjet3ProngRawYield_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimjet3ProngNormYieldEffiAndPurity[flavour] = new TH1F(Form("hsimjet3ProngYieldAndPurity_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimjet3ProngNormYieldEffiAndPurityUnfold[flavour] = new TH1F(Form("hsimjet3ProngYieldAndPurityUnfold_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimjet3ProngCrossSection[flavour] = new TH1F(Form("hsimjet3ProngCrossSection_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimjet3ProngFlavourFraction[flavour] = new TH1F(Form("hsimjet3ProngFlavourFraction_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimjet3ProngPt[flavour] = new TH1F(Form("hsimjet3ProngPt_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi3ProngSxy[flavour] = new TH1F(Form("hsimSVEffi3ProngSxy_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi3ProngSxyz[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyz_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi3ProngSxyN1[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi3ProngSxyN1wSys[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyN1wSys_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffi3ProngSxyzN1[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyzN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity3ProngSxy[flavour] = new TH1F(Form("hsimSVPurity3ProngSxy_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity3ProngSxyz[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyz_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity3ProngSxyN1[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity3ProngSxyN1wSys[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyN1wSys_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVPurity3ProngSxyzN1[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyzN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimSVEffiAndPurity3ProngSxyN1[flavour] = new TH1F(Form("hsimSVEffiAndPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimtaggedjetSVEffi3ProngSxyN1[flavour] = new TH1F(Form("hsimtaggedjetSVEffi3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      hsimtaggedjetSVPurity3ProngSxyN1[flavour] = new TH1F(Form("hsimtaggedjetSVPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        hsimjet3ProngLxy[flavour][jetPt] = new TH1F(Form("hsimjet3ProngLxy_%d_%d", flavour, jetPt), "", h3simjetPt3ProngLxyFlavour->GetNbinsY(), h3simjetPt3ProngLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngLxyFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngLxyFlavour->GetNbinsY()));
        hsimjet3ProngLxyz[flavour][jetPt] = new TH1F(Form("hsimjet3ProngLxyz_%d_%d", flavour, jetPt), "", h3simjetPt3ProngLxyzFlavour->GetNbinsY(), h3simjetPt3ProngLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngLxyzFlavour->GetNbinsY()));
        hsimjet3ProngSxy[flavour][jetPt] = new TH1F(Form("hsimjet3ProngSxy_%d_%d", flavour, jetPt), "", h3simjetPt3ProngSxyFlavour->GetNbinsY(), h3simjetPt3ProngSxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyFlavour->GetNbinsY()));
        hsimjet3ProngSxyz[flavour][jetPt] = new TH1F(Form("hsimjet3ProngSxyz_%d_%d", flavour, jetPt), "", h3simjetPt3ProngSxyzFlavour->GetNbinsY(), h3simjetPt3ProngSxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyzFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyzFlavour->GetNbinsY()));
        hsimjet3ProngsigmaLxy[flavour][jetPt] = new TH1F(Form("hsimjet3ProngsigmaLxy_%d_%d", flavour, jetPt), "", h3simjetPt3ProngsigmaLxyFlavour->GetNbinsY(), h3simjetPt3ProngsigmaLxyFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngsigmaLxyFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngsigmaLxyFlavour->GetNbinsY()));
        hsimjet3ProngsigmaLxyz[flavour][jetPt] = new TH1F(Form("hsimjet3ProngsigmaLxyz_%d_%d", flavour, jetPt), "", h3simjetPt3ProngsigmaLxyzFlavour->GetNbinsY(), h3simjetPt3ProngsigmaLxyzFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngsigmaLxyzFlavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngsigmaLxyzFlavour->GetNbinsY()));
        if (fillN1) {
          hsimjet3ProngSxyN1[flavour][jetPt] = new TH1F(Form("hsimjet3ProngSxyN1_%d_%d", flavour, jetPt), "", h3simjetPt3ProngSxyN1Flavour->GetNbinsY(), h3simjetPt3ProngSxyN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyN1Flavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyN1Flavour->GetNbinsY()));
          hsimjet3ProngSxyzN1[flavour][jetPt] = new TH1F(Form("hsimjet3ProngSxyzN1_%d_%d", flavour, jetPt), "", h3simjetPt3ProngSxyzN1Flavour->GetNbinsY(), h3simjetPt3ProngSxyzN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyzN1Flavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyzN1Flavour->GetNbinsY()));
          hsimjet3ProngMassN1[flavour][jetPt] = new TH1F(Form("hsimjet3ProngMassN1_%d_%d", flavour, jetPt), "", h3simjetPt3ProngMassN1Flavour->GetNbinsY(), h3simjetPt3ProngMassN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngMassN1Flavour->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngMassN1Flavour->GetNbinsY()));
          hsimtaggedjet3ProngSxyN1[flavour][jetPt] = new TH1F(Form("hsimtaggedjet3ProngSxyN1_%d_%d", flavour, jetPt), "", h3simtaggedjetPt3ProngSxyN1Flavour->GetNbinsY(), h3simtaggedjetPt3ProngSxyN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngSxyN1Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngSxyN1Flavour->GetNbinsY()));
          hsimtaggedjet3ProngSxyzN1[flavour][jetPt] = new TH1F(Form("hsimtaggedjet3ProngSxyzN1_%d_%d", flavour, jetPt), "", h3simtaggedjetPt3ProngSxyzN1Flavour->GetNbinsY(), h3simtaggedjetPt3ProngSxyzN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngSxyzN1Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngSxyzN1Flavour->GetNbinsY()));
          hsimtaggedjet3ProngMassN1[flavour][jetPt] = new TH1F(Form("hsimtaggedjet3ProngMassN1_%d_%d", flavour, jetPt), "", h3simtaggedjetPt3ProngMassN1Flavour->GetNbinsY(), h3simtaggedjetPt3ProngMassN1Flavour->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngMassN1Flavour->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngMassN1Flavour->GetNbinsY()));
          hsimSVEffi3ProngSxyTaggerPoint[flavour][jetPt] = new TH1F(Form("hsimSVEffi3ProngSxyTaggerPoint_%d_%d", flavour, jetPt), "", HfJetTagging::numTaggerSV, HfJetTagging::xlowTaggerSV, HfJetTagging::xupTaggerSV);
          hsimSVPurity3ProngSxyTaggerPoint[flavour][jetPt] = new TH1F(Form("hsimSVPurity3ProngSxyTaggerPoint_%d_%d", flavour, jetPt), "", HfJetTagging::numTaggerSV, HfJetTagging::xlowTaggerSV, HfJetTagging::xupTaggerSV);
        }
      }
    }
  }
  std::cout << "init hist " << std::endl;
}

void HfJetTaggingSVAnalysis::projectionHistSVMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  if (fillMCD && fill2Prong) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      TH1F* proj2ProngLxy = reinterpret_cast<TH1F*> (h3simjetPt2ProngLxyFlavour->ProjectionY(Form("proj2ProngLxy_%d", binFlavour), 1, h3simjetPt2ProngLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj2ProngLxyz = reinterpret_cast<TH1F*> (h3simjetPt2ProngLxyzFlavour->ProjectionY(Form("proj2ProngLxyz_%d", binFlavour), 1, h3simjetPt2ProngLxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj2ProngSxy = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyFlavour->ProjectionY(Form("proj2ProngSxy_%d", binFlavour), 1, h3simjetPt2ProngSxyFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj2ProngSxyz = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyzFlavour->ProjectionY(Form("proj2ProngSxyz_%d", binFlavour), 1, h3simjetPt2ProngSxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj2ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simjetPt2ProngsigmaLxyFlavour->ProjectionY(Form("proj2ProngsigmaLxy_%d", binFlavour), 1, h3simjetPt2ProngsigmaLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simjetPt2ProngsigmaLxyzFlavour->ProjectionY(Form("proj2ProngsigmaLxyz_%d", binFlavour), 1, h3simjetPt2ProngsigmaLxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
      hsimjet2ProngLxy[0][0]->Add(proj2ProngLxy);
      hsimjet2ProngLxyz[0][0]->Add(proj2ProngLxyz);
      hsimjet2ProngSxy[0][0]->Add(proj2ProngSxy);
      hsimjet2ProngSxyz[0][0]->Add(proj2ProngSxyz);
      hsimjet2ProngsigmaLxy[0][0]->Add(proj2ProngsigmaLxy);
      hsimjet2ProngsigmaLxyz[0][0]->Add(proj2ProngsigmaLxyz);
      hsimjet2ProngLxy[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngLxy->Clone(Form("hsimjet2ProngLxy_%d_0", flavour)));
      hsimjet2ProngLxyz[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngLxyz->Clone(Form("hsimjet2ProngLxyz_%d_0", flavour)));
      hsimjet2ProngSxy[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngSxy->Clone(Form("hsimjet2ProngSxy_%d_0", flavour)));
      hsimjet2ProngSxyz[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngSxyz->Clone(Form("hsimjet2ProngSxyz_%d_0", flavour)));
      hsimjet2ProngsigmaLxy[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxy->Clone(Form("hsimjet2ProngsigmaLxy_%d_0", flavour)));
      hsimjet2ProngsigmaLxyz[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyz->Clone(Form("hsimjet2ProngsigmaLxyz_%d_0", flavour)));

      if (fillN1) {
        TH1F* proj2ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyN1Flavour->ProjectionY(Form("proj2ProngSxyN1_%d", binFlavour), 1, h3simjetPt2ProngSxyN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* proj2ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyzN1Flavour->ProjectionY(Form("proj2ProngSxyzN1_%d", binFlavour), 1, h3simjetPt2ProngSxyzN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* proj2ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt2ProngMassN1Flavour->ProjectionY(Form("proj2ProngMassN1_%d", binFlavour), 1, h3simjetPt2ProngMassN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjet2ProngSxyN1[0][0]->Add(proj2ProngSxyN1);
        hsimjet2ProngSxyzN1[0][0]->Add(proj2ProngSxyzN1);
        hsimjet2ProngSxyN1[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngSxyN1->Clone(Form("hsimjet2ProngSxyN1_%d_0", flavour)));
        hsimjet2ProngSxyzN1[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngSxyzN1->Clone(Form("hsimjet2ProngSxyzN1_%d_0", flavour)));
        hsimjet2ProngMassN1[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngMassN1->Clone(Form("hsimjet2ProngMassN1_%d_0", flavour)));
      }

      if (fillTest) {
        TH1F* proj2ProngChi2 = reinterpret_cast<TH1F*> (h3simjetPt2ProngChi2Flavour->ProjectionY(Form("proj2ProngChi2_%d", binFlavour), 1, h3simjetPt2ProngChi2Flavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjet2ProngChi2[0][0]->Add(proj2ProngChi2);
        hsimjet2ProngChi2[flavour][0] = reinterpret_cast<TH1F*>(proj2ProngChi2->Clone(Form("hsimjet2ProngChi2_%d_0", flavour)));
      }

      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        int leftbinJetPt2ProngLxy = h3simjetPt2ProngLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngLxy = h3simjetPt2ProngLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngLxy = reinterpret_cast<TH1F*> (h3simjetPt2ProngLxyFlavour->ProjectionY(Form("projJetPtRange2ProngLxy_%d_%d", binJetPt, flavour), leftbinJetPt2ProngLxy, rightbinJetPt2ProngLxy, binFlavour, binFlavour));
        hsimjet2ProngLxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxy->Clone(Form("hsimjet2ProngLxy_%d_%d", flavour, binJetPt))); 
        hsimjet2ProngLxy[0][binJetPt]->Add(projJetPtRange2ProngLxy);

        int leftbinJetPt2ProngLxyz = h3simjetPt2ProngLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngLxyz = h3simjetPt2ProngLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngLxyz = reinterpret_cast<TH1F*> (h3simjetPt2ProngLxyzFlavour->ProjectionY(Form("projJetPtRange2ProngLxyz_%d_%d", binJetPt, flavour), leftbinJetPt2ProngLxyz, rightbinJetPt2ProngLxyz, binFlavour, binFlavour));
        hsimjet2ProngLxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxyz->Clone(Form("hsimjet2ProngLxyz_%d_%d", flavour, binJetPt))); 
        hsimjet2ProngLxyz[0][binJetPt]->Add(projJetPtRange2ProngLxyz);

        int leftbinJetPt2ProngSxy = h3simjetPt2ProngSxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngSxy = h3simjetPt2ProngSxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngSxy = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyFlavour->ProjectionY(Form("projJetPtRange2ProngSxy_%d_%d", binJetPt, flavour), leftbinJetPt2ProngSxy, rightbinJetPt2ProngSxy, binFlavour, binFlavour));
        hsimjet2ProngSxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxy->Clone(Form("hsimjet2ProngSxy_%d_%d", flavour, binJetPt))); 
        hsimjet2ProngSxy[0][binJetPt]->Add(projJetPtRange2ProngSxy);

        int leftbinJetPt2ProngSxyz = h3simjetPt2ProngSxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngSxyz = h3simjetPt2ProngSxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngSxyz = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyzFlavour->ProjectionY(Form("projJetPtRange2ProngSxyz_%d_%d", binJetPt, flavour), leftbinJetPt2ProngSxyz, rightbinJetPt2ProngSxyz, binFlavour, binFlavour));
        hsimjet2ProngSxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyz->Clone(Form("hsimjet2ProngSxyz_%d_%d", flavour, binJetPt))); 
        hsimjet2ProngSxyz[0][binJetPt]->Add(projJetPtRange2ProngSxyz);

        int leftbinJetPt2ProngsigmaLxy = h3simjetPt2ProngsigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngsigmaLxy = h3simjetPt2ProngsigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simjetPt2ProngsigmaLxyFlavour->ProjectionY(Form("projJetPtRange2ProngsigmaLxy_%d_%d", binJetPt, flavour), leftbinJetPt2ProngsigmaLxy, rightbinJetPt2ProngsigmaLxy, binFlavour, binFlavour));
        hsimjet2ProngsigmaLxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxy->Clone(Form("hsimjet2ProngsigmaLxy_%d_%d", flavour, binJetPt))); 
        hsimjet2ProngsigmaLxy[0][binJetPt]->Add(projJetPtRange2ProngsigmaLxy);

        int leftbinJetPt2ProngsigmaLxyz = h3simjetPt2ProngsigmaLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt2ProngsigmaLxyz = h3simjetPt2ProngsigmaLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simjetPt2ProngsigmaLxyzFlavour->ProjectionY(Form("projJetPtRange2ProngsigmaLxyz_%d_%d", binJetPt, flavour), leftbinJetPt2ProngsigmaLxyz, rightbinJetPt2ProngsigmaLxyz, binFlavour, binFlavour));
        hsimjet2ProngsigmaLxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxyz->Clone(Form("hsimjet2ProngsigmaLxyz_%d_%d", flavour, binJetPt))); 
        hsimjet2ProngsigmaLxyz[0][binJetPt]->Add(projJetPtRange2ProngsigmaLxyz);

        if (fillN1) {
          int leftbinJetPt2ProngSxyN1 = h3simjetPt2ProngSxyN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt2ProngSxyN1 = h3simjetPt2ProngSxyN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange2ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyN1Flavour->ProjectionY(Form("projJetPtRange2ProngSxyN1_%d_%d", binJetPt, flavour), leftbinJetPt2ProngSxyN1, rightbinJetPt2ProngSxyN1, binFlavour, binFlavour));
          hsimjet2ProngSxyN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyN1->Clone(Form("hsimjet2ProngSxyN1_%d_%d", flavour, binJetPt))); 
          hsimjet2ProngSxyN1[0][binJetPt]->Add(projJetPtRange2ProngSxyN1);

          int leftbinJetPt2ProngSxyzN1 = h3simjetPt2ProngSxyzN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt2ProngSxyzN1 = h3simjetPt2ProngSxyzN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange2ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt2ProngSxyzN1Flavour->ProjectionY(Form("projJetPtRange2ProngSxyzN1_%d_%d", binJetPt, flavour), leftbinJetPt2ProngSxyzN1, rightbinJetPt2ProngSxyzN1, binFlavour, binFlavour));
          hsimjet2ProngSxyzN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyzN1->Clone(Form("hsimjet2ProngSxyzN1_%d_%d", flavour, binJetPt))); 
          hsimjet2ProngSxyzN1[0][binJetPt]->Add(projJetPtRange2ProngSxyzN1);

          int leftbinJetPt2ProngMassN1 = h3simjetPt2ProngMassN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt2ProngMassN1 = h3simjetPt2ProngMassN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange2ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt2ProngMassN1Flavour->ProjectionY(Form("projJetPtRange2ProngMassN1_%d_%d", binJetPt, flavour), leftbinJetPt2ProngMassN1, rightbinJetPt2ProngMassN1, binFlavour, binFlavour));
          hsimjet2ProngMassN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngMassN1->Clone(Form("hsimjet2ProngMassN1_%d_%d", flavour, binJetPt))); 
          hsimjet2ProngMassN1[0][binJetPt]->Add(projJetPtRange2ProngMassN1);

          double binContent = h3simjetPt2ProngSxyN1Flavour->Integral(binJetPt, binJetPt, 1, h3simjetPt2ProngSxyN1Flavour->GetNbinsY(), 1, h3simjetPt2ProngSxyN1Flavour->GetNbinsZ());
          hsimjet2ProngPt[flavour]->SetBinContent(binJetPt, binContent);
        }
      }
    }
  } // end fillMCD && fill2Prong

  if (fillMCD && fill3Prong) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      TH1F* proj3ProngLxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngLxyFlavour->ProjectionY(Form("proj3ProngLxy_%d", binFlavour), 1, h3simjetPt3ProngLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj3ProngLxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngLxyzFlavour->ProjectionY(Form("proj3ProngLxyz_%d", binFlavour), 1, h3simjetPt3ProngLxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj3ProngSxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyFlavour->ProjectionY(Form("proj3ProngSxy_%d", binFlavour), 1, h3simjetPt3ProngSxyFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj3ProngSxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzFlavour->ProjectionY(Form("proj3ProngSxyz_%d", binFlavour), 1, h3simjetPt3ProngSxyzFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj3ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngsigmaLxyFlavour->ProjectionY(Form("proj3ProngsigmaLxy_%d", binFlavour), 1, h3simjetPt3ProngsigmaLxyFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* proj3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngsigmaLxyzFlavour->ProjectionY(Form("proj3ProngsigmaLxyz_%d", binFlavour), 1, h3simjetPt3ProngsigmaLxyzFlavour->GetNbinsX(), binFlavour, binFlavour));

      hsimjet3ProngLxy[0][0]->Add(proj3ProngLxy);
      hsimjet3ProngLxyz[0][0]->Add(proj3ProngLxyz);
      hsimjet3ProngSxy[0][0]->Add(proj3ProngSxy);
      hsimjet3ProngSxyz[0][0]->Add(proj3ProngSxyz);
      hsimjet3ProngsigmaLxy[0][0]->Add(proj3ProngsigmaLxy);
      hsimjet3ProngsigmaLxyz[0][0]->Add(proj3ProngsigmaLxyz);
      hsimjet3ProngLxy[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngLxy->Clone(Form("hsimjet3ProngLxy_%d_0", flavour)));
      hsimjet3ProngLxyz[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngLxyz->Clone(Form("hsimjet3ProngLxyz_%d_0", flavour)));
      hsimjet3ProngSxy[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxy->Clone(Form("hsimjet3ProngSxy_%d_0", flavour)));
      hsimjet3ProngSxyz[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyz->Clone(Form("hsimjet3ProngSxyz_%d_0", flavour)));
      hsimjet3ProngsigmaLxy[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxy->Clone(Form("hsimjet3ProngsigmaLxy_%d_0", flavour)));
      hsimjet3ProngsigmaLxyz[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxyz->Clone(Form("hsimjet3ProngsigmaLxyz_%d_0", flavour)));

      if (fillN1) {
        TH1F* proj3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyN1Flavour->ProjectionY(Form("proj3ProngSxyN1_%d", binFlavour), 1, h3simjetPt3ProngSxyN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* proj3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzN1Flavour->ProjectionY(Form("proj3ProngSxyzN1_%d", binFlavour), 1, h3simjetPt3ProngSxyzN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* proj3ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngMassN1Flavour->ProjectionY(Form("proj3ProngMassN1_%d", binFlavour), 1, h3simjetPt3ProngMassN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjet3ProngSxyN1[0][0]->Add(proj3ProngSxyN1);
        hsimjet3ProngSxyzN1[0][0]->Add(proj3ProngSxyzN1);
        hsimjet3ProngMassN1[0][0]->Add(proj3ProngMassN1);
        hsimjet3ProngSxyN1[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyN1->Clone(Form("hsimjet3ProngSxyN1_%d_0", flavour)));
        hsimjet3ProngSxyzN1[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyzN1->Clone(Form("hsimjet3ProngSxyzN1_%d_0", flavour)));
        hsimjet3ProngMassN1[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngMassN1->Clone(Form("hsimjet3ProngMassN1_%d_0", flavour)));

        TH1F* projtaggedjet3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyN1Flavour->ProjectionY(Form("projtaggedjet3ProngSxyN1_%d", binFlavour), 1, h3simtaggedjetPt3ProngSxyN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projtaggedjet3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyzN1Flavour->ProjectionY(Form("projtaggejet3ProngSxyzN1_%d", binFlavour), 1, h3simtaggedjetPt3ProngSxyzN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projtaggedjet3ProngMassN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngMassN1Flavour->ProjectionY(Form("projtaggedjet3ProngMassN1_%d", binFlavour), 1, h3simtaggedjetPt3ProngMassN1Flavour->GetNbinsX(), binFlavour, binFlavour));
        hsimtaggedjet3ProngSxyN1[0][0]->Add(projtaggedjet3ProngSxyN1);
        hsimtaggedjet3ProngSxyzN1[0][0]->Add(projtaggedjet3ProngSxyzN1);
        hsimtaggedjet3ProngMassN1[0][0]->Add(projtaggedjet3ProngMassN1);
        hsimtaggedjet3ProngSxyN1[flavour][0] = reinterpret_cast<TH1F*>(projtaggedjet3ProngSxyN1->Clone(Form("hsimtaggedjet3ProngSxyN1_%d_0", flavour)));
        hsimtaggedjet3ProngSxyzN1[flavour][0] = reinterpret_cast<TH1F*>(projtaggedjet3ProngSxyzN1->Clone(Form("hsimtaggedjet3ProngSxyzN1_%d_0", flavour)));
        hsimtaggedjet3ProngMassN1[flavour][0] = reinterpret_cast<TH1F*>(projtaggedjet3ProngMassN1->Clone(Form("hsimtaggedjet3ProngMassN1_%d_0", flavour)));
      }

      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        int leftbinJetPt3ProngLxy = h3simjetPt3ProngLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngLxy = h3simjetPt3ProngLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngLxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngLxyFlavour->ProjectionY(Form("projJetPtRange3ProngLxy_%d_%d", binJetPt, flavour), leftbinJetPt3ProngLxy, rightbinJetPt3ProngLxy, binFlavour, binFlavour));
        hsimjet3ProngLxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxy->Clone(Form("hsimjet3ProngLxy_%d_%d", flavour, binJetPt))); 
        hsimjet3ProngLxy[0][binJetPt]->Add(projJetPtRange3ProngLxy);

        int leftbinJetPt3ProngLxyz = h3simjetPt3ProngLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngLxyz = h3simjetPt3ProngLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngLxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngLxyzFlavour->ProjectionY(Form("projJetPtRange3ProngLxyz_%d_%d", binJetPt, flavour), leftbinJetPt3ProngLxyz, rightbinJetPt3ProngLxyz, binFlavour, binFlavour));
        hsimjet3ProngLxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxyz->Clone(Form("hsimjet3ProngLxyz_%d_%d", flavour, binJetPt))); 
        hsimjet3ProngLxyz[0][binJetPt]->Add(projJetPtRange3ProngLxyz);

        int leftbinJetPt3ProngSxy = h3simjetPt3ProngSxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngSxy = h3simjetPt3ProngSxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngSxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyFlavour->ProjectionY(Form("projJetPtRange3ProngSxy_%d_%d", binJetPt, flavour), leftbinJetPt3ProngSxy, rightbinJetPt3ProngSxy, binFlavour, binFlavour));
        hsimjet3ProngSxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxy->Clone(Form("hsimjet3ProngSxy_%d_%d", flavour, binJetPt))); 
        hsimjet3ProngSxy[0][binJetPt]->Add(projJetPtRange3ProngSxy);

        int leftbinJetPt3ProngSxyz = h3simjetPt3ProngSxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngSxyz = h3simjetPt3ProngSxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngSxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzFlavour->ProjectionY(Form("projJetPtRange3ProngSxyz_%d_%d", binJetPt, flavour), leftbinJetPt3ProngSxyz, rightbinJetPt3ProngSxyz, binFlavour, binFlavour));
        hsimjet3ProngSxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyz->Clone(Form("hsimjet3ProngSxyz_%d_%d", flavour, binJetPt))); 
        hsimjet3ProngSxyz[0][binJetPt]->Add(projJetPtRange3ProngSxyz);

        int leftbinJetPt3ProngsigmaLxy = h3simjetPt3ProngsigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngsigmaLxy = h3simjetPt3ProngsigmaLxyFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngsigmaLxyFlavour->ProjectionY(Form("projJetPtRange3ProngsigmaLxy_%d_%d", binJetPt, flavour), leftbinJetPt3ProngsigmaLxy, rightbinJetPt3ProngsigmaLxy, binFlavour, binFlavour));
        hsimjet3ProngsigmaLxy[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxy->Clone(Form("hsimjet3ProngsigmaLxy_%d_%d", flavour, binJetPt))); 
        hsimjet3ProngsigmaLxy[0][binJetPt]->Add(projJetPtRange3ProngsigmaLxy);

        int leftbinJetPt3ProngsigmaLxyz = h3simjetPt3ProngsigmaLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPt3ProngsigmaLxyz = h3simjetPt3ProngsigmaLxyzFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRange3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngsigmaLxyzFlavour->ProjectionY(Form("projJetPtRange3ProngsigmaLxyz_%d_%d", binJetPt, flavour), leftbinJetPt3ProngsigmaLxyz, rightbinJetPt3ProngsigmaLxyz, binFlavour, binFlavour));
        hsimjet3ProngsigmaLxyz[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxyz->Clone(Form("hsimjet3ProngsigmaLxyz_%d_%d", flavour, binJetPt))); 
        hsimjet3ProngsigmaLxyz[0][binJetPt]->Add(projJetPtRange3ProngsigmaLxyz);

        if (fillN1) {
          int leftbinJetPt3ProngSxyN1 = h3simjetPt3ProngSxyN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt3ProngSxyN1 = h3simjetPt3ProngSxyN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyN1Flavour->ProjectionY(Form("projJetPtRange3ProngSxyN1_%d_%d", binJetPt, flavour), leftbinJetPt3ProngSxyN1, rightbinJetPt3ProngSxyN1, binFlavour, binFlavour));
          hsimjet3ProngSxyN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyN1->Clone(Form("hsimjet3ProngSxyN1_%d_%d", flavour, binJetPt))); 
          hsimjet3ProngSxyN1[0][binJetPt]->Add(projJetPtRange3ProngSxyN1);

          int leftbinJetPt3ProngSxyzN1 = h3simjetPt3ProngSxyzN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt3ProngSxyzN1 = h3simjetPt3ProngSxyzN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzN1Flavour->ProjectionY(Form("projJetPtRange3ProngSxyzN1_%d_%d", binJetPt, flavour), leftbinJetPt3ProngSxyzN1, rightbinJetPt3ProngSxyzN1, binFlavour, binFlavour));
          hsimjet3ProngSxyzN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyzN1->Clone(Form("hsimjet3ProngSxyzN1_%d_%d", flavour, binJetPt))); 
          hsimjet3ProngSxyzN1[0][binJetPt]->Add(projJetPtRange3ProngSxyzN1);

          int leftbinJetPt3ProngMassN1 = h3simjetPt3ProngMassN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt3ProngMassN1 = h3simjetPt3ProngMassN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngMassN1Flavour->ProjectionY(Form("projJetPtRange3ProngMassN1_%d_%d", binJetPt, flavour), leftbinJetPt3ProngMassN1, rightbinJetPt3ProngMassN1, binFlavour, binFlavour));
          hsimjet3ProngMassN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngMassN1->Clone(Form("hsimjet3ProngMassN1_%d_%d", flavour, binJetPt))); 
          hsimjet3ProngMassN1[0][binJetPt]->Add(projJetPtRange3ProngMassN1);

          double jetPtValue = HfJetTagging::binsJetPt[binJetPt - 1];
          int binJetPt3Prong = h3simjetPt3ProngSxyN1Flavour->GetXaxis()->FindBin(jetPtValue);
          double binContent = h3simjetPt3ProngSxyN1Flavour->Integral(binJetPt3Prong, binJetPt3Prong, 1, h3simjetPt3ProngSxyN1Flavour->GetNbinsY(), 1, h3simjetPt3ProngSxyN1Flavour->GetNbinsZ());
          hsimjet3ProngPt[flavour]->SetBinContent(binJetPt, binContent);

          int leftbintaggedjetJetPt3ProngSxyN1 = h3simtaggedjetPt3ProngSxyN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbintaggedjetJetPt3ProngSxyN1 = h3simtaggedjetPt3ProngSxyN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projtaggedjetJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyN1Flavour->ProjectionY(Form("projtaggedjetJetPtRange3ProngSxyN1_%d_%d", binJetPt, flavour), leftbintaggedjetJetPt3ProngSxyN1, rightbintaggedjetJetPt3ProngSxyN1, binFlavour, binFlavour));
          hsimtaggedjet3ProngSxyN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange3ProngSxyN1->Clone(Form("hsimtaggedjet3ProngSxyN1_%d_%d", flavour, binJetPt))); 
          hsimtaggedjet3ProngSxyN1[0][binJetPt]->Add(projtaggedjetJetPtRange3ProngSxyN1);

          int leftbintaggedjetJetPt3ProngSxyzN1 = h3simtaggedjetPt3ProngSxyzN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbintaggedjetJetPt3ProngSxyzN1 = h3simtaggedjetPt3ProngSxyzN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projtaggedjetJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyzN1Flavour->ProjectionY(Form("projtaggedjetJetPtRange3ProngSxyzN1_%d_%d", binJetPt, flavour), leftbintaggedjetJetPt3ProngSxyzN1, rightbintaggedjetJetPt3ProngSxyzN1, binFlavour, binFlavour));
          hsimtaggedjet3ProngSxyzN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange3ProngSxyzN1->Clone(Form("hsimtaggedjet3ProngSxyzN1_%d_%d", flavour, binJetPt))); 
          hsimtaggedjet3ProngSxyzN1[0][binJetPt]->Add(projtaggedjetJetPtRange3ProngSxyzN1);

          int leftbintaggedjetJetPt3ProngMassN1 = h3simtaggedjetPt3ProngMassN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbintaggedjetJetPt3ProngMassN1 = h3simtaggedjetPt3ProngMassN1Flavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projtaggedjetJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngMassN1Flavour->ProjectionY(Form("projtaggedjetJetPtRange3ProngMassN1_%d_%d", binJetPt, flavour), leftbintaggedjetJetPt3ProngMassN1, rightbintaggedjetJetPt3ProngMassN1, binFlavour, binFlavour));
          hsimtaggedjet3ProngMassN1[flavour][binJetPt] = reinterpret_cast<TH1F*>(projtaggedjetJetPtRange3ProngMassN1->Clone(Form("hsimtaggedjet3ProngMassN1_%d_%d", flavour, binJetPt))); 
          hsimtaggedjet3ProngMassN1[0][binJetPt]->Add(projtaggedjetJetPtRange3ProngMassN1);
        }
      }
    }
  }
}

void HfJetTaggingSVAnalysis::rebinHistSVMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
  }
}

void HfJetTaggingSVAnalysis::initSVMC(TString rootSim) {
  loadSimSV(rootSim.Data());
  initHistSVMC();
  projectionHistSVMC();
  std::cout << "completed initSVMC" << std::endl;
  //rebinHistSVMC();
}

void HfJetTaggingSVAnalysis::saveHistogramSVQA(TString rootFile, bool doSys) {
  TFile* fout = new TFile(rootFile, "RECREATE");
  if (!fout->IsOpen()) {
    std::cerr << "Error: Could not open the ROOT file for writing: " << rootFile << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

  if (fillData) {
    dir = fout->GetDirectory("data");
    if (!dir) {
      dir = fout->mkdir("data");
      dir->cd();
    }
    hdataEventSel->Write("hdatanEvents"); /// nEvents
    hdatajetPt->Write(); // raw yield
    TH1F* hdatajetPtRebinWidth = (TH1F*) hdatajetPtRebin->Clone("hdatajetPtRebin");
    hdatajetPtRebinWidth->Write(); // rawyield rebinning norm width
    hdatataggedjetSVEffi3ProngSxyN1[2]->Write("hdatabjetEffi"); // b-jet tagging efficiency data-driven
    hdatataggedjetSVPurity3ProngSxyN1[2]->Write("hdatabjetPurity"); // b-jet purity data-driven

    for (int binJetPt = 0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
      for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
        if (binJetPt == 0) { // inclusive
        }
        /// untagged template fit

        /// tagged template fit
      }
    }

    hdatajet3ProngCrossSection->Write("hdatabjetXSection"); // b-jet X Section
    grdatajet3ProngXSection->Write("grdatabjetXSection");
    if (doSys) {
      grdatajet3ProngXSectionSysUnfolding->Write("grdatabjetXSectionSysUnfolding");
      grdatajet3ProngXSectionSys->Write("grdatabjetXSectionSys");
    }
  }

  if (fillMCD) {
    dir = fout->GetDirectory("sim");
    if (!dir) {
      dir = fout->mkdir("sim");
      dir->cd();
    }
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetPt[flavour]->Write(Form("hsim%sjetPt", HfJetTagging::FLAVOUR[flavour].Data()));
      TH1F* hsimjetPtRebinWidth = (TH1F*) hsimjetPtRebin[flavour]->Clone();
      hsimjetPtRebinWidth->Scale(1.0, "width");
      hsimjetPtRebinWidth->Write(Form("hsim%sjetPtRebin", HfJetTagging::FLAVOUR[flavour].Data()));
      for (int binJetPt = 0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (binJetPt == 0) { // inclusive
          hsimjet3ProngMassN1[binJetPt][flavour]->Write(Form("hsim%sjetSVMass", HfJetTagging::FLAVOUR[flavour].Data()));
          hsimtaggedjet3ProngMassN1[binJetPt][flavour]->Write(Form("hsim%staggedjetSVMass", HfJetTagging::FLAVOUR[flavour].Data()));
        }
        if (binJetPt == 0) continue;
        hsimjet3ProngMassN1[binJetPt][flavour]->Write(Form("hsim%sjetSVMass_ptRagne_%f_%f", HfJetTagging::FLAVOUR[flavour].Data(), HfJetTagging::binsJetPt[binJetPt-1], HfJetTagging::binsJetPt[binJetPt]));
        //hsimtaggedjet3ProngMassN1[binJetPt][flavour]->Write(Form("hsim%staggedjetSVMass_ptRagne_%f_%f", HfJetTagging::FLAVOUR[flavour].Data(), HfJetTagging::binsJetPt[binJetPt-1], HfJetTagging::binsJetPt[binJetPt])); // binejtpt==8 it is not defined
      }
    }
    hsimtaggedjetSVEffi3ProngSxyN1[2]->Write("hsimbjetEffi");
    hsimtaggedjetSVPurity3ProngSxyN1[2]->Write("hsimbjetPurity");
    hsimjet3ProngCrossSection[2]->Write("hsimbjetXSection");
  }
}

// Set function
void HfJetTaggingSVAnalysis::setFill2Prong(bool mfill2Prong) {
  fill2Prong = mfill2Prong;
  if (fill2Prong) {
    std::cout << "2-prong analysis" << std::endl;
  }
}

void HfJetTaggingSVAnalysis::setFill3Prong(bool mfill3Prong) {
  fill3Prong = mfill3Prong;
  if (fill3Prong) {
    std::cout << "3-prong analysis" << std::endl;
  }
}

void HfJetTaggingSVAnalysis::setFillN1(bool mfillN1) {
  fillN1 = mfillN1;
  if (fillN1) {
    std::cout << "using the largeest Sxy" << std::endl;
  }
}

void HfJetTaggingSVAnalysis::setFillEffi(bool mfillEffi) {
  fillEffi = mfillEffi;
  if (fillEffi) {
    std::cout << "using cut Sxy and sigmaLxy for calcluation of efficiency" << std::endl;
  }
}

void HfJetTaggingSVAnalysis::setFillEffiWithIP(bool mfillEffiWithIP) {
  fillEffiWithIP = mfillEffiWithIP;
  if (fillEffiWithIP) {
    std::cout << "using cut Sxy and sigmaLxy for calcluation of efficiency with IP" << std::endl;
  }
}

void HfJetTaggingSVAnalysis::setSim3ProngEffiDirect(const float cutSxy) {
  std::cout << "set Efficiency of SV for 3-prong by N1 hist" << std::endl;
  int flavour = 2; // b-jet
  std::cout << "flavour: " << HfJetTagging::FLAVOURJET[flavour] << std::endl;
  for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
    if (binJetPt < 1) continue; // 0 is inclusive jet pt
    float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], hsimjetPtRebin[flavour], binJetPt, cutSxy);
    effi3ProngDirect[binJetPt] = effi;
  }
}

void HfJetTaggingSVAnalysis::setSim3ProngPurityDirect(const float cutSxy) {
  std::cout << "set Purity of SV for 3-prong by N1 hist" << std::endl;
  int flavour = 2; // b-jet
  for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
    if (binJetPt < 1) continue; // 0 is inclusive jet pt
    float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
    if (purity < 0) continue;
    purity3ProngDirect[binJetPt] = purity;
  }
}

void HfJetTaggingSVAnalysis::setSim3ProngEffiTagged(const float cutSxy) {
  std::cout << "set Efficiency of SV for 3-prong by tagged hist" << std::endl;
  int flavour = 2;
  for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
    if (binJetPt < 1) continue; // 0 is inclusive jet pt
    float effi = taggingutilities::getEfficiency(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimjetPt[flavour], binJetPt);
    if (effi < 0) continue;
    effi3ProngTagged[binJetPt] = effi;
  }
}

void HfJetTaggingSVAnalysis::setSim3ProngPurityTagged(const float cutSxy) {
  std::cout << "set Purity of SV for 3-prong by tagged hist" << std::endl;
  int flavour = 2;
  for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
    if (binJetPt < 1) continue; // 0 is inclusive jet pt
    float purity = taggingutilities::getPurity(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimtaggedjet3ProngMassN1[0][binJetPt]);
    if (purity < 0) continue;
    purity3ProngTagged[binJetPt] = purity;
  }
}

// Draw function
// Data 2-prongs
void HfJetTaggingSVAnalysis::drawData2ProngLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngLxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.5, 0.9, binJetPt);
  latexDataSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngLxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.5, 0.9, binJetPt);
  latexDataSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngsigmaLxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.5, 0.9, binJetPt);
  latexDataSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngsigmaLxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.5, 0.9, binJetPt);
  latexDataSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngSxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngSxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.5, 0.9, binJetPt);
  latexDataSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngSxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngSxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.5, 0.9, binJetPt);
  latexDataSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

// Data 3-prongs
void HfJetTaggingSVAnalysis::drawData3ProngLxy(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngLxy[binJetPt] = (TH1F*) hdatajet3ProngLxy[binJetPt]->Clone();
  hdatajetNormArea3ProngLxy[binJetPt]->Scale(1. / hdatajetNormArea3ProngLxy[binJetPt]->Integral());
  hdatajetNormNEvents3ProngLxy[binJetPt] = (TH1F*) hdatajet3ProngLxy[binJetPt]->Clone();
  hdatajetNormNEvents3ProngLxy[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngLxy[binJetPt] = (TH1F*) hdatajet3ProngLxy[binJetPt]->Clone();
  hdatajetNormNJets3ProngLxy[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngLxy[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngLxy[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngLxy[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngLxy[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 1, 5e+2*hdatajet3ProngLxy[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXY, HfJetTagging::Y_AXIS_LXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2*1/hdatajet3ProngLxy[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_LXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyNormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngLxy[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_LXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyNormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngLxyz(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngLxyz[binJetPt] = (TH1F*) hdatajet3ProngLxyz[binJetPt]->Clone();
  hdatajetNormArea3ProngLxyz[binJetPt]->Scale(1. / hdatajetNormArea3ProngLxyz[binJetPt]->Integral());
  hdatajetNormNEvents3ProngLxyz[binJetPt] = (TH1F*) hdatajet3ProngLxyz[binJetPt]->Clone();
  hdatajetNormNEvents3ProngLxyz[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngLxyz[binJetPt] = (TH1F*) hdatajet3ProngLxyz[binJetPt]->Clone();
  hdatajetNormNJets3ProngLxyz[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngLxyz[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngLxyz[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngLxyz[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngLxyz[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 1, 5e+2*hdatajet3ProngLxyz[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXYZ, HfJetTagging::Y_AXIS_LXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2*1/hdatajet3ProngLxyz[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyzNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyzNormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngLxyz[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyzNormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngsigmaLxy[binJetPt] = (TH1F*) hdatajet3ProngsigmaLxy[binJetPt]->Clone();
  hdatajetNormArea3ProngsigmaLxy[binJetPt]->Scale(1. / hdatajetNormArea3ProngsigmaLxy[binJetPt]->Integral());
  hdatajetNormNEvents3ProngsigmaLxy[binJetPt] = (TH1F*) hdatajet3ProngsigmaLxy[binJetPt]->Clone();
  hdatajetNormNEvents3ProngsigmaLxy[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngsigmaLxy[binJetPt] = (TH1F*) hdatajet3ProngsigmaLxy[binJetPt]->Clone();
  hdatajetNormNJets3ProngsigmaLxy[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngsigmaLxy[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngsigmaLxy[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngsigmaLxy[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngsigmaLxy[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 1, 5e+2*hdatajet3ProngsigmaLxy[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::Y_AXIS_SIGMALXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2*1/hdatajet3ProngsigmaLxy[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyNormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngsigmaLxy[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyNormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngsigmaLxyz[binJetPt] = (TH1F*) hdatajet3ProngsigmaLxyz[binJetPt]->Clone();
  hdatajetNormArea3ProngsigmaLxyz[binJetPt]->Scale(1. / hdatajetNormArea3ProngsigmaLxyz[binJetPt]->Integral());
  hdatajetNormNEvents3ProngsigmaLxyz[binJetPt] = (TH1F*) hdatajet3ProngsigmaLxyz[binJetPt]->Clone();
  hdatajetNormNEvents3ProngsigmaLxyz[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngsigmaLxyz[binJetPt] = (TH1F*) hdatajet3ProngsigmaLxyz[binJetPt]->Clone();
  hdatajetNormNJets3ProngsigmaLxyz[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngsigmaLxyz[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngsigmaLxyz[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngsigmaLxyz[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngsigmaLxyz[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 1, 5e+2*hdatajet3ProngsigmaLxyz[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::Y_AXIS_SIGMALXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2*1/hdatajet3ProngsigmaLxyz[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyzNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SIGMALXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyzNormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngsigmaLxyz[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SIGMALXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyzNormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingSVAnalysis::drawData3ProngSxy(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngSxy[binJetPt] = (TH1F*) hdatajet3ProngSxy[binJetPt]->Clone();
  hdatajetNormArea3ProngSxy[binJetPt]->Scale(1. / hdatajetNormArea3ProngSxy[binJetPt]->Integral());
  hdatajetNormNEvents3ProngSxy[binJetPt] = (TH1F*) hdatajet3ProngSxy[binJetPt]->Clone();
  hdatajetNormNEvents3ProngSxy[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngSxy[binJetPt] = (TH1F*) hdatajet3ProngSxy[binJetPt]->Clone();
  hdatajetNormNJets3ProngSxy[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxy[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxy[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngSxy[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngSxy[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hdatajet3ProngSxy[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hdatajet3ProngSxy[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyNormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxy[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyNormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}



void HfJetTaggingSVAnalysis::drawData3ProngSxyz(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngSxyz[binJetPt] = (TH1F*) hdatajet3ProngSxyz[binJetPt]->Clone();
  hdatajetNormArea3ProngSxyz[binJetPt]->Scale(1. / hdatajetNormArea3ProngSxyz[binJetPt]->Integral());
  hdatajetNormNEvents3ProngSxyz[binJetPt] = (TH1F*) hdatajet3ProngSxyz[binJetPt]->Clone();
  hdatajetNormNEvents3ProngSxyz[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngSxyz[binJetPt] = (TH1F*) hdatajet3ProngSxyz[binJetPt]->Clone();
  hdatajetNormNJets3ProngSxyz[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxyz[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxyz[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngSxyz[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngSxyz[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hdatajet3ProngSxyz[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hdatajet3ProngSxyz[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzNormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzNormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxyz[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzNormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngSxyN1(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngSxyN1[binJetPt] = (TH1F*) hdatajet3ProngSxyN1[binJetPt]->Clone();
  hdatajetNormArea3ProngSxyN1[binJetPt]->Scale(1. / hdatajetNormArea3ProngSxyN1[binJetPt]->Integral());
  hdatajetNormNEvents3ProngSxyN1[binJetPt] = (TH1F*) hdatajet3ProngSxyN1[binJetPt]->Clone();
  hdatajetNormNEvents3ProngSxyN1[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngSxyN1[binJetPt] = (TH1F*) hdatajet3ProngSxyN1[binJetPt]->Clone();
  hdatajetNormNJets3ProngSxyN1[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxyN1[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxyN1[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngSxyN1[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngSxyN1[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hdatajet3ProngSxyN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hdatajet3ProngSxyN1[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1NormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxyN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1NormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingSVAnalysis::drawData3ProngSxyzN1(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngSxyzN1[binJetPt] = (TH1F*) hdatajet3ProngSxyzN1[binJetPt]->Clone();
  hdatajetNormArea3ProngSxyzN1[binJetPt]->Scale(1. / hdatajetNormArea3ProngSxyzN1[binJetPt]->Integral());
  hdatajetNormNEvents3ProngSxyzN1[binJetPt] = (TH1F*) hdatajet3ProngSxyzN1[binJetPt]->Clone();
  hdatajetNormNEvents3ProngSxyzN1[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngSxyzN1[binJetPt] = (TH1F*) hdatajet3ProngSxyzN1[binJetPt]->Clone();
  hdatajetNormNJets3ProngSxyzN1[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxyzN1[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxyzN1[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngSxyzN1[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngSxyzN1[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hdatajet3ProngSxyzN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2*1/hdatajet3ProngSxyzN1[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1NormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxyzN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1NormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngMassN1(bool doLog = true, int binJetPt=0) {
  hdatajetNormArea3ProngMassN1[binJetPt] = (TH1F*) hdatajet3ProngMassN1[binJetPt]->Clone();
  hdatajetNormArea3ProngMassN1[binJetPt]->Scale(1. / hdatajetNormArea3ProngMassN1[binJetPt]->Integral());
  hdatajetNormNEvents3ProngMassN1[binJetPt] = (TH1F*) hdatajet3ProngMassN1[binJetPt]->Clone();
  hdatajetNormNEvents3ProngMassN1[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJets3ProngMassN1[binJetPt] = (TH1F*) hdatajet3ProngMassN1[binJetPt]->Clone();
  hdatajetNormNJets3ProngMassN1[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngMassN1[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngMassN1[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatajetNormNEvents3ProngMassN1[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatajetNormNJets3ProngMassN1[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, 5e+2*hdatajet3ProngMassN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2*1/hdatajet3ProngMassN1[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1NormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngMassN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1NormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingSVAnalysis::drawDatataggedjet3ProngMassN1(bool doLog = true, int binJetPt=0) {
  hdatataggedjetNormArea3ProngMassN1[binJetPt] = (TH1F*) hdatataggedjet3ProngMassN1[binJetPt]->Clone();
  hdatataggedjetNormArea3ProngMassN1[binJetPt]->Scale(1. / hdatataggedjetNormArea3ProngMassN1[binJetPt]->Integral());
  hdatataggedjetNormNEvents3ProngMassN1[binJetPt] = (TH1F*) hdatataggedjet3ProngMassN1[binJetPt]->Clone();
  hdatataggedjetNormNEvents3ProngMassN1[binJetPt]->Scale(1. / ndataEvents);
  hdatataggedjetNormNJets3ProngMassN1[binJetPt] = (TH1F*) hdatataggedjet3ProngMassN1[binJetPt]->Clone();
  hdatataggedjetNormNJets3ProngMassN1[binJetPt]->Scale(1. / ndataJets[binJetPt]);

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjet3ProngMassN1[binJetPt], ""});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormArea3ProngMassN1[binJetPt], ""});

  std::vector<HistogramData> normNEvents;
  normArea.push_back({hdatataggedjetNormNEvents3ProngMassN1[binJetPt], ""});

  std::vector<HistogramData> normNJets;
  normArea.push_back({hdatataggedjetNormNJets3ProngMassN1[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, 5e+2*hdatataggedjet3ProngMassN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngMassN1_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2*1/hdatataggedjet3ProngMassN1[binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngMassN1NormArea_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngMassN1NormEvents_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngMassN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.52, 0.9, binJetPt);
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngMassN1NormJets_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));


}

// MC 2-prongs
void HfJetTaggingSVAnalysis::drawSim2ProngLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngLxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngLxy[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngLxy[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngLxy[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngLxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngLxy[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngLxy[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngLxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngLxy[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngLxy[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 1, 5e+2*hsimjet2ProngLxy[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXY, HfJetTagging::Y_AXIS_LXY);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2*1/hsimjet2ProngLxy[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_LXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2*1/nsimJets[0][binJetPt], 5e+2*hsimjet2ProngLxy[0][binJetPt]->GetMaximum()/nsimJets[0][binJetPt], HfJetTagging::X_AXIS_LXY,Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngLxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngLxyz[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngLxyz[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngLxyz[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngLxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngLxyz[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngLxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngLxyz[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 1, 5e+2*hsimjet2ProngLxyz[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXYZ, HfJetTagging::Y_AXIS_LXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2*1/hsimjet2ProngLxyz[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyzNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyzNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyzNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngSxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxy[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngSxy[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngSxy[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngSxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxy[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngSxy[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngSxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxy[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngSxy[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hsimjet2ProngSxy[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hsimjet2ProngSxy[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngSxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyz[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngSxyz[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngSxyz[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngSxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyz[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngSxyz[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngSxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyz[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngSxyz[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hsimjet2ProngSxyz[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2*1/hsimjet2ProngSxyz[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngsigmaLxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngsigmaLxy[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngsigmaLxy[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngsigmaLxy[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngsigmaLxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngsigmaLxy[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngsigmaLxy[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngsigmaLxy[flavour][binJetPt] = (TH1F*) hsimjet2ProngsigmaLxy[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngsigmaLxy[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 1, 5e+2*hsimjet2ProngsigmaLxy[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::Y_AXIS_SIGMALXY);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2*1/hsimjet2ProngsigmaLxy[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/nsimEvents, HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/nsimJets[0][binJetPt], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingSVAnalysis::drawSim2ProngsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngsigmaLxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngsigmaLxyz[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngsigmaLxyz[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngsigmaLxyz[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngsigmaLxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngsigmaLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngsigmaLxyz[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngsigmaLxyz[flavour][binJetPt] = (TH1F*) hsimjet2ProngsigmaLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngsigmaLxyz[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 1, 5e+2*hsimjet2ProngsigmaLxyz[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::Y_AXIS_SIGMALXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2*1/hsimjet2ProngsigmaLxyz[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyzNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2/nsimEvents, HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyzNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyN1[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngSxyN1[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngSxyN1[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyN1[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngSxyN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyN1[flavour][binJetPt]->Clone();
    if (debug) {
      std::cout << "flavour: " << flavour << " binjetpt: " << binJetPt << " area: " << hsimjetNormNJets2ProngSxyN1[flavour][binJetPt]->Integral(1, hsimjetNormNJets2ProngSxyN1[flavour][binJetPt]->GetNbinsX()) << " njets: " << nsimJets[flavour][binJetPt] << std::endl;
    }
    hsimjetNormNJets2ProngSxyN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hsimjet2ProngSxyN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXYN1);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hsimjet2ProngSxyN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYN1.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYN1.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngSxyzN1[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngSxyzN1[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngSxyzN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngSxyzN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hsimjet2ProngSxyzN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZN1);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2*1/hsimjet2ProngSxyzN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZN1.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYZN1.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea2ProngMassN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngMassN1[flavour][binJetPt]->Clone();
    hsimjetNormArea2ProngMassN1[flavour][binJetPt]->Scale(1. / hsimjetNormArea2ProngMassN1[flavour][binJetPt]->Integral());
    hsimjetNormNEvents2ProngMassN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngMassN1[flavour][binJetPt]->Clone();
    hsimjetNormNEvents2ProngMassN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets2ProngMassN1[flavour][binJetPt] = (TH1F*) hsimjet2ProngMassN1[flavour][binJetPt]->Clone();
    hsimjetNormNJets2ProngMassN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet2ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet2ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet2ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet2ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea2ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea2ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea2ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea2ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents2ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents2ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets2ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets2ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets2ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets2ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-3, 5e+2*hsimjet2ProngMassN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2*1/hsimjet2ProngMassN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngMassN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngMassN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "2-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngMassN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngEffiSxyN1(const float cutSxy) {
  std::cout << "Efficiency of SV for 2-prong" << std::endl;
  std::vector<HistogramData> histList;
  histList.push_back({hsimSVEffi2ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::cout << "flavour: " << HfJetTagging::FLAVOURJET[flavour] << std::endl;
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet2ProngSxyN1[flavour][binJetPt], hsimjetPtRebin[flavour], binJetPt, cutSxy);
      float errorEffi = taggingutilities::getErrorEfficiency(hsimjet2ProngSxyN1[flavour][binJetPt], cutSxy);
      errorEffi = errorEffi/100;
      if (flavour==3) errorEffi = errorEffi/10;
      if (effi < 0) continue;
      hsimSVEffi2ProngSxyN1[flavour]->SetBinContent(binJetPt, effi);
      hsimSVEffi2ProngSxyN1[flavour]->SetBinError(binJetPt, errorEffi);
    }
    histList.push_back({hsimSVEffi2ProngSxyN1[flavour], HfJetTagging::FLAVOURJETS[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-3, 3e+1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + GEANT 4", "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("2-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngEffiSxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngPuritySxyN1(const float cutSxy) {
  std::cout << "Purity of SV for 3-prong with direct" << std::endl;
  std::vector<HistogramData> histList;
  histList.push_back({hsimSVPurity2ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjet2ProngSxyN1, cutSxy);
      float errorPurity = taggingutilities::getErrorPurity(flavour, binJetPt, hsimjet2ProngSxyN1, cutSxy);
      if (purity < 0) continue;
      hsimSVPurity2ProngSxyN1[flavour]->SetBinContent(binJetPt, purity);
      hsimSVPurity2ProngSxyN1[flavour]->SetBinError(binJetPt, errorPurity);
      if (debug) {
        std::cout << "[Purity] 3-prong "<<  HfJetTagging::FLAVOURJET[flavour]<< " jet pT: " << HfJetTagging::binsJetPt[binJetPt] << " purity: " << purity << " error of purity: " << errorPurity << std::endl;
      }
    }
    histList.push_back({hsimSVPurity2ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("2-prongs candidate (largest S#it{L}_{XY} > %0.1f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngPuritySxyzN1(const float cutSxyz) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxyz);
      if (purity < 0) continue;
      hsimSVPurity2ProngSxyzN1[flavour]->SetBinContent(binJetPt, purity);
    }
    normHist.push_back({hsimSVPurity2ProngSxyzN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngPuritySxyzN1.pdf\")", nc++, dirSim.Data()));
}

// MC 3-Prongs
void HfJetTaggingSVAnalysis::drawSim3ProngLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngLxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngLxy[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngLxy[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngLxy[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngLxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngLxy[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngLxy[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngLxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngLxy[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngLxy[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngLxy[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngLxy[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 1, 5e+2*hsimjet3ProngLxy[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXY, HfJetTagging::Y_AXIS_LXY);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2*1/hsimjet3ProngLxy[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_LXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2*1/nsimJets[0][binJetPt], 5e+2*hsimjet3ProngLxy[0][binJetPt]->GetMaximum()/nsimJets[0][binJetPt], HfJetTagging::X_AXIS_LXY,Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngLxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngLxyz[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngLxyz[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngLxyz[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngLxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngLxyz[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngLxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngLxyz[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 1, 5e+2*hsimjet3ProngLxyz[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXYZ, HfJetTagging::Y_AXIS_LXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2*1/hsimjet3ProngLxyz[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyzNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyzNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyzNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngSxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxy[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngSxy[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngSxy[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngSxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxy[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngSxy[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngSxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxy[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngSxy[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngSxy[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngSxy[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hsimjet3ProngSxy[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hsimjet3ProngSxy[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngSxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyz[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngSxyz[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngSxyz[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngSxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyz[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngSxyz[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngSxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyz[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngSxyz[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hsimjet3ProngSxyz[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2*1/hsimjet3ProngSxyz[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngsigmaLxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngsigmaLxy[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngsigmaLxy[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngsigmaLxy[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngsigmaLxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngsigmaLxy[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngsigmaLxy[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngsigmaLxy[flavour][binJetPt] = (TH1F*) hsimjet3ProngsigmaLxy[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngsigmaLxy[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 1, 5e+2*hsimjet3ProngsigmaLxy[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::Y_AXIS_SIGMALXY);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2*1/hsimjet3ProngsigmaLxy[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/nsimEvents, HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/nsimJets[0][binJetPt], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyNormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngsigmaLxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngsigmaLxyz[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngsigmaLxyz[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngsigmaLxyz[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngsigmaLxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngsigmaLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngsigmaLxyz[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngsigmaLxyz[flavour][binJetPt] = (TH1F*) hsimjet3ProngsigmaLxyz[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngsigmaLxyz[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 1, 5e+2*hsimjet3ProngsigmaLxyz[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::Y_AXIS_SIGMALXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2*1/hsimjet3ProngsigmaLxyz[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyzNormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2/nsimEvents, HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.9-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyzNormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyN1[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngSxyN1[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngSxyN1[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyN1[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngSxyN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyN1[flavour][binJetPt]->Clone();
    if (debug) {
      std::cout << "flavour: " << flavour << " binjetpt: " << binJetPt << " area: " << hsimjetNormNJets3ProngSxyN1[flavour][binJetPt]->Integral(1, hsimjetNormNJets3ProngSxyN1[flavour][binJetPt]->GetNbinsX()) << " njets: " << nsimJets[flavour][binJetPt] << std::endl;
    }
    hsimjetNormNJets3ProngSxyN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hsimjet3ProngSxyN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXYN1);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hsimjet3ProngSxyN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYN1.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYN1.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngSxyzN1[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngSxyzN1[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngSxyzN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngSxyzN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hsimjet3ProngSxyzN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZN1);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2*1/hsimjet3ProngSxyzN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZN1.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYZN1.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormArea3ProngMassN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngMassN1[flavour][binJetPt]->Clone();
    hsimjetNormArea3ProngMassN1[flavour][binJetPt]->Scale(1. / hsimjetNormArea3ProngMassN1[flavour][binJetPt]->Integral());
    hsimjetNormNEvents3ProngMassN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngMassN1[flavour][binJetPt]->Clone();
    hsimjetNormNEvents3ProngMassN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJets3ProngMassN1[flavour][binJetPt] = (TH1F*) hsimjet3ProngMassN1[flavour][binJetPt]->Clone();
    hsimjetNormNJets3ProngMassN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjet3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjet3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjet3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjet3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormArea3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormArea3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormArea3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormArea3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEvents3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEvents3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJets3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJets3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJets3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJets3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-3, 5e+2*hsimjet3ProngMassN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2*1/hsimjet3ProngMassN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyN1(const float cutSxy) {
  std::cout << "Efficiency of SV for 3-prong" << std::endl;
  std::vector<HistogramData> histList;
  histList.push_back({hsimSVEffi3ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::cout << "flavour: " << HfJetTagging::FLAVOURJET[flavour] << std::endl;
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], hsimjetPtRebin[flavour], binJetPt, cutSxy);
      float errorEffi = taggingutilities::getErrorEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], cutSxy);
      errorEffi = errorEffi/100;
      if (flavour==3) errorEffi = errorEffi/10;
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyN1[flavour]->SetBinContent(binJetPt, effi);
      hsimSVEffi3ProngSxyN1[flavour]->SetBinError(binJetPt, errorEffi);
    }
    histList.push_back({hsimSVEffi3ProngSxyN1[flavour], HfJetTagging::FLAVOURJETS[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-3, 3e+1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + GEANT 4", "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyN1wSys() {
  std::vector<HistogramData> histList;
  histList.push_back({hsimSVEffi3ProngSxyN1wSys[0], HfJetTagging::FLAVOURJET[0]});
  float arrcut[4] = {10, 20, 30, 40};

  for (int cut = 0; cut < 4; cut++) {
    int flavour = 2; // b-jet
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], hsimjetPtRebin[flavour], binJetPt, arrcut[cut]);
      //float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], arrcut[cut]);
      float errorEffi = taggingutilities::getErrorEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], arrcut[cut]);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyN1wSys[cut]->SetBinContent(binJetPt, effi);
      hsimSVEffi3ProngSxyN1wSys[cut]->SetBinError(binJetPt, errorEffi);
    }
    histList.push_back({hsimSVEffi3ProngSxyN1wSys[cut], Form("largest S#it{L}_{XY} > %0.1f", arrcut[cut])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, 1e-3, HfJetTagging::REFHIST::EFFI[1], 2e-3, HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  //latex.DrawLatex(0.17, 0.89-0.055*4, Form("3-prongs candidate (largest S#it{L}_{XY} > %0.1f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyN1wSys.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyzN1(const float cutSxyz) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyzN1[flavour][binJetPt], hsimjetPtRebin[flavour], binJetPt, cutSxyz);
      float errorEffi = taggingutilities::getErrorEfficiency(hsimjet3ProngSxyzN1[flavour][binJetPt], cutSxyz);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyzN1[flavour]->SetBinContent(binJetPt, effi);
      hsimSVEffi3ProngSxyzN1[flavour]->SetBinError(binJetPt, errorEffi);
    }
    normHist.push_back({hsimSVEffi3ProngSxyzN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, 1e-3, HfJetTagging::REFHIST::EFFI[1], 2e-3, HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("3-prongs candidate (largest S#it{L}_{XYZ} > %0.1f)", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyzN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyN1(const float cutSxy) {
  std::cout << "Purity of SV for 3-prong with direct" << std::endl;
  std::vector<HistogramData> histList;
  histList.push_back({hsimSVPurity3ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
      float errorPurity = taggingutilities::getErrorPurity(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
      if (purity < 0) continue;
      hsimSVPurity3ProngSxyN1[flavour]->SetBinContent(binJetPt, purity);
      hsimSVPurity3ProngSxyN1[flavour]->SetBinError(binJetPt, errorPurity);
      if (debug) {
        std::cout << "[Purity] 3-prong "<<  HfJetTagging::FLAVOURJET[flavour]<< " jet pT: " << HfJetTagging::binsJetPt[binJetPt] << " purity: " << purity << " error of purity: " << errorPurity << std::endl;
      }
    }
    histList.push_back({hsimSVPurity3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*4, Form("3-prongs candidate (largest S#it{L}_{XY} > %0.1f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyN1wSys() {
  std::vector<HistogramData> histList;
  histList.push_back({hsimSVPurity3ProngSxyN1wSys[0], HfJetTagging::FLAVOURJET[0]});
  float arrcut[3] = {20, 40, 60};

  for (int cut = 0; cut < 3; cut++) {
    int flavour = 2; // b-jet
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjet3ProngSxyN1, arrcut[cut]);
      float errorPurity = taggingutilities::getErrorPurity(flavour, binJetPt, hsimjet3ProngSxyN1, arrcut[cut]);
      errorPurity = errorPurity/10;
      if (purity < 0) continue;
      hsimSVPurity3ProngSxyN1wSys[cut]->SetBinContent(binJetPt, purity);
      hsimSVPurity3ProngSxyN1wSys[cut]->SetBinError(binJetPt, errorPurity);
    }
    histList.push_back({hsimSVPurity3ProngSxyN1wSys[cut], Form("largest #it{S}(#it{L}_{#it{xy}}) > %.0f", arrcut[cut])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  //gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 0.13, 0.6, HfJetTagging::X_AXIS_JETPT, "b-jet purity");
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0]-0.05, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + GEANT 4", "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  //latex.DrawLatex(0.17, 0.89-0.055*4, Form("3-prongs candidate (largest S#it{L}_{XY} > %0.1f)", cutSxy));
  latex.DrawLatex(0.17, 0.89-0.055*5, "3-prong secondary-vertex candidate");
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyN1wSys.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyzN1(const float cutSxyz) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getPurity(hsimjet3ProngSxyzN1[flavour][binJetPt], hsimjet3ProngSxyzN1[0][binJetPt]);
      if (effi < 0) continue;
      hsimSVPurity3ProngSxyzN1[flavour]->SetBinContent(binJetPt, effi);
    }
    normHist.push_back({hsimSVPurity3ProngSxyzN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyzN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyN1Tagger(int binJetPt) {
  //if (binJetPt < 1) return; // 0 is inclusive jet pt
  std::vector<HistogramData> histList;
  int flavour = 2; // bjet

  for (int binTagger=0; binTagger<HfJetTagging::numTaggerSV; binTagger++) {
    float cutSxy = HfJetTagging::SYS::binsTaggerSV[binTagger];
    float effi = taggingutilities::getEfficiency(hsimjetPt[flavour], hsimjet3ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
    std::cout << "effi: " << effi << std::endl; hsimSVEffi3ProngSxyTaggerPoint[flavour][binJetPt]->SetBinContent(binTagger+1, effi);
  }
  histList.push_back({hsimSVEffi3ProngSxyTaggerPoint[flavour][binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::xlowTaggerSV, HfJetTagging::xupTaggerSV + HfJetTagging::binWidthTaggerSV, HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], "tagger point (S#it{L}_{xy})", HfJetTagging::AXIS_BEAUTY_EFFI);
  canHan->drawCombined(histList.size(), histList, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/EffiTaggerRange_%d.pdf\")", nc++, dirSim.Data(), binJetPt));

}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyN1Tagger(int binJetPt) {
  //if (binJetPt < 1) return; // 0 is inclusive jet pt
  std::vector<HistogramData> histList;
  int flavour = 2; // bjet

  //std::cout << "Purity as tagger point range jet pT: " << HfJetTagging::binsJetPt[binJetPt] << std::endl;
  for (int binTagger=0; binTagger<HfJetTagging::numTaggerSV; binTagger++) {
    float cutSxy = HfJetTagging::SYS::binsTaggerSV[binTagger];
    float purity = taggingutilities::getPurity(binJetPt, flavour, hsimjet3ProngSxyN1, cutSxy);
    std::cout << "Purity: " << purity << std::endl;
    hsimSVPurity3ProngSxyTaggerPoint[flavour][binJetPt]->SetBinContent(binTagger+1, purity);
  }
  histList.push_back({hsimSVPurity3ProngSxyTaggerPoint[flavour][binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::xlowTaggerSV, HfJetTagging::xupTaggerSV + HfJetTagging::binWidthTaggerSV, HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], "tagger point (S#it{L}_{xy})", HfJetTagging::AXIS_BEAUTY_PURITY);
  canHan->drawCombined(histList.size(), histList, true, true, HfJetTagging::LEG[0]+0.1, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/PurityTaggerRange_%d.pdf\")", nc++, dirSim.Data(), binJetPt));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiAndPuritySxyN1(const float cutSxy) {
  std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjetPt[flavour], hsimjet3ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
      float purity = taggingutilities::getPurity(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
      if (effi < 0 || purity < 0) continue;
      hsimSVEffiAndPurity3ProngSxyN1[flavour]->SetBinContent(binJetPt, purity / effi);
    }
    normHist.push_back({hsimSVEffiAndPurity3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], 10, HfJetTagging::X_AXIS_JETPT, "#frac{P}{#epsillon}");
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiAndPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngSxyN1(bool withInc, bool doLog, int binJetPt) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormArea3ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngSxyN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormArea3ProngSxyN1[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormArea3ProngSxyN1[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEvents3ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngSxyN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEvents3ProngSxyN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJets3ProngSxyN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngSxyN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJets3ProngSxyN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjet3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjet3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjet3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjet3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hsimtaggedjet3ProngSxyN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXYN1);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2*1/hsimtaggedjet3ProngSxyN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYN1.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYN1.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngSxyzN1(bool withInc, bool doLog, int binJetPt) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormArea3ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormArea3ProngSxyzN1[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormArea3ProngSxyzN1[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEvents3ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEvents3ProngSxyzN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJets3ProngSxyzN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngSxyzN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJets3ProngSxyzN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjet3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjet3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjet3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjet3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hsimtaggedjet3ProngSxyzN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZN1);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2*1/hsimtaggedjet3ProngSxyzN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyzN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZN1.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyzN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_SXYZN1.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngSxyzN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngMassN1(bool withInc, bool doLog, int binJetPt) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtaggedjetNormArea3ProngMassN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngMassN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormArea3ProngMassN1[flavour][binJetPt]->Scale(1. / hsimtaggedjetNormArea3ProngMassN1[flavour][binJetPt]->Integral());
    hsimtaggedjetNormNEvents3ProngMassN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngMassN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNEvents3ProngMassN1[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimtaggedjetNormNJets3ProngMassN1[flavour][binJetPt] = (TH1F*) hsimtaggedjet3ProngMassN1[flavour][binJetPt]->Clone();
    hsimtaggedjetNormNJets3ProngMassN1[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtaggedjet3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtaggedjet3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtaggedjet3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtaggedjet3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtaggedjetNormArea3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimtaggedjetNormArea3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtaggedjetNormNJets3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, 5e+2*hsimtaggedjet3ProngMassN1[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2*1/hsimtaggedjet3ProngMassN1[0][binJetPt]->GetMaximum(), 1, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngMassN1NormArea_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngMassN1NormNEvents_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/nsimJets[0][binJetPt], 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.52, 0.89, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.52, 0.89-0.055*5, "tagged jet, 3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngMassN1NormNJets_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngEffiMassN1(const float cutSxy) {
  std::cout << "Efficiency of SV for 3-prong by tagger hist" << std::endl;
  std::vector<HistogramData> histList;
  histList.push_back({hsimtaggedjetSVEffi3ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::cout << "flavour : " << HfJetTagging::FLAVOURJET[flavour] << std::endl;
    hsimtaggedjetSVEffi3ProngSxyN1[flavour]->Sumw2();
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimjetPt[flavour], binJetPt);
      float errorEffi = taggingutilities::getEfficiency(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimjetPt[flavour], binJetPt);
      //float errorEffi = taggingutilities::getErrorEfficiency(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimjet3ProngMassN1[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimtaggedjetSVEffi3ProngSxyN1[flavour]->SetBinContent(binJetPt, effi);
      hsimtaggedjetSVEffi3ProngSxyN1[flavour]->SetBinError(binJetPt, errorEffi);
      //hsimtaggedjetSVEffi3ProngSxyN1[flavour]->SetBinError(binJetPt, 0.01f);
    }
    histList.push_back({hsimtaggedjetSVEffi3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-3, 3e+1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngPurityMassN1(const float cutSxy) {
  std::cout << "Purity of SV for 3-prong with tagged jet" << std::endl;
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtaggedjetSVPurity3ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity =  taggingutilities::getPurity(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimtaggedjet3ProngMassN1[0][binJetPt]);
      float errorPurity =  taggingutilities::getErrorPurity(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimtaggedjet3ProngMassN1[0][binJetPt]);
      if (purity < 0) continue;
      hsimtaggedjetSVPurity3ProngSxyN1[flavour]->SetBinContent(binJetPt, purity);
      hsimtaggedjetSVPurity3ProngSxyN1[flavour]->SetBinError(binJetPt, errorPurity);
      if (debug) {
        std::cout << "[Purity] 3-prong "<<  HfJetTagging::FLAVOURJET[flavour]<< " jet pT: " << HfJetTagging::binsJetPt[binJetPt] << " purity: " << purity << " error of purity: " << errorPurity << std::endl;
      }
    }
    normHist.push_back({hsimtaggedjetSVPurity3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

// DataVsSim 2-Prongs
void HfJetTaggingSVAnalysis::drawDataVsSim2ProngLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormArea2ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormArea2ProngLxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormArea2ProngLxy[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim2ProngLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormArea2ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormArea2ProngLxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormArea2ProngLxyz[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim2ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormArea2ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormArea2ProngsigmaLxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormArea2ProngsigmaLxy[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim2ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormArea2ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormArea2ProngsigmaLxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormArea2ProngsigmaLxyz[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim2ProngSxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormArea2ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormArea2ProngSxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormArea2ProngSxy[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim2ProngSxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormArea2ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormArea2ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormArea2ProngSxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormArea2ProngSxyz[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

// DataVsSim 3-Prongs
void HfJetTaggingSVAnalysis::drawDataVsSim3ProngLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormArea3ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormArea3ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormArea3ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormArea3ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngLxy[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngLxy[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngLxy[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngLxy[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngLxy[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngLxy[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngLxy[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngLxy[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 1, 5e+2*hdatajet3ProngLxy[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXY, HfJetTagging::Y_AXIS_LXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 0, 2, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-4*((float) 1 / hdatajet3ProngLxy[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 0, 2, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_LXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 0, 2, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngLxy[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_LXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], 0, 2, HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormArea3ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormArea3ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormArea3ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormArea3ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngLxyz[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngLxyz[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngLxyz[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngLxyz[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngLxyz[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngLxyz[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngLxyz[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngLxyz[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 1, 5e+2*hdatajet3ProngLxyz[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_LXYZ, HfJetTagging::Y_AXIS_LXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 0, 2, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-4*((float) 1 / hdatajet3ProngLxyz[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 0, 2, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 0, 2, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngLxyz[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_LXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_LXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], 0, 2, HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormArea3ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormArea3ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormArea3ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormArea3ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngsigmaLxy[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngsigmaLxy[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngsigmaLxy[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngsigmaLxy[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngsigmaLxy[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngsigmaLxy[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngsigmaLxy[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngsigmaLxy[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 1, 5e+2*hdatajet3ProngsigmaLxy[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::Y_AXIS_SIGMALXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-4*((float) 1 / hdatajet3ProngsigmaLxy[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreasigmaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventssigmaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngsigmaLxy[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SIGMALXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetssigmaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormArea3ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormArea3ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormArea3ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormArea3ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngsigmaLxyz[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngsigmaLxyz[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngsigmaLxyz[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngsigmaLxyz[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngsigmaLxyz[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngsigmaLxyz[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngsigmaLxyz[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngsigmaLxyz[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 1, 5e+2*hdatajet3ProngsigmaLxyz[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::Y_AXIS_SIGMALXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-4*((float) 1 / hdatajet3ProngsigmaLxyz[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreasigmaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SIGMALXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventssigmaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngsigmaLxyz[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SIGMALXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SIGMALXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], 0, 2, HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetssigmaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormArea3ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormArea3ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormArea3ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormArea3ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngSxy[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngSxy[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngSxy[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngSxy[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngSxy[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngSxy[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngSxy[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngSxy[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hdatajet3ProngSxy[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-4*((float) 1 / hdatajet3ProngSxy[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaSxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsSxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxy[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsSxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEvents3ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJets3ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormNJets3ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngSxyz[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngSxyz[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngSxyz[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngSxyz[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngSxyz[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngSxyz[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngSxyz[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngSxyz[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hdatajet3ProngSxyz[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-4*((float) 1 / hdatajet3ProngSxyz[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaSxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsSxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxyz[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsSxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxyN1(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxyN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngSxyN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxyN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngSxyN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEvents3ProngSxyN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJets3ProngSxyN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormNJets3ProngSxyN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngSxyN1[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngSxyN1[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngSxyN1[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngSxyN1[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngSxyN1[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngSxyN1[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngSxyN1[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngSxyN1[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 1, 5e+2*hdatajet3ProngSxyN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXY, HfJetTagging::Y_AXIS_SXY);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-4*((float) 1 / hdatajet3ProngSxyN1[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaSxyN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsSxyN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxyN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXY, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXY.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], 0, 2, HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsSxyN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxyzN1(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngSxyzN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngSxyzN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngSxyzN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngSxyzN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEvents3ProngSxyzN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormNEvents3ProngSxyzN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJets3ProngSxyzN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormNJets3ProngSxyzN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngSxyzN1[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngSxyzN1[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngSxyzN1[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngSxyzN1[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngSxyzN1[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngSxyzN1[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngSxyzN1[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngSxyzN1[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 1, 5e+2*hdatajet3ProngSxyzN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_SXYZ, HfJetTagging::Y_AXIS_SXYZ);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-4*((float) 1 / hdatajet3ProngSxyzN1[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaSxyzN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsSxyzN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngSxyzN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_SXYZ, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_SXYZ.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], 0, 2, HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsSxyzN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngMassN1(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajet3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjet3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormArea3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormArea3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEvents3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormNEvents3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJets3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormNJets3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatajet3ProngMassN1[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetNormArea3ProngMassN1[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetNormNEvents3ProngMassN1[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetNormNJets3ProngMassN1[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimjet3ProngMassN1[0][binJetPt]);
  hRatioNormArea->Divide(hsimjetNormArea3ProngMassN1[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimjetNormNEvents3ProngMassN1[0][binJetPt]);
  hRatioNormNJets->Divide(hsimjetNormNJets3ProngMassN1[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, 5e+2*hdatajet3ProngMassN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-4*((float) 1 / hdatajet3ProngMassN1[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNEventsMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatajet3ProngMassN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormNJetsMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSimtaggedjet3ProngMassN1(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatataggedjet3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimtaggedjet3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatataggedjetNormArea3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimtaggedjetNormArea3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatataggedjetNormNEvents3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimtaggedjetNormNEvents3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatataggedjetNormNJets3ProngMassN1[binJetPt], Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimtaggedjetNormNJets3ProngMassN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hdatataggedjet3ProngMassN1[binJetPt]->Clone("hRatioRawHist"));
  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatataggedjetNormArea3ProngMassN1[binJetPt]->Clone("hRatioNormArea"));
  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatataggedjetNormNEvents3ProngMassN1[binJetPt]->Clone("hRatioNormNEvents"));
  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatataggedjetNormNJets3ProngMassN1[binJetPt]->Clone("hRatioNormNJets"));
  hRatioRawHist->Divide(hsimtaggedjet3ProngMassN1[0][binJetPt]);
  hRatioNormArea->Divide(hsimtaggedjetNormArea3ProngMassN1[0][binJetPt]);
  hRatioNormNEvents->Divide(hsimtaggedjetNormNEvents3ProngMassN1[0][binJetPt]);
  hRatioNormNJets->Divide(hsimtaggedjetNormNJets3ProngMassN1[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, 5e+2*hdatataggedjet3ProngMassN1[binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_MASS, HfJetTagging::Y_AXIS_MASS);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 3e-1*((float) 1 / hdatataggedjet3ProngMassN1[binJetPt]->GetMaximum()), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngNormAreaMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataEvents, 1, HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngNormNEventsMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 5e-2/ndataJets[binJetPt], 5e+2*hdatataggedjet3ProngMassN1[binJetPt]->GetMaximum()/ndataJets[binJetPt], HfJetTagging::X_AXIS_MASS, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_MASS.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.94-0.055*5, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 0, 2, HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet3ProngNormNJetsMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawTemplateFitMCN1() {
std::cout << "line: " << __LINE__ << std::endl;
  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.1, 5);

  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;
    TH1F* hsimincjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[0][binJetPt]->Clone();
    TH1F* hsimcjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[1][binJetPt]->Clone();
    TH1F* hsimbjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[2][binJetPt]->Clone();
    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[3][binJetPt]->Clone();
    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
    RooDataHist mcbjetMass("mcbjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);

    int incjetMassYield = mccjetMass.sumEntries()+mcbjetMass.sumEntries()+mclfjetMass.sumEntries();
    RooRealVar cjetMassYield("cjetMassYield", "cjet Yield", hsimjet3ProngMassN1[1][0]->Integral(1, hsimcjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar bjetMassYield("bjetMassYield", "bjet Yield", hsimjet3ProngMassN1[2][0]->Integral(1, hsimbjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar lfjetMassYield("lfjetMassYield", "lfjet Yield", hsimjet3ProngMassN1[3][0]->Integral(1, hsimlfjet3ProngMass->GetNbinsX()), 0, incjetMassYield);

    RooAddPdf modelFitMC("modelFitMC", "Total PDF", RooArgList(histPdfcjetMass, histPdfbjetMass, histPdflfjetMass), RooArgList(cjetMassYield, bjetMassYield, lfjetMassYield));
    std::cout << "START MC FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetMassYield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetMassYield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetMassYield.getVal() << std::endl;
    if (lfjetMassYield.getVal()<1) {
      std::cout<< "Fit failed" << std::endl;
      continue;
    }
    RooFitResult* fitMC = nullptr;
    fitMC = modelFitMC.fitTo(mcincjetMass, RooFit::Minos(kTRUE), RooFit::Save(true));
    std::cout << "END MC FITTING" << std::endl;
    std::cout<<"fit MC: " << std::endl;
    fitMC->Print();

    RooPlot* frameMC = mass.frame();
    mcincjetMass.plotOn(frameMC, RooFit::DrawOption(""), RooFit::Name("InclusiveJet"));
    //modelFitMC.plotOn(frameMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("TotalFit"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfcjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kGreen+3), RooFit::Name("CharmJetComponent"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfbjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kRed+1), RooFit::Name("BottomJetComponent"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdflfjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kBlue+1), RooFit::Name("LightFlavorJetComponent"));

    frameMC->GetXaxis()->SetTitle(HfJetTagging::X_AXIS_MASS);  // X-axis title
    frameMC->GetXaxis()->SetLabelSize(0.045);                   // X-axis label size
    frameMC->GetXaxis()->SetTitleOffset(1.1);                  // X-axis title offset
    frameMC->GetXaxis()->SetTitleSize(0.05);                   // X-axis title size

    frameMC->GetYaxis()->SetTitle("Counts");    // Y-axis title
    frameMC->GetYaxis()->SetLabelSize(0.045);                   // Y-axis label size
    frameMC->GetYaxis()->SetTitleOffset(1.15);                 // Y-axis title offset
    frameMC->GetYaxis()->SetTitleSize(0.05);                   // Y-axis title size
    frameMC->GetYaxis()->SetRangeUser(5e-3, incjetMassYield);
    frameMC->GetXaxis()->SetRangeUser(0.25, 5);

    TLegend* legend = new TLegend(0.17, 0.2, 0.4, 0.4);  // (x1, y1, x2, y2) for legend position
    legend->SetBorderSize(0);  // No border
    legend->SetFillColor(0);   // Transparent background
    legend->SetTextSize(0.045); // Text size

    legend->AddEntry(frameMC->findObject("InclusiveJet"), HfJetTagging::INCJET, "lep");
    //legend->AddEntry(frameMC->findObject("TotalFit"), "Fit", "l");
    legend->AddEntry(frameMC->findObject("CharmJetComponent"), HfJetTagging::CJET, "l");
    legend->AddEntry(frameMC->findObject("BottomJetComponent"), HfJetTagging::BJET, "l");
    legend->AddEntry(frameMC->findObject("LightFlavorJetComponent"), HfJetTagging::LFJET, "l");

    hsimjet3ProngFlavourFraction[2]->SetBinContent(binJetPt, (float) (bjetMassYield.getVal() / (cjetMassYield.getVal() + bjetMassYield.getVal() + lfjetMassYield.getVal())));

    canHan = new CanvasHandler();
    canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.02);
    gPad->SetLogy();
    //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
    //gROOT->ProcessLine(Form("cc%d->cd()", nc));
    frameMC->Draw();
    legend->Draw();
    latexSimJetInfoForSV(0.49, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.49, 0.89-0.055*5, "untagged jet (largest S#it{L}_{XY})");
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSVAnalysis::drawTemplateFitMCtaggedjetN1(float const cutSxy=40) {
  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.1, 5);

  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;
    TH1F* hsimincjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[0][binJetPt]->Clone();
    TH1F* hsimcjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[1][binJetPt]->Clone();
    TH1F* hsimbjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[2][binJetPt]->Clone();
    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[3][binJetPt]->Clone();
    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
    RooDataHist mcbjetMass("mcbjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);

    int incjetMassYield = mccjetMass.sumEntries()+mcbjetMass.sumEntries()+mclfjetMass.sumEntries();
    RooRealVar cjetMassYield("cjetMassYield", "cjet Yield", hsimtaggedjet3ProngMassN1[1][0]->Integral(1, hsimcjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar bjetMassYield("bjetMassYield", "bjet Yield", hsimtaggedjet3ProngMassN1[2][0]->Integral(1, hsimbjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar lfjetMassYield("lfjetMassYield", "lfjet Yield", hsimtaggedjet3ProngMassN1[3][0]->Integral(1, hsimlfjet3ProngMass->GetNbinsX()), 0, incjetMassYield);

    RooAddPdf modelFitMC("modelFitMC", "Total PDF", RooArgList(histPdfcjetMass, histPdfbjetMass, histPdflfjetMass), RooArgList(cjetMassYield, bjetMassYield, lfjetMassYield));
    std::cout << "START MC FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetMassYield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetMassYield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetMassYield.getVal() << std::endl;
    if (lfjetMassYield.getVal()<1) {
      std::cout<< "Fit failed" << std::endl;
      continue;
    }
    RooFitResult* fitMC = nullptr;
    fitMC = modelFitMC.fitTo(mcincjetMass, RooFit::Minos(kTRUE), RooFit::Save(true));
    std::cout << "END MC FITTING" << std::endl;
    std::cout<<"fit MC: " << std::endl;
    fitMC->Print();

    RooPlot* frameMC = mass.frame();
    mcincjetMass.plotOn(frameMC, RooFit::DrawOption(""), RooFit::Name("InclusiveJet"));
    //modelFitMC.plotOn(frameMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("TotalFit"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfcjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kGreen+3), RooFit::Name("CharmJetComponent"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfbjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kRed+1), RooFit::Name("BottomJetComponent"));
    modelFitMC.plotOn(frameMC, RooFit::Components("histPdflfjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kBlue+1), RooFit::Name("LightFlavorJetComponent"));

    frameMC->GetXaxis()->SetTitle(HfJetTagging::X_AXIS_MASS);  // X-axis title
    frameMC->GetXaxis()->SetLabelSize(0.045);                   // X-axis label size
    frameMC->GetXaxis()->SetTitleOffset(1.1);                  // X-axis title offset
    frameMC->GetXaxis()->SetTitleSize(0.05);                   // X-axis title size

    frameMC->GetYaxis()->SetTitle("Counts");    // Y-axis title
    frameMC->GetYaxis()->SetLabelSize(0.045);                   // Y-axis label size
    frameMC->GetYaxis()->SetTitleOffset(1.15);                 // Y-axis title offset
    frameMC->GetYaxis()->SetTitleSize(0.05);                   // Y-axis title size
    frameMC->GetYaxis()->SetRangeUser(5e-3, incjetMassYield);
    frameMC->GetXaxis()->SetRangeUser(0.25, 5);

    TLegend* legend = new TLegend(0.17, 0.2, 0.4, 0.4);  // (x1, y1, x2, y2) for legend position
    legend->SetBorderSize(0);  // No border
    legend->SetFillColor(0);   // Transparent background
    legend->SetTextSize(0.045); // Text size

    legend->AddEntry(frameMC->findObject("InclusiveJet"), HfJetTagging::INCJET, "lep");
    //legend->AddEntry(frameMC->findObject("TotalFit"), "Fit", "l");
    legend->AddEntry(frameMC->findObject("CharmJetComponent"), HfJetTagging::CJET, "l");
    legend->AddEntry(frameMC->findObject("BottomJetComponent"), HfJetTagging::BJET, "l");
    legend->AddEntry(frameMC->findObject("LightFlavorJetComponent"), HfJetTagging::LFJET, "l");

    canHan = new CanvasHandler();
    canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.02);
    gPad->SetLogy();
    //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
    //gROOT->ProcessLine(Form("cc%d->cd()", nc));
    frameMC->Draw();
    legend->Draw();
    latexSimJetInfoForSV(0.47, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.47, 0.89-0.055*5, Form("tagged jet (largest S#it{L}_{XY} > %0.f)", cutSxy));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/templatetaggedjet3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSVAnalysis::drawTemplateFitDataWithMCtaggedjetN1() {
  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.0, 10.0);

  /// For test jet pT template
  TH1F* hdataincjetPt = (TH1F*) hdatajetPt->Clone();
  TH1F* hsimincjetPt = (TH1F*)  hsimjetPt[0]->Clone();
  TH1F* hsimcjetPt = (TH1F*)  hsimjetPt[1]->Clone();
  TH1F* hsimbjetPt = (TH1F*)  hsimjetPt[2]->Clone();
  TH1F* hsimlfjetPt = (TH1F*)  hsimjetPt[3]->Clone();

  ///
  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;

    // for untagged jet
    TH1F* hdataincjet3ProngMass = (TH1F*) hdatajet3ProngMassN1[binJetPt]->Clone();
    TH1F* hsimincjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[0][binJetPt]->Clone();
    TH1F* hsimcjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[1][binJetPt]->Clone();
    TH1F* hsimbjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[2][binJetPt]->Clone();
    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[3][binJetPt]->Clone();
    RooDataHist dataincjetMass("dataincjetMass", "Data", mass, RooFit::Import(*hdataincjet3ProngMass)); 
    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
    RooDataHist mcbjetMass("mcbjetMass", "beauty jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);

    double cYieldMC  = hsimcjet3ProngMass->Integral();
    double bYieldMC  = hsimbjet3ProngMass->Integral();
    double lfYieldMC = hsimlfjet3ProngMass->Integral();
    double totalMCYield = cYieldMC + bYieldMC + lfYieldMC;

    double fracC_MC = cYieldMC / totalMCYield;
    double fracB_MC = bYieldMC / totalMCYield;
    double fracLF_MC = lfYieldMC / totalMCYield;
    std::cout << "fraction of charm jet: " << fracC_MC << std::endl;
    std::cout << "fraction of beauty jet: " << fracB_MC << std::endl;
    RooRealVar global_b("global_b", "global b prior", fracB_MC);
    RooRealVar global_c("global_c", "global c prior", fracC_MC);

    RooRealVar cjetMassFrac("cjetMassFrac", "cjet fraction", fracC_MC, 0.0, 1.0);
    RooRealVar bjetMassFrac("bjetMassFrac", "bjet fraction", fracB_MC, 0.0, 1.0);
    RooFormulaVar lfjetMassFrac("lfjetMassFrac", "1 - c - b", "1 - cjetMassFrac - bjetMassFrac", RooArgList(cjetMassFrac, bjetMassFrac));

    float powerPrior = 0.01;
    RooGaussian priorB("priorB", "Prior on b", bjetMassFrac, RooFit::RooConst(fracB_MC), RooFit::RooConst(powerPrior));
    RooGaussian priorC("priorC", "Prior on c", cjetMassFrac, RooFit::RooConst(fracC_MC), RooFit::RooConst(powerPrior));

    int incjetMassYield = dataincjetMass.sumEntries();
    RooRealVar totalYield("totalYield", "Total yield", incjetMassYield, 0.5 * incjetMassYield, 1.5 * incjetMassYield);
    RooFormulaVar cjetMassYield("cjetMassYield", "", "@0 * @1", RooArgList(cjetMassFrac, totalYield));
    RooFormulaVar bjetMassYield("bjetMassYield", "", "@0 * @1", RooArgList(bjetMassFrac, totalYield));
    RooFormulaVar lfjetMassYield("lfjetMassYield", "", "@0 * @1", RooArgList(lfjetMassFrac, totalYield));

    RooAddPdf modelMC("modelMC", "Total PDF", RooArgList(histPdfcjetMass, histPdfbjetMass, histPdflfjetMass), RooArgList(cjetMassYield, bjetMassYield, lfjetMassYield));
    RooProdPdf totalModel("totalModel", "Model with priors", RooArgSet(modelMC, priorB, priorC));
    std::cout << "START MC FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetMassYield.getVal() << " fraction: " << fracC_MC << std::endl;
    std::cout << "bjet yield before: " << bjetMassYield.getVal() << " fraction: " << fracB_MC << std::endl;
    std::cout << "lfjet yield before: " << lfjetMassYield.getVal() << " fraction: " << fracLF_MC << std::endl;
    if (lfjetMassYield.getVal() < 1) {
      std::cout<< "Fit failed" << std::endl;
      continue;
    }
    RooFitResult* fitMinosData = nullptr;
    //fitMinosData = modelMC.fitTo(dataincjetMass, RooFit::Hesse(kTRUE), RooFit::Minos(kTRUE), RooFit::Save(true));
    //fitMinosData = totalModel.fitTo(dataincjetMass, RooFit::Hesse(kTRUE), RooFit::Minos(kTRUE), RooFit::Save(true));
    fitMinosData = totalModel.fitTo(dataincjetMass, RooFit::Save(true));
    std::cout << "END DATA FITTING" << std::endl;
    std::cout<<"fit Data: " << std::endl;
    fitMinosData->Print();
    double cYieldData = cjetMassYield.getVal();
    double bYieldData = bjetMassYield.getVal();
    double lfYieldData = lfjetMassYield.getVal();
    double totalDataYield =  cYieldData + bYieldData + lfYieldData;
    double fracC_Data = cYieldData / totalDataYield;
    double fracB_Data = bYieldData / totalDataYield;
    double fracLF_Data = lfYieldData / totalDataYield;
    std::cout << "cjet yield after: " << cjetMassYield.getVal() << " fraction: " << fracC_Data << std::endl;
    std::cout << "bjet yield after: " << bjetMassYield.getVal() << " fraction: " << fracB_Data << std::endl;
    std::cout << "lfjet yield after: " << lfjetMassYield.getVal() << " fraction: " << fracLF_Data << std::endl;

    hsimjet3ProngFlavourFraction[2]->SetBinContent(binJetPt, fracB_MC);
    hsimjet3ProngFlavourFraction[2]->SetBinError(binJetPt, 0.001f); // temp
    //hdatajet3ProngFlavourFraction[1]->SetBinContent(binJetPt, fracC_Data);
    hdatajet3ProngFlavourFraction[2]->SetBinContent(binJetPt, fracB_Data);
    hdatajet3ProngFlavourFraction[2]->SetBinError(binJetPt, 0.001f); // temp
    //hdatajet3ProngFlavourFraction[3]->SetBinContent(binJetPt, fracLF_Data);

    RooPlot* frameDataWithMC = mass.frame();
    dataincjetMass.plotOn(frameDataWithMC, RooFit::DrawOption(""), RooFit::Name("InclusiveJetData"));
//    modelMC.plotOn(frameDataWithMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("TotalFit"));
//    modelMC.plotOn(frameDataWithMC, RooFit::Components("histPdfcjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kGreen+3), RooFit::Name("CharmJetComponent"));
//    modelMC.plotOn(frameDataWithMC, RooFit::Components("histPdfbjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kRed+1), RooFit::Name("BottomJetComponent"));
//    modelMC.plotOn(frameDataWithMC, RooFit::Components("histPdflfjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kBlue+1), RooFit::Name("LightFlavorJetComponent"));
    totalModel.plotOn(frameDataWithMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("TotalFit"));
    totalModel.plotOn(frameDataWithMC, RooFit::Components("histPdfcjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kGreen+3), RooFit::Name("CharmJetComponent"));
    totalModel.plotOn(frameDataWithMC, RooFit::Components("histPdfbjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kRed+1), RooFit::Name("BottomJetComponent"));
    totalModel.plotOn(frameDataWithMC, RooFit::Components("histPdflfjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kBlue+1), RooFit::Name("LightFlavorJetComponent"));

    double pull = (bjetMassFrac.getVal() - fracB_MC) / bjetMassFrac.getError();
    std::cout << "Pull from prior: " << pull << std::endl;
    std::cout << "Prior mean: " << fracB_MC << std::endl;
    std::cout << "Fit result: " << bjetMassFrac.getVal() << " ± " << bjetMassFrac.getError() << std::endl;

    frameDataWithMC->GetXaxis()->SetTitle(HfJetTagging::X_AXIS_MASS);  // X-axis title
    frameDataWithMC->GetXaxis()->SetLabelSize(0.045);                   // X-axis label size
    frameDataWithMC->GetXaxis()->SetTitleOffset(1.1);                  // X-axis title offset
    frameDataWithMC->GetXaxis()->SetTitleSize(0.05);                   // X-axis title size
    frameDataWithMC->GetXaxis()->SetRangeUser(0.25, 5);

    frameDataWithMC->GetYaxis()->SetTitle("Counts");    // Y-axis title
    frameDataWithMC->GetYaxis()->SetLabelSize(0.045);                   // Y-axis label size
    frameDataWithMC->GetYaxis()->SetTitleOffset(1.15);                 // Y-axis title offset
    frameDataWithMC->GetYaxis()->SetTitleSize(0.05);                   // Y-axis title size
    frameDataWithMC->GetYaxis()->SetRangeUser(1.01, incjetMassYield);

    TLegend* legend = new TLegend(0.17, 0.2, 0.4, 0.4);  // (x1, y1, x2, y2) for legend position
    legend->SetBorderSize(0);  // No border
    legend->SetFillColor(0);   // Transparent background
    legend->SetTextSize(0.045); // Text size

    legend->AddEntry(frameDataWithMC->findObject("InclusiveJetDat"), HfJetTagging::INCJET, "lep");
    legend->AddEntry(frameDataWithMC->findObject("TotalFit"), "Fit", "l");
    legend->AddEntry(frameDataWithMC->findObject("CharmJetComponent"), HfJetTagging::CJET, "l");
    legend->AddEntry(frameDataWithMC->findObject("BottomJetComponent"), HfJetTagging::BJET, "l");
    legend->AddEntry(frameDataWithMC->findObject("LightFlavorJetComponent"), HfJetTagging::LFJET, "l");

    canHan = new CanvasHandler();
    canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.02);
    gPad->SetLogy();
    //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
    //gROOT->ProcessLine(Form("cc%d->cd()", nc));
    frameDataWithMC->Draw();
    legend->Draw();
    latexSimJetInfoForSV(0.49, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.49, 0.89-0.055*5, "untagged jet (largest S#it{L}_{XY})");
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template3ProngMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    // For tagged jet
    TH1F* hdatataggedincjet3ProngMass = (TH1F*) hdatataggedjet3ProngMassN1[binJetPt]->Clone();
    TH1F* hsimtaggedincjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[0][binJetPt]->Clone();
    TH1F* hsimtaggedcjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[1][binJetPt]->Clone();
    TH1F* hsimtaggedbjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[2][binJetPt]->Clone();
    TH1F* hsimtaggedlfjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1[3][binJetPt]->Clone();
    RooDataHist datataggedincjetMass("datataggedincjetMass", "Data", mass, RooFit::Import(*hdatataggedincjet3ProngMass)); 
    RooDataHist mctaggedincjetMass("mctaggedincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimtaggedincjet3ProngMass)); 
    RooDataHist mctaggedcjetMass("mctaggedcjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimtaggedcjet3ProngMass)); 
    RooDataHist mctaggedbjetMass("mctaggedbjetMass", "beauty jet (MC)", mass, RooFit::Import(*hsimtaggedbjet3ProngMass)); 
    RooDataHist mctaggedlfjetMass("mctaggedlfjetMass", "lf jet (MC)", mass, RooFit::Import(*hsimtaggedlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdftaggedcjetMass("histPdftaggedcjetMass", "Histogram PDF", mass, mctaggedcjetMass);
    RooHistPdf histPdftaggedbjetMass("histPdftaggedbjetMass", "Histogram PDF", mass, mctaggedbjetMass);
    RooHistPdf histPdftaggedlfjetMass("histPdftaggedlfjetMass", "Histogram PDF", mass, mctaggedlfjetMass);

    double cYieldtaggedjetMC  = hsimtaggedcjet3ProngMass->Integral();
    double bYieldtaggedjetMC  = hsimtaggedbjet3ProngMass->Integral();
    double lfYieldtaggedjetMC = hsimtaggedlfjet3ProngMass->Integral();
    double totalYieldtaggedjetMC = cYieldtaggedjetMC + bYieldtaggedjetMC + lfYieldtaggedjetMC;

    double fracCtaggedjet_MC = cYieldtaggedjetMC / totalYieldtaggedjetMC;
    double fracBtaggedjet_MC = bYieldtaggedjetMC / totalYieldtaggedjetMC;
    double fracLFtaggedjet_MC = lfYieldtaggedjetMC / totalYieldtaggedjetMC;
    double relWidth = 0.10; // 10%
    double sigmaB = relWidth * fracBtaggedjet_MC;
    double sigmaC = relWidth * fracCtaggedjet_MC;
    std::cout << "fraction of charm tagged jet: " << fracCtaggedjet_MC << std::endl;
    std::cout << "fraction of beauty tagged jet: " << fracBtaggedjet_MC << std::endl;
    RooRealVar globaltaggedjet_b("global_b", "global b prior", fracBtaggedjet_MC);
    RooRealVar globaltaggedjet_c("global_c", "global c prior", fracCtaggedjet_MC);

    RooRealVar taggedcjetMassFrac("cjetMassFractaggedjet", "cjet fraction", fracCtaggedjet_MC, 0.0, 1.0);
    RooRealVar taggedbjetMassFrac("bjetMassFractaggedjet", "bjet fraction", fracBtaggedjet_MC, 0.0, 1.0);
    RooFormulaVar taggedlfjetMassFrac("lfjetMassFractaggedjet", "1 - c - b", "1 - cjetMassFractaggedjet - bjetMassFractaggedjet", RooArgList(taggedcjetMassFrac, taggedbjetMassFrac));

    //float powerPriorTaggedjet = 0.01;
    //RooGaussian priorBtaggedjet("priorBtaggedjet", "Prior on b", taggedbjetMassFrac, RooFit::RooConst(fracBtaggedjet_MC), RooFit::RooConst(powerPriorTaggedjet));
    RooGaussian priorBtaggedjet("priorBtaggedjet", "Prior on b", taggedbjetMassFrac, RooFit::RooConst(fracBtaggedjet_MC), RooFit::RooConst(sigmaB));
    RooGaussian priorCtaggedjet("priorCtaggedjet", "Prior on c", taggedcjetMassFrac, RooFit::RooConst(fracCtaggedjet_MC), RooFit::RooConst(sigmaC));
    //RooGaussian priorCtaggedjet("priorCtaggedjet", "Prior on c", taggedcjetMassFrac, RooFit::RooConst(fracCtaggedjet_MC), RooFit::RooConst(powerPriorTaggedjet));

    int taggedincjetMassYield = datataggedincjetMass.sumEntries();
    RooRealVar totaltaggedjetYield("totaltaggedjetYield", "Total taggedjet yield", taggedincjetMassYield, 0.5 * taggedincjetMassYield, 1.5 * taggedincjetMassYield);
    RooFormulaVar taggedcjetMassYield("taggedcjetMassYield", "", "@0 * @1", RooArgList(taggedcjetMassFrac, totaltaggedjetYield));
    RooFormulaVar taggedbjetMassYield("taggedbjetMassYield", "", "@0 * @1", RooArgList(taggedbjetMassFrac, totaltaggedjetYield));
    RooFormulaVar taggedlfjetMassYield("taggedlfjetMassYield", "", "@0 * @1", RooArgList(taggedlfjetMassFrac, totaltaggedjetYield));

    RooAddPdf modeltaggedjetMC("modeltaggedjetMC", "Total PDF", RooArgList(histPdftaggedcjetMass, histPdftaggedbjetMass, histPdftaggedlfjetMass), RooArgList(taggedcjetMassYield, taggedbjetMassYield, taggedlfjetMassYield));
    RooProdPdf priorModeltaggedjetMC("priorModeltaggedjetMC", "Model with priors", RooArgSet(modeltaggedjetMC, priorBtaggedjet, priorCtaggedjet));

    std::cout << "START MC FITTING" << std::endl;
    std::cout << "cjet yield before: " << taggedcjetMassYield.getVal() << std::endl;
    std::cout << "bjet yield before: " << taggedbjetMassYield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << taggedlfjetMassYield.getVal() << std::endl;
    if (taggedlfjetMassYield.getVal()<1) {
      std::cout<< "Fit failed" << std::endl;
      continue;
    }
    RooFitResult* fitMinostaggedjetData = nullptr;
    //fitMinostaggedjetData = modeltaggedjetMC.fitTo(datataggedincjetMass, RooFit::Minos(kTRUE), RooFit::Save(true));
    //fitMinostaggedjetData = modeltaggedjetMC.fitTo(datataggedincjetMass, RooFit::Save(true));
    fitMinostaggedjetData = priorModeltaggedjetMC.fitTo(datataggedincjetMass, RooFit::Save(true));
    std::cout << "END DATA FITTING" << std::endl;
    std::cout<<"fit Data: " << std::endl;
    fitMinostaggedjetData->Print();

    RooPlot* frametaggedjetDataWithMC = mass.frame();
    datataggedincjetMass.plotOn(frametaggedjetDataWithMC, RooFit::DrawOption(""), RooFit::Name("InclusiveJet"));
    //mctaggedincjetMass.plotOn(frametaggedjetDataWithMC, RooFit::DrawOption(""), RooFit::Name("InclusiveJet"));
    modeltaggedjetMC.plotOn(frametaggedjetDataWithMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("TotalFit"));
    modeltaggedjetMC.plotOn(frametaggedjetDataWithMC, RooFit::Components("histPdftaggedcjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kGreen+3), RooFit::Name("CharmJetComponent"));
    modeltaggedjetMC.plotOn(frametaggedjetDataWithMC, RooFit::Components("histPdftaggedbjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kRed+1), RooFit::Name("BottomJetComponent"));
    modeltaggedjetMC.plotOn(frametaggedjetDataWithMC, RooFit::Components("histPdftaggedlfjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kBlue+1), RooFit::Name("LightFlavorJetComponent"));
    

    frametaggedjetDataWithMC->GetXaxis()->SetTitle(HfJetTagging::X_AXIS_MASS);  // X-axis title
    frametaggedjetDataWithMC->GetXaxis()->SetLabelSize(0.045);                   // X-axis label size
    frametaggedjetDataWithMC->GetXaxis()->SetTitleOffset(1.1);                  // X-axis title offset
    frametaggedjetDataWithMC->GetXaxis()->SetTitleSize(0.05);                   // X-axis title size

    frametaggedjetDataWithMC->GetYaxis()->SetTitle("Counts");    // Y-axis title
    frametaggedjetDataWithMC->GetYaxis()->SetLabelSize(0.045);                   // Y-axis label size
    frametaggedjetDataWithMC->GetYaxis()->SetTitleOffset(1.15);                 // Y-axis title offset
    frametaggedjetDataWithMC->GetYaxis()->SetTitleSize(0.05);                   // Y-axis title size
    frametaggedjetDataWithMC->GetYaxis()->SetRangeUser(1.01, taggedincjetMassYield);
    frametaggedjetDataWithMC->GetXaxis()->SetRangeUser(0.25, 5);

    TLegend* legtaggedjet = new TLegend(0.17, 0.2, 0.4, 0.4);  // (x1, y1, x2, y2) for legend position
    legtaggedjet->SetBorderSize(0);  // No border
    legtaggedjet->SetFillColor(0);   // Transparent background
    legtaggedjet->SetTextSize(0.045); // Text size

    legtaggedjet->AddEntry(frametaggedjetDataWithMC->findObject("InclusiveJet"), HfJetTagging::INCJET, "lep");
    legtaggedjet->AddEntry(frametaggedjetDataWithMC->findObject("TotalFit"), "Fit", "l");
    legtaggedjet->AddEntry(frametaggedjetDataWithMC->findObject("CharmJetComponent"), HfJetTagging::CJET, "l");
    legtaggedjet->AddEntry(frametaggedjetDataWithMC->findObject("BottomJetComponent"), HfJetTagging::BJET, "l");
    legtaggedjet->AddEntry(frametaggedjetDataWithMC->findObject("LightFlavorJetComponent"), HfJetTagging::LFJET, "l");

    canHan = new CanvasHandler();
    canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.02);
    gPad->SetLogy();
    //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
    //gROOT->ProcessLine(Form("cc%d->cd()", nc));
    frametaggedjetDataWithMC->Draw();
    legtaggedjet->Draw();
    latexSimJetInfoForSV(0.47, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.47, 0.89-0.055*5, Form("tagged jet (largest S#it{L}_{XY} > %0.f)", HfJetTagging::CUT::SxyByHY));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/templatetaggedjet3ProngMassN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

    if (binJetPt <1) continue;
    // tagging efficiency for data driven method
    double numcjet = cjetMassYield.getVal();
    double numbjet = bjetMassYield.getVal();
    double numlfjet = lfjetMassYield.getVal();
    double numincjet = numcjet + numbjet + numlfjet;
    double numtaggedcjet = taggedcjetMassYield.getVal();
    double numtaggedbjet = taggedbjetMassYield.getVal();
    double numtaggedlfjet = taggedlfjetMassYield.getVal();
    double numtaggedincjet = numtaggedcjet + numtaggedbjet + numtaggedlfjet;
    if (numtaggedbjet == 0 ) continue;
    double effiincjet = (double) numtaggedincjet / numincjet;
    double efficjet = (double) numtaggedcjet / numcjet;
    double effibjet = (double) numtaggedbjet / numbjet;
    double effilfjet = (double) numtaggedlfjet / numlfjet;
    if (effibjet > 1 || effibjet < 0) continue;
    double errorEffibjet = std::sqrt(effibjet * (1 - effibjet) / numbjet);
    double errorEfficjet = std::sqrt(efficjet * (1 - efficjet) / numcjet);
    double errorEffilfjet = std::sqrt(effilfjet * (1 - effilfjet) / numlfjet);
    double errorEffiincjet = std::sqrt(effiincjet * (1 - effiincjet) / numincjet);
    float errorEffi = 0.1f;
    effibjet = taggingutilities::getEfficiency(hsimtaggedjet3ProngMassN1[2][binJetPt], hsimjetPt[2], binJetPt); // TEMP; the result is correct?
    //errorEffibjet =
    std::cout << "LINE: " << __LINE__ << std::endl;
    errorEffibjet = taggingutilities::getErrorEfficiency(hsimtaggedjet3ProngMassN1[2][binJetPt], hsimjetPt[2], binJetPt);
    //effibjet = effi3ProngDirect[binJetPt];
    hdatataggedjetSVEffi3ProngSxyN1[0]->SetBinContent(binJetPt, effiincjet);
    hdatataggedjetSVEffi3ProngSxyN1[0]->SetBinError(binJetPt, errorEffiincjet);
    hdatataggedjetSVEffi3ProngSxyN1[1]->SetBinContent(binJetPt, efficjet);
    hdatataggedjetSVEffi3ProngSxyN1[1]->SetBinError(binJetPt, errorEfficjet);
    hdatataggedjetSVEffi3ProngSxyN1[2]->SetBinContent(binJetPt, effibjet);
    hdatataggedjetSVEffi3ProngSxyN1[2]->SetBinError(binJetPt, errorEffibjet);
    hdatataggedjetSVEffi3ProngSxyN1[3]->SetBinContent(binJetPt, effilfjet);
    hdatataggedjetSVEffi3ProngSxyN1[3]->SetBinError(binJetPt, errorEffilfjet);
    hdatajet3ProngRawYield->SetBinContent(binJetPt, numtaggedbjet);
    //hdatajet3ProngRawYield->SetBinContent(binJetPt, numtaggedincjet);
    hdatajet3ProngRawYield->SetBinError(binJetPt, std::sqrt(numtaggedincjet));
    effi3ProngTaggedData[binJetPt] = effibjet;

    /// directly compared to total inc-jet tagging efficiency w/ template fit
    double numincjetwoTemplateFit = hdatajet3ProngMassN1[binJetPt]->Integral(); // N_inc^tag (jet pt)
    double numtaggedincjetwoTemplateFit = hdatataggedjet3ProngMassN1[binJetPt]->Integral(); // N_inc^tag (jet pt)
    hdatataggedjetSVEffi3ProngSxyN1woTemplateFit[0]->SetBinContent(binJetPt, numtaggedincjetwoTemplateFit / numincjetwoTemplateFit);
    hdatataggedjetSVEffi3ProngSxyN1woTemplateFit[0]->SetBinError(binJetPt, errorEffi);

    // purity for data driven method
    double B = taggedbjetMassYield.getVal();
    double C = taggedcjetMassYield.getVal();
    double L = taggedlfjetMassYield.getVal();

    double eB = taggedbjetMassYield.getPropagatedError(*fitMinostaggedjetData);
    double eC = taggedcjetMassYield.getPropagatedError(*fitMinostaggedjetData);
    double eL = taggedlfjetMassYield.getPropagatedError(*fitMinostaggedjetData);
    //double eC = taggedcjetMassYield.getError();
    //double eL = taggedlfjetMassYield.getError();

    double T = B + C + L;
    if (T == 0) continue;

    double purity = B / T;
    double purityOfCharm = C / T;
    double purityOfLf = L / T;

    double dPurity2 = pow((C + L) / (T*T), 2) * eB * eB + pow(B / (T*T), 2) * (eC * eC + eL * eL);

    double errorPurity = sqrt(dPurity2);
    hdatataggedjetSVPurity3ProngSxyN1[2]->SetBinContent(binJetPt, purity);
    hdatataggedjetSVPurity3ProngSxyN1[2]->SetBinError(binJetPt, errorPurity);
    purity3ProngTaggedData[binJetPt] = purity;
  }

  // draw tagging efficiency for data driven method
  std::vector<HistogramData> histEffiincjet;
  histEffiincjet.push_back({hdatataggedjetSVEffi3ProngSxyN1[0], "Data w template fit"});
  histEffiincjet.push_back({hdatataggedjetSVEffi3ProngSxyN1woTemplateFit[0], "Data w/ template fit"});
  histEffiincjet.push_back({hsimtaggedjetSVEffi3ProngSxyN1[3], "MC"}); // almost same inc-jet and lfjet

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-3, 3e+1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histEffiincjet.size(), histEffiincjet, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "Data + (PYTHIA 8 + Geant 4)", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", HfJetTagging::CUT::SxyByHY));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1incjet.pdf\")", nc++, dirDataVsSim.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-3, 3e+2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histEffiincjet.size(), histEffiincjet, true, true, HfJetTagging::LEG[0]-0.05, HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "Data + (PYTHIA 8 + Geant 4)", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", HfJetTagging::CUT::SxyByHY));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1incjet.pdf\")", nc++, dirDataVsSim.Data()));

  std::vector<HistogramData> histEffi;
  histEffi.push_back({hdatataggedjetSVEffi3ProngSxyN1[2], "Data"});
  histEffi.push_back({hsimtaggedjetSVEffi3ProngSxyN1[2], "MC"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-2, 3e+2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histEffi.size(), histEffi, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "Data + (PYTHIA 8 + Geant 4)", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", HfJetTagging::CUT::SxyByHY));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1.pdf\")", nc++, dirDataVsSim.Data()));

  std::vector<HistogramData> histEffiForData;
  histEffiForData.push_back({hdatataggedjetSVEffi3ProngSxyN1[2], "Data"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  gPad->SetLogy(true);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], 1e-2, 3e+2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histEffiForData.size(), histEffiForData, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "Data + (PYTHIA 8 + Geant 4)", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", HfJetTagging::CUT::SxyByHY));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1.pdf\")", nc++, dirData.Data()));

  // draw purity for data driven method
  std::vector<HistogramData> histPurity;
  histPurity.push_back({hdatataggedjetSVPurity3ProngSxyN1[2], "Data"});
  histPurity.push_back({hsimtaggedjetSVPurity3ProngSxyN1[2], "MC"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histPurity.size(), histPurity, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "Data + (PYTHIA 8 + Geant 4)", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", HfJetTagging::CUT::SxyByHY));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngPuritySxyN1.pdf\")", nc++, dirDataVsSim.Data()));

  std::vector<HistogramData> histPurityForData;
  histPurityForData.push_back({hdatataggedjetSVPurity3ProngSxyN1[2], "Data"});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], 1.0, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(histPurityForData.size(), histPurityForData, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  latexSimJetInfoForEffi(0.17, 0.89, "Data + (PYTHIA 8 + Geant 4)", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.17, 0.89-0.055*5, Form("3-prong secondary-vertex candidate (largest #it{S}(#it{L}_{#it{xy}}) > %.0f)", HfJetTagging::CUT::SxyByHY));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngPuritySxyN1.pdf\")", nc++, dirData.Data()));



  // To add 
}

void HfJetTaggingSVAnalysis::drawTemplateFitDataWithMCtaggedjetN1Dep() {

  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.1, 5);

  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;
    TH1F* hdataincjet3ProngMass = (TH1F*) hdatajet3ProngMassN1[binJetPt]->Clone();
    TH1F* hsimincjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[0][binJetPt]->Clone();
    TH1F* hsimcjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[1][binJetPt]->Clone();
    TH1F* hsimbjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[2][binJetPt]->Clone();
    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimjet3ProngMassN1[3][binJetPt]->Clone();
    RooDataHist dataincjetMass("dataincjetMass", "Data", mass, RooFit::Import(*hdataincjet3ProngMass)); 
    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
    RooDataHist mcbjetMass("mcbjetMass", "beauty jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);

    int incjetMassYield = dataincjetMass.sumEntries();
    RooRealVar cjetMassYield("cjetMassYield", "cjet Yield", hsimjet3ProngMassN1[1][0]->Integral(1, hsimcjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar bjetMassYield("bjetMassYield", "bjet Yield", hsimjet3ProngMassN1[2][0]->Integral(1, hsimbjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar lfjetMassYield("lfjetMassYield", "lfjet Yield", hsimjet3ProngMassN1[3][0]->Integral(1, hsimlfjet3ProngMass->GetNbinsX()), 0, incjetMassYield);

    RooAddPdf modelMC("modelMC", "Total PDF", RooArgList(histPdfcjetMass, histPdfbjetMass, histPdflfjetMass), RooArgList(cjetMassYield, bjetMassYield, lfjetMassYield));
    std::cout << "START MODEL FITTING" << std::endl;
    std::cout << "cjet yield before: " << cjetMassYield.getVal() << std::endl;
    std::cout << "bjet yield before: " << bjetMassYield.getVal() << std::endl;
    std::cout << "lfjet yield before: " << lfjetMassYield.getVal() << std::endl;
    if (lfjetMassYield.getVal()<1) {
      std::cout<< "Fit failed" << std::endl;
      continue;
    }
    RooFitResult* fitMigrad = modelMC.fitTo(dataincjetMass, RooFit::Save()); // Migrad
    RooFitResult* fitHesse = modelMC.fitTo(dataincjetMass, RooFit::Hesse(kTRUE), RooFit::Save()); // Hesse
    RooFitResult* fitMinos = modelMC.fitTo(dataincjetMass, RooFit::Minos(kTRUE), RooFit::Save()); // Minos
                                                                                                  //RooFitResult* fitHesseMinos = modelMC.fitTo(dataincjetMass, RooFit::Hesse(), RooFit::Minos(kTRUE), RooFit::Save()); // Hesse + Minos

    RooPlot* frameComparison = mass.frame();
    dataincjetMass.plotOn(frameComparison, RooFit::DrawOption(""), RooFit::Name("InclusiveJetData"));
    //mcincjetMass.plotOn(frameComparison, RooFit::DrawOption(""), RooFit::Name("InclusiveJetData"));
    modelMC.plotOn(frameComparison, RooFit::LineColor(kGreen+3), RooFit::Name("Migrad"));
    modelMC.plotOn(frameComparison, RooFit::LineColor(kRed+1), RooFit::Name("Hesse"));
    modelMC.plotOn(frameComparison, RooFit::LineColor(kBlue+1), RooFit::Name("Minos"));
    //modelMC.plotOn(frameComparison, RooFit::LineColor(kGreen+3), RooFit::Name("Hesse+Minos"));

    frameComparison->GetXaxis()->SetTitle(HfJetTagging::X_AXIS_MASS);  // X-axis title
    frameComparison->GetXaxis()->SetLabelSize(0.045);                   // X-axis label size
    frameComparison->GetXaxis()->SetTitleOffset(1.1);                  // X-axis title offset
    frameComparison->GetXaxis()->SetTitleSize(0.05);                   // X-axis title size
    frameComparison->GetXaxis()->SetRangeUser(0.25, 5);

    frameComparison->GetYaxis()->SetTitle("Counts");    // Y-axis title
    frameComparison->GetYaxis()->SetLabelSize(0.045);                   // Y-axis label size
    frameComparison->GetYaxis()->SetTitleOffset(1.15);                 // Y-axis title offset
    frameComparison->GetYaxis()->SetTitleSize(0.05);                   // Y-axis title size
    frameComparison->GetYaxis()->SetRangeUser(1.01, incjetMassYield);

    TLegend* legDep = new TLegend(0.17, 0.2, 0.4, 0.4);  // (x1, y1, x2, y2) for legend position
    legDep->SetBorderSize(0);  // No border
    legDep->SetFillColor(0);   // Transparent background
    legDep->SetTextSize(0.045); // Text size

    legDep->AddEntry(frameComparison->findObject("InclusiveJetData"), "Data", "lep");
    legDep->AddEntry(frameComparison->findObject("Migrad"), "Migrad Fit", "l");
    legDep->AddEntry(frameComparison->findObject("Hesse"), "Hesse Fit", "l");
    legDep->AddEntry(frameComparison->findObject("Minos"), "Minos Fit", "l");
    //legDep->AddEntry(frameComparison->findObject("Hesse+Minos"), "Hesse+Minos Fit", "l");

    canHan = new CanvasHandler();
    canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.02);
    gPad->SetLogy();
    frameComparison->Draw();
    legDep->Draw();
    latexSimJetInfoForSV(0.49, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.49, 0.89-0.055*5, "untagged jet (largest S#it{L}_{XY})");
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template3ProngMassN1Dep_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSVAnalysis::unfoldingJetSV(bool doLog, int flavour) {

  if (!fillData) {
    std::cout<< "There are no datas" <<std::endl;
    return;
  }

  if (!fillMCD) {
    std::cout << "MCD off" << std::endl;
    return;
  }

  RooUnfoldResponse resMat(hsimjetPtMatched[flavour], hsimpartjetPtMatched[flavour], h2simjetPtpartjetPtMatched[flavour], "", "", false);

  // Bayesain unfolding
  TH1F* hdatajetPtRebin = (TH1F*) hdatajetPt->Rebin(unfold::nBinsJetPt, "", unfold::binsJetPt);
  int n_iter=10;
  //RooUnfoldBayes unfoldBayes(&resMat, hdatajetPtRebin, n_iter);
  RooUnfoldBayes unfoldBayes(&resMat, hdatajetPt, n_iter);
  //RooUnfoldSvd unfoldSVD(&resMat, hdatajetPtRebin, 16);
  RooUnfoldSvd unfoldSVD(&resMat, hdatajetPt, 16);
  //unfoldBayes.PrintTable(); // Unfolded results
  //unfoldSVD.PrintTable(); // Unfolded results
  TH1F* unfolded_bayes_jetPt = (TH1F*) unfoldBayes.Hunfold();
  TH1F* unfolded_svd_jetPt = (TH1F*) unfoldSVD.Hunfold();

  RooUnfoldBayes refold(&resMat, unfolded_bayes_jetPt, n_iter);
  TH1F* refolded_jetPt = (TH1F*) refold.Hunfold();
	std::vector<HistogramData> histList;
	histList.push_back({unfolded_bayes_jetPt, "unfolded Bayes"});
	histList.push_back({unfolded_svd_jetPt, "unfolded SVD"});

}

void HfJetTaggingSVAnalysis::closureTestSVMC(bool doLog = false) {
	std::vector<HistogramData> histList;
	histList.push_back({hsimjetPtRebin[2], "b-jet (no cut)"});
  TH1F *hclosure = new TH1F("hclosureMC", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
  for (int binJetPt=1; binJetPt < hclosure->GetNbinsX()+1; binJetPt++) {
    float reco = hsimtaggedjet3ProngMassN1[0][binJetPt]->Integral(); // N_inc^tag (jet pt)
    //hclosure->SetBinContent(binJetPt, reco);
    float effi = effi3ProngTagged[binJetPt];
    float purity = purity3ProngTagged[binJetPt];
    if ((effi || purity) < 1) continue;
    reco = reco * purity / effi;
    hclosure->SetBinContent(binJetPt, reco);
  }
	histList.push_back({hclosure, "P/#epsilon * tagged inc-jet (MC)"});

  TH1F *hRatio = static_cast<TH1F*>(hsimjetPtRebin[2]->Clone("hRatio"));
  hRatio->Divide(hclosure);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 5e+2*hsimjetPtRebin[2]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, "Yield");
  canHan->drawCombined(histList.size(), histList, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);

  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "Closure test");
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/closureTestSVMC.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::closureTestSV(bool doLog = false) {
	std::vector<HistogramData> histList;
  TH1F *hclosure = new TH1F("hclosure", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
  for (int binJetPt=1; binJetPt < hclosure->GetNbinsX()+1; binJetPt++) {
    float reco = hdatataggedjet3ProngMassN1[binJetPt]->Integral(); // N_inc^tag (jet pt)
    //hclosure->SetBinContent(binJetPt, reco);
    float effi = effi3ProngTaggedData[binJetPt];
    float purity = purity3ProngTaggedData[binJetPt];
    if ((effi || purity) < 1) continue;
    reco = reco * purity / effi;
    hclosure->SetBinContent(binJetPt, reco);
  }
  TH1F* hsimjetPtNorm = (TH1F*) hsimjetPtRebin[2]->Clone();
  hsimjetPtNorm->Scale(1. / hsimjetPtNorm->Integral(hsimjetPtNorm->FindBin(10), hsimjetPtNorm->GetNbinsX()));
  hclosure->Scale(1. / hclosure->Integral(hclosure->FindBin(10), hclosure->GetNbinsX()));
	histList.push_back({hsimjetPtNorm, "b-jet (no cut)"});
	histList.push_back({hclosure, "P/#epsilon * tagged inc-jet (data-driven)"});

  TH1F *hRatio = static_cast<TH1F*>(hsimjetPtNorm->Clone("hRatio"));
  hRatio->Divide(hclosure);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 5e+2*hsimjetPtRebin[2]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, "Yield");
  canHan->drawCombined(histList.size(), histList, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);

  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "Closure test");
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/closureTestSV.pdf\")", nc++, dirDataVsSim.Data()));
}

void HfJetTaggingSVAnalysis::drawDataSV3ProngCrossSection(bool doLog, int n_iter = 4, int n_reg = 6) {
  /// unfolding
  //// response matrix
  if (!loadResMat) {
    std::cout << "[ERROR] drawDataSV3ProngCrossSection should be needed external response matrix" << std::endl;
    return;
  }
  RooUnfoldResponse resMat(hexternalsimjetPtMatched[0], hexternalsimpartjetPtMatched[0], h2externalsimjetPtpartjetPtMatched[0], "", "", false);
  RooUnfoldResponse resMatRebin(hexternalsimjetPtMatchedRebin[0], hexternalsimpartjetPtMatchedRebin[0], h2externalsimjetPtpartjetPtMatchedRebin[0], "", "", false);
  RooUnfoldResponse resMatInverse(hexternalsimpartjetPtMatched[0], hexternalsimjetPtMatched[0], h2externalsimpartjetPtjetPtMatched[0], "", "", false);
  RooUnfoldBayes unfoldBayes(&resMatRebin, hdatajet3ProngRawYield, n_iter);
  RooUnfoldSvd unfoldSvd(&resMatRebin, hdatajet3ProngRawYield, n_reg);
  TH1F* hdatajet3ProngUnfoldedBayesRawYield = (TH1F*) unfoldBayes.Hunfold();
  TH1F* hdatajet3ProngUnfoldedSvdRawYield = (TH1F*) unfoldSvd.Hunfold(); // if svd method doesn't work, just use bayses
  hdatajet3ProngUnfoldedBayesRawYield->Sumw2();
  hdatajet3ProngUnfoldedSvdRawYield->Sumw2();

  hdatajet3ProngCrossSection = (TH1F*) hdatajet3ProngUnfoldedSvdRawYield->Clone("hdatajet3ProngCrossSection");
  hdatajet3ProngCrossSectionwoUnfold = (TH1F*) hdatajet3ProngRawYield->Clone("hdatajet3ProngCrossSectionwoUnfold");
  hdatajet3ProngCrossSectionFromBayes = (TH1F*) hdatajet3ProngUnfoldedBayesRawYield->Clone("hdatajet3ProngCrossSectionFromBayes");
  hdatajet3ProngCrossSectionFromMCEffiAndPurity = (TH1F*) hdatajet3ProngUnfoldedSvdRawYield->Clone("hdatajet3ProngCrossSectionFromMCEffiAndPurity");
  for (int binJetPt=1; binJetPt < hdatajet3ProngCrossSection->GetNbinsX()+1; binJetPt++) {
    //float reco = hdatajet3ProngRawYield->GetBinContent(binJetPt); // numtaggedincjet
    //float reco = hdatajet3ProngUnfoldedBayesRawYield->GetBinContent(binJetPt); // numtaggedincjet
    float statErr = hdatajet3ProngUnfoldedSvdRawYield->GetBinError(binJetPt);
    std::cout << "bin jet pt : " << binJetPt << " stat err: " << statErr << std::endl;
    float reco = hdatajet3ProngUnfoldedSvdRawYield->GetBinContent(binJetPt); // numtaggedincjet
    float recoUnfoldedBayes = hdatajet3ProngUnfoldedBayesRawYield->GetBinContent(binJetPt);
    float recoUnfoldedSvd = hdatajet3ProngUnfoldedSvdRawYield->GetBinContent(binJetPt);
    float recoFromMC = hdatajet3ProngUnfoldedSvdRawYield->GetBinContent(binJetPt); // numtaggedincjet
    float effi = effi3ProngTaggedData[binJetPt];
    float purity = purity3ProngTaggedData[binJetPt];
    float effiFromMC = effi3ProngTagged[binJetPt];
    float purityFromMC = purity3ProngTagged[binJetPt];
    if (effi < 0.0001f) continue;
    //if ((effi || purity) < 0) continue; 
    reco = reco * purity / effi;
    //recoFromMC = recoFromMC * purityFromMC / effiFromMC;
    recoFromMC = recoFromMC * purity / effiFromMC;
    recoUnfoldedBayes = recoUnfoldedBayes * purity / effi;
    recoUnfoldedSvd = recoUnfoldedSvd * purity / effi;
    if (debug) std::cout << "cross section; effi: " << effi << " purity: " << purity << std::endl;
    statErr = statErr * purity / effi;
    statErr *= (sigmaVis_mb / (ndataEvents * deltaEta));
    hdatajet3ProngYieldEffiAndPurity->SetBinContent(binJetPt, reco);
    hdatajet3ProngUnfoldedBayesYieldEffiAndPurity->SetBinContent(binJetPt, recoUnfoldedBayes);
    hdatajet3ProngUnfoldedSvdYieldEffiAndPurity->SetBinContent(binJetPt, recoUnfoldedSvd);
  }
  hdatajet3ProngCrossSection->Multiply(hdatataggedjetSVPurity3ProngSxyN1[2]);
  hdatajet3ProngCrossSection->Divide(hdatataggedjetSVEffi3ProngSxyN1[2]);
  hdatajet3ProngCrossSectionwoUnfold->Multiply(hdatataggedjetSVPurity3ProngSxyN1[2]);
  hdatajet3ProngCrossSectionwoUnfold->Divide(hdatataggedjetSVEffi3ProngSxyN1[2]);
  hdatajet3ProngCrossSectionFromBayes->Multiply(hdatataggedjetSVPurity3ProngSxyN1[2]);
  hdatajet3ProngCrossSectionFromBayes->Divide(hdatataggedjetSVEffi3ProngSxyN1[2]);
  hdatajet3ProngCrossSectionFromMCEffiAndPurity->Multiply(hsimtaggedjetSVPurity3ProngSxyN1[2]);
  hdatajet3ProngCrossSectionFromMCEffiAndPurity->Divide(hsimtaggedjetSVEffi3ProngSxyN1[2]);
  hdatajet3ProngNormYield = (TH1F*) hdatajet3ProngRawYield->Clone();
  TH1F* hdatajet3ProngUnfoldedBayesNormYield = (TH1F*) hdatajet3ProngUnfoldedBayesRawYield->Clone();
  TH1F* hdatajet3ProngUnfoldedSvdNormYield = (TH1F*) hdatajet3ProngUnfoldedSvdRawYield->Clone();
  hdatajet3ProngNormYield->Scale(1.0, "width");
  hdatajet3ProngUnfoldedBayesNormYield->Scale(1.0, "width");
  hdatajet3ProngUnfoldedSvdNormYield->Scale(1.0, "width");
  hdatajet3ProngUnfoldedBayesYieldEffiAndPurity->Scale(1.0, "width");
  hdatajet3ProngUnfoldedSvdYieldEffiAndPurity->Scale(1.0, "width");
  hdatajet3ProngCrossSection->Scale(sigmaVis_mb/ (ndataEvents*deltaEta), "width");
  hdatajet3ProngCrossSectionwoUnfold->Scale(sigmaVis_mb/ (ndataEvents*deltaEta), "width");
  hdatajet3ProngCrossSectionFromBayes->Scale(sigmaVis_mb/ (ndataEvents*deltaEta), "width");
  hdatajet3ProngCrossSectionFromMCEffiAndPurity->Scale(sigmaVis_mb/ (ndataEvents*deltaEta), "width");

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngRawYield->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("%s", HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  hdatajet3ProngRawYield->Draw("same e");
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawYield.pdf\")", nc++, dirData.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngUnfoldedBayesRawYield->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("Unfolded_{Bayes} %s", HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  hdatajet3ProngUnfoldedBayesRawYield->Draw("same e");
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngUnfoldedBayesRawYield.pdf\")", nc++, dirData.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngUnfoldedSvdRawYield->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("Unfolded_{SVD} %s", HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  hdatajet3ProngUnfoldedSvdRawYield->Draw("same e");
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngUnfoldedSvdRawYield.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngYieldEffiAndPurity->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("%s %s", HfJetTagging::AXIS_EFFIPURITY.Data(), HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  hdatajet3ProngYieldEffiAndPurity->Draw("same e");
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngYieldEffiAndPurity.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngUnfoldedBayesYieldEffiAndPurity->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("%s Unfolded_{Bayes} %s", HfJetTagging::AXIS_EFFIPURITY.Data(), HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  hdatajet3ProngUnfoldedBayesYieldEffiAndPurity->Draw("same e");
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngUnfoldBayesYieldEffiAndPurity.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngUnfoldedSvdYieldEffiAndPurity->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("%s Unfolded_{SVD} %s", HfJetTagging::AXIS_EFFIPURITY.Data(), HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  hdatajet3ProngUnfoldedSvdYieldEffiAndPurity->Draw("same e");
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngUnfoldSvdYieldEffiAndPurity.pdf\")", nc++, dirData.Data()));

  std::vector<HistogramData> histDiffUnfoldingMethod;
  histDiffUnfoldingMethod.push_back({hdatajet3ProngUnfoldedBayesYieldEffiAndPurity, "Bayes)"});
  histDiffUnfoldingMethod.push_back({hdatajet3ProngUnfoldedSvdYieldEffiAndPurity, "Svd)"});
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajet3ProngUnfoldedSvdYieldEffiAndPurity->GetMaximum(), HfJetTagging::X_AXIS_JETPT, Form("%s Unfolded_{SVD} %s", HfJetTagging::AXIS_EFFIPURITY.Data(), HfJetTagging::Y_AXIS_INCJET_TAG_YIELD.Data()));
  canHan->drawCombined(histDiffUnfoldingMethod.size(), histDiffUnfoldingMethod, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngUnfoldBayesAndSvdYieldEffiAndPurity.pdf\")", nc++, dirData.Data()));

  std::vector<HistogramData> histXSection;
  histXSection.push_back({hdatajet3ProngCrossSection, "b-jet (SV)"});
  histXSection.push_back({hpwhgbjetCrossSectionRebin, "POWHEG + PYTHIA8 dijet CT18nlo"});

  std::vector<HistogramData> histXSectionToCompUnfold;
  histXSectionToCompUnfold.push_back({hdatajet3ProngCrossSection, "b-jet (SV)"});
  histXSectionToCompUnfold.push_back({hdatajet3ProngCrossSectionwoUnfold, "wo Unfold"});
  
  std::vector<HistogramData> histXSectionVsUnfoldingMethods;
  histXSectionVsUnfoldingMethods.push_back({hdatajet3ProngCrossSection, "b-jet (SVD)"});
  histXSectionVsUnfoldingMethods.push_back({hdatajet3ProngCrossSectionFromBayes, "b-jet (Bayes)"});

  std::vector<HistogramData> histXSectionFromMCEffiAndPurity;
  histXSectionFromMCEffiAndPurity.push_back({hdatajet3ProngCrossSectionFromMCEffiAndPurity, "b-jet (SV)"});
  histXSectionFromMCEffiAndPurity.push_back({hpwhgbjetCrossSectionRebin, "POWHEG + PYTHIA8 dijet CT18nlo"});

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSection->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION);
  //hdatajet3ProngCrossSection->Draw("same e");
  canHan->drawCombined(histXSection.size(), histXSection, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSection.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSection->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION);
  //hdatajet3ProngCrossSection->Draw("same e");
  canHan->drawCombined(histXSectionToCompUnfold.size(), histXSectionToCompUnfold, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionwoUnfold.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSection->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION);
  //hdatajet3ProngCrossSection->Draw("same e");
  canHan->drawCombined(histXSectionVsUnfoldingMethods.size(), histXSectionVsUnfoldingMethods, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionVsUnfoldingMethods.pdf\")", nc++, dirData.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSectionFromMCEffiAndPurity->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION);
  //hdatajet3ProngCrossSection->Draw("same e");
  canHan->drawCombined(histXSectionFromMCEffiAndPurity.size(), histXSectionFromMCEffiAndPurity, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.5, 0.9, -1);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionFromMCEffiAndPurity.pdf\")", nc++, dirData.Data()));

  hpwhgbjetCrossSectionRebin->Sumw2();
  TH1F* hRatio = static_cast<TH1F*> (hpwhgbjetCrossSectionRebin->Clone());
  hRatio->Divide(hdatajet3ProngCrossSection);

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000, 0.185);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSection->GetMaximum(), 1.4, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION, 1.10, 1.60);
  //hdatajet3ProngCrossSection->Draw("same e");
  canHan->drawCombinedForXSection(histXSection.size(), histXSection, true, 0.47, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.050);
  //latexDataSet();
  latexDataJetInfo(0.47, 0.94, -1, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.85, 2.55, HfJetTagging::X_AXIS_JETPT, "Model/Data");
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionWithRatio.pdf\")", nc++, dirData.Data()));

  TH1F* hRatioFromMC = static_cast<TH1F*> (hpwhgbjetCrossSectionRebin->Clone());
  hRatioFromMC->Divide(hdatajet3ProngCrossSectionFromMCEffiAndPurity);

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000, 0.185);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSectionFromMCEffiAndPurity->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION, 1.10, 1.60);
  //hdatajet3ProngCrossSection->Draw("same e");
  canHan->drawCombinedForXSection(histXSectionFromMCEffiAndPurity.size(), histXSectionFromMCEffiAndPurity, true, 0.47, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.050);
  //latexDataSet();
  latexDataJetInfo(0.47, 0.94, -1, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.05, 1.95, HfJetTagging::X_AXIS_JETPT, "Model/Data");
  hRatioFromMC->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionFromMCEffiAndPurityWithRatio.pdf\")", nc++, dirData.Data()));

  std::vector<HistogramData> histDataDriven;
  histDataDriven.push_back({hdatajet3ProngCrossSection, "data-driven"});
  histDataDriven.push_back({hdatajet3ProngCrossSectionFromMCEffiAndPurity, "MC effi and purity"});

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.170);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-13/hdatajet3ProngCrossSection->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION, 1.10, 1.40);
  canHan->drawCombined(histDataDriven.size(), histDataDriven, true, true, 0.47, 0.55, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.47, 0.88, -1, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionForDataDriven.pdf\")", nc++, dirData.Data()));

}

void HfJetTaggingSVAnalysis::drawSimSV3ProngCrossSection(bool doLog) {
  int flavour = 2;
  //TH1F* hsimCrossSection = reinterpret_cast<TH1F*>(hsimjetPtRebin[flavour]->Clone());
  for (int binJetPt=1; binJetPt < hsimjet3ProngCrossSection[flavour]->GetNbinsX()+1; binJetPt++) {
    float reco = hsimtaggedjet3ProngMassN1[0][binJetPt]->Integral(); // N_inc^tag (jet pt)
    hsimjet3ProngRawYield[flavour]->SetBinContent(binJetPt, reco);
    float effi = effi3ProngTagged[binJetPt];
    float purity = purity3ProngTagged[binJetPt];
    if (effi < 0.0001f) continue;
    //if ((effi || purity) < 0) continue;
    reco = reco * purity / effi;
    //reco = reco * purity;
    hsimjet3ProngNormYieldEffiAndPurity[flavour]->SetBinContent(binJetPt, reco);
    hsimjet3ProngCrossSection[flavour]->SetBinContent(binJetPt, reco);
  }
  hsimjet3ProngNormYield[flavour] = (TH1F*) hsimjet3ProngRawYield[flavour]->Clone();
  hsimjet3ProngNormYield[flavour]->Scale(1.0, "width");
  hsimjet3ProngNormYieldEffiAndPurity[flavour]->Scale(1.0, "width");
  hsimjet3ProngCrossSection[flavour]->Scale(sigmaVis_mb/ (nsimEvents*deltaEta), "width");

  std::vector<HistogramData> histXSection;
  histXSection.push_back({hsimjet3ProngCrossSection[flavour], "LO"});
  histXSection.push_back({hpwhgbjetCrossSectionRebin, "POWHEG (NLO)"});

  canHan = new CanvasHandler();

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  hsimjet3ProngRawYield[flavour]->Draw("same e");
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawYield.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  hsimjet3ProngNormYield[flavour]->Draw("same e");
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormYield.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1e-06, 1e+8, HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_LXY);
  hsimjet3ProngNormYieldEffiAndPurity[flavour]->Draw("same e");
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormYieldEffiAndPurity.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hsimjet3ProngNormYieldEffiAndPurityUnfold[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_EFFIPURITY);
  hsimjet3ProngNormYieldEffiAndPurityUnfold[flavour]->Draw("same e");
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormYieldEffiAndPurityUnfold.pdf\")", nc++, dirSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hsimjet3ProngCrossSection[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_BJET_XSECTION);
  //hsimjet3ProngCrossSection[flavour]->Draw("same e");
  canHan->drawCombined(histXSection.size(), histXSection, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSection.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawDataVsSimSV3ProngCrossSection(bool doLog) {
  int flavour = 2;

  TH1F* normAreaData = (TH1F*) hdatajet3ProngNormYield->Clone();
  TH1F* normAreaSim = (TH1F*) hsimjet3ProngNormYield[flavour]->Clone();
  normAreaData->Scale(1. / normAreaData->Integral());
  normAreaSim->Scale(1. / normAreaSim->Integral());

  TH1F* normNEventsData = (TH1F*) hdatajet3ProngNormYield->Clone();
  TH1F* normNEventsSim = (TH1F*) hsimjet3ProngNormYield[flavour]->Clone();
  normNEventsData->Scale(1. / ndataEvents);
  normNEventsSim->Scale(1. / nsimEvents);

  std::vector<HistogramData> rawYield;
  rawYield.push_back({hdatajet3ProngRawYield, Form("Data (%s)", DATASET.Data())});
  rawYield.push_back({hsimjet3ProngRawYield[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normYield;
  normYield.push_back({hdatajet3ProngNormYield, Form("Data (%s)", DATASET.Data())});
  normYield.push_back({hsimjet3ProngNormYield[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({normAreaData, Form("Data (%s)", DATASET.Data())});
  normArea.push_back({normAreaSim, Form("MC (%s)", SIMSET.Data())});

//  std::vector<HistogramData> normArea;
//  normArea.push_back({normAreaData, Form("Data (%s)", DATASET.Data())});
//  normArea.push_back({normAreaSim, Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> yieldEffiAndPurity;

  std::vector<HistogramData> yieldEffiAndPurityUnfold;

  std::vector<HistogramData> histXSection;
  histXSection.push_back({hdatajet3ProngCrossSection, Form("Data (%s)", DATASET.Data())});
  histXSection.push_back({hsimjet3ProngCrossSection[2], Form("MC (%s)", SIMSET.Data())});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawCombined(rawYield.size(), rawYield, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawYield.pdf\")", nc++, dirDataVsSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawCombined(normYield.size(), normYield, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormYield.pdf\")", nc++, dirDataVsSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngNormAreaYield.pdf\")", nc++, dirDataVsSim.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawCombined(histXSection.size(), histXSection, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSection.pdf\")", nc++, dirDataVsSim.Data()));

}

void HfJetTaggingSVAnalysis::drawDataSV3ProngFlavourFraction() {

  // untagged 
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  //canHan->drawCombined(histXSection.size(), histXSection, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  hdatajet3ProngFlavourFraction[2]->Draw();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngFlavourFractionUntagged.pdf\")", nc++, dirData.Data()));


  // tagged

  // x section of b-jet / incluisve
}

void HfJetTaggingSVAnalysis::drawSimSV3ProngFlavourFraction() {
  // untagged
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  //canHan->drawCombined(histXSection.size(), histXSection, true, true, 0.24, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  hdatajet3ProngFlavourFraction[2]->Draw();
  latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngFlavourFractionUntagged.pdf\")", nc++, dirData.Data()));



  // tagged
}

void HfJetTaggingSVAnalysis::drawDataVsSimSV3ProngFlavourFraction() {
  std::vector<HistogramData> histUntagged;
  histUntagged.push_back({hdatajet3ProngFlavourFraction[2], Form("Data (%s)", DATASET.Data())});
  histUntagged.push_back({hsimjet3ProngFlavourFraction[2], Form("MC (%s)", SIMSET.Data())});
  // untagged
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 1, HfJetTagging::X_AXIS_JETPT, "b-jet fraction", 1.10, 1.40);
  canHan->drawCombined(histUntagged.size(), histUntagged, true, true, 0.60, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimJetInfo(0.5, 0.9, -1, TRIGGERNAME.Data());
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngFlavourFractionUntagged.pdf\")", nc++, dirDataVsSim.Data()));


  // tagged
}

// systematic uncertainty
void HfJetTaggingSVAnalysis::calSysTotal() {
  hsysSVTotal = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVTotal");
  hsysSVTotal->Reset();
  this->calSysUnfolding();
  this->calSysTaggerPoint();
  this->calSysSecondaryContamination();
  for (int binJetPt = 1; binJetPt <= hdatajet3ProngCrossSection->GetNbinsX(); binJetPt++) {
    float sysUnfolding = hsysSVUnfolding->GetBinContent(binJetPt);
    float sysTaggerPoint = hsysSVTaggerPoint->GetBinContent(binJetPt);
    float sysSeoncaryContamination = hsysSVSecondaryContamination->GetBinContent(binJetPt);
    float totalSys = TMath::Sqrt(
        sysUnfolding * sysUnfolding
        //+ sysTaggerPoint * sysTaggerPoint
        //+ sysSeoncaryContamination * sysSeoncaryContamination
        );
    hsysSVTotal->SetBinContent(binJetPt, totalSys);
  }
}

void HfJetTaggingSVAnalysis::calSysTaggerPoint() {
  hsysSVTaggerPoint = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVTaggerPoint");
  hsysSVTaggerPoint->Reset();
  for (int binJetPt = 1; binJetPt <= hdatajet3ProngCrossSection->GetNbinsX(); binJetPt++) {
  }
}

void HfJetTaggingSVAnalysis::calSysSecondaryContamination() {
  hsysSVSecondaryContamination = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVSeoncaryContamination");
  hsysSVSecondaryContamination->Reset();
  for (int binJetPt = 1; binJetPt <= hdatajet3ProngCrossSection->GetNbinsX(); binJetPt++) {
  }
}

void HfJetTaggingSVAnalysis::calSysUnfolding() {
  hsysSVUnfolding = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVUnfolding");
  hsysSVUnfolding->Reset();
  hsysSVUnfoldingPer = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVUnfoldingPer");
  hsysSVUnfoldingPer->Reset();
  this->calSysUnfoldingMethods();
  this->calSysUnfoldingSvdParam();

  const int nBins = hdatajet3ProngCrossSection->GetNbinsX();
  double ax[HfJetTagging::nBinsJetPt];
  double ay[HfJetTagging::nBinsJetPt];
  double aeylsys[HfJetTagging::nBinsJetPt];
  double aeyhsys[HfJetTagging::nBinsJetPt];

  for (int i = 0; i < nBins; i++) {
    int binJetPt = i+1;

    float sysMethod = hsysSVUnfoldingMethods->GetBinContent(binJetPt);
    float sysParam  = hsysSVUnfoldingSvdParam->GetBinContent(binJetPt);
    float combinedSys = TMath::Sqrt(sysMethod*sysMethod + sysParam*sysParam);
    float sysMethodPer = hsysSVUnfoldingPerMethods->GetBinContent(binJetPt);
    float sysParamPer  = hsysSVUnfoldingPerSvdParam->GetBinContent(binJetPt);
    float combinedSysPer = TMath::Sqrt(sysMethodPer*sysMethodPer + sysParamPer*sysParamPer);

    ax[i] = HfJetTagging::binsJetPt[binJetPt] + (HfJetTagging::binsJetPt[binJetPt+1] - HfJetTagging::binsJetPt[binJetPt]) / 2.0;
    ay[i] = hdatajet3ProngCrossSection->GetBinContent(binJetPt);

    aeylsys[i] = combinedSys / 2.0;
    aeyhsys[i] = aeylsys[i];
    hsysSVUnfolding->SetBinContent(binJetPt, combinedSys);
    hsysSVUnfoldingPer->SetBinContent(binJetPt, combinedSysPer);
  }
  grsysSVUnfolding = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aeylsys, aeyhsys, 0, 0);
}

void HfJetTaggingSVAnalysis::calSysUnfoldingMethods() { // calculation for dependeces of methods of unfolding (Bayes & SVD)
  hsysSVUnfoldingMethods = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVUnfoldingMethos");
  hsysSVUnfoldingMethods->Reset();
  hsysSVUnfoldingPerMethods = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVUnfoldingPerMethos");
  hsysSVUnfoldingPerMethods->Reset();
  double ax[HfJetTagging::nBinsJetPt];
  double ay[HfJetTagging::nBinsJetPt];
  double aeylsys[HfJetTagging::nBinsJetPt];
  double aeyhsys[HfJetTagging::nBinsJetPt];
  for (int i = 0; i < hdatajet3ProngCrossSection->GetNbinsX(); i++) {
    int binJetPt = i+1;
    double valRef = hdatajet3ProngCrossSection->GetBinContent(binJetPt);
    double valBayes = hdatajet3ProngCrossSectionFromBayes->GetBinContent(binJetPt);
    double sysError = TMath::Abs(valRef - valBayes);

    ax[i] = HfJetTagging::binsJetPt[binJetPt] + (HfJetTagging::binsJetPt[binJetPt+1]-HfJetTagging::binsJetPt[binJetPt])/2;
    ay[i] = hdatajet3ProngCrossSection->GetBinContent(binJetPt+1);
    aeylsys[i] = sysError / 2;
    aeyhsys[i] = aeylsys[i];
    if (valRef == 0) continue;
    double sysErrorPer = sysError / valRef;
    hsysSVUnfoldingMethods->SetBinContent(binJetPt, sysError);
    hsysSVUnfoldingPerMethods->SetBinContent(binJetPt, sysErrorPer);
  }
  grsysSVUnfoldingMethods = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aeylsys, aeyhsys, 0, 0);
}

void HfJetTaggingSVAnalysis::calSysUnfoldingSvdParam() { // unfolding for dependeces of regression in SVD
  hsysSVUnfoldingSvdParam = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVUnfoldingSvdParam");
  hsysSVUnfoldingSvdParam->Reset();
  hsysSVUnfoldingPerSvdParam = (TH1F*) hdatajet3ProngCrossSection->Clone("hsysSVUnfoldingPerSvdParam");
  hsysSVUnfoldingPerSvdParam->Reset();

  double ax[HfJetTagging::nBinsJetPt];
  double ay[HfJetTagging::nBinsJetPt];
  double aeylsys[HfJetTagging::nBinsJetPt];
  double aeyhsys[HfJetTagging::nBinsJetPt];
  int regLow = 5;
  int regDefault = 6;
  int regHigh = 7;
  if (!loadResMat) return;
  RooUnfoldResponse resMatRebin(hexternalsimjetPtMatchedRebin[0], hexternalsimpartjetPtMatchedRebin[0], h2externalsimjetPtpartjetPtMatchedRebin[0], "", "", false);
  RooUnfoldSvd unfoldSvdLow(&resMatRebin, hdatajet3ProngRawYield, regLow);
  RooUnfoldSvd unfoldSvdDefault(&resMatRebin, hdatajet3ProngRawYield, regDefault);
  RooUnfoldSvd unfoldSvdHigh(&resMatRebin, hdatajet3ProngRawYield, regHigh);
  TH1F* htempdatajet3ProngXSectionLow = (TH1F*) unfoldSvdLow.Hunfold();
  TH1F* htempdatajet3ProngXSectionHigh = (TH1F*) unfoldSvdHigh.Hunfold();
  htempdatajet3ProngXSectionLow->Multiply(hdatataggedjetSVPurity3ProngSxyN1[2]);
  htempdatajet3ProngXSectionLow->Divide(hdatataggedjetSVEffi3ProngSxyN1[2]);
  htempdatajet3ProngXSectionLow->Scale(sigmaVis_mb/ (ndataEvents*deltaEta), "width");
  htempdatajet3ProngXSectionHigh->Multiply(hdatataggedjetSVPurity3ProngSxyN1[2]);
  htempdatajet3ProngXSectionHigh->Divide(hdatataggedjetSVEffi3ProngSxyN1[2]);
  htempdatajet3ProngXSectionHigh->Scale(sigmaVis_mb/ (ndataEvents*deltaEta), "width");

  for (int i = 0; i < hdatajet3ProngCrossSection->GetNbinsX(); i++) { 
    int binJetPt = i+1;
    double valLow = htempdatajet3ProngXSectionLow->GetBinContent(binJetPt);
    double valHigh = htempdatajet3ProngXSectionHigh->GetBinContent(binJetPt);
    double valRef = hdatajet3ProngCrossSection->GetBinContent(binJetPt);
    double diffLow = TMath::Abs(valLow - valRef);
    double diffHigh = TMath::Abs(valHigh - valRef);
    double sysError = TMath::Max(diffLow, diffHigh);

    ax[i] = HfJetTagging::binsJetPt[binJetPt] + (HfJetTagging::binsJetPt[binJetPt+1]-HfJetTagging::binsJetPt[binJetPt])/2;
    ay[i] = hdatajet3ProngCrossSection->GetBinContent(binJetPt+1);
    aeylsys[i] = sysError / 2;
    aeyhsys[i] = aeylsys[i];
    if (valRef == 0) continue;
    double sysErrorPer = sysError / valRef;
    hsysSVUnfoldingSvdParam->SetBinContent(binJetPt, sysError);
    hsysSVUnfoldingPerSvdParam->SetBinContent(binJetPt, sysErrorPer);
  }
  grsysSVUnfoldingParam = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aeylsys, aeyhsys, 0, 0);
}

void HfJetTaggingSVAnalysis::drawDataSV3ProngSys(bool loadExtSys = false) {
  if (!loadExtSys) {
    this->calSysTotal();
  } else {
    std::cout << "get external file of systematic uncertainty" << std::endl;
  } 

  std::vector<HistogramData> histSys;
  std::vector<HistogramData> histSysUnfolding;
  // unfolding
  histSysUnfolding.push_back({hsysSVUnfoldingMethods, "Unfolding methods"});
  histSysUnfolding.push_back({hsysSVUnfoldingSvdParam, "Svd reg parm (5, 6, 7)"});

  // merge
  histSys.push_back({hsysSVUnfolding, "Unfolding methods"});
  // ...

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 1, HfJetTagging::X_AXIS_JETPT, "b-jet fraction", 1.10, 1.40);
  canHan->drawCombined(histSysUnfolding.size(), histSysUnfolding, true, true, 0.60, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.47, 0.94, -1, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSysUnfolding.pdf\")", nc++, dirData.Data()));

}

void HfJetTaggingSVAnalysis::drawDataSV3ProngCrossSectionWithSys(bool loadExtSys = false, bool withSys = false) {
  if (withSys) {
    if (!loadExtSys) {
      this->calSysTotal();
    } else {
      std::cout << "get external file of systematic uncertainty" << std::endl;
    } 
  }

  double ax[HfJetTagging::nBinsJetPt];
  double ay[HfJetTagging::nBinsJetPt];
  double aexl[HfJetTagging::nBinsJetPt];
  double aexh[HfJetTagging::nBinsJetPt];
  double aeylstat[HfJetTagging::nBinsJetPt];
  double aeyhstat[HfJetTagging::nBinsJetPt];
  double aeylsysUnfolding[HfJetTagging::nBinsJetPt];
  double aeyhsysUnfolding[HfJetTagging::nBinsJetPt];
  double aeylsys[HfJetTagging::nBinsJetPt];
  double aeyhsys[HfJetTagging::nBinsJetPt];
  for (int binJetPt = 0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    ax[binJetPt] = HfJetTagging::binsJetPt[binJetPt] + (HfJetTagging::binsJetPt[binJetPt+1]-HfJetTagging::binsJetPt[binJetPt])/2;
    ay[binJetPt] = hdatajet3ProngCrossSection->GetBinContent(binJetPt+1);
    aexl[binJetPt] = (HfJetTagging::binsJetPt[binJetPt+1] - HfJetTagging::binsJetPt[binJetPt])/2;
    aexh[binJetPt] = (HfJetTagging::binsJetPt[binJetPt+1] - HfJetTagging::binsJetPt[binJetPt])/2;
    aeylstat[binJetPt] = hdatajet3ProngCrossSection->GetBinError(binJetPt+1)/2;
    aeyhstat[binJetPt] = hdatajet3ProngCrossSection->GetBinError(binJetPt+1)/2;
    if (withSys) {
      aeylsysUnfolding[binJetPt] = hsysSVUnfolding->GetBinContent(binJetPt + 1)/2;
      aeyhsysUnfolding[binJetPt] = aeylsysUnfolding[binJetPt];
      aeylsys[binJetPt] = hsysSVUnfoldingMethods->GetBinContent(binJetPt + 1)/2; // it should be updated multiple uncertainty in the future
      aeyhsys[binJetPt] = aeylsys[binJetPt];
    } else {
      aeylsysUnfolding[binJetPt] = 0;
      aeyhsysUnfolding[binJetPt] = 0;
      aeylsys[binJetPt] = 0;
      aeyhsys[binJetPt] = 0;
    }
  }
  /// for saving
  grdatajet3ProngXSection = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aexl, aexh, aeylstat, aeyhstat);
  grdatajet3ProngXSectionSysUnfolding = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aexl, aexh, aeylsysUnfolding, aeyhsysUnfolding);
  grdatajet3ProngXSectionSys = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aexl, aexh, aeylsys, aeyhsys);
  grsysSVUnfolding = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aeylsys, aeyhsys, 0, 0);
  ///

  /// for drawing
  auto *grSVXSection = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, 0, 0, aeylstat, aeyhstat);
  grSVXSection->SetMarkerStyle(20);
  grSVXSection->SetMarkerSize(0.8);
  //grSVXSection->SetMarkerColor(kBlack);
  //grSVXSection->SetLineColor(kBlack);
  grSVXSection->SetMarkerColor(kBlue);
  grSVXSection->SetLineColor(kBlue);
  grSVXSection->SetLineWidth(1);
  grSVXSection->GetXaxis()->SetLimits(HfJetTagging::binsJetPt[0], HfJetTagging::binsJetPt[HfJetTagging::nBinsJetPt]);

  auto *grSVXSectionSys = new TGraphAsymmErrors(HfJetTagging::nBinsJetPt, ax, ay, aexl, aexh, aeylsys, aeyhsys);
  grSVXSectionSys->SetFillStyle(1001);
  grSVXSectionSys->SetMarkerStyle(0);
  grSVXSectionSys->SetLineStyle(0);
  //grSVXSectionSys->SetFillColor(17);
  //grSVXSectionSys->SetLineColor(17);
  grSVXSectionSys->SetFillColor(kAzure-4);
  grSVXSectionSys->SetLineColor(kAzure-4);

  TAxis* xAxis = grSVXSectionSys->GetXaxis();
  xAxis->SetRangeUser(HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1]);

  TAxis* yAxis = grSVXSectionSys->GetYaxis();
  yAxis->SetTitle(HfJetTagging::Y_AXIS_BJET_XSECTION);
  yAxis->SetTitleSize(0.06);
  yAxis->SetTitleOffset(1.3);
  yAxis->SetRangeUser(3e-12/hdatajet3ProngCrossSection->GetMaximum(), 0.4);

  TGraph *grModel = new TGraph(hpwhgbjetCrossSectionRebin);
  grModel->SetLineColor(kRed);
  grModel->SetLineWidth(2);

  TLegend *legXSec = new TLegend();
  legXSec->AddEntry(grSVXSection, "b-jet (SV)", "lep");
  legXSec->AddEntry(grSVXSectionSys, "systematic uncertainty", "f");
  if (fillResultRun2) legXSec->AddEntry(grxsectionRun2IP, "Run 2 preliminaty (13 TeV)", "lep");
  if (fillResultRun2) legXSec->AddEntry(grxsectionRun2IPsys, "systematic uncertainty (Run 2)", "f");
  legXSec->AddEntry(grModel, "POWHEG + PYTHIA 8 dijet CT18nlo", "l");

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180);
  gPad->SetLogy();
  grSVXSectionSys->Draw("A 5 SAME");
  grSVXSection->Draw("P Y SAME");
  grModel->Draw("L SAME");
  if (fillResultRun2) {
    grxsectionRun2IPsys->Draw("5 SAME");
    grxsectionRun2IP->Draw("P Y SAME");
  }
  latexDataJetInfo(0.43, 0.94, -1, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  SetLegendBoxSize(legXSec, 5, 0.43, 0.50, 0.05, 3* 0.05 / 4); legXSec->Draw();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionWithSys.pdf\")", nc++, dirData.Data()));

//////
  /// for confernece without physical data
  TGraphAsymmErrors *grtemp = (TGraphAsymmErrors*) grxsectionRun2IPsys->Clone();

  TAxis* xtempAxis = grtemp->GetXaxis();
  xtempAxis->SetRangeUser(HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1]);
  xtempAxis->SetTitle(HfJetTagging::X_AXIS_JETPT);
  xtempAxis->SetTitleSize(0.045);

  TAxis* ytempAxis = grtemp->GetYaxis();
  ytempAxis->SetTitle(HfJetTagging::Y_AXIS_BJET_XSECTION);
  ytempAxis->SetTitleSize(0.045);
  ytempAxis->SetTitleOffset(1.3);
  ytempAxis->SetRangeUser(3e-12/hdatajet3ProngCrossSection->GetMaximum(), 0.4);

  TLegend *legtemp = new TLegend();
  if (fillResultRun2) legtemp->AddEntry(grxsectionRun2IP, "Run 2 preliminaty (13 TeV)", "lep");
  if (fillResultRun2) legtemp->AddEntry(grxsectionRun2IPsys, "systematic uncertainty (Run 2)", "f");
  legtemp->AddEntry(grModel, "POWHEG + PYTHIA 8 dijet CT18nlo", "l");

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.180, 0.04, 0.05, 0.14);
  gPad->SetLogy();
  if (fillResultRun2) {
    grtemp->Draw("A 5 SAME");
    grxsectionRun2IP->Draw("P Y SAME");
  }
  grModel->Draw("L SAME");
  latexDataJetInfo(0.43, 0.94, -1, "anti-#it{k}_{T}", "charged", 0.4, "");
  SetLegendBoxSize(legtemp, 3, 0.43, 0.60, 0.05, 3* 0.05 / 4); legtemp->Draw();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionWithSyswoPhysics.pdf\")", nc++, dirData.Data()));
  ///
/////

  TH1F* hRatio = static_cast<TH1F*> (hpwhgbjetCrossSectionRebin->Clone());
  hRatio->Divide(hdatajet3ProngCrossSection);

  int numGrap = 0;
  canHan->createRatioCanvas(nc, 0, 0, 800, 1000, 0.195);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  gPad->SetLogy();
  grSVXSectionSys->Draw("A 5 SAME"); numGrap++;
  grSVXSection->Draw("P Y SAME"); numGrap++;
  grModel->Draw("L SAME"); numGrap++;
  if (fillResultRun2) {
    grxsectionRun2IPsys->Draw("5 SAME"); numGrap++;
    grxsectionRun2IP->Draw("P Y SAME"); numGrap++;
  }
  latexDataJetInfo(0.43, 0.94, -1, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  SetLegendBoxSize(legXSec, numGrap, 0.43, 0.50, 0.05, 3* 0.05 / 4); legXSec->Draw();

  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.85, 2.55, HfJetTagging::X_AXIS_JETPT, "Model/Data");
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngCrossSectionWithSysAndRatio.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingSVAnalysis::saveSVXSectionWithSys(TString rootFile, bool doSys) {

  TFile* fout = new TFile(rootFile, "RECREATE");
  if (!fout->IsOpen()) {
    std::cerr << "Error: Could not open the ROOT file for writing: " << rootFile << std::endl;
    return;
  }
  TDirectory* dir;
  // data
  if (fillData) {
  	dir = fout->GetDirectory("data");
  	if (!dir) {
    	dir = fout->mkdir("data");
    	dir->cd();
  	}
    hdataEventSel->Write("hdatanEvents"); /// nEvents
    hdatajetPt->Write(); // raw yield
    TH1F* hdatajetPtRebinWidth = (TH1F*) hdatajetPtRebin->Clone("hdatajetPtRebin");
    hdatajetPtRebinWidth->Write(); // rawyield rebinning norm width
    hdatataggedjetSVEffi3ProngSxyN1[2]->Write("hdatabjetEffi"); // b-jet tagging efficiency data-driven
    hdatataggedjetSVPurity3ProngSxyN1[2]->Write("hdatabjetPurity"); // b-jet purity data-driven
    hdatajet3ProngCrossSection->Write("hdatabjetXSection"); // b-jet X Section
    grdatajet3ProngXSection->Write("grdatabjetXSection");
    if (doSys) {
      hsysSVUnfoldingSvdParam->Write("hsysSVUnfoldingParam");
      hsysSVUnfoldingMethods->Write("hsysSVUnfoldingMethods");
      hsysSVUnfolding->Write("hsysSVUnfolding");
      hsysSVUnfoldingPerSvdParam->Write("hsysSVUnfoldingPerParam");
      hsysSVUnfoldingPerMethods->Write("hsysSVUnfoldingPerMethods");
      hsysSVUnfoldingPer->Write("hsysSVUnfoldingPer");
      grsysSVUnfoldingParam->Write("grsysSVUnfoldingParam");
      grsysSVUnfoldingMethods->Write("grsysSVUnfoldingMethods");
      grsysSVUnfolding->Write("grsysSVUnfolding");
      grdatajet3ProngXSectionSysUnfolding->Write("grdatabjetXSectionSysUnfolding");
      grdatajet3ProngXSectionSys->Write("grdatabjetXSectionSys");
    }
  }

  if (fillMCD) {
    dir = fout->GetDirectory("sim");
    if (!dir) {
      dir = fout->mkdir("sim");
      dir->cd();
    }
    hsimEventSel->Write(); /// nEvents
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetPt[flavour]->Write(Form("hsim%sjetPt", HfJetTagging::FLAVOUR[flavour].Data()));
      TH1F* hsimjetPtRebinWidth = (TH1F*) hsimjetPtRebin[flavour]->Clone();
      hsimjetPtRebinWidth->Scale(1.0, "width");
      hsimjetPtRebinWidth->Write(Form("hsim%sjetPtRebin", HfJetTagging::FLAVOUR[flavour].Data()));
    }
    hsimtaggedjetSVEffi3ProngSxyN1[2]->Write("hsimbjetEffi");
    hsimtaggedjetSVPurity3ProngSxyN1[2]->Write("hsimbjetPurity");
    hsimjet3ProngCrossSection[2]->Write("hsimbjetXSection");

    if (loadResMat) {
      for (int binFlavour =0; binFlavour < HfJetTagging::nFlavour+1; binFlavour++) {
        TH2F* h2ResMat = (TH2F*) h2externalsimjetPtpartjetPtMatched[binFlavour]->Clone();
        TH2F* h2ResMatInv = (TH2F*) h2externalsimpartjetPtjetPtMatched[binFlavour]->Clone();
        //taggingutilities::normalize2DHist(h2ResMat);
        //taggingutilities::normalize2DHist(h2ResMatInv);
        h2ResMat->Write(Form("h2sim%sjetResMat", HfJetTagging::FLAVOUR[binFlavour].Data()));
        h2ResMatInv->Write(Form("h2sim%sjetResMatInverse", HfJetTagging::FLAVOUR[binFlavour].Data()));
        //h2externalsimjetPtpartjetPtMatchedRebin[binFlavour]->Write(Form("resMatRebin_%d", binFlavour));
        //h2externalsimpartjetPtjetPtMatchedRebin[binFlavour]->Write(Form("resMatInverseRebin_%d", binFlavour));
        //hexternalsimjetPtMatched[binFlavour]->Write(Form("hsimjetPtMatched_%d", binFlavour));
        //hexternalsimjetPtMatchedRebin[binFlavour]->Write(Form("hsimjetPtMatchedRebin_%d", binFlavour));
        //hexternalsimpartjetPtMatched[binFlavour]->Write(Form("hsimpartjetPtMatched_%d", binFlavour));
        //hexternalsimpartjetPtMatchedRebin[binFlavour]->Write(Form("hsimpartjetPtMatchedRebin_%d", binFlavour));
      }
    }
  }
  
  // model
  if (loadPOWHEG) {
    dir = fout->GetDirectory("model");
    if (!dir) {
      dir = fout->mkdir("model");
      dir->cd();
    }
    hpwhgbjetCrossSection->Write("hpowhegbjetXSection");
  }

  // sys
  //if (fillSys) {
  //}
}

//void HfJetTaggingSVAnalysis::unfoldingJetSV(int flavour) {
//
//  if (!fillData) {
//    std::cout<< " there are no datas" <<std::endl;
//    return;
//  }
//  //if (!(fillMCD && fillMCP)) {
//  if (!fillMCD && !fillMatched) {
//    //std::cout << "MCD and MCP on" << std::endl;
//    std::cout << "MCD on" << std::endl;
//    return;
//  }
//}

#endif // HFJETTAGGINGSVANALYSIS_H 
