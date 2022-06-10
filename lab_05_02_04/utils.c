#include <stdio.h>
#include "utils.h"

#define ERR_OK 0
#define ERR_NO_NUMBERS -1

void swap(double *num1, double *num2)
{
    double temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

int find_index(FILE *fp, int *ind_min, int *ind_max)
{
    int rc = ERR_OK;

    double min = 0, max = 0;
    double number = 0;
    int count = 0;

    if (fscanf(fp, "%lf", &max) == 1 && fscanf(fp, "%lf", &min) == 1)
    {
        count += 2;

        if (max < min)
        {
            swap(&min, &max);
        }

        while (fscanf(fp, "%lf", &number) == 1)
        {
            if (number > max)
            {
                max = number;
                *ind_max = count;
            }
            else if (number < min)
            {
                min = number;
                *ind_min = count;
            }
        
            ++count;
        }
    }
    else
    {
        rc = ERR_NO_NUMBERS;
    }

    return rc;
}

double calc_sum(FILE *fp, int ind_start, int ind_finish)
{
    double number = 0;
    double sum = 0;
    int count = 0;

    while (fscanf(fp, "%lf", &number) == 1)
    {
        if (count < ind_finish && count > ind_start)
            sum += number;

        ++count;
    }

    return sum;
}
