CC= gcc -Wall

test: test.o qsort.o
	$(CC) -o test test.o qsort.o

test.o:

qsort.o:
