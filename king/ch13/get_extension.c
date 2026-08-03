/* stores a filename's extension */

#include <string.h>

void get_extension(const char *file_name, char *extension)
{
    int i = 0;

    while (i < strlen(file_name) && file_name[i++] != '.')
        ;
    if (file_name[i - 1] == '.')
        strcpy(extension, &file_name[i]);
}
