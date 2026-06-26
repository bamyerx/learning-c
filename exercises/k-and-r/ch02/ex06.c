/*
 * Exercise 2-6 from K&R: Write a function setbits(x,p,n,y) that returns x with
 * the n bits that begin at position p set to the rightmost n bits of y, leaving
 * the other bits unchanged.
 */

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /* the rightmost n bits of y, leftshifted to start at position p */
    unsigned ybits = (y & ~(~0 << n)) << (p + 1 - n);

    /* a mask with n bits set starting at position p */
    unsigned mask = ~(~0 << n) << (p + 1 - n);

    return x & ~mask | ybits;
}
