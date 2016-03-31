#! /bin/bash
# Syntax: junk [options] targetFileList  where options include -l, -n, --help
optionL="n"
optionN="n"
optionHelp="n"
junk="~/.junk"
mkdir -p $junk

# Iterate through all parameters for options
for i in $@; do
	case $i in
		"-l" ) optionL="y";;
		"-n" ) optionN="y";;
		"--help" ) optionHelp="y";;
	esac
done

# Help option to display usage info
if [ $optionHelp = "y" ]; then
	echo "Usage: junk [options] targetFileList"
	echo
	echo "The junk command takes the list of filenames and moves them to the users ~/.junk directory and it keeps the newest version of any duplicate files."
	echo 
	echo "Options include: -l -n --help"
	echo "     -l Lists the current contents of the .junk directory"
	echo "     -n Shows the number of files in the .junk directory and the amount of memory space consumed"
	echo
fi

#Move the files from the filename list to the junk directory, keeping the newest
files=${*: -1}
while read f; do
	mv -u $f ~/.junk/$f
done < $files

# List the current contents of the .junk directory
if [ $optionL = "y" ]; then
	echo "Contents of .junk: "
	echo $(ls ~/.junk)
	echo
fi

# Show the number of files and the memory space consumption
if [ $optionN = "y" ]; then
	echo "Number of files:" $(ls ~/.junk | wc -l)
	#Report the Memory space consumed
fi
