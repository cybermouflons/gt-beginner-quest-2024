#!/bin/bash

./challenge
if [ $? -eq 139 ]; then
    echo 
    echo "Well done! You are starting to think like a true hacker!"
    echo -n 'Here is the flag: '
    cat flag.txt
else
    echo 
    sleep 2
    echo "Access Denied"
fi
