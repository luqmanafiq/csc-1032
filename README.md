SUMMARY

An exercise to complete a program that uses different ways to search for a 
value in an array.

This README.txt file has the following sections:
    - Using replit
    - Project files
    - What you have to do 
    - Building the project outside replit
    - Further information
    
------------------------------------------------------------------------------
USING REPLIT

This project is available at: https://replit.com/@nickcook/csc1032-search. 
It is also available in the csc1032-cpart1-exercises.zip file on Canvas.

You can fork then run and edit the project in replit.
   
Running the project, runs the main function in main.c and executes
the unit tests of the functions in search.c.

Alternatively, you can download all files and compile and run the project
using a C compiler on your own machine (or on cs-linux.ncl.ac.uk, for example)
- see the section on building the project outside of replit.

------------------------------------------------------------------------------
PROJECT FILES

This project contains the following files:

    search.c        - the implementation of search functions
    search.h        - the declaration of search functions
    test_search.c   - unit tests of functions declared in search.h
                      and implemented in search.c
    test_search.h   - declarations of functions and structures implemented 
                      in test_search.c
    main.c          - the main function
    munit.c         - the unit test library implementation
    munit.h         - the unit test library declarations
    README.txt      - this README file

The only file that you edit is search.c. Do NOT edit any of the other
files.

------------------------------------------------------------------------------
WHAT YOU HAVE TO DO

Your task is to complete the implementation of the following functions in
search.c:

    /* iterative linear search */
    int linearsearch(int x, int arr[], int n);
    /* recursive linear search */
    int rlinearsearch(int x, int arr[], int n, int i);
    /* sentinel linear search */
    int slinearsearch(int x, int arr[], int n);
    /* iterative binary search */
    int binarysearch(int x, int arr[], int n);
    /* recursive binary search */
    int rbinarysearch(int x, int arr[], int li, int hi);

Each function is declared and documented in search.h. Make sure you read
and understand the documentation in search.h BEFORE you attempt to
implement a function.

See the further information for some background on the search algorithms.

You test your functions by running the project, which runs the unit tests.

Press the green Run button to compile and run the project.

If you do this before editing the search.c file you will see that all tests
end with an error.

The output to expect for correct implementation of the functions is similar
to the following:

...........................................................................
/test_search/test_linearsearch       
    testing linearsearch ...
    searching a0 for: 0x 1x 
    searching a1 for: 0x 1 2x 
    searching a2 for: 0x 1x 2x 3x 4x 5 6 7x 
    searching a9 for: 0 1 2 3 4x 5 6x 7 8x 9 10 11 12x 
    searching a10 for: 0 1 2 3 4x 5 6 7 8x 9 10 11 12x 
    searching adup for: 0 1 2 3 4x 5 6 7 8x 9 10 11 12x 
    searching aduplast for: 0 1 2 3 4x 5 6x 7 8x 9 10 11 12x 
[ OK    ] [ 0.00003200 / 0.00003300 CPU ]
/test_search/test_linearsearch_err   
    testing linearsearch error cases ...
[ OK    ] [ 0.00001000 / 0.00001000 CPU ]
/test_search/test_rlinearsearch      
    testing rlinearsearch ...
    searching a0 for: 0x 1x 
    searching a1 for: 0x 1 2x 
    searching a2 for: 0x 1x 2x 3x 4x 5 6 7x 
    searching a9 for: 0 1 2 3 4x 5 6x 7 8x 9 10 11 12x 
    searching a10 for: 0 1 2 3 4x 5 6 7 8x 9 10 11 12x 
    searching adup for: 0 1 2 3 4x 5 6 7 8x 9 10 11 12x 
    searching aduplast for: 0 1 2 3 4x 5 6x 7 8x 9 10 11 12x 
[ OK    ] [ 0.00002800 / 0.00002900 CPU ]
/test_search/test_rlinearsearch_err  
    testing rlinearsearch error cases ...
