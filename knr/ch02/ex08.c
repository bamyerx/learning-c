/*
 * Exercise 2-8 from K&R: Write a function rightrot(x,n) that returns the value
 * of the integer x rotated to the right by n positions.
 */

#define WORDLENGTH 32

unsigned rightrot(unsigned x, int n)
{
    return (x >> n) | (x << (WORDLENGTH - n));
}
