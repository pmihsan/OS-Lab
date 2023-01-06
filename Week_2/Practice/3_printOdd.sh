echo "Enter n: "
read n

for((i=1;i<=$n;i++))
do
	if [ $(expr $i % 2) -ne 0 ] 
	then
		echo $i
	fi
done

