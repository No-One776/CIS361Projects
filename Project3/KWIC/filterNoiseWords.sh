#!/bin/bash
if [ $# -ne 1 ] || [ ! -f $* ]; then
	echo "Usage: bash filterNoiseWords [FILE]"
	exit 1
fi 
while read -r line; do
	set $line
	mainarray[$y]=$line
	let "y= $y + 1"
	while read noise; do
		if [ "$1" == "$noise" ]
		then 
		testarray[$x]=$line
		fi
	let "x= $x + 1"	
done < noise.dat
done
Array3=()
for xx in "${mainarray[@]}"; do
  skip=
  for yy in "${testarray[@]}"; do  
  [[ $xx == $yy ]] && { skip=1; break; }
  done
  [[ -n $skip ]] || Array3+=("$xx")
  done
  for i in "${Array3[@]}"; do
    echo $i
    done