[ OK    ] [ 0.00000800 / 0.00000700 CPU ]
...
...
10 of 10 (100%) tests successful, 0 (0%) test skipped.
...........................................................................

Note, the seed and CPU runtimes will be different to the above.

If there is an error in a function, the test will tell you the line in the
test_search.c at which the error was detected and there will be a 
diagnostic message that should help you track down the problem that caused
the error.
       
Your aim is to correct your function implementations until there are no test
errors.

------------------------------------------------------------------------------
BUILDING THE PROJECT OUTSIDE REPLIT

You can build the project outside replit. It should compile as is on
any version of linux and on MacOS (which is a POSIX compliant, variant
of BSD Unix).

To compile and run the project, download the csc1032-cpart1-exercises.zip 
archive from Canvas (if you have not already downloaded it). Unzip the file 
and change to the search directory.

Then enter the following command:

    # make run
    
at the command line. 

Alternatively, make the project and then run it as follows:

    # make
    # ./main 

Project files are available in the csc1032-cpart1-exercises.zip archive on
Canvas.

See Makefile for the compilation commands.
------------------------------------------------------------------------------
FURTHER INFORMATION

An iterative linear search (typically using a for loop) starts at the first
index position of an array, compares the value at that position to the value
to search for, and returns the index position if they are the same. If they
are not the same, it increments the index by 1 and compares the value at that
next position, and so on. The search terminates with the current index
position if the value is found. In the worst case, the value is not found (or
it is in the last index position) and the value to search for has to be
compared with every value in the array. This requires N comparisons for an
array of size N. In addition, while iterating through the array, the current
index must be compared with the last index position in the array to ensure the
search does not go beyond the end of the array. This requires another N
comparisons. There are therefore 2N comparisons for worst case iterative
linear search and the algorithm is O(N) with respect to execution time.
That is, execution time is proportionate to N as N grows. See
https://en.wikipedia.org/wiki/Big_O_notation for background on the Big O
classification of algorithms.

In a sentinel linear search, the item at the last index position is stored in
a local variable and replaced in the array by the value to search for. This is
called the sentinel value. The advantage of this approach is that when
iterating through the array (using a while loop) we only have to compare the
value being searched for with the value at each index position. If the value
is in the array then the loop will terminate when it is founds. If it is not,
then the loop will terminate at the final index position because of the
replacement of the last item before looping through the array. This means
that, in the worst case, there are N comparisons for an array of size N while
iterating through the array (as opposed to 2N in the standard linear search).
There is 1 additional comparison to check the case where the iteration
terminated at the sentinel value. This case either means the value being
searched for was not in the original array or the value was at the last index
position of the original array. In the latter case, the sentinel value will be
equal to the value at the last index position stored locally before looping
through the array. This still means the worst case for sentinel linear search
is N+1 comparisons, which is an improvement on 2N comparisons for standard
linear search. For large N, sentinel linear search and standard linear search
are both O(N) algorithms.

Binary search works for arrays where the values in the array can be ordered .
That is, any two values can be compared and one is either less than, greater
than or equal to the other. To perform binary search, the values must be in
ascending order - for any index position i in the array, array[i] <=
array[i+1]. If the array and its values have these properties, then binary
search is a divide and conquer algorithm that repeatedly divides the original
array into subarrays of half the size until the value being searched for is
found (or it is known that it is not in the array). For example, the first
step is to compare the value to search for with the value at the mid-point of
the array. If the value is the same, the algorithm terminates. If the value is
less than the value at the mid-point, then the subsequent search is restricted
to the subarray of values in the bottom half of the array. If the value is
greater than the value at the mid-point, then the subsequent search is
restricted to the subarray of values in the top half of the array. The
algorithm repeats this approach with smaller and smaller subarrays until the
value is found or the array has been completely searched. Binary search is
O(logN) and, therefore, more efficient than linear search provided the array
values are in order.

Recursive versions of algorithms replace the iterative step of a loop with a
recursive call to the search function.

There are many resources on the Web that define different search algorithms 
and compare their properties.

------------------------------------------------------------------------------

