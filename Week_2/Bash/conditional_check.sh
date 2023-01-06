read -p "Enter n: " n
echo -e "To check whether a number is greater than 5 and divisible by 2 or it is greater than 45 or it is divisible by 9\n"
if (( $n > 0 ))
then
	echo "$n is positive"
	if (( ( $n > 5 && $(( $n % 2 == 0 )) ) || ( $n > 45 ) || ( $(( $n % 9 == 0 )) ) ))
	then
		echo "Given condition satisfied"
	else
		echo "Given condition failed"
	fi
elif (( $n < 0 ))
then
	echo "$n is negative"
else
	echo "Value is equal to zero"
fi
