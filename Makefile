# Paths
SRC := main.c
OUTPUT := main

# Compiler Settings
CC := gcc
C_STD := c99
CFLAGS := -Wall -Werror -Wimplicit-function-declaration

all:
	$(CC) -std=$(C_STD) $(SRC) -o $(OUTPUT) $(CFLAGS)

# Command that needs to run is this:
# gcc -std=c99 -o main main.c -Wall -Werror -Wimplicit-function-declaration -Llib -lraylib -lgdi32 -lwinmm

clean:
	rm main.exe