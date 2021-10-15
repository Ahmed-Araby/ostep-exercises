/**
 * use execve
 * deal with absolute PATHS only
 * */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *args[])
{
    char *path = "/bin/ls";                  // exceve deals with PATHS only
    char *argv[] = {"ls", "-l", "-a", NULL}; // if this is not null terminated the call will fail
    char *envp[] = {NULL};
    int ret = execve(path, argv, envp); // if failed will set the errno external variable
    printf("exeve response = %d \n", ret);
    printf("p_api_exec_1.c \n");
    perror(errno);
}