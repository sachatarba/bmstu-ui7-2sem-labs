#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/utils.h"
#include "../inc/product_t.h"
#include "../inc/error_t.h"

#define NUMBER_SIZE 20

#define ARGS 3

// int main(void)
int main(int argc, char **argv)
{
    error_t rc = ERR_OK;

    if (argc == ARGS)
    {       
        FILE *fp = fopen(argv[1], "r");
        
        if (fp != NULL)
        {
            product_t *products = malloc(sizeof(product_t));
            char *buff = NULL;

            size_t i = 0;

            while (rc == ERR_OK && (rc = read_struct(fp, products + i) == ERR_OK))
            {
                ++i;
                rc = realloc_array((void **) &products, (i + 1) * sizeof(product_t));
            }
            if (!feof(fp))
            {
                rc = ERR_READING;
            }

            double max_price = 0;

            if (rc != ERR_READING && parse_double(argv[2], &max_price) == ERR_OK && max_price >= 0)
            {
                find_by_price(products, i, atof(argv[2]));
            }
            else
            {
                rc = ERR_READING;
            }

            fclose(fp);
            free(buff);
            
            free_products_array(products, i);
            free(products);

            products = NULL;
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
