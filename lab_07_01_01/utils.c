#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "error_t.h"

#define BUFF_SIZE 100

#define RADIX 10

// int is_symbol_endline(char symbol);

// char *iter_string_while_whitespace(char *string, direction_t direction)
// {
//     switch (direction)
//     {
//     case FORWARD:
//         while (isspace(*string))
//         {
//             ++string;
//         }

//         break;
    
//     case BACK:
//         while (isspace(*string))
//         {
//             --string;
//         }

//         break;
//     }

//     return string;
// }

// char *strip(char *string)
// {
//     char *start = iter_string_while_whitespace(string, FORWARD);

//     size_t len = strlen(string);

//     string = iter_string_while_whitespace(string + len - 1, BACK);

//     *(string + 1) = '\0';

//     return start;
// }

// /* Если в конце файле содержится более одного символа
//    перевода строки, возвращает ошибку
// */
// int read_number(FILE *fp, int *number)
// {
//     error_t rc = OK;

//     char buff[BUFF_SIZE] = { '\0' };
//     char *p = NULL;
//     char *end = NULL;
//     int num_check = 0;

//     if (fgets(buff, BUFF_SIZE, fp) != NULL)
//     {
//         p = strip(buff);
//         num_check = (int) strtol(buff, &end, RADIX);

//         if (end == '\0' && strlen(p) > 0)
//         {
//             *number = num_check;
//         }
//         else if (feof(fp))
//         {
//             rc = ERR_EOF;
//         }
//         else
//         {
//             rc = ERR_BAD_FILE_DATA;
//         }
//     }
//     else
//     {
//         rc = ERR_READING;
//     }

//     return rc;
// }

int compare_int(const void *num1, const void *num2)
{
    return *((const int *) num1) - *((const int *) num2); 
}

int create_array(int **arr_begin, int **arr_end, size_t len)
{
    error_t rc = OK;

    *arr_begin = calloc(len, sizeof(int));

    if (arr_begin != NULL)
    {
        *arr_end = *arr_begin + len;
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}

size_t find_index_of_min(const int *arr_begin, const int *arr_end)
{
    int min = *arr_begin;
    size_t ind = 0;
    size_t i = 0;

    while (arr_begin != arr_end)
    {
        if (*arr_begin < min)
        {
            min = *arr_begin;
            ind = i;
        }

        ++i;
        ++arr_begin;
    }

    return ind;
}

size_t find_index_of_max(const int *arr_begin, const int *arr_end)
{
    int max = *arr_begin;
    size_t ind = 0;
    size_t i = 0;

    while (arr_begin != arr_end)
    {
        if (*arr_begin > max)
        {
            max = *arr_begin;
            ind = i;
        }

        ++i;
        ++arr_begin;
    }

    return ind;
}

int copy_array(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst)
{
    int rc = OK;

    while (pb_src != pe_src)
    {
        if (pb_dst < pe_dst)
        {
            *pb_dst = *pb_src;
            ++pb_dst;
        }
        else
        {
            rc = ERR_ARR_OVERFLOW;
        }
        // ++pb_dst;
        ++pb_src;
    }

    return rc;
}
