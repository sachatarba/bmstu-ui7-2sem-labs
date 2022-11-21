#ifndef __MATH_UTILS_H__
#define __MATH_UTILS_H__

#include <stddef.h>

int is_prime(size_t number);

size_t find_max_prime_divider(size_t number);

void process_prime_factorization(const size_t number, void (*process)(size_t, void *), void *arg);

#endif //  __MATH_UTILS_H__
