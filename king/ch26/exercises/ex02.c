/*
 * Exercise 2 from Chapter 26 of King: Write a simplified version of printf in
 * which the only conversion specification is %d, and all arguments after the
 * first are assumed to have int type. If the function encounters a % character
 * that's not immediately followed by a d character, it should ignore both
 * characters. The function should use calls of putchar to produce all output.
 * You may assume that the format string doesn't contain escape sequences.
 */

#include <stdarg.h>
#include <stdio.h>

void print_int(int);

void simple_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	for (; *format; format++)
		if (*format == '%') {
			if (*++format == 'd')
				print_int(va_arg(ap, int));
		} else
			putchar(*format);
	va_end(ap);
}

void print_int(int n)
{
	unsigned int u, power;

	if (n < 0)
		putchar('-');

	/* convert to unsigned magnitude to avoid overflow for INT_MIN */
	u = (n < 0) ? -(unsigned int) n : (unsigned int) n;

	for (power = 1; u / power >= 10; power *= 10)
		;
	do {
		putchar(u / power + '0');
		u %= power;
		power /= 10;
	} while (power != 0);
}
