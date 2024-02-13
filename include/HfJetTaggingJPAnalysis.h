#ifndef HFJETTAGGINGJPANALYSIS_H
#define HFJETTAGGINGJPANALYSIS_H

#include "TH1D.h"
#include "TString.h"
#include "DataPoint.h"
#include "CanvasHandler.h"
//#include "JetAnalysis.h"
//#include "HfJetTaggingAnalysis.h"
//#include "HfJetTaggingTCAnalysis.h"

class HfJetTaggingJPAnalysis {
  public:
    HfJetTaggingJPAnalysis(const TString rootData, const TString rootSim, bool doData, bool doMC, bool dopartLevel) {
      InitConfig();
      if (doData) {
				if (!LoadDataJPQA(rootData.Data())) {
          return;
        }
      	InitHistogramForNormalizationJPQAData();
      	ProjectionHistJPQAData();
      	NormalizedHistogramJPQAData();
			}
      if (doMC) {
				if (!LoadSimJPQA(rootSim.Data())) {
          return;
        }
      	InitHistogramForNormalizationJPQAMC();
      	ProjectionHistJPQAMC();
        //NegLogHist();
      	NormalizedHistogramJPQAMC();
			}
      SaveHistogramJPQA("JPQA.root", doData, doMC, dopartLevel);
 
    }
    ~HfJetTaggingJPAnalysis();

    // function
    ///Basic
    void InitConfig();
    int LoadDataJPQA(TString rootData);
    int LoadSimJPQA(TString rootSim);
    void InitHistogramForNormalizationJPQAData();
    void InitHistogramForNormalizationJPQAMC();
    void ProjectionHistJPQAData();
    void ProjectionHistJPQAMC();
    //void NegLogHist();
    void NormalizedHistogramJPQAData();
    void NormalizedHistogramJPQAMC();
    void SaveHistogramJPQA(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    /// Draw
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    std::vector<HistogramData> histList;
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool withLeg, double legendxmin, double ymin, double xmax, double ymax);

    int canvasNum = 0;
    CanvasHandler* canvasHandler;
    void DrawTaggedJetJP(bool withInc, bool doLog, int binJetPt);
    void DrawTaggedJetNegLogJP(bool withInc, bool doLog, int binJetPt);

  protected:
    TH3F* h3simTagjetPtJPFlavour;
    TH3F* h3simTagjetPtNegLogJPFlavour;
    TH1F* hsimTagjetJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNormalizedNegLogJP[HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    
  private:
    TLatex latex;

};

//HfJetTaggingJPAnalysis::~HfJetTaggingJPAnalysis() {
//  delete h3simTagjetPtJPFlavour;
//  for (int flavour=0; flavour < HfJetTagging::nFlavour; flavour++) {
//    for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt; binJetPt++) {
//      delete hsimTagjetJP[flavour][binJetPt];
//      delete hsimTagjetNegLogJP[flavour][binJetPt];
//      delete hsimTagjetNormalizedJP[flavour][binJetPt];
//      delete hsimTagjetNormalizedNegLogJP[flavour][binJetPt];
//    }
//  }
//}
//
void HfJetTaggingJPAnalysis::InitConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
}

int HfJetTaggingJPAnalysis::LoadDataJPQA(TString rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file (DATA, JP QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-tc-charged";

  return 1;
}

int HfJetTaggingJPAnalysis::LoadSimJPQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC, Flavour QA) not found!" << std::endl;
    return 0;
  }
  TString taskName = "jet-taggerhf-qa-charged";

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  h3simTagjetPtJPFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_JP_flavour", taskName.Data())));
  h3simTagjetPtNegLogJPFlavour = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));

  std::cout << "Load completed JP MC data" << std::endl;
  return 1;
}

void HfJetTaggingJPAnalysis::InitHistogramForNormalizationJPQAData() {
}

void HfJetTaggingJPAnalysis::InitHistogramForNormalizationJPQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetJP[flavour][jetPt] = new TH1F(Form("hsimTagjetJP_%d_%d", flavour, jetPt), "", h3simTagjetPtJPFlavour->GetNbinsY(), h3simTagjetPtJPFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtJPFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtJPFlavour->GetNbinsY()));
			hsimTagjetNegLogJP[flavour][jetPt] = new TH1F(Form("hsimTagjetNegLogJP_%d_%d", flavour, jetPt), "", h3simTagjetPtNegLogJPFlavour->GetNbinsY(), h3simTagjetPtNegLogJPFlavour->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPFlavour->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPFlavour->GetNbinsY()));
    }
  }
}

void HfJetTaggingJPAnalysis::ProjectionHistJPQAData() {
}

