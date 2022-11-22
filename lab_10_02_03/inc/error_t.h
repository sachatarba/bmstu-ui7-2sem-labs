#ifndef __ERROR_T_H__
#define __ERROR_T_H__

enum error
{
    OK,
    ERR_READING,
    ERR_ZERO_NUMBER,
    ERR_BAD_OPERATION,
    ERR_DIV
};

typedef enum error error_t;

#endif //  __ERROR_T_H__