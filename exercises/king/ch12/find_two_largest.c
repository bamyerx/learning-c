/* finds the two largest integers in an array */
void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    int *p;

    if (*a > *(a + 1)) {
        *largest = *a;
        *second_largest = *(a + 1);
    } else {
        *largest = *(a + 1);
        *second_largest = *a;
    }
    for (p = a + 2; p < a + n; p++) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest)
            *second_largest = *p;
    }
}
