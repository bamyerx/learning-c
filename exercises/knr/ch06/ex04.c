/*
 * Exercise 6-4 from K&R: Write a program that prints the distinct words in its
 * input sorted into decreasing order of frequency of occurrence. Precede each
 * word by its count.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

static int nwords;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
void tree_to_array(struct tnode *, struct tnode **, int *i);
int compare_nodes(const void *, const void *);

/* count distinct words and print in decreasing order of frequency */
int main(void)
{
	struct tnode *root, **list;
	char word[MAXWORD];
	int i;

	nwords = 0;
	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]))
			root = addtree(root, word);
	}
	if (nwords == 0)
		return 0;
	list = malloc(nwords * sizeof(struct tnode *));
	if (list == NULL) {
		printf("Error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	tree_to_array(root, list, &i);
	qsort(list, nwords, sizeof(struct tnode *), compare_nodes);
	for (i = 0; i < nwords; i++) {
		printf("%4d %s\n", list[i]->count, list[i]->word);
	}
	return 0;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

/* tree_to_array: traverses tree and places nodes in an array */
void tree_to_array(struct tnode *p, struct tnode **list, int *i)
{
	if (p != NULL) {
		tree_to_array(p->left, list, i);
		list[(*i)++] = p;
		tree_to_array(p->right, list, i);
	}
}

/* compare_nodes: compares tree nodes by count, then by lexicographical order */
int compare_nodes(const void *a, const void *b)
{
	struct tnode *pa = *(struct tnode **) a;
	struct tnode *pb = *(struct tnode **) b;

	if (pa->count != pb->count)
		return pb->count - pa->count;

	return strcmp(pa->word, pb->word);
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

struct tnode *talloc(void);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
		nwords++;
	} else {
		cond = strcmp(w, p->word);
		if (cond < 0) {
			p->left = addtree(p->left, w);
		} else if (cond > 0) {
			p->right = addtree(p->right, w);
		} else {
			p->count++;
		}
	}
	return p;
}

/* talloc: make a tnode, terminate program on failure */
struct tnode *talloc(void)
{
	struct tnode *t;

	if ((t = malloc(sizeof(struct tnode))) == NULL) {
		printf("Error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	return t;
}

/* strdup: duplicate s, terminate program on failure */
char *strdup(char *s)
{
	char *p;

	if ((p = malloc(strlen(s) + 1)) == NULL) {
		printf("Error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	return strcpy(p, s);
}
