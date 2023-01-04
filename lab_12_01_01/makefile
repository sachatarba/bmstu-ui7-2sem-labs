CC := gcc 
CFLAGS := -std=gnu99 -Werror -Wall -Wextra
CHECK_FLAGS := $(shell pkg-config --cflags --libs check)

OBJS :=

app.exe : ./out/libarr.a ./out/libprocess.so ./out/libutils.so ./out/main.o
	export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:./out/
	$(CC) ./out/main.o -larr -lutils -ldl -lm -L./out/ -o app.exe

unit_tests.exe : $(OBJS_CHECK) 
	$(CC) $^ $(CHECK_FLAGS) -lm -o unit_tests.exe

./unit_tests/out/%.o : ./unit_tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

./out/main.o : ./src/main.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

./out/libarr.a : ./src/array_t.c
	$(CC) $(CFLAGS) -c $< -o ./out/array_t.o
	ar rc $@ ./out/array_t.o

./out/libprocess.so : ./src/process.c
	$(CC) $(CFLAGS) -fPIC -c $< -o ./out/process.o
	$(CC) -o ./out/libprocess.so -shared ./out/process.o

./out/libutils.so : ./src/utils.c
	$(CC) $(CFLAGS) -fPIC -c $< -o ./out/utils.o
	$(CC) -o ./out/libutils.so -shared ./out/utils.o

./out/*.a : $(OBJS_STATIC)

.PHONY: clean build run build_units run_units

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

build_units : unit_tests.exe
	
run_units : build_units
	./unit_tests.exe

run : build
	./app.exe

clean :
	$(RM) *.o ./out/*.o *.exe *.out *.so *.a ./out/*.so ./out/*.a