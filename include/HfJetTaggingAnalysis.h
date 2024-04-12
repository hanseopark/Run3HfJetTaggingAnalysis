#ifndef HFJETTAGGINGANALYSIS_H
#define HFJETTAGGINGANALYSIS_H

#include <fstream>
#include "TH1F.h"
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"
//#include "JetAnalysis.h"

/// Now it works itself withtout JetAnalysis.h(GeneralQA) seperatively
/// If histograms were saved by same root file,
/// In future, it should be merged by class HfJetTaggingAnalysis : public JetAnalysis
/// So the functions have to be made by different name of funciton in JetAnalysis.h

class HfJetTaggingAnalysis {
  public:
    HfJetTaggingAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMC, TString trigger, bool dopartLevel) {
      initConfig(trigger.Data());
      if (doData) {
				if (!loadDataFlavourQA(rootData.Data())) {
          return;
        }
      	initHistogramForNormalizationFlavourQAData();
      	projectionHistFlavourQAData();
      	normalizedHistogramFlavourQAData();
			}
      if (doMC) {
				if (!loadSimFlavourQA(rootSim.Data())) {
          return;
        }
      	initHistogramForNormalizationFlavourQAMC();
      	projectionHistFlavourQAMC();
      	normalizedHistogramFlavourQAMC();
			}
      saveHistogramFlavourQA("FlavourQA.root", doData, doMC, dopartLevel);
    }
    ~HfJetTaggingAnalysis();

    // function
		/// Basic
    void initConfig(TString triggerNAME);
    int loadDataFlavourQA(TString rootData);
    int loadSimFlavourQA(TString rootSim);
    void initHistogramForNormalizationFlavourQAData();
    void initHistogramForNormalizationFlavourQAMC();
    void projectionHistFlavourQAData();
    void projectionHistFlavourQAMC();
    void normalizedHistogramFlavourQAData();
    void normalizedHistogramFlavourQAMC();
    void saveHistogramFlavourQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

		/// Draw
    void histColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    std::vector<HistogramData> histList;
    void drawCombined(int num, const std::vector<HistogramData>& histList, bool withLeg, double legendxmin, double ymin, double xmax, double ymax);
		void drawDataJetPt(bool doLog);
		void drawDataTrackPt(bool doLog, int binJetPt);
		void drawDataTrackEta(bool doLog, int binJetPt);
		void drawDataTrackPhi(bool doLog, int binJetPt);
		void drawDataImpXY(bool doLog, int binJetPt);
		void drawDataSignImpXY(bool doLog, int binJetPt);
		void drawDataImpXYSig(bool doLog, int binJetPt);
		void drawDataSignImpXYSig(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXY4x1(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXY2x2(bool doLog, int binJetPt, int binTrackPt);
    
		void drawDataImpZ(bool doLog, int binJetPt);
		void drawDataSignImpZ(bool doLog, int binJetPt);
		void drawDataImpZSig(bool doLog, int binJetPt);
		void drawDataSignImpZSig(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpZ4x1(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpZ2x2(bool doLog, int binJetPt, int binTrackPt);
		void drawDataImpXYZ(bool doLog, int binJetPt);
		void drawDataSignImpXYZ(bool doLog, int binJetPt);
		void drawDataImpXYZSig(bool doLog, int binJetPt);
		void drawDataSignImpXYZSig(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXYZ4x1(bool doLog, int binJetPt, int binTrackPt);
    void drawDataImpXYZ2x2(bool doLog, int binJetPt, int binTrackPt);

    void drawSimJetPt(bool withInc, bool doLog);
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

    void drawDataVsMCTagJetImpXY(bool doLog, int binJetPt);
    void drawDataVsMCTagJetSignImpXY(bool doLog, int binJetPt);
    void drawDataVsMCTagJetImpXYSig(bool doLog, int binJetPt);
    void drawDataVsMCTagJetSignImpXYSig(bool doLog, int binJetPt, int binTrackPt);

    void fitDataJetSignImpXYSignificance(bool doLog);
    void fitincJetSignImpXYSignificance(bool doLog);
    void fitcJetSignImpXYSignificance(bool doLog);
    void fitbJetSignImpXYSignificance(bool doLog);
    void fitlfJetSignImpXYSignificance(bool doLog);
    void fitTaggedJetSignImpXYSignificance(bool withInc, bool doLog);

    // histogram
		/// Data
		TH1F* hdataTagjetPt;
		TH1F* hdataTagjetTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetTrackPhi[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		/// MC
    TH1F* hsimTagjetPt[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjetEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

    TH1F* hsimtrackPtImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];
    TH1F* hsimtrackPtSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsTrackPt+1];

  protected:
    // draw option. It should be moved to JetAnalysis.h when itself will be merged
    int canvasNum = 0;
    CanvasHandler* canvasHandler;
    int nEvent = -1;
    
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
		TH1F* hdataTagjetNormalizedPt;
		TH1F* hdataTagjetNormalizedTrackPt[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedTrackEta[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedTrackPhi[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedSignImpXY[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedImpXYSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedSignImpXYSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetNormalizedImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedSignImpZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedImpZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedSignImpZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];
		TH1F* hdataTagjetNormalizedImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedSignImpXYZ[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedImpXYZSig[HfJetTagging::nBinsJetPt+1];
		TH1F* hdataTagjetNormalizedSignImpXYZSig[HfJetTagging::nBinsJetPt+1][HfJetTagging::nBinsTrackPt+1];

		/// MC
    TH1F* hsimEventSel;
    TH3F* h3simTagjetPtTrackPtFlavour;
    TH3F* h3simTagjetPtTrackEtaFlavour;
    TH3F* h3simTagjetPtTrackPhiFlavour;
    TH3F* h3simTagjetPtImpXYFlavour;
    TH3F* h3simTagjetPtSignImpXYFlavour;
    TH3F* h3simTagjetPtImpXYSigFlavour;
    TH3F* h3simTagjetPtSignImpXYSigFlavour;
    TH3F* h3simTagjetPtImpZFlavour;
    TH3F* h3simTagjetPtSignImpZFlavour;
    TH3F* h3simTagjetPtImpZSigFlavour;
    TH3F* h3simTagjetPtSignImpZSigFlavour;
    TH3F* h3simTagjetPtImpXYZFlavour;
    TH3F* h3simTagjetPtSignImpXYZFlavour;
    TH3F* h3simTagjetPtImpXYZSigFlavour;
    TH3F* h3simTagjetPtSignImpXYZSigFlavour;

    //// normalized
    TH1F* hsimTagjetNormalizedPt[HfJetTagging::nFlavour+1];
    TH1F* hsimTagjetNormalizedTrackPt[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedTrackEta[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedTrackPhi[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXY[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXYSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXYZ[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedSignImpXYZSig[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];

  private:
    TLatex latex;
    TString triggerName;

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
  delete h3simTagjetPtTrackPtFlavour;
  delete h3simTagjetPtTrackEtaFlavour;
  delete h3simTagjetPtTrackPhiFlavour;
  delete h3simTagjetPtImpXYFlavour;
  delete h3simTagjetPtSignImpXYFlavour;
  delete h3simTagjetPtImpXYSigFlavour;
  delete h3simTagjetPtSignImpXYSigFlavour;
  delete h3simTagjetPtImpZFlavour;
  delete h3simTagjetPtSignImpZFlavour;
  delete h3simTagjetPtImpZSigFlavour;
  delete h3simTagjetPtSignImpZSigFlavour;
  delete h3simTagjetPtImpXYZFlavour;
  delete h3simTagjetPtSignImpXYZFlavour;
  delete h3simTagjetPtImpXYZSigFlavour;
  delete h3simTagjetPtSignImpXYZSigFlavour;

  delete hdataTagjetPt;
  delete hdataTagjetNormalizedPt;
  for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    delete hdataTagjetTrackPt[binJetPt];
    delete hdataTagjetTrackEta[binJetPt];
    delete hdataTagjetTrackPhi[binJetPt];
    delete hdataTagjetNormalizedTrackPt[binJetPt];
    delete hdataTagjetNormalizedTrackEta[binJetPt];
    delete hdataTagjetNormalizedTrackPhi[binJetPt];
    delete hdataTagjetImpXY[binJetPt];
    delete hdataTagjetSignImpXY[binJetPt];
    delete hdataTagjetImpXYSig[binJetPt];
    delete hdataTagjetNormalizedImpXY[binJetPt];
    delete hdataTagjetNormalizedSignImpXY[binJetPt];
    delete hdataTagjetNormalizedImpXYSig[binJetPt];
    for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
      delete hdataTagjetSignImpXYSig[binJetPt][binTrackPt];
      delete hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt];
    }
  }

  for (int flavour=0; flavour < HfJetTagging::nFlavour; flavour++) {
    for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
      delete hsimTagjetTrackPt[flavour][binJetPt];
      delete hsimTagjetTrackEta[flavour][binJetPt];
      delete hsimTagjetTrackPhi[flavour][binJetPt];
      delete hsimTagjetImpXY[flavour][binJetPt];
      delete hsimTagjetSignImpXY[flavour][binJetPt];
      delete hsimTagjetImpXYSig[flavour][binJetPt];
      delete hsimTagjetSignImpXYSig[flavour][binJetPt];
      delete hsimTagjetImpZ[flavour][binJetPt];
      delete hsimTagjetSignImpZ[flavour][binJetPt];
      delete hsimTagjetImpZSig[flavour][binJetPt];
      delete hsimTagjetSignImpZSig[flavour][binJetPt];
      delete hsimTagjetImpXYZ[flavour][binJetPt];
      delete hsimTagjetSignImpXYZ[flavour][binJetPt];
      delete hsimTagjetImpXYZSig[flavour][binJetPt];
      delete hsimTagjetSignImpXYZSig[flavour][binJetPt];

      delete hsimTagjetNormalizedTrackPt[flavour][binJetPt];
      delete hsimTagjetNormalizedTrackEta[flavour][binJetPt];
      delete hsimTagjetNormalizedTrackPhi[flavour][binJetPt];
      delete hsimTagjetNormalizedImpXY[flavour][binJetPt];
      delete hsimTagjetNormalizedSignImpXY[flavour][binJetPt];
      delete hsimTagjetNormalizedImpXYSig[flavour][binJetPt];
      delete hsimTagjetNormalizedSignImpXYSig[flavour][binJetPt];
      delete hsimTagjetNormalizedImpZ[flavour][binJetPt];
      delete hsimTagjetNormalizedSignImpZ[flavour][binJetPt];
      delete hsimTagjetNormalizedImpZSig[flavour][binJetPt];
      delete hsimTagjetNormalizedSignImpZSig[flavour][binJetPt];
      delete hsimTagjetNormalizedImpXYZ[flavour][binJetPt];
      delete hsimTagjetNormalizedSignImpXYZ[flavour][binJetPt];
      delete hsimTagjetNormalizedImpXYZSig[flavour][binJetPt];
      delete hsimTagjetNormalizedSignImpXYZSig[flavour][binJetPt];
    }
    for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt; binTrackPt++) {
      delete hsimtrackPtImpXY[flavour][binTrackPt];
      delete hsimtrackPtSignImpXY[flavour][binTrackPt];
      delete hsimtrackPtImpXYSig[flavour][binTrackPt];
      delete hsimtrackPtSignImpXYSig[flavour][binTrackPt];
      delete hsimtrackPtImpZ[flavour][binTrackPt];
      delete hsimtrackPtSignImpZ[flavour][binTrackPt];
      delete hsimtrackPtImpZSig[flavour][binTrackPt];
      delete hsimtrackPtSignImpZSig[flavour][binTrackPt];
      delete hsimtrackPtImpXYZ[flavour][binTrackPt];
      delete hsimtrackPtSignImpXYZ[flavour][binTrackPt];
      delete hsimtrackPtImpXYZSig[flavour][binTrackPt];
      delete hsimtrackPtSignImpXYZSig[flavour][binTrackPt];
    }
  }
}

void HfJetTaggingAnalysis::initConfig(TString trigger) {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  triggerName = trigger.Data();
  TString dirData = Form("fig/data/%s/genHfTag", DATASET.Data());
  TString dirSim = Form("fig/sim/%s/genHfTag", SIMSET.Data());
  TString dirDataVsSim = Form("fig/dataVSsim/%s_%s/genHfTag", DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/incjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/bjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/cjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(Form("%s/lfjet", dirSim.Data()), kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int HfJetTaggingAnalysis::loadDataFlavourQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task";
  TString taskTagQa = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  hdataEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
  h3dataTagjetPtTrackPtTrackEta = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_eta", taskTagQa.Data())));
  h3dataTagjetPtTrackPtTrackPhi = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_track_phi", taskTagQa.Data())));
  h2dataTagjetPtImpXY = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy", taskTagQa.Data())));
  h2dataTagjetPtSignImpXY = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xy", taskTagQa.Data())));
  h2dataTagjetPtImpXYSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy_significance", taskTagQa.Data())));
  h3dataTagjetPtTrackPtSignImpXYSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xy_significance", taskTagQa.Data())));
  h2dataTagjetPtImpZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_z", taskTagQa.Data())));
  h2dataTagjetPtSignImpZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_z", taskTagQa.Data())));
  h2dataTagjetPtImpZSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_z_significance", taskTagQa.Data())));
  h3dataTagjetPtTrackPtSignImpZSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_z_significance", taskTagQa.Data())));
  h2dataTagjetPtImpXYZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xyz", taskTagQa.Data())));
  h2dataTagjetPtSignImpXYZ = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xyz", taskTagQa.Data())));
  h2dataTagjetPtImpXYZSig = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xyz_significance", taskTagQa.Data())));
  h3dataTagjetPtTrackPtSignImpXYZSig = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_sign_impact_parameter_xyz_significance", taskTagQa.Data())));

  std::cout << "Load completed Flavour Real data" << std::endl;
  return 1;
}

int HfJetTaggingAnalysis::loadSimFlavourQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskEventSel = "event-selection-task";
  TString taskTagQa = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  hsimEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
  h3simTagjetPtTrackPtFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_pt_flavour", taskTagQa.Data())));
  h3simTagjetPtTrackEtaFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_eta_flavour", taskTagQa.Data())));
  h3simTagjetPtTrackPhiFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_track_phi_flavour", taskTagQa.Data())));
  h3simTagjetPtImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_flavour", taskTagQa.Data())));
  h3simTagjetPtImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
  h3simTagjetPtSignImpXYFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_flavour", taskTagQa.Data())));
  h3simTagjetPtSignImpXYSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
  h3simTagjetPtImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_flavour", taskTagQa.Data())));
  h3simTagjetPtImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_significance_flavour", taskTagQa.Data())));
  h3simTagjetPtSignImpZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_flavour", taskTagQa.Data())));
  h3simTagjetPtSignImpZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_significance_flavour", taskTagQa.Data())));
  h3simTagjetPtImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_flavour", taskTagQa.Data())));
  h3simTagjetPtImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
  h3simTagjetPtSignImpXYZFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_flavour", taskTagQa.Data())));
  h3simTagjetPtSignImpXYZSigFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));

  std::cout << "Load completed Flavour MC data" << std::endl;
  return 1;
}

void HfJetTaggingAnalysis::initHistogramForNormalizationFlavourQAData() {
	hdataTagjetPt = new TH1F("hdataTagjetPt", "", h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetXaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsX()));
	for (int jetPt =0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
    hdataTagjetTrackPt[jetPt] = new TH1F(Form("hdataTagjetTrackPt_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetYaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
    hdataTagjetTrackEta[jetPt] = new TH1F(Form("hdataTagjetTrackEta_%d", jetPt), "", h3dataTagjetPtTrackPtTrackEta->GetNbinsZ(), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackEta->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
    hdataTagjetTrackPhi[jetPt] = new TH1F(Form("hdataTagjetTrackPhi_%d", jetPt), "", h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ(), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtTrackPhi->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));
    hdataTagjetImpXY[jetPt] = new TH1F(Form("hdataTagjetImpXY_%d", jetPt), "", h2dataTagjetPtImpXY->GetNbinsY(), h2dataTagjetPtImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXY->GetNbinsY()));
    hdataTagjetSignImpXY[jetPt] = new TH1F(Form("hdataTagjetSignImpXY_%d", jetPt), "", h2dataTagjetPtSignImpXY->GetNbinsY(), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXY->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXY->GetNbinsY()));
    hdataTagjetImpXYSig[jetPt] = new TH1F(Form("hdataTagjetImpXYSig_%d", jetPt), "", h2dataTagjetPtImpXYSig->GetNbinsY(), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYSig->GetNbinsY()));
    hdataTagjetImpZ[jetPt] = new TH1F(Form("hdataTagjetImpZ_%d", jetPt), "", h2dataTagjetPtImpZ->GetNbinsY(), h2dataTagjetPtImpZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpZ->GetNbinsY()));
    hdataTagjetSignImpZ[jetPt] = new TH1F(Form("hdataTagjetSignImpZ_%d", jetPt), "", h2dataTagjetPtSignImpZ->GetNbinsY(), h2dataTagjetPtSignImpZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpZ->GetNbinsY()));
    hdataTagjetImpZSig[jetPt] = new TH1F(Form("hdataTagjetImpZSig_%d", jetPt), "", h2dataTagjetPtImpZSig->GetNbinsY(), h2dataTagjetPtImpZSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpZSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpZSig->GetNbinsY()));
    hdataTagjetImpXYZ[jetPt] = new TH1F(Form("hdataTagjetImpXYZ_%d", jetPt), "", h2dataTagjetPtImpXYZ->GetNbinsY(), h2dataTagjetPtImpXYZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYZ->GetNbinsY()));
    hdataTagjetSignImpXYZ[jetPt] = new TH1F(Form("hdataTagjetSignImpXYZ_%d", jetPt), "", h2dataTagjetPtSignImpXYZ->GetNbinsY(), h2dataTagjetPtSignImpXYZ->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtSignImpXYZ->GetYaxis()->GetBinUpEdge(h2dataTagjetPtSignImpXYZ->GetNbinsY()));
    hdataTagjetImpXYZSig[jetPt] = new TH1F(Form("hdataTagjetImpXYZSig_%d", jetPt), "", h2dataTagjetPtImpXYZSig->GetNbinsY(), h2dataTagjetPtImpXYZSig->GetYaxis()->GetBinLowEdge(1), h2dataTagjetPtImpXYZSig->GetYaxis()->GetBinUpEdge(h2dataTagjetPtImpXYZSig->GetNbinsY()));

		for (int trackPt =0; trackPt < HfJetTagging::nBinsTrackPt+1; trackPt++) {
			hdataTagjetSignImpXYSig[jetPt][trackPt] = new TH1F(Form("hdataTagjetSignImpXYSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsZ()));
			hdataTagjetSignImpZSig[jetPt][trackPt] = new TH1F(Form("hdataTagjetSignImpZSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpZSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpZSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpZSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpZSig->GetNbinsZ()));
			hdataTagjetSignImpXYZSig[jetPt][trackPt] = new TH1F(Form("hdataTagjetSignImpXYZSig_%d_%d", jetPt, trackPt), "", h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsZ(), h3dataTagjetPtTrackPtSignImpXYZSig->GetZaxis()->GetBinLowEdge(1), h3dataTagjetPtTrackPtSignImpXYZSig->GetZaxis()->GetBinUpEdge(h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsZ()));
		}
	}
}

void HfJetTaggingAnalysis::initHistogramForNormalizationFlavourQAMC() {
  std::cout << "Init histogram" << std::endl;
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimTagjetPt[flavour] = new TH1F(Form("hsimTagjetPt_%d", flavour), "", h3simTagjetPtTrackEtaFlavour->GetNbinsX(), h3simTagjetPtTrackEtaFlavour->GetXaxis()->GetBinLowEdge(1), h3simTagjetPtTrackEtaFlavour->GetXaxis()->GetBinUpEdge(h3simTagjetPtTrackEtaFlavour->GetNbinsY()));
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			//hsimTagjetEta[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackPt_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackPtFlavour->GetNbinsY(), h3simTagjetPtTrackPtFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPtFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPtFlavour->GetNbinsY()));
			hsimTagjetTrackPt[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackPt_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackPtFlavour->GetNbinsY(), h3simTagjetPtTrackPtFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPtFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPtFlavour->GetNbinsY()));
			hsimTagjetTrackEta[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackEta_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackEtaFlavour->GetNbinsY(), h3simTagjetPtTrackEtaFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackEtaFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackEtaFlavour->GetNbinsY()));
			hsimTagjetTrackPhi[flavour][jetPt] = new TH1F(Form("hsimTagjetTrackPhi_%d_%d", flavour, jetPt), "", h3simTagjetPtTrackPhiFlavour->GetNbinsY(), h3simTagjetPtTrackPhiFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtTrackPhiFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtTrackPhiFlavour->GetNbinsY()));
			hsimTagjetImpXY[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXY_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYFlavour->GetNbinsY(), h3simTagjetPtImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYFlavour->GetNbinsY()));
			hsimTagjetSignImpXY[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXY_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYFlavour->GetNbinsY(), h3simTagjetPtSignImpXYFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYFlavour->GetNbinsY()));
			hsimTagjetImpXYSig[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXYSig_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYSigFlavour->GetNbinsY(), h3simTagjetPtImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYSigFlavour->GetNbinsY()));
			hsimTagjetSignImpXYSig[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXYSig_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYSigFlavour->GetNbinsY(), h3simTagjetPtSignImpXYSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYSigFlavour->GetNbinsY()));
			hsimTagjetImpZ[flavour][jetPt] = new TH1F(Form("hsimTagjetImpZ_%d_%d", flavour, jetPt), "", h3simTagjetPtImpZFlavour->GetNbinsY(), h3simTagjetPtImpZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpZFlavour->GetNbinsY()));
			hsimTagjetSignImpZ[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpZ_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpZFlavour->GetNbinsY(), h3simTagjetPtSignImpZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpZFlavour->GetNbinsY()));
			hsimTagjetImpZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetImpZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtImpZSigFlavour->GetNbinsY(), h3simTagjetPtImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpZSigFlavour->GetNbinsY()));
			hsimTagjetSignImpZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpZSigFlavour->GetNbinsY(), h3simTagjetPtSignImpZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpZSigFlavour->GetNbinsY()));
			hsimTagjetImpXYZ[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXYZ_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYZFlavour->GetNbinsY(), h3simTagjetPtImpXYZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYZFlavour->GetNbinsY()));
			hsimTagjetSignImpXYZ[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXYZ_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYZFlavour->GetNbinsY(), h3simTagjetPtSignImpXYZFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYZFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYZFlavour->GetNbinsY()));
			hsimTagjetImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetImpXYZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtImpXYZSigFlavour->GetNbinsY(), h3simTagjetPtImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtImpXYZSigFlavour->GetNbinsY()));
			hsimTagjetSignImpXYZSig[flavour][jetPt] = new TH1F(Form("hsimTagjetSignImpXYZSig_%d_%d", flavour, jetPt), "", h3simTagjetPtSignImpXYZSigFlavour->GetNbinsY(), h3simTagjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtSignImpXYZSigFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtSignImpXYZSigFlavour->GetNbinsY()));
		}
	}
}

