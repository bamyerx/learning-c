/*
 * Project 6 from Chapter 23 of King: Write a program that copies a text file
 * from standard input to standard output, replace each control characters
 * (other than \n) by a question mark.
 */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
	int c;

	while ((c = getchar()) != EOF)
		if (iscntrl((unsigned char) c) && c != '\n')
			putchar('?');
		else
			putchar(c);

	return 0;
}
