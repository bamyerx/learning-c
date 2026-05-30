/*
 * Exercise 1-19 from K&R: Write a function reverse(s) that reverses the
 * character string s. Use it to write a program that reverses its input a line
 * at a time.
 */

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
   int len;
   char line[MAXLINE];

   while ((len = get_line(line, MAXLINE)) > 0) {
      if (line[len - 1] == '\n') {
         line[len - 1] = '\0';
      }
      reverse(line);
      printf("%s\n", line);
   }
   return 0;
}

int get_line(char s[], int lim) {
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

void reverse(char s[]) {
   int i, j;
   char temp;

   for (j = 0; s[j] != '\0'; ++j) {
      ;
   }
   --j;

   for (i = 0; i < j; ++i, --j) {
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
   }
}
