all: main
main.o: main.c
	gcc -c main.c -o main.o
functions.o: functions.c
	gcc -c functions.c -o functions.o
main: main.o functions.o
	gcc main.o functions.o -o a.out
run:
	./a.out
