#pragma once

#include "utils.h"

#define ERR_OK 0
#define ERR_NO_NUMBERS -1

void swap(int *num1, int *num2)
{
    int temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

int process(FILE *f, int *maximum, int *second_maximum)
{
    int rc = ERR_OK;

    int number = 0;
    int count = 0;

    while (fscanf(f, "%d", &number) == 1)
    {
        if (count == 0)
            *maximum = number;
        else if (count == 1)
            *second_maximum = number;
        else if (number > *second_maximum)
        {
            *second_maximum = number;
            if (*second_maximum > *maximum)
                swap(maximum, second_maximum);
        }

        ++count;
    }

    if (count == 0 || count == 1)
        rc = ERR_NO_NUMBERS;

    return rc;
}
