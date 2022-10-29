#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/utils.h"
#include "../inc/product_t.h"
#include "../inc/error_t.h"

#define NUMBER_SIZE 20

#define ARGS 3

int main(int argc, char **argv)
{
    error_t rc = ERR_OK;

    if (argc == ARGS)
    {       
        FILE *fp = fopen(argv[1], "r");
        char *buff = NULL;
        size_t size = 0;
        
        if (fp != NULL)
        {
            if ((rc = read_string(fp, &buff, &size)) == ERR_OK && (rc = parse_number(buff, (long long*) &size)) == ERR_OK)
            {
                if (size > 0)
                {
                    product_t *products = calloc(sizeof(product_t), size);

                    if (products != NULL)
                    {
                        size_t i = 0;

                        while (i < size && rc == ERR_OK)
                        {
                            rc = read_struct(fp, products + i);
                            ++i;
                        }
                        if (!feof(fp))
                        {
                            rc = ERR_READING;
                        }

                        if (i == size)
                        {
                            double max_price = 0;

                            if (rc != ERR_READING && parse_double(argv[2], &max_price) == ERR_OK && max_price >= 0)
                            {
                                find_by_price(products, i, atof(argv[2]));
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

                        free_products_array(products, i);
                        free(products);
                        products = NULL;
                    }
                    else
                    {
                        rc = ERR_ALLOC;
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

            free(buff);
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
