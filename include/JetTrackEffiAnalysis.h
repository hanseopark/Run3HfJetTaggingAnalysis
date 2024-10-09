#ifndef JETTRACKEFFIANALYSIS_H
#define JETTRACKEFFIANALYSIS_H

#include <TH1.h>
#include <TString.h>
#include "DataPoint.h"
#include "CanvasHandler.h"

// TODO::
// data and particle level projection name is not perfect

class JetTrackEffiAnalysis {
  public:
    JetTrackEffiAnalysis() {
      initConfig();
    }

    ~JetTrackEffiAnalysis();

    // function
    void initConfig();
    int loadSimGeneralTrackEffiQA(TString rootSim);
    void initHistogramForNormalizationGeneralTrackEffiQAMC();
    void projectionHistGeneralTrackEffiQAMC();
    void saveHistogramGeneralTrackEffiQA(TString rootFile);

    /// Set
    void setFillData(bool fillData);
    void setFillMC(bool fillMC);

    // Draw option
    void drawSimGenJetPartPt(bool doLog);
    void drawSimGenJetTrackPt(bool doLog);
    void drawTrackEffi();

    // histogram from root file
    /// DATA
    /// MCD
    TH1F* hsimGenJetTrackPt;
    TH1F* hsimGenJetPartclePt;

  protected:
    // draw option
    int cn=0;
    CanvasHandler* canHan;

    // histogram
    /// Data

    /// MC
    TH1F* hMcCollCutsConts;
    TH1F* hMcPartCutsConts;
    TH1F* hTrackCutsConts;
    TH3F* h3PartPtPartEtaPartPhi;
    TH3F* h3TrackPtTrackEtaTrackPhiNoAsso;
    TH3F* h3TrackPtTrackEtaTrackPhiAssoPrimary;
    TH3F* h3TrackPtTrackEtaTrackPhiAssoNonPrimary;
    TH3F* h3TrackPtTrackEtaTrackPhiAssoSplit;
    TH3F* h3PartPtPartEtaPartPhiAssoPrimary;
    TH3F* h3PartPtPartEtaPartPhiAssoNonPrimary;
    TH3F* h3PartPtPartEtaPartPhiAssoSplit;

    // normalized histogram
    /// MC
    TH1F* hPartPt;
    TH1F* hTrackPtAssoPrimary; 
    TH1F* hTrackPtAssoNonPrimary; 
    TH1F* hTrackPtAssoSplit; 
    TH1F* hPartPtAssoPrimary;
    TH1F* hPartPtAssoNonPrimary;
    TH1F* hPartPtAssoSplit;

  private:
    TLatex latex;
    TString dirData;
    TString dirSim;
    TString dirDataVsSim;
    bool fillData = false;
    bool fillMC = false;

};

JetTrackEffiAnalysis::~JetTrackEffiAnalysis() {
}

void JetTrackEffiAnalysis::initConfig() {
  latex.SetNDC(); // Use normalized coordinates
  latex.SetTextSize(0.03); // Set text size
  latex.SetTextFont(42);
  dirData = Form("fig/%s/data/%s/trkeffi", SOURCESET.Data(), DATASET.Data());
  dirSim = Form("fig/%s/sim/%s/trkeffi", SOURCESET.Data(), SIMSET.Data());
  dirDataVsSim = Form("fig/%s/dataVSsim/%s_%s/trkeffi", SOURCESET.Data(), DATASET.Data(), SIMSET.Data());
  gSystem->mkdir(dirData, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirSim, kTRUE); // kTRUE: create parent directories if they don't exist
  gSystem->mkdir(dirDataVsSim, kTRUE); // kTRUE: create parent directories if they don't exist
}

int JetTrackEffiAnalysis::loadSimGeneralTrackEffiQA(TString rootSim) {
  if (gSystem->AccessPathName(rootSim.Data())) {
    std::cout << "Input file (MC) not found!" << std::endl;
    return 0;
  }

  TFile* fin;
  fin = TFile::Open(rootSim.Data(), "READ");
  TString task = "track-efficiency";

  h3PartPtPartEtaPartPhi = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_particle_pt_particle_eta_particle_phi_mcpartofinterest", task.Data())));
  h3TrackPtTrackEtaTrackPhiNoAsso = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_track_pt_track_eta_track_phi_noassociatedtrack", task.Data())));
  h3TrackPtTrackEtaTrackPhiAssoPrimary = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_track_pt_track_eta_track_phi_associatedtrack_primary", task.Data())));
  h3TrackPtTrackEtaTrackPhiAssoNonPrimary = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_track_pt_track_eta_track_phi_associatedtrack_nonprimary", task.Data())));
  h3TrackPtTrackEtaTrackPhiAssoSplit = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_track_pt_track_eta_track_phi_associatedtrack_split", task.Data())));
  h3PartPtPartEtaPartPhiAssoPrimary = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_particle_pt_particle_eta_particle_phi_associatedtrack_primary", task.Data())));
  h3PartPtPartEtaPartPhiAssoNonPrimary = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_particle_pt_particle_eta_particle_phi_associatedtrack_nonprimary", task.Data())));
  h3PartPtPartEtaPartPhiAssoSplit = reinterpret_cast<TH3F*> (fin->Get(Form("%s/h3_particle_pt_particle_eta_particle_phi_associatedtrack_split", task.Data())));

  std::cout << "Load completed track efficiency task" << std::endl;
  return 1;
}

