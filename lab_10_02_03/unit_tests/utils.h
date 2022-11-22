#ifndef __UTILS_H__
#define __UTILS_H__

#include "../inc/node_t.h"

int copmare_int(const void *a, const void *b);

void sorted_insert(node_t **head, node_t *element, int (*copmarator)(const void *, const void *));

#endif //  __UTILS_H__
