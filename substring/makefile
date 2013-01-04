CC=g++
FLAGS=-W -Wall -pedantic -g
TARGET=substring

all: $(TARGET)

$(TARGET): main.o substring.o
	$(CC) $(FLAGS) main.o substring.o -o $(TARGET)

main.o: substring.h main.cpp
	$(CC) $(FLAGS) -c main.cpp -o main.o

substring.o: substring.cpp substring.h
	$(CC) $(FLAGS) -c substring.cpp -o substring.o

clean: 
	rm -rf *.o $(TARGET)
