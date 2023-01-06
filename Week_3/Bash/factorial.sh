read -p "Enter a number: " n
echo $n

function fact () {
	if (( $1 == 1 || $1 == 2 ))
	then 
		echo "Factorial of $1 is $1"
	else
		ans=1
		for((i=2;i<=$1;i++))
		do
			ans=$(($ans * $i))
		done
		echo "Factorial of $1 is $ans"
	fi
}
fact $n
