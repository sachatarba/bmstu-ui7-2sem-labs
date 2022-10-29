#ifndef __ERROR_T_H__
#define __ERROR_T_H__

enum error
{
    ERR_OK,
    ERR_READING,
    ERR_NO_DATA,
    ERR_BAD_DATA,
    ERR_BAD_PRICE,
    ERR_ALLOC,
    ERR_INV_PTR,
    ERR_BAD_SIZE,
    ERR_NO_FILE,
    ERR_BAD_FLAGS
};

typedef enum error error_t;

#endif
