echo -e "Program to collect student details\n"

read -p "Enter name: " name
read -p "Enter register number: " reg_no
read -p "Enter five subject marks: " m1 m2 m3 m4 m5

total=$(( $m1 + $m2 + $m3 + $m4 + $m5 ))
avg=$(( $total / 5 ))
avg_gpa=$(( $avg / 10 ))

if (( $m1 > 50 && $m2 > 50 && $m3 > 50 && $m4 > 50 && $m5 > 50 ))
then
	echo "Student $name-$reg_no passed in all subjects"
	echo "Total Marks - $total/500"
	echo "Average - $avg/100"
	echo "GPA - $avg_gpa/10"
	echo -n "Grade - "
	if (( $avg_gpa >= 9 && $avg_gpa <= 10 ))
	then 
		echo "O"
	
	elif (( $avg_gpa >= 8 && $avg_gpa < 9 ))
	then
		echo "A+"

	elif (( $avg_gpa >= 7 && $avg_gpa < 8 ))
	then
		echo "A"

	elif (( $avg_gpa >= 6 && $avg_gpa < 7 ))
	then
		echo "B+"
	
	elif (( $avg_gpa >= 5 && $avg_gpa < 6 ))
	then
		echo "B"
	else
		echo "C"
	fi
else
	echo "Student $name-$reg_no failed"
	echo "Total Marks - $total/500"
	echo "Average - $avg/100"
	echo "GPA - $avg_gpa/10"
fi
