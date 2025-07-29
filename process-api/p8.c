/*
Write a program that creates two children, and connects the stan-
dard output of one to the standard input of the other, using the
pipe() system call.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int pipefd[2];

    if(pipe(pipefd) == -1){
        fprintf(stderr, "Error when creating a pipe; \n");
        exit(1);        
    }

    int child1 = fork();
    if(child1 == -1){
        fprintf(stderr, "Error when using fork()\n");
        exit(1);
    }

    if(child1 == 0){
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        write(STDOUT_FILENO, "hello", 6);

        exit(1);
    }

    int child2 = fork();
    if(child2 == 0){
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        char buf[7];
        read(STDIN_FILENO, buf, 6);
        buf[6] = '\0';

        printf("%s\n", buf);
        exit(1);
    }

    wait(&child1);
    wait(&child2);
    
    return 0;
}