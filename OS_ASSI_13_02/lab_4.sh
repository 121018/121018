 max=0
for i in `ls -l|tr -s " "|cut -f 5 -d " "`
do
if [ $max -le $i ]
then
max=$i
fi
done
echo maximum sized filename is:
ls -S | head -n 1

echo its maximum size is: $max
