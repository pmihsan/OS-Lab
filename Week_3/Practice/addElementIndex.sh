arr=(10 23 34 12 45)

n=${#arr[@]}

echo "Given array ${arr[@]}"

echo "Enter an index and element to insert " 
read ins val

for ((i=$n;i>$ins;i--))
do
	arr[i]=${arr[$(($i-1))]}
done
unset arr[$ins]
arr[$ins]=$val

echo "Given array ${arr[@]}"

