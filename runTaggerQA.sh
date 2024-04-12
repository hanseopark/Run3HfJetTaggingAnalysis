#!/bin/bash

# For future, it will add merged all task
# this is just a skeleton for now

if [ $# -lt 2 ]; then
  echo "Usage: $0 <DATA_LOCATION> <MODE> <DATAPASS> <MCTRIGGER>"
  exit 1
fi

DATA_LOCATION=$1
MODE=$2
DATAPASS=$3
MCTRIGGER=$4

# Set DATAPATH based on DATA_LOCATION argument
if [ "$DATA_LOCATION" == "local" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/local/data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/local/sim"
elif [ "$DATA_LOCATION" == "dev" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/Data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/MC/DetectorLevel"
elif [ "$DATA_LOCATION" == "HY" ] || [ "$DATA_LOCATION" == "hy" ]; then
  DATAPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HY/data"
  SIMPATH="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/HY/sim"
else
  echo "Invalid DATA_LOCATION: $DATA_LOCATION"
  DATA_LOCATION="/Users/hanseopark/alice/work/PHD_Analysis/Run3/pp/13.6TeV/HfJets/Dev/HFJetsWork/Data"
  echo "Using data path: $DATA_LOCATION"
  exit 2
fi

# data and mc set pass and trigger
if [ "$DATAPASS" == "apass6" ]; then
  DATA_SET="LHC22o_apass6"
elif [ "$DATAPASS" == "LHC22o_apass4_lowIR" ]; then
  DATA_SET="LHC22o_apass4_lowIR"
elif [ "$DATAPASS" == "LHC22f_apass4" ]; then
  DATA_SET="LHC22f_apass4"
elif [ "$DATAPASS" == "LHC22o_apass4" ]; then
  DATA_SET="LHC22o_apass4"
else
  DATA_SET="LHC22o_apass6"
fi
DATAPATH="$DATAPATH/$DATA_SET"

if [ "$MCTRIGGER" == "jj" ]; then # JetJet trigger test sample
  MC_SET="LHC23d4"
  TRIGGER_NAME="JetJet trigger"
elif [ "$MCTRIGGER" == "apass4" ]; then # General Purpose MC anchored to LHC22f apass4
  MC_SET="LHC23d1k"
  TRIGGER_NAME="anchored to apass4 22f"
elif [ "$MCTRIGGER" == "apass4highIR" ]; then # General Purpose anchored to apass4 of 13.6 TeV pp data period LHC22m/o/p/r/t, high IR
  MC_SET="LHC23k2d"
  TRIGGER_NAME="anchored to apass4 LHC22m/o/p/r/t, high IR"
elif [ "$MCTRIGGER" == "apass6" ]; then # General Purpose anchored to apass6 of 13.6 TeV pp data period LHC22o MinBias
  MC_SET="LHC24b1"
  TRIGGER_NAME="anchored to apass6 LHC22o"
elif [ "$MCTRIGGER" == "mb" || "$MCTRIGGER" == "MB" ]; then
  MC_SET="LHC24b1"
  TRIGGER_NAME="MB"
else
  MC_SET="LHC24b1"
  TRIGGER_NAME="MB"
fi
SIMPATH="$SIMPATH/$MC_SET"

# default root file
DATATYPE="AnalysisResults_IP.root"
SIMTYPE="AnalysisResults_IP.root"

PROCESS_IP_DATA=true
PROCESS_IP_MCD=true
DO_FIT_JP=true
DO_TC=true
DO_TEMPLATE_FIT=false
PROCESS_JP_DATA=true
PROCESS_JP_MCD=true
PROCESS_SV_2PRONG_MCD=false
PROCESS_SV_3PRONG_MCD=false
#TRIGGER_NAME=""
IS_PARTICLE_LEVEL=false
WITH_INCLUSIVE=true
USE_LOG_SCALE=true

select_DATATYPE() {
  case $1 in
    "PROCESS_IP_DATA")
      DATATYPE="AnalysisResults_IP.root"
      ;;
    "PROCESS_JP_DATA")
      DATATYPE="AnalysisResults_JP.root"
      if [ "$PROCESS_IP_DATA" == true ]; then
        DATATYPE="AnalysisResults_JP.root"
      fi
      ;;
  esac
}

for process_var in "PROCESS_IP_DATA" "PROCESS_JP_DATA"; do
  if [ "${!process_var}" == true ]; then
    select_DATATYPE "$process_var"
  fi
done

select_SIMTYPE() {
  case $1 in
    "PROCESS_IP_MCD")
      SIMTYPE="AnalysisResults_IP.root"
      ;;
    "PROCESS_JP_MCD")
      SIMTYPE="AnalysisResults_JP.root"
      if [ "$PROCESS_IP_MCD" == true ]; then
        SIMTYPE="AnalysisResults_IP.root"
      fi
      ;;
    "PROCESS_SV_2PRONG_MCD")
      SIMTYPE="AnalysisResults_2prong.root"
      ;;
    "PROCESS_SV_3PRONG_MCD")
      SIMTYPE="AnalysisResults_3prong.root"
      ;;
  esac
}

