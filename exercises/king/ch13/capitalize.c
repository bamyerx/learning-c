#include <ctype.h>

/* capitalizes all letters */
void capitalize(char *s)
{
    char *p;

    for (p = s; *p; p++) {
        *p = toupper(*p);
    }
}
