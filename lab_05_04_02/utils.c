#include <string.h>
#include "utils.h"

#define OK 1
#define ERR 0

void write_struct(FILE *fp, product_t *product, int pos)
{
    long int seek_cur = ftell(fp);
    fseek(fp, sizeof(*product) * pos, SEEK_SET);
    fwrite(product, sizeof(*product), 1, fp);
    fseek(fp, seek_cur, SEEK_SET);
}

int read_struct(FILE *fp, product_t *product, int pos)
{
    int rc = 0;
    long int seek_cur = ftell(fp);

    fseek(fp, sizeof(*product) * pos, SEEK_SET);

    rc = fread(product, sizeof(*product), 1, fp);
    
    fseek(fp, seek_cur, SEEK_SET);

    return rc;
}

int input_struct(product_t *product)
{
    int rc = OK;

    if (scanf("%s", product->name) != 1)
        rc = ERR;
    if (scanf("%s", product->producer) != 1)
        rc = ERR;
    if (scanf("%u", &product->price) != 1)
        rc = ERR;
    if (scanf("%u", &product->count) != 1)
        rc = ERR;
    
    return rc;
}

void print_struct(product_t *product)
{
    printf("%s\n", product->name);
    printf("%s\n", product->producer);
    printf("%d\n", product->price);
    printf("%d\n", product->count);
}

int comparator(product_t *product1, product_t *product2)
{
    int res = 0;

    if (product1->price > product2->price)
    {
        res = 1;
    }
    else if (product1->price == product2->price)
    {
        if (product1->count > product2->count)
        {
            res = 1;
        }
        else
        {
            res = -1;
        }
    }
    else if (product1->price < product2->price)
    {
        res = -1;
    }

    return res;
}

int copy(FILE *source, FILE *destination)
{
    product_t product = { { '\0' }, { '\0' }, 0, 0 };
    // product_t product;
    int pos = 0;

    while (read_struct(source, &product, pos) == 1)
    {
        write_struct(destination, &product, pos);
        ++pos;
    }

    return pos;
}

void swap_struct(FILE *fp, int pos1, int pos2)
{
    product_t temp1 = { { '\0' }, { '\0' }, 0, 0 };
    product_t temp2 = { { '\0' }, { '\0' }, 0, 0 };
    // product_t temp1, temp2;

    read_struct(fp, &temp1, pos1);
    read_struct(fp, &temp2, pos2);
    write_struct(fp, &temp2, pos1);
    write_struct(fp, &temp1, pos2);
}

int sort(FILE *fp)
{
    product_t temp1 = { { '\0' }, { '\0' }, 0, 0 }, temp2 = { { '\0' }, { '\0' }, 0, 0 };
    // product_t temp1, temp2;
    int pos1 = 0, pos2 = 0;

    while (read_struct(fp, &temp1, pos1) == 1)
    {
        pos2 = 0;

        while (read_struct(fp, &temp1, pos2) == 1 && read_struct(fp, &temp2, pos2 + 1) == 1)
        {
            if (comparator(&temp1, &temp2) == -1)
            {
                swap_struct(fp, pos2, pos2 + 1);
            }

            ++pos2;
        }

        ++pos1;
    }

    return pos1;
}

int print_file(FILE *fp)
{
    product_t temp = { { '\0' }, { '\0' }, 0, 0 };
    // product_t temp;
    int pos = 0;

    while (read_struct(fp, &temp, pos) == 1)
    {
        print_struct(&temp);
        ++pos;
    }

    return pos;
}

int check_name(product_t *product, char substr[])
{
    int res = 0;

    if (*substr)
    {
        if (strstr(product->name, substr) != NULL)
        {
            if (!*(strstr(product->name, substr) + strlen(substr)))
            {
                res = 1;
            }
        }
    }

    return res;
}

int find_products_by_name(FILE *fp, char substr_name[])
{
    product_t temp = { { '\0' }, { '\0' }, 0, 0 };
    // product_t temp;
    int pos = 0;
    int count = 0;

    while (read_struct(fp, &temp, pos) == 1)
    {
        if (check_name(&temp, substr_name))
        {
            print_struct(&temp);
            ++count;
        }
        ++pos;
    }

    return count;
}
