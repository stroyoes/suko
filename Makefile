CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
TARGET = suko
SRC = main.c solver.c board.c 

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
