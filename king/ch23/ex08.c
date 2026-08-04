/*
 * Exercise 8 from Chapter 23 of King: Use strchr to write the following
 * function:
 *
 *     int numchar(const char *s, char ch);
 *
 * numchar returns the number of times the character ch occurs in the string s.
 */

#include <string.h>

int numchar(const char *s, char ch)
{
	int count = 0;

	while ((s = strchr(s, ch)) != NULL) {
		count++;
		s++;
	}
	return count;
}
