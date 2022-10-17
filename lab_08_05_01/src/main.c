#include <stdlib.h>

#include "../inc/matr_t.h"

int main(void)
{
    matr_t matr;
    // create_matr(&matr, 2, 3);
    read_matr(&matr);
    del_col(&matr, 1);
    print_matr(&matr);
    free_matr(&matr);

    return 0;
}
