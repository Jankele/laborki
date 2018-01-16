all: a.out
a.out: main.o functions.o
	gcc main.o functions.o -o a.out
main.o: main.c
	gcc -c main.c
functions.o: functions.c
	gcc -c functions.c