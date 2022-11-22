#include <stdio.h>

#include "utils.h"

int copmare_int(const void *a, const void *b)
{
    return *((int *) a) - *((int *) b);
}

void sorted_insert(node_t **head, node_t *element, int (*copmarator)(const void *, const void *))
{
    if (*head == NULL)
    {
        *head = element;
        element->next = NULL;
    }
    else if (copmarator(&(*head)->degree, &element->degree) > 0)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        node_t *cur = *head;
        node_t *next = cur->next;

        if (next != NULL)
        {
            while (next != NULL && copmarator(&next->degree, &element->degree) < 0)
            {
                cur = next;
                next = cur->next;
            }

            element->next = next;
            cur->next = element;
        }
        else
        {
            cur->next = element;
        }
    }
}
