read -p "Enter three number " a b c
ans=$a
if (( $a > $b ))
then 
	if (( $a > $c ))
	then
		ans=$a
	else
		ans=$c
	fi
elif (( $b > $c ))
then 
	if (( $b > $a ))
	then
		ans=$b
	else
		ans=$a
	fi
elif (( $c > $a ))
then
	if (( $c > $b ))
	then
		ans=$c
	else
		ans=$b
	fi
fi
echo "Maximum is $ans"
