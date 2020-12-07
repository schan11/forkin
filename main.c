// Serena Chan
// Systems Level Programming
// 12/07/2020
// Work 15: Forkin' Around

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int f1, f2, status;
    
    f1 = fork(); // fork off first child process
    if (f1){
        printf("Parent PPID: %d\n", getpid());
        f2 = fork(); // fork off second child process
        if (f2 == 0){
            printf("Second child PPID: %d\n", getpid()); // print pid at start
            int sleept = rand() % 9 + 2; // sleep for a random number of seconds in the range [2, 10]
            sleep(sleept);
            printf("Second child has finished the process\n");
        }
        wait(&status); // after the fork, wait for any child to finish
        printf("Completed Child PID: %d\n", wait(&status));
        printf("Seconds Asleep: %d\n", WEXITSTATUS(status));
        printf("Parent has finished the process\n");
    }
    
    else{
        printf("First child PPID: %d\n", getpid());
        int sleept = rand() % 9 + 2;
        sleep(sleept);
        printf("Second child has finished the process\n");
    }
    
    
}


