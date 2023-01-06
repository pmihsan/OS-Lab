echo "Enter n: "
read n
rev=0
while [ "$n" -gt 0 ]
do
	num=$(expr $n % 10)
	temp=$(expr $rev \* 10)
	rev=$(expr $temp + $num)
	n=$(expr $n / 10)
done
echo "Reverse of n is : $rev" 

