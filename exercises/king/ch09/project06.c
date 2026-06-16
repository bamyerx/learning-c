/*
 * Project 6 from Chapter 9 of King: Write a function that computes the value of
 * the following polynomial:
 *
 *    3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
 *
 * Write a program that asks the user to enter a value of x, calls the function
 * to computer the value of the polynomial, and then displays the value returned
 * by the function.
 */

#include <stdio.h>

double f(double x);

int main(void)
{
   double x;

   printf("Enter value for x: ");
   scanf("%lf", &x);
   printf("3x\u2075 + 2x\u2074 - 5x\u00b3 - x\u00b2 + 7x - 6 = %g\n", f(x));

   return 0;
}

double f(double x)
{
   return 3 * x * x * x * x * x
        + 2 * x * x * x * x
        - 5 * x * x * x
        - 1 * x * x
        + 7 * x
        - 6;
}
