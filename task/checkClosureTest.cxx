#include "../include/DataPoint.h"
#include "../include/HfJetTaggingAnalysis.h"
#include "../include/HfJetTaggingTCAnalysis.h"
#include "../include/HfJetTaggingJPAnalysis.h"
#include "../include/HfJetTaggingSVAnalysis.h"

TFile* loadFile(TSTring rootData) {
  if (gSystem->AccessPathName(rootData.Data())) {
    std::cout << "Input file: " << rootData.Data() << " not found!" << std::endl;
    return NULL;
  }
  TFile* fin;
  fin = TFile::Open(rootData.Data(), "READ");
  return fin;
}




void checkClosureTest() {
  TFile* sample1 = loadFile()

}
