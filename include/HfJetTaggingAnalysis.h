#ifndef HFJETTAGGINGANALYSIS_H
#define HFJETTAGGINGANALYSIS_H

#if !(defined(__CINT__) || defined(__CLING__)) || defined(__ACLIC__)
#include <fstream>
#include "TH1F.h"
#include <TString.h>
//#include "JetAnalysis.h"

// for UNFOLDING
#include "RooUnfoldResponse.h"
#include "RooUnfoldiBayes.h"
#endif

#include "DataPoint.h"
#include "CanvasHandler.h"

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
    int loadDataIPQA(TString rootData);
    int loadSimIPQA(TString rootSim);
    void initHistogramForNormalizationIPQAData();
    void initHistogramForNormalizationIPQAMC();
    void projectionHistIPQAData();
    void projectionHistIPQAMC();
    void rebinHistIPQAData();
    void rebinHistIPQAMC();
    void normalizedHistogramIPQAData();
    void normalizedHistogramIPQAMC();
    void saveHistogramIPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    /// Set
    void setFillData(bool fillData);
    void setFillMCD(bool fillMCD);
    void setFillMCP(bool fillMCP);
    void setDoUnfolding(bool doUnfolding);
    void setFillTest(bool fillTest);
    void setFillIPxy(bool fillIPxy);
    void setFillIPz(bool fillIPz);
    void setFillIPxyz(bool fillIPxyz);
    void setFitForJP(bool fitForJP);
    void setFillRun2Def(bool fillRun2Def);

		/// Draw
    std::vector<HistogramData> histList;
		void drawDataJetPt(bool doLog);
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
    void drawSimJetImpXYRun2Def(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYRun2Def(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYSignificanceRun2Def(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceRun2Def(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXY2x2Run2Def(bool withInc, bool doLog, int binJetPt);

    void drawSimFlavourRawJetpartJetPt(bool doLog, int flavour);
    void drawSimFlavourJetpartJetPt(bool doLog, int flavour);
    void drawDataVsMCTagJetImpXY(bool doLog, int binJetPt);
    void drawDataVsMCTagJetSignImpXY(bool doLog, int binJetPt);
    void drawDataVsMCTagJetImpXYSig(bool doLog, int binJetPt);
    void drawDataVsMCTagJetSignImpXYSig(bool doLog, int binJetPt, int binTrackPt);

    void fitDataJetSignImpXYSignificance(bool doLog);
    void fitIncJetSignImpXYSignificance(bool doLog);
    void fitCharmJetSignImpXYSignificance(bool doLog);
    void fitBeautyJetSignImpXYSignificance(bool doLog);
    void fitLfJetSignImpXYSignificance(bool doLog);
    void fitTaggedJetSignImpXYSignificance(bool withInc, bool doLog);
    void unfoldingJet(int flavour);

    // histogram
		/// Data
		TH1F* hdatajetPt;
		TH1F* hdatajetTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetTrackPhi[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdatajetImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdatajetImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

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
    TH2F* h2simjetPtpartjetPtmatched[HfJetTagging::nFlavour+1];
    TH2F* h2simjetPtpartjetPtmatchedRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPt[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetEta[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPtRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimjetEtaRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimjetPhiRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetPtRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetEtaRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimpartjetPhiRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpXYRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetImpXYSigRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetSignImpXYSigRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

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

  protected:
    // draw option. It should be moved to JetAnalysis.h when itself will be merged
    int nc = 0;
    CanvasHandler* canHan;
    int nEvent = -1;
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
    bool fillRun2Def = false;

    // histogram
		/// data
    TH1F* hdataEventSel;
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
		TH1F* hdatajetNormalizedPt;
		TH1F* hdatajetNormalizedTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedTrackPhi[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdatajetNormalizedImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdatajetNormalizedImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdatajetNormalizedSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		/// MC
    TH1F* hsimEventSel;
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
    TH3F* h3simjetPtpartjetPtmatchedFlavour;
    TH3F* h3simjetPtpartjetPtmatchedFlavourRun2Def;
    TH3F* h3simjetPtFlavourFlavourRun2Def;
    TH3F* h3simjetEtaFlavourFlavourRun2Def;
    TH3F* h3simjetPhiFlavourFlavourRun2Def;
    TH3F* h3simjetPtImpXYFlavourRun2Def;
    TH3F* h3simjetPtSignImpXYFlavourRun2Def;
    TH3F* h3simjetPtImpXYSigFlavourRun2Def;
    TH3F* h3simjetPtSignImpXYSigFlavourRun2Def;

    //// normalized
    TH1F* hsimjetNormalizedPt[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormalizedEta[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormalizedPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormalizedImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormalizedSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormalizedImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimtrackNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimpartjetNormalizedPt[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormalizedEta[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormalizedPhi[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormalizedPtRun2Def[HfJetTagging::nFlavour+1];
    TH1F* hsimpartjetNormalizedEtaRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimpartjetNormalizedPhiRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpXYRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpXYRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedImpXYSigRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimjetNormalizedSignImpXYSigRun2Def[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];


  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;
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
  delete hdatajetNormalizedPt;
  for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    delete hdatajetTrackPt[binJetPt];
    delete hdatajetTrackEta[binJetPt];
    delete hdatajetTrackPhi[binJetPt];
    delete hdatajetNormalizedTrackPt[binJetPt];
    delete hdatajetNormalizedTrackEta[binJetPt];
    delete hdatajetNormalizedTrackPhi[binJetPt];
    delete hdatajetImpXY[binJetPt];
    delete hdatajetSignImpXY[binJetPt];
    delete hdatajetImpXYSig[binJetPt];
    delete hdatajetNormalizedImpXY[binJetPt];
    delete hdatajetNormalizedSignImpXY[binJetPt];
    delete hdatajetNormalizedImpXYSig[binJetPt];
    for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
      delete hdatajetSignImpXYSig[binJetPt][binTrackPt];
      delete hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt];
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

      delete hsimjetNormalizedTrackPt[flavour][binJetPt];
      delete hsimjetNormalizedTrackEta[flavour][binJetPt];
      delete hsimjetNormalizedTrackPhi[flavour][binJetPt];
      delete hsimjetNormalizedImpXY[flavour][binJetPt];
      delete hsimjetNormalizedSignImpXY[flavour][binJetPt];
      delete hsimjetNormalizedImpXYSig[flavour][binJetPt];
      delete hsimjetNormalizedSignImpXYSig[flavour][binJetPt];
      delete hsimjetNormalizedImpZ[flavour][binJetPt];
      delete hsimjetNormalizedSignImpZ[flavour][binJetPt];
      delete hsimjetNormalizedImpZSig[flavour][binJetPt];
      delete hsimjetNormalizedSignImpZSig[flavour][binJetPt];
      delete hsimjetNormalizedImpXYZ[flavour][binJetPt];
      delete hsimjetNormalizedSignImpXYZ[flavour][binJetPt];
      delete hsimjetNormalizedImpXYZSig[flavour][binJetPt];
      delete hsimjetNormalizedSignImpXYZSig[flavour][binJetPt];
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
  dirData = Form("%s/%s/data/%s/genHfTag", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/genHfTag", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  dirDataVsSim = Form("%s/%s/dataVSsim/%s_%s/genHfTag", dirFig.Data(), SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingAnalysis::loadDataIPQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task";
  TString taskTagQa = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  if (!fillData) return 0;
  hdataEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
  h3dataTagjetPtTrackPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_eta", taskTagQa.Data())));
  h3dataTagjetPtTrackPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_phi", taskTagQa.Data())));
  if (fillIPxy) {
    h2dataTagjetPtImpXY = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy", taskTagQa.Data())));
    h2dataTagjetPtSignImpXY = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xy", taskTagQa.Data())));
    h2dataTagjetPtImpXYSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy_significance", taskTagQa.Data())));
    h3dataTagjetPtTrackPtSignImpXYSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xy_significance", taskTagQa.Data())));
  }
  if (fillIPz) {
    h2dataTagjetPtImpZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_z", taskTagQa.Data())));
    h2dataTagjetPtSignImpZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_z", taskTagQa.Data())));
    h2dataTagjetPtImpZSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_z_significance", taskTagQa.Data())));
    h3dataTagjetPtTrackPtSignImpZSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_z_significance", taskTagQa.Data())));
  }
  if (fillIPxyz) {
    h2dataTagjetPtImpXYZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xyz", taskTagQa.Data())));
    h2dataTagjetPtSignImpXYZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xyz", taskTagQa.Data())));
    h2dataTagjetPtImpXYZSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xyz_significance", taskTagQa.Data())));
    h3dataTagjetPtTrackPtSignImpXYZSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xyz_significance", taskTagQa.Data())));
  }

  std::cout << "Load completed Flavour Real data" << std::endl;
  return 1;
}

int HfJetTaggingAnalysis::loadSimIPQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task";
  TString taskTagQa = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  if (fillMCD) {
    hsimEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
    h2simjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskTagQa.Data())));
    h2simjetEtaFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_flavour", taskTagQa.Data())));
    h2simjetPhiFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_flavour", taskTagQa.Data())));
    h3simjetPtTrackPtFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskTagQa.Data())));
    h3simjetPtTrackEtaFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskTagQa.Data())));
    h3simjetPtTrackPhiFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskTagQa.Data())));
    if (fillIPxy) {
      h3simjetPtImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simjetPtImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simTagtrackPtImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simTagtrackPtImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      h3simTagtrackPtSignImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_sign_impact_parameter_xy_flavour", taskTagQa.Data())));
      h3simTagtrackPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_track_pt_sign_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
    }
    if (fillIPz) {
      h3simjetPtImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_flavour", taskTagQa.Data())));
      h3simjetPtImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_significance_flavour", taskTagQa.Data())));
      h3simjetPtSignImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_flavour", taskTagQa.Data())));
      h3simjetPtSignImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_significance_flavour", taskTagQa.Data())));
    }
    if (fillIPxyz) {
      h3simjetPtImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_flavour", taskTagQa.Data())));
      h3simjetPtImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_flavour", taskTagQa.Data())));
      h3simjetPtSignImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
    }
  }

  if (fillMCP) {
    h2simpartjetPtFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_part_flavour", taskTagQa.Data())));
    h2simpartjetEtaFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_part_flavour", taskTagQa.Data())));
    h2simpartjetPhiFlavour = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_part_flavour", taskTagQa.Data())));
  }

  if (fillRun2Def) {
    h3simjetPtpartjetPtmatchedFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_jet_pt_part_matchedgeo_flavour", taskTagQa.Data())));
    h3simjetPtpartjetPtmatchedFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_jet_pt_part_matchedgeo_flavour_run2", taskTagQa.Data())));
    h3simjetPtFlavourFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_flavour_flavour_run2", taskTagQa.Data())));
    h3simjetEtaFlavourFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_eta_flavour_flavour_run2", taskTagQa.Data())));
    h3simjetPhiFlavourFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_phi_flavour_flavour_run2", taskTagQa.Data())));
    if (fillIPxy) {
      h3simjetPtImpXYFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_flavour_run2", taskTagQa.Data())));
      h3simjetPtImpXYSigFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_significance_flavour_run2", taskTagQa.Data())));
      h3simjetPtSignImpXYFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_flavour_run2", taskTagQa.Data())));
      h3simjetPtSignImpXYSigFlavourRun2Def = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_run2", taskTagQa.Data())));
    }
    std::cout << "Load completed Flavour MC data" << std::endl;
  }
  return 1;
}

