#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_INVALID_NUMBER 1

void input_array(int *elements_number, int *array);

double calc_geometric_mean(int elements_number, int *array);

int main(void)
{
    int array[10] = { 0 };
    int elements_number = 0;
    int exit_code = ERR_INVALID_NUMBER;
    double ans = 0;

    input_array(&elements_number, array);

    if (elements_number <= 10 && elements_number >= 0)
    {
        ans = calc_geometric_mean(elements_number, array);
        printf("%lf", ans);
        exit_code = ERR_OK;
    }

    return exit_code;
}

void input_array(int *elements_number, int *array)
{
    scanf("%d", elements_number);

    for (int current_element = 0; current_element < *elements_number; ++current_element)
    {
        scanf("%d", &array[current_element]);
    }
}

double calc_geometric_mean(int elements_number, int *array)
{
    double geometric_mean = 1;

    for (int current_element = 0; current_element < elements_number; ++current_element)
    {
        geometric_mean *= array[current_element];  
    }

    geometric_mean = pow(geometric_mean, 1. / elements_number);

    return geometric_mean;
}