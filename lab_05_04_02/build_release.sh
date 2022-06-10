#!/bin/bash

gcc -c utils.c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal

gcc -c main.c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal
gcc -o app.exe main.o -lm
