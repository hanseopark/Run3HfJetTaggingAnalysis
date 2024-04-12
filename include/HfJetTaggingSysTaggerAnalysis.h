#ifndef HFJETTAGGINGSYSTAGGERANALYSIS_H
#define HFJETTAGGINGSYSTAGGERANALYSIS_H

#include <TH1F.h>
#include <TString.h>
#include "CanvasHandler.h"
#include "DataPoint.h"

class HfJetTaggingSysTaggerAnalysis {
  public:
    HfJetTaggingSysTaggerAnalysis(const std::vector<TString> &rootSim, bool doData, bool doMC, bool dopartLevel) {
///      if (doData) {
///        LoadData(rootSim);
///      }
      initConfig();
      if (doMC) {
        if(!LoadSimTagger(rootSim)) {
          return;
        }
        InitHistogramTagger();
        ProjectionHistTagger();
        NormalizedHistogramTagger();
      }
      //SaveHistogram("sysTagger.root", doData, doMC, dopartLevel);

    }
    ~HfJetTaggingSysTaggerAnalysis();

    //// FUNCTION ////
    void initConfig();
    int LoadSimTagger(const std::vector<TString> &rootFiles);
    void InitHistogramTagger();
    void ProjectionHistTagger();
    void NormalizedHistogramTagger();
    void SaveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel);

    // fucntion
    void HistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void DrawCombined(int num, const std::vector<HistogramData>& histList, bool doLeg, double legendxmin, double ymin, double xmax, double ymax);
    float getEfficiency(TH1F* h1, TH1F* h2);
    float getPurity(TH1F* h1, TH1F* h2);
    void drawGraphEffiAndPurity(bool doLog, int binJetPt);
    

  protected:
    CanvasHandler* canvasHandler;
    int canvasNum=0;

    TH3F* h3simTagjetPtJPFlavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtNegLogJPFlavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtJPN1Flavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtNegLogJPN1Flavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtJPN2Flavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtNegLogJPN2Flavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtJPN3Flavour[HfJetTagging::numTagger];
    TH3F* h3simTagjetPtNegLogJPN3Flavour[HfJetTagging::numTagger];

    TH1F* hsimTagjetJP[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJP[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN1[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN1[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN2[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN2[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetJPN3[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimTagjetNegLogJPN3[HfJetTagging::numTagger][HfJetTagging::nFlavour+1][HfJetTagging::nBinsJetPt+1];
    TH1F* hsimJPEffiN1[HfJetTagging::numTagger][HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN2[HfJetTagging::numTagger][HfJetTagging::nFlavour+1];
    TH1F* hsimJPEffiN3[HfJetTagging::numTagger][HfJetTagging::nFlavour+1];

  private:
    TLatex latex;

};

HfJetTaggingSysTaggerAnalysis::~HfJetTaggingSysTaggerAnalysis() {
  std::cout<< " " << std::endl;
}

//int HfJetTaggingSysTaggerAnalysis::LoadData(TString rootFile) { // TODO
//  return 0;
//}

void HfJetTaggingSysTaggerAnalysis::initConfig() {
  //latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

}

int HfJetTaggingSysTaggerAnalysis::LoadSimTagger(const std::vector<TString> &rootFiles) {
  const TString &taskName = "jet-taggerhf-qa-charged";
  int maxTagger = 0;
  for (const auto& rootFile : rootFiles) {
    if (gSystem->AccessPathName(rootFile.Data())) {
      std::cout << "Input file (MC) not found!" << std::endl;
      std::cout << Form("%s ", rootFile.Data()) << std::endl;
      return 0;
    }
    TFile* fin;
    fin = TFile::Open(rootFile, "READ");
    
    h3simTagjetPtNegLogJPFlavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN1Flavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N1_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN2Flavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N2_flavour", taskName.Data())));
    h3simTagjetPtNegLogJPN3Flavour[maxTagger] = reinterpret_cast<TH3F*>(fin->Get(Form("%s/h3_jet_pt_neg_log_JP_N3_flavour", taskName.Data())));
    maxTagger++;
  }
  std::cout<<"MC loaded"<<std::endl;

  return 1;
}

void HfJetTaggingSysTaggerAnalysis::InitHistogramTagger() {
  for (int tagger =0; tagger < HfJetTagging::numTagger; tagger++) {
    for (int flavour = 0; flavour < HfJetTagging::nFlavour+1; flavour++) {
      hsimJPEffiN1[tagger][flavour] = new TH1F(Form("hsimJPEffiN1_%d_%d", tagger, flavour), "", 10000, 0, 10000);
      hsimJPEffiN2[tagger][flavour] = new TH1F(Form("hsimJPEffiN2_%d_%d", tagger, flavour), "", 10000, 0, 10000);
      hsimJPEffiN3[tagger][flavour] = new TH1F(Form("hsimJPEffiN3_%d_%d", tagger, flavour), "", 10000, 0, 10000);
      for (int binJetPt=0; binJetPt < HfJetTagging::nBinsJetPt+1; binJetPt++) {
        hsimTagjetNegLogJP[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJP_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPFlavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPFlavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPFlavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPFlavour[tagger]->GetNbinsY()));
        hsimTagjetNegLogJPN1[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPN1Flavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPN1Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN1Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN1Flavour[tagger]->GetNbinsY()));
        hsimTagjetNegLogJPN2[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPN2Flavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPN2Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN2Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN2Flavour[tagger]->GetNbinsY()));
        hsimTagjetNegLogJPN3[tagger][flavour][binJetPt] = new TH1F(Form("hsimTagjetNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt), "", h3simTagjetPtNegLogJPN3Flavour[tagger]->GetNbinsY(), h3simTagjetPtNegLogJPN3Flavour[tagger]->GetYaxis()->GetBinLowEdge(1), h3simTagjetPtNegLogJPN3Flavour[tagger]->GetYaxis()->GetBinUpEdge(h3simTagjetPtNegLogJPN3Flavour[tagger]->GetNbinsY()));
      }
    }
  }
}

void HfJetTaggingSysTaggerAnalysis::ProjectionHistTagger() {
  HfJetTagging::JetFlavour jetFlavours[] = {HfJetTagging::None, HfJetTagging::Charm, HfJetTagging::Beauty, HfJetTagging::LightFlavour};
  for (int tagger=0; tagger<HfJetTagging::numTagger; tagger++) {
    for (int binFlavour = 2; binFlavour < HfJetTagging::nFlavour+2; binFlavour++) {
      HfJetTagging::JetFlavour flavour = jetFlavours[binFlavour - 1];
		  TH1F* projNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour[tagger]->ProjectionY(Form("projNegLogJP_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPFlavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN1Flavour[tagger]->ProjectionY(Form("projNegLogJPN1_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPN1Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN2Flavour[tagger]->ProjectionY(Form("projNegLogJPN2_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPN2Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));
		  TH1F* projNegLogJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN3Flavour[tagger]->ProjectionY(Form("projNegLogJPN3_%d_%d", tagger, flavour), 1, h3simTagjetPtNegLogJPN3Flavour[tagger]->GetNbinsX(), binFlavour, binFlavour));

		  hsimTagjetNegLogJP[tagger][0][0]->Add(projNegLogJP);
		  hsimTagjetNegLogJP[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_%d_0", tagger, flavour)));
		  hsimTagjetNegLogJPN1[tagger][0][0]->Add(projNegLogJPN1);
		  hsimTagjetNegLogJPN1[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN1->Clone(Form("hsimTagjetNegLogJPN1_%d_%d_0", tagger, flavour)));
		  hsimTagjetNegLogJPN2[tagger][0][0]->Add(projNegLogJPN2);
		  hsimTagjetNegLogJPN2[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN2->Clone(Form("hsimTagjetNegLogJPN2_%d_%d_0", tagger, flavour)));
		  hsimTagjetNegLogJPN3[tagger][0][0]->Add(projNegLogJPN3);
		  hsimTagjetNegLogJPN3[tagger][flavour][0] = reinterpret_cast<TH1F*>(projNegLogJPN3->Clone(Form("hsimTagjetNegLogJPN3_%d_%d_0", tagger, flavour)));
      delete projNegLogJP;
      delete projNegLogJPN1;
      delete projNegLogJPN2;
      delete projNegLogJPN3;
      for (int binJetPt=0; binJetPt<HfJetTagging::nBinsJetPt+1; binJetPt++) {
        int leftbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJP = h3simTagjetPtNegLogJPFlavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJP = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPFlavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJP_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJP, rightbinJetPtNegLogJP, binFlavour, binFlavour));
        hsimTagjetNegLogJP[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJP->Clone(Form("hsimTagjetNegLogJP_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJP[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJP);

        int leftbinJetPtNegLogJPN1 = h3simTagjetPtNegLogJPN1Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN1 = h3simTagjetPtNegLogJPN1Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN1 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN1Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN1, rightbinJetPtNegLogJPN1, binFlavour, binFlavour));
        hsimTagjetNegLogJPN1[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN1->Clone(Form("hsimTagjetNegLogJPN1_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJPN1[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN1);

        int leftbinJetPtNegLogJPN2 = h3simTagjetPtNegLogJPN2Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN2 = h3simTagjetPtNegLogJPN2Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN2 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN2Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN2, rightbinJetPtNegLogJPN2, binFlavour, binFlavour));
        hsimTagjetNegLogJPN2[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN2->Clone(Form("hsimTagjetNegLogJPN2_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJPN2[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN2);

        int leftbinJetPtNegLogJPN3 = h3simTagjetPtNegLogJPN3Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt-1])-1;
        int rightbinJetPtNegLogJPN3 = h3simTagjetPtNegLogJPN3Flavour[tagger]->GetXaxis()->FindBin(HfJetTagging::binsJetPt[binJetPt])-1;
        TH1F* projJetPtRangeNegLogJPN3 = reinterpret_cast<TH1F*> (h3simTagjetPtNegLogJPN3Flavour[tagger]->ProjectionY(Form("projJetPtRangeNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt), leftbinJetPtNegLogJPN3, rightbinJetPtNegLogJPN3, binFlavour, binFlavour));
        hsimTagjetNegLogJPN3[tagger][flavour][binJetPt] = reinterpret_cast<TH1F*>(projJetPtRangeNegLogJPN3->Clone(Form("hsimTagjetNegLogJPN3_%d_%d_%d", tagger, flavour, binJetPt))); 
        hsimTagjetNegLogJPN3[tagger][0][binJetPt]->Add(projJetPtRangeNegLogJPN3);

        delete projJetPtRangeNegLogJP;
        delete projJetPtRangeNegLogJPN1;
        delete projJetPtRangeNegLogJPN2;
        delete projJetPtRangeNegLogJPN3;
      }
    }
  }
}

void HfJetTaggingSysTaggerAnalysis::NormalizedHistogramTagger() {
}

void HfJetTaggingSysTaggerAnalysis::SaveHistogram(TString rootFile, bool doData, bool doMC, bool dopartLevel) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  TDirectory* dir;

  if (doMC) {
    dir = fout->GetDirectory("sim");
  	if (!dir) {
    	dir = fout->mkdir("sim");
    	dir->cd();
  	}
  }
}

void HfJetTaggingSysTaggerAnalysis::HistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void HfJetTaggingSysTaggerAnalysis::DrawCombined(int num, const std::vector<HistogramData>& histograms, bool doLeg, double xmin, double ymin, double xmax, double ymax) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  for (int i=0; i<num; i++){
    TH1F *hist = histograms[i].hist;
    this->HistColorStyle(hist, i+1, i+20, HfJetTagging::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    //hist->Draw("same HIST");
    hist->Draw("same");
  }
  if(doLeg) leg->Draw();
}

float HfJetTaggingSysTaggerAnalysis::getEfficiency(TH1F* hNegLogJPNx, TH1F* hNegLogJPUntagged) {
  // it needs code defence
  int numOfbJetBeforeTagger = hNegLogJPUntagged->Integral(1, hNegLogJPUntagged->GetNbinsX());
  int numOfbJetAfterTagger = hNegLogJPNx->Integral(1, hNegLogJPNx->GetNbinsX());
  if (numOfbJetBeforeTagger==0) return -1;
  float effi = static_cast<float>((float)numOfbJetAfterTagger / numOfbJetBeforeTagger);
  return effi;
}

float HfJetTaggingSysTaggerAnalysis::getPurity(TH1F* hNegLogJPTaggedbJet, TH1F* hNegLogJPTaggedIncJet) {
  // it needs defence
  int numOfbjet = hNegLogJPTaggedbJet->Integral(1,hNegLogJPTaggedbJet->GetNbinsX());
  int numOfincjet = hNegLogJPTaggedIncJet->Integral(1, hNegLogJPTaggedIncJet->GetNbinsX());
  if (numOfincjet == 0 ) return -1;
  float purity = static_cast<float>((float)numOfbjet/numOfincjet);
  return purity;
}

void HfJetTaggingSysTaggerAnalysis::drawGraphEffiAndPurity(bool doLog, int binJetPt) {
  float xN1[HfJetTagging::numTagger], yN1[HfJetTagging::numTagger];
  float xN2[HfJetTagging::numTagger], yN2[HfJetTagging::numTagger];
  float xN3[HfJetTagging::numTagger], yN3[HfJetTagging::numTagger];
  for (int tagger=0; tagger<HfJetTagging::numTagger; tagger++) {
    for (int flavour=1; flavour<HfJetTagging::nFlavour+1; flavour++) {
      if (flavour!=2) continue;
      float effiN1= this->getEfficiency(hsimTagjetNegLogJPN1[tagger][flavour][binJetPt], hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN1 = this->getPurity(hsimTagjetNegLogJPN1[tagger][flavour][binJetPt],hsimTagjetNegLogJPN1[tagger][0][binJetPt]);
      float effiN2= this->getEfficiency(hsimTagjetNegLogJPN2[tagger][flavour][binJetPt], hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN2 = this->getPurity(hsimTagjetNegLogJPN2[tagger][flavour][binJetPt],hsimTagjetNegLogJPN2[tagger][0][binJetPt]);
      float effiN3= this->getEfficiency(hsimTagjetNegLogJPN3[tagger][flavour][binJetPt], hsimTagjetNegLogJP[tagger][flavour][binJetPt]);
      float purityN3 = this->getPurity(hsimTagjetNegLogJPN3[tagger][flavour][binJetPt],hsimTagjetNegLogJPN3[tagger][0][binJetPt]);
      xN1[tagger] = effiN1;
      yN1[tagger] = purityN1;
      xN2[tagger] = effiN2;
      yN2[tagger] = purityN2;
      xN3[tagger] = effiN3;
      yN3[tagger] = purityN3;
      std::cout << "N1 tagger point: " << HfJetTagging::SYS::binsTagger[tagger] << " effi: " << effiN1 << " purity: " << purityN1 << std::endl;
    }
  }
  canvasHandler = new CanvasHandler();
  canvasHandler->createCanvas(canvasNum++);
  //if(doLog) gPad->SetLogy();
  auto gN1 = new TGraph(HfJetTagging::numTagger, xN1, yN1);
  auto gN2 = new TGraph(HfJetTagging::numTagger, xN2, yN2);
  auto gN3 = new TGraph(HfJetTagging::numTagger, xN3, yN3);

  gN1->SetName("gN1");
  gN1->SetTitle("N1 tagger");
  gN1->SetMarkerStyle(21);
  gN1->SetDrawOption("AP");
  gN1->SetLineColor(2);
  gN1->SetLineWidth(4);
  gN1->SetFillStyle(0);
  gN1->GetXaxis()->SetRangeUser(0, 1);
  gN1->GetYaxis()->SetRangeUser(0, 0.2);
  gN1->GetXaxis()->SetNdivisions(510);  // 10 primary + 1 secondary per decade
  gN1->GetYaxis()->SetNdivisions(510);

  gN1->GetXaxis()->SetTitle("#epsilon");
  gN1->GetYaxis()->SetTitle("purity");

  gN2->SetName("gN2");
  gN2->SetTitle("N2 tagger");
  gN2->SetMarkerStyle(22);
  gN2->SetMarkerColor(3);
  gN2->SetDrawOption("P");
  gN2->SetLineColor(3);
  gN2->SetLineWidth(4);
  gN2->SetFillStyle(0);
  gN2->GetXaxis()->SetRangeUser(0, 1);
  gN2->GetYaxis()->SetRangeUser(0, 1);

  gN3->SetName("gN3");
  gN3->SetTitle("N3 tagger");
  gN3->SetMarkerStyle(23);
  gN3->SetLineColor(4);
  gN3->SetMarkerColor(4);
  gN3->SetLineWidth(4);
  gN3->SetFillStyle(0);
  gN3->GetXaxis()->SetRangeUser(0, 1);
  gN3->GetYaxis()->SetRangeUser(0, 1);

  //gN1->Draw("AC*");
//  TMultiGraph *mg = new TMultiGraph();
//  mg->Add(gN1);
//  mg->Add(gN2);
//  mg->Add(gN3);
//  mg->Draw("ALP");
  if (doLog) {
    gPad->SetLogx();
    gPad->SetLogy();
  }
  gN1->Draw("ALP");
  gN2->Draw("same LP");
  gN3->Draw("same LP");

  for (int i=0; i<HfJetTagging::numTagger; i++) {
    latex.DrawLatex(xN1[i]+0.005, yN1[i]+0.005, Form("%0.1f", HfJetTagging::SYS::binsTagger[i]));
  }
  TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg->AddEntry(gN1, "N=1", "lp");
  leg->AddEntry(gN2, "N=2", "lp");
  leg->AddEntry(gN3, "N=3", "lp");
  leg->Draw();
  //gN2->Draw("same");
  gROOT->ProcessLine(Form("cc%d->Print(\"fig/sim/sys/bjet/tagger/EffiAndPurityJPNx.pdf\")", canvasNum - 1));
}

#endif // HFJETTAGGINGSYSTAGGERANALYSIS_H
