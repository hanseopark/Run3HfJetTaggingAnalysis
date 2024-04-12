#!/bin/bash

# This script processes root files for data and simulation using PlotHfJetAnalysisTask.C
# It expects several arguments:
#   1. Input root file for data (AnalysisResult.root)
#   2. Input root file for simulation
#   3. Process IP data (true/false)
#   7. Process IP Monte Carlo data (true/false)

DATA_FILE_PATH="$1"
SIM_FILE_PATH="$2"
PROCESS_IP_DATA="$3"
PROCESS_IP_MCD="$4"
DO_FIT_JP="$5"
DO_TC="$6"
DO_TEMPLATE_FIT="$7"
PROCESS_JP_DATA="$8"
PROCESS_JP_MCD="$9"
PROCESS_SV_2PRONG_MCD="${10}"
PROCESS_SV_3PRONG_MCD="${11}"
TRIGGER_NAME="${12}"
IS_PARTICLE_LEVEL="${13}"
INCLUSION_TYPE="${14}"
USE_LOG_SCALE="${15}"
DATA_SET="${16}"
MC_SET="${17}"

# Execute the root command with the provided input files
# $1: Input root file for data, $2: Input root file for simulation
echo "Running analysis with the following parameters:"
echo "Data file path: $1"
echo "Simulation file path: $2"
echo "Process IP data: $3"
echo "Process IP MCD: $4"
echo "fitting for JP: $5"
echo "Doing TC: $6"
echo "Doing template fitting: $7"
echo "Process JP data: $8"
echo "Process JP MCD: $9"
echo "Process 2Prong on SV: ${10}"
echo "Process 3Prong on SV: ${11}"
echo "Trigger name: ${12}"
echo "Is particle level: ${13}"
echo "Inclusion type: ${14}"
echo "Use log scale: ${15}"
echo "Data set: " ${16}
echo "MC set: " ${17}

#root -x -l -b -q "task/PlotHfJetTaggingTask.C(\"$1\", \"$2\")"
root -x -l -b -q "task/PlotHfJetTaggingTask.C(\"$DATA_FILE_PATH\", \"$SIM_FILE_PATH\", $PROCESS_IP_DATA, $PROCESS_IP_MCD, $DO_FIT_JP, $DO_TC, $DO_TEMPLATE_FIT, $PROCESS_JP_DATA, $PROCESS_JP_MCD, $PROCESS_SV_2PRONG_MCD, $PROCESS_SV_3PRONG_MCD, \"$TRIGGER_NAME\", $IS_PARTICLE_LEVEL, $INCLUSION_TYPE, $USE_LOG_SCALE, \"$DATA_SET\", \"$MC_SET\")"

# Uncomment the following lines if needed for additional tasks
# root -x -l -b -q task/PlotHfJetHadronTask.C\(\"$1\"\)
# root -x -l -b -q task/TemplateFitHfJetTaggingTask.C\(\"$1\"\)
