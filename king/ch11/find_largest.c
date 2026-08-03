/* returns a pointer to the array's largest element */
int *find_largest(int a[], int n)
{
    int i, *largest;

    largest = &a[0];
    for (i = 1; i < n; i++)
        if (a[i] > *largest)
            largest = &a[i];
    return largest;
}