void HfJetTaggingAnalysis::initHistogramForNormalizationIPQAData() {
  if (!fillData) return;
  hdatajetPt = new TH1F("hdatajetPt", "", h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsX()));
  for (int jetPt =0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
    hdatajetTrackPt[jetPt] = new TH1F(Form("hdatajetTrackPt_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
    hdatajetTrackEta[jetPt] = new TH1F(Form("hdatajetTrackEta_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsZ(), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
    hdatajetTrackPhi[jetPt] = new TH1F(Form("hdatajetTrackPhi_%d", jetPt), "", h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ(), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));
    if (fillIPxy) {
      hdatajetImpXY[jetPt] = new TH1F(Form("hdatajetImpXY_%d", jetPt), "", h2dataTagjetPtImpXY->GetNbinsY(), h2dataTagjetPtImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXY->GetNbinsY()));
      hdatajetSignImpXY[jetPt] = new TH1F(Form("hdatajetSignImpXY_%d", jetPt), "", h2dataTagjetPtSignImpXY->GetNbinsY(), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXY->GetNbinsY()));
      hdatajetImpXYSig[jetPt] = new TH1F(Form("hdatajetImpXYSig_%d", jetPt), "", h2dataTagjetPtImpXYSig->GetNbinsY(), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYSig->GetNbinsY()));
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
      }
      if (fillIPz) {
        hdatajetSignImpZSig[jetPt][trackPt] = new TH1F(Form("hdatajetSignImpZSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpZSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpZSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpZSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpZSig->GetNbinsZ()));
      }
      if (fillIPxyz) {
        hdatajetSignImpXYZSig[jetPt][trackPt] = new TH1F(Form("hdatajetSignImpXYZSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYZSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYZSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsZ()));
      }
    }
  }
}

void HfJetTaggingAnalysis::initHistogramForNormalizationIPQAMC() {
  if (fillMCD) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetPt[flavour] = new TH1F(Form("hsimjetPt_%d", flavour), "", h2simjetPtFlavour->GetNbinsX(), h2simjetPtFlavour->GetXaxis()->GetBinLowEdge(1), h2simjetPtFlavour->GetNbinsX());
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
    }
  }
  if (fillMCP) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimpartjetPt[flavour] = new TH1F(Form("hsimpartjetPt_%d", flavour), "", h2simpartjetPtFlavour->GetNbinsX(), h2simpartjetPtFlavour->GetXaxis()->GetBinLowEdge(1), h2simpartjetPtFlavour->GetNbinsX());
      hsimpartjetEta[flavour] = new TH1F(Form("hsimpartjetEta_%d", flavour), "", h2simpartjetEtaFlavour->GetNbinsX(), h2simpartjetEtaFlavour->GetXaxis()->GetBinLowEdge(1), h2simpartjetEtaFlavour->GetNbinsX());
      hsimpartjetPhi[flavour] = new TH1F(Form("hsimpartjetPhi_%d", flavour), "", h2simpartjetPhiFlavour->GetNbinsX(), h2simpartjetPhiFlavour->GetXaxis()->GetBinLowEdge(1), h2simpartjetPhiFlavour->GetNbinsX());
    }
  }
  if (fillRun2Def) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetPtRun2Def[flavour] = new TH1F(Form("hsimjetPtRun2Def_%d", flavour), "", h3simjetPtFlavourFlavourRun2Def->GetNbinsX(), h3simjetPtFlavourFlavourRun2Def->GetXaxis()->GetBinLowEdge(1), h3simjetPtFlavourFlavourRun2Def->GetNbinsX());
      hsimjetEta[flavour] = new TH1F(Form("hsimjetEta_%d", flavour), "", h3simjetEtaFlavourFlavourRun2Def->GetNbinsX(), h3simjetEtaFlavourFlavourRun2Def->GetXaxis()->GetBinLowEdge(1), h3simjetEtaFlavourFlavourRun2Def->GetNbinsX());
      hsimjetEtaRun2Def[flavour] = new TH1F(Form("hsimjetEtaRun2Def_%d", flavour), "", h3simjetEtaFlavourFlavourRun2Def->GetNbinsX(), h3simjetEtaFlavourFlavourRun2Def->GetXaxis()->GetBinLowEdge(1), h3simjetEtaFlavourFlavourRun2Def->GetNbinsX());
      hsimjetPhi[flavour] = new TH1F(Form("hsimjetPhi_%d", flavour), "", h3simjetPhiFlavourFlavourRun2Def->GetNbinsX(), h3simjetPhiFlavourFlavourRun2Def->GetXaxis()->GetBinLowEdge(1), h3simjetPhiFlavourFlavourRun2Def->GetNbinsX());
      hsimjetPhiRun2Def[flavour] = new TH1F(Form("hsimjetPhiRun2Def_%d", flavour), "", h3simjetPhiFlavourFlavourRun2Def->GetNbinsX(), h3simjetPhiFlavourFlavourRun2Def->GetXaxis()->GetBinLowEdge(1), h3simjetPhiFlavourFlavourRun2Def->GetNbinsX());
      h2simjetPtpartjetPt[flavour] = new TH2F();
      h2simjetPtpartjetPtmatched[flavour] = new TH2F();
      h2simjetPtpartjetPtmatchedRun2Def[flavour] = new TH2F();
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillIPxy) {
          hsimjetImpXYRun2Def[flavour][jetPt] = new TH1F(Form("hsimjetImpXYRun2_%d_%d", flavour, jetPt), "", h3simjetPtImpXYFlavourRun2Def->GetNbinsY(), h3simjetPtImpXYFlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYFlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYFlavourRun2Def->GetNbinsY()));
          hsimjetSignImpXYRun2Def[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXY_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYFlavourRun2Def->GetNbinsY(), h3simjetPtSignImpXYFlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYFlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYFlavourRun2Def->GetNbinsY()));
          hsimjetImpXYSigRun2Def[flavour][jetPt] = new TH1F(Form("hsimjetImpXYSig_%d_%d", flavour, jetPt), "", h3simjetPtImpXYSigFlavourRun2Def->GetNbinsY(), h3simjetPtImpXYSigFlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYSigFlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYSigFlavourRun2Def->GetNbinsY()));
          hsimjetSignImpXYSigRun2Def[flavour][jetPt] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simjetPtSignImpXYSigFlavourRun2Def->GetNbinsY(), h3simjetPtSignImpXYSigFlavourRun2Def->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavourRun2Def->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavourRun2Def->GetNbinsY()));
        }
      }
    }
  }
}