void HfJetTaggingAnalysis::projectionHistFlavourQAData() {

	//TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
  //int cutBinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::startJetPt);
  //int cutBinJetPt = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(50);
  int cutBinJetPt = 1;
	TH1F* projJetPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionX("projJetPt", cutBinJetPt, h3dataTagjetPtTrackPtTrackEta->GetNbinsY(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));

	TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY("projJetTrackPt", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
	TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ("projJetTrackEta", 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsY()));
	TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ("projJetTrackPhi", 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsX(), 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsY()));

  cutBinJetPt = h2dataTagjetPtImpXY->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projImpXY = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXY->ProjectionY("projJetImpXY", cutBinJetPt, h2dataTagjetPtImpXY->GetNbinsX()));
  cutBinJetPt = h2dataTagjetPtSignImpXY->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXY->ProjectionY("projJetSignImpXY", cutBinJetPt, h2dataTagjetPtSignImpXY->GetNbinsX()));
  cutBinJetPt = h2dataTagjetPtImpXYSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYSig->ProjectionY("projJetImpXYSig", cutBinJetPt, h2dataTagjetPtImpXYSig->GetNbinsX()));
  cutBinJetPt = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYSig->ProjectionZ("projJetSignImpXYSig", cutBinJetPt, h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpXYSig->GetNbinsY()));
  cutBinJetPt = h2dataTagjetPtImpZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projImpZ = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZ->ProjectionY("projJetImpZ", cutBinJetPt, h2dataTagjetPtImpZ->GetNbinsX()));
  cutBinJetPt = h2dataTagjetPtSignImpZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projSignImpZ = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpZ->ProjectionY("projJetSignImpZ", cutBinJetPt, h2dataTagjetPtSignImpZ->GetNbinsX()));
  cutBinJetPt = h2dataTagjetPtImpZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projImpZSig = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZSig->ProjectionY("projJetImpZSig", cutBinJetPt, h2dataTagjetPtImpZSig->GetNbinsX()));
  cutBinJetPt = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpZSig->ProjectionZ("projJetSignImpZSig", cutBinJetPt, h3dataTagjetPtTrackPtSignImpZSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpZSig->GetNbinsY()));
  cutBinJetPt = h2dataTagjetPtImpXYZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projImpXYZ = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZ->ProjectionY("projJetImpXYZ", cutBinJetPt, h2dataTagjetPtImpXYZ->GetNbinsX()));
  cutBinJetPt = h2dataTagjetPtSignImpXYZ->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projSignImpXYZ = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXYZ->ProjectionY("projJetSignImpXYZ", cutBinJetPt, h2dataTagjetPtSignImpXYZ->GetNbinsX()));
  cutBinJetPt = h2dataTagjetPtImpXYZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projImpXYZSig = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZSig->ProjectionY("projJetImpXYZSig", cutBinJetPt, h2dataTagjetPtImpXYZSig->GetNbinsX()));
  cutBinJetPt = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::cutJetPt);
	TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYZSig->ProjectionZ("projJetSignImpXYZSig", cutBinJetPt, h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsX(), 1, h3dataTagjetPtTrackPtSignImpXYZSig->GetNbinsY()));

	hdataTagjetPt = reinterpret_cast<TH1F*>(projJetPt->Clone());
	hdataTagjetTrackPt[0] = reinterpret_cast<TH1F*>(projTrackPt->Clone());
	hdataTagjetTrackEta[0] = reinterpret_cast<TH1F*>(projTrackEta->Clone());
	hdataTagjetTrackPhi[0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone());
	hdataTagjetImpXY[0] = reinterpret_cast<TH1F*>(projImpXY->Clone());
	hdataTagjetSignImpXY[0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone());
	hdataTagjetImpXYSig[0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone());
	hdataTagjetSignImpXYSig[0][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone("hdataTagjetSignImpXYSig_0_0"));
	hdataTagjetImpZ[0] = reinterpret_cast<TH1F*>(projImpZ->Clone());
	hdataTagjetSignImpZ[0] = reinterpret_cast<TH1F*>(projSignImpZ->Clone());
	hdataTagjetImpZSig[0] = reinterpret_cast<TH1F*>(projImpZSig->Clone());
	hdataTagjetSignImpZSig[0][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone());
	hdataTagjetImpXYZ[0] = reinterpret_cast<TH1F*>(projImpXYZ->Clone());
	hdataTagjetSignImpXYZ[0] = reinterpret_cast<TH1F*>(projSignImpXYZ->Clone());
	hdataTagjetImpXYZSig[0] = reinterpret_cast<TH1F*>(projImpXYZSig->Clone());
	hdataTagjetSignImpXYZSig[0][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone());

	for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
		int leftbinJetPtTrackEta = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtTrackEta = h3dataTagjetPtTrackPtTrackEta->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionY(Form("projJetPtRangeTrackPt_%d", binJetPt), leftbinJetPtTrackEta, rightbinJetPtTrackEta, 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));
		TH1F* projJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackEta->ProjectionZ(Form("projJetPtRangeTrackEta_%d", binJetPt), leftbinJetPtTrackEta, rightbinJetPtTrackEta, 1, h3dataTagjetPtTrackPtTrackEta->GetNbinsZ()));

		int leftbinJetPtTrackPhi = h3dataTagjetPtTrackPtTrackPhi->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtTrackPhi = h3dataTagjetPtTrackPtTrackPhi->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtTrackPhi->ProjectionZ(Form("projJetPtRangeTrackPhi_%d", binJetPt), leftbinJetPtTrackPhi, rightbinJetPtTrackPhi, 1, h3dataTagjetPtTrackPtTrackPhi->GetNbinsZ()));

		int leftbinJetPtImpXY = h2dataTagjetPtImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtImpXY = h2dataTagjetPtImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeImpXY  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXY->ProjectionY(Form("projJetPtRangeImpXY_%d", binJetPt), leftbinJetPtImpXY, rightbinJetPtImpXY));

		int leftbinJetPtSignImpXY = h2dataTagjetPtSignImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtSignImpXY = h2dataTagjetPtSignImpXY->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeSignImpXY  = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXY->ProjectionY(Form("projJetPtRangeSignImpXY_%d", binJetPt), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY));

		int leftbinJetPtImpXYSig = h2dataTagjetPtImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtImpXYSig = h2dataTagjetPtImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeImpXYSig  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYSig->ProjectionY(Form("projJetPtRangeImpXYSig_%d", binJetPt), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig));

		int leftbinJetPtImpZ = h2dataTagjetPtImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtImpZ = h2dataTagjetPtImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeImpZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZ->ProjectionY(Form("projJetPtRangeImpZ_%d", binJetPt), leftbinJetPtImpZ, rightbinJetPtImpZ));

		int leftbinJetPtSignImpZ = h2dataTagjetPtSignImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtSignImpZ = h2dataTagjetPtSignImpZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeSignImpZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpZ->ProjectionY(Form("projJetPtRangeSignImpZ_%d", binJetPt), leftbinJetPtSignImpZ, rightbinJetPtSignImpZ));

		int leftbinJetPtImpZSig = h2dataTagjetPtImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtImpZSig = h2dataTagjetPtImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeImpZSig  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpZSig->ProjectionY(Form("projJetPtRangeImpZSig_%d", binJetPt), leftbinJetPtImpZSig, rightbinJetPtImpZSig));

		int leftbinJetPtImpXYZ = h2dataTagjetPtImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtImpXYZ = h2dataTagjetPtImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeImpXYZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZ->ProjectionY(Form("projJetPtRangeImpXYZ_%d", binJetPt), leftbinJetPtImpXYZ, rightbinJetPtImpXYZ));

		int leftbinJetPtSignImpXYZ = h2dataTagjetPtSignImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtSignImpXYZ = h2dataTagjetPtSignImpXYZ->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeSignImpXYZ  = reinterpret_cast<TH1F*> (h2dataTagjetPtSignImpXYZ->ProjectionY(Form("projJetPtRangeSignImpXYZ_%d", binJetPt), leftbinJetPtSignImpXYZ, rightbinJetPtSignImpXYZ));

		int leftbinJetPtImpXYZSig = h2dataTagjetPtImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtImpXYZSig = h2dataTagjetPtImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		TH1F* projJetPtRangeImpXYZSig  = reinterpret_cast<TH1F*> (h2dataTagjetPtImpXYZSig->ProjectionY(Form("projJetPtRangeImpXYZSig_%d", binJetPt), leftbinJetPtImpXYZSig, rightbinJetPtImpXYZSig));

		hdataTagjetTrackPt[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPt->Clone());
		hdataTagjetTrackEta[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackEta->Clone());
		hdataTagjetTrackPhi[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPhi->Clone());
    hdataTagjetImpXY[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone());
    hdataTagjetSignImpXY[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone());
    hdataTagjetImpXYSig[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone());
    hdataTagjetImpZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZ->Clone());
    hdataTagjetSignImpZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZ->Clone());
    hdataTagjetImpZSig[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZSig->Clone());
    hdataTagjetImpXYZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZ->Clone());
    hdataTagjetSignImpXYZ[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZ->Clone());
    hdataTagjetImpXYZSig[binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZSig->Clone());

		int leftbinJetPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		int leftbinJetPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		int leftbinJetPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
		int rightbinJetPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
		for (int binTrackPt =1; binTrackPt<HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
			int leftbinTrackPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
			int rightbinTrackPtSignImpXYSig = h3dataTagjetPtTrackPtSignImpXYSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
			TH1F* projJetPtRangeTrackPtRangeSignImpXYSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpXYSig_%d_%d", binJetPt, binTrackPt), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, leftbinTrackPtSignImpXYSig, rightbinTrackPtSignImpXYSig));

			int leftbinTrackPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
			int rightbinTrackPtSignImpZSig = h3dataTagjetPtTrackPtSignImpZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
			TH1F* projJetPtRangeTrackPtRangeSignImpZSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpZSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpZSig_%d_%d", binJetPt, binTrackPt), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, leftbinTrackPtSignImpZSig, rightbinTrackPtSignImpZSig));

			int leftbinTrackPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt-1])-1;
			int rightbinTrackPtSignImpXYZSig = h3dataTagjetPtTrackPtSignImpXYZSig->GetXaxis()->FindBin(HfJetTagging::binsTrackPt[binTrackPt])-1;
			TH1F* projJetPtRangeTrackPtRangeSignImpXYZSig  = reinterpret_cast<TH1F*> (h3dataTagjetPtTrackPtSignImpXYZSig->ProjectionZ(Form("projJetPtRangeTrackPtRangeSignImpXYZSig_%d_%d", binJetPt, binTrackPt), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, leftbinTrackPtSignImpXYZSig, rightbinTrackPtSignImpXYZSig));

			hdataTagjetSignImpXYSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpXYSig->Clone());
			hdataTagjetSignImpZSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpZSig->Clone());
			hdataTagjetSignImpXYZSig[binJetPt][binTrackPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPtRangeSignImpXYZSig->Clone());

		}
	}
}

