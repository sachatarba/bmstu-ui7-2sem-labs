#include <stddef.h>
#include <stdio.h>

struct array_t
{
    int *p;
    size_t len;
};

typedef struct array_t array_t;

int get_array_len(FILE *fp, array_t *arr);
// int get_len_from_file(FILE *fp, size_t len);

int init_array(array_t *arr);

int free_array(array_t *arr);

int read_array(FILE *fp, array_t *arr);

int print_array_to_file(FILE *fp, array_t *arr);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
