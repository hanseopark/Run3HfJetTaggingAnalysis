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
doTrackTuner=false
doTrack2Coll=false
ssource=""
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
    --tracktuner )
      doTrackTuner=true
      ;;
    --track2coll )
      doTrack2Coll=true
      ;;
    --mergeSV )
      doMergeSV=true
      ;;
    --source )
      shift
      ssource=$1
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

#FIGURE_NAME="ALICE Simulation"
#FIGURE_NAME="ALICE Performance"
FIGURE_NAME="ALICE Work in Progress"
#FIGURE_NAME="ALICE Prepliminary"
TRIGGER_NAME="PYTHIA 8 + Geant 4"

# Output the set options
echo "Analysis of systematic"
echo "--shower: $doShower"
echo "--radius: $doRadius"
echo "--trksel: $doTrackSelection"
echo "--trigger: $doTrigger"
echo "--pass: $doPass"
echo "--tagger: $doTagger"
echo "--quarkhadron: $doQuarkHadronLevel"
echo "--tracktuner: $doTrackTuner"
echo "--track2coll: $doTrack2Coll"
echo "--megeSV: $doMergeSV"

root -x -l -b -q 'task/plotSys.cxx("'"$ssource"'", "'"$data"'", "'"$sim"'", "'"$TRIGGER_NAME"'", "'"$FIGURE_NAME"'", "'"$suffix"'","'"$doShower"'", "'"$doRadius"'", "'"$doTrackSelection"'", "'"$doTrigger"'", "'"$doPass"'", "'"$doTagger"'", "'"$doQuarkHadronLevel"'", "'"$doTrackTuner"'", "'"$doTrack2Coll"'", "'"$doMergeSV"'")'
