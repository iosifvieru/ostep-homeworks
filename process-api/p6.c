/*
Write a slight modification of the previous program, this time us-
ing waitpid() instead of wait(). When would waitpid() be useful?
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
        waitpid(-1, NULL, 0);
        printf("Writing from the parent process. pid: %d\n", pid);
    }

    return 0;
}
