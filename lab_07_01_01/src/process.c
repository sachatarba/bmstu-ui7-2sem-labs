#include <stdlib.h>
#include <string.h>

#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    error_t rc = OK;

    if (pb_src != NULL && pe_src != NULL && pb_src < pe_src)
    {
        size_t min_ind = find_index_of_min(pb_src, pe_src);
        size_t max_ind = find_index_of_max(pb_src, pe_src);

        size_t start_ind = min_ind < max_ind ? min_ind + 1 : max_ind + 1;
        size_t end_ind = min_ind > max_ind ? min_ind : max_ind;
        size_t len = end_ind - start_ind;

        if (len > 0 && max_ind != min_ind)
        {
            if (create_array(pb_dst, pe_dst, len) == OK)
            {
                if (copy_array(pb_src + start_ind, pb_src + end_ind, *pb_dst, *pe_dst) != OK)
                {
                    rc = ERR_ARR_OVERFLOW;
                }
            }
            else
            {
                rc = ERR_INV_PTR;
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
    void *temp = malloc(size);
    char *p = buff;

    for (size_t i = 0; i < num; ++i)
    {
        for (size_t j = 0; j < num - 1; ++j)
        {
            if (cmp(p + j * size, p + j * size + 1 * size) > 0)
            {
                memcpy(temp, p + j * size, size);
                memcpy(p + j * size, p + j * size + 1 * size, size);
                memcpy(p + j * size + 1 * size, temp, size);
            }
        }
    }

    free(temp);
}
