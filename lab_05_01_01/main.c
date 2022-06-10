#include <stdio.h>
#include "utils.h"

#define ERR_OK 0
#define ERR_NO_NUMBERS -1

int main(void)
{
    int rc = ERR_OK;

    int maximum = 0;
    int second_maximum = 0;

    if ((rc = process(stdin, &maximum, &second_maximum)) == ERR_OK)
    {
        printf("%d %d", maximum, second_maximum);
    }

    return rc;
}
