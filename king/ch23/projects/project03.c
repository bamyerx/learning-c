/*
 * Project 3 from Chapter 23 of King: Write a program that copies a text file
 * from standard input to standard output, capitalizing the first letter in each
 * word.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	int c;
	bool capitalize = true;

	while ((c = getchar()) != EOF) {
		if (capitalize && !isspace(c)) {
			putchar(toupper(c));
			capitalize = false;
		} else
			putchar(c);
		if (isspace(c))
			capitalize = true;
	}

	return 0;
}
