/**
 * wait for child termination
 * check for the child status on termination 
 * */

#include <unistd.h>   // provide access to the POSIX API
#include <sys/wait.h> // wait and its sibilings
#include <stdio.h>    // std input  / out sys calls

int main(int argc, char *argv[])
{
    int pid = fork();
    if (pid == 0)
    {
        // child
        printf("I am child process, pid = %d \n", getpid());
    }
    else if (pid > 0)
    {
        // parent
        printf("iam parent, pid = %d. will wait for child termination cpid=%d \n", getpid(), pid);
        int state_loc;
        int childPId = wait(&state_loc);
        printf("child procss cpid = %d. child state : %d \n", childPId, state_loc);
        printf("child process terminated normally? %s \n", WIFEXITED(state_loc) == 1 ? "YES" : "NO");
    }
    else
    {
        // failure case
        printf("failed to create child process \n");
    }

    return 0;
}