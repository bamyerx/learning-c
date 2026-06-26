/*
 * Exercise 2-1 from K&R: Write a program to determin ethe ranges of char,
 * short, int, and long variables, both signed and unsigned, by printing
 * appropriate values from standard headers and by direct computation. Harder if
 * you compute them: determine the ranges of the various floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
   printf("Type\t\t       Minimum Value\t       Maximum Value\n");
   printf("signed char\t%20d\t%20d\n", SCHAR_MIN, SCHAR_MAX);
   printf("unsigned char\t%20d\t%20d\n", 0, UCHAR_MAX);
   printf("signed int\t%20d\t%20d\n", INT_MIN, INT_MAX);
   printf("unsigned int\t%20d\t%20u\n", 0, UINT_MAX);
   printf("signed long\t%20ld\t%20ld\n", LONG_MIN, LONG_MAX);
   printf("unsigned long\t%20d\t%20lu\n", 0, ULONG_MAX);
}
