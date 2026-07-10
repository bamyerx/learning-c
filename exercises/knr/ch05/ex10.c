/*
 * Exercise 5-10 from K&R: Write the program expr, which evaluates a reverse
 * Polish expression from the command line, where each operator or operand is a
 * separate argument.
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define UNKNOWN '1'

int getop(char *);
double pop(void);
void push(double);

int main(int argc, char *argv[])
{
	int type;
	char *arg;
	double op2;

	while (--argc > 0) {
		arg = *++argv;
		type = getop(arg);
		switch (type) {
		case NUMBER:
			push(atof(arg));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case UNKNOWN:	/* FALLTHROUGH */
		default:
			printf("error: unknown argument %s\n", arg);
			break;
		}
	}
	printf("%.8g\n", pop());

	return 0;
}

#define MAXVAL 100

double val[MAXVAL];
double *p = val;

void push(double f)
{
	if (p < val + MAXVAL)
		*p++ = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (p > val)
		return *--p;
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getop(char *arg)
{
	int saw_digit = 0;

	if (*(arg + 1) == '\0' && !isdigit(*arg))
		return *arg;
	if (*arg == '+' || *arg == '-')
		arg++;
	while (isdigit(*arg)) {
		saw_digit = 1;
		arg++;
	}
	if (*arg == '.')
		arg++;
	while (isdigit(*arg)) {
		saw_digit = 1;
		arg++;
	}
	if (saw_digit && *arg == '\0')
		return NUMBER;
	return UNKNOWN;
}
