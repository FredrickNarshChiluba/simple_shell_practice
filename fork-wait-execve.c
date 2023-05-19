#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int i;
    pid_t child_pid;
    int status;

    for (i = 0; i < 5; i++) {
        child_pid = fork();

        if (child_pid == -1) {
            perror("Error:");
            return (1);
        }

        if (child_pid == 0) {
            printf("Child %d executing ls -l /tmp:\n", i + 1);
	    sleep(3);
            char *const argv[] = { "ls", "-l", "/tmp", NULL };
            char *const envp[] = { NULL };
           if(execve("/bin/ls", argv, envp) == -1){
            perror("Error:");
            exit(1);
	   }
        } else {
            wait(&status);
            printf("Child %d exited\n", i + 1);
        }
    }

    return 0;
}

