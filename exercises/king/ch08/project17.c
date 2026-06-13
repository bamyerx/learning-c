/*
 * Project 17 from Chapter 8 of King: Write a program that prints an n x n magic
 * square (a square arrangement of the numbers 1, 2, ..., n^2 in which the sums
 * of the rows, columns, and diagonals are all the same). The user will specify
 * the value of n:
 *
 *    This program creates a magic square of a specified size.
 *    The size mucst be an odd number between 1 and 99.
 *    Enter size of magic square: 5
 *       17   24    1    8   15
 *       23    5    7   14   16
 *        4    6   13   20   22
 *       10   12   19   21    3
 *       11   18   25    2    9
 */

#include <stdio.h>

int main(void)
{
   int i, j, n, m;

   printf("This program creates a magic square of a specified size.\n");
   printf("The size must be an odd number between 1 and 99.\n");
   printf("Enter size of magic square: ");
   scanf("%d", &n);
   
   int arr[n][n];
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
         arr[i][j] = 0;
   }

   i = 0;
   j = n / 2 + 1;
   m = 1;
   arr[i][j] = m;
   while (m <= n * n) {
      if (arr[(i - 1 + n) % n][(j + 1) % n] == 0) {
         i = (i - 1 + n) % n;
         j = (j + 1) % n;
      } else
         i--;
      arr[i][j] = m;
      m++;
   }

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
         printf("%5d", arr[i][j]);
      printf("\n");
   }

   return 0;
}
