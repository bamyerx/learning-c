/*
 * Exercise 5-18 from K&R: Modify undcl so that it does not add redundant
 * parentheses to declarations.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { FALSE, TRUE };
enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;           /* type of last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char out[1000];

int main(void)  /* undcl: convert word descriptions to declarations */
{
	int type, needs_paren(void);
	char temp[MAXTOKEN];

	out[0] = '\0';
	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, needs_paren() ? "(*%s)" : "*%s", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
	}
	printf("%s\n", out);

	return 0;
}

int needs_paren(void)
{
	char *p = out;

	if (*p == '\0')
		return FALSE;
	while (*p)
		p++;
	return (*(p-1) == ')' && *(p-2) == '(') || *(p-1) == ']';
}

int gettoken(void)  /* return next token */
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
