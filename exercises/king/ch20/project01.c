/*
 * Programming Project 1 from Chapter 20 of King: Design a union that makes it
 * possible to view a 32-bit value as either a float or the structure described
 * in Exercise 14. Write a program that stores 1 in the structures sign field,
 * 128 in the exponent field, and 0 in the fraction field, then prints the float
 * value stored in the union. (The answer should be -2.0 if you've set up the
 * bit-fields correctly.)
 */

#include <stdio.h>

struct IEEE_float {
	unsigned int fraction: 23;
	unsigned int exponent: 8;
	unsigned int sign: 1;
};

int main(void)
{
	union {
		float f1;
		struct IEEE_float f2;
	} u;

	u.f2.sign = 1;
	u.f2.exponent = 128;
	u.f2.fraction = 0;

	printf("Float value: %f\n", u.f1);

	return 0;
}
