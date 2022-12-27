#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"

int greater(const int a, const int b)
{
    return a > b;
}

int lesser(const int a, const int b)
{
    return a < b;
}

size_t find_index_by_condition(const int *arr_begin, const int *arr_end, condition_t condition)
{
    int find = *arr_begin;
    size_t ind = 0;
    size_t i = 0;

    while (arr_begin != arr_end)
    {
        if (condition(*arr_begin, find))
        {
            find = *arr_begin;
            ind = i;
        }

        ++i;
        ++arr_begin;
    }

    return ind;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, size_t *len)
{
    error_t rc = OK;

    if (pb_src != NULL && pe_src != NULL && pb_src < pe_src)
    {
        size_t min_ind = find_index_by_condition(pb_src, pe_src, lesser);
        size_t max_ind = find_index_by_condition(pb_src, pe_src, greater);

        size_t start_ind = min_ind < max_ind ? min_ind + 1 : max_ind + 1;
        size_t end_ind = min_ind > max_ind ? min_ind : max_ind;
        *len = end_ind - start_ind;

        if (*len > 0 && max_ind != min_ind)
        {
            if (pb_dst != NULL && pe_dst != NULL)
            {
                if (*pe_dst - *pb_dst >= (long int) *len)
                {
                    if (copy_array(pb_src + start_ind, pb_src + end_ind, *pb_dst, *pe_dst) != OK)
                    {
                        rc = ERR_ARR_OVERFLOW;
                    }
                }
                else
                {
                    rc = ERR_NO_MEM_ENOUGH;
                }
            }
            else
            {
                rc = DST_NULL_PTR;
            }
        }
        else
        {
            rc = ERR_BAD_LEN;
        }
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}

void mysort(void *buff, size_t num, size_t size, int (*cmp)(const void *, const void *))
{
    char *p = buff;

    for (size_t i = 0; i < num; ++i)
    {
        for (size_t j = 0; j < num - 1; ++j)
        {
            if (cmp(p + j * size, p + j * size + 1 * size) > 0)
            {
                swap(p + j * size, p + j * size + 1 * size, size);
            }
        }
    }
}
