#!/bin/bash

# Define the jet types and categories
jet_types=("incjet" "lfjet" "cjet" "bjet")
data_types=("data" "sim")

# Boolean flags for systematics
doShower="false"
doRadius="false"
doTrackSelection="false"
doTrigger="false"
doPass="false"
doTagger="false"

# Define a function to display help message
show_help() {
  echo "Usage: bash startSysAnalysisHfJetTagging.sh [OPTION]..."
  echo "Run the HfJetTagging analysis with specified options."
  echo ""
  echo "Available options:"
  echo "  --shower            Enable shower systematics analysis"
  echo "  --radius            Enable radius systematics analysis"
  echo "  --ts                Enable track selection systematics analysis"
  echo "  --trigger           Enable trigger systematics analysis"
  echo "  --pass              Enable apass systematics analysis"
  echo "  --tagger              Enable tagger point systematics analysis"
  echo "  -h, --help          Display this help message and exit"
  echo ""
  echo "Example:"
  echo "  bash startSysAnalysisHfJetTagging.sh --radius --ts"
}


if [ "$#" -eq 0 ]; then
  show_help
  exit 1
fi


# Parse command-line arguments
while [ "$1" != "" ]; do
  case $1 in
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
  esac
  shift
done

# Loop through jet types and categories to create directories
for jet_type in "${jet_types[@]}"; do
  for data_type in "${data_types[@]}"; do
    if [ "$doShower" = "true" ]; then
      directory="fig/${data_type}/sys/${jet_type}/shower"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
    if [ "$doRadius" = "true" ]; then
      directory="fig/${data_type}/sys/${jet_type}/radius"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
    if [ "$doTrackSelection" = "true" ]; then
      directory="fig/${data_type}/sys/${jet_type}/trackselection"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
    if [ "$doTrigger" = "true" ]; then
      directory="fig/${data_type}/sys/${jet_type}/trigger"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
    if [ "$doPass" = "true" ]; then
      directory="fig/${data_type}/sys/${jet_type}/pass"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
    if [ "$doTagger" = "true" ]; then
      directory="fig/${data_type}/sys/${jet_type}/tagger"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
  done
done

echo "Directories creation completed."

# Now call your ROOT script with these options
# Ensure your ROOT macro 'PlotSysHfJetTagging.C' can handle these boolean arguments
root -x -l -b -q 'task/PlotSysHfJetTagging.C("'"$doShower"'", "'"$doRadius"'", "'"$doTrackSelection"'", "'"$doTrigger"'", "'"$doPass"'", "'"$doTagger"'")'
