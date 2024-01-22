#!/bin/bash

# This script processes root files for data and simulation using PlotJetAnalysisTask.C
# It expects two arguments:
#   1. Input root file for data (AnalysisResult.root)
#   2. Input root file for simulation

# Example usage to create run.sh:
#   #!/bin/bash
#   TCDATAINPUT=/path/to/data
#   TCSIMINPUT=/path/to/simulation
#   bash startAnalysisHfJetTagging.sh $TCDATAINPUT $TCSIMINPUT

# Define the jet types and categories
data_types=("data" "sim")
para_types=("mix" "resolution" "pT")

# Loop through jet types and categories to create directories
for data_type in "${data_types[@]}"; do
  for para_type in "${para_types[@]}"; do
    basedir="fig/${data_type}/general/${para_type}"

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
root -x -l -b -q "task/PlotJetAnalysisTask.C(\"$1\", \"$2\")"
