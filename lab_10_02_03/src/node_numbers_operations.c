#include <stdio.h>

#include "../inc/node_numbers_operations.h"

size_t print_degrees(node_t *head)
{
    size_t count = 0;

    while (head != NULL)
    {
        printf("%zu ", pop_head(&head, false));
        head = head->next;
        ++count;
    }

    printf("L\n");

    return count;
}

void mul_numbers(node_t *num1, node_t *num2, node_t **res)
{
    if (num1 != NULL || num2 != NULL)
    {
        while (num1 != NULL || num2 != NULL)
        {
            if (num1 != NULL && num2 != NULL)
            {
                push_back(num1->degree + num2->degree, res);
                num1 = num1->next;
                num2 = num2->next;
            }
            else if (num1 != NULL)
            {
                push_back(num1->degree, res);
                num1 = num1->next;
            }
            else
            {
                push_back(num2->degree, res);
                num2 = num2->next;
            }
        }
    }
}

void sqr(node_t *num, node_t **res)
{
    mul_numbers(num, num, res);
}

void del_zeros(node_t **head)
{
    size_t last_degree = pop_back(head);
    
    while (last_degree == 0 && *head != NULL)
    {
        last_degree = pop_back(head);
    }

    if (last_degree != 0)
    {
        push_back(last_degree, head);
    }
}

int div_numbers(node_t *dividend, node_t *divider, node_t **res)
{
    int is_divided = 1;

    while (dividend != NULL)
    {
        if (divider != NULL)
        {
            if (dividend->degree >= divider->degree)
            {
                push_back(dividend->degree - divider->degree, res);
            }
            else
            {
                is_divided = 0;
            }

            dividend = dividend->next;
            divider = divider->next;
        }
        else
        {
            push_back(dividend->degree, res);
            dividend = dividend->next;
        }
    }

    if (divider == NULL)
    {
        del_zeros(res);
    }
    else
    {
        is_divided = 0;
    }

    return is_divided;
}
