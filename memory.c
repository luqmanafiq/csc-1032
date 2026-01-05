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
void printchar(char* name, char* pc) {
    char* fmt = name[0] == 'p'  ? "*%s%-2s '%c'%s %3u; %s%-4s %p\n" 
                                : "%s%-4s '%c'%s %3u; &%s%-4s %p\n";
    char* sep = *pc ? "," : ", ";
   
    printf(fmt, name, ":", *pc, sep, (unsigned char) *pc, 
            name, ":", pc);
}

/* printelem function takes the name of an array, the address of the 
 * char array and the index position of an element in the array and 
 * uses the printf function to output the same information as 
 * printchar in a consistent format.
 */
void printelem(char* aname, char arr[], int i) {
    char* sep = arr[i] ? "," : ", ";
    
    printf("%s[%d]: '%c'%s %3u; &%s[%d]: %p\n", 
            aname, i, arr[i], sep, (unsigned char) arr[i], 
            aname, i, &arr[i]);
}

char gc = 'g'; // global - in data area

int main(int argc, char** argv) {
    char s[] = {'h', 'e', 'l', 'l', 'o'};

    char c = 'a';
    printchar("c", &c);
    char d = 'b';
    printchar("d", &d);
    
    // output addresses of main, printelem and printchar functions
    printf("&main:      %p\n", &main);
    printf("&printelem: %p\n", &printelem);
    printf("&printchar: %p\n", &printchar);
    
    char t[] = {'g', 'o'};

    /* starting from last element of array s,
     * iterate through memory byte by byte to find
     * first occurrence of byte with value 0
     */
    char* pc = &s[4]; // assign address of last element to pointer pc

    // output values and addresses until reach byte with value 0
    while (*pc) {
        printchar("pc", pc);
        pc = pc + 1; // increment pointer to address of next byte
    }

    // output value and address of 0 byte found
    printchar("pc", pc);

    // terminate s and t at the last element of each array
    s[4] = '\0';
    t[1] = '\0';

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    /* s and t are synonyms for the addresses of the
     * arrays s and t
     * s, &s and &s[0] (address of first element)
     * have the same value when output as pointer values (%p)
     * and similarly for t
     */
    printf("s: %p, &s: %p, &s[0]: %p\n", s, &s, &s[0]);
    printf("t: %p, &t: %p, &t[0]: %p\n", t, &t, &t[0]);

    char* ps = s;           // assign the address of array s to pointer ps
    printf("ps: %p\n", ps); // the value of ps is the address of s

    /* output the value and address of each element of s
     * and output the values pointed to by ps, incrementing
     * the pointer value on each iteration of the loop
     */
    for (int i = 0; i < 5; i++) {
        printelem("s", s, i);
        printchar("ps", ps);
        ps = ps + 1; // increment the pointer value
    }

    /* output the value and address of each element of t
     */
    for (int i = 0; i < 2; i++) {
        printelem("t", t, i);
    }
    
    int ai[] = {1, 2, 3}; // declare array of 3 ints
    int* pai = ai;        // assign the address of array ai to pointer pai
    printf("sizeof(int): %lu\n", sizeof(int)); // output the size of an int

    /* output the value and address of each element of ai
     * and output the values pointed to be pai, incrementing
     * the pointer value on each iteration of the loop
     */
    for (int i = 0; i < 3; i++) {
        printf("ai[%d]: %d; &ai[%d]: %p\n", i, ai[i], i, &ai[i]);
        printf("*pai:  %d; pai:    %p\n", *pai, pai);
        pai = pai + 1; // increment the pointer value
    }

    static char sc = 's'; // declared static - in data area
    printf("sc:    '%c', %u; &sc: %p\n", sc, sc, &sc);
    // global variable gc is also in data area
    printf("gc:    '%c', %u; &gc: %p\n", gc, gc, &gc);
    
    // dynamically allocated objects are on heap
    char* dc = (char*) malloc(sizeof(char)); // dynamic allocation
    *dc = 'x';  // assign value at memory location
    printf("*dc:   '%c', %u; dc:  %p\n", *dc, *dc, dc);

    free(dc);   // must always free after finished with dynamic allocation

    return 0;
}
