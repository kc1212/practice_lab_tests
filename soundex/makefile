CC=g++
FLAGS=-W -Wall -pedantic -g
TARGET=soundex

all: $(TARGET)

$(TARGET): main.o soundex.o
	$(CC) $(FLAGS) main.o soundex.o -o $(TARGET)

main.o: main.cpp soundex.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

soundex.o: soundex.cpp soundex.h
	$(CC) $(FLAGS) -c soundex.cpp -o soundex.o
	
clean: 
	rm -rf *.o $(TARGET)
