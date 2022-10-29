#include <stdlib.h>
#include <string.h>

#include "../inc/product_t.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"

#define BUFF_SIZE 30

error_t read_struct(FILE *fp, product_t *product)
{
    error_t rc = ERR_OK;

    char *buff = NULL;
    size_t size;
    rc = read_string(fp, &buff, &size);

    if (rc == ERR_OK)
    {
        if (!is_string_whitespace(buff))
        {
            product->name = NULL;
            rc = copy_string(&product->name, buff);

            if (rc == ERR_OK && (rc = read_string(fp, &buff, &size)) == ERR_OK)
            {
                rc = parse_number(buff, &product->price);

                if (product->price < 0)
                {
                    rc = ERR_BAD_PRICE;
                }
            }
            if (is_string_whitespace(buff))
            {
                rc = ERR_READING;
            }
        }
        if (rc != ERR_OK)
        {
            free_product(product);
        }
    }
    free(buff);

    return rc;
}

error_t free_product(product_t *product)
{
    error_t rc = ERR_OK;

    if (product != NULL)
    {
        free(product->name);
        product->name = NULL;
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}

error_t free_products_array(product_t *product, size_t size)
{
    error_t rc = ERR_OK;

    if (product != NULL)
    {
        for (size_t i = 0; i < size; ++i)
        {
            free_product(product + i);
        }
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}


void print_struct(product_t *product)
{
    printf("%s", product->name);
    printf("%lld\n", product->price);
}

error_t find_by_price(product_t *products, size_t products_number, double price)
{
    error_t rc = ERR_NO_DATA;

    for (size_t i = 0; i < products_number; ++i)
    {
        if ((products + i)->price < price)
        {
            rc = ERR_OK;
            print_struct(products + i);
        }
    }

    return rc;
}
