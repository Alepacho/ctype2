CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g

all:
	$(CC) $(CFLAGS) main.c -o main