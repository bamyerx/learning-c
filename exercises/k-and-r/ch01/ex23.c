/*
 * Exercise 1-23 from K&R: Write a program to remove all comments from a C
 * program.
 */

#include <stdio.h>

#define CODE 0
#define AFTER_SLASH 1
#define COMMENT 2
#define STRING 3
#define CHAR 4

int main(void)
{
   int state, c;
   int lastchar = '\0';
   int nbackslash = 0; /* backslash counter for escape sequence parsing */

   state = CODE;
   while ((c = getchar()) != EOF) {
      if (state == CODE) {
         if (c == '/') {
            state = AFTER_SLASH;
         } else {
            putchar(c);
            if (c == '\"') {
               state = STRING;
            } else if (c == '\'') {
               state = CHAR;
            }
         }
      } else if (state == AFTER_SLASH) {
         if (c == '*') {
            putchar(' ');
            state = COMMENT;
         } else {
            putchar('/');
            putchar(c);
            if (c == '\"') {
               state = STRING;
            } else if (c == '\'') {
               state = CHAR;
            } else {
               state = CODE;
            }
         }
      } else if (state == COMMENT) {
         if (c == '/' && lastchar == '*') {
            state = CODE;
         }
      } else if (state == STRING) {
         putchar(c);
         if (c == '\\') {
            ++nbackslash;
         } else if (c == '"' && nbackslash % 2 == 0) {
            nbackslash = 0;
            state = CODE;
         } else {
            nbackslash = 0;
         }
      } else if (state == CHAR) {
         putchar(c);
         if (c == '\\') {
            ++nbackslash;
         } else if (c == '\'' && nbackslash % 2 == 0) {
            nbackslash = 0;
            state = CODE;
         } else {
            nbackslash = 0;
         }
      }
      lastchar = c;
   }
   /* if input ends in AFTER_SLASH, ensure the held '/' gets printed */
   if (state == AFTER_SLASH) {
      putchar('/');
   }

   return 0;
}
