#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include <TCanvas.h>
#include <TPad.h>
#include <TH2D.h>
#include <TString.h>
#include <TSystem.h>
#include <TLatex.h>
#include "DataPoint.h"

class CanvasHandler {
  public:
    CanvasHandler();
    ~CanvasHandler();

    void histColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void createCanvas(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas2x2(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas3x1(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas4x1(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas3x2(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void DrawRefHistogram(int number, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);
    void DrawRefHistogramWithPad(int number, int numPad, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);
    void createRatioCanvas(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void drawPad(std::vector<HistogramData>& histograms, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
    void drawPadCombined(std::vector<HistogramData>& histograms, bool withLeg, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
    void drawUpperPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
    void drawLowerPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);

  private:
    TCanvas* canvas;
    TPad* mpad[50];
    TPad* mtoppad;
    TPad* muppad;
    TPad* mlowpad;

};

CanvasHandler::CanvasHandler() {
}

CanvasHandler::~CanvasHandler() {
  if (canvas) delete canvas;
  for (int i =0; i< 50; i++) {
    if (mpad[i]) delete mpad[i];
  }
}

void CanvasHandler::histColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void CanvasHandler::createCanvas(int number=0, int xp=0, int yp=0, int x=800, int y=600,
                                double pleft=0.12, double pright=0.05, double ptop=0.05, double pbot=0.12) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetMarkerSize(1.6);
    canvas->cd();
    std::snprintf(name, sizeof(name), "mpad%d", number);
    mpad[0] = new TPad(name, name, 0.02, 0.02, 0.99, 0.99, 0, 0, 0);
    mpad[0]->SetTopMargin(ptop);
    mpad[0]->SetBottomMargin(pbot);
    mpad[0]->SetLeftMargin(pleft);
    mpad[0]->SetRightMargin(pright);
    mpad[0]->Range(0, 0, 1, 1);
    mpad[0]->SetLogz(1);
    mpad[0]->Draw();
    mpad[0]->cd();
    canvas->Modified();
    canvas->Update();
  } else {
    mpad[0] = dynamic_cast<TPad*>(canvas->GetListOfPrimitives()->FindObject(Form("mpad[0]%d", number)));
    if (mpad[0]) {
      canvas->cd();
      mpad[0]->cd();
      canvas->Modified();
      canvas->Update();
    }
  }
  gSystem->ProcessEvents();
}

void CanvasHandler::createCanvas2x2(int number=0, int xp=0, int yp=0, int x=800, int y=800,
    double pleft=0.12, double pright=0.05, double ptop=0.05, double pbot=0.12) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetMarkerSize(1.6);
    canvas->Divide(2, 2); // Divide canvas into 2 rows, 2 column
    for (int i = 0; i < 4; ++i) {
      canvas->cd(i+1);
      std::snprintf(name, sizeof(name), "mpad%d_%d", number, i);
      mpad[i] = new TPad(name, name, 0.0, 0.0, 1.0, 1.0, 0, 0, 0);
      mpad[i]->SetTopMargin(ptop);
      mpad[i]->SetBottomMargin(pbot);
      mpad[i]->SetLeftMargin(pleft);
      mpad[i]->SetRightMargin(pright);
      mpad[i]->Range(0, 0, 1, 1);
      mpad[i]->SetLogz(1);
      mpad[i]->Draw();
      mpad[i]->cd();
    }
    canvas->Modified();
    canvas->Update();
  } else {
    for (int i = 0; i < 4; ++i) {
      mpad[i] = dynamic_cast<TPad*>(canvas->GetListOfPrimitives()->FindObject(Form("mpad%d_%d", number, i)));
      if (mpad[i]) {
        canvas->cd(i+1);
        mpad[i]->cd();
        canvas->Modified();
        canvas->Update();
      }
    }
  }
  gSystem->ProcessEvents();
}

void CanvasHandler::createCanvas3x1(int number=0, int xp=0, int yp=0, int x=1200, int y=600,
    double pleft=0.12, double pright=0.05, double ptop=0.05, double pbot=0.12) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetMarkerSize(1.6);
    canvas->Divide(3, 1); // Divide canvas into 3 rows, 1 column
    for (int i = 0; i < 3; ++i) {
      canvas->cd(i+1);
      std::snprintf(name, sizeof(name), "mpad%d_%d", number, i);
      mpad[i] = new TPad(name, name, 0.0, 0.0, 1.0, 1.0, 0, 0, 0);
      mpad[i]->SetTopMargin(ptop);
      mpad[i]->SetBottomMargin(pbot);
      mpad[i]->SetLeftMargin(pleft);
      mpad[i]->SetRightMargin(pright);
      mpad[i]->Range(0, 0, 1, 1);
      mpad[i]->SetLogz(1);
      mpad[i]->Draw();
      mpad[i]->cd();
    }
    canvas->Modified();
    canvas->Update();
  } else {
    for (int i = 0; i < 3; ++i) {
      mpad[i] = dynamic_cast<TPad*>(canvas->GetListOfPrimitives()->FindObject(Form("mpad%d_%d", number, i)));
      if (mpad[i]) {
        canvas->cd(i+1);
        mpad[i]->cd();
        canvas->Modified();
        canvas->Update();
      }
    }
  }
  gSystem->ProcessEvents();
}

void CanvasHandler::createCanvas4x1(int number=0, int xp=0, int yp=0, int x=1000, int y=600,
    double pleft=0.12, double pright=0.05, double ptop=0.05, double pbot=0.12) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetMarkerSize(1.6);
    //canvas->SetLeftMargin(0.2);
    //canvas->SetBottomMargin(0.2);
    //canvas->Divide(4, 1, 0 ,0); // Divide canvas into 4 rows, 1 column
    canvas->Divide(4, 1); // Divide canvas into 4 rows, 1 column
    for (int i = 0; i < 4; ++i) {
      canvas->cd(i+1);
      std::snprintf(name, sizeof(name), "mpad%d_%d", number, i);
      mpad[i] = new TPad(name, name, 0.0, 0.0, 1.0, 1.0, 0, 0, 0);
      mpad[i]->SetTopMargin(ptop);
      mpad[i]->SetBottomMargin(pbot);
      mpad[i]->SetLeftMargin(pleft);
      mpad[i]->SetRightMargin(pright);
      mpad[i]->Range(0, 0, 1, 1);
      mpad[i]->SetLogz(1);
      mpad[i]->Draw();
      mpad[i]->cd();
    }
    canvas->Modified();
    canvas->Update();
  } else {
    for (int i = 0; i < 4; ++i) {
      mpad[i] = dynamic_cast<TPad*>(canvas->GetListOfPrimitives()->FindObject(Form("mpad%d_%d", number, i)));
      if (mpad[i]) {
        canvas->cd(i+1);
        mpad[i]->cd();
        canvas->Modified();
        canvas->Update();
      }
    }
  }
  gSystem->ProcessEvents();
}

