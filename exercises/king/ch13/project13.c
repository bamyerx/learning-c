/*
 * Project 13 from Chapter 13 of King: Modify Programming Project 15 from
 * Chapter 8 so that it includes the following function:
 *
 *      void encrypt(char *message, int shift);
 *
 * The function expects message to point to a string containing the message to
 * be encrypted; shift represents the amount by which each letter in the message
 * is to be shifted.
 */

#include <stdio.h>

#define MAX_MESSAGE 80

void encrypt(char *, int);

int main(void)
{
   char message[MAX_MESSAGE];
   int c, i, shift;

   printf("Enter message to be encrypted: ");
   for(i = 0; (c = getchar()) != '\n'; i++)
      message[i] = c;
   message[i] = '\0';
   printf("Enter shift amount (1-25): ");
   scanf("%d", &shift);
   encrypt(message, shift);
   printf("Encrypted message: %s\n", message);

   return 0;
}

void encrypt(char *message, int shift)
{
    char c;
    for (; (c = *message); message++) {
        if (c >= 'A' && c <= 'Z') 
            *message = ((c - 'A') + shift) % 26 + 'A';
        if (c >= 'a' && c <= 'z')
            *message = ((c - 'a') + shift) % 26 + 'a';
    }
}
