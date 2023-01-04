CC := gcc 
CFLAGS := -std=gnu99 -Werror -Wall -Wextra

./out/libutils.so : ./src/utils.c
	$(CC) $(CFLAGS) -fPIC -c $< -o ./out/utils.o
	$(CC) -o ./out/libutils.so -shared ./out/utils.o

.PHONY: clean build run build_units run_units

run : ./out/libutils.so
	python3 ./src/main.py

clean :
	$(RM) *.o ./out/*.o *.exe *.out *.so *.a ./out/*.so ./out/*.a