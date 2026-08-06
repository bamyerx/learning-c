/*
 * Exercise 1 from Chapter 26 of King: Rewrite the max_int function so that,
 * instead of passing the number of integers as the first argument, we must
 * supply 0 as the last argument.
 */

#include <stdarg.h>

int max_int(int n, ...)
{
	va_list ap;
	int current, largest;

	va_start(ap, n);
	largest = n;

	while ((current = va_arg(ap, int)) != 0)
		if (current > largest)
			largest = current;

	va_end(ap);
	return largest;
}
