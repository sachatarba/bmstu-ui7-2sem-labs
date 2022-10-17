#ifndef __MATR_T_H__
#define __MATR_T_H__

#include <stddef.h>

#include "../inc/error_t.h"

struct matr
{
    double **body;

    size_t rows;
    size_t cols;

    size_t rows_allocated;
    size_t cols_allocated;

    size_t alloc_resize; 
};

typedef struct matr matr_t;

error_t create_matr(matr_t *matr, size_t rows, size_t cols);

error_t free_matr(matr_t *matr);

error_t read_matr(matr_t *matr);

error_t print_matr(matr_t *matr);

error_t del_row(matr_t *matr, size_t row_ind);

error_t del_col(matr_t *matr, size_t col_ind);

#endif
