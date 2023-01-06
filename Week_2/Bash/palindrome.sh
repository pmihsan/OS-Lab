read -p "Enter n: " n
rev=0
num=$n
while (( $n > 0 ))
do
	rem=$(expr $n % 10)
	rev=$(expr $rev \* 10)
	rev=$(expr $rev + $rem)
	n=$(($n / 10))
done
if [ $num -eq $rev ]
then 
	echo "$num is palindrome"
else
	echo "$num is not a palindrome"
fi
