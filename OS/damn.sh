i=1
count=1
m=`expr $# % 2`
if [ $m -eq 0 ]
then
for i in $* 
do
count=`expr $count + 1`
i=$count
n=`expr $count % 2`
if [ $n -eq 0 ]
then
c=`expr $count - 1`
cp $c.txt $count.txt 
fi
done 
else
echo " ODD " 
fi 
