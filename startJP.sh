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
FIGURE_NAME="$7"
SUFFIX="$8"
INCLUSION_TYPE="$9"
USE_LOG_SCALE="${10}"
PROCESS_DATA="${11}"
PROCESS_MCD="${12}"
PROCESS_MCP="${13}"
DO_TRACK_PROB="${14}"
DO_TEMPLATE_FIT="${15}"
FILL_EFFI="${16}"

# Execute the root command with the provided input files
# $1: Input root file for data, $2: Input root file for simulation
echo "Running analysis with the following parameters:"
echo "Data file path: $1"
echo "Simulation file path: $2"
echo "Use HY or local: $3"
echo "Data set: " $4
echo "MC set: " $5
echo "Trigger name: $6"
echo "Figure name: $7"
echo "fig_suffix: $8"
echo "Inclusion type: $9"
echo "Use log scale: ${10}"
echo "Process data: ${11}"
echo "Process MCD: ${12}"
echo "fitting MCP: ${13}"
echo "Do track probability: ${14}"
echo "Do template fit: ${15}"
echo "fill effi and purity: ${16}"

root -x -l -b -q "task/plotJP.cxx(\"$DATA_FILE_PATH\", \"$SIM_FILE_PATH\", \"$SOURCE_SET\", \"$DATA_SET\", \"$MC_SET\", \"$TRIGGER_NAME\", \"$FIGURE_NAME\", \"$SUFFIX\", $INCLUSION_TYPE, $USE_LOG_SCALE, $PROCESS_DATA, $PROCESS_MCD, $PROCESS_MCP, $DO_TRACK_PROB, $DO_TEMPLATE_FIT, $FILL_EFFI)"
