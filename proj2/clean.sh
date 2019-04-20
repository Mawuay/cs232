#!/bin/sh
# clean.sh.cpp shell script that evaluates directory and remove all extraneous files in the working directory.
# Author: Daniel Ackuaku
# CS 232 Calvin college 2019.
# Created on: March 09, 2019

# Function that removes extraneous files from the directorry recursively
housekeeping() {
    cd $MY_DIRECTORY/
    for files in  `ls -A`
    do
        # checking for ( ~, #, .o ) in files
        if [ -f "$files" ] 
        then
        case $files in
            *"~")
                echo "$files"
                rm $files
            ;;

            *"#")
                echo "$files"
                rm $files
            ;;

            *".o")
                echo "$files"
                rm $files
            ;;

            "core")
                echo "$files"
                rm $files
            ;;
        esac

       # checking for directories in files 
       # recurssive portion of teh code that looks into each directory 
        elif [ -d $files ]
        then
            echo $files This is a directory
            PREV_DIR=$MY_DIRECTORY
            MY_DIRECTORY=$files
            housekeeping 
            MY_DIRECTORY=$PREV_DIR

        # checking for executables in files 
        elif [ -x "$files" ];
        then
            echo "$files"
            rm $files

        fi
        
    done

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
    housekeeping
    echo ""
else
    MY_DIRECTORY=$1 
    echo ""
    echo You are deleting from the `pwd`/$MY_DIRECTORY 
    echo ""
    housekeeping
    echo ""
fi