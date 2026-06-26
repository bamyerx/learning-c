/*
 * Exercise 2-10 from K&R: Rewrite the function lower, which converts uppercase
 * letters to lower case, with a conditional expression instead of if-else.
 */

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
