#ifndef HFJETTAGGINGMATCHANALYSIS_H
#define HFJETTAGGINGMATCHANALYSIS_H

#include <TH1D.h>
#include <TString.h>
//#include "DataPoint.h"
//#include "CanvasHandler.h"
//#include "HfJetTaggingUtilities.h"
#include "HfJetTaggingAnalysis.h"
//#include "JetAnalysis.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"

class HfJetTaggingSVAnalysis : public HfJetTaggingAnalysis{
  public:
    HfJetTaggingSVAnalysis() : HfJetTaggingAnalysis() {
      initConfig();
    }
    ~HfJetTaggingSVAnalysis();

    void initConfig();
    int loadDataSVQA(TString rootData);
    int loadSimSVQA(TString rootSim);
    void initHistogramForNormalizationSVQAData();
    void initHistogramForNormalizationSVQAMC();
    void projectionHistSVQAData();
    void projectionHistSVQAMC();
    void normalizedHistogramSVQAData();
    void normalizedHistogramSVQAMC();
    void saveHistogramSVQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // Set
    void setFillEffi(bool fillEffi);

    // Draw
    //int nc = 30000;
    CanvasHandler* canHan;

    // MC 2-prongs

    // MC 3-prongs

    void drawSim3ProngRawLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngEffiSxy(const float cutSxy);
    void drawSim3ProngEffiSxyz(const float cutSxyz);
    void drawSim3ProngEffiSxyN1(const float cutSxy);
    void drawSim3ProngEffiSxyzN1(const float cutSxyz);
    void drawSim3ProngPuritySxy(const float cutSxy);
    void drawSim3ProngPuritySxyz(const float cutSxyz);
    void drawSim3ProngPuritySxyN1(const float cutSxy);
    void drawSim3ProngPuritySxyzN1(const float cutSxyz);
    void drawSim3ProngEffiSxyN1Tagger(int binJetPt);
    void drawSim3ProngPuritySxyN1Tagger(int binJetPt);
    void drawSim3ProngEffiAndPuritySxyN1(const float custSxy);
    void drawSim3ProngChi2(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyN1Run2Def(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyzN1Run2Def(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngMassN1Run2Def(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawMassN1Run2Def(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngEffiSxyRun2Def(const float cutSxy);
    void drawSim3ProngEffiSxyzRun2Def(const float cutSxyz);
    void drawSim3ProngEffiSxyN1Run2Def(const float cutSxy);
    void drawSim3ProngEffiSxyzN1Run2Def(const float cutSxyz);
    void drawSim3ProngPuritySxyRun2Def(const float cutSxy);
    void drawSim3ProngPuritySxyzRun2Def(const float cutSxyz);
    void drawSim3ProngPuritySxyN1Run2Def(const float cutSxy);
    void drawSim3ProngPuritySxyzN1Run2Def(const float cutSxyz);
    void drawSimtaggedjet3ProngEffiSxyN1(const float cutSxy);
    void drawSimtaggedjet3ProngEffiSxyN1Run2Def(const float cutSxy);
    void drawSimtaggedjet3ProngPuritySxyN1(const float cutSxy);
    void drawSimtaggedjet3ProngPuritySxyN1Run2Def(const float cutSxy);

    // DataVsMC 2-Prongs
    void drawDataVsSim2ProngLxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngLxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngSxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngSxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngsigmaLxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngsigmaLxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngRawLxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngRawLxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngRawSxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngRawSxyz(bool doLog, int binJetPt);
    void drawDataVsSim2ProngRawsigmaLxy(bool doLog, int binJetPt);
    void drawDataVsSim2ProngRawsigmaLxyz(bool doLog, int binJetPt);

    // DataVsMC 3-Prongs
    void drawDataVsSim3ProngLxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngLxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngsigmaLxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngsigmaLxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawLxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawLxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawSxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawSxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawsigmaLxy(bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawsigmaLxyz(bool doLog, int binJetPt);
    void drawDataVsSim3ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawDataVsSim3ProngRawSxyN1(bool withInc, bool doLog, int binJetPt);

    // templtae fit
    
    void drawTemplateFitMC();
    void drawTemplateFitMCN1();
    void drawTemplateFitMCtaggedjetN1();

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
    TH1F* hsimSVEffi3ProngSxyzN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyTaggerPoint[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimSVPurity3ProngSxy[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyz[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyzN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyTaggerPoint[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimSVEffiAndPurity3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyzRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVEffi3ProngSxyzN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyzRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimSVPurity3ProngSxyzN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjetSVEffi3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjetSVEffi3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjetSVPurity3ProngSxyN1[HfJetTagging::nFlavour+1];
    TH1F* hsimtaggedjetSVPurity3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1];

    // hist from root (Data)
    TH2F* h2dataTagjetPt2ProngLxy;
    TH2F* h2dataTagjetPt2ProngLxyz;
    TH2F* h2dataTagjetPt2ProngSxy;
    TH2F* h2dataTagjetPt2ProngSxyz;
    TH2F* h2dataTagjetPt2ProngsigmaLxy;
    TH2F* h2dataTagjetPt2ProngsigmaLxyz;
    TH2F* h2dataTagjetPt2ProngSxyN1;
    TH2F* h2dataTagjetPt2ProngSxyzN1;
    TH2F* h2dataTagjet2ProngSxysigmaLxy;
    TH2F* h2dataTagjet2ProngSxyzsigmaLxyz;
    TH2F* h2dataTagjetPt2ProngSxyCutSxyAndsigmaLxy;
    TH2F* h2dataTagjetPt2ProngSxyzCutSxyzAndsigmaLxyz;
    TH2F* h2dataTagjetPt2ProngSxyN1CutSxyAndsigmaLxy;
    TH2F* h2dataTagjetPt2ProngSxyzN1CutSxyzAndsigmaLxyz;

    TH2F* h2dataTagjetPt3ProngLxy;
    TH2F* h2dataTagjetPt3ProngLxyz;
    TH2F* h2dataTagjetPt3ProngSxy;
    TH2F* h2dataTagjetPt3ProngSxyz;
    TH2F* h2dataTagjetPt3ProngsigmaLxy;
    TH2F* h2dataTagjetPt3ProngsigmaLxyz;
    TH2F* h2dataTagjetPt3ProngSxyN1;
    TH2F* h2dataTagjetPt3ProngSxyzN1;
    TH2F* h2dataTagjet3ProngSxysigmaLxy;
    TH2F* h2dataTagjet3ProngSxyzsigmaLxyz;
    TH2F* h2dataTagjetPt3ProngSxyCutSxyAndsigmaLxy;
    TH2F* h2dataTagjetPt3ProngSxyzCutSxyzAndsigmaLxyz;
    TH2F* h2dataTagjetPt3ProngSxyN1CutSxyAndsigmaLxy;
    TH2F* h2dataTagjetPt3ProngSxyzN1CutSxyzAndsigmaLxyz;

    // hist (Data)
    TH1F* hdataTagjet2ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyCutsigmaLxy;
    TH1F* hdataTagjet2ProngsigmaLxyCutSxy;
    TH1F* hdataTagjet2ProngSxyzCutsigmaLxyz;
    TH1F* hdataTagjet2ProngsigmaLxyzCutSxyz;
    TH1F* hdataTagjet2ProngSxyCutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyzCutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyN1CutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet2ProngSxyzN1CutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];

    TH1F* hdataTagjet3ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyCutsigmaLxy;
    TH1F* hdataTagjet3ProngsigmaLxyCutSxy;
    TH1F* hdataTagjet3ProngSxyzCutsigmaLxyz;
    TH1F* hdataTagjet3ProngsigmaLxyzCutSxyz;
    TH1F* hdataTagjet3ProngSxyCutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyzCutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyN1CutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjet3ProngSxyzN1CutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];

    TH1F* hdataTagjetNormalized2ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyCutsigmaLxy;
    TH1F* hdataTagjetNormalized2ProngsigmaLxyCutSxy;
    TH1F* hdataTagjetNormalized2ProngSxyzCutsigmaLxyz;
    TH1F* hdataTagjetNormalized2ProngsigmaLxyzCutSxyz;
    TH1F* hdataTagjetNormalized2ProngSxyCutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyzCutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyN1CutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized2ProngSxyzN1CutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyzN1[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyCutsigmaLxy;
    TH1F* hdataTagjetNormalized3ProngsigmaLxyCutSxy;
    TH1F* hdataTagjetNormalized3ProngSxyzCutsigmaLxyz;
    TH1F* hdataTagjetNormalized3ProngsigmaLxyzCutSxyz;
    TH1F* hdataTagjetNormalized3ProngSxyCutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyzCutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyN1CutSxyAndsigmaLxy[HfJetTagging::nBinsJetPt+1];
    TH1F* hdataTagjetNormalized3ProngSxyzN1CutSxyzAndsigmaLxyz[HfJetTagging::nBinsJetPt+1];

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
    TH3F* h3simjetPt3ProngLxyFlavourRun2Def;
    TH3F* h3simjetPt3ProngLxyzFlavourRun2Def;
    TH3F* h3simjetPt3ProngSxyFlavourRun2Def;
    TH3F* h3simjetPt3ProngSxyzFlavourRun2Def;
    TH3F* h3simjetPt3ProngsigmaLxyFlavourRun2Def;
    TH3F* h3simjetPt3ProngSxyN1FlavourRun2Def;
    TH3F* h3simjetPt3ProngSxyzN1FlavourRun2Def;
    TH3F* h3simjetPt3ProngMassN1FlavourRun2Def;
    TH3F* h3simtaggedjetPt3ProngSxyN1FlavourRun2Def;
    TH3F* h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def;
    TH3F* h3simtaggedjetPt3ProngMassN1FlavourRun2Def;

    // hist (MC)
    TH1F* hsim2ProngjetPt[HfJetTagging::nFlavour+1];
    TH1F* hsim3ProngjetPt[HfJetTagging::nFlavour+1];
    TH1F* hsim3ProngjetPtRun2Def[HfJetTagging::nFlavour+1];
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
    TH1F* hsimjet3ProngChi2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngLxyRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngLxyzRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyzRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngsigmaLxyRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngsigmaLxyzRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngSxyzN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjet3ProngMassN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjet3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjet3ProngSxyzN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjet3ProngMassN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimjetNormalized2ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized2ProngChi2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];


    TH1F* hsimjetNormalized3ProngLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngSxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngSxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngsigmaLxy[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngsigmaLxyz[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormalized3ProngSxyN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormalized3ProngSxyzN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormalized3ProngMassN1[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngSxyzN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngMassN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormalized3ProngSxyN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormalized3ProngSxyzN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtaggedjetNormalized3ProngMassN1Run2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalized3ProngChi2[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;
    bool fill2Prong = false;
    bool fill3Prong = false;
    bool fillN1 = false;
    bool fillEffi = false;
    float effi2ProngTopo[HfJetTagging::nBinsJetPt+1] = {-1.};
    float purity2ProngTopo[HfJetTagging::nBinsJetPt+1] = {-1.};
    float effi3ProngTopo[HfJetTagging::nBinsJetPt+1] = {-1.};
    float purity3ProngTopo[HfJetTagging::nBinsJetPt+1] = {-1.};

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
      if (hsimjetNormalized2ProngLxy[flavour][jetPt]) delete hsimjetNormalized2ProngLxy[flavour][jetPt];
      if (hsimjetNormalized2ProngLxyz[flavour][jetPt]) delete hsimjetNormalized2ProngLxyz[flavour][jetPt];
      if (hsimjetNormalized2ProngSxy[flavour][jetPt]) delete hsimjetNormalized2ProngSxy[flavour][jetPt];
      if (hsimjetNormalized2ProngSxyz[flavour][jetPt]) delete hsimjetNormalized2ProngSxyz[flavour][jetPt];
      if (hsimjetNormalized2ProngsigmaLxy[flavour][jetPt]) delete hsimjetNormalized2ProngsigmaLxy[flavour][jetPt];
      if (hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt]) delete hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt];
      if (hsimjetNormalized3ProngLxy[flavour][jetPt]) delete hsimjetNormalized3ProngLxy[flavour][jetPt];
      if (hsimjetNormalized3ProngLxyz[flavour][jetPt]) delete hsimjetNormalized3ProngLxyz[flavour][jetPt];
      if (hsimjetNormalized3ProngSxy[flavour][jetPt]) delete hsimjetNormalized3ProngSxy[flavour][jetPt];
      if (hsimjetNormalized3ProngSxyz[flavour][jetPt]) delete hsimjetNormalized3ProngSxyz[flavour][jetPt];
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
  gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingSVAnalysis::loadDataSVQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, SV QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";
  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  if (fillData && fill2Prong) {
    h2dataTagjetPt2ProngLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Lxy", taskName.Data())));
    h2dataTagjetPt2ProngLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Lxyz", taskName.Data())));
    h2dataTagjetPt2ProngSxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxy", taskName.Data())));
    h2dataTagjetPt2ProngSxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxyz", taskName.Data())));
    h2dataTagjetPt2ProngsigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_sigmaLxy", taskName.Data())));
    h2dataTagjetPt2ProngsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_sigmaLxyz", taskName.Data())));
    h2dataTagjet2ProngSxysigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_2prong_Sxy_sigmaLxy", taskName.Data())));
    h2dataTagjet2ProngSxyzsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_2prong_Sxyz_sigmaLxyz", taskName.Data())));
    if (fillN1) {
      h2dataTagjetPt2ProngSxyN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxy_N1", taskName.Data())));
      h2dataTagjetPt2ProngSxyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_2prong_Sxyz_N1", taskName.Data())));
    }
  }
  if (fillData && fill3Prong) {
    h2dataTagjetPt3ProngLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Lxy", taskName.Data())));
    h2dataTagjetPt3ProngLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Lxyz", taskName.Data())));
    h2dataTagjetPt3ProngSxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxy", taskName.Data())));
    h2dataTagjetPt3ProngSxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxyz", taskName.Data())));
    h2dataTagjetPt3ProngsigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_sigmaLxy", taskName.Data())));
    h2dataTagjetPt3ProngsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_sigmaLxyz", taskName.Data())));
    h2dataTagjet3ProngSxysigmaLxy = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_3prong_Sxy_sigmaLxy", taskName.Data())));
    h2dataTagjet3ProngSxyzsigmaLxyz = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_3prong_Sxyz_sigmaLxyz", taskName.Data())));
    if (fillN1) {
      h2dataTagjetPt3ProngSxyN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxy_N1", taskName.Data())));
      h2dataTagjetPt3ProngSxyzN1 = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_3prong_Sxyz_N1", taskName.Data())));
    }
  }
  std::cout << "Load completed SV data" << std::endl;
  return 1;
}

int HfJetTaggingSVAnalysis::loadSimSVQA(TString rootSim) {
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
    if (fillN1) {
      h3simjetPt3ProngSxyN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_N1_flavour", taskName.Data())));
      h3simjetPt3ProngSxyzN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_N1_flavour", taskName.Data())));
      h3simjetPt3ProngMassN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_mass_N1_flavour", taskName.Data())));
      h3simtaggedjetPt3ProngSxyN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxy_N1_flavour", taskName.Data())));
      h3simtaggedjetPt3ProngSxyzN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxyz_N1_flavour", taskName.Data())));
      h3simtaggedjetPt3ProngMassN1Flavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_mass_N1_flavour", taskName.Data())));
    }
    if (fillTest) {
      h3simjetPt3ProngChi2Flavour =reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_jet_pt_3prong_chi2_flavour", taskName.Data())));
    }
  }
  if (fillRun2Def && fill3Prong) {
    h3simjetPt3ProngLxyFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Lxy_flavour_run2", taskName.Data())));
    h3simjetPt3ProngLxyzFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Lxyz_flavour_run2", taskName.Data())));
    h3simjetPt3ProngSxyFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_flavour_run2", taskName.Data())));
    h3simjetPt3ProngSxyzFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_flavour_run2", taskName.Data())));
    if (fillN1) {
      h3simjetPt3ProngSxyN1FlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_N1_flavour_run2", taskName.Data())));
      h3simjetPt3ProngSxyzN1FlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_N1_flavour_run2", taskName.Data())));
      h3simjetPt3ProngMassN1FlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_mass_N1_flavour_run2", taskName.Data())));
      h3simtaggedjetPt3ProngSxyN1FlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxy_N1_flavour_run2", taskName.Data())));
      h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxyz_N1_flavour_run2", taskName.Data())));
      h3simtaggedjetPt3ProngMassN1FlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_mass_N1_flavour_run2", taskName.Data())));
    }
  }
  std::cout << "Load completed SV MC" << std::endl;
  return 1;
}

void HfJetTaggingSVAnalysis::initHistogramForNormalizationSVQAData() {
  if (fillData && fill2Prong) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hdataTagjet2ProngLxy[jetPt] = new TH1F(Form("hdataTagjet2ProngLxy_%d", jetPt), "", h2dataTagjetPt2ProngLxy->GetNbinsY(), h2dataTagjetPt2ProngLxy->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngLxy->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngLxy->GetNbinsY()));
      hdataTagjet2ProngLxyz[jetPt] = new TH1F(Form("hdataTagjet2ProngLxyz_%d", jetPt), "", h2dataTagjetPt2ProngLxyz->GetNbinsY(), h2dataTagjetPt2ProngLxyz->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngLxyz->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngLxyz->GetNbinsY()));
      hdataTagjet2ProngSxy[jetPt] = new TH1F(Form("hdataTagjet2ProngSxy_%d", jetPt), "", h2dataTagjetPt2ProngSxy->GetNbinsY(), h2dataTagjetPt2ProngSxy->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngSxy->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngSxy->GetNbinsY()));
      hdataTagjet2ProngSxyz[jetPt] = new TH1F(Form("hdataTagjet2ProngSxyz_%d", jetPt), "", h2dataTagjetPt2ProngSxyz->GetNbinsY(), h2dataTagjetPt2ProngSxyz->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngSxyz->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngSxyz->GetNbinsY()));
      hdataTagjet2ProngsigmaLxy[jetPt] = new TH1F(Form("hdataTagjet2ProngsigmaLxy_%d", jetPt), "", h2dataTagjetPt2ProngsigmaLxy->GetNbinsY(), h2dataTagjetPt2ProngsigmaLxy->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngsigmaLxy->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngsigmaLxy->GetNbinsY()));
      hdataTagjet2ProngsigmaLxyz[jetPt] = new TH1F(Form("hdataTagjet2ProngsigmaLxyz_%d", jetPt), "", h2dataTagjetPt2ProngsigmaLxyz->GetNbinsY(), h2dataTagjetPt2ProngsigmaLxyz->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngsigmaLxyz->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngsigmaLxyz->GetNbinsY()));
      if (fillN1) {
        hdataTagjet2ProngSxyN1[jetPt] = new TH1F(Form("hdataTagjet2ProngSxyN1_%d", jetPt), "", h2dataTagjetPt2ProngSxyN1->GetNbinsY(), h2dataTagjetPt2ProngSxyN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngSxyN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngSxyN1->GetNbinsY()));
        hdataTagjet2ProngSxyzN1[jetPt] = new TH1F(Form("hdataTagjet2ProngSxyzN1_%d", jetPt), "", h2dataTagjetPt2ProngSxyzN1->GetNbinsY(), h2dataTagjetPt2ProngSxyzN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt2ProngSxyzN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPt2ProngSxyzN1->GetNbinsY()));
      }
    }
  }
  if (fillData && fill3Prong) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hdataTagjet3ProngLxy[jetPt] = new TH1F(Form("hdataTagjet3ProngLxy_%d", jetPt), "", h2dataTagjetPt3ProngLxy->GetNbinsY(), h2dataTagjetPt3ProngLxy->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngLxy->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngLxy->GetNbinsY()));
      hdataTagjet3ProngLxyz[jetPt] = new TH1F(Form("hdataTagjet3ProngLxyz_%d", jetPt), "", h2dataTagjetPt3ProngLxyz->GetNbinsY(), h2dataTagjetPt3ProngLxyz->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngLxyz->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngLxyz->GetNbinsY()));
      hdataTagjet3ProngSxy[jetPt] = new TH1F(Form("hdataTagjet3ProngSxy_%d", jetPt), "", h2dataTagjetPt3ProngSxy->GetNbinsY(), h2dataTagjetPt3ProngSxy->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngSxy->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngSxy->GetNbinsY()));
      hdataTagjet3ProngSxyz[jetPt] = new TH1F(Form("hdataTagjet3ProngSxyz_%d", jetPt), "", h2dataTagjetPt3ProngSxyz->GetNbinsY(), h2dataTagjetPt3ProngSxyz->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngSxyz->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngSxyz->GetNbinsY()));
      hdataTagjet3ProngsigmaLxy[jetPt] = new TH1F(Form("hdataTagjet3ProngsigmaLxy_%d", jetPt), "", h2dataTagjetPt3ProngsigmaLxy->GetNbinsY(), h2dataTagjetPt3ProngsigmaLxy->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngsigmaLxy->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngsigmaLxy->GetNbinsY()));
      hdataTagjet3ProngsigmaLxyz[jetPt] = new TH1F(Form("hdataTagjet3ProngsigmaLxyz_%d", jetPt), "", h2dataTagjetPt3ProngsigmaLxyz->GetNbinsY(), h2dataTagjetPt3ProngsigmaLxyz->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngsigmaLxyz->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngsigmaLxyz->GetNbinsY()));
      if (fillN1) {
        hdataTagjet3ProngSxyN1[jetPt] = new TH1F(Form("hdataTagjet3ProngSxyN1_%d", jetPt), "", h2dataTagjetPt3ProngSxyN1->GetNbinsY(), h2dataTagjetPt3ProngSxyN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngSxyN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngSxyN1->GetNbinsY()));
        hdataTagjet3ProngSxyzN1[jetPt] = new TH1F(Form("hdataTagjet3ProngSxyzN1_%d", jetPt), "", h2dataTagjetPt3ProngSxyzN1->GetNbinsY(), h2dataTagjetPt3ProngSxyzN1->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPt3ProngSxyzN1->GetYaxis()->GetBinUpEdge(h2dataTagjetPt3ProngSxyzN1->GetNbinsY()));
      }
    }
  }
}

