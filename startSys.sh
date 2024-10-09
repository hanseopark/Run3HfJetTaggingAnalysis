#!/bin/bash

usage() {
  echo "Usage: $0 [--shower] [--radius] [--ts] [--trigger] [--pass] [--tagger]"
  exit 1
}

# Initialize flags
doShower=false
doRadius=false
doTrackSelection=false
doTrigger=false
doPass=false
doTagger=false
doQuarkHadronLevel=false
source=""
data=""
sim=""
TRIGGER_NAME=""
suffix=""
# Parse command line arguments
while [ "$1" != "" ]; do
  case $1 in
    --shower )
      doShower=true
      ;;
    --radius )
      doRadius=true
      ;;
    --trksel )
      doTrackSelection=true
      ;;
    --trigger )
      doTrigger=true
      ;;
    --pass )
      doPass=true
      ;;
    --tagger )
      doTagger=true
      ;;
    --quarkhadron )
      doQuarkHadronLevel=true
      ;;
    --source )
      shift
      source=$1
      ;;
    --data )
      shift
      data=$1
      ;;
    --mc )
      shift
      sim=$1
      ;;
    --suffix )
      shift
      suffix=$1
      ;;
    -h | --help )
      usage
      exit
      ;;
    * )
      echo "Unknown option: $1"
      usage
      ;;
  esac
  shift
done

if [ "$sim" == "LHC23d4" ]; then # JetJet trigger test sample
  TRIGGER_NAME="PYTHIA 8 + Geant4 jet-jet test sample"
elif [ "$sim" == "LHC23d1k" ]; then # General Purpose MC anchored to LHC22f apass4
  TRIGGER_NAME="anchored to apass4 22f"
elif [ "$sim" == "LHC23k2f" ]; then # General Purpose anchored to apass4 of 13.6 TeV pp data period LHC22m/o/p/r/t, high IR
  TRIGGER_NAME="anchored to apass4 LHC22m/o/p/r/t, high IR"
elif [ "$sim" == "LHC24b1b" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o MinBias
  TRIGGER_NAME="anchored to apass6 LHC22o"
else
  TRIGGER_NAME="MB"
fi

# Output the set options
echo "Analysis of systematic"
echo "--shower: $doShower"
echo "--radius: $doRadius"
echo "--trksel: $doTrackSelection"
echo "--trigger: $doTrigger"
echo "--pass: $doPass"
echo "--tagger: $doTagger"
echo "--quarkhadron: $doQuarkHadronLevel"

root -x -l -b -q 'task/plotSys.cxx("'"$source"'", "'"$data"'", "'"$sim"'", "'"$TRIGGER_NAME"'", "'"$suffix"'","'"$doShower"'", "'"$doRadius"'", "'"$doTrackSelection"'", "'"$doTrigger"'", "'"$doPass"'", "'"$doTagger"'", "'"$doQuarkHadronLevel"'")'
