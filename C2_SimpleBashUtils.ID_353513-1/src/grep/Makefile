CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: s21_grep

s21_grep: s21_grep.c
	$(CC) $(CFLAGS) s21_grep.c -o s21_grep

clean:
	rm -f s21_grep

re: clean all
