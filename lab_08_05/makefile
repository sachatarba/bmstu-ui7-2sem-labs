CC := gcc 
CFLAGS := -std=c99 -Werror -Wall -pedantic -Wextra
CHECK_FLAGS := $(shell pkg-config --cflags --libs check)

OBJS := ./out/matr_t.o ./out/utils.o ./out/process.o 
OBJS_CHECK :=  $(OBJS) ./unit_tests/out/check_process.o

app.exe : $(OBJS) ./out/main.o
	$(CC) $^ -lm -o app.exe

unit_tests.exe : $(OBJS_CHECK) 
	$(CC) $^ $(CHECK_FLAGS) -lm -o unit_tests.exe

./unit_tests/out/%.o : ./unit_tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

./out/%.o : ./src/%.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean build run build_units run_units

build : app.exe

build_units : unit_tests.exe
	
run_units : build_units
	./unit_tests.exe

run : build
	./app.exe

clean :
	$(RM) *.o ./out/*.o *.exe *.out
