#include <stdlib.h>
#include "utils.h"

#define NUMBERS_TO_WRITE 1

void write_rand_numbers_to_bin_file(FILE *fp, int number)
{
    int number_to_write = 0;

    for (int current_number = 0; current_number < number; ++current_number)
    {
        number_to_write = rand();
        fwrite(&number_to_write, sizeof(int), NUMBERS_TO_WRITE, fp);
    }
}

int print_numbers(FILE *fp)
{
    int number_to_print = 0;
    int count = 0;

    while (fread(&number_to_print, sizeof(int), 1, fp) == 1)
    {
        printf("%d ", number_to_print);
        ++count;
    }

    return count;
}

int get_number_by_pos(FILE *fp, int *number, int pos)
{
    long int seek_cur = ftell(fp);
    fseek(fp, pos * sizeof(int), SEEK_SET);
    int count = fread(number, sizeof(int), 1, fp);
    fseek(fp, seek_cur, SEEK_SET);

    return count;
}

void set_number_by_pos(FILE *fp, int number, int pos)
{
    long int seek_cur = ftell(fp);
    fseek(fp, pos * sizeof(int), SEEK_SET);
    fwrite(&number, sizeof(int), 1, fp);
    fseek(fp, seek_cur, SEEK_SET);
}

void swap_numbers_on_pos(FILE *fp, int pos1, int pos2)
{
    int num1, num2 = 0;
    get_number_by_pos(fp, &num1, pos1);
    get_number_by_pos(fp, &num2, pos2);
    set_number_by_pos(fp, num2, pos1);
    set_number_by_pos(fp, num1, pos2);
}

int sort(FILE *fp)
{
    int num1, num2 = 0;
    int pos1 = 0, pos2 = 0;

    while (get_number_by_pos(fp, &num1, pos1) == 1)
    {
        pos2 = 0;

        while (get_number_by_pos(fp, &num1, pos2) == 1 && get_number_by_pos(fp, &num2, pos2 + 1) == 1)
        {
            if (num1 > num2)
            {
                swap_numbers_on_pos(fp, pos2 + 1, pos2);
            }
            ++pos2;
        }

        ++pos1;
    }

    return pos1;
}
