#include <stdio.h>
#include <stdlib.h>

#include "../inc/node_t.h"

void *pop_back(node_t **head)
{
    void *ret_data = NULL;

    node_t *temp_cur = *head;
    node_t *temp_next = temp_cur->next;

    if (temp_next == NULL)
    {
        ret_data = temp_cur->data;
        free(temp_cur);
        temp_cur = NULL;
    }
    else
    {
        while (temp_next->next != NULL)
        {
            temp_cur = temp_next;
            temp_next = temp_cur->next;
        }

        ret_data = temp_next->data;
        free(temp_next);
        temp_cur->next = NULL;
    }

    return ret_data;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *cur_node = head;
    node_t *ret_find = NULL;

    while (cur_node != NULL && ret_find == NULL)
    {
        if (comparator(cur_node->data, data) == 0)
        {
            ret_find = cur_node;
        }

        cur_node = cur_node->next;
    }

    return ret_find;
}

node_t *reverse(node_t *head)
{
    node_t *cur = head;
    node_t *next = NULL;
    node_t *prev = NULL;

    while (cur->next != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return cur;
}

void sorted_insert(node_t **head, node_t *element, int (*copmarator)(const void *, const void *))
{
    if (copmarator((*head)->data, element->data) > 0)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        node_t *cur = (*head)->next;
        node_t *next = cur->next;
 
        while (copmarator(next->data, element->data) < 0)
        {
            cur = next;
            next = cur->next;
        }

        cur->next = element;
        element->next = next;
    }
}

void sort(node_t **head);
