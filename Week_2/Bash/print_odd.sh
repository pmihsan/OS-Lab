read -p "Enter n: " n
echo "Print first odd numbers till $n"

for((i=1;i<=$n;i++))
do
	if (( $(($i % 2)) != 0 ))
	then
		echo -n "$i "
	fi
done
echo 
