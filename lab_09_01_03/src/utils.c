#include <ctype.h>
#include <stdlib.h>

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "../inc/utils.h"

#define BUFF_SIZE 30

int is_string_whitespace(char *string)
{
    int is_whitespace = 1;

    while (*string)
    {
        if (!isspace(*string))
        {
            is_whitespace = 0;
        }
        ++string;
    }

    return is_whitespace;
}

error_t read_string(FILE *fp, char **buff, size_t *size)
{
    error_t rc = ERR_OK;

    if (getline(buff, size, fp) <= 0) 
    {
        rc = ERR_READING;
    }
    else if (buff == NULL || *buff == NULL)
    {
        rc = ERR_ALLOC;
    }

    return rc;
}

error_t copy_string(char **dst, char *src)
{
    error_t rc = ERR_OK;

    if (dst != NULL)
    {
        *dst = strdup(src);

        if (*dst == NULL)
        {
            rc = ERR_ALLOC;
        }
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}

error_t parse_number(char *buffer, long long *number)
{
    error_t rc = ERR_OK;

    char *end;
    *number = (long long) strtod(buffer, &end);

    if (*end != '\r' && *end != '\n' && *end != '\0')
    {
        rc = ERR_READING;
    }

    return rc;
}

error_t parse_double(char *buffer, double *number)
{
    error_t rc = ERR_OK;

    char *end;
    *number = strtod(buffer, &end);

    if (*end != '\r' && *end != '\n' && *end != '\0')
    {
        rc = ERR_READING;
    }

    return rc;
}

error_t realloc_array(void **ptr, size_t size)
{
    error_t rc = ERR_OK;

    if (ptr != NULL && *ptr != NULL)
    {
        void *temp = realloc(*ptr, size);

        if (temp != NULL)
        {
            *ptr = temp;
        }
        else
        {
            rc = ERR_ALLOC;
        }
    }
    else
    {
        rc = ERR_INV_PTR;
    }

    return rc;
}
