CC=gcc
CFLAGS=-W -Wall -g
OBJECTS=main.o letter.o stack.o
EXECS=cryptoarithmetic

all: letter.o stack.o main.o
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECS)

clean:
	rm -f $(OBJECTS) $(EXECS)

# Object files
main.o: main.c
letter.o: letter.c letter.h
stack.o: stack.c stack.h

