/*
 * Exercise 4 from Chapter 23 of King: Using isalpha and isalnum, write a
 * function that checks whether a string has the syntax of a C identifier (it
 * consists of letters, digits, and underscores, with a letter or underscore
 * at the beginning).
 */

#include <ctype.h>

int is_ident(const char *s)
{
	if (!isalpha((unsigned char) *s) && *s != '_')
		return 0;
	for (s++; *s; s++)
		if (!isalnum((unsigned char) *s) && *s != '_')
			return 0;
	return 1;
}
