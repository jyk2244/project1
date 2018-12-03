CC=g++
CFLAGS=-std=c++11 
TARGET=library
OBJECTS=library.o resource.o member.o space.o time.o

$(TARGET): $(OBJECTS) main.cpp
		$(CC) $(CFLAGS) -o $@ $^

library.o: library.cpp
		$(CC) $(CFLAGS) -c $^

resource.o: resource.cpp
		$(CC) $(CFLAGS) -c $^

member.o: member.cpp
		$(CC) $(CFLAGS) -c $^

space.o: space.cpp
		$(CC) $(CFLAGS) -c $^

time.o: time.cpp
		$(CC) $(CFLAGS) -c $^


