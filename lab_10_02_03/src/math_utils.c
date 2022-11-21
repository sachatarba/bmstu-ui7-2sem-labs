#include <math.h>
#include <stdio.h>

int is_prime(size_t number)
{
    int is_num_prime = 1;

    for (size_t i = 2; i < (size_t) sqrt(number) + 1; ++i)
    {
        if (number % i == 0)
        {
            is_num_prime = 0;
        }
    }

    return is_num_prime;
}

size_t find_max_prime_divider(size_t number)
{
    size_t max = 1;

    for (size_t i = 2; i <= number; ++i)
    {
        if (number % i == 0)
        {
            if (is_prime(i))
            {
                max = i;
            }
        }
    }

    return max;
}

void process_prime_factorization(size_t number, void (*process)(size_t, void *), void *arg)
{
    size_t degree = 0;
    size_t div_in_max_degree = 0;
    size_t max_prime_divider = find_max_prime_divider(number);

    for (size_t i = 2; i < max_prime_divider + 1; ++i)
    {
        if (is_prime(i))
        {
            degree = 0;

            if (number % i == 0)
            {
                div_in_max_degree = i;

                while (number % div_in_max_degree == 0)
                {
                    ++degree;
                    div_in_max_degree *= i;
                }
            }

            process(degree, arg);
        }
    }
}
