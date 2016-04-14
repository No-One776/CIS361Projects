#!/bin/bash

if [ ! -f "$*:0" ]; then
	echo "Usage: filterNoiseWords [FILE]"
	exit 1
fi 

echo $*

