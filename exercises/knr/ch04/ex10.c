/*
 * Exercise 4-10 of K&R: An alternate organization uses getline to read an
 * entire input line; this makes getch and ungetch unnecessary. Revise the
 * calculator to use this approach.
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':      
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

#define MAXLINE 1000

int getline(char [], int);

char buf[MAXLINE] = "";
int bufp = 0;

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    if (buf[bufp] == '\0') {
        if (getline(buf, MAXLINE) == 0)
            return EOF;
        bufp = 0;
    }
    while ((s[0] = c = buf[bufp++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = buf[bufp++]))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = buf[bufp++]))
            ;
    s[i] = '\0';
    bufp--;
    return NUMBER;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
