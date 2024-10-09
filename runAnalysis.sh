#!/bin/bash

usage() {
  echo "Usage: $0 --mode MODE --source SOURCE_NAME [--data DATAPASS] [--mc MCTRIGGER] [-h|--help]"
  echo "  --mode MODE            Mode of operation (e.g., tag, ip, tc, jp, sv, effi, sys, jet)"
  echo "  --source SOURCE_NAME   Source name (e.g., local, dev, HY, hytest, TEST)"
  echo "  --data DATAPASS        Data pass (optional)"
  echo "  --mc MCTRIGGER         MC trigger (optional)"
  echo "  --suffix SUFFIX        fig_suffix"
  echo "  -h, --help             Display this help and exit"
  exit 1
}

## Common
PROCESS_DATA=false
PROCESS_MCD=false
PROCESS_MCP=false
# Parse command line arguments
while [ "$1" != "" ]; do
  case $1 in
    --mode )
      shift
      MODE=$1
     ;;
    --source )
      shift
      SOURCE_NAME=$1
      ;;
    --sourcesuffix )
      shift
      SOURCE_SUFFIX=$1
      ;;
    --data )
      shift
      PROCESS_DATA=true
      DATAPASS=$1
      ;;
    --mc )
      shift
      PROCESS_MCD=true
      MCTRIGGER=$1
      ;;
    --suffix )
      shift
      SUFFIX=$1
      ;;
    --rootsuffix )
      shift
      ROOTSUFFIX=$1
      ;;
    -h | --help )
      usage
      exit
      ;;
    ## FOR systematic
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
    * )
      echo "Unknown option: $1"
      usage
      ;;
  esac
  shift
done

