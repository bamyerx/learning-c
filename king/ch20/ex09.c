/*
 * Exercise 8 from Chapter 20 of King: (a) Write the following function:
 *
 *     int count_ones(unsigned char ch);
 *
 * count_ones should return the number of 1 bits in ch.
 * (b) Write the function in part (a) without using a loop.
 */

int count_ones(unsigned char ch)
{
	return (ch & 1) +
		   (ch >> 1 & 1) +
		   (ch >> 2 & 1) +
		   (ch >> 3 & 1) +
		   (ch >> 4 & 1) +
		   (ch >> 5 & 1) +
		   (ch >> 6 & 1) +
		   (ch >> 7 & 1);
}
