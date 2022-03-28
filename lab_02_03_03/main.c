#include <stdio.h>

#define ERR_OK 0
#define ERR_INVALID_NUMBER_OF_ELM 1
#define MAX_SIZE 10
#define SIZE 20

int input_array(int *array, int *elements_number);

void print_array(int *array, int elements_number);

int reverse_number(int number);

void insert_element(int *array, int array_size, int element, int pos);

void modify_array(int *array, int array_size, int *new_array_size);

int main(void)
{
    int array[SIZE] = { 0 };
    int elements_number = 0;
    int exit_code = ERR_INVALID_NUMBER_OF_ELM;

    if (input_array(array, &elements_number))
    {
        int new_array_size = 0;

        if (elements_number <= MAX_SIZE && elements_number > 0)
        {
            modify_array(array, elements_number, &new_array_size);
            print_array(array, new_array_size);
            exit_code = ERR_OK;
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

int reverse_number(int number)
{
    int reverse = 0;
    int current_digit = 0;

    while (number > 0)
    {
        current_digit = number % 10;
        number /= 10;
        reverse *= 10;
        reverse += current_digit;
    }

    return reverse;
}

void insert_element(int *array, int array_size, int element, int pos)
{
    for (int current_pos = array_size; current_pos >= pos; --current_pos)
    {
        array[current_pos + 1] = array[current_pos];
    }

    array[pos] = element; 
}

void modify_array(int *array, int array_size, int *new_array_size)
{
    *new_array_size = array_size;

    for (int current_element = 0; current_element < 2 * array_size; ++current_element)
    {
        if (array[current_element] > 0)
        {
            insert_element(array, *new_array_size, reverse_number(array[current_element]), current_element + 1);
            ++current_element;
            ++*new_array_size;
        }
    }
}
