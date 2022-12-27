#ifndef __ARRAY_T_C__
#define __ARRAY_T_C__

#include <stddef.h>
#include <stdio.h>

struct array
{
    int *p;
    int *end;
    size_t len;
};

enum array_t_states
{
    ARRAY_T_NOT_INITED,
    ARRAY_T_INITED,
    ARRAY_T_P_INITED,
    ARRAY_T_P_NOT_INITED,  
};

typedef enum array_t_states array_t_states_t;

typedef struct array array_t;

int create_array(int **arr_begin, int **arr_end, size_t len);

array_t_states_t initialize_state(array_t *arr);

int init_array(array_t *arr, size_t len);

int init_array_from_file(FILE *fp, array_t *arr);

int free_array(array_t *arr);

int read_array(FILE *fp, array_t *arr);

void print_array_to_file(FILE *fp, array_t *arr);

// int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
