#pragma once

#include <stdio.h>

void write_rand_numbers_to_bin_file(FILE *fp, int number);

int print_numbers(FILE *fp);

int get_number_by_pos(FILE *fp, int *number, int pos);

void set_number_by_pos(FILE *fp, int number, int pos);

int sort(FILE *fp);
