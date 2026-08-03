bool search(const int a[], int n, int key);
int find_largest(int a[], int n);

int temperatures[7][24];

/* 
 * Exercise 14. Write a statement that uses the search function to search
 * the entire temperatures array for the value 32.
 * 
 * Note: *temperatures, temperatures[0], and &temperatures[0][0] are all
 * equivalent as parameters here.
 */
search(*temperatures, 7 * 24, 32);

/*
 * Exercise 15. Write a loop that prints all temperature readings stores in
 * row i of the temperatures array. Use a pointer to visit each element of
 * the row.
 */

int *p;

for (p = temperatures[i]; p < temperatures[i] + 24; p++)
    printf("%d ", *p);

/*
 * Exercise 16. Write a loop that prints the highest temperature in the
 * temperatures array for each day of the week. The loop body should call
 * the find_largest function, passing it one row of the array at a time.
 */

int *(row)[24];

for (row = temperatures; row < temperatures + 7; row++)
    printf("%d ", find_largest(*row, 24));

/*
 * Alternatively, using *p:
 */

for (p = temperatures[0]; p < temperatures[0] + 7 * 24; p += 24)
    printf("%d ", find_largest(p, 24));
