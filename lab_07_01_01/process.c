#include "process.h"
#include "utils.h"


int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    size_t min_ind = find_index_of_min(pb_src, pe_src);
    size_t max_ind = find_index_of_max(pb_src, pe_src);

    size_t start_ind = min_ind < max_ind ? min_ind : max_ind;
    size_t end_ind = min_ind > max_ind ? min_ind : max_ind;
    size_t len = end_ind - start_ind - 1;

    create_array(pb_dst, pe_dst, len);
    copy_array(pb_src, pe_src, *pb_dst, *pe_dst);
}

void mysort(void *buff, size_t num, size_t size, int (*cmp)(const void *, const void *));
