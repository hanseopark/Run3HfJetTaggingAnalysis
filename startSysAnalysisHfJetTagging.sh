#!/bin/bash

# Define the jet types and categories
jet_types=("incjet" "lfjet" "cjet" "bjet")
data_types=("data" "sim")

# Boolean flags for systematics
doShower="false"
doRadius="false"

# Parse command-line arguments
while [ "$1" != "" ]; do
  case $1 in
    --shower )
      doShower=true
      ;;
    --radius )
      doRadius=true
      ;;
  esac
  shift
done

# Loop through jet types and categories to create directories
for jet_type in "${jet_types[@]}"; do
  for data_type in "${data_types[@]}"; do
    if [ "$doShower" = "true" ]; then
      directory="fig/${data_type}/${jet_type}/shower"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
    if [ "$doRadius" = "true" ]; then
      directory="fig/${data_type}/${jet_type}/radius"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    fi
  done
done

echo "Directories creation completed."

# Now call your ROOT script with these options
# Ensure your ROOT macro 'PlotSysHfJetTagging.C' can handle these boolean arguments
root -x -l -b -q 'task/PlotSysHfJetTagging.C("'"$doShower"'", "'"$doRadius"'")'
