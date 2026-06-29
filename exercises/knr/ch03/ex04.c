/*
 * Exercise 3-4 from K&R: In a two's complement number representation, our
 * version of itoa does not handle the largest negative number, that is, the
 * value of n equal to -(2^(wordsize-1)). Explain why not. Modify it to print 
 * that value correctly, regardless of the machine on which it runs.
 */

/*
 * Original itoa:
 * void itoa(int n, char s[])
 * {
 *      int i, sign;
 *
 *      if ((sign = n) < 0)
 *          n = -n;
 *      i = 0;
 *      do {
 *          s[i++] = n % 10 + '0';
 *      } while ((n /= 10) > 0);
 *      if (sign < 0)
 *          s[i++] = '-';
 *      s[i] = '\0';
 *      reverse(s);
 * }
 *
 * This version of itoa cannot handle the largest negative number because it 
 * converts any negative number to a positive number. The largest positive
 * number in a two's complement representation is 2^(wordsize-1) - 1, which is
 * too small too store the largest negative number, whose magnitude is larger
 * by one.
 */

void itoa(int n, char s[])
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
    s[i] = '\0';
    reverse(s);
}
