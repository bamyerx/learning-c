/*
 * Exercise 6-2 from K&R: Write a program that reads a C program and prints in
 * alphabetical order each group of variable names that are identical in the
 * first 6 characters, but different somewhere thereafter. Don't count words
 * within strings and comments. Make 6 a parameter that can be set from the
 * command line.
 *
 * Note: My solution involves arranging names returned by getword() as a binary
 * tree of variable name groups, each with a binary tree of variable names. This
 * is accomplished using a single tnode structure which can serve as either a
 * group node or a variable node, with the following properties: group nodes
 * have name == NULL with vars pointing to a variable tree and variable nodes
 * have name != NULL and vars == NULL.
 */

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 24

const char *keywords[] = {
	"auto",     "break",    "case",     "char",
	"const",    "continue", "default",  "do",
	"double",   "else",     "enum",     "extern",
	"float",    "for",      "goto",     "if",
	"int",      "long",     "register", "return",
	"short",    "signed",   "sizeof",   "static",
	"struct",   "switch",   "typedef",  "union",
	"unsigned", "void",     "volatile", "while",
};

struct tnode {
	char *name;
	struct tnode *left;
	struct tnode *right;
	struct tnode *vars;
};

struct tnode *addgroup(struct tnode *, char *, int);
struct tnode *addvar(struct tnode *, char *);
void printgroups(struct tnode *, int);
int getword(char *, int);
int is_keyword(char *);

/* prints groups of matching variable names */
int main(int argc, char *argv[])
{
	int n, strtopi(const char *, int);
	struct tnode *root;
	char word[MAXWORD];

	argv++;
	argc--;
	if (argc < 1) {
		printf("main: no argument specified\n");
		exit(EXIT_FAILURE);
	}
	if (*argv[0] == '\0') {
		printf("main: argument is empty\n");
		exit(EXIT_FAILURE);
	}
	n = strtopi(*argv, 10);
	if (n < 1 || n >= MAXWORD) {
		printf("main: argument must be an integer between 1 and %d\n", MAXWORD);
		exit(EXIT_FAILURE);
	}
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if ((isalpha(word[0]) || word[0] == '_') && !is_keyword(word)) {
			root = addgroup(root, word, n);
			if (root == NULL) {
				printf("main: memory allocation failure\n");
				exit(EXIT_FAILURE);
			}
		}
	printgroups(root, n);
	return 0;
}

/* strtopi: converts string to positive int, returns 0 if unsuccessful */
int strtopi(const char *s, int base)
{
	long l;
	char *p;
	
	l = strtol(s, &p, base);
	if (p == s || *p != '\0' || (l < 1) || (l > INT_MAX)) {
		return 0;
	}
	return (int) l;
}

/* is_keyword: checks if parameter is a C keyword */
int is_keyword(char *word)
{
	int i;

	for (i = 0; i < NKEYS; i++)
		if (strcmp(word, keywords[i]) == 0)
			return 1;
	return 0;
}

struct tnode *talloc(void);
char *strdup(char *);

/* addgroup: add a name to p or create new group below p */
struct tnode *addgroup(struct tnode *p, char *name, int n)
{
	int cond;

	if (p == NULL) {
		if ((p = talloc()) == NULL)
			return NULL;
		p->vars = addvar(NULL, name);
		if (p->vars == NULL) {
			free(p);
			return NULL;
		}
		p->name = NULL;
		p->left = p->right = NULL;
	} else {
		cond = strncmp(name, p->vars->name, n);
		if (cond > 0) {
			p->right = addgroup(p->right, name, n);
			if (p->right == NULL)
				return NULL;
		} else if (cond < 0) {
			p->left = addgroup(p->left, name, n);
			if (p->left == NULL)
				return NULL;
		} else {
			p->vars = addvar(p->vars, name);
			if (p->vars == NULL)
				return NULL;
		}
	}
	return p;
}

/* addvar: add a variable name at or below p */
struct tnode *addvar(struct tnode *p, char *name)
{
	int cond;

	if (p == NULL) {
		if ((p = talloc()) == NULL)
			return NULL;
		p->name = strdup(name);
		if (p->name == NULL) {
			free(p);
			return NULL;
		}
		p->left = p->right = p->vars = NULL;
	} else {
		cond = strcmp(name, p->name);
		if (cond > 0) {
			p->right = addvar(p->right, name);
			if (p->right == NULL)
				return NULL;
		} else if (cond < 0) {
			p->left = addvar(p->left, name);
			if (p->left == NULL)
				return NULL;
		}
	}
	return p;
}

void treeprint(struct tnode *);

/* printgroups: in-order print of each group of tree p */
void printgroups(struct tnode *p, int n)
{
	char prefix[n+1];

	if (p != NULL) {
		printgroups(p->left, n);
		strncpy(prefix, p->vars->name, n);
		prefix[n] = '\0';
		printf("\nGroup %s:\n", prefix);
		treeprint(p->vars);
		printgroups(p->right, n);
	}
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->name);
		treeprint(p->right);
	}
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* strdup: make a duplicate of s */
char *strdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
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
