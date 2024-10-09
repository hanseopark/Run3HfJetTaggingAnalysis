# !bin/bash

#./runSys.sh --source dev --data LHC22o_apass4 --mc jj

# Load the configuration
source ./config.sh

# Function to display usage
usage() {
  echo "Usage: $0 --source <source_value> --data <data_value> --mc <mc_value> ..."
  exit 1
}
# Initialize flags
doShower=false
doRadius=false
doTrackSelection=false
doTrigger=false
doPass=false
doTagger=false

# Parse command line arguments
while [ "$1" != "" ]; do
  case $1 in
    --source )
      shift
      DATA_LOCATION=$1
      ;;
    --data )
      shift
      DATAPASS=$1
      ;;
    --mc )
      shift
      MCTRIGGER=$1
      ;;
    --suffix )
      shift
      SUFFIX=$1
      ;;
    --reset )
      shift
      if [ -z "$SUFFIX" ]; then
        rm -rf fig
      else
        rm -rf fig_$SUFFIX
      fi
      ;;
    --shower )
      doShower=true
      ;;
    --radius )
      doRadius=true
      ;;
    --ts )
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

# Check required arguments
if [ -z "$DATA_LOCATION" ]; then
  echo "Error: --source is required"
  usage
fi


# Set DATAPATH and SIMPATH based on DATA_LOCATION argument
case $DATA_LOCATION in
  local)
    DATAPATH="$LOCAL_DATAPATH/$DATAPASS"
    SIMPATH="$LOCAL_SIMPATH"
    ;;
  dev)
    DATAPATH="$DEV_DATAPATH/$DATAPASS"
    SIMPATH="$DEV_SIMPATH"
    ;;
  hy)
    DATAPATH="$HY_DATAPATH/$DATAPASS"
    SIMPATH="$HY_SIMPATH"
    ;;
  test)
    DATAPATH="$TEST_DATAPATH/$DATAPASS"
    SIMPATH="$TEST_SIMPATH"
    ;;
  *)
    echo "Invalid DATA_LOCATION: $DATA_LOCATION"
    exit 2
    ;;
esac

# Determine the data and mc sets and paths based on provided arguments
set_paths_and_triggers "$DATAPASS" "$MCTRIGGER"
if [ -n "$DATAPASS" ]; then
  DATAPATH="$DATAPATH/$DATA_SET"
fi

if [ -n "$MCTRIGGER" ]; then
  SIMPATH="$SIMPATH/$MC_SET"
fi


# default root file
DATATYPE="AnalysisResults_IP.root"
SIMTYPE="AnalysisResults_IP.root"

if [ "$DATA_LOCATION" == "dev" ]; then
  DATATYPE="AnalysisResults.root"
  SIMTYPE="AnalysisResults.root"
  FIXED_TYPE=true
else
  FIXED_TYPE=false
fi

# Output the set paths and file types
[ -n "$DATAPATH" ] && echo "DATAPATH: $DATAPATH"
[ -n "$SIMPATH" ] && echo "SIMPATH: $SIMPATH"
echo "DATATYPE: $DATATYPE"
echo "SIMTYPE: $SIMTYPE"
[ -n "$TRIGGER_NAME" ] && echo "TRIGGER_NAME: $TRIGGER_NAME"

# Build the options string for startSysAnalysisHfJetTagging.sh
OPTIONS=""
[ "$doShower" = true ] && OPTIONS="$OPTIONS --shower"
[ "$doRadius" = true ] && OPTIONS="$OPTIONS --radius"
[ "$doTrackSelection" = true ] && OPTIONS="$OPTIONS --ts"
[ "$doTrigger" = true ] && OPTIONS="$OPTIONS --trigger"
[ "$doPass" = true ] && OPTIONS="$OPTIONS --pass"
[ "$doTagger" = true ] && OPTIONS="$OPTIONS --tagger"

# Call startSysAnalysisHfJetTagging.sh with the appropriate options
./startSysAnalysisHfJetTagging.sh $OPTIONS --source "$DATA_LOCATION" --data "$DATA_SET" --mc "$MC_SET" --suffix "$SUFFIX"
