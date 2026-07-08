/*
 * Project 17 from Chapter 13 of King: Modify Programming Project 2 from Chapter
 * 12 so that it includes the following function:
 *
 *      bool is_palindrome(const char *message);
 *
 * The function returns true if the string pointed to by message is a 
 * palindrome.
  */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXMSG 100

bool is_palindrome(const char *);

int main(void)
{
    char msg[MAXMSG+1];
    int c, i = 0;

    printf("Enter a message: ");
    while ((c = getchar()) != '\n')
        if (i < MAXMSG)
            msg[i++] = c;
    msg[i] = '\0';
    printf("%s\n", is_palindrome(msg) ? "Palindrome" : "Not a palindrome");

    return 0;
}

bool is_palindrome(const char *message)
{
    char c, *left, *right, trimmed_msg[MAXMSG+1];
    
    left = right = trimmed_msg;
    while ((c = *message++))
        if (isalpha(c))
            *right++ = toupper(c);
    right--;
    while (left <= right) {
        if (*left++ != *right--)
            return false;
    }
    return true;
}
