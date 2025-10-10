#ifndef HFJETTAGGINGANALYSIS_H
#define HFJETTAGGINGANALYSIS_H

#if !(defined(__CINT__) || defined(__CLING__)) || defined(__ACLIC__)
#include <fstream>
#include "TH1F.h"
#include <TString.h>
//#include "JetAnalysis.h"

#endif

#include "DataPoint.h"
#include "CanvasHandler.h"
#include "HfJetTaggingUtilities.h"

/// Now it works itself withtout JetAnalysis.h(GeneralQA) seperatively
/// If histograms were saved by same root file,
/// In future, it should be merged by class HfJetTaggingAnalysis : public JetAnalysis
/// So the functions have to be made by different name of funciton in JetAnalysis.h

class HfJetTaggingAnalysis {
  public:
    HfJetTaggingAnalysis() {
      initConfig();
    }
    ~HfJetTaggingAnalysis();

    // function
		/// Basic
    void initConfig();

    // common hist like jet pt, eta and phi
    /// data
    int loadDataQA(TString rootData);
    void rebinHistData();
    void initCommonHistData(TString rootData);
    
    /// mc
    int loadSimQA(TString rootSim);
    void initHistogramMC();
    void projectionHistMC();
    void rebinHistMC();
    void initCommonHistMC(TString rootSim);

    // ip hist 
    /// data
    int loadDataIP(TString rootData);
    void initHistIPData();
    void projectionHistIPData();
    void rebinHistIPData();
    void initIPData(TString rootData);

    /// mc
    int loadSimIP(TString rootSim);
    void initHistIPMC();
    void projectionHistIPMC();
    void rebinHistIPMC();
    void initIPMC(TString rootSim);

    // model
    int loadPOWHEGFile(TString rootFile);
    void rebinHistPOWHEG();
    void initModel(TString rootFile);
    
    // input run2 x secion of b-jet
    void inputResultRun25TeV();
    void inputResultRun2();

    // external correction
    int loadExternalUnfold(TString rootFile);
    void initExternalUnfold(TString rootFile);

    void saveHistogramIPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);
    void saveHistogramUnfold(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    /// Set
    void setFillData(bool fillData);
    void setFillMCD(bool fillMCD);
    void setFillMCP(bool fillMCP);
    void setFillMatched(bool fillMatched);
    void setDebug(bool debug);
    void setDoUnfolding(bool doUnfolding);
    void setFillTest(bool fillTest);
    void setFillIPxy(bool fillIPxy);
    void setFillIPz(bool fillIPz);
    void setFillIPxyz(bool fillIPxyz);
    void setLoadResMat(bool loadResMat);
    void setLoadPOWHEG(bool loadPOWHEG);
    void setFitForJP(bool fitForJP);

		/// Draw
    std::vector<HistogramData> histList;
		void drawDataJetPt(bool doLog);
		void drawDataJetEta(bool doLog);
		void drawDataJetPhi(bool doLog);
		void drawDataTrackPt(bool doLog, int binJetPt);
		void drawDataTrackEta(bool doLog, int binJetPt);
		void drawDataTrackPhi(bool doLog, int binJetPt);
		void drawDataImpXY(bool doLog, int binJetPt);
		void drawDataSignImpXY(bool doLog, int binJetPt);
		void drawDataImpXYSig(bool doLog, int binJetPt);
		void drawDataSignImpXYSig(bool doLog, int binJetPt, int binTrackPt);
		void drawDataImpZ(bool doLog, int binJetPt);
		void drawDataSignImpZ(bool doLog, int binJetPt);
		void drawDataImpZSig(bool doLog, int binJetPt);
		void drawDataSignImpZSig(bool doLog, int binJetPt, int binTrackPt);
		void drawDataImpXYZ(bool doLog, int binJetPt);
		void drawDataSignImpXYZ(bool doLog, int binJetPt);
		void drawDataImpXYZSig(bool doLog, int binJetPt);
		void drawDataSignImpXYZSig(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXY4x1(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXY2x2(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpZ4x1(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpZ2x2(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXYZ4x1(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXYZ2x2(bool doLog, int binJetPt, int binTrackPt);

    void drawSimJetPt(bool withInc, bool doLog);
    void drawSimJetEta(bool withInc, bool doLog);
    void drawSimJetPhi(bool withInc, bool doLog);
    void drawSimJetTrackPt(bool withInc, bool doLog, int binJetPt);
    void drawSimFlavourJetTrackPt(bool doLog, int flavour, int startJetPt);
    void drawSimJetTrackEta(bool withInc, bool doLog, int binJetPt);
    void drawSimFlavourJetTrackEta(bool doLog, int flavour, int startJetPt);
    void drawSimJetTrackPhi(bool withInc, bool doLog, int binJetPt);
    void drawSimFlavourJetTrackPhi(bool doLog, int flavour, int startJetPt);
    void drawSimJetImpXY(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXY(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXY2x2(bool withInc, bool doLog, int binJetPt);

    void drawSimJetImpZ(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZ(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpZ2x2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYZ(bool withInc, bool doLog, int binJetPT);
    void drawSimJetSignImpXYZ(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYZ2x2(bool withInc, bool doLog, int binJetPt);

    void drawSimTrackImpXY(bool withInc, bool doLog, int binTrackPt);
    void drawSimFlavourTrackImpXY(bool doLog, int flavour, int startTrackPt);
    void drawSimTrackSignImpXY(bool withInc, bool doLog, int binTrackPt);
    void drawSimFlavourTrackSignImpXY(bool doLog, int flavour, int startTrackPt);
    void drawSimTrackImpXYSig(bool withInc, bool doLog, int binTrackPt);
    void drawSimFlavourTrackImpXYSig(bool doLog, int flavour, int startTrackPt);
    void drawSimTrackSignImpXYSig(bool withInc, bool doLog, int binTrackPt);
    void drawSimFlavourTrackSignImpXYSig(bool doLog, int flavour, int startTrackPt);

    void drawSimpartJetPt(bool withInc, bool doLog);
    void drawSimpartJetEta(bool withInc, bool doLog);
    void drawSimpartJetPhi(bool withInc, bool doLog);
    void drawSimpartFlavourMatchingEffi();
    void drawSimFlavourMatchingEffi();
    void drawSimMatchedFlavourMatchingEffi();
    void drawSimRawJetPtMatched(bool withInc, bool doLog);
    void drawSimResMat(int flavour);

    void drawSimFlavourJetpartJetPt(bool doLog, int flavour);
    void drawDataVsSimJetPt(bool doLog);
    void drawDataVsSimJetEta(bool doLog);
    void drawDataVsSimJetPhi(bool doLog);
    void drawDataVsSimJetImpXY(bool doLog, int binJetPt);
    void drawDataVsSimJetSignImpXY(bool doLog, int binJetPt);
    void drawDataVsSimJetImpXYSig(bool doLog, int binJetPt);
    void drawDataVsSimJetSignImpXYSig(bool doLog, int binJetPt, int binTrackPt);

    void fitDataJetSignImpXYSignificance(bool doLog);
    void fitIncJetSignImpXYSignificance(bool doLog);
    void fitCharmJetSignImpXYSignificance(bool doLog);
    void fitBeautyJetSignImpXYSignificance(bool doLog);
    void fitLfJetSignImpXYSignificance(bool doLog);
    void fitTaggedJetSignImpXYSignificance(bool withInc, bool doLog);
    void drawTrackEfficiency(bool withInc, bool doLog);
    void drawJetEfficiency(bool doLog, int flavour);
    void drawJetPurity(bool doLog, int flavour);
    void unfoldingJet(bool doLog, int flavour, int n_iter, int k_reg, bool fromExternal);
    void unfoldingJetFromExternal(bool doLog, int flavour, int n_iter, int k_reg);
    void unfoldingJetWithData(bool doLog, int flavour, int n_iter, int k_reg, bool fromExternal);

    // histogram
		/// Data
		TH1F* hdatajetPt;
		TH1F* hdatajetEta;
		TH1F* hdatajetPhi;
		TH1F* hdatajetTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetTrackPhi[HfJetTagging::nBinsJetPt+1];

    //// rebin
		TH1F* hdatajetPtRebin;

		/// MC
    TH1F* hsimjetPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEta[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH2F* h2simjetPtpartjetPt[HfJetTagging::nFlavour+1];
    TH2F* h2simjetPtpartjetPtMatched[HfJetTagging::nFlavour+1];
    TH2F* h2simpartjetPtjetPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPt[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetEta[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartFlavourMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartCharmJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartBeautyJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartLfJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartFlavourMatchedFlavour[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimFlavourMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimCharmJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimBeautyJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimLfJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimMatchedFlavourMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimMatchedCharmJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimMatchedBeautyJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimMatchedLfJetMatchingEffi[HfJetTagging::nFlavour+1];
    TH1F* hsimFlavourMatchingFlavourRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimMatchedFlavourMatchingFlavourRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPtMatched[HfJetTagging::nFlavour+1];

    TH1F* hsimtrackImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];

    TH2F* h2externalsimjetPtpartjetPtMatched[HfJetTagging::nFlavour+1];
    TH2F* h2externalsimpartjetPtjetPtMatched[HfJetTagging::nFlavour+1];
    TH2F* h2externalsimjetPtpartjetPtMatchedNorm[HfJetTagging::nFlavour+1];
    TH2F* h2externalsimpartjetPtjetPtMatchedNorm[HfJetTagging::nFlavour+1];
    TH2F* h2externalsimjetPtpartjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH2F* h2externalsimpartjetPtjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hexternalsimjetPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hexternalsimjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hexternalsimpartjetPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hexternalsimpartjetPtMatchedRebin[HfJetTagging::nFlavour+1];

    //// rebin
    TH1F* hsimjetPtRebin[HfJetTagging::nFlavour+1];
    TH2F* h2simjetPtpartjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH2F* h2simpartjetPtjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormPtMatchedRebin[HfJetTagging::nFlavour+1];

    /// for unfolding
    std::tuple<float, float> effi2ProngDirect[HfJetTagging::nBinsJetPt+1];
    std::tuple<float, float> purity2ProngDirect[HfJetTagging::nBinsJetPt+1];
    std::tuple<float, float> effi2ProngTagged[HfJetTagging::nBinsJetPt+1];
    std::tuple<float, float> purity2ProngTagged[HfJetTagging::nBinsJetPt+1];

    float effi3ProngDirect[HfJetTagging::nBinsJetPt+1] = {-1.};
    float purity3ProngDirect[HfJetTagging::nBinsJetPt+1] = {-1.};
    float effi3ProngTagged[HfJetTagging::nBinsJetPt+1] = {-1.};
    float purity3ProngTagged[HfJetTagging::nBinsJetPt+1] = {-1.};
    float effi3ProngTaggedData[HfJetTagging::nBinsJetPt+1] = {-1.};
    float purity3ProngTaggedData[HfJetTagging::nBinsJetPt+1] = {-1.};

  protected:
    // draw option. It should be moved to JetAnalysis.h when itself will be merged
    long long ndataEvents = -1;
    double ndataJets[HfJetTagging::nBinsJetPt+1] = {-1.};
    //float dataTaggingEffiForIP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};
    //float dataTaggingEffiForSV[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};
    //float dataTaggingPurityForIP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};
    //float dataTaggingPurityForSV[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};

    long long nsimEvents = -1;
    double nsimJets[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1.};
    //float simTaggingEffiForIP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};
    //float simTaggingEffiForSV[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};
    //float simTaggingPurityForIP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};
    //float simTaggingPurityForSV[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1] = {-1};

    int npwhgEvents = -1;

    int nc = 0;
    float sigmaVis_mb = 59.4; // in mb (millibarn)
    float sigmaVis_cm2 = sigmaVis_mb * 1e-27; // Convert mb to cm^2
    float deltaEta = 1.0; // |eta| < 0.5
    float xs = 0;
    float nTrials = 0 ;
    CanvasHandler* canHan;
    TString dirFig = "fig";
    bool fillData = false;
    bool fillMCD = false;
    bool fillMCP = false;
    bool doUnfolding = false;
    bool fillTest = false;
    bool fillIPxy = false;
    bool fillIPz = false;
    bool fillIPxyz = false;
    bool fitForJP = false;
    bool fillMatched = false;
    bool fillSysSVCont = false;
    bool loadResMat = false;
    bool loadPOWHEG = false;
    bool debug = false;
    bool fillResultRun25TeV = false;
    bool fillResultRun2 = false;

    // histogram
		/// data
    TH1F* hdataEventSel;
    TH1F* hdataLumi;
    TH3F* h3dataTagjetPtTrackPtTrackEta;
    TH3F* h3dataTagjetPtTrackPtTrackPhi;
    TH2F* h2dataTagjetPtImpXY;
    TH2F* h2dataTagjetPtSignImpXY;
    TH2F* h2dataTagjetPtImpXYSig;
    TH3F* h3dataTagjetPtTrackPtSignImpXYSig;
    TH2F* h2dataTagjetPtImpZ;
    TH2F* h2dataTagjetPtSignImpZ;
    TH2F* h2dataTagjetPtImpZSig;
    TH3F* h3dataTagjetPtTrackPtSignImpZSig;
    TH2F* h2dataTagjetPtImpXYZ;
    TH2F* h2dataTagjetPtSignImpXYZ;
    TH2F* h2dataTagjetPtImpXYZSig;
    TH3F* h3dataTagjetPtTrackPtSignImpXYZSig;

		//// normalized
    TH1F* hdatajetNormPt;
    TH1F* hdatajetNormNEventsPt;
    TH1F* hdatajetNormNJetsPt;
    TH1F* hdatajetNormAreaPt;
    TH1F* hdatajetNormPtRebin;
    TH1F* hdatajetNormNEventsPtRebin;
    TH1F* hdatajetNormNJetsPtRebin;
    TH1F* hdatajetNormAreaPtRebin;
    TH1F* hdatajetNormNEventsEta;
    TH1F* hdatajetNormNJetsEta;
    TH1F* hdatajetNormAreaEta;
    TH1F* hdatajetNormNEventsPhi;
    TH1F* hdatajetNormNJetsPhi;
    TH1F* hdatajetNormAreaPhi;
    TH1F* hdatajetNormNEventsTrackPt[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJetsTrackPt[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormAreaTrackPt[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEventsTrackEta[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJetsTrackEta[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormAreaTrackEta[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNEventsTrackPhi[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormNJetsTrackPhi[HfJetTagging::nBinsJetPt+1];
    TH1F* hdatajetNormAreaTrackPhi[HfJetTagging::nBinsJetPt+1];

		TH1F* hdatajetImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormNEventsImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormNJetsImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormAreaImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];


		TH1F* hdatajetImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormNEventsImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormNJetsImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormAreaImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormNEventsImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNEventsSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormNJetsImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormNJetsSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		TH1F* hdatajetNormAreaImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormAreaSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		/// MC
    TH1F* hsimEventSel;
    TH1F* hsimLumi;
    TH2F* h2simjetPtFlavour;
    TH2F* h2simjetEtaFlavour;
    TH2F* h2simjetPhiFlavour;
    TH3F* h3simjetPtTrackPtFlavour;
    TH3F* h3simjetPtTrackEtaFlavour;
    TH3F* h3simjetPtTrackPhiFlavour;
    TH3F* h3simjetPtImpXYFlavour;
    TH3F* h3simjetPtSignImpXYFlavour;
    TH3F* h3simjetPtImpXYSigFlavour;
    TH3F* h3simjetPtSignImpXYSigFlavour;
    TH3F* h3simjetPtImpZFlavour;
    TH3F* h3simjetPtSignImpZFlavour;
    TH3F* h3simjetPtImpZSigFlavour;
    TH3F* h3simjetPtSignImpZSigFlavour;
    TH3F* h3simjetPtImpXYZFlavour;
    TH3F* h3simjetPtSignImpXYZFlavour;
    TH3F* h3simjetPtImpXYZSigFlavour;
    TH3F* h3simjetPtSignImpXYZSigFlavour;
    TH3F* h3simTagtrackPtImpXYFlavour;
    TH3F* h3simTagtrackPtSignImpXYFlavour;
    TH3F* h3simTagtrackPtImpXYSigFlavour;
    TH3F* h3simTagtrackPtSignImpXYSigFlavour;
    TH2F* h2simpartjetPtFlavour;
    TH2F* h2simpartjetEtaFlavour;
    TH2F* h2simpartjetPhiFlavour;
    TH3F* h3simpartjetPtCompareFlavour;
    TH3F* h3simjetPtpartjetPtMatchedFlavour;

    //// normalized
    TH1F* hsimjetNormPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNEventsPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNJetsPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormAreaPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNEventsEta[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNJetsEta[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormAreaEta[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNEventsPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNJetsPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormAreaPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNEventsPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNJetsPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormAreaPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNEventsPt[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNJetsPt[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormAreaPt[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNEventsEta[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNJetsEta[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormAreaEta[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNEventsPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNJetsPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormAreaPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNEventsPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormNJetsPtMatched[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormAreaPtMatched[HfJetTagging::nFlavour+1];

    TH1F* hsimjetNormNEventsTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNEventsSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormAreaSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormNJetsSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNEventsImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormAreaImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNJetsImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNEventsSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormAreaSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNJetsSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNEventsImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormAreaImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNJetsImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNEventsSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormAreaSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormNJetsSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    
    ///// rebin
    TH1F* hsimjetNormPtRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNEventsPtRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNJetsPtRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormAreaPtRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNEventsPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNJetsPtMatchedRebin[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormNAreaPtMatchedRebin[HfJetTagging::nFlavour+1];

    // model
    TH1F* hpwhgNEvent;
    TH1F* hpwhgInclusiveJetXSection_R2;
    TH1F* hpwhgBkgSubtractedJetXSection_R2;
    TH1F* hpwhgBJetXSection_R2;
    TH1F* hpwhgBkgSubtractedBJetXSection_R2;
    TH1F* hpwhgCJetXSection_R2;
    TH1F* hpwhgBkgSubtractedCJetXSection_R2;
    TH1F* hpwhgInclusiveJetXSection_R3;
    TH1F* hpwhgBkgSubtractedJetXSection_R3;
    TH1F* hpwhgBJetXSection_R3;
    TH1F* hpwhgBkgSubtractedBJetXSection_R3;
    TH1F* hpwhgCJetXSection_R3;
    TH1F* hpwhgBkgSubtractedCJetXSection_R3;
    TH1F* hpwhgInclusiveJetXSection_R4;
    TH1F* hpwhgBkgSubtractedJetXSection_R4;
    TH1F* hpwhgBJetXSection_R4;
    TH1F* hpwhgBkgSubtractedBJetXSection_R4;
    TH1F* hpwhgCJetXSection_R4;
    TH1F* hpwhgBkgSubtractedCJetXSection_R4;
    TH1F* hpwhgInclusiveJetXSection_R5;
    TH1F* hpwhgBkgSubtractedJetXSection_R5;
    TH1F* hpwhgBJetXSection_R5;
    TH1F* hpwhgBkgSubtractedBJetXSection_R5;
    TH1F* hpwhgCJetXSection_R5;
    TH1F* hpwhgBkgSubtractedCJetXSection_R5;
    TH1F* hpwhgInclusiveJetXSection_R6;
    TH1F* hpwhgBkgSubtractedJetXSection_R6;
    TH1F* hpwhgBJetXSection_R6;
    TH1F* hpwhgBkgSubtractedBJetXSection_R6;
    TH1F* hpwhgCJetXSection_R6;
    TH1F* hpwhgBkgSubtractedCJetXSection_R6;
    TProfile* hpwhgTotalCrossSection;
    TH1F* hpwhgNumberOfTrials;
    TH1F* hpwhgbjetCrossSection;

    TH1F* hpwhgInclusiveJetXSection_R2Rebin;
    TH1F* hpwhgBkgSubtractedJetXSection_R2Rebin;
    TH1F* hpwhgBJetXSection_R2Rebin;
    TH1F* hpwhgBkgSubtractedBJetXSection_R2Rebin;
    TH1F* hpwhgCJetXSection_R2Rebin;
    TH1F* hpwhgBkgSubtractedCJetXSection_R2Rebin;
    TH1F* hpwhgInclusiveJetXSection_R3Rebin;
    TH1F* hpwhgBkgSubtractedJetXSection_R3Rebin;
    TH1F* hpwhgBJetXSection_R3Rebin;
    TH1F* hpwhgBkgSubtractedBJetXSection_R3Rebin;
    TH1F* hpwhgCJetXSection_R3Rebin;
    TH1F* hpwhgBkgSubtractedCJetXSection_R3Rebin;
    TH1F* hpwhgInclusiveJetXSection_R4Rebin;
    TH1F* hpwhgBkgSubtractedJetXSection_R4Rebin;
    TH1F* hpwhgBJetXSection_R4Rebin;
    TH1F* hpwhgBkgSubtractedBJetXSection_R4Rebin;
    TH1F* hpwhgCJetXSection_R4Rebin;
    TH1F* hpwhgBkgSubtractedCJetXSection_R4Rebin;
    TH1F* hpwhgInclusiveJetXSection_R5Rebin;
    TH1F* hpwhgBkgSubtractedJetXSection_R5Rebin;
    TH1F* hpwhgBJetXSection_R5Rebin;
    TH1F* hpwhgBkgSubtractedBJetXSection_R5Rebin;
    TH1F* hpwhgCJetXSection_R5Rebin;
    TH1F* hpwhgBkgSubtractedCJetXSection_R5Rebin;
    TH1F* hpwhgInclusiveJetXSection_R6Rebin;
    TH1F* hpwhgBkgSubtractedJetXSection_R6Rebin;
    TH1F* hpwhgBJetXSection_R6Rebin;
    TH1F* hpwhgBkgSubtractedBJetXSection_R6Rebin;
    TH1F* hpwhgCJetXSection_R6Rebin;
    TH1F* hpwhgBkgSubtractedCJetXSection_R6Rebin;
    TProfile* hpwhgTotalCrossSectionRebin;
    TH1F* hpwhgbjetCrossSectionRebin;

    TGraphAsymmErrors* grxsectionRun25TeVIP;
    TGraphAsymmErrors* grxsectionRun25TeVIPsys;
    TGraphAsymmErrors* grxsectionRun2IP;
    TGraphAsymmErrors* grxsectionRun2IPsys;
    TGraphAsymmErrors* grxsectionRun2SV;
    TGraphAsymmErrors* grxsectionRun2SVsys;

  private:
    TLatex latex;
    TString dirDataGen;
    TString dirDataIP;
    TString dirSimGen;
    TString dirSimResMat;
    TString dirSimIP;
    TString dirDataVsSimGen;
    TString dirDataVsSimIP;
};

HfJetTaggingAnalysis::~HfJetTaggingAnalysis() {
  delete hdataEventSel;
  delete h3dataTagjetPtTrackPtTrackEta;
  delete h3dataTagjetPtTrackPtTrackPhi;
  delete h2dataTagjetPtImpXY;
  delete h2dataTagjetPtSignImpXY;
  delete h2dataTagjetPtImpXYSig;
  delete h3dataTagjetPtTrackPtSignImpXYSig;
  delete h2dataTagjetPtImpZ;
  delete h2dataTagjetPtSignImpZ;
  delete h2dataTagjetPtImpZSig;
  delete h3dataTagjetPtTrackPtSignImpZSig;
  delete h2dataTagjetPtImpXYZ;
  delete h2dataTagjetPtSignImpXYZ;
  delete h2dataTagjetPtImpXYZSig;
  delete h3dataTagjetPtTrackPtSignImpXYZSig;

  delete hsimEventSel;
  delete h3simjetPtTrackPtFlavour;
  delete h3simjetPtTrackEtaFlavour;
  delete h3simjetPtTrackPhiFlavour;
  delete h3simjetPtImpXYFlavour;
  delete h3simjetPtSignImpXYFlavour;
  delete h3simjetPtImpXYSigFlavour;
  delete h3simjetPtSignImpXYSigFlavour;
  delete h3simjetPtImpZFlavour;
  delete h3simjetPtSignImpZFlavour;
  delete h3simjetPtImpZSigFlavour;
  delete h3simjetPtSignImpZSigFlavour;
  delete h3simjetPtImpXYZFlavour;
  delete h3simjetPtSignImpXYZFlavour;
  delete h3simjetPtImpXYZSigFlavour;
  delete h3simjetPtSignImpXYZSigFlavour;

  delete hdatajetPt;
  for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    delete hdatajetTrackPt[binJetPt];
    delete hdatajetTrackEta[binJetPt];
    delete hdatajetTrackPhi[binJetPt];
    delete hdatajetImpXY[binJetPt];
    delete hdatajetSignImpXY[binJetPt];
    delete hdatajetImpXYSig[binJetPt];
    for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
      delete hdatajetSignImpXYSig[binJetPt][binTrackPt];
    }
  }

  for (int flavour=0; flavour < HfJetTagging::nFlavour; flavour++) {
    for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
      delete hsimjetTrackPt[flavour][binJetPt];
      delete hsimjetTrackEta[flavour][binJetPt];
      delete hsimjetTrackPhi[flavour][binJetPt];
      delete hsimjetImpXY[flavour][binJetPt];
      delete hsimjetSignImpXY[flavour][binJetPt];
      delete hsimjetImpXYSig[flavour][binJetPt];
      delete hsimjetSignImpXYSig[flavour][binJetPt];
      delete hsimjetImpZ[flavour][binJetPt];
      delete hsimjetSignImpZ[flavour][binJetPt];
      delete hsimjetImpZSig[flavour][binJetPt];
      delete hsimjetSignImpZSig[flavour][binJetPt];
      delete hsimjetImpXYZ[flavour][binJetPt];
      delete hsimjetSignImpXYZ[flavour][binJetPt];
      delete hsimjetImpXYZSig[flavour][binJetPt];
      delete hsimjetSignImpXYZSig[flavour][binJetPt];
    }
    for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
      delete hsimtrackImpXY[flavour][binTrackPt];
      delete hsimtrackSignImpXY[flavour][binTrackPt];
      delete hsimtrackImpXYSig[flavour][binTrackPt];
      delete hsimtrackSignImpXYSig[flavour][binTrackPt];
      delete hsimtrackImpZ[flavour][binTrackPt];
      delete hsimtrackSignImpZ[flavour][binTrackPt];
      delete hsimtrackImpZSig[flavour][binTrackPt];
      delete hsimtrackSignImpZSig[flavour][binTrackPt];
      delete hsimtrackImpXYZ[flavour][binTrackPt];
      delete hsimtrackSignImpXYZ[flavour][binTrackPt];
      delete hsimtrackImpXYZSig[flavour][binTrackPt];
      delete hsimtrackSignImpXYZSig[flavour][binTrackPt];
    }
  }
}

void HfJetTaggingAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  dirFig = "fig";
  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  } 
  dirDataGen = Form("%s/%s/data/%s/gen", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirDataIP = Form("%s/%s/data/%s/ip", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSimGen = Form("%s/%s/sim/%s/gen", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  dirSimResMat = Form("%s/%s/sim/%s/resmat", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  dirSimIP = Form("%s/%s/sim/%s/ip", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  dirDataVsSimGen = Form("%s/%s/dataVSsim/%s_%s/gen", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  dirDataVsSimIP = Form("%s/%s/dataVSsim/%s_%s/ip", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirDataGen, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataIP, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSimGen, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSimIP, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSimResMat, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSimResMat.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSimResMat.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSimResMat.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSimResMat.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSimGen, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirDataVsSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirDataVsSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirDataVsSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirDataVsSimGen.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSimIP, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirDataVsSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirDataVsSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirDataVsSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirDataVsSimIP.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingAnalysis::loadDataQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (Data, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task";
  TString taskTagQa = "jet-taggerhf-qa-charged";
  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  hdataEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
  //hdataLumi = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
  ndataEvents = hdataEventSel->GetEntries();
  if (debug) std::cout << "data evt: " << ndataEvents << std::endl;
  hdatajetPt = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_pt", taskTagQa.Data())));
  hdatajetEta = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_eta", taskTagQa.Data())));
  hdatajetPhi = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_phi", taskTagQa.Data())));
  hdatajetPt->Sumw2();
  hdatajetEta->Sumw2();
  hdatajetPhi->Sumw2();
  for (int binJetPt = 1; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
    float binxmin = hdatajetPt->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
    float binxmax = hdatajetPt->FindBin(HfJetTagging::binsJetPt[binJetPt]);
    float content = hdatajetPt->Integral(binxmin, binxmax-1);
    ndataJets[0] += content;
    ndataJets[binJetPt] = content;
  }
  if (ndataEvents < 0) {
    std::cout << "number of data events is 0" << std::endl;
    return 0;
  }
  return 1;
}

void HfJetTaggingAnalysis::rebinHistData() {
  hdatajetPtRebin = new TH1F("hdatajetPtRebin", "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
  hdatajetPtRebin = (TH1F*) hdatajetPt->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
}

void HfJetTaggingAnalysis::initCommonHistData(TString rootData) {
  loadDataQA(rootData);
  rebinHistData();
  std::cout << "load and completed common hist (Data)" << std::endl;
}

//int HfJetTaggingAnalysis::loadSimQA(TString rootSim) {
//  if (gSystem->AccessPathName(rootSim.Data())) {
//    std::cout << "Input file (MC, Flavour QA) not found!" << std::endl;
//    return 0;
//  }
//  TString taskEventSel = "event-selection-task";
//  //TString taskEventSel = "eventselection-run3/eventselection";
//  TString taskTagQa = "jet-taggerhf-qa-charged";
//  TFile* fin;
//  fin = TFile::Open(rootSim.Data(), "READ");
//  hsimEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
//  nsimEvents = hsimEventSel->GetEntries();
//  if (debug) std::cout << "sim evt: " << nsimEvents << std::endl;
//  h2simjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskTagQa.Data())));
//  h2simjetEtaFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_flavour", taskTagQa.Data())));
//  h2simjetPhiFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_flavour", taskTagQa.Data())));
//  h2simjetPtFlavour->Sumw2();
//  h2simjetEtaFlavour->Sumw2();
//  h2simjetPhiFlavour->Sumw2();
//  return 1;
//}

int HfJetTaggingAnalysis::loadSimQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task"; // <--- Primary path
  TString taskEventSel_backup = "eventselection-run3/eventselection"; // <--- Backup path
  TString taskTagQa = "jet-taggerhf-qa-charged";
  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");

  hsimEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
  if (!hsimEventSel) {
    if (debug) std::cout << "Primary path for Event Selection failed. Trying backup path: " << taskEventSel_backup.Data() << std::endl;
    hsimEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel_backup.Data())));
  }

  if (hsimEventSel) { // Only proceed if the histogram was successfully loaded
    nsimEvents = hsimEventSel->GetEntries();
    if (debug) std::cout << "sim evt: " << nsimEvents << std::endl;
  } else {
    nsimEvents = 0; // Set to 0 if loading failed
    if (debug) std::cout << "sim evt: 0 (Histogram not found)" << std::endl;
  }

  h2simjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskTagQa.Data())));
  h2simjetEtaFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_flavour", taskTagQa.Data())));
  h2simjetPhiFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_flavour", taskTagQa.Data())));

  if (h2simjetPtFlavour) h2simjetPtFlavour->Sumw2();
  if (h2simjetEtaFlavour) h2simjetEtaFlavour->Sumw2();
  if (h2simjetPhiFlavour) h2simjetPhiFlavour->Sumw2();

  return 1;
}


void HfJetTaggingAnalysis::initHistogramMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetPt[flavour] = new TH1F(Form("hsimjetPt_%d", flavour), "", h2simjetPtFlavour->GetNbinsX() , h2simjetPtFlavour->GetXaxis()->GetBinLowEdge(1), h2simjetPtFlavour->GetXaxis()->GetBinUpEdge(h2simjetPtFlavour->GetNbinsX()));
    hsimjetEta[flavour] = new TH1F(Form("hsimjetEta_%d", flavour), "", h2simjetEtaFlavour->GetNbinsX(), h2simjetEtaFlavour->GetXaxis()->GetBinLowEdge(1), h2simjetEtaFlavour->GetXaxis()->GetBinUpEdge(h2simjetEtaFlavour->GetNbinsX()));
    hsimjetPhi[flavour] = new TH1F(Form("hsimjetPhi_%d", flavour), "", h2simjetPhiFlavour->GetNbinsX(), h2simjetPhiFlavour->GetXaxis()->GetBinLowEdge(1), h2simjetPhiFlavour->GetXaxis()->GetBinUpEdge(h2simjetPhiFlavour->GetNbinsX()));
    hsimjetPt[flavour]->Sumw2();
    hsimjetEta[flavour]->Sumw2();
    hsimjetPhi[flavour]->Sumw2();
  }
  std::cout << "completed initHistogramMC" << std::endl;
}

void HfJetTaggingAnalysis::projectionHistMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
    TH1F* projJetPt = reinterpret_cast<TH1F*> (h2simjetPtFlavour->ProjectionX(Form("projJetPt_%d", binFlavour), binFlavour, binFlavour));
    TH1F* projJetEta = reinterpret_cast<TH1F*> (h2simjetEtaFlavour->ProjectionX(Form("projJetEta_%d", binFlavour), binFlavour, binFlavour));
    TH1F* projJetPhi = reinterpret_cast<TH1F*> (h2simjetPhiFlavour->ProjectionX(Form("projJetPhi_%d", binFlavour), binFlavour, binFlavour));
    hsimjetPt[0]->Add(projJetPt);
    hsimjetEta[0]->Add(projJetEta);
    hsimjetPhi[0]->Add(projJetPhi);
    hsimjetPt[flavour] = reinterpret_cast<TH1F*> (projJetPt->Clone());
    hsimjetEta[flavour] = reinterpret_cast<TH1F*> (projJetEta->Clone());
    hsimjetPhi[flavour] = reinterpret_cast<TH1F*> (projJetPhi->Clone());
    nsimJets[0][0] += hsimjetEta[flavour]->Integral();
    nsimJets[flavour][0] = hsimjetEta[flavour]->Integral();
    for (int binJetPt = 1; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
      int binLow = hsimjetPt[flavour]->FindBin(HfJetTagging::binsJetPt[binJetPt - 1]);
      int binHigh = hsimjetPt[flavour]->FindBin(HfJetTagging::binsJetPt[binJetPt]) - 1;
      float integral = hsimjetPt[flavour]->Integral(binLow, binHigh);
      nsimJets[0][binJetPt] += integral;
      nsimJets[flavour][binJetPt] = integral;
    }
  }
}

void HfJetTaggingAnalysis::rebinHistMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetPtRebin[flavour] = new TH1F(Form("hsimjetPtRebin_%d", flavour), "", HfJetTagging::nBinsJetPt , HfJetTagging::binsJetPt);
    hsimjetPtRebin[flavour] = (TH1F*) hsimjetPt[flavour]->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  }
}

void HfJetTaggingAnalysis::initCommonHistMC(TString rootSim) {
  loadSimQA(rootSim);
  initHistogramMC();
  projectionHistMC();
  rebinHistMC();
  std::cout << "load and completed common hist (MC)" << std::endl;
}

int HfJetTaggingAnalysis::loadDataIP(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task";
  TString taskTagQa = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  if (!fillData) return 0;
  h3dataTagjetPtTrackPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_eta", taskTagQa.Data())));
  h3dataTagjetPtTrackPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_phi", taskTagQa.Data())));
  h3dataTagjetPtTrackPtTrackEta->Sumw2();
  h3dataTagjetPtTrackPtTrackPhi->Sumw2();
  if (fillIPxy) {
    h2dataTagjetPtImpXY = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy", taskTagQa.Data())));
    h2dataTagjetPtSignImpXY = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xy", taskTagQa.Data())));
    h2dataTagjetPtImpXYSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy_significance", taskTagQa.Data())));
    h3dataTagjetPtTrackPtSignImpXYSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xy_significance", taskTagQa.Data())));
    h2dataTagjetPtImpXY->Sumw2();
    h2dataTagjetPtSignImpXY->Sumw2();
    h2dataTagjetPtImpXYSig->Sumw2();
    h3dataTagjetPtTrackPtSignImpXYSig->Sumw2();
  }
  if (fillIPz) {
    h2dataTagjetPtImpZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_z", taskTagQa.Data())));
    h2dataTagjetPtSignImpZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_z", taskTagQa.Data())));
    h2dataTagjetPtImpZSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_z_significance", taskTagQa.Data())));
    h3dataTagjetPtTrackPtSignImpZSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_z_significance", taskTagQa.Data())));
    h2dataTagjetPtImpZ->Sumw2();
    h2dataTagjetPtSignImpZ->Sumw2();
    h2dataTagjetPtImpZSig->Sumw2();
    h3dataTagjetPtTrackPtSignImpZSig->Sumw2();
  }
  if (fillIPxyz) {
    h2dataTagjetPtImpXYZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xyz", taskTagQa.Data())));
    h2dataTagjetPtSignImpXYZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xyz", taskTagQa.Data())));
    h2dataTagjetPtImpXYZSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xyz_significance", taskTagQa.Data())));
    h3dataTagjetPtTrackPtSignImpXYZSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xyz_significance", taskTagQa.Data())));
    h2dataTagjetPtImpXYZ->Sumw2();
    h2dataTagjetPtSignImpXYZ->Sumw2();
    h2dataTagjetPtImpXYZSig->Sumw2();
    h3dataTagjetPtTrackPtSignImpXYZSig->Sumw2();
  }

  std::cout << "Load completed Flavour Real data" << std::endl;
  return 1;
}

void HfJetTaggingAnalysis::initHistIPData() {
  if (!fillData) return;
  //hdatajetPt = new TH1F("hdatajetPt", "", h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsX()));
  for (int jetPt =0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
    hdatajetTrackPt[jetPt] = new TH1F(Form("hdatajetTrackPt_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
    hdatajetTrackEta[jetPt] = new TH1F(Form("hdatajetTrackEta_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsZ(), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
    hdatajetTrackPhi[jetPt] = new TH1F(Form("hdatajetTrackPhi_%d", jetPt), "", h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ(), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));
    if (fillIPxy) {
      hdatajetImpXY[jetPt] = new TH1F(Form("hdatajetImpXY_%d", jetPt), "", h2dataTagjetPtImpXY->GetNbinsY(), h2dataTagjetPtImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXY->GetNbinsY()));
      hdatajetSignImpXY[jetPt] = new TH1F(Form("hdatajetSignImpXY_%d", jetPt), "", h2dataTagjetPtSignImpXY->GetNbinsY(), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXY->GetNbinsY()));
      hdatajetImpXYSig[jetPt] = new TH1F(Form("hdatajetImpXYSig_%d", jetPt), "", h2dataTagjetPtImpXYSig->GetNbinsY(), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYSig->GetNbinsY()));

      hdatajetNormNEventsImpXY[jetPt] = new TH1F(Form("hdatajetNormNEventsImpXY_%d", jetPt), "", h2dataTagjetPtImpXY->GetNbinsY(), h2dataTagjetPtImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXY->GetNbinsY()));
      hdatajetNormNEventsSignImpXY[jetPt] = new TH1F(Form("hdatajetNormNEventsSignImpXY_%d", jetPt), "", h2dataTagjetPtSignImpXY->GetNbinsY(), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXY->GetNbinsY()));
      hdatajetNormNEventsImpXYSig[jetPt] = new TH1F(Form("hdatajetNormNEventsImpXYSig_%d", jetPt), "", h2dataTagjetPtImpXYSig->GetNbinsY(), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYSig->GetNbinsY()));

      hdatajetNormNJetsImpXY[jetPt] = new TH1F(Form("hdatajetNormNJetsImpXY_%d", jetPt), "", h2dataTagjetPtImpXY->GetNbinsY(), h2dataTagjetPtImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXY->GetNbinsY()));
      hdatajetNormNJetsSignImpXY[jetPt] = new TH1F(Form("hdatajetNormNJetsSignImpXY_%d", jetPt), "", h2dataTagjetPtSignImpXY->GetNbinsY(), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXY->GetNbinsY()));
      hdatajetNormNJetsImpXYSig[jetPt] = new TH1F(Form("hdatajetNormNJetsImpXYSig_%d", jetPt), "", h2dataTagjetPtImpXYSig->GetNbinsY(), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYSig->GetNbinsY()));

      hdatajetNormAreaImpXY[jetPt] = new TH1F(Form("hdatajetNormAreaImpXY_%d", jetPt), "", h2dataTagjetPtImpXY->GetNbinsY(), h2dataTagjetPtImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXY->GetNbinsY()));
      hdatajetNormAreaSignImpXY[jetPt] = new TH1F(Form("hdatajetNormAreaSignImpXY_%d", jetPt), "", h2dataTagjetPtSignImpXY->GetNbinsY(), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXY->GetNbinsY()));
      hdatajetNormAreaImpXYSig[jetPt] = new TH1F(Form("hdatajetNormAreaImpXYSig_%d", jetPt), "", h2dataTagjetPtImpXYSig->GetNbinsY(), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYSig->GetNbinsY()));
    }
    if (fillIPz) {
      hdatajetImpZ[jetPt] = new TH1F(Form("hdatajetImpZ_%d", jetPt), "", h2dataTagjetPtImpZ->GetNbinsY(), h2dataTagjetPtImpZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpZ->GetNbinsY()));
      hdatajetSignImpZ[jetPt] = new TH1F(Form("hdatajetSignImpZ_%d", jetPt), "", h2dataTagjetPtSignImpZ->GetNbinsY(), h2dataTagjetPtSignImpZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpZ->GetNbinsY()));
      hdatajetImpZSig[jetPt] = new TH1F(Form("hdatajetImpZSig_%d", jetPt), "", h2dataTagjetPtImpZSig->GetNbinsY(), h2dataTagjetPtImpZSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpZSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpZSig->GetNbinsY()));
    }
    if (fillIPxyz) {
      hdatajetImpXYZ[jetPt] = new TH1F(Form("hdatajetImpXYZ_%d", jetPt), "", h2dataTagjetPtImpXYZ->GetNbinsY(), h2dataTagjetPtImpXYZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYZ->GetNbinsY()));
      hdatajetSignImpXYZ[jetPt] = new TH1F(Form("hdatajetSignImpXYZ_%d", jetPt), "", h2dataTagjetPtSignImpXYZ->GetNbinsY(), h2dataTagjetPtSignImpXYZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXYZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXYZ->GetNbinsY()));
      hdatajetImpXYZSig[jetPt] = new TH1F(Form("hdatajetImpXYZSig_%d", jetPt), "", h2dataTagjetPtImpXYZSig->GetNbinsY(), h2dataTagjetPtImpXYZSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYZSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYZSig->GetNbinsY()));
    }
    for (int trackPt =0; trackPt < HfJetTagging::nBinsTrackPt+1; trackPt++) {
      if (fillIPxy) {
        hdatajetSignImpXYSig[jetPt][trackPt] = new TH1F(Form("hdatajetSignImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ()));
        hdatajetNormNEventsSignImpXYSig[jetPt][trackPt] = new TH1F(Form("hdatajetNormNEventsSignImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ()));
        hdatajetNormNJetsSignImpXYSig[jetPt][trackPt] = new TH1F(Form("hdatajetNormNJetsSignImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ()));
        hdatajetNormAreaSignImpXYSig[jetPt][trackPt] = new TH1F(Form("hdatajetNormAreaSignImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ()));
      }
      if (fillIPz) {
        hdatajetSignImpZSig[jetPt][trackPt] = new TH1F(Form("hdatajetSignImpZSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpZSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpZSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpZSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpZSig->GetNbinsZ()));
      }
      if (fillIPxyz) {
        hdatajetSignImpXYZSig[jetPt][trackPt] = new TH1F(Form("hdatajetSignImpXYZSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYZSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYZSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsZ()));
      }
    }
  }
  std::cout << "Completed Flavour data for initilize histogram" << std::endl;
}

void HfJetTaggingAnalysis::projectionHistIPData() {
  if (!fillData) return;
  //TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
  //int cutBinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::startJetPt);
  //int cutBinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(50);
  int cutBinJetPt = 1;
  TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", cutBinJetPt, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));

  TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY("projJetTrackPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
  TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
  TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsY()));
  //hdatajetPt = reinterpret_cast<TH1F*>(projJetPt->Clone("hdatajetPt"));
  hdatajetTrackPt[0] = reinterpret_cast<TH1F*>(projTrackPt->Clone("hdatajetTrackPt_0"));
  hdatajetTrackEta[0] = reinterpret_cast<TH1F*>(projTrackEta->Clone("hdatajetTrackEta_0"));
  hdatajetTrackPhi[0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone("hdatajetTrackPhi_0"));
  if (fillIPxy) {
    cutBinJetPt = h2dataTagjetPtImpXY->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projImpXY = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXY->ProjectionY("projJetImpXY", cutBinJetPt, h2dataTagjetPtImpXY->GetNbinsX()));
    cutBinJetPt = h2dataTagjetPtSignImpXY->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXY->ProjectionY("projJetSignImpXY", cutBinJetPt, h2dataTagjetPtSignImpXY->GetNbinsX()));
    cutBinJetPt = h2dataTagjetPtImpXYSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYSig->ProjectionY("projJetImpXYSig", cutBinJetPt, h2dataTagjetPtImpXYSig->GetNbinsX()));
    cutBinJetPt = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYSig->ProjectionZ("projJetSignImpXYSig", cutBinJetPt, h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsY()));
    hdatajetImpXY[0] = reinterpret_cast<TH1F*>(projImpXY->Clone("hdatajetImpXY_0"));
    hdatajetSignImpXY[0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone("hdatajetSignImpXY_0"));
    hdatajetImpXYSig[0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone("hdatajetImpXYSig_0"));
    hdatajetSignImpXYSig[0][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone("hdatajetSignImpXYSig_0_0"));
  }
  if (fillIPz) {
    cutBinJetPt = h2dataTagjetPtImpZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projImpZ = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZ->ProjectionY("projJetImpZ", cutBinJetPt, h2dataTagjetPtImpZ->GetNbinsX()));
    cutBinJetPt = h2dataTagjetPtSignImpZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projSignImpZ = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpZ->ProjectionY("projJetSignImpZ", cutBinJetPt, h2dataTagjetPtSignImpZ->GetNbinsX()));
    cutBinJetPt = h2dataTagjetPtImpZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projImpZSig = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZSig->ProjectionY("projJetImpZSig", cutBinJetPt, h2dataTagjetPtImpZSig->GetNbinsX()));
    cutBinJetPt = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpZSig->ProjectionZ("projJetSignImpZSig", cutBinJetPt, h3dataTagjetPtTrackPtSignImpZSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpZSig->GetNbinsY()));
    hdatajetImpZ[0] = reinterpret_cast<TH1F*>(projImpZ->Clone("hdatajetImpZ_0"));
    hdatajetSignImpZ[0] = reinterpret_cast<TH1F*>(projSignImpZ->Clone("hdatajetSignImpZ_0"));
    hdatajetImpZSig[0] = reinterpret_cast<TH1F*>(projImpZSig->Clone("hdatajetImpZSig_0"));
    hdatajetSignImpZSig[0][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone("hdatajetSignImpZSig_0_0"));
  }
  if (fillIPxyz) {
    cutBinJetPt = h2dataTagjetPtImpXYZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projImpXYZ = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZ->ProjectionY("projJetImpXYZ", cutBinJetPt, h2dataTagjetPtImpXYZ->GetNbinsX()));
    cutBinJetPt = h2dataTagjetPtSignImpXYZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projSignImpXYZ = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXYZ->ProjectionY("projJetSignImpXYZ", cutBinJetPt, h2dataTagjetPtSignImpXYZ->GetNbinsX()));
    cutBinJetPt = h2dataTagjetPtImpXYZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projImpXYZSig = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZSig->ProjectionY("projJetImpXYZSig", cutBinJetPt, h2dataTagjetPtImpXYZSig->GetNbinsX()));
    cutBinJetPt = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
    TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYZSig->ProjectionZ("projJetSignImpXYZSig", cutBinJetPt, h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsY()));
    hdatajetImpXYZ[0] = reinterpret_cast<TH1F*>(projImpXYZ->Clone("hdatajetImpXYZ_0"));
    hdatajetSignImpXYZ[0] = reinterpret_cast<TH1F*>(projSignImpXYZ->Clone("hdatajetSignImpXYZ_0"));
    hdatajetImpXYZSig[0] = reinterpret_cast<TH1F*>(projImpXYZSig->Clone("hdatajetImpXYZSig_0"));
    hdatajetSignImpXYZSig[0][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone("hdatajetSignImpXYZSig_0_0"));
  }
  for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
    int leftbinJetPtSignImpXYSig = -1;
    int rightbinJetPtSignImpXYSig = -1;
    int leftbinJetPtSignImpZSig = -1;
    int rightbinJetPtSignImpZSig = -1;
    int leftbinJetPtSignImpXYZSig = -1;
    int rightbinJetPtSignImpXYZSig = -1;

    int leftbinJetPtTrackEta = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtTrackEta = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY(Form("projJetPtRangeTrackPt_%d", binJetPt), leftbinJetPtTrackEta, rightbinJetPtTrackEta, 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
    TH1F* projJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ(Form("projJetPtRangeTrackEta_%d", binJetPt), leftbinJetPtTrackEta, rightbinJetPtTrackEta, 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));

    int leftbinJetPtTrackPhi = h3dataTagjetPtTrackPtTrackPhi->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
    int rightbinJetPtTrackPhi = h3dataTagjetPtTrackPtTrackPhi->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    TH1F* projJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ(Form("projJetPtRangeTrackPhi_%d", binJetPt), leftbinJetPtTrackPhi, rightbinJetPtTrackPhi, 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));

    hdatajetTrackPt[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPt->Clone(Form("hdatajetTrackPt_%d", binJetPt)));
    hdatajetTrackEta[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackEta->Clone(Form("hdatajetTrackEta_%d", binJetPt)));
    hdatajetTrackPhi[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPhi->Clone(Form("hdatajetTrackPhi_%d", binJetPt)));

    if (fillIPxy) {
      int leftbinJetPtImpXY = h2dataTagjetPtImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtImpXY = h2dataTagjetPtImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeImpXY  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXY->ProjectionY(Form("projJetPtRangeImpXY_%d", binJetPt), leftbinJetPtImpXY, rightbinJetPtImpXY));

      int leftbinJetPtSignImpXY = h2dataTagjetPtSignImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtSignImpXY = h2dataTagjetPtSignImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeSignImpXY  = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXY->ProjectionY(Form("projJetPtRangeSignImpXY_%d", binJetPt), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY));

      int leftbinJetPtImpXYSig = h2dataTagjetPtImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtImpXYSig = h2dataTagjetPtImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeImpXYSig  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYSig->ProjectionY(Form("projJetPtRangeImpXYSig_%d", binJetPt), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig));

      hdatajetImpXY[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone(Form("hdatajetImpXY_%d", binJetPt)));
      hdatajetSignImpXY[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone(Form("hdatajetSignImpXY_%d", binJetPt)));
      hdatajetImpXYSig[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone(Form("hdatajetImpXYSig_%d", binJetPt)));
      leftbinJetPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      rightbinJetPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    }
    if (fillIPz) {

      int leftbinJetPtImpZ = h2dataTagjetPtImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtImpZ = h2dataTagjetPtImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeImpZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZ->ProjectionY(Form("projJetPtRangeImpZ_%d", binJetPt), leftbinJetPtImpZ, rightbinJetPtImpZ));

      int leftbinJetPtSignImpZ = h2dataTagjetPtSignImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtSignImpZ = h2dataTagjetPtSignImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeSignImpZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpZ->ProjectionY(Form("projJetPtRangeSignImpZ_%d", binJetPt), leftbinJetPtSignImpZ, rightbinJetPtSignImpZ));

      int leftbinJetPtImpZSig = h2dataTagjetPtImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtImpZSig = h2dataTagjetPtImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeImpZSig  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZSig->ProjectionY(Form("projJetPtRangeImpZSig_%d", binJetPt), leftbinJetPtImpZSig, rightbinJetPtImpZSig));

      hdatajetImpZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZ->Clone(Form("hdatajetImpZ_%d", binJetPt)));
      hdatajetSignImpZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZ->Clone(Form("hdatajetSignImpZ_%d", binJetPt)));
      hdatajetImpZSig[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZSig->Clone(Form("hdatajetImpZSig_%d", binJetPt)));
      leftbinJetPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      rightbinJetPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    }
    if (fillIPxyz) {

      int leftbinJetPtImpXYZ = h2dataTagjetPtImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtImpXYZ = h2dataTagjetPtImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeImpXYZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZ->ProjectionY(Form("projJetPtRangeImpXYZ_%d", binJetPt), leftbinJetPtImpXYZ, rightbinJetPtImpXYZ));

      int leftbinJetPtSignImpXYZ = h2dataTagjetPtSignImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtSignImpXYZ = h2dataTagjetPtSignImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeSignImpXYZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXYZ->ProjectionY(Form("projJetPtRangeSignImpXYZ_%d", binJetPt), leftbinJetPtSignImpXYZ, rightbinJetPtSignImpXYZ));

      int leftbinJetPtImpXYZSig = h2dataTagjetPtImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      int rightbinJetPtImpXYZSig = h2dataTagjetPtImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
      TH1F* projJetPtRangeImpXYZSig  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZSig->ProjectionY(Form("projJetPtRangeImpXYZSig_%d", binJetPt), leftbinJetPtImpXYZSig, rightbinJetPtImpXYZSig));

      hdatajetImpXYZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZ->Clone(Form("hdatajetImpXYZ_%d", binJetPt)));
      hdatajetSignImpXYZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZ->Clone(Form("hdatajetSignImpXYZ_%d", binJetPt)));
      hdatajetImpXYZSig[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZSig->Clone(Form("hdatajetImpXYZSig_%d", binJetPt)));
      leftbinJetPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
      rightbinJetPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
    }
    for (int binTrackPt =1; binTrackPt<HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
      if (fillIPxy) {
        int leftbinTrackPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
        int rightbinTrackPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
        TH1F* projJetPtRangeTrackPtRangeSignImpXYSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpXYSig_%d_%d", binJetPt, binTrackPt), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, leftbinTrackPtSignImpXYSig, rightbinTrackPtSignImpXYSig));
        hdatajetSignImpXYSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpXYSig->Clone(Form("hdatajetSignImpXYSig_%d_%d", binJetPt, binTrackPt)));
      }
      if (fillIPz) {
        int leftbinTrackPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
        int rightbinTrackPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
        TH1F* projJetPtRangeTrackPtRangeSignImpZSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpZSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpZSig_%d_%d", binJetPt, binTrackPt), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, leftbinTrackPtSignImpZSig, rightbinTrackPtSignImpZSig));
        hdatajetSignImpZSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpZSig->Clone(Form("hdatajetSignImpZSig_%d_%d", binJetPt, binTrackPt)));
      }
      if (fillIPxyz) {
        int leftbinTrackPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
        int rightbinTrackPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
        TH1F* projJetPtRangeTrackPtRangeSignImpXYZSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYZSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpXYZSig_%d_%d", binJetPt, binTrackPt), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, leftbinTrackPtSignImpXYZSig, rightbinTrackPtSignImpXYZSig));
        hdatajetSignImpXYZSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpXYZSig->Clone(Form("hdatajetSignImpXYZSig_%d_%d", binJetPt, binTrackPt)));
      }
    }
  }
}

