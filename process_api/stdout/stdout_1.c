/*
* how this output get printed if stdout is line buffered
* resources:
    1- https://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
    
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
    while (1)
    {
        printf("here");
    }
}