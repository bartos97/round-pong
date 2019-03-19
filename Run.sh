#!/bin/bash

if [ $# = 1 ]
then
	if [ $1 = "release" ]
	then
		./bin/linux-Release-x86_64/round-pong/round-pong
		exit
	elif [ $1 = "debug" ]
	then
		./bin/linux-Debug-x86_64/round-pong/round-pong
		exit
	fi
fi

echo 	'You need to specify which configuration you want to run:'
echo	'Run `./Run.sh release` or `./Run.sh debug`'
echo	'Make sure that given configuration has been already made via: '
echo	'`make config=release` or `make config=debug`'
