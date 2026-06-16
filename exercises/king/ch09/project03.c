/*
 * Project 3 from Chapter 9 of King: Modify Programming Project 9 from Chapter 8
 * so that it includes the following functions:
 *
 *    void generate_random_walk(char walk[10][10];
 *    void print_array(char walk[10][10]);
 *
 * main first calls generate_random_walk, which initializes the array to contain
 * '.' characters and then replaces some of these characters by the letters A
 * through Z, as described in the original project. main then calls print_array
 * to display the array on the screen.
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

void generate_random_walk(char walk[N_ROWS][N_COLS]);
void print_array(char walk[N_ROWS][N_COLS]);

int main(void)
{
   char arr[N_ROWS][N_COLS];

   generate_random_walk(arr);
   print_array(arr);
  
   return 0;
}

void generate_random_walk(char walk[N_ROWS][N_COLS])
{
   int i, j, dir;
   char c;

   srand((unsigned) time(NULL));

   /* initialize walkay */
   for (i = 0; i < N_ROWS; i++) 
      for (j = 0; j < N_COLS; j++)
         walk[i][j] = '.';

   i = 0, j = 0, c = 'B';
   walk[i][j] = 'A';
   while (c <= 'Z') {
      dir = rand() % 4;
      if (dir == UP && i != 0 && walk[i - 1][j] == '.') {
         i--;
         walk[i][j] = c;
         c++;
      } else if (dir == DOWN && i != N_ROWS - 1 && walk[i + 1][j] == '.') {
         i++;
         walk[i][j] = c;
         c++;
      } else if (dir == LEFT && j != 0 && walk[i][j - 1] == '.') {
         j--;
         walk[i][j] = c;
         c++;
      } else if (dir == RIGHT && j != N_COLS - 1 && walk[i][j + 1] == '.') {
         j++;
         walk[i][j] = c;
         c++;
      } else if ((i == 0 || walk[i - 1][j] != '.')
            && (i == N_ROWS - 1 || walk[i + 1][j] != '.')
            && (j == 0 || walk[i][j - 1] != '.')
            && (j == N_COLS - 1 || walk[i][j + 1] != '.'))
         break;
   }
}

void print_array(char walk[N_ROWS][N_COLS])
{
   int i, j;

   for (i = 0; i < N_ROWS; i++) {
      for (j = 0; j < N_COLS; j++) {
         printf("%c ", walk[i][j]);
      }
      printf("\n");
   }
}
