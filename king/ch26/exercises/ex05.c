/*
 * Exercise 5 from Chapter 26 of King: Write the following function:
 *
 *    char *vstrcat(const char *first, ...);
 *
 * All arguments of vstrcat are assumed to be strings, except for the last argu-
 * ment, which must be a null pointer (cast to char * type). The function returns
 * a pointer to a dynamically allocated string containing the concatenation of
 * the arguments. vstrcat should return a null pointer if not enough memory is
 * available.
 */

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *vstrcat(const char *first, ...)
{
	va_list ap;
	size_t len;
	char *s, *temp;

	va_start(ap, first);
	len = strlen(first);
	while ((temp = va_arg(ap, char *)) != NULL)
		len += strlen(temp);
	va_end(ap);

	if ((s = malloc(len + 1)) == NULL)
		return NULL;
	va_start(ap, first);
	strcpy(s, first);
	while ((temp = va_arg(ap, char *)) != NULL)
		strcat(s, temp);
	va_end(ap);

	return s;
}
