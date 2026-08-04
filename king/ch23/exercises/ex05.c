/*
 * Exercise 5 from Chapter 23 of King: Using isxdigit, write a function that
 * checks whether a string represents a valid hexadecimal number (it consists
 * solely of hexadecimal digits). If so, the function returns the value of the
 * number as a long int. Otherwise, the function returns -1.
 */

#include <ctype.h>

long is_hex(const char *s)
{
	long h = 0;
	unsigned char c;

	if (!*s)  /* string is empty */
		return -1;

	for (; *s; s++) {
		c = *s;
		if (!isxdigit(c))
			return -1;
		h *= 16;
		if (isdigit(c))
			h += c - '0';
		else
			h += toupper(c) - 'A' + 10;
	}
	return h;
}
