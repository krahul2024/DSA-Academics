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

```