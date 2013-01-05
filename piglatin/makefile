CC=g++
FLAGS=-W -Wall -pedantic -g
TARGET=piglatin

all: $(TARGET)

$(TARGET): main.o piglatin.o
	$(CC) $(FLAGS) main.o piglatin.o -o $(TARGET)

main.o: main.cpp piglatin.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

piglatin.o: piglatin.cpp piglatin.h
	$(CC) $(FLAGS) -c piglatin.cpp -o piglatin.o

clean:
	rm -rf *.o $(TARGET)