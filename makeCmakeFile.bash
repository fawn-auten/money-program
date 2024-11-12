#!/bin/bash


# cmake file
cmakeFile="CMakeLists.txt"

# directory to find source files
inputDirectory="./src"

# directory for output files
outDirectory="./out"

# command for Cmake to use
cmakeCommand="add_executable"


# dont continue if cmake file exists
if [ -e $cmakeFile ]; then
    rm $cmakeFile
fi

# make cmake file with basic information
echo "project(Lab_5)
set (CMAKE_CXX_STANDARD 20)
cmake_minimum_required()
" >> $cmakeFile


# create compilation commands
for file in $(ls $inputDirectory)
do  

    sourceFileName="$inputDirectory/$file"
    outputFileName="$outDirectory/${file%%.cpp}"
    
    outputText="$cmakeCommand($outputFileName $sourceFileName)"
    echo $outputText >> $cmakeFile
done

# run cmake
cmakeOutput= "$(cmake CMakeLists.txt)"
echo "${cmakeOutput}"

