#! /usr/bin/bash 

# allowing user to enter input in the same line as the instruction is shown
# like enter your username ..username 
#read -p 'Username : ' username
#echo 'Username entered is : ' $username



# making input silent or not show the input like password 
#read -sp 'Password : ' password 
#echo
#echo 'Password entered is : ' $password 


# allowing user to enter multiple inputs and store them inside an array 
# echo 'Enter names '
# read -a names

# echo "Names entered are :${names[0]} , ${names[1]}"
# echo "All names are : ${names[*]} " # this prints all the names in array 



# let's say we didn't define a variable name against the read command then the value is stored in a 
# default variable namee REPLY     

# read 
# echo $REPLY 

# using ternary operators 
echo "Enter a number: "
read number
result=$((number%2==0?2*2:33))
# echo $result

echo $number  $([ $((number & 1)) -eq 1 ] && echo "Odd" || echo "Even")
