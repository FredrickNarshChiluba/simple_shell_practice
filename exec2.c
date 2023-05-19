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

    // Execute /bin/ls -l
    execve("/bin/ls", argv, envp);

    // execve will only return if there is an error
    perror("execve");
    return 1;
}

