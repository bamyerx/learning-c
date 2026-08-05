/*
 * Exercise 7 from Chapter 20 of King: Write the following functions:
 *
 *     unsigned int rotate_left(unsigned int i, int n);
 *     unsigned int rotate_right(unsigned int i, int n);
 *
 * rotate_left should return the result of shifting the bits in i to the left by
 * n places, with the bits that were "shifted off" moved to the right end of i.
 * rotate_right is similar, but it should "rotate" bits off to the right instead
 * of the left.
 */

#include <limits.h>

const int width = sizeof(unsigned int) * CHAR_BIT;

unsigned int rotate_left(unsigned int i, int n)
{
	n %= width;
	return i << n | i >> (width - n);
}

unsigned int rotate_right(unsigned int i, int n)
{
	n %= width;
	return i >> n | i << (width - n);
}
