/**
 * fork more than 1 child process 
 * wait for specifc one child process
 * */

#include <unistd.h>   // provide access to the POSIX API
#include <sys/wait.h> // wait and its sibilings
#include <stdio.h>    // std input  / out sys calls
#include <stdlib.h>   // provide declearation for exist method

void child_intro()
{
    printf("Hi Iam child process, pid = %d \n", getpid());
    exit(0); // exit normally
}

int giveBirth()
{
    int cpid = fork();
    if (cpid == 0)
    {
        child_intro();
    }
    else if (cpid > 0)
    {
        return cpid;
    }
    else
    {
        exit(1); // exit with failure (not normally)
    }

    exit(1); // undefined state (just eliminate the compiler warnning)
}
int main(int argc, char *argv[])
{
    int cpid1 = giveBirth();
    int cpid2 = giveBirth();
    sleep(3);

    /**
    * at this point all child process has been terminated 
    * which make them in waitable state and wait() function will 
    * wait for a child to terminate or return directly if there is a waitable process 
    * */
    // int tcpid = wait(NULL);
    int tcpid = waitpid(cpid2, NULL, 0); // 0 for options mean !!???
    printf("child processes ids are: %d, %d \n", cpid1, cpid2);
    printf("terminated child process id : %d \n", tcpid);
    return 0;
}