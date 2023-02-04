echo "Enter a number: "
read num
temp=$num
sum=0
while [ $temp -gt 0 ]
do
rem=$(($temp%10))
sum=$(($sum+$rem*$rem*$rem))
temp=$(($temp/10))
done
if [ $sum -eq $num ]
then
echo "Armstrong"
else
echo "Not Armstrong"
fi