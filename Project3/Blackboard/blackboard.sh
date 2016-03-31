#!/bin/bash
# Author: Justin Rohr
# Bash script reads the current directory and looks for files from blackboard. 
# 1. Unzips a downloaded file into a data directory under the cwd named by the user 
# 2. Create a sub-directory under the "Data" directory by each students id
# 4. Test run each students program: building the program from a makefile and executing it against an input file - both reside in the CWD
# 5. Save the log of the screen output from student testing into a file named report in the CWD

# Checks for file arguement and gives usage info if none
if [ $# -ne 1 ]; then
   echo -e \\nUsage: $0 downloaded-Bb.zip 1>&2
   echo Available zipped file"(s)" in directory: 1>&2
   for f in *.zip; do
      echo -e \\t$f 1>&2
   done
   exit 1
fi

# Determine the file prefixes from the content of the zip (I.e. Project 4_)
((k = 1))
while [ $(zipinfo -1 $1 | cut -c 1-$k | uniq | wc -l) -eq 1 ]; do
    ((k++))
done
((k--))
prefix=$(zipinfo -1 $1 | cut -c 1-$k | uniq)

#Create a directory based on the zip files name
#TODO: Use user input?
TMP=$(echo $1  | sed 's/.zip$//')
mkdir -p $TMP
unzip -q $1 -d $TMP
cd $TMP

# Read files
for f in "${prefix}"*; do
   # Remove the prefix and the attempt information
   name=$(echo $f | sed "s/^$prefix//" | sed -E "s/_attempt_[-0-9]{19}//")
   user=$(echo $name | sed -E "s/([^_]+)_.*$/\1/")
   if [ $name =  $user ]; then
      # Users memo file
      user=$(echo $user | sed "s/\.txt$//") 
      file=memo.txt
   else
      # Remove the user name prefix
      file=$(echo $name | sed "s/$user\_//" )
   fi
   if [ ! -d $user ]; then
      # create a new directory in case we need one
      mkdir -p $user
   fi

   # move and rename the file
   mv "$f" "$user/$file"
done
cd ..

#TODO Part 4 & 5
report="Report.txt"
for f in "$TMP/"*; do
    if [[ -d $f ]]; then
	user=$(echo $f | sed "s/^$TMP\///")
	echo $user >> $report
	make -f makefile -C $f/ >> $report
	make test -f makefile -C $f/ >> $report 
    fi
done

