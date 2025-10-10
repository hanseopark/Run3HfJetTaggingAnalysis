#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include <TCanvas.h>
#include <TPad.h>
#include <TH2D.h>
#include <TString.h>
#include <TSystem.h>
#include <TLatex.h>
#include <TLegendEntry.h>
#include "DataPoint.h"

void SetLegendBoxSize(TLegend *legend, int numGraphs, double xpoint, double ypoint, double boxWeight, double boxHeight);

class CanvasHandler {
  public:
    CanvasHandler();
    ~CanvasHandler();

    void histColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void histColorStyle2D(TH2* h2, int mc, int ms, double mS, int lc, int ls);
    void createCanvas(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot, int optstat);
    void createCanvasMxN(int number, int Nx, int Ny, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas2x2(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas3x1(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas4x1(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void createCanvas3x2(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    std::vector<HistogramData> histList;
    void thistColorStyle(TH1F* h1, int mc, int ms, double mS, int lc, int ls);
    void setHistogram2D(TH2 *h2, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle, float xoffset, float yoffset, int optstat);
    void drawCombined(int histSize, const std::vector<HistogramData>& histList, bool withInc, bool withLeg, double legendxmin, double ymin, double xmax, double ymax, double ratio, TString option);
    void drawCombined2D(int histSize, const std::vector<Histogram2DData>& histList, bool withInc, bool withLeg, double legendxmin, double ymin, double xmax, double ymax, double ratio);
    void drawCombinedForXSection(int histSize, const std::vector<HistogramData>& histList, bool withLeg, double legendxmin, double ymin, double xmax, double ymax, double ratio);
    void drawRefHistogram(int number, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle, float xoffset, float yoffset, int optstat, float titleszie, float labelsize);
    void drawRefRatioHistogram(int number, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);
    void drawRefHistogramWithPad(int number, int numPad, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);
    void drawRefHistogramWithPadMxN(int number, int numPad_x, int numpad_y, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);
    void createRatioCanvas(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot, int optstat);
    void drawPad(std::vector<HistogramData>& histograms, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
    void drawPadCombined(std::vector<HistogramData>& histograms, bool withInc, bool withLeg, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
    void drawPadMxNCombined(int numcan, int numpad_x, int numpad_y, std::vector<HistogramData>& histograms, bool withInc, bool doLog, bool withLeg, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
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

void CanvasHandler::histColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20, double markersize = 1, 
    int linecolor = 1, int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void CanvasHandler::histColorStyle2D(TH2* h2, int markercolor = 1, int markerstyle = 20, double markersize = 1, 
    int linecolor = 1, int linestyle = 1)
{
  h2->SetMarkerStyle(markerstyle);
  h2->SetMarkerColor(markercolor);
  h2->SetMarkerSize(markersize);
  h2->SetLineStyle(linestyle);
  h2->SetLineColor(linecolor);
}

void CanvasHandler::createCanvas(int number=0, int xp=0, int yp=0, int x=800, int y=600,
                                double pleft=0.12, double pright=0.04, double ptop=0.05, double pbot=0.12, int optstat=0) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(optstat);
    gStyle->SetOptTitle(0);
    gStyle->SetLineWidth(2);
    //gStyle->SetMarkerSize(CANOPT::MARKERSIZE);
    canvas->cd();
    std::snprintf(name, sizeof(name), "mpad%d", number);
    mpad[0] = new TPad(name, name, 0.02, 0.02, 0.99, 0.99, 0, 0, 0);
    mpad[0]->SetTopMargin(ptop);
    mpad[0]->SetBottomMargin(pbot);
    mpad[0]->SetLeftMargin(pleft);
    mpad[0]->SetRightMargin(pright);
    mpad[0]->Range(0, 0, 1, 1);
    //mpad[0]->SetLogz(1);
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

void CanvasHandler::createCanvasMxN(int number=0, int Nx=2, int Ny=2, int xp=0, int yp=0, int x=800, int y=800, double lMargin=0.12, double rMargin =0.05, double tMargin=0.05, double bMargin=0.12) {
  char name[100];
  std::snprintf(name, sizeof(name), "cc%d", number);
  canvas = dynamic_cast<TCanvas*>(gROOT->GetListOfCanvases()->FindObject(name));
  if (!canvas) {
    canvas = new TCanvas(name, name, xp, yp, x, y);
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetMarkerSize(CANOPT::MARKERSIZE);
    gStyle->SetLineWidth(1);
    gStyle->SetTextFont(42);
    //gStyle->SetHistLineWidth(10);
    //gStyle->SetTextSizePixels(10);

    //
    float vSpacing = 0.0;
    float vStep  = (1.- bMargin - tMargin - (Ny-1) * vSpacing) / Ny;
    float hSpacing = 0.0;
    float hStep  = (1.- lMargin - rMargin - (Nx-1) * hSpacing) / Nx;
    float vposd,vposu,vmard,vmaru,vfactor;
    float hposl,hposr,hmarl,hmarr,hfactor;
    for (Int_t i=0;i<Nx;i++) {
      if (i==0) {
        hposl = 0.0;
        hposr = lMargin + hStep;
        hfactor = hposr-hposl;
        hmarl = lMargin / hfactor;
        hmarr = 0.0;
      } else if (i == Nx-1) {
        hposl = hposr + hSpacing;
        hposr = hposl + hStep + rMargin;
        hfactor = hposr-hposl;
        hmarl = 0.0;
        hmarr = rMargin / (hposr-hposl);
      } else {
        hposl = hposr + hSpacing;
        hposr = hposl + hStep;
        hfactor = hposr-hposl;
        hmarl = 0.0;
        hmarr = 0.0;
      }
      for (Int_t j=0;j<Ny;j++) {
        if (j==0) {
          vposd = 0.0;
          vposu = bMargin + vStep;
          vfactor = vposu-vposd;
          vmard = bMargin / vfactor;
          vmaru = 0.0;
        } else if (j == Ny-1) {
          vposd = vposu + vSpacing;
          vposu = vposd + vStep + tMargin;
          vfactor = vposu-vposd;
          vmard = 0.0;
          vmaru = tMargin / (vposu-vposd);
        } else {
          vposd = vposu + vSpacing;
          vposu = vposd + vStep;
          vfactor = vposu-vposd;
          vmard = 0.0;
          vmaru = 0.0;
        }
        canvas->cd();
        std::snprintf(name, sizeof(name), "mpad%d_%d_%d", number,i,j);
        TPad *pad = (TPad*) gROOT->FindObject(name);
        if (pad) delete pad;
        //pad = new TPad(name,"",hposl,vposd,hposr,vposu);
        pad = new TPad(name,"",hposl,vposd,hposr,vposu, 0, 0, 0);
        pad->SetFillStyle(4000);
        pad->SetFrameFillStyle(4000);
        pad->SetLeftMargin(hmarl);
        pad->SetRightMargin(hmarr);
        pad->SetBottomMargin(vmard);
        pad->SetTopMargin(vmaru);
        pad->SetFrameBorderMode(0);
        pad->SetBorderMode(0);
        pad->Range(0,0,1,1);
        pad->SetLogz(1);
        pad->Draw();
        canvas->Modified();
        canvas->Update();
      }
    }
  } else {
    std::cout<<"temp";
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
    gStyle->SetMarkerSize(HfJetTagging::MARKERSIZE);
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

void CanvasHandler::createCanvas3x1(int number=0, int xp=0, int yp=0, int x=2400, int y=600,
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
    canvas->SetBorderMode(0);
    canvas->SetFrameBorderMode(0); // Remove frame around the canvas
   
    for (int i = 0; i < 3; ++i) {
      canvas->cd(i+1);
      std::snprintf(name, sizeof(name), "mpad%d_%d", number, i);
      mpad[i] = new TPad(name, name, 0.0, 0.0, 1.0, 1.0, 0, 0, 0);
      mpad[i]->SetTopMargin(ptop);
      mpad[i]->SetBottomMargin(pbot);
      if (i==0) {
        mpad[i]->SetLeftMargin(0.12);
      } else {
        mpad[i]->SetLeftMargin(pleft);
      }
      mpad[i]->SetRightMargin(pright);
      mpad[i]->SetFrameBorderMode(0); // Remove frame around the pad
      mpad[i]->SetBorderMode(0);
      mpad[i]->SetBorderSize(0); // Remove border around the pad
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

void CanvasHandler::createCanvas4x1(int number=0, int xp=0, int yp=0, int x=3200, int y=600,
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
      if (i==0) mpad[i]->SetLeftMargin(0.12);
      else mpad[i]->SetLeftMargin(pleft);
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

void CanvasHandler::thistColorStyle(TH1F* h1, int markercolor = 1, int markerstyle = 20,
    double markersize = 1, int linecolor = 1,
    int linestyle = 1)
{
  h1->SetMarkerStyle(markerstyle);
  h1->SetMarkerColor(markercolor);
  h1->SetMarkerSize(markersize);
  h1->SetLineStyle(linestyle);
  h1->SetLineColor(linecolor);
}

void CanvasHandler::drawCombined(int histSize, const std::vector<HistogramData>& histograms, bool withInc, bool withLeg, double xmin=0.6, double ymin=0.6, double xmax=0.9, double ymax=0.9, double ratio=0.060, TString option="e") {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  if (histSize <=4) {
    //std::vector<int> histogramOrder = {0, 2, 1, 3}; // Customize this order as needed
    std::vector<int> histogramOrder = {0, 1, 2, 3}; // Customize this order as needed
    for (int i : histogramOrder) {
      if (i < 0 || i >= histSize) continue;
      if (i==0 && !(withInc)) continue;
      TH1F *hist = histograms[i].hist;
      this->histColorStyle(hist, HfJetTagging::colorFlavour[i], HfJetTagging::markerStyleFlavour[i], HfJetTagging::markerSizeFlavour[i], HfJetTagging::colorFlavour[i], 1);
      TString clfi = histograms[i].classification;
      //leg->AddEntry(hist, clfi.Data(), "l");
      leg->AddEntry(hist, clfi.Data(), "lep");
      hist->Draw(Form("same %s", option.Data()));
    }
  } else {
    for (int i=0; i<histSize; i++) {
      if(i==0 && !(withInc)) continue;
      TH1F *hist = histograms[i].hist;
      this->histColorStyle(hist, HfJetTagging::colorFlavour[i], i+20, HfJetTagging::MARKERSIZE, HfJetTagging::colorFlavour[i], 1);
      TString clfi = histograms[i].classification;
      leg->AddEntry(hist, clfi.Data(), "lep");
      hist->Draw(Form("same %s", option.Data()));
    }
  }
  // for legend
  SetLegendBoxSize(leg, histSize, xmin, ymin, ratio, 3 * ratio / 4);
  if (withLeg) leg->Draw();
}

void CanvasHandler::drawCombinedForXSection(int histSize, const std::vector<HistogramData>& histograms, bool withLeg, double xmin=0.6, double ymin=0.6, double xmax=0.9, double ymax=0.9, double ratio=0.060) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  // first order data
  TH1F *hist = histograms[0].hist;
  this->histColorStyle(hist, HfJetTagging::colorFlavour[0], HfJetTagging::markerStyleFlavour[0], HfJetTagging::markerSizeFlavour[0], HfJetTagging::colorFlavour[0], 1);
  TString clfi = histograms[0].classification;
  //leg->AddEntry(hist, clfi.Data(), "l");
  leg->AddEntry(hist, clfi.Data(), "lep");
  hist->Draw("same e");
  // second order model 
  TH1F* histModel = histograms[1].hist;
  clfi = histograms[1].classification;
  TGraph* gr = new TGraph(histModel);
  gr->SetLineColor(kRed);
  gr->SetLineWidth(2);
  leg->AddEntry(gr, clfi.Data(), "l");
  gr->Draw("SAME L");

  // for legend
  SetLegendBoxSize(leg, histSize, xmin, ymin, ratio, 3 * ratio / 4);
  if (withLeg) leg->Draw();
}

void CanvasHandler::drawCombined2D(int histSize, const std::vector<Histogram2DData>& histograms, bool withInc, bool withLeg, double xmin=0.6, double ymin=0.6, double xmax=0.9, double ymax=0.9, double ratio=0.060) {
  TLegend *leg = new TLegend(xmin, ymin, xmax, ymax);
  if (histSize <=4) {
    //std::vector<int> histogramOrder = {0, 2, 1, 3}; // Customize this order as needed
    std::vector<int> histogramOrder = {0, 1, 2, 3}; // Customize this order as needed
    for (int i : histogramOrder) {
      if (i < 0 || i >= histSize) continue;
      if (i==0 && !(withInc)) continue;
      TH2 *hist = histograms[i].hist;
      this->histColorStyle2D(hist, HfJetTagging::colorFlavour[i], HfJetTagging::markerStyleFlavour[i], HfJetTagging::markerSizeFlavour[i], HfJetTagging::colorFlavour[i], 1);
      TString clfi = histograms[i].classification;
      //leg->AddEntry(hist, clfi.Data(), "l");
      leg->AddEntry(hist, clfi.Data(), "lep");
      hist->Draw("same e");
    }
  } else {
    for (int i=0; i<histSize; i++) {
      if(i==0 && !(withInc)) continue;
      TH2 *hist = histograms[i].hist;
      this->histColorStyle2D(hist, HfJetTagging::colorFlavour[i], i+20, HfJetTagging::MARKERSIZE, HfJetTagging::colorFlavour[i], 1);
      TString clfi = histograms[i].classification;
      leg->AddEntry(hist, clfi.Data(), "lep");
      hist->Draw("same e");
    }
  }
  // for legend
  SetLegendBoxSize(leg, histSize, xmin, ymin, ratio, 3 * ratio / 4);
  if (withLeg) leg->Draw();
}

void CanvasHandler::setHistogram2D(TH2* h2, double xmin, double xmas, double ymin, double ymax, TString xtitle, TString ytitle, float xoffset=1.10, float yoffset=1.20, int optstat=0) {
  h2->SetStats(optstat);
  h2->GetXaxis()->SetTitle(xtitle.Data());
  h2->GetXaxis()->SetLabelSize(0.045);
  h2->GetXaxis()->SetTitleOffset(xoffset);
  h2->GetXaxis()->SetTitleSize(0.05);
  h2->GetYaxis()->SetTitle(ytitle.Data());
  h2->GetYaxis()->SetLabelSize(0.045);
  h2->GetYaxis()->SetTitleOffset(yoffset);
  h2->GetYaxis()->SetTitleSize(0.05);
}

void CanvasHandler::drawRefHistogram(int number, double xmin, double xmax, double ymin, double ymax,
    TString xtitle, TString ytitle, float xoffset=1.10, float yoffset=1.20, int optstat=0, float titlesize=0.05, float labelsize=0.045) {
  char name[100];
  std::snprintf(name, sizeof(name), "href%d", number);
  int xbin = 100;
  int ybin = 100;
  TH2D* href = new TH2D(name, name, xbin, xmin, xmax, ybin, ymin, ymax);
  href->SetStats(optstat);
  href->GetXaxis()->SetTitle(xtitle.Data());
  href->GetXaxis()->SetLabelSize(labelsize);
  href->GetXaxis()->SetTitleOffset(xoffset);
  href->GetXaxis()->SetTitleSize(titlesize);
  href->GetYaxis()->SetTitle(ytitle.Data());
  href->GetYaxis()->SetLabelSize(labelsize);
  href->GetYaxis()->SetTitleOffset(yoffset);
  href->GetYaxis()->SetTitleSize(titlesize);
  href->Draw();
}

void CanvasHandler::drawRefRatioHistogram(int number, double xmin, double xmax, double ymin, double ymax,
    TString xtitle, TString ytitle="Data/MC") {

  char name[100];
  std::snprintf(name, sizeof(name), "hrefRatio%d", number);
  int xbin = 100;
  int ybin = 100;
  TH2D* href = new TH2D(name, name, xbin, xmin, xmax, ybin, ymin, ymax);
  href->SetStats(0);
  href->GetXaxis()->SetTitle(xtitle.Data());
  href->GetYaxis()->SetTitle(ytitle.Data());
  href->GetXaxis()->SetTitleSize(0.08);
  href->GetYaxis()->SetTitleSize(0.08);
  href->GetXaxis()->SetLabelSize(0.06);
  href->GetYaxis()->SetLabelSize(0.06);
  href->GetXaxis()->SetTitleOffset(1.15);
  href->GetYaxis()->SetTitleOffset(0.8);
  href->GetYaxis()->CenterTitle();
  href->Draw();
}

void CanvasHandler::drawRefHistogramWithPad(int number, int numpad, double xmin, double xmax, double ymin, double ymax,
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
  href->GetYaxis()->SetTitleOffset(1.2);
  href->GetXaxis()->SetTitleSize(0.05);
  href->GetYaxis()->SetTitleSize(0.05);
  href->Draw();
}

void CanvasHandler::drawRefHistogramWithPadMxN(int number, int numpad_x, int numpad_y, double xmin, double xmax, double ymin, double ymax,
    TString xtitle, TString ytitle) {
  char name[100];
  std::snprintf(name, sizeof(name), "href%d_%d_%d", number, numpad_x, numpad_y);
  int xbin = 100;
  int ybin = 100;
  TH2D* href = new TH2D(name, name, xbin, xmin, xmax, ybin, ymin, ymax);
  href->SetStats(0);
  href->GetXaxis()->SetTitleFont(42);
  href->GetXaxis()->SetLabelSize(0.045);
  href->GetXaxis()->SetTitleOffset(0.8);
  href->GetXaxis()->SetTitleSize(0.08);
  href->GetXaxis()->SetTitle(xtitle.Data());
  href->GetYaxis()->SetTitleFont(42);
  href->GetYaxis()->SetLabelSize(0.045);
  href->GetYaxis()->SetTitleOffset(1.00);
  href->GetYaxis()->SetTitleSize(0.08);
  href->GetYaxis()->SetTitle(ytitle.Data());
  href->Draw();
}

void CanvasHandler::createRatioCanvas(int number=0, int xp=0, int yp=0, int x=800, int y=1000,
    double pleft=0.15, double pright=0.05, double ptop=0.0, double pbot=0.30, int optstat=0) {
    char name[100];
    snprintf(name,sizeof(name),"cc%d",number);
    TCanvas *c = new TCanvas(name,name,xp,yp,x,y);
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
    muppad->SetTopMargin(ptop);
    muppad->SetBottomMargin(0.0);
    muppad->SetLeftMargin(pleft);
    muppad->SetRightMargin(pright);
    muppad->Draw();
    muppad->cd();
    mtoppad->cd();
	snprintf(name,sizeof(name),"padd%d",number);	
    mlowpad = new TPad(name,name,0.01,0.01,0.99,0.35,0,0,0);
    mlowpad->SetTopMargin(0.0);
    mlowpad->SetBottomMargin(pbot);
    mlowpad->SetLeftMargin(pleft);
    mlowpad->SetRightMargin(pright);
    mlowpad->Draw();
    c->Modified();
    c->Update();
  //gSystem->ProcessEvents();
}

void CanvasHandler::drawPad(std::vector<HistogramData>& histograms, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  TH1F *hist = histograms[numpad].hist;
  gROOT->ProcessLine(Form("mpad%d_%d->cd()", numcan, numpad));
  if (doLog) gPad->SetLogy();
  this->drawRefHistogramWithPad(numcan, numpad, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  hist->Draw("same");
  gROOT->ProcessLine(Form("mpad%d_%d->Update()", numcan, numpad));
}

void CanvasHandler::drawPadCombined(std::vector<HistogramData>& histograms, bool withInc, bool withLeg, bool doLog, int numcan, int numpad, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  TLegend *leg = new TLegend(CANOPT::LEG[0], CANOPT::LEG[1], CANOPT::LEG[2], CANOPT::LEG[3]);
  int histSize = histograms.size();
  gROOT->ProcessLine(Form("mpad%d_%d->cd()", numcan, numpad));
  SetLegendBoxSize(leg, histSize, 0.65, 0.65, 0.10, 0.06);
  if (doLog) gPad->SetLogy();
  this->drawRefHistogramWithPad(numcan, numpad, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  std::vector<int> histogramOrder = {0, 2, 1, 3}; // Customize this order as needed
  //for (int i=0; i<histSize; i++) {
  for (int i : histogramOrder) {
    if (i==0 && !(withInc)) continue;
    TH1F *hist = histograms[i].hist;
    this->histColorStyle(hist, HfJetTagging::colorFlavour[i], i+20, CANOPT::MARKERSIZE, HfJetTagging::colorFlavour[i], 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("same");
  }
  if (withLeg) leg->Draw();
  gROOT->ProcessLine(Form("mpad%d_%d->Update()", numcan, numpad));
}

void CanvasHandler::drawPadMxNCombined(int numcan, int numpad_x, int numpad_y, std::vector<HistogramData>& histograms, bool withInc, bool doLog, bool withLeg, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  gStyle->SetTextFont(42);
  //gStyle->SetTextSize(0.01);
  TLegend *leg = new TLegend(CANOPT::LEG[0], CANOPT::LEG[1], CANOPT::LEG[2], CANOPT::LEG[3]);
  int histSize = histograms.size();
  gROOT->ProcessLine(Form("mpad%d_%d_%d->cd()", numcan, numpad_x, numpad_y));
  if (doLog) gPad->SetLogy();
  this->drawRefHistogramWithPadMxN(numcan, numpad_x, numpad_y, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());

  std::vector<int> histogramOrder = {0, 2, 1, 3}; // Customize this order as needed
  //for (int i=0; i<histSize; i++) {
  for (int i : histogramOrder) {
    if (i < 0 || i >= histSize) continue;
    if (i==0 && !(withInc)) continue;
    TH1F *hist = histograms[i].hist;
    this->histColorStyle(hist, HfJetTagging::colorFlavour[i], HfJetTagging::markerStyleFlavour[i], 1.8*HfJetTagging::markerSizeFlavour[i], HfJetTagging::colorFlavour[i], 1);
    TString clfi = histograms[i].classification;
    leg->AddEntry(hist, clfi.Data(), "lep");
    hist->Draw("samePE");
  }
  // for legend
  if (numpad_x==0) SetLegendBoxSize(leg, histSize, 0.73, 0.68, 0.075, 0.045); // for tc
  //if (numpad_x==0) SetLegendBoxSize(leg, histSize, 0.68, 0.50, 0.075, 0.045); // for jp
  //if (numpad_x==0) SetLegendBoxSize(leg, histSize, 0.68, 0.68, 0.075, 0.045); // for jp
  if (numpad_x==1) SetLegendBoxSize(leg, histSize, 0.55, 0.63, 0.075, 0.060);
  if (numpad_x==2) SetLegendBoxSize(leg, histSize, 0.70, 0.70, 0.10, 0.06);
  if (numpad_x==3) SetLegendBoxSize(leg, histSize, 0.70, 0.70, 0.10, 0.06);
  if (withLeg) leg->Draw();
  gROOT->ProcessLine(Form("mpad%d_%d_%d->Update()", numcan, numpad_x, numpad_y));
}

void CanvasHandler::drawUpperPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  gROOT->ProcessLine(Form("padu%d->cd()", number));
  gPad->SetLogy();
  this->drawRefHistogramWithPad(number, 0, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  h1->Draw("same");
  gROOT->ProcessLine(Form("padu%d->Update()", number));
}

void CanvasHandler::drawLowerPad(TH1F* h1, int number, double xmin, double xmax, double ymin=1.1, double ymax=1.1, TString xtitle="", TString ytitle="#frac{data}{MC}") {
  xmin= h1->FindBin(1);
  xmax= h1->FindBin(h1->GetNbinsX());
  gROOT->ProcessLine(Form("padd%d->cd()", number));
  this->drawRefHistogramWithPad(number, 1, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  h1->Draw("same");
  gROOT->ProcessLine(Form("padd%d->Update()", number));
}

//void latexDataJetInfo(double x=0.2, double y=0.9, int binJetPt=0, TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis") {
void latexDataJetInfo(double x=0.2, double y=0.9, int binJetPt=0, TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis", double textSize=0.036) {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  latex.SetTextFont(42);

  float textStep = 0.055;
  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
  latex.DrawLatex(x, y-textStep, "pp, #font[42]{#it{#sqrt{s}} = 13.6 TeV}");
  latex.DrawLatex(x, y-2*textStep, Form("%s,#it{ R} = %0.1f, %s-particle jets", jetAlgo.Data(), jetRadi, jetType.Data()));
  if (binJetPt < 0)  {
    latex.DrawLatex(x, y-3*textStep, "|#it{#eta}^{ch jet}| < 0.5");
  }
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-3*textStep, Form("#it{p}_{T}^{ch jet} > %d GeV/#it{c}, |#it{#eta}^{ch jet}| < 0.5", static_cast<int>(HfJetTagging::cutJetPt)));
  }
  if (binJetPt > 0) 
    latex.DrawLatex(x, y-3*textStep, Form("%d < #it{p}_{T}^{ch jet} < %d GeV/#it{c}, |#it{#eta}^{ch jet}| < 0.5", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
}

void latexSimJetInfo(double x=0.2, double y=0.9, int binJetPt=0, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis", double textSize=0.036) {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(textSize); // Set text size
  latex.SetTextFont(42);

  float textStep = 0.055/0.036 * textSize;
  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
  latex.DrawLatex(x, y-textStep, triggerName.Data());
  latex.DrawLatex(x, y-2*textStep, "pp, #font[42]{#it{#sqrt{s}} = 13.6 TeV}");
  latex.DrawLatex(x, y-3*textStep, Form("%s,#it{ R} = %0.1f, %s-particle jets", jetAlgo.Data(), jetRadi, jetType.Data()));
  if (binJetPt < 0)  {
    latex.DrawLatex(x, y-4*textStep, "|#it{#eta}^{ch jet}| < 0.5");
  }
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-4*textStep, Form("#it{p}_{T}^{ch jet} > %d GeV/#it{c}, |#it{#eta}^{ch jet}| < 0.5", static_cast<int>(HfJetTagging::cutJetPt)));
  }
  if (binJetPt > 0) {
    latex.DrawLatex(x, y-4*textStep, Form("%d < #it{p}_{T}^{ch jet} < %d GeV/#it{c}, |#it{#eta}^{ch jet}| < 0.5", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
}

void latexSimJetInfoForEffi(double x=0.2, double y=0.9, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis") {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  latex.SetTextFont(42);

  float textStep = 0.055;
  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
  latex.DrawLatex(x, y-textStep, triggerName.Data());
  latex.DrawLatex(x, y-2*textStep, "pp, #font[42]{#it{#sqrt{s}} = 13.6 TeV}");
  latex.DrawLatex(x, y-3*textStep, Form("%s,#it{ R} = %0.1f, %s-particle jets", jetAlgo.Data(), jetRadi, jetType.Data()));
  latex.DrawLatex(x, y-4*textStep, "|#it{#eta}_{jet}| < 0.5");
  //latex.DrawLatex(x, y-4*textStep, "#left| #it{#eta}_{jet} #right| < 0.5");
  //latex.DrawLatex(x, y-4*textStep, "#left| #it{#eta}_{jet} #right| #LT 0.5");
}

//void latexSimTrackInfo(double x=0.2, double y=0.9, int binTrackPt=0, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis") {
//  TLatex latex;
//  latex.SetNDC(); // Use normalized coordinates
//  latex.SetTextSize(0.03); // Set text size
//  latex.SetTextFont(42);
//
//  float textStep = 0.045;
//  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
//  latex.DrawLatex(x, y-textStep, triggerName.Data());
//  latex.DrawLatex(x, y-2*textStep, "pp, #font[42]{#it{#sqrt{s}} = 13.6 TeV}");
//  latex.DrawLatex(x, y-3*textStep, Form("%s, %s-particle jets", jetAlgo.Data(), jetType.Data()));
//  if (binJetPt == 0) {
//    latex.DrawLatex(x, y-4*textStep, Form("#it{p}_{T}^{ch jet} > %d GeV/#it{c}, #it{R} = %0.1f", static_cast<int>(HfJetTagging::cutJetPt),jetRadi));
//  }
//  if (binJetPt > 0) latex.DrawLatex(x, y-4*textStep, Form("%d < #it{p}_{T}^{ch jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
//  latex.DrawLatex(x, y-5*textStep, "|#it{#eta}^{ch jet}| < 0.5");
//  latex.DrawLatex(x, y-6*textStep, "#it{p}_{T}^{track} > 0.15 GeV/#it{c}");
//  //latex.DrawLatex(x, y-0.20, "constituents in jets");
//}

void latexSimJetInfoForTC(double x=0.2, double y=0.9, int binJetPt=0, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis") {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextFont(42);
  latex.SetTextSize(0.045); // Set text size

  float textStep = 0.060;
  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
  latex.DrawLatex(x, y-textStep, triggerName.Data());
  latex.DrawLatex(x, y-2*textStep, "pp, #font[42]{#sqrt{#it{s}} = 13.6 TeV}");
  latex.DrawLatex(x, y-3*textStep, Form("%s, %s-particle jets", jetAlgo.Data(), jetType.Data()));
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-4*textStep, Form("#it{p}_{T}^{ch jet} > %d GeV/#it{c}, #it{R} = %0.1f", static_cast<int>(HfJetTagging::cutJetPt),jetRadi));
  }
  if (binJetPt > 0) latex.DrawLatex(x, y-4*textStep, Form("%d < #it{p}_{T}^{ch jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  latex.DrawLatex(x, y-5*textStep, "|#it{#eta}^{ch jet}| < 0.5");
  latex.DrawLatex(x, y-6*textStep, "#it{p}_{T}^{track} > 0.15 GeV/#it{c}");
  //latex.DrawLatex(x, y-0.20, "constituents in jets");
}

void latexSimJetInfoForJP(double x=0.2, double y=0.9, int binJetPt=0, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis") {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextFont(42);
  latex.SetTextSize(0.045); // Set text size

  float textStep = 0.060;
  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
  latex.DrawLatex(x, y-textStep, triggerName.Data());
  latex.DrawLatex(x, y-2*textStep, "pp, #font[42]{#sqrt{#it{s}} = 13.6 TeV}");
  latex.DrawLatex(x, y-3*textStep, Form("%s, %s-particle jets", jetAlgo.Data(), jetType.Data()));
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-4*textStep, Form("#it{p}_{T}^{ch jet} > %d GeV/#it{c}, #it{R} = %0.1f", static_cast<int>(HfJetTagging::cutJetPt),jetRadi));
  }
  if (binJetPt > 0) latex.DrawLatex(x, y-4*textStep, Form("%d < #it{p}_{T}^{ch jet} < %d", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  latex.DrawLatex(x, y-5*textStep, "|#it{#eta}^{ch jet}| < 0.5");
  latex.DrawLatex(x, y-6*textStep, "#it{p}_{T}^{track} > 0.15 GeV/#it{c}");
  //latex.DrawLatex(x, y-0.20, "constituents in jets");
}

void latexSimJetInfoForSV(double x=0.2, double y=0.9, int binJetPt=0, TString triggerName="", TString jetAlgo = "Anti-#it{k}_{T}", TString jetType="Charged", float jetRadi=0.4, TString aliceFig="this analysis") {
  TLatex latex;
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.036); // Set text size
  latex.SetTextFont(42);

  float textStep = 0.055;
  latex.DrawLatex(x, y, Form("%s", aliceFig.Data()));
  latex.DrawLatex(x, y-textStep, triggerName.Data());
  latex.DrawLatex(x, y-2*textStep, "pp, #font[42]{#it{#sqrt{s}} = 13.6 TeV}");
  latex.DrawLatex(x, y-3*textStep, Form("%s,#it{ R} = %0.1f, %s-particle jets", jetAlgo.Data(), jetRadi, jetType.Data()));
  if (binJetPt == 0) {
    latex.DrawLatex(x, y-4*textStep, Form("#it{p}_{T}^{ch jet} > %d GeV/#it{c}, |#it{#eta}^{ch jet} < 0.5|", static_cast<int>(HfJetTagging::cutJetPt)));
  }
  if (binJetPt > 0) {
    latex.DrawLatex(x, y-4*textStep, Form("%d < #it{p}_{T}^{ch jet} < %d GeV/#it{c}, |#it{#eta}^{ch jet}| < 0.5", static_cast<int>(HfJetTagging::binsJetPt[binJetPt-1]), static_cast<int>(HfJetTagging::binsJetPt[binJetPt])));
  }
  //latex.DrawLatex(x, y-6*textStep, "DCA_{xy} > 0.008 cm, CHI2PCA < 4");
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

void SetLegendBoxSize(TLegend *legend, int numGraphs, double xpoint=0.6, double ypoint=0.6, double boxWidthFactor=0.05, double boxHeightFactor=0.03) {
  //double boxWidthFactor = 0.05;
  //double boxHeightFactor = 0.03;

  legend->SetTextFont(42);
//  TList *legendEntries = legend->GetListOfPrimitives();
//  if (!legendEntries) {
//    std::cout << "Legend is empty!" << std::endl;
//    return;
//  }
//
//  // Iterate over legend entries
//  for (int i = 0; i < legendEntries->GetSize(); ++i) {
//    TObject *obj = legendEntries->At(i);
//    if (!obj) {
//      std::cout << "Null entry found in legend!" << std::endl;
//      continue;
//    }
//
//    // Check if the entry is of type TLegendEntry
//    if (obj->InheritsFrom(TLegendEntry::Class())) {
//      TLegendEntry *entry = (TLegendEntry*)obj;
//      const char *label = entry->GetLabel();
//      //std::cout << "Legend entry label: " << label << std::endl;
//      //std::cout << "Legend entry makerstyle: " << entry->GetMarkerStyle() << std::endl;
//      //std::cout << "Legend entry makersize: " << entry->GetMarkerSize() << std::endl;
//      //std::cout << "Legend entry makercolor: " << entry->GetMarkerColor() << std::endl;
//      entry->SetTextSize(0.045);
//      entry->SetTextFont(42);
//    } else {
//      std::cout << "Non-legend entry found in legend!" << std::endl;
//    }
//  }

  double boxWidth = boxWidthFactor * numGraphs;
  double boxHeight = 1.2*boxHeightFactor * numGraphs;
  legend->SetFillColor(kWhite);

  legend->SetBorderSize(0);
  legend->SetFillColor(0);
  legend->SetFillStyle(0);
  legend->SetMargin(0.2);

  legend->SetX1(xpoint);
  legend->SetY1(ypoint);
  //legend->SetX1(0.65);
  //legend->SetY1(0.65);
  legend->SetX2(xpoint + boxWidth);
  legend->SetY2(ypoint + boxHeight);

  legend->SetTextSize(boxHeightFactor);
  //legend->SetTextSize(1.0*boxHeightFactor);
}


#endif // CANVASHANDLER_H
