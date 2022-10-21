#ifndef __UTILS_H__
#define __UTILS_H__

#include <stddef.h>

#include "../inc/error_t.h"

error_t realloc_array(double **arr, size_t new_size);

error_t alloc_array(double **arr, size_t size);

#endif