void HfJetTaggingAnalysis::rebinHistIPData() {
}

void HfJetTaggingAnalysis::initIPData(TString rootData) {
  loadDataIP(rootData.Data());
  initHistIPData();
  projectionHistIPData();
  //rebinHistDataIPData();
}

int HfJetTaggingAnalysis::loadSimIP(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, Flavour IP QA) not found!" << std::endl;
    return 0;
  }
  TString taskTagQa = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  if (fillMCD) {
    h3simjetPtTrackPtFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskTagQa.Data())));
    h3simjetPtTrackEtaFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskTagQa.Data())));
    h3simjetPtTrackPhiFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskTagQa.Data())));
    h3simjetPtTrackPtFlavour->Sumw2();
    h3simjetPtTrackEtaFlavour->Sumw2();
    h3simjetPtTrackPhiFlavour->Sumw2();
    if (fillIPxy) {
      h3simjetPtImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simjetPtImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simTagtrackPtImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simTagtrackPtImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simTagtrackPtSignImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_sign_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simTagtrackPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_sign_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simjetPtImpXYFlavour->Sumw2();
      h3simjetPtImpXYSigFlavour->Sumw2();
      h3simjetPtSignImpXYFlavour->Sumw2();
      h3simjetPtSignImpXYSigFlavour->Sumw2();
      h3simTagtrackPtImpXYFlavour->Sumw2();
      h3simTagtrackPtImpXYSigFlavour->Sumw2();
      h3simTagtrackPtSignImpXYFlavour->Sumw2();
      h3simTagtrackPtSignImpXYSigFlavour->Sumw2();
    }
    if (fillIPz) {
      h3simjetPtImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_flavour", taskTagQa.Data())));
      h3simjetPtImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_significance_flavour", taskTagQa.Data())));
      h3simjetPtSignImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_flavour", taskTagQa.Data())));
      h3simjetPtSignImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_significance_flavour", taskTagQa.Data())));
      h3simjetPtImpZFlavour->Sumw2();
      h3simjetPtImpZSigFlavour->Sumw2();
      h3simjetPtSignImpZFlavour->Sumw2();
      h3simjetPtSignImpZSigFlavour->Sumw2();
    }
    if (fillIPxyz) {
      h3simjetPtImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_flavour", taskTagQa.Data())));
      h3simjetPtImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
      h3simjetPtImpXYZFlavour->Sumw2();
      h3simjetPtImpXYZSigFlavour->Sumw2();
      h3simjetPtSignImpXYZFlavour->Sumw2();
      h3simjetPtSignImpXYZSigFlavour->Sumw2();
    }
  }

  if (fillMCP) {
    h2simpartjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_part_flavour", taskTagQa.Data())));
    h2simpartjetEtaFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_part_flavour", taskTagQa.Data())));
    h2simpartjetPhiFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_part_flavour", taskTagQa.Data())));
    h2simpartjetPtFlavour->Sumw2();
    h2simpartjetEtaFlavour->Sumw2();
    h2simpartjetPhiFlavour->Sumw2();
    if (fillTest) {
      h3simpartjetPtCompareFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_compare_part_flavour_flavour_run2", taskTagQa.Data())));
      h3simpartjetPtCompareFlavour->Sumw2();
    }
  }

  if (fillMatched) {
    h3simjetPtpartjetPtMatchedFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_jet_pt_part_matchedgeo_flavour", taskTagQa.Data())));
    h3simjetPtpartjetPtMatchedFlavour->Sumw2();
    std::cout << "Load completed Flavour MC data" << std::endl;
  }
  return 1;
}

