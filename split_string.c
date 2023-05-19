#include <stdio.h>
#include <string.h>

/**
 * Split string into words
 */
int main() {
    char str[] = "This is a test string.";
    char *token;

    token = strtok(str, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}
