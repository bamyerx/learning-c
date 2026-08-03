/*
 * Exercise 5-5 from K&R: Write versions of the library functions strncpy,
 * strncat, and strncmp, which operate on at most the first n characters of
 * their argument strings. For example, strncpy(s,t,n) copies at most n
 * characters of t to s.
 */

char *strncpy(char *s, char *t, int n)
{
	char *p = s;
	while (n-- && (*p++ = *t++))
		;
	while (n--)
		*p++ = '\0';
	return s;
}

char *strncat(char *s, char *t, int n)
{
	char *p = s;
	for (; *p; p++)
		;
	while (n-- && (*p++ = *t++))
		;
	*p = '\0';
	return s;
}

int strncmp(char *s, char *t, int n)
{
	for (; n--; s++, t++) {
		if (*s != *t)
			return *s - *t;
		if (*s == '\0')
			return 0;
	}
	return 0;
}
