#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <TH1.h>
#include <TString.h>

namespace HfJetTagging{
  const int nBinsJetPt = 18;
  const double binsJetPt[nBinsJetPt + 1] = {
  0,
  2.0,
  4.0,
  10.0,
  15.0,
  20.0,
  25.0,
  30.0,
  35.0,
  40.0,
  45.0,
  50.0,
  55.0,
  60.0,
  65.0,
  70.0,
  80.0,
  90.0,
  100.0};
  const TString INCJET="inclusive jet";
  const TString LFJET="lf jet";
  const TString CJET="c jet";
  const TString BJET="b jet";
  const int INCJETCOLOR=1;
  const int LFJETCOLOR=2;
  const int CJETCOLOR=3;
  const int BJETCOLOR=4;

} // namespace HfJetTagging

struct HistogramData {
  TH1D* hist;
  TString classification;
  TString description;
  // You can add more members if needed
};

#endif // DATAPOINT_H

