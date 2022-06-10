#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

#define NULL ((void *)0)
#define EOF (-1)

#define ARGS 2
#define FIRST_ARG 1

#define NUMBERS_BETWEEN 1

#define ERR_OK 0
#define ERR_NO_FILE 1
#define ERR_NO_NUMBERS 2
#define ERR_WRONG_ARGS 3
#define ERR_NO_NUMBERS_BETWEEN 4

int main(int argc, char *argv[])
{
    int rc = ERR_OK;
    // char file_name[20];
    // printf("%s", argv[0]);
    // scanf("%s", file_name);
    if (argc == ARGS)
    {
        FILE *fp = fopen(argv[ARGS - 1], "r");

        if (fp != NULL)
        {
            int ind_min = 0;
            int ind_max = 0;

            if (find_index(fp, &ind_min, &ind_max) == ERR_OK)
            {
                if (ind_max - ind_min > NUMBERS_BETWEEN)
                {
                    // printf("%d %d\n", ind_max, ind_min);
                    fseek(fp, 0, 0);
                    double sum = calc_sum(fp, ind_min, ind_max);
                    // printf("%lf\n", sum);
                    double average = sum / (abs(ind_max - ind_min) - 1);

                    printf("%lf", average);
                }
                else
                {
                    rc = ERR_NO_NUMBERS_BETWEEN;
                }

            }
            else
            {
                rc = ERR_NO_NUMBERS;
            }

            fclose(fp);
        }
        else
        {
            rc = ERR_NO_FILE;
        }
    }
    else
    {
        rc = ERR_WRONG_ARGS;
    }

    return rc;
}
