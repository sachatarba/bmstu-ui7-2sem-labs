#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/utils.h"
#include "../inc/error_t.h"


int compare_int(const void *num1, const void *num2)
{
    return *((const int *) num1) - *((const int *) num2); 
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

int swap(void *data1, void *data2, size_t data_size)
{
    int rc = OK;
    void *temp = malloc(data_size);
    
    if (temp)
    {
        memcpy(temp, data1, data_size);
        memcpy(data1, data2, data_size);
        memcpy(data2, temp, data_size);
        
        free(temp);
        temp = NULL;
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}
