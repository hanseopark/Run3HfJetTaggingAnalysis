# config.sh

# Define paths
BASE_PATH=$(pwd)
LOCAL_DATAPATH="$BASE_PATH/../local/data"
LOCAL_SIMPATH="$BASE_PATH/../local/sim"
DEV_DATAPATH="$BASE_PATH/../dev/HFJetsWork/Data"
DEV_SIMPATH="$BASE_PATH/../dev/HFJetsWork/MC/DetectorLevel"
HY_DATAPATH="$BASE_PATH/../HY/data"
HY_SIMPATH="$BASE_PATH/../HY/sim"
TEST_DATAPATH="$BASE_PATH/../test/data"
TEST_SIMPATH="$BASE_PATH/../test/sim"

set_paths_and_triggers() {
  local DATAPASS=$1
  local MCTRIGGER=$2

  # Set DATA_SET based on DATAPASS
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
  # Set MC_SET and TRIGGER_NAME based on MCTRIGGER
  if [ "$MCTRIGGER" == "jj" ]; then
    MC_SET="LHC23d4"
    TRIGGER_NAME="PYTHIA 8 + Geant4"
  elif [ "$MCTRIGGER" == "apass4" ]; then
    MC_SET="LHC23d1k"
    TRIGGER_NAME="anchored to apass4 22f"
  elif [ "$MCTRIGGER" == "apass4highIR" ]; then
    MC_SET="LHC23k2f"
    TRIGGER_NAME="anchored to apass4 LHC22m/o/p/r/t, high IR"
  elif [ "$MCTRIGGER" == "apass6" ]; then
    MC_SET="LHC24b1"
    TRIGGER_NAME="anchored to apass6 LHC22o"
  elif [ "$MCTRIGGER" == "mb" ] || [ "$MCTRIGGER" == "MB" ]; then
    MC_SET="LHC24b1"
    TRIGGER_NAME="MB"
  else
    MC_SET="LHC24b1"
    TRIGGER_NAME="MB"
  fi
}

