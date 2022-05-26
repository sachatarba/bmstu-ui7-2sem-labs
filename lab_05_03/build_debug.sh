#!/bin/bash

gcc -c utils.c -Wall -Werror -Wpedantic -Wextra -g

gcc -c main.c -Wall -Werror -Wpedantic -Wextra -g
gcc -o app.exe main.o  utils.o -lm
