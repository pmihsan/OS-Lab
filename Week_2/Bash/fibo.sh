read -p "Enter n: " n

x=0
y=1

echo "Fibonacci series till $n"
for (( i=0;i<=$n;i++ ))
do 
	if (( $i == 0 ))
	then
		echo -n "$x "
	elif (( $i == 1 ))
	then
		echo -n "$y "
	else
		z=$(( $x + $y ))
		echo -n "$z "
		x=$y
		y=$z
	fi
done
echo ""
