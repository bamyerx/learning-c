/*
 * Exercise 2-9 from K&R: In a two's complement number system, x &= (x-1)
 * deletes the rightmost 1-bit in x. Explain why. Use this observation to write
 * a faster version of bitcount.
 */

/*
 * x - 1 in two's complement always results in the rightmost 1-bit of x being
 * cleared and every subsequent bit being set. Therefore, x &= (x-1) is just
 * x with the rightmost 1-bit cleared. This can be used to write a faster
 * version of bitcount since, instead of iterating for every bit in x, the loop
 * only needs to iterate per 1-bit in x.
 */

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1), b++)
        ;

    return b;
}
