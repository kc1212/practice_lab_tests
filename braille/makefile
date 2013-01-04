CC=g++
FLAGS=-W -Wall -pedantic -g
TARGET=braille

all: $(TARGET)

$(TARGET): main.o braille.o
	$(CC) $(FLAGS) main.o braille.o -o $(TARGET)

main.o: main.cpp braille.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

braille.o: braille.cpp braille.h
	$(CC) $(FLAGS) -c braille.cpp -o braille.o

clean:
	rm -rf *.o $(TARGET)

