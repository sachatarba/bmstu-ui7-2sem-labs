#include <stddef.h>
#include "stdio.h"

#include "utils.h"
#include "error_t.h"

#define BUFF_SIZE 100

#define RADIX 10

int is_symbol_endline(char symbol);

char *iter_string_while_whitespace(char *string, direction_t direction)
{
    switch (direction)
    {
    case FORWARD:
        while (isspace(*string))
        {
            ++string;
        }

        break;
    
    case BACK:
        while (isspace(*string))
        {
            --string;
        }

        break;
    }

    return string;
}

char *strip(char *string)
{
    char *start = iter_string_while_whitespace(string, FORWARD);

    size_t len = strlen(string);

    string = iter_string_while_whitespace(string + len - 1, BACK);

    *(string + 1) = '\0';

    return start;
}

/* Если в конце файле содержится более одного символа
   перевода строки, возвращает ошибку
*/
int read_number(FILE *fp, int *number)
{
    error_t rc = OK;

    char buff[BUFF_SIZE] = { '\0' };
    char *p = NULL;
    char *end = NULL;
    int num_check = 0;

    if (fgets(buff, BUFF_SIZE, fp) != NULL)
    {
        p = strip(buff);
        num_check = (int) strtol(buff, &end, RADIX);

        if (end == '\0' && strlen(p) > 0)
        {
            *number = num_check;
        }
        else if (feof(fp))
        {
            rc = ERR_EOF;
        }
        else
        {
            rc = ERR_BAD_FILE_DATA;
        }
    }
    else
    {
        rc = ERR_READING;
    }

    return rc;
}
