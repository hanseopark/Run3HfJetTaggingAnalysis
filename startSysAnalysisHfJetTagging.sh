# !bin/bash

# $1: input root file (AnalysisResult.root)

## TO MAKE runSys.sh
## # !bin/bash

# it needs to write cut information for direcoty

# Define the jet types and categories
jet_types=("incjet" "lfjet" "cjet" "bjet")
data_types=("data" "sim")
sys_types=("shower" "radius")

# Loop through jet types and categories to create directories
for jet_type in "${jet_types[@]}"; do
  for data_type in "${data_types[@]}"; do
    for sys_type in "${sys_types[@]}"; do
      directory="fig/${data_type}/${jet_type}/${sys_type}"
      mkdir -p "$directory"
      echo "Created directory: $directory"
    done
  done
done

echo "Directories creation completed."
root -x -l -b -q "task/PlotSysHfJetTagging.C"
