/*
 * Project 7 from Chapter 8 of King: Write a program that reads a 5x5 array of
 * integers and then prints the row sums and the column sums:
 *
 *    Enter row 1: 8 3 9 0 10
 *    Enter row 2: 3 5 17 1 1
 *    Enter row 3: 2 8 6 23 1
 *    Enter row 4: 15 7 3 2 9
 *    Enter row 5: 6 14 2 6 0
 *
 *    Row totals: 30 27 40 36 28
 *    Columns totals: 34 37 37 32 21
 */

#include <stdio.h>

#define NROWS 5
#define NCOLS 5

int main(void)
{
   int m[NROWS][NCOLS] = {0};
   int i, j, sum;

   for (i = 0; i < NROWS; i++) {
      printf("Enter row %d: ", i + 1);
      for (j = 0; j < NCOLS; j++) {
         scanf("%d", &m[i][j]);
      }
   }
   printf("Row totals: ");
   for (i = 0; i < NROWS; i++) {
      sum = 0;
      for (j = 0; j < NCOLS; j++) {
         sum += m[i][j];
      }
      printf(" %d", sum);
   }
   printf("\nColumn totals: ");
   for (j = 0; j < NCOLS; j++) {
      sum = 0;
      for (i = 0; i < NROWS; i++) {
         sum += m[i][j];
      }
      printf(" %d", sum);
   }
   printf("\n");

   return 0;
}
