/**
 * man(manual) page basic example that illustrate how pipes work
 * 
 * pipe write end will get bytes from the process that send data, 
 * which mean the process writes to this end 
 * 
 * pipe read end will get bytes writen from the other side and the other 
 * process will be able to read from the pipe read end, the process will read byte
 * by byte.  
 * */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buf;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
    create the pipe and assign the file descriptors to 
    the pipefd array [0] and [1] entries
    */
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0)
    {                     /* Child reads from pipe */
        close(pipefd[1]); /* Close unused write end */

        while (read(pipefd[0], &buf, 1) > 0)
            write(STDOUT_FILENO, &buf, 1);

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);
    }
    else
    {                     /* Parent writes argv[1] to pipe */
        close(pipefd[0]); /* Close unused read end, [my comment starts] it closes it own version / copy of the file descriptor not the physical file it self */
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]); /* Reader will see EOF */
        wait(NULL);       /* Wait for child */
        exit(EXIT_SUCCESS);
    }
}