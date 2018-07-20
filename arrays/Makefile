CC = g++

CFLAGS = -c -Wall -g

all: test

clean:
	rm -rf *o test

test: main.o rvector.o rvector_test.o
	$(CC) main.o rvector.o rvector_test.o -o test

main.o: main.cc
	$(CC) $(CFLAGS) main.cc

rvector.o: rvector.cc
	$(CC) $(CFLAGS) rvector.cc

rvector_test.o: rvector_test.cc
	$(CC) $(CFLAGS) rvector_test.cc