for process_var in "PROCESS_IP_MCD" "PROCESS_JP_MCD" "PROCESS_SV_2PRONG_MCD" "PROCESS_SV_3PRONG_MCD"; do
  if [ "${!process_var}" == true ]; then
    select_SIMTYPE "$process_var"
  fi
done

if [ "$MODE" == "single" ]; then
  DATAINPUT="$DATAPATH/$DATATYPE"
  SIMINPUT="$SIMPATH/$SIMTYPE"
  bash startAnalysisHfJetTagging.sh "$DATAINPUT" "$SIMINPUT" $PROCESS_IP_DATA $PROCESS_IP_MCD $DO_FIT_JP $DO_TC $DO_TEMPLATE_FIT $PROCESS_JP_DATA $PROCESS_JP_MCD $PROCESS_SV_2PRONG_MCD $PROCESS_SV_3PRONG_MCD "$TRIGGER_NAME" $IS_PARTICLE_LEVEL $WITH_INCLUSIVE $USE_LOG_SCALE "$DATA_SET" "$MC_SET"

elif [ "$MODE" == "trigger" ]; then
  SIMTYPES=("AnalysisResults_globalTracks.root" "AnalysisResults_QualityTracks.root" "AnalysisResults_JetJet.root" "AnalysisResults_bbbar.root" "AnalysisResults_ccbar.root" "AnalysisResults_bbbarJet.root" "AnalysisResults_ccbarJet.root")
  for SIMTYPE in "${SIMTYPES[@]}"; do
    # Set TRIGGER_NAME based on SIMTYPE
    case "$SIMTYPE" in
      *"_JetJet"*) TRIGGER_NAME="JetJet" ;;
      *"_bbbar"*) TRIGGER_NAME="bbbar" ;;
      *"_ccbar"*) TRIGGER_NAME="ccbar" ;;
      *"_bbbarJet"*) TRIGGER_NAME="bbbarJet" ;;
      *"_ccbarJet"*) TRIGGER_NAME="ccbarJet" ;;
      *"_QualityTracks"*) TRIGGER_NAME="QualityTracks" ;;
      *) TRIGGER_NAME="MB" ;;
    esac

  # Define other variables
  SIMINPUT="$SIMPATH/$SIMTYPE"
  bash startAnalysisHfJetTagging.sh "$DATAINPUT" "$SIMINPUT" $PROCESS_IP_DATA $PROCESS_IP_MCD $DO_FIT_JP $DO_TC $DO_TEMPLATE_FIT $PROCESS_JP_DATA $PROCESS_JP_MCD $PROCESS_SV_2PRONG_MCD $PROCESS_SV_3PRONG_MCD "$TRIGGER_NAME" $IS_PARTICLE_LEVEL $WITH_INCLUSIVE $USE_LOG_SCALE "$DATA_SET" "$MC_SET"
done
else
  echo "Invalid MODE: $MODE"
  exit 3
fi
