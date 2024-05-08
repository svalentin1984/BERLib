CC=gcc

CFLAGS=-Wall -pedantic -I ../../src/berc

TARGET=example-berc

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -c main.c
	$(CC) $(CFLAGS) -c ../../src/berc/*.c
	$(CC) $(CFLAGS) -o $(TARGET) *.o
clean:
	$(RM) $(TARGET) *.o
