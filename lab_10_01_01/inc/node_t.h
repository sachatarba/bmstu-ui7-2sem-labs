#ifndef __NODE_T_H__
#define __NODE_T_H__

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

void *pop_back(node_t **head);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

node_t *reverse(node_t *head);

void sorted_insert(node_t **head, node_t *element, int (*copmarator)(const void *, const void *));

void sort(node_t **head);

#endif //  __NODE_T_H__
