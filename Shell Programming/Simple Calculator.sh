echo "Enter the first number:";
read a;
echo "Enter the second number:";
read b;
echo "Enter operation: 1.Addition 2.Subtraction 3.Multiplication 4.Division"
read op;
case $op in
1) echo "Sum is $((a+b))";;
2) echo "Difference is $((a-b))";;
3) echo "Product is $((a*b))";;
4) if ((b == 0));
then echo "Error: Division by zero is not allowed."
else echo "Dividend is $((a/b))"
fi
;;
*) echo "Invalid Option";;
esac
