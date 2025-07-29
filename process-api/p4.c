/*
Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including execl(), execle(), execlp(),
execv(), execvp(), and execvP(). Why do you think there
are so many variants of the same basic call?
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]){
    int pid = fork();
    if(pid == -1){
        fprintf(stderr, "Error when using fork().\n");
        exit(1);
    }
    /* child process */
    if(pid == 0){
        char* args[1];
        args[0] = "/bin/ls";
        args[1] = NULL;

        execvp(args[0], args);
    } else {
        printf("Parent process.\n");
    }

    return 0;
}