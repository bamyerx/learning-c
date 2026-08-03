/*
 * Exercise 1-10 from chapter 1 of K & R: Write a program to copy its input to
 * its output, replacing each tab by \t, each backspace by \b, and each back-
 * slash by \\.
 */

#include <stdio.h>

int main(void)
{
   int c;

   while ((c = getchar()) != EOF) {
      if (c == '\t') {
          printf("\\t");
      } else if (c == '\b') {
          printf("\\b");
      } else if (c == '\\') {
          printf("\\\\");
      } else {
          putchar(c);
      }
   }

   return 0;
}
