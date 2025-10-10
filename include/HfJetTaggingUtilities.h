#ifndef HFJETTAGGINGUTILITIES_H
#define HFJETTAGGINGUTILITIES_H

#include "TH1.h"
#include "TString.h"
#include "DataPoint.h"
#include "CanvasHandler.h"
#include <cmath>
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TDecompSVD.h"

namespace taggingutilities {

  // for response matrix
  void normalize2DHist(TH2* h2ResMat) {
    if (!h2ResMat) {
      std::cerr << "Error: Input histogram is null." << std::endl;
      return;
    }

    int nYBins = h2ResMat->GetNbinsY();
    int nXBins = h2ResMat->GetNbinsX();

    for (int j = 1; j <= nYBins; ++j) {
      double sum = 0;
      for (int i = 1; i <= nXBins; ++i) {
        sum += h2ResMat->GetBinContent(i, j);
      }

      if (sum > 0) {
        for (int i = 1; i <= nXBins; ++i) {
          double content = h2ResMat->GetBinContent(i, j);
          h2ResMat->SetBinContent(i, j, content / sum);
          h2ResMat->SetBinError(i, j, h2ResMat->GetBinError(i, j) / sum);
        }
      } else {
        for (int i = 1; i <= nXBins; ++i) {
          h2ResMat->SetBinContent(i, j, 0);
          h2ResMat->SetBinError(i, j, 0);
        }
      }
    }

    std::cout << "Response matrix '" << h2ResMat->GetName() << "' has been normalized by truth bins." << std::endl;
  }

  void normalize2DHistTotal(TH2* h2) {
    if (!h2) {
      std::cerr << "Error: Input histogram is null." << std::endl;
      return;
    }

    double totalIntegral = h2->Integral();
    if (totalIntegral > 0) {
      int nXBins = h2->GetNbinsX();
      int nYBins = h2->GetNbinsY();
      for (int i = 1; i <= nXBins; ++i) {
        for (int j = 1; j <= nYBins; ++j) {
          double content = h2->GetBinContent(i, j);
          h2->SetBinContent(i, j, content / totalIntegral);
          h2->SetBinError(i, j, h2->GetBinError(i, j) / totalIntegral);
        }
      }
      std::cout << "2D histogram '" << h2->GetName() << "' normalized by total integral." << std::endl;
    } else {
      std::cerr << "Warning: Total integral is zero, cannot normalize." << std::endl;
    }
  }

  void rebin2DHist(TH2* h2, TH2* h2rebin, int nXbins, const double *binsX, int nYbins, const double *binsY) {

    //h2rebin = new TH2F("h2rebin", "", nXbins, binsX, nYbins, binsY);
    for (int i = 1; i <= h2->GetNbinsX(); i++) {
      for (int j = 1; j <= h2->GetNbinsY(); j++) {
        float content = h2->GetBinContent(i, j);
        float error = h2->GetBinError(i, j);
        int bindet = h2rebin->GetXaxis()->FindBin(h2->GetXaxis()->GetBinCenter(i));
        int binpart = h2rebin->GetYaxis()->FindBin(h2->GetYaxis()->GetBinCenter(j));
        float currentContent = h2rebin->GetBinContent(bindet, binpart);
        float currentError = h2rebin->GetBinError(bindet, binpart);
        float newContent = currentContent + content;
        float newError = sqrt(pow(currentError, 2) + pow(error, 2)); // Combine errors in quadrature
        h2rebin->SetBinContent(bindet, binpart, newContent);
        h2rebin->SetBinError(bindet, binpart, newError);
      }
    }
  }


  std::vector<TH1F*> makeRelativePtDiffHists( TH2F* histResMat, int nBins, const double* ptBins, const TString& histPrefix = "hRelDiff", bool doNorm=true) {
    std::vector<TH1F*> hists;

    for (int i = 0; i <= nBins; ++i) {
      TString name = Form("%s_%d", histPrefix.Data(), i);
      TString title = (i == 0)
        ? "Relative pT diff (all)"
        : Form("Rel pT diff for %.0f–%.0f GeV", ptBins[i - 1], ptBins[i]);
      TH1F* h = new TH1F(name, title, 100, -1, 1);
      h->Sumw2();
      hists.push_back(h);
    }

    for (int i = 1; i <= histResMat->GetNbinsX(); ++i) {
      for (int j = 1; j <= histResMat->GetNbinsY(); ++j) {
        double recoPt = histResMat->GetXaxis()->GetBinCenter(i);
        double truthPt = histResMat->GetYaxis()->GetBinCenter(j);
        double weight = histResMat->GetBinContent(i, j);
        if (truthPt > 0 && weight > 0) {
          double rel = (recoPt - truthPt) / truthPt;
          hists[0]->Fill(rel, weight); // inclusive

          for (int b = 0; b < nBins; ++b) {
            if (truthPt >= ptBins[b] && truthPt < ptBins[b + 1]) {
              hists[b + 1]->Fill(rel, weight);
              break;
            }
          }
        }
      }
    }

    if (doNorm) {
      for (auto& h : hists) {
        if (h->Integral() > 0)
          h->Scale(1.0 / h->Integral());
      }
    }

    return hists;
  }

