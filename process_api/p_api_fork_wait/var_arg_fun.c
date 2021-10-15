/**
 * implement variable argument function in c, try to think about how to achieve this in assemply
 * we need to read about 
 *
 * va_start
 * va_list
 * va_arg
 * */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdarg.h> // support variable argument (variadic_function), old depricated is (stdarg.h)

int sum(int count, int lastArhDummy, ...) // the 3 dots are called ellipses.
{
    va_list nums;
    va_start(nums, lastArhDummy); // the second argument is reference to the last argument in the function before the ellipses
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += va_arg(nums, int);
    }
    va_end(nums); // clean up, what kind of clean up is this !!??
    return sum;
}

int main(int argc, char *args[])
{

    int res = sum(5, -1, 1, 2, 3, 4, 5);
    printf("res is %d \n", res);
    return 0;
}