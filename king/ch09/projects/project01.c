/*
 * Project 1 from Chapter 9 of King: Write a program that asks the user to enter
 * a series of integers (which it stores in an array), then sorts the integers
 * by calling the function selection_sort. When given an array with n elements,
 * selection_sort must do the following:
 *    1. Search the array to find the largest element, then move it up to the
 *       last position in the array.
 *    2. Call itself recursively to sort the first n-1 elements of the array.
 */

#include <stdio.h>

#define N 10

void selection_sort(int a[], int n);

int main(void)
{
   int a[N], i;

   printf("Enter %d integers to be sorted: ", N);
   for (i = 0; i < N; i++)
      scanf("%d", &a[i]);

   selection_sort(a, N);

   printf("In sorted order: ");
   for (i = 0; i < N; i++)
      printf("%d ", a[i]);
   printf("\n");

   return 0;
}

void selection_sort(int a[], int n)
{
   if (n != 0) {
      int i, max, temp;
      for (i = 0, max = 0; i < n; i++)
         if (a[i] > a[max])
            max = i;
      temp = a[n - 1];
      a[n - 1] = a[max];
      a[max] = temp;
      selection_sort(a, n - 1);
   }
}