  float getEfficiency(TH1F* htagjet, TH1F* huntaggedjet) { // for JP
    float numOfbJetBeforeTagger = huntaggedjet->Integral(1, huntaggedjet->GetNbinsX());
    float numOfbJetAfterTagger = htagjet->Integral(1, htagjet->GetNbinsX());
    float effi = static_cast<float>((float)numOfbJetAfterTagger / numOfbJetBeforeTagger);
    std::cout << "[effi] before jet entries: " << numOfbJetBeforeTagger << " after jet entries: " << numOfbJetAfterTagger << " effi: " << effi << std::endl;
    return effi;
  }

  float getEfficiency(TH1F* htagjet, TH1F* huntaggedjet, int binJetPt) { // it is calculated from tagged hist
    float numOfbJetBeforeTagger = huntaggedjet->Integral(huntaggedjet->FindBin(HfJetTagging::binsJetPt[binJetPt-1]), huntaggedjet->FindBin(HfJetTagging::binsJetPt[binJetPt]));
    float numOfbJetAfterTagger = htagjet->Integral(1, htagjet->GetNbinsX());
    float effi = static_cast<float>((float)numOfbJetAfterTagger / numOfbJetBeforeTagger);
    std::cout << "[effi] before jet entries: " << numOfbJetBeforeTagger << " after jet entries: " << numOfbJetAfterTagger << " effi: " << effi << std::endl;
    return effi;
  }

  float getEfficiency(TH1F* hjetwcut, TH1F* htotaljet, int binJetPt, float taggerPoint) { // it is calculated from N1 hist
    float effi = -1;
    int binStart = hjetwcut->FindBin(taggerPoint);
    int binEnd = hjetwcut->GetNbinsX();

    float numTaggedjet = hjetwcut->Integral(binStart, binEnd);
    float numTotaljet = htotaljet->GetBinContent(binJetPt);
    //std::cout << "bin: "<< binJetPt << " numtaggedjet: " << numTaggedjet << " numtotaljet " << numTotaljet << std::endl;

    if (numTotaljet == 0) return -1;

    effi = numTaggedjet / numTotaljet;
    return std::isnan(effi) ? -1 : effi;
  }

  float getErrorEfficiency(TH1F* htagjet, TH1F* huntaggedjet) {
    float numOfbJetBeforeTagger = huntaggedjet->Integral(1, huntaggedjet->GetNbinsX());
    float numOfbJetAfterTagger = htagjet->Integral(1, htagjet->GetNbinsX());

    if (numOfbJetBeforeTagger == 0 || numOfbJetAfterTagger == 0) return -1;

    float effi = static_cast<float>(numOfbJetAfterTagger) / numOfbJetBeforeTagger;
    float errorEffi = effi * std::sqrt((1.0 / numOfbJetAfterTagger) + (1.0 / numOfbJetBeforeTagger));

    std::cout << "[effi] before jet entries: " << numOfbJetBeforeTagger << " after jet entries: " << numOfbJetAfterTagger << " efficiency: " << effi << " error: " << errorEffi << std::endl;

    return errorEffi;
  }

  float getErrorEfficiency(TH1F* htagjet, TH1F* huntaggedjet, int binJetPt) {
    float numOfbJetBeforeTagger = huntaggedjet->Integral(
        huntaggedjet->FindBin(HfJetTagging::binsJetPt[binJetPt-1]),
        huntaggedjet->FindBin(HfJetTagging::binsJetPt[binJetPt])
        );

    float numOfbJetAfterTagger = htagjet->Integral(1, htagjet->GetNbinsX());

    if (numOfbJetBeforeTagger <= 1) {
      std::cout << "[error_effi] Before jet entries are zero or negative, returning -1" << std::endl;
      return -1.0;
    }

    float effi = static_cast<float>(numOfbJetAfterTagger) / numOfbJetBeforeTagger;

    float error_sq = (effi * (1.0 - effi)) / numOfbJetBeforeTagger;
    float error_effi = std::sqrt(error_sq);

    std::cout << "[error_effi] before jet entries: " << numOfbJetBeforeTagger
      << " effi: " << effi
      << " error: " << error_effi << std::endl;

    return error_effi;
  }

