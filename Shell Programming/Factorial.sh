//Shell program to display the factorial of a number.
echo "Enter a number:";
read n;
f=1;
for ((i=1;i<=n;i++))
do ((f=f*i));
done;
echo "Factorial: $f"
