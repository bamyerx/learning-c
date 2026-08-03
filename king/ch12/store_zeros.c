/* store zeros in an array */
void store_zeros(int a[], int n)
{
    int *p;

    for (p = a; a < a + n; p++)
        *p = 0;
}
