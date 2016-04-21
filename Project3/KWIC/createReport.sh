#!/bin/bash
out=0
in=0
rm -f tempfile.txt
if [ $# -ne 1 ]; then
	echo "Usage: bash createReport [FILE]"
	exit 1
fi 
while read line; do
  set $line
  let out++
  echo $line >> tempfile.txt
  done
  #Get output in order
  cat tempfile.txt | sort -u > outfile.out
  echo "-------------------------------------" >> outfile.out
  echo "Sample Output in File outfile.out" >> outfile.out
  echo "-------------------------------------" >> outfile.out
  echo "The number of lines in the output file:" $out >> outfile.out

echo >> outfile.out

while read stuff; do
  set $stuff
  echo $stuff >> outfile.out
  let in++
  done < test.dat
  echo "-------------------------------------" >> outfile.out
  echo "Sample Input in File test.dat" >> outfile.out
  echo "-------------------------------------" >> outfile.out
  echo "The number of lines in the input file:" $in >> outfile.out