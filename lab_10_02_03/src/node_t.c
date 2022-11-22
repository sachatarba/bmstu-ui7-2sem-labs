#include <stdio.h>
#include <stdlib.h>

#include "../inc/node_t.h"

void push_back(const size_t degree, node_t **head)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(node_t));
        (*head)->degree = degree;
        (*head)->next = NULL;
    }
    else
    {
        node_t *cur = *head;
        
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        cur->next = malloc(sizeof(node_t));
        cur->next->degree = degree;
        cur->next->next = NULL;
    }
}

void push_back_to_node_t(const size_t number, void *head)
{
    push_back(number, (node_t **) head);
}

size_t pop_back(node_t **head)
{
    size_t ret_number = 0;

    if (head != NULL)
    { 
        if (*head != NULL)
        {
            node_t *temp_cur = *head;
            node_t *temp_next = temp_cur->next;

            if (temp_next == NULL)
            {
                ret_number = temp_cur->degree;
                free(temp_cur);
                *head = NULL;
            }
            else
            {
                while (temp_next->next != NULL)
                {
                    temp_cur = temp_next;
                    temp_next = temp_cur->next;
                }

                ret_number = temp_next->degree;
                free(temp_next);
                temp_cur->next = NULL;
            }
        }
    }

    return ret_number;
}

size_t pop_head(node_t **head, bool need_to_del_node)
{
    size_t ret_number = 0;

    if (head != NULL)
    {
        if (*head != NULL)
        {
            ret_number = (*head)->degree;

            if (need_to_del_node == true)
            { 
                node_t *temp = *head;
                *head = (*head)->next;
                free(temp);
            }
        }
    }

    return ret_number;
}

void free_node(node_t **head)
{
    while (head != NULL && *head != NULL)
    {
        pop_back(head);
    }
}
