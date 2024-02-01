### Bash Basics 

* ls 
```bash
	
	$ ls # lists only non-hidden files and directories 
	 Bash     'Bit Manipulation'  'Data Mining'           Graphs      Miscellaneous   problems-solutions.md   Sorting-Searching
	 bash.md   contest            'Dynamic Programming'  'maths&NT'   Problems        README.md      

	 $ ls -l # list of all(non-hidden) the files with detailed information permissions, sizes, last-modified etc.
			total 8
			drwxr-xr-x 2 root root 4096 Dec 16 07:12 data
			drwxr-xr-x 2 root root 4096 Dec 16 07:12 scripts


	# list all the files and directories(hidden and visible ones)
	$ ls -a
	.  ..  data  newfile.txt  scripts
	
	# list all the files and directories(both hidden and visible) with detailed information, various commands can be combined 
	$ ls -a -l
	total 16
	drwxr-xr-x 1 root root 4096 Feb  1 01:02 .
	drwxr-xr-x 1 root root 4096 Feb  1 00:51 ..
	drwxr-xr-x 2 root root 4096 Dec 16 07:12 data
	-rw-r--r-- 1 root root    0 Feb  1 01:02 newfile.txt
	drwxr-xr-x 2 root root 4096 Dec 16 07:12 scripts


	# List all the files recursively(list of all the files in each directory)
	$ ls -R
	.:
	data  newfile.txt  scripts

	./data:
	BankWages.csv  CASchools.csv        annual-avg-temp-anomaly.json
	BondYield.csv  Electricity1970.csv  current_senators.json

	./scripts:
	calculator.py  nobel_prizes.json  pinball.py


	# We can combine above command with -a to list the hidden ones also
	$ ls -a -R
	.:
	.  ..  data  newfile.txt  scripts

	./data:
	.                .records314.dat  .records561.dat  BankWages.csv        annual-avg-temp-anomaly.json
	..               .records329.dat  .records587.dat  BondYield.csv        current_senators.json
	.records104.dat  .records385.dat  .records817.dat  CASchools.csv
	.records292.dat  .records553.dat  .records927.dat  Electricity1970.csv

	./scripts:
	.  ..  calculator.py  nobel_prizes.json  pinball.py


	# The above command can also be combined with -l to list all the detailed information recursively, also we can use $ -lh instead of $ -l to get the size information in human readable format 

	$ ls -a -lh -R
	.:
	total 16K
	drwxr-xr-x 1 root root 4.0K Feb  1 01:02 .
	drwxr-xr-x 1 root root 4.0K Feb  1 00:51 ..
	drwxr-xr-x 2 root root 4.0K Dec 16 07:12 data
	-rw-r--r-- 1 root root    0 Feb  1 01:02 newfile.txt
	drwxr-xr-x 2 root root 4.0K Dec 16 07:12 scripts

	./data:
	total 312K
	drwxr-xr-x 2 root root 4.0K Dec 16 07:12 .
	drwxr-xr-x 1 root root 4.0K Feb  1 01:02 ..
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records104.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records292.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records314.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records329.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records385.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records553.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records561.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records587.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records817.dat
	-rw-r--r-- 1 root root    7 Dec 16 07:12 .records927.dat
	-rw-r--r-- 1 root root  15K Dec 16 07:12 BankWages.csv
	-rw-r--r-- 1 root root 1.4K Dec 16 07:12 BondYield.csv
	-rw-r--r-- 1 root root  78K Dec 16 07:12 CASchools.csv
	-rw-r--r-- 1 root root 9.5K Dec 16 07:12 Electricity1970.csv
	-rw-r--r-- 1 root root 5.5K Dec 16 07:12 annual-avg-temp-anomaly.json
	-rw-r--r-- 1 root root 142K Dec 16 07:12 current_senators.json

	./scripts:
	total 228K
	drwxr-xr-x 2 root root 4.0K Dec 16 07:12 .
	drwxr-xr-x 1 root root 4.0K Feb  1 01:02 ..
	-rw-r--r-- 1 root root    0 Dec 16 07:12 calculator.py
	-rw-r--r-- 1 root root 220K Dec 16 07:12 nobel_prizes.json
	-rw-r--r-- 1 root root    0 Dec 16 07:12 pinball.py


	# to display all the files with an extension(here it is csv)
	$ ls data/*.csv
	data/BankWages.csv  data/CASchools.csv
	data/BondYield.csv  data/Electricity1970.csv

	# to see the list of all files and directories(hidden : directories which start with .directory_name, .file_name)
	$ ls -la
	total 16
	drwxr-xr-x 1 root root 4096 Dec 16 07:12 .
	drwxr-xr-x 1 root root 4096 Feb  1 15:34 ..
	drwxr-xr-x 2 root root 4096 Dec 16 07:12 data
	drwxr-xr-x 2 root root 4096 Dec 16 07:12 scripts

	$ ls -lad directory/.?* # to get the list of all hidden files , -l is for long list, -a is for listing all the entries, -d is for listing all the directories and not their content. 

	# .?* -> matches all the files and directories whose name starts with . 

```

