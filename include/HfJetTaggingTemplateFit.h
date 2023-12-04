#ifndef HFJETTAGGINGTEMPLATEFIT_H
#define HFJETTAGGINGTEMPLATEFIT_H

#include <TString.h>
#include "HfJetTaggingAnalysis.h"
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"

class HfJetTaggingTemplateFit : public HfJetTaggingAnalysis {
  public:
    HfJetTaggingTemplateFit(const TString &rootFile, const TString &taskName, bool doMC) : HfJetTaggingAnalysis(rootFile, taskName, doMC){
    }
    HfJetTaggingTemplateFit(const TString &rootFile, const TString &taskName, bool doMC, const TString &cutSelection) : HfJetTaggingAnalysis(rootFile, taskName, doMC, cutSelection){
    }
    ~HfJetTaggingTemplateFit();
    void TemplateFit();
    void Fit();

  private:

};

void HfJetTaggingTemplateFit::TemplateFit(){
  RooRealVar jetProb("jetProb", "Jet Probaility", 0, 10);

}

void HfJetTaggingTemplateFit::Fit(){
  RooRealVar jetProb("jetProb", "Jet Probaility", 0, 10);

  RooDataHist mcincjetJPLog("mcincjetJPLog", "Data Hist", jetProb, RooFit::Import(*hsimincjetJPLog)); // FIXME: I should to change experimenta data from mc which is data driven method
  RooDataHist mclfjetJPLog("mclfjetJPLog", "Data Hist", jetProb, RooFit::Import(*hsimlfjetJPLog));
  RooDataHist mccjetJPLog("mccjetJPLog", "Data Hist", jetProb, RooFit::Import(*hsimcjetJPLog));
  RooDataHist mcbjetJPLog("mcbjetJPLog", "Data Hist", jetProb, RooFit::Import(*hsimbjetJPLog));

  // Create a histogram PDF using the data histogram
  RooHistPdf histPdflfjetJPLog("histPdflfjetJPLog", "Histogram PDF", jetProb, mclfjetJPLog, 10);
  RooHistPdf histPdfcjetJPLog("histPdfcjetJPLog", "Histogram PDF", jetProb, mccjetJPLog, 10);
  RooHistPdf histPdfbjetJPLog("histPdfbjetJPLog", "Histogram PDF", jetProb, mcbjetJPLog, 10);

  // Define relative normalization factors for signal, background, and secondary background
  RooRealVar lfjetJPLogYield("lfjetJPLogYield", "Signal Yield", hsimlfjetJPLog->Integral(), 0, mclfjetJPLog.sumEntries());
  RooRealVar cjetJPLogYield("cjetJPLogYield", "Background Yield", hsimcjetJPLog->Integral(), 0, mccjetJPLog.sumEntries());
  RooRealVar bjetJPLogYield("bjetJPLogYield", "Secondary Background Yield", hsimbjetJPLog->Integral(), 0, mcbjetJPLog.sumEntries());

  // Perform the fit to the data
  RooAddPdf model("model", "Total PDF", RooArgList(histPdflfjetJPLog, histPdfcjetJPLog, histPdfbjetJPLog), RooArgList(lfjetJPLogYield, cjetJPLogYield, bjetJPLogYield));
  //RooAddPdf model("model", "Total PDF", RooArgList(histPdflfjetJPLog, histPdfcjetJPLog, histPdfbjetJPLog));

  //RooFitResult* fitResultlfjetJPLog = histPdflfjetJPLog.fitTo(mclfjetJPLog, RooFit::Save(true));
  RooFitResult* fitResult = model.fitTo(mcincjetJPLog, RooFit::Save(true));

  // Print fit results
  //fitResult->Print();

  //  // Plot the data and the fit result
  //RooPlot* frame = jetProb.frame();
  //mclfjetJPLog.plotOn(frame);
  //histPdflfjetJPLog.plotOn(frame);
  RooPlot* frame = jetProb.frame();
  mcincjetJPLog.plotOn(frame);
  model.plotOn(frame);

  model.plotOn(frame, RooFit::Components("histPdflfjetJPLog"), RooFit::LineStyle(kDashed), RooFit::LineColor(kRed));
  model.plotOn(frame, RooFit::Components("histPdfcjetJPLog"), RooFit::LineStyle(kDashed), RooFit::LineColor(kGreen));
  model.plotOn(frame, RooFit::Components("histPdfbjetJPLog"), RooFit::LineStyle(kDashed), RooFit::LineColor(kBlue));

  // Draw the frame
  TCanvas canvas("canvas", "Template Fit");
  gPad->SetLogy();
  frame->Draw();
  canvas.SaveAs("template_fit.png");

  //RooDataSet* generatedData = histPdf.generate(jetProb, 1);
  //generatedData->Print();
  //RooHist *fittedHist = frame->getHist();

  //RooAddPdf model ("model", "bjet template", R);
  //RooDataHist data("data", "dataset with x", x, hsimbjetNormalizedJP);
}

//void HfJetTaggingTemplateFit::bjetTemplateFit() {
//
//}

#endif // HFJETTAGGINGTEMPLATEFIT_H

