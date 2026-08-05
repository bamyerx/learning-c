/*
 * Project 3 of Chapter 7 of King: Modify the sum2.c program of section 7.1 to
 * sum a series of double values.
 */

#include <stdio.h>

int main(void)
{
   double n, sum = 0;

   printf("This program sums a series of floating-precision values.\n");
   printf("Enter numbers (0 to terminate): ");

   scanf("%lf", &n);
   while (n != 0) {
      sum += n;
      scanf("%lf", &n);
   }
   printf("The sum is: %lf\n", sum);

   return 0;
}
