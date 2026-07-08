/*
 * Project 6 from Chapter 13 of King: Improve the planet.c program of Section
 * 13.7 by having it ignore case when comparing command-line arguments with
 * strings in the planets array.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int compare(const char *, const char *);

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto" };

    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++)
            if (compare(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet \n", argv[i]);
    }

    return 0;
}

int compare(const char *s, const char *t)
{
    for (; toupper(*s) == toupper(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return toupper(*s) - toupper(*t);
}
