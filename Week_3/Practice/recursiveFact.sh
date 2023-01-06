read -p "Enter n:" n

fact () {
	num=$1
	if [ $num -le 2 ]
	then
		echo $num
	else
		f=$(( $num - 1 ))
		f=$( fact $f )
		f=$(( $f * $num ))
		echo $f
	fi
}

echo -n "Factorial of $n is "
fact $n

