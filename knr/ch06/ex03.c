/*
 * Exercise 6-3 from K&R: Write a cross-referencer that prints a list of all
 * words in a document, and for each word, a list of the line numbers on which
 * it occurs. Remove noise words like "the," "and," and so on.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
	char *word;
	struct lnode *head;
	struct lnode *tail;
	struct tnode *left;
	struct tnode *right;
};

struct lnode {
	int line;
	struct lnode *next;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int is_noise(char *);
int getword(char *, int);
char *lowercase(char *);

/* cross-referencer */
int main(void)
{
	struct tnode *root;
	char word[MAXWORD];
	int line_number;

	root = NULL;
	line_number = 1;
	while (getword(word, MAXWORD) != EOF) {
		if (word[0] == '\n')
			line_number++;
		else if (isalpha(word[0]) && !is_noise(lowercase(word)))
			root = addtree(root, word, line_number);
	}
	treeprint(root);
	return 0;
}

/* lowercase: convert string to lowercase */
char *lowercase(char *s)
{
	char *p;

	for (p = s; *p != '\0'; p++)
		*p = tolower(*p);
	return s;
}

/* is_noise: checks if word is a noise word using a binary search */
int is_noise(char *word)
{
	static const char *noise[] = {
		"a", "an", "and", "are", "as", "at", "be", "been", "but", "by", "for",
		"from", "had", "has", "have", "he", "her", "his", "i", "if", "in", 
		"into", "is", "it", "its", "me", "my", "not", "of", "on", "or", "our",
		"she", "so", "that", "the", "their", "them", "there", "they", "this",
		"to", "was", "we", "were", "which", "with", "you", "your"
	};

	int cond, low, high, mid;

	low = 0;
	high = (int) (sizeof(noise) / sizeof(noise[0])) - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		cond = strcmp(word, noise[mid]);
		if (cond < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return 1;
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
		if (c == '\n') {
			*w = c;
			return word[0];
		}
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()) && *w != '\'') {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
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
struct lnode *lalloc(void);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line)
{
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->head = lalloc();
		p->head->next = NULL;
		p->head->line = line;
		p->tail = p->head;
		p->left = p->right = NULL;
	} else {
		cond = strcmp(w, p->word);
		if (cond < 0) {
			p->left = addtree(p->left, w, line);
		} else if (cond > 0) {
			p->right = addtree(p->right, w, line);
		} else {
			if (p->tail->line != line) {
				p->tail->next = lalloc();
				p->tail = p->tail->next;
				p->tail->line = line;
				p->tail->next = NULL;
			}
		}
	}
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s: ", p->word);
		while (p->head->next != NULL) {
			printf("%d, ", p->head->line);
			p->head = p->head->next;
		}
		printf("%d\n", p->head->line);
		treeprint(p->right);
	}
}

#include <stdlib.h>

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

/* lalloc: make an lnode, terminate program on failure */
struct lnode *lalloc(void)
{
	struct lnode *l;

	if ((l = malloc(sizeof(struct lnode))) == NULL) {
		printf("Error: out of memory\n");
		exit(EXIT_FAILURE);
	}
	return l;
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
