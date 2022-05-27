#include <stdio.h>
#include <string.h>
#include "utils.h"


#define ARGS_A_B 4
#define ARGS_C 3

#define FIRST_FLAG "sb"
#define SECOND_FLAG "fb"
#define THIRD_FLAG "ab"

#define ERR_OK 0
#define ERR_NO_FILE 1
#define ERR_WRONG_FLAGS 53

int main(int argc, char *argv[])
{
    printf("o shit i am sorry");
    int rc = ERR_OK;

    // FILE *fp = fopen("file_out.txt", "r+b");
    // product_t temp;
    // input_struct(&temp);
    // write_struct(fp, &temp, 3);
    // print_file(fp);
    

    printf("o shit i am sorry");
    if (argc == ARGS_A_B)
    {
        if (!strcmp(argv[ARGS_A_B - 3], FIRST_FLAG))
        {
            FILE *source_file = fopen(argv[ARGS_A_B - 2], "rb");

            if (source_file != NULL)
            {
                FILE *destination_file = fopen(argv[ARGS_A_B - 1], "wb");

                if (destination_file != NULL)
                {
                    printf("o shit i am sorry");
                    sort(source_file, destination_file);
                    print_file(destination_file);
                    
                    fclose(destination_file);
                }
                else
                {
                    rc = ERR_NO_FILE;
                }

                fclose(source_file);
            }
            else
            {
                rc = ERR_NO_FILE;
            }
        }
    }

    return rc;
}
