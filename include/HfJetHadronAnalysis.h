#ifndef HFJETHADRONANALYSIS_H
#define HFJETHADRONANALYSIS_H

#include <TH1D.h>
#include <TString.h>
#include "JetAnalysis.h"

class HfJetHadronAnalysis : public JetAnalysis {
  public:
    HfJetHadronAnalysis(const TString &rootFile, const TString &taskName, bool doMC) : JetAnalysis(rootFile, taskName, doMC){

    }
    ~HfJetHadronAnalysis();
    void InitHistogram();
  private:

};

void HfJetHadronAnalysis::InitHistogram() {
  std::cout << "Init histogram for HfJetHadron" << std::endl;

}


#endif // HFJETHADRONANALYSIS_H