void HfJetTaggingJPAnalysis::ProjectionHistJPQAMC() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
	for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
    HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
		TH1F* projJP = reinterpret_cast<TH1F*> (h3simTagjetPtJPFlavour->ProjectionY(Form("projJP_%d", binFlavour), 1, h3simTagjetPtJPFlavour->GetNbinsX(), binFlavour, binFlavour));
		TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour->ProjectionY(Form("projNegLogJP_%d", binFlavour), 1, h3simTagjetPtNegLogJPFlavour->GetNbinsX(), binFlavour, binFlavour));
		hsimTagjetJP[0][0]->Add(projJP);
		hsimTagjetJP[flavour][0] = reinterpret_cast<TH1F*>(projJP->Clone(Form("hsimTagjetJP_%d_0", flavour)));
		hsimTagjetNegLogJP[0][0]->Add(projNegLogJP);
		hsimTagjetNegLogJP[flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_0", flavour)));

		for (int binJetPt =1; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
			int leftbinJetPtJP = h3simTagjetPtJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtJP = h3simTagjetPtJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeJP = reinterpret_cast<TH1F*> (h3simTagjetPtJPFlavour->ProjectionY(Form("projJetPtRangeJP_%d_%d", binJetPt, flavour), leftbinJetPtJP, rightbinJetPtJP, flavour, flavour));
			hsimTagjetJP[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeJP->Clone(Form("hsimTagjetJP_%d_%d", flavour, binJetPt))); 
			hsimTagjetJP[0][binJetPt]->Add(projJetPtRangeJP);

			int leftbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1]);
			int rightbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt]);
			TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour->ProjectionY(Form("projJetPtRangeNegLogJP_%d_%d", binJetPt, flavour), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, flavour, flavour));
			hsimTagjetNegLogJP[flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_%d", flavour, binJetPt))); 
			hsimTagjetNegLogJP[0][binJetPt]->Add(projJetPtRangeNegLogJP);

    }
  }
}

//void HfJetTaggingJPAnalysis::NegLogHist() {
//	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
//		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
//      hsimTagjetNegLogJP[flavour][jetPt] = (TH1F*)hsimTagjetJP[flavour][jetPt]->Clone(Form("hsimTagjetNegLogJP_%d_%d", flavour, jetPt));
//      int nBinsX = hsimTagjetNegLogJP[flavour][jetPt]->GetNbinsX();
//      for (int iBin = 0; iBin <= nBinsX + 1; ++iBin) { // Include underflow and overflow
//        double originalValue = hsimTagjetNegLogJP[flavour][jetPt]->GetBinContent(iBin);
//        double logValue = -1; // Default value for undefined log
//
//        // Calculate -log(value) only for positive values
//        if (originalValue > 0) {
//          logValue = -TMath::Log(originalValue);
//        }
//
//        // Set the new bin content
//        hsimTagjetNegLogJP[flavour][jetPt]->SetBinContent(iBin, logValue);
//      }
//    }
//  }
//}

void HfJetTaggingJPAnalysis::NormalizedHistogramJPQAData() {
}

void HfJetTaggingJPAnalysis::NormalizedHistogramJPQAMC() {
	for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
		for (int jetPt = 0; jetPt < HfJetTagging::nBinsJetPt+1; jetPt++) {
			hsimTagjetNormalizedJP[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetJP[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedJP_%d_%d", flavour, jetPt)));
			hsimTagjetNormalizedNegLogJP[flavour][jetPt] = reinterpret_cast<TH1F*> (hsimTagjetNegLogJP[flavour][jetPt]->Clone(Form("hsimTagjetNormalizedNegLogJP_%d_%d", flavour, jetPt)));

      // Scale
			hsimTagjetNormalizedJP[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedJP[flavour][jetPt]->GetEntries());
			hsimTagjetNormalizedNegLogJP[flavour][jetPt]->Scale(1. / hsimTagjetNormalizedNegLogJP[flavour][jetPt]->GetEntries());
    }
  }
}

void HfJetTaggingJPAnalysis::SaveHistogramJPQA(TString outFile, bool doData, bool doMC, bool dopartLevel) {
}

// Draw function
void HfJetTaggingJPAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingJPAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, bool withLeg, double xmin=0, double ymin=0, double xmax=1, double ymax=1){
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (withLeg) leg->Draw();
}
void HfJetTaggingJPAnalysis::DrawTaggedJetJP(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedJP[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedJP[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedJP[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedJP[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::JP[0], HfJetTagging::REFHIST::JP[1], HfJetTagging::REFHIST::JP[2], HfJetTagging::REFHIST::JP[3], "JP", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/jetProb_%d.pdf\")", canvasNum - 1, static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

void HfJetTaggingJPAnalysis::DrawTaggedJetNegLogJP(bool withInc = false, bool doLog = true, int binJetPt=0){
  std::vector<HistogramData> NormHistList;
  if (withInc) NormHistList.push_back({hsimTagjetNormalizedNegLogJP[0][binJetPt], HfJetTagging::INCJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJP[1][binJetPt], HfJetTagging::CJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJP[2][binJetPt], HfJetTagging::BJET});
  NormHistList.push_back({hsimTagjetNormalizedNegLogJP[3][binJetPt], HfJetTagging::LFJET});

  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  if (doLog) gPad->SetLogy();
  canvasHandler->DrawRefHistogram(canvasNum, HfJetTagging::REFHIST::LOGJP[0], HfJetTagging::REFHIST::LOGJP[1], HfJetTagging::REFHIST::LOGJP[2], HfJetTagging::REFHIST::LOGJP[3], "-Log(JP)", "#frac{1}{#it{N_{track}}} #frac{d#it{N_{track}}}{d#it{p_{T}^{track}}}");
  this->DrawCombined(NormHistList.size(), NormHistList, true, HfJetTagging::LEG[0], HfJetTagging::LEG[1], HfJetTagging::LEG[2], HfJetTagging::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/jetProbNegLog_%d.pdf\")", canvasNum - 1, static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));

}

#endif // HFJETTAGGINGJPANALYSIS_H 
