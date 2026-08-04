/*
 * Project 2 from Chapter 23 of King: Write a program that copies a text file
 * from standard input to standard output, removing all white-space characters
 * from the beginning of each line. A line consisting entirely of white-space
 * characters will not be copied.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	int c;
	bool print = false;

	while ((c = getchar()) != EOF) {
		if (print)
			putchar(c);
		else if (!isspace(c)) {
			print = true;
			putchar(c);
		}
		if (c == '\n')
			print = false;
	}

	return 0;
}
