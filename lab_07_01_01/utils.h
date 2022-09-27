enum direction_t
{
    BACK,
    FORWARD
};

typedef enum direction_t direction_t;

int is_symbol_endline(char symbol);

const char *iter_string_while_whitespace(const char *string, direction_t direction);

char *strip(char *string);

int read_number(FILE *fp, int *number);
