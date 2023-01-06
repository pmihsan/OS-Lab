echo "Enter n: "
read n
neg=0
res=$n

if [ $n -lt 0 ]
then 
	n=$(expr $n \* -1)
	neg=1
fi

rev=0

while [ "$n" -gt 0 ]
do
	num=$(expr $n % 10)
	temp=$(expr $rev \* 10)
	rev=$(expr $temp + $num)
	n=$(expr $n / 10)
done

if [ $neg -eq 1 ]
then 
	rev=$(expr $rev \* -1)
fi

if [ $res -eq $rev ]
then 
	echo "The given number $res is palindrome"
else
	echo "The given number $res is not palindrome"
fi

