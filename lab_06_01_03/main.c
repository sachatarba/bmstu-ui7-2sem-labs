#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#define ERR_OK          0
#define ERR_BAD_SIZE    1
#define ERR_NO_DATA     2
#define ERR_BAD_FLAGS   3
#define ERR_NO_FILE     4
#define ERR_READING     5

#define MAX_SIZE 15

#define NUMBER_SIZE 20

#define ARGS 3

int main(int argc, char **argv)
{
    int rc = ERR_OK;

    if (argc == ARGS)
    {
        
        FILE *fp = fopen(argv[1], "r");
        
        if (fp != NULL)
        {
            product_t products[MAX_SIZE];
            memset(products, 0, sizeof(products));

            size_t size = 0;
            char buff[NUMBER_SIZE] = "\0";

            if ((rc = read_string(fp, buff, NUMBER_SIZE)) == ERR_OK && (rc = parse_number(buff, (int*) &size) == ERR_OK))
            {
                if (size > 0 && size <= MAX_SIZE)
                {
                    for (size_t i = 0; i < size && (rc = read_struct(fp, products + i) == ERR_OK); ++i);

                    if (!atof(argv[2]))
                    {
                        if (!find_all(products, size, atof(argv[2])))
                        {
                            rc = ERR_NO_DATA;
                        } 
                    }
                    else
                    {
                        rc = ERR_READING;
                    }
                }
                else
                {
                    rc = ERR_BAD_SIZE;
                }
            }
            else
            {
                rc = ERR_READING;
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
        rc = ERR_BAD_FLAGS;
    }

    return rc;
}
