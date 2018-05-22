CC = g++
CFLAGS = -std=c++11 -pthread

all: main.o pth.o
	@$(CC) $(CFLAGS) -o run main.o

main.o: main.cpp pth.h
	@$(CC) $(CFLAGS) -c main.cpp

pth.o: pth.h

clean:
	@rm -rf run *.o