void HfJetTaggingAnalysis::projectionHistIPQAData() {
  if (!fillData) return;
  //TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
  //int cutBinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::startJetPt);
  //int cutBinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(50);
  int cutBinJetPt = 1;
  TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", cutBinJetPt, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));

  TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY("projJetTrackPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
  TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
  TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsY()));
  hdatajetPt = reinterpret_cast<TH1F*>(projJetPt->Clone("hdatajetPt"));
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

void HfJetTaggingAnalysis::projectionHistIPQAMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  if (fillMCD) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      TH1F* projJetPt = reinterpret_cast<TH1F*> (h2simjetPtFlavour->ProjectionX(Form("projJetPt_%d", binFlavour), binFlavour, binFlavour));
      TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3simjetPtTrackPtFlavour->ProjectionY(Form("projTrackPt_%d", binFlavour), 1, h3simjetPtTrackPtFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3simjetPtTrackEtaFlavour->ProjectionY(Form("projTrackEta_%d", binFlavour), 1, h3simjetPtTrackEtaFlavour->GetNbinsX(), binFlavour, binFlavour));
      TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3simjetPtTrackPhiFlavour->ProjectionY(Form("projTrackPhi_%d", binFlavour), 1, h3simjetPtTrackPhiFlavour->GetNbinsX(), binFlavour, binFlavour));
      hsimjetPt[0]->Add(projJetPt);
      hsimjetTrackPt[0][0]->Add(projTrackPt);
      hsimjetTrackEta[0][0]->Add(projTrackEta);
      hsimjetTrackPhi[0][0]->Add(projTrackPhi);
      hsimjetPt[flavour] = reinterpret_cast<TH1F*>(projJetPt->Clone(Form("hsimjetPt_%d", flavour)));
      hsimjetTrackPt[flavour][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone(Form("hsimjetTrackPt_%d_0", flavour)));
      hsimjetTrackEta[flavour][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone(Form("hsimjetTrackEta_%d_0", flavour)));
      hsimjetTrackPhi[flavour][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone(Form("hsimjetTrackPhi_%d_0", flavour)));
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
    }
  }

  if (fillRun2Def) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
      TH1F* projJetPtRun2Def = reinterpret_cast<TH1F*> (h3simjetPtFlavourFlavourRun2Def->ProjectionX(Form("projJetPt_%d", binFlavour), 1, h3simjetPtFlavourFlavourRun2Def->GetNbinsY(), binFlavour, binFlavour));
      hsimjetPtRun2Def[flavour] = reinterpret_cast<TH1F*>(projJetPtRun2Def->Clone());
      hsimjetPtRun2Def[0]->Add(projJetPtRun2Def);

      TH1F* projJetEtaRun2Def = reinterpret_cast<TH1F*> (h3simjetEtaFlavourFlavourRun2Def->ProjectionX(Form("projJetPt_%d", binFlavour), 1, h3simjetEtaFlavourFlavourRun2Def->GetNbinsY(), binFlavour, binFlavour));
      hsimjetEtaRun2Def[flavour] = reinterpret_cast<TH1F*>(projJetEtaRun2Def->Clone());
      hsimjetEtaRun2Def[0]->Add(projJetPtRun2Def);

      TH1F* projJetEta = reinterpret_cast<TH1F*> (h3simjetEtaFlavourFlavourRun2Def->ProjectionX(Form("projJetPt_%d", binFlavour), binFlavour, binFlavour, 1, h3simjetEtaFlavourFlavourRun2Def->GetNbinsZ()));
      hsimjetEta[flavour] = reinterpret_cast<TH1F*>(projJetEta->Clone());
      hsimjetEta[0]->Add(projJetPtRun2Def);

      TH1F* projJetPhiRun2Def = reinterpret_cast<TH1F*> (h3simjetPhiFlavourFlavourRun2Def->ProjectionX(Form("projJetPt_%d", binFlavour), 1, h3simjetPhiFlavourFlavourRun2Def->GetNbinsY(), binFlavour, binFlavour));
      hsimjetPhiRun2Def[flavour] = reinterpret_cast<TH1F*>(projJetPhiRun2Def->Clone());
      hsimjetPhiRun2Def[0]->Add(projJetPtRun2Def);

      TH1F* projJetPhi = reinterpret_cast<TH1F*> (h3simjetPhiFlavourFlavourRun2Def->ProjectionX(Form("projJetPt_%d", binFlavour), binFlavour, binFlavour, 1, h3simjetPhiFlavourFlavourRun2Def->GetNbinsZ()));
      hsimjetPhi[flavour] = reinterpret_cast<TH1F*>(projJetPhi->Clone());
      hsimjetPhi[0]->Add(projJetPtRun2Def);

      if (fillIPxy) {
        TH1F* projImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavourRun2Def->ProjectionY(Form("projImpXY_%d", binFlavour), 1, h3simjetPtImpXYFlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYFlavourRun2Def->ProjectionY(Form("projSignImpXY_%d", binFlavour), 1, h3simjetPtSignImpXYFlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYSigFlavourRun2Def->ProjectionY(Form("projImpXYSig_%d", binFlavour), 1, h3simjetPtImpXYSigFlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binFlavour), 1, h3simjetPtSignImpXYSigFlavourRun2Def->GetNbinsX(), binFlavour, binFlavour));
        hsimjetImpXYRun2Def[0][0]->Add(projImpXY);
        hsimjetSignImpXYRun2Def[0][0]->Add(projSignImpXY);
        hsimjetImpXYSigRun2Def[0][0]->Add(projImpXYSig);
        hsimjetSignImpXYSigRun2Def[0][0]->Add(projSignImpXYSig);
        hsimjetImpXYRun2Def[flavour][0] = reinterpret_cast<TH1F*>(projImpXY->Clone(Form("hsimjetImpXYRun2Def_%d_0", flavour)));
        hsimjetSignImpXYRun2Def[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone(Form("hsimjetSignImpXYRun2Def_%d_0", flavour)));
        hsimjetImpXYSigRun2Def[flavour][0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone(Form("hsimjetImpXYSigRun2Def_%d_0", flavour)));
        hsimjetSignImpXYSigRun2Def[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone(Form("hsimjetSignImpXYSigRun2Def_%d_0", flavour)));
        for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
          int leftbinJetPtImpXY = h3simjetPtImpXYFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpXY = h3simjetPtImpXYFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavourRun2Def->ProjectionY(Form("projJetPtRagneImpXY_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXY, rightbinJetPtImpXY, binFlavour, binFlavour));
          hsimjetImpXYRun2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone());
          hsimjetImpXYRun2Def[0][binJetPt]->Add(projJetPtRangeImpXY);

          int leftbinJetPtSignImpXY = h3simjetPtSignImpXYFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXY = h3simjetPtSignImpXYFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXY = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYFlavourRun2Def->ProjectionY(Form("projJetPtRagneSignImpXY_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY, binFlavour, binFlavour));
          hsimjetSignImpXYRun2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone());
          hsimjetSignImpXYRun2Def[0][binJetPt]->Add(projJetPtRangeSignImpXY);

          int leftbinJetPtImpXYSig = h3simjetPtImpXYSigFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtImpXYSig = h3simjetPtImpXYSigFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYSigFlavourRun2Def->ProjectionY(Form("projJetPtRagneImpXYSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig, binFlavour, binFlavour));
          hsimjetImpXYSigRun2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone());
          hsimjetImpXYSigRun2Def[0][binJetPt]->Add(projJetPtRangeImpXYSig);

          int leftbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
          int rightbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavourRun2Def->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
          TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavourRun2Def->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binFlavour, binFlavour));
          hsimjetSignImpXYSigRun2Def[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone());
          hsimjetSignImpXYSigRun2Def[0][binJetPt]->Add(projJetPtRangeSignImpXYSig);
        }
      }
    }
  }
}

void HfJetTaggingAnalysis::rebinHistIPQAData() {

}

