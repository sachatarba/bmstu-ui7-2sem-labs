#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_INVALID_NUMBER_OF_ELM 1
#define MAX_SIZE 10
#define MAX_DIGITS 10
#define BASE 10

int input_array(int *array, int *elements_number);

void print_array(int *array, int elements_number);

void make_array(int *old_array, int elements_number_of_old_array, int *new_array, int *elements_number_of_new_array);

int check_number(int number);

int main(void)
{
    int array[MAX_SIZE] = { 0 };
    int elements_number = 0;
    int exit_code = ERR_INVALID_NUMBER_OF_ELM;

    if (input_array(array, &elements_number))
    {
        if (elements_number <= MAX_SIZE && elements_number > 0)
        {
            int new_array[MAX_SIZE] = { 0 };
            int new_elements_number = 0;

            make_array(array, elements_number, new_array, &new_elements_number);
            print_array(new_array, new_elements_number);

            if (new_elements_number != 0)
            {
                exit_code = ERR_OK;
            }
        }
    }

    return exit_code;
}

int input_array(int *array, int *elements_number)
{
    int is_correct = 1;

    if (scanf("%d", elements_number) != 1)
    {
        is_correct = 0;
    }

    for (int current_element = 0; current_element < *elements_number; ++current_element)
    {
        if (scanf("%d", (array + current_element)) != 1)
        {
            is_correct = 0;
        }
    }

    return is_correct;
}

void print_array(int *array, int elements_number)
{
    for (int current_element = 0; current_element < elements_number; ++current_element)
    {
        printf("%d ", array[current_element]);
    }
}

int check_number(int number)
{
    int number_cp = number;
    int digits[MAX_DIGITS] = { 0 };
    int sum = 0;
    int current_digit = 0;
    int digits_counter = 0;
    int is_amstrong_number = 1;

    while (number > 0)
    {
        current_digit = number % BASE;
        number /= BASE;
        digits[digits_counter] = current_digit;
        ++digits_counter;
    }

    for (int current_digit = 0; current_digit < digits_counter; ++current_digit)
    {
        sum += pow(digits[current_digit], digits_counter);
    }

    if (sum != number_cp || number_cp == 0)
    {
        is_amstrong_number = 0;
    }

    return is_amstrong_number;
}

void make_array(int *old_array, int elements_number_of_old_array, int *new_array, int *elements_number_of_new_array)
{
    *elements_number_of_new_array = 0;

    for (int current_element = 0; current_element < elements_number_of_old_array; ++current_element)
    {
        if (check_number(old_array[current_element]))
        {
            new_array[*elements_number_of_new_array] = old_array[current_element];
            ++*elements_number_of_new_array;
        }
    }
}
