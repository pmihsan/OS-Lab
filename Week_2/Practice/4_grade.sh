echo "Enter the GPA"
read num
echo -n "Grade - "
case "$num" in 
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
		echo "F"
	;;
	*)
		echo "Enter a valid GPA"
	;;
esac

