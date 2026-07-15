/*
 * Exercise 5-15 from K&R: Add the option -f to fold upper and lower case
 * together, so that case distinctions are not made during sorting; for example,
 * a and A compare equal.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* max # lines to be sorted */

char *lineptr[MAXLINES];	/* pointers to text lines */
int numeric = 0, reverse = 0, fold = 0;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void knr_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int my_strcmp(const char *, const char *);
int numcmp(const char *, const char *);

/* sort input lines */
int main(int argc, char *argv[])
{
	int c, nlines;

	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				fold = 1;
				break;
			default:
				printf("sort: illegal option %c\n", c);
				argc = 0;
				break;
			}
	if (argc != 0) {
		printf("Usage: sort [-n] [-r] [-f]\n");
		return 1;
	} else if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		knr_qsort((void**) lineptr, 0, nlines-1, 
			(int (*)(void*,void*))(numeric ? numcmp : my_strcmp));
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000		/* max lenth of any input line */

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
			line[len-1] = '\0';	/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	if (reverse)
		lineptr += nlines;
	while (nlines-- > 0)
		printf("%s\n", reverse ? *--lineptr : *lineptr++);
}

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
	int c;
	char *p = s;

	while (--lim > 0 && (c = getchar()) != EOF && c!= '\n')
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

/* qsort: sort v[left]...v[right] into increasing order */
void knr_qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;

	void swap(void *v[], int, int);

	if (left >= right)		/* do nothing if array contains */
		return;				/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	knr_qsort(v, left, last-1, comp);
	knr_qsort(v, last+1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#include <ctype.h>

/* my_strcmp: compare s1 and s2 lexicographically */
int my_strcmp(const char *s1, const char *s2)
{
	for (; fold ? toupper(*s1) == toupper(*s2) : *s1 == *s2; s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
