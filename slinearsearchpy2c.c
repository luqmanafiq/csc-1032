#include <stdio.h>

/*
 * This function is a C implementation of the
 * slinearsearchfunction that is defined for Exercise 2 of
 * CSC1032 C programming part 1. See:
 *     https://replit.com/@nickcook/csc1032-search#README.txt
 *
 * Development of this function was covered in the 2nd C
 * lecture on 2 May (see Canvas).
 *
 * The lecture shows how to develop a C program from its Python
 * equivalent. The Pyton program it is translated from is at:
 *     https://replit.com/@nickcook/csc1032-slinearsearchpy
 */
int slinearsearch(int x, int arr[], int n) {
  int last = arr[n - 1];

  arr[n - 1] = x;

  int i = 0;

  while (arr[i] != x) {
    i++;
  }

  arr[n - 1] = last;

  return arr[i] == x ? i : -1;
}

int main(void) {
  int n = 11; // lenght of array
  int arr[] = {1, 0, 2, 10, 20, 9, 5, -1, 3, 4, 8};
  // idx: 0  1  2  3   4   5  6  7   8  9  10

  for (int x = -3; x < 10; x++) {
    int r = slinearsearch(x, arr, n);

    if (r == -1) {
      printf("%d is not in array\n", x);
    } else {
      printf("%d is at index position %d in array\n", x, r);
    }
  }

  return 0;
}
