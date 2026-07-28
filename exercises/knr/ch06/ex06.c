/*
 * Exercise 6-6 from K&R: Implement a simple version of the #define preprocessor
 * (i.e., no arguments) suitable for use with C programs, based on the routines
 * of this section.
 *
 * In addition to not supporting parameterized macros, this processor also
 * has the following limitations:
 *     - Replacement text may only be up to MAXTOKEN characters long.
 *     - Line continuations are not recognized.
 *     - Comments inline with preprocessor directives are not recognized.
 *     - #define directives that are longer than MAXLINE as well as other
 *       preprocessor directives are passed through unchanged.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTOKEN 100
#define MAXLINE 1000

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

int getch(void);
void ungetch(int);
int getname(char *, int);
void process_directive(void);
void process_char_or_string(char);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);

/* basic C preprocessor that performs macro expansion */
int main(void)
{
	int c;
	char name[MAXTOKEN+1];
	struct nlist *p;
	
	enum {NORMAL, NEWLINE, DIRECTIVE, CHAR, STRING, COMMENT} state;

	state = NEWLINE;
	while ((c = getch()) != EOF) {
		switch(state) {
		case NORMAL:
			if (isalpha(c) || c == '_') {
				ungetch(c);
				getname(name, MAXTOKEN);
				if ((p = lookup(name)) != NULL)
					fputs(p->defn, stdout);
				else
					fputs(name, stdout);
			} else {
				putchar(c);
				switch(c) {
				case '/':
					if ((c = getch()) == '*') {
						putchar(c);
						state = COMMENT;
					} else
						ungetch(c);
					break;
				case '\n':
					state = NEWLINE; 
					break;
				case '\'':
					state = CHAR; 
					break;
				case '"':
					state = STRING; 
					break;
				}
			}
			break;
		case NEWLINE:
			if (c == '#')
				state = DIRECTIVE;
			else if (isspace(c))
				putchar(c);
			else {
				ungetch(c);
				state = NORMAL;
			}
			break;
		case DIRECTIVE:
			ungetch(c);
			process_directive();
			state = NEWLINE;
			break;
		case CHAR:
			putchar(c);
			process_char_or_string('\'');
			state = NORMAL;
			break;
		case STRING:
			putchar(c);
			process_char_or_string('"');
			state = NORMAL;
			break;
		case COMMENT:
			putchar(c);
			if (c == '*') {
				if ((c = getch()) == '/') {
					putchar(c);
					state = NORMAL;
				} else
					ungetch(c);
			}
			break;
		}
	}
}

/* getname: read a C identifier from input */
int getname(char *name, int lim)
{
	int c, i;

	i = 0;
	if (isalpha(c = getch()) || c == '_') {
		name[i++] = c;
		while (isalnum(c = getch()) || c == '_')
			if (i < lim)
				name[i++] = c;
	}
	if (c != EOF)
		ungetch(c);
	name[i] = '\0';
	return i;
}

/* process_directive: print non-define directives as is and install macros and
 *                    their expansions as key-value pairs in a hash table */
void process_directive(void)
{
	int c, i;
	char name[MAXTOKEN+1], defn[MAXTOKEN+1], buf[MAXLINE+1], *p;

	/* buffer up to MAXLINE - 1 characters of the directive line
	 * if the line is too long, emit the entire line unchanged and return */
	i = 0;
	buf[i++] = '#';
	while ((c = getch()) != '\n' && c != EOF && i < MAXLINE)
		buf[i++] = c;
	buf[i] = '\0';
	if (c != '\n' && c != EOF) {  /* line is longer than MAXLINE */
		fputs(buf, stdout);
		while ((c = getch()) != '\n' && c != EOF)
			putchar(c);
		if (c == '\n')
			ungetch(c);
		return;
	}
	ungetch(c);

	/* parse buffered directive line for a #define directive */
	p = buf;
	p++;                 /* advance past the '#' */
	while (isspace(*p))  /* skip white space between # and identifier */
		p++;
	/* flush buffer and return if line ended in white space after '#', 
	 * next six characters are not "define", or "define" is not followed by 
	 * white space */
	if (*p == '\0' || strncmp(p, "define", 6) != 0 || !isspace(*(p+6))) {
		fputs(buf, stdout);
		return;
	}
	p += 6;
	while (isspace(*p))  /* skip white space between "define" and macro name */
		p++;

	/* validate and copy identifier into name */
	i = 0;
	if (!isalpha(*p) && *p != '_') {  /* invalid identifier name or line ended */
		fputs(buf, stdout);
		return;
	}
	name[i++] = *p++;
	while (isalnum(*p) || *p == '_') { /* copy identifier into name */
		if (i < MAXTOKEN)              /* (up to MAXTOKEN characters) */
			name[i++] = *p++;
		else
			p++;
	}
	if (*p != '\0' && !isspace(*p)) {  /* invalid end of identifier */
		fputs(buf, stdout);
		return;
	}
	name[i] = '\0';

	/* skip white space until next token */
	while (isspace(*p))
		p++;

	/* copy rest of line into defn (up to MAXTOKEN characters)  */
	i = 0;
	while (*p != '\0' && i < MAXTOKEN)
		defn[i++] = *p++;
	defn[i] = '\0';

	if (install(name, defn) == NULL) {
		exit(EXIT_FAILURE);
	}
}

/* process_char_or_string: print characters within character or string 
 *                         literals */
void process_char_or_string(char delimiter)
{
	int c, consecutive_backslashes;

	consecutive_backslashes = 0;
	while ((c = getch()) != EOF && c != '\n') {
		putchar(c);
		if (c == delimiter && consecutive_backslashes % 2 == 0)
			return;
		else if (c == '\\')
			consecutive_backslashes++;
		else
			consecutive_backslashes = 0;
	}
	if (c == '\n')
		ungetch(c);
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

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

char *strdup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	char *cp;
	unsigned hashval;

	if ((cp = strdup(defn)) == NULL)
		return NULL;
	if ((np = lookup(name)) == NULL) {
		np = malloc(sizeof(*np));
		if (np == NULL || (np->name = strdup(name)) == NULL) {
			free(np);
			free(cp);
			return NULL;
		}
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else
		free(np->defn);
	np->defn = cp;
	return np;
}

/* make a duplicate of s */
char *strdup(char *s)
{
	char *p;

	p = malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}
