/*
Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int pid = fork();
    if(pid == -1){
        fprintf(stderr, "Error when using fork()\n");
        exit(1);
    }

    if(pid == 0){
        printf("Writing from a child process. %d \n", pid);
    } else {
        wait(NULL);
        printf("Writing from the parent process. pid: %d\n", pid);
    }

    return 0;
}
