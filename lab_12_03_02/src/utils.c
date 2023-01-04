#include "../inc/utils.h"

static bool is_prime(int number)
{
    size_t sq = sqrt(number);

    bool prime = true; 

    for (size_t i = 2; i <= sq + 1; ++i)
    {
        if (number % i == 0)
        {
            prime = false;
        }
    }

    return prime;
}

void fill_array_prime(int *arr, size_t size)
{
    int cur_prime_num = 2;

    for (size_t i = 0; i < size; ++i)
    {
        while (is_prime(cur_prime_num) == false)
        {
            ++cur_prime_num;
        }

        arr[i] = cur_prime_num;
        ++cur_prime_num;
    }
}

size_t insert_num_after_even(int *src, int *dst, size_t size, int num)
{
    size_t dst_size = 0;

    if (src != NULL && dst == NULL)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (src[i] % 2 == 0)
            {
                ++dst_size;
            }
        }

        dst_size += size;
    }
    else if (src != NULL && dst != NULL)
    {
        for (size_t i = 0; i < size; ++i)
        {
            dst[dst_size] = src[i];
            
            if (src[i] % 2 == 0)
            {
                dst[++dst_size] = num;
            }

            ++dst_size;
        }
    }

    return dst_size;
}
