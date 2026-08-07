/*
 * Exercise 7-5 from K&R: Rewrite the postfix calculator of Chapter 4 to use
 * scanf and/or sscanf to do the input and number conversion.
 */

#include <stdio.h>

#define MAXOP   100   /* max size of operand or operator */
#define MAXLINE 1000  /* max line length */

void push(double);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
	int n;
	double f, op2;
	char c, *p, line[MAXLINE];

	while (fgets(line, sizeof(line), stdin) != NULL) {
		p = line;
		while (*p) {
			if (sscanf(p, "%lf%n", &f, &n) == 1) {
				push(f);
				p += n;
			} else {
				switch(*p) {
				case ' ': case '\t':
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
					printf("error: unknown operator %c\n", *p);
					break;
				}
				p++;
			}
		}
	}
	return 0;
}

#define MAXVAL 100   /* maximum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

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
