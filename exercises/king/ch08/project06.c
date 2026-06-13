/*
 * Project 6 from Chapter 8 of King: The prototypical Internet newbie is a
 * fellow named B1FF, who has a unique way of writing messages. Here's a typical
 * B1FF commique:
 * 
 * H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
 *
 * Write a "B1FF filter" that reads a message entered by the user and translates
 * it into B1FF-speak:
 *
 *    Enter message: Hey dude, C is rilly cool
 *    In B1FF-speak: H3Y DUD3, C 15 R1LLY COOL!!!!!!!!!!
 *
 * Your program should convert the message to upper-case letters, substitute
 * digits for certain letters (A->4, B->8, E->3, I->1, O->0, S->5) and then
 * apparent 10 or so exclamation marks.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX_MESSAGE 1000

int main(void)
{
   int message[MAX_MESSAGE];
   int c, i, n;

   printf("Enter message: ");
   for (i = 0; (c = getchar()) != '\n'; i++)
      message[i] = c;
   n = i;
   printf("In B1FF-speak: ");
   for (i = 0; i < n; i++) {
      c = toupper(message[i]);
      switch (c) {
         case 'A': printf("4");
                   break;
         case 'B': printf("8");
                   break;
         case 'E': printf("3");
                   break;
         case 'I': printf("1");
                   break;
         case 'O': printf("0");
                   break;
         case 'S': printf("5");
                   break;
         default:  printf("%c", c);
                   break;
      }
   }
   printf("!!!!!!!!!!\n");

   return 0;
}
