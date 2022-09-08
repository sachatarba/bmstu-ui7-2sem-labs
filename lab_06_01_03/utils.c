#include <stdlib.h>

#include "utils.h"

#define ERR_OK      0
#define ERR_READING 1
#define ERR_NO_DATA 2

#define RADIX 10

#define BUFF_SIZE 30

int read_string(FILE *fp, char *buff, const char MAX_LEN)
{
    int rc = ERR_OK;

    if (fgets(buff, MAX_LEN, fp) == NULL) 
    {
        rc = ERR_READING;
    }

    return rc;
}

int read_struct(FILE *fp, product_t *product)
{
    int rc = ERR_OK;

    rc = read_string(fp, product->name, LEN_NAME);

    char buff[BUFF_SIZE] = "\0";

    if ((rc = read_string(fp, buff, BUFF_SIZE)) != ERR_READING)
    {
        rc = parse_number(buff, &product->price);
    }

    return rc;
}

int parse_number(char *buffer, int *number)
{
    int rc = ERR_OK;

    char *end;
    *number = (int) strtod(buffer, &end);

    if (*end != '\r' && *end != '\n')
    {
        rc = ERR_READING;
    }

    return rc;
}

void print_struct(product_t *product)
{
    printf("%s", product->name);
    printf("%d\n", product->price);
}

int find_all(product_t *products, size_t products_number, double price)
{
    int rc = ERR_NO_DATA;

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