void HfJetTaggingSVAnalysis::initHistogramForNormalizationSVQAMC() {
  if (fillMCD && fill2Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsim2ProngjetPt[flavour] = new TH1F(Form("hsim2ProngjetPt_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
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
      hsim3ProngjetPt[flavour] = new TH1F(Form("hsim3ProngjetPt_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxy[flavour] = new TH1F(Form("hsimSVEffi3ProngSxy_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyz[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyz_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyN1[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyzN1[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyzN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxy[flavour] = new TH1F(Form("hsimSVPurity3ProngSxy_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyz[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyz_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyN1[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyzN1[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyzN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffiAndPurity3ProngSxyN1[flavour] = new TH1F(Form("hsimSVEffiAndPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimtaggedjetSVEffi3ProngSxyN1[flavour] = new TH1F(Form("hsimtaggedjetSVEffi3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimtaggedjetSVPurity3ProngSxyN1[flavour] = new TH1F(Form("hsimtaggedjetSVPurity3ProngSxyN1_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimtaggedjetSVEffi3ProngSxyN1Run2Def[flavour] = new TH1F(Form("hsimtaggedjetSVEffi3ProngSxyN1Run2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimtaggedjetSVPurity3ProngSxyN1Run2Def[flavour] = new TH1F(Form("hsimtaggedjetSVPurity3ProngSxyN1Run2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
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
  if (fillRun2Def && fill3Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsim3ProngjetPtRun2Def[flavour] = new TH1F(Form("hsim3ProngjetPtRun2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyRun2Def[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyRun2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyzRun2Def[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyzRun2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyN1Run2Def[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyN1Run2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVEffi3ProngSxyzN1Run2Def[flavour] = new TH1F(Form("hsimSVEffi3ProngSxyzN1Run2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyRun2Def[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyRun2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyzRun2Def[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyzRun2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyN1Run2Def[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyN1Run2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
		  hsimSVPurity3ProngSxyzN1Run2Def[flavour] = new TH1F(Form("hsimSVPurity3ProngSxyzN1Run2Def_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillN1) {
          hsimjet3ProngSxyN1Run2Def[flavour][jetPt] = new TH1F(Form("hsimjet3ProngSxyN1Run2Def_%d_%d", flavour, jetPt), "", h3simjetPt3ProngSxyN1FlavourRun2Def->GetNbinsY(), h3simjetPt3ProngSxyN1FlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyN1FlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyN1FlavourRun2Def->GetNbinsY()));
          hsimjet3ProngSxyzN1Run2Def[flavour][jetPt] = new TH1F(Form("hsimjet3ProngSxyzN1Run2Def_%d_%d", flavour, jetPt), "", h3simjetPt3ProngSxyzN1FlavourRun2Def->GetNbinsY(), h3simjetPt3ProngSxyzN1FlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyzN1FlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyzN1FlavourRun2Def->GetNbinsY()));
          hsimjet3ProngMassN1Run2Def[flavour][jetPt] = new TH1F(Form("hsimjet3ProngMassN1Run2Def_%d_%d", flavour, jetPt), "", h3simjetPt3ProngMassN1FlavourRun2Def->GetNbinsY(), h3simjetPt3ProngMassN1FlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngMassN1FlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngMassN1FlavourRun2Def->GetNbinsY()));
          hsimtaggedjet3ProngSxyN1Run2Def[flavour][jetPt] = new TH1F(Form("hsimtaggedjet3ProngSxyN1Run2Def_%d_%d", flavour, jetPt), "", h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetNbinsY(), h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetNbinsY()));
          hsimtaggedjet3ProngSxyzN1Run2Def[flavour][jetPt] = new TH1F(Form("hsimtaggedjet3ProngSxyzN1Run2Def_%d_%d", flavour, jetPt), "", h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetNbinsY(), h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetNbinsY()));
          hsimtaggedjet3ProngMassN1Run2Def[flavour][jetPt] = new TH1F(Form("hsimtaggedjet3ProngMassN1Run2Def_%d_%d", flavour, jetPt), "", h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetNbinsY(), h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetNbinsY()));
        }
      }
    }
  }
  std::cout << "init hist " << std::endl;
}

void HfJetTaggingSVAnalysis::projectionHistSVQAData() {
  if (fillData && fill2Prong) {
    TH1F* proj2ProngLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngLxy->ProjectionY("proj2ProngLxy", 1, h2dataTagjetPt2ProngLxy->GetNbinsX()));
    TH1F* proj2ProngLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngLxyz->ProjectionY("proj2ProngLxyz", 1, h2dataTagjetPt2ProngLxyz->GetNbinsX()));
    TH1F* proj2ProngSxy = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngSxy->ProjectionY("proj2ProngSxy", 1, h2dataTagjetPt2ProngSxy->GetNbinsX()));
    TH1F* proj2ProngSxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngSxyz->ProjectionY("proj2ProngSxyz", 1, h2dataTagjetPt2ProngSxyz->GetNbinsX()));
    TH1F* proj2ProngsigmaLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngsigmaLxy->ProjectionY("proj2ProngsigmaLxy", 1, h2dataTagjetPt2ProngsigmaLxy->GetNbinsX()));
    TH1F* proj2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngsigmaLxyz->ProjectionY("proj2ProngsigmaLxyz", 1, h2dataTagjetPt2ProngsigmaLxyz->GetNbinsX()));

    hdataTagjet2ProngLxy[0] = reinterpret_cast<TH1F*>(proj2ProngLxy->Clone("hdataTagjet2ProngLxy_0"));
    hdataTagjet2ProngLxyz[0] = reinterpret_cast<TH1F*>(proj2ProngLxyz->Clone("hdataTagjet2ProngLxyz_0"));
    hdataTagjet2ProngSxy[0] = reinterpret_cast<TH1F*>(proj2ProngSxy->Clone("hdataTagjet2ProngSxy_0"));
    hdataTagjet2ProngSxyz[0] = reinterpret_cast<TH1F*>(proj2ProngSxyz->Clone("hdataTagjet2ProngSxyz_0"));
    hdataTagjet2ProngsigmaLxy[0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxy->Clone("hdataTagjet2ProngsigmaLxy_0"));
    hdataTagjet2ProngsigmaLxyz[0] = reinterpret_cast<TH1F*>(proj2ProngsigmaLxyz->Clone("hdataTagjet2ProngsigmaLxyz_0"));

    for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      int leftbinJetPt2ProngLxy = h2dataTagjetPt2ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngLxy = h2dataTagjetPt2ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngLxy->ProjectionY(Form("projJetPtRange2ProngLxy_%d", binJetPt), leftbinJetPt2ProngLxy, rightbinJetPt2ProngLxy));
      hdataTagjet2ProngLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxy->Clone(Form("hsimjet2ProngLxy_%d", binJetPt))); 

      int leftbinJetPt2ProngLxyz = h2dataTagjetPt2ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngLxyz = h2dataTagjetPt2ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngLxyz->ProjectionY(Form("projJetPtRange2ProngLxyz_%d", binJetPt), leftbinJetPt2ProngLxyz, rightbinJetPt2ProngLxyz));
      hdataTagjet2ProngLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngLxyz->Clone(Form("hsimjet2ProngLxyz_%d", binJetPt))); 

      int leftbinJetPt2ProngSxy = h2dataTagjetPt2ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngSxy = h2dataTagjetPt2ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngSxy = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngSxy->ProjectionY(Form("projJetPtRange2ProngSxy_%d", binJetPt), leftbinJetPt2ProngSxy, rightbinJetPt2ProngSxy));
      hdataTagjet2ProngSxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxy->Clone(Form("hsimjet2ProngSxy_%d", binJetPt))); 

      int leftbinJetPt2ProngSxyz = h2dataTagjetPt2ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngSxyz = h2dataTagjetPt2ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngSxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngSxyz->ProjectionY(Form("projJetPtRange2ProngSxyz_%d", binJetPt), leftbinJetPt2ProngSxyz, rightbinJetPt2ProngSxyz));
      hdataTagjet2ProngSxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngSxyz->Clone(Form("hsimjet2ProngSxyz_%d", binJetPt))); 

      int leftbinJetPt2ProngsigmaLxy = h2dataTagjetPt2ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngsigmaLxy = h2dataTagjetPt2ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngsigmaLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngsigmaLxy->ProjectionY(Form("projJetPtRange2ProngsigmaLxy_%d", binJetPt), leftbinJetPt2ProngsigmaLxy, rightbinJetPt2ProngsigmaLxy));
      hdataTagjet2ProngsigmaLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxy->Clone(Form("hsimjet2ProngsigmaLxy_%d", binJetPt))); 

      int leftbinJetPt2ProngsigmaLxyz = h2dataTagjetPt2ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt2ProngsigmaLxyz = h2dataTagjetPt2ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange2ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt2ProngsigmaLxyz->ProjectionY(Form("projJetPtRange2ProngsigmaLxyz_%d", binJetPt), leftbinJetPt2ProngsigmaLxyz, rightbinJetPt2ProngsigmaLxyz));
      hdataTagjet2ProngsigmaLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange2ProngsigmaLxyz->Clone(Form("hsimjet2ProngsigmaLxyz_%d", binJetPt))); 
    }
  }
  if (fillData && fill3Prong) {
    TH1F* proj3ProngLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngLxy->ProjectionY("proj3ProngLxy", 1, h2dataTagjetPt3ProngLxy->GetNbinsX()));
    TH1F* proj3ProngLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngLxyz->ProjectionY("proj3ProngLxyz", 1, h2dataTagjetPt3ProngLxyz->GetNbinsX()));
    TH1F* proj3ProngSxy = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngSxy->ProjectionY("proj3ProngSxy", 1, h2dataTagjetPt3ProngSxy->GetNbinsX()));
    TH1F* proj3ProngSxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngSxyz->ProjectionY("proj3ProngSxyz", 1, h2dataTagjetPt3ProngSxyz->GetNbinsX()));
    TH1F* proj3ProngsigmaLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngsigmaLxy->ProjectionY("proj3ProngsigmaLxy", 1, h2dataTagjetPt3ProngsigmaLxy->GetNbinsX()));
    TH1F* proj3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngsigmaLxyz->ProjectionY("proj3ProngsigmaLxyz", 1, h2dataTagjetPt3ProngsigmaLxyz->GetNbinsX()));

    hdataTagjet3ProngLxy[0] = reinterpret_cast<TH1F*>(proj3ProngLxy->Clone("hdataTagjet3ProngLxy_0"));
    hdataTagjet3ProngLxyz[0] = reinterpret_cast<TH1F*>(proj3ProngLxyz->Clone("hdataTagjet3ProngLxyz_0"));
    hdataTagjet3ProngSxy[0] = reinterpret_cast<TH1F*>(proj3ProngSxy->Clone("hdataTagjet3ProngSxy_0"));
    hdataTagjet3ProngSxyz[0] = reinterpret_cast<TH1F*>(proj3ProngSxyz->Clone("hdataTagjet3ProngSxyz_0"));
    hdataTagjet3ProngsigmaLxy[0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxy->Clone("hdataTagjet3ProngsigmaLxy_0"));
    hdataTagjet3ProngsigmaLxyz[0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxyz->Clone("hdataTagjet3ProngsigmaLxyz_0"));

    for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
      int leftbinJetPt3ProngLxy = h2dataTagjetPt3ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngLxy = h2dataTagjetPt3ProngLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngLxy->ProjectionY(Form("projJetPtRange3ProngLxy_%d", binJetPt), leftbinJetPt3ProngLxy, rightbinJetPt3ProngLxy));
      hdataTagjet3ProngLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxy->Clone(Form("hsimjet3ProngLxy_%d", binJetPt))); 

      int leftbinJetPt3ProngLxyz = h2dataTagjetPt3ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngLxyz = h2dataTagjetPt3ProngLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngLxyz->ProjectionY(Form("projJetPtRange3ProngLxyz_%d", binJetPt), leftbinJetPt3ProngLxyz, rightbinJetPt3ProngLxyz));
      hdataTagjet3ProngLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxyz->Clone(Form("hsimjet3ProngLxyz_%d", binJetPt))); 

      int leftbinJetPt3ProngSxy = h2dataTagjetPt3ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngSxy = h2dataTagjetPt3ProngSxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngSxy = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngSxy->ProjectionY(Form("projJetPtRange3ProngSxy_%d", binJetPt), leftbinJetPt3ProngSxy, rightbinJetPt3ProngSxy));
      hdataTagjet3ProngSxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxy->Clone(Form("hsimjet3ProngSxy_%d", binJetPt))); 

      int leftbinJetPt3ProngSxyz = h2dataTagjetPt3ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngSxyz = h2dataTagjetPt3ProngSxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngSxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngSxyz->ProjectionY(Form("projJetPtRange3ProngSxyz_%d", binJetPt), leftbinJetPt3ProngSxyz, rightbinJetPt3ProngSxyz));
      hdataTagjet3ProngSxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyz->Clone(Form("hsimjet3ProngSxyz_%d", binJetPt))); 

      int leftbinJetPt3ProngsigmaLxy = h2dataTagjetPt3ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngsigmaLxy = h2dataTagjetPt3ProngsigmaLxy->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngsigmaLxy = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngsigmaLxy->ProjectionY(Form("projJetPtRange3ProngsigmaLxy_%d", binJetPt), leftbinJetPt3ProngsigmaLxy, rightbinJetPt3ProngsigmaLxy));
      hdataTagjet3ProngsigmaLxy[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxy->Clone(Form("hsimjet3ProngsigmaLxy_%d", binJetPt))); 

      int leftbinJetPt3ProngsigmaLxyz = h2dataTagjetPt3ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPt3ProngsigmaLxyz = h2dataTagjetPt3ProngsigmaLxyz->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRange3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h2dataTagjetPt3ProngsigmaLxyz->ProjectionY(Form("projJetPtRange3ProngsigmaLxyz_%d", binJetPt), leftbinJetPt3ProngsigmaLxyz, rightbinJetPt3ProngsigmaLxyz));
      hdataTagjet3ProngsigmaLxyz[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxyz->Clone(Form("hsimjet3ProngsigmaLxyz_%d", binJetPt))); 
    }
  }
}

