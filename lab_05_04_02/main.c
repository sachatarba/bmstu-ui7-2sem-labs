#include <stdio.h>
#include <string.h>
#include "utils.h"


#define ARGS_A_B 4
#define ARGS_C 3

#define FIRST_FLAG "sb"
#define SECOND_FLAG "fb"
#define THIRD_FLAG "ab"

#define ERR_OK 0
#define ERR_NO_FILE 1
#define ERR_EMPTY_FILE 2
#define ERR_WRONG_FLAGS 53

int main(int argc, char *argv[])
{
    int rc = ERR_OK;

    if (argc == ARGS_A_B && !strcmp(argv[ARGS_A_B - 3], FIRST_FLAG))
    {
        FILE *source_file = fopen(argv[ARGS_A_B - 2], "rb");

        if (source_file != NULL)
        {
            FILE *destination_file = fopen(argv[ARGS_A_B - 1], "r+b");

            if (destination_file != NULL)
            {
                if (copy(source_file, destination_file)) 
                {
                    sort(destination_file);
                    // print_file(destination_file);
                }
                else
                {
                    rc = ERR_EMPTY_FILE;
                }

                fclose(destination_file);
            }
            else
            {
                rc = ERR_NO_FILE;
            }

            fclose(source_file);
        }
        else
        {
            rc = ERR_NO_FILE;
        }
    }
    else if (argc == ARGS_A_B && !strcmp(argv[ARGS_A_B - 3], SECOND_FLAG))
    {
        FILE *fp = fopen(argv[ARGS_A_B - 2], "rb");
        
        if (fp != NULL)
        {
            if (strlen(argv[ARGS_A_B - 1]))
            {
                    find_products_by_name(fp, argv[ARGS_A_B - 1]);
            }
            else
            {
                rc = ERR_WRONG_FLAGS;
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
    
    return rc;
}
