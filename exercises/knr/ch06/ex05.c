/*
 * Exercise 6-5 from K&R: Write a function undef that will remove a name and
 * definition from the table maintained by lookup and install.
 */

#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

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

/* undef: remove name and associated defn from hashtab */
void undef(char *name)
{
	struct nlist *np, *prev;
	unsigned hashval;

	hashval = hash(name);
	for (np = hashtab[hashval], prev = NULL; 
		 np->next != NULL && strcmp(name, np->name) != 0; 
		 prev = np, np = np->next)
		;
	if (prev == NULL)
		hashtab[hashval] = np->next;
	else
		prev->next = np->next;
	free(np->name);
	free(np->defn);
	free(np);
}
