read -p "Enter the number " n

echo -n "Grade - "
case $n in 
	10)
		echo "O"
		;;
	9)
		echo "A+"
		;;
	8)
		echo "A"
		;;
	7)
		echo "B+"
		;;
	6)
		echo "B"
		;;
	5)
		echo "C"
		;;
	4)
		echo "F"
		;;
	*)
		echo "Not a valid number"
		;;
esac

