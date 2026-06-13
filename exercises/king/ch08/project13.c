/*
 * Project 13 from Chapter 8 of King: Modify Programming Project 11 from Chapter
 * 7 so that the program labels its output:
 *    
 *    Enter a first and last name: Lloyd Fosdick
 *    You entered the name: Fosdick, :.
 *
 * The program will need to store the last name (but not the first name) in an
 * array of characters until it can be printed. You may assume that the last 
 * name is no more than 20 characters long.
 */

#include <stdio.h>

#define MAX_LASTNAME 20

int main(void)
{
   char lastname[MAX_LASTNAME];
   int first_initial, c, i;

   printf("Enter a first and last name: ");
   while ((c = getchar()) == ' ')
      ;
   first_initial = c;
   while ((c = getchar()) != ' ' && c != '\n')
      ;
   while ((c = getchar()) == ' ')
      ;
   i = 0;
   do {
      lastname[i] = c;
      i++;
   } while ((c = getchar()) != ' ' && c != '\n');
   lastname[i] = '\n';

   printf("You entered the name: ");
   for (i = 0; lastname[i] != '\n'; i++)
      printf("%c", lastname[i]);
   printf(", %c.\n", first_initial);

   return 0;
}
