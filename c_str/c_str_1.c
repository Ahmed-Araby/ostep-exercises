#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc, char *argv[])
{
    char a = 'a'; // has no length, there is no null character at the end.
    printf("char= %c \n", a);
    return 0;
}