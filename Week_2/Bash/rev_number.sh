read -p "Enter n: " n
rev=0

while (( $n > 0 ))
do
	rem=$(expr $n % 10)
	rev=$(expr $rev \* 10)
	rev=$(expr $rev + $rem)
	n=$(($n / 10))
done
echo "Reverse is $rev"
