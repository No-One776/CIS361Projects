#!/bin/bash
# Check for proper arguments
if [ $# -ne 1 ] || [ ! -f $* ]; then
	echo -e Please give a file argument to read.
	echo -e "\\nUsage: shiftLines [FILE]" 
	exit 1
fi

# Read the file and create shift combinations
while read line; do
	set $line
	first=""
	for i in $line; do
		first="$first $1"
		shift
		echo $* $first
	done
done < $*

