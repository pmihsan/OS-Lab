read -p "Enter n: " n

ans=1

for((i=2;i<=$n;i++))
do
	ans=$(( $ans * $i ))
done

echo "Factorial of $n is $ans"
