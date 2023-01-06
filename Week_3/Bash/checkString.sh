read -p "Enter string1: " s1
read -p "Enter string2: " s2

if [ $s1 ==  $s2 ]
then
	echo "$s1 and $s2 are same"
else
	echo "$s1 and $s2 are different"
fi
