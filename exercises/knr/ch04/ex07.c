/*
 * Exercise 4-7 of K&R: Write a routine ungets(s) that will push back an entire
 * string onto the input. Should ungets know about buf and bufp, or should it
 * just use ungetch?
 */

/*
 * ungets need not know about buf or bufp, since those can remain encapsulated
 * by the getch/ungetch layer. Instead, ungets can simply use ungetch to push
 * the string onto the buffer.
 */

#define BUFSIZE 100

/* ungets: push a string back onto input */
void ungets(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    while (i > 0)
        ungetch(s[--i]);
}

char buf[BUFSIZE];      /* buffer for ungetch */
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
