/**
 * this process will get signaled from terminal
 * and we will analyze how it will respond.
 * 
 * stop and resume a process from linux shell
 * https://ostechnix.com/suspend-process-resume-later-linux/#:~:text=First%2C%20find%20the%20pid%20of,kill%20%2DCONT%20.
 * 
 * why after resume the process do not response to ctrl + C interuption !??
 * why "ps" do not show this process in terminal while running !!???
 * */

#include <unistd.h>  // provide access to the POSIX API
#include <stdio.h>   // std input  / out sys calls
#include <stdlib.h>  // provide declearation for exist method
#include <stdbool.h> // marcos for true and false

int main(int argc, char *argv[])
{
    printf("pid = %d \n", getpid());
    for (int i = 0;; i++)
    {
        printf("counter = %d \n", i);
        sleep(2);
    }

    return 0;
}