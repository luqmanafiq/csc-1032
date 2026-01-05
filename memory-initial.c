#include <stdio.h>  // for output
#include <stdlib.h> // for malloc and free

/* printchar function takes the name of a char and the address of the
 * char (a pointer) and uses printf to output in consistent format:
 *    the name of the char
 *    the value at the given address as a char
 *    the value at the given address as its decimal ASCII code
 *    the address of the char (a pointer value)
 *
 * If the name begins with a 'p' then the original variable is
 * assumed to be a pointer to a char, otherwise it is assumed to be
 * a char.
 */
void printchar(char *name, char *pc) {
  char *fmt = name[0] == 'p' ? "*%s%-2s '%c'%s %3u; %s%-4s %p\n"
                             : "%s%-4s '%c'%s %3u; &%s%-4s %p\n";
  char *sep = *pc ? "," : ", ";

  printf(fmt, name, ":", *pc, sep, (unsigned char)*pc, name, ":", pc);
}

/* printelem function takes the name of an array, the address of the
 * char array and the index position of an element in the array and
 * uses the printf function to output the same information as
 * printchar in a consistent format.
 */
void printelem(char *aname, char arr[], int i) {
  char *sep = arr[i] ? "," : ", ";

  printf("%s[%d]: '%c'%s %3u; &%s[%d]: %p\n", aname, i, arr[i], sep,
         (unsigned char)arr[i], aname, i, &arr[i]);
}

int main(int argc, char **argv) {
  char c = 'a';
  printchar("c", &c);
  char d = 'b';
  printchar("d", &d);

  return 0;
}
