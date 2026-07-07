/* replaces occurrences of "foo" in string with "xxx" */
void censor(char *s)
{
    char *p;

    for (p = s; *p; p++)
        if (*p == 'f' && *(p+1) == 'o' && *(p+2) == 'o')
            *p = *(p+1) = *(p+2) = 'x';
}
