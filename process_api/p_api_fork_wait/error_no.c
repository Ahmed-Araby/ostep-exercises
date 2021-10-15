/**
 * this process will wait without having any childs to wait for 
 * then we will check for the errno and symbolic link and error message
 * */

#include <unistd.h>   // provide access to the POSIX API
#include <sys/wait.h> // wait and its sibilings
#include <stdio.h>    // std input  / out sys calls
#include <stdlib.h>   // provide declearation for exist method
#include <stdbool.h>  // marcos for true and false
#include <errno.h>

int main(int argc, char *argv[])
{
    printf("before error, errno = %d \n ", errno); // this variable is defined by the header file error.h
    int pid = wait(NULL);
    printf("child pid = %d \n ", pid);
    printf("after error, errno = %d \n ", errno);   // this is defined in x86_64 linux file (system and architecture specifc), error.h file we inclded will check for the march definition
    printf("ECHILD symbolic value %d \n ", ECHILD); // base generic symbolic file
    char cerrno = (char)errno;                      // what happens here !!???
    if (cerrno == 10)
        printf("yes \n");
    perror(&errno); // how does this function deal with integer value assigned to char
    return 0;
}