void HfJetTaggingSVAnalysis::projectionHistSVQAMC() {
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
          hsim2ProngjetPt[flavour]->SetBinContent(binJetPt, binContent);
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

      if (fillTest) {
        TH1F* proj3ProngChi2 = reinterpret_cast<TH1F*> (h3simjetPt3ProngChi2Flavour->ProjectionY(Form("proj3ProngChi2_%d", binFlavour), 1, h3simjetPt3ProngChi2Flavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjet3ProngChi2[0][0]->Add(proj3ProngChi2);
        hsimjet3ProngChi2[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngChi2->Clone(Form("hsimjet3ProngChi2_%d_0", flavour)));
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
          hsim3ProngjetPt[flavour]->SetBinContent(binJetPt, binContent);

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
  if (fillRun2Def && fill3Prong) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      if (fillN1) {
        TH1F* proj3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyN1FlavourRun2Def->ProjectionY(Form("proj3ProngSxyN1_%d", binFlavour), 1, h3simjetPt3ProngSxyN1FlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* proj3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzN1FlavourRun2Def->ProjectionY(Form("proj3ProngSxyzN1_%d", binFlavour), 1, h3simjetPt3ProngSxyzN1FlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* proj3ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngMassN1FlavourRun2Def->ProjectionY(Form("proj3ProngMassN1_%d", binFlavour), 1, h3simjetPt3ProngMassN1FlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        hsimjet3ProngSxyN1Run2Def[0][0]->Add(proj3ProngSxyN1);
        hsimjet3ProngSxyzN1Run2Def[0][0]->Add(proj3ProngSxyzN1);
        hsimjet3ProngMassN1Run2Def[0][0]->Add(proj3ProngMassN1);
        hsimjet3ProngSxyN1Run2Def[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyN1->Clone(Form("hsimjet3ProngSxyN1Run2Def_%d_0", flavour)));
        hsimjet3ProngSxyzN1Run2Def[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyzN1->Clone(Form("hsimjet3ProngSxyzN1_%d_0", flavour)));
        hsimjet3ProngMassN1Run2Def[flavour][0] = reinterpret_cast<TH1F*>(proj3ProngMassN1->Clone(Form("hsimjet3ProngMassN1_%d_0", flavour)));

        TH1F* projtaggedjet3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->ProjectionY(Form("projtaggedjet3ProngSxyN1_%d", binFlavour), 1, h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projtaggedjet3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->ProjectionY(Form("projtaggedjet3ProngSxyzN1_%d", binFlavour), 1, h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projtaggedjet3ProngMassN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngMassN1FlavourRun2Def->ProjectionY(Form("projtaggedjet3ProngMassN1_%d", binFlavour), 1, h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        hsimtaggedjet3ProngSxyN1Run2Def[0][0]->Add(projtaggedjet3ProngSxyN1);
        hsimtaggedjet3ProngSxyzN1Run2Def[0][0]->Add(projtaggedjet3ProngSxyzN1);
        hsimtaggedjet3ProngMassN1Run2Def[0][0]->Add(projtaggedjet3ProngMassN1);
        hsimtaggedjet3ProngSxyN1Run2Def[flavour][0] = reinterpret_cast<TH1F*>(projtaggedjet3ProngSxyN1->Clone(Form("hsimtaggedjet3ProngSxyN1_%d_0", flavour)));
        hsimtaggedjet3ProngSxyzN1Run2Def[flavour][0] = reinterpret_cast<TH1F*>(projtaggedjet3ProngSxyzN1->Clone(Form("hsimtaggedjet3ProngSxyzN1_%d_0", flavour)));
        hsimtaggedjet3ProngMassN1Run2Def[flavour][0] = reinterpret_cast<TH1F*>(projtaggedjet3ProngMassN1->Clone(Form("hsimtaggedjet3ProngMassN1_%d_0", flavour)));
      }
      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (fillN1) {
          int leftbinJetPt3ProngSxyN1 = h3simjetPt3ProngSxyN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt3ProngSxyN1 = h3simjetPt3ProngSxyN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyN1FlavourRun2Def->ProjectionY(Form("projJetPtRange3ProngSxyN1_%d_%d", binJetPt, flavour), leftbinJetPt3ProngSxyN1, rightbinJetPt3ProngSxyN1, binFlavour, binFlavour));
          hsimjet3ProngSxyN1Run2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyN1->Clone(Form("hsimjet3ProngSxyN1Run2Def_%d_%d", flavour, binJetPt))); 
          hsimjet3ProngSxyN1Run2Def[0][binJetPt]->Add(projJetPtRange3ProngSxyN1);

          int leftbinJetPt3ProngSxyzN1 = h3simjetPt3ProngSxyzN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt3ProngSxyzN1 = h3simjetPt3ProngSxyzN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzN1FlavourRun2Def->ProjectionY(Form("projJetPtRange3ProngSxyzN1_%d_%d", binJetPt, flavour), leftbinJetPt3ProngSxyzN1, rightbinJetPt3ProngSxyzN1, binFlavour, binFlavour));
          hsimjet3ProngSxyzN1Run2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyzN1->Clone(Form("hsimjet3ProngSxyzN1_%d_%d", flavour, binJetPt))); 
          hsimjet3ProngSxyzN1Run2Def[0][binJetPt]->Add(projJetPtRange3ProngSxyzN1);

          int leftbinJetPt3ProngMassN1 = h3simjetPt3ProngMassN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPt3ProngMassN1 = h3simjetPt3ProngMassN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngMassN1FlavourRun2Def->ProjectionY(Form("projJetPtRange3ProngMassN1_%d_%d", binJetPt, flavour), leftbinJetPt3ProngMassN1, rightbinJetPt3ProngMassN1, binFlavour, binFlavour));
          hsimjet3ProngMassN1Run2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngMassN1->Clone(Form("hsimjet3ProngMassN1_%d_%d", flavour, binJetPt))); 
          hsimjet3ProngMassN1Run2Def[0][binJetPt]->Add(projJetPtRange3ProngMassN1);

          double jetPtValue = HfJetTagging::binsJetPt[binJetPt - 1];
          int binJetPt3Prong = h3simjetPt3ProngSxyN1FlavourRun2Def->GetXaxis()->FindBin(jetPtValue);
          double binContent = h3simjetPt3ProngSxyN1FlavourRun2Def->Integral(binJetPt3Prong, binJetPt3Prong, 1, h3simjetPt3ProngSxyN1FlavourRun2Def->GetNbinsY(), 1, h3simjetPt3ProngSxyN1FlavourRun2Def->GetNbinsZ());
          hsim3ProngjetPtRun2Def[flavour]->SetBinContent(binJetPt, binContent);

          int leftbintaggedjetJetPt3ProngSxyN1 = h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbintaggedjetJetPt3ProngSxyN1 = h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projtaggedJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyN1FlavourRun2Def->ProjectionY(Form("projtaggedJetPtRange3ProngSxyN1Run2Def_%d_%d", binJetPt, flavour), leftbintaggedjetJetPt3ProngSxyN1, rightbintaggedjetJetPt3ProngSxyN1, binFlavour, binFlavour));
          hsimtaggedjet3ProngSxyN1Run2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projtaggedJetPtRange3ProngSxyN1->Clone(Form("hsimtaggedjet3ProngSxyN1Run2Def_%d_%d", flavour, binJetPt))); 
          hsimtaggedjet3ProngSxyN1Run2Def[0][binJetPt]->Add(projtaggedJetPtRange3ProngSxyN1);

          int leftbintaggedjetJetPt3ProngSxyzN1 = h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbintaggedjetJetPt3ProngSxyzN1 = h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projtaggedJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyzN1FlavourRun2Def->ProjectionY(Form("projtaggedJetPtRange3ProngSxyzN1Run2Def_%d_%d", binJetPt, flavour), leftbintaggedjetJetPt3ProngSxyzN1, rightbintaggedjetJetPt3ProngSxyzN1, binFlavour, binFlavour));
          hsimtaggedjet3ProngSxyzN1Run2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projtaggedJetPtRange3ProngSxyzN1->Clone(Form("hsimtaggedjet3ProngSxyzN1Run2Def_%d_%d", flavour, binJetPt))); 
          hsimtaggedjet3ProngSxyzN1Run2Def[0][binJetPt]->Add(projtaggedJetPtRange3ProngSxyzN1);

          int leftbintaggedjetJetPt3ProngMassN1 = h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbintaggedjetJetPt3ProngMassN1 = h3simtaggedjetPt3ProngMassN1FlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projtaggedJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngMassN1FlavourRun2Def->ProjectionY(Form("projtaggedJetPtRange3ProngMassN1Run2Def_%d_%d", binJetPt, flavour), leftbintaggedjetJetPt3ProngMassN1, rightbintaggedjetJetPt3ProngMassN1, binFlavour, binFlavour));
          hsimtaggedjet3ProngMassN1Run2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projtaggedJetPtRange3ProngMassN1->Clone(Form("hsimtaggedjet3ProngMassN1Run2Def_%d_%d", flavour, binJetPt))); 
          hsimtaggedjet3ProngMassN1Run2Def[0][binJetPt]->Add(projtaggedJetPtRange3ProngMassN1);

        }
      }
    }
  }
}

