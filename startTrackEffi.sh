#!/bin/bash

# This script processes root files for data and simulation using PlotHfJetAnalysisTask.C
# It expects several arguments:
#   1. Input root file for data (AnalysisResult.root)
#   2. Input root file for simulation
#   3. Process IP data (true/false)
#   7. Process IP Monte Carlo data (true/false)

DATA_FILE_PATH="$1"
SIM_FILE_PATH="$2"
SOURCE_SET="$3"
DATA_SET="$4"
MC_SET="$5"
TRIGGER_NAME="$6"
INCLUSION_TYPE="$7"
USE_LOG_SCALE="$8"
PROCESS_DATA="$9"
PROCESS_MCD="${10}"
PROCESS_MCP="${11}"


# Execute the root command with the provided input files
# $1: Input root file for data, $2: Input root file for simulation
echo "Running analysis with the following parameters:"
echo "Data file path: $1"
echo "Simulation file path: $2"
echo "Use HY or local: $3"
echo "Data set: " $4
echo "MC set: " $5
echo "Trigger name: $6"
echo "Inclusion type: $7"
echo "Use log scale: $8"
echo "Process data: $9"
echo "Process MCD: ${10}"
echo "fitting MCP: ${11}"
root -x -l -b -q "task/plotTrackEffi.C(\"$DATA_FILE_PATH\", \"$SIM_FILE_PATH\", \"$SOURCE_SET\", \"$DATA_SET\", \"$MC_SET\", \"$TRIGGER_NAME\", $INCLUSION_TYPE, $USE_LOG_SCALE, $PROCESS_DATA, $PROCESS_MCD, $PROCESS_MCP)"
