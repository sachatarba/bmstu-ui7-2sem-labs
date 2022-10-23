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
        {                                             
            if ((rc = crop_matr_to_square(&l)) == OK)
            {
                if ((rc = crop_matr_to_square(&r)) == OK)
                {
                    if ((rc = expand_to_bigger_matrix(&l, &r)) == OK)
                    {
                        int rho, gamma = 0;

                        if (scanf("%d %d", &rho, &gamma) == 2)
                        {
                            if (rho >= 0 && gamma >= 0)
                            {
                                matr_t pow_l, pow_r, res;
                                memset(&res, 0, sizeof(matr_t));
                                pow_matr(&l, &pow_l, rho);
                                pow_matr(&r, &pow_r, gamma);
                                mul_matr(&pow_l, &pow_r, &res);

                                print_matr(&res);

                                free_matr(&res);
                                free_matr(&pow_l);
                                free_matr(&pow_r);
                            }
                            else
                            {
                                rc = ERR_BAD_POWS;
                            }
                        }
                        else
                        {
                            rc = ERR_NO_POWERS;
                        }
                    }
                }
            }

            free_matr(&r);
        }

        free_matr(&l);
    }

    return rc;
}
