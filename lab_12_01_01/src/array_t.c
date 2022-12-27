#include <malloc.h>
#include <stdlib.h>

#include "../inc/array_t.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"


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

array_t_states_t initialize_state(array_t *arr)
{
    array_t_states_t init_state = ARRAY_T_INITED;

    if (arr == NULL)
    {
        init_state = ARRAY_T_NOT_INITED;
    }
    else if (arr->p == NULL)
    {
        init_state = ARRAY_T_P_NOT_INITED; 
    }
    else
    {
        init_state = ARRAY_T_P_INITED;
    }

    return init_state;
}

int init_array(array_t *arr, size_t len)
{
    error_t rc = OK;

    if (initialize_state(arr) != ARRAY_T_NOT_INITED)
    {
        if (initialize_state(arr) == ARRAY_T_P_INITED)
        {
            free(arr->p);
            arr->p = NULL;
        }
        else
        {
            arr->len = len;
            arr->p = calloc(arr->len, sizeof(int));
        }

        if (arr->p == NULL)
        {
            rc = ERR_INV_PTR;
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

int free_array(array_t *arr)
{
    error_t rc = OK;

    if (initialize_state(arr) != ARRAY_T_NOT_INITED)
    {
        arr->len = 0;

        if (initialize_state(arr) != ARRAY_T_P_NOT_INITED)
        {
            free(arr->p);
            arr->p = NULL;
        }
        else
        {
            rc = ERR_INV_PTR;
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

int get_array_len_from_file(FILE *fp, size_t *len)
{
    error_t rc = OK;
    int num = 0;
    *len = 0;

    while (fscanf(fp, "%d", &num) == 1)
    {
        ++*len;
    }
    
    if (!feof(fp))
    {
        rc = ERR_BAD_FILE_DATA;
    }

    if (*len == 0)
    {
        rc = ERR_BAD_LEN;
    }

    return rc;
}

int init_array_from_file(FILE *fp, array_t *arr)
{
    error_t rc = OK;

    size_t len = 0;

    rc = get_array_len_from_file(fp, &len);

    if (rc == OK)
    {
        rc = init_array(arr, len);

        if (rc == OK)
        {
            fseek(fp, SEEK_SET, 0);
            read_array(fp, arr);
        }
    }

    return rc;
}

int read_array(FILE *fp, array_t *arr)
{
    error_t rc = OK;
    size_t i = 0;

    while (i < arr->len && rc == OK)
    {
        if (fscanf(fp, "%d", (arr->p + i)) == 1)
        {
            ++i;
        }
        else
        {
            rc = ERR_READING;
        }
    }

    return rc;
}

void print_array_to_file(FILE *fp, array_t *arr)
{
    for (size_t i = 0; i < arr->len; ++i)
    {
        fprintf(fp, "%d ", *(arr->p + i));
    }
}