void HfJetTaggingSVAnalysis::normalizedHistogramSVQAData() {
  if (fillData && fill2Prong) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hdataTagjetNormalized2ProngLxy[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngLxy[jetPt]->Clone(Form("hdataTagjetNormalized2ProngLxy_%d", jetPt)));
      hdataTagjetNormalized2ProngLxyz[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngLxyz[jetPt]->Clone(Form("hdataTagjetNormalized2ProngLxyz_%d", jetPt)));
      hdataTagjetNormalized2ProngSxy[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngSxy[jetPt]->Clone(Form("hdataTagjetNormalized2ProngSxy_%d", jetPt)));
      hdataTagjetNormalized2ProngSxyz[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngSxyz[jetPt]->Clone(Form("hdataTagjetNormalized2ProngSxyz_%d", jetPt)));
      hdataTagjetNormalized2ProngsigmaLxy[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngsigmaLxy[jetPt]->Clone(Form("hdataTagjetNormalized2ProngsigmaLxy_%d", jetPt)));
      hdataTagjetNormalized2ProngsigmaLxyz[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngsigmaLxyz[jetPt]->Clone(Form("hdataTagjetNormalized2ProngsigmaLxyz_%d", jetPt)));
      hdataTagjetNormalized2ProngLxy[jetPt]->Scale(1. / hdataTagjetNormalized2ProngLxy[jetPt]->Integral());
      hdataTagjetNormalized2ProngLxyz[jetPt]->Scale(1. / hdataTagjetNormalized2ProngLxyz[jetPt]->Integral());
      hdataTagjetNormalized2ProngSxy[jetPt]->Scale(1. / hdataTagjetNormalized2ProngSxy[jetPt]->Integral());
      hdataTagjetNormalized2ProngSxyz[jetPt]->Scale(1. / hdataTagjetNormalized2ProngSxyz[jetPt]->Integral());
      hdataTagjetNormalized2ProngsigmaLxy[jetPt]->Scale(1. / hdataTagjetNormalized2ProngsigmaLxy[jetPt]->Integral());
      hdataTagjetNormalized2ProngsigmaLxyz[jetPt]->Scale(1. / hdataTagjetNormalized2ProngsigmaLxyz[jetPt]->Integral());
      if (fillN1) {
        hdataTagjetNormalized2ProngSxyN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngSxyN1[jetPt]->Clone("hdataTagjetNormalized2ProngSxyN1"));
        hdataTagjetNormalized2ProngSxyzN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngSxyzN1[jetPt]->Clone("hdataTagjetNormalized2ProngSxyzN1"));
        //hdataTagjetNormalized2ProngMassN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet2ProngMassN1[jetPt]->Clone("hdataTagjetNormalized2ProngMassN1"));
        hdataTagjetNormalized2ProngSxyN1[jetPt]->Scale(1. /hdataTagjetNormalized2ProngSxyN1[jetPt]->Integral());
        hdataTagjetNormalized2ProngSxyzN1[jetPt]->Scale(1. /hdataTagjetNormalized2ProngSxyzN1[jetPt]->Integral());
        //hdataTagjetNormalized2ProngMassN1[jetPt]->Scale(1. /hdataTagjetNormalized2ProngMassN1[jetPt]->Integral());
      }
    }
  }
  if (fillData && fill3Prong) {
    for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
      hdataTagjetNormalized3ProngLxy[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngLxy[jetPt]->Clone(Form("hdataTagjetNormalized3ProngLxy_%d", jetPt)));
      hdataTagjetNormalized3ProngLxyz[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngLxyz[jetPt]->Clone(Form("hdataTagjetNormalized3ProngLxyz_%d", jetPt)));
      hdataTagjetNormalized3ProngSxy[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngSxy[jetPt]->Clone(Form("hdataTagjetNormalized3ProngSxy_%d", jetPt)));
      hdataTagjetNormalized3ProngSxyz[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngSxyz[jetPt]->Clone(Form("hdataTagjetNormalized3ProngSxyz_%d", jetPt)));
      hdataTagjetNormalized3ProngsigmaLxy[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngsigmaLxy[jetPt]->Clone(Form("hdataTagjetNormalized3ProngsigmaLxy_%d", jetPt)));
      hdataTagjetNormalized3ProngsigmaLxyz[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngsigmaLxyz[jetPt]->Clone(Form("hdataTagjetNormalized3ProngsigmaLxyz_%d", jetPt)));
      hdataTagjetNormalized3ProngLxy[jetPt]->Scale(1. / hdataTagjetNormalized3ProngLxy[jetPt]->Integral());
      hdataTagjetNormalized3ProngLxyz[jetPt]->Scale(1. / hdataTagjetNormalized3ProngLxyz[jetPt]->Integral());
      hdataTagjetNormalized3ProngSxy[jetPt]->Scale(1. / hdataTagjetNormalized3ProngSxy[jetPt]->Integral(0, HfJetTagging::REFHIST::SXY[1]));
      //hdataTagjetNormalized3ProngSxy[jetPt]->Scale(1. / hdataTagjetNormalized3ProngSxy[jetPt]->Integral());
      hdataTagjetNormalized3ProngSxyz[jetPt]->Scale(1. / hdataTagjetNormalized3ProngSxyz[jetPt]->Integral());
      hdataTagjetNormalized3ProngsigmaLxy[jetPt]->Scale(1. / hdataTagjetNormalized3ProngsigmaLxy[jetPt]->Integral());
      hdataTagjetNormalized3ProngsigmaLxyz[jetPt]->Scale(1. / hdataTagjetNormalized3ProngsigmaLxyz[jetPt]->Integral());
      if (fillN1) {
        hdataTagjetNormalized3ProngSxyN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngSxyN1[jetPt]->Clone("hdataTagjetNormalized3ProngSxyN1"));
        hdataTagjetNormalized3ProngSxyzN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngSxyzN1[jetPt]->Clone("hdataTagjetNormalized3ProngSxyzN1"));
        //hdataTagjetNormalized3ProngMassN1[jetPt] = reinterpret_cast<TH1F*> (hdataTagjet3ProngMassN1[jetPt]->Clone("hdataTagjetNormalized3ProngMassN1"));
        hdataTagjetNormalized3ProngSxyN1[jetPt]->Scale(1. /hdataTagjetNormalized3ProngSxyN1[jetPt]->Integral());
        hdataTagjetNormalized3ProngSxyzN1[jetPt]->Scale(1. /hdataTagjetNormalized3ProngSxyzN1[jetPt]->Integral());
        //hdataTagjetNormalized3ProngMassN1[jetPt]->Scale(1. /hdataTagjetNormalized3ProngMassN1[jetPt]->Integral());
      }
    }
  }
}

