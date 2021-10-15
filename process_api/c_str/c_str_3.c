/*
change the value of individual char in a string
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h> // for malloc

int main(int argc, char *argv[])
{
    // string in the code segment (image).
    char *str = "abc";
    /* 
        this should be constant, yep it is and "abc" is
        stored in the code segment and str point to its address in the code segment,
        and code segement is read only which mean we can not change it.

        solution is to put the string into the heap or the stack
    */
    // str[0] = 's';
    printf("str = %s \n", str);

    // string into the stack
    char stack_str[] = "abc\0"; // we should add the null char manually
    stack_str[0] = 's';
    printf("stack str = %s \n", stack_str);

    // string into the heap
    char *heap_str = malloc(4);
    /**
     * what will happen here
     * is that the pointer heap_str is no longer point at the heap memory 
     * instead we are pointing at the the code segment which is constant
     * also we lost reference to the heap allocated memory which mean we have 
     * memory leak
     * 
     * */
    // heap_str = "abc\0";

    // write way to do it
    strcpy(heap_str, "abc"); // secodn argument is constant from the code segment memory
    heap_str[0] = 'S';
    printf("heap str = %s \n ", heap_str);
    return 0;
}