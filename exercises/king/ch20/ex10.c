/*
 * Exercise 10 from Chapter 20 of King: Write the following function:
 *
 *     unsigned int reverse_bits(unsigned int n);
 *
 * reverse_bits should return an unsigned integer whose bits are the same as
 * those in n but in reverse order.
 */

#include <limits.h>


unsigned int reverse_bits(unsigned int n)
{
	unsigned int r;
	int i, width;

	width = sizeof(unsigned int) * CHAR_BIT;
	for (i = 0, r = 0; i < width; i++) {
		r <<= 1;
		r |= n & 1;
		n >>= 1;
	}
	return r;
}
