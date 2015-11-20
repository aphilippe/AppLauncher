#!/bin/bash
# Create the project in a folder not added in git.
# Need cmake

#TODO
#	platform as a parameter
#		Verify if platform exists
#	param clean platform -> delete "platform" folder
#	param clean all -> delete "projects" folder

projectFolder=projects

# We need at least one parameter
if [ -z $1 ]
then
	echo "How to use $0 :"
	echo "$0 <name of plateform> : create projet for the platform"
	exit
fi

platform=$1

# First create folder for all builds
mkdir -p $projectFolder/$platform

# change directory
cd $projectFolder/$platform

# execute cmake command
cmake ../../. -G"$platform"