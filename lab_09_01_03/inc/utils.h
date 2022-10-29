#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>

#include "../inc/error_t.h"

error_t parse_number(char *buffer, long long *number);

error_t read_string(FILE *fp, char **buff, size_t *size);

error_t parse_double(char *buffer, double *number);

int is_string_whitespace(char *string);

error_t copy_string(char **dst, char *src);

error_t realloc_array(void **ptr, size_t size);

#endif
