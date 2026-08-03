/*
 * Project 14 from Chapter 7 of King: Write a program that uses Newton's method
 * to compute the square root of a positive floating-point number:
 * 
 *    Enter a positive number: 3
 *    Square root: 1.73205
 *
 * For greater accuracy, your program should use variables of type double rather
 * than float. Have the program terminate when the absolute value of the 
 * difference between the old value of y and the new value of y is less than the
 * product of .00001 and y.
 */

#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001

int main(void)
{
   double x, y0, y1;

   y0 = 1;
   printf("Enter a positive number: ");
   scanf(" %lf", &x);
   y1 = (y0 + x / y0) / 2.0;
   while (fabs(y1 - y0) >= EPSILON * y1) {
      y0 = y1;
      y1 = (y0 + x / y0) / 2.0;
   }
   printf("Square root: %.5f\n", y1);

   return 0;
}
