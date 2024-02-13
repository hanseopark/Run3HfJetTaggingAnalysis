#!/bin/bash

# This script processes root files for different jet types and categories using PlotHfJetTaggingTask.C
# It expects two arguments:
#   1. Input root file for data (e.g., AnalysisResult.root)
#   2. Input root file for simulation

# Example usage for creating run.sh:
#   #!/bin/bash
#   TCDATAINPUT=/path/to/data
#   TCSIMINPUT=/path/to/simulation
#   bash startAnalysisHfJetTagging.sh $TCDATAINPUT $TCSIMINPUT

# Define the jet types and data categories
jet_types=("incjet" "lfjet" "cjet" "bjet")
data_types=("data" "sim")

# Loop through jet types and data categories to create directories
for jet_type in "${jet_types[@]}"; do
  for data_type in "${data_types[@]}"; do
    basedir="fig/${data_type}/${jet_type}"

    # Check if the directory already exists
    if [ ! -d "$basedir" ]; then
      # The directory does not exist, so create it
      mkdir -p "$basedir"
      echo "Created directory: $basedir"
    else
      # The directory already exists, skip creating it
      echo "Directory already exists, skipping: $basedir"
    fi
  done
done

# Execute the root command with the provided input files
# $1: Input root file for data, $2: Input root file for simulation
root -x -l -b -q "task/PlotHfJetJPTaggingTask.C(\"$1\", \"$2\")"
