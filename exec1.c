#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main() {
    char *const argv[] = { "/bin/ls", "-l", NULL };
    char *const envp[] = { NULL };

    execve("/bin/ls", argv, envp);

    // The code below this line will not be executed if execve is successful.
    // Handle error if execve returns -1.
    perror("execve");
    return 1;
}

