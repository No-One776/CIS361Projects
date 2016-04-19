#!/bin/bash

if [ $# -ne 1 ] || [ ! -f $* ]; then
	echo "Usage: filterNoiseWords [FILE]"
	exit 1
fi 

while read -r line; do
	echo $line
	while read noise; do
		echo $noise	
	 #TODO Check the line start against noise words
	done < $*
done
