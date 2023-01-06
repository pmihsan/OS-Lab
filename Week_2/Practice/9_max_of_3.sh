echo "Enter three number"
read a b c

if [ $a -gt $b ]
then
	if [ $a -gt $c ]
	then
		echo "$a is greater"
	else 
		echo "$c is greater"
	fi
elif [ $b -gt $c ]
then
	if [ $b -gt $a ]
	then
		echo "$b is greater"
	else 
		echo "$a is greater"
	fi
elif [ $c -gt $a ]
then
	if [ $c -gt $b ]
	then
		echo "$c is greater"
	else 
		echo "$b is greater"
	fi
fi

