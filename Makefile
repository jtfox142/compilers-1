CC = g++

CFLAGS = -Wall -std=c++11

p0: p0.o scanner.o
	$(CC) $(CFLAGS) -o p0 p0.o scanner.o

p0.o: p0.cpp node.hpp scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c p0.cpp

scanner.o: scanner.cpp scanner.hpp
	$(CC) $(CFLAGS) -c scanner.cpp

clean: 
	rm *.o p1