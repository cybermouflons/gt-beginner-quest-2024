#!/bin/bash
# I will hide the flag well so you can't find it
cp /flag.txt /flag-$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 16 | head -n 1).txt
rm /flag.txt
