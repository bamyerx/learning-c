/*
 * Exercise 4-6 of K&R: Add commands for handling variables. (it's easy to
 * provide twenty-six variables with single-letter names.) Add a variable for
 * the most recently printed value.
 */

#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP   100     /* max size of operand or operator */
#define MAXVAR  26      /* maximum number of variables */
#define NUMBER  '0'     /* signal that a number was found */
#define NAME    '1'     /* signal that a word was found */
#define MAXVAL  100     /* maximum depth of val stack */
#define BUFSIZE 100
#define FALSE   0
#define TRUE    1

int getop(char []);
int stackop(char []);
int math(char []);
void push(double);
double pop(void);
double peek(void);
void dupe(void);
void swap(void);
void clear(void);
void printall(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(void)
{
    int type, eval, lastvar;
    double op2, var[MAXVAR] = {0.0};
    char s[MAXOP];

    eval = TRUE;
    lastvar = 0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                if (stackop(s))
                    eval = FALSE;
                else if (math(s))
                    ;
                else if (strlen(s) == 1 && isupper(s[0])) {
                    lastvar = s[0];
                    push(var[s[0] - 'A']);
                }
                else
                    printf("error: unknown command %s\n", s);
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '=':
                eval = FALSE;
                if (lastvar > 0){
                    pop();      /* pop previously read value for lastvar */
                    var[lastvar - 'A'] = pop();
                } else
                    printf("error: no variable specified\n");
                break;
            case '\n':      
                if (eval)
                    printf("\t%.8g\n", pop());
                eval = TRUE;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* stackop: execute a stack operation */
int stackop(char s[]) 
{
    if (strcmp(s, "print") == 0)
        printf("%.8g\n", peek());
    else if (strcmp(s, "dupe") == 0)
        dupe();
    else if (strcmp(s, "swap") == 0)
        swap();
    else if (strcmp(s, "clear") == 0)
        clear();
    else if (strcmp(s, "printall") == 0)
        printall();
    else 
        return 0;   /* failure */

    return 1;       /* success */
}

/* math: execute a mathematical function */
int math(char s[])
{
    double x, y;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "log") == 0) {
        if ((x = pop())<= 0)
            printf("error: nonpositive argument for log\n");
        else
            push(log(x));
    } else if (strcmp(s, "pow") == 0) {
        y = pop();
        x = pop();
        if (x == 0 && y <= 0)
            printf("error: negative exponent for zero base\n");
        else if (x < 0 && y != (int) y)
            printf("error: non-integer exponent for negative base\n");
        else
            push(pow(x, y));
    } else if (strcmp(s, "sqrt") == 0) {
        if ((x = pop()) < 0)
            printf("error: negative radicand\n");
        else
            push(sqrt(x));
    } else
        return 0;   /* failure */

    return 1;       /* success */
}

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

/* peek: return top value from stack without popping */
double peek(void)
{
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("(empty)\n");
        return 0.0;
    }
}

/* dupe: duplicate the top value of the stack */
void dupe(void)
{
    if (sp > 0)
        push(peek());
    else
        printf("error: stack empty\n");
}

/* swap: swap the top two values of the stack */
void swap(void)
{
    double temp;
    if (sp > 1) {
        temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else
        printf("error: not enough elements to swap\n");
}

/* clear: reset the stack index to zero */
void clear(void)
{
    sp = 0;
}

/* print: print the entire stack to stdout */
void printall(void)
{
    printf("stack: ");
    if (sp > 0) {
        int i;
        for (i = 0; i < sp; i++)
            printf("%.8g ", val[i]);
    } else
        printf("(empty)");
    printf("\n");
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isalnum(c) && c != '.' && c != '-')
        return c;       /* not a number */
    i = 0;
    if (isalpha(c)) {
        while (isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        return NAME;
    }
    if (c == '-') {     /* decide if '-' is a negative sign or minus operator */
        if (!isdigit(c = getch()) && c != '.') {
            ungetch(c);
            return '-';
        } else
            s[++i] = c;
    }
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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
