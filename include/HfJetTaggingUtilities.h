#ifndef HFJETTAGGINGUTILITIES_H
#define HFJETTAGGINGUTILITIES_H

#include "TH1D.h"
#include "TString.h"
#include "DataPoint.h"
#include "CanvasHandler.h"

class FinalTaggerResult {
  public:
//    void setEffiIPN1(float meffiIPN1) effiIPN1 = meffiIPN1;
//    void setEffiIPN2(float meffiIPN2) effiIPN2 = meffiIPN2;
//    void setEffiIPN3(float meffiIPN3) effiIPN3 = meffiIPN3;
//    void setPurityIPN1(float mPurityIPN1) purityIPN1 = mPurityIPN1;
//    void setPurityIPN2(float mPurityIPN2) purityIPN2 = mPurityIPN2;
//    void setPurityIPN3(float mPurityIPN3) purityIPN3 = mPurityIPN3;
//    void setEffiSV(float meffiSV) effiSV = meffiSV;
//    void setPuritySV(float mpuritySV) puritySV = mpuritySV;
    int loadIPQA(TString rootFile, TString taskName);

  private:
    float effiIPN1 = -1.0;
    float effiIPN2 = -1.0;
    float effiIPN3 = -1.0;
    float purityIPN1 = -1.0;
    float purityIPN2 = -1.0;
    float purityIPN3 = -1.0;
    float effiSV = -1.0;
    float puritySV = -1.0;

    // histList
    TH1F* hdataJetPt;
    TH1F* hdataEffiIPN1;
    TH1F* hdataEffiIPN2;
    TH1F* hdataEffiIPN3;
    TH1F* hdataPurityIPN1;
    TH1F* hdataPurityIPN2;
    TH1F* hdataPurityIPN3;

};

int FinalTaggerResult::loadIPQA(TString rootFile, TString taskName) {
  if (gSystem->AccessPathName(rootFile.Data())) {
    std::cout << "Input file (General Flavour QA) not found!" << std::endl;
    return 0;
  }
  //TFile* fin;
  //fin = TFile::Open(rootData.Data(), "READ");
  return 1;
}

namespace taggingutilities {
  float getEfficiency(TH1F* htagjet, TH1F* huntaggedjet) {
    // it needs code defence
    int numOfbJetBeforeTagger = huntaggedjet->Integral(1, huntaggedjet->GetNbinsX());
    int numOfbJetAfterTagger = htagjet->Integral(1, htagjet->GetNbinsX());
    if (numOfbJetBeforeTagger==0) return -1;
    float effi = static_cast<float>((float)numOfbJetAfterTagger / numOfbJetBeforeTagger);
    std::cout << "[effi] before jet entries: " << numOfbJetBeforeTagger << " after jet entries: " << numOfbJetAfterTagger << " effi: " << effi << std::endl;
    return effi;
  }

  float getPurity(TH1F* hNegLogJPTaggedbJet, TH1F* hNegLogJPTaggedIncJet) {
    // it needs defence
    int numOfbjet = hNegLogJPTaggedbJet->Integral(1, hNegLogJPTaggedbJet->GetNbinsX());
    int numOfincjet = hNegLogJPTaggedIncJet->Integral(1, hNegLogJPTaggedIncJet->GetNbinsX());
    if (numOfincjet == 0 ) return -1;
    float purity = static_cast<float>((float)numOfbjet/numOfincjet);
    std::cout << "[purity] b jet entries: " << numOfbjet << " inc jet entries: " << numOfincjet << " purity: " << purity <<std::endl;
    return purity;
  }

  float getErrorEfficiency(TH1F* htagjet, TH1F* huntaggedjet) {
    int numOfbJetBeforeTagger = huntaggedjet->Integral(1, huntaggedjet->GetNbinsX());
    int numOfbJetAfterTagger = htagjet->Integral(1, htagjet->GetNbinsX());

    if (numOfbJetBeforeTagger == 0 || numOfbJetAfterTagger == 0) return -1;

    float effi = static_cast<float>(numOfbJetAfterTagger) / numOfbJetBeforeTagger;
    float errorEffi = effi * std::sqrt((1.0 / numOfbJetAfterTagger) + (1.0 / numOfbJetBeforeTagger));

    //std::cout << "[effi] before jet entries: " << numOfbJetBeforeTagger << " after jet entries: " << numOfbJetAfterTagger << " efficiency: " << effi << " error: " << errorEffi << std::endl;

    return errorEffi;
  }

