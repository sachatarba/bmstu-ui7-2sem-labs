#pragma once

#include <stdio.h>
#include <string.h>

#define LEN_NAME 26

typedef struct
{
    char name[LEN_NAME];
    int price;
} product_t;

int read_struct(FILE *fp, product_t *product);

void print_struct(product_t *product);

int find_all(product_t *product, size_t products_numbers, int price);

int parse_number(char *buffer, int *number);

int read_string(FILE *fp, char *buff, const char MAX_LEN);
