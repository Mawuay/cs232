

clean() {
cd $MY_DIRECTORY

for i in *
do 
    if [ ! -d $i ] 
    then 
        if [ -x $i ]
    elif [ -d $i ]
    then 
    clean $i 
    cd ..

}


#####################################################################
                               #Main Prog
#####################################################################
# Control loop statement
if [ -z $1 ]
then
    MY_DIRECTORY=`pwd`
    echo ""
    echo You are deleting all from the current $MY_DIRECTORY
    echo ""
    clean
    echo ""
else
    MY_DIRECTORY=$1 
    echo ""
    echo You are deleting from the `pwd`/$MY_DIRECTORY 
    echo ""
    clean
    echo ""
fi