/*
 * Project 7 from Chapter 10 of King: Write a program that prompts the user for
 * a number and then displays the number, using characters to simulate the
 * effect of a seven-segment display:
 *
 *    Enter a number: 491-9014
 *         _       _   _          
 *    |_| |_|   | |_| | |   | |_|
 *      |  _|   |  _| |_|   |   |
 *
 * Chracters other than digits should be ignored. Write the program so that the
 * maximum number of digits is controlled by a macro named MAX_DIGITS, which has
 * the value 10. If the number contains more than this number of digits, the
 * extra digits are ignored.
 */

#include <stdio.h>

#define MAX_DIGITS 10

const int segments[10][7] = { {1, 1, 1, 1, 1, 1, 0},
                              {0, 1, 1, 0, 0, 0, 0},
                              {1, 1, 0, 1, 1, 0, 1},
                              {1, 1, 1, 1, 0, 0, 1},
                              {0, 1, 1, 0, 0, 1, 1},
                              {1, 0, 1, 1, 0, 1, 1},
                              {1, 0, 1, 1, 1, 1, 1},
                              {1, 1, 1, 0, 0, 0, 0},
                              {1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 0, 1, 1} };
char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
   int c, digits_read = 0;

   clear_digits_array();
   printf("Enter a number: ");
   while ((c = getchar()) != '\n' && digits_read <= MAX_DIGITS) {
      if (c >= '0' && c <= '9') {
         process_digit(c - '0', digits_read);
         digits_read++;
      }
   }
   print_digits_array();

   return 0;
}

void clear_digits_array(void)
{
   int i, j;

   for (i = 0; i < 3; i++)
      for (j = 0; j < MAX_DIGITS * 4; j++)
         digits[i][j] = ' ';
}

void process_digit(int digit, int position)
{
   if (segments[digit][0]) 
      digits[0][position * 4 + 1] = '_';
   if (segments[digit][1])
      digits[1][position * 4 + 2] = '|';
   if (segments[digit][2]) 
      digits[2][position * 4 + 2] = '|';
   if (segments[digit][3]) 
      digits[2][position * 4 + 1] = '_';
   if (segments[digit][4]) 
      digits[2][position * 4] = '|';
   if (segments[digit][5]) 
      digits[1][position * 4] = '|';
   if (segments[digit][6]) 
      digits[1][position * 4 + 1] = '_';
}

void print_digits_array(void)
{
   int i, j;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < MAX_DIGITS * 4; j++)
         printf("%c", digits[i][j]);
      printf("\n");
   }
}
