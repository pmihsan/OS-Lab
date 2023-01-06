read -p "Enter n: " n
echo $n
arr=()
for((i=0;i<$n;i++))
do
	read -p "Enter number: " arr[i]
done
echo "Given - ${arr[@]}"
read -p "Enter an index and element to add " ind ele
for((i=$n;i>$ind;i--))
do
	arr[i]=${arr[i-1]}
done
unset arr[ind]
arr[ind]=$ele
echo "After inserting the element $ele at index $ind - ${arr[@]}"
