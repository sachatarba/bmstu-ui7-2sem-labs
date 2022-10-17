#include <stdlib.h>

#include "../inc/matr_t.h"

int main(void)
{
    matr_t matr;
    create_matr(&matr, 5, 5);
    read_matr(&matr);
    print_matr(&matr);

    return 0;
}
