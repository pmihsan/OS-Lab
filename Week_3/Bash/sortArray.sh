read -p "Enter n: " n
echo $n
arr=()
for((i=0;i<$n;i++))
do
	read -p "Enter number: " arr[i]
done
echo "Given - ${arr[@]}"
for((i=0;i<$n;i++))
do
	for((j=0;j<$n-1;j++))
	do
		if (( ${arr[j]} > ${arr[j+1]} ))
		then
			temp=${arr[j+1]}
			arr[j+1]=${arr[j]}
			arr[j]=$temp
		fi
	done
done
echo "Sorted - ${arr[@]}"
