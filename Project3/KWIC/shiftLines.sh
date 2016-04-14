#!/bin/bash

if [ $# -ne 1 -o -d "$*:0" ]; then
	echo -e Please give a file argument to read.
	echo -e "\\nUsage: shiftLines [FILE]" 
	exit 1
fi

echo $*

while read line; do
	set $line
	first=""
	for i in $line; do
		first="$first $1"
		shift
		echo $* $first
	done
done < $*

