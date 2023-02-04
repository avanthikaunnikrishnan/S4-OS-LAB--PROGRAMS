echo "Enter a number"
read n
echo "Fibonacci sequence: "
first=0
second=1
echo $first
echo $second
for ((i=0;i<n-2;i++))
{
third=$((first+second))
echo "$third"
first=$((second))
second=$((third))
}