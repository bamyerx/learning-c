/*
 * Project 9 from Chapter 8 of King: Write a program that generates a "random
 * walk" across a 10x10 array. The array will contain characters (all '.'
 * initially). The program must randomly "walk" from element to element, always
 * going up, down, left, or right by one element. The elements visited by the
 * program will be labeled with the letters A through Z, in the order visited.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_ROWS 10
#define N_COLS 10
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

int main(void)
{
   char arr[N_ROWS][N_COLS];
   int i, j, dir;
   char c;

   srand((unsigned) time(NULL));

   /* initialize array */
   for (i = 0; i < N_ROWS; i++) {
      for (j = 0; j < N_COLS; j++) {
         arr[i][j] = '.';
      }
   }

   i = 0;
   j = 0;
   c = 'A';
   arr[i][j] = c;
   c++;
   while (c <= 'Z') {
      dir = rand() % 4;
      if (dir == UP && i != 0 && arr[i - 1][j] == '.') {
         i--;
         arr[i][j] = c;
         c++;
      } else if (dir == DOWN && i != N_ROWS - 1 && arr[i + 1][j] == '.') {
         i++;
         arr[i][j] = c;
         c++;
      } else if (dir == LEFT && j != 0 && arr[i][j - 1] == '.') {
         j--;
         arr[i][j] = c;
         c++;
      } else if (dir == RIGHT && j != N_COLS - 1 && arr[i][j + 1] == '.') {
         j++;
         arr[i][j] = c;
         c++;
      } else if ((i == 0 || arr[i - 1][j] != '.')
            && (i == N_ROWS - 1 || arr[i + 1][j] != '.')
            && (j == 0 || arr[i][j - 1] != '.')
            && (j == N_COLS - 1 || arr[i][j + 1] != '.'))
            break;
   }

   for (i = 0; i < N_ROWS; i++) {
      for (j = 0; j < N_COLS; j++) {
         printf("%c ", arr[i][j]);
      }
      printf("\n");
   }

   return 0;
}
