/*
 * Exercise 2 from Chapter 17 of King: Write a function duplicate that uses
 * dynamic storage allocation to create a copy of a string. For example, the
 * call:
 *
 *     p = duplicate(str);
 *
 * would allocate space for a string of the same length as str, copy the
 * contents of str into the new string, and return a pointer to it. Have
 * duplicate return a null pointer if the memory allocation fails.
 */

#include <stdlib.h>
#include <string.h>

char *duplicate(char *s)
{
	char *copy;

	copy = malloc(strlen(s) + 1);
	if (copy == NULL)
		return NULL;
	return strcpy(copy, s);
}
