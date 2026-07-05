int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int *p, sum;

    for (p = *a, sum = 0; p < *a + n * LEN; p++)
        sum += *p;

    return sum;
}
