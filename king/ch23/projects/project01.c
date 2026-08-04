/*
 * Project 1 from Chapter 23 of King: Write a program that finds the roots of
 * the equation ax^2 + bx + c = 0 using the quadratic formula. Have the program
 * prompt for the values of a, b, and c, then print both values of x.
 * (If b^2 - 4ac is negative, the program should instead print a message to the
 * effect that the roots are complex.)
 */

#include <math.h>
#include <stdio.h>

int main(void)
{
	double a, b, c, d, x1, x2;

	printf("Enter value for a: ");
	scanf("%lf", &a);
	if (a == 0) {
		printf("a must be nonzero\n");
		return 1;
	}
	printf("Enter value for b: ");
	scanf("%lf", &b);
	printf("Enter value for c ");
	scanf("%lf", &c);

	d = (b * b) - (4.0 * a * c);
	if (d >= 0) {
		x1 = (-1.0 * b + sqrt(d)) / (2.0 * a);
		x2 = (-1.0 * b - sqrt(d)) / (2.0 * a);
		printf("Roots: x1 = %g, x2 = %g\n", x1, x2);
	} else
		printf("Roots are complex\n");

	return 0;
}
