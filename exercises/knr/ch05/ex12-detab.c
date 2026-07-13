/*
 * Exercise 5-12 from K&R: Extend entab and detab to accept the shorthand
 *
 *		entab -m +n
 *
 * to mean tab stops every n columns, starting at column m. Choose conveniunt
 * (for the user) default behavior.
 *
 * Note: the behavior when detab is called without m or n is the same as in
 * exercise 5-11. If m is specified without specifying n, the program will
 * use DEFAULT_TAB as the number of columns between tab stops. If n is specified
 * without specifying m, the starting column will be the last tab stop provided
 * as an argument or 0 if none were provided.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB 8
#define MAXTABS 100

int parse_positive_int(char *);

int main(int argc, char *argv[])
{
	int c, col, ntabs, tabstop, m = 0, n = 0;
	int tabstops[MAXTABS];

	ntabs = 0;
	while (--argc > 0) {
		char *arg = *++argv;
		if (*arg == '-') {
			m = parse_positive_int(arg+1);
			if (m < 1) { 
				printf("detab: illegal option %s\n", *argv);
				return 1;
			}
		} else if (*arg == '+') {
			n = parse_positive_int(arg+1);
			if (n < 1) {
				printf("detab: illegal option %s\n", *argv);
				return 1;
			}
		} else {
			tabstop = parse_positive_int(arg);
			if (tabstop < 1) {
				printf("detab: illegal option %s\n", *argv);
				return 1;
			}
			if (ntabs > 0 && tabstops[ntabs-1] >= tabstop) {
				printf("detab: tab stops must be strictly increasing\n");
				return 1;
			}
			if (ntabs == MAXTABS) {
				printf("detab: too many tab stops\n");
				return 1;
			}
			tabstops[ntabs++] = tabstop;
		}
	}
	if (m > 0 && ntabs > 0 && m < tabstops[ntabs-1]) {
		printf("detab: tab start column must be greater ");
		printf("than or equal to last specified tab stop\n");
		return 1;
	}
	if (m > 0 && n == 0) {
		n = DEFAULT_TAB;
	}
	if (n > 0 && m == 0) {
		m = (ntabs > 0) ? tabstops[ntabs-1] : 0;
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
			else if (m > 0) {
				for (tabstop = m; tabstop <= col; tabstop += n)
					;
			}
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

/* parse_positive_int: returns atoi(s) if s is a positive integer, 0 otherwise */
int parse_positive_int(char *s)
{
	char *p;
	if (*s == '\0')
		return 0;
	for (p = s; *p; p++)
		if (!isdigit(*p))
			return 0;
	return atoi(s);		/* returns 0 if atoi(s) = 0 */
}
