/*
 * Exercise 2-7 from K&R: Write a function invert(x,p,n) that returns x with the
 * n bits that begin with position p inverted (i.e., 1 changed into 0 and vice
 * versa), leaving the others unchanged.
 */

unsigned invert(unsigned x, int p, int n)
{
    /* a mask with n bits set starting at position p */
    unsigned mask = ~(~0 << n) << (p + 1 - n);

    return x ^ mask;
}
