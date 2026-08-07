/*
 * Exercise 7-4 from K&R: Write a private version of scanf analogous to
 * minprintf from the previous section.
 */

#include <stdarg.h>
#include <stdio.h>

#define BUFSIZE 100

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
	va_list ap;  /* points to each unnamed arg in turn */
	char *p, *sp, fmtbuf[BUFSIZE];
	int i, *ip;
	double *dp;

	va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
	i = 0;
	for (p = fmt; *p && i + 3 < BUFSIZE; p++) {
		if (*p != '%') {
			fmtbuf[i++] = *p;
			continue;
		}
		fmtbuf[i++] = '%';
		fmtbuf[i++] = *++p;
		fmtbuf[i] = '\0';
		switch(*p) {
		case 'd':
			ip = va_arg(ap, int *);
			if (scanf(fmtbuf, ip) != 1)
				goto scan_failure;
			i = 0;
			break;
		case 'f':
			dp = va_arg(ap, double *);
			if (scanf(fmtbuf, dp) != 1)
				goto scan_failure;
			i = 0;
			break;
		case 's':
			sp = va_arg(ap, char *);
			if (scanf(fmtbuf, sp) != 1)
				goto scan_failure;
			i = 0;
			break;
		}
	}
	scan_failure:
	va_end(ap);  /* clean up when done */
}
