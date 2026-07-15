/*
 * Exercise 5-18 from K&R: Make dcl recover from input errors.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { SUCCESS, FAILURE };	/* return codes for dcl and dirdcl */

int dcl(void);
int dirdcl(void);

int gettoken(void);
int tokentype;           /* type of last token */
int getch(void);
void ungetch(int);
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];

int main(void)  /* convert declaration to words */
{
	int c;

	while (gettoken() != EOF) {    /* 1st token on line is the datatype */
		strcpy(datatype, token);
		out[0] = '\0';
		if (dcl() == FAILURE)
			while ((c = getch()) != '\n' && c != EOF)
					;
		else if (tokentype != '\n' && tokentype != EOF) { 
			printf("syntax error: unexpected '%c'\n", tokentype);
			while ((c = getch()) != '\n' && c != EOF)
				;
		} else
			printf("%s: %s %s\n", name, out, datatype);
	}

	return 0;
}

int gettoken(void)  /* return next token */
{
	int c;
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

/* dcl: parse a declarator */
int dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; )  /* count *'s */
		ns++;
	if (dirdcl() == FAILURE)
		return FAILURE;
	while (ns-- > 0)
		strcat(out, " pointer to");
	return SUCCESS;
}

/* dirdcl: parse a direct declarator */
int dirdcl(void)
{
	int type;

	if (tokentype == '(') {        /* ( dcl ) */
		if (dcl() == FAILURE)
			return FAILURE;
		if (tokentype != ')') {
			printf("error: missing )\n");
			return FAILURE;
		}
	} else if (tokentype == NAME)  /* variable name */
		strcpy(name, token);
	else {
		printf("error: expected name or (dcl)\n");
		return FAILURE;
	}
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	/* error handling for other cases */
	return SUCCESS;
}
