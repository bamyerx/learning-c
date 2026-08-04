/*
 * Exercise 1 from Chapter 23 of King: Extend the round_nearest function so that
 * it rounds a floating-point number x to n digits after the decimal point. For
 * example, the call round_nearest(3.14159, 3) would return 3.142.
 */

#include <math.h>

double round_nearest(double x, int n)
{
	double p = pow(10.0, n);

	return (x < 0.0) ? ceil(x * p - 0.5) / p : floor(x * p + 0.5) / p;
}