void HfJetTaggingAnalysis::initHistIPMC() {
  if (fillMCD) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        hsimjetTrackPt[flavour][jetPt] = new TH1F(Form("hsimjetTrackPt_%d_%d", flavour, jetPt), "", h3simjetPtTrackPtFlavour->GetNbinsY(), h3simjetPtTrackPtFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPtFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPtFlavour->GetNbinsY()));
        hsimjetTrackEta[flavour][jetPt] = new TH1F(Form("hsimjetTrackEta_%d_%d", flavour, jetPt), "", h3simjetPtTrackEtaFlavour->GetNbinsY(), h3simjetPtTrackEtaFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackEtaFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtTrackEtaFlavour->GetNbinsY()));
        hsimjetTrackPhi[flavour][jetPt] = new TH1F(Form("hsimjetTrackPhi_%d_%d", flavour, jetPt), "", h3simjetPtTrackPhiFlavour->GetNbinsY(), h3simjetPtTrackPhiFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtTrackPhiFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtTrackPhiFlavour->GetNbinsY()));
        if (fillIPxy) {
          hsimjetImpXY[flavour][jetPt] = new TH1F(Form("hsimjetImpXY_%d_%d", flavour, jetPt), "", h3simjetPtImpXYFlavour->GetNbinsY(), h3simjetPtImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYFlavour->GetNbinsY()));
          hsimjetSignImpXY[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXY_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYFlavour->GetNbinsY(), h3simjetPtSignImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYFlavour->GetNbinsY()));
          hsimjetImpXYSig[flavour][jetPt] = new TH1F(Form("hsimjetImpXYSig_%d_%d", flavour, jetPt), "", h3simjetPtImpXYSigFlavour->GetNbinsY(), h3simjetPtImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYSigFlavour->GetNbinsY()));
          hsimjetSignImpXYSig[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYSigFlavour->GetNbinsY(), h3simjetPtSignImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour->GetNbinsY()));
          hsimtrackImpXY[flavour][jetPt] = new TH1F(Form("hsimtrackImpXY_%d_%d", flavour, jetPt), "", h3simTagtrackPtImpXYFlavour->GetNbinsY(), h3simTagtrackPtImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagtrackPtImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simTagtrackPtImpXYFlavour->GetNbinsY()));
          hsimtrackSignImpXY[flavour][jetPt] = new TH1F(Form("hsimtrackSignImpXY_%d_%d", flavour, jetPt), "", h3simTagtrackPtSignImpXYFlavour->GetNbinsY(), h3simTagtrackPtSignImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagtrackPtSignImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simTagtrackPtSignImpXYFlavour->GetNbinsY()));
          hsimtrackImpXYSig[flavour][jetPt] = new TH1F(Form("hsimtrackImpXYSig_%d_%d", flavour, jetPt), "", h3simTagtrackPtImpXYSigFlavour->GetNbinsY(), h3simTagtrackPtImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagtrackPtImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagtrackPtImpXYSigFlavour->GetNbinsY()));
          hsimtrackSignImpXYSig[flavour][jetPt] = new TH1F(Form("hsimtrackSignImpXYSig_%d_%d", flavour, jetPt), "", h3simTagtrackPtSignImpXYSigFlavour->GetNbinsY(), h3simTagtrackPtSignImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagtrackPtSignImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagtrackPtSignImpXYSigFlavour->GetNbinsY()));
        }
        if (fillIPz) {
          hsimjetImpZ[flavour][jetPt] = new TH1F(Form("hsimjetImpZ_%d_%d", flavour, jetPt), "", h3simjetPtImpZFlavour->GetNbinsY(), h3simjetPtImpZFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpZFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtImpZFlavour->GetNbinsY()));
          hsimjetSignImpZ[flavour][jetPt] = new TH1F(Form("hsimjetSignImpZ_%d_%d", flavour, jetPt), "", h3simjetPtSignImpZFlavour->GetNbinsY(), h3simjetPtSignImpZFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZFlavour->GetNbinsY()));
          hsimjetImpZSig[flavour][jetPt] = new TH1F(Form("hsimjetImpZSig_%d_%d", flavour, jetPt), "", h3simjetPtImpZSigFlavour->GetNbinsY(), h3simjetPtImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtImpZSigFlavour->GetNbinsY()));
          hsimjetSignImpZSig[flavour][jetPt] = new TH1F(Form("hsimjetSignImpZSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpZSigFlavour->GetNbinsY(), h3simjetPtSignImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigFlavour->GetNbinsY()));
        }
        if (fillIPxyz) {
          hsimjetImpXYZ[flavour][jetPt] = new TH1F(Form("hsimjetImpXYZ_%d_%d", flavour, jetPt), "", h3simjetPtImpXYZFlavour->GetNbinsY(), h3simjetPtImpXYZFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYZFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYZFlavour->GetNbinsY()));
          hsimjetSignImpXYZ[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYZ_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYZFlavour->GetNbinsY(), h3simjetPtSignImpXYZFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZFlavour->GetNbinsY()));
          hsimjetImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimjetImpXYZSig_%d_%d", flavour, jetPt), "", h3simjetPtImpXYZSigFlavour->GetNbinsY(), h3simjetPtImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYZSigFlavour->GetNbinsY()));
          hsimjetSignImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYZSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYZSigFlavour->GetNbinsY(), h3simjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigFlavour->GetNbinsY()));
        }
      }
      if (fillMatched) {
        hsimjetPtMatched[flavour] = new TH1F(Form("hsimjetPtMatched_%d", flavour), "", h3simjetPtpartjetPtMatchedFlavour->GetNbinsX(), h3simjetPtpartjetPtMatchedFlavour->GetXaxis()->GetBinLowEdge(1), h3simjetPtpartjetPtMatchedFlavour->GetXaxis()->GetBinUpEdge(h3simjetPtpartjetPtMatchedFlavour->GetNbinsX()));
        hsimpartjetPtMatched[flavour] = new TH1F(Form("hsimpartjetPtMatched_%d", flavour), "", h3simjetPtpartjetPtMatchedFlavour->GetNbinsY(), h3simjetPtpartjetPtMatchedFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtpartjetPtMatchedFlavour->GetYaxis()->GetBinUpEdge(h3simjetPtpartjetPtMatchedFlavour->GetNbinsY()));
        h2simjetPtpartjetPtMatched[flavour] = new TH2F(Form("h2simjetPtpartjetPtMatched_%d", flavour), "", h3simjetPtpartjetPtMatchedFlavour->GetNbinsX(), h3simjetPtpartjetPtMatchedFlavour->GetXaxis()->GetBinLowEdge(1), h3simjetPtpartjetPtMatchedFlavour->GetNbinsX(), h3simjetPtpartjetPtMatchedFlavour->GetNbinsY(), h3simjetPtpartjetPtMatchedFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtpartjetPtMatchedFlavour->GetNbinsY());
        h2simpartjetPtjetPtMatched[flavour] = new TH2F(Form("h2simpartjetPtjetPtMatched_%d", flavour), "", h3simjetPtpartjetPtMatchedFlavour->GetNbinsY(), h3simjetPtpartjetPtMatchedFlavour->GetYaxis()->GetBinLowEdge(1), h3simjetPtpartjetPtMatchedFlavour->GetNbinsY(), h3simjetPtpartjetPtMatchedFlavour->GetNbinsX(), h3simjetPtpartjetPtMatchedFlavour->GetXaxis()->GetBinLowEdge(1), h3simjetPtpartjetPtMatchedFlavour->GetNbinsX());
      }
    }
  }
  if (fillMCP) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimpartjetPt[flavour] = new TH1F(Form("hsimpartjetPt_%d", flavour), "", h2simpartjetPtFlavour->GetNbinsX(), h2simpartjetPtFlavour->GetXaxis()->GetBinLowEdge(1), h2simpartjetPtFlavour->GetXaxis()->GetBinUpEdge(h2simpartjetPtFlavour->GetNbinsX()));
      hsimpartjetEta[flavour] = new TH1F(Form("hsimpartjetEta_%d", flavour), "", h2simpartjetEtaFlavour->GetNbinsX(), h2simpartjetEtaFlavour->GetXaxis()->GetBinLowEdge(1), h2simpartjetEtaFlavour->GetXaxis()->GetBinUpEdge(h2simpartjetEtaFlavour->GetNbinsX()));
      hsimpartjetPhi[flavour] = new TH1F(Form("hsimpartjetPhi_%d", flavour), "", h2simpartjetPhiFlavour->GetNbinsX(), h2simpartjetPhiFlavour->GetXaxis()->GetBinLowEdge(1), h2simpartjetPhiFlavour->GetXaxis()->GetBinUpEdge(h2simpartjetPhiFlavour->GetNbinsX()));
      if (fillTest) {
        hsimpartFlavourMatchingEffi[flavour] = new TH1F(Form("hsimpartFlavourMatchingEffi_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimpartCharmJetMatchingEffi[flavour] = new TH1F(Form("hsimpartCharmMatchingEffi_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimpartBeautyJetMatchingEffi[flavour] = new TH1F(Form("hsimpartBeautyMatchingEffi_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
        hsimpartLfJetMatchingEffi[flavour] = new TH1F(Form("hsimpartLfMatchingEffi_%d", flavour), "", HfJetTagging::nBinsJetPt, HfJetTagging::binsJetPt);
      }
    }
  }
}

void HfJetTaggingAnalysis::projectionHistIPMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  if (fillMCD) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour->ProjectionY(Form("projTrackPt_%d", binFlavour), 1, h3simjetPtTrackPtFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3simjetPtTrackEtaFlavour->ProjectionY(Form("projTrackEta_%d", binFlavour), 1, h3simjetPtTrackEtaFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3simjetPtTrackPhiFlavour->ProjectionY(Form("projTrackPhi_%d", binFlavour), 1, h3simjetPtTrackPhiFlavour->GetNbinsX(), binFlavour, binFlavour));
      hsimjetTrackPt[0][0]->Add(projTrackPt);
      hsimjetTrackEta[0][0]->Add(projTrackEta);
      hsimjetTrackPhi[0][0]->Add(projTrackPhi);
      hsimjetTrackPt[flavour][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone(Form("hsimjetTrackPt_%d_0", flavour)));
      hsimjetTrackEta[flavour][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone(Form("hsimjetTrackEta_%d_0", flavour)));
      hsimjetTrackPhi[flavour][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone(Form("hsimjetTrackPhi_%d_0", flavour)));
      if (fillMatched) {
        TH3F* h3simjetPtpartjetPtmatchedbinbyFlavour = reinterpret_cast<TH3F*> (h3simjetPtpartjetPtMatchedFlavour->Clone());
        h3simjetPtpartjetPtmatchedbinbyFlavour->GetZaxis()->SetRange(binFlavour, binFlavour);
        TH2F* projJetPtpartJetPtMatched = reinterpret_cast<TH2F*> (h3simjetPtpartjetPtmatchedbinbyFlavour->Project3D("yx"));
        TH2F* projpartJetPtJetPtMatched = reinterpret_cast<TH2F*> (h3simjetPtpartjetPtmatchedbinbyFlavour->Project3D("xy"));
        TH1F* projJetPtMatched = reinterpret_cast<TH1F*> (h3simjetPtpartjetPtMatchedFlavour->ProjectionX(Form("projJetPtMatched_%d", binFlavour), 1, h3simjetPtpartjetPtMatchedFlavour->GetNbinsY(), binFlavour, binFlavour));
        TH1F* projpartJetPtMatched = reinterpret_cast<TH1F*> (h3simjetPtpartjetPtMatchedFlavour->ProjectionY(Form("projpartJetPtMatched_%d", binFlavour), 1, h3simjetPtpartjetPtMatchedFlavour->GetNbinsX(), binFlavour, binFlavour));
        h2simjetPtpartjetPtMatched[0]->Add(projJetPtpartJetPtMatched);
        h2simpartjetPtjetPtMatched[0]->Add(projpartJetPtJetPtMatched);
        hsimjetPtMatched[0]->Add(projJetPtMatched);
        hsimpartjetPtMatched[0]->Add(projpartJetPtMatched);
        h2simjetPtpartjetPtMatched[flavour] = reinterpret_cast<TH2F*>(projJetPtpartJetPtMatched->Clone(Form("h2simjetPtpartjetPtMatched_%d", flavour)));
        h2simpartjetPtjetPtMatched[flavour] = reinterpret_cast<TH2F*>(projpartJetPtJetPtMatched->Clone(Form("h2simpartjetPtjetPtMatched_%d", flavour)));
        hsimjetPtMatched[flavour] = reinterpret_cast<TH1F*>(projJetPtMatched->Clone(Form("hsimjetPtMatched_%d", flavour)));
        hsimpartjetPtMatched[flavour] = reinterpret_cast<TH1F*>(projpartJetPtMatched->Clone(Form("hsimpartjetPtMatched_%d", flavour)));
      }
      if (fillIPxy) {
        TH1F* projImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavour->ProjectionY(Form("projImpXY_%d", binFlavour), 1, h3simjetPtImpXYFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYFlavour->ProjectionY(Form("projSignImpXY_%d", binFlavour), 1, h3simjetPtSignImpXYFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYSigFlavour->ProjectionY(Form("projImpXYSig_%d", binFlavour), 1, h3simjetPtImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binFlavour), 1, h3simjetPtSignImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projImpXYForTrackPt = reinterpret_cast<TH1F*> (h3simTagtrackPtImpXYFlavour->ProjectionY(Form("projImpXY_%d", binFlavour), 1, h3simTagtrackPtImpXYFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYForTrackPt = reinterpret_cast<TH1F*> (h3simTagtrackPtSignImpXYFlavour->ProjectionY(Form("projSignImpXY_%d", binFlavour), 1, h3simTagtrackPtSignImpXYFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projImpXYSigForTrackPt = reinterpret_cast<TH1F*> (h3simTagtrackPtImpXYSigFlavour->ProjectionY(Form("projImpXYSig_%d", binFlavour), 1, h3simTagtrackPtImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSigForTrackPt = reinterpret_cast<TH1F*> (h3simTagtrackPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binFlavour), 1, h3simTagtrackPtSignImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjetImpXY[0][0]->Add(projImpXY);
        hsimjetSignImpXY[0][0]->Add(projSignImpXY);
        hsimjetImpXYSig[0][0]->Add(projImpXYSig);
        hsimjetSignImpXYSig[0][0]->Add(projSignImpXYSig);
        hsimtrackImpXY[0][0]->Add(projImpXYForTrackPt);
        hsimtrackSignImpXY[0][0]->Add(projSignImpXYForTrackPt);
        hsimtrackImpXYSig[0][0]->Add(projImpXYSigForTrackPt);
        hsimtrackSignImpXYSig[0][0]->Add(projSignImpXYSigForTrackPt);
        hsimjetImpXY[flavour][0] = reinterpret_cast<TH1F*>(projImpXY->Clone(Form("hsimjetImpXY_%d_0", flavour)));
        hsimjetSignImpXY[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone(Form("hsimjetSignImpXY_%d_0", flavour)));
        hsimjetImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone(Form("hsimjetImpXYSig_%d_0", flavour)));
        hsimjetSignImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone());
        hsimtrackImpXY[flavour][0] = reinterpret_cast<TH1F*>(projImpXYForTrackPt->Clone(Form("hsimtrackImpXYForTrackPt_%d_0", flavour)));
        hsimtrackSignImpXY[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYForTrackPt->Clone(Form("hsimtrackSignImpXYForTrackPt_%d_0", flavour)));
        hsimtrackImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projImpXYSigForTrackPt->Clone(Form("hsimtrackImpXYSigForTrackPt_%d_0", flavour)));
        hsimtrackSignImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigForTrackPt->Clone());
      }
      if (fillIPz) {
        TH1F* projImpZ = reinterpret_cast<TH1F*> (h3simjetPtImpZFlavour->ProjectionY(Form("projImpZ_%d", binFlavour), 1, h3simjetPtImpZFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZ = reinterpret_cast<TH1F*> (h3simjetPtSignImpZFlavour->ProjectionY(Form("projSignImpZ_%d", binFlavour), 1, h3simjetPtSignImpZFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projImpZSig = reinterpret_cast<TH1F*> (h3simjetPtImpZSigFlavour->ProjectionY(Form("projImpZSig_%d", binFlavour), 1, h3simjetPtImpZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigFlavour->ProjectionY(Form("projSignImpZSig_%d", binFlavour), 1, h3simjetPtSignImpZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjetImpZ[0][0]->Add(projImpZ);
        hsimjetSignImpZ[0][0]->Add(projSignImpZ);
        hsimjetImpZSig[0][0]->Add(projImpZSig);
        hsimjetSignImpZSig[0][0]->Add(projSignImpZSig);
        hsimjetImpZ[flavour][0] = reinterpret_cast<TH1F*>(projImpZ->Clone());
        hsimjetSignImpZ[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZ->Clone());
        hsimjetImpZSig[flavour][0] = reinterpret_cast<TH1F*>(projImpZSig->Clone());
        hsimjetSignImpZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone());
      }
      if (fillIPxyz) {
        TH1F* projImpXYZ = reinterpret_cast<TH1F*> (h3simjetPtImpXYZFlavour->ProjectionY(Form("projImpXYZ_%d", binFlavour), 1, h3simjetPtImpXYZFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZ = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZFlavour->ProjectionY(Form("projSignImpXYZ_%d", binFlavour), 1, h3simjetPtSignImpXYZFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projImpXYZSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYZSigFlavour->ProjectionY(Form("projImpXYZSig_%d", binFlavour), 1, h3simjetPtImpXYZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigFlavour->ProjectionY(Form("projSignImpXYZSig_%d", binFlavour), 1, h3simjetPtSignImpXYZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
        hsimjetImpXYZ[0][0]->Add(projImpXYZ);
        hsimjetSignImpXYZ[0][0]->Add(projSignImpXYZ);
        hsimjetImpXYZSig[0][0]->Add(projImpXYZSig);
        hsimjetSignImpXYZSig[0][0]->Add(projSignImpXYZSig);
        hsimjetImpXYZ[flavour][0] = reinterpret_cast<TH1F*>(projImpXYZ->Clone());
        hsimjetSignImpXYZ[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZ->Clone());
        hsimjetImpXYZSig[flavour][0] = reinterpret_cast<TH1F*>(projImpXYZSig->Clone());
        hsimjetSignImpXYZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone());
      }

      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        int leftbinJetPtTrackPt = h3simjetPtTrackPtFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtTrackPt = h3simjetPtTrackPtFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour->ProjectionY(Form("projJetPtRangeTrackPt_%d_%d", binJetPt, binFlavour), leftbinJetPtTrackPt, rightbinJetPtTrackPt, binFlavour, binFlavour));
        hsimjetTrackPt[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPt->Clone(Form("hsimjetTrackPt_%d_%d", flavour, binJetPt))); 
        hsimjetTrackPt[0][binJetPt]->Add(projJetPtRangeTrackPt);

        int leftbinJetPtTrackEta = h3simjetPtTrackEtaFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtTrackEta = h3simjetPtTrackEtaFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simjetPtTrackEtaFlavour->ProjectionY(Form("projJetPtRangeTrackEta_%d_%d", binFlavour, binJetPt), leftbinJetPtTrackEta, rightbinJetPtTrackEta, binFlavour, binFlavour));
        hsimjetTrackEta[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackEta->Clone(Form("hsimjetTrackEta_%d_%d", flavour, binJetPt)));
        hsimjetTrackEta[0][binJetPt]->Add(projJetPtRangeTrackEta);

        int leftbinJetPtTrackPhi = h3simjetPtTrackPhiFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtTrackPhi = h3simjetPtTrackPhiFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simjetPtTrackPhiFlavour->ProjectionY(Form("projJetPtRangeTrackPhi_%d_%d", binJetPt, binFlavour), leftbinJetPtTrackPhi, rightbinJetPtTrackPhi, binFlavour, binFlavour));
        hsimjetTrackPhi[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPhi->Clone());
        hsimjetTrackPhi[0][binJetPt]->Add(projJetPtRangeTrackPhi);

        if (fillIPxy) {
          int leftbinJetPtImpXY = h3simjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpXY = h3simjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavour->ProjectionY(Form("projJetPtRagneImpXY_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXY, rightbinJetPtImpXY, binFlavour, binFlavour));
          hsimjetImpXY[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone());
          hsimjetImpXY[0][binJetPt]->Add(projJetPtRangeImpXY);

          int leftbinJetPtSignImpXY = h3simjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXY = h3simjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXY = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYFlavour->ProjectionY(Form("projJetPtRagneSignImpXY_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY, binFlavour, binFlavour));
          hsimjetSignImpXY[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone());
          hsimjetSignImpXY[0][binJetPt]->Add(projJetPtRangeSignImpXY);

          int leftbinJetPtImpXYSig = h3simjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpXYSig = h3simjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYSigFlavour->ProjectionY(Form("projJetPtRagneImpXYSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig, binFlavour, binFlavour));
          hsimjetImpXYSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone());
          hsimjetImpXYSig[0][binJetPt]->Add(projJetPtRangeImpXYSig);

          int leftbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binFlavour, binFlavour));
          hsimjetSignImpXYSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone());
          hsimjetSignImpXYSig[0][binJetPt]->Add(projJetPtRangeSignImpXYSig);
        }
        if (fillIPz) {

          int leftbinJetPtImpZ = h3simjetPtImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpZ = h3simjetPtImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpZ = reinterpret_cast<TH1F*>(h3simjetPtImpZFlavour->ProjectionY(Form("projJetPtRagneImpZ_%d_%d", binJetPt, binFlavour), leftbinJetPtImpZ, rightbinJetPtImpZ, binFlavour, binFlavour));
          hsimjetImpZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZ->Clone());
          hsimjetImpZ[0][binJetPt]->Add(projJetPtRangeImpZ);

          int leftbinJetPtSignImpZ = h3simjetPtSignImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZ = h3simjetPtSignImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZ = reinterpret_cast<TH1F*>(h3simjetPtSignImpZFlavour->ProjectionY(Form("projJetPtRagneSignImpZ_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZ, rightbinJetPtSignImpZ, binFlavour, binFlavour));
          hsimjetSignImpZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZ->Clone());
          hsimjetSignImpZ[0][binJetPt]->Add(projJetPtRangeSignImpZ);
          int leftbinJetPtImpZSig = h3simjetPtImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpZSig = h3simjetPtImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpZSig = reinterpret_cast<TH1F*>(h3simjetPtImpZSigFlavour->ProjectionY(Form("projJetPtRagneImpZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpZSig, rightbinJetPtImpZSig, binFlavour, binFlavour));
          hsimjetImpZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZSig->Clone());
          hsimjetImpZSig[0][binJetPt]->Add(projJetPtRangeImpZSig);

          int leftbinJetPtSignImpZSig = h3simjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpZSig = h3simjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpZSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, binFlavour, binFlavour));
          hsimjetSignImpZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSig->Clone());
          hsimjetSignImpZSig[0][binJetPt]->Add(projJetPtRangeSignImpZSig);


        }
        if (fillIPxyz) {

          int leftbinJetPtImpXYZ = h3simjetPtImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpXYZ = h3simjetPtImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpXYZ = reinterpret_cast<TH1F*>(h3simjetPtImpXYZFlavour->ProjectionY(Form("projJetPtRagneImpXYZ_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYZ, rightbinJetPtImpXYZ, binFlavour, binFlavour));
          hsimjetImpXYZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZ->Clone());
          hsimjetImpXYZ[0][binJetPt]->Add(projJetPtRangeImpXYZ);

          int leftbinJetPtSignImpXYZ = h3simjetPtSignImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZ = h3simjetPtSignImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZ = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZ_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZ, rightbinJetPtSignImpXYZ, binFlavour, binFlavour));
          hsimjetSignImpXYZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZ->Clone());
          hsimjetSignImpXYZ[0][binJetPt]->Add(projJetPtRangeSignImpXYZ);
          int leftbinJetPtImpXYZSig = h3simjetPtImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpXYZSig = h3simjetPtImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpXYZSig = reinterpret_cast<TH1F*>(h3simjetPtImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneImpXYZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYZSig, rightbinJetPtImpXYZSig, binFlavour, binFlavour));
          hsimjetImpXYZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZSig->Clone());
          hsimjetImpXYZSig[0][binJetPt]->Add(projJetPtRangeImpXYZSig);

          int leftbinJetPtSignImpXYZSig = h3simjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYZSig = h3simjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYZSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, binFlavour, binFlavour));
          hsimjetSignImpXYZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSig->Clone());
          hsimjetSignImpXYZSig[0][binJetPt]->Add(projJetPtRangeSignImpXYZSig);


        }
      }
      if (fillIPxy) {
        for (int binTrackPt =1; binTrackPt<HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
          int leftbinTrackPtImpXY = h3simjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
          int rightbinTrackPtImpXY = h3simjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
          TH1F* projTrackPtRangeImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavour->ProjectionY(Form("projTrackPtRagneImpXY_%d_%d", binTrackPt, binFlavour), leftbinTrackPtImpXY, rightbinTrackPtImpXY, binFlavour, binFlavour));
          hsimtrackImpXY[flavour][binTrackPt] = reinterpret_cast<TH1F*>(projTrackPtRangeImpXY->Clone());
          hsimtrackImpXY[0][binTrackPt]->Add(projTrackPtRangeImpXY);

          int leftbinTrackPtSignImpXY = h3simjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
          int rightbinTrackPtSignImpXY = h3simjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
          TH1F* projTrackPtRangeSignImpXY = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYFlavour->ProjectionY(Form("projTrackPtRagneSignImpXY_%d_%d", binTrackPt, binFlavour), leftbinTrackPtSignImpXY, rightbinTrackPtSignImpXY, binFlavour, binFlavour));
          hsimtrackSignImpXY[flavour][binTrackPt] = reinterpret_cast<TH1F*>(projTrackPtRangeSignImpXY->Clone());
          hsimtrackSignImpXY[0][binTrackPt]->Add(projTrackPtRangeSignImpXY);

          int leftbinTrackPtImpXYSig = h3simjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
          int rightbinTrackPtImpXYSig = h3simjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
          TH1F* projTrackPtRangeImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYSigFlavour->ProjectionY(Form("projTrackPtRagneImpXYSig_%d_%d", binTrackPt, binFlavour), leftbinTrackPtImpXYSig, rightbinTrackPtImpXYSig, binFlavour, binFlavour));
          hsimtrackImpXYSig[flavour][binTrackPt] = reinterpret_cast<TH1F*>(projTrackPtRangeImpXYSig->Clone());
          hsimtrackImpXYSig[0][binTrackPt]->Add(projTrackPtRangeImpXYSig);

          int leftbinTrackPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
          int rightbinTrackPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
          TH1F* projTrackPtRangeSignImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour->ProjectionY(Form("projTrackPtRagneSignImpXYSig_%d_%d", binTrackPt, binFlavour), leftbinTrackPtSignImpXYSig, rightbinTrackPtSignImpXYSig, binFlavour, binFlavour));
          hsimtrackSignImpXYSig[flavour][binTrackPt] = reinterpret_cast<TH1F*>(projTrackPtRangeSignImpXYSig->Clone());
          hsimtrackSignImpXYSig[0][binTrackPt]->Add(projTrackPtRangeSignImpXYSig);
        }
      }
    }
  }
  if (fillMCP) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      TH1F* projpartJetPt = reinterpret_cast<TH1F*> (h2simpartjetPtFlavour->ProjectionX(Form("projpartJetPt_%d", binFlavour), binFlavour, binFlavour));
      TH1F* projpartJetEta = reinterpret_cast<TH1F*> (h2simpartjetEtaFlavour->ProjectionX(Form("projpartJetEta_%d", binFlavour), binFlavour, binFlavour));
      TH1F* projpartJetPhi = reinterpret_cast<TH1F*> (h2simpartjetPhiFlavour->ProjectionX(Form("projpartJetPhi_%d", binFlavour), binFlavour, binFlavour));
      hsimpartjetPt[0]->Add(projpartJetPt);
      hsimpartjetEta[0]->Add(projpartJetEta);
      hsimpartjetPhi[0]->Add(projpartJetPhi);
      hsimpartjetPt[flavour] = reinterpret_cast<TH1F*>(projpartJetPt->Clone(Form("hsimpartjetPt_%d", flavour)));
      hsimpartjetEta[flavour] = reinterpret_cast<TH1F*>(projpartJetPt->Clone(Form("hsimpartjetEta_%d", flavour)));
      hsimpartjetPhi[flavour] = reinterpret_cast<TH1F*>(projpartJetPt->Clone(Form("hsimpartjetPhi_%d", flavour)));

      for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (fillTest) {
          int leftbinJetPtMatchedFlavour = h3simpartjetPtCompareFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtMatchedFlavour = h3simpartjetPtCompareFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projMatchedFlavour = reinterpret_cast<TH1F*> (h3simpartjetPtCompareFlavour->ProjectionY(Form("projMatchedFlavour_%d_%d", binJetPt, binFlavour), leftbinJetPtMatchedFlavour, rightbinJetPtMatchedFlavour, binFlavour, binFlavour));
          hsimpartFlavourMatchedFlavour[flavour][binJetPt] = reinterpret_cast<TH1F*>(projMatchedFlavour->Clone());
        }
      }
    }
  }
}

void HfJetTaggingAnalysis::rebinHistIPMC() {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    if (fillMatched) {
      hsimjetPtMatchedRebin[flavour] = (TH1F*) hsimjetPtMatched[flavour]->Rebin(unfold::nBinsMCDJetPt, "", unfold::binsMCDJetPt);
      hsimpartjetPtMatchedRebin[flavour] = (TH1F*) hsimpartjetPtMatched[flavour]->Rebin(unfold::nBinsMCPJetPt, "", unfold::binsMCPJetPt);
      h2simjetPtpartjetPtMatchedRebin[flavour] = new TH2F();
      taggingutilities::rebin2DHist(h2simjetPtpartjetPtMatched[flavour], h2simjetPtpartjetPtMatchedRebin[flavour], unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
      h2simpartjetPtjetPtMatchedRebin[flavour] = new TH2F();
      taggingutilities::rebin2DHist(h2simpartjetPtjetPtMatched[flavour], h2simpartjetPtjetPtMatchedRebin[flavour], unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
    }
  }
}

void HfJetTaggingAnalysis::initIPMC(TString rootSim) {
  loadSimIP(rootSim.Data());
  initHistIPMC();
  projectionHistIPMC();
  rebinHistIPMC();
}

int HfJetTaggingAnalysis::loadPOWHEGFile(TString rootFile) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (Model) not found!" << std::endl;
    return 0;
  }
  TFile* fin;
  fin = TFile::Open(rootFile.Data(), "READ");
  hpwhgNEvent = reinterpret_cast<TH1F*>(fin->Get("hNEvent"));
  hpwhgInclusiveJetXSection_R2 = reinterpret_cast<TH1F*>(fin->Get("InclusiveJetXSection_R2"));
  hpwhgBkgSubtractedJetXSection_R2 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedJetXSection_R2"));
  hpwhgBJetXSection_R2 = reinterpret_cast<TH1F*>(fin->Get("BJetXSection_R2"));
  hpwhgBkgSubtractedBJetXSection_R2 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedBJetXSection_R2"));
  hpwhgCJetXSection_R2 = reinterpret_cast<TH1F*>(fin->Get("CJetXSection_R2"));
  hpwhgBkgSubtractedCJetXSection_R2 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedCJetXSection_R2"));
  hpwhgInclusiveJetXSection_R3 = reinterpret_cast<TH1F*>(fin->Get("InclusiveJetXSection_R3"));
  hpwhgBkgSubtractedJetXSection_R3 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedJetXSection_R3"));
  hpwhgBJetXSection_R3 = reinterpret_cast<TH1F*>(fin->Get("BJetXSection_R3"));
  hpwhgBkgSubtractedBJetXSection_R3 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedBJetXSection_R3"));
  hpwhgCJetXSection_R3 = reinterpret_cast<TH1F*>(fin->Get("CJetXSection_R3"));
  hpwhgBkgSubtractedCJetXSection_R3 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedCJetXSection_R3"));
  hpwhgInclusiveJetXSection_R4 = reinterpret_cast<TH1F*>(fin->Get("InclusiveJetXSection_R4"));
  hpwhgBkgSubtractedJetXSection_R4 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedJetXSection_R4"));
  hpwhgBJetXSection_R4 = reinterpret_cast<TH1F*>(fin->Get("BJetXSection_R4"));
  hpwhgBkgSubtractedBJetXSection_R4 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedBJetXSection_R4"));
  hpwhgCJetXSection_R4 = reinterpret_cast<TH1F*>(fin->Get("CJetXSection_R4"));
  hpwhgBkgSubtractedCJetXSection_R4 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedCJetXSection_R4"));
  hpwhgInclusiveJetXSection_R5 = reinterpret_cast<TH1F*>(fin->Get("InclusiveJetXSection_R5"));
  hpwhgBkgSubtractedJetXSection_R5 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedJetXSection_R5"));
  hpwhgBJetXSection_R5 = reinterpret_cast<TH1F*>(fin->Get("BJetXSection_R5"));
  hpwhgBkgSubtractedBJetXSection_R5 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedBJetXSection_R5"));
  hpwhgCJetXSection_R5 = reinterpret_cast<TH1F*>(fin->Get("CJetXSection_R5"));
  hpwhgBkgSubtractedCJetXSection_R5 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedCJetXSection_R5"));
  hpwhgInclusiveJetXSection_R6 = reinterpret_cast<TH1F*>(fin->Get("InclusiveJetXSection_R6"));
  hpwhgBkgSubtractedJetXSection_R6 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedJetXSection_R6"));
  hpwhgBJetXSection_R6 = reinterpret_cast<TH1F*>(fin->Get("BJetXSection_R6"));
  hpwhgBkgSubtractedBJetXSection_R6 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedBJetXSection_R6"));
  hpwhgCJetXSection_R6 = reinterpret_cast<TH1F*>(fin->Get("CJetXSection_R6"));
  hpwhgBkgSubtractedCJetXSection_R6 = reinterpret_cast<TH1F*>(fin->Get("BkgSubtractedCJetXSection_R6"));
  TProfile* hpwhgTotalCrossSection = reinterpret_cast<TProfile*>(fin->Get("CrossSection"));
  hpwhgNumberOfTrials = reinterpret_cast<TH1F*>(fin->Get("NumberofTrials"));
  
  npwhgEvents = hpwhgNEvent->GetEntries();
  xs = hpwhgTotalCrossSection->GetBinContent(1);  // total xsec from profile
  nTrials = hpwhgNumberOfTrials->GetEntries();
  if (debug) std::cout << "xsec: " << xs << " nTrials: " << nTrials << std::endl;
  hpwhgBJetXSection_R4->Sumw2();
  hpwhgbjetCrossSection = reinterpret_cast<TH1F*> (hpwhgBJetXSection_R4->Clone("hpwhgbjetCrossSection"));
  hpwhgbjetCrossSection->Scale(1.0 / npwhgEvents);

  setLoadPOWHEG(true);
  return 1;
}

void HfJetTaggingAnalysis::rebinHistPOWHEG() {
  hpwhgInclusiveJetXSection_R2Rebin = (TH1F*) hpwhgInclusiveJetXSection_R2->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedJetXSection_R2Rebin = (TH1F*) hpwhgBkgSubtractedJetXSection_R2->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBJetXSection_R2Rebin = (TH1F*) hpwhgBJetXSection_R2->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedBJetXSection_R2Rebin = (TH1F*) hpwhgBkgSubtractedBJetXSection_R2->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgCJetXSection_R2Rebin = (TH1F*) hpwhgCJetXSection_R2->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedCJetXSection_R2Rebin = (TH1F*) hpwhgBkgSubtractedCJetXSection_R2->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);

  hpwhgInclusiveJetXSection_R3Rebin = (TH1F*) hpwhgInclusiveJetXSection_R3->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedJetXSection_R3Rebin = (TH1F*) hpwhgBkgSubtractedJetXSection_R3->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBJetXSection_R3Rebin = (TH1F*) hpwhgBJetXSection_R3->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedBJetXSection_R3Rebin = (TH1F*) hpwhgBkgSubtractedBJetXSection_R3->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgCJetXSection_R3Rebin = (TH1F*) hpwhgCJetXSection_R3->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedCJetXSection_R3Rebin = (TH1F*) hpwhgBkgSubtractedCJetXSection_R3->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);

  hpwhgInclusiveJetXSection_R4Rebin = (TH1F*) hpwhgInclusiveJetXSection_R4->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedJetXSection_R4Rebin = (TH1F*) hpwhgBkgSubtractedJetXSection_R4->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBJetXSection_R4Rebin = (TH1F*) hpwhgBJetXSection_R4->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedBJetXSection_R4Rebin = (TH1F*) hpwhgBkgSubtractedBJetXSection_R4->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgCJetXSection_R4Rebin = (TH1F*) hpwhgCJetXSection_R4->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedCJetXSection_R4Rebin = (TH1F*) hpwhgBkgSubtractedCJetXSection_R4->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);

  hpwhgInclusiveJetXSection_R5Rebin = (TH1F*) hpwhgInclusiveJetXSection_R5->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedJetXSection_R5Rebin = (TH1F*) hpwhgBkgSubtractedJetXSection_R5->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBJetXSection_R5Rebin = (TH1F*) hpwhgBJetXSection_R5->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedBJetXSection_R5Rebin = (TH1F*) hpwhgBkgSubtractedBJetXSection_R5->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgCJetXSection_R5Rebin = (TH1F*) hpwhgCJetXSection_R5->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedCJetXSection_R5Rebin = (TH1F*) hpwhgBkgSubtractedCJetXSection_R5->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);

  hpwhgInclusiveJetXSection_R6Rebin = (TH1F*) hpwhgInclusiveJetXSection_R6->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedJetXSection_R6Rebin = (TH1F*) hpwhgBkgSubtractedJetXSection_R6->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBJetXSection_R6Rebin = (TH1F*) hpwhgBJetXSection_R6->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedBJetXSection_R6Rebin = (TH1F*) hpwhgBkgSubtractedBJetXSection_R6->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgCJetXSection_R6Rebin = (TH1F*) hpwhgCJetXSection_R6->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgBkgSubtractedCJetXSection_R6Rebin = (TH1F*) hpwhgBkgSubtractedCJetXSection_R6->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);

  hpwhgbjetCrossSectionRebin = (TH1F*) hpwhgbjetCrossSection->Rebin(HfJetTagging::nBinsJetPt, "", HfJetTagging::binsJetPt);
  hpwhgbjetCrossSectionRebin->Scale(1.0, "width");
}

