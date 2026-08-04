/*
 * Exercise 12 from Chapter 23 of King: Many versions of <string.h> provide
 * additional (nonstandard) functions, such as those listed below. Write each
 * function using only the features of the C standard.
 * 
 *     (a) strdup(s) -- Returns a pointer to a copy of s stored in memory
 *         obtained by calling malloc. Returns a null pointer if enough
 *         memory couldn't be allocated.
 *     (b) stricmp(s1, s2) -- Similar to strcmp, but ignores the case of 
 *         letters.
 *     (c) strlwr(s) -- Converts upper-case letters in s to lower case, leaving
 *         other characters unchanged; returns s.
 *     (d) strrev(s) -- Reverses the characters in s; returns s.
 *     (e) strset(s, ch) -- Fills s with copies of the character ch; returns s.
 */

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *p = malloc(len);

	if (p != NULL)
		memcpy(p, s, len);
	return p;
}

int my_stricmp(const char *s1, const char *s2)
{
	for (;; s1++, s2++) {
		int c1 = toupper((unsigned char) *s1);
		int c2 = toupper((unsigned char) *s2);

		if (c1 != c2)
			return c1 - c2;
		if (c1 == '\0')
			return 0;
	}
}

char *my_strlwr(char *s)
{
	char *p = s;

	for (; *p; p++)
		*p = tolower((unsigned char) *p);
	return s;
}

char *my_strrev(char *s)
{
	char *p = s; 
	char *q = s + strlen(s);
	char temp;

	while (p < --q) {
		temp = *p;
		*p++ = *q;
		*q = temp;
	}
	return s;
}

char *my_strset(char *s, char ch)
{
	char *p = s;

	while (*p)
		*p++ = ch;
	return s;
}
