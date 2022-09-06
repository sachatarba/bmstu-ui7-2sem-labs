#!/bin/bash

gcc -c *.c -Wall -Werror -Wpedantic -Wextra
gcc -o app.exe *.o -lm
