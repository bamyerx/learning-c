/*
 * Exercise 4 from Chapter 26 of King: Write a function named display that takes
 * any number of arguments. The first argument must be an integer. The remaining
 * arguments will be strings. The first argument specifies how many strings the
 * call contains. The function will print the strings on a single line, with
 * adjacent string separated by one space. For example, the call
 *
 *     display(4, "Special", "Agent", "Dale", "Cooper");
 *
 * will produce the following output:
 *
 *     Special Agent Dale Cooper
 */

#include <stdarg.h>
#include <stdio.h>

void display(int n, ...)
{
	va_list ap;

	va_start(ap, n);
	while (n-- > 0)
		printf(n ? "%s " : "%s\n", va_arg(ap, char *));
	va_end(ap);
}
