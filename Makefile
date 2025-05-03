SRC := src/main.c
LIB := -Llib
OUTPUT := main

# Compiler Settings
CC := gcc
C_STD := c99
CFLAGS := -Wall -Werror -Wimplicit-function-declaration

# raylib link flags
RAYLIB_FLAGS := -lraylib -lgdi32 -lwinmm

all:
	$(CC) -std=$(C_STD) $(SRC) -o $(OUTPUT) $(CFLAGS) $(LIB) $(RAYLIB_FLAGS)

# Command that needs to run is this:
# gcc -std=c99 -o main main.c -Wall -Werror -Wimplicit-function-declaration -Llib -lraylib -lgdi32 -lwinmm

clean:
	rm main.exe