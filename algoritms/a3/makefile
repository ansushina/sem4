

CFLAGS := -std=c99 -Wall -Werror -pedantic -ggdb

app.exe: main.o io.o process.o
	gcc -o app.exe process.o main.o io.o
	
process.o : process.c process.h errors.h io.h
	gcc $(CFLAGS) -c process.c
	
io.o : io.c io.h errors.h
	gcc $(CFLAGS) -c io.c
	
main.o : main.c process.h errors.h io.h
	gcc $(CFLAGS) -c main.c

tabl.exe : tabl.c
	gcc $(CFLAGS) -o tabl.exe tabl.c
	
clean :
	rm *.exe *.o
