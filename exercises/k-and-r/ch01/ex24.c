/*
 * Exercise 1-24 from K&R: Write a program to check a C program for rudimentary
 * syntax errors like unmatched parentheses, brackets, and braces.
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define CODE 0
#define COMMENT 1
#define STRING 2
#define CHAR 3
#define MAXSTACK 1000

int stack[MAXSTACK];
int top = 0;

int push(int c);
void pop(void);
int peek(void);

/* checks for unmatched delimiters and proper nesting */
int main(void)
{
   int state, c;
   int error = FALSE;
   int lastchar = '\0';
   int nbackslash = 0; /* backslash counter for escape sequence parsing */

   push('\0'); /* push a '\0' to indicate the bottom of the stack */
   state = CODE;
   while ((c = getchar()) != EOF && !error) {
      if (state == CODE) {
         if (c == '*' && lastchar == '/') {
            state = COMMENT;
         } else if (c == '\"') {
            state = STRING;
         } else if (c == '\'') {
            state = CHAR;
         } else if (c == '(' || c == '[' || c == '{') {
            if (!push(c)) {
               error = TRUE;
               printf("Stack overflow: maximum nesting depth reached");
            }
         } else if (c == ')' || c == ']' || c == '}') {
            if (peek() == '\0') {
               error = TRUE;
               printf("Syntax error: unmatched closing delimiter '%c'\n", c);
            } else if ((c == ')' && peek() == '(')
                  || (c == ']' && peek() == '[')
                  || (c == '}' && peek() == '{')) {
               pop();
            } else {
               error = TRUE;
               printf("Syntax error: mismatched delimiters: ");
               printf("%c does not match %c\n", peek(), c);
            }
         }
      } else if (state == COMMENT) {
         if (c == '/' && lastchar == '*') {
            state = CODE;
         }
      } else if (state == STRING) {
         if (c == '\\') {
            ++nbackslash;
         } else if (c == '"' && nbackslash % 2 == 0) {
            nbackslash = 0;
            state = CODE;
         } else {
            nbackslash = 0;
         }
      } else if (state == CHAR) {
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
   if (!error && top != 1) {
      printf("Syntax error: unclosed delimiter %c\n", peek());
   }
   return 0;
}

/* push: push an element onto the stack */
int push(int c) {
   if (top < MAXSTACK) {
      stack[top] = c;
      ++top;
      return TRUE;
   } else {
      return FALSE;
   }
}

/* pop: pop an element off of the stack */
void pop(void) {
   --top;
}

/* peek: return the element at the top of the stack */
int peek(void) {
   return stack[top - 1];
}
