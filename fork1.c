#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;
    pid_t child_pid;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    my_pid = getpid();
    printf("Process ID for either child or parent: %u\n", my_pid);
    printf("My pid is %u\n", my_pid);
    if (child_pid == 0)
    {
	printf("process ID for child: %u\n", my_pid);
        printf("(%u) Nooooooooo!\n", my_pid);
    }
    else
    {
	printf("process ID for parent: %u\n",my_pid);
	printf("process ID for child: %u\n", child_pid);
        printf("(%u) %u, I am your father\n", my_pid, child_pid);
    }
    return (0);
}