void HfJetTaggingSVAnalysis::normalizedHistogramSVQAMC() {
  if (fillMCD && fill2Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        hsimjetNormalized2ProngLxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngLxy[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngLxy_%d_%d", flavour, jetPt)));
        hsimjetNormalized2ProngLxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngLxyz[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngLxyz_%d_%d", flavour, jetPt)));
        hsimjetNormalized2ProngSxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngSxy[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngSxy_%d_%d", flavour, jetPt)));
        hsimjetNormalized2ProngSxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngSxyz[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngSxyz_%d_%d", flavour, jetPt)));
        hsimjetNormalized2ProngsigmaLxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngsigmaLxy[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngsigmaLxy_%d_%d", flavour, jetPt)));
        hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngsigmaLxyz[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngsigmaLxyz_%d_%d", flavour, jetPt)));
        hsimjetNormalized2ProngLxy[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngLxy[flavour][jetPt]->Integral());
        hsimjetNormalized2ProngLxyz[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngLxyz[flavour][jetPt]->Integral());
        //hsimjetNormalized2ProngSxy[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngSxy[flavour][jetPt]->Integral(HfJetTagging::NOR::SXY[0], HfJetTagging::NOR::SXY[1]));
        hsimjetNormalized2ProngSxy[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngSxy[flavour][jetPt]->Integral());
        hsimjetNormalized2ProngSxyz[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngSxyz[flavour][jetPt]->Integral());
        hsimjetNormalized2ProngsigmaLxy[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngsigmaLxy[flavour][jetPt]->Integral());
        hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt]->Integral());
        if (fillN1) {
          hsimjetNormalized2ProngSxyN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngSxyN1[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngSxyN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized2ProngSxyzN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngSxyzN1[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngSxyzN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized2ProngMassN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet2ProngMassN1[flavour][jetPt]->Clone(Form("hsimjetNormalized2ProngMassN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized2ProngSxyN1[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngSxyN1[flavour][jetPt]->Integral());
          hsimjetNormalized2ProngSxyzN1[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngSxyzN1[flavour][jetPt]->Integral());
          hsimjetNormalized2ProngMassN1[flavour][jetPt]->Scale(1. / hsimjetNormalized2ProngMassN1[flavour][jetPt]->Integral());
        }
      }
    }
  } // end fillMCD && fill2Prong
  if (fillMCD && fill3Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        hsimjetNormalized3ProngLxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngLxy[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngLxy_%d_%d", flavour, jetPt)));
        hsimjetNormalized3ProngLxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngLxyz[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngLxyz_%d_%d", flavour, jetPt)));
        hsimjetNormalized3ProngSxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngSxy[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxy_%d_%d", flavour, jetPt)));
        hsimjetNormalized3ProngSxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngSxyz[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyz_%d_%d", flavour, jetPt)));
        hsimjetNormalized3ProngsigmaLxy[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngsigmaLxy[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngsigmaLxy_%d_%d", flavour, jetPt)));
        hsimjetNormalized3ProngsigmaLxyz[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngsigmaLxyz[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngsigmaLxyz_%d_%d", flavour, jetPt)));
        hsimjetNormalized3ProngLxy[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngLxy[flavour][jetPt]->Integral());
        hsimjetNormalized3ProngLxyz[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngLxyz[flavour][jetPt]->Integral());
        hsimjetNormalized3ProngSxy[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxy[flavour][jetPt]->Integral());
        //hsimjetNormalized3ProngSxy[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxy[flavour][jetPt]->Integral(0, HfJetTagging::REFHIST::SXY[1]));
        hsimjetNormalized3ProngSxyz[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyz[flavour][jetPt]->Integral());
        hsimjetNormalized3ProngsigmaLxy[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngsigmaLxy[flavour][jetPt]->Integral());
        hsimjetNormalized3ProngsigmaLxyz[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngsigmaLxyz[flavour][jetPt]->Integral());
        if (fillN1) {
          hsimjetNormalized3ProngSxyN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngSxyN1[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized3ProngSxyzN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngSxyzN1[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyzN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized3ProngMassN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngMassN1[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngMassN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized3ProngSxyN1[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyN1[flavour][jetPt]->Integral());
          hsimjetNormalized3ProngSxyzN1[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyzN1[flavour][jetPt]->Integral());
          hsimjetNormalized3ProngMassN1[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngMassN1[flavour][jetPt]->Integral());

          hsimtaggedjetNormalized3ProngSxyN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimtaggedjet3ProngSxyN1[flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngSxyN1_%d_%d", flavour, jetPt)));
          hsimtaggedjetNormalized3ProngSxyzN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimtaggedjet3ProngSxyzN1[flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngSxyzN1_%d_%d", flavour, jetPt)));
          hsimtaggedjetNormalized3ProngMassN1[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimtaggedjet3ProngMassN1[flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngMassN1_%d_%d", flavour, jetPt)));
          hsimtaggedjetNormalized3ProngSxyN1[flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngSxyN1[flavour][jetPt]->Integral());
          hsimtaggedjetNormalized3ProngSxyzN1[flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngSxyzN1[flavour][jetPt]->Integral());
          hsimtaggedjetNormalized3ProngMassN1[flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngMassN1[flavour][jetPt]->Integral());
        }
      }
    }
  }
  if (fillRun2Def && fill3Prong) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillN1) {
          hsimjetNormalized3ProngSxyN1Run2Def[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngSxyN1Run2Def[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized3ProngSxyzN1Run2Def[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngSxyzN1Run2Def[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyzN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized3ProngMassN1Run2Def[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimjet3ProngMassN1Run2Def[flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngMassN1_%d_%d", flavour, jetPt)));
          hsimjetNormalized3ProngSxyN1Run2Def[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyN1Run2Def[flavour][jetPt]->Integral());
          hsimjetNormalized3ProngSxyzN1Run2Def[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyzN1Run2Def[flavour][jetPt]->Integral());
          hsimjetNormalized3ProngMassN1Run2Def[flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngMassN1Run2Def[flavour][jetPt]->Integral());

          hsimtaggedjetNormalized3ProngSxyN1Run2Def[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimtaggedjet3ProngSxyN1Run2Def[flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngSxyN1_%d_%d", flavour, jetPt)));
          hsimtaggedjetNormalized3ProngSxyzN1Run2Def[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimtaggedjet3ProngSxyzN1Run2Def[flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngSxyzN1_%d_%d", flavour, jetPt)));
          hsimtaggedjetNormalized3ProngMassN1Run2Def[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimtaggedjet3ProngMassN1Run2Def[flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngMassN1_%d_%d", flavour, jetPt)));
          hsimtaggedjetNormalized3ProngSxyN1Run2Def[flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngSxyN1Run2Def[flavour][jetPt]->Integral());
          hsimtaggedjetNormalized3ProngSxyzN1Run2Def[flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngSxyzN1Run2Def[flavour][jetPt]->Integral());
          hsimtaggedjetNormalized3ProngMassN1Run2Def[flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngMassN1Run2Def[flavour][jetPt]->Integral());
        }
      }
    }
  }
}

void HfJetTaggingSVAnalysis::saveHistogramSVQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile, "RECREATE");
  if (!fout->IsOpen()) {
    std::cerr << "Error: Could not open the ROOT file for writing: " << rootFile << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

  if (doMC) {
 	  dir = fout->GetDirectory("data");
  	if (!dir) {
    	dir = fout->mkdir("data");
    	dir->cd();
  	}
  }
  if (doMC) {
  	dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
    }
    for (int flavour = 0; flavour < HfJetTagging::nFlavour + 1; ++flavour) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt + 1; ++jetPt) {
        if (hsimjet2ProngLxy[flavour][jetPt]) hsimjet2ProngLxy[flavour][jetPt]->Write();
        if (hsimjet2ProngLxyz[flavour][jetPt]) hsimjet2ProngLxyz[flavour][jetPt]->Write();
        if (hsimjet2ProngSxy[flavour][jetPt]) hsimjet2ProngSxy[flavour][jetPt]->Write();
        if (hsimjet2ProngSxyz[flavour][jetPt]) hsimjet2ProngSxyz[flavour][jetPt]->Write();
        if (hsimjet2ProngsigmaLxy[flavour][jetPt]) hsimjet2ProngsigmaLxy[flavour][jetPt]->Write();
        if (hsimjet2ProngsigmaLxyz[flavour][jetPt]) hsimjet2ProngsigmaLxyz[flavour][jetPt]->Write();
//        if (hsimjet3ProngLxy[flavour][jetPt]) hsimjet3ProngLxy[flavour][jetPt]->Write();
//        if (hsimjet3ProngLxyz[flavour][jetPt]) hsimjet3ProngLxyz[flavour][jetPt]->Write();
//        if (hsimjet3ProngSxy[flavour][jetPt]) hsimjet3ProngSxy[flavour][jetPt]->Write();
//        if (hsimjet3ProngSxyz[flavour][jetPt]) hsimjet3ProngSxyz[flavour][jetPt]->Write();
        if (hsimjetNormalized2ProngLxy[flavour][jetPt]) hsimjetNormalized2ProngLxy[flavour][jetPt]->Write();
        if (hsimjetNormalized2ProngLxyz[flavour][jetPt]) hsimjetNormalized2ProngLxyz[flavour][jetPt]->Write();
        if (hsimjetNormalized2ProngSxy[flavour][jetPt]) hsimjetNormalized2ProngSxy[flavour][jetPt]->Write();
        if (hsimjetNormalized2ProngSxyz[flavour][jetPt]) hsimjetNormalized2ProngSxyz[flavour][jetPt]->Write();
        if (hsimjetNormalized2ProngsigmaLxy[flavour][jetPt]) hsimjetNormalized2ProngsigmaLxy[flavour][jetPt]->Write();
        if (hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt]) hsimjetNormalized2ProngsigmaLxyz[flavour][jetPt]->Write();
//        if (hsimjetNormalized3ProngLxy[flavour][jetPt]) hsimjetNormalized3ProngLxy[flavour][jetPt]->Write();
//        if (hsimjetNormalized3ProngLxyz[flavour][jetPt]) hsimjetNormalized3ProngLxyz[flavour][jetPt]->Write();
//        if (hsimjetNormalized3ProngSxy[flavour][jetPt]) hsimjetNormalized3ProngSxy[flavour][jetPt]->Write();
//        if (hsimjetNormalized3ProngSxyz[flavour][jetPt]) hsimjetNormalized3ProngSxyz[flavour][jetPt]->Write();
      }
    }
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

// Draw function
// Data 2-prongs
void HfJetTaggingSVAnalysis::drawData2ProngLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngLxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngLxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngsigmaLxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngsigmaLxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngSxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngSxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData2ProngSxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngSxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

// Data 3-prongs
void HfJetTaggingSVAnalysis::drawData3ProngLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngLxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngLxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngsigmaLxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngsigmaLxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngSxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngSxy[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxy_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawData3ProngSxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngSxyz[binJetPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyz_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

// MC 2-prongs
void HfJetTaggingSVAnalysis::drawSim2ProngRawLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWLXY[0], HfJetTagging::REFHIST::RAWLXY[1], HfJetTagging::REFHIST::RAWLXY[2], HfJetTagging::REFHIST::RAWLXY[3], "L_{xy}", "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngRawLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWLXYZ[0], HfJetTagging::REFHIST::RAWLXYZ[1], HfJetTagging::REFHIST::RAWLXYZ[2], HfJetTagging::REFHIST::RAWLXYZ[3], "L_{xyz}", "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngRawLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], "S_{xy}", "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/raw2ProngSxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXYZ[0], HfJetTagging::REFHIST::RAWSXYZ[1], HfJetTagging::REFHIST::RAWSXYZ[2], HfJetTagging::REFHIST::RAWSXYZ[3], "S_{xy}", "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/raw2ProngSxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSIGMALXY[0], HfJetTagging::REFHIST::RAWSIGMALXY[1], HfJetTagging::REFHIST::RAWSIGMALXY[2], HfJetTagging::REFHIST::RAWSIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/raw2ProngsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSIGMALXYZ[0], HfJetTagging::REFHIST::RAWSIGMALXYZ[1], HfJetTagging::REFHIST::RAWSIGMALXYZ[2], HfJetTagging::REFHIST::RAWSIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/raw2ProngsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate (1^{st} #it{S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/raw2ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngRawSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjet2ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet2ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet2ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet2ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXYZ[0], HfJetTagging::REFHIST::RAWSXYZ[1], HfJetTagging::REFHIST::RAWSXYZ[2], HfJetTagging::REFHIST::RAWSXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, 0, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate (1^{st} #it{S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/raw2ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized2ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.68, 0.60, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.68, 0.60, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}



void HfJetTaggingSVAnalysis::drawSim2ProngSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate (1^{st} #it{S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized2ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate (1^{st} #it{S}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized2ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "2-prongs candidate (1^{st} #it{S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim2ProngEffiSxy(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      int entriesTagJet = hsimjet2ProngSxy[flavour][binJetPt]->Integral(cutSxy, -1);
      int entriesUnTagJet = hsimjet2ProngSxy[flavour][binJetPt]->Integral();
      //float effi = taggingutilities::getEfficiency(hsimjet2ProngSxy[flavour][binJetPt], hsimjet2ProngSxy[flavour][binJetPt]);
      float effi = static_cast<float>(entriesTagJet / entriesUnTagJet);
      if (effi < 0) continue;
      hsimSVEffi2ProngSxy[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi2ProngSxy[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngEffiSxy.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngEffiSxyz(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet2ProngSxyz[flavour][binJetPt], hsimjet2ProngSxyz[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimSVEffi2ProngSxyz[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi2ProngSxyz[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngEffiSxyz.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngEffiSxyN1(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimjet2ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
      if (effi < 0) continue;
      effi2ProngTopo[binJetPt] = effi;
      hsimSVEffi2ProngSxyN1[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi2ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngEffiSxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngEffiSxyzN1(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimjet2ProngSxyzN1[flavour][binJetPt], binJetPt, cutSxyz);
      if (effi < 0) continue;
      hsimSVEffi2ProngSxyzN1[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi2ProngSxyzN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngEffiSxyzN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngPuritySxy(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(hsimjet2ProngSxy[flavour][binJetPt], hsimjet2ProngSxy[0][binJetPt]);
      if (purity < 0) continue;
      hsimSVPurity2ProngSxy[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimSVPurity2ProngSxy[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::PURITY[0], HfJetTagging::REFHIST::PURITY[1], HfJetTagging::REFHIST::PURITY[2], HfJetTagging::REFHIST::PURITY[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngPuritySxy.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngPuritySxyN1(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurityDirect(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
      if (purity < 0) continue;
      purity2ProngTopo[binJetPt] = purity;
      hsimSVPurity2ProngSxyN1[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimSVPurity2ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngPuritySxyz(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getPurity(hsimjet2ProngSxyz[flavour][binJetPt], hsimjet2ProngSxyz[0][binJetPt]);
      if (effi < 0) continue;
      hsimSVPurity2ProngSxyz[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVPurity2ProngSxyz[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngPuritySxyz.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim2ProngPuritySxyzN1(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurityDirect(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxyz);
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

void HfJetTaggingSVAnalysis::drawSim2ProngChi2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized2ProngChi2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized2ProngChi2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized2ProngChi2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized2ProngChi2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::CHI2[0], HfJetTagging::REFHIST::CHI2[1], HfJetTagging::REFHIST::CHI2[2], HfJetTagging::REFHIST::CHI2[3], HfJetTagging::X_AXIS_CHI2, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.68, 0.60, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "2-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/2ProngChi2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


// MC 3-Prongs
void HfJetTaggingSVAnalysis::drawSim3ProngLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngLxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngLxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngLxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized3ProngLxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngLxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngLxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized3ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngSxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngSxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized3ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngRawSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histList;
  if (withInc) histList.push_back({hsimjet3ProngSxy[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimjet3ProngSxy[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimjet3ProngSxy[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimjet3ProngSxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_YIELD);
  canHan->drawCombined(histList.size(), histList, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawSxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngRawSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histList;
  if (withInc) histList.push_back({hsimjet3ProngSxyz[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimjet3ProngSxyz[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimjet3ProngSxyz[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimjet3ProngSxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXYZ[0], HfJetTagging::REFHIST::RAWSXYZ[1], HfJetTagging::REFHIST::RAWSXYZ[2], HfJetTagging::REFHIST::RAWSXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_YIELD);
  canHan->drawCombined(histList.size(), histList, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawSxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  if (withInc) normHist.push_back({hsimjetNormalized3ProngsigmaLxy[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxy[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxy[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxy[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.68, 0.60, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngsigmaLxyz[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxyz[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxyz[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxyz[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.68, 0.60, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st} S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st} #it{S}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st}#it{ S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngRawMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjet3ProngMassN1[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet3ProngMassN1[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet3ProngMassN1[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet3ProngMassN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, hsimjet3ProngMassN1[0][binJetPt]->GetEntries(), HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st} #it{S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingSVAnalysis::drawSim3ProngRawSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histList;
  if (withInc) histList.push_back({hsimjet3ProngSxyN1[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimjet3ProngSxyN1[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimjet3ProngSxyN1[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimjet3ProngSxyN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_YIELD);
  canHan->drawCombined(histList.size(), histList, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st} #it{S}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawSxyN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngRawSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histList;
  if (withInc) histList.push_back({hsimjet3ProngSxyzN1[0][binJetPt], HfJetTagging::INCJET});
  histList.push_back({hsimjet3ProngSxyzN1[1][binJetPt], HfJetTagging::CJET});
  histList.push_back({hsimjet3ProngSxyzN1[2][binJetPt], HfJetTagging::BJET});
  histList.push_back({hsimjet3ProngSxyzN1[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(histList.size(), histList, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st} #it{S}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawSxyzN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxy(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxy[flavour][binJetPt], hsimjet3ProngSxy[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxy[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi3ProngSxy[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxy.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyz(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyz[flavour][binJetPt], hsimjet3ProngSxyz[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyz[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi3ProngSxyz[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyz.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyN1(const float cutSxy) {
  std::cout << "Efficiency of SV for 3-prong" << std::endl;
	std::vector<HistogramData> histList;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimjet3ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
      //float effi = taggingutilities::getEfficiencyDirect(hsim3ProngjetPt[flavour], hsimjet3ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
      //float effi = hsimjet3ProngSxyN1[flavour][binJetPt]->Integral(1, hsimjet3ProngSxyN1[flavour][binJetPt]->FindBin(cutSxy)) / hsimjet3ProngSxyN1[0][binJetPt]->Integral();
      std::cout << "jet pt: " << HfJetTagging::binsJetPt[binJetPt] << " effi: " << effi << std::endl;
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyN1[flavour]->SetBinContent(binJetPt, effi);
    }
	  histList.push_back({hsimSVEffi3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  latexSimJetInfo(0.5, 0.9, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.5, 0.9-0.055*6, "3-prongs candidate (1^{st}#it{ S}_{XY} > 30)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyzN1(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimjet3ProngSxyzN1[flavour][binJetPt], binJetPt, cutSxyz);
      if (effi < 0) continue;
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyzN1[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi3ProngSxyzN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyzN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxy(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getPurity(hsimjet3ProngSxy[flavour][binJetPt], hsimjet3ProngSxy[0][binJetPt]);
      if (effi < 0) continue;
      hsimSVPurity3ProngSxy[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVPurity3ProngSxy[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxy.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyN1(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurityDirect(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
      if (purity < 0) continue;
      purity3ProngTopo[binJetPt] = purity;
      hsimSVPurity3ProngSxyN1[flavour]->SetBinContent(binJetPt, purity);
      //hsimSVPurity3ProngSxyN1[flavour]->SetBinError(binJetPt, errorPurity);
      //std::cout << "[Purity] 3-prong "<<  HfJetTagging::FLAVOURJET[flavour]<< " jet pT: " << HfJetTagging::binsJetPt[binJetPt] << " purity: " << purity << " error of purity: " << errorPurity << std::endl;
    }
	  normHist.push_back({hsimSVPurity3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyz(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(hsimjet3ProngSxyz[flavour][binJetPt], hsimjet3ProngSxyz[0][binJetPt]);
      if (purity < 0) continue;
      hsimSVPurity3ProngSxyz[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimSVPurity3ProngSxyz[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyz.pdf\")", nc++, dirSim.Data()));
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
    float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimjet3ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
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
    float purity = taggingutilities::getPurityDirect(binJetPt, flavour, hsimjet3ProngSxyN1, cutSxy);
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
      float effi = taggingutilities::getEfficiencyDirect(hsimjetPt[flavour], hsimjet3ProngSxyN1[flavour][binJetPt], binJetPt, cutSxy);
      float purity = taggingutilities::getPurityDirect(flavour, binJetPt, hsimjet3ProngSxyN1, cutSxy);
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

void HfJetTaggingSVAnalysis::drawSim3ProngChi2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngChi2[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngChi2[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngChi2[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngChi2[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::CHI2[0], HfJetTagging::REFHIST::CHI2[1], HfJetTagging::REFHIST::CHI2[2], HfJetTagging::REFHIST::CHI2[3], HfJetTagging::X_AXIS_CHI2, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.68, 0.60, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.4, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.4, 0.9-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngChi2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

//void HfJetTaggingSVAnalysis::drawSim3Prong

void HfJetTaggingSVAnalysis::drawSim3ProngSxyN1Run2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngSxyN1Run2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngSxyN1Run2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngSxyN1Run2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngSxyN1Run2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.12, 0.04);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22-0.02, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  //latexSimSet();
  //latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimJetInfo(0.5, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.5, 0.89-0.055*5, "3-prongs candidate (largest S#it{L}_{XY})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1Run2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngSxyzN1Run2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngSxyzN1Run2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngSxyzN1Run2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngSxyzN1Run2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngSxyzN1Run2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st} #it{S}_{XYZ})");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyzN1Run2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngMassN1Run2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalized3ProngMassN1Run2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalized3ProngMassN1Run2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalized3ProngMassN1Run2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalized3ProngMassN1Run2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimSet();
  //latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimJetInfo(0.5, 0.9, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st}#it{ S}_{XY} > 30)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngMassN1Run2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawSim3ProngRawMassN1Run2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjet3ProngMassN1Run2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjet3ProngMassN1Run2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjet3ProngMassN1Run2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjet3ProngMassN1Run2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], 1, hsimjet3ProngMassN1Run2Def[0][binJetPt]->GetEntries(), HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.22, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimSet();
  //latexSimJetInfo(0.5, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimJetInfo(0.5, 0.9, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.5, 0.9-0.045*7, "3-prongs candidate (1^{st}#it{ S}_{XY} > 30)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngRawMassN1Run2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyRun2Def(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyRun2Def[flavour][binJetPt], hsimjet3ProngSxyRun2Def[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyRun2Def[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi3ProngSxyRun2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyRun2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyzRun2Def(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyzRun2Def[flavour][binJetPt], hsimjet3ProngSxyzRun2Def[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyzRun2Def[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi3ProngSxyzRun2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyzRun2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyN1Run2Def(const float cutSxy) {
  std::cout << "Efficiency of SV for 3-prong (Run2 def)" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimSVEffi3ProngSxyN1Run2Def[0], HfJetTagging::FLAVOURJET[0]});
  std::cout << "ent: " << hsimjetPtRun2Def[0]->GetEntries() << std::endl;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      //float effi = taggingutilities::getEfficiencyDirect(hsimjetPtRun2Def[flavour], hsimjet3ProngSxyN1Run2Def[flavour][binJetPt], binJetPt, cutSxy);
      float effi = taggingutilities::getEfficiencyDirect(hsim3ProngjetPtRun2Def[flavour], hsimjet3ProngSxyN1Run2Def[flavour][binJetPt], binJetPt, cutSxy);
      if (effi < 0) continue;
      effi3ProngTopo[binJetPt] = effi;
      hsimSVEffi3ProngSxyN1Run2Def[flavour]->SetBinContent(binJetPt, effi);
    }
	  histList.push_back({hsimSVEffi3ProngSxyN1Run2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "Tagging efficiency");
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  latexSimJetInfo(0.2, 0.9, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.2, 0.9-0.055*6, "3-prongs candidate (1^{st}#it{ S}_{XY} > 30)");
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyN1Run2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngEffiSxyzN1Run2Def(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiencyDirect(hsimjetPtRun2Def[flavour], hsimjet3ProngSxyzN1Run2Def[flavour][binJetPt], binJetPt, cutSxyz);
      if (effi < 0) continue;
      hsimSVEffi3ProngSxyzN1Run2Def[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVEffi3ProngSxyzN1Run2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngEffiSxyzN1Run2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyRun2Def(const float cutSxy) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getPurity(hsimjet3ProngSxyRun2Def[flavour][binJetPt], hsimjet3ProngSxyRun2Def[0][binJetPt]);
      if (effi < 0) continue;
      hsimSVPurity3ProngSxy[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVPurity3ProngSxyRun2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyRun2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyN1Run2Def(const float cutSxy) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hsimSVPurity3ProngSxyN1Run2Def[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurityDirect(flavour, binJetPt, hsimjet3ProngSxyN1Run2Def, cutSxy);
      if (purity < 0) continue;
      purity3ProngTopo[binJetPt] = purity;
      hsimSVPurity3ProngSxyN1Run2Def[flavour]->SetBinContent(binJetPt, purity);
      //hsimSVPurity3ProngSxyN1[flavour]->SetBinError(binJetPt, errorPurity);
      //std::cout << "[Purity] 3-prong "<<  HfJetTagging::FLAVOURJET[flavour]<< " jet pT: " << HfJetTagging::binsJetPt[binJetPt] << " purity: " << purity << " error of purity: " << errorPurity << std::endl;
    }
	  normHist.push_back({hsimSVPurity3ProngSxyN1Run2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  latexSimJetInfo(0.2, 0.9, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.2, 0.9-0.045*7, "tagged jet 3-prongs candidate (1^{st}#it{ S}_{XY} > 30)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyN1Run2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyzRun2Def(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(hsimjet3ProngSxyzRun2Def[flavour][binJetPt], hsimjet3ProngSxyz[0][binJetPt]);
      if (purity < 0) continue;
      hsimSVPurity3ProngSxyzRun2Def[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimSVPurity3ProngSxyzRun2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyzRun2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSim3ProngPuritySxyzN1Run2Def(const float cutSxyz) {
	std::vector<HistogramData> normHist;
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getPurity(hsimjet3ProngSxyzN1Run2Def[flavour][binJetPt], hsimjet3ProngSxyzN1Run2Def[0][binJetPt]);
      if (effi < 0) continue;
      hsimSVPurity3ProngSxyzN1Run2Def[flavour]->SetBinContent(binJetPt, effi);
    }
	  normHist.push_back({hsimSVPurity3ProngSxyzN1Run2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxyz));
  latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XYZ})=%0.1f", cutSxyz));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngPuritySxyzN1Run2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngEffiSxyN1(const float cutSxy) {
  std::cout << "Efficiency of SV for 3-prong" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimtaggedjetSVEffi3ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimjet3ProngMassN1[flavour][binJetPt]);
      float errorEffi = taggingutilities::getErrorEfficiency(hsimtaggedjet3ProngMassN1[flavour][binJetPt], hsimjet3ProngMassN1[flavour][binJetPt]);
      if (effi < 0) continue;
      hsimtaggedjetSVEffi3ProngSxyN1[flavour]->SetBinContent(binJetPt, effi);
      hsimtaggedjetSVEffi3ProngSxyN1[flavour]->SetBinError(binJetPt, errorEffi);
    }
	  histList.push_back({hsimtaggedjetSVEffi3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.11, 0.04, 0.05, 0.13);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI, 1.10, 1.15);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.065);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  latexSimJetInfoForEffi(0.17, 0.89, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.17, 0.89-0.055*4, "3-prongs candidate (largest S#it{L}_{XY} > 30)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngEffiSxyN1Run2Def(const float cutSxy) {
  std::cout << "Efficiency of SV for 3-prong" << std::endl;
	std::vector<HistogramData> histList;
	histList.push_back({hsimtaggedjetSVEffi3ProngSxyN1Run2Def[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float effi = taggingutilities::getEfficiency(hsimjet3ProngSxyN1[flavour][binJetPt], hsimtaggedjet3ProngSxyN1[flavour][binJetPt]);

      if (effi < 0) continue;
      hsimtaggedjetSVEffi3ProngSxyN1Run2Def[flavour]->SetBinContent(binJetPt, effi);
    }
	  histList.push_back({hsimtaggedjetSVEffi3ProngSxyN1Run2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_EFFI);
  canHan->drawCombined(histList.size(), histList, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  latexSimJetInfo(0.2, 0.9, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.2, 0.9-0.045*7, "3-prongs candidate (1^{st}#it{ S}_{XY} > 40)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngEffiSxyN1Run2Def.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngPuritySxyN1(const float cutSxy) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hsimtaggedjetSVPurity3ProngSxyN1[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(hsimtaggedjet3ProngSxyN1[flavour][binJetPt], hsimjet3ProngSxyN1[0][binJetPt]);
      if (purity < 0) continue;
      //purity3ProngTopo[binJetPt] = purity;
      hsimtaggedjetSVPurity3ProngSxyN1[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimtaggedjetSVPurity3ProngSxyN1[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  latexSimJetInfo(0.2, 0.9, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.2, 0.9-0.045*7, "tagged jet 3-prongs candidate (1^{st}#it{ S}_{XY} > 40)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngPuritySxyN1.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingSVAnalysis::drawSimtaggedjet3ProngPuritySxyN1Run2Def(const float cutSxy) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hsimtaggedjetSVPurity3ProngSxyN1Run2Def[0], HfJetTagging::FLAVOURJET[0]});
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue; // 0 is inclusive jet pt
      float purity = taggingutilities::getPurity(hsimtaggedjet3ProngSxyN1Run2Def[flavour][binJetPt], hsimjet3ProngSxyN1Run2Def[0][binJetPt]);
      if (purity < 0) continue;
      //purity3ProngTopo[binJetPt] = purity;
      hsimtaggedjetSVPurity3ProngSxyN1Run2Def[flavour]->SetBinContent(binJetPt, purity);
    }
	  normHist.push_back({hsimtaggedjetSVPurity3ProngSxyN1Run2Def[flavour], HfJetTagging::FLAVOURJET[flavour]});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PURITY);
  canHan->drawCombined(normHist.size(), normHist, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (sIPs)=%0.1f", cutSxy));
  //latex.DrawLatex(0.2, 0.9-0.04, Form("tagger point (#it{S}_{XY})=%0.1f", cutSxy));
  latexSimJetInfo(0.2, 0.9, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
  latex.DrawLatex(0.2, 0.9-0.045*7, "tagged jet 3-prongs candidate (1^{st}#it{ S}_{XY} > 40)");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/taggedjet/3ProngPuritySxyN1Run2Def.pdf\")", nc++, dirSim.Data()));
}






//void HfJetTaggingSVAnalysis

// DataVsSim 2-Prongs
void HfJetTaggingSVAnalysis::drawDataVsSim2ProngLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized2ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized2ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized2ProngLxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized2ProngLxy[0][binJetPt]);
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
  normHist.push_back({hdataTagjetNormalized2ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized2ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized2ProngLxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized2ProngLxyz[0][binJetPt]);
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
  normHist.push_back({hdataTagjetNormalized2ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized2ProngsigmaLxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized2ProngsigmaLxy[0][binJetPt]);
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
  normHist.push_back({hdataTagjetNormalized2ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized2ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized2ProngsigmaLxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized2ProngsigmaLxyz[0][binJetPt]);
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
  normHist.push_back({hdataTagjetNormalized2ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized2ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized2ProngSxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized2ProngSxy[0][binJetPt]);
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
  normHist.push_back({hdataTagjetNormalized2ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized2ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized2ProngSxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized2ProngSxyz[0][binJetPt]);
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
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized3ProngLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngLxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized3ProngLxy[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.68, 0.62, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.040);
  latexSimJetInfo(0.48, 0.94, binJetPt, TRIGGERNAME.Data());
  latex.DrawLatex(0.48, 0.94-0.045*7, "3-prongs candidate");
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized3ProngLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngLxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized3ProngLxyz[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::X_AXIS_LXYZ);
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.60, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngsigmaLxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngsigmaLxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngsigmaLxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized3ProngsigmaLxy[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.60, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngsigmaLxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngsigmaLxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized3ProngsigmaLxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngsigmaLxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized3ProngsigmaLxyz[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.60, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngsigmaLxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxy(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngSxy[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized3ProngSxy[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngSxy[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized3ProngSxy[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.6, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxy_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxyz(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdataTagjetNormalized3ProngSxyz[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalized3ProngSxyz[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngSxyz[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalized3ProngSxyz[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, "Probability distribution");
  canHan->drawCombined(normHist.size(), normHist, true, true, 0.6, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyz_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

//void HfJetTaggingSVAnalysis::drawTemplateFitMC() {
//  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.1, 5);
//
//  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
//    if (binJetPt==1) continue;
//    TH1F* hsimincjet3ProngMass = (TH1F*) hsimjet3ProngMass[0][binJetPt]->Clone();
//    TH1F* hsimcjet3ProngMass = (TH1F*) hsimjet3ProngMass[1][binJetPt]->Clone();
//    TH1F* hsimbjet3ProngMass = (TH1F*) hsimjet3ProngMass[2][binJetPt]->Clone();
//    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimjet3ProngMass[3][binJetPt]->Clone();
//    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
//    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
//    RooDataHist mcbjetMass("mcbjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
//    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 
//
//    // Create a histogram PDF using the data histogram
//    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
//    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
//    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);
//
//    int incjetMassYield = mccjetMass.sumEntries()+mcbjetMass.sumEntries()+mclfjetMass.sumEntries();
//    RooRealVar cjetMassYield("cjetMassYield", "cjet Yield", hsimjet3ProngMass[1][0]->Integral(1, hsimcjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
//    RooRealVar bjetMassYield("bjetMassYield", "bjet Yield", hsimjet3ProngMass[2][0]->Integral(1, hsimbjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
//    RooRealVar lfjetMassYield("lfjetMassYield", "lfjet Yield", hsimjet3ProngMass[3][0]->Integral(1, hsimlfjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
//
//    RooAddPdf modelFitMC("modelFitMC", "Total PDF", RooArgList(histPdfcjetMass, histPdfbjetMass, histPdflfjetMass), RooArgList(cjetMassYield, bjetMassYield, lfjetMassYield));
//    std::cout << "START MC FITTING" << std::endl;
//    std::cout << "cjet yield before: " << cjetMassYield.getVal() << std::endl;
//    std::cout << "bjet yield before: " << bjetMassYield.getVal() << std::endl;
//    std::cout << "lfjet yield before: " << lfjetMassYield.getVal() << std::endl;
//    RooFitResult* fitMC = modelFitMC.fitTo(mcincjetMass, RooFit::Minos(kTRUE), RooFit::Save(true));
//    std::cout << "END MC FITTING" << std::endl;
//
//    std::cout<<"fit MC: " << std::endl;
//    fitMC->Print();
//
//    RooPlot* frameMC = mass.frame();
//    mcincjetMass.plotOn(frameMC, RooFit::DrawOption(""), RooFit::Name("InclusiveJet"));
//    modelFitMC.plotOn(frameMC, RooFit::LineStyle(kDashed), RooFit::LineColor(kGray), RooFit::DrawOption(""), RooFit::Name("TotalFit"));
//    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfcjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kGreen+3), RooFit::Name("CharmJetComponent"));
//    modelFitMC.plotOn(frameMC, RooFit::Components("histPdfbjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kRed+1), RooFit::Name("BottomJetComponent"));
//    modelFitMC.plotOn(frameMC, RooFit::Components("histPdflfjetMass"), RooFit::DrawOption(""), RooFit::LineColor(kBlue+1), RooFit::Name("LightFlavorJetComponent"));
//
//    frameMC->GetXaxis()->SetTitle(HfJetTagging::X_AXIS_MASS);  // X-axis title
//    frameMC->GetXaxis()->SetLabelSize(0.03);                   // X-axis label size
//    frameMC->GetXaxis()->SetTitleOffset(0.9);                  // X-axis title offset
//    frameMC->GetXaxis()->SetTitleSize(0.05);                   // X-axis title size
//
//    frameMC->GetYaxis()->SetTitle("Count");    // Y-axis title
//    frameMC->GetYaxis()->SetLabelSize(0.03);                   // Y-axis label size
//    frameMC->GetYaxis()->SetTitleOffset(1.25);                 // Y-axis title offset
//    frameMC->GetYaxis()->SetTitleSize(0.05);                   // Y-axis title size
//    frameMC->GetYaxis()->SetRangeUser(1, incjetMassYield);
//    frameMC->GetXaxis()->SetRangeUser(0.25, 5);
//
//    TLegend* legend = new TLegend(0.2, 0.2, 0.4, 0.4);  // (x1, y1, x2, y2) for legend position
//    legend->SetBorderSize(0);  // No border
//    legend->SetFillColor(0);   // Transparent background
//    legend->SetTextSize(0.03); // Text size
//
//    legend->AddEntry(frameMC->findObject("InclusiveJet"), "MC", "lep");
//    legend->AddEntry(frameMC->findObject("TotalFit"), "Fit", "l");
//    legend->AddEntry(frameMC->findObject("CharmJetComponent"), HfJetTagging::CJET, "l");
//    legend->AddEntry(frameMC->findObject("BottomJetComponent"), HfJetTagging::BJET, "l");
//    legend->AddEntry(frameMC->findObject("LightFlavorJetComponent"), HfJetTagging::LFJET, "l");
//
//
//
//    canHan = new CanvasHandler();
//    canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
//    gPad->SetLogy();
//    //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
//    //gROOT->ProcessLine(Form("cc%d->cd()", nc));
//    frameMC->Draw();
//    legend->Draw();
//    latexSimJetInfo(0.62, 0.9, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
//    latex.DrawLatex(0.62, 0.9-0.045*7, "3-prongs candidate (1^{st}#it{ S}_{XY})");
//    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template3ProngMass_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//  }
//}


void HfJetTaggingSVAnalysis::drawTemplateFitMCN1() {
  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.1, 5);

  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;
    TH1F* hsimincjet3ProngMass = (TH1F*) hsimjet3ProngMassN1Run2Def[0][binJetPt]->Clone();
    TH1F* hsimcjet3ProngMass = (TH1F*) hsimjet3ProngMassN1Run2Def[1][binJetPt]->Clone();
    TH1F* hsimbjet3ProngMass = (TH1F*) hsimjet3ProngMassN1Run2Def[2][binJetPt]->Clone();
    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimjet3ProngMassN1Run2Def[3][binJetPt]->Clone();
    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
    RooDataHist mcbjetMass("mcbjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);

    int incjetMassYield = mccjetMass.sumEntries()+mcbjetMass.sumEntries()+mclfjetMass.sumEntries();
    RooRealVar cjetMassYield("cjetMassYield", "cjet Yield", hsimjet3ProngMassN1Run2Def[1][0]->Integral(1, hsimcjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar bjetMassYield("bjetMassYield", "bjet Yield", hsimjet3ProngMassN1Run2Def[2][0]->Integral(1, hsimbjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar lfjetMassYield("lfjetMassYield", "lfjet Yield", hsimjet3ProngMassN1Run2Def[3][0]->Integral(1, hsimlfjet3ProngMass->GetNbinsX()), 0, incjetMassYield);

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
    frameMC->GetYaxis()->SetRangeUser(1.01, incjetMassYield);
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
    latexSimJetInfoForSV(0.49, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
    latex.DrawLatex(0.49, 0.89-0.055*5, "untagged jet (largest S#it{L}_{XY})");
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/template3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSVAnalysis::drawTemplateFitMCtaggedjetN1() {
  RooRealVar mass("mass", HfJetTagging::X_AXIS_MASS, 0.1, 5);

  for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    if (binJetPt==1) continue;
    TH1F* hsimincjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1Run2Def[0][binJetPt]->Clone();
    TH1F* hsimcjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1Run2Def[1][binJetPt]->Clone();
    TH1F* hsimbjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1Run2Def[2][binJetPt]->Clone();
    TH1F* hsimlfjet3ProngMass = (TH1F*) hsimtaggedjet3ProngMassN1Run2Def[3][binJetPt]->Clone();
    RooDataHist mcincjetMass("mcincjetMass", "inclusive jet (MC)", mass, RooFit::Import(*hsimincjet3ProngMass)); 
    RooDataHist mccjetMass("mccjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimcjet3ProngMass)); 
    RooDataHist mcbjetMass("mcbjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimbjet3ProngMass)); 
    RooDataHist mclfjetMass("mclfjetMass", "charm jet (MC)", mass, RooFit::Import(*hsimlfjet3ProngMass)); 

    // Create a histogram PDF using the data histogram
    RooHistPdf histPdfcjetMass("histPdfcjetMass", "Histogram PDF", mass, mccjetMass);
    RooHistPdf histPdfbjetMass("histPdfbjetMass", "Histogram PDF", mass, mcbjetMass);
    RooHistPdf histPdflfjetMass("histPdflfjetMass", "Histogram PDF", mass, mclfjetMass);

    int incjetMassYield = mccjetMass.sumEntries()+mcbjetMass.sumEntries()+mclfjetMass.sumEntries();
    RooRealVar cjetMassYield("cjetMassYield", "cjet Yield", hsimtaggedjet3ProngMassN1Run2Def[1][0]->Integral(1, hsimcjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar bjetMassYield("bjetMassYield", "bjet Yield", hsimtaggedjet3ProngMassN1Run2Def[2][0]->Integral(1, hsimbjet3ProngMass->GetNbinsX()), 0, incjetMassYield);
    RooRealVar lfjetMassYield("lfjetMassYield", "lfjet Yield", hsimtaggedjet3ProngMassN1Run2Def[3][0]->Integral(1, hsimlfjet3ProngMass->GetNbinsX()), 0, incjetMassYield);

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
    frameMC->GetYaxis()->SetRangeUser(1.01, incjetMassYield);
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
    latexSimJetInfoForSV(0.47, 0.89, binJetPt, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Performance");
    latex.DrawLatex(0.47, 0.89-0.055*5, "tagged jet (largest S#it{L}_{XY} > 30)");
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/templatetaggedjet3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

//void HfJetTaggingSVAnalysis::drawDataVsSim3ProngSxyN1(bool doLog = true, int binJetPt=0) {
//  std::vector<HistogramData> normHist;
//  normHist.push_back({hdataTagjetNormalized3ProngSxyN1[binJetPt], Form("Data (%s)", DATASET.Data())});
//  normHist.push_back({hsimjetNormalized3ProngSxyN1[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
//  
//  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalized3ProngSxyN1[binJetPt]->Clone("hRatio"));
//  hRatio->Divide(hsimjetNormalized3ProngSxyN1[0][binJetPt]);
//  canHan = new CanvasHandler();
//  canHan->createRatioCanvas(nc);
//  gROOT->ProcessLine(Form("padu%d->cd()", nc));
//  if (doLog) gPad->SetLogy();
//  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, "Probability distribution");
//  canHan->drawCombined(normHist.size(), normHist, true, true, 0.6, 0.65, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  gROOT->ProcessLine(Form("padd%d->cd()", nc));
//  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_RATIO);
//  hRatio->Draw("same");
//
//  gROOT->ProcessLine(Form("cc%d->Print(\"%s/3ProngSxyN1_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//}





#endif // HFJETTAGGINGMATCHANALYSIS_H 

