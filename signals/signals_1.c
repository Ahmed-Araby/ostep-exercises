/**
 * process with id =1 is the init process
 * which is the very first process in unix system
 * 
 * process can not handle kill signals
 * 
 * what I understood is that a handler only block the signal 
 * temporary, then the signal effect get into action after 
 * the handler return, but what happened here is that we got
 * completly blocked the signal and changed the flow of the signal 
 * action, we need to read linux sys programming book 
 * 
 * 
 * slide 
 * http://courses.cms.caltech.edu/cs124/lectures-wi2016/CS124Lec15.pdf
 * 
 * man pages 
 * https://man7.org/linux/man-pages/man2/kill.2.html
 * https://man7.org/linux/man-pages/man2/signal.2.html
 * 
 * signals 
 * https://bash.cyberciti.biz/guide/Sending_signal_to_Processes
 * */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_signal(int sig)
{
    printf("signal = %d \n", sig);
    return;
}

int main(int argc, char *argv[])
{
    signal(SIGIO, handle_signal);
    int x = kill(getpid(), SIGIO);
    printf("kil ret = %d \n", x);
}