void JetTrackEffiAnalysis::initHistogramForNormalizationGeneralTrackEffiQAMC() {
  hPartPt = new TH1F("hPartPt", "", h3PartPtPartEtaPartPhi->GetNbinsX(), h3PartPtPartEtaPartPhi->GetXaxis()->GetBinLowEdge(1), h3PartPtPartEtaPartPhi->GetXaxis()->GetBinUpEdge(h3PartPtPartEtaPartPhi->GetNbinsX()));
  hTrackPtAssoPrimary = new TH1F("hTrackPtAssoPrimary", "", h3TrackPtTrackEtaTrackPhiAssoPrimary->GetNbinsX(), h3TrackPtTrackEtaTrackPhiAssoPrimary->GetXaxis()->GetBinLowEdge(1), h3TrackPtTrackEtaTrackPhiAssoPrimary->GetXaxis()->GetBinUpEdge(h3TrackPtTrackEtaTrackPhiAssoPrimary->GetNbinsX()));
  hTrackPtAssoNonPrimary = new TH1F("hTrackPtAssoNonPrimary", "", h3TrackPtTrackEtaTrackPhiAssoNonPrimary->GetNbinsX(), h3TrackPtTrackEtaTrackPhiAssoNonPrimary->GetXaxis()->GetBinLowEdge(1), h3TrackPtTrackEtaTrackPhiAssoNonPrimary->GetXaxis()->GetBinUpEdge(h3TrackPtTrackEtaTrackPhiAssoNonPrimary->GetNbinsX()));
  hTrackPtAssoSplit = new TH1F("hTrackPtAssoSplit", "", h3TrackPtTrackEtaTrackPhiAssoSplit->GetNbinsX(), h3TrackPtTrackEtaTrackPhiAssoSplit->GetXaxis()->GetBinLowEdge(1), h3TrackPtTrackEtaTrackPhiAssoSplit->GetXaxis()->GetBinUpEdge(h3TrackPtTrackEtaTrackPhiAssoSplit->GetNbinsX()));
  hPartPtAssoPrimary = new TH1F("hPartPtAssoPrimary", "", h3PartPtPartEtaPartPhiAssoPrimary->GetNbinsX(), h3PartPtPartEtaPartPhiAssoPrimary->GetXaxis()->GetBinLowEdge(1), h3PartPtPartEtaPartPhiAssoPrimary->GetXaxis()->GetBinUpEdge(h3PartPtPartEtaPartPhiAssoPrimary->GetNbinsX()));
  hPartPtAssoNonPrimary = new TH1F("hPartPtAssoNonPrimary", "", h3PartPtPartEtaPartPhiAssoNonPrimary->GetNbinsX(), h3PartPtPartEtaPartPhiAssoNonPrimary->GetXaxis()->GetBinLowEdge(1), h3PartPtPartEtaPartPhiAssoNonPrimary->GetXaxis()->GetBinUpEdge(h3PartPtPartEtaPartPhiAssoNonPrimary->GetNbinsX()));
  hPartPtAssoSplit = new TH1F("hPartPtAssoSplit", "", h3PartPtPartEtaPartPhiAssoSplit->GetNbinsX(), h3PartPtPartEtaPartPhiAssoSplit->GetXaxis()->GetBinLowEdge(1), h3PartPtPartEtaPartPhiAssoSplit->GetXaxis()->GetBinUpEdge(h3PartPtPartEtaPartPhiAssoSplit->GetNbinsX()));
}