void CanvasHandler::createCanvas3x2(int number=0, int xp=0, int yp=0, int x=1200, int y=800,
    double pleft=0.12, double pright=0.05, double ptop=0.05, double pbot=0.12) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetMarkerSize(1.6);
    canvas->Divide(3, 2); // Divide canvas into 3 rows, 2 column
    for (int i = 0; i < 6; ++i) {
      canvas->cd(i+1);
      std::snprintf(name, sizeof(name), "mpad%d_%d", number, i);
      mpad[i] = new TPad(name, name, 0.0, 0.0, 1.0, 1.0, 0, 0, 0);
      mpad[i]->SetTopMargin(ptop);
      mpad[i]->SetBottomMargin(pbot);
      mpad[i]->SetLeftMargin(pleft);
      mpad[i]->SetRightMargin(pright);
      mpad[i]->Range(0, 0, 1, 1);
      mpad[i]->SetLogz(1);
      mpad[i]->Draw();
      mpad[i]->cd();
    }
    canvas->Modified();
    canvas->Update();
  } else {
    for (int i = 0; i < 6; ++i) {
      mpad[i] = dynamic_cast<TPad*>(canvas->GetListOfPrimitives()->FindObject(Form("mpad%d_%d", number, i)));
      if (mpad[i]) {
        canvas->cd(i+1);
        mpad[i]->cd();
        canvas->Modified();
        canvas->Update();
      }
    }
  }
  gSystem->ProcessEvents();
}

