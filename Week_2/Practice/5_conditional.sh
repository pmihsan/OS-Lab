echo "Enter n: "
read n

if [ "$n" -gt 0 ]
then 
	if (( ( $n > 5 & $(expr $n % 2) == 0 ) || ($n > 45) || ( $(expr $n % 9) == 0 ) ))
	then
		echo "$n is greater than 5 and divisible by 2"
		echo "or it is greater than 45 or it is divisible by 9"
	fi
elif [ "$n" -eq 0 ]
then
	echo "n is equal to zero"
else
	echo "$n is negative"
fi
