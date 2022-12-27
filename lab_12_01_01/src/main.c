#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dlfcn.h>

#include "../inc/array_t.h"
#include "../inc/process.h"
#include "../inc/utils.h"
#include "../inc/error_t.h"

#define KEY_FLAG "f"

typedef int (*fn_key_t)(const int *, const int *, int **, int **, size_t *);

typedef void (*fn_mysort_t)(void *, size_t, size_t, int (*cmp)(const void *, const void *));

int main(int argc, char **argv)
{
    
    error_t rc = OK;

    void *hlib = dlopen("./out/libprocess.so", RTLD_NOW);
    if (!hlib)
    {
        printf("Cannot open library. %s\n", dlerror());

        rc = ERR_LOAD_LIB;
    }

    fn_key_t key = (fn_key_t) dlsym(hlib, "key");
    fn_mysort_t mysort = (fn_mysort_t) dlsym(hlib, "mysort");

    if (!key || !mysort)
    {
        rc = ERR_LOAD_LIB;
    }

    if ((argc == 3 || argc == 4) && rc == OK)
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
                if ((rc = init_array_from_file(fin, &a)) == OK)
                {
                    if (argc == 4)
                    {
                        array_t b;
                        size_t len = 0;
                        memset(&b, 0, sizeof(array_t));

                        if ((rc = key(a.p, a.p + a.len, &b.p, &b.end, &len)) == ERR_NO_MEM_ENOUGH)
                        {
                            if (create_array(&b.p, &b.end, len) == OK)
                            {
                                if ((rc = key(a.p, a.p + a.len, &b.p, &b.end, &len)) == OK)
                                {
                                    FILE *fout = fopen(argv[2], "w");
                                    
                                    b.len = b.end - b.p;
                                    mysort(b.p, b.len, sizeof(int), compare_int);
                                    print_array_to_file(fout, &b);
                                    
                                    fclose(fout);
                                }
                            }
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
    
    dlclose(hlib);

    return rc;
}
