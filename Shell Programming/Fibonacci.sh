//Shell program to find the fibonacci series up to a particular number of terms.
echo "Enter a number:";
read n;
echo "Fibonacci Series is :";
f1=0;
f2=1;
if ((n==1))
then echo "$f1";
elif ((n==2))
then
echo "$f1";
echo "$f2";
else
echo "$f1";
echo "$f2";
for ((i=0;i<n;i++))
do
f3=$((f1+f2));
echo "$f3";
f1=$f2;
f2=$f3;
done;
fi;
