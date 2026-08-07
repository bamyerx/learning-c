/*
 * Exercise 7-2 from K&R: Write a program that will print arbitrary input in a
 * sensible way. As a minimum, it should print non-graphic characters in octal
 * or hexadecimal according to local custom, and break long text lines.
 */

#include <ctype.h>
#include <stdio.h>

#define MAXWIDTH 80

int main(void)
{
	int c;
	int width = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar('\n');
			width = 0;
		}
		else if (isprint((unsigned char) c)) {
			putchar(c);
			width++;
		} else {
			if (width + 4 > MAXWIDTH) {
				putchar('\n');
				width = 0;
			}
			width += printf("\\x%.2x", (unsigned char) c);
		}
		if (width >= MAXWIDTH) {
			putchar('\n');
			width = 0;
		}
	}

	return 0;
}
