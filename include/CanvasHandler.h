#include <TCanvas.h>
#include <TPad.h>
#include <TH2D.h>
#include <TString.h>
#include <TSystem.h>

class CanvasHandler {
  public:
    CanvasHandler(int number = 0, int xp = 0, int yp = 0, int x = 400, int y = 400,
        double pleft = 0.17, double pright = 0.1, double ptop = 0.1, double pbot = 0.13);
    ~CanvasHandler();

    void DrawRefHistogram(int number, double xmin, double xmax, double ymin, double ymax,
        TString xtitle, TString ytitle);

  private:
    TCanvas* canvas;
    TPad* mpad;
};

CanvasHandler::CanvasHandler(int number, int xp, int yp, int x, int y,
    double pleft, double pright, double ptop, double pbot) {
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

CanvasHandler::~CanvasHandler() {
  if (canvas) delete canvas;
  if (mpad) delete mpad;
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

