/*
Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

volatile int child_finished = 0;

void sigchild_handler(int sig) {
    child_finished = 1;
}

int main(int argc, char* argv[]) {
    signal(SIGCHLD, sigchild_handler);

    int pd = fork();
    if(pd == -1){
        fprintf(stderr, "Error when using fork()\n");
        exit(1);
    }

    /* child process */
    if(pd == 0){
        printf("hello");
    } else {
        while(child_finished == 0) {
            /* nop */
        }
        printf("goodbye");
    }
    return 0;
}