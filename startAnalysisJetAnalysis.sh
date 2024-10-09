#!/bin/bash

# This script processes root files for data and simulation using PlotJetAnalysisTask.C
# It expects several arguments:
#   1. Input root file for data (AnalysisResult.root)
#   2. Input root file for simulation
#   3. Process data (true/false)
#   4. Process data with Rho Area Sub (true/false)
#   5. Process data with Event-wise Constituent Subtraction (true/false)
#   6. Process data with Subjet Matching (true/false)
#   7. Process Monte Carlo data (true/false)
#   8. Process Monte Carlo data with weights (true/false)
#   9. Process Monte Carlo Pythia data (true/false)
#  10. Process Monte Carlo Pythia data with weights (true/false)
#  11. Process Monte Carlo Pythia and Monte Carlo Data Matched (true/false)
#  12. Process Monte Carlo Pythia and Monte Carlo Data Matched with weights (true/false)
#  13. Process data with trigger information (true/false)
#  14. Process tracking efficiency (true/false)
#  15. Process tracking efficiency with weights (true/false)
#  16. Process tracking with subjet information (true/false)
#  17. Process Rho calculation (true/false)
#  18. Process Random Cone calculation (true/false)
#  19. Trigger name
#  20. Use inclusive type (true/false)
#  21. Use log scale (true/false)

DATA_FILE_PATH="$1"
SIM_FILE_PATH="$2"
PROCESS_DATA="$3"
PROCESS_DATA_RHO_AREA_SUB="$4"
PROCESS_DATA_EVT_WISE_CONST_SUB="$5"
PROCESS_DATA_SUB_MATCHED="$6"
PROCESS_MCD="$7"
PROCESS_MCD_WEIGHTED="$8"
PROCESS_MCP="$9"
PROCESS_MCP_WEIGHTED="${10}"
PROCESS_MCP_MCD_MATCHED="${11}"
PROCESS_MCP_MCD_MATCHED_WEIGHTED="${12}"
PROCESS_DATA_TRIGGER="${13}"
PROCESS_TRACK="${14}"
PROCESS_TRACK_WEIGHTED="${15}"
PROCESS_TRACK_SUB="${16}"
PROCESS_RHO="${17}"
PROCESS_RANDOM_CONE="${18}"
TRIGGER_NAME="${19}"
WITH_INCLUSIVE="${20}"
USE_LOG_SCALE="${21}"

# Define the jet types and categories
data_types=("data" "sim" "dataVSsim")

# Loop through jet types and categories to create directories
for data_type in "${data_types[@]}"; do
  basedir="fig/${data_type}/general"

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

# Execute the root command with the provided input files and parameters
# $1: Input root file for data, $2: Input root file for simulation
echo "Running analysis with the following parameters:"
echo "Data file path: $1"
echo "Simulation file path: $2"
echo "Process data: $3"
echo "Process data with Rho Area Sub: $4"
echo "Process data with Event-wise Constituent Subtraction: $5"
echo "Process data with Subjet Matching: $6"
echo "Process Monte Carlo data: $7"
echo "Process Monte Carlo data with weights: $8"
echo "Process Monte Carlo Pythia data: $9"
echo "Process Monte Carlo Pythia data with weights: ${10}"
echo "Process Monte Carlo Pythia and Monte Carlo Data Matched: ${11}"
echo "Process Monte Carlo Pythia and Monte Carlo Data Matched with weights: ${12}"
echo "Process data with trigger information: ${13}"
echo "Process tracking efficiency: ${14}"
echo "Process tracking efficiency with weights: ${15}"
echo "Process tracking with subjet information: ${16}"
echo "Process Rho calculation: ${17}"
echo "Process Random Cone calculation: ${18}"
echo "Trigger name: ${19}"
echo "Use inclusive type: ${20}"
echo "Use log scale: ${21}"

root -x -l -b -q "task/PlotJetAnalysisTask.C(\"$DATA_FILE_PATH\", \"$SIM_FILE_PATH\", $PROCESS_DATA, $PROCESS_DATA_RHO_AREA_SUB, $PROCESS_DATA_EVT_WISE_CONST_SUB, $PROCESS_DATA_SUB_MATCHED, $PROCESS_MCD, $PROCESS_MCD_WEIGHTED, $PROCESS_MCP, $PROCESS_MCP_WEIGHTED, $PROCESS_MCP_MCD_MATCHED, $PROCESS_MCP_MCD_MATCHED_WEIGHTED, $PROCESS_DATA_TRIGGER, $PROCESS_TRACK, $PROCESS_TRACK_WEIGHTED, $PROCESS_TRACK_SUB, $PROCESS_RHO, $PROCESS_RANDOM_CONE, \"$TRIGGER_NAME\", $WITH_INCLUSIVE, $USE_LOG_SCALE)"