void HfJetTaggingAnalysis::projectionHistFlavourQAMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
		TH1F* projJetPt = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour->ProjectionX(Form("projJetPt_%d", binFlavour), 1, h3simTagjetPtTrackEtaFlavour->GetNbinsY(), binFlavour, binFlavour));
		TH1F* projTrackPt = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPtFlavour->ProjectionY(Form("projTrackPt_%d", binFlavour), 1, h3simTagjetPtTrackPtFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projTrackEta = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour->ProjectionY(Form("projTrackEta_%d", binFlavour), 1, h3simTagjetPtTrackEtaFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projTrackPhi = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPhiFlavour->ProjectionY(Form("projTrackPhi_%d", binFlavour), 1, h3simTagjetPtTrackPhiFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projImpXY = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYFlavour->ProjectionY(Form("projImpXY_%d", binFlavour), 1, h3simTagjetPtImpXYFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYFlavour->ProjectionY(Form("projSignImpXY_%d", binFlavour), 1, h3simTagjetPtSignImpXYFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYSigFlavour->ProjectionY(Form("projImpXYSig_%d", binFlavour), 1, h3simTagjetPtImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYSigFlavour->ProjectionY(Form("projSignImpXYSig_%d", binFlavour), 1, h3simTagjetPtSignImpXYSigFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projImpZ = reinterpret_cast<TH1F*> (h3simTagjetPtImpZFlavour->ProjectionY(Form("projImpZ_%d", binFlavour), 1, h3simTagjetPtImpZFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projSignImpZ = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpZFlavour->ProjectionY(Form("projSignImpZ_%d", binFlavour), 1, h3simTagjetPtSignImpZFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projImpZSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpZSigFlavour->ProjectionY(Form("projImpZSig_%d", binFlavour), 1, h3simTagjetPtImpZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpZSigFlavour->ProjectionY(Form("projSignImpZSig_%d", binFlavour), 1, h3simTagjetPtSignImpZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projImpXYZ = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYZFlavour->ProjectionY(Form("projImpXYZ_%d", binFlavour), 1, h3simTagjetPtImpXYZFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projSignImpXYZ = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYZFlavour->ProjectionY(Form("projSignImpXYZ_%d", binFlavour), 1, h3simTagjetPtSignImpXYZFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projImpXYZSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYZSigFlavour->ProjectionY(Form("projImpXYZSig_%d", binFlavour), 1, h3simTagjetPtImpXYZSigFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3simTagjetPtSignImpXYZSigFlavour->ProjectionY(Form("projSignImpXYZSig_%d", binFlavour), 1, h3simTagjetPtSignImpXYZSigFlavour->GetNbinsX(), binFlavour, binFlavour));

		// inclusive
		hsimTagjetPt[0]->Add(projJetPt);
		hsimTagjetTrackPt[0][0]->Add(projTrackPt);
		hsimTagjetTrackEta[0][0]->Add(projTrackEta);
		hsimTagjetTrackPhi[0][0]->Add(projTrackPhi);
		hsimTagjetImpXY[0][0]->Add(projImpXY);
		hsimTagjetSignImpXY[0][0]->Add(projSignImpXY);
		hsimTagjetImpXYSig[0][0]->Add(projImpXYSig);
		hsimTagjetSignImpXYSig[0][0]->Add(projSignImpXYSig);
		hsimTagjetImpZ[0][0]->Add(projImpZ);
		hsimTagjetSignImpZ[0][0]->Add(projSignImpZ);
		hsimTagjetImpZSig[0][0]->Add(projImpZSig);
		hsimTagjetSignImpZSig[0][0]->Add(projSignImpZSig);
		hsimTagjetImpXYZ[0][0]->Add(projImpXYZ);
		hsimTagjetSignImpXYZ[0][0]->Add(projSignImpXYZ);
		hsimTagjetImpXYZSig[0][0]->Add(projImpXYZSig);
		hsimTagjetSignImpXYZSig[0][0]->Add(projSignImpXYZSig);

		// jet flavour
		hsimTagjetPt[flavour] = reinterpret_cast<TH1F*>(projJetPt->Clone(Form("hsimTagjetPt_%d", flavour)));
		hsimTagjetTrackPt[flavour][0] = reinterpret_cast<TH1F*>(projTrackPt->Clone(Form("hsimTagjetTrackPt_%d_0", flavour)));
		hsimTagjetTrackEta[flavour][0] = reinterpret_cast<TH1F*>(projTrackEta->Clone(Form("hsimTagjetTrackEta_%d_0", flavour)));
		hsimTagjetTrackPhi[flavour][0] = reinterpret_cast<TH1F*>(projTrackPhi->Clone(Form("hsimTagjetTrackPhi_%d_0", flavour)));
		hsimTagjetImpXY[flavour][0] = reinterpret_cast<TH1F*>(projImpXY->Clone(Form("hsimTagjetImpXY_%d_0", flavour)));
		hsimTagjetSignImpXY[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone(Form("hsimTagjetSignImpXY_%d_0", flavour)));
		hsimTagjetImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone(Form("hsimTagjetImpXYSig_%d_0", flavour)));
		hsimTagjetSignImpXYSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone());
		hsimTagjetImpZ[flavour][0] = reinterpret_cast<TH1F*>(projImpZ->Clone());
		hsimTagjetSignImpZ[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZ->Clone());
		hsimTagjetImpZSig[flavour][0] = reinterpret_cast<TH1F*>(projImpZSig->Clone());
		hsimTagjetSignImpZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone());
		hsimTagjetImpXYZ[flavour][0] = reinterpret_cast<TH1F*>(projImpXYZ->Clone());
		hsimTagjetSignImpXYZ[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZ->Clone());
		hsimTagjetImpXYZSig[flavour][0] = reinterpret_cast<TH1F*>(projImpXYZSig->Clone());
		hsimTagjetSignImpXYZSig[flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone());

		for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
			int leftbinJetPtTrackPt = h3simTagjetPtTrackPtFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtTrackPt = h3simTagjetPtTrackPtFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeTrackPt = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPtFlavour->ProjectionY(Form("projJetPtRangeTrackPt_%d_%d", binJetPt, binFlavour), leftbinJetPtTrackPt, rightbinJetPtTrackPt, binFlavour, binFlavour));
			hsimTagjetTrackPt[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPt->Clone(Form("hsimTagjetTrackPt_%d_%d", flavour, binJetPt))); 
			hsimTagjetTrackPt[0][binJetPt]->Add(projJetPtRangeTrackPt);

			int leftbinJetPtTrackEta = h3simTagjetPtTrackEtaFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtTrackEta = h3simTagjetPtTrackEtaFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeTrackEta = reinterpret_cast<TH1F*> (h3simTagjetPtTrackEtaFlavour->ProjectionY(Form("projJetPtRangeTrackEta_%d_%d", binFlavour, binJetPt), leftbinJetPtTrackEta, rightbinJetPtTrackEta, binFlavour, binFlavour));
			hsimTagjetTrackEta[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackEta->Clone(Form("hsimTagjetTrackEta_%d_%d", flavour, binJetPt)));
			hsimTagjetTrackEta[0][binJetPt]->Add(projJetPtRangeTrackEta);

			int leftbinJetPtTrackPhi = h3simTagjetPtTrackPhiFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtTrackPhi = h3simTagjetPtTrackPhiFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeTrackPhi = reinterpret_cast<TH1F*> (h3simTagjetPtTrackPhiFlavour->ProjectionY(Form("projJetPtRangeTrackPhi_%d_%d", binJetPt, binFlavour), leftbinJetPtTrackPhi, rightbinJetPtTrackPhi, binFlavour, binFlavour));
			hsimTagjetTrackPhi[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeTrackPhi->Clone());
			hsimTagjetTrackPhi[0][binJetPt]->Add(projJetPtRangeTrackPhi);

			int leftbinJetPtImpXY = h3simTagjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtImpXY = h3simTagjetPtImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeImpXY = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYFlavour->ProjectionY(Form("projJetPtRagneImpXY_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXY, rightbinJetPtImpXY, binFlavour, binFlavour));
			hsimTagjetImpXY[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone());
			hsimTagjetImpXY[0][binJetPt]->Add(projJetPtRangeImpXY);

			int leftbinJetPtSignImpXY = h3simTagjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtSignImpXY = h3simTagjetPtSignImpXYFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeSignImpXY = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYFlavour->ProjectionY(Form("projJetPtRagneSignImpXY_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY, binFlavour, binFlavour));
			hsimTagjetSignImpXY[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone());
			hsimTagjetSignImpXY[0][binJetPt]->Add(projJetPtRangeSignImpXY);

			int leftbinJetPtImpXYSig = h3simTagjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtImpXYSig = h3simTagjetPtImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeImpXYSig = reinterpret_cast<TH1F*> (h3simTagjetPtImpXYSigFlavour->ProjectionY(Form("projJetPtRagneImpXYSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig, binFlavour, binFlavour));
			hsimTagjetImpXYSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone());
			hsimTagjetImpXYSig[0][binJetPt]->Add(projJetPtRangeImpXYSig);

			int leftbinJetPtSignImpXYSig = h3simTagjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtSignImpXYSig = h3simTagjetPtSignImpXYSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binFlavour, binFlavour));
			hsimTagjetSignImpXYSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone());
			hsimTagjetSignImpXYSig[0][binJetPt]->Add(projJetPtRangeSignImpXYSig);

			int leftbinJetPtImpZ = h3simTagjetPtImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtImpZ = h3simTagjetPtImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeImpZ = reinterpret_cast<TH1F*>(h3simTagjetPtImpZFlavour->ProjectionY(Form("projJetPtRagneImpZ_%d_%d", binJetPt, binFlavour), leftbinJetPtImpZ, rightbinJetPtImpZ, binFlavour, binFlavour));
			hsimTagjetImpZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZ->Clone());
			hsimTagjetImpZ[0][binJetPt]->Add(projJetPtRangeImpZ);

			int leftbinJetPtSignImpZ = h3simTagjetPtSignImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtSignImpZ = h3simTagjetPtSignImpZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeSignImpZ = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpZFlavour->ProjectionY(Form("projJetPtRagneSignImpZ_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZ, rightbinJetPtSignImpZ, binFlavour, binFlavour));
			hsimTagjetSignImpZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZ->Clone());
			hsimTagjetSignImpZ[0][binJetPt]->Add(projJetPtRangeSignImpZ);
			int leftbinJetPtImpZSig = h3simTagjetPtImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtImpZSig = h3simTagjetPtImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeImpZSig = reinterpret_cast<TH1F*>(h3simTagjetPtImpZSigFlavour->ProjectionY(Form("projJetPtRagneImpZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpZSig, rightbinJetPtImpZSig, binFlavour, binFlavour));
			hsimTagjetImpZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZSig->Clone());
			hsimTagjetImpZSig[0][binJetPt]->Add(projJetPtRangeImpZSig);

			int leftbinJetPtSignImpZSig = h3simTagjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtSignImpZSig = h3simTagjetPtSignImpZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeSignImpZSig = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, binFlavour, binFlavour));
			hsimTagjetSignImpZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSig->Clone());
			hsimTagjetSignImpZSig[0][binJetPt]->Add(projJetPtRangeSignImpZSig);
			int leftbinJetPtImpXYZ = h3simTagjetPtImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtImpXYZ = h3simTagjetPtImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeImpXYZ = reinterpret_cast<TH1F*>(h3simTagjetPtImpXYZFlavour->ProjectionY(Form("projJetPtRagneImpXYZ_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYZ, rightbinJetPtImpXYZ, binFlavour, binFlavour));
			hsimTagjetImpXYZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZ->Clone());
			hsimTagjetImpXYZ[0][binJetPt]->Add(projJetPtRangeImpXYZ);

			int leftbinJetPtSignImpXYZ = h3simTagjetPtSignImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtSignImpXYZ = h3simTagjetPtSignImpXYZFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeSignImpXYZ = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYZFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZ_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZ, rightbinJetPtSignImpXYZ, binFlavour, binFlavour));
			hsimTagjetSignImpXYZ[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZ->Clone());
			hsimTagjetSignImpXYZ[0][binJetPt]->Add(projJetPtRangeSignImpXYZ);
			int leftbinJetPtImpXYZSig = h3simTagjetPtImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtImpXYZSig = h3simTagjetPtImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeImpXYZSig = reinterpret_cast<TH1F*>(h3simTagjetPtImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneImpXYZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtImpXYZSig, rightbinJetPtImpXYZSig, binFlavour, binFlavour));
			hsimTagjetImpXYZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZSig->Clone());
			hsimTagjetImpXYZSig[0][binJetPt]->Add(projJetPtRangeImpXYZSig);

			int leftbinJetPtSignImpXYZSig = h3simTagjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
			int rightbinJetPtSignImpXYZSig = h3simTagjetPtSignImpXYZSigFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
			TH1F* projJetPtRangeSignImpXYZSig = reinterpret_cast<TH1F*>(h3simTagjetPtSignImpXYZSigFlavour->ProjectionY(Form("projJetPtRagneSignImpXYZSig_%d_%d", binJetPt, binFlavour), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, binFlavour, binFlavour));
			hsimTagjetSignImpXYZSig[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSig->Clone());
			hsimTagjetSignImpXYZSig[0][binJetPt]->Add(projJetPtRangeSignImpXYZSig);
		}
	}
  delete h3simTagjetPtTrackPtFlavour;
  delete h3simTagjetPtTrackEtaFlavour;
  delete h3simTagjetPtTrackPhiFlavour;
  delete h3simTagjetPtImpXYFlavour;
  delete h3simTagjetPtSignImpXYFlavour;
  delete h3simTagjetPtImpXYSigFlavour;
  delete h3simTagjetPtSignImpXYSigFlavour;
  delete h3simTagjetPtImpZFlavour;
  delete h3simTagjetPtSignImpZFlavour;
  delete h3simTagjetPtImpZSigFlavour;
  delete h3simTagjetPtSignImpZSigFlavour;
  delete h3simTagjetPtImpXYZFlavour;
  delete h3simTagjetPtSignImpXYZFlavour;
  delete h3simTagjetPtImpXYZSigFlavour;
  delete h3simTagjetPtSignImpXYZSigFlavour;
}

void HfJetTaggingAnalysis::normalizedHistogramFlavourQAData() {
	hdataTagjetNormalizedPt = (TH1F*) hdataTagjetPt->Clone("hdataTagjetNormalizedPt");
	hdataTagjetNormalizedPt->Scale(1. / hdataTagjetNormalizedPt->GetEntries());
	for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
		hdataTagjetNormalizedTrackPt[binJetPt] = (TH1F*) hdataTagjetTrackPt[binJetPt]->Clone(Form("hdataTagjetNormalizedTrackPt_%d", binJetPt));
		hdataTagjetNormalizedTrackEta[binJetPt] = (TH1F*) hdataTagjetTrackEta[binJetPt]->Clone(Form("hdataTagjetNormalizedTrackEta_%d", binJetPt));
		hdataTagjetNormalizedTrackPhi[binJetPt] = (TH1F*) hdataTagjetTrackPhi[binJetPt]->Clone(Form("hdataTagjetNormalizedTrackPhi_%d", binJetPt));
		hdataTagjetNormalizedImpXY[binJetPt] = (TH1F*) hdataTagjetImpXY[binJetPt]->Clone(Form("hdataTagjetNormalizedImpXY_%d", binJetPt));
		hdataTagjetNormalizedSignImpXY[binJetPt] = (TH1F*) hdataTagjetSignImpXY[binJetPt]->Clone(Form("hdataTagjetNormalizedSignImpXY_%d", binJetPt));
		hdataTagjetNormalizedImpXYSig[binJetPt] = (TH1F*) hdataTagjetImpXYSig[binJetPt]->Clone(Form("hdataTagjetNormalizedImpXYSig_%d", binJetPt));
		hdataTagjetNormalizedImpZ[binJetPt] = (TH1F*) hdataTagjetImpZ[binJetPt]->Clone(Form("hdataTagjetNormalizedImpZ_%d", binJetPt));
		hdataTagjetNormalizedSignImpZ[binJetPt] = (TH1F*) hdataTagjetSignImpZ[binJetPt]->Clone(Form("hdataTagjetNormalizedSignImpZ_%d", binJetPt));
		hdataTagjetNormalizedImpZSig[binJetPt] = (TH1F*) hdataTagjetImpZSig[binJetPt]->Clone(Form("hdataTagjetNormalizedImpZSig_%d", binJetPt));
		hdataTagjetNormalizedImpXYZ[binJetPt] = (TH1F*) hdataTagjetImpXYZ[binJetPt]->Clone(Form("hdataTagjetNormalizedImpXYZ_%d", binJetPt));
		hdataTagjetNormalizedSignImpXYZ[binJetPt] = (TH1F*) hdataTagjetSignImpXYZ[binJetPt]->Clone(Form("hdataTagjetNormalizedSignImpXYZ_%d", binJetPt));
		hdataTagjetNormalizedImpXYZSig[binJetPt] = (TH1F*) hdataTagjetImpXYZSig[binJetPt]->Clone(Form("hdataTagjetNormalizedImpXYZSig_%d", binJetPt));

		hdataTagjetNormalizedTrackPt[binJetPt]->Scale(1. / hdataTagjetNormalizedTrackPt[binJetPt]->GetEntries());
		hdataTagjetNormalizedTrackEta[binJetPt]->Scale(1. / hdataTagjetNormalizedTrackEta[binJetPt]->GetEntries());
		hdataTagjetNormalizedTrackPhi[binJetPt]->Scale(1. / hdataTagjetNormalizedTrackPhi[binJetPt]->GetEntries());
		hdataTagjetNormalizedImpXY[binJetPt]->Scale(1. / hdataTagjetNormalizedImpXY[binJetPt]->GetEntries());
		hdataTagjetNormalizedSignImpXY[binJetPt]->Scale(1. / hdataTagjetNormalizedSignImpXY[binJetPt]->GetEntries());
		hdataTagjetNormalizedImpXYSig[binJetPt]->Scale(1. / hdataTagjetNormalizedImpXYSig[binJetPt]->GetEntries());
		hdataTagjetNormalizedImpZ[binJetPt]->Scale(1. / hdataTagjetNormalizedImpZ[binJetPt]->GetEntries());
		hdataTagjetNormalizedSignImpZ[binJetPt]->Scale(1. / hdataTagjetNormalizedSignImpZ[binJetPt]->GetEntries());
		hdataTagjetNormalizedImpZSig[binJetPt]->Scale(1. / hdataTagjetNormalizedImpZSig[binJetPt]->GetEntries());
		hdataTagjetNormalizedImpXYZ[binJetPt]->Scale(1. / hdataTagjetNormalizedImpXYZ[binJetPt]->GetEntries());
		hdataTagjetNormalizedSignImpXYZ[binJetPt]->Scale(1. / hdataTagjetNormalizedSignImpXYZ[binJetPt]->GetEntries());
		hdataTagjetNormalizedImpXYZSig[binJetPt]->Scale(1. / hdataTagjetNormalizedImpXYZSig[binJetPt]->GetEntries());

		for (int binTrackPt=0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
			hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt] = (TH1F*) hdataTagjetSignImpXYSig[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedSignImpXYSig_%d_%d", binJetPt, binTrackPt));
			hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt] = (TH1F*) hdataTagjetSignImpZSig[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedSignImpZSig_%d_%d", binJetPt, binTrackPt));
			hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt] = (TH1F*) hdataTagjetSignImpXYZSig[binJetPt][binTrackPt]->Clone(Form("hdataTagjetNormalizedSignImpXYZSig_%d_%d", binJetPt, binTrackPt));

			hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->GetEntries());
			hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt]->GetEntries());
			hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt]->Scale(1. / hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt]->GetEntries());
		}
	}
}

