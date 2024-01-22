#include <TCanvas.h>
#include <TPad.h>
#include <TH2D.h>
#include <TString.h>
#include <TSystem.h>

class CanvasHandler {
  public:
    CanvasHandler();
    ~CanvasHandler();

    void createCanvas(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void DrawRefHistogram(int number, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);
    void createRatioCanvas(int number, int xp, int yp, int x, int y, double pleft, double pright, double ptop, double pbot);
    void drawUpperPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);
    void drawLowerPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle);

  private:
    TCanvas* canvas;
    TPad* mpad;
    TPad* mtoppad;
    TPad* muppad;
    TPad* mlowpad;
};

CanvasHandler::CanvasHandler() {
}

CanvasHandler::~CanvasHandler() {
  if (canvas) delete canvas;
  if (mpad) delete mpad;
}

void CanvasHandler::createCanvas(int number=0, int xp=0, int yp=0, int x=400, int y=400,
    double pleft=0.17, double pright=0.1, double ptop=0.1, double pbot=0.13) {
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
    mpad = new TPad(name, name, 0.02, 0.02, 0.99, 0.99, 0, 0, 0);
    mpad->SetTopMargin(ptop);
    mpad->SetBottomMargin(pbot);
    mpad->SetLeftMargin(pleft);
    mpad->SetRightMargin(pright);
    mpad->Range(0, 0, 1, 1);
    mpad->SetLogz(1);
    mpad->Draw();
    mpad->cd();
    canvas->Modified();
    canvas->Update();
  } else {
    mpad = dynamic_cast<TPad*>(canvas->GetListOfPrimitives()->FindObject(Form("mpad%d", number)));
    if (mpad) {
      canvas->cd();
      mpad->cd();
      canvas->Modified();
      canvas->Update();
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
  href->GetXaxis()->SetTitle(xtitle.Data());
  href->GetYaxis()->SetTitle(ytitle.Data());
  href->Draw();
}

void CanvasHandler::createRatioCanvas(int number=0, int xp=0, int yp=0, int x=400, int y=400,
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
}

void CanvasHandler::drawUpperPad(TH1F* h1, int number, double xmin, double xmax, double ymin, double ymax, TString xtitle, TString ytitle) {
  gROOT->ProcessLine(Form("padu%d->cd()", number));
  this->DrawRefHistogram(number, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  h1->Draw("same");
  gROOT->ProcessLine(Form("padu%d->Update()", number));
}

void CanvasHandler::drawLowerPad(TH1F* h1, int number, double xmin, double xmax, double ymin=1.1, double ymax=1.1, TString xtitle="", TString ytitle="#frac{data}{MC}") {
  xmin= h1->FindBin(1);
  xmax= h1->FindBin(h1->GetNbinsX());
  gROOT->ProcessLine(Form("padd%d->cd()", number));
  this->DrawRefHistogram(number, xmin, xmax, ymin, ymax, xtitle.Data(), ytitle.Data());
  h1->Draw("same");
  gROOT->ProcessLine(Form("padd%d->Update()", number));
}
