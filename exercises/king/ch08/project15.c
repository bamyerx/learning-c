/*
 * Project 15 from Chapter 8 of King: Write a program that encrypts a message
 * using a Caesar cipher. The user will enter the message to be encrypted and
 * the shift amount (the number of positions by which letter should be 
 * shifted):
 *
 *    Enter message to be encrypted: Go ahead, make my day.
 *    Enter shift amount (1-25): 3
 *    Encrypted message: Jr dkhdg, pdnh pb gdb.
 *
 * Notice that the program can decrypt a message is the user enters 26 minus the
 * original key. You may assume that the message does not exceed 80 characters.
 * Characters other than letters should be left unchanged. Lower-case letters
 * should remain lower-case when encrypted, and upper-case letters remain upper-
 * case.
 */

#include <stdio.h>

#define MAX_MESSAGE 80

int main(void)
{
   char message[MAX_MESSAGE];
   int c, i, shift;

   printf("Enter message to be encrypted: ");
   for(i = 0; (c = getchar()) != '\n'; i++)
      message[i] = c;
   message[i] = '\n';
   printf("Enter shift amount (1-25): ");
   scanf("%d", &shift);
   printf("Encrypted message: ");
   for (i = 0; message[i] != '\n'; i++) {
      c = message[i];
      if (c >= 'A' && c <= 'Z') 
         c = ((c - 'A') + shift) % 26 + 'A';
      if (c >= 'a' && c <= 'z')
         c = ((c - 'a') + shift) % 26 + 'a';
      printf("%c", c);
   }
   printf("\n");

   return 0;
}
