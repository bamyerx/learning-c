/*
 * Project 6 from Chapter 7 of King: Write a program that prints the values of
 * sizeof(int), sizeof(short), sizeof(long), sizeof(float), sizeof(double), and
 * sizeof(long double).
 */

#include <stdio.h>

int main(void)
{
   typedef char Int8;
   typedef short Int16;
   typedef int Int32;

   unsigned long long size = 1;

   printf("Size of char: %llu bits\n", (size = sizeof(char)) * 8);
   printf("Size of short: %llu bits\n", (size = sizeof(short)) * 8);
   printf("Size of int: %llu bits\n", (size = sizeof(int)) * 8);
   printf("Size of long: %llu bits\n", (size = sizeof(long)) * 8);
   printf("Size of long long: %llu bits\n", (size = sizeof(long long)) * 8);
   printf("Size of float: %llu bits\n", (size = sizeof(float)) * 8);
   printf("Size of double: %llu bits\n", (size = sizeof(double)) * 8);
   printf("Size of long double: %llu bits\n", (size = sizeof(long double)) * 8);
   printf("-------------------------------------------\n");
   printf("Size of Int8: %llu bits\n", (size = sizeof(Int8)) * 8);
   printf("Size of Int16: %llu bits\n", (size = sizeof(Int16)) * 8);
   printf("Size of Int32: %llu bits\n", (size = sizeof(Int32)) * 8);
   printf("Size of size (expected: 64 bits): %llu bits\n", (size = sizeof(size)) * 8);
   return 0;
}
