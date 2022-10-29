#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <stdio.h>

#include "../inc/error_t.h"

#define LEN_NAME 26

typedef struct
{
    char *name;
    long long price;
} product_t;

error_t read_struct(FILE *fp, product_t *product);

void print_struct(product_t *product);

error_t find_by_price(product_t *product, size_t products_numbers, double price);

error_t free_product(product_t *product);

error_t free_products_array(product_t *product, size_t size);

#endif
