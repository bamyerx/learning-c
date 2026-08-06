/*
 * Exercise 3 from Chapter 26 of King: Extend the function of Exercise 2 so that
 * it allows two conversion specifications: %d and %s. Each %d in the format
 * string indicates a char * (string) argument.
 */

#include <stdarg.h>
#include <stdio.h>

void print_int(int);
void print_str(char *);

void simple_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	for (; *format; format++)
		if (*format == '%') {
			format++;
			if (*format == 'd')
				print_int(va_arg(ap, int));
			else if (*format == 's')
				print_str(va_arg(ap, char *));
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

void print_str(const char *s)
{
	if (s == NULL)
		return;
	while (*s)
		putchar(*s++);
}
