#!/bin/bash
# Create the project in a folder not added in git.
# Need cmake

#TODO
#	platform as a parameter
#	param clean platform -> delete "platform" folder
#	param clean all -> delete "projects" folder

projectFolder=projects
platform=Xcode

# First create folder for all builds
mkdir -p $projectFolder/$platform

# change directory
cd $projectFolder/$platform

# execute cmake command
cmake ../../. -G"$platform"