#ifndef HFJETTAGGINGSYSANALYSIS_H
#define HFJETTAGGINGSYSANALYSIS_H

#include <TH1F.h>
#include <TString.h>
#include <vector>
#include <array>
#include "CanvasHandler.h"
#include "DataPoint.h"
#include "HfJetTaggingUtilities.h"

class HfJetTaggingSysAnalysis {
  public:
    HfJetTaggingSysAnalysis() {
      initConfig();
    }
    HfJetTaggingSysAnalysis(int nccc) {
      initConfig();
      gnc=nccc;
    }
    ~HfJetTaggingSysAnalysis();

    void initConfig();
    int processSetUp(const std::vector<std::pair<TString, TString>> &rootFiles);
    int loadData(const std::vector<std::pair<TString, TString>> &rootFiles);
    int loadSim(const std::vector<std::pair<TString, TString>> &rootFiles);
    void initHist();
    void projHist();
    void normHist();
    void initAnalysis(const std::vector<std::pair<TString, TString>> &rootFiles);
    void saveHist();
    void savePara();

    // fucntion
    // Set
    void setFillData(bool fillData);
    void setFillMCD(bool fillMCD);
    void setFillMCP(bool fillMCP);
    void setFillIPxy(bool fillIPxy);
    void setFillIPz(bool fillIPz);
    void setFillIPxyz(bool fillIPxyz);
    void setFillTC(bool fillTC);
    void setFillJP(bool fillJP);
    void setFillSV(bool fillSV);

    // Get
    int getNC();
    float getErrorShower();
    float getErrorRadius();
    float getErrorTS();
    float getErrorUnfold();

