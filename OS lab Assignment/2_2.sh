echo Enter any character;
read a;
b= grep $a text.sh;
if [ $? -eq 0 ]
then              
echo character found ;
fi
