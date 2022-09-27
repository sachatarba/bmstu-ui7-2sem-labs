#include <stddef.h>

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

void mysort(void *buff, size_t num, size_t size, int (*cmp)(const void *, const void *));
