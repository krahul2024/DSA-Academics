#! /usr/bin/bash 

echo "Today is "  `date`
#echo -e "\nEnter path to directory"
#read dir_path 
#echo -e "\nContents of this path are :"   # using -e we can use c style \n and \t  see notes_one for more stuff
#ls $dir_path

# reading from a file and printing its contents line wise 
while read line 
do 
    echo $line 
done < notes_one.txt

sleep 1 
clear 


#name="Rahul"
#echo -e "Hello\t"$name

# command line arguments 
echo -e "Hello\t"$1

# writing to a file 
echo -e "This file contains name entered in the command line\t"$1  > output.txt
open output.txt

# appending to a file
echo -e "\nThis is appended text and contains the name entered in command line\t"$1 >> output.txt

# redirecting or writing output of command to a file 
ls > file.txt

ls >> output.txt