void HfJetTaggingAnalysis::normalizedHistogramFlavourQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		hsimTagjetNormalizedPt[flavour] = (TH1F*) hsimTagjetPt[flavour]->Clone(Form("hsimTagjetNormalizedPt_%d", flavour));
	  hsimTagjetNormalizedPt[flavour]->Scale(1. / hsimTagjetNormalizedPt[flavour]->GetEntries());
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetNormalizedTrackPt[flavour][jetPt] = (TH1F*) hsimTagjetTrackPt[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedTrackPt_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedTrackEta[flavour][jetPt] = (TH1F*) hsimTagjetTrackEta[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedTrackEta_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedTrackPhi[flavour][jetPt] = (TH1F*) hsimTagjetTrackPhi[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedTrackPhi_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXY[flavour][jetPt] = (TH1F*) hsimTagjetImpXY[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXY_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXY[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXY[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXY_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXYSig[flavour][jetPt] = (TH1F*) hsimTagjetImpXYSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXYSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXYSig[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXYSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXYSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpZ[flavour][jetPt] = (TH1F*) hsimTagjetImpZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpZ[flavour][jetPt] = (TH1F*) hsimTagjetSignImpZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpZSig[flavour][jetPt] = (TH1F*) hsimTagjetImpZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpZSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpZSig[flavour][jetPt] = (TH1F*) hsimTagjetSignImpZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpZSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXYZ[flavour][jetPt] = (TH1F*) hsimTagjetImpXYZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXYZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXYZ[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXYZ[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXYZ_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedImpXYZSig[flavour][jetPt] = (TH1F*) hsimTagjetImpXYZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedImpXYZSig_%d_%d", flavour, jetPt));
			hsimTagjetNormalizedSignImpXYZSig[flavour][jetPt] = (TH1F*) hsimTagjetSignImpXYZSig[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedSignImpXYZSig_%d_%d", flavour, jetPt));

			hsimTagjetNormalizedTrackPt[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedTrackPt[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedTrackEta[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedTrackEta[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedTrackPhi[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedTrackPhi[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedImpXY[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXY[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedSignImpXY[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXY[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedImpXYSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXYSig[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedSignImpXYSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXYSig[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedImpZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpZ[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedSignImpZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpZ[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedImpZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpZSig[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedSignImpZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpZSig[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedImpXYZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXYZ[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedSignImpXYZ[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXYZ[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedImpXYZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedImpXYZSig[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedSignImpXYZSig[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedSignImpXYZSig[flavour][jetPt]->GetEntries());
		}
	}
}

void HfJetTaggingAnalysis::saveHistogramFlavourQA(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
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

		hdataTagjetPt->Write();
		hdataTagjetNormalizedPt->Write();
		for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
			hdataTagjetTrackPt[binJetPt]->Write();
			hdataTagjetTrackEta[binJetPt]->Write();
			hdataTagjetTrackPhi[binJetPt]->Write();
			hdataTagjetImpXY[binJetPt]->Write();
			hdataTagjetSignImpXY[binJetPt]->Write();
			hdataTagjetImpXYSig[binJetPt]->Write();
			hdataTagjetImpZ[binJetPt]->Write();
			hdataTagjetSignImpZ[binJetPt]->Write();
			hdataTagjetImpZSig[binJetPt]->Write();
			hdataTagjetImpXYZ[binJetPt]->Write();
			hdataTagjetSignImpXYZ[binJetPt]->Write();
			hdataTagjetImpXYZSig[binJetPt]->Write();
      hdataTagjetNormalizedTrackPt[binJetPt]->Write();
			hdataTagjetNormalizedTrackEta[binJetPt]->Write();
			hdataTagjetNormalizedTrackPhi[binJetPt]->Write();
      hdataTagjetNormalizedImpXY[binJetPt]->Write();
			hdataTagjetNormalizedSignImpXY[binJetPt]->Write();
			hdataTagjetNormalizedImpXYSig[binJetPt]->Write();
      hdataTagjetNormalizedImpZ[binJetPt]->Write();
			hdataTagjetNormalizedSignImpZ[binJetPt]->Write();
			hdataTagjetNormalizedImpZSig[binJetPt]->Write();
      hdataTagjetNormalizedImpXYZ[binJetPt]->Write();
			hdataTagjetNormalizedSignImpXYZ[binJetPt]->Write();
			hdataTagjetNormalizedImpXYZSig[binJetPt]->Write();
      
			for (int binTrackPt =0; binTrackPt < HfJetTagging::nBinsTrackPt+1; binTrackPt++) {
				hdataTagjetSignImpXYSig[binJetPt][binTrackPt]->Write();
				hdataTagjetSignImpZSig[binJetPt][binTrackPt]->Write();
				hdataTagjetSignImpXYZSig[binJetPt][binTrackPt]->Write();
				hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Write();
				hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt]->Write();
				hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt]->Write();
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
      hsimTagjetPt[binFlavour]->Write();
      hsimTagjetNormalizedPt[binFlavour]->Write();
		  for (int binJetPt =0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        hsimTagjetTrackPt[binFlavour][binJetPt]->Write();
        hsimTagjetTrackEta[binFlavour][binJetPt]->Write();
        hsimTagjetTrackPhi[binFlavour][binJetPt]->Write();
        hsimTagjetImpXY[binFlavour][binJetPt]->Write();
        hsimTagjetSignImpXY[binFlavour][binJetPt]->Write();
        hsimTagjetImpXYSig[binFlavour][binJetPt]->Write();
        hsimTagjetSignImpXYSig[binFlavour][binJetPt]->Write();
        hsimTagjetImpZ[binFlavour][binJetPt]->Write();
        hsimTagjetSignImpZ[binFlavour][binJetPt]->Write();
        hsimTagjetImpZSig[binFlavour][binJetPt]->Write();
        hsimTagjetSignImpZSig[binFlavour][binJetPt]->Write();
        hsimTagjetImpXYZ[binFlavour][binJetPt]->Write();
        hsimTagjetSignImpXYZ[binFlavour][binJetPt]->Write();
        hsimTagjetImpXYZSig[binFlavour][binJetPt]->Write();
        hsimTagjetSignImpXYZSig[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedTrackPt[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedTrackEta[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedTrackPhi[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedImpXY[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedSignImpXY[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedImpXYSig[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedSignImpXYSig[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedImpZ[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedSignImpZ[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedImpZSig[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedSignImpZSig[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedImpXYZ[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedSignImpXYZ[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedImpXYZSig[binFlavour][binJetPt]->Write();
        hsimTagjetNormalizedSignImpXYZSig[binFlavour][binJetPt]->Write();
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

// Draw function
void HfJetTaggingAnalysis::histColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingAnalysis::drawCombined(int num, const std::vector<HistogramData>& histograms, bool withLeg, double xmin=0, double ymin=0, double xmax=1, double ymax=1){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  SetLegendBoxSize(leg, num);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->histColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (withLeg) leg->Draw();
}

void HfJetTaggingAnalysis::drawDataJetPt(bool doLog) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedPt, "abc"});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], "#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{jet}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/jetmomentum.pdf\")", canvasNum - 1, DATASET.Data()));
}

void HfJetTaggingAnalysis::drawDataTrackPt(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedTrackPt[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/trackmomentum_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataTrackEta(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedTrackEta[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "#eta_{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{#eta}_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/tracketa_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataTrackPhi(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedTrackPhi[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "#phi_{track}", "frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{#phi}_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/trackphi_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXY(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXY[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  gStyle->SetOptStat(1110);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XY}}}");
  //this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  hdataTagjetNormalizedImpXY[binJetPt]->SetStats(1);
  hdataTagjetNormalizedImpXY[binJetPt]->Draw();
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXY_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  hdataTagjetNormalizedImpXY[binJetPt]->SetStats(0);
}

void HfJetTaggingAnalysis::drawDataSignImpXY(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedSignImpXY[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  gStyle->SetOptStat(1110);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "sIP_{XY} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{sXY}}}");
  //this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  hdataTagjetNormalizedSignImpXY[binJetPt]->SetStats(1);
  hdataTagjetNormalizedSignImpXY[binJetPt]->Draw();
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpXY_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  hdataTagjetNormalizedSignImpXY[binJetPt]->SetStats(0);
}

void HfJetTaggingAnalysis::drawDataImpXYSig(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXYSig[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  gStyle->SetOptStat(1110);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XY}}}");
  //this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  hdataTagjetNormalizedImpXYSig[binJetPt]->SetStats(1);
  hdataTagjetNormalizedImpXYSig[binJetPt]->Draw();
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXYSig_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  hdataTagjetNormalizedImpXYSig[binJetPt]->SetStats(0);
}

void HfJetTaggingAnalysis::drawDataSignImpXYSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  gStyle->SetOptStat(1110);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "sIPs_{XY} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  //this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->SetStats(1);
  hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Draw();
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpXYSig_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
  hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->SetStats(0);
}

void HfJetTaggingAnalysis::drawDataImpXY4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXY[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXY[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedImpXYSig[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas4x1(canvasNum++);
  for (int mpad=0; mpad<4; mpad++){
    canvasHandler->drawPad(NormHistList, doLog, canvasNum-1, mpad, HfJetTagging::REFIPXY[mpad][0], HfJetTagging::REFIPXY[mpad][1], HfJetTagging::REFIPXY[mpad][2], HfJetTagging::REFIPXY[mpad][3], HfJetTagging::X_AXIS_IMPXY[mpad], HfJetTagging::Y_AXIS_IMPXY[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXY4x1_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXY2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXY[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXY[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedImpXYSig[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas2x2(canvasNum++);
  for (int mpad=0; mpad<4; mpad++){
    canvasHandler->drawPad(NormHistList, doLog, canvasNum-1, mpad, HfJetTagging::REFIPXY[mpad][0], HfJetTagging::REFIPXY[mpad][1], HfJetTagging::REFIPXY[mpad][2], HfJetTagging::REFIPXY[mpad][3], HfJetTagging::X_AXIS_IMPXY[mpad], HfJetTagging::Y_AXIS_IMPXY[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXY2x2_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpZ[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], "IP_{Z} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{Z}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpZ_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedSignImpZ[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], "sIP_{Z} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIP_{Z}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpZ_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpZSig(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpZSig[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], "IPs_{Z} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{Z}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpZSig_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpZSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], "sIPs_{Z} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{Z}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpZSig_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedImpZSig[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas4x1(canvasNum++);
  for (int mpad=0; mpad<4; mpad++){
    canvasHandler->drawPad(NormHistList, doLog, canvasNum-1, mpad, HfJetTagging::REFIPZ[mpad][0], HfJetTagging::REFIPZ[mpad][1], HfJetTagging::REFIPZ[mpad][2], HfJetTagging::REFIPZ[mpad][3], HfJetTagging::X_AXIS_IMPZ[mpad], HfJetTagging::Y_AXIS_IMPZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpZ4x1_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpZ2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedImpZSig[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpZSig[binJetPt][binTrackPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas2x2(canvasNum++);
  for (int mpad=0; mpad<4; mpad++){
    canvasHandler->drawPad(NormHistList, doLog, canvasNum-1, mpad, HfJetTagging::REFIPZ[mpad][0], HfJetTagging::REFIPZ[mpad][1], HfJetTagging::REFIPZ[mpad][2], HfJetTagging::REFIPZ[mpad][3], HfJetTagging::X_AXIS_IMPZ[mpad], HfJetTagging::Y_AXIS_IMPZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpZ2x2_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ2x2(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXYZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedImpXYZSig[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas2x2(canvasNum++);
  for (int mpad=0; mpad<4; mpad++){
    canvasHandler->drawPad(NormHistList, doLog, canvasNum-1, mpad, HfJetTagging::REFIPXYZ[mpad][0], HfJetTagging::REFIPXYZ[mpad][1], HfJetTagging::REFIPXYZ[mpad][2], HfJetTagging::REFIPXYZ[mpad][3], HfJetTagging::X_AXIS_IMPXYZ[mpad], HfJetTagging::Y_AXIS_IMPXYZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXYZ2x2_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}



void HfJetTaggingAnalysis::drawDataImpXYZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXYZ[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XYZ} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXYZ_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYZ(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYZ[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "sIP_{XYZ} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIP_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpXYZ_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZSig(bool doLog, int binJetPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXYZSig[binJetPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "IPs_{XYZ} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXYZSig_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawDataSignImpXYZSig(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt], ""});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "sIPs_{XYZ} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpXYZSig_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawDataImpXYZ4x1(bool doLog, int binJetPt=0, int binTrackPt=0) {
	std::vector<HistogramData> NormHistList;
	NormHistList.push_back({hdataTagjetNormalizedImpXYZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYZ[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedImpXYZSig[binJetPt], ""});
	NormHistList.push_back({hdataTagjetNormalizedSignImpXYZSig[binJetPt][binTrackPt], ""});
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas4x1(canvasNum++);
  for (int mpad=0; mpad<4; mpad++) {
    canvasHandler->drawPad(NormHistList, doLog, canvasNum-1, mpad, HfJetTagging::REFIPXYZ[mpad][0], HfJetTagging::REFIPXYZ[mpad][1], HfJetTagging::REFIPXYZ[mpad][2], HfJetTagging::REFIPXYZ[mpad][3], HfJetTagging::X_AXIS_IMPXYZ[mpad], HfJetTagging::Y_AXIS_IMPXYZ[mpad]);
  }
  latexDataJetInfo(0.2, 0.9, binJetPt);
  latexDataSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/ImpXYZ4x1_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
}

void HfJetTaggingAnalysis::drawSimJetPt(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedPt[0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedPt[1], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedPt[2], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedPt[3], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], "#it{p}_{T}^{jet}", "#frac{1}{#it{N_{jet}}} #frac{d#it{N_{jet}}}{d#it{p_{T}^{jet}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/jetmomentum.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackPt(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedTrackPt[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPt[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPt[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPt[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPT[0], HfJetTagging::REFHIST::TRACKPT[1], HfJetTagging::REFHIST::TRACKPT[2], HfJetTagging::REFHIST::TRACKPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/trackmomentum_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackPt(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> NormHistList;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPt[flavour][binJetPt+1], Form("%0.f<jet pT<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPTASJETPT[0], HfJetTagging::REFHIST::TRACKPTASJETPT[1], HfJetTagging::REFHIST::TRACKPTASJETPT[2], HfJetTagging::REFHIST::TRACKPTASJETPT[3], "#it{p}_{T}^{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/%sjet/trackmomentum.pdf\")", canvasNum - 1, SIMSET.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackEta(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedTrackEta[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackEta[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackEta[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackEta[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETA[0], HfJetTagging::REFHIST::TRACKETA[1], HfJetTagging::REFHIST::TRACKETA[2], HfJetTagging::REFHIST::TRACKETA[3], "#eta_{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{#eta}_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/tracketa_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackEta(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> NormHistList;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackEta[flavour][binJetPt+1], Form("%0.f<jet #eta<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();

  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKETAASJETPT[0], HfJetTagging::REFHIST::TRACKETAASJETPT[1], HfJetTagging::REFHIST::TRACKETAASJETPT[2], HfJetTagging::REFHIST::TRACKETAASJETPT[3], "#eta_{track}", " #frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{#eta}_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/%sjet/tracketa.pdf\")", canvasNum - 1, SIMSET.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetTrackPhi(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedTrackPhi[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPhi[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPhi[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedTrackPhi[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHI[0], HfJetTagging::REFHIST::TRACKPHI[1], HfJetTagging::REFHIST::TRACKPHI[2], HfJetTagging::REFHIST::TRACKPHI[3], "#phi_{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{#phi}_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  if (binJetPt == 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet}", static_cast<int>(HfJetTagging::cutJetPt)));
  if (binJetPt > 0) latex.DrawLatex(0.3, 0.9, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/trackphi_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingAnalysis::drawSimFlavourJetTrackPhi(bool doLog = true, int flavour =2, int startJetPt=0) {
  std::vector<HistogramData> NormHistList;
  for (int binJetPt =startJetPt; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
    NormHistList.push_back({hsimTagjetNormalizedTrackPhi[flavour][binJetPt+1], Form("%0.f<jet #phi<%0.f",HfJetTagging::binsJetPt[binJetPt], HfJetTagging::binsJetPt[binJetPt+1])});
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::TRACKPHIASJETPT[0], HfJetTagging::REFHIST::TRACKPHIASJETPT[1], HfJetTagging::REFHIST::TRACKPHIASJETPT[2], HfJetTagging::REFHIST::TRACKPHIASJETPT[3], "#phi_{track}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{#phi}_{track}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/%sjet/trackphi.pdf\")", canvasNum - 1, SIMSET.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
}

void HfJetTaggingAnalysis::drawSimJetImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXY[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "IP_{XY} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpXY_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], "Signed IP_{XY} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIP_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpXY_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpXYSignificance_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpXYSignificance_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXY2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXY;
  if (withInc) histListImpXY.push_back({hsimTagjetNormalizedImpXY[0][binJetPt], HfJetTagging::INCJET});
  histListImpXY.push_back({hsimTagjetNormalizedImpXY[1][binJetPt], HfJetTagging::CJET});
  histListImpXY.push_back({hsimTagjetNormalizedImpXY[2][binJetPt], HfJetTagging::BJET});
  histListImpXY.push_back({hsimTagjetNormalizedImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXY;
  if (withInc) histListSignImpXY.push_back({hsimTagjetNormalizedSignImpXY[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXY.push_back({hsimTagjetNormalizedSignImpXY[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXY.push_back({hsimTagjetNormalizedSignImpXY[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXY.push_back({hsimTagjetNormalizedSignImpXY[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYSig;
  if (withInc) histListImpXYSig.push_back({hsimTagjetNormalizedImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYSig.push_back({hsimTagjetNormalizedImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histListImpXYSig.push_back({hsimTagjetNormalizedImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histListImpXYSig.push_back({hsimTagjetNormalizedImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYSig;
  if (withInc) histListSignImpXYSig.push_back({hsimTagjetNormalizedSignImpXYSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYSig.push_back({hsimTagjetNormalizedSignImpXYSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYSig.push_back({hsimTagjetNormalizedSignImpXYSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYSig.push_back({hsimTagjetNormalizedSignImpXYSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler->createCanvas2x2(canvasNum++);
  int numCan = canvasNum-1;
  int mpad=0;

  // mpad0
  canvasHandler->drawPadCombined(histListImpXY, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);

  // mpad1
  canvasHandler->drawPadCombined(histListSignImpXY, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);

  // mpad2
  canvasHandler->drawPadCombined(histListImpXYSig, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);

  // mpad3
  canvasHandler->drawPadCombined(histListSignImpXYSig, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::Y_AXIS_IMPXY[3]);

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpXY2x2_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZ2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpZ;
  if (withInc) histListImpZ.push_back({hsimTagjetNormalizedImpZ[0][binJetPt], HfJetTagging::INCJET});
  histListImpZ.push_back({hsimTagjetNormalizedImpZ[1][binJetPt], HfJetTagging::CJET});
  histListImpZ.push_back({hsimTagjetNormalizedImpZ[2][binJetPt], HfJetTagging::BJET});
  histListImpZ.push_back({hsimTagjetNormalizedImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpZ;
  if (withInc) histListSignImpZ.push_back({hsimTagjetNormalizedSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpZ.push_back({hsimTagjetNormalizedSignImpZ[1][binJetPt], HfJetTagging::CJET});
  histListSignImpZ.push_back({hsimTagjetNormalizedSignImpZ[2][binJetPt], HfJetTagging::BJET});
  histListSignImpZ.push_back({hsimTagjetNormalizedSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpZSig;
  if (withInc) histListImpZSig.push_back({hsimTagjetNormalizedImpZSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpZSig.push_back({hsimTagjetNormalizedImpZSig[1][binJetPt], HfJetTagging::CJET});
  histListImpZSig.push_back({hsimTagjetNormalizedImpZSig[2][binJetPt], HfJetTagging::BJET});
  histListImpZSig.push_back({hsimTagjetNormalizedImpZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpZSig;
  if (withInc) histListSignImpZSig.push_back({hsimTagjetNormalizedSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpZSig.push_back({hsimTagjetNormalizedSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpZSig.push_back({hsimTagjetNormalizedSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpZSig.push_back({hsimTagjetNormalizedSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler->createCanvas2x2(canvasNum++);
  int numCan = canvasNum-1;
  int mpad=0;

  // mpad0
  canvasHandler->drawPadCombined(histListImpZ, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[0], HfJetTagging::Y_AXIS_IMPZ[0]);

  // mpad1
  canvasHandler->drawPadCombined(histListSignImpZ, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], HfJetTagging::X_AXIS_IMPZ[1], HfJetTagging::Y_AXIS_IMPZ[1]);

  // mpad2
  canvasHandler->drawPadCombined(histListImpZSig, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[2], HfJetTagging::Y_AXIS_IMPZ[2]);

  // mpad3
  canvasHandler->drawPadCombined(histListSignImpZSig, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], HfJetTagging::X_AXIS_IMPZ[3], HfJetTagging::Y_AXIS_IMPZ[3]);

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpZ2x2_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZ2x2(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> histListImpXYZ;
  if (withInc) histListImpXYZ.push_back({hsimTagjetNormalizedImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYZ.push_back({hsimTagjetNormalizedImpXYZ[1][binJetPt], HfJetTagging::CJET});
  histListImpXYZ.push_back({hsimTagjetNormalizedImpXYZ[2][binJetPt], HfJetTagging::BJET});
  histListImpXYZ.push_back({hsimTagjetNormalizedImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYZ;
  if (withInc) histListSignImpXYZ.push_back({hsimTagjetNormalizedSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYZ.push_back({hsimTagjetNormalizedSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYZ.push_back({hsimTagjetNormalizedSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYZ.push_back({hsimTagjetNormalizedSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListImpXYZSig;
  if (withInc) histListImpXYZSig.push_back({hsimTagjetNormalizedImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  histListImpXYZSig.push_back({hsimTagjetNormalizedImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  histListImpXYZSig.push_back({hsimTagjetNormalizedImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  histListImpXYZSig.push_back({hsimTagjetNormalizedImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  std::vector<HistogramData> histListSignImpXYZSig;
  if (withInc) histListSignImpXYZSig.push_back({hsimTagjetNormalizedSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  histListSignImpXYZSig.push_back({hsimTagjetNormalizedSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  histListSignImpXYZSig.push_back({hsimTagjetNormalizedSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  histListSignImpXYZSig.push_back({hsimTagjetNormalizedSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler->createCanvas2x2(canvasNum++);
  int numCan = canvasNum-1;
  int mpad=0;

  // mpad0
  canvasHandler->drawPadCombined(histListImpXYZ, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[0], HfJetTagging::Y_AXIS_IMPXYZ[0]);

  // mpad1
  canvasHandler->drawPadCombined(histListSignImpXYZ, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], HfJetTagging::X_AXIS_IMPXYZ[1], HfJetTagging::Y_AXIS_IMPXYZ[1]);

  // mpad2
  canvasHandler->drawPadCombined(histListImpXYZSig, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[2], HfJetTagging::Y_AXIS_IMPXYZ[2]);

  // mpad3
  canvasHandler->drawPadCombined(histListSignImpXYZSig, false, doLog, numCan, mpad++, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], HfJetTagging::X_AXIS_IMPXYZ[3], HfJetTagging::Y_AXIS_IMPXYZ[3]);

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpXYZ2x2_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpZ[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpZ[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpZ[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpZ[3][0], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], "IP_{Z} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpZ_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpZ[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpZ[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpZ[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpZ[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZ[0], HfJetTagging::REFHIST::IPZ[1], HfJetTagging::REFHIST::IPZ[2], HfJetTagging::REFHIST::IPZ[3], "Signed IP_{Z} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIP_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpZ_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpZSig[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpZSig[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpZSig[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], "IPs_{Z}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpZSignificance_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpZSig[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpZSig[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpZSig[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpZSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPZSIG[0], HfJetTagging::REFHIST::IPZSIG[1], HfJetTagging::REFHIST::IPZSIG[2], HfJetTagging::REFHIST::IPZSIG[3], "Signed IPs_{Z}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpZSignificance_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZ[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZ[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "IP_{XYZ} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IP_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpXYZ_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYZ(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZ[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZ[0], HfJetTagging::REFHIST::IPXYZ[1], HfJetTagging::REFHIST::IPXYZ[2], HfJetTagging::REFHIST::IPXYZ[3], "Signed IP_{XYZ} [#mum]", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIP_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpXYZ_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetImpXYZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "IPs_{XYZ}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{IPs_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/ImpXYZSignificance_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingAnalysis::drawSimJetSignImpXYZSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYZSig[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYZSIG[0], HfJetTagging::REFHIST::IPXYZSIG[1], HfJetTagging::REFHIST::IPXYZSIG[2], HfJetTagging::REFHIST::IPXYZSIG[3], "Signed IPs_{XYZ}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XYZ}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
  latexSimSet();
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpXYZSignificance_%d.pdf\")", canvasNum - 1, SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

//void HfJetTaggingAnalysis::drawDataVsMCTagJetSignImpXYSig(bool doLog = true, int binJetPt=0, int binTrackPt=0) {
//  std::vector<HistogramData> NormHistList;
//  NormHistList.push_back({hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt], "Data"});
//  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt], "MC"});
//
//  canvasHandler = new CanvasHandler();
//  canvasHandler->createCanvas(canvasNum++);
//  if (doLog) gPad->SetLogy();
//  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
//  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
//  latexSimJetInfo(0.2, 0.9, binJetPt, triggerName.Data());
//  latexDataSet(0.6);
//  latexSimSet();
//  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/%s_%s/genHfTag/SignImpXYSignificance_%d_%d.pdf\")", canvasNum - 1, DATASET.Data(), SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
//}

void HfJetTaggingAnalysis::drawDataVsMCTagJetImpXY(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedImpXY[binJetPt], Form("Data (%s)", DATASET.Data())});
  NormHistList.push_back({hsimTagjetNormalizedImpXY[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalizedImpXY[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimTagjetNormalizedImpXY[0][binJetPt]);
  canvasHandler = new CanvasHandler();
  canvasHandler->createRatioCanvas(canvasNum);
  gROOT->ProcessLine(Form("padu%d->cd()", canvasNum));
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 0, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::Y_AXIS_IMPXY[0]);
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", canvasNum));
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 1, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[0], "Data/MC");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/%s_%s/genHfTag/ImpXY_%d.pdf\")", canvasNum, DATASET.Data(), SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  canvasNum++;
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetSignImpXY(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedSignImpXY[binJetPt], Form("Data (%s)", DATASET.Data())});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXY[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalizedSignImpXY[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimTagjetNormalizedSignImpXY[0][binJetPt]);
  canvasHandler = new CanvasHandler();
  canvasHandler->createRatioCanvas(canvasNum);
  gROOT->ProcessLine(Form("padu%d->cd()", canvasNum));
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 0, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::Y_AXIS_IMPXY[1]);
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", canvasNum));
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 1, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[1], "Data/MC");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/%s_%s/genHfTag/SignImpXY_%d.pdf\")", canvasNum, DATASET.Data(), SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  canvasNum++;
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetImpXYSig(bool doLog = true, int binJetPt=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedImpXYSig[binJetPt], Form("Data (%s)", DATASET.Data())});
  NormHistList.push_back({hsimTagjetNormalizedImpXYSig[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalizedImpXYSig[binJetPt]->Clone("hRatio"));
  hRatio->Divide(hsimTagjetNormalizedImpXYSig[0][binJetPt]);
  canvasHandler = new CanvasHandler();
  canvasHandler->createRatioCanvas(canvasNum);
  gROOT->ProcessLine(Form("padu%d->cd()", canvasNum));
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 0, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::Y_AXIS_IMPXY[2]);
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", canvasNum));
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 1, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], HfJetTagging::X_AXIS_IMPXY[2], "Data/MC");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/%s_%s/genHfTag/ImpXYSignificance_%d.pdf\")", canvasNum, DATASET.Data(), SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  canvasNum++;
}

void HfJetTaggingAnalysis::drawDataVsMCTagJetSignImpXYSig(bool doLog = true, int binJetPt=0, int binTrackPt=0) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt], Form("Data (%s)", DATASET.Data())});
  NormHistList.push_back({hsimTagjetNormalizedSignImpXYSig[0][binJetPt], Form("MC (%s)", SIMSET.Data())});
  
  TH1F *hRatio = static_cast<TH1F*>(hdataTagjetNormalizedSignImpXYSig[binJetPt][binTrackPt]->Clone("hRatio"));
  hRatio->Divide(hsimTagjetNormalizedSignImpXYSig[0][binJetPt]);
  canvasHandler = new CanvasHandler();
  canvasHandler->createRatioCanvas(canvasNum);
  gROOT->ProcessLine(Form("padu%d->cd()", canvasNum));
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 0, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("padd%d->cd()", canvasNum));
  canvasHandler->DrawRefHistogramWithPad(canvasNum, 1, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::RATIO[2], HfJetTagging::REFHIST::RATIO[3], "Signed IPs_{XY}", "Data/MC");
  hRatio->Draw("same");

  gROOT->ProcessLine(Form("cc%d->Print(\"fig/dataVSsim/%s_%s/genHfTag/SignImpXYSignificance_%d_%d.pdf\")", canvasNum, DATASET.Data(), SIMSET.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt]), static_cast<int>(HfJetTagging::binsTrackPt[binTrackPt])));
  canvasNum++;
}

void HfJetTaggingAnalysis::fitDataJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hdataTagjetSignImpXYSig[0][0], ""});
  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParLimits(1, -3, 3);
  hdataTagjetSignImpXYSig[0][0]->Fit(fResoFunc, "QRL");

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

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimTagjetSignImpXYSig[0][0]->GetMaximum() * 10, "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/data/%s/genHfTag/SignImpXYSignificanceWithFit.pdf\")", canvasNum - 1, DATASET.Data()));

}

void HfJetTaggingAnalysis::fitincJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTagjetSignImpXYSig[0][0], HfJetTagging::INCJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParLimits(1, -3, 3);
  //hsimTagjetSignImpXYSig[0][0]->Fit(fResoFunc, "QRL");
  hsimTagjetSignImpXYSig[0][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Writing parameters to a text file
  std::ofstream outData("paramsMC.txt");
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

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimTagjetSignImpXYSig[0][0]->GetMaximum() * 10, "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/incjet/SignImpXYSignificanceWithFit.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingAnalysis::fitcJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTagjetSignImpXYSig[1][0], HfJetTagging::CJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParLimits(0, 0, 1e+10);
  fResoFunc->SetParLimits(1, -3, 3);
  hsimTagjetSignImpXYSig[1][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);

  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimTagjetSignImpXYSig[0][0]->GetMaximum() * 10, "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/cjet/SignImpXYSignificanceWithFit.pdf\")", canvasNum - 1, SIMSET.Data()));

}

void HfJetTaggingAnalysis::fitbJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTagjetSignImpXYSig[2][0], HfJetTagging::BJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParLimits(0, 0, 1e+10);
  fResoFunc->SetParLimits(1, -3, 3);
  hsimTagjetSignImpXYSig[2][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);
  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimTagjetSignImpXYSig[0][0]->GetMaximum() * 10, "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/bjet/SignImpXYSignificanceWithFit.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingAnalysis::fitlfJetSignImpXYSignificance(bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  NormHistList.push_back({hsimTagjetSignImpXYSig[3][0], HfJetTagging::LFJET});

  TF1 *fResoFunc = new TF1("fResoFunc", "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
  fResoFunc->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
  fResoFunc->SetParLimits(1, -3, 3);
  hsimTagjetSignImpXYSig[3][0]->Fit(fResoFunc, "QRL");

  double params[9];
  fResoFunc->GetParameters(params); // Retrieve the parameters

  // Constructing the equation string with parameter values
  TString equation = Form("f(x) = (%.3f e^{-(x-%.3f)^{2}/(2#times%.3f^{2})}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx}) + (%.3fe^{%.3fx})", 
      params[0], params[1],
      params[2], params[3],
      params[4], params[5],
      params[6], params[7], params[8]);
  // Position to draw the equation on the canvas
  double posX = 0.15, posY = 0.85;

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimTagjetSignImpXYSig[0][0]->GetMaximum() * 10, "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, false);
  latex.DrawLatex(posX, posY, equation);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/lfjet/SignImpXYSignificanceWithFit.pdf\")", canvasNum - 1, SIMSET.Data()));
}

void HfJetTaggingAnalysis::fitTaggedJetSignImpXYSignificance(bool withInc = false, bool doLog = true) {
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetSignImpXYSig[0][0], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetSignImpXYSig[1][0], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetSignImpXYSig[2][0], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetSignImpXYSig[3][0], HfJetTagging::LFJET});
  TF1 *fResoFunc[HfJetTagging::nFlavour+1];
  // Open a file to save the parameters
  std::ofstream outFile("fitParameters.txt");

  for (int flavour=0; flavour<HfJetTagging::nFlavour+1; flavour++) {
    fResoFunc[flavour]= new TF1(Form("fResoFunc_%d", flavour), "gaus(0)+expo(3)+expo(5)+expo(7)", -40, 0);
    fResoFunc[flavour]->SetParameters(1, 0, 1, 1, 0.5, 1, 0.5, 1, 0.5);
    fResoFunc[flavour]->SetParLimits(6, 0, 1e+10);
    fResoFunc[flavour]->SetParLimits(7, -1, 1);
    hsimTagjetSignImpXYSig[flavour][0]->Fit(fResoFunc[flavour], "QRL");

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

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], 0.1, hsimTagjetSignImpXYSig[0][0]->GetMaximum()*10, "Signed IPs_{XY}", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{sIPs_{XY}}}");
  this->drawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/%s/genHfTag/SignImpXYSignificanceWithFit.pdf\")", canvasNum - 1, SIMSET.Data()));
}

#endif // HFJETTAGGINGANALYSIS_H 
