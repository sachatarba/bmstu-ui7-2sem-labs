#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/array_t.h"
#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"

#define KEY_FLAG "f"

int main(int argc, char **argv)
{
    error_t rc = OK;

    if (argc == 3 || argc == 4)
    {
        if (argc == 4 && strcmp(argv[3], KEY_FLAG))
        {
            rc = ERR_BAD_FLAG;
        }
        else
        {
            FILE *fin = fopen(argv[1], "r");

            array_t a;
            memset(&a, 0, sizeof(array_t));

            if (fin != NULL)
            {
                if ((rc = get_array_len(fin, &a)) == OK)
                {
                    fseek(fin, SEEK_SET, 0);
                    init_array(&a);
                    read_array(fin, &a);

                    if (argc == 4)
                    {
                        array_t b;
                        memset(&b, 0, sizeof(array_t));

                        if ((rc = key(a.p, a.p + a.len, &b.p, &b.end)) == OK)
                        {
                            FILE *fout = fopen(argv[2], "w");
                            
                            b.len = b.end - b.p;
                            mysort(b.p, b.len, sizeof(int), compare_int);
                            print_array_to_file(fout, &b);
                            
                            fclose(fout);
                        }

                        free_array(&b);
                    }
                    else
                    {
                        FILE *fout = fopen(argv[2], "w");

                        mysort(a.p, a.len, sizeof(int), compare_int);
                        print_array_to_file(fout, &a);

                        fclose(fout);
                    }

                    free_array(&a);
                }

                fclose(fin);
            }
            else
            {
                rc = ERR_NO_FILE;
            }
        }
    }
    else
    {
        rc = ERR_WRONG_FLAGS_COUNT;
    }
    
    return rc;
}
