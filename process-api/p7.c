
/*
Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int pid = fork();
    if(pid == -1){
        fprintf(stderr, "Error when using fork.\n");
        exit(1);
    }

    if(pid == 0){
        close(STDOUT_FILENO);

        // int fd = open("p7.output", O_CREAT | O_APPEND | O_WRONLY | O_TRUNC, S_IRWXU);
        // if(fd == -1){
        //     fprintf(stderr, "Error creating the file descriptor.");
        //     exit(1);
        // }

        printf("HELLO FROM CHILD\n");
    } else {
        printf("Hello from parent\n");
    }

    return 0;
}
