CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -Wconversion -g

SRC ?= sandbox/scratch.c
OUT ?= bin/program

run:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	./$(OUT)

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

check:
	$(CC) $(CFLAGS) -fsyntax-only $(SRC)

clean:
	rm -rf bin/* build/*