void HfJetTaggingAnalysis::initModel(TString rootFile) {
  loadPOWHEGFile(rootFile);
  rebinHistPOWHEG();
  std::cout << "load and completed model" << std::endl;
}

int HfJetTaggingAnalysis::loadExternalUnfold(TString rootFile) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (external response matrix file for unfolding) not found!" << std::endl;
    return 0;
  }
  TFile* fin;
  fin = TFile::Open(rootFile.Data(), "READ");
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    h2externalsimjetPtpartjetPtMatched[flavour] = reinterpret_cast<TH2F*>(fin->Get(Form("sim/resMat_%d", flavour)));
    h2externalsimpartjetPtjetPtMatched[flavour] = reinterpret_cast<TH2F*>(fin->Get(Form("sim/resMatInverse_%d", flavour)));
    h2externalsimjetPtpartjetPtMatchedNorm[flavour] = reinterpret_cast<TH2F*>(fin->Get(Form("sim/resMatNorm_%d", flavour)));
    h2externalsimpartjetPtjetPtMatchedNorm[flavour] = reinterpret_cast<TH2F*>(fin->Get(Form("sim/resMatInverseNorm_%d", flavour)));
    h2externalsimjetPtpartjetPtMatchedRebin[flavour] = reinterpret_cast<TH2F*>(fin->Get(Form("sim/resMatRebin_%d", flavour)));
    h2externalsimpartjetPtjetPtMatchedRebin[flavour] = reinterpret_cast<TH2F*>(fin->Get(Form("sim/resMatInverseRebin_%d", flavour)));
    hexternalsimjetPtMatched[flavour] = reinterpret_cast<TH1F*> (fin->Get(Form("sim/hsimjetPtMatched_%d", flavour)));
    hexternalsimjetPtMatchedRebin[flavour] = reinterpret_cast<TH1F*> (fin->Get(Form("sim/hsimjetPtMatchedRebin_%d", flavour)));
    hexternalsimpartjetPtMatched[flavour] = reinterpret_cast<TH1F*> (fin->Get(Form("sim/hsimpartjetPtMatched_%d", flavour)));
    hexternalsimpartjetPtMatchedRebin[flavour] = reinterpret_cast<TH1F*> (fin->Get(Form("sim/hsimpartjetPtMatchedRebin_%d", flavour)));
  }
  if (h2externalsimjetPtpartjetPtMatched[0]->GetEntries() > 0)
  std::cout << "loaded external hist" << std::endl;
  setLoadResMat(true);

  return 1;
}

void HfJetTaggingAnalysis::initExternalUnfold(TString rootFile) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    h2externalsimjetPtpartjetPtMatched[flavour] = new TH2F();
    h2externalsimpartjetPtjetPtMatched[flavour] = new TH2F();
    h2externalsimjetPtpartjetPtMatchedRebin[flavour] = new TH2F();
    h2externalsimpartjetPtjetPtMatchedRebin[flavour] = new TH2F();
    hexternalsimjetPtMatched[flavour] = new TH1F();
    hexternalsimjetPtMatchedRebin[flavour] = new TH1F();
    hexternalsimpartjetPtMatched[flavour] = new TH1F();
    hexternalsimpartjetPtMatchedRebin[flavour] = new TH1F();
  }
  loadExternalUnfold(rootFile);
  std::cout << "load and completed external unfold" << std::endl;
}

void HfJetTaggingAnalysis::saveHistogramIPQA(TString rootFile, bool doData, bool doMCD, bool doMCP) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

	if (doData) {
  	dir = fout->GetDirectory("data");
  	if (!dir) {
    	dir = fout->mkdir("data");
    	dir->cd();
  	}

		hdatajetPt->Write();
    hdatajetNormAreaPt->Write();
    hdatajetNormNEventsPt->Write();
    hdatajetNormNJetsPt->Write();
    hdatajetNormAreaPtRebin->Write();
    hdatajetNormNEventsPtRebin->Write();
    hdatajetNormNJetsPtRebin->Write();
		for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
			hdatajetTrackPt[binJetPt]->Write();
			hdatajetTrackEta[binJetPt]->Write();
			hdatajetTrackPhi[binJetPt]->Write();
      if (fillIPxy) {
        hdatajetImpXY[binJetPt]->Write();
        hdatajetSignImpXY[binJetPt]->Write();
        hdatajetImpXYSig[binJetPt]->Write();
      }
      if (fillIPz) {
        hdatajetImpZ[binJetPt]->Write();
        hdatajetSignImpZ[binJetPt]->Write();
        hdatajetImpZSig[binJetPt]->Write();
      }
      
      if (fillIPxyz) {
        hdatajetImpXYZ[binJetPt]->Write();
        hdatajetSignImpXYZ[binJetPt]->Write();
        hdatajetImpXYZSig[binJetPt]->Write();
      }
      
      for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
        if (fillIPxy)  hdatajetSignImpXYSig[binJetPt][binTrackPt]->Write();
        if (fillIPz)   hdatajetSignImpZSig[binJetPt][binTrackPt]->Write();
        if (fillIPxyz) hdatajetSignImpXYZSig[binJetPt][binTrackPt]->Write();
      }
		}
	}

	if (doMCD) {
  	dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
  	}
		for (int binFlavour =0; binFlavour < HfJetTagging::nFlavour+1; binFlavour++) {
      hsimjetPt[binFlavour]->Write();
      hsimjetPtRebin[binFlavour]->Write();
      if (fillMatched) {
        h2simjetPtpartjetPtMatched[binFlavour]->Write(Form("resMat_%d", binFlavour));
        h2simjetPtpartjetPtMatchedRebin[binFlavour]->Write(Form("resMatRebin_%d", binFlavour));
      }
      for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        hsimjetTrackPt[binFlavour][binJetPt]->Write();
        hsimjetTrackEta[binFlavour][binJetPt]->Write();
        hsimjetTrackPhi[binFlavour][binJetPt]->Write();
        if (fillIPxy) {
          hsimjetImpXY[binFlavour][binJetPt]->Write();
          hsimjetSignImpXY[binFlavour][binJetPt]->Write();
          hsimjetImpXYSig[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYSig[binFlavour][binJetPt]->Write();
        }
        if (fillIPz) {
          hsimjetImpZ[binFlavour][binJetPt]->Write();
          hsimjetSignImpZ[binFlavour][binJetPt]->Write();
          hsimjetImpZSig[binFlavour][binJetPt]->Write();
          hsimjetSignImpZSig[binFlavour][binJetPt]->Write();
        }
        if (fillIPxyz) {
          hsimjetImpXYZ[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYZ[binFlavour][binJetPt]->Write();
          hsimjetImpXYZSig[binFlavour][binJetPt]->Write();
          hsimjetSignImpXYZSig[binFlavour][binJetPt]->Write();
        }
      }
////		  for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
////        hsimtrackImpXY[binFlavour][binTrackPt]->Write();
////        hsimtrackSignImpXY[binFlavour][binTrackPt]->Write();
////        hsimtrackImpXYSig[binFlavour][binTrackPt]->Write();
////        hsimtrackSignImpXYSig[binFlavour][binTrackPt]->Write();
////      }
    }
	}

  fout->Close();
	delete fout;
}


void HfJetTaggingAnalysis::saveHistogramUnfold(TString rootFile, bool doData, bool doMCD, bool doMCP) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;
	if (doData) {
  	if (!dir) {
    	dir = fout->mkdir("data");
    	dir->cd();
  	}
  }
  if (doMCD) {
  	dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
  	}
		for (int binFlavour =0; binFlavour < HfJetTagging::nFlavour+1; binFlavour++) {
      if (fillMatched) {
        TH2F* h2ResMat = (TH2F*) h2simjetPtpartjetPtMatched[binFlavour]->Clone("h2ResMat");
        TH2F* h2ResMatInv = (TH2F*) h2simpartjetPtjetPtMatched[binFlavour]->Clone("h2ResMatInv");
        h2ResMat->Write(Form("resMat_%d", binFlavour));
        h2ResMatInv->Write(Form("resMatInverse_%d", binFlavour));
        taggingutilities::normalize2DHist(h2ResMat);
        taggingutilities::normalize2DHist(h2ResMatInv);
        //h2ResMat->Write(Form("resMatNorm_%d", binFlavour));
        //h2ResMatInv->Write(Form("resMatInverseNorm_%d", binFlavour));
        h2simjetPtpartjetPtMatchedRebin[binFlavour]->Write(Form("resMatRebin_%d", binFlavour));
        h2simpartjetPtjetPtMatchedRebin[binFlavour]->Write(Form("resMatInverseRebin_%d", binFlavour));
        hsimjetPtMatched[binFlavour]->Write(Form("hsimjetPtMatched_%d", binFlavour));
        hsimjetPtMatchedRebin[binFlavour]->Write(Form("hsimjetPtMatchedRebin_%d", binFlavour));
        hsimpartjetPtMatched[binFlavour]->Write(Form("hsimpartjetPtMatched_%d", binFlavour));
        hsimpartjetPtMatchedRebin[binFlavour]->Write(Form("hsimpartjetPtMatchedRebin_%d", binFlavour));
      }
    }
  }
}

// Set function
void HfJetTaggingAnalysis::setFillData(bool mfillData) {
  fillData = mfillData;
  if (fillData) {
    std::cout << "Fill Data ON " << std::endl;
  }
}

void HfJetTaggingAnalysis::setFillMCD(bool mfillMCD) {
  fillMCD = mfillMCD;
  if (fillMCD) {
    std::cout << "Fill MCD ON" << std::endl;
  }
}

void HfJetTaggingAnalysis::setFillMCP(bool mfillMCP) {
  fillMCP = mfillMCP;
  if (fillMCP) {
    std::cout << "Fill MCP ON" << std::endl;
  }
}

void HfJetTaggingAnalysis::setDoUnfolding(bool mdoUnfolding) {
  doUnfolding = mdoUnfolding;
  if (fillMCP) {
    std::cout << "Do unfolding jet" << std::endl;
  }
}

void HfJetTaggingAnalysis::setFillTest(bool mfillTest) {
  fillTest = mfillTest;
  if (fillTest) {
    std::cout << "using test and developing " << std::endl;
  }
}
void HfJetTaggingAnalysis::setFillIPxy(bool mfillIPxy) {
  fillIPxy = mfillIPxy;
  if (fillIPxy) {
    std::cout << "fill impact parameter xy-plane" << std::endl;
  }
}
void HfJetTaggingAnalysis::setFillIPz(bool mfillIPz) {
  fillIPz = mfillIPz;
  if (fillIPz) {
    std::cout << "fill impact parameter z-axis" << std::endl;
  }
}
void HfJetTaggingAnalysis::setFillIPxyz(bool mfillIPxyz) {
  fillIPxyz = mfillIPxyz;
  if (fillIPxyz) {
    std::cout << "fill impact parameter xyz-plane" << std::endl;
  }
}

void HfJetTaggingAnalysis::setFitForJP(bool mfitForJP) {
  fitForJP = mfitForJP;
  if (fitForJP) {
    std::cout << "fitting resolution function from IP distribution ON" << std::endl;
  }
}

void HfJetTaggingAnalysis::setFillMatched(bool mfillMatched) {
  fillMatched = mfillMatched;
  if (fillMatched) {
    std::cout << "fill matched MCD and MCP" << std::endl;
  }
}

void HfJetTaggingAnalysis::setDebug(bool mdebug) {
  debug = mdebug;
  if (debug) {
    std::cout << "debuging mode" << std::endl;
  }
}

void HfJetTaggingAnalysis::setLoadResMat(bool mloadResMat) {
  loadResMat = mloadResMat;
  if (loadResMat) {
    std::cout << "load external response matrix" << std::endl;
  }
}

void HfJetTaggingAnalysis::setLoadPOWHEG(bool mloadPOWHEG) {
  loadPOWHEG = mloadPOWHEG;
  if (loadPOWHEG) {
    std::cout << "load POWHEG model" << std::endl;
  }
}

// calculation function

// draw function
void HfJetTaggingAnalysis::drawDataJetPt(bool doLog) {
  hdatajetNormPt = (TH1F*) hdatajetPt->Clone("hdatajetNormPt");
  hdatajetNormPt->Scale(1.0, "width");
  hdatajetNormAreaPt = (TH1F*) hdatajetPt->Clone("hdatajetNormAreaPt");
  hdatajetNormAreaPt->Scale(1. / hdatajetNormAreaPt->Integral(), "width");
  hdatajetNormNEventsPt = (TH1F*) hdatajetPt->Clone("hdatajetNormNEventsPt");
  hdatajetNormNEventsPt->Scale(1. / ndataEvents, "width");
  hdatajetNormNJetsPt = (TH1F*) hdatajetPt->Clone("hdatajetNormNJetsPt");
  hdatajetNormNJetsPt->Scale(1. / ndataJets[0], "width");

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetPt, ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaPt, ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsPt, ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsPt, ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hdatajetPt->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentum.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2*1/hdatajetPt->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumNormArea.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-1/ndataEvents, 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumNormNEvents.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/ndataJets[0], 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNJets.size(), normNJets, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumNormNJets.pdf\")", nc++, dirDataGen.Data()));

  // rebin
  hdatajetNormPtRebin = (TH1F*) hdatajetPtRebin->Clone("hdatajetNormPtRebin");
  hdatajetNormPtRebin->Sumw2();
  hdatajetNormPtRebin->Scale(1.0, "width");
  hdatajetNormAreaPtRebin = (TH1F*) hdatajetPtRebin->Clone("hdatajetNormAreaPtRebin");
  hdatajetNormAreaPtRebin->Scale(1. / hdatajetNormAreaPtRebin->Integral(), "width");
  hdatajetNormNEventsPtRebin = (TH1F*) hdatajetPtRebin->Clone("hdatajetNormNEventsPtRebin");
  hdatajetNormNEventsPtRebin->Scale(1. / ndataEvents, "width");
  hdatajetNormNJetsPtRebin = (TH1F*) hdatajetPtRebin->Clone("hdatajetNormNJetsPtRebin");
  hdatajetNormNJetsPtRebin->Scale(1. / ndataJets[0], "width");

	std::vector<HistogramData> rawHistRebin;
	rawHistRebin.push_back({hdatajetNormPtRebin, ""});

	std::vector<HistogramData> normAreaRebin;
	normAreaRebin.push_back({hdatajetNormAreaPtRebin, ""});

	std::vector<HistogramData> normNEventsRebin;
	normNEventsRebin.push_back({hdatajetNormNEventsPtRebin, ""});

	std::vector<HistogramData> normNJetsRebin;
	normNJetsRebin.push_back({hdatajetNormNJetsPtRebin, ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hdatajetPtRebin->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHistRebin.size(), rawHistRebin, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumRebin.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hdatajetPtRebin->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normAreaRebin.size(), normAreaRebin, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumRebinNormArea.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-1/ndataEvents, 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNEventsRebin.size(), normNEventsRebin, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumRebinNormNEvents.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/ndataJets[0], 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNJetsRebin.size(), normNJetsRebin, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetMomentumRebinNormNJets.pdf\")", nc++, dirDataGen.Data()));
}

void HfJetTaggingAnalysis::drawDataJetEta(bool doLog) {
  hdatajetNormAreaEta = (TH1F*) hdatajetEta->Clone();
  hdatajetNormAreaEta->Scale(1. / hdatajetNormAreaEta->Integral());
  hdatajetNormNEventsEta = (TH1F*) hdatajetEta->Clone();
  hdatajetNormNEventsEta->Scale(1. / ndataEvents);
  hdatajetNormNJetsEta = (TH1F*) hdatajetEta->Clone();
  hdatajetNormNJetsEta->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetEta, ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaEta, ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsEta, ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsEta, ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-3, 5e+2*hdatajetEta->GetMaximum(), HfJetTagging::X_AXIS_JETETA, HfJetTagging::Y_AXIS_JETETA);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetEta.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/hdatajetNormAreaEta->GetMaximum(), 1, HfJetTagging::X_AXIS_JETETA, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetEtaNormArea.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETETA, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetEtaNormNEvents.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/ndataJets[0], 1, HfJetTagging::X_AXIS_JETETA, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNJets.size(), normNJets, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetEtaNormNJets.pdf\")", nc++, dirDataGen.Data()));
}

void HfJetTaggingAnalysis::drawDataJetPhi(bool doLog) {
  hdatajetNormAreaPhi = (TH1F*) hdatajetPhi->Clone();
  hdatajetNormAreaPhi->Scale(1. / hdatajetNormAreaPhi->Integral());
  hdatajetNormNEventsPhi = (TH1F*) hdatajetPhi->Clone();
  hdatajetNormNEventsPhi->Scale(1. / ndataEvents);
  hdatajetNormNJetsPhi = (TH1F*) hdatajetPhi->Clone();
  hdatajetNormNJetsPhi->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetPhi, ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaPhi, ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsPhi, ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsPhi, ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-3, 5e+2*hdatajetPhi->GetMaximum(), HfJetTagging::X_AXIS_JETPHI, HfJetTagging::Y_AXIS_JETPHI);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetPhi.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/hdatajetNormAreaPhi->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPHI, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetPhiNormArea.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETPHI, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNEvents.size(), normNEvents, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetPhiNormNEvents.pdf\")", nc++, dirDataGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/ndataJets[0], 1, HfJetTagging::X_AXIS_JETPHI, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNJets.size(), normNJets, true, false);
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetPhiNormNJets.pdf\")", nc++, dirDataGen.Data()));
}

