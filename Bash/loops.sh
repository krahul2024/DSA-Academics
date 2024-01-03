#! /usr/bin/bash 

#printing square of all numbers from 1 to 20 
# for ((i = 0; i < 4; i++)); do
#     echo "Square of $i is -> $((i * i))"
#     if (($i & 1));then 
#     	echo "$i is Odd"
#     else echo "$i is Even"
#     fi
# done

# for ((i = 0; i < 4; i++)); do
#     printf "Square of %d is -> %d, %d is %s\n" $i $((i * i)) $i $([ $((i & 1)) -eq 1 ] && echo "Odd" || echo "Even")
# done


# printing fibonacci -> bash uses long int so it is possible to print upto 92 without getting overflows
# a=0
# b=1 
# echo "Enter the term you want to print fibonacci sequence upto"
# read term 

# printf "First two terms are %d and %d\n" $a $b 

# for ((i = 2; i <= term; i++)); do
# 	# echo $i
#     c=$(($a + $b))
#     a=$b
#     b=$c
#     printf "%dth term is: %d\n" $i $c
# done


# printing all primes between 2 and some number using while loop 
# echo "Enter the term you want to print primes upto :" 
# read term 
# i=2 
# while (($i<$term));do
# 	j=2
# 	while(($j<$i && $i%$j!=0));do 
# 		((j++)) 
# 	done

# 	if(($j==$i)); then 
# 		printf "%d " $i
# 	fi 

# 	((i++))
# done
# echo

# we can use break and continue statements similar to the c++ 

# loops for sequence 
# for i in {1..12}; do 
# 	echo $i
# done 

# we can also do ((i+=1))