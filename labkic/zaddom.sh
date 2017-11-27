# skompilowac tak zeby uzyc tylko jednej linijki i wypisac roznice miedzy dwoma sposobami
#!/bin/bash
gcc main.o factorial.o hello.o -o hello $(gcc -c main.c factorial.c hello.c)
