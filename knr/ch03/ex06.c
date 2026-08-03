/*
 * Exercise 3-6 from K&R: Write a version of itoa that accepts three arguments
 * instead of two. The third argument is a minimum field width; the converted 
 * number must be padded with blanks on the left if necessary to make it wide
 * enough.
 */

void itoa(int n, char s[], int min_width)
{
    unsigned m;
    int i, sign;

    m = (sign = n) < 0 ? -1u * n : n;
    i = 0;
    do {
        s[i++] = m % 10 + '0';
    } while ((m /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < min_width)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
