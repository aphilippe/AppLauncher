#!/bin/bash
# Create the project in a folder not added in git.
# Need cmake

#TODO
#	platform as a parameter
#		Verify if platform exists
#	param clean platform -> delete "platform" folder
#	param clean all -> delete "projects" folder

projectFolder=projects

check_params () {
	# We need at least one parameter
	if [ -z $1 ]
	then
		echo >&2 "How to use $0 :"
		echo >&2 "$0 <name of plateform> : create projet for the platform"
		return 0
	elif [ $1 == cleanAll ]
	then
		return 1
	elif [ $1 == clean ]
	then
		return 2
	else
		return 3
	fi
}

create_project () {
	platform=$1
	# First create folder for all builds
	mkdir -p $projectFolder/$platform
	# change directory
	cd $projectFolder/$platform
	# execute cmake command
	cmake ../../. -G"$platform"
}

check_params $@
retval=$?
if [ $retval == 1 ]
then
	echo "cleanAll"
elif [ $retval == 2 ]
then
	echo "clean"
elif [ $retval == 3 ]
then
	create_project $@
fi

