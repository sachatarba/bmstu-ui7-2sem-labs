#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <stddef.h>

typedef int (*condition_t)(const int, const int);

size_t find_index_by_condition(const int *arr_begin, const int *arr_end, condition_t condition);

int greater(const int a, const int b);

int lesser(const int a, const int b);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, size_t *len);

void mysort(void *buff, size_t num, size_t size, int (*cmp)(const void *, const void *));

#endif
