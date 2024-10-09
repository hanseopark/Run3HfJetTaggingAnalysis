#!/bin/bash

DATAPASS_OPTIONS=("apass6" "LHC22o_apass4_lowIR" "LHC22f_apass4" "LHC22o_apass4")
MCTRIGGER_OPTIONS=("jj" "apass4" "apass4highIR" "apass6")

for DATAPASS_OPTION in "${DATAPASS_OPTIONS[@]}"; do
  for MCTRIGGER_OPTION in "${MCTRIGGER_OPTIONS[@]}"; do
    bash runTaggerQA.sh HY single "$DATAPASS_OPTION" "$MCTRIGGER_OPTION"
  done
done

