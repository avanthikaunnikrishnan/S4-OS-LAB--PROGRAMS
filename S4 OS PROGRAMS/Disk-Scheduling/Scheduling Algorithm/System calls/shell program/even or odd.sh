echo "Enter a number"
read num
rem=$((num%2))
if (($rem==0))
then
echo "Even"
else
echo "Odd"
fi
