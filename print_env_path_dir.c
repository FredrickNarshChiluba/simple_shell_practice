#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPathDirectories() {
    const char *path = getenv("PATH");
    if (path != NULL) {
        char *pathCopy = strdup(path);
        if (pathCopy != NULL) {
            char *directory = strtok(pathCopy, ":");
            while (directory != NULL) {
                printf("%s\n", directory);
                directory = strtok(NULL, ":");
            }
            free(pathCopy);
        }
    }
}

int main(void) {
    printf("Directories in PATH:\n");
    printPathDirectories();

    return 0;
}
