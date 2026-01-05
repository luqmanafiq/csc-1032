/* 
 * include the standard I/O library to use the printf function
 * See: http://man7.org/linux/man-pages/man3/printf.3.html
 */
#include <stdio.h> 

/* 
 * NOTE: in repl.it fork this project to get your own copy.
 */

/*
 * Every C program has a main function which is the entry point for
 * execution
 * To run this program, press the green run button. 
 * Output will appear in the linux console.
 *
 * To compile and run the program on a linux machine or a Mac, 
 * in a terminal enter the following commands at the shell prompt:
 *     cc helloworld.c
 * assuming the program is in file helloworld.c.
 * Then enter:
 *     ./a.out
 * to run the program.
 */
 int main(void) {
    /* printf prints output to the console */
    printf("Hello World!\n");

    /*
     * the return value from main is a program's exit code
     * (by convention, 0 means success) 
     */
    return 0;
}
