/*
 * Exercise 6-1 from K&R: Our version of getword does not properly handle under-
 * scores, string constants, comments, or preprocessor control lines. Write a
 * better version.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
	char *word;
	int count;
} keytab[] = {
	"auto", 0,     "break", 0,    "case", 0,     "char", 0,
	"const", 0,    "continue", 0, "default", 0,  "do", 0,
	"double", 0,   "else", 0,     "enum", 0,     "extern", 0,
	"float", 0,    "for", 0,      "goto", 0,     "if", 0,
	"int", 0,      "long", 0,     "register", 0, "return", 0,
	"short", 0,    "signed", 0,   "sizeof", 0,   "static", 0,
	"struct", 0,   "switch", 0,   "typedef", 0,  "union", 0,
	"unsigned", 0, "void", 0,     "volatile", 0, "while", 0,
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int main(void)
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int getch(void);
void ungetch(int);
void skip_char(void);
void skip_string(void);
void skip_comment(void);
void skip_preprocessor(void);

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c;
	char *w = word;

	while ((c = getch()) != EOF) {
		while (isspace(c))
			c = getch();
		if (c == EOF)
			break;
		switch(c) {
		case '\'':
			skip_char();
			break;
		case '"':
			skip_string();
			break;
		case '/':
			if ((c = getch()) == '*')
				skip_comment();
			else {
				ungetch(c);
				*w++ = '/';
				*w = '\0';
				return '/';
			}
			break;
		case '#': 
			skip_preprocessor();
			break;
		default:
			*w++ = c;
			if (!isalpha(c) && c != '_') {
				*w = '\0';
				return c;
			}
			for ( ; --lim > 0; w++)
				if (!isalnum(*w = getch()) && *w != '_') {
					ungetch(*w);
					break;
				}
			*w = '\0';
			return word[0];
		}
	}
	*w = '\0';
	return c;
}

/* skip_char: Consumes characters that belong to a character constant */
void skip_char(void)
{
	int c, consecutive_backslashes = 0;

	while ((c = getch()) != EOF) {
		if (c == '\'' && consecutive_backslashes % 2 == 0)
			return;
		if (c == '\\')
			consecutive_backslashes++;
		else
			consecutive_backslashes = 0;
	}
}

/* skip_string: Consumes characters that belong to a string constant */
void skip_string(void)
{
	int c, consecutive_backslashes = 0;

	while ((c = getch()) != EOF) {
		if (c == '"' && consecutive_backslashes % 2 == 0)
			return;
		if (c == '\\')
			consecutive_backslashes++;
		else
			consecutive_backslashes = 0;
	}
}

/* skip_comment: Consumes characters that belong to a comment */
void skip_comment(void)
{
	int c, saw_star = 0;

	while ((c = getch()) != EOF) {
		if (c == '/' && saw_star)
			return;
		if (c == '*')
			saw_star = 1;
		else
			saw_star = 0;
	}
}

/* skip_preprocessor: Consumes characters that belong to a preprocessor
 *                    command line */
void skip_preprocessor(void)
{
	int c, saw_backslash = 0;

	while ((c = getch()) != EOF) {
		if (c == '\n' && saw_backslash == 0)
			return;
		if (c == '\\')
			saw_backslash = 1;
		else
			saw_backslash = 0;
	}
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* getch: get a (possibly pushed-back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
