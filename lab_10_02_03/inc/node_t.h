#ifndef __NODE_T_H__
#define __NODE_T_H__

typedef struct node node_t;

#include <stdbool.h>

struct node
{
    size_t degree;
    node_t *next;
};

void push_back(const size_t degree, node_t **head);

void push_back_to_node_t(const size_t number, void *head);

size_t pop_back(node_t **head);

size_t pop_head(node_t **head, bool need_to_del_node);

void free_node(node_t **head);

#endif //  __NODE_T_H__
