#ifndef __ERROR_T_H__
#define __ERROR_T_H__

enum error
{
    OK,
    ERR_BAD_ROWS,
    ERR_BAD_COLS,
    ERR_INV_PTR,
    ERR_READING,
    ERR_INV_STRUCT_PTR,
    ERR_ALLOC_MATR
};

typedef enum error error_t;

#endif