  float getErrorPurity(TH1F* hNegLogJPTaggedbJet, TH1F* hNegLogJPTaggedIncJet) {
    int numOfbjet = hNegLogJPTaggedbJet->Integral(1, hNegLogJPTaggedbJet->GetNbinsX());
    int numOfincjet = hNegLogJPTaggedIncJet->Integral(1, hNegLogJPTaggedIncJet->GetNbinsX());

    if (numOfincjet == 0 || numOfbjet == 0) return -1;

    float purity = static_cast<float>(numOfbjet) / numOfincjet;
    float errorPurity = purity * std::sqrt((1.0 / numOfbjet) + (1.0 / numOfincjet));

    //std::cout << "[purity] b jet entries: " << numOfbjet << " inc jet entries: " << numOfincjet << " purity: " << purity << " error: " << errorPurity << std::endl;

    return errorPurity;
  }

  float getEfficiencyDirect(TH1F* huntagjet, TH1F* htagjet, int binJetPt, float cutSxy = 2.5) {
    int cuttagBin = htagjet->FindBin(cutSxy);
    TH1F* hrebinuntagjet = (TH1F*) huntagjet->Rebin(HfJetTagging::nBinsJetPt,"REBIN", HfJetTagging::binsJetPt);
    int numunTagjet = hrebinuntagjet->GetBinContent(binJetPt);
    int numcutTagjet = htagjet->Integral(cuttagBin, htagjet->GetNbinsX());

    std::cout << "jet Pt: " << HfJetTagging::binsJetPt[binJetPt] << " # of unttagged b-jet: " << numunTagjet << " # of tagjet b-jet: " << numcutTagjet << std::endl;
    float effi = -1;
    // Check if numTagjet is not zero to avoid division by zero
    if (numunTagjet != 0) {
      effi = static_cast<float> ((float) numcutTagjet / (float) numunTagjet);
      // It's still a good idea to check if the efficiency is within expected bounds
      if (effi < 0 || effi > 1) {
        std::cout << "Warning: Efficiency is over 1 or less than 0, " << effi << std::endl;
        effi = -1; // Or handle this case as needed
      }
    } else {
      std::cout << "Warning: Total number of tag jets is zero, efficiency is undefined." << std::endl;
    }
    if (std::isnan(effi)) return -1;
    return effi;
  }

  float getPurityDirect(int specificFlavour, int binJetPt, TH1F* hbasejet[][HfJetTagging::nBinsJetPt+1], float cutImp = 2.5) {
    if (specificFlavour <= 0 || specificFlavour > HfJetTagging::nFlavour) {
      std::cerr << "Invalid specific flavour provided." << std::endl;
      return -1;
    }
    if (binJetPt < 0 || binJetPt > HfJetTagging::nBinsJetPt) {
      std::cerr << "Invalid jet pt provided." << std::endl;
      return -1;
    }

    int binTargetjet = hbasejet[specificFlavour][binJetPt]->FindBin(cutImp);
    float purity = -1;
    int numbjet = hbasejet[specificFlavour][binJetPt]->Integral(binTargetjet, hbasejet[specificFlavour][binJetPt]->GetNbinsX());

    int sumBase = 0;

    for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
      int binBasejet = hbasejet[flavour][binJetPt]->FindBin(cutImp);
      double integral = hbasejet[flavour][binJetPt]->Integral(binBasejet, hbasejet[flavour][binJetPt]->GetNbinsX());
      sumBase +=integral;
    }
    std::cout << "jet Pt: " << HfJetTagging::binsJetPt[binJetPt] << "# of bjets: " << numbjet << " # of incjet: " << sumBase <<std::endl;
    // Check if sumBase is not zero to avoid division by zero
    if (sumBase != 0) {
      purity = (float) numbjet/sumBase;
    } else {
      std::cerr << "Warning: Total base sum is zero, purity is undefined." << std::endl;
    }

    if (std::isnan(purity)) return -1;
    return static_cast<float>(purity);
  }
}

#endif // HFJETTAGGINGUTILITIES_H
