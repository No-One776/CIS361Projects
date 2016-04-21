#!/bin/bash
if [ $# -ne 1 ] || [ ! -f $* ]; then
	echo "Usage: bash shift.sh [FILE]"
	exit 1
fi 

while read -r line; do
  set $line
  start=""
    for i in $line; do
    start="$start $1"
    shift
    echo $* $start
done
done < $*
