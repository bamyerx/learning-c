/*
 * Exercise 7-3 from K&R: Revise minprintf to handle more of the other
 * facilities of printf.
 */

#include <stdarg.h>
#include <stdio.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap;  /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	unsigned uval;
	double dval;

	va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'i':
			ival = va_arg(ap, int);
			printf("%i", ival);
			break;
		case 'o':
			uval = va_arg(ap, unsigned);
			printf("%o", uval);
			break;
		case 'x':
			uval = va_arg(ap, unsigned);
			printf("%x", uval);
			break;
		case 'u':
			uval = va_arg(ap, unsigned);
			printf("%u", uval);
			break;
		case 'c':
			ival = va_arg(ap, int);
			printf("%c", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 'e':
			dval = va_arg(ap, double);
			printf("%e", dval);
			break;
		case 'g':
			dval = va_arg(ap, double);
			printf("%g", dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			if (sval == NULL)
				sval = "(null)";
			while (*sval)
				putchar(*sval++);
			break;
		case 'p':
			printf("%p", (void *) p);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);  /* clean up when done */
}
