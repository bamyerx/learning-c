/*
 * Exercise 2-2 from K&R: Write a loop equivalent to the for loop above without using && or ||.
 *
 * Original loop:
 *      for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *          s[i] = c;
 */

/* CODE FRAGMENT ONLY */

#define TRUE 1
#define FALSE 0

int loop = TRUE;
while (loop) {
    if (i >= MAXLINE)
        loop = FALSE;
    else if ((c = getchar()) == '\n')
        loop = FALSE;
    else if (c == EOF)
        loop = FALSE;
    else {
        s[i] = c;
        ++i;
    }
}
