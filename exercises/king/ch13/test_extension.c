#include <stdio.h>



/* checks a filename's extension */

#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension)
{
    char *p, *q;
    p = file_name;
    q = extension;

    while (*p && *p++ != '.')
        ;
    for (; toupper(*p) == toupper(*q); p++, q++) {
        if (*p == '\0')
            return true;
    }
    return false;
}

int main(void)
{
    char file_name[100], extension[10];

    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter extension: ");
    scanf("%s", extension);

    printf("Result: %s\n", test_extension(file_name, extension) ? "true" : "false");
}
