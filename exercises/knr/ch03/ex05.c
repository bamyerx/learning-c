/*
 * Exercise 3-5 from K&R: Write the function itob(n,s,b) that converts the
 * integer n into a base b character representation in the string s. In
 * particular, itob(n,s,16) formats s as a hexadecimal integer in s.
 */

/* slightly generalized to allow base 2 to 36 to use letters up to Z */
void itob(int n, char s[], int b)
{
    if (b < 2 || b > 36) {
        s[0] = '\0';
        return;
    }

    int i, sign, digit;
    unsigned m;
    
    m = (sign = n) < 0 ? -1u * n : n;
    i = 0;
    do {
        digit = m % b;
        s[i++] = digit + (digit > 9 ? 'A' - 10 : '0');
    } while ((m /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
