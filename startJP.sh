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
SUFFIX="$7"
INCLUSION_TYPE="$8"
USE_LOG_SCALE="$9"
PROCESS_DATA="${10}"
PROCESS_MCD="${11}"
PROCESS_MCP="${12}"
FILL_RUN2DEF="${13}"
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
echo "fig_suffix: $7"
echo "Inclusion type: $8"
echo "Use log scale: $9"
echo "Process data: ${10}"
echo "Process MCD: ${11}"
echo "fitting MCP: ${12}"
echo "fill run 2 definition: ${13}"
echo "Do track probability: ${14}"
echo "Do template fit: ${15}"
echo "fill effi and purity: ${16}"

root -x -l -b -q "task/plotJP.cxx(\"$DATA_FILE_PATH\", \"$SIM_FILE_PATH\", \"$SOURCE_SET\", \"$DATA_SET\", \"$MC_SET\", \"$TRIGGER_NAME\", \"$SUFFIX\", $INCLUSION_TYPE, $USE_LOG_SCALE, $PROCESS_DATA, $PROCESS_MCD, $PROCESS_MCP, $FILL_RUN2DEF $DO_TRACK_PROB, $DO_TEMPLATE_FIT, $FILL_EFFI)"
