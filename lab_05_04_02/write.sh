#!/bin/bash

gcc -c write.c -o write.o -g
gcc write.o utils.o

if [ -n "$1" ]; then
    if [ -n "$2" ]; then
        ./a.out "$1" "$2"
    else
        echo "No number"
    fi
else
    echo "No input file"
fi
