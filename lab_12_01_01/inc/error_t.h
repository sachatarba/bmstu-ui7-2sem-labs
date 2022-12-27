#ifndef __ERROR_T_H__
#define __ERROR_T_H__

enum error
{
    OK,
    ERR_BAD_LEN,
    ERR_INV_PTR,
    ERR_BAD_FILE_DATA,
    ERR_READING,
    ERR_EOF,
    ERR_ARR_OVERFLOW,
    ERR_BAD_FLAG,
    ERR_WRONG_FLAGS_COUNT,
    ERR_NO_FILE,
    ERR_INV_STRUCT_PTR,
    DST_NULL_PTR,
    ERR_NO_MEM_ENOUGH,
    ERR_LOAD_LIB
};

typedef enum error error_t;

#endif