void JetTrackEffiAnalysis::projectionHistGeneralTrackEffiQAMC() {
  TH1F* projPartPt = (TH1F*) h3PartPtPartEtaPartPhi->ProjectionX("projPartPt", 1, h3PartPtPartEtaPartPhi->GetNbinsY(), 1, h3PartPtPartEtaPartPhi->GetNbinsZ());
  TH1F* projTrackPtAssoPrimary = (TH1F*) h3TrackPtTrackEtaTrackPhiAssoPrimary->ProjectionX("projTrackPtAssoPrimary", 1, h3TrackPtTrackEtaTrackPhiAssoPrimary->GetNbinsY(), 1, h3TrackPtTrackEtaTrackPhiAssoPrimary->GetNbinsZ());
  TH1F* projTrackPtAssoNonPrimary = (TH1F*) h3TrackPtTrackEtaTrackPhiAssoNonPrimary->ProjectionX("projTrackPtAssoNonPrimary", 1, h3TrackPtTrackEtaTrackPhiAssoNonPrimary->GetNbinsY(), 1, h3TrackPtTrackEtaTrackPhiAssoNonPrimary->GetNbinsZ());
  TH1F* projTrackPtAssoSplit = (TH1F*) h3TrackPtTrackEtaTrackPhiAssoSplit->ProjectionX("projTrackPtAssoSplit", 1, h3TrackPtTrackEtaTrackPhiAssoSplit->GetNbinsY(), 1, h3TrackPtTrackEtaTrackPhiAssoSplit->GetNbinsZ());
  TH1F* projPartPtAssoPrimary = (TH1F*) h3PartPtPartEtaPartPhiAssoPrimary->ProjectionX("projPartPtAssoPrimary", 1, h3PartPtPartEtaPartPhiAssoPrimary->GetNbinsY(), 1, h3PartPtPartEtaPartPhiAssoPrimary->GetNbinsZ());
  TH1F* projPartPtAssoNonPrimary = (TH1F*) h3PartPtPartEtaPartPhiAssoNonPrimary->ProjectionX("projPartPtAssoNonPrimary", 1, h3PartPtPartEtaPartPhiAssoNonPrimary->GetNbinsY(), 1, h3PartPtPartEtaPartPhiAssoNonPrimary->GetNbinsZ());
  TH1F* projPartPtAssoSplit = (TH1F*) h3PartPtPartEtaPartPhiAssoSplit->ProjectionX("projPartPtAssoSplit", 1, h3PartPtPartEtaPartPhiAssoSplit->GetNbinsY(), 1, h3PartPtPartEtaPartPhiAssoSplit->GetNbinsZ());

  hPartPt = reinterpret_cast<TH1F*>(projPartPt->Clone("hPartPt"));
  hTrackPtAssoPrimary = reinterpret_cast<TH1F*>(projTrackPtAssoPrimary->Clone("hTrackPtAssoPrimary"));
  hTrackPtAssoNonPrimary = reinterpret_cast<TH1F*>(projTrackPtAssoNonPrimary->Clone("hTrackPtAssoNonPrimary"));
  hTrackPtAssoSplit = reinterpret_cast<TH1F*>(projTrackPtAssoSplit->Clone("hTrackPtAssoSplit"));
  hPartPtAssoPrimary = reinterpret_cast<TH1F*>(projPartPtAssoPrimary->Clone("hPartPtAssoPrimary"));
  hPartPtAssoNonPrimary = reinterpret_cast<TH1F*>(projPartPtAssoNonPrimary->Clone("hPartPtAssoNonPrimary"));
  hPartPtAssoSplit = reinterpret_cast<TH1F*>(projPartPtAssoSplit->Clone("hPartPtAssoSplit"));
}

void JetTrackEffiAnalysis::saveHistogramGeneralTrackEffiQA(TString rootFile) {
  TFile* fout = new TFile(rootFile.Data(), "RECREATE");

  // Check if the file is open successfully
  if (!fout || !fout->IsOpen()) {
    std::cout << "Error: Could not open the ROOT file for writing." << std::endl;
    return;
  }

  // Create or retrieve the directory
  TDirectory* dir;

  dir = fout->GetDirectory("sim");
  if (!dir) {
    dir = fout->mkdir("sim");
    dir->cd();
    hPartPt->Write();
    hTrackPtAssoPrimary->Write();
    hTrackPtAssoNonPrimary->Write();
    hTrackPtAssoSplit->Write();
    hPartPtAssoPrimary->Write();
    hPartPtAssoNonPrimary->Write();
    hPartPtAssoSplit->Write();
  }

  delete fout;
}

// Set function
void JetTrackEffiAnalysis::setFillData(bool mfillData) {
  fillData = mfillData;
  if (fillData) {
    std::cout << "Fill Data ON " << std::endl;
  }
}

void JetTrackEffiAnalysis::setFillMC(bool mfillMC) {
  fillMC = mfillMC;
  if (fillMC) {
    std::cout << "Fill MC ON" << std::endl;
  }
}

// Draw function

// MC
void JetTrackEffiAnalysis::drawTrackEffi() {
  TH1F* heffi;
  int rebinNum = 4;
  hPartPt->Rebin(rebinNum);
  hPartPtAssoPrimary->Rebin(rebinNum);
  std::cout << "part ent: " << hPartPt->GetEntries() << std::endl;
  std::cout << "det ent: " << hPartPtAssoPrimary->GetEntries() << std::endl;
  heffi = (TH1F*) hPartPt->Clone();
  heffi->Divide(hPartPtAssoPrimary);
	std::vector<HistogramData> histList;
	histList.push_back({heffi, ""});
  canHan = new CanvasHandler();
  canHan->createCanvas(cn);
  canHan->drawRefHistogram(cn, GeneralJet::REFHIST::TRACKEFFI[0], GeneralJet::REFHIST::TRACKEFFI[1], GeneralJet::REFHIST::TRACKEFFI[2], GeneralJet::REFHIST::TRACKEFFI[3], "#it{p}_{T}", "#epsilon");
  canHan->drawCombined(histList.size(), histList, true, false, GeneralJet::LEG[0], GeneralJet::LEG[1], GeneralJet::LEG[2], GeneralJet::LEG[3]);
  gROOT->ProcessLine(Form("cc%d->Print(\"%s/trackEffiAssoPrimary.pdf\")", cn++, dirSim.Data()));
}

#endif // JETTRACKEFFIANALYSIS_H
