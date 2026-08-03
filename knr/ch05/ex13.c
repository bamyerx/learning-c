/*
 * Exercise 5-13 from K&R: Write the program tail, which prints the last n lines
 * of its input. By default, n is 10, let us say, but it can be changed by an 
 * optional argument, so that
 *
 *		tail -n
 *
 * prints the last n lines. The program should behave rationally no matter how
 * unreasonable the input or the value of n. Write the program so that it makes
 * the best use of available storage; lines should be stored as in the sorting
 * program of Section 5.6, not in a two-dimensional array of fixed size.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define DEFAULT_TAIL 10

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
char *alloc(int n);

int main(int argc, char *argv[])
{
	int nlines, tail = DEFAULT_TAIL;

	if (argc > 1) {
		if (argc > 2) {
			printf("tail: too many arguments\n");
			return 1;
		}
		char *p = *++argv;
		if (*p++ != '-') {
			printf("tail: illegal option %s\n", *argv);
			return 1;
		}
		while (*p)
			if (!isdigit(*p++)) {
				printf("tail: illegal option %s\n", *argv);
				return 1;
			}
		if ((tail = atoi(*argv + 1)) < 1) {
			printf("tail: invalid number of lines\n");
			return 1;
		}
	}
	nlines = readlines(lineptr, MAXLINES);
	if (nlines < 0) {
		printf("tail: input too large\n");
		return 1;
	} 
	if (tail > nlines)
		tail = nlines;
	writelines(lineptr + nlines - tail, tail);
	return 0;
}

#define MAXLEN 1000

int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
	int c;
	char *p = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	return p - s;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

/* alloc: return pointer to n characters */
char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}
