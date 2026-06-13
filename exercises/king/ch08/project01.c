/*
 * Project 1 from Chapter 8 of King: Modify the repdigit.c program of section
 * 8.1 so that it shows which digits (if any) were repeated:
 *
 *    Enter a number: 939577
 *    Repeated digit(s): 7 9
 */

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
   bool digit_seen[10] = {false};
   int digit;
   long n;

   printf("Enter a number: ");
   scanf("%ld", &n);
   printf("Repeated digit(s):");
   while (n > 0) {
      digit = n % 10;
      if (digit_seen[digit])
         printf(" %d", digit);
      digit_seen[digit] = true;
      n /= 10;
   }
   printf("\n");

   return 0;
}
