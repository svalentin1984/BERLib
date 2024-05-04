CC=g++

CFLAGS=-Wall -pedantic -I ../../src/bercpp -pthread

TARGET=example-bercpp

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -c main.cpp
	$(CC) $(CFLAGS) -c ../../src/bercpp/*.cpp
	$(CC) $(CFLAGS) -c ../../src/bercpp/BERException/*.cpp
	$(CC) $(CFLAGS) -o $(TARGET) *.o

clean:
	$(RM) $(TARGET) *.o
