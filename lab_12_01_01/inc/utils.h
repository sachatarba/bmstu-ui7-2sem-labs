#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>

int get_array_len_from_file(FILE *fp, size_t *len);

int compare_int(const void *num1, const void *num2);

int copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);

int swap(void *data1, void *data2, size_t data_size);

#endif
