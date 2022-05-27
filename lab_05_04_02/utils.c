#include "utils.h"

void write_struct(FILE *fp, product_t *product, int pos)
{
    long int seek_cur = ftell(fp);
    fseek(fp, sizeof(*product) * pos, SEEK_SET);
    fwrite(product->name, sizeof(product->name), 1, fp);
    fwrite(product->producer, sizeof(product->producer), 1, fp);
    fwrite(&product->price, sizeof(product->price), 1, fp);
    fwrite(&product->count, sizeof(product->count), 1, fp);
    fseek(fp, seek_cur, SEEK_SET);
}

int read_struct(FILE *fp, product_t *product, int pos)
{
    int rc = 0;
    long int seek_cur = ftell(fp);

    fseek(fp, sizeof(*product) * pos, SEEK_SET);

    if ((rc = fread(product->name, sizeof(product->name), 1, fp)) == 1)
    {
        fread(product->producer, sizeof(product->producer), 1, fp);
        fread(&product->price, sizeof(product->price), 1, fp);
        fread(&product->count, sizeof(product->count), 1, fp);
    }
    
    fseek(fp, seek_cur, SEEK_SET);

    return rc;
}

void input_struct(product_t *product)
{
    scanf("%s", product->name);
    scanf("%s", product->producer);
    scanf("%u", &product->price);
    scanf("%u", &product->count);
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
        if (product1->count > product2->price)
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

void copy(FILE *source, FILE *destination)
{
    product_t product;
    int pos = 0;

    while (read_struct(source, &product, pos) == 1)
    {
        write_struct(destination, &product, pos);
    }
}

void swap_struct(FILE *fp, int pos1, int pos2)
{
    product_t temp1;
    product_t temp2;

    read_struct(fp, &temp1, pos1);
    read_struct(fp, &temp2, pos2);
    write_struct(fp, &temp2, pos1);
    write_struct(fp, &temp1, pos2);
}

void sort(FILE *source, FILE *destination)
{
    copy(source, destination);

    product_t temp1, temp2;
    int pos1, pos2 = 0;

    while (read_struct(destination, &temp1, pos1) == 1)
    {
        pos2 = 0;

        while (read_struct(destination, &temp1, pos2) == 1 && read_struct(destination, &temp2, pos2 + 1) == 1)
        {
            if (comparator(&temp1, &temp2) == -1)
            {
                swap_struct(destination, pos2, pos2 + 1);
            }

            ++pos2;
        }

        ++pos1;
    }
}

void print_file(FILE *fp)
{
    product_t temp;
    int pos = 0;

    while (read_struct(fp, &temp, pos) == 1)
    {
        print_struct(&temp);
        ++pos;
    }
}
