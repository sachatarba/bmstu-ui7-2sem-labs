#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "../inc/matr_t.h"
#include "../inc/process.h"

int main(void)
{
    error_t rc = OK;

    matr_t l, r;

    if ((rc = read_matr(&l)) == OK)
    {
        if ((rc = read_matr(&r)) == OK)
        {                                             // 2  and 2 3 | 5 6
            if ((rc = crop_matr_to_square(&l)) == OK) // 2 | 2 and 2 3 | 5 6
            {
                if ((rc = crop_matr_to_square(&r)) == OK) // 2 2 | 2 2
                {
                    if ((rc = expand_to_bigger_matrix(&l, &r)) == OK)
                    {
                        int rho, gamma = 0;

                        if (scanf("%d %d", &rho, &gamma) == 2)
                        {
                            if (rho >= 0 && gamma >= 0)
                            {
                                matr_t pow_l = l;
                                matr_t pow_r = r;

                                for (size_t i = 0; i < (size_t) rho - 1; ++i)
                                {
                                    mul_matr(&pow_l, &l, &pow_l);
                                }

                                for (size_t j = 0; j < (size_t) gamma - 1; ++j)
                                {
                                    mul_matr(&pow_r, &r, &pow_r);
                                }

                                matr_t res;
                                mul_matr(&pow_l, &pow_r, &res);

                                print_matr(&res);

                                free_matr(&l);
                                free_matr(&r);
                                free_matr(&res);
                            }
                            else
                            {
                                rc = ERR_BAD_POWS;
                            }
                        }
                    }
                }
            }
        }
    }

    return rc;
}
