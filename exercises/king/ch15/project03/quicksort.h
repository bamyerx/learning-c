#ifndef QUICKSORT_H
#define QUICKSORT_H

/*
 * quicksort: Sorts elements of a[low],...,a[high] in ascending order.
 */
void quicksort(int a[], int low, int high);

/*
 * split: Splits the array a into two partitions such that all elements of the
 *        first partition are less than or equal to a[low] and all elements of
 *        the second partition are greater than a[low]. Returns the partition
 *        index.
 */
int split(int a[], int low, int high);

#endif
