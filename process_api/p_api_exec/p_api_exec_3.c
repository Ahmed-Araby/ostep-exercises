/**
 * use execvp
 * execute binary file from the PATH env variable paths
 * 
 * this method 
 * will search in PATH
 * also it handle absolute path
 * can not handle relative paths
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *args[])
{
    char *file = "../out/p_api_1.o";    // exceve deals with PATHS only
    char *argv[] = {"p_api_1.o", NULL}; // if this is not null terminated the call will fail
    int ret = execvp(file, argv);
    printf("p_api_exec_3.c \n");
    perror(&errno);
    return 0;
}
