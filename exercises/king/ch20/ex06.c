/*
 * Exercise 6 from Chapter 20 of King: (a) Use the bitwise operators to write
 * the following function:
 *
 *     unsigned short swap_bytes(unsigned short i);
 *
 * swap_bytes should return the number that results from swapping the two bytes
 * in i. For example, if i has the value 0x1234, then swap_bytes should return
 * 0x3412. Test your function by writing a program that reads a number in hexa-
 * decimal, then writes the number with its bytes swapped:
 *
 *     Enter a hexadecimal number (up to four digits): 1234
 *     Number with bytes swapped: 3412
 *
 * (b) Condense the swap_bytes function so that its body is a single statement.
 */

#include <stdio.h>

unsigned short swap_bytes(unsigned short i);

int main(void)
{
	unsigned short i;

	printf("Enter a hexadecimal number (up to four digits): ");
	scanf("%hx", &i);
	printf("Number with bytes swapped: %hx\n", swap_bytes(i));
}

unsigned short swap_bytes(unsigned short i)
{
	return i >> 8 | i << 8;
}
