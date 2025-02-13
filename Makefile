CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/sarmap.c
OBJ = $(SRC:.c=.o)

# Define output directories
LIBDIR = lib
BINDIR = bin

# Define Static Library
STATIC_LIB = $(LIBDIR)/libsarmap.a
TEST_PROGRAM = $(BINDIR)/main

# Windows (MinGW) Support
ifeq ($(OS), Windows_NT)
    STATIC_LIB = $(LIBDIR)/sarmap.lib
    CFLAGS += -D BUILD_SARMAP
endif

all: folders $(STATIC_LIB) $(TEST_PROGRAM)

folders:
	mkdir -p $(LIBDIR) $(BINDIR)

# Compile object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Create Static Library
$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

# Compile Test Program
$(TEST_PROGRAM): main.c $(STATIC_LIB)
	$(CC) -Iinclude main.c -L$(LIBDIR) -lsarmap -o $@

clean:
	rm -f $(OBJ) $(STATIC_LIB) $(TEST_PROGRAM)