void CanvasHandler::DrawRefHistogram(int number, double xmin, double xmax, double ymin, double ymax,
    TString xtitle, TString ytitle) {
  char name[100];
  std::snprintf(name, sizeof(name), "href%d", number);
  int xbin = 100;
  int ybin = 100;
  TH2D* href = new TH2D(name, name, xbin, xmin, xmax, ybin, ymin, ymax);
  href->SetStats(0);
  href->GetXaxis()->SetTitle(xtitle.Data());
  href->GetXaxis()->SetLabelSize(0.03);
  href->GetXaxis()->SetTitleOffset(1.2);
  href->GetYaxis()->SetTitle(ytitle.Data());
  href->GetYaxis()->SetLabelSize(0.03);
  href->GetYaxis()->SetTitleOffset(1.5);
  href->Draw();
}

void CanvasHandler::DrawRefHistogramWithPad(int number, int numpad, double xmin, double xmax, double ymin, double ymax,
    TString xtitle, TString ytitle) {
  char name[100];
  std::snprintf(name, sizeof(name), "href%d_%d", number, numpad);
  int xbin = 100;
  int ybin = 100;
  TH2D* href = new TH2D(name, name, xbin, xmin, xmax, ybin, ymin, ymax);
  href->SetStats(0);
  href->GetXaxis()->SetTitle(xtitle.Data());
  href->GetXaxis()->SetLabelSize(0.03);
  href->GetXaxis()->SetTitleOffset(1.2);
  href->GetYaxis()->SetTitle(ytitle.Data());
  href->GetYaxis()->SetLabelSize(0.03);
  href->GetYaxis()->SetTitleOffset(1.5);
  href->Draw();
}

void CanvasHandler::createRatioCanvas(int number=0, int xp=0, int yp=0, int x=1600, int y=900,
    double pleft=0.17, double pright=0.1, double ptop=0.1, double pbot=0.13) {
    char name[100];
    snprintf(name,sizeof(name),"cc%d",number);
    TCanvas *c = new TCanvas(name,name,0,0,800,1000);
    gStyle->SetOptStat(0); gStyle->SetOptTitle(0);
    c->cd();
    mtoppad = new TPad("mtoppad","mtoppad",0.01,0.01,0.99,0.99,0,0,0);
    mtoppad->SetTopMargin(0.0);
    mtoppad->SetBottomMargin(0.0);
    mtoppad->SetLeftMargin(0.0);
    mtoppad->SetRightMargin(0.0);
    mtoppad->Range(0, 0, 10, 10);
    mtoppad->Draw();
    mtoppad->cd();
    //   This is just for the Y axis label
    mtoppad->cd();
	snprintf(name,sizeof(name),"padu%d",number);	
    muppad = new TPad(name,name,0.01,0.35,0.99,0.99,0,0,0);
    muppad->SetTopMargin(0.0);
    muppad->SetBottomMargin(0.0);
    muppad->SetLeftMargin(0.15);
    muppad->SetRightMargin(0.05);
    muppad->Draw();
    muppad->cd();
    mtoppad->cd();
	snprintf(name,sizeof(name),"padd%d",number);	
    mlowpad = new TPad(name,name,0.01,0.01,0.99,0.35,0,0,0);
    mlowpad->SetTopMargin(0.0);
    mlowpad->SetBottomMargin(0.3);
    mlowpad->SetLeftMargin(0.15);
    mlowpad->SetRightMargin(0.05);
    mlowpad->Draw();
    c->Modified();
    c->Update();
  //gSystem->ProcessEvents();
}