    // draw
    void drawDataJetPt(bool doLog);
    void drawDataJetEta(bool doLog);
    void drawDataJetPhi(bool doLog);
    void drawDataJetImpXY(bool doLog, int binJetPt);
    void drawDataJetSignImpXY(bool doLog, int binJetPt);
    void drawDataJetImpXYSignificance(bool doLog, int binJetPt);
    void drawDataJetSignImpXYSignificance(bool doLog, int binJetPt);
    void drawDataJetSignImpXYSignificanceN1(bool doLog, int binJetPt);
    void drawDataJetSignImpXYSignificanceN2(bool doLog, int binJetPt);
    void drawDataJetSignImpXYSignificanceN3(bool doLog, int binJetPt);
    void drawData3ProngLxy(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngLxyz(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngSxy(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngSxyz(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngMassN1(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngtaggedjetSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngtaggedjetSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawData3ProngtaggedjetMassN1(bool withInc, bool doLog, int binJetPt);

    void drawSimJetPt(bool withInc, bool doLog);
    void drawSimJetEta(bool withInc, bool doLog);
    void drawSimJetPhi(bool withInc, bool doLog);
    void drawSimJetImpXY(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXY(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpZ(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZ(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYZ(bool withInc, bool doLog, int binJetPT);
    void drawSimJetSignImpXYZ(bool withInc, bool doLog, int binJetPt);
    void drawSimJetImpXYZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificance(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYSignificanceN3(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpZSignificanceN3(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN1(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN2(bool withInc, bool doLog, int binJetPt);
    void drawSimJetSignImpXYZSignificanceN3(bool withInc, bool doLog, int binJetPt);
    void drawSimJetNegLogJP(bool withInc, bool doLog, int binJetPt);
    void drawSimJetNegLogJPN1(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN2(bool withInc, bool doLog, int binJetPt, float cutImp);
    void drawSimJetNegLogJPN3(bool withInc, bool doLog, int binJetPt, float cutImp);

    void drawSim3ProngRawLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngRawMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngtaggedjetRawSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngtaggedjetRawSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngtaggedjetRawMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngsigmaLxy(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngsigmaLxyz(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngMassN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngtaggedjetSxyN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngtaggedjetSxyzN1(bool withInc, bool doLog, int binJetPt);
    void drawSim3ProngtaggedjetMassN1(bool withInc, bool doLog, int binJetPt);
 
    // histogram from root
  // data
    std::vector<TH1F*> hdatajetPt;
    std::vector<TH1F*> hdatajetEta;
    std::vector<TH1F*> hdatajetPhi;


    std::vector<TH2F*> h2datajetPtImpXY;
    std::vector<TH2F*> h2datajetPtSignImpXY;
    std::vector<TH2F*> h2datajetPtImpXYSig;
    std::vector<TH2F*> h2datajetPtSignImpXYSig;
    std::vector<TH2F*> h2datajetPtSignImpXYSigN1;
    std::vector<TH2F*> h2datajetPtSignImpXYSigN2;
    std::vector<TH2F*> h2datajetPtSignImpXYSigN3;
    
  // mc
    /// for IP
    std::vector<TH2F*> h2simjetPtFlavour;
    std::vector<TH2F*> h2simjetEtaFlavour;
    std::vector<TH2F*> h2simjetPhiFlavour;
    std::vector<TH3F*> h3simjetPtImpXYFlavour;
    std::vector<TH3F*> h3simjetPtSignImpXYFlavour;
    std::vector<TH3F*> h3simjetPtImpXYSigFlavour;
    std::vector<TH3F*> h3simjetPtSignImpXYSigFlavour;
    std::vector<TH3F*> h3simjetPtImpZFlavour;
    std::vector<TH3F*> h3simjetPtSignImpZFlavour;
    std::vector<TH3F*> h3simjetPtImpZSigFlavour;
    std::vector<TH3F*> h3simjetPtSignImpZSigFlavour;
    std::vector<TH3F*> h3simjetPtImpXYZFlavour;
    std::vector<TH3F*> h3simjetPtSignImpXYZFlavour;
    std::vector<TH3F*> h3simjetPtImpXYZSigFlavour;
    std::vector<TH3F*> h3simjetPtSignImpXYZSigFlavour;
    std::vector<TH3F*> h3simjetPtSignImpXYSigN1Flavour;
    std::vector<TH3F*> h3simjetPtSignImpXYSigN2Flavour;
    std::vector<TH3F*> h3simjetPtSignImpXYSigN3Flavour;
    std::vector<TH3F*> h3simjetPtSignImpZSigN1Flavour;
    std::vector<TH3F*> h3simjetPtSignImpZSigN2Flavour;
    std::vector<TH3F*> h3simjetPtSignImpZSigN3Flavour;
    std::vector<TH3F*> h3simjetPtSignImpXYZSigN1Flavour;
    std::vector<TH3F*> h3simjetPtSignImpXYZSigN2Flavour;
    std::vector<TH3F*> h3simjetPtSignImpXYZSigN3Flavour;
    std::vector<TH3F*> h3simjetPtNegLogJPFlavour;
    std::vector<TH3F*> h3simjetPtNegLogJPN1Flavour;
    std::vector<TH3F*> h3simjetPtNegLogJPN2Flavour;
    std::vector<TH3F*> h3simjetPtNegLogJPN3Flavour;

    /// for SV
    std::vector<TH3F*> h3simjetPt3ProngLxyFlavour;
    std::vector<TH3F*> h3simjetPt3ProngLxyzFlavour;
    std::vector<TH3F*> h3simjetPt3ProngSxyFlavour;
    std::vector<TH3F*> h3simjetPt3ProngSxyzFlavour;
    std::vector<TH3F*> h3simjetPt3ProngsigmaLxyFlavour;
    std::vector<TH3F*> h3simjetPt3ProngsigmaLxyzFlavour;
    std::vector<TH3F*> h3simjetPt3ProngSxyN1Flavour;
    std::vector<TH3F*> h3simjetPt3ProngSxyzN1Flavour;
    std::vector<TH3F*> h3simjetPt3ProngMassN1Flavour;
    std::vector<TH3F*> h3simtaggedjetPt3ProngSxyN1Flavour;
    std::vector<TH3F*> h3simtaggedjetPt3ProngSxyzN1Flavour;
    std::vector<TH3F*> h3simtaggedjetPt3ProngMassN1Flavour;

    // initilize histogram for analysis

// data
    std::vector<TH1F*> hdatajetNormAreaPt;
    std::vector<TH1F*> hdatajetNormAreaEta;
    std::vector<TH1F*> hdatajetNormAreaPhi;
    std::vector<TH1F*> hdatajetNormNEventsPt;
    std::vector<TH1F*> hdatajetNormNEventsEta;
    std::vector<TH1F*> hdatajetNormNEventsPhi;
    std::vector<TH1F*> hdatajetNormNJetsPt;
    std::vector<TH1F*> hdatajetNormNJetsEta;
    std::vector<TH1F*> hdatajetNormNJetsPhi;

    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetSignImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetSignImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetSignImpXYSigN1;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetSignImpXYSigN2;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetSignImpXYSigN3;

    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaSignImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaSignImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaSignImpXYSigN1;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaSignImpXYSigN2;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormAreaSignImpXYSigN3;

    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsSignImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsSignImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsSignImpXYSigN1;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsSignImpXYSigN2;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNEventsSignImpXYSigN3;

    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsSignImpXY;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsSignImpXYSig;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsSignImpXYSigN1;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsSignImpXYSigN2;
    std::vector<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>> hdatajetNormNJetsSignImpXYSigN3;

// mc
    std::vector<std::array<TH1F*, HfJetTagging::nFlavour + 1>> hsimjetPt;
    std::vector<std::array<TH1F*, HfJetTagging::nFlavour + 1>> hsimjetEta;
    std::vector<std::array<TH1F*, HfJetTagging::nFlavour + 1>> hsimjetPhi;
    /// for IP
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetImpXY;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXY;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetImpXYSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetImpZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetImpZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetImpXYZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetImpXYZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYSigN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYSigN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYSigN3;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpZSigN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpZSigN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpZSigN3;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYZSigN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYZSigN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetSignImpXYZSigN3;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNegLogJP;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNegLogJPN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNegLogJPN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNegLogJPN3;

    /// for SV
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngLxy;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngLxyz;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngSxy;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngSxyz;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngsigmaLxy;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngsigmaLxyz;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngSxyN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngSxyzN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjet3ProngMassN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimtaggedjet3ProngSxyN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimtaggedjet3ProngSxyzN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimtaggedjet3ProngMassN1;

/// norm ////
    std::vector<std::array<TH1F*, HfJetTagging::nFlavour + 1>> hsimjetNormalizedPt;
    std::vector<std::array<TH1F*, HfJetTagging::nFlavour + 1>> hsimjetNormalizedEta;
    std::vector<std::array<TH1F*, HfJetTagging::nFlavour + 1>> hsimjetNormalizedPhi;
    /// for IP and norm
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedImpXY;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXY;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedImpXYSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedImpZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedImpZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedImpXYZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYZ;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedImpXYZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYZSig;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYSigN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYSigN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYSigN3;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpZSigN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpZSigN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpZSigN3;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYZSigN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYZSigN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedSignImpXYZSigN3;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedNegLogJP;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedNegLogJPN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedNegLogJPN2;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalizedNegLogJPN3;

    /// for SV and norm
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngLxy;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngLxyz;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngSxy;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngSxyz;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngsigmaLxy;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngsigmaLxyz;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngSxyN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngSxyzN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimjetNormalized3ProngMassN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimtaggedjetNormalized3ProngSxyN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimtaggedjetNormalized3ProngSxyzN1;
    std::vector<std::array<std::array<TH1F*, HfJetTagging::nBinsJetPt + 1>, HfJetTagging::nFlavour + 1>> hsimtaggedjetNormalized3ProngMassN1;

  protected:
    int nc=gnc;
    int numFiles = 0;
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;
    CanvasHandler* canHan;
    std::vector<std::pair<TString, TString>> files;
    bool fillData = false;
    bool fillMCD = false;
    bool fillMCP = false;
    bool fillIPxy = false;
    bool fillIPz = false;
    bool fillIPxyz = false;
    bool fillTC = false;
    bool fillJP = false;
    bool fillSV = false;

    TString dirFig = false;
    int errorShower[HfJetTagging::nBinsJetPt];
    int errorRadius[HfJetTagging::nBinsJetPt];
    int errorTS[HfJetTagging::nBinsJetPt];
    /// ... ///
    

  private:

};

HfJetTaggingSysAnalysis::~HfJetTaggingSysAnalysis() {

  for (auto& fileHist : h2simjetPtFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h2simjetEtaFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h2simjetPhiFlavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtImpXYFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtImpXYSigFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYSigFlavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtImpZFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtImpZSigFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpZFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpZSigFlavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtImpXYZFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtImpXYZSigFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYZFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYZSigFlavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtSignImpXYSigN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYSigN2Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYSigN3Flavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtSignImpZSigN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpZSigN2Flavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtSignImpXYZSigN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYZSigN2Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtSignImpXYZSigN3Flavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPtNegLogJPFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtNegLogJPN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtNegLogJPN2Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPtNegLogJPN3Flavour) if (fileHist) delete fileHist;

  for (auto& fileHist : h3simjetPt3ProngLxyFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngLxyzFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngSxyFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngSxyzFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngsigmaLxyFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngsigmaLxyzFlavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngSxyN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngSxyzN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simjetPt3ProngMassN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simtaggedjetPt3ProngSxyN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simtaggedjetPt3ProngSxyzN1Flavour) if (fileHist) delete fileHist;
  for (auto& fileHist : h3simtaggedjetPt3ProngMassN1Flavour) if (fileHist) delete fileHist;


  for (int numFile = 0; numFile < numFiles; numFile++) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour + 1; flavour++) {
      delete hsimjetPt[numFile][flavour];
      delete hsimjetEta[numFile][flavour];
      delete hsimjetPhi[numFile][flavour];

      for (int binJetPt = 0; binJetPt < HfJetTagging::nBinsJetPt + 1; binJetPt++) {
        if (fillIPxy) {
          delete hsimjetImpXY[numFile][flavour][binJetPt];
          delete hsimjetSignImpXY[numFile][flavour][binJetPt];
          delete hsimjetImpXYSig[numFile][flavour][binJetPt];
          delete hsimjetSignImpXYSig[numFile][flavour][binJetPt];
        }
        if (fillIPz) {
          delete hsimjetImpZ[numFile][flavour][binJetPt];
          delete hsimjetSignImpZ[numFile][flavour][binJetPt];
          delete hsimjetImpZSig[numFile][flavour][binJetPt];
          delete hsimjetSignImpZSig[numFile][flavour][binJetPt];
        }
        if (fillIPxyz) {
          delete hsimjetImpXYZ[numFile][flavour][binJetPt];
          delete hsimjetSignImpXYZ[numFile][flavour][binJetPt];
          delete hsimjetImpXYZSig[numFile][flavour][binJetPt];
          delete hsimjetSignImpXYZSig[numFile][flavour][binJetPt];
        }
        if (fillTC) {
          if (fillIPxy) {
            delete hsimjetSignImpXYSigN1[numFile][flavour][binJetPt];
            delete hsimjetSignImpXYSigN2[numFile][flavour][binJetPt];
            delete hsimjetSignImpXYSigN3[numFile][flavour][binJetPt];
          }
          if (fillIPz) {
            delete hsimjetSignImpZSigN1[numFile][flavour][binJetPt];
            delete hsimjetSignImpZSigN2[numFile][flavour][binJetPt];
            delete hsimjetSignImpZSigN3[numFile][flavour][binJetPt];
          }
          if (fillIPxyz) {
            delete hsimjetSignImpXYZSigN1[numFile][flavour][binJetPt];
            delete hsimjetSignImpXYZSigN2[numFile][flavour][binJetPt];
            delete hsimjetSignImpXYZSigN3[numFile][flavour][binJetPt];
          }
        }
        if (fillJP) {
          delete hsimjetNegLogJP[numFile][flavour][binJetPt];
          delete hsimjetNegLogJPN1[numFile][flavour][binJetPt];
          delete hsimjetNegLogJPN2[numFile][flavour][binJetPt];
          delete hsimjetNegLogJPN3[numFile][flavour][binJetPt];
        }
        if (fillSV) {
          delete hsimjet3ProngLxy[numFile][flavour][binJetPt];
          delete hsimjet3ProngLxyz[numFile][flavour][binJetPt];
          delete hsimjet3ProngsigmaLxy[numFile][flavour][binJetPt];
          delete hsimjet3ProngsigmaLxyz[numFile][flavour][binJetPt];
          delete hsimjet3ProngSxy[numFile][flavour][binJetPt];
          delete hsimjet3ProngSxyz[numFile][flavour][binJetPt];
          delete hsimjet3ProngSxyN1[numFile][flavour][binJetPt];
          delete hsimjet3ProngSxyzN1[numFile][flavour][binJetPt];
        }
      }
    }
  }
  if (fillMCD) {
    for (int numFile = 0; numFile < numFiles; numFile++) {
      for (int flavour = 0; flavour < HfJetTagging::nFlavour + 1; flavour++) {
        if (hsimjetNormalizedPt[numFile][flavour]) hsimjetNormalizedPt[numFile][flavour]->Delete();
        if (hsimjetNormalizedEta[numFile][flavour]) hsimjetNormalizedEta[numFile][flavour]->Delete();
        if (hsimjetNormalizedPhi[numFile][flavour]) hsimjetNormalizedPhi[numFile][flavour]->Delete();
        for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt + 1; jetPt++) {
          if (fillIPxy) {
            if (hsimjetNormalizedImpXY[numFile][flavour][jetPt]) hsimjetNormalizedImpXY[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedSignImpXY[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXY[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedImpXYSig[numFile][flavour][jetPt]) hsimjetNormalizedImpXYSig[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedSignImpXYSig[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYSig[numFile][flavour][jetPt]->Delete();
          }
          if (fillIPz) {
            if (hsimjetNormalizedImpZ[numFile][flavour][jetPt]) hsimjetNormalizedImpZ[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedSignImpZ[numFile][flavour][jetPt]) hsimjetNormalizedSignImpZ[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedImpZSig[numFile][flavour][jetPt]) hsimjetNormalizedImpZSig[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedSignImpZSig[numFile][flavour][jetPt]) hsimjetNormalizedSignImpZSig[numFile][flavour][jetPt]->Delete();
          }
          if (fillIPxyz) {
            if (hsimjetNormalizedImpXYZ[numFile][flavour][jetPt]) hsimjetNormalizedImpXYZ[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedSignImpXYZ[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYZ[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedImpXYZSig[numFile][flavour][jetPt]) hsimjetNormalizedImpXYZSig[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedSignImpXYZSig[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYZSig[numFile][flavour][jetPt]->Delete();
          }
          if (fillTC) {
            if (fillIPxy) {
              if (hsimjetNormalizedSignImpXYSigN1[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYSigN1[numFile][flavour][jetPt]->Delete();
              if (hsimjetNormalizedSignImpXYSigN2[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYSigN2[numFile][flavour][jetPt]->Delete();
              if (hsimjetNormalizedSignImpXYSigN3[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYSigN3[numFile][flavour][jetPt]->Delete();
            }
            if (fillIPz) {
              if (hsimjetNormalizedSignImpZSigN1[numFile][flavour][jetPt]) hsimjetNormalizedSignImpZSigN1[numFile][flavour][jetPt]->Delete();
              if (hsimjetNormalizedSignImpZSigN2[numFile][flavour][jetPt]) hsimjetNormalizedSignImpZSigN2[numFile][flavour][jetPt]->Delete();
              if (hsimjetNormalizedSignImpZSigN3[numFile][flavour][jetPt]) hsimjetNormalizedSignImpZSigN3[numFile][flavour][jetPt]->Delete();
            }
            if (fillIPxyz) {
              if (hsimjetNormalizedSignImpXYZSigN1[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYZSigN1[numFile][flavour][jetPt]->Delete();
              if (hsimjetNormalizedSignImpXYZSigN2[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYZSigN2[numFile][flavour][jetPt]->Delete();
              if (hsimjetNormalizedSignImpXYZSigN3[numFile][flavour][jetPt]) hsimjetNormalizedSignImpXYZSigN3[numFile][flavour][jetPt]->Delete();
            }
          }
          if (fillJP) {
            if (hsimjetNormalizedNegLogJP[numFile][flavour][jetPt]) hsimjetNormalizedNegLogJP[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedNegLogJPN1[numFile][flavour][jetPt]) hsimjetNormalizedNegLogJPN1[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedNegLogJPN2[numFile][flavour][jetPt]) hsimjetNormalizedNegLogJPN2[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalizedNegLogJPN3[numFile][flavour][jetPt]) hsimjetNormalizedNegLogJPN3[numFile][flavour][jetPt]->Delete();
          }
          if (fillSV) {
            if (hsimjetNormalized3ProngLxy[numFile][flavour][jetPt]) hsimjetNormalized3ProngLxy[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngLxyz[numFile][flavour][jetPt]) hsimjetNormalized3ProngLxyz[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngSxy[numFile][flavour][jetPt]) hsimjetNormalized3ProngSxy[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngSxyz[numFile][flavour][jetPt]) hsimjetNormalized3ProngSxyz[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngsigmaLxy[numFile][flavour][jetPt]) hsimjetNormalized3ProngsigmaLxy[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngsigmaLxyz[numFile][flavour][jetPt]) hsimjetNormalized3ProngsigmaLxyz[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngSxyN1[numFile][flavour][jetPt]) hsimjetNormalized3ProngSxyN1[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]) hsimjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]->Delete();
            if (hsimjetNormalized3ProngMassN1[numFile][flavour][jetPt]) hsimjetNormalized3ProngMassN1[numFile][flavour][jetPt]->Delete();
            if (hsimtaggedjetNormalized3ProngSxyN1[numFile][flavour][jetPt]) hsimtaggedjetNormalized3ProngSxyN1[numFile][flavour][jetPt]->Delete();
            if (hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]) hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]->Delete();
            if (hsimtaggedjetNormalized3ProngMassN1[numFile][flavour][jetPt]) hsimtaggedjetNormalized3ProngMassN1[numFile][flavour][jetPt]->Delete();
          }
        }
      }
    }
  }
}

void HfJetTaggingSysAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  //latex.SetTextFont(42);

  dirFig = "fig";
  if (!(SUFFIXSET.CompareTo("")==0)) {
    dirFig = Form("fig_%s", SUFFIXSET.Data());
  } 
  dirData = Form("%s/%s/data/%s/sys", dirFig.Data(), SOURCESET.Data(), DATASET.Data());
  dirSim = Form("%s/%s/sim/%s/sys", dirFig.Data(), SOURCESET.Data(), SIMSET.Data());
  //dirDataVsSim = Form("fig/%s/dataVSsim/%s_%s/sys", SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE);
  gSystem->mkdir(dirSim, kTRUE);
  //gSystem->mkdir(dirDataVsSim, kTRUE);
}

// Set function
void HfJetTaggingSysAnalysis::setFillData(bool mfillData) {
  fillData = mfillData;
  if (fillData) {
    std::cout << "Fill Data ON " << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillMCD(bool mfillMCD) {
  fillMCD = mfillMCD;
  if (fillMCD) {
    std::cout << "Fill MCD ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillMCP(bool mfillMCP) {
  fillMCP = mfillMCP;
  if (fillMCP) {
    std::cout << "Fill MCP ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillIPxy(bool mfillIPxy) {
  fillIPxy = mfillIPxy;
  if (fillIPxy) {
    std::cout << "Fill IPxy ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillIPz(bool mfillIPz) {
  fillIPz = mfillIPz;
  if (fillIPz) {
    std::cout << "Fill IPz ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillIPxyz(bool mfillIPxyz) {
  fillIPxyz = mfillIPxyz;
  if (fillIPxyz) {
    std::cout << "Fill IPxyz ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillTC(bool mfillTC) {
  fillTC = mfillTC;
  if (fillTC) {
    std::cout << "Fill TC ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillJP(bool mfillJP) {
  fillJP = mfillJP;
  if (fillJP) {
    std::cout << "Fill JP ON" << std::endl;
  }
}

void HfJetTaggingSysAnalysis::setFillSV(bool mfillSV) {
  fillSV = mfillSV;
  if (fillSV) {
    std::cout << "Fill SV ON" << std::endl;
  }
}

int HfJetTaggingSysAnalysis::getNC() {
  return gnc;
}

int HfJetTaggingSysAnalysis::processSetUp(const std::vector<std::pair<TString, TString>> &rootFiles) {
  numFiles = rootFiles.size();
  if (numFiles < 1) {
    std::cout << "no input file" << std::endl;
    return 0;
  }
  if (fillData) {
    hdatajetPt.resize(numFiles);
    hdatajetEta.resize(numFiles);
    hdatajetPhi.resize(numFiles);
    hdatajetNormAreaPt.resize(numFiles);
    hdatajetNormAreaEta.resize(numFiles);
    hdatajetNormAreaPhi.resize(numFiles);
    if (fillIPxy) {

    }
  }

  if (fillMCD) {
    h2simjetPtFlavour.resize(numFiles);
    h2simjetEtaFlavour.resize(numFiles);
    h2simjetPhiFlavour.resize(numFiles);
    hsimjetPt.resize(numFiles);
    hsimjetEta.resize(numFiles);
    hsimjetPhi.resize(numFiles);
    if (fillIPxy) {
      h3simjetPtImpXYFlavour.resize(numFiles);
      h3simjetPtSignImpXYFlavour.resize(numFiles);
      h3simjetPtImpXYSigFlavour.resize(numFiles);
      h3simjetPtSignImpXYSigFlavour.resize(numFiles);
      hsimjetImpXY.resize(numFiles);
      hsimjetSignImpXY.resize(numFiles);
      hsimjetImpXYSig.resize(numFiles);
      hsimjetSignImpXYSig.resize(numFiles);
      hsimjetNormalizedImpXY.resize(numFiles);
      hsimjetNormalizedSignImpXY.resize(numFiles);
      hsimjetNormalizedImpXYSig.resize(numFiles);
      hsimjetNormalizedSignImpXYSig.resize(numFiles);
    }
    if (fillIPz) {
      h3simjetPtImpZFlavour.resize(numFiles);
      h3simjetPtSignImpZFlavour.resize(numFiles);
      h3simjetPtImpZSigFlavour.resize(numFiles);
      h3simjetPtSignImpZSigFlavour.resize(numFiles);
      hsimjetImpZ.resize(numFiles);
      hsimjetSignImpZ.resize(numFiles);
      hsimjetImpZSig.resize(numFiles);
      hsimjetSignImpZSig.resize(numFiles);
      hsimjetNormalizedImpZ.resize(numFiles);
      hsimjetNormalizedSignImpZ.resize(numFiles);
      hsimjetNormalizedImpZSig.resize(numFiles);
      hsimjetNormalizedSignImpZSig.resize(numFiles);
    }
    if (fillIPxyz) {
      h3simjetPtImpXYZFlavour.resize(numFiles);
      h3simjetPtSignImpXYZFlavour.resize(numFiles);
      h3simjetPtImpXYZSigFlavour.resize(numFiles);
      h3simjetPtSignImpXYZSigFlavour.resize(numFiles);
      hsimjetImpXYZ.resize(numFiles);
      hsimjetSignImpXYZ.resize(numFiles);
      hsimjetImpXYZSig.resize(numFiles);
      hsimjetSignImpXYZSig.resize(numFiles);
      hsimjetNormalizedImpXYZ.resize(numFiles);
      hsimjetNormalizedSignImpXYZ.resize(numFiles);
      hsimjetNormalizedImpXYZSig.resize(numFiles);
      hsimjetNormalizedSignImpXYZSig.resize(numFiles);
    }
    if (fillTC) {
      if (fillIPxy) {
        h3simjetPtSignImpXYSigN1Flavour.resize(numFiles);
        h3simjetPtSignImpXYSigN2Flavour.resize(numFiles);
        h3simjetPtSignImpXYSigN3Flavour.resize(numFiles);
        hsimjetSignImpXYSigN1.resize(numFiles);
        hsimjetSignImpXYSigN2.resize(numFiles);
        hsimjetSignImpXYSigN3.resize(numFiles);
        hsimjetNormalizedSignImpXYSigN1.resize(numFiles);
        hsimjetNormalizedSignImpXYSigN2.resize(numFiles);
        hsimjetNormalizedSignImpXYSigN3.resize(numFiles);
      }
      if (fillIPz) {
        h3simjetPtSignImpZSigN1Flavour.resize(numFiles);
        h3simjetPtSignImpZSigN2Flavour.resize(numFiles);
        h3simjetPtSignImpZSigN3Flavour.resize(numFiles);
        hsimjetSignImpZSigN1.resize(numFiles);
        hsimjetSignImpZSigN2.resize(numFiles);
        hsimjetSignImpZSigN3.resize(numFiles);
        hsimjetNormalizedSignImpZSigN1.resize(numFiles);
        hsimjetNormalizedSignImpZSigN2.resize(numFiles);
        hsimjetNormalizedSignImpZSigN3.resize(numFiles);
      }
      if (fillIPxyz) {
        h3simjetPtSignImpXYZSigN1Flavour.resize(numFiles);
        h3simjetPtSignImpXYZSigN2Flavour.resize(numFiles);
        h3simjetPtSignImpXYZSigN3Flavour.resize(numFiles);
        hsimjetSignImpXYZSigN1.resize(numFiles);
        hsimjetSignImpXYZSigN2.resize(numFiles);
        hsimjetSignImpXYZSigN3.resize(numFiles);
        hsimjetNormalizedSignImpXYZSigN1.resize(numFiles);
        hsimjetNormalizedSignImpXYZSigN2.resize(numFiles);
        hsimjetNormalizedSignImpXYZSigN3.resize(numFiles);
      }
    }
    if (fillJP) {
      h3simjetPtNegLogJPFlavour.resize(numFiles);
      h3simjetPtNegLogJPN1Flavour.resize(numFiles);
      h3simjetPtNegLogJPN2Flavour.resize(numFiles);
      h3simjetPtNegLogJPN3Flavour.resize(numFiles);
      hsimjetNegLogJP.resize(numFiles);
      hsimjetNegLogJPN1.resize(numFiles);
      hsimjetNegLogJPN2.resize(numFiles);
      hsimjetNegLogJPN3.resize(numFiles);
      hsimjetNormalizedNegLogJP.resize(numFiles);
      hsimjetNormalizedNegLogJPN1.resize(numFiles);
      hsimjetNormalizedNegLogJPN2.resize(numFiles);
      hsimjetNormalizedNegLogJPN3.resize(numFiles);
    }
    if (fillSV) {
      h3simjetPt3ProngLxyFlavour.resize(numFiles);
      h3simjetPt3ProngLxyzFlavour.resize(numFiles);
      h3simjetPt3ProngSxyFlavour.resize(numFiles);
      h3simjetPt3ProngSxyzFlavour.resize(numFiles);
      h3simjetPt3ProngsigmaLxyFlavour.resize(numFiles);
      h3simjetPt3ProngsigmaLxyzFlavour.resize(numFiles);
      h3simjetPt3ProngSxyN1Flavour.resize(numFiles);
      h3simjetPt3ProngSxyzN1Flavour.resize(numFiles);
      h3simjetPt3ProngMassN1Flavour.resize(numFiles);
      h3simtaggedjetPt3ProngSxyN1Flavour.resize(numFiles);
      h3simtaggedjetPt3ProngSxyzN1Flavour.resize(numFiles);
      h3simtaggedjetPt3ProngMassN1Flavour.resize(numFiles);
      hsimjet3ProngLxy.resize(numFiles);
      hsimjet3ProngLxyz.resize(numFiles);
      hsimjet3ProngSxy.resize(numFiles);
      hsimjet3ProngSxyz.resize(numFiles);
      hsimjet3ProngsigmaLxy.resize(numFiles);
      hsimjet3ProngsigmaLxyz.resize(numFiles);
      hsimjet3ProngSxyN1.resize(numFiles);
      hsimjet3ProngSxyzN1.resize(numFiles);
      hsimjet3ProngMassN1.resize(numFiles);
      hsimtaggedjet3ProngSxyN1.resize(numFiles);
      hsimtaggedjet3ProngSxyzN1.resize(numFiles);
      hsimtaggedjet3ProngMassN1.resize(numFiles);
      hsimjetNormalized3ProngLxy.resize(numFiles);
      hsimjetNormalized3ProngLxyz.resize(numFiles);
      hsimjetNormalized3ProngSxy.resize(numFiles);
      hsimjetNormalized3ProngSxyz.resize(numFiles);
      hsimjetNormalized3ProngsigmaLxy.resize(numFiles);
      hsimjetNormalized3ProngsigmaLxyz.resize(numFiles);
      hsimjetNormalized3ProngSxyN1.resize(numFiles);
      hsimjetNormalized3ProngSxyzN1.resize(numFiles);
      hsimjetNormalized3ProngMassN1.resize(numFiles);
      hsimtaggedjetNormalized3ProngSxyN1.resize(numFiles);
      hsimtaggedjetNormalized3ProngSxyzN1.resize(numFiles);
      hsimtaggedjetNormalized3ProngMassN1.resize(numFiles);
    }
  }
  return 1;
}

int HfJetTaggingSysAnalysis::loadData(const std::vector<std::pair<TString, TString>> &rootFiles) {
  const TString &taskTagQa = "jet-taggerhf-qa-charged";
  int numFile = 0;
  for (const auto& rootFile : rootFiles) {
    const TString fileName = rootFile.first;
    const TString fileDesc = rootFile.second;
    if (gSystem->AccessPathName(fileName)) {
      std::cout << "Input file (Data) not found!" << std::endl;
      std::cout << Form("%s ", fileName.Data()) << std::endl;
      return 0;
    }
    files.push_back(std::make_pair(fileName, fileDesc));
    TFile* fin;
    fin = TFile::Open(fileName, "READ");
    if (fillData) {
      hdatajetPt[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_pt", taskTagQa.Data())));
      hdatajetEta[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_eta", taskTagQa.Data())));
      hdatajetPhi[numFile] = reinterpret_cast<TH1F*>(fin->Get(Form("%s/h_jet_phi", taskTagQa.Data())));
      if (fillIPxy) {
        h2datajetPtImpXY[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy", taskTagQa.Data())));
        h2datajetPtImpXYSig[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_impact_parameter_xy_significance", taskTagQa.Data())));
        h2datajetPtSignImpXY[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xy", taskTagQa.Data())));
        h2datajetPtSignImpXYSig[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_sign_impact_parameter_xy_significance", taskTagQa.Data())));
      }
      if (fillTC) {
        if (fillIPxy) {
          h2datajetPtSignImpXYSigN1[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_N1", taskTagQa.Data())));
          h2datajetPtSignImpXYSigN2[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_N2", taskTagQa.Data())));
          h2datajetPtSignImpXYSigN3[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_N3", taskTagQa.Data())));
        }
      }
    }
    numFile++;
  }
  return 1;
}

int HfJetTaggingSysAnalysis::loadSim(const std::vector<std::pair<TString, TString>> &rootFiles) {
  const TString &taskTagQa = "jet-taggerhf-qa-charged";
  int numFile = 0;
  for (const auto& rootFile : rootFiles) {
    const TString fileName = rootFile.first;
    const TString fileDesc = rootFile.second;
    if (gSystem->AccessPathName(fileName)) {
      std::cout << "Input file (MC) not found!" << std::endl;
      std::cout << Form("%s ", fileName.Data()) << std::endl;
      return 0;
    }
    files.push_back(std::make_pair(fileName, fileDesc));
    TFile* fin;
    fin = TFile::Open(fileName, "READ");
    if (fillMCD) {
      //hsimEventSel = reinterpret_cast<TH1F*>(fin->Get(Form("%s/hColCounterAcc", taskEventSel.Data())));
      h2simjetPtFlavour[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_pt_flavour", taskTagQa.Data())));
      h2simjetEtaFlavour[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_eta_flavour", taskTagQa.Data())));
      h2simjetPhiFlavour[numFile] = reinterpret_cast<TH2F*>(fin->Get(Form("%s/h2_jet_phi_flavour", taskTagQa.Data())));
      if (fillIPxy) {
        h3simjetPtImpXYFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_flavour", taskTagQa.Data())));
        h3simjetPtImpXYSigFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
        h3simjetPtSignImpXYFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_flavour", taskTagQa.Data())));
        h3simjetPtSignImpXYSigFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour", taskTagQa.Data())));
      }
      if (fillIPz) {
        h3simjetPtImpZFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_flavour", taskTagQa.Data())));
        h3simjetPtImpZSigFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_z_significance_flavour", taskTagQa.Data())));
        h3simjetPtSignImpZFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_flavour", taskTagQa.Data())));
        h3simjetPtSignImpZSigFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_z_significance_flavour", taskTagQa.Data())));
      }
      if (fillIPxyz) {
        h3simjetPtImpXYZFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_flavour", taskTagQa.Data())));
        h3simjetPtImpXYZSigFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
        h3simjetPtSignImpXYZFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_flavour", taskTagQa.Data())));
        h3simjetPtSignImpXYZSigFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xyz_significance_flavour", taskTagQa.Data())));
      }
      if (fillTC) {
        if (fillIPxy) {
          h3simjetPtSignImpXYSigN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskTagQa.Data())));
          h3simjetPtSignImpXYSigN2Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskTagQa.Data())));
          h3simjetPtSignImpXYSigN3Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskTagQa.Data())));
        }
        if (fillIPz) {
          h3simjetPtSignImpZSigN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskTagQa.Data())));
          h3simjetPtSignImpZSigN2Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskTagQa.Data())));
        }
        if (fillIPxyz) {
          h3simjetPtSignImpXYZSigN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N1", taskTagQa.Data())));
          h3simjetPtSignImpXYZSigN2Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N2", taskTagQa.Data())));
          h3simjetPtSignImpXYZSigN3Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_sign_impact_parameter_xy_significance_flavour_N3", taskTagQa.Data())));
        }
      }
      if (fillJP) {
        h3simjetPtNegLogJPFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskTagQa.Data())));
        h3simjetPtNegLogJPN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_neg_log_JP_N1_flavour", taskTagQa.Data())));
        h3simjetPtNegLogJPN2Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_neg_log_JP_N2_flavour", taskTagQa.Data())));
        h3simjetPtNegLogJPN3Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_neg_log_JP_N3_flavour", taskTagQa.Data())));
      }
      if (fillSV) {
        h3simjetPt3ProngLxyFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Lxy_flavour", taskTagQa.Data())));
        h3simjetPt3ProngLxyzFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Lxyz_flavour", taskTagQa.Data())));
        h3simjetPt3ProngSxyFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_flavour", taskTagQa.Data())));
        h3simjetPt3ProngSxyzFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_flavour", taskTagQa.Data())));
        h3simjetPt3ProngsigmaLxyFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_sigmaLxy_flavour", taskTagQa.Data())));
        h3simjetPt3ProngsigmaLxyzFlavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_sigmaLxyz_flavour", taskTagQa.Data())));
        h3simjetPt3ProngSxyN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxy_N1_flavour", taskTagQa.Data())));
        h3simjetPt3ProngSxyzN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_Sxyz_N1_flavour", taskTagQa.Data())));
        h3simjetPt3ProngMassN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_3prong_mass_N1_flavour", taskTagQa.Data())));
        h3simtaggedjetPt3ProngSxyN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxy_N1_flavour", taskTagQa.Data())));
        h3simtaggedjetPt3ProngSxyzN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_Sxyz_N1_flavour", taskTagQa.Data())));
        h3simtaggedjetPt3ProngMassN1Flavour[numFile] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_taggedjet_pt_3prong_mass_N1_flavour", taskTagQa.Data())));
      }
    }
    if (fillMCP) { // TODO

    }
    numFile++;
  }
  std::cout<<"MC loaded files: "<< numFile <<std::endl;
  return 1;
}


void HfJetTaggingSysAnalysis::initHist() {
  for (int numFile =0; numFile < numFiles; numFile++) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimjetPt[numFile][flavour] = new TH1F(Form("hsimjetPt_%d_%d", numFile, flavour), "", h2simjetPtFlavour[numFile]->GetNbinsX(), h2simjetPtFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h2simjetPtFlavour[numFile]->GetXaxis()->GetBinUpEdge(h2simjetPtFlavour[numFile]->GetNbinsX()));
      hsimjetEta[numFile][flavour] = new TH1F(Form("hsimjetEta_%d_%d", numFile, flavour), "", h2simjetEtaFlavour[numFile]->GetNbinsX(), h2simjetEtaFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h2simjetEtaFlavour[numFile]->GetXaxis()->GetBinUpEdge(h2simjetEtaFlavour[numFile]->GetNbinsX()));
      hsimjetPhi[numFile][flavour] = new TH1F(Form("hsimjetPhi_%d_%d", numFile, flavour), "", h2simjetPhiFlavour[numFile]->GetNbinsX(), h2simjetPhiFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h2simjetPhiFlavour[numFile]->GetXaxis()->GetBinUpEdge(h2simjetPhiFlavour[numFile]->GetNbinsX()));
      for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        if (fillIPxy) {
          hsimjetImpXY[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetImpXY_%d_%d", flavour, binJetPt), "", h3simjetPtImpXYFlavour[numFile]->GetNbinsY(), h3simjetPtImpXYFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYFlavour[numFile]->GetNbinsY()));
          hsimjetSignImpXY[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXY_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYFlavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYFlavour[numFile]->GetNbinsY()));
          hsimjetImpXYSig[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetImpXYSig_%d_%d", flavour, binJetPt), "", h3simjetPtImpXYSigFlavour[numFile]->GetNbinsY(), h3simjetPtImpXYSigFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYSigFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYSigFlavour[numFile]->GetNbinsY()));
          hsimjetSignImpXYSig[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYSig_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYSigFlavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYSigFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigFlavour[numFile]->GetNbinsY()));
        }
        if (fillIPz) {
          hsimjetImpZ[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetImpZ_%d_%d", flavour, binJetPt), "", h3simjetPtImpZFlavour[numFile]->GetNbinsY(), h3simjetPtImpZFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpZFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtImpZFlavour[numFile]->GetNbinsY()));
          hsimjetSignImpZ[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpZ_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpZFlavour[numFile]->GetNbinsY(), h3simjetPtSignImpZFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZFlavour[numFile]->GetNbinsY()));
          hsimjetImpZSig[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetImpZSig_%d_%d", flavour, binJetPt), "", h3simjetPtImpZSigFlavour[numFile]->GetNbinsY(), h3simjetPtImpZSigFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpZSigFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtImpZSigFlavour[numFile]->GetNbinsY()));
          hsimjetSignImpZSig[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpZSig_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpZSigFlavour[numFile]->GetNbinsY(), h3simjetPtSignImpZSigFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigFlavour[numFile]->GetNbinsY()));
        }
        if (fillIPxyz) {
          hsimjetImpXYZ[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetImpXYZ_%d_%d", flavour, binJetPt), "", h3simjetPtImpXYZFlavour[numFile]->GetNbinsY(), h3simjetPtImpXYZFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYZFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYZFlavour[numFile]->GetNbinsY()));
          hsimjetSignImpXYZ[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYZ_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYZFlavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYZFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZFlavour[numFile]->GetNbinsY()));
          hsimjetImpXYZSig[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetImpXYZSig_%d_%d", flavour, binJetPt), "", h3simjetPtImpXYZSigFlavour[numFile]->GetNbinsY(), h3simjetPtImpXYZSigFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtImpXYZSigFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtImpXYZSigFlavour[numFile]->GetNbinsY()));
          hsimjetSignImpXYZSig[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYZSig_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYZSigFlavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYZSigFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigFlavour[numFile]->GetNbinsY()));
        }
        if (fillTC) {
          if (fillIPxy) {
            hsimjetSignImpXYSigN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYSigN1_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYSigN1Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYSigN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigN1Flavour[numFile]->GetNbinsY()));
            hsimjetSignImpXYSigN2[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYSigN2_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYSigN2Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYSigN2Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigN2Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigN2Flavour[numFile]->GetNbinsY()));
            hsimjetSignImpXYSigN3[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYSigN3_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYSigN3Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYSigN3Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYSigN3Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYSigN3Flavour[numFile]->GetNbinsY()));
          }
          if (fillIPz) {
            hsimjetSignImpZSigN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpZSigN1_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpZSigN1Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpZSigN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigN1Flavour[numFile]->GetNbinsY()));
            hsimjetSignImpZSigN2[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpZSigN2_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpZSigN2Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpZSigN2Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigN2Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigN2Flavour[numFile]->GetNbinsY()));
            hsimjetSignImpZSigN3[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpZSigN3_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpZSigN3Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpZSigN3Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpZSigN3Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpZSigN3Flavour[numFile]->GetNbinsY()));
          }
          if (fillIPxyz) {
            hsimjetSignImpXYZSigN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYZSigN1_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetNbinsY()));
            hsimjetSignImpXYZSigN2[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYZSigN2_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetNbinsY()));
            hsimjetSignImpXYZSigN3[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetSignImpXYZSigN3_%d_%d", flavour, binJetPt), "", h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetNbinsY(), h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetNbinsY()));
          }
        }
        if (fillJP) {
          hsimjetNegLogJP[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJP_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPtNegLogJPFlavour[numFile]->GetNbinsY(), h3simjetPtNegLogJPFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPFlavour[numFile]->GetNbinsY()));
          hsimjetNegLogJPN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJPN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPtNegLogJPN1Flavour[numFile]->GetNbinsY(), h3simjetPtNegLogJPN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPN1Flavour[numFile]->GetNbinsY()));
          hsimjetNegLogJPN2[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJPN2_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPtNegLogJPN2Flavour[numFile]->GetNbinsY(), h3simjetPtNegLogJPN2Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPN2Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPN2Flavour[numFile]->GetNbinsY()));
          hsimjetNegLogJPN3[numFile][flavour][binJetPt] = new TH1F(Form("hsimjetNegLogJPN3_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPtNegLogJPN3Flavour[numFile]->GetNbinsY(), h3simjetPtNegLogJPN3Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPtNegLogJPN3Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPtNegLogJPN3Flavour[numFile]->GetNbinsY()));
        }
        if (fillSV) {
          hsimjet3ProngLxy[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngLxy_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngLxyFlavour[numFile]->GetNbinsY(), h3simjetPt3ProngLxyFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngLxyFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngLxyFlavour[numFile]->GetNbinsY()));
          hsimjet3ProngLxyz[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngLxyz_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngLxyzFlavour[numFile]->GetNbinsY(), h3simjetPt3ProngLxyzFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngLxyzFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngLxyzFlavour[numFile]->GetNbinsY()));
          hsimjet3ProngsigmaLxy[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngsigmaLxy_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetNbinsY(), h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetNbinsY()));
          hsimjet3ProngsigmaLxyz[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngsigmaLxyz_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetNbinsY(), h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetNbinsY()));
          hsimjet3ProngSxy[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngSxy_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngSxyFlavour[numFile]->GetNbinsY(), h3simjetPt3ProngSxyFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyFlavour[numFile]->GetNbinsY()));
          hsimjet3ProngSxyz[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngSxyz_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngSxyzFlavour[numFile]->GetNbinsY(), h3simjetPt3ProngSxyzFlavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyzFlavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyzFlavour[numFile]->GetNbinsY()));
          hsimjet3ProngSxyN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngSxyN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngSxyN1Flavour[numFile]->GetNbinsY(), h3simjetPt3ProngSxyN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyN1Flavour[numFile]->GetNbinsY()));
          hsimjet3ProngSxyzN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngSxyzN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngSxyzN1Flavour[numFile]->GetNbinsY(), h3simjetPt3ProngSxyzN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngSxyzN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngSxyzN1Flavour[numFile]->GetNbinsY()));
          hsimjet3ProngMassN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimjet3ProngMassN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simjetPt3ProngMassN1Flavour[numFile]->GetNbinsY(), h3simjetPt3ProngMassN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simjetPt3ProngMassN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simjetPt3ProngMassN1Flavour[numFile]->GetNbinsY()));
          hsimtaggedjet3ProngSxyN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimtaggedjet3ProngSxyN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetNbinsY(), h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetNbinsY()));
          hsimtaggedjet3ProngSxyzN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimtaggedjet3ProngSxyzN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetNbinsY(), h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetNbinsY()));
          hsimtaggedjet3ProngMassN1[numFile][flavour][binJetPt] = new TH1F(Form("hsimtaggedjet3ProngMassN1_%d_%d_%d", numFile, flavour, binJetPt), "", h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetNbinsY(), h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetYaxis()->GetBinLowEdge(1), h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetYaxis()->GetBinUpEdge(h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetNbinsY()));
        }
      }
    }
  }
}

