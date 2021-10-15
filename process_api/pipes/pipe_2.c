#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>   // exit function
#include <sys/wait.h> // for wait() method

int main(int argc, char *argv[])
{
    printf("pipe program, pipe_2.c \n");

    int pipe_fd[2]; // having garpage
    int ps = pipe(pipe_fd);
    if (ps != 0)
    {
        printf("failed to create pipe \n");
        exit(1);
    }

    int cpid = fork();
    if (cpid == -1)
    {
        printf("failed to fork a child process \n");
        exit(1);
    }

    else if (cpid == 0)
    {
        close(pipe_fd[1]); // close writing end of the pipe
        char message;      // point at null
        printf("message is : ");

        while (true)
        {
            int bytesCnt = read(pipe_fd[0], &message, 1); // this should be blocking function call
            if (bytesCnt <= 0)
            {
                printf("\nchild process finished reading \n");
                break;
            }
            else
            {
                printf("%c", message);
            }
        }
        // printf("\n");
    }
    else
    {
        // parent process
        close(pipe_fd[0]);    // I will never read what I wrote
        char *message = "ab"; // this will implictly put null char at the end
        int bytesCnt = write(pipe_fd[1], message, strlen(message));
        if (bytesCnt != strlen(message))
        {
            printf("parent process failed to write the message \n");
            exit(1);
        }

        printf("parent finished writing \n");
        // int wcpid = wait(NULL);
        // if (wcpid == -1)
        // {
        //     printf("failed to wait for the child process \n");
        //     exit(1);
        // }
    }
    return 0;
}