  float getErrorEfficiency(TH1F* hjet, float taggerPoint) {
    int binStart = hjet->FindBin(taggerPoint);
    int binEnd = hjet->GetNbinsX();

    float numTaggedjet = hjet->Integral(binStart, binEnd);
    float numTotaljet = hjet->Integral(1, binEnd);

    if (numTaggedjet == 0 || numTotaljet == 0) return 0;

    float effi = numTaggedjet / numTotaljet;
    float errorEffi = effi * std::sqrt((1.0 / numTaggedjet) + (1.0 / numTotaljet));

    return errorEffi;
  }

  float getPurity(TH1F* hNegLogJPTaggedbJet, TH1F* hNegLogJPTaggedIncJet) { // for JP
    // it needs defence
    int numOfbjet = hNegLogJPTaggedbJet->Integral(1, hNegLogJPTaggedbJet->GetNbinsX());
    int numOfincjet = hNegLogJPTaggedIncJet->Integral(1, hNegLogJPTaggedIncJet->GetNbinsX());
    if (numOfincjet == 0 ) return -1;
    float purity = static_cast<float>((float)numOfbjet/numOfincjet);
    std::cout << "[purity] b jet entries: " << numOfbjet << " inc jet entries: " << numOfincjet << " purity: " << purity <<std::endl;
    return purity;
  }

  float getPurity(int specificFlavour, int binJetPt, TH1F* hbasejet[][HfJetTagging::nBinsJetPt+1], float cutImp = 2.5) {
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
    float numbjet = hbasejet[specificFlavour][binJetPt]->Integral(binTargetjet, hbasejet[specificFlavour][binJetPt]->GetNbinsX());

    float sumBase = 0;

    for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
      int binBasejet = hbasejet[flavour][binJetPt]->FindBin(cutImp);
      float integral = hbasejet[flavour][binJetPt]->Integral(binBasejet, hbasejet[flavour][binJetPt]->GetNbinsX());
      sumBase +=integral;
    }
    std::cout << "jet Pt: " << HfJetTagging::binsJetPt[binJetPt] << " # of " << HfJetTagging::FLAVOURJET[specificFlavour] <<" jets: " << numbjet << " # of incjet: " << sumBase <<std::endl;
    // Check if sumBase is not zero to avoid division by zero
    if (sumBase != 0) {
      purity = (float) numbjet/sumBase;
    } else {
      std::cerr << "Warning: Total base sum is zero, purity is undefined." << std::endl;
    }

    if (std::isnan(purity)) return -1;
    return static_cast<float>(purity);
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


  float getErrorPurity(int specificFlavour, int binJetPt, TH1F* hbasejet[][HfJetTagging::nBinsJetPt+1], float cutImp = 2.5) {
    if (specificFlavour <= 0 || specificFlavour > HfJetTagging::nFlavour) {
      std::cerr << "Invalid specific flavour provided." << std::endl;
      return -1;
    }
    if (binJetPt < 0 || binJetPt > HfJetTagging::nBinsJetPt) {
      std::cerr << "Invalid jet pt provided." << std::endl;
      return -1;
    }

    int binTargetjet = hbasejet[specificFlavour][binJetPt]->FindBin(cutImp);
    float numbjet = hbasejet[specificFlavour][binJetPt]->Integral(binTargetjet, hbasejet[specificFlavour][binJetPt]->GetNbinsX());

    float sumBase = 0;
    for (int flavour = 1; flavour < HfJetTagging::nFlavour+1; flavour++) {
      int binBasejet = hbasejet[flavour][binJetPt]->FindBin(cutImp);
      float integral = hbasejet[flavour][binJetPt]->Integral(binBasejet, hbasejet[flavour][binJetPt]->GetNbinsX());
      sumBase += integral;
    }

    if (sumBase == 0) {
      std::cerr << "Warning: Total base sum is zero, purity error is undefined." << std::endl;
      return -1;
    }

    float purity = numbjet / sumBase;
    float purityError = sqrt(numbjet * (1 - purity)) / sumBase;

    if (std::isnan(purityError)) return -1;
    return static_cast<float>(purityError);
  }

  TVectorD getDVector(RooUnfoldResponse* response) {
    if (!response) {
      std::cerr << "Error: Input RooUnfoldResponse object is null." << std::endl;
      return TVectorD(0);
    }

    const TMatrixD& A = response->Mresponse();
    const TVectorD& b = response->Vmeasured();

    TDecompSVD svd_decomp(A);

    const TMatrixD& U_matrix = svd_decomp.GetU();

    TMatrixD U_T_matrix = U_matrix;
    U_T_matrix.Transpose(U_matrix);

    TVectorD d_vector = U_T_matrix * b;

    return d_vector;
  }

}

#endif // HFJETTAGGINGUTILITIES_H
