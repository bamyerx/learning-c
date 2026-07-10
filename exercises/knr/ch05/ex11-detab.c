/*
 * Exercise 5-11 from K&R: Modify the program entab and detab to accept a list
 * of tab stops as arguments. Use the default tab settings if there are no
 * arguments.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB 8
#define MAXTABS 100

int main(int argc, char *argv[])
{
	int c, col, ntabs, tabstop;
	int tabstops[MAXTABS];

	ntabs = 0;
	while (--argc) {
		char *arg = *++argv;
		int saw_digit = 0;
		while (isdigit(*arg)) {
			saw_digit = 1;
			arg++;
		}
		if (!saw_digit || *arg != '\0') {
			printf("detab: invalid tabstop argument %s\n", *argv);
			return 1;
		}
		tabstop = atoi(*argv);
		if (ntabs > 0 && tabstops[ntabs-1] >= tabstop) {
			printf("detab: tabstops must be strictly increasing\n");
			return 1;
		}
		if (ntabs == MAXTABS) {
			printf("detab: too many tabstops\n");
			return 1;
		}
		tabstops[ntabs++] = tabstop;
	}

	col = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			putchar('\n');
			col = 0;
		} else if (c == '\t') {
			int i;
			for (i = 0; i < ntabs && col >= tabstops[i]; i++)
				;
			if (i < ntabs)
				tabstop = tabstops[i];
			else
				tabstop = DEFAULT_TAB * (col / DEFAULT_TAB + 1);
			while (col < tabstop) {
				putchar(' ');
				col++;
			}
		} else {
			putchar(c);
			col++;
		}
	}

	return 0;
}
