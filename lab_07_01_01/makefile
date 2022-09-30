CC := gcc 
CFLAGS := -std=c99 -Werror -Wall -pedantic -Wextra

OBJS := ./out/array_t.o ./out/process.o ./out/utils.o 
# OBJS := array_t.o process.o utils.o

app.exe : $(OBJS) ./out/main.o
	$(CC) $(CFLAGS) $^ -o app.exe

./out/%.o : ./src/%.c ./inc/*.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean build run

build : app.exe

run : build
	app.exe

clean :
	$(RM) *.o ./out/*.o *.exe *.out
