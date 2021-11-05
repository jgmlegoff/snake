LDFLAGS = -lncurses

all: snake

snake: main.o snake.o
	gcc snake.o main.o -o snake $(LDFLAGS)

snake.o : snake.c snake.h
	gcc -c snake.c -o snake.o 

main.o : main.c
	gcc -c main.c -o main.o 

