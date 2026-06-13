/*
 * Project 10 from Chapter 8 of King: Modify Programming Project 4 from Chapter
 * 7 so that the program labels its output:
 *
 *    Enter phone number: 1-800-COL-LECT
 *    In numeric form: 1-800-265-5328
 *
 * The program will need to store the phone number (either in its original form
 * or in its numeric form) in an array of characters until it can be printed.
 * You may assume that the phone number is no more than 15 characters long.
 */

#include <stdio.h>

#define MAX_LEN 15

int main(void)
{
   char output[MAX_LEN + 1];
   int c, i;

   printf("Enter phone number: ");
   i = 0;
   while ((c = getchar()) != '\n') {
      switch (c) {
         case 'A': case 'B': case 'C': output[i] = '2'; break;
         case 'D': case 'E': case 'F': output[i] = '3'; break;
         case 'G': case 'H': case 'I': output[i] = '4'; break;
         case 'J': case 'K': case 'L': output[i] = '5'; break;
         case 'M': case 'N': case 'O': output[i] = '6'; break;
         case 'P': case 'Q': case 'R': case 'S': output[i] = '7'; break;
         case 'T': case 'U': case 'V': output[i] = '8'; break;
         case 'W': case 'X': case 'Y': case 'Z': output[i] = '9'; break;
         default:  output[i] = c;
      }
   i++;
   } 
   output[i] = c;

   printf("In numeric form: ");
   for (i = 0; output[i] != '\n'; i++)
      printf("%c", output[i]);
   printf("\n");
   
   return 0;
}
