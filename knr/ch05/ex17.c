/*
 * Exercise 5-17 from K&R: Add a field-searching capability, so sorting may be
 * done on fields within lines, each field sorted according to an independent
 * set of options.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000	/* max # lines to be sorted */
#define MAXKEYS  100	/* max # fields allowed */
#define MAXOPTS	 4		/* number of options allowed */

char *lineptr[MAXLINES];		/* pointers to text lines */
int fields[MAXKEYS];			/* fields specified as sort keys */
char opts[MAXKEYS][MAXOPTS+1];	/* options for each field */

int numeric = 0, reverse = 0, fold = 0, directory = 0, nkeys = 0;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void knr_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int compare(const char *, const char *);

/* sort input lines */
int main(int argc, char *argv[])
{
	int c, nlines, nopts;

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
			case 'd':
				directory = 1;
				break;
			case 'k':
				nopts = 0;
				fields[nkeys] = 0;
				while (isdigit(c = *++argv[0]))
					fields[nkeys] = fields[nkeys] * 10 + (c - '0');
				if (fields[nkeys] < 1) {
					printf("sort: field number must be specified\n");
					argc = 0;
					break;
				}
				while (c != '\0' && nopts < MAXOPTS) {
					if (c != 'n' && c != 'r' && c != 'f' && c != 'd')
						goto illegal_option;
					else
						opts[nkeys][nopts++] = c;
					c = *++argv[0];
				}
				if (c != '\0') {
					printf("sort: field sorting argument too long\n");
					argc = 0;
					break;
				}
				opts[nkeys][nopts] = '\0';
				printf("fields[nkeys = %d] = %d\n", nkeys, fields[nkeys]);
				printf("opts[nkeys = %d][nopts = %d] = %s\n", nkeys, nopts, opts[nkeys]);
				nkeys++;
				--argv[0];
				break;
			default:
				illegal_option:
				printf("sort: illegal option %c\n", c);
				argc = 0;
				break;
			}
	if (argc != 0) {
		printf("Usage: sort [-r] [-n|fd] [-k#[r][n|fd]]...\n");
		return 1;
	} else if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		knr_qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(compare));
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
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
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

int my_strcmp(const char *, const char *, int, int);
int numcmp(const char *, const char *);
int get_field(char *, const char *, int);

/* compare s1 and s2 based on fields and options */
int compare(const char *s1, const char *s2)
{
	int i, field, result;
	char field1[MAXLEN], field2[MAXLEN], *p;

	/* if no fields are specified for sorting */
	if (nkeys == 0) {
		result = numeric ? numcmp(s1, s2) : my_strcmp(s1, s2, fold, directory);
		return reverse ? -result : result;
	}
	
	for (i = 0; i < nkeys; i++) {
		/* flags for individual fields */
		int n = numeric, r = reverse, f = fold, d = directory;

		printf("s1 = %s\n", s1);
		printf("s2 = %s\n", s2);
		field = fields[i];
		get_field(field1, s1, field);
		get_field(field2, s2, field);
		printf("field1 = %s\n", field1);
		printf("field2 = %s\n", field2);

		/* set field-specific flags */
		for (p = opts[i]; *p; p++) {
			switch(*p) {
			case 'n': 
				n = 1; break;
			case 'r': 
				r = 1; break;
			case 'f': 
				f = 1; break;
			case 'd': 
				d = 1; break;
			}
		}

		result = n ? numcmp(field1, field2) : my_strcmp(field1, field2, f, d);
		if (result != 0)
			return r ? -result : result;
	}
	/* tie-breaker comparison for field-specified sorts */
	return my_strcmp(s1, s2, 0, 0);
}

/* get_field: find the nth field in s and copy the null-terminated field into t */
/*            if the field is missing, t will contain the empty string */
int get_field(char *t, const char *s, int n)
{
	int i = 0;

	/* skip leading white space */
	while (isspace(*s))
		s++;
	while (i++ < n - 1) {
		/* skip current field */
		while (!isspace(*s) && *s != '\0') {
			s++;
		}
		/* skip white space to get to next field */
		while (isspace(*s))
			s++;
		if (*s == '\0') {
			t[0] = '\0';
			return 0;
		}
	}
	for (i = 0; *s != '\0' && !isspace(*s); i++)
		t[i] = *s++;
	t[i] = '\0';
	
	return i;
}

/* my_strcmp: compare s1 and s2 by character */
int my_strcmp(const char *s1, const char *s2, int f, int d)
{
	int charcmp(char, char, int, int);

	for (; charcmp(*s1, *s2, f, d) == 0; s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return charcmp(*s1, *s2, f, d);
}

/* charcmp: compare c1 and c2 according to global options */
int charcmp(char c1, char c2, int f, int d)
{
	if (f) {
		c1 = toupper(c1);
		c2 = toupper(c2);
	}
	if (d) 
		if ((!isalnum(c1) && c1 != ' ') || (!isalnum(c2) && c2 != ' '))
			return 0;
    return c1 - c2;
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
