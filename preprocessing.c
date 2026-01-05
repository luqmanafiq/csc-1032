/* 
 * Use this program to demonstrate what happens during
 * preprocessing.
 * 
 * Instructions:
 * 1. Press run and you should see the output:
 *      MY_CONST is: 10
 *      Printing 10 again
 *    On a linux machine or a Mac, use the commands:
 *      cc preprocessing.c
 *    to compile the program (assuming it is in a file
 *    called preprocessing.c).
 *    Then the command:
 *      ./a.out
 *    to run the program.
 * 2. In replit, enter the following command in the 
 *    console on the right:
 *      > clang -P -E main.c
 *    the output is this main.c file after 
 *    preprocessing but before compilation. 
 *    clang is the repl.it C compiler and preprocessor.
 *   
 *    Comments below tell you what to expect.
 *
 *    On a linux machine or a Mac, use the command:
 *      cc -P -E preprocessing.c
 *    to run the preprocessor (assuming the 
 *    program file is called preprocessing.c).
*/

/* 
 * After preprocessing the following line is replaced
 * by the contents of the stdio.h file that contains
 * the declaration of structs, global variables and
 * function prototypes for the standard I/O library.
 */ 
#include <stdio.h>

/* 
 * After preprocessing the following line is deleted and   * wherever the symbol MY_CONST appears in the remaining
 * code, it is replaced by 10.
 */
#define MY_CONST 10

int main(void) {
  /* After preprocessing MY_CONST will be replaced by the      value 10 
   */
  printf("MY_CONST is: %d\n", MY_CONST);
  printf("Printing %d again\n", MY_CONST);
  return 0;
}
