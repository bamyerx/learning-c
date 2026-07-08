/*
 * Exercise 5-2 from K&R: Write getfloat, the floating-point analog of getint.
 * What type does getfloat return as its function value?
 */

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next integer from input into *pn */
int getfloat(double *dn)
{
	double power;
	int c, sign = 0, saw_digit = 0;

	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);	/* it is not a number */
		return 0;
	}
	if (c == '+' || c == '-') {
		sign = c;
		if (!isdigit(c = getch()) && c != '.') {
			ungetch(c);
			ungetch(sign);
			return 0;
		}
	}
	for (*dn = 0.0; isdigit(c); c = getch()) {
		saw_digit = 1;
		*dn = 10.0 * *dn + (c - '0');
	}
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch()) {
		saw_digit = 1;
		*dn = 10.0 * *dn + (c - '0');
		power *= 10;
	}
	if (!saw_digit) {
		ungetch(c);
		ungetch('.');
		if (sign)
			ungetch(sign);
		return 0;
	}
	*dn = ((sign == '-') ? -1 : 1) * (*dn / power);
	if (c != EOF)
		ungetch(c);
	return c;
}
