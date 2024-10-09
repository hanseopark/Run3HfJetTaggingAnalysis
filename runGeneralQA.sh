# !bin/bash

# Check arguments
if [ $# -lt 2 ]; then
  echo "Usage: $0 <DATA_LOCATION> <MODE> <DATAPASS> <MCTRIGGER>"
  exit 1
fi

DATA_LOCATION=$1
MODE=$2
DATAPASS=$3
MCTRIGGER=$4

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

DATATYPE="AnalysisResults.root"
SIMTYPE="AnalysisResults.root"

PROCESS_DATA=false
PROCESS_DATA_RHO_AREA_SUB=true
PROCESS_DATA_EVT_WISE_CONST_SUB=false
PROCESS_DATA_SUB_MATCHED=false
PROCESS_MCD=true
PROCESS_MCD_WEIGHTED=false
PROCESS_MCP=true
PROCESS_MCP_WEIGHTED=false
PROCESS_MCP_MCD_MATCHED=true
PROCESS_MCP_MCD_MATCHED_WEIGHTED=false
PROCESS_DATA_TRIGGER=false
PROCESS_TRACK=false
PROCESS_TRACK_WEIGHTED=false
PROCESS_TRACK_SUB=false
PROCESS_RHO=false
PROCESS_RANDOM_CONE=false
PROCESS_TRACKEFFI=false
#TRIGGER_NAME=""
WITH_INCLUSIVE=true
USE_LOG_SCALE=true

if [ "$PROCESS_DATA" == true ] && [ "$PROCESS_DATA_RHO_AREA_SUB" == true ] && [ "$PROCESS_RHO" == true ]; then
  DATATYPE="AnalysisResults_rhosub_rho.root"
  SIMTYPE="AnalysisResults_rho.root"
elif [ "$PROCESS_DATA" == true ] && [ "$PROCESS_DATA_RHO_AREA_SUB" == true ]; then
  DATATYPE="AnalysisResults_rhosub_rho.root"
elif [ "$PROCESS_MCD" == true ] && [ "$PROCESS_MCD_WEIGHTED" == true ]; then
  SIMTYPE="AnalysisResults_weighted.root"
elif [ "$PROCESS_MCD" == true ] && [ "$PROCESS_MCP" == true ] && [ "$PROCESS_MCP_MCD_MATCHED" == true ]; then
  SIMTYPE="AnalysisResults_Matched.root"
else
  DATATYPE="AnalysisResults.root"
  SIMTYPE="AnalysisResults.root"
fi
DATATYPE="AnalysisResults_rhosub_rho.root"
SIMTYPE="AnalysisResults_rho.root"

if [ "$DATA_LOCATION" == "dev" ]; then
  DATATYPE="AnalysisResults.root"
  SIMTYPE="AnalysisResults.root"
  FIXED_TYPE=true
else
  FIXED_TYPE=false
fi


if [ "$MODE" == "single" ]; then
  DATAINPUT="$DATAPATH/$DATATYPE"
  SIMINPUT="$SIMPATH/$SIMTYPE"
  bash startAnalysisJetAnalysis.sh "$DATAINPUT" "$SIMINPUT" \
    "$PROCESS_DATA" "$PROCESS_DATA_RHO_AREA_SUB" \
    "$PROCESS_DATA_EVT_WISE_CONST_SUB" "$PROCESS_DATA_SUB_MATCHED" \
    "$PROCESS_MCD" "$PROCESS_MCD_WEIGHTED" \
    "$PROCESS_MCP" "$PROCESS_MCP_WEIGHTED" \
    "$PROCESS_MCP_MCD_MATCHED" "$PROCESS_MCP_MCD_MATCHED_WEIGHTED" \
    "$PROCESS_DATA_TRIGGER" "$PROCESS_TRACK" \
    "$PROCESS_TRACK_WEIGHTED" "$PROCESS_TRACK_SUB" \
    "$PROCESS_RHO" "$PROCESS_RANDOM_CONE" \
    "$TRIGGER_NAME" "$WITH_INCLUSIVE" "$USE_LOG_SCALE"

elif [ "$MODE" == "trigger" ]; then
  SIMTYPES=("AnalysisResults_globalTracks.root" "AnalysisResults_QualityTracks.root" "AnalysisResults_JetJet.root" "AnalysisResults_bbbar.root" "AnalysisResults_ccbar.root" "AnalysisResults_bbbarJet.root" "AnalysisResults_ccbarJet.root")
  for SIMTYPE in "${SIMTYPES[@]}"; do
    # Set TRIGGER_NAME based on SIMTYPE
#    if [[ "$SIMTYPE" == *"_JetJet"* ]]; then
#      TRIGGER_NAME="JetJet"
#    elif [[ "$SIMTYPE" == *"_bbbar"* ]]; then
#      TRIGGER_NAME="bbbar"
#    elif [[ "$SIMTYPE" == *"_ccbar"* ]]; then
#      TRIGGER_NAME="ccbar"
#    elif [[ "$SIMTYPE" == *"_bbbarJet"* ]]; then
#      TRIGGER_NAME="bbbarJet"
#    elif [[ "$SIMTYPE" == *"_ccbarJet"* ]]; then
#      TRIGGER_NAME="bbbarJet"
#    elif [[ "$SIMTYPE" == *"_QualityTracks"* ]]; then
#      TRIGGER_NAME="QualityTracks"
#    else
#      TRIGGER_NAME="MB"
#    fi
    case "$SIMTYPE" in
      *"_JetJet"*) TRIGGER_NAME="JetJet" ;;
      *"_bbbar"*) TRIGGER_NAME="bbbar" ;;
      *"_ccbar"*) TRIGGER_NAME="ccbar" ;;
      *"_bbbarJet"*) TRIGGER_NAME="bbbarJet" ;;
      *"_ccbarJet"*) TRIGGER_NAME="bbbarJet" ;;
      *"_QualityTracks"*) TRIGGER_NAME="QualityTracks" ;;
      *) TRIGGER_NAME="MB" ;;
    esac

    # Define other variables
    SIMINPUT="$SIMPATH/$SIMTYPE"
    bash startAnalysisJetAnalysis.sh "$DATAINPUT" "$SIMINPUT" \
      "$PROCESS_DATA" "$PROCESS_DATA_RHO_AREA_SUB" \
      "$PROCESS_DATA_EVT_WISE_CONST_SUB" "$PROCESS_DATA_SUB_MATCHED" \
      "$PROCESS_MCD" "$PROCESS_MCD_WEIGHTED" \
      "$PROCESS_MCP" "$PROCESS_MCP_WEIGHTED" \
      "$PROCESS_MCP_MCD_MATCHED" "$PROCESS_MCP_MCD_MATCHED_WEIGHTED" \
      "$PROCESS_DATA_TRIGGER" "$PROCESS_TRACK" \
      "$PROCESS_TRACK_WEIGHTED" "$PROCESS_TRACK_SUB" \
      "$PROCESS_RHO" "$PROCESS_RANDOM_CONE" \
      "$TRIGGER_NAME" "$WITH_INCLUSIVE" "$USE_LOG_SCALE"
  done
else
  echo "Invalid MODE: $MODE"
  exit 3
fi