void HfJetTaggingAnalysis::rebinHistIPQAMC() {

//  std::vector<double> rebinIPxy = {-40.5, -30, -20, -10, -5, -4, -3, -2.5, -2, -1.5, -1, -0.9, -0.8, -0.7, -0.6, -0.5, -0.45, -0.40, -0.35, -0.3, -0.25, -0.2, -0.15, -0.1, -0.05, 0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.5, 2, 2.5, 3, 4, 5, 10, 20, 30, 40.5};
//  std::vector<double> rebinIPxySig = {-400, -300, -200, -100, -50, -40, -30, -20, -10, -5, -4, -3, -2.5, -2, -1.5, -1, -0.9, -0.8, -0.7, -0.6, -0.5, -0.45, -0.40, -0.35, -0.3, -0.25, -0.2, -0.15, -0.1, -0.05, 0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.6, 0.7, 0.8, 0.9, 1, 1.5, 2, 2.5, 3, 4, 5, 10, 20, 30, 40, 50, 100, 200, 300, 400};
//
//  // Rebin histogram
//	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
//		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
//      hsimjetImpXY[flavour][jetPt]->Rebin(rebinIPxy.size() - 1, hsimjetImpXY[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetSignImpXY[flavour][jetPt]->Rebin(rebinIPxy.size() - 1, hsimjetSignImpXY[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetImpXYSig[flavour][jetPt]->Rebin(rebinIPxySig.size() - 1, hsimjetImpXYSig[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetSignImpXYSig[flavour][jetPt]->Rebin(rebinIPxySig.size() - 1, hsimjetSignImpXYSig[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetNormalizedImpXY[flavour][jetPt]->Rebin(rebinIPxy.size() - 1, hsimjetNormalizedImpXY[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetNormalizedSignImpXY[flavour][jetPt]->Rebin(rebinIPxy.size() - 1, hsimjetNormalizedSignImpXY[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetNormalizedImpXYSig[flavour][jetPt]->Rebin(rebinIPxySig.size() - 1, hsimjetNormalizedImpXYSig[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//      hsimjetNormalizedSignImpXYSig[flavour][jetPt]->Rebin(rebinIPxySig.size() - 1, hsimjetNormalizedSignImpXYSig[flavour][jetPt]->GetName(), &rebinIPxy[0]);
//    }
//  }

}

void HfJetTaggingAnalysis::normalizedHistogramIPQAData() {
  if (!fillData) return;
  hdatajetNormalizedPt = (TH1F*) hdatajetPt->Clone("hdatajetNormalizedPt");
  hdatajetNormalizedPt->Scale(1. / hdatajetNormalizedPt->GetEntries());
  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
    hdatajetNormalizedTrackPt[binJetPt] = (TH1F*) hdatajetTrackPt[binJetPt]->Clone(Form("hdatajetNormalizedTrackPt_%d", binJetPt));
    hdatajetNormalizedTrackEta[binJetPt] = (TH1F*) hdatajetTrackEta[binJetPt]->Clone(Form("hdatajetNormalizedTrackEta_%d", binJetPt));
    hdatajetNormalizedTrackPhi[binJetPt] = (TH1F*) hdatajetTrackPhi[binJetPt]->Clone(Form("hdatajetNormalizedTrackPhi_%d", binJetPt));
    hdatajetNormalizedTrackPt[binJetPt]->Scale(1. / hdatajetNormalizedTrackPt[binJetPt]->GetEntries());
    hdatajetNormalizedTrackEta[binJetPt]->Scale(1. / hdatajetNormalizedTrackEta[binJetPt]->GetEntries());
    hdatajetNormalizedTrackPhi[binJetPt]->Scale(1. / hdatajetNormalizedTrackPhi[binJetPt]->GetEntries());
    if (fillIPxy) {
      hdatajetNormalizedImpXY[binJetPt] = (TH1F*) hdatajetImpXY[binJetPt]->Clone(Form("hdatajetNormalizedImpXY_%d", binJetPt));
      hdatajetNormalizedSignImpXY[binJetPt] = (TH1F*) hdatajetSignImpXY[binJetPt]->Clone(Form("hdatajetNormalizedSignImpXY_%d", binJetPt));
      hdatajetNormalizedImpXYSig[binJetPt] = (TH1F*) hdatajetImpXYSig[binJetPt]->Clone(Form("hdatajetNormalizedImpXYSig_%d", binJetPt));
      hdatajetNormalizedImpXY[binJetPt]->Scale(1. / hdatajetNormalizedImpXY[binJetPt]->GetEntries());
      hdatajetNormalizedSignImpXY[binJetPt]->Scale(1. / hdatajetNormalizedSignImpXY[binJetPt]->GetEntries());
      hdatajetNormalizedImpXYSig[binJetPt]->Scale(1. / hdatajetNormalizedImpXYSig[binJetPt]->GetEntries());
    }
    if (fillIPz) {
      hdatajetNormalizedImpZ[binJetPt] = (TH1F*) hdatajetImpZ[binJetPt]->Clone(Form("hdatajetNormalizedImpZ_%d", binJetPt));
      hdatajetNormalizedSignImpZ[binJetPt] = (TH1F*) hdatajetSignImpZ[binJetPt]->Clone(Form("hdatajetNormalizedSignImpZ_%d", binJetPt));
      hdatajetNormalizedImpZSig[binJetPt] = (TH1F*) hdatajetImpZSig[binJetPt]->Clone(Form("hdatajetNormalizedImpZSig_%d", binJetPt));
      hdatajetNormalizedImpZ[binJetPt]->Scale(1. / hdatajetNormalizedImpZ[binJetPt]->GetEntries());
      hdatajetNormalizedSignImpZ[binJetPt]->Scale(1. / hdatajetNormalizedSignImpZ[binJetPt]->GetEntries());
      hdatajetNormalizedImpZSig[binJetPt]->Scale(1. / hdatajetNormalizedImpZSig[binJetPt]->GetEntries());
    }
    if (fillIPxyz) {
      hdatajetNormalizedImpXYZ[binJetPt] = (TH1F*) hdatajetImpXYZ[binJetPt]->Clone(Form("hdatajetNormalizedImpXYZ_%d", binJetPt));
      hdatajetNormalizedSignImpXYZ[binJetPt] = (TH1F*) hdatajetSignImpXYZ[binJetPt]->Clone(Form("hdatajetNormalizedSignImpXYZ_%d", binJetPt));
      hdatajetNormalizedImpXYZSig[binJetPt] = (TH1F*) hdatajetImpXYZSig[binJetPt]->Clone(Form("hdatajetNormalizedImpXYZSig_%d", binJetPt));
      hdatajetNormalizedImpXYZ[binJetPt]->Scale(1. / hdatajetNormalizedImpXYZ[binJetPt]->GetEntries());
      hdatajetNormalizedSignImpXYZ[binJetPt]->Scale(1. / hdatajetNormalizedSignImpXYZ[binJetPt]->GetEntries());
      hdatajetNormalizedImpXYZSig[binJetPt]->Scale(1. / hdatajetNormalizedImpXYZSig[binJetPt]->Integral());
    }

    for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
      if (fillIPxy) {
        hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYSig[binJetPt][binTrackPt]->Clone(Form("hdatajetNormalizedSignImpXYSig_%d_%d", binJetPt, binTrackPt));
        hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Scale(1. / hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt]->GetEntries());
      }
      if (fillIPz) {
        hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpZSig[binJetPt][binTrackPt]->Clone(Form("hdatajetNormalizedSignImpZSig_%d_%d", binJetPt, binTrackPt));
        hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt]->Scale(1. / hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt]->GetEntries());
      }
      if (fillIPxyz) {
        hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt] = (TH1F*) hdatajetSignImpXYZSig[binJetPt][binTrackPt]->Clone(Form("hdatajetNormalizedSignImpXYZSig_%d_%d", binJetPt, binTrackPt));
        hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt]->Scale(1. / hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt]->GetEntries());
      }
    }
  }
}

