#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

int main(int argc, char *argv[]) {
    // Get the value of the PATH environment variable
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not found.\n");
        return 1;
    }

    // Tokenize the PATH variable using ':' as the delimiter
    char *token = strtok(path, ":");
   if(argc > 0){
    while (token != NULL) {
        // Concatenate the directory path and the filename
        char filepath[MAX_PATH_LENGTH];
        snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", token, argv[1]);

        // Check if the file exists
        if (access(filepath, F_OK) == 0) {
            printf("File found: %s\n", filepath);
            return 0;
        }

        // Move to the next token
        token = strtok(NULL, ":");
    }
   }

    printf("File not found.\n");
    return 0;
}