void HfJetTaggingSysAnalysis::projHist() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  if (fillMCD) {
    for (int numFile =0; numFile < numFiles; numFile++) {
      for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
        HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
        TH1F* projJetPt = reinterpret_cast<TH1F*> (h2simjetPtFlavour[numFile]->ProjectionX(Form("projJetPt_%d_%d", numFile, binFlavour), binFlavour, binFlavour));
        TH1F* projJetEta = reinterpret_cast<TH1F*> (h2simjetEtaFlavour[numFile]->ProjectionX(Form("projJetEta_%d_%d", numFile, binFlavour), binFlavour, binFlavour));
        TH1F* projJetPhi = reinterpret_cast<TH1F*> (h2simjetPhiFlavour[numFile]->ProjectionX(Form("projJetPhi_%d_%d", numFile, binFlavour), binFlavour, binFlavour));
        //hsimjetPt[numFile][0]->Add(projJetPt);
        //hsimjetEta[numFile][0]->Add(projJetEta);
        //hsimjetPhi[numFile][0]->Add(projJetPhi);
        hsimjetPt[numFile][flavour] = reinterpret_cast<TH1F*> (projJetPt->Clone(Form("hsimjetPt_%d_%d", numFile, flavour)));
        hsimjetEta[numFile][flavour] = reinterpret_cast<TH1F*> (projJetEta->Clone(Form("hsimjetEta_%d_%d", numFile, flavour)));
        hsimjetPhi[numFile][flavour] = reinterpret_cast<TH1F*> (projJetPhi->Clone(Form("hsimjetPhi_%d_%d", numFile, flavour)));
        if (fillIPxy) {
          TH1F* projImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavour[numFile]->ProjectionY(Form("projImpXY_%d_%d", numFile, binFlavour), 1, h3simjetPtImpXYFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projSignImpXY = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYFlavour[numFile]->ProjectionY(Form("projSignImpXY_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYSigFlavour[numFile]->ProjectionY(Form("projImpXYSig_%d_%d", numFile, binFlavour), 1, h3simjetPtImpXYSigFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projSignImpXYSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigFlavour[numFile]->ProjectionY(Form("projSignImpXYSig_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYSigFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          hsimjetImpXY[numFile][0][0]->Add(projImpXY);
          hsimjetSignImpXY[numFile][0][0]->Add(projSignImpXY);
          hsimjetImpXYSig[numFile][0][0]->Add(projImpXYSig);
          hsimjetSignImpXYSig[numFile][0][0]->Add(projSignImpXYSig);
          hsimjetImpXY[numFile][flavour][0] = reinterpret_cast<TH1F*>(projImpXY->Clone(Form("hsimjetImpXY_%d_%d_0", numFile, flavour)));
          hsimjetSignImpXY[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXY->Clone(Form("hsimjetSignImpXY_%d_%d_0", numFile, flavour)));
          hsimjetImpXYSig[numFile][flavour][0] = reinterpret_cast<TH1F*>(projImpXYSig->Clone(Form("hsimjetImpXYSig_%d_%d_0", numFile, flavour)));
          hsimjetSignImpXYSig[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSig->Clone(Form("hsimjetSignImpXYSig_%d_%d_0", numFile, flavour)));
        }
        if (fillIPz) {
          TH1F* projImpZ = reinterpret_cast<TH1F*> (h3simjetPtImpZFlavour[numFile]->ProjectionY(Form("projImpZ_%d_%d", numFile, binFlavour), 1, h3simjetPtImpZFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projSignImpZ = reinterpret_cast<TH1F*> (h3simjetPtSignImpZFlavour[numFile]->ProjectionY(Form("projSignImpZ_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpZFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projImpZSig = reinterpret_cast<TH1F*> (h3simjetPtImpZSigFlavour[numFile]->ProjectionY(Form("projImpZSig_%d_%d", numFile, binFlavour), 1, h3simjetPtImpZSigFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projSignImpZSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigFlavour[numFile]->ProjectionY(Form("projSignImpZSig_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpZSigFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          hsimjetImpZ[numFile][0][0]->Add(projImpZ);
          hsimjetSignImpZ[numFile][0][0]->Add(projSignImpZ);
          hsimjetImpZSig[numFile][0][0]->Add(projImpZSig);
          hsimjetSignImpZSig[numFile][0][0]->Add(projSignImpZSig);
          hsimjetImpZ[numFile][flavour][0] = reinterpret_cast<TH1F*>(projImpZ->Clone(Form("hsimjetImpZ_%d_%d_0", numFile, flavour)));
          hsimjetSignImpZ[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpZ->Clone(Form("hsimjetSignImpZ_%d_%d_0", numFile, flavour)));
          hsimjetImpZSig[numFile][flavour][0] = reinterpret_cast<TH1F*>(projImpZSig->Clone(Form("hsimjetImpZSig_%d_%d_0", numFile, flavour)));
          hsimjetSignImpZSig[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSig->Clone(Form("hsimjetSignImpZSig_%d_%d_0", numFile, flavour)));
        }
        if (fillIPxyz) {
          TH1F* projImpXYZ = reinterpret_cast<TH1F*> (h3simjetPtImpXYZFlavour[numFile]->ProjectionY(Form("projImpXYZ_%d_%d", numFile, binFlavour), 1, h3simjetPtImpXYZFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projSignImpXYZ = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZFlavour[numFile]->ProjectionY(Form("projSignImpXYZ_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYZFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projImpXYZSig = reinterpret_cast<TH1F*> (h3simjetPtImpXYZSigFlavour[numFile]->ProjectionY(Form("projImpXYZSig_%d_%d", numFile, binFlavour), 1, h3simjetPtImpXYZSigFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projSignImpXYZSig = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigFlavour[numFile]->ProjectionY(Form("projSignImpXYZSig_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYZSigFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          hsimjetImpXYZ[numFile][0][0]->Add(projImpXYZ);
          hsimjetSignImpXYZ[numFile][0][0]->Add(projSignImpXYZ);
          hsimjetImpXYZSig[numFile][0][0]->Add(projImpXYZSig);
          hsimjetSignImpXYZSig[numFile][0][0]->Add(projSignImpXYZSig);
          hsimjetImpXYZ[numFile][flavour][0] = reinterpret_cast<TH1F*>(projImpXYZ->Clone(Form("hsimjetImpXYZ_%d_%d_0", numFile, flavour)));
          hsimjetSignImpXYZ[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZ->Clone(Form("hsimjetSignImpXYZ_%d_%d_0", numFile, flavour)));
          hsimjetImpXYZSig[numFile][flavour][0] = reinterpret_cast<TH1F*>(projImpXYZSig->Clone(Form("hsimjetImpXYZSig_%d_%d_0", numFile, flavour)));
          hsimjetSignImpXYZSig[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSig->Clone(Form("hsimjetSignImpXYZSig_%d_%d_0", numFile, flavour)));
        }
        if (fillTC) {
          if (fillIPxy) {
            TH1F* projSignImpXYSigN1 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigN1Flavour[numFile]->ProjectionY(Form("projSignImpXYSigN1_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYSigN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            TH1F* projSignImpXYSigN2 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigN2Flavour[numFile]->ProjectionY(Form("projSignImpXYSigN2_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYSigN2Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            TH1F* projSignImpXYSigN3 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYSigN3Flavour[numFile]->ProjectionY(Form("projSignImpXYSigN3_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYSigN3Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            hsimjetSignImpXYSigN1[numFile][0][0]->Add(projSignImpXYSigN1);
            hsimjetSignImpXYSigN2[numFile][0][0]->Add(projSignImpXYSigN2);
            hsimjetSignImpXYSigN3[numFile][0][0]->Add(projSignImpXYSigN3);
            hsimjetSignImpXYSigN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN1->Clone(Form("hsimjetSignImpXYSigN1_%d_%d_0", numFile, flavour)));
            hsimjetSignImpXYSigN2[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN2->Clone(Form("hsimjetSignImpXYSigN2_%d_%d_0", numFile, flavour)));
            hsimjetSignImpXYSigN3[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYSigN3->Clone(Form("hsimjetSignImpXYSigN3_%d_%d_0", numFile, flavour)));
          }
          if (fillIPz) {
            TH1F* projSignImpZSigN1 = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigN1Flavour[numFile]->ProjectionY(Form("projSignImpZSigN1_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpZSigN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            TH1F* projSignImpZSigN2 = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigN2Flavour[numFile]->ProjectionY(Form("projSignImpZSigN2_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpZSigN2Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            TH1F* projSignImpZSigN3 = reinterpret_cast<TH1F*> (h3simjetPtSignImpZSigN3Flavour[numFile]->ProjectionY(Form("projSignImpZSigN3_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpZSigN3Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            hsimjetSignImpZSigN1[numFile][0][0]->Add(projSignImpZSigN1);
            hsimjetSignImpZSigN2[numFile][0][0]->Add(projSignImpZSigN2);
            hsimjetSignImpZSigN3[numFile][0][0]->Add(projSignImpZSigN3);
            hsimjetSignImpZSigN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN1->Clone(Form("hsimjetSignImpZSigN1_%d_%d_0", numFile, flavour)));
            hsimjetSignImpZSigN2[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN2->Clone(Form("hsimjetSignImpZSigN2_%d_%d_0", numFile, flavour)));
            hsimjetSignImpZSigN3[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpZSigN3->Clone(Form("hsimjetSignImpZSigN3_%d_%d_0", numFile, flavour)));
          }
          if (fillIPxyz) {
            TH1F* projSignImpXYZSigN1 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigN1Flavour[numFile]->ProjectionY(Form("projSignImpXYZSigN1_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            TH1F* projSignImpXYZSigN2 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigN2Flavour[numFile]->ProjectionY(Form("projSignImpXYZSigN2_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            TH1F* projSignImpXYZSigN3 = reinterpret_cast<TH1F*> (h3simjetPtSignImpXYZSigN3Flavour[numFile]->ProjectionY(Form("projSignImpXYZSigN3_%d_%d", numFile, binFlavour), 1, h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
            hsimjetSignImpXYZSigN1[numFile][0][0]->Add(projSignImpXYZSigN1);
            hsimjetSignImpXYZSigN2[numFile][0][0]->Add(projSignImpXYZSigN2);
            hsimjetSignImpXYZSigN3[numFile][0][0]->Add(projSignImpXYZSigN3);
            hsimjetSignImpXYZSigN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN1->Clone(Form("hsimjetSignImpXYZSigN1_%d_%d_0", numFile, flavour)));
            hsimjetSignImpXYZSigN2[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN2->Clone(Form("hsimjetSignImpXYZSigN2_%d_%d_0", numFile, flavour)));
            hsimjetSignImpXYZSigN3[numFile][flavour][0] = reinterpret_cast<TH1F*>(projSignImpXYZSigN3->Clone(Form("hsimjetSignImpXYZSigN3_%d_%d_0", numFile, flavour)));
          }
        }
        if (fillJP) {
		      TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPFlavour[numFile]->ProjectionY(Form("projNegLogJP_%d_%d", numFile, flavour), 1, h3simjetPtNegLogJPFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
		      TH1F* projNegLogJPN1 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN1Flavour[numFile]->ProjectionY(Form("projNegLogJPN1_%d_%d", numFile, flavour), 1, h3simjetPtNegLogJPN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
		      TH1F* projNegLogJPN2 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN2Flavour[numFile]->ProjectionY(Form("projNegLogJPN2_%d_%d", numFile, flavour), 1, h3simjetPtNegLogJPN2Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
		      TH1F* projNegLogJPN3 = reinterpret_cast<TH1F*> (h3simjetPtNegLogJPN3Flavour[numFile]->ProjectionY(Form("projNegLogJPN3_%d_%d", numFile, flavour), 1, h3simjetPtNegLogJPN3Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          hsimjetNegLogJP[numFile][0][0]->Add(projNegLogJP);
          hsimjetNegLogJPN1[numFile][0][0]->Add(projNegLogJPN1);
          hsimjetNegLogJPN2[numFile][0][0]->Add(projNegLogJPN2);
          hsimjetNegLogJPN3[numFile][0][0]->Add(projNegLogJPN3);
          hsimjetNegLogJP[numFile][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimjetNegLogJP_%d_%d_0", numFile, flavour)));
          hsimjetNegLogJPN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone(Form("hsimjetNegLogJPN1_%d_%d_0", numFile, flavour)));
          hsimjetNegLogJPN2[numFile][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone(Form("hsimjetNegLogJPN2_%d_%d_0", numFile, flavour)));
          hsimjetNegLogJPN3[numFile][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone(Form("hsimjetNegLogJPN3_%d_%d_0", numFile, flavour)));
        }
        if (fillSV) {
          TH1F* proj3ProngLxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngLxyFlavour[numFile]->ProjectionY(Form("proj3ProngLxy_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngLxyFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngLxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngLxyzFlavour[numFile]->ProjectionY(Form("proj3ProngLxyz_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngLxyzFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngSxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyFlavour[numFile]->ProjectionY(Form("proj3ProngSxy_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngSxyFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngSxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzFlavour[numFile]->ProjectionY(Form("proj3ProngSxyz_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngSxyzFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngsigmaLxy = reinterpret_cast<TH1F*> (h3simjetPt3ProngsigmaLxyFlavour[numFile]->ProjectionY(Form("proj3ProngsigmaLxy_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngsigmaLxyz = reinterpret_cast<TH1F*> (h3simjetPt3ProngsigmaLxyzFlavour[numFile]->ProjectionY(Form("proj3ProngsigmaLxyz_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyN1Flavour[numFile]->ProjectionY(Form("proj3ProngSxyN1_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngSxyN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngSxyzN1Flavour[numFile]->ProjectionY(Form("proj3ProngSxyzN1_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngSxyzN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* proj3ProngMassN1 = reinterpret_cast<TH1F*> (h3simjetPt3ProngMassN1Flavour[numFile]->ProjectionY(Form("proj3ProngMassN1_%d_%d", numFile, binFlavour), 1, h3simjetPt3ProngMassN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projTagged3ProngSxyN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->ProjectionY(Form("projTagged3ProngSxyN1_%d_%d", numFile, binFlavour), 1, h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projTagged3ProngSxyzN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->ProjectionY(Form("projTagged3ProngSxyzN1_%d_%d", numFile, binFlavour), 1, h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          TH1F* projTagged3ProngMassN1 = reinterpret_cast<TH1F*> (h3simtaggedjetPt3ProngMassN1Flavour[numFile]->ProjectionY(Form("projTagged3ProngMassN1_%d_%d", numFile, binFlavour), 1, h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetNbinsX(), binFlavour, binFlavour));
          hsimjet3ProngLxy[numFile][0][0]->Add(proj3ProngLxy);
          hsimjet3ProngLxyz[numFile][0][0]->Add(proj3ProngLxyz);
          hsimjet3ProngSxy[numFile][0][0]->Add(proj3ProngSxy);
          hsimjet3ProngSxyz[numFile][0][0]->Add(proj3ProngSxyz);
          hsimjet3ProngsigmaLxy[numFile][0][0]->Add(proj3ProngsigmaLxy);
          hsimjet3ProngsigmaLxyz[numFile][0][0]->Add(proj3ProngsigmaLxyz);
          hsimjet3ProngSxyN1[numFile][0][0]->Add(proj3ProngSxyN1);
          hsimjet3ProngSxyzN1[numFile][0][0]->Add(proj3ProngSxyzN1);
          hsimjet3ProngMassN1[numFile][0][0]->Add(proj3ProngMassN1);
          hsimjet3ProngLxy[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngLxy->Clone(Form("hsimjet3ProngLxy_%d_%d_0", numFile, flavour)));
          hsimjet3ProngLxyz[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngLxyz->Clone(Form("hsimjet3ProngLxyz_%d_%d_0", numFile, flavour)));
          hsimjet3ProngSxy[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxy->Clone(Form("hsimjet3ProngSxy_%d_%d_0", numFile, flavour)));
          hsimjet3ProngSxyz[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyz->Clone(Form("hsimjet3ProngSxyz_%d_%d_0", numFile, flavour)));
          hsimjet3ProngsigmaLxy[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxy->Clone(Form("hsimjet3ProngsigmaLxy_%d_%d_0", numFile, flavour)));
          hsimjet3ProngsigmaLxyz[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngsigmaLxyz->Clone(Form("hsimjet3ProngsigmaLxyz_%d_%d_0", numFile, flavour)));
          hsimjet3ProngSxyN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyN1->Clone(Form("hsimjet3ProngSxyN1_%d_%d_0", numFile, flavour)));
          hsimjet3ProngSxyzN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngSxyzN1->Clone(Form("hsimjet3ProngSxyzN1_%d_%d_0", numFile, flavour)));
          hsimjet3ProngMassN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(proj3ProngMassN1->Clone(Form("hsimjet3ProngMassN1_%d_%d_0", numFile, flavour)));
          hsimtaggedjet3ProngSxyN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projTagged3ProngSxyN1->Clone(Form("hsimtaggedjet3ProngSxyN1_%d_%d_0", numFile, flavour)));
          hsimtaggedjet3ProngSxyzN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projTagged3ProngSxyzN1->Clone(Form("hsimtaggedjet3ProngSxyzN1_%d_%d_0", numFile, flavour)));
          hsimtaggedjet3ProngMassN1[numFile][flavour][0] = reinterpret_cast<TH1F*>(projTagged3ProngMassN1->Clone(Form("hsimtaggedjet3ProngMassN1_%d_%d_0", numFile, flavour)));
        }
        for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
          if (fillIPxy) {
            int leftbinJetPtImpXY = h3simjetPtImpXYFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtImpXY = h3simjetPtImpXYFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeImpXY = reinterpret_cast<TH1F*> (h3simjetPtImpXYFlavour[numFile]->ProjectionY(Form("projJetPtRagneImpXY_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtImpXY, rightbinJetPtImpXY, binFlavour, binFlavour));
            hsimjetImpXY[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXY->Clone());
            hsimjetImpXY[numFile][0][binJetPt]->Add(projJetPtRangeImpXY);

            int leftbinJetPtSignImpXY = h3simjetPtSignImpXYFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtSignImpXY = h3simjetPtSignImpXYFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeSignImpXY = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYFlavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXY_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXY, rightbinJetPtSignImpXY, binFlavour, binFlavour));
            hsimjetSignImpXY[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXY->Clone());
            hsimjetSignImpXY[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXY);

            int leftbinJetPtImpXYSig = h3simjetPtImpXYSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtImpXYSig = h3simjetPtImpXYSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeImpXYSig = reinterpret_cast<TH1F*>(h3simjetPtImpXYSigFlavour[numFile]->ProjectionY(Form("projJetPtRagneImpXYSig_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtImpXYSig, rightbinJetPtImpXYSig, binFlavour, binFlavour));
            hsimjetImpXYSig[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYSig->Clone());
            hsimjetImpXYSig[numFile][0][binJetPt]->Add(projJetPtRangeImpXYSig);

            int leftbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtSignImpXYSig = h3simjetPtSignImpXYSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeSignImpXYSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigFlavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYSig_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYSig, rightbinJetPtSignImpXYSig, binFlavour, binFlavour));
            hsimjetSignImpXYSig[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSig->Clone());
            hsimjetSignImpXYSig[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYSig);
          }
          if (fillIPz) {
            int leftbinJetPtImpZ = h3simjetPtImpZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtImpZ = h3simjetPtImpZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeImpZ = reinterpret_cast<TH1F*> (h3simjetPtImpZFlavour[numFile]->ProjectionY(Form("projJetPtRagneImpZ_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtImpZ, rightbinJetPtImpZ, binFlavour, binFlavour));
            hsimjetImpZ[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZ->Clone());
            hsimjetImpZ[numFile][0][binJetPt]->Add(projJetPtRangeImpZ);

            int leftbinJetPtSignImpZ = h3simjetPtSignImpZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtSignImpZ = h3simjetPtSignImpZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeSignImpZ = reinterpret_cast<TH1F*>(h3simjetPtSignImpZFlavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpZ_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpZ, rightbinJetPtSignImpZ, binFlavour, binFlavour));
            hsimjetSignImpZ[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZ->Clone());
            hsimjetSignImpZ[numFile][0][binJetPt]->Add(projJetPtRangeSignImpZ);

            int leftbinJetPtImpZSig = h3simjetPtImpZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtImpZSig = h3simjetPtImpZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeImpZSig = reinterpret_cast<TH1F*>(h3simjetPtImpZSigFlavour[numFile]->ProjectionY(Form("projJetPtRagneImpZSig_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtImpZSig, rightbinJetPtImpZSig, binFlavour, binFlavour));
            hsimjetImpZSig[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpZSig->Clone());
            hsimjetImpZSig[numFile][0][binJetPt]->Add(projJetPtRangeImpZSig);

            int leftbinJetPtSignImpZSig = h3simjetPtSignImpZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtSignImpZSig = h3simjetPtSignImpZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeSignImpZSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigFlavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpZSig_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpZSig, rightbinJetPtSignImpZSig, binFlavour, binFlavour));
            hsimjetSignImpZSig[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSig->Clone());
            hsimjetSignImpZSig[numFile][0][binJetPt]->Add(projJetPtRangeSignImpZSig);
          }
          if (fillIPxyz) {
            int leftbinJetPtImpXYZ = h3simjetPtImpXYZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtImpXYZ = h3simjetPtImpXYZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeImpXYZ = reinterpret_cast<TH1F*> (h3simjetPtImpXYZFlavour[numFile]->ProjectionY(Form("projJetPtRagneImpXYZ_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtImpXYZ, rightbinJetPtImpXYZ, binFlavour, binFlavour));
            hsimjetImpXYZ[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZ->Clone());
            hsimjetImpXYZ[numFile][0][binJetPt]->Add(projJetPtRangeImpXYZ);

            int leftbinJetPtSignImpXYZ = h3simjetPtSignImpXYZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtSignImpXYZ = h3simjetPtSignImpXYZFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeSignImpXYZ = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZFlavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYZ_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYZ, rightbinJetPtSignImpXYZ, binFlavour, binFlavour));
            hsimjetSignImpXYZ[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZ->Clone());
            hsimjetSignImpXYZ[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYZ);

            int leftbinJetPtImpXYZSig = h3simjetPtImpXYZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtImpXYZSig = h3simjetPtImpXYZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeImpXYZSig = reinterpret_cast<TH1F*>(h3simjetPtImpXYZSigFlavour[numFile]->ProjectionY(Form("projJetPtRagneImpXYZSig_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtImpXYZSig, rightbinJetPtImpXYZSig, binFlavour, binFlavour));
            hsimjetImpXYZSig[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeImpXYZSig->Clone());
            hsimjetImpXYZSig[numFile][0][binJetPt]->Add(projJetPtRangeImpXYZSig);

            int leftbinJetPtSignImpXYZSig = h3simjetPtSignImpXYZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtSignImpXYZSig = h3simjetPtSignImpXYZSigFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeSignImpXYZSig = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigFlavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYZSig_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYZSig, rightbinJetPtSignImpXYZSig, binFlavour, binFlavour));
            hsimjetSignImpXYZSig[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSig->Clone());
            hsimjetSignImpXYZSig[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYZSig);
          }
          if (fillTC) {
            if (fillIPxy) {
              int leftbinJetPtSignImpXYSigN1 = h3simjetPtSignImpXYSigN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpXYSigN1 = h3simjetPtSignImpXYSigN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpXYSigN1 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigN1Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYSigN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYSigN1, rightbinJetPtSignImpXYSigN1, binFlavour, binFlavour));
              hsimjetSignImpXYSigN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN1->Clone());
              hsimjetSignImpXYSigN1[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYSigN1);

              int leftbinJetPtSignImpXYSigN2 = h3simjetPtSignImpXYSigN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpXYSigN2 = h3simjetPtSignImpXYSigN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpXYSigN2 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigN2Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYSigN2_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYSigN2, rightbinJetPtSignImpXYSigN2, binFlavour, binFlavour));
              hsimjetSignImpXYSigN2[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN2->Clone());
              hsimjetSignImpXYSigN2[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYSigN2);

              int leftbinJetPtSignImpXYSigN3 = h3simjetPtSignImpXYSigN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpXYSigN3 = h3simjetPtSignImpXYSigN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpXYSigN3 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYSigN3Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYSigN3_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYSigN3, rightbinJetPtSignImpXYSigN3, binFlavour, binFlavour));
              hsimjetSignImpXYSigN3[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYSigN3->Clone());
              hsimjetSignImpXYSigN3[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYSigN3);
            }
            if (fillIPz) {
              int leftbinJetPtSignImpZSigN1 = h3simjetPtSignImpZSigN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpZSigN1 = h3simjetPtSignImpZSigN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpZSigN1 = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigN1Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpZSigN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpZSigN1, rightbinJetPtSignImpZSigN1, binFlavour, binFlavour));
              hsimjetSignImpZSigN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN1->Clone());
              hsimjetSignImpZSigN1[numFile][0][binJetPt]->Add(projJetPtRangeSignImpZSigN1);

              int leftbinJetPtSignImpZSigN2 = h3simjetPtSignImpZSigN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpZSigN2 = h3simjetPtSignImpZSigN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpZSigN2 = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigN2Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpZSigN2_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpZSigN2, rightbinJetPtSignImpZSigN2, binFlavour, binFlavour));
              hsimjetSignImpZSigN2[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN2->Clone());
              hsimjetSignImpZSigN2[numFile][0][binJetPt]->Add(projJetPtRangeSignImpZSigN2);

              int leftbinJetPtSignImpZSigN3 = h3simjetPtSignImpZSigN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpZSigN3 = h3simjetPtSignImpZSigN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpZSigN3 = reinterpret_cast<TH1F*>(h3simjetPtSignImpZSigN3Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpZSigN3_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpZSigN3, rightbinJetPtSignImpZSigN3, binFlavour, binFlavour));
              hsimjetSignImpZSigN3[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpZSigN3->Clone());
              hsimjetSignImpZSigN3[numFile][0][binJetPt]->Add(projJetPtRangeSignImpZSigN3);
            }
            if (fillIPxyz) {
              int leftbinJetPtSignImpXYZSigN1 = h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpXYZSigN1 = h3simjetPtSignImpXYZSigN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpXYZSigN1 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigN1Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYZSigN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYZSigN1, rightbinJetPtSignImpXYZSigN1, binFlavour, binFlavour));
              hsimjetSignImpXYZSigN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN1->Clone());
              hsimjetSignImpXYZSigN1[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN1);

              int leftbinJetPtSignImpXYZSigN2 = h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpXYZSigN2 = h3simjetPtSignImpXYZSigN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpXYZSigN2 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigN2Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYZSigN2_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYZSigN2, rightbinJetPtSignImpXYZSigN2, binFlavour, binFlavour));
              hsimjetSignImpXYZSigN2[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN2->Clone());
              hsimjetSignImpXYZSigN2[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN2);

              int leftbinJetPtSignImpXYZSigN3 = h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
              int rightbinJetPtSignImpXYZSigN3 = h3simjetPtSignImpXYZSigN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
              TH1F* projJetPtRangeSignImpXYZSigN3 = reinterpret_cast<TH1F*>(h3simjetPtSignImpXYZSigN3Flavour[numFile]->ProjectionY(Form("projJetPtRagneSignImpXYZSigN3_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtSignImpXYZSigN3, rightbinJetPtSignImpXYZSigN3, binFlavour, binFlavour));
              hsimjetSignImpXYZSigN3[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeSignImpXYZSigN3->Clone());
              hsimjetSignImpXYZSigN3[numFile][0][binJetPt]->Add(projJetPtRangeSignImpXYZSigN3);
            }
          }
          if (fillJP) {
            int leftbinJetPtNegLogJP = h3simjetPtNegLogJPFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtNegLogJP = h3simjetPtNegLogJPFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*>(h3simjetPtNegLogJPFlavour[numFile]->ProjectionY(Form("projJetPtRagneNegLogJP_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, binFlavour, binFlavour));
            hsimjetNegLogJP[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone());
            hsimjetNegLogJP[numFile][0][binJetPt]->Add(projJetPtRangeNegLogJP);

            int leftbinJetPtNegLogJPN1 = h3simjetPtNegLogJPN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtNegLogJPN1 = h3simjetPtNegLogJPN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*>(h3simjetPtNegLogJPN1Flavour[numFile]->ProjectionY(Form("projJetPtRagneNegLogJPN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1, binFlavour, binFlavour));
            hsimjetNegLogJPN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone());
            hsimjetNegLogJPN1[numFile][0][binJetPt]->Add(projJetPtRangeNegLogJPN1);

            int leftbinJetPtNegLogJPN2 = h3simjetPtNegLogJPN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtNegLogJPN2 = h3simjetPtNegLogJPN2Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*>(h3simjetPtNegLogJPN2Flavour[numFile]->ProjectionY(Form("projJetPtRagneNegLogJPN2_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2, binFlavour, binFlavour));
            hsimjetNegLogJPN2[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone());
            hsimjetNegLogJPN2[numFile][0][binJetPt]->Add(projJetPtRangeNegLogJPN2);

            int leftbinJetPtNegLogJPN3 = h3simjetPtNegLogJPN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPtNegLogJPN3 = h3simjetPtNegLogJPN3Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*>(h3simjetPtNegLogJPN3Flavour[numFile]->ProjectionY(Form("projJetPtRagneNegLogJPN3_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3, binFlavour, binFlavour));
            hsimjetNegLogJPN3[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone());
            hsimjetNegLogJPN3[numFile][0][binJetPt]->Add(projJetPtRangeNegLogJPN3);
          }
          if (fillSV) {
            int leftbinJetPt3ProngLxy = h3simjetPt3ProngLxyFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngLxy = h3simjetPt3ProngLxyFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngLxy = reinterpret_cast<TH1F*>(h3simjetPt3ProngLxyFlavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngLxy_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngLxy, rightbinJetPt3ProngLxy, binFlavour, binFlavour));
            hsimjet3ProngLxy[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxy->Clone());
            hsimjet3ProngLxy[numFile][0][binJetPt]->Add(projJetPtRange3ProngLxy);

            int leftbinJetPt3ProngLxyz = h3simjetPt3ProngLxyzFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngLxyz = h3simjetPt3ProngLxyzFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngLxyz = reinterpret_cast<TH1F*>(h3simjetPt3ProngLxyzFlavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngLxyz_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngLxyz, rightbinJetPt3ProngLxyz, binFlavour, binFlavour));
            hsimjet3ProngLxyz[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngLxyz->Clone());
            hsimjet3ProngLxyz[numFile][0][binJetPt]->Add(projJetPtRange3ProngLxyz);

            int leftbinJetPt3ProngsigmaLxy = h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngsigmaLxy = h3simjetPt3ProngsigmaLxyFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngsigmaLxy = reinterpret_cast<TH1F*>(h3simjetPt3ProngsigmaLxyFlavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngsigmaLxy_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngsigmaLxy, rightbinJetPt3ProngsigmaLxy, binFlavour, binFlavour));
            hsimjet3ProngsigmaLxy[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxy->Clone());
            hsimjet3ProngsigmaLxy[numFile][0][binJetPt]->Add(projJetPtRange3ProngsigmaLxy);

            int leftbinJetPt3ProngsigmaLxyz = h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngsigmaLxyz = h3simjetPt3ProngsigmaLxyzFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngsigmaLxyz = reinterpret_cast<TH1F*>(h3simjetPt3ProngsigmaLxyzFlavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngsigmaLxyz_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngsigmaLxyz, rightbinJetPt3ProngsigmaLxyz, binFlavour, binFlavour));
            hsimjet3ProngsigmaLxyz[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngsigmaLxyz->Clone());
            hsimjet3ProngsigmaLxyz[numFile][0][binJetPt]->Add(projJetPtRange3ProngsigmaLxyz);

            int leftbinJetPt3ProngSxy = h3simjetPt3ProngSxyFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngSxy = h3simjetPt3ProngSxyFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngSxy = reinterpret_cast<TH1F*>(h3simjetPt3ProngSxyFlavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngSxy_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngSxy, rightbinJetPt3ProngSxy, binFlavour, binFlavour));
            hsimjet3ProngSxy[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxy->Clone());
            hsimjet3ProngSxy[numFile][0][binJetPt]->Add(projJetPtRange3ProngSxy);

            int leftbinJetPt3ProngSxyz = h3simjetPt3ProngSxyzFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngSxyz = h3simjetPt3ProngSxyzFlavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngSxyz = reinterpret_cast<TH1F*>(h3simjetPt3ProngSxyzFlavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngSxyz_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngSxyz, rightbinJetPt3ProngSxyz, binFlavour, binFlavour));
            hsimjet3ProngSxyz[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyz->Clone());
            hsimjet3ProngSxyz[numFile][0][binJetPt]->Add(projJetPtRange3ProngSxyz);

            int leftbinJetPt3ProngSxyN1 = h3simjetPt3ProngSxyN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngSxyN1 = h3simjetPt3ProngSxyN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*>(h3simjetPt3ProngSxyN1Flavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngSxyN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngSxyN1, rightbinJetPt3ProngSxyN1, binFlavour, binFlavour));
            hsimjet3ProngSxyN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyN1->Clone());
            hsimjet3ProngSxyN1[numFile][0][binJetPt]->Add(projJetPtRange3ProngSxyN1);

            int leftbinJetPt3ProngSxyzN1 = h3simjetPt3ProngSxyzN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngSxyzN1 = h3simjetPt3ProngSxyzN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*>(h3simjetPt3ProngSxyzN1Flavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngSxyzN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngSxyzN1, rightbinJetPt3ProngSxyzN1, binFlavour, binFlavour));
            hsimjet3ProngSxyzN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngSxyzN1->Clone());
            hsimjet3ProngSxyzN1[numFile][0][binJetPt]->Add(projJetPtRange3ProngSxyzN1);

            int leftbinJetPt3ProngMassN1 = h3simjetPt3ProngMassN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinJetPt3ProngMassN1 = h3simjetPt3ProngMassN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*>(h3simjetPt3ProngMassN1Flavour[numFile]->ProjectionY(Form("projJetPtRagne3ProngMassN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinJetPt3ProngMassN1, rightbinJetPt3ProngMassN1, binFlavour, binFlavour));
            hsimjet3ProngMassN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRange3ProngMassN1->Clone());
            hsimjet3ProngMassN1[numFile][0][binJetPt]->Add(projJetPtRange3ProngMassN1);

            int leftbinTaggedJetPt3ProngSxyN1 = h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinTaggedJetPt3ProngSxyN1 = h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projTaggedJetPtRange3ProngSxyN1 = reinterpret_cast<TH1F*>(h3simtaggedjetPt3ProngSxyN1Flavour[numFile]->ProjectionY(Form("projTaggedJetPtRagne3ProngSxyN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinTaggedJetPt3ProngSxyN1, rightbinTaggedJetPt3ProngSxyN1, binFlavour, binFlavour));
            hsimtaggedjet3ProngSxyN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projTaggedJetPtRange3ProngSxyN1->Clone());
            hsimtaggedjet3ProngSxyN1[numFile][0][binJetPt]->Add(projTaggedJetPtRange3ProngSxyN1);

            int leftbinTaggedJetPt3ProngSxyzN1 = h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinTaggedJetPt3ProngSxyzN1 = h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projTaggedJetPtRange3ProngSxyzN1 = reinterpret_cast<TH1F*>(h3simtaggedjetPt3ProngSxyzN1Flavour[numFile]->ProjectionY(Form("projTaggedJetPtRagne3ProngSxyzN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinTaggedJetPt3ProngSxyzN1, rightbinTaggedJetPt3ProngSxyzN1, binFlavour, binFlavour));
            hsimtaggedjet3ProngSxyzN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projTaggedJetPtRange3ProngSxyzN1->Clone());
            hsimtaggedjet3ProngSxyzN1[numFile][0][binJetPt]->Add(projTaggedJetPtRange3ProngSxyzN1);

            int leftbinTaggedJetPt3ProngMassN1 = h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
            int rightbinTaggedJetPt3ProngMassN1 = h3simtaggedjetPt3ProngMassN1Flavour[numFile]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
            TH1F* projTaggedJetPtRange3ProngMassN1 = reinterpret_cast<TH1F*>(h3simtaggedjetPt3ProngMassN1Flavour[numFile]->ProjectionY(Form("projTaggedJetPtRagne3ProngMassN1_%d_%d_%d", numFile, binJetPt, binFlavour), leftbinTaggedJetPt3ProngMassN1, rightbinTaggedJetPt3ProngMassN1, binFlavour, binFlavour));
            hsimtaggedjet3ProngMassN1[numFile][flavour][binJetPt] = reinterpret_cast<TH1F*>(projTaggedJetPtRange3ProngMassN1->Clone());
            hsimtaggedjet3ProngMassN1[numFile][0][binJetPt]->Add(projTaggedJetPtRange3ProngMassN1);
          }
        }
      }
    }
  }
  if (fillMCP) { // TODO
  }
}

void HfJetTaggingSysAnalysis::normHist() {
  if (fillMCD) {
    for (int numFile =0; numFile < numFiles; numFile++) {
      for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
        if (hsimjetPt[numFile][flavour]->Integral()>0) {
          //hsimjetNormalizedPt[numFile][flavour] = (TH1F*) hsimjetPt[numFile][flavour]->Clone(Form("hsimjetNormalizedPt_%d_%d", numFile, flavour));
          //hsimjetNormalizedEta[numFile][flavour] = (TH1F*) hsimjetEta[numFile][flavour]->Clone(Form("hsimjetNormalizedEta_%d_%d", numFile, flavour));
          //hsimjetNormalizedPhi[numFile][flavour] = (TH1F*) hsimjetPhi[numFile][flavour]->Clone(Form("hsimjetNormalizedPhi_%d_%d", numFile, flavour));
          //hsimjetNormalizedPt[numFile][flavour]->Scale(1. / hsimjetNormalizedPt[numFile][flavour]->Integral());
          //hsimjetNormalizedEta[numFile][flavour]->Scale(1. / hsimjetNormalizedEta[numFile][flavour]->Integral());
          //hsimjetNormalizedPhi[numFile][flavour]->Scale(1. / hsimjetNormalizedPhi[numFile][flavour]->Integral());
        }
        for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
          if (fillIPxy) {
            hsimjetNormalizedImpXY[numFile][flavour][jetPt] = (TH1F*) hsimjetImpXY[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXY_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedSignImpXY[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXY[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXY_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedImpXYSig[numFile][flavour][jetPt] = (TH1F*) hsimjetImpXYSig[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYSig_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedSignImpXYSig[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYSig[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYSig_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedImpXY[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXY[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedSignImpXY[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXY[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedImpXYSig[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYSig[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedSignImpXYSig[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYSig[numFile][flavour][jetPt]->Integral());
          }
          if (fillIPz) {
            hsimjetNormalizedImpZ[numFile][flavour][jetPt] = (TH1F*) hsimjetImpZ[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedImpZ_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedSignImpZ[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpZ[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZ_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedImpZSig[numFile][flavour][jetPt] = (TH1F*) hsimjetImpZSig[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedImpZSig_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedSignImpZSig[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpZSig[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZSig_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedImpZ[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedImpZ[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedSignImpZ[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZ[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedImpZSig[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedImpZSig[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedSignImpZSig[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZSig[numFile][flavour][jetPt]->Integral());
          }
          if (fillIPxyz) { hsimjetNormalizedImpXYZ[numFile][flavour][jetPt] = (TH1F*) hsimjetImpXYZ[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYZ_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedSignImpXYZ[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYZ[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZ_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedImpXYZSig[numFile][flavour][jetPt] = (TH1F*) hsimjetImpXYZSig[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedImpXYZSig_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedSignImpXYZSig[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYZSig[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZSig_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedImpXYZ[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYZ[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedSignImpXYZ[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZ[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedImpXYZSig[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedImpXYZSig[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedSignImpXYZSig[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZSig[numFile][flavour][jetPt]->Integral());
          }
          if (fillTC) {
            if (fillIPxy) {
              hsimjetNormalizedSignImpXYSigN1[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYSigN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYSigN1_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpXYSigN2[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYSigN2[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYSigN2_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpXYSigN3[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYSigN3[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYSigN3_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpXYSigN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYSigN1[numFile][flavour][jetPt]->Integral());
              hsimjetNormalizedSignImpXYSigN2[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYSigN2[numFile][flavour][jetPt]->Integral());
              hsimjetNormalizedSignImpXYSigN3[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYSigN3[numFile][flavour][jetPt]->Integral());
            }
            if (fillIPz) {
              hsimjetNormalizedSignImpZSigN1[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpZSigN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZSigN1_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpZSigN2[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpZSigN2[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZSigN2_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpZSigN3[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpZSigN3[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpZSigN3_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpZSigN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZSigN1[numFile][flavour][jetPt]->Integral());
              hsimjetNormalizedSignImpZSigN2[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZSigN2[numFile][flavour][jetPt]->Integral());
              hsimjetNormalizedSignImpZSigN3[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpZSigN3[numFile][flavour][jetPt]->Integral());
            }
            if (fillIPxyz) {
              hsimjetNormalizedSignImpXYZSigN1[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYZSigN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZSigN1_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpXYZSigN2[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYZSigN2[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZSigN2_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpXYZSigN3[numFile][flavour][jetPt] = (TH1F*) hsimjetSignImpXYZSigN3[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedSignImpXYZSigN3_%d_%d_%d", numFile, flavour, jetPt));
              hsimjetNormalizedSignImpXYZSigN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZSigN1[numFile][flavour][jetPt]->Integral());
              hsimjetNormalizedSignImpXYZSigN2[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZSigN2[numFile][flavour][jetPt]->Integral());
              hsimjetNormalizedSignImpXYZSigN3[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedSignImpXYZSigN3[numFile][flavour][jetPt]->Integral());
            }
          }
          if (fillJP) {
            hsimjetNormalizedNegLogJP[numFile][flavour][jetPt] = (TH1F*) hsimjetNegLogJP[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedNegLogJP_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedNegLogJPN1[numFile][flavour][jetPt] = (TH1F*) hsimjetNegLogJPN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedNegLogJPN1_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedNegLogJPN2[numFile][flavour][jetPt] = (TH1F*) hsimjetNegLogJPN2[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedNegLogJPN2_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedNegLogJPN3[numFile][flavour][jetPt] = (TH1F*) hsimjetNegLogJPN3[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalizedNegLogJPN3_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalizedNegLogJP[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedNegLogJP[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedNegLogJPN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedNegLogJPN1[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedNegLogJPN2[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedNegLogJPN2[numFile][flavour][jetPt]->Integral());
            hsimjetNormalizedNegLogJPN3[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalizedNegLogJPN3[numFile][flavour][jetPt]->Integral());
          }
          if (fillSV) {
            hsimjetNormalized3ProngLxy[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngLxy[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngLxy_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngLxyz[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngLxyz[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngLxyz_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngSxy[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngSxy[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxy_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngSxyz[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngSxyz[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyz_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngsigmaLxy[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngsigmaLxy[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngsigmaLxy_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngsigmaLxyz[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngsigmaLxyz[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngsigmaLxyz_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngSxyN1[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngSxyN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyN1_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngSxyzN1[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngSxyzN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngSxyzN1_%d_%d_%d", numFile, flavour, jetPt));
            hsimjetNormalized3ProngMassN1[numFile][flavour][jetPt] = (TH1F*) hsimjet3ProngMassN1[numFile][flavour][jetPt]->Clone(Form("hsimjetNormalized3ProngMassN1_%d_%d_%d", numFile, flavour, jetPt));
            hsimtaggedjetNormalized3ProngSxyN1[numFile][flavour][jetPt] = (TH1F*) hsimtaggedjet3ProngSxyN1[numFile][flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngSxyN1_%d_%d_%d", numFile, flavour, jetPt));
            hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][jetPt] = (TH1F*) hsimtaggedjet3ProngSxyzN1[numFile][flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngSxyzN1_%d_%d_%d", numFile, flavour, jetPt));
            hsimtaggedjetNormalized3ProngMassN1[numFile][flavour][jetPt] = (TH1F*) hsimtaggedjet3ProngMassN1[numFile][flavour][jetPt]->Clone(Form("hsimtaggedjetNormalized3ProngMassN1_%d_%d_%d", numFile, flavour, jetPt));

            hsimjetNormalized3ProngLxy[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngLxy[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngLxyz[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngLxyz[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngSxy[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxy[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngSxyz[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyz[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngsigmaLxy[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngsigmaLxy[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngsigmaLxyz[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngsigmaLxyz[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngSxyN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyN1[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]->Integral());
            hsimjetNormalized3ProngMassN1[numFile][flavour][jetPt]->Scale(1. / hsimjetNormalized3ProngMassN1[numFile][flavour][jetPt]->Integral());
            hsimtaggedjetNormalized3ProngSxyN1[numFile][flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngSxyN1[numFile][flavour][jetPt]->Integral());
            hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][jetPt]->Integral());
            hsimtaggedjetNormalized3ProngMassN1[numFile][flavour][jetPt]->Scale(1. / hsimtaggedjetNormalized3ProngMassN1[numFile][flavour][jetPt]->Integral());
          }
        }
      }
    }
  }
  if (fillMCP) { // TODO
  }
}

void HfJetTaggingSysAnalysis::initAnalysis(const std::vector<std::pair<TString, TString>> &rootFiles) {
  processSetUp(rootFiles);
  if (fillData) {
    loadData(rootFiles);
  } else if (fillMCD) {
    loadSim(rootFiles);
  } else {
    std::cout << " turn on data or mcd" << std::endl;
    return;
  }
  initHist();
  projHist();
  normHist();
}

void HfJetTaggingSysAnalysis::savePara() {
  gnc=nc;
}

/// draw function
void HfJetTaggingSysAnalysis::drawDataJetPt(bool doLog = true) {
  std::vector<HistogramData> rawHist;
  std::vector<HistogramData> normArea;
  for (int numFile =0; numFile < numFiles; numFile++) {
    rawHist.push_back({hdatajetPt[numFile], files[numFile].second});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], hdatajetPt[0]->GetMaximum(), HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/jetmomemtum.pdf\")", nc++, dirData.Data()));
}

void HfJetTaggingSysAnalysis::drawDataJetEta(bool doLog = true) {
}

void HfJetTaggingSysAnalysis::drawDataJetPhi(bool doLog = true) {
}

void HfJetTaggingSysAnalysis::drawDataJetImpXY(bool doLog = true, int binJetPt = 0) {
  std::vector<HistogramData> rawHist;
  std::vector<HistogramData> normArea;
  for (int numFile =0; numFile < numFiles; numFile++) {
    rawHist.push_back({hdatajetImpXY[numFile][binJetPt], files[numFile].second});
  }
  canHan = new CanvasHandler();
  canHan->createCanvas(nc);
  if (doLog) gPad->SetLogy();
  canHan->drawCombined(rawHist.size(), rawHist, true, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  latexDataSet();
  latexDataJetInfo(0.47, 0.86, 0, "anti-#it{k}_{T}", "charged", 0.4, FIGURESET.Data());
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/ImpXY_%d.pdf\")", nc++, dirData.Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void HfJetTaggingSysAnalysis::drawDataJetSignImpXY(bool doLog = true, int binJetPt = 0) {
}

void HfJetTaggingSysAnalysis::drawDataJetImpXYSignificance(bool doLog = true, int binJetPt = 0) {
}

void HfJetTaggingSysAnalysis::drawDataJetSignImpXYSignificance(bool doLog = true, int binJetPt = 0) {
}

void HfJetTaggingSysAnalysis::drawDataJetSignImpXYSignificanceN1(bool doLog = true, int binJetPt = 0) {
}

void HfJetTaggingSysAnalysis::drawDataJetSignImpXYSignificanceN2(bool doLog = true, int binJetPt = 0) {
}

void HfJetTaggingSysAnalysis::drawDataJetSignImpXYSignificanceN3(bool doLog = true, int binJetPt = 0) {
}

void HfJetTaggingSysAnalysis::drawSimJetPt(bool withInc = false, bool doLog = true) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedPt[numFile][flavour], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPT[0], HfJetTagging::REFHIST::JETPT[1], HfJetTagging::REFHIST::JETPT[2], HfJetTagging::REFHIST::JETPT[3], HfJetTagging::X_AXIS_JETPT, HfJetTagging::Y_AXIS_JETPT);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, -1, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetmomemtum.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetEta(bool withInc = false, bool doLog = true) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedEta[numFile][flavour], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETETA[0], HfJetTagging::REFHIST::JETETA[1], HfJetTagging::REFHIST::JETETA[2], HfJetTagging::REFHIST::JETETA[3], HfJetTagging::X_AXIS_JETETA, HfJetTagging::Y_AXIS_JETETA);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, -1, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jeteta.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetPhi(bool withInc = false, bool doLog = true) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedPhi[numFile][flavour], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::JETPHI[0], HfJetTagging::REFHIST::JETPHI[1], HfJetTagging::REFHIST::JETPHI[2], HfJetTagging::REFHIST::JETPHI[3], HfJetTagging::X_AXIS_JETPHI, HfJetTagging::Y_AXIS_JETPHI);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, -1, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/jetphi.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data()));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedImpXY[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[0], HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.65, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.030);
    latex.DrawLatex(0.65, 0.89-0.055*5, Form("%s jet", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/ImpXY_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetSignImpXY(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedSignImpXY[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXY[0], HfJetTagging::REFHIST::IPXY[1], HfJetTagging::REFHIST::IPXY[2], HfJetTagging::REFHIST::IPXY[3], HfJetTagging::X_AXIS_IMPXY[1], HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.65, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.030);
    latex.DrawLatex(0.65, 0.89-0.055*5, Form("%s jet", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/SignImpXY_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedImpXYSig[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[2], HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.65, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.030);
    latex.DrawLatex(0.65, 0.89-0.055*5, Form("%s jet", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/ImpXYSig_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetSignImpXYSignificance(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedSignImpXYSig[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.65, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.030);
    latex.DrawLatex(0.65, 0.89-0.055*5, Form("%s jet", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/SignImpXYSig_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSimJetSignImpXYSignificanceN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalizedSignImpXYSigN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::IPXYSIG[0], HfJetTagging::REFHIST::IPXYSIG[1], HfJetTagging::REFHIST::IPXYSIG[2], HfJetTagging::REFHIST::IPXYSIG[3], HfJetTagging::X_AXIS_IMPXY[3], HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.65, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data(), 0.030);
    latex.DrawLatex(0.65, 0.89-0.055*5, Form("%s jet, 1^{st} largest %s", HfJetTagging::FLAVOUR[flavour].Data(), HfJetTagging::X_AXIS_IMPXY[3].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/SignImpXYSigN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngLxy[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWLXY[0], HfJetTagging::REFHIST::RAWLXY[1], HfJetTagging::REFHIST::RAWLXY[2], HfJetTagging::REFHIST::RAWLXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawLxy_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngLxyz[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWLXYZ[0], HfJetTagging::REFHIST::RAWLXYZ[1], HfJetTagging::REFHIST::RAWLXYZ[2], HfJetTagging::REFHIST::RAWLXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawLxyz_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngSxy[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawSxy_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngSxyz[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXYZ[0], HfJetTagging::REFHIST::RAWSXYZ[1], HfJetTagging::REFHIST::RAWSXYZ[2], HfJetTagging::REFHIST::RAWSXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawSxyz_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngsigmaLxy[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSIGMALXY[0], HfJetTagging::REFHIST::RAWSIGMALXY[1], HfJetTagging::REFHIST::RAWSIGMALXY[2], HfJetTagging::REFHIST::RAWSIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngsigmaLxyz[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSIGMALXYZ[0], HfJetTagging::REFHIST::RAWSIGMALXYZ[1], HfJetTagging::REFHIST::RAWSIGMALXYZ[2], HfJetTagging::REFHIST::RAWSIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngSxyN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate (largest S#it{L}_{XY})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawSxyN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngSxyzN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXYZ[0], HfJetTagging::REFHIST::RAWSXYZ[1], HfJetTagging::REFHIST::RAWSXYZ[2], HfJetTagging::REFHIST::RAWSXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate (largest S#it{L}_{XYZ})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawSxyzN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngRawMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjet3ProngMassN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWMASS[0], HfJetTagging::REFHIST::RAWMASS[1], HfJetTagging::REFHIST::RAWMASS[2], HfJetTagging::REFHIST::RAWMASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate (largest S#it{L}_{XYZ})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngRawSxyzN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngtaggedjetRawSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimtaggedjet3ProngSxyN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXY[0], HfJetTagging::REFHIST::RAWSXY[1], HfJetTagging::REFHIST::RAWSXY[2], HfJetTagging::REFHIST::RAWSXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s tagged jet, 3-prongs candidate (largest S#it{L}_{XY})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngTaggedjetRawSxyN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngtaggedjetRawSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimtaggedjet3ProngSxyzN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWSXYZ[0], HfJetTagging::REFHIST::RAWSXYZ[1], HfJetTagging::REFHIST::RAWSXYZ[2], HfJetTagging::REFHIST::RAWSXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s tagged jet, 3-prongs candidate (largest S#it{L}_{XYZ})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngTaggedjetRawSxyzN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngtaggedjetRawMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimtaggedjet3ProngMassN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::RAWMASS[0], HfJetTagging::REFHIST::RAWMASS[1], HfJetTagging::REFHIST::RAWMASS[2], HfJetTagging::REFHIST::RAWMASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_YIELD);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s tagged jet, 3-prongs candidate (largest S#it{L}_{XY})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngTaggedjetRawMassN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngLxy[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXY[0], HfJetTagging::REFHIST::LXY[1], HfJetTagging::REFHIST::LXY[2], HfJetTagging::REFHIST::LXY[3], HfJetTagging::X_AXIS_LXY, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngLxy_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngLxyz[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::LXYZ[0], HfJetTagging::REFHIST::LXYZ[1], HfJetTagging::REFHIST::LXYZ[2], HfJetTagging::REFHIST::LXYZ[3], HfJetTagging::X_AXIS_LXYZ, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngLxyz_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngSxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngSxy[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngSxy_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngSxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngSxyz[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngSxyz_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngsigmaLxy(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngsigmaLxy[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXY[0], HfJetTagging::REFHIST::SIGMALXY[1], HfJetTagging::REFHIST::SIGMALXY[2], HfJetTagging::REFHIST::SIGMALXY[3], HfJetTagging::X_AXIS_SIGMALXY, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngsigmaLxy_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngsigmaLxyz(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngsigmaLxyz[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SIGMALXYZ[0], HfJetTagging::REFHIST::SIGMALXYZ[1], HfJetTagging::REFHIST::SIGMALXYZ[2], HfJetTagging::REFHIST::SIGMALXYZ[3], HfJetTagging::X_AXIS_SIGMALXYZ, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngsigmaLxyz_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngSxyN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate (largest S#it{L}_{XY})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngSxyN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngSxyzN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate (largest S#it{L}_{XYZ})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngSxyzN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimjetNormalized3ProngMassN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s jet, 3-prongs candidate (largest S#it{L}_{XY})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngMassN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngtaggedjetSxyN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimtaggedjetNormalized3ProngSxyN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXY[0], HfJetTagging::REFHIST::SXY[1], HfJetTagging::REFHIST::SXY[2], HfJetTagging::REFHIST::SXY[3], HfJetTagging::X_AXIS_SXY, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s tagged jet, 3-prongs candidate (largest S#it{L}_{XY})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngTaggedjetSxyN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngtaggedjetSxyzN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::SXYZ[0], HfJetTagging::REFHIST::SXYZ[1], HfJetTagging::REFHIST::SXYZ[2], HfJetTagging::REFHIST::SXYZ[3], HfJetTagging::X_AXIS_SXYZ, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s tagged jet, 3-prongs candidate (largest S#it{L}_{XYZ})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngTaggedjetSxyzN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void HfJetTaggingSysAnalysis::drawSim3ProngtaggedjetMassN1(bool withInc = false, bool doLog = true, int binJetPt=0) {
  for (int flavour=0; flavour < HfJetTagging::nFlavour+1; flavour++) {
    std::vector<HistogramData> normHist;
    for (int numFile =0; numFile < numFiles; numFile++) {
      normHist.push_back({hsimtaggedjetNormalized3ProngSxyzN1[numFile][flavour][binJetPt], files[numFile].second});
    }
    canHan = new CanvasHandler();
    canHan->createCanvas(nc);
    if (doLog) gPad->SetLogy();
    canHan->drawRefHistogram(nc, HfJetTagging::REFHIST::MASS[0], HfJetTagging::REFHIST::MASS[1], HfJetTagging::REFHIST::MASS[2], HfJetTagging::REFHIST::MASS[3], HfJetTagging::X_AXIS_MASS, HfJetTagging::AXIS_PROB);
    canHan->drawCombined(normHist.size(), normHist, withInc, true, 0.17, 0.80, HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
    latexSimSet();
    latexSimJetInfo(0.50, 0.89, binJetPt, TRIGGERNAME.Data(), "anti-#it{k}_{T}", "Charged", 0.4, FIGURESET.Data());
    latex.DrawLatex(0.50, 0.89-0.055*5, Form("%s tagged jet, 3-prongs candidate (largest S#it{L}_{XYZ})", HfJetTagging::FLAVOUR[flavour].Data()));
    gROOT->ProcessLine(Form("cc%d->Print(\"%s/%sjet/3ProngTaggedjetMassN1_%d.pdf\")", nc++, dirSim.Data(), HfJetTagging::FLAVOUR[flavour].Data(), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

#endif // HFJETTAGGINGSYSANALYSIS_H
