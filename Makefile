
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

min-in-rotated-sorted-array: min-in-rotated-sorted-array.o
	$(CC) $(CFLAGS) -o min-in-rotated-sorted-array min-in-rotated-sorted-array.o

min-in-rotated-sorted-array.o: min-in-rotated-sorted-array.cpp
	$(CC) $(CFLAGS) -c min-in-rotated-sorted-array.cpp

clean:
	rm -rf min-in-rotated-sorted-array min-in-rotated-sorted-array.o
