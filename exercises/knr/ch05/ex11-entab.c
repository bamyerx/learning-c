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
	int c, col, pending_blanks, ntabs, tabstop;
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
			printf("entab: invalid tabstop argument %s\n", *argv);
			return 1;
		}
		tabstop = atoi(*argv);
		if (ntabs > 0 && tabstops[ntabs-1] >= tabstop) {
			printf("entab: tabstops must be strictly increasing\n");
			return 1;
		}
		if (ntabs == MAXTABS) {
			printf("entab: too many tabstops\n");
			return 1;
		}
		tabstops[ntabs++] = tabstop;
	}

	col = pending_blanks = 0;
	while ((c = getchar()) != EOF) {
		/* end of line; reset column counter and print pending blanks */
		if (c == '\n') {
			while (pending_blanks-- > 0)
				putchar(' ');
			putchar('\n');
			col = 0;
		} else if (c == ' ') {
			/* calculate the next tab stop */
			int i;
			for (i = 0; i < ntabs && col >= tabstops[i]; i++)
				;
			if (i < ntabs)
				tabstop = tabstops[i];
			else
				tabstop = DEFAULT_TAB * (col / DEFAULT_TAB +1);
			if (col + pending_blanks + 1 == tabstop) {
				/* prefer a blank to a tab if only a blank is sufficient */
				if (pending_blanks == 0)
					putchar(' ');
				else {
					putchar('\t');
					col = tabstop;
				} 
			} else
				pending_blanks++;
		} else {
			/* when a non-blank character is seen, print pending blanks */
			while (pending_blanks-- > 0) {
				putchar(' ');
				col++;
			}
			putchar(c);
			col++;
		}
	}
	/* print any pending blanks at the end of the file */
	if (pending_blanks != 0)
		while (pending_blanks-- > 0)
			putchar(' ');

	return 0;
}
