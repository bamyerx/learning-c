/*
 * Project 7 from Chapter 9 of King: Write a recursive function that computes
 * x^n. To test your function, write a program that asks the user to enter
 * values for x and n, calls power to computer x^n, and then displays the value
 * returned by the function.
 */

#include <stdio.h>

int power(int x, int n);

int main(void)
{
   int n, x;

   printf("Enter values for x and n: ");
   scanf("%d %d", &x, &n);
   printf("%d^%d = %d\n", x, n, power(x, n));

   return 0;
}

int power(int x, int n)
{
   if (n == 0)
      return 1;
   else if (n % 2 != 0)
      return x * power(x, n - 1);
   else {
      int y;
      y = power(x, n / 2);
      return y * y;
   }
}
