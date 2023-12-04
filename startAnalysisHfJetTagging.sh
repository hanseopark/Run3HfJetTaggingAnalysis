# !bin/bash

# $1: input root file (AnalysisResult.root)

## TO MAKE run.sh
## # !bin/bash
## INPUT=/path/
## bash startAnalysisHfJetTagging.sh $INPUT

# it needs to write cut information for direcoty
mkdir -p fig/data/incjet fig/data/lfjet fig/data/cjet fig/data/bjet fig/sim/incjet fig/sim/lfjet/ fig/sim/cjet/ fig/sim/bjet
root -x -l -b -q "task/PlotHfJetTaggingTask.C(\"$1\", \"$2\", \"$3\")"

#root -x -l -b -q task/PlotHfJetHadronTask.C\(\"$1\"\)
#root -x -l -b -q task/TemplateFitHfJetTaggingTask.C\(\"$1\"\)
