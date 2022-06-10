#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "w+b");
    product_t temp;

    for (int i = 0; i < atoi(argv[2]); ++i)
    {
        input_struct(&temp);
        write_struct(fp, &temp, i);
    }

    printf("Вывод файла:\n");
    print_file(fp);
    fclose(fp);

    return 0;
}