* cat 

```bash
	
	# to read contents of a file line by line 
	$ cat data/Electricity1970.csv 
	"","cost","output","labor","laborshare","capital","capitalshare","fuel","fuelshare"
	"1",0.213,8,6869.47,0.3291,64.945,0.4197,18,0.2512
	"4",3.0427,869,8372.96,0.103,68.227,0.2913,21.067,0.6057

```

* tail

```bash
	
	$ tail filename.ext # displays some of the last lines of the file 

	$ tail -n no_of_lines filename.ext # displays last no_of_lines of the file 

	$ tail -no_of_lines filename # this can also be used to get last no_of_lines of the file 


```

* head 
```bash
	$ head filename.ext # displays some of the starting lines of the file 

	$ head -n no_of_lines filename.ext # displays starting no_of_lines of the file 

```

* wc 

```bash
	
	# to count the no. of words in a file 
	$ wc -w data/current_senators.json 
	11755 data/current_senators.json

	$ wc -l filename # to count the no. of lines in a file 

	# we can also combine this command with `cat` command, cat will print all the text in terminal and then wc -l will count all the lines. 

	$ cat data/Electricity1970.csv | wc -l
	159

	$ wc -c filename # to count the no. of characters in a file 

	$ wc data/current_senators.json  # wc gives count of all the lines, words, characters 
  	5165  11755 145180 data/current_senators.json

  	$ wc -l -w

```

* echo 

```bash 
	
	# this creates a file named sales.csv in the my-data directory with the mentioned string/parameters
	$ echo "ID,Name,Concept,Quantity,Price,Total,Comments" > my-data/sales.csv 

```

* rm

*files deleted using rm are permanent, there is no recycle-bin*

```bash 
	
	# delete a single file 
	$ rm file_path

	# delete a directory 
	$ rm -r directory_path 

	# delete multiple files 
	$ rm file_path1 file_path2 ...

	# interactive removal -> ask for confirmation
	$ rm -i file_path  

	# force removal 
	$ rm -f file_path 

	#verbose -> display information about each of the file which is being deleted 
	$ rm -v file_path 

	# remove an empty directory 
	$ rmdir directory_path 

	#remove all .ext files 
	$rm *.extension 

```

* mv and cp

```bash 
	
	$ mv source destination # to move files 
	$ cp source destination # to copy files

	# preserve metadata(permissions, timestamps and others) during copy
	$ cp -a source destination

```

```bash
	
	# we can use $ env or $ printenv to get details about the environment, or search for some field in the env, both do the same things. 

	$ env | grep -i SECRET_PASSWORD
	SECRET_PASSWORD=5362ba84-a144-4e7f-9228-460c6bfb7c50

	$ printenv | grep -i SECRET_PASSWORD
	SECRET_PASSWORD=5362ba84-a144-4e7f-9228-460c6bfb7c50
	
```

* Symlink 
*A symlink, short for symbolic link, is a type of file that serves as a reference or pointer to another file or directory in a filesystem. Unlike a hard link, which directly points to an inode on disk, a symbolic link contains the path to the target file or directory.*
```bash

	# create a symlink 
	# ln is the command used to create links between files. The name "ln" stands for "link."
	# The -l option is used with the ln command to create a hard link, When used with ls command, it displays detailed information about files, including permissions, owner, group, size, modification time, and link count.

	# The -s option is used with the ln command to create a symbolic link (symlink or soft link), When used with ls command, it can be used to indicate symlink files in the listing.

	$ ln -s file_path path_of_link_to_be_created
```
