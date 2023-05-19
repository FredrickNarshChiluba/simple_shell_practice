#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main(void) {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command (or 'exit' to quit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from the end of the command
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("Error:");
            return 1;
        }

        if (child_pid == 0) {
            // Child process
            execl(command, command, NULL);

            // If execl returns, an error occurred
            perror("Error:");
            exit(1);
        } else {
            // Parent process
            int status;
            wait(&status);
        }
    }

    return 0;
}

