/*
 * Exercise 4-8 of K&R: Suppose that there will never be more than one character
 * of pushback. Modify getch and ungetch accordingly.
 */

#define BUFSIZE 100

char buf;               /* buffer for ungetch */
int bufp = 0;           /* 0 indicates unbuffered, 1 indicates buffered */

int getch(void)         /* get a (possibly pushed-back character */
{
    if (bufp) {
        bufp = 0;
        return buf;
    }
    return getchar();
}

void ungetch(int c)     /* push character back on input */
{
    if (bufp)
        printf("ungetch: too many characters\n");
    else {
        buf = c;
        bufp = 1;
    }
}