void HfJetTaggingAnalysis::normalizedHistogramIPQAMC() {
  if (fillMCD) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetNormalizedPt[flavour] = (TH1F*) hsimjetPt[flavour]->Clone(Form("hsimjetNormalizedPt_%d", flavour));
      hsimjetNormalizedPt[flavour]->Scale(1. / hsimjetNormalizedPt[flavour]->Integral());
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        hsimjetNormalizedTrackPt[flavour][jetPt] = (TH1F*) hsimjetTrackPt[flavour][jetPt]->Clone(Form("hsimjetNormalizedTrackPt_%d_%d", flavour, jetPt));
        hsimjetNormalizedTrackEta[flavour][jetPt] = (TH1F*) hsimjetTrackEta[flavour][jetPt]->Clone(Form("hsimjetNormalizedTrackEta_%d_%d", flavour, jetPt));
        hsimjetNormalizedTrackPhi[flavour][jetPt] = (TH1F*) hsimjetTrackPhi[flavour][jetPt]->Clone(Form("hsimjetNormalizedTrackPhi_%d_%d", flavour, jetPt));
        hsimjetNormalizedTrackPt[flavour][jetPt]->Scale(1. / hsimjetNormalizedTrackPt[flavour][jetPt]->Integral());
        hsimjetNormalizedTrackEta[flavour][jetPt]->Scale(1. / hsimjetNormalizedTrackEta[flavour][jetPt]->Integral());
        hsimjetNormalizedTrackPhi[flavour][jetPt]->Scale(1. / hsimjetNormalizedTrackPhi[flavour][jetPt]->Integral());
        if (fillIPxy) {
          hsimjetNormalizedImpXY[flavour][jetPt] = (TH1F*) hsimjetImpXY[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXY_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpXY[flavour][jetPt] = (TH1F*) hsimjetSignImpXY[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXY_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpXYSig[flavour][jetPt] = (TH1F*) hsimjetImpXYSig[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYSig_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpXYSig[flavour][jetPt] = (TH1F*) hsimjetSignImpXYSig[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d", flavour, jetPt));
          hsimtrackNormalizedImpXY[flavour][jetPt] = (TH1F*) hsimtrackImpXY[flavour][jetPt]->Clone(Form("hsimtrackNormalizedImpXY_%d_%d", flavour, jetPt));
          hsimtrackNormalizedSignImpXY[flavour][jetPt] = (TH1F*) hsimtrackSignImpXY[flavour][jetPt]->Clone(Form("hsimtrackNormalizedSignImpXY_%d_%d", flavour, jetPt));
          hsimtrackNormalizedImpXYSig[flavour][jetPt] = (TH1F*) hsimtrackImpXYSig[flavour][jetPt]->Clone(Form("hsimtrackNormalizedImpXYSig_%d_%d", flavour, jetPt));
          hsimtrackNormalizedSignImpXYSig[flavour][jetPt] = (TH1F*) hsimtrackSignImpXYSig[flavour][jetPt]->Clone(Form("hsimtrackNormalizedSignImpXYSig_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpXY[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXY[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpXY[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXY[flavour][jetPt]->Integral());
          hsimjetNormalizedImpXYSig[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYSig[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpXYSig[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][jetPt]->Integral());
          hsimtrackNormalizedImpXY[flavour][jetPt]->Scale(1. / hsimtrackNormalizedImpXY[flavour][jetPt]->Integral());
          hsimtrackNormalizedSignImpXY[flavour][jetPt]->Scale(1. / hsimtrackNormalizedSignImpXY[flavour][jetPt]->Integral());
          hsimtrackNormalizedImpXYSig[flavour][jetPt]->Scale(1. / hsimtrackNormalizedImpXYSig[flavour][jetPt]->Integral());
          hsimtrackNormalizedSignImpXYSig[flavour][jetPt]->Scale(1. / hsimtrackNormalizedSignImpXYSig[flavour][jetPt]->Integral());
        }
        if (fillIPz) {
          hsimjetNormalizedImpZ[flavour][jetPt] = (TH1F*) hsimjetImpZ[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpZ_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpZ[flavour][jetPt] = (TH1F*) hsimjetSignImpZ[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZ_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpZSig[flavour][jetPt] = (TH1F*) hsimjetImpZSig[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpZSig_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpZSig[flavour][jetPt] = (TH1F*) hsimjetSignImpZSig[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZSig_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpZ[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpZ[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpZ[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZ[flavour][jetPt]->Integral());
          hsimjetNormalizedImpZSig[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpZSig[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpZSig[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZSig[flavour][jetPt]->Integral());
        }
        if (fillIPxyz) {
          hsimjetNormalizedImpXYZ[flavour][jetPt] = (TH1F*) hsimjetImpXYZ[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYZ_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpXYZ[flavour][jetPt] = (TH1F*) hsimjetSignImpXYZ[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZ_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpXYZSig[flavour][jetPt] = (TH1F*) hsimjetImpXYZSig[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYZSig_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpXYZSig[flavour][jetPt] = (TH1F*) hsimjetSignImpXYZSig[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZSig_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpXYZ[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYZ[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpXYZ[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZ[flavour][jetPt]->Integral());
          hsimjetNormalizedImpXYZSig[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYZSig[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpXYZSig[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZSig[flavour][jetPt]->Integral());
        }
      }
    }
  }
  if (fillMCP) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimpartjetNormalizedPt[flavour] = (TH1F*) hsimpartjetPt[flavour]->Clone(Form("hsimpartjetNormalizedPt_%d", flavour));
      hsimpartjetNormalizedEta[flavour] = (TH1F*) hsimpartjetPt[flavour]->Clone(Form("hsimpartjetNormalizedEta_%d", flavour));
      hsimpartjetNormalizedPhi[flavour] = (TH1F*) hsimpartjetPt[flavour]->Clone(Form("hsimpartjetNormalizedPhi_%d", flavour));

      hsimpartjetNormalizedPt[flavour]->Scale(1. / hsimpartjetNormalizedPt[flavour]->Integral());
      hsimpartjetNormalizedEta[flavour]->Scale(1. / hsimpartjetNormalizedEta[flavour]->Integral());
      hsimpartjetNormalizedPhi[flavour]->Scale(1. / hsimpartjetNormalizedPhi[flavour]->Integral());
    }
  }
  if (fillRun2Def) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetNormalizedEta[flavour] = (TH1F*) hsimjetEta[flavour]->Clone(Form("hsimjetNormalizedEta_%d", flavour));
      hsimjetNormalizedEta[flavour]->Scale(1. / hsimjetNormalizedEta[flavour]->Integral());
      hsimjetNormalizedPhi[flavour] = (TH1F*) hsimjetPhi[flavour]->Clone(Form("hsimjetNormalizedPhi_%d", flavour));
      hsimjetNormalizedPhi[flavour]->Scale(1. / hsimjetNormalizedPhi[flavour]->Integral());
      for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
        if (fillIPxy) {
          hsimjetNormalizedImpXYRun2Def[flavour][jetPt] = (TH1F*) hsimjetImpXYRun2Def[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYRun2Def_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpXYRun2Def[flavour][jetPt] = (TH1F*) hsimjetSignImpXYRun2Def[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYRun2Def_%d_%d", flavour, jetPt));
          hsimjetNormalizedImpXYSigRun2Def[flavour][jetPt] = (TH1F*) hsimjetImpXYSigRun2Def[flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYSigRun2Def_%d_%d", flavour, jetPt));
          hsimjetNormalizedSignImpXYSigRun2Def[flavour][jetPt] = (TH1F*) hsimjetSignImpXYSigRun2Def[flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYSigRun2Def_%d_%d", flavour, jetPt));

          hsimjetNormalizedImpXYRun2Def[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXY[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpXYRun2Def[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXY[flavour][jetPt]->Integral());
          hsimjetNormalizedImpXYSigRun2Def[flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYSig[flavour][jetPt]->Integral());
          hsimjetNormalizedSignImpXYSigRun2Def[flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYSig[flavour][jetPt]->Integral());
        }
      }
    }
  }
}

void HfJetTaggingAnalysis::saveHistogramIPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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
		hdatajetNormalizedPt->Write();
		for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
			hdatajetTrackPt[binJetPt]->Write();
			hdatajetTrackEta[binJetPt]->Write();
			hdatajetTrackPhi[binJetPt]->Write();
			hdatajetImpXY[binJetPt]->Write();
			hdatajetSignImpXY[binJetPt]->Write();
			hdatajetImpXYSig[binJetPt]->Write();
			hdatajetImpZ[binJetPt]->Write();
			hdatajetSignImpZ[binJetPt]->Write();
			hdatajetImpZSig[binJetPt]->Write();
			hdatajetImpXYZ[binJetPt]->Write();
			hdatajetSignImpXYZ[binJetPt]->Write();
			hdatajetImpXYZSig[binJetPt]->Write();
      hdatajetNormalizedTrackPt[binJetPt]->Write();
			hdatajetNormalizedTrackEta[binJetPt]->Write();
			hdatajetNormalizedTrackPhi[binJetPt]->Write();
      hdatajetNormalizedImpXY[binJetPt]->Write();
			hdatajetNormalizedSignImpXY[binJetPt]->Write();
			hdatajetNormalizedImpXYSig[binJetPt]->Write();
      hdatajetNormalizedImpZ[binJetPt]->Write();
			hdatajetNormalizedSignImpZ[binJetPt]->Write();
			hdatajetNormalizedImpZSig[binJetPt]->Write();
      hdatajetNormalizedImpXYZ[binJetPt]->Write();
			hdatajetNormalizedSignImpXYZ[binJetPt]->Write();
			hdatajetNormalizedSignImpXYZ[binJetPt]->Write();
      
			for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
				hdatajetSignImpXYSig[binJetPt][binTrackPt]->Write();
				hdatajetSignImpZSig[binJetPt][binTrackPt]->Write();
				hdatajetSignImpXYZSig[binJetPt][binTrackPt]->Write();
				hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Write();
				hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt]->Write();
				hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt]->Write();
			}
		}
	}

	if (doMC) {
  	dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
  	}
		for (int binFlavour =0; binFlavour < HfJetTagging::nFlavour+1; binFlavour++) {
      hsimjetPt[binFlavour]->Write();
      hsimjetNormalizedPt[binFlavour]->Write();
		  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        hsimjetTrackPt[binFlavour][binJetPt]->Write();
        hsimjetTrackEta[binFlavour][binJetPt]->Write();
        hsimjetTrackPhi[binFlavour][binJetPt]->Write();
        hsimjetImpXY[binFlavour][binJetPt]->Write();
        hsimjetSignImpXY[binFlavour][binJetPt]->Write();
        hsimjetImpXYSig[binFlavour][binJetPt]->Write();
        hsimjetSignImpXYSig[binFlavour][binJetPt]->Write();
        hsimjetImpZ[binFlavour][binJetPt]->Write();
        hsimjetSignImpZ[binFlavour][binJetPt]->Write();
        hsimjetImpZSig[binFlavour][binJetPt]->Write();
        hsimjetSignImpZSig[binFlavour][binJetPt]->Write();
        hsimjetImpXYZ[binFlavour][binJetPt]->Write();
        hsimjetSignImpXYZ[binFlavour][binJetPt]->Write();
        hsimjetImpXYZSig[binFlavour][binJetPt]->Write();
        hsimjetSignImpXYZSig[binFlavour][binJetPt]->Write();
        hsimjetNormalizedTrackPt[binFlavour][binJetPt]->Write();
        hsimjetNormalizedTrackEta[binFlavour][binJetPt]->Write();
        hsimjetNormalizedTrackPhi[binFlavour][binJetPt]->Write();
        hsimjetNormalizedImpXY[binFlavour][binJetPt]->Write();
        hsimjetNormalizedSignImpXY[binFlavour][binJetPt]->Write();
        hsimjetNormalizedImpXYSig[binFlavour][binJetPt]->Write();
        hsimjetNormalizedSignImpXYSig[binFlavour][binJetPt]->Write();
        hsimjetNormalizedImpZ[binFlavour][binJetPt]->Write();
        hsimjetNormalizedSignImpZ[binFlavour][binJetPt]->Write();
        hsimjetNormalizedImpZSig[binFlavour][binJetPt]->Write();
        hsimjetNormalizedSignImpZSig[binFlavour][binJetPt]->Write();
        hsimjetNormalizedImpXYZ[binFlavour][binJetPt]->Write();
        hsimjetNormalizedSignImpXYZ[binFlavour][binJetPt]->Write();
        hsimjetNormalizedImpXYZSig[binFlavour][binJetPt]->Write();
        hsimjetNormalizedSignImpXYZSig[binFlavour][binJetPt]->Write();
      }
		  for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
        hsimtrackImpXY[binFlavour][binTrackPt]->Write();
        hsimtrackSignImpXY[binFlavour][binTrackPt]->Write();
        hsimtrackImpXYSig[binFlavour][binTrackPt]->Write();
        hsimtrackSignImpXYSig[binFlavour][binTrackPt]->Write();
        hsimtrackNormalizedImpXY[binFlavour][binTrackPt]->Write();
        hsimtrackNormalizedSignImpXY[binFlavour][binTrackPt]->Write();
        hsimtrackNormalizedImpXYSig[binFlavour][binTrackPt]->Write();
        hsimtrackNormalizedSignImpXYSig[binFlavour][binTrackPt]->Write();
      }
//      for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
//        hsimtrackPtImpXY[binFlavour][binTrackPt]->Write();
//        hsimtrackPtSignImpXY[binFlavour][binTrackPt]->Write();
//        hsimtrackPtImpXYSig[binFlavour][binTrackPt]->Write();
//        hsimtrackPtSignImpXYSig[binFlavour][binTrackPt]->Write();
//        hsimtrackPtImpZ[binFlavour][binTrackPt]->Write();
//        hsimtrackPtSignImpZ[binFlavour][binTrackPt]->Write();
//        hsimtrackPtImpZSig[binFlavour][binTrackPt]->Write();
//        hsimtrackPtSignImpZSig[binFlavour][binTrackPt]->Write();
//        hsimtrackPtImpXYZ[binFlavour][binTrackPt]->Write();
//        hsimtrackPtSignImpXYZ[binFlavour][binTrackPt]->Write();
//        hsimtrackPtImpXYZSig[binFlavour][binTrackPt]->Write();
//        hsimtrackPtSignImpXYZSig[binFlavour][binTrackPt]->Write();
//      }
    }
	}

  fout->Close();
	delete fout;
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

void HfJetTaggingAnalysis::setFillRun2Def(bool mfillRun2Def) {
  fillRun2Def = mfillRun2Def;
  if (fillRun2Def) {
    std::cout << "fill Efficiency and Purity of jet reconstruction" << std::endl;
  }
}

// Draw function
void HfJetTaggingAnalysis::drawDataJetPt(bool doLog) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedPt, ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  //this->drawCombined(normHist.size(), normHist, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentum.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingAnalysis::drawDataTrackPt(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedTrackPt[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackmomentum_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataTrackEta(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedTrackEta[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/tracketa_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataTrackPhi(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedTrackPhi[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackphi_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXY(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXY[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXY(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedSignImpXY[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXY_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYSig(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXYSig[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSig_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSig_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}


void HfJetTaggingAnalysis::drawDataImpZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::X_AXIS_IMPZ[0]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedSignImpZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZ_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpZSig(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpZSig[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/genHfTag/ImpZSig_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpZSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSig_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXYZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedSignImpXYZ[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZ_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZSig(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXYZSig[binJetPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZSig_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYZSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normHist.size(), normHist, true, false);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSig_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

// MxN
void HfJetTaggingAnalysis::drawDataImpXY4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHistList;
	normHistList.push_back({hdatajetNormalizedImpXY[binJetPt], ""});
	std::vector<HistogramData> normHistListSign;
	normHistListSign.push_back({hdatajetNormalizedSignImpXY[binJetPt], ""});
	std::vector<HistogramData> normHistListSig;
	normHistListSig.push_back({hdatajetNormalizedImpXYSig[binJetPt], ""});
	std::vector<HistogramData> normHistListSignSig;
	normHistListSignSig.push_back({hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt], ""});

  canHan = new CanvasHandler();
  canHan->createCanvasMxN(nc, 4, 1, 0, 0, 2400, 600, 0.05, 0.01, 0.05, 0.12);
  latexDataSet();
  canHan->drawPadMxNCombined(nc, 0, 0, normHistList, true, doLog, false, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], "Probability");
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", nc, 0, 0));
  latexSimJetInfo(0.35, 0.98, 0, "", "anti-#it{k}_{T}", "Charged", 0.4, "this simulation");
  canHan->drawPadMxNCombined(nc, 1, 0, normHistListSign, true, doLog, false, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], "");
  canHan->drawPadMxNCombined(nc, 2, 0, normHistListSig, true, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], "");
  canHan->drawPadMxNCombined(nc, 3, 0, normHistListSignSig, true, doLog, false, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], "");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY4x1_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXY2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXY[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpXY[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedImpXYSig[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas2x2(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPXY[mpad][0], HfJetTagging::REFIPXY[mpad][1], HfJetTagging::REFIPXY[mpad][2], HfJetTagging::REFIPXY[mpad][3], HfJetTagging::X_AXIS_IMPXY[mpad], HfJetTagging::Y_AXIS_IMPXY[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY2x2_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedImpZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas4x1(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPZ[mpad][0], HfJetTagging::REFIPZ[mpad][1], HfJetTagging::REFIPZ[mpad][2], HfJetTagging::REFIPZ[mpad][3], HfJetTagging::X_AXIS_IMPZ[mpad], HfJetTagging::Y_AXIS_IMPZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ4x1_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedImpZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas2x2(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPZ[mpad][0], HfJetTagging::REFIPZ[mpad][1], HfJetTagging::REFIPZ[mpad][2], HfJetTagging::REFIPZ[mpad][3], HfJetTagging::X_AXIS_IMPZ[mpad], HfJetTagging::Y_AXIS_IMPZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ2x2_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedImpXYZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas4x1(nc);
  for (int mpad=0; mpad<4; mpad++) {
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPXYZ[mpad][0], HfJetTagging::REFIPXYZ[mpad][1], HfJetTagging::REFIPXYZ[mpad][2], HfJetTagging::REFIPXYZ[mpad][3], HfJetTagging::X_AXIS_IMPXYZ[mpad], HfJetTagging::Y_AXIS_IMPXYZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ4x1_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> normHist;
	normHist.push_back({hdatajetNormalizedImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpXYZ[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedImpXYZSig[binJetPt], ""});
	normHist.push_back({hdatajetNormalizedSignImpXYZSig[binJetPt][binTrackPt], ""});
  canHan = new CanvasHandler();
  canHan->createCanvas2x2(nc);
  for (int mpad=0; mpad<4; mpad++){
    canHan->drawPad(normHist, doLog, nc, mpad, HfJetTagging::REFIPXYZ[mpad][0], HfJetTagging::REFIPXYZ[mpad][1], HfJetTagging::REFIPXYZ[mpad][2], HfJetTagging::REFIPXYZ[mpad][3], HfJetTagging::X_AXIS_IMPXYZ[mpad], HfJetTagging::Y_AXIS_IMPXYZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ2x2_%d_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

// sim
void HfJetTaggingAnalysis::drawSimJetPt(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedPt[0], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedPt[1], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedPt[2], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedPt[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomentum.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingAnalysis::drawSimJetEta(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedEta[0], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedEta[1], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedEta[2], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedEta[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], HfJetTagging::REFHIST::JETETA[2], HfJetTagging::REFHIST::JETETA[3], HfJetTagging::X_AXIS_JETETA, HfJetTagging::Y_AXIS_JETETA);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jeteta.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingAnalysis::drawSimJetPhi(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedPhi[0], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedPhi[1], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedPhi[2], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedPhi[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], HfJetTagging::REFHIST::JETPHI[2], HfJetTagging::REFHIST::JETPHI[3], HfJetTagging::X_AXIS_JETPHI, HfJetTagging::Y_AXIS_JETPHI);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetphi.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackPt(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedTrackPt[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedTrackPt[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedTrackPt[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedTrackPt[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackmomentum_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackPt(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> normHist;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    normHist.push_back({hsimjetNormalizedTrackPt[flavour][binJetPt+1], Form("%0.f<jet pT<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPTASJETPT[0], HfJetTagging::REFHIST::TRACKPTASJETPT[1], HfJetTagging::REFHIST::TRACKPTASJETPT[2], HfJetTagging::REFHIST::TRACKPTASJETPT[3], HfJetTagging::X_AXIS_TRACKPT, HfJetTagging::Y_AXIS_TRACKPT);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackmomentum.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackEta(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedTrackEta[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedTrackEta[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedTrackEta[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedTrackEta[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/tracketa_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackEta(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> normHist;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    normHist.push_back({hsimjetNormalizedTrackEta[flavour][binJetPt+1], Form("%0.f<jet #eta<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();

  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKETAASJETPT[0], HfJetTagging::REFHIST::TRACKETAASJETPT[1], HfJetTagging::REFHIST::TRACKETAASJETPT[2], HfJetTagging::REFHIST::TRACKETAASJETPT[3], HfJetTagging::X_AXIS_TRACKETA, HfJetTagging::Y_AXIS_TRACKETA);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/tracketa.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackPhi(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedTrackPhi[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedTrackPhi[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedTrackPhi[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedTrackPhi[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //if (binJetPt == 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet}", static_cast<int>(HfJetTagging::cutJetPt)));
  //if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackphi_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackPhi(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> normHist;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    normHist.push_back({hsimjetNormalizedTrackPhi[flavour][binJetPt+1], Form("%0.f<jet #phi<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::TRACKPHIASJETPT[0], HfJetTagging::REFHIST::TRACKPHIASJETPT[1], HfJetTagging::REFHIST::TRACKPHIASJETPT[2], HfJetTagging::REFHIST::TRACKPHIASJETPT[3], HfJetTagging::X_AXIS_TRACKPHI, HfJetTagging::Y_AXIS_TRACKPHI);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackphi.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpXY[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpXY[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpXY[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpXY[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}


void HfJetTaggingAnalysis::drawSimJetSignImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpXY[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpXY[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXY_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSignificance_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificance_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXY2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXY;
  histListImpXY.push_back({hsimjetNormalizedImpXY[0][binJetPt], HfJetTagging::INCJET});
  histListImpXY.push_back({hsimjetNormalizedImpXY[1][binJetPt], HfJetTagging::CJET});
  histListImpXY.push_back({hsimjetNormalizedImpXY[2][binJetPt], HfJetTagging::BJET});
  histListImpXY.push_back({hsimjetNormalizedImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXY;
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXY[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXY[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYSig;
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYSig;
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

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

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY2x2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZ2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpZ;
  histListImpZ.push_back({hsimjetNormalizedImpZ[0][binJetPt], HfJetTagging::INCJET});
  histListImpZ.push_back({hsimjetNormalizedImpZ[1][binJetPt], HfJetTagging::CJET});
  histListImpZ.push_back({hsimjetNormalizedImpZ[2][binJetPt], HfJetTagging::BJET});
  histListImpZ.push_back({hsimjetNormalizedImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpZ;
  histListSignImpZ.push_back({hsimjetNormalizedSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpZ.push_back({hsimjetNormalizedSignImpZ[1][binJetPt], HfJetTagging::CJET});
  histListSignImpZ.push_back({hsimjetNormalizedSignImpZ[2][binJetPt], HfJetTagging::BJET});
  histListSignImpZ.push_back({hsimjetNormalizedSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpZSig;
  histListImpZSig.push_back({hsimjetNormalizedImpZSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpZSig.push_back({hsimjetNormalizedImpZSig[1][binJetPt], HfJetTagging::CJET});
  histListImpZSig.push_back({hsimjetNormalizedImpZSig[2][binJetPt], HfJetTagging::BJET});
  histListImpZSig.push_back({hsimjetNormalizedImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpZSig;
  histListSignImpZSig.push_back({hsimjetNormalizedSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpZSig.push_back({hsimjetNormalizedSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpZSig.push_back({hsimjetNormalizedSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpZSig.push_back({hsimjetNormalizedSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

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

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ2x2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZ2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXYZ;
  histListImpXYZ.push_back({hsimjetNormalizedImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYZ.push_back({hsimjetNormalizedImpXYZ[1][binJetPt], HfJetTagging::CJET});
  histListImpXYZ.push_back({hsimjetNormalizedImpXYZ[2][binJetPt], HfJetTagging::BJET});
  histListImpXYZ.push_back({hsimjetNormalizedImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYZ;
  histListSignImpXYZ.push_back({hsimjetNormalizedSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYZ.push_back({hsimjetNormalizedSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYZ.push_back({hsimjetNormalizedSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYZ.push_back({hsimjetNormalizedSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYZSig;
  histListImpXYZSig.push_back({hsimjetNormalizedImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYZSig.push_back({hsimjetNormalizedImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  histListImpXYZSig.push_back({hsimjetNormalizedImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  histListImpXYZSig.push_back({hsimjetNormalizedImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYZSig;
  histListSignImpXYZSig.push_back({hsimjetNormalizedSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYZSig.push_back({hsimjetNormalizedSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYZSig.push_back({hsimjetNormalizedSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYZSig.push_back({hsimjetNormalizedSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

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

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ2x2_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpZ[0][0], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpZ[1][0], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpZ[2][0], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpZ[3][0], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::Y_AXIS_IMPZ[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZ_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpZ[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpZ[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZ_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpZSig[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpZSig[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpZSignificance_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpZSignificance_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZ_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZ_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYZSignificance_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, TRIGGERNAME.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYZSignificance_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimTrackImpXY(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normHist.push_back({hsimtrackNormalizedImpXY[1][binTrackPt], HfJetTagging::CJET});
  normHist.push_back({hsimtrackNormalizedImpXY[2][binTrackPt], HfJetTagging::BJET});
  normHist.push_back({hsimtrackNormalizedImpXY[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  //gPad->SetGridx();
  //gPad->SetGridy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackImpXY_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackImpXY(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedImpXY[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormalizedImpXY[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackImpXY.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimTrackSignImpXY(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedSignImpXY[0][binTrackPt], HfJetTagging::INCJET});
  normHist.push_back({hsimtrackNormalizedSignImpXY[1][binTrackPt], HfJetTagging::CJET});
  normHist.push_back({hsimtrackNormalizedSignImpXY[2][binTrackPt], HfJetTagging::BJET});
  normHist.push_back({hsimtrackNormalizedSignImpXY[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  //gPad->SetGridx();
  //gPad->SetGridy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackSignImpXY_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackSignImpXY(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedSignImpXY[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormalizedSignImpXY[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackSignImpXY.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimTrackImpXYSig(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normHist.push_back({hsimtrackNormalizedImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normHist.push_back({hsimtrackNormalizedImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normHist.push_back({hsimtrackNormalizedImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  //gPad->SetGridx();
  //gPad->SetGridy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackImpXYSig_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackImpXYSig(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedImpXYSig[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormalizedImpXYSig[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackImpXYSig.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimTrackSignImpXYSig(bool withInc = false, bool doLog = true, int binTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedSignImpXYSig[0][binTrackPt], HfJetTagging::INCJET});
  normHist.push_back({hsimtrackNormalizedSignImpXYSig[1][binTrackPt], HfJetTagging::CJET});
  normHist.push_back({hsimtrackNormalizedSignImpXYSig[2][binTrackPt], HfJetTagging::BJET});
  normHist.push_back({hsimtrackNormalizedSignImpXYSig[3][binTrackPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  //gPad->SetGridx();
  //gPad->SetGridy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/TrackSignImpXYSig_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimFlavourTrackSignImpXYSig(bool doLog = true, int flavour = 2, int startTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimtrackNormalizedSignImpXYSig[flavour][0], "No cut"});
  for (int binTrackPt =startTrackPt; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
    normHist.push_back({hsimtrackNormalizedSignImpXYSig[flavour][binTrackPt+1], Form("%0.f<track pT<%0.f",HfJetTagging::binsTrackPt[binTrackPt], HfJetTagging::binsTrackPt[binTrackPt+1])});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  //latexSimTrackInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/trackSignImpXYSig.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimFlavourRawJetpartJetPt(bool doLog = true, int flavour = 2) {
  std::vector<HistogramData> histList;
  histList.push_back({hsimjetPt[flavour], "MCD jet"});
  histList.push_back({hsimpartjetPt[flavour], "MCP jet"});

  TH1F *hRatio = static_cast<TH1F*>(hsimjetPt[flavour]->Clone("hRatio"));
  hRatio->Divide(hsimpartjetPt[flavour]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  //canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histList.size(), histList, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_JETPT, "MCD/MCP");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/rawjetmomentumWithMCDMCP.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimFlavourJetpartJetPt(bool doLog = true, int flavour = 2) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedPt[flavour], "MCD jet"});
  normHist.push_back({hsimpartjetNormalizedPt[flavour], "MCP jet"});

  TH1F *hRatio = static_cast<TH1F*>(hsimjetNormalizedPt[flavour]->Clone("hRatio"));
  hRatio->Divide(hsimpartjetNormalizedPt[flavour]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_JETPT, "MCD/MCP");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetmomentumWithMCDMCP.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetImpXY(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormalizedImpXY[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalizedImpXY[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormalizedImpXY[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalizedImpXY[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetSignImpXY(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormalizedSignImpXY[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalizedSignImpXY[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormalizedSignImpXY[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalizedSignImpXY[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXY_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetImpXYSig(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormalizedImpXYSig[binJetPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalizedImpXYSig[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormalizedImpXYSig[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalizedImpXYSig[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSignificance_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetSignImpXYSig(bool doLog = true, int binJetPt=0, int binTrackPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt], Form("Data (%s)", DATASET.Data())});
  normHist.push_back({hsimjetNormalizedSignImpXYSig[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdatajetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Clone("hRatio"));
  hRatio->Divide(hsimjetNormalizedSignImpXYSig[0][binJetPt]);
  canHan = new CanvasHandler();
  canHan->createRatioCanvas(nc);
  gROOT->ProcessLine(Form("padu%d->cd()", nc));
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogramWithPad(nc, 0, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, true, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", nc));
  canHan->drawRefHistogramWithPad(nc, 1, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::AXIS_RATIO);
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificance_%d_%d.pdf\")", nc++, dirDataVsSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
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
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceWithFit.pdf\")", nc++, dirData.Data()));
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
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/incjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSim.Data()));
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
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/cjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSim.Data()));
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
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/bjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSim.Data()));
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
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/lfjet/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSim.Data()));
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
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceWithFit.pdf\")", nc++, dirSim.Data()));
}

// For mcp
void HfJetTaggingAnalysis::drawSimpartJetPt(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimpartjetNormalizedPt[0], HfJetTagging::INCJET});
  normHist.push_back({hsimpartjetNormalizedPt[1], HfJetTagging::CJET});
  normHist.push_back({hsimpartjetNormalizedPt[2], HfJetTagging::BJET});
  normHist.push_back({hsimpartjetNormalizedPt[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetmomentum.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingAnalysis::drawSimpartJetEta(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimpartjetNormalizedEta[0], HfJetTagging::INCJET});
  normHist.push_back({hsimpartjetNormalizedEta[1], HfJetTagging::CJET});
  normHist.push_back({hsimpartjetNormalizedEta[2], HfJetTagging::BJET});
  normHist.push_back({hsimpartjetNormalizedEta[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetEta.pdf\")", nc++, dirSim.Data()));
}

void HfJetTaggingAnalysis::drawSimpartJetPhi(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimpartjetNormalizedPhi[0], HfJetTagging::INCJET});
  normHist.push_back({hsimpartjetNormalizedPhi[1], HfJetTagging::CJET});
  normHist.push_back({hsimpartjetNormalizedPhi[2], HfJetTagging::BJET});
  normHist.push_back({hsimpartjetNormalizedPhi[3], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/partjetPhi.pdf\")", nc++, dirSim.Data()));
}


void HfJetTaggingAnalysis::drawSimJetImpXYRun2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpXYRun2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpXYRun2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpXYRun2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpXYRun2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYRun2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYRun2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpXYRun2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpXYRun2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpXYRun2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpXYRun2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.17, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYRun2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYSignificanceRun2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedImpXYSigRun2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedImpXYSigRun2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedImpXYSigRun2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedImpXYSigRun2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXYSignificanceRun2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYSignificanceRun2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> normHist;
  normHist.push_back({hsimjetNormalizedSignImpXYSigRun2Def[0][binJetPt], HfJetTagging::INCJET});
  normHist.push_back({hsimjetNormalizedSignImpXYSigRun2Def[1][binJetPt], HfJetTagging::CJET});
  normHist.push_back({hsimjetNormalizedSignImpXYSigRun2Def[2][binJetPt], HfJetTagging::BJET});
  normHist.push_back({hsimjetNormalizedSignImpXYSigRun2Def[3][binJetPt], HfJetTagging::LFJET});

  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);
  canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.67, 0.70, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.19, 0.86, 0, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, "ALICE Simulation");
  //latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/SignImpXYSignificanceRun2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXY2x2Run2Def(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXY;
  histListImpXY.push_back({hsimjetNormalizedImpXYRun2Def[0][binJetPt], HfJetTagging::INCJET});
  histListImpXY.push_back({hsimjetNormalizedImpXYRun2Def[1][binJetPt], HfJetTagging::CJET});
  histListImpXY.push_back({hsimjetNormalizedImpXYRun2Def[2][binJetPt], HfJetTagging::BJET});
  histListImpXY.push_back({hsimjetNormalizedImpXYRun2Def[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXY;
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXYRun2Def[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXYRun2Def[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXYRun2Def[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXY.push_back({hsimjetNormalizedSignImpXYRun2Def[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYSig;
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSigRun2Def[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSigRun2Def[1][binJetPt], HfJetTagging::CJET});
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSigRun2Def[2][binJetPt], HfJetTagging::BJET});
  histListImpXYSig.push_back({hsimjetNormalizedImpXYSigRun2Def[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYSig;
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSigRun2Def[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSigRun2Def[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSigRun2Def[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYSig.push_back({hsimjetNormalizedSignImpXYSigRun2Def[3][binJetPt], HfJetTagging::LFJET});

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

  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY2x2Run2Def_%d.pdf\")", nc++, dirSim.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::unfoldingJet(int flavour) {
  // It needs RooUnfold
  //gSystem->Load("/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Analysis/RooUnfold/build/libRooUnfold.dylib");
  
  if (!fillData) {
    std::cout<< " there are no datas" <<std::endl;
    return;
  }
  if (!(fillMCD && fillMCP)) {
    std::cout << "MCD and MCP on" << std::endl;
    return;
  }
  RooUnfoldResponse resMat(hsimjetPt[flavour], hsimpartjetPt[flavour]);
  // Bayesain unfolding
  int n_iter=4;
  RooUnfoldBayes unfold(&resMat, hdatajetPt, n_iter);
  TH1F* unfolded_jetPt = (TH1F*) unfold.Hunfold();

	std::vector<HistogramData> histLst;
	histList.push_back({unfolded_jetPt, ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  //if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(histList.size(), histList, true, false);
  //this->drawCombined(histList.size(), histList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/unfolded_jetmomentum.pdf\")", nc++, dirData.Data()));
}



#endif // HFJETTAGGINGANALYSIS_H 
