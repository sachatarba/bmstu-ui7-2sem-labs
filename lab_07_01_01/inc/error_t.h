enum error_t
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
    ERR_NO_FILE
};

typedef enum error_t error_t;