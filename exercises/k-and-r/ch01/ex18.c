/*
 * Exercise 1-18 from K&R: Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int limit);

int main(void)
{
   int len, last_index;
   char line[MAXLINE];

   while((len = get_line(line, MAXLINE)) > 0) {
      int i;
      last_index = -1;
      for (i = 0; i < len - 1; ++i) {
         if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
            last_index = i;
         }
      }
      if (last_index != -1) {
         line[last_index + 1] = '\0';
         printf("%s\n", line);
      }
   }
}

int get_line(char s[], int lim) 
{
   int c, i;

   for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
      s[i] = c;
   }
   if (c == '\n') {
      s[i] = c;
      ++i;
   }
   s[i] = '\0';
   return i;
}
