#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define NULL ((void *)0)

#define ERR_OK 0
#define ERR_NO_FILE 1
#define ERR_NO_NUMBERS 2
#define ERR_WRONG_FLAGS 3

#define ARGS_1 4
#define ARGS_2_3 3

#define FLAG_1 "c"
#define FLAG_2 "p"
#define FLAG_3 "s"

int main(int argc, char *argv[])
{
    int rc = ERR_OK;
    
    if (argc == ARGS_1)
    {
        if (!strcmp(argv[ARGS_1 - 3], FLAG_1))
        {
            FILE *fp = fopen(argv[ARGS_1 - 1], "wb");

            if (fp != NULL)
            {
                write_rand_numbers_to_bin_file(fp, atoi(argv[ARGS_1 - 2]));

                fclose(fp);
            }
            else
            {
                rc = ERR_NO_FILE;
            }
        }
        else
        {
            rc = ERR_WRONG_FLAGS;
        }
    }
    else if (argc == ARGS_2_3)
    {
        if (!strcmp(argv[ARGS_2_3 - 2], FLAG_2))
        {
            FILE *fp = fopen(argv[ARGS_2_3 - 1], "rb");

            if (fp != NULL)
            {
                if (!print_numbers(fp))
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
        else if (!strcmp(argv[ARGS_2_3 - 2], FLAG_3))
        {
            FILE *fp = fopen(argv[ARGS_2_3 - 1], "r+b");

            if (fp != NULL)
            {
                if (!sort(fp))
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
            rc = ERR_WRONG_FLAGS;
        }
    }
    else
    {
        rc = ERR_WRONG_FLAGS;
    }

    return rc;
}
