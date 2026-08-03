/*
 * Exercise 3-1 from K&R: Out binary search makes two tests inside the loop,
 * when one would suffice (at the price of more tests outside.) Write a version
 * with only one test inside the loop and measure the difference in run-time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(void)
{
    int i, x, v[N], n;
    clock_t t1, t2;

    srand((unsigned) time(NULL));

    for (i = 0; i < N; i++)
        v[i] = i;

    x = rand() % N;
    printf("x = %d\n", x);

    t1 = clock();
    n = binsearch(x, v, N);
    printf("n = %d\n", n);
    t2 = clock();

    printf("Time to run binsearch: %f s\n", (double) (t2 - t1) / CLOCKS_PER_SEC);

    t1 = clock();
    n = binsearch2(x, v, N);
    printf("n = %d\n", n);
    t2 = clock();

    printf("Time to run binsearch2: %f s\n", (double) (t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}

/* the original binsearch function */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

/* binsearch with a single test in the loop */
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (x == v[low]) ? low : -1; 
}
