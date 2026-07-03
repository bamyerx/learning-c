/*
 * Exercise 4-9 of K&R: Our getch and ungetch do not handle a pushed-back EOF
 * correctly. Decide what their properties ought to be if an EOF is pushed back,
 * then implement your design.
 */

/*
 * EOF is defined by stdio.h as -1, which is not guaranteed to be handled by the
 * char array buffer used in getch and ungetch because the signedness of char is
 * implementation-defined. This can be fixed by simply changing the buffer type
 * to int.
 */

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void)         /* get a (possibly pushed-back character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
