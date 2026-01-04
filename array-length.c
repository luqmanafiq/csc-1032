#include <stdio.h>

/*
 * Note the difference between sizeof(arr) in printlen
 * compared to main and, therefore, the difference in calculated
 * length. This is because sizeof(arr) in printlen returns
 * the size of an address on this architecture (e.g. 8 bytes
 * on a 64 bit machine with 64 bit addresses). It is not the size
 * of the array but the size of the address of the array. The
 * address size is fixed for a given architecturre. It is the
 * number of bits needed to represent an address (which is a
 * fixed sized integer value).
 * If the address size is 8 and int size is 2 on this
 * architecture, the length calculation in printlen will be 2.
 * However, as can be seen in main, and as calculated in main,
 * the array length is actually 5. The calculation of array length
 * as sizeof(arr) / sizeof(int) is clearly incorrect in printlen.
 * The problem is the attempt to use sizeof to calculate the size
 * of an array from its address. sizeof(arr) only gives the size of
 * the array when it is called in the same scope as the array
 * declaration (e.g. in main in this case).
 * The solution to this problem in C is for functions to have
 * a parameter for the length of an array in addition to the array
 * itself. For example, printlen should be amended to:
 *     void printlen(int arr[], int arr_len)
 * and sizeof(arr) / sizeof(int) should not be used to calculate
 * array length in printlen.
 */
void printlen(int arr[]) {
  printf("Printing sizes and array length in printlen\n");
  printf("printlen sizeof(arr) bytes: %lu\n", sizeof(arr));
  printf("printlen sizeof(int) bytes: %lu\n", sizeof(int));

  size_t len = sizeof(arr) / sizeof(int);
  printf("printlen len: %lu elements not 5??\n", len);
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};

  printf("Printing sizes and array length in main\n");
  printf("main sizeof(arr): %lu bytes\n", sizeof(arr));
  printf("main sizeof(int): %lu bytes\n", sizeof(int));

  size_t len = sizeof(arr) / sizeof(int);
  printf("main len: %lu elements\n", len);

  printlen(arr);
  return 0;
}
