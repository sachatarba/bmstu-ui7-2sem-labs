#pragma once

#include <stdio.h>
#include <stdint.h>

#define LEN_NAME 31
#define LEN_PRODUCER 16

#define SIZE 53

typedef struct
{
    char name[LEN_NAME];
    char producer[LEN_PRODUCER];
    uint32_t price;
    uint32_t count;
} product_t;

void write_struct(FILE *fp, product_t *product, int pos);

int read_struct(FILE *fp, product_t *product, int pos);

void input_struct(product_t *product);

void print_struct(product_t *product);

int comparator(product_t *product1, product_t *product2);

void copy(FILE *source, FILE *destination);

void swap_struct(FILE *fp, int pos1, int pos2);

void sort(FILE *destination);

void print_file(FILE *fp);

int check_name(product_t *product, char substr[]);

void find_products_by_name(FILE *fp, char substr_name[]);
