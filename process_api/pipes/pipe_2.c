#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>   // exit function
#include <sys/wait.h> // for wait() method

int main(int argc, char *argv[])
{
    printf("pipe program, pipe_2.c \n");

    int pipe_fd[2]; // have garpage
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
        char buf;
        close(pipe_fd[1]); // as this point to the same open end of the file we need to close it also, other wise the read will be blocked.
        while (read(pipe_fd[0], &buf, 1) > 0)
        {
            printf("%c", buf);
            fflush(stdout);
        }
        // close(pipe_fd[0]);

        printf("\n %d - %d \n", pipe_fd[0], pipe_fd[1]);
        fflush(stdout);
    }
    else
    {
        // parent process
        char *message = "abaaaaaaaaaaaaaaaaaaaaa"; // this will implictly put null char at the end
        // close(pipe_fd[0]);
        int bytesCnt = write(pipe_fd[1], message, strlen(message));
        close(pipe_fd[1]); // if this is not closed, child process that reads from the pipe will hang waiting for more data
        printf("parent finished writing \n");
        wait(NULL);
    }
    return 0;
}