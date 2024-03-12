CC = g++

CFLAGS = -Wall -std=c++11

p1: p1.o testScanner.o scanner.o
	$(CC) $(CFLAGS) -o p1 p1.o testScanner.o

p1.o: p1.cpp testScanner.cpp testScanner.hpp token.hpp
	$(CC) $(CFLAGS) -c p1.cpp

testScanner.o: scanner.cpp scanner.hpp token.hpp
	$(CC) $(CFLAGS) -c testScanner.cpp

scanner.o: scanner.cpp scanner.hpp token.hpp
	$(CC) $(CFLAGS) -c scanner.cpp

clean: 
	rm *.o p1