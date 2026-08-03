/*
 * Project 5 from Chapter 9 of King: Modify Programming Project 17 from Chapter
 * 8 so that it includes the following functions:
 *
 *    void create_magic_square(int n, int magic_square[n][n]);
 *    void print_magic_square(int n, int magic_square[n][n]);
 *
 * After obtaining the number n from the user, main will call
 * create_magic_square, passing it an nxn array that is declared inside main.
 * create_magic_square will fill the array with the numbers 1, 2, ..., n^2 as
 * described in the original project. main will then call print_magic_square,
 * which will display the array in the format described in the original project.
 */

#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void)
{
   int n;

   printf("This program creates a magic square of a specified size.\n");
   printf("The size must be an odd number between 1 and 99.\n");
   printf("Enter size of magic square: ");
   scanf("%d", &n);

   int arr[n][n];
   create_magic_square(n, arr);
   print_magic_square(n, arr);

   return 0;
}

void create_magic_square(int n, int magic_square[n][n])
{
   int i, j, m;

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
         magic_square[i][j] = 0;
   }

   i = 0;
   j = n / 2 + 1;
   m = 1;
   magic_square[i][j] = m;
   while (m <= n * n) {
      if (magic_square[(i - 1 + n) % n][(j + 1) % n] == 0) {
         i = (i - 1 + n) % n;
         j = (j + 1) % n;
      } else
         i--;
      magic_square[i][j] = m;
      m++;
   }
}

void print_magic_square(int n, int magic_square[n][n])
{
   int i, j;

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
         printf("%5d", magic_square[i][j]);
      printf("\n");
   }
}
