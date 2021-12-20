CC = gcc
AR = ar
OBJECTS_MAIN = stringProg.o
FLAGS = -Wall -g

all: stringProg

stringProg: $(OBJECTS_MAIN)
	$(CC) $(flags)  -o stringProg $(OBJECTS_MAIN)

stringProg.o: stringProg.c
	$(CC) $(flags)  -c stringProg.c

run:
	./stringProg -> out.txt

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
