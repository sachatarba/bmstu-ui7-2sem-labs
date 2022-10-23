#ifndef __PROCESS_H__
#define __PROCESS_H__


#include "../inc/error_t.h"
#include "../inc/matr_t.h"

error_t crop_matr_to_square(matr_t *matr);

error_t expand_to_bigger_matrix(matr_t *l, matr_t *r);

error_t geometric_mean_of_cols(matr_t *matr, long long *arr);

error_t find_max_of_rows(matr_t *matr, long long *arr);

error_t expand_to_bigger_matrix(matr_t *l, matr_t *r);

#endif
