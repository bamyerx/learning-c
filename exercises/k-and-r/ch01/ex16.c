/*
 * Exercise 1-16 from K & R: Revise the main routine of the longest-line
 * problem so it will correctly print the length of arbitrary long input lines,
 * and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
   int len;
   int max;
   char line[MAXLINE];
   char longest[MAXLINE];

   max = 0;
   while ((len = get_line(line, MAXLINE)) > 0) {
      if (len > max) {
         max = len;
         copy(longest, line);
      }
   }
   if (max > 0) {
      printf("%s", longest);
   }
   return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim) {
   int c, i;

   for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
      if (i < lim - 1) {
         s[i] = c;
      }
      if (i == lim - 1) {
         s[i] = '\0';
      }
   }
   if (c == '\n' && i < lim - 1) {
      s[i] = c;
      ++i;
      s[i] = '\0';
   } else if (c == '\n') {
      ++i;
   }
   return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
   int i;

   i = 0;
   while ((to[i] = from[i]) != '\0') {
      ++i;
   }
}
