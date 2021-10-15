/**
 * continuously listen for specifc type of event
 * like stop and continue with external signals been sent to the child process
 * we are targeting from the parent process.
 * 
 * shell commands to test
 * kill -STOP "pid"
 * kill -CONT "pid"
 * 
 * results:
 * every Thing went well as expected
 * unlike the p_get_signaled.c process
 * this process responds to keyboard signal interupt (termination) after 
 * stop and cont. 
 * */

#include <unistd.h>   // provide access to the POSIX API
#include <sys/wait.h> // wait and its sibilings
#include <stdio.h>    // std input  / out sys calls
#include <stdlib.h>   // provide declearation for exist method
#include <stdbool.h>  // marcos for true and false

void child_intro()
{
    printf("Hi Iam child process, pid = %d \n", getpid());

    for (int i = 0;; i++)
    {
        // just get ur self into state friendly for signaling from external porcess like (shell).
        printf("child process, pid = %d. counter = %d \n", getpid(), i);
        sleep(2);
    }

    return;
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

    printf("code for stoped process state %d \n", CLD_STOPPED);
    printf("code for continued process state %d \n", CLD_CONTINUED);
    printf("code for killed process state %d \n", CLD_KILLED);
    printf("coide for existed process state %d \n", CLD_EXITED);
    printf("\n\n");

    while (true)
    {
        // continuously monitor the child process
        siginfo_t sigInfo;
        int tcpid = waitid(P_PID, cpid1, &sigInfo, WEXITED | WSTOPPED | WCONTINUED);
        printf("child process id : %d \n", tcpid);
        printf("proess change type %d \n", sigInfo.si_code);
    }

    return 0;
}