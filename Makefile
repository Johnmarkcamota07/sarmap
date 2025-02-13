CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -fPIC
SRC = src/sarmap.c
OBJ = $(SRC:.c=.o)

# Define output directories
LIBDIR = lib
BINDIR = bin

# Create static and shared library names
STATIC_LIB = $(LIBDIR)/libsarmap.a
SHARED_LIB = $(LIBDIR)/libsarmap.so
TEST_PROGRAM = $(BINDIR)/main

# Windows (MinGW) Support
ifeq ($(OS), Windows_NT)
    SHARED_LIB = $(LIBDIR)/sarmap.dll
    CFLAGS += -D BUILD_SARMAP
endif

all: folders $(STATIC_LIB) $(SHARED_LIB) $(TEST_PROGRAM)

folders:
	mkdir -p $(LIBDIR) $(BINDIR)

# Compile object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Create Static Library
$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

# Create Shared Library (Linux/macOS: .so, Windows: .dll)
$(SHARED_LIB): $(OBJ)
	$(CC) -shared -o $@ $^

# Compile Test Program
$(TEST_PROGRAM): main.c $(STATIC_LIB)
	$(CC) -Iinclude main.c -L$(LIBDIR) -lsarmap -o $@

clean:
	rm -f $(OBJ) $(STATIC_LIB) $(SHARED_LIB) $(TEST_PROGRAM)