# Set DATAPATH based on SOURCE_NAME argument
if [ "$SOURCE_NAME" == "local" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/local/data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/local/sim"
elif [ "$SOURCE_NAME" == "dev" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/Data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel"
elif [ "$SOURCE_NAME" == "HY" ] || [ "$SOURCE_NAME" == "hy" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HY/data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HY/sim"
elif [ "$SOURCE_NAME" == "HYTEST" ] || [ "$SOURCE_NAME" == "hytest" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HYTEST/data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HYTEST/sim"
elif [ "$SOURCE_NAME" == "TEST" ] || [ "$SOURCE_NAME" == "test" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/test/data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/test/sim"
else
  echo "Invalid SOURCE_NAME: $SOURCE_NAME"
  exit 2
fi

# data and mc set pass and trigger
if [ "$DATAPASS" == "apass6" ]; then
  DATA_NAME="LHC22o_apass6"
elif [ "$DATAPASS" == "LHC22o_apass4_lowIR" ]; then
  DATA_NAME="LHC22o_apass4_lowIR"
elif [ "$DATAPASS" == "LHC22f_apass4" ]; then
  DATA_NAME="LHC22f_apass4"
elif [ "$DATAPASS" == "LHC22o_apass4" ]; then
  DATA_NAME="LHC22o_apass4"
elif [ "$DATAPASS" == "LHC22o_apass6" ]; then
  DATA_NAME="LHC22o_apass6"
elif [ "$DATAPASS" == "apass7" ]; then
  DATA_NAME="LHC22o_apass7"
else
  DATA_NAME="LHC22o_apass6"
fi
DATAPATH="$DATAPATH/$DATA_NAME"

if [ "$MCTRIGGER" == "jjtest" ]; then # JetJet trigger test sample
  MC_NAME="LHC23d4"
  TRIGGER_NAME="PYTHIA 8 + Geant4"
elif [ "$MCTRIGGER" == "apass4" ]; then # General Purpose MC anchored to LHC22f apass4
  MC_NAME="LHC23d1k"
  TRIGGER_NAME="anchored to apass4 22f"
elif [ "$MCTRIGGER" == "apass4highIR" ]; then # General Purpose anchored to apass4 of 13.6 TeV pp data period LHC22m/o/p/r/t, high IR
  MC_NAME="LHC23k2f"
  TRIGGER_NAME="anchored to apass4 LHC22m/o/p/r/t, high IR"
elif [ "$MCTRIGGER" == "apass6" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o MinBias
  MC_NAME="LHC24b1b"
  TRIGGER_NAME="anchored to apass6 LHC22o"
elif [ "$MCTRIGGER" == "apass7" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o MinBias
  MC_NAME="LHC24f3"
  TRIGGER_NAME="anchored to apass7 LHC22o"
elif [ "$MCTRIGGER" == "apass6Hf" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o MinBias
  MC_NAME="LHC24d3"
  TRIGGER_NAME="b & c enhanced anchored to apass6 LHC22o"
elif [ "$MCTRIGGER" == "jjapass7" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o jet-jet
  MC_NAME="LHC24g4"
  TRIGGER_NAME="jet-jet anchored to apass7 LHC22o"
elif [ "$MCTRIGGER" == "testJetAnchoredGapGen-20240723-100905" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o MinBias
  MC_NAME="testJetAnchoredGapGen-20240723-100905"
  TRIGGER_NAME="anchored to apass7 jet-jet no Gap"
elif [ "$MCTRIGGER" == "mb" || "$MCTRIGGER" == "MB" ]; then
  MC_NAME="LHC24b1b"
  TRIGGER_NAME="MB"
else
  MC_NAME="LHC24b1b"
  TRIGGER_NAME="MB"
fi
SIMPATH="$SIMPATH/$MC_NAME"

if [ -n "$SOURCE_SUFFIX" ]; then
  DATAPATH=$DATAPATH/$SOURCE_SUFFIX
  SIMPATH=$SIMPATH/$SOURCE_SUFFIX
fi

#### ROOT FILE NAME ####
ROOT_DATA_NAME="AnalysisResults.root"
ROOT_SIM_NAME="AnalysisResults.root"
#ROOT_DATA_NAME="AnalysisResults_IP.root"
#ROOT_SIM_NAME="AnalysisResults_IP.root"
#ROOT_DATA_NAME="AnalysisResults_JP.root"
#ROOT_SIM_NAME="AnalysisResults_JP.root"
#ROOT_DATA_NAME="AnalysisResults_IP_JP.root"
#ROOT_SIM_NAME="AnalysisResults_IP_JP.root"
#ROOT_DATA_NAME="AnalysisResults_SV.root"
#ROOT_SIM_NAME="AnalysisResults_SV.root"

if [ "$SOURCE_NAME" == "dev" ]; then
  ROOT_DATA_NAME="AnalysisResults.root"
  ROOT_SIM_NAME="AnalysisResults.root"
fi

if [ -n "$ROOTSUFFIX" ]; then
  ROOT_DATA_NAME="AnalysisResults_$ROOTSUFFIX.root"
  ROOT_SIM_NAME="AnalysisResults_$ROOTSUFFIX.root"
fi

#### CONFIGURATION ####
PROCESS_MCP=false
WITH_INCLUSIVE=true
USE_LOG_SCALE=true
FILL_RUN2DEF=false
FILL_TEST=false

## General jet

## IP
FILL_IP_XY=true
FILL_IP_Z=false
FILL_IP_XYZ=false
DO_FIT_JP=true
FILL_JETRECO_EFFIANDPURITY=false
DO_UNFOLDING=false

## TC
FILL_TC_XY=true
FILL_TC_Z=true
FILL_TC_XYZ=true
FILL_TC_EFFIANDPURITY=true

## JP
DO_TRACK_PROB=false
DO_TEMPLATE_FIT=false
FILL_JP_EFFIANDPURITY=true

## SV
FILL_SV_2PRONG=false
FILL_SV_3PRONG=true
FILL_SV_N1=true
FILL_SV_EFFIANDPURITY=true

## For track efficiency
PROCESS_TRACK_EFFI=false

# Build the options string for startSysAnalysisHfJetTagging.sh
SYS_OPTIONS=""
[ "$doShower" = true ] && SYS_OPTIONS="$SYS_OPTIONS --shower"
[ "$doRadius" = true ] && SYS_OPTIONS="$SYS_OPTIONS --radius"
[ "$doTrackSelection" = true ] && SYS_OPTIONS="$SYS_OPTIONS --trksel"
[ "$doTrigger" = true ] && SYS_OPTIONS="$SYS_OPTIONS --trigger"
[ "$doPass" = true ] && SYS_OPTIONS="$SYS_OPTIONS --pass"
[ "$doTagger" = true ] && SYS_OPTIONS="$SYS_OPTIONS --tagger"
[ "$doQuarkHadronLevel" = true ] && SYS_OPTIONS="$SYS_OPTIONS --quarkhadron"

DATAINPUT="$DATAPATH/$ROOT_DATA_NAME"
SIMINPUT="$SIMPATH/$ROOT_SIM_NAME"
if [ "$MODE" == "tag" ]; then
  #bash startAnalysisHfJetTagging.sh "$DATAINPUT" "$SIMINPUT" $PROCESS_IP_DATA $PROCESS_IP_MCD $DO_FIT_JP $DO_TC $PROCESS_JP_DATA $PROCESS_JP_MCD $DO_TEMPLATE_FIT $PROCESS_SV_2PRONG_DATA $PROCESS_SV_3PRONG_DATA $PROCESS_SV_2PRONG_MCD $PROCESS_SV_3PRONG_MCD "$TRIGGER_NAME" $IS_PARTICLE_LEVEL $WITH_INCLUSIVE $USE_LOG_SCALE "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME"
  bash startIP.sh "$DATAINPUT" "$SIMINPUT" "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME" "$TRIGGER_NAME" "$SUFFIX" $WITH_INCLUSIVE $USE_LOG_SCALE $PROCESS_DATA $PROCESS_MCD $PROCESS_MCP $FILL_RUN2DEF $FILL_IP_XY $FILL_IP_Z $FILL_IP_XYZ $DO_FIT_JP $FILL_JETRECO_EFFIANDPURITY $DO_UNFOLDING
elif [ "$MODE" == "ip" ]; then
  bash startIP.sh "$DATAINPUT" "$SIMINPUT" "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME" "$TRIGGER_NAME" "$SUFFIX" $WITH_INCLUSIVE $USE_LOG_SCALE $PROCESS_DATA $PROCESS_MCD $PROCESS_MCP $FILL_RUN2DEF $FILL_IP_XY $FILL_IP_Z $FILL_IP_XYZ $DO_FIT_JP $FILL_JETRECO_EFFIANDPURITY $DO_UNFOLDING
elif [ "$MODE" == "tc" ]; then
  bash startTC.sh "$DATAINPUT" "$SIMINPUT" "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME" "$TRIGGER_NAME" "$SUFFIX" $WITH_INCLUSIVE $USE_LOG_SCALE $PROCESS_DATA $PROCESS_MCD $PROCESS_MCP $FILL_RUN2DEF $FILL_TC_XY $FILL_TC_Z $FILL_TC_XYZ $FILL_TC_EFFIANDPURITY
elif [ "$MODE" == "jp" ]; then
  bash startJP.sh "$DATAINPUT" "$SIMINPUT" "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME" "$TRIGGER_NAME" "$SUFFIX" $WITH_INCLUSIVE $USE_LOG_SCALE $PROCESS_DATA $PROCESS_MCD $PROCESS_MCP $FILL_RUN2DEF $DO_TRACK_PROB $DO_TEMPLATE_FIT $FILL_JP_EFFIANDPURITY
elif [ "$MODE" == "sv" ]; then
  bash startSV.sh "$DATAINPUT" "$SIMINPUT" "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME" "$TRIGGER_NAME" "$SUFFIX" $WITH_INCLUSIVE $USE_LOG_SCALE $PROCESS_DATA $PROCESS_MCD $PROCESS_MCP $FILL_RUN2DEF $FILL_TEST $FILL_SV_2PRONG $FILL_SV_3PRONG $FILL_SV_N1 $FILL_SV_EFFIANDPURITY
elif [ "$MODE" == "effi" ]; then
  bash startTrackEffi.sh "$DATAINPUT" "$SIMINPUT" "$SOURCE_NAME" "$DATA_NAME" "$MC_NAME" "$TRIGGER_NAME" $WITH_INCLUSIVE $USE_LOG_SCALE $PROCESS_DATA $PROCESS_MCD $PROCESS_MCP
elif [ "$MODE" == "sys" ]; then
  bash startSys.sh $SYS_OPTIONS --source "$SOURCE_NAME" --data "$DATA_NAME" --mc "$MC_NAME" --suffix "$SUFFIX"
elif [ "$MODE" == "jet" ]; then
  bash startAnalysisJetAnalysis.sh
else
  echo "Invalid MODE: $MODE"
  exit 3
fi
