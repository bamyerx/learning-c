/*
 * Exercise 5-4 from K&R: Write the function strend(s,t), which returns 1 if the
 * string t occurs at the end of string s, and zero otherwise.
 */

int strend(char *s, char *t)
{
	int n = 0;

	for (; *s; s++)
		;
	for (; *t; t++)
		n++;
	while (n-- >= 0)
		if (*s-- != *t--)
			return 0;
	return 1;
}
