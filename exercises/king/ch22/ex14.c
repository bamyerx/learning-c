/*
 * Exercise 14 from Chapter 22 of King:
 * (a) Write your own version of the fgets function. Make it behave as much like
 *     the real fgets function as possible; in particular, make sure that it has
 *     the proper return value. To avoid conflicts with the standard library,
 *     don't name your function fgets.
 * (b) Write your own version of fputs, following the same rules as in part (a).
 */

#include <stdio.h>

char *fgetline(char *s, int n, FILE *stream)
{
	int c, i;

	i = 0;
	while (i < n - 1 && (c = getc(stream)) != '\n') {
		if (c == EOF && (i == 0 || ferror(stream)))
			return NULL;
		s[i++] = c;
	}
	if (i < n - 1)
		s[i++] = '\n';
	s[i] = '\0';
	return s;
}

int fwriteline(const char *s, FILE *stream)
{
	while (*s)
		if (putc(*s++, stream) == EOF)
			return EOF;

	return 0;
}
