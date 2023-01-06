echo "Enter a number"
read n

fact () {
	res=$1
	if [ $1 -le 1 ]
	then 
		return 1
	fi
	ans=1
	for((i=2;i<=$res;i++))
	do
		ans=$(($ans * $i))
	done
}

fact $n
echo "Factorial of $n is $ans"

