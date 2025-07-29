/*
Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    /* this will close the std out file descriptor (value 1) */
    close(STDOUT_FILENO);

    /* this will open a new file descriptor, the lowest number available - 1 in this case; it will override the stdout to p2.output */
    int fd = open("p2.output", O_CREAT | O_APPEND | O_WRONLY | O_TRUNC, S_IRWXU);

    if(fd == -1){
        fprintf(stderr, "Error creating the file descriptor.");
        exit(1);
    }

    int pid = fork();
    if(pid == -1){
        fprintf(stderr, "Erorr when fork().");
        exit(1);
    }

    /* child process */
    if(pid == 0){
        printf("Printing sth in the child process..\n");

        for(int i = 0; i < 5; i++){
            printf("[child]: %d\n", i);
        }
    } else {
        printf("Printing sth in the parent process..\n");

        for(int i = 0; i < 5; i++){
            printf("[parent]: %d\n", i);
        }
    }

    return 0;
}