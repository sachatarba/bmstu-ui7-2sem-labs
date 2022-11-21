#ifndef __NODE_NUMBERS_OPERATIONS_H__
#define __NODE_NUMBERS_OPERATIONS_H__

#include "../inc/node_t.h"

size_t print_degrees(node_t *head);

void mul_numbers(node_t *num1, node_t *num2, node_t **res);

void sqr(node_t *num, node_t **res);

int div_numbers(node_t *dividend, node_t *divider, node_t **res);

void del_zeros(node_t **head);

#endif //  __NODE_NUMBERS_OPERATIONS_H__
