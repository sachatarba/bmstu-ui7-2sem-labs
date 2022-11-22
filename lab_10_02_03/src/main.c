#include <stdio.h>
#include <string.h>

#include "../inc/node_t.h"
#include "../inc/node_numbers_operations.h"
#include "../inc/math_utils.h"
#include "../inc/error_t.h"

#define OUT "out"
#define MUL "mul"
#define SQR "sqr"
#define DIV "div"

#define BUFF 10

int main(void)
{
    error_t rc = OK;

    char operation[BUFF] = "\0";

    if (scanf("%s", operation) == 1)
    {
        if (strcmp(operation, OUT) == 0)
        {
            long long number = 0;

            if (scanf("%lld", &number) == 1)
            {
                if (number > 0)
                {
                    node_t *prime_fact = NULL;
                    
                    process_prime_factorization((size_t) number, push_back_to_node_t, (void *) &prime_fact);
                    print_degrees(prime_fact);

                    free_node(&prime_fact);
                }
                else
                {
                    rc = ERR_ZERO_NUMBER;
                }
            }
            else
            {
                rc = ERR_READING;
            }         
        }
        else if (strcmp(operation, SQR) == 0)
        {
            long long number = 0;

            if (scanf("%lld", &number) == 1)
            {
                if (number > 0)
                {
                    node_t *prime_fact = NULL;
                    node_t *prime_fact_sqr = NULL;
                    
                    process_prime_factorization((size_t) number, push_back_to_node_t, (void *) &prime_fact);
                    sqr(prime_fact, &prime_fact_sqr);

                    print_degrees(prime_fact_sqr);
                    
                    free_node(&prime_fact);
                    free_node(&prime_fact_sqr);
                }
                else
                {
                    rc = ERR_ZERO_NUMBER;
                }
            }
            else
            {
                rc = ERR_READING;
            }       
        }
        else if (strcmp(operation, MUL) == 0)
        {
            long long num1 = 0, num2 = 0;

            if (scanf("%lld %lld", &num1, &num2) == 2)
            {
                if (num1 > 0 && num2 > 0)
                {
                    node_t *prime_fact1 = NULL;
                    node_t *prime_fact2 = NULL;
                    node_t *prime_fact_res = NULL;
                    
                    process_prime_factorization((size_t) num1, push_back_to_node_t, (void *) &prime_fact1);
                    process_prime_factorization((size_t) num2, push_back_to_node_t, (void *) &prime_fact2);
                    
                    mul_numbers(prime_fact1, prime_fact2, &prime_fact_res);

                    print_degrees(prime_fact_res);

                    free_node(&prime_fact1);
                    free_node(&prime_fact2);
                    free_node(&prime_fact_res);
                }
                else
                {
                    rc = ERR_ZERO_NUMBER;
                }
            } 
            else
            {
                rc = ERR_READING;
            }   
        }
        else if (strcmp(operation, DIV) == 0)
        {
            long long divinded = 0, divider = 0;

            if (scanf("%lld %lld", &divinded, &divider) == 2)
            {
                if (divinded > 0 && divider > 0)
                {
                    node_t *prime_fact1 = NULL;
                    node_t *prime_fact2 = NULL;
                    node_t *prime_fact_res = NULL;
                    
                    process_prime_factorization((size_t) divinded, push_back_to_node_t, (void *) &prime_fact1);
                    process_prime_factorization((size_t) divider, push_back_to_node_t, (void *) &prime_fact2);
                    
                    if (div_numbers(prime_fact1, prime_fact2, &prime_fact_res))
                    {
                        print_degrees(prime_fact_res);
                    }
                    else
                    {
                        rc = ERR_DIV;
                    }


                    free_node(&prime_fact1);
                    free_node(&prime_fact2);
                    free_node(&prime_fact_res);
                }
                else
                {
                    rc = ERR_ZERO_NUMBER;
                }
            }
            else
            {
                rc = ERR_READING;
            }   
        }
        else
        {
            rc = ERR_BAD_OPERATION;
        }
    }
    else
    {
        rc = ERR_READING;
    }

    return rc;
}