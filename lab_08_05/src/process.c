#include "../inc/process.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define EPS 1e-7

error_t crop_matr_to_square(matr_t *matr)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        // TODO: придумать название функции для этой логики и вынести туда
        if (matr->rows > matr->cols)
        {
            while (matr->cols != matr->rows)
            {
                size_t row = 0, col = 0;
                find_min_of_matr(matr, &row, &col);
                rc = del_row(matr, row);
            }
        }
        else
        {
            while (matr->cols != matr->rows)
            {
                size_t row = 0, col = 0;
                find_min_of_matr(matr, &row, &col);
                rc = del_col(matr, col);
            } 
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

error_t geometric_mean_of_cols(matr_t *matr, long long *arr)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        if (arr != NULL)
        {            
            // Стоит ли выделять память в этой функции?
            long long geometric_mean;

            for (size_t cur_col = 0; cur_col < matr->cols; ++cur_col)
            {
                geometric_mean = 1;

                for (size_t cur_row = 0; cur_row < matr->rows; ++cur_row)
                {
                    geometric_mean *= matr->body[cur_row][cur_col];
                }

                geometric_mean = pow(geometric_mean, 1. / matr->rows);
                
                arr[cur_col] = geometric_mean;
            }
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

long long find_max(long long *arr, size_t size)
{
    long long max = arr[0];

    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

error_t find_max_of_rows(matr_t *matr, long long *arr)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        if (arr != NULL)
        {
            for (size_t i = 0; i < matr->rows; ++i)
            {
                arr[i] = find_max(matr->body[i], matr->cols);
            }
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

error_t expand_to_bigger_matrix(matr_t *l, matr_t *r)
{
    error_t rc = OK;

    if (l != NULL && r != NULL)
    {
        matr_t *to_expand = l->rows < r->rows ? l : r;
        matr_t *bigger_matr = l->rows > r->rows ? l : r;

        long long *temp = malloc(sizeof(long long) * bigger_matr->rows);

        if (temp != NULL)
        {
            while (l->rows != r->rows)
            {
                geometric_mean_of_cols(to_expand, temp);
                append_row(to_expand, temp);
            }

            while (l->cols != r->cols)
            {
                find_max_of_rows(to_expand, temp);
                append_col(to_expand, temp);
            }

            free(temp);
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

error_t make_identity_matr(matr_t *matr, size_t rows, size_t cols)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        rc = create_matr(matr, rows, cols);

        if (rc == OK)
        {
            for (size_t i = 0; i < matr->rows; ++i)
            {
                for (size_t j = 0; j < matr->cols; ++j)
                {
                    matr->body[i][j] = i == j;
                }
            }
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}

error_t pow_matr(matr_t *matr, matr_t *res, size_t power)
{
    error_t rc = OK;

    if (matr != NULL)
    {
        memset(res, 0, sizeof(matr_t));

        if (power == 0)
        {
            make_identity_matr(res, matr->rows, matr->cols);
        }
        else
        {
            copy_matr(res, matr);

            for (size_t i = 0; i < power - 1; ++i)
            {
                mul_matr(res, matr, res);
            }
        }
    }
    else
    {
        rc = ERR_INV_STRUCT_PTR;
    }

    return rc;
}
