#! /usr/bin/bash 
# echo "Hello bro! You are seeing this string in terminal"

# # this is a comment and it won't be executed by the script  
# # talking about the variables in scripting 
# # there are two types of variables 
# # system variables -> maintained by system and are defined in BLOCK letters, user defined variables 

# # some system variables 

# echo $BASH # gives location and name of the shell 
# echo $BASH_VERSION 
# echo $HOME 
# echo $PWD 


# # user defined variables 
# name="Rahul" 
# echo user defined variable is $name # whole string is printed 

# # reading user inputs 
# # read command is used for taking input from user 

# echo "Enter some text"
# read textByUser 
# echo Entered text is $textByUser 

# # using multiple variables 
# echo "enter two space seperated texts"
# read text1 text2 
# echo $text1 $text2


#  using conditional statements two ways to write 
echo "Enter a number" 
read number 
# if [[ $number -gt 9 ]]; then 
# 	echo "Number entered is not less than 10" 
# elif [[ $number -lt 0 ]]; then 
# 	echo "Number entered is less than 10 but it is greater than 0"
# else echo "Number entered is Zero"
# fi

if ((number >= 10)); then 
	echo -e "Number is not less than 10\n";  
elif ((number <= 5)); then 
	echo -e "Number is not less than 10 and greater than 4\n"
else echo -e "Number is less than 5\n" 
fi 


# checking if a number is odd/even
if ((number%2 == 1)); then 
	echo "The number is odd."
else echo "The number is even."
fi

# number1=5
# number2=2

# bitwise_and=$(($number1 & $number2))
# echo "Bitwise AND: $bitwise_and"


if (($(($number & 1)))); then 
	echo "odd number"
else echo "even number" 
fi