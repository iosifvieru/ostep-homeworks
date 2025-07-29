/* 
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to some-
thing (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int x = 100;

    /* up until this point both processes share the same memory */
    int pid = fork();
    if(pid < 0){
        fprintf(stderr, "Error when calling fork().");
        exit(1);
    }

    /* child process */
    if(pid == 0){
        /* x should print 100 */
        printf("child process: (pid %d), value of x is: %d\n", (int)getpid(), x);

        /* the value of x is changed only in the child process. */
        x = rand() % 100;
    } else {
        /* parent process */
        printf("parent process: (pid %d), value of x is: %d\n", (int)getpid(), x);
    }

    /* 
        in the child process the value of x will be a rand value from 1-100 
        in the parent process the value of x will be 100.
    */
    printf("x: %d\n", x);
    return 0;
}