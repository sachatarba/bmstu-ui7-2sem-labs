#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../inc/utils.h"
#include "../inc/error_t.h"

int compare_int(const void *num1, const void *num2)
{
    return *((const int *) num1) - *((const int *) num2); 
}

int create_array(int **arr_begin, int **arr_end, size_t len)
{
    error_t rc = OK;

    *arr_begin = calloc(len, sizeof(int));

    if (arr_begin != NULL)
    {
        *arr_end = *arr_begin + len;
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}

size_t find_index_of_min(const int *arr_begin, const int *arr_end)
{
    int min = *arr_begin;
    size_t ind = 0;
    size_t i = 0;

    while (arr_begin != arr_end)
    {
        if (*arr_begin < min)
        {
            min = *arr_begin;
            ind = i;
        }

        ++i;
        ++arr_begin;
    }

    return ind;
}

size_t find_index_of_max(const int *arr_begin, const int *arr_end)
{
    int max = *arr_begin;
    size_t ind = 0;
    size_t i = 0;

    while (arr_begin != arr_end)
    {
        if (*arr_begin > max)
        {
            max = *arr_begin;
            ind = i;
        }

        ++i;
        ++arr_begin;
    }

    return ind;
}

int copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst)
{
    int rc = OK;

    while (pb_src != pe_src)
    {
        if (pb_dst < pe_dst)
        {
            *pb_dst = *pb_src;
            ++pb_dst;
        }
        else
        {
            rc = ERR_ARR_OVERFLOW;
        }

        ++pb_src;
    }

    return rc;
}
