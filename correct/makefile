CC=g++
FLAGS=-W -Wall -pedantic -std=gnu++98 -g
TARGET=correct

all: $(TARGET)

$(TARGET): main.o correct.o
	$(CC) $(FLAGS) main.o correct.o -o $(TARGET)

main.o: main.cpp correct.h
	$(CC) $(FLAGS) -c main.cpp -o main.o

correct.o: correct.cpp correct.h
	$(CC) $(FLAGS) -c correct.cpp -o correct.o

clean:
	rm -rf *.o $(TARGET)

