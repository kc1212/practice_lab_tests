CC=g++
FLAGS=-W -Wall -pedantic -g
TARGET=words

all: $(TARGET)

$(TARGET): main.o words.o
	$(CC) $(FLAGS) main.o words.o -o $(TARGET)

main.o: main.cpp words.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

words.o: words.cpp words.h
	$(CC) $(FLAGS) -c words.cpp -o words.o

clean:
	rm -rf *.o $(TARGET)

