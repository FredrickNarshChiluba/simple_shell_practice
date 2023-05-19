#include <stdio.h>
#include <unistd.h>

extern char **environ; // Declare the environ variable

int main(void) {
    char *args[] = {"/bin/ls", "-l", "/tmp", NULL};

    execve(args[0], args, environ);

    // If execve returns, it means an error occurred
    perror("execve");
    return 1;
}
