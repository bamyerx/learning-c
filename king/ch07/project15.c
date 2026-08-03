/*
 * Project 15 from Chapter 7 of King: Write a program that computes the
 * factorial of a positive integer:
 *
 *    Enter a positive integer: 6
 *    Factorial of 6: 720
 *
 * Use a short variable to store the value of the factorial. What is the largest 
 * value of n for which the program correctly prings the factorial of n? Repeat
 * using an int/long/long long/float/double/long double variable instead.
 */

#include <stdio.h>

int main(void)
{
   int n;
   long double fact = 1;

   printf("Enter a positive integer: ");
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
      fact *= i;
      printf("i = %d, fact = %llg\n", i, fact);
   }
   printf("Factorial: %llg\n", fact);

   return 0;
}

/*
 * short:       n = 7    n! =                     5 040
 * int:         n = 12   n! =               479 001 600
 * long:        n = 20   n! = 2 432 902 008 176 640 000
 * long long:   n = 20   n! = 2 432 902 008 176 640 000
 * float:       n = 34   n! = 2.95233e38
 * double:      n = 170  n! = 7.25742e306
 * long double: n = 1754 n! = 1.97926e4930
 */
