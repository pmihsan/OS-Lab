echo "Enter n: "
read n

x=0
y=1
echo "Fibonacci series till $n is"
echo "$x"
echo "$y"
for((i=2;i<=$n;i++))
do
	z=$(expr $x + $y)
	echo "$z"
	x=$y
	y=$z
done

