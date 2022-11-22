#include <stdio.h>
#include <stdlib.h>

#include "../inc/node_t.h"
#include "../inc/comparator.h"

#define OK 0
#define ERR_READING 1
#define ERR_COUNT 2

int main(void)
{
    int rc = OK;

    node_t *head = NULL;
    int count = 0;

    if (scanf("%d", &count) == 1)
    {
        if (count > 0)
        {
            int *data = malloc(sizeof(int) * count);

            for (size_t i = 0; (i < (size_t) count) && (rc == OK); ++i)
            {
                if (scanf("%d", data + i) == 1) 
                {
                    node_t *elem = malloc(sizeof(node_t));
                    elem->next = NULL;
                    elem->data = data + i;
                    sorted_insert(&head, elem, copmare_int);
                }
                else
                {
                    rc = ERR_READING;
                }
            }

            node_t *new_head = reverse(head);
            node_t *head_sorted = sort(new_head, copmare_int);

            size_t i = 0;

            while (head_sorted != NULL)
            {
                printf("%d ", *((int *) pop_back(&head_sorted)));
                free(data + i++);
            }
        }
        else
        {
            rc = ERR_COUNT;
        }
    }
    else
    {
        rc = ERR_READING;
    }


    return rc;
}
