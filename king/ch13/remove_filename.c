/* removes the filename from a url */

void remove_filename(char *url)
{
    int i, n;

    for (i = 0, n = 0; url[i] != '\0'; i++)
        if (url[i] == '/')
            n = i;
    url[n] = '\0';
}
