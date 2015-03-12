

echo Enter a word
read mon;
case $mon in
jan|janu|janua|january) echo january ;;
*) echo invalid word ;;
esac
