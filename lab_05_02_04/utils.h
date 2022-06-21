#pragma once

#include <stdio.h>

void swap(double *num1, double *num2);

int find_index(FILE *fp, int *ind_min, int *ind_max);

double calc_sum(FILE *fp, int ind_min, int ind_max);
