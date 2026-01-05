/* 
 * search.c - the implementation of search functions.
 * 
 * This is the file you edit.
 */
#include <errno.h>
#include "search.h"

/* 
 * See search.h for the specification of this iterative linear search 
 * function.
 *
 * You have to implement this function.
 * Error checking is implemented for you.
 */
int linearsearch(int x, int arr[], int n) { 
    if (!arr || n < 0) {
        errno = EINVAL;
        return -1;
    }
    for (int i = 0; i < n; i++)
      if (arr[i] == x) return i;

    // replace the following line with search of the array
    return -1;
 }
 
/* 
 * See search.h for the specification of this recursive linear search 
 * function.
 *
 * You have to implement this function.
 */
int rlinearsearch(int x, int arr[], int n, int i) { 
  if (!arr || n < 0 || i < 0) {
    errno = EINVAL;
    return -1;
  }
  if (i == n)
    return -1;
  
  if (arr[i] == x)
    return i;
  

  return rlinearsearch(x, arr, n, i + 1);
}


 
/* 
 * See search.h for the specification of this sentinel linear search 
 * function.
 *
 * You have to implement this function.
 */
int slinearsearch(int x, int arr[], int n) {
  if (!arr || n < 0) {
    errno = EINVAL;
    return -1; 
  }
  if (!n) return -1;
  int last = arr[n-1];
  arr[n-1] = x;
  int i = 0;

  while (arr[i] != x)
    i += 1;
  arr[n - 1] = last;
  return arr[i] == x ? i : -1;
}
/* 
 * See search.h for the specification of this iterative binary search 
 * function.
 *
 * You have to implement this function.
 */
int binarysearch(int x, int arr[], int n) {     
    if (!arr || n < 0) {
        errno = EINVAL;
        return -1;
    }
    
    int li = 0;
    int hi = n - 1;
    int mi;
    
    while (li <= hi) {
        mi = (li + hi) / 2;
        
        if (x == arr[mi]) 
            return mi;
        
        if (x < arr[mi])
            hi = mi - 1;
        else
            li = mi + 1;
    }
    
    return -1;
}

/* 
 * See search.h for the specification of this recursive binary search 
 * function.
 *
 * You have to implement this function.
 */
int rbinarysearch(int x, int arr[], int li, int hi) { 
    if (!arr || li < 0) {
        errno = EINVAL;
        return -1;
    }

    if (li > hi)
        return -1;
    
    int mi = (li + hi) / 2;
    
    if (x == arr[mi])
        return mi;
    
    if (x < arr[mi])
        hi = mi - 1;
    else
        li = mi + 1;
        
    return rbinarysearch(x, arr, li, hi);
}
