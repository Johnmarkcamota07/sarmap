CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Werror
SRC = src/sarmap.c main.c
OBJ = $(SRC:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
