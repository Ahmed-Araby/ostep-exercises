/*
    this program will fail because 
    there is no child process to wait for them
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("c program ");
    int ppid = wait(NULL); // will return -1 (failure) because there is no childs to wait for
    printf("\n ppid is : %d \n", ppid);
    return 0;
}