void HfJetTaggingAnalysis::drawDataTrackPt(bool doLog, int binJetPt=0) {

  hdatajetNormAreaTrackPt[binJetPt] = (TH1F*) hdatajetTrackPt[binJetPt]->Clone();
  hdatajetNormAreaTrackPt[binJetPt]->Scale(1. / hdatajetNormAreaTrackPt[binJetPt]->Integral());
  hdatajetNormNEventsTrackPt[binJetPt] = (TH1F*) hdatajetTrackPt[binJetPt]->Clone();
  hdatajetNormNEventsTrackPt[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsTrackPt[binJetPt] = (TH1F*) hdatajetTrackPt[binJetPt]->Clone();
  hdatajetNormNJetsTrackPt[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetTrackPt[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaTrackPt[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsTrackPt[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsTrackPt[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackmomentum_%d.pdf\")", nc++, dirDataGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackmomentumNormArea_%d.pdf\")", nc++, dirDataGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::drawDataTrackEta(bool doLog, int binJetPt=0) {
  hdatajetNormAreaTrackEta[binJetPt] = (TH1F*) hdatajetTrackEta[binJetPt]->Clone();
  hdatajetNormAreaTrackEta[binJetPt]->Scale(1. / hdatajetNormAreaTrackEta[binJetPt]->Integral());
  hdatajetNormNEventsTrackEta[binJetPt] = (TH1F*) hdatajetTrackEta[binJetPt]->Clone();
  hdatajetNormNEventsTrackEta[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsTrackEta[binJetPt] = (TH1F*) hdatajetTrackEta[binJetPt]->Clone();
  hdatajetNormNJetsTrackEta[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetTrackEta[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaTrackEta[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsTrackEta[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsTrackEta[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/tracketa_%d.pdf\")", nc++, dirDataGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/tracketaNormArea_%d.pdf\")", nc++, dirDataGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataTrackPhi(bool doLog, int binJetPt=0) {

  hdatajetNormAreaTrackPhi[binJetPt] = (TH1F*) hdatajetTrackPhi[binJetPt]->Clone();
  hdatajetNormAreaTrackPhi[binJetPt]->Scale(1. / hdatajetNormAreaTrackPhi[binJetPt]->Integral());
  hdatajetNormNEventsTrackPhi[binJetPt] = (TH1F*) hdatajetTrackPhi[binJetPt]->Clone();
  hdatajetNormNEventsTrackPhi[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsTrackPhi[binJetPt] = (TH1F*) hdatajetTrackPhi[binJetPt]->Clone();
  hdatajetNormNJetsTrackPhi[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetTrackPhi[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaTrackPhi[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsTrackPhi[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsTrackPhi[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackphi_%d.pdf\")", nc++, dirDataGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackphiNormArea_%d.pdf\")", nc++, dirDataGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXY(bool doLog, int binJetPt=0) {
  hdatajetNormAreaImpXY[binJetPt] = (TH1F*) hdatajetImpXY[binJetPt]->Clone();
  hdatajetNormAreaImpXY[binJetPt]->Scale(1. / hdatajetNormAreaImpXY[binJetPt]->Integral());
  hdatajetNormNEventsImpXY[binJetPt] = (TH1F*) hdatajetImpXY[binJetPt]->Clone();
  hdatajetNormNEventsImpXY[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsImpXY[binJetPt] = (TH1F*) hdatajetImpXY[binJetPt]->Clone();
  hdatajetNormNJetsImpXY[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpXY[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpXY[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpXY[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpXY[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXY(bool doLog, int binJetPt=0) {
  hdatajetNormAreaSignImpXY[binJetPt] = (TH1F*) hdatajetSignImpXY[binJetPt]->Clone();
  hdatajetNormAreaSignImpXY[binJetPt]->Scale(1. / hdatajetNormAreaSignImpXY[binJetPt]->Integral());
  hdatajetNormNEventsSignImpXY[binJetPt] = (TH1F*) hdatajetSignImpXY[binJetPt]->Clone();
  hdatajetNormNEventsSignImpXY[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsSignImpXY[binJetPt] = (TH1F*) hdatajetSignImpXY[binJetPt]->Clone();
  hdatajetNormNJetsSignImpXY[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpXY[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpXY[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpXY[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpXY[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXY_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "Anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYSig(bool doLog, int binJetPt=0) {
  hdatajetNormAreaImpXYSig[binJetPt] = (TH1F*) hdatajetImpXYSig[binJetPt]->Clone();
  hdatajetNormAreaImpXYSig[binJetPt]->Scale(1. / hdatajetNormAreaImpXYSig[binJetPt]->Integral());
  hdatajetNormNEventsImpXYSig[binJetPt] = (TH1F*) hdatajetImpXYSig[binJetPt]->Clone();
  hdatajetNormNEventsImpXYSig[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsImpXYSig[binJetPt] = (TH1F*) hdatajetImpXYSig[binJetPt]->Clone();
  hdatajetNormNJetsImpXYSig[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpXYSig[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpXYSig[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpXYSig[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpXYSig[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSig_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSigNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
  hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt]->Scale(1. / hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt]->Integral());
  hdatajetNormNEventsSignImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormNEventsSignImpXYSig[binJetPt][binTrackPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsSignImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormNJetsSignImpXYSig[binJetPt][binTrackPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetSignImpXYSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsSignImpXYSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsSignImpXYSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSig_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSigNormArea_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ(bool doLog, int binJetPt=0) {
  hdatajetNormAreaImpZ[binJetPt] = (TH1F*) hdatajetImpZ[binJetPt]->Clone();
  hdatajetNormAreaImpZ[binJetPt]->Scale(1. / hdatajetNormAreaImpZ[binJetPt]->Integral());
  hdatajetNormNEventsImpZ[binJetPt] = (TH1F*) hdatajetImpZ[binJetPt]->Clone();
  hdatajetNormNEventsImpZ[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsImpZ[binJetPt] = (TH1F*) hdatajetImpZ[binJetPt]->Clone();
  hdatajetNormNJetsImpZ[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpZ[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpZ[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpZ[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::X_AXIS_IMPZ[0]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::X_AXIS_IMPZ[0]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpZ(bool doLog, int binJetPt=0) {
  hdatajetNormAreaSignImpZ[binJetPt] = (TH1F*) hdatajetSignImpZ[binJetPt]->Clone();
  hdatajetNormAreaSignImpZ[binJetPt]->Scale(1. / hdatajetNormAreaSignImpZ[binJetPt]->Integral());
  hdatajetNormNEventsSignImpZ[binJetPt] = (TH1F*) hdatajetSignImpZ[binJetPt]->Clone();
  hdatajetNormNEventsSignImpZ[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsSignImpZ[binJetPt] = (TH1F*) hdatajetSignImpZ[binJetPt]->Clone();
  hdatajetNormNJetsSignImpZ[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetSignImpZ[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaSignImpZ[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsSignImpZ[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsSignImpZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZ_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpZSig(bool doLog, int binJetPt=0) {
  hdatajetNormAreaImpZSig[binJetPt] = (TH1F*) hdatajetImpZSig[binJetPt]->Clone();
  hdatajetNormAreaImpZSig[binJetPt]->Scale(1. / hdatajetNormAreaImpZSig[binJetPt]->Integral());
  hdatajetNormNEventsImpZSig[binJetPt] = (TH1F*) hdatajetImpZSig[binJetPt]->Clone();
  hdatajetNormNEventsImpZSig[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsImpZSig[binJetPt] = (TH1F*) hdatajetImpZSig[binJetPt]->Clone();
  hdatajetNormNJetsImpZSig[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpZSig[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpZSig[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpZSig[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpZSig[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/genHfTag/ImpZSig_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/genHfTag/ImpZSigNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpZSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
  hdatajetNormAreaSignImpZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpZSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormAreaSignImpZSig[binJetPt][binTrackPt]->Scale(1. / hdatajetNormAreaSignImpZSig[binJetPt][binTrackPt]->Integral());
  hdatajetNormNEventsSignImpZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpZSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormNEventsSignImpZSig[binJetPt][binTrackPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsSignImpZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpZSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormNJetsSignImpZSig[binJetPt][binTrackPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetSignImpZSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaSignImpZSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsSignImpZSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsSignImpZSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSig_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSigNormArea_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ(bool doLog, int binJetPt=0) {
  hdatajetNormAreaImpXYZ[binJetPt] = (TH1F*) hdatajetImpXYZ[binJetPt]->Clone();
  hdatajetNormAreaImpXYZ[binJetPt]->Scale(1. / hdatajetNormAreaImpXYZ[binJetPt]->Integral());
  hdatajetNormNEventsImpXYZ[binJetPt] = (TH1F*) hdatajetImpXYZ[binJetPt]->Clone();
  hdatajetNormNEventsImpXYZ[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsImpXYZ[binJetPt] = (TH1F*) hdatajetImpXYZ[binJetPt]->Clone();
  hdatajetNormNJetsImpXYZ[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpXYZ[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpXYZ[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpXYZ[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpXYZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYZ(bool doLog, int binJetPt=0) {
  hdatajetNormAreaSignImpXYZ[binJetPt] = (TH1F*) hdatajetSignImpXYZ[binJetPt]->Clone();
  hdatajetNormAreaSignImpXYZ[binJetPt]->Scale(1. / hdatajetNormAreaSignImpXYZ[binJetPt]->Integral());
  hdatajetNormNEventsSignImpXYZ[binJetPt] = (TH1F*) hdatajetSignImpXYZ[binJetPt]->Clone();
  hdatajetNormNEventsSignImpXYZ[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsSignImpXYZ[binJetPt] = (TH1F*) hdatajetSignImpXYZ[binJetPt]->Clone();
  hdatajetNormNJetsSignImpXYZ[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetSignImpXYZ[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaSignImpXYZ[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsSignImpXYZ[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsSignImpXYZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZ_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZSig(bool doLog, int binJetPt=0) {
  hdatajetNormAreaImpXYZSig[binJetPt] = (TH1F*) hdatajetImpXYZSig[binJetPt]->Clone();
  hdatajetNormAreaImpXYZSig[binJetPt]->Scale(1. / hdatajetNormAreaImpXYZSig[binJetPt]->Integral());
  hdatajetNormNEventsImpXYZSig[binJetPt] = (TH1F*) hdatajetImpXYZSig[binJetPt]->Clone();
  hdatajetNormNEventsImpXYZSig[binJetPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsImpXYZSig[binJetPt] = (TH1F*) hdatajetImpXYZSig[binJetPt]->Clone();
  hdatajetNormNJetsImpXYZSig[binJetPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetImpXYZSig[binJetPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpXYZSig[binJetPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsImpXYZSig[binJetPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsImpXYZSig[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZSig_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZSigNormArea_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYZSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
  hdatajetNormAreaSignImpXYZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYZSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormAreaSignImpXYZSig[binJetPt][binTrackPt]->Scale(1. / hdatajetNormAreaSignImpXYZSig[binJetPt][binTrackPt]->Integral());
  hdatajetNormNEventsSignImpXYZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYZSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormNEventsSignImpXYZSig[binJetPt][binTrackPt]->Scale(1. / ndataEvents);
  hdatajetNormNJetsSignImpXYZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYZSig[binJetPt][binTrackPt]->Clone();
  hdatajetNormNJetsSignImpXYZSig[binJetPt][binTrackPt]->Scale(1. / ndataJets[0]);

	std::vector<HistogramData> rawHist;
	rawHist.push_back({hdatajetSignImpXYZSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaSignImpXYZSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normNEvents;
	normNEvents.push_back({hdatajetNormNEventsSignImpXYZSig[binJetPt][binTrackPt], ""});

	std::vector<HistogramData> normNJets;
	normNJets.push_back({hdatajetNormNJetsSignImpXYZSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSig_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normArea.size(), normArea, true, false);
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSigNormArea_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

// MxN
void HfJetTaggingAnalysis::drawDataImpXY4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normArea;
	normArea.push_back({hdatajetNormAreaImpXY[binJetPt], ""});
	std::vector<HistogramData> normAreaSign;
	normAreaSign.push_back({hdatajetNormAreaSignImpXY[binJetPt], ""});
	std::vector<HistogramData> normAreaSig;
	normAreaSig.push_back({hdatajetNormAreaImpXYSig[binJetPt], ""});
	std::vector<HistogramData> normAreaSignSig;
	normAreaSignSig.push_back({hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.12);
  latexDataSet();
  canHan->drawPadMxNCombined(nc, 0, 0, normArea, true, doLog, false, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], "Probability");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
  latexSimJetInfo(0.35, 0.98, 0, "", "anti-#it{k}_{T}", "Charged", 0.4, "this simulation");
  canHan->drawPadMxNCombined(nc, 1, 0, normAreaSign, true, doLog, false, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], "");
  canHan->drawPadMxNCombined(nc, 2, 0, normAreaSig, true, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], "");
  canHan->drawPadMxNCombined(nc, 3, 0, normAreaSignSig, true, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], "");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY4x1_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXY2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormAreaImpXY[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpXY[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaImpXYSig[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas2x2(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPXY[mpad][0], HfJetTagging::REFIPXY[mpad][1], HfJetTagging::REFIPXY[mpad][2], HfJetTagging::REFIPXY[mpad][3], HfJetTagging::X_AXIS_IMPXY[mpad], HfJetTagging::Y_AXIS_IMPXY[mpad]);
  }
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY2x2_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormAreaImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaImpZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas4x1(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPZ[mpad][0], HfJetTagging::REFIPZ[mpad][1], HfJetTagging::REFIPZ[mpad][2], HfJetTagging::REFIPZ[mpad][3], HfJetTagging::X_AXIS_IMPZ[mpad], HfJetTagging::Y_AXIS_IMPZ[mpad]);
  }
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ4x1_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormAreaImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaImpZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas2x2(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPZ[mpad][0], HfJetTagging::REFIPZ[mpad][1], HfJetTagging::REFIPZ[mpad][2], HfJetTagging::REFIPZ[mpad][3], HfJetTagging::X_AXIS_IMPZ[mpad], HfJetTagging::Y_AXIS_IMPZ[mpad]);
  }
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ2x2_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormAreaImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaImpXYZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpXYZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas4x1(nc);
  for (int mpad=0; mpad<4; mpad++) {
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPXYZ[mpad][0], HfJetTagging::REFIPXYZ[mpad][1], HfJetTagging::REFIPXYZ[mpad][2], HfJetTagging::REFIPXYZ[mpad][3], HfJetTagging::X_AXIS_IMPXYZ[mpad], HfJetTagging::Y_AXIS_IMPXYZ[mpad]);
  }
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ4x1_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormAreaImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaImpXYZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormAreaSignImpXYZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas2x2(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPXYZ[mpad][0], HfJetTagging::REFIPXYZ[mpad][1], HfJetTagging::REFIPXYZ[mpad][2], HfJetTagging::REFIPXYZ[mpad][3], HfJetTagging::X_AXIS_IMPXYZ[mpad], HfJetTagging::Y_AXIS_IMPXYZ[mpad]);
  }
  latexDataJetInfo(0.17, 0.86, binJetPt, "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ2x2_%d_%d.pdf\")", nc++, dirDataIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

// sim
void HfJetTaggingAnalysis::drawSimJetPt(bool withInc = false, bool doLog = true) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormPt[flavour] = (TH1F*) hsimjetPt[flavour]->Clone();
    hsimjetNormPt[flavour]->Scale(1.0, "width");
    hsimjetNormAreaPt[flavour] = (TH1F*) hsimjetPt[flavour]->Clone();
    hsimjetNormAreaPt[flavour]->Scale(1. / hsimjetNormAreaPt[flavour]->Integral());
    hsimjetNormNEventsPt[flavour] = (TH1F*) hsimjetPt[flavour]->Clone();
    hsimjetNormNEventsPt[flavour]->Scale(1. / nsimEvents);
    hsimjetNormNJetsPt[flavour] = (TH1F*) hsimjetPt[flavour]->Clone();
    hsimjetNormNJetsPt[flavour]->Scale(1. / nsimJets[flavour][0]);
  }

  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetPt[0], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetPt[1], HfJetTagging::CJET});
  rawHist.push_back({hsimjetPt[2], HfJetTagging::BJET});
  rawHist.push_back({hsimjetPt[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaPt[0], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaPt[1], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaPt[2], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaPt[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsPt[0], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsPt[1], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsPt[2], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsPt[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsPt[0], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsPt[1], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsPt[2], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsPt[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hsimjetPt[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentum.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPt[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormArea.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETPT, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPT.Data()), 1.10, 1.50);
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormNEvents.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETPT, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_JETPT.Data()), 1.10, 1.50);
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormNJets.pdf\")", nc++, dirSimGen.Data()));

  /// rebin
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormPtRebin[flavour] = (TH1F*) hsimjetPtRebin[flavour]->Clone();
    hsimjetNormPtRebin[flavour]->Scale(1.0, "width");
    hsimjetNormAreaPtRebin[flavour] = (TH1F*) hsimjetPtRebin[flavour]->Clone();
    hsimjetNormAreaPtRebin[flavour]->Scale(1. / hsimjetNormAreaPtRebin[flavour]->Integral(), "width");
    hsimjetNormNEventsPtRebin[flavour] = (TH1F*) hsimjetPtRebin[flavour]->Clone();
    hsimjetNormNEventsPtRebin[flavour]->Scale(1. / nsimEvents, "width");
    hsimjetNormNJetsPtRebin[flavour] = (TH1F*) hsimjetPtRebin[flavour]->Clone();
    hsimjetNormNJetsPtRebin[flavour]->Scale(1. / nsimJets[flavour][0], "width");
  }

  std::vector<HistogramData> rawHistRebin;
  rawHistRebin.push_back({hsimjetNormPtRebin[0], HfJetTagging::INCJET});
  rawHistRebin.push_back({hsimjetNormPtRebin[1], HfJetTagging::CJET});
  rawHistRebin.push_back({hsimjetNormPtRebin[2], HfJetTagging::BJET});
  rawHistRebin.push_back({hsimjetNormPtRebin[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normAreaRebin;
  normAreaRebin.push_back({hsimjetNormAreaPtRebin[0], HfJetTagging::INCJET});
  normAreaRebin.push_back({hsimjetNormAreaPtRebin[1], HfJetTagging::CJET});
  normAreaRebin.push_back({hsimjetNormAreaPtRebin[2], HfJetTagging::BJET});
  normAreaRebin.push_back({hsimjetNormAreaPtRebin[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEventsRebin;
  normNEventsRebin.push_back({hsimjetNormNEventsPtRebin[0], HfJetTagging::INCJET});
  normNEventsRebin.push_back({hsimjetNormNEventsPtRebin[1], HfJetTagging::CJET});
  normNEventsRebin.push_back({hsimjetNormNEventsPtRebin[2], HfJetTagging::BJET});
  normNEventsRebin.push_back({hsimjetNormNEventsPtRebin[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJetsRebin;
  normNJetsRebin.push_back({hsimjetNormNJetsPtRebin[0], HfJetTagging::INCJET});
  normNJetsRebin.push_back({hsimjetNormNJetsPtRebin[1], HfJetTagging::CJET});
  normNJetsRebin.push_back({hsimjetNormNJetsPtRebin[2], HfJetTagging::BJET});
  normNJetsRebin.push_back({hsimjetNormNJetsPtRebin[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hsimjetNormPtRebin[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHistRebin.size(), rawHistRebin, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumRebin.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPt[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normAreaRebin.size(), normAreaRebin, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormAreaRebin.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETPT, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPT.Data()), 1.10, 1.50);
  canHan->drawCombined(normNEventsRebin.size(), normNEventsRebin, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormNEventsRebin.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETPT, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_JETPT.Data()), 1.10, 1.50);
  canHan->drawCombined(normNJetsRebin.size(), normNJetsRebin, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormNJetsRebin.pdf\")", nc++, dirSimGen.Data()));
}

void HfJetTaggingAnalysis::drawSimJetEta(bool withInc = false, bool doLog = true) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaEta[flavour] = (TH1F*) hsimjetEta[flavour]->Clone();
    hsimjetNormAreaEta[flavour]->Scale(1. / hsimjetNormAreaEta[flavour]->Integral());
    hsimjetNormNEventsEta[flavour] = (TH1F*) hsimjetEta[flavour]->Clone();
    hsimjetNormNEventsEta[flavour]->Scale(1. / nsimEvents);
    hsimjetNormNJetsEta[flavour] = (TH1F*) hsimjetEta[flavour]->Clone();
    hsimjetNormNJetsEta[flavour]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetEta[0], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetEta[1], HfJetTagging::CJET});
  rawHist.push_back({hsimjetEta[2], HfJetTagging::BJET});
  rawHist.push_back({hsimjetEta[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaEta[0], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaEta[1], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaEta[2], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaEta[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsEta[0], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsEta[1], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsEta[2], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsEta[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsEta[0], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsEta[1], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsEta[2], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsEta[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 1, 5e+2*hsimjetEta[0]->GetMaximum(), HfJetTagging::X_AXIS_JETETA, HfJetTagging::Y_AXIS_JETETA);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jeteta.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/hsimjetEta[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETETA, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetetaNormArea.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETETA, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETETA.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetetaNormNEvents.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETETA, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETETA.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetetaNormNJets.pdf\")", nc++, dirSimGen.Data()));
}

void HfJetTaggingAnalysis::drawSimJetPhi(bool withInc = false, bool doLog = true) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaPhi[flavour] = (TH1F*) hsimjetPhi[flavour]->Clone();
    hsimjetNormAreaPhi[flavour]->Scale(1. / hsimjetNormAreaPhi[flavour]->Integral());
    hsimjetNormNEventsPhi[flavour] = (TH1F*) hsimjetPhi[flavour]->Clone();
    hsimjetNormNEventsPhi[flavour]->Scale(1. / nsimEvents);
    hsimjetNormNJetsPhi[flavour] = (TH1F*) hsimjetPhi[flavour]->Clone();
    hsimjetNormNJetsPhi[flavour]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetPhi[0], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetPhi[1], HfJetTagging::CJET});
  rawHist.push_back({hsimjetPhi[2], HfJetTagging::BJET});
  rawHist.push_back({hsimjetPhi[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaPhi[0], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaPhi[1], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaPhi[2], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaPhi[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsPhi[0], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsPhi[1], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsPhi[2], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsPhi[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsPhi[0], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsPhi[1], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsPhi[2], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsPhi[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 1, 5e+2*hsimjetPhi[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPHI, HfJetTagging::Y_AXIS_JETPHI);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetphi.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/hsimjetPhi[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPHI, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetphiNormArea.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETPHI, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPHI.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetphiNormNEvents.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETPHI, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPHI.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetphiNormNJets.pdf\")", nc++, dirSimGen.Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackPt(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaTrackPt[flavour][binJetPt] = (TH1F*) hsimjetTrackPt[flavour][binJetPt]->Clone();
    hsimjetNormAreaTrackPt[flavour][binJetPt]->Scale(1. / hsimjetNormAreaTrackPt[flavour][binJetPt]->Integral());
    hsimjetNormNEventsTrackPt[flavour][binJetPt] = (TH1F*) hsimjetTrackPt[flavour][binJetPt]->Clone();
    hsimjetNormNEventsTrackPt[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsTrackPt[flavour][binJetPt] = (TH1F*) hsimjetTrackPt[flavour][binJetPt]->Clone();
    hsimjetNormNJetsTrackPt[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetTrackPt[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetTrackPt[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetTrackPt[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetTrackPt[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaTrackPt[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaTrackPt[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaTrackPt[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaTrackPt[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsTrackPt[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsTrackPt[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsTrackPt[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsTrackPt[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsTrackPt[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsTrackPt[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsTrackPt[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsTrackPt[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], 1, 5e+2*hsimjetTrackPt[0][binJetPt]->GetMaximum(), HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackmomentum_%d.pdf\")", nc++, dirSimGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackmomentumNormArea_%d.pdf\")", nc++, dirSimGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackPt(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> normHist;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    normHist.push_back({hsimjetNormAreaTrackPt[flavour][binJetPt+1], Form("%0.f<jet pT<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPTASJETPT[0], HfJetTagging::REFHIST::TRACKPTASJETPT[1], HfJetTagging::REFHIST::TRACKPTASJETPT[2], HfJetTagging::REFHIST::TRACKPTASJETPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackmomentum.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackEta(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaTrackEta[flavour][binJetPt] = (TH1F*) hsimjetTrackEta[flavour][binJetPt]->Clone();
    hsimjetNormAreaTrackEta[flavour][binJetPt]->Scale(1. / hsimjetNormAreaTrackEta[flavour][binJetPt]->Integral());
    hsimjetNormNEventsTrackEta[flavour][binJetPt] = (TH1F*) hsimjetTrackEta[flavour][binJetPt]->Clone();
    hsimjetNormNEventsTrackEta[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsTrackEta[flavour][binJetPt] = (TH1F*) hsimjetTrackEta[flavour][binJetPt]->Clone();
    hsimjetNormNJetsTrackEta[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetTrackEta[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetTrackEta[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetTrackEta[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetTrackEta[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaTrackEta[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaTrackEta[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaTrackEta[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaTrackEta[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsTrackEta[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsTrackEta[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsTrackEta[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsTrackEta[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsTrackEta[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsTrackEta[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsTrackEta[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsTrackEta[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/tracketa_%d.pdf\")", nc++, dirSimGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/tracketaNormArea_%d.pdf\")", nc++, dirSimGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackEta(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> normHist;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    normHist.push_back({hsimjetNormAreaTrackEta[flavour][binJetPt+1], Form("%0.f<jet #eta<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETAASJETPT[0], HfJetTagging::REFHIST::TRACKETAASJETPT[1], HfJetTagging::REFHIST::TRACKETAASJETPT[2], HfJetTagging::REFHIST::TRACKETAASJETPT[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/tracketa.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackPhi(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaTrackPhi[flavour][binJetPt] = (TH1F*) hsimjetTrackPhi[flavour][binJetPt]->Clone();
    hsimjetNormAreaTrackPhi[flavour][binJetPt]->Scale(1. / hsimjetNormAreaTrackPhi[flavour][binJetPt]->Integral());
    hsimjetNormNEventsTrackPhi[flavour][binJetPt] = (TH1F*) hsimjetTrackPhi[flavour][binJetPt]->Clone();
    hsimjetNormNEventsTrackPhi[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsTrackPhi[flavour][binJetPt] = (TH1F*) hsimjetTrackPhi[flavour][binJetPt]->Clone();
    hsimjetNormNJetsTrackPhi[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetTrackPhi[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetTrackPhi[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetTrackPhi[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetTrackPhi[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaTrackPhi[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaTrackPhi[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaTrackPhi[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaTrackPhi[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsTrackPhi[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsTrackPhi[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsTrackPhi[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsTrackPhi[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsTrackPhi[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsTrackPhi[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsTrackPhi[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsTrackPhi[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackphi_%d.pdf\")", nc++, dirSimGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));


  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackphiNormArea_%d.pdf\")", nc++, dirSimGen.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackPhi(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> normHist;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    normHist.push_back({hsimjetNormAreaTrackPhi[flavour][binJetPt+1], Form("%0.f<jet #phi<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHIASJETPT[0], HfJetTagging::REFHIST::TRACKPHIASJETPT[1], HfJetTagging::REFHIST::TRACKPHIASJETPT[2], HfJetTagging::REFHIST::TRACKPHIASJETPT[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackphi.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaImpXY[flavour][binJetPt] = (TH1F*) hsimjetImpXY[flavour][binJetPt]->Clone();
    hsimjetNormAreaImpXY[flavour][binJetPt]->Scale(1. / hsimjetNormAreaImpXY[flavour][binJetPt]->Integral());
    hsimjetNormNEventsImpXY[flavour][binJetPt] = (TH1F*) hsimjetImpXY[flavour][binJetPt]->Clone();
    hsimjetNormNEventsImpXY[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsImpXY[flavour][binJetPt] = (TH1F*) hsimjetImpXY[flavour][binJetPt]->Clone();
    hsimjetNormNJetsImpXY[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetImpXY[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetImpXY[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetImpXY[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaImpXY[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaImpXY[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaImpXY[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsImpXY[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsImpXY[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsImpXY[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsImpXY[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsImpXY[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsImpXY[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsImpXY[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingAnalysis::drawSimJetSignImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXY[flavour][binJetPt] = (TH1F*) hsimjetSignImpXY[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXY[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXY[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXY[flavour][binJetPt] = (TH1F*) hsimjetSignImpXY[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXY[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXY[flavour][binJetPt] = (TH1F*) hsimjetSignImpXY[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXY[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXY[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXY[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXY[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXY[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXY[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXY[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXY[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXY[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXY_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));


}

void HfJetTaggingAnalysis::drawSimJetImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaImpXYSig[flavour][binJetPt] = (TH1F*) hsimjetImpXYSig[flavour][binJetPt]->Clone();
    hsimjetNormAreaImpXYSig[flavour][binJetPt]->Scale(1. / hsimjetNormAreaImpXYSig[flavour][binJetPt]->Integral());
    hsimjetNormNEventsImpXYSig[flavour][binJetPt] = (TH1F*) hsimjetImpXYSig[flavour][binJetPt]->Clone();
    hsimjetNormNEventsImpXYSig[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsImpXYSig[flavour][binJetPt] = (TH1F*) hsimjetImpXYSig[flavour][binJetPt]->Clone();
    hsimjetNormNJetsImpXYSig[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetImpXYSig[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetImpXYSig[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSignificance_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSignificanceNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSig[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYSig[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYSig[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSig[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYSig[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYSig[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYSig[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificance_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXY2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXY;
  histListImpXY.push_back({hsimjetNormAreaImpXY[0][binJetPt], HfJetTagging::INCJET});
  histListImpXY.push_back({hsimjetNormAreaImpXY[1][binJetPt], HfJetTagging::CJET});
  histListImpXY.push_back({hsimjetNormAreaImpXY[2][binJetPt], HfJetTagging::BJET});
  histListImpXY.push_back({hsimjetNormAreaImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXY;
  histListSignImpXY.push_back({hsimjetNormAreaSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXY.push_back({hsimjetNormAreaSignImpXY[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXY.push_back({hsimjetNormAreaSignImpXY[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXY.push_back({hsimjetNormAreaSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYSig;
  histListImpXYSig.push_back({hsimjetNormAreaImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYSig.push_back({hsimjetNormAreaImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histListImpXYSig.push_back({hsimjetNormAreaImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histListImpXYSig.push_back({hsimjetNormAreaImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYSig;
  histListSignImpXYSig.push_back({hsimjetNormAreaSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYSig.push_back({hsimjetNormAreaSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYSig.push_back({hsimjetNormAreaSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYSig.push_back({hsimjetNormAreaSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvas2x2(nc, 0, 0, 800, 800, 0.13);
  int mpad=0;

  // mpad0
  canHan->drawPadCombined(histListImpXY, withInc, false, doLog, nc, mpad, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  gROOT->ProcessLine(Form("mpad%d_%d->cd()", nc, mpad++));
  //latexSimJetInfo(0.17, 0.85, 0, "jet-jet trigger", "Anti-#it{k}_{T}", "Charged", 0.4, "this simulation");
  latexSimJetInfo(0.17, 0.88, 0, "PYTHIA 8", "Anti-#it{k}_{T}", "Charged", 0.4, "this simulation");

  // mpad1
  canHan->drawPadCombined(histListSignImpXY, withInc, true, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);

  // mpad2
  canHan->drawPadCombined(histListImpXYSig, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);

  // mpad3
  canHan->drawPadCombined(histListSignImpXYSig, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY2x2_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZ2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpZ;
  histListImpZ.push_back({hsimjetNormAreaImpZ[0][binJetPt], HfJetTagging::INCJET});
  histListImpZ.push_back({hsimjetNormAreaImpZ[1][binJetPt], HfJetTagging::CJET});
  histListImpZ.push_back({hsimjetNormAreaImpZ[2][binJetPt], HfJetTagging::BJET});
  histListImpZ.push_back({hsimjetNormAreaImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpZ;
  histListSignImpZ.push_back({hsimjetNormAreaSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpZ.push_back({hsimjetNormAreaSignImpZ[1][binJetPt], HfJetTagging::CJET});
  histListSignImpZ.push_back({hsimjetNormAreaSignImpZ[2][binJetPt], HfJetTagging::BJET});
  histListSignImpZ.push_back({hsimjetNormAreaSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpZSig;
  histListImpZSig.push_back({hsimjetNormAreaImpZSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpZSig.push_back({hsimjetNormAreaImpZSig[1][binJetPt], HfJetTagging::CJET});
  histListImpZSig.push_back({hsimjetNormAreaImpZSig[2][binJetPt], HfJetTagging::BJET});
  histListImpZSig.push_back({hsimjetNormAreaImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpZSig;
  histListSignImpZSig.push_back({hsimjetNormAreaSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpZSig.push_back({hsimjetNormAreaSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpZSig.push_back({hsimjetNormAreaSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpZSig.push_back({hsimjetNormAreaSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvas2x2(nc);
  int mpad=0;

  // mpad0
  canHan->drawPadCombined(histListImpZ, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::Y_AXIS_IMPZ[0]);

  // mpad1
  canHan->drawPadCombined(histListSignImpZ, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);

  // mpad2
  canHan->drawPadCombined(histListImpZSig, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);

  // mpad3
  canHan->drawPadCombined(histListSignImpZSig, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ2x2_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZ2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXYZ;
  histListImpXYZ.push_back({hsimjetNormAreaImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYZ.push_back({hsimjetNormAreaImpXYZ[1][binJetPt], HfJetTagging::CJET});
  histListImpXYZ.push_back({hsimjetNormAreaImpXYZ[2][binJetPt], HfJetTagging::BJET});
  histListImpXYZ.push_back({hsimjetNormAreaImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYZ;
  histListSignImpXYZ.push_back({hsimjetNormAreaSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYZ.push_back({hsimjetNormAreaSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYZ.push_back({hsimjetNormAreaSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYZ.push_back({hsimjetNormAreaSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYZSig;
  histListImpXYZSig.push_back({hsimjetNormAreaImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYZSig.push_back({hsimjetNormAreaImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  histListImpXYZSig.push_back({hsimjetNormAreaImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  histListImpXYZSig.push_back({hsimjetNormAreaImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYZSig;
  histListSignImpXYZSig.push_back({hsimjetNormAreaSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYZSig.push_back({hsimjetNormAreaSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYZSig.push_back({hsimjetNormAreaSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYZSig.push_back({hsimjetNormAreaSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan->createCanvas2x2(nc);
  int mpad=0;

  // mpad0
  canHan->drawPadCombined(histListImpXYZ, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);

  // mpad1
  canHan->drawPadCombined(histListSignImpXYZ, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);

  // mpad2
  canHan->drawPadCombined(histListImpXYZSig, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);

  // mpad3
  canHan->drawPadCombined(histListSignImpXYZSig, withInc, false, doLog, nc, mpad++, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ2x2_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaImpZ[flavour][binJetPt] = (TH1F*) hsimjetImpZ[flavour][binJetPt]->Clone();
    hsimjetNormAreaImpZ[flavour][binJetPt]->Scale(1. / hsimjetNormAreaImpZ[flavour][binJetPt]->Integral());
    hsimjetNormNEventsImpZ[flavour][binJetPt] = (TH1F*) hsimjetImpZ[flavour][binJetPt]->Clone();
    hsimjetNormNEventsImpZ[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsImpZ[flavour][binJetPt] = (TH1F*) hsimjetImpZ[flavour][binJetPt]->Clone();
    hsimjetNormNJetsImpZ[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetImpZ[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetImpZ[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetImpZ[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaImpZ[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaImpZ[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaImpZ[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsImpZ[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsImpZ[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsImpZ[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsImpZ[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsImpZ[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsImpZ[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsImpZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::Y_AXIS_IMPZ[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::Y_AXIS_IMPZ[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::drawSimJetSignImpZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpZ[flavour][binJetPt] = (TH1F*) hsimjetSignImpZ[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpZ[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpZ[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpZ[flavour][binJetPt] = (TH1F*) hsimjetSignImpZ[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpZ[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpZ[flavour][binJetPt] = (TH1F*) hsimjetSignImpZ[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpZ[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpZ[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpZ[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpZ[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpZ[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZ[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZ[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZ[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZ[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZ_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaImpZSig[flavour][binJetPt] = (TH1F*) hsimjetImpZSig[flavour][binJetPt]->Clone();
    hsimjetNormAreaImpZSig[flavour][binJetPt]->Scale(1. / hsimjetNormAreaImpZSig[flavour][binJetPt]->Integral());
    hsimjetNormNEventsImpZSig[flavour][binJetPt] = (TH1F*) hsimjetImpZSig[flavour][binJetPt]->Clone();
    hsimjetNormNEventsImpZSig[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsImpZSig[flavour][binJetPt] = (TH1F*) hsimjetImpZSig[flavour][binJetPt]->Clone();
    hsimjetNormNJetsImpZSig[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetImpZSig[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetImpZSig[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetImpZSig[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaImpZSig[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaImpZSig[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsImpZSig[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsImpZSig[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsImpZSig[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsImpZSig[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZSignificance_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZSignificanceNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpZSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSig[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpZSig[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpZSig[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpZSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSig[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpZSig[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpZSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpZSig[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpZSig[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificance_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificanceNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaImpXYZ[flavour][binJetPt] = (TH1F*) hsimjetImpXYZ[flavour][binJetPt]->Clone();
    hsimjetNormAreaImpXYZ[flavour][binJetPt]->Scale(1. / hsimjetNormAreaImpXYZ[flavour][binJetPt]->Integral());
    hsimjetNormNEventsImpXYZ[flavour][binJetPt] = (TH1F*) hsimjetImpXYZ[flavour][binJetPt]->Clone();
    hsimjetNormNEventsImpXYZ[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsImpXYZ[flavour][binJetPt] = (TH1F*) hsimjetImpXYZ[flavour][binJetPt]->Clone();
    hsimjetNormNJetsImpXYZ[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetImpXYZ[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetImpXYZ[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYZ[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZ[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYZ[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYZ[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYZ[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZ[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYZ[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYZ[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZ[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYZ[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZ_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaImpXYZSig[flavour][binJetPt] = (TH1F*) hsimjetImpXYZSig[flavour][binJetPt]->Clone();
    hsimjetNormAreaImpXYZSig[flavour][binJetPt]->Scale(1. / hsimjetNormAreaImpXYZSig[flavour][binJetPt]->Integral());
    hsimjetNormNEventsImpXYZSig[flavour][binJetPt] = (TH1F*) hsimjetImpXYZSig[flavour][binJetPt]->Clone();
    hsimjetNormNEventsImpXYZSig[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsImpXYZSig[flavour][binJetPt] = (TH1F*) hsimjetImpXYZSig[flavour][binJetPt]->Clone();
    hsimjetNormNJetsImpXYZSig[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZSignificance_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZSignificanceNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimjetNormAreaSignImpXYZSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSig[flavour][binJetPt]->Clone();
    hsimjetNormAreaSignImpXYZSig[flavour][binJetPt]->Scale(1. / hsimjetNormAreaSignImpXYZSig[flavour][binJetPt]->Integral());
    hsimjetNormNEventsSignImpXYZSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSig[flavour][binJetPt]->Clone();
    hsimjetNormNEventsSignImpXYZSig[flavour][binJetPt]->Scale(1. / nsimEvents);
    hsimjetNormNJetsSignImpXYZSig[flavour][binJetPt] = (TH1F*) hsimjetSignImpXYZSig[flavour][binJetPt]->Clone();
    hsimjetNormNJetsSignImpXYZSig[flavour][binJetPt]->Scale(1. / nsimJets[flavour][binJetPt]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimjetSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  rawHist.push_back({hsimjetSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  rawHist.push_back({hsimjetSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimjetNormAreaSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normArea.push_back({hsimjetNormAreaSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimjetNormNEventsSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normNJets.push_back({hsimjetNormNJetsSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificance_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificanceNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimTrackImpXY(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtrackNormAreaImpXY[flavour][binTrackPt] = (TH1F*) hsimtrackImpXY[flavour][binTrackPt]->Clone();
    hsimtrackNormAreaImpXY[flavour][binTrackPt]->Scale(1. / hsimtrackNormAreaImpXY[flavour][binTrackPt]->Integral());
    hsimtrackNormNEventsImpXY[flavour][binTrackPt] = (TH1F*) hsimtrackImpXY[flavour][binTrackPt]->Clone();
    hsimtrackNormNEventsImpXY[flavour][binTrackPt]->Scale(1. / nsimEvents);
    hsimtrackNormNJetsImpXY[flavour][binTrackPt] = (TH1F*) hsimtrackImpXY[flavour][binTrackPt]->Clone();
    hsimtrackNormNJetsImpXY[flavour][binTrackPt]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtrackImpXY[0][binTrackPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtrackImpXY[1][binTrackPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtrackImpXY[2][binTrackPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtrackImpXY[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtrackNormAreaImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtrackNormAreaImpXY[1][binTrackPt], HfJetTagging::CJET});
  normArea.push_back({hsimtrackNormAreaImpXY[2][binTrackPt], HfJetTagging::BJET});
  normArea.push_back({hsimtrackNormAreaImpXY[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtrackNormNEventsImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtrackNormNEventsImpXY[1][binTrackPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtrackNormNEventsImpXY[2][binTrackPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtrackNormNEventsImpXY[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtrackNormNJetsImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtrackNormNJetsImpXY[1][binTrackPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtrackNormNJetsImpXY[2][binTrackPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtrackNormNJetsImpXY[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackImpXY_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackImpXYNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));

}

void HfJetTaggingAnalysis::drawSimFlavourTrackImpXY(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormAreaImpXY[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormAreaImpXY[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackImpXY.pdf\")", nc++, dirSimIP.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimTrackSignImpXY(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtrackNormAreaSignImpXY[flavour][binTrackPt] = (TH1F*) hsimtrackSignImpXY[flavour][binTrackPt]->Clone();
    hsimtrackNormAreaSignImpXY[flavour][binTrackPt]->Scale(1. / hsimtrackNormAreaSignImpXY[flavour][binTrackPt]->Integral());
    hsimtrackNormNEventsSignImpXY[flavour][binTrackPt] = (TH1F*) hsimtrackSignImpXY[flavour][binTrackPt]->Clone();
    hsimtrackNormNEventsSignImpXY[flavour][binTrackPt]->Scale(1. / nsimEvents);
    hsimtrackNormNJetsSignImpXY[flavour][binTrackPt] = (TH1F*) hsimtrackSignImpXY[flavour][binTrackPt]->Clone();
    hsimtrackNormNJetsSignImpXY[flavour][binTrackPt]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtrackSignImpXY[0][binTrackPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtrackSignImpXY[1][binTrackPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtrackSignImpXY[2][binTrackPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtrackSignImpXY[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtrackNormAreaSignImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtrackNormAreaSignImpXY[1][binTrackPt], HfJetTagging::CJET});
  normArea.push_back({hsimtrackNormAreaSignImpXY[2][binTrackPt], HfJetTagging::BJET});
  normArea.push_back({hsimtrackNormAreaSignImpXY[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtrackNormNEventsSignImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtrackNormNEventsSignImpXY[1][binTrackPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtrackNormNEventsSignImpXY[2][binTrackPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtrackNormNEventsSignImpXY[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtrackNormNJetsSignImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtrackNormNJetsSignImpXY[1][binTrackPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtrackNormNJetsSignImpXY[2][binTrackPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtrackNormNJetsSignImpXY[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackSignImpXY_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackSignImpXYNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackSignImpXY(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormAreaSignImpXY[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormAreaSignImpXY[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackSignImpXY.pdf\")", nc++, dirSimIP.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimTrackImpXYSig(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtrackNormAreaImpXYSig[flavour][binTrackPt] = (TH1F*) hsimtrackImpXYSig[flavour][binTrackPt]->Clone();
    hsimtrackNormAreaImpXYSig[flavour][binTrackPt]->Scale(1. / hsimtrackNormAreaImpXYSig[flavour][binTrackPt]->Integral());
    hsimtrackNormNEventsImpXYSig[flavour][binTrackPt] = (TH1F*) hsimtrackImpXYSig[flavour][binTrackPt]->Clone();
    hsimtrackNormNEventsImpXYSig[flavour][binTrackPt]->Scale(1. / nsimEvents);
    hsimtrackNormNJetsImpXYSig[flavour][binTrackPt] = (TH1F*) hsimtrackImpXYSig[flavour][binTrackPt]->Clone();
    hsimtrackNormNJetsImpXYSig[flavour][binTrackPt]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtrackImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtrackImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtrackImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtrackImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtrackNormAreaImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtrackNormAreaImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normArea.push_back({hsimtrackNormAreaImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normArea.push_back({hsimtrackNormAreaImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtrackNormNEventsImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtrackNormNEventsImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtrackNormNEventsImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtrackNormNEventsImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtrackNormNJetsImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtrackNormNJetsImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtrackNormNJetsImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtrackNormNJetsImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackImpXYSig_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackImpXYSigNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackImpXYSig(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormAreaImpXYSig[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormAreaImpXYSig[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackImpXYSig.pdf\")", nc++, dirSimIP.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimTrackSignImpXYSig(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimtrackNormAreaSignImpXYSig[flavour][binTrackPt] = (TH1F*) hsimtrackSignImpXYSig[flavour][binTrackPt]->Clone();
    hsimtrackNormAreaSignImpXYSig[flavour][binTrackPt]->Scale(1. / hsimtrackNormAreaSignImpXYSig[flavour][binTrackPt]->Integral());
    hsimtrackNormNEventsSignImpXYSig[flavour][binTrackPt] = (TH1F*) hsimtrackSignImpXYSig[flavour][binTrackPt]->Clone();
    hsimtrackNormNEventsSignImpXYSig[flavour][binTrackPt]->Scale(1. / nsimEvents);
    hsimtrackNormNJetsSignImpXYSig[flavour][binTrackPt] = (TH1F*) hsimtrackSignImpXYSig[flavour][binTrackPt]->Clone();
    hsimtrackNormNJetsSignImpXYSig[flavour][binTrackPt]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimtrackSignImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  rawHist.push_back({hsimtrackSignImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  rawHist.push_back({hsimtrackSignImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  rawHist.push_back({hsimtrackSignImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimtrackNormAreaSignImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normArea.push_back({hsimtrackNormAreaSignImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normArea.push_back({hsimtrackNormAreaSignImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normArea.push_back({hsimtrackNormAreaSignImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimtrackNormNEventsSignImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normNEvents.push_back({hsimtrackNormNEventsSignImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normNEvents.push_back({hsimtrackNormNEventsSignImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normNEvents.push_back({hsimtrackNormNEventsSignImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimtrackNormNJetsSignImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normNJets.push_back({hsimtrackNormNJetsSignImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normNJets.push_back({hsimtrackNormNJetsSignImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normNJets.push_back({hsimtrackNormNJetsSignImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackSignImpXYSig_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackSignImpXYSigNormArea_%d.pdf\")", nc++, dirSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackSignImpXYSig(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormAreaSignImpXYSig[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormAreaSignImpXYSig[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackSignImpXYSig.pdf\")", nc++, dirSimIP.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimFlavourJetpartJetPt(bool doLog = true, int flavour = 2) {
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetPt[flavour], "MCD jet"});
  rawHist.push_back({hsimpartjetPt[flavour], "MCP jet"});

  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormAreaPt[flavour], "MCD jet"});
  normHist.push_back({hsimpartjetNormAreaPt[flavour], "MCP jet"});

  TH1F *hRatioRawHist = static_cast<TH1F*>(hsimjetPt[flavour]->Clone("hRatioRawHist"));
  hRatioRawHist->Divide(hsimpartjetPt[flavour]);

  TH1F *hRatioNormArea = static_cast<TH1F*>(hsimjetNormAreaPt[flavour]->Clone("hRatioNormArea"));
  hRatioNormArea->Divide(hsimpartjetNormAreaPt[flavour]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_JETPT, "MCD/MCP");
  hRatioRawHist->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetmomentumWithMCDMCP.pdf\")", nc++, dirSimIP.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_JETPT, "MCD/MCP");
  hRatioNormArea->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetmomentumNormAreaWithMCDMCP.pdf\")", nc++, dirSimIP.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawDataVsSimJetPt(bool doLog = true) {
  int flavour = 0; // inc-jet
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hdatajetPt, Form("Data (%s)", DATASET.Data())});
  rawHist.push_back({hsimjetPt[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaPt, Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormAreaPt[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hdatajetNormNEventsPt, Form("Data (%s)", DATASET.Data())});
  normNEvents.push_back({hsimjetNormNEventsPt[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hdatajetNormNJetsPt, Form("Data (%s)", DATASET.Data())});
  normNJets.push_back({hsimjetNormNJetsPt[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> rawHistRebin;
  rawHistRebin.push_back({hdatajetPtRebin, Form("Data (%s)", DATASET.Data())});
  rawHistRebin.push_back({hsimjetPtRebin[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normAreaRebin;
  normAreaRebin.push_back({hdatajetNormAreaPtRebin, Form("Data (%s)", DATASET.Data())});
  //normAreaRebin.push_back({hsimjetNormAreaPtRebin[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNEventsRebin;
  normNEventsRebin.push_back({hdatajetNormNEventsPtRebin, Form("Data (%s)", DATASET.Data())});
  //normNEventsRebin.push_back({hsimjetNormNEventsPtRebin[flavour], Form("MC (%s)", SIMSET.Data())});

  std::vector<HistogramData> normNJetsRebin;
  normNJetsRebin.push_back({hdatajetNormNJetsPtRebin, Form("Data (%s)", DATASET.Data())});
  //normNJetsRebin.push_back({hsimjetNormNJetsPtRebin[flavour], Form("MC (%s)", SIMSET.Data())});

  TH1F *hRatioRawJetPt = static_cast<TH1F*>(hdatajetPt->Clone("hRatioRawJetPt"));
  hRatioRawJetPt->Divide(hsimjetPt[flavour]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 5e+2*hdatajetPt->GetMaximum(), "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_RATIO);
  hRatioRawJetPt->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentum.pdf\")", nc++, dirDataVsSimGen.Data()));

  TH1F *hRatioNormArea = static_cast<TH1F*>(hdatajetPt->Clone("hRatioNormArea"));
  hRatioNormArea->Divide(hsimjetPt[flavour]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hdatajetPt->GetMaximum(), 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_RATIO);
  hRatioNormArea->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormArea.pdf\")", nc++, dirDataVsSimGen.Data()));

  TH1F *hRatioNormNEvents = static_cast<TH1F*>(hdatajetPt->Clone("hRatioNormNEvents"));
  hRatioNormNEvents->Divide(hsimjetPt[flavour]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-1/ndataEvents, 1, "", "Event normalization");
  canHan->drawCombined(normNEvents.size(), normNEvents, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_RATIO);
  hRatioNormNEvents->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormNEvents.pdf\")", nc++, dirDataVsSimGen.Data()));

  TH1F *hRatioNormNJets = static_cast<TH1F*>(hdatajetPt->Clone("hRatioNormNJets"));
  hRatioNormNJets->Divide(hsimjetPt[flavour]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-1/ndataJets[0], 1, "", HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normNJets.size(), normNJets, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 2, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_RATIO);
  hRatioNormNJets->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentumNormNJets.pdf\")", nc++, dirDataVsSimGen.Data()));

}

void HfJetTaggingAnalysis::drawDataVsSimJetEta(bool doLog = true) {
  int flavour = 2;
}

void HfJetTaggingAnalysis::drawDataVsSimJetPhi(bool doLog = true) {
  int flavour = 2;
}

void HfJetTaggingAnalysis::drawDataVsSimJetImpXY(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaImpXY[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormAreaImpXY[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormAreaImpXY[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormAreaImpXY[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normArea.size(), normArea, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYNormArea_%d.pdf\")", nc++, dirDataVsSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataVsSimJetSignImpXY(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaSignImpXY[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormAreaSignImpXY[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormAreaSignImpXY[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormAreaSignImpXY[0][binJetPt]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normArea.size(), normArea, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYNormArea_%d.pdf\")", nc++, dirDataVsSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataVsSimJetImpXYSig(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> rawHist;

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaImpXYSig[binJetPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormAreaImpXYSig[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormAreaImpXYSig[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormAreaImpXYSig[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normArea.size(), normArea, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSignificanceNormArea_%d.pdf\")", nc++, dirDataVsSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataVsSimJetSignImpXYSig(bool doLog = true, int binJetPt=0, int binTrackPt=0) {
  std::vector<HistogramData> rawHist;

  std::vector<HistogramData> normArea;
  normArea.push_back({hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt], Form("Data (%s)", DATASET.Data())});
  normArea.push_back({hsimjetNormAreaSignImpXYSig[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormAreaSignImpXYSig[binJetPt][binTrackPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormAreaSignImpXYSig[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normArea.size(), normArea, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceNormArea_%d_%d.pdf\")", nc++, dirDataVsSimIP.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}


void HfJetTaggingAnalysis::fitDataJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hdatajetSignImpXYSig[0][0], ""});
  //TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)+expo(9)+expo(11)", -40, 0);
  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
//  fResoFunc->SetParameters(1.3e+06, 0, 1,
//                           10, 0.5,
//                           10, 0.5,
//                           10, 0.5);
  fResoFunc->SetParameters(1306800, -0.1049, 0.861425, 
                           13.7547, 0.977967,
                           8.96823, 0.151595,
                           6.94499, 0.0250301);
  fResoFunc->SetParLimits(1, -3, 3);
  fResoFunc->SetParLimits(2, 0, 1e+2);
  //dataTagjetSignImpXYSig[0][0]->Fit(fResoFunc, "QRL");
  hdatajetSignImpXYSig[0][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Writing parameters to a text file
  std::ofstream outData("paramsData.txt");
  if (outData.is_open()) {
    outData << DATASET.Data() << " ";
    for (int i = 0; i < 9; ++i) {
      outData << std::fixed << std::setprecision(3) << params[i];
      if (i != 8) outData << ", ";
    }
    outData.close();
  } else {
    std::cerr << "Unable to open file for writing." << std::endl;
  }

  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 10, hdatajetSignImpXYSig[0][0]->GetMaximum() * 10, HfJetTagging::X_AXIS_IMPXY[3], "Raw yield");
  canHan->drawCombined(histList.size(), histList, true, false);
  latex.DrawLatex(posX, posY, equation);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceWithFit.pdf\")", nc++, dirDataIP.Data()));
}


void HfJetTaggingAnalysis::fitIncJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetSignImpXYSig[0][0], HfJetTagging::INCJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  fResoFunc->SetParameters(61145.8, -0.082085, 0.706361, 
                           10.0794, 1.15412,
                           5.81011, 0.188979,
                           3.8514, 0.032457);
  fResoFunc->SetParLimits(0, 1e+2, 1e+10);
  fResoFunc->SetParLimits(1, -3, 3);
//  fResoFunc->SetParLimits(3, 0, 1e+2);
//  fResoFunc->SetParLimits(5, 0, 1e+2);
//  fResoFunc->SetParLimits(7, 0, 1e+2);
  //hsimjetSignImpXYSig[0][0]->Fit(fResoFunc, "QRL");
  hsimjetSignImpXYSig[0][0]->Fit(fResoFunc, "QRM");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Writing parameters to a text file
  std::ofstream outData("paramsIncJetMC.txt");
  if (outData.is_open()) {
    outData << SIMSET.Data() << " ";
    for (int i = 0; i < 9; ++i) {
      outData << std::fixed << std::setprecision(3) << params[i];
      if (i != 8) outData << ", ";
    }
    outData.close();
  } else {
    std::cerr << "Unable to open file for writing." << std::endl;
  }

  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.05, 0.05, 0.12, 1);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 1, hsimjetSignImpXYSig[0][0]->GetMaximum() * 10, HfJetTagging::X_AXIS_IMPXY[3], "Raw yield");
  canHan->drawCombined(histList.size(), histList, true, false);
  latex.DrawLatex(posX, posY, equation);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::fitCharmJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetSignImpXYSig[1][0], HfJetTagging::CJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  //fResoFunc->SetParameters(hsimjetSignImpXYSig[1][0]->GetEnries(), 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParameters(61145.8, -0.082085, 0.706361, 
                           10.0794, 1.15412,
                           5.81011, 0.188979,
                           3.8514, 0.032457);
  fResoFunc->SetParLimits(0, 1, 1e+10);
  fResoFunc->SetParLimits(1, -3, 3);
  fResoFunc->SetParLimits(6, 0, 10);
  hsimjetSignImpXYSig[1][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Writing parameters to a text file
  std::ofstream outData("paramsCharmJetMC.txt");
  if (outData.is_open()) {
    outData << SIMSET.Data() << " ";
    for (int i = 0; i < 9; ++i) {
      outData << std::fixed << std::setprecision(3) << params[i];
      if (i != 8) outData << ", ";
    }
    outData.close();
  } else {
    std::cerr << "Unable to open file for writing." << std::endl;
  }

  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimjetSignImpXYSig[0][0]->GetMaximum() * 10, HfJetTagging::X_AXIS_IMPXY[3], "Raw yield");
  canHan->drawCombined(histList.size(), histList, true, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::fitBeautyJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetSignImpXYSig[2][0], HfJetTagging::BJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  //fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParameters(61145.8, -0.082085, 0.706361, 
                           10.0794, 1.15412,
                           5.81011, 0.188979,
                           3.8514, 0.032457);
  fResoFunc->SetParLimits(0, 0, 1e+10);
  fResoFunc->SetParLimits(1, -3, 3);
  hsimjetSignImpXYSig[2][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Writing parameters to a text file
  std::ofstream outData("paramsBeautyJetMC.txt");
  if (outData.is_open()) {
    outData << SIMSET.Data() << " ";
    for (int i = 0; i < 9; ++i) {
      outData << std::fixed << std::setprecision(3) << params[i];
      if (i != 8) outData << ", ";
    }
    outData.close();
  } else {
    std::cerr << "Unable to open file for writing." << std::endl;
  }
  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimjetSignImpXYSig[0][0]->GetMaximum() * 10, HfJetTagging::X_AXIS_IMPXY[3], "Raw yield");
  canHan->drawCombined(histList.size(), histList, true, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::fitLfJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetSignImpXYSig[3][0], HfJetTagging::LFJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  //fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParameters(61145.8, -0.082085, 0.706361, 
                           10.0794, 1.15412,
                           5.81011, 0.188979,
                           3.8514, 0.032457);
  fResoFunc->SetParLimits(0, 1e+4, 1e+10);
  fResoFunc->SetParLimits(1, -1, 1);
  hsimjetSignImpXYSig[3][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Writing parameters to a text file
  std::ofstream outData("paramsLfJetMC.txt");
  if (outData.is_open()) {
    outData << SIMSET.Data() << " ";
    for (int i = 0; i < 9; ++i) {
      outData << std::fixed << std::setprecision(3) << params[i];
      if (i != 8) outData << ", ";
    }
    outData.close();
  } else {
    std::cerr << "Unable to open file for writing." << std::endl;
  }

  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimjetSignImpXYSig[0][0]->GetMaximum() * 10, HfJetTagging::X_AXIS_IMPXY[3], "Raw yield");
  canHan->drawCombined(histList.size(), histList, true, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::fitTaggedJetSignImpXYSignificance(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetSignImpXYSig[0][0], HfJetTagging::INCJET});
  histList.push_back({hsimjetSignImpXYSig[1][0], HfJetTagging::CJET});
  histList.push_back({hsimjetSignImpXYSig[2][0], HfJetTagging::BJET});
  histList.push_back({hsimjetSignImpXYSig[3][0], HfJetTagging::LFJET});
  TF1 *fResoFunc[HfJetTagging::nFlavour+1];
  // Open a file to save the parameters
  std::ofstream outFile("fitParameters.txt");

  for (int flavour=0; flavour<HfJetTagging::nFlavour+1; flavour++) {
    fResoFunc[flavour]= new TF1(Form("fResoFunc_%d", flavour), "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
    //fResoFunc[flavour]->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
    fResoFunc[flavour]->SetParameters(61145.8, -0.082085, 0.706361, 
                           10.0794, 1.15412,
                           5.81011, 0.188979,
                           3.8514, 0.032457);
    fResoFunc[flavour]->SetParLimits(6, 0, 1e+10);
    fResoFunc[flavour]->SetParLimits(7, -1, 1);
    hsimjetSignImpXYSig[flavour][0]->Fit(fResoFunc[flavour], "QRL");

    // Assuming there are 9 parameters as in your example
    double params[9];
    fResoFunc[flavour]->GetParameters(params);

    // Print and save the parameters
    std::cout << "Flavour " << flavour << " parameters: ";
    outFile << "Flavour " << flavour << " parameters: ";
    for (int i = 0; i < 9; ++i) {
      std::cout << params[i] << " ";
      outFile << params[i] << " ";
    }
    std::cout << std::endl;
    outFile << std::endl;
  }
  outFile.close();

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimjetSignImpXYSig[0][0]->GetMaximum()*10, HfJetTagging::X_AXIS_IMPXY[3], "Raw yield");
  canHan->drawCombined(histList.size(), histList, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSimIP.Data()));
}

// For mcp
void HfJetTaggingAnalysis::drawSimpartJetPt(bool withInc = false, bool doLog = true) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimpartjetNormAreaPt[flavour] = (TH1F*) hsimpartjetPt[flavour]->Clone();
    hsimpartjetNormAreaPt[flavour]->Scale(1. / hsimpartjetNormAreaPt[flavour]->Integral());
    hsimpartjetNormNEventsPt[flavour] = (TH1F*) hsimpartjetPt[flavour]->Clone();
    hsimpartjetNormNEventsPt[flavour]->Scale(1. / nsimEvents);
    hsimpartjetNormNJetsPt[flavour] = (TH1F*) hsimpartjetPt[flavour]->Clone();
    hsimpartjetNormNJetsPt[flavour]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimpartjetPt[0], HfJetTagging::INCJET});
  rawHist.push_back({hsimpartjetPt[1], HfJetTagging::CJET});
  rawHist.push_back({hsimpartjetPt[2], HfJetTagging::BJET});
  rawHist.push_back({hsimpartjetPt[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimpartjetNormAreaPt[0], HfJetTagging::INCJET});
  normArea.push_back({hsimpartjetNormAreaPt[1], HfJetTagging::CJET});
  normArea.push_back({hsimpartjetNormAreaPt[2], HfJetTagging::BJET});
  normArea.push_back({hsimpartjetNormAreaPt[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimpartjetNormNEventsPt[0], HfJetTagging::INCJET});
  normNEvents.push_back({hsimpartjetNormNEventsPt[1], HfJetTagging::CJET});
  normNEvents.push_back({hsimpartjetNormNEventsPt[2], HfJetTagging::BJET});
  normNEvents.push_back({hsimpartjetNormNEventsPt[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimpartjetNormNJetsPt[0], HfJetTagging::INCJET});
  normNJets.push_back({hsimpartjetNormNJetsPt[1], HfJetTagging::CJET});
  normNJets.push_back({hsimpartjetNormNJetsPt[2], HfJetTagging::BJET});
  normNJets.push_back({hsimpartjetNormNJetsPt[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.15);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hsimjetPt[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetmomentum.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPt[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetmomentumNormArea.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETPT, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPT.Data()), 1.10, 1.50);
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetmomentumNormNEvents.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.17, 0.04, 0.05, 0.13);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETPT, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NJETS.Data(), HfJetTagging::Y_AXIS_JETPT.Data()), 1.10, 1.50);
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetmomentumNormNJets.pdf\")", nc++, dirSimGen.Data()));

}

void HfJetTaggingAnalysis::drawSimpartJetEta(bool withInc = false, bool doLog = true) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimpartjetNormAreaEta[flavour] = (TH1F*) hsimpartjetEta[flavour]->Clone();
    hsimpartjetNormAreaEta[flavour]->Scale(1. / hsimpartjetNormAreaEta[flavour]->Integral());
    hsimpartjetNormNEventsEta[flavour] = (TH1F*) hsimpartjetEta[flavour]->Clone();
    hsimpartjetNormNEventsEta[flavour]->Scale(1. / nsimEvents);
    hsimpartjetNormNJetsEta[flavour] = (TH1F*) hsimpartjetEta[flavour]->Clone();
    hsimpartjetNormNJetsEta[flavour]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimpartjetEta[0], HfJetTagging::INCJET});
  rawHist.push_back({hsimpartjetEta[1], HfJetTagging::CJET});
  rawHist.push_back({hsimpartjetEta[2], HfJetTagging::BJET});
  rawHist.push_back({hsimpartjetEta[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimpartjetNormAreaEta[0], HfJetTagging::INCJET});
  normArea.push_back({hsimpartjetNormAreaEta[1], HfJetTagging::CJET});
  normArea.push_back({hsimpartjetNormAreaEta[2], HfJetTagging::BJET});
  normArea.push_back({hsimpartjetNormAreaEta[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimpartjetNormNEventsEta[0], HfJetTagging::INCJET});
  normNEvents.push_back({hsimpartjetNormNEventsEta[1], HfJetTagging::CJET});
  normNEvents.push_back({hsimpartjetNormNEventsEta[2], HfJetTagging::BJET});
  normNEvents.push_back({hsimpartjetNormNEventsEta[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimpartjetNormNJetsEta[0], HfJetTagging::INCJET});
  normNJets.push_back({hsimpartjetNormNJetsEta[1], HfJetTagging::CJET});
  normNJets.push_back({hsimpartjetNormNJetsEta[2], HfJetTagging::BJET});
  normNJets.push_back({hsimpartjetNormNJetsEta[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 1, 5e+2*hsimjetEta[0]->GetMaximum(), HfJetTagging::X_AXIS_JETETA, HfJetTagging::Y_AXIS_JETETA);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjeteta.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/hsimjetEta[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETETA, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetetaNormArea.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETETA, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETETA.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetetaNormNEvents.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETETA, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETETA.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetetaNormNJets.pdf\")", nc++, dirSimGen.Data()));
}

void HfJetTaggingAnalysis::drawSimpartJetPhi(bool withInc = false, bool doLog = true) {
  for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    hsimpartjetNormAreaPhi[flavour] = (TH1F*) hsimpartjetPhi[flavour]->Clone();
    hsimpartjetNormAreaPhi[flavour]->Scale(1. / hsimpartjetNormAreaPhi[flavour]->Integral());
    hsimpartjetNormNEventsPhi[flavour] = (TH1F*) hsimpartjetPhi[flavour]->Clone();
    hsimpartjetNormNEventsPhi[flavour]->Scale(1. / nsimEvents);
    hsimpartjetNormNJetsPhi[flavour] = (TH1F*) hsimpartjetPhi[flavour]->Clone();
    hsimpartjetNormNJetsPhi[flavour]->Scale(1. / nsimJets[flavour][0]);
  }
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimpartjetPhi[0], HfJetTagging::INCJET});
  rawHist.push_back({hsimpartjetPhi[1], HfJetTagging::CJET});
  rawHist.push_back({hsimpartjetPhi[2], HfJetTagging::BJET});
  rawHist.push_back({hsimpartjetPhi[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normArea;
  normArea.push_back({hsimpartjetNormAreaPhi[0], HfJetTagging::INCJET});
  normArea.push_back({hsimpartjetNormAreaPhi[1], HfJetTagging::CJET});
  normArea.push_back({hsimpartjetNormAreaPhi[2], HfJetTagging::BJET});
  normArea.push_back({hsimpartjetNormAreaPhi[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNEvents;
  normNEvents.push_back({hsimpartjetNormNEventsPhi[0], HfJetTagging::INCJET});
  normNEvents.push_back({hsimpartjetNormNEventsPhi[1], HfJetTagging::CJET});
  normNEvents.push_back({hsimpartjetNormNEventsPhi[2], HfJetTagging::BJET});
  normNEvents.push_back({hsimpartjetNormNEventsPhi[3], HfJetTagging::LFJET});

  std::vector<HistogramData> normNJets;
  normNJets.push_back({hsimpartjetNormNJetsPhi[0], HfJetTagging::INCJET});
  normNJets.push_back({hsimpartjetNormNJetsPhi[1], HfJetTagging::CJET});
  normNJets.push_back({hsimpartjetNormNJetsPhi[2], HfJetTagging::BJET});
  normNJets.push_back({hsimpartjetNormNJetsPhi[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 1, 5e+2*hsimjetPhi[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPHI, HfJetTagging::Y_AXIS_JETPHI);
  canHan->drawCombined(rawHist.size(), rawHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetphi.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/hsimjetPhi[0]->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPHI, HfJetTagging::AXIS_PROB);
  canHan->drawCombined(normArea.size(), normArea, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetphiNormArea.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/nsimEvents, 1, HfJetTagging::X_AXIS_JETPHI, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPHI.Data()));
  canHan->drawCombined(normNEvents.size(), normNEvents, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetphiNormNEvents.pdf\")", nc++, dirSimGen.Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.14);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], 5e-2/nsimJets[0][0], 1, HfJetTagging::X_AXIS_JETPHI, Form("#frac{1}{%s} %s", HfJetTagging::AXIS_NEVENTS.Data(), HfJetTagging::Y_AXIS_JETPHI.Data()));
  canHan->drawCombined(normNJets.size(), normNJets, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetphiNormNJets.pdf\")", nc++, dirSimGen.Data()));
}

void HfJetTaggingAnalysis::drawSimpartFlavourMatchingEffi() {
  std::vector<HistogramData> histListMatchingEffi;
  std::vector<HistogramData> histListCharmJetMatchingEffi;
  std::vector<HistogramData> histListBeautyJetMatchingEffi;
  std::vector<HistogramData> histListLfJetMatchingEffi;
  histListMatchingEffi.push_back({hsimpartFlavourMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListCharmJetMatchingEffi.push_back({hsimpartCharmJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListBeautyJetMatchingEffi.push_back({hsimpartBeautyJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListLfJetMatchingEffi.push_back({hsimpartLfJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue;
      int matchedFlavour = hsimpartFlavourMatchedFlavour[flavour][binJetPt]->GetBinContent(flavour);
      int missBin[2] = { (flavour % 3) + 1, ((flavour + 1) % 3) + 1 };
      int missMatchedFlavour[2] = {static_cast<int>(hsimpartFlavourMatchedFlavour[flavour][binJetPt]->GetBinContent(missBin[0])) , static_cast<int>(hsimpartFlavourMatchedFlavour[flavour][binJetPt]->GetBinContent(missBin[1]))};
      if (missMatchedFlavour[0] < 1 || missMatchedFlavour[1] < 1) continue;
      int missMatched = missMatchedFlavour[0] + missMatchedFlavour[1];
      float effi =  (float) matchedFlavour / (matchedFlavour+missMatched);
      hsimpartFlavourMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
      hsimpartFlavourMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      std::cout << "DEBUG: " << " JET FLAVOUR: " << flavour << ", " << HfJetTagging::FLAVOURJET[flavour] << " missBin: " << missBin[0] << " " << missBin[1] << std::endl;
      if (flavour==1) {
        hsimpartCharmJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        //hsimCharmJetMatchingEffi[(flavour %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimpartCharmJetMatchingEffi[missBin[0]]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimpartCharmJetMatchingEffi[missBin[1]]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      if (flavour==2) {
        hsimpartBeautyJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        hsimpartBeautyJetMatchingEffi[missBin[0]]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimpartBeautyJetMatchingEffi[missBin[1]]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      if (flavour==3) {
        hsimpartLfJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        hsimpartLfJetMatchingEffi[(flavour %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimpartLfJetMatchingEffi[((flavour+1) %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      hsimpartCharmJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      hsimpartBeautyJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      hsimpartLfJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
    }
    histListMatchingEffi.push_back({hsimpartFlavourMatchingEffi[flavour], HfJetTagging::FLAVOURJET[flavour]});
    if (flavour==1) {
      histListCharmJetMatchingEffi.push_back({hsimpartCharmJetMatchingEffi[flavour], "c to c (matched)"});
      histListCharmJetMatchingEffi.push_back({hsimpartCharmJetMatchingEffi[(flavour%3)+1], "c to b (miss matched)"});
      histListCharmJetMatchingEffi.push_back({hsimpartCharmJetMatchingEffi[((flavour+1)%3)+1], "c to lf (miss matched)"});
    }
    if (flavour==2) {
      histListBeautyJetMatchingEffi.push_back({hsimpartBeautyJetMatchingEffi[(flavour%3)+1], "b to lf (miss matched)"});
      histListBeautyJetMatchingEffi.push_back({hsimpartBeautyJetMatchingEffi[flavour], "b to b (matched)"});
      histListBeautyJetMatchingEffi.push_back({hsimpartBeautyJetMatchingEffi[((flavour+1)%3)+1], "b to c (miss matched)"});
    }
    if (flavour==3) {
      histListLfJetMatchingEffi.push_back({hsimpartLfJetMatchingEffi[(flavour%3)+1], "lf to c (miss matched)"});
      histListLfJetMatchingEffi.push_back({hsimpartLfJetMatchingEffi[((flavour+1)%3)+1], "lf to b (miss matched)"});
      histListLfJetMatchingEffi.push_back({hsimpartLfJetMatchingEffi[flavour], "lf to lf (matched)"});
    }
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListMatchingEffi.size(), histListMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partFlavourMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListCharmJetMatchingEffi.size(), histListCharmJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partCharmJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListBeautyJetMatchingEffi.size(), histListBeautyJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partBeautyJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListLfJetMatchingEffi.size(), histListLfJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partLfJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::drawSimFlavourMatchingEffi() {
  std::vector<HistogramData> histListMatchingEffi;
  std::vector<HistogramData> histListCharmJetMatchingEffi;
  std::vector<HistogramData> histListBeautyJetMatchingEffi;
  std::vector<HistogramData> histListLfJetMatchingEffi;
  histListMatchingEffi.push_back({hsimFlavourMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListCharmJetMatchingEffi.push_back({hsimCharmJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListBeautyJetMatchingEffi.push_back({hsimBeautyJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListLfJetMatchingEffi.push_back({hsimLfJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue;
      int matchedFlavour = hsimFlavourMatchingFlavourRun2Def[flavour][binJetPt]->GetBinContent(flavour);
      int missBin[2] = { (flavour % 3) + 1, ((flavour + 1) % 3) + 1 };
      int missMatchedFlavour[2] = {static_cast<int>(hsimFlavourMatchingFlavourRun2Def[flavour][binJetPt]->GetBinContent(missBin[0])) , static_cast<int>(hsimFlavourMatchingFlavourRun2Def[flavour][binJetPt]->GetBinContent(missBin[1]))};
      if (missMatchedFlavour[0] < 1 || missMatchedFlavour[1] < 1) continue;
      int missMatched = missMatchedFlavour[0] + missMatchedFlavour[1];
      float effi =  (float) matchedFlavour / (matchedFlavour+missMatched);
      hsimFlavourMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
      hsimFlavourMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      std::cout << "DEBUG: " << " JET FLAVOUR: " << flavour << ", " << HfJetTagging::FLAVOURJET[flavour] << " missBin: " << missBin[0] << " " << missBin[1] << std::endl;
      if (flavour==1) {
        hsimCharmJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        //hsimCharmJetMatchingEffi[(flavour %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimCharmJetMatchingEffi[missBin[0]]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimCharmJetMatchingEffi[missBin[1]]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      if (flavour==2) {
        hsimBeautyJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        hsimBeautyJetMatchingEffi[missBin[0]]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimBeautyJetMatchingEffi[missBin[1]]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      if (flavour==3) {
        hsimLfJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        hsimLfJetMatchingEffi[(flavour %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimLfJetMatchingEffi[((flavour+1) %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      hsimCharmJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      hsimBeautyJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      hsimLfJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
    }
    histListMatchingEffi.push_back({hsimFlavourMatchingEffi[flavour], HfJetTagging::FLAVOURJET[flavour]});
    if (flavour==1) {
      histListCharmJetMatchingEffi.push_back({hsimCharmJetMatchingEffi[flavour], "c to c (matched)"});
      histListCharmJetMatchingEffi.push_back({hsimCharmJetMatchingEffi[(flavour%3)+1], "c to b (miss matched)"});
      histListCharmJetMatchingEffi.push_back({hsimCharmJetMatchingEffi[((flavour+1)%3)+1], "c to lf (miss matched)"});
    }
    if (flavour==2) {
      histListBeautyJetMatchingEffi.push_back({hsimBeautyJetMatchingEffi[(flavour%3)+1], "b to lf (miss matched)"});
      histListBeautyJetMatchingEffi.push_back({hsimBeautyJetMatchingEffi[flavour], "b to b (matched)"});
      histListBeautyJetMatchingEffi.push_back({hsimBeautyJetMatchingEffi[((flavour+1)%3)+1], "b to c (miss matched)"});
    }
    if (flavour==3) {
      histListLfJetMatchingEffi.push_back({hsimLfJetMatchingEffi[(flavour%3)+1], "lf to c (miss matched)"});
      histListLfJetMatchingEffi.push_back({hsimLfJetMatchingEffi[((flavour+1)%3)+1], "lf to b (miss matched)"});
      histListLfJetMatchingEffi.push_back({hsimLfJetMatchingEffi[flavour], "lf to lf (matched)"});
    }
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListMatchingEffi.size(), histListMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/FlavourMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListCharmJetMatchingEffi.size(), histListCharmJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/CharmJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListBeautyJetMatchingEffi.size(), histListBeautyJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/BeautyJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListLfJetMatchingEffi.size(), histListLfJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/LfJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::drawSimMatchedFlavourMatchingEffi() {
  std::vector<HistogramData> histListMatchingEffi;
  std::vector<HistogramData> histListCharmJetMatchingEffi;
  std::vector<HistogramData> histListBeautyJetMatchingEffi;
  std::vector<HistogramData> histListLfJetMatchingEffi;
  histListMatchingEffi.push_back({hsimMatchedFlavourMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListCharmJetMatchingEffi.push_back({hsimMatchedCharmJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListBeautyJetMatchingEffi.push_back({hsimMatchedBeautyJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  histListLfJetMatchingEffi.push_back({hsimMatchedLfJetMatchingEffi[0], HfJetTagging::INCJET}); // dummy
  for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
    for (int binJetPt = HfJetTagging::startJetPt+1; binJetPt <= HfJetTagging::nBinsJetPt; binJetPt++) {
      if (binJetPt < 1) continue;
      int matchedFlavour = hsimMatchedFlavourMatchingFlavourRun2Def[flavour][binJetPt]->GetBinContent(flavour);
      int missBin[2] = { (flavour % 3) + 1, ((flavour + 1) % 3) + 1 };
      int missMatchedFlavour[2] = {static_cast<int>(hsimMatchedFlavourMatchingFlavourRun2Def[flavour][binJetPt]->GetBinContent(missBin[0])) , static_cast<int>(hsimMatchedFlavourMatchingFlavourRun2Def[flavour][binJetPt]->GetBinContent(missBin[1]))};
      if (missMatchedFlavour[0] < 1 || missMatchedFlavour[1] < 1) continue;
      int missMatched = missMatchedFlavour[0] + missMatchedFlavour[1];
      float effi =  (float) matchedFlavour / (matchedFlavour+missMatched);
      hsimMatchedFlavourMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
      hsimMatchedFlavourMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      std::cout << "DEBUG: " << " JET FLAVOUR: " << flavour << ", " << HfJetTagging::FLAVOURJET[flavour] << " missBin: " << missBin[0] << " " << missBin[1] << std::endl;
      if (flavour==1) {
        hsimMatchedCharmJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        //hsimMatchedCharmJetMatchingEffi[(flavour %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimMatchedCharmJetMatchingEffi[missBin[0]]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimMatchedCharmJetMatchingEffi[missBin[1]]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      if (flavour==2) {
        hsimMatchedBeautyJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        hsimMatchedBeautyJetMatchingEffi[missBin[0]]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimMatchedBeautyJetMatchingEffi[missBin[1]]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      if (flavour==3) {
        hsimMatchedLfJetMatchingEffi[flavour]->SetBinContent(binJetPt, effi);
        hsimMatchedLfJetMatchingEffi[(flavour %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[0] / (matchedFlavour+missMatched));
        hsimMatchedLfJetMatchingEffi[((flavour+1) %3)+1]->SetBinContent(binJetPt, (float) missMatchedFlavour[1] / (matchedFlavour+missMatched));
      }
      hsimMatchedCharmJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      hsimMatchedBeautyJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
      hsimMatchedLfJetMatchingEffi[flavour]->SetBinError(binJetPt, 0);
    }
    histListMatchingEffi.push_back({hsimMatchedFlavourMatchingEffi[flavour], HfJetTagging::FLAVOURJET[flavour]});
    if (flavour==1) {
      histListCharmJetMatchingEffi.push_back({hsimMatchedCharmJetMatchingEffi[flavour], "c to c (matched)"});
      histListCharmJetMatchingEffi.push_back({hsimMatchedCharmJetMatchingEffi[(flavour%3)+1], "c to b (miss matched)"});
      histListCharmJetMatchingEffi.push_back({hsimMatchedCharmJetMatchingEffi[((flavour+1)%3)+1], "c to lf (miss matched)"});
    }
    if (flavour==2) {
      histListBeautyJetMatchingEffi.push_back({hsimMatchedBeautyJetMatchingEffi[(flavour%3)+1], "b to lf (miss matched)"});
      histListBeautyJetMatchingEffi.push_back({hsimMatchedBeautyJetMatchingEffi[flavour], "b to b (matched)"});
      histListBeautyJetMatchingEffi.push_back({hsimMatchedBeautyJetMatchingEffi[((flavour+1)%3)+1], "b to c (miss matched)"});
    }
    if (flavour==3) {
      histListLfJetMatchingEffi.push_back({hsimMatchedLfJetMatchingEffi[(flavour%3)+1], "lf to c (miss matched)"});
      histListLfJetMatchingEffi.push_back({hsimMatchedLfJetMatchingEffi[((flavour+1)%3)+1], "lf to b (miss matched)"});
      histListLfJetMatchingEffi.push_back({hsimMatchedLfJetMatchingEffi[flavour], "lf to lf (matched)"});
    }
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListMatchingEffi.size(), histListMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/matchedFlavourMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListCharmJetMatchingEffi.size(), histListCharmJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/matchedCharmJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListBeautyJetMatchingEffi.size(), histListBeautyJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/matchedBeautyJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::EFFI[0], HfJetTagging::REFHIST::EFFI[1], HfJetTagging::REFHIST::EFFI[2], HfJetTagging::REFHIST::EFFI[3], HfJetTagging::X_AXIS_JETPT, "flavour mat effi");
  canHan->drawCombined(histListLfJetMatchingEffi.size(), histListLfJetMatchingEffi, false, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/matchedLfJetMatchingEffi.pdf\")", nc++, dirSimIP.Data()));
}

void HfJetTaggingAnalysis::drawSimRawJetPtMatched(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetPtMatched[0], HfJetTagging::INCJET});
  histList.push_back({hsimjetPtMatched[1], HfJetTagging::CJET});
  histList.push_back({hsimjetPtMatched[2], HfJetTagging::BJET});
  histList.push_back({hsimjetPtMatched[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 1e+4*hsimjetPtMatched[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histList.size(), histList, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentummatched.pdf\")", nc++, dirSimIP.Data()));


}

void HfJetTaggingAnalysis::drawSimResMat(int flavour) {

  TH2F* hresMat = (TH2F*) h2simjetPtpartjetPtMatched[flavour]->Clone("hresMat");
  TH2F* hresMatRebin = new TH2F("hresMatRebinTemp", "", unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::rebin2DHist(hresMat, hresMatRebin, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  TH2F* hresMatInv = (TH2F*) h2simpartjetPtjetPtMatched[flavour]->Clone("hresMatInv");
  TH2F* hresMatInvRebin = new TH2F("hresMatInverseRebin", "", unfold::nBinsMCPJetPt, unfold::binsMCPJetPt, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt);
  taggingutilities::rebin2DHist(hresMatInv, hresMatInvRebin, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt);

  h2simjetPtpartjetPtMatchedRebin[flavour] = (TH2F*) hresMatRebin->Clone("hresMatRebin"); // for saving
  h2simpartjetPtjetPtMatchedRebin[flavour] = (TH2F*) hresMatInvRebin->Clone("hresMatInvRebin"); // for saving

  std::vector<TH1F*> hRelDiff = taggingutilities::makeRelativePtDiffHists(hresMat, unfold::nBinsJetPt, unfold::binsJetPt);
  std::vector<HistogramData> histRel;
  int startBin = 3;
  int endBin = startBin + 3;
  while (startBin < endBin) {
    histRel.push_back({hRelDiff[startBin], Form("%0.f < jet pt < %0.f", unfold::binsJetPt[startBin], unfold::binsJetPt[startBin+1])});
    startBin++;
  }

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.12, 0.10, 0.05, 0.12, 1110);
  canHan->setHistogram2D(hresMat, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::X_AXIS_RECJETPT, HfJetTagging::X_AXIS_TRUEJETPT, 1.10, 1.20, 111111);
  hresMat->Draw("colz");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/resmat.pdf\")", nc++, dirSimResMat.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600, 0.12, 0.10, 0.05, 0.12, 1110);
  gPad->SetLogz();
  canHan->setHistogram2D(hresMat, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::X_AXIS_RECJETPT, HfJetTagging::X_AXIS_TRUEJETPT, 1.10, 1.20, 111111);
  hresMat->Draw("colz");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/resmatLog.pdf\")", nc++, dirSimResMat.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.12, 0.10, 0.05, 0.12, 1110);
  canHan->setHistogram2D(hresMatRebin, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::X_AXIS_RECJETPT, HfJetTagging::X_AXIS_TRUEJETPT, 1.10, 1.20, 111111);
  hresMatRebin->SetMinimum(1e-6);
  hresMatRebin->Draw("colz");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/resmatRebin.pdf\")", nc++, dirSimResMat.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createCanvas(nc, 0, 0, 800, 600, 0.12, 0.10, 0.05, 0.12, 1110);
  gPad->SetLogz();
  canHan->setHistogram2D(hresMatRebin, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::X_AXIS_RECJETPT, HfJetTagging::X_AXIS_TRUEJETPT, 1.10, 1.20, 111111);
  hresMatRebin->SetMinimum(1e-6);
  hresMatRebin->Draw("colz");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/resmatRebinLog.pdf\")", nc++, dirSimResMat.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600);
  canHan->drawRefHistogram(nc, -1, 1, 5e-6, hRelDiff[0]->GetMaximum(), Form("(%s - %s) / %s (GeV/#it{c})", HfJetTagging::AXIS_RECO_JETPT.Data(), HfJetTagging::AXIS_TRUE_JETPT.Data(), HfJetTagging::AXIS_TRUE_JETPT.Data()), HfJetTagging::AXIS_PROB.Data());
  latexSimJetInfo(0.60, 0.90, 0, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.028);
  hRelDiff[0]->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/relativeMomentumDiff.pdf\")", nc++, dirSimResMat.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan = new CanvasHandler();
  canHan->createCanvas(nc, 0, 0, 800, 600);
  canHan->drawRefHistogram(nc, -1, 1, 5e-6, 5e-1*hRelDiff[0]->GetMaximum(), Form("(%s - %s) / %s (GeV/#it{c})", HfJetTagging::AXIS_RECO_JETPT.Data(), HfJetTagging::AXIS_TRUE_JETPT.Data(), HfJetTagging::AXIS_TRUE_JETPT.Data()), HfJetTagging::AXIS_PROB.Data());
  latexSimJetInfo(0.55, 0.90, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.028);
  canHan->drawCombined(histRel.size(), histRel, true, true, 0.55, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/relativeMomentumDiffWithPtRange.pdf\")", nc++, dirSimResMat.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
  delete hresMat;
  delete hresMatRebin;
  delete hresMatInv;
  delete hresMatInvRebin;
  for (auto* h : hRelDiff) {
    delete h;
  }
  hRelDiff.clear();
}


void HfJetTaggingAnalysis::drawTrackEfficiency(bool withInc = false, bool doLog = true) {

}

void HfJetTaggingAnalysis::drawJetEfficiency(bool doLog = true, int flavour = 2) {
  // N_matched_true / N_true
  // hsimpartjetPtMatched[flavour] / hsimpartjetPt[flavour]
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimpartjetPtMatched[flavour], Form("matched true %s jet", HfJetTagging::FLAVOUR[flavour].Data())});
  rawHist.push_back({hsimpartjetPt[flavour], Form("true %s jet", HfJetTagging::FLAVOUR[flavour].Data())});
  TH1F *hRatio = static_cast<TH1F*>(hsimpartjetPtMatched[flavour]->Clone("hRatio"));
  hRatio->Divide(hsimpartjetPt[flavour]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hsimpartjetPt[flavour]->GetMaximum(), "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());

  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0, 1.15, HfJetTagging::X_AXIS_JETPT, "Jet matching efficiency");
  hRatio->Draw("same");
  
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetRecoEffi.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawJetPurity(bool doLog = true, int flavour = 2) {
  // N_matched_reco / N_reco
  // hsimjetPtMatched[flavour] / hsimjetPt[flavour]
  std::vector<HistogramData> rawHist;
  rawHist.push_back({hsimjetPtMatched[flavour], Form("matched reco %s jet", HfJetTagging::FLAVOUR[flavour].Data())});
  rawHist.push_back({hsimjetPt[flavour], Form("reco %s jet", HfJetTagging::FLAVOUR[flavour].Data())});
  TH1F *hRatio = static_cast<TH1F*>(hsimjetPtMatched[flavour]->Clone("hRatio"));
  hRatio->Divide(hsimjetPt[flavour]);

  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-3, 5e+2*hsimjetPt[flavour]->GetMaximum(), "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.48, 0.57, HfJetTagging::LEG[2], HfJetTagging::LEG[3], 0.045);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());

  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.5, 1.5, HfJetTagging::X_AXIS_JETPT, "Jet purity");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetPurity.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::unfoldingJet(bool doLog, int flavour, int n_iter = 4, int k_reg = 16, bool fromExternal = false) {
  // It needs RooUnfold
  //gSystem->Load("/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Analysis/RooUnfold/build/libRooUnfold.dylib");
  
  if (!(fillMCD && fillMCP && fillMatched)) {
    return;
  }
  TH2F* hresMat = nullptr;
  TString extSuffix = "";
  if (!fromExternal) {
    hresMat = (TH2F*) h2simjetPtpartjetPtMatched[flavour]->Clone();
  } else {
    hresMat = (TH2F*) h2externalsimjetPtpartjetPtMatched[flavour]->Clone();
    extSuffix = "FromExt";
  }
  TH2F* hresMatTemp = (TH2F*) hresMat->Clone();
  TH2F* hresMatNormMCP = (TH2F*) hresMat->Clone();
  taggingutilities::normalize2DHist(hresMatNormMCP);
  TH2F* hresMatNormTotal = (TH2F*) hresMat->Clone();
  taggingutilities::normalize2DHistTotal(hresMatNormTotal);
  TH1F* hsimjetPtMatchedNormArea = (TH1F*) hsimjetPtMatched[flavour]->Clone();
  hsimjetPtMatchedNormArea->Scale(1. / hsimjetPtMatchedNormArea->Integral());
  TH1F* hsimpartjetPtMatchedNormArea = (TH1F*) hsimpartjetPtMatched[flavour]->Clone();
  hsimpartjetPtMatchedNormArea->Scale(1. / hsimpartjetPtMatchedNormArea->Integral());

  // rebin
  TH2F* hresMatRebin = new TH2F("hresMatRebin", "", unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::rebin2DHist(hresMat, hresMatRebin, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  TH2F* hresMatRebinNormMCP = new TH2F("hresMatRebinNormMCP", "", unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::rebin2DHist(hresMat, hresMatRebinNormMCP, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::normalize2DHist(hresMatRebinNormMCP);
  TH2F* hresMatRebinNormTotal = new TH2F("hresMatRebinNormTotal", "", unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::rebin2DHist(hresMat, hresMatRebinNormTotal, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::normalize2DHist(hresMatRebinNormTotal);
  TH1F* hsimjetPtMatchedRebinNormArea = (TH1F*) hsimjetPtMatchedNormArea->Rebin(unfold::nBinsMCDJetPt, "", unfold::binsMCDJetPt);
  TH1F* hsimpartjetPtMatchedRebinNormArea = (TH1F*) hsimpartjetPtMatchedNormArea->Rebin(unfold::nBinsMCPJetPt, "", unfold::binsMCPJetPt);

  // response matrix
  RooUnfoldResponse resMat(hsimjetPtMatched[flavour], hsimpartjetPtMatched[flavour], hresMat, "", "", false);
  RooUnfoldResponse resMatNormMCP(hsimjetPtMatchedNormArea, hsimpartjetPtMatchedNormArea, hresMatNormMCP, "", "", false);
  RooUnfoldResponse resMatNormTotal(hsimjetPtMatchedNormArea, hsimpartjetPtMatchedNormArea, hresMatNormTotal, "", "", false);
  RooUnfoldResponse resMatRebin(hsimjetPtMatchedRebin[flavour], hsimpartjetPtMatchedRebin[flavour], hresMatRebin, "", "", false);
  RooUnfoldResponse resMatRebinNormMCP(hsimjetPtMatchedRebinNormArea, hsimpartjetPtMatchedRebinNormArea, hresMatRebinNormMCP, "", "", false);
  RooUnfoldResponse resMatRebinNormTotal(hsimjetPtMatchedRebinNormArea, hsimpartjetPtMatchedRebinNormArea, hresMatRebinNormTotal, "", "", false);

  // doing unfolding
  RooUnfoldBayes unfoldBayes(&resMat, hsimjetPtMatched[flavour], n_iter);
  RooUnfoldBayes unfoldBayesNormMCP(&resMatNormMCP, hsimjetPtMatchedNormArea, n_iter);
  RooUnfoldBayes unfoldBayesNormTotal(&resMatNormTotal, hsimjetPtMatchedNormArea, n_iter);
  RooUnfoldBayes unfoldBayesRebin(&resMatRebin, hsimjetPtMatchedRebin[flavour], n_iter);
  RooUnfoldBayes unfoldBayesRebinNormMCP(&resMatRebinNormMCP, hsimjetPtMatchedRebinNormArea, n_iter);
  RooUnfoldBayes unfoldBayesRebinNormTotal(&resMatRebinNormTotal, hsimjetPtMatchedRebinNormArea, n_iter);
  RooUnfoldSvd unfoldSvd(&resMat, hsimjetPtMatched[flavour], k_reg);
  RooUnfoldSvd unfoldSvdNormMCP(&resMatNormMCP, hsimjetPtMatchedNormArea, k_reg);
  RooUnfoldSvd unfoldSvdNormTotal(&resMatNormTotal, hsimjetPtMatchedNormArea, k_reg);
  RooUnfoldSvd unfoldSvdRebin(&resMatRebin, hsimjetPtMatchedRebin[flavour], k_reg);
  RooUnfoldSvd unfoldSvdRebinNormMCP(&resMatRebinNormMCP, hsimjetPtMatchedRebinNormArea, k_reg);
  RooUnfoldSvd unfoldSvdRebinNormTotal(&resMatRebinNormTotal, hsimjetPtMatchedRebinNormArea, k_reg);

  TH1F* hsimjetPtUnfoldedBayes = (TH1F*) unfoldBayes.Hunfold();
  TH1F* hsimjetPtUnfoldedBayesNormMCP = (TH1F*) unfoldBayesNormMCP.Hunfold();
  TH1F* hsimjetPtUnfoldedBayesNormTotal = (TH1F*) unfoldBayesNormTotal.Hunfold();
  TH1F* hsimjetPtUnfoldedBayesRebin = (TH1F*) unfoldBayesRebin.Hunfold();
  TH1F* hsimjetPtUnfoldedBayesRebinNormMCP = (TH1F*) unfoldBayesRebinNormMCP.Hunfold();
  TH1F* hsimjetPtUnfoldedBayesRebinNormTotal = (TH1F*) unfoldBayesRebinNormTotal.Hunfold();
  TH1F* hsimjetPtUnfoldedSvd = (TH1F*) unfoldSvd.Hunfold();
  TH1F* hsimjetPtUnfoldedSvdNormMCP = (TH1F*) unfoldSvdNormMCP.Hunfold();
  TH1F* hsimjetPtUnfoldedSvdNormTotal = (TH1F*) unfoldSvdNormTotal.Hunfold();
  TH1F* hsimjetPtUnfoldedSvdRebin = (TH1F*) unfoldSvdRebin.Hunfold();
  TH1F* hsimjetPtUnfoldedSvdRebinNormMCP = (TH1F*) unfoldSvdRebinNormMCP.Hunfold();
  TH1F* hsimjetPtUnfoldedSvdRebinNormTotal = (TH1F*) unfoldSvdRebinNormTotal.Hunfold();

  // calculation of ratio for validation of unfolding on MC level
  TH1F *hRatioBayes = static_cast<TH1F*>(hsimjetPtUnfoldedBayes->Clone(""));
  TH1F *hRatioBayesNormMCP = static_cast<TH1F*>(hsimjetPtUnfoldedBayesNormMCP->Clone(""));
  TH1F *hRatioBayesNormTotal = static_cast<TH1F*>(hsimjetPtUnfoldedBayesNormTotal->Clone(""));
  TH1F *hRatioBayesRebin = static_cast<TH1F*>(hsimjetPtUnfoldedBayesRebin->Clone(""));
  TH1F *hRatioBayesRebinNormMCP = static_cast<TH1F*>(hsimjetPtUnfoldedBayesRebinNormMCP->Clone(""));
  TH1F *hRatioBayesRebinNormTotal = static_cast<TH1F*>(hsimjetPtUnfoldedBayesRebinNormTotal->Clone(""));
  TH1F *hRatioSvd = static_cast<TH1F*>(hsimjetPtUnfoldedSvd->Clone(""));
  TH1F *hRatioSvdNormMCP = static_cast<TH1F*>(hsimjetPtUnfoldedSvdNormMCP->Clone(""));
  TH1F *hRatioSvdNormTotal = static_cast<TH1F*>(hsimjetPtUnfoldedSvdNormTotal->Clone(""));
  TH1F *hRatioSvdRebin = static_cast<TH1F*>(hsimjetPtUnfoldedSvdRebin->Clone(""));
  TH1F *hRatioSvdRebinNormMCP = static_cast<TH1F*>(hsimjetPtUnfoldedSvdRebinNormMCP->Clone(""));
  TH1F *hRatioSvdRebinNormTotal = static_cast<TH1F*>(hsimjetPtUnfoldedSvdRebinNormTotal->Clone(""));

  hRatioBayes->Divide(hsimpartjetPtMatched[flavour]);
  hRatioSvd->Divide(hsimpartjetPtMatched[flavour]);

  //RooUnfoldBayes unfold(&resMat, hdatajetPt, n_iter);

	std::vector<HistogramData> histClosure;
	histClosure.push_back({hsimjetPtUnfoldedBayes, "unfolded Bayes"});
	histClosure.push_back({hsimjetPtUnfoldedSvd, "unfolded SVD"});
	histClosure.push_back({hsimjetPtMatched[flavour], "det matched"});
	histClosure.push_back({hsimpartjetPtMatched[flavour], "true matched"});

	std::vector<HistogramData> histClosureNormMCP;
	histClosureNormMCP.push_back({hsimjetPtUnfoldedBayesNormMCP, "unfolded Bayes"});
	histClosureNormMCP.push_back({hsimjetPtUnfoldedSvdNormMCP, "unfolded SVD"});
	histClosureNormMCP.push_back({hsimjetPtMatchedNormArea, "det matched"});
	histClosureNormMCP.push_back({hsimpartjetPtMatchedNormArea, "true matched"});

	std::vector<HistogramData> histClosureNormTotal;
	histClosureNormTotal.push_back({hsimjetPtUnfoldedBayesNormTotal, "unfolded Bayes"});
	histClosureNormTotal.push_back({hsimjetPtUnfoldedSvdNormTotal, "unfolded SVD"});
	histClosureNormTotal.push_back({hsimjetPtMatchedNormArea, "det matched"});
	histClosureNormTotal.push_back({hsimpartjetPtMatchedNormArea, "true matched"});

	std::vector<HistogramData> histClosureRebin;
	histClosureRebin.push_back({hsimjetPtUnfoldedBayesRebin, "unfolded Bayes"});
	histClosureRebin.push_back({hsimjetPtUnfoldedSvdRebin, "unfolded SVD"});
	histClosureRebin.push_back({hsimjetPtMatchedRebin[flavour], "det matched"});
	histClosureRebin.push_back({hsimpartjetPtMatchedRebin[flavour], "true matched"});

	std::vector<HistogramData> histClosureRebinNormMCP;
	histClosureRebinNormMCP.push_back({hsimjetPtUnfoldedBayesRebinNormMCP, "unfolded Bayes"});
	histClosureRebinNormMCP.push_back({hsimjetPtUnfoldedSvdRebinNormMCP, "unfolded SVD"});
	histClosureRebinNormMCP.push_back({hsimjetPtMatchedRebinNormArea, "det matched"});
	histClosureRebinNormMCP.push_back({hsimpartjetPtMatchedRebinNormArea, "true matched"});

  std::vector<HistogramData> histClosureRebinNormTotal;
  histClosureRebinNormTotal.push_back({hsimjetPtUnfoldedBayesRebinNormTotal, "unfolded Bayes"});
  histClosureRebinNormTotal.push_back({hsimjetPtUnfoldedSvdRebinNormTotal, "unfolded SVD"});
  histClosureRebinNormTotal.push_back({hsimjetPtMatchedRebinNormArea, "det matched"});
  histClosureRebinNormTotal.push_back({hsimpartjetPtMatchedRebinNormArea, "true matched"});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], 5e+2*hsimjetPtUnfoldedBayes->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosure.size(), histClosure, true, true);
  latex.DrawLatex(0.3, 0.9, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.3, 0.9, Form("regularization factor #it{k}_reg: %d", k_reg));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetmomentumUnfolded.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  std::vector<HistogramData> histRatio;
	histRatio.push_back({hRatioBayes, "Bayes"});
	histRatio.push_back({hRatioSvd, "SVD"});

  std::vector<HistogramData> histRatioNormMCP;
	histRatioNormMCP.push_back({hRatioBayesNormMCP, "Bayes"});
	histRatioNormMCP.push_back({hRatioSvdNormMCP, "SVD"});

  std::vector<HistogramData> histRatioNormTotal;
	histRatioNormTotal.push_back({hRatioBayesNormTotal, "Bayes"});
	histRatioNormTotal.push_back({hRatioSvdNormTotal, "SVD"});

  std::vector<HistogramData> histRatioRebin;
	histRatioRebin.push_back({hRatioBayesRebin, "Bayes"});
	histRatioRebin.push_back({hRatioSvdRebin, "SVD"});

  std::vector<HistogramData> histRatioRebinNormMCP;
	histRatioRebinNormMCP.push_back({hRatioBayesRebinNormMCP, "Bayes"});
	histRatioRebinNormMCP.push_back({hRatioSvdRebinNormMCP, "SVD"});

  std::vector<HistogramData> histRatioRebinNormTotal;
	histRatioRebinNormTotal.push_back({hRatioBayesRebinNormTotal, "Bayes"});
	histRatioRebinNormTotal.push_back({hRatioSvdRebinNormTotal, "SVD"});

  /// for d-vecotr
  TVectorD d_vector = taggingutilities::getDVector(&resMatRebin);

  int n_d = d_vector.GetNoElements();
  TH1D* hist_d_abs = new TH1D("hist_d_abs", "|d_i| Distribution for SVD Unfolding;i;|d_i|", n_d, 0.5, n_d + 0.5);

  // cc 
  canHan->createCanvas(nc);
  gPad->SetLogy();

  hist_d_abs->SetLineColor(kBlue);
  hist_d_abs->SetLineWidth(2);
  hist_d_abs->SetMarkerStyle(20);
  hist_d_abs->SetMarkerSize(0.8);
  hist_d_abs->SetMarkerColor(kBlue);
  hist_d_abs->Draw("P L");

  TLine* line_one = new TLine(0.5, 1.0, n_d + 0.5, 1.0);
  line_one->SetLineColor(kRed);
  line_one->SetLineStyle(2);
  line_one->Draw("same");

  TLatex* templatex = new TLatex();
  templatex->SetNDC();
  templatex->SetTextSize(0.035);
  templatex->SetTextColor(kRed);
  templatex->DrawLatex(0.7, 0.9, "|d_i| = 1");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/dvector.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hsimjetPtUnfoldedBayes->GetMaximum(), "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosure.size(), histClosure, true, true, 0.47, 0.35, 0.77, 0.75);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.63, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.48, 0.60, Form("regularization factor #it{k}_reg: %d", k_reg));
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histRatio.size(), histRatio, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedClosureTest%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayes->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosureNormMCP.size(), histClosureNormMCP, true, true, 0.47, 0.35, 0.77, 0.75);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.63, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.48, 0.60, Form("regularization factor #it{k}_reg: %d", k_reg));
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histRatioNormMCP.size(), histRatioNormMCP, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedClosureTestNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayes->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosureNormTotal.size(), histClosureNormTotal, true, true, 0.47, 0.35, 0.77, 0.75);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.63, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.48, 0.60, Form("regularization factor #it{k}_reg: %d", k_reg));
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histRatioNormTotal.size(), histRatioNormTotal, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedClosureTestNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hsimjetPtUnfoldedBayes->GetMaximum(), "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosureRebin.size(), histClosureRebin, true, true, 0.47, 0.35, 0.77, 0.75);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.63, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.48, 0.60, Form("regularization factor #it{k}_reg: %d", k_reg));
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histRatioRebin.size(), histRatioRebin, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedClosureTestRebin%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayesRebin->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosureRebinNormMCP.size(), histClosureRebinNormMCP, true, true, 0.47, 0.35, 0.77, 0.75);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.63, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.48, 0.60, Form("regularization factor #it{k}_reg: %d", k_reg));
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histRatioRebinNormMCP.size(), histRatioRebinNormMCP, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedClosureTestRebinNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayesRebin->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histClosureRebinNormTotal.size(), histClosureRebinNormTotal, true, true, 0.47, 0.35, 0.77, 0.75);
  latexSimJetInfo(0.48, 0.94, -1, "PYTHIA 8 + Geant 4", "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
  latex.DrawLatex(0.48, 0.63, Form("iteration #it{n}: %d", n_iter));
  latex.DrawLatex(0.48, 0.60, Form("regularization factor #it{k}_reg: %d", k_reg));
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histRatioRebinNormTotal.size(), histRatioRebinNormTotal, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedClosureTestRebinNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

//  // dependeces of chi2
//  const int maxIter = 20;
//  TH1F* hChi2 = new TH1F("hChi2", "Chi2 of change vs iteration", maxIter, 0, maxIter);
//
//  for (int i = 0; i < maxIter; ++i) {
//    RooUnfoldBayes tempUnfoldBayes(&resMat, hsimjetPtMatched[flavour], i);
//    double chi2 = tempUnfoldBayes.Chi2();
//
//    hChi2->SetBinContent(i+1, chi2);
//  }
//  canHan->createCanvas(nc);
//  canHan->drawRefHistogram(nc, 0, maxIter, 0, 5e+1*hChi2->GetMaximum(), "number of iteration", "chi2");
//  hChi2->Draw("same");
//  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/iterationChi2.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
//

  // dependeces of iteration number for bayesian
  const int maxIter = 6;
  std::vector<HistogramData> histDepIter;
  std::vector<HistogramData> histDepIterNormMCP;
  std::vector<HistogramData> histDepIterNormTotal;
  std::vector<HistogramData> histDepIterRebin;
  std::vector<HistogramData> histDepIterRebinNormMCP;
  std::vector<HistogramData> histDepIterRebinNormTotal;

  std::vector<HistogramData> histDepIterRatio;
  std::vector<HistogramData> histDepIterRatioNormMCP;
  std::vector<HistogramData> histDepIterRatioNormTotal;
  std::vector<HistogramData> histDepIterRatioRebin;
  std::vector<HistogramData> histDepIterRatioRebinNormMCP;
  std::vector<HistogramData> histDepIterRatioRebinNormTotal;
  for (int i = 2; i <= maxIter; i++) {
    RooUnfoldBayes tempUnfoldBayes(&resMat, hsimjetPtMatched[flavour], i);
    RooUnfoldBayes tempUnfoldBayesNormMCP(&resMatNormMCP, hsimjetPtMatchedNormArea, i);
    RooUnfoldBayes tempUnfoldBayesNormTotal(&resMatNormTotal, hsimjetPtMatchedNormArea, i);
    RooUnfoldBayes tempUnfoldBayesRebin(&resMatRebin, hsimjetPtMatchedRebin[flavour], i);
    RooUnfoldBayes tempUnfoldBayesRebinNormMCP(&resMatRebinNormMCP, hsimjetPtMatchedRebinNormArea, i);
    RooUnfoldBayes tempUnfoldBayesRebinNormTotal(&resMatRebinNormTotal, hsimjetPtMatchedRebinNormArea, i);

    TH1F* hunfoldedBayes = (TH1F*) tempUnfoldBayes.Hunfold();
    TH1F* hunfoldedBayesNormMCP = (TH1F*) unfoldBayesNormMCP.Hunfold();
    TH1F* hunfoldedBayesNormTotal = (TH1F*) unfoldBayesNormTotal.Hunfold();
    TH1F* hunfoldedBayesRebin = (TH1F*) unfoldBayesRebin.Hunfold();
    TH1F* hunfoldedBayesRebinNormMCP = (TH1F*) unfoldBayesRebinNormMCP.Hunfold();
    TH1F* hunfoldedBayesRebinNormTotal = (TH1F*) unfoldBayesRebinNormTotal.Hunfold();

    TH1F* hRatioBayesDep = static_cast<TH1F*>(hunfoldedBayes->Clone(""));
    TH1F* hRatioBayesNormMCPDep = static_cast<TH1F*>(hunfoldedBayesNormMCP->Clone(""));
    TH1F* hRatioBayesNormTotalDep = static_cast<TH1F*>(hunfoldedBayesNormTotal->Clone(""));
    TH1F* hRatioBayesRebinDep = static_cast<TH1F*>(hunfoldedBayesRebin->Clone(""));
    TH1F* hRatioBayesRebinNormMCPDep = static_cast<TH1F*>(hunfoldedBayesRebinNormMCP->Clone(""));
    TH1F* hRatioBayesRebinNormTotalDep = static_cast<TH1F*>(hunfoldedBayesRebinNormTotal->Clone(""));

    hRatioBayesDep->Divide(hsimpartjetPtMatched[flavour]);
    hRatioBayesNormMCPDep->Divide(hsimpartjetPtMatchedNormArea);
    hRatioBayesNormTotalDep->Divide(hsimpartjetPtMatchedNormArea);
    hRatioBayesRebinDep->Divide(hsimpartjetPtMatchedRebin[flavour]);
    hRatioBayesRebinNormMCPDep->Divide(hsimpartjetPtMatchedRebinNormArea);
    hRatioBayesRebinNormTotalDep->Divide(hsimpartjetPtMatchedRebinNormArea);

    histDepIter.push_back({hunfoldedBayes, Form("N of iter: %d", i)});
    histDepIterNormMCP.push_back({hunfoldedBayesNormMCP, Form("N of iter: %d", i)});
    histDepIterNormTotal.push_back({hunfoldedBayesNormTotal, Form("N of iter: %d", i)});
    histDepIterRebin.push_back({hunfoldedBayesRebin, Form("N of iter: %d", i)});
    histDepIterRebinNormMCP.push_back({hunfoldedBayesRebinNormMCP, Form("N of iter: %d", i)});
    histDepIterRebinNormTotal.push_back({hunfoldedBayesRebinNormTotal, Form("N of iter: %d", i)});

    histDepIterRatio.push_back({hRatioBayesDep, Form("N of iter: %d", i)});
    histDepIterRatioNormMCP.push_back({hRatioBayesNormMCPDep, Form("N of iter: %d", i)});
    histDepIterRatioNormTotal.push_back({hRatioBayesNormTotalDep, Form("N of iter: %d", i)});
    histDepIterRatioRebin.push_back({hRatioBayesRebinDep, Form("N of iter: %d", i)});
    histDepIterRatioRebinNormMCP.push_back({hRatioBayesRebinNormMCPDep, Form("N of iter: %d", i)});
    histDepIterRatioRebinNormTotal.push_back({hRatioBayesRebinNormTotalDep, Form("N of iter: %d", i)});
  }

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hsimjetPtUnfoldedBayes->GetMaximum(), "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histDepIter.size(), histDepIter, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIter%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayesNormMCP->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histDepIterNormMCP.size(), histDepIterNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayesNormTotal->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histDepIterNormTotal.size(), histDepIterNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hsimjetPtUnfoldedBayesRebin->GetMaximum(), "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histDepIterRebin.size(), histDepIterRebin, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebin%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayesRebinNormMCP->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histDepIterRebinNormMCP.size(), histDepIterRebinNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebinNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedBayesRebinNormTotal->GetMaximum(), 1, "", HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histDepIterRebinNormTotal.size(), histDepIterRebinNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebinNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepIterRatio.size(), histDepIterRatio, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRatio%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepIterRatioNormMCP.size(), histDepIterRatioNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRatioNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepIterRatioNormTotal.size(), histDepIterRatioNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRatioNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepIterRatioRebin.size(), histDepIterRatioRebin, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebinRatio%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepIterRatioRebinNormMCP.size(), histDepIterRatioRebinNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebinRatioNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepIterRatioRebinNormTotal.size(), histDepIterRatioRebinNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebinRatioNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  // depenences of regulatation nubmer for SVD
  int maxReg[6] = {2, 3, 4, 5, 6, 7};
  std::vector<HistogramData> histDepReg;
  std::vector<HistogramData> histDepRegNormMCP;
  std::vector<HistogramData> histDepRegNormTotal;
  std::vector<HistogramData> histDepRegRebin;
  std::vector<HistogramData> histDepRegRebinNormMCP;
  std::vector<HistogramData> histDepRegRebinNormTotal;

  std::vector<HistogramData> histDepRegRatio;
  std::vector<HistogramData> histDepRegRatioNormMCP;
  std::vector<HistogramData> histDepRegRatioNormTotal;
  std::vector<HistogramData> histDepRegRatioRebin;
  std::vector<HistogramData> histDepRegRatioRebinNormMCP;
  std::vector<HistogramData> histDepRegRatioRebinNormTotal;
  for (int i : maxReg) {
    RooUnfoldSvd tempUnfoldSvd(&resMat, hsimjetPtMatched[flavour], i);
    RooUnfoldSvd tempUnfoldSvdNormMCP(&resMatNormMCP, hsimjetPtMatchedNormArea, i);
    RooUnfoldSvd tempUnfoldSvdNormTotal(&resMatNormTotal, hsimjetPtMatchedNormArea, i);
    RooUnfoldSvd tempUnfoldSvdRebin(&resMatRebin, hsimjetPtMatchedRebin[flavour], i);
    RooUnfoldSvd tempUnfoldSvdRebinNormMCP(&resMatRebinNormMCP, hsimjetPtMatchedRebinNormArea, i);
    RooUnfoldSvd tempUnfoldSvdRebinNormTotal(&resMatRebinNormTotal, hsimjetPtMatchedRebinNormArea, i);

    TH1F* hunfoldedSvd = (TH1F*) tempUnfoldSvd.Hunfold();
    TH1F* hunfoldedSvdNormMCP = (TH1F*) unfoldSvdNormMCP.Hunfold();
    TH1F* hunfoldedSvdNormTotal = (TH1F*) unfoldSvdNormTotal.Hunfold();
    TH1F* hunfoldedSvdRebin = (TH1F*) tempUnfoldSvdRebin.Hunfold();
    TH1F* hunfoldedSvdRebinNormMCP = (TH1F*) unfoldSvdRebinNormMCP.Hunfold();
    TH1F* hunfoldedSvdRebinNormTotal = (TH1F*) unfoldSvdRebinNormTotal.Hunfold();

    TH1F* hRatioSvdDep = static_cast<TH1F*>(hunfoldedSvd->Clone(""));
    TH1F* hRatioSvdNormMCPDep = static_cast<TH1F*>(hunfoldedSvdNormMCP->Clone(""));
    TH1F* hRatioSvdNormTotalDep = static_cast<TH1F*>(hunfoldedSvdNormTotal->Clone(""));
    TH1F* hRatioSvdRebinDep = static_cast<TH1F*>(hunfoldedSvdRebin->Clone(""));
    TH1F* hRatioSvdRebinNormMCPDep = static_cast<TH1F*>(hunfoldedSvdRebinNormMCP->Clone(""));
    TH1F* hRatioSvdRebinNormTotalDep = static_cast<TH1F*>(hunfoldedSvdRebinNormTotal->Clone(""));

    hRatioSvdDep->Divide(hsimpartjetPtMatched[flavour]);
    hRatioSvdNormMCPDep->Divide(hsimpartjetPtMatchedNormArea);
    hRatioSvdNormTotalDep->Divide(hsimpartjetPtMatchedNormArea);
    hRatioSvdRebinDep->Divide(hsimpartjetPtMatchedRebin[flavour]);
    hRatioSvdRebinNormMCPDep->Divide(hsimpartjetPtMatchedRebinNormArea);
    hRatioSvdRebinNormTotalDep->Divide(hsimpartjetPtMatchedRebinNormArea);

    histDepReg.push_back({hunfoldedSvd, Form("N of reg: %d", i)});
    histDepRegNormMCP.push_back({hunfoldedSvdNormMCP, Form("N of reg: %d", i)});
    histDepRegNormTotal.push_back({hunfoldedSvdNormTotal, Form("N of reg: %d", i)});
    histDepRegRebin.push_back({hunfoldedSvdRebin, Form("N of reg: %d", i)});
    histDepRegRebinNormMCP.push_back({hunfoldedSvdRebinNormMCP, Form("N of reg: %d", i)});
    histDepRegRebinNormTotal.push_back({hunfoldedSvdRebinNormTotal, Form("N of reg: %d", i)});

    histDepRegRatio.push_back({hRatioSvdDep, Form("N of reg: %d", i)});
    histDepRegRatioNormMCP.push_back({hRatioSvdNormMCPDep, Form("N of reg: %d", i)});
    histDepRegRatioNormTotal.push_back({hRatioSvdNormTotalDep, Form("N of reg: %d", i)});
    histDepRegRatioRebin.push_back({hRatioSvdRebinDep, Form("N of reg: %d", i)});
    histDepRegRatioRebinNormMCP.push_back({hRatioSvdRebinNormMCPDep, Form("N of reg: %d", i)});
    histDepRegRatioRebinNormTotal.push_back({hRatioSvdRebinNormTotalDep, Form("N of reg: %d", i)});
  }

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hsimjetPtUnfoldedSvd->GetMaximum(), HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepReg.size(), histDepReg, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepReg%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedSvdNormMCP->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepRegNormMCP.size(), histDepRegNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedSvdNormTotal->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepRegNormTotal.size(), histDepRegNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hsimjetPtUnfoldedSvdRebin->GetMaximum(), HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepRegRebin.size(), histDepRegRebin, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebin%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedSvdRebinNormMCP->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepRegRebinNormMCP.size(), histDepRegRebinNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebinNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2/hsimjetPtUnfoldedSvdRebinNormTotal->GetMaximum(), 1, HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepRegRebinNormTotal.size(), histDepRegRebinNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebinNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepRegRatio.size(), histDepRegRatio, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRatio%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepRegRatioNormMCP.size(), histDepRegRatioNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRatioNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepRegRatioNormTotal.size(), histDepRegRatioNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRatioNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepRegRatioRebin.size(), histDepRegRatioRebin, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebinRatio%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepRegRatioRebinNormMCP.size(), histDepRegRatioRebinNormMCP, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebinRatioNormMCP%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / true jet");
  canHan->drawCombined(histDepRegRatioRebinNormTotal.size(), histDepRegRatioRebinNormTotal, true, true);
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebinRatioNormTotal%s.pdf\")", nc++, dirSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));
}

void HfJetTaggingAnalysis::unfoldingJetWithData(bool doLog, int flavour, int n_iter = 4, int k_reg = 6, bool fromExternal = false) {
  
  if (!fillData) {
    std::cout<< "There are no datas" <<std::endl;
    return;
  }
  if (!fillMCD) {
    std::cout << "MCD off" << std::endl;
    return;
  }

  TH2F* hresMat = nullptr;
  TH2F* hresMatInverse = nullptr;
  TString extSuffix = "";
  if (!fromExternal) {
    hresMat = (TH2F*) h2simjetPtpartjetPtMatched[flavour]->Clone();
    hresMatInverse = (TH2F*) h2simpartjetPtjetPtMatched[flavour]->Clone();
  } else {
    hresMat = (TH2F*) h2externalsimjetPtpartjetPtMatched[flavour]->Clone();
    extSuffix = "FromExt";
  }

  // rebin
  TH2F* hresMatRebin = new TH2F("hresMatRebin", "", unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);
  taggingutilities::rebin2DHist(hresMat, hresMatRebin, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt);

  TH2F* hresMatInverseRebin = new TH2F("hresMatRebin", "", unfold::nBinsMCPJetPt, unfold::binsMCPJetPt, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt);
  taggingutilities::rebin2DHist(hresMatInverse, hresMatInverseRebin, unfold::nBinsMCPJetPt, unfold::binsMCPJetPt, unfold::nBinsMCDJetPt, unfold::binsMCDJetPt);

  // response matrix
  RooUnfoldResponse resMat(hsimjetPtMatched[flavour], hsimpartjetPtMatched[flavour], h2simjetPtpartjetPtMatched[flavour], "", "", false);
  RooUnfoldResponse resMatRebin(hsimjetPtMatchedRebin[flavour], hsimpartjetPtMatchedRebin[flavour], hresMatRebin, "", "", false);
  RooUnfoldResponse resMatInverse(hsimpartjetPtMatched[flavour], hsimjetPtMatched[flavour], h2simpartjetPtjetPtMatched[flavour], "", "", false);
  RooUnfoldResponse resMatInverseRebin(hsimpartjetPtMatchedRebin[flavour], hsimjetPtMatchedRebin[flavour], hresMatInverseRebin, "", "", false);

  // doing unfolding
  RooUnfoldBayes unfoldBayes(&resMat, hdatajetPt, n_iter);
  RooUnfoldSvd unfoldSvd(&resMat, hdatajetPt, k_reg);
  TH1F* hdatajetPtUnfoldedBayes = (TH1F*) unfoldBayes.Hunfold();
  TH1F* hdatajetPtUnfoldedSvd = (TH1F*) unfoldSvd.Hunfold();
  RooUnfoldBayes refold(&resMatInverse, hdatajetPtUnfoldedBayes, n_iter);
  TH1F* hdatajetPtRefolded = (TH1F*) refold.Hunfold();

  // rebin hist
  RooUnfoldBayes unfoldBayesRebin(&resMatRebin, hdatajetPtRebin, n_iter);
  RooUnfoldSvd unfoldSvdRebin(&resMatRebin, hdatajetPtRebin, k_reg);
  TH1F* hdatajetPtUnfoldedBayesRebin = (TH1F*) unfoldBayesRebin.Hunfold();
  TH1F* hdatajetPtUnfoldedSvdRebin = (TH1F*) unfoldSvdRebin.Hunfold();
  RooUnfoldBayes refoldRebin(&resMatInverseRebin, hdatajetPtUnfoldedBayesRebin, n_iter);
  TH1F* hdatajetPtRefoldedRebin = (TH1F*) refoldRebin.Hunfold();

  TH1F* hRatioRefolded = (TH1F*) hdatajetPtRefolded->Clone("");
  hRatioRefolded->Divide(hdatajetPt);
  TH1F* hRatioRefoldedRebin = (TH1F*) hdatajetPtRefoldedRebin->Clone("");
  hRatioRefoldedRebin->Divide(hdatajetPtRebin);
  TH1F* hRatioBayesSvd = (TH1F*) hdatajetPtUnfoldedBayes->Clone("");
  hRatioBayesSvd->Divide(hdatajetPtUnfoldedSvd);
  if (debug) {
    std::cout << "data mean: " << hdatajetPtRebin->GetMean() << std::endl;
  }
  TH1F* hRatioBayesSvdRebin = (TH1F*) hdatajetPtUnfoldedBayesRebin->Clone("");
  hRatioBayesSvdRebin->Divide(hdatajetPtUnfoldedSvdRebin);

	std::vector<HistogramData> histAll;
	histAll.push_back({hdatajetPt, "raw jet"});
	histAll.push_back({hdatajetPtUnfoldedBayes, "unfolded Bayes"});
	histAll.push_back({hdatajetPtUnfoldedSvd, "unfolded SVD"});
	histAll.push_back({hdatajetPtRefolded, "refolded"});

	std::vector<HistogramData> histRebin;
	histRebin.push_back({hdatajetPtRebin, "raw jet"});
	histRebin.push_back({hdatajetPtUnfoldedBayesRebin, "unfolded Bayes"});
	histRebin.push_back({hdatajetPtUnfoldedSvdRebin, "unfolded SVD"});
	histRebin.push_back({hdatajetPtRefoldedRebin, "refolded"});

  std::vector<HistogramData> histRatioRefold;
	histRatioRefold.push_back({hRatioRefolded, "refold / data"});

  std::vector<HistogramData> histRatioRefoldRebin;
	histRatioRefoldRebin.push_back({hRatioRefoldedRebin, "refold / data"});

  std::vector<HistogramData> histRatioMethods;
	histRatioMethods.push_back({hRatioBayesSvd, "Bayes / SVD"});

  std::vector<HistogramData> histRatioMethodsRebin;
	histRatioMethodsRebin.push_back({hRatioBayesSvdRebin, "Bayes / SVD"});

  canHan = new CanvasHandler();

  /// To get d-vector for validation of unfolding about SVD
  TVectorD d_vector = taggingutilities::getDVector(&resMatRebin);

  int n_d = d_vector.GetNoElements();
  TH1D* hist_d_abs = new TH1D("hist_d_abs", "|d_i| Distribution for SVD Unfolding;i;|d_i|", n_d, 0.5, n_d + 0.5);

  if (debug) {
    std::cout << "\nd-vector elements:" << std::endl;
    for (int i = 0; i < n_d; ++i) {
      double val = d_vector[i];
      double abs_val = TMath::Abs(val);
      hist_d_abs->SetBinContent(i + 1, abs_val);
      std::cout << "  d_" << i << " = " << val << "  |d_" << i << "| = " << abs_val << std::endl;
    }
  }

  canHan->createCanvas(nc);
  gPad->SetLogy();

  hist_d_abs->SetLineColor(kBlue);
  hist_d_abs->SetLineWidth(2);
  hist_d_abs->SetMarkerStyle(20);
  hist_d_abs->SetMarkerSize(0.8);
  hist_d_abs->SetMarkerColor(kBlue);
  hist_d_abs->Draw("P L");

  TLine* line_one = new TLine(0.5, 1.0, n_d + 0.5, 1.0);
  line_one->SetLineColor(kRed);
  line_one->SetLineStyle(2);
  line_one->Draw("same");

  TLatex* latex = new TLatex();
  latex->SetNDC();
  latex->SetTextSize(0.035);
  latex->SetTextColor(kRed);
  latex->DrawLatex(0.7, 0.9, "|d_i| = 1");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/dvector.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  /// To check refolding
  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 1.2e+4*hdatajetPtRefolded->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histAll.size(), histAll, true, true);
  //latexDataJetInfo(0.2, 0.9);
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "refolded / data jet");
  canHan->drawCombined(histRatioRefold.size(), histRatioRefold, true, true, 0.8, 0.8);
  //latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedJetmomentum.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 1.2e+4*hdatajetPtRefoldedRebin->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histRebin.size(), histRebin, true, true);
  //latexDataJetInfo(0.2, 0.9);
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "refolded / data jet");
  canHan->drawCombined(histRatioRefoldRebin.size(), histRatioRefoldRebin, true, true, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedJetmomentumRebin.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
  // hRatioBayesSvd

  // To check difference methods
  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 1.2e+4*hdatajetPtRefolded->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histAll.size(), histAll, true, true);
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "Bayes / SVD");
  canHan->drawCombined(histRatioMethods.size(), histRatioMethods, true, false, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedJetmomentumBayesSvd.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 1, 1.2e+4*hdatajetPtRefoldedRebin->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histRebin.size(), histRebin, true, true);
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "Bayes / SVD");
  canHan->drawCombined(histRatioMethodsRebin.size(), histRatioMethodsRebin, true, false, 0.8, 0.8);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedJetmomentumBayesSvdRebin.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  // dependeces of iteration number for bayesian
  const int maxIter = 7;
  std::vector<HistogramData> histDepIter;
  std::vector<HistogramData> histDepIterRebin;
  for (int i = 3; i <= maxIter; i++) {
    RooUnfoldBayes tempUnfoldBayes(&resMat, hdatajetPt, i);
    RooUnfoldBayes tempUnfoldBayesRebin(&resMatRebin, hdatajetPtRebin, i);
    TH1F* hunfoldedBayes = (TH1F*) tempUnfoldBayes.Hunfold();
    TH1F* hunfoldedBayesRebin = (TH1F*) tempUnfoldBayesRebin.Hunfold();
    TH1F* hRatioBayesDep = static_cast<TH1F*>(hunfoldedBayes->Clone(""));
    TH1F* hRatioBayesDepRebin = static_cast<TH1F*>(hunfoldedBayesRebin->Clone(""));
    hRatioBayesDep->Divide(hdatajetPt);
    hRatioBayesDepRebin->Divide(hdatajetPtRebin);
    histDepIter.push_back({hRatioBayesDep, Form("N of reg: %d", i)});
    histDepIterRebin.push_back({hRatioBayesDepRebin, Form("N of reg: %d", i)});
  }
  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / data jet");
  canHan->drawCombined(histDepIter.size(), histDepIter, true, true);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIter.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  canHan->createCanvas(nc);
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 1.45, HfJetTagging::X_AXIS_JETPT, "unfolded / data jet");
  canHan->drawCombined(histDepIterRebin.size(), histDepIterRebin, true, true);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepIterRebin.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data()));

  // depenences of regulatation nubmer for SVD
  int maxReg[6] = {4, 5, 6, 7, 8, 9}; // default 6
  std::vector<HistogramData> histDepReg;
  std::vector<HistogramData> histDepRegRebin;

  std::vector<HistogramData> histDepRegRatio;
  std::vector<HistogramData> histDepRegRatioRebin;

  for (int i : maxReg) {
    RooUnfoldSvd tempUnfoldSvd(&resMat, hdatajetPt, i);
    RooUnfoldSvd tempUnfoldSvdRebin(&resMatRebin, hdatajetPtRebin, i);

    TH1F* hunfoldedSvd = (TH1F*) tempUnfoldSvd.Hunfold();
    TH1F* hunfoldedSvdRebin = (TH1F*) tempUnfoldSvdRebin.Hunfold();

    TH1F* hRatioSvdDep = static_cast<TH1F*>(hunfoldedSvd->Clone(""));
    TH1F* hRatioSvdRebinDep = static_cast<TH1F*>(hunfoldedSvdRebin->Clone(""));

    hRatioSvdDep->Divide(hdatajetPtUnfoldedSvd);
    hRatioSvdRebinDep->Divide(hdatajetPtUnfoldedSvdRebin);

    histDepReg.push_back({hunfoldedSvd, Form("N of reg: %d", i)});
    histDepRegRebin.push_back({hunfoldedSvdRebin, Form("N of reg: %d", i)});

    histDepRegRatio.push_back({hRatioSvdDep, Form("%d/%d", i, k_reg)});
    histDepRegRatioRebin.push_back({hRatioSvdRebinDep, Form("%d/%d", i, k_reg)});
  }

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hdatajetPtUnfoldedSvd->GetMaximum(), HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepReg.size(), histDepReg, true, true);
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 2.05, HfJetTagging::X_AXIS_JETPT, "Ratio");
  canHan->drawCombined(histDepRegRatio.size(), histDepRegRatio, true, true, 0.7, 0.6);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepReg%s.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));

  canHan->createRatioCanvas(nc, 0, 0, 800, 1000);
  gROOT->ProcessLine(Form("padu%d->cd()", nc)); // upper pad
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 5e-2, 1.2e+4*hdatajetPtUnfoldedSvd->GetMaximum(), HfJetTagging::X_AXIS_JETPT, "");
  canHan->drawCombined(histDepRegRebin.size(), histDepRegRebin, true, true);
  gROOT->ProcessLine(Form("padd%d->cd()", nc)); // lower pad
  canHan->drawRefRatioHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], 0.55, 2.05, HfJetTagging::X_AXIS_JETPT, "Ratio");
  canHan->drawCombined(histDepRegRatioRebin.size(), histDepRegRatioRebin, true, true, 0.7, 0.6);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/unfoldedDepRegRebin%s.pdf\")", nc++, dirDataVsSimGen.Data(), HfJetTagging::FLAVOUR[flavour].Data(), extSuffix.Data()));
}

void HfJetTaggingAnalysis::inputResultRun25TeV() {

  const int nBinsIP = 7;
  double binCenterIP[nBinsIP]   = {25, 35, 45, 55, 65, 75, 90};
  double binHalfWidthLIP[nBinsIP] = {5, 5, 5, 5, 5, 5, 10};
  double binHalfWidthRIP[nBinsIP] = {5, 5, 5, 5, 5, 5, 10};

  double xsectionIP[nBinsIP] = {
    1.890133e-05, 4.386416e-06, 1.230452e-06,
    4.295903e-07, 1.765481e-07, 8.089851e-08, 3.395137e-08
  };

  double statIPErr[nBinsIP] = {
    6.550406e-07, 1.991809e-07, 7.812431e-08,
    4.177579e-08, 2.622846e-08, 1.825934e-08, 7.980077e-09
  };

  double sysIPErrDown[nBinsIP] = {
    3.691349e-06, 8.145814e-07, 2.224271e-07,
    8.003604e-08, 3.434072e-08, 1.622017e-08, 7.729798e-09 
  };

  double sysIPErrUp[nBinsIP] = {
    3.691349e-06, 8.145814e-07, 2.224271e-07,
    8.003604e-08, 3.434072e-08, 1.622017e-08, 7.729798e-09 
  };


  // --- Stat-only error bars ---
  TGraphAsymmErrors* grIPStat = new TGraphAsymmErrors(
      nBinsIP, binCenterIP, xsectionIP,
      binHalfWidthLIP, binHalfWidthRIP,
      statIPErr, statIPErr
      );
  grIPStat->SetName("grIPStat");
  grIPStat->SetMarkerStyle(21);
  grIPStat->SetMarkerSize(1.2);
  grIPStat->SetLineWidth(2);
  grxsectionRun25TeVIP = (TGraphAsymmErrors*) grIPStat->Clone("grxsectionRun25TeVIP");

  // --- Sys uncertainty as boxes ---
  TGraphAsymmErrors* grIPSys = new TGraphAsymmErrors(
      nBinsIP, binCenterIP, xsectionIP,
      binHalfWidthLIP, binHalfWidthRIP,
      sysIPErrDown, sysIPErrUp
      );
  grIPSys->SetName("grIPSys");
  grIPSys->SetFillColorAlpha(kGray+1, 0.5);
  grIPSys->SetLineColor(kGray+2);
  grIPSys->SetMarkerSize(0);
  grxsectionRun25TeVIPsys = (TGraphAsymmErrors*) grIPSys->Clone("grxsectionRun25TeVIPsys");

  const int nBinsSV = 8;
  double binCenter[nBinsSV]   = {15, 25, 35, 45, 55, 65, 75, 90};
  double binHalfWidthL[nBinsSV] = { 5,  5,  5,  5,  5,  5,  5, 10};
  double binHalfWidthR[nBinsSV] = { 5,  5,  5,  5,  5,  5,  5, 10};

  double xsectionSV[nBinsSV] = {
    1.476458e-04, 1.890056e-05, 4.028217e-06, 1.214165e-06,
    4.493813e-07, 1.887126e-07, 8.760899e-08, 3.311354e-08
  };

  double statSVErr[nBinsSV] = {
    2.733068e-06, 5.565617e-07, 1.525548e-07, 6.353048e-08,
    3.225597e-08, 1.946924e-08, 1.271058e-08, 6.103368e-09
  };

  double sysSVErrDown[nBinsSV] = {
    2.504751e-05, 2.910785e-06, 7.002047e-07, 2.337892e-07,
    1.262906e-07, 4.202921e-08, 2.099978e-08, 1.239897e-08
  };
  double sysSVErrUp[nBinsSV] = {
    3.540706e-05, 3.913789e-06, 9.497780e-07, 2.763133e-07,
    9.899267e-08, 4.827023e-08, 2.123490e-08, 8.405349e-09
  };

  // --- Stat-only error bars ---
  TGraphAsymmErrors* grSVStat = new TGraphAsymmErrors(
      nBinsSV, binCenter, xsectionSV,
      binHalfWidthL, binHalfWidthR,
      statSVErr, statSVErr
      );
  grSVStat->SetName("grSVStat");
  grSVStat->SetMarkerStyle(20);
  grSVStat->SetMarkerSize(0.8);
  grSVStat->SetLineWidth(2);
  grxsectionRun2SV = (TGraphAsymmErrors*) grSVStat->Clone("grxsectionRun2SV");

  // --- Sys uncertainty as boxes ---
  TGraphAsymmErrors* grSVSys = new TGraphAsymmErrors(
      nBinsSV, binCenter, xsectionSV,
      binHalfWidthL, binHalfWidthR,
      sysSVErrDown, sysSVErrUp
      );
  grSVSys->SetName("grSVSys");
  grSVSys->SetFillColorAlpha(kGray+1, 0.5);
  grSVSys->SetLineColor(kGray+2);
  grSVSys->SetMarkerSize(0);
  grxsectionRun2SVsys = (TGraphAsymmErrors*) grSVStat->Clone("grxsectionRun2SVsys");

  fillResultRun25TeV = true;
}

void HfJetTaggingAnalysis::inputResultRun2() {

  const std::vector<double> sysErrJetpTAN = {0., 1.03538208e-04, 3.11339252e-05, 7.49509293e-06, 2.13181921e-06, 7.07038924e-07, 1.93702750e-07, 5.04617624e-08};

  const int nBinsIP = 7;
  double binCenterIP[nBinsIP] = {12.5, 17.5, 25., 35., 45., 60., 85.};
  double binHalfWidthLIP[nBinsIP] = {2.5, 2.5, 5., 5., 5., 10., 15.};
  double binHalfWidthRIP[nBinsIP] = {2.5, 2.5, 5., 5., 5., 10., 15.};

  double xsectionIP[nBinsIP] = {
    5.13175213e-04, 1.90898273e-04, 5.99992528e-05, 1.56207822e-05, 4.86497248e-06, 1.31496725e-06, 3.79097833e-07};

  double statIPErr[nBinsIP] = {3.97640736e-05, 1.54394181e-05, 3.86491106e-06, 1.91765280e-06, 1.11474148e-06, 3.35839931e-07, 1.43962624e-07};

  double sysIPErrDown[nBinsIP] = {1.03538208e-04, 3.11339252e-05, 7.49509293e-06, 2.13181921e-06, 7.07038924e-07, 1.93702750e-07, 5.04617624e-08};
  double sysIPErrUp[nBinsIP] = {1.03538208e-04, 3.11339252e-05, 7.49509293e-06, 2.13181921e-06, 7.07038924e-07, 1.93702750e-07, 5.04617624e-08};

  // --- Stat-only error bars ---
  TGraphAsymmErrors* grIPStat = new TGraphAsymmErrors(
      nBinsIP, binCenterIP, xsectionIP,
      binHalfWidthLIP, binHalfWidthRIP,
      statIPErr, statIPErr
      );
  grIPStat->SetName("grIPStat");
  grIPStat->SetMarkerStyle(21);
  grIPStat->SetMarkerSize(0.8);
  grIPStat->SetMarkerColor(kGray+2);
  grIPStat->SetLineColor(kGray+2);
  grIPStat->SetLineWidth(2);
  grxsectionRun2IP = (TGraphAsymmErrors*) grIPStat->Clone("grxsectionRun2IP");

  // --- Sys uncertainty as boxes ---
  TGraphAsymmErrors* grIPSys = new TGraphAsymmErrors(
      nBinsIP, binCenterIP, xsectionIP,
      binHalfWidthLIP, binHalfWidthRIP,
      sysIPErrDown, sysIPErrUp
      );
  grIPSys->SetName("grIPSys");
  grIPSys->SetFillColorAlpha(kGray, 0.5);
  grIPSys->SetLineColor(kGray);
  grIPSys->SetMarkerSize(0);
  grxsectionRun2IPsys = (TGraphAsymmErrors*) grIPSys->Clone("grxsectionRun2IPsys");

  fillResultRun2 = true;
}

//void HfJetTaggingAnalysis::



#endif // HFJETTAGGINGANALYSIS_H 
