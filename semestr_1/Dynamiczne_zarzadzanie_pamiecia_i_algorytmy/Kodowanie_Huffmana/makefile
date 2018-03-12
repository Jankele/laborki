all: main
tomke.o: main.c
	gcc -c main.c -o main.o
funkcje.o: funkcje.c
	gcc -c funkcje.c -o funkcje.o
main: main.o funkcje.o
	gcc main.o funkcje.o -o a.out
run:
	./a.out
clean:
	rm *.o