void CanvasHandler::drawPad(std::vector<HistogramData>& histograms, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  TH1F *hist = histograms[numpad].hist;
  gROOT->ProcessLine(Form("mpad%d_%d->cd()", numcan, numpad));
  if (doLog) gPad->SetLogy();
  this->DrawRefHistogramWithPad(numcan, numpad, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  hist->Draw("same");
  gROOT->ProcessLine(Form("mpad%d_%d->Update()", numcan, numpad));
}

void CanvasHandler::drawPadCombined(std::vector<HistogramData>& histograms, bool withLeg, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  TLegend *leg = new TLegend(CANOPT::LEG[0], CANOPT::LEG[1], CANOPT::LEG[2], CANOPT::LEG[3]);
  int histSize = histograms.size();
  gROOT->ProcessLine(Form("mpad%d_%d->cd()", numcan, numpad));
  if (doLog) gPad->SetLogy();
  this->DrawRefHistogramWithPad(numcan, numpad, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  for (int i=0; i<histSize; i++) {
    TH1F *hist = histograms[i].hist;
    this->histColorStyle(hist, i+1, i+20, CANOPT::MARKERSIZE, i+1, 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (withLeg) leg->Draw();
  gROOT->ProcessLine(Form("mpad%d_%d->Update()", numcan, numpad));
}

void CanvasHandler::drawUpperPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  gROOT->ProcessLine(Form("padu%d->cd()", number));
  gPad->SetLogy();
  this->DrawRefHistogramWithPad(number, 0, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  h1->Draw("same");
  gROOT->ProcessLine(Form("padu%d->Update()", number));
}

void CanvasHandler::drawLowerPad(TH1F* h1, int number, double xmin, double xmax, double ymin=1.1, double ymax=1.1, TString xtitle="", TString ytitle="#frac{data}{MC}") {
  xmin= h1->FindBin(1);
  xmax= h1->FindBin(h1->GetNbinsX());
  gROOT->ProcessLine(Form("padd%d->cd()", number));
  this->DrawRefHistogramWithPad(number, 1, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  h1->Draw("same");
  gROOT->ProcessLine(Form("padd%d->Update()", number));
}

void latexDataJetInfo(double x=0.2, double y=0.9, int binJetPt=0, TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4) {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

  latex.DrawLatex(x, y, "pp #sqrt{s} = 13.6 TeV");
  latex.DrawLatex(x, y-0.04, Form("%s %s jets, R=%0.1f", jetAlgo.Data(), jetType.Data(), jetRadi));
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-0.08, Form("#it{p}_{T,jet}^{ch} > %d GeV/#it{c}", static_cast<int>(HfJetTagging::cutJetPt)));
  }
  if (binJetPt > 0) latex.DrawLatex(x, y-0.08, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  latex.DrawLatex(x, y-0.12, "constituents in jets");
}

void latexSimJetInfo(double x=0.2, double y=0.9, int binJetPt=0, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4) {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size

  latex.DrawLatex(x, y, "pp #sqrt{s} = 13.6 TeV");
  latex.DrawLatex(x, y-0.04, Form("%s %s jets, R=%0.1f", jetAlgo.Data(), jetType.Data(), jetRadi));
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-0.08, Form("#it{p}_{T,jet}^{ch} > %d GeV/#it{c}", static_cast<int>(HfJetTagging::cutJetPt)));
  }
  if (binJetPt > 0) latex.DrawLatex(x, y-0.08, Form("%d < #it{p}_{T}^{jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  latex.DrawLatex(x, y-0.12, "constituents in jets");
  latex.DrawLatex(x, y-0.16, triggerName.Data());
}

void latexDataSet(double x=0.80, double y=0.97) {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextColor(kRed+2); // dark red 
  latex.DrawLatex(x, y, DATASET.Data());
}

void latexSimSet(double x=0.80, double y=0.97) {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextColor(kRed+2); // dark red 
  latex.DrawLatex(x, y, SIMSET.Data());
}

void SetLegendBoxSize(TLegend *legend, int numGraphs) {
  double boxWidthFactor = 0.05;
  double boxHeightFactor = 0.03;

  double boxWidth = boxWidthFactor * numGraphs;
  double boxHeight = boxHeightFactor * numGraphs;

  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);
  legend->SetMargin(0.2);

  legend->SetX1NDC(0.7);
  legend->SetY1NDC(0.7 - boxHeight);
  legend->SetX2NDC(0.7 + boxWidth);
  legend->SetY2NDC(0.7);

  legend->SetTextSize(0.03);
}


#endif // CANVASHANDLER_H
