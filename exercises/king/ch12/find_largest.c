/* returns a pointer to the array's largest element */
int *find_largest(int a[], int n)
{
    int *p, *largest;

    largest = a;
    for (p = a; p < a + n; p++)
        if (*p  > *largest)
            largest = p;
    return largest;
}
