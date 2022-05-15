#include <stdio.h>

#define ERR_OK 0
#define ERR_INVALID_NUMBER_OF_ELM 1
#define MAX_SIZE 10

int input_array(int *array_begin, int *array_end);

void copy_pos_elm(int *source_begin, int *source_end, int *cp_begin, int **cp_end);

void copy_neg_elm(int *source_begin, int *source_end, int *cp_begin, int **cp_end);

int calc_mul(int *array1_begin, int *array1_end, int *array2_begin, int *array2_end);

int main(void)
{
    int array_begin[MAX_SIZE] = { 0 };
    int *array_end = array_begin + MAX_SIZE;
    int exit_code = ERR_INVALID_NUMBER_OF_ELM;

    if (input_array(array_begin, array_end))
    {
        if (array_end - array_begin <= MAX_SIZE && array_end - array_begin > 0)
        {
            int array_pos_begin[MAX_SIZE] = { 0 };
            int *array_pos_end = array_pos_begin + MAX_SIZE;
            int array_neg_begin[MAX_SIZE] = { 0 };
            int *array_neg_end = array_neg_begin + MAX_SIZE;

            copy_pos_elm(array_begin, array_end, array_pos_begin, &array_pos_end);
            copy_neg_elm(array_begin, array_end, array_neg_begin, &array_neg_end);

            if (array_pos_end - array_pos_begin > 0 && array_neg_end - array_neg_begin > 0)
            {
                int ans = calc_mul(array_pos_begin, array_pos_end, array_neg_begin, array_neg_end);
                printf("%d", ans);

                exit_code = ERR_OK;
            }
        }
    }

    return exit_code;
}

int input_array(int *array_begin, int *array_end)
{
    int is_correct = 1;
    int elements_number = 0;

    if (scanf("%d", &elements_number) != 1)
    {
        is_correct = 0;
    }

    array_end = array_begin + elements_number;
    int *current_ptr = array_begin;

    while (current_ptr < array_end)
    {
        if (scanf("%d", current_ptr++) != 1)
        {
            is_correct = 0;
        }
    }

    return is_correct;
}

void copy_pos_elm(int *source_begin, int *source_end, int *cp_begin, int **cp_end)
{
    int *current_ptr_source = source_begin;
    *cp_end = cp_begin;

    while (current_ptr_source < source_end)
    {
        if (*current_ptr_source > 0)
        {
            **cp_end = *current_ptr_source;
            ++*cp_end;
        }

        ++current_ptr_source;
    }
}

void copy_neg_elm(int *source_begin, int *source_end, int *cp_begin, int **cp_end)
{
    int *current_ptr_source = source_begin;
    *cp_end = cp_begin;

    while (current_ptr_source < source_end)
    {
        if (*current_ptr_source < 0)
        {
            **cp_end = *current_ptr_source;
            ++*cp_end;
        }

        ++current_ptr_source;
    }
}

int calc_mul(int *array1_begin, int *array1_end, int *array2_begin, int *array2_end)
{
    int min = (array1_end - array1_begin < array2_end - array2_begin) ? array1_end - array1_begin : array2_end - array2_begin;
    int mul = 0;

    for (int current_elm = 0; current_elm < min; ++current_elm)
    {
        mul += *array2_begin * *(array1_end - 1);
        ++array2_begin;
        --array1_end;
    }

    return mul;
}
