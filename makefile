CC = g++
CFLAGS = -Wall -g

main: 
	$(CC) $(CFLAGS) -o main main.o

main.o: 
	$(CC) $(CFLAGS) -c -std=c++20 main.cpp
