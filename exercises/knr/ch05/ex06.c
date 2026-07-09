/*
 * Exercise 5-6 from K&R: Rewrite appropriate programs from earlier chapters and
 * exercises with pointers instead of array indexing. Good possibilities include
 * getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3,
 * and 4), reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
	int c;
	char *p = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	return p - s;
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
	int c;
	char *p = s;

	for (; *p; p++)		/* point p to end of s */
		;
	for (p--; s < p; s++, p--) {
		c = *s;
		*s = *p;
		p* = c;
	}
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
	char *p, *q, *r;

	for (p = s; *p; p++) {
		for (q = p, r = t; *r && *q++ == *r++)
			;
		if (r > t && !*r)
			return p - s;
	}
	return -1;
}
