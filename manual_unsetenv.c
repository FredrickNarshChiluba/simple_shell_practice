#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) {
    if (name == NULL || *name == '\0' || strchr(name, '=') != NULL) {
        return -1; // Invalid name
    }

    size_t nameLen = strlen(name);

    // Iterate over the environment variables
    for (char **env = environ; *env != NULL; ++env) {
        if (strncmp(*env, name, nameLen) == 0 && (*env)[nameLen] == '=') {
            // Remove the environment variable by shifting the subsequent pointers
            char **nextEnv = env + 1;
            while (*nextEnv != NULL) {
                *env++ = *nextEnv++;
            }
            *env = NULL;
            return 0; // Variable successfully removed
        }
    }

    return 0; // Variable not found, but no error occurred
}

int main(void) {
    _unsetenv("MY_VARIABLE"); // Remove the environment variable

    // Test retrieving the removed environment variable
    const char *value = getenv("MY_VARIABLE");
    if (value != NULL) {
        printf("MY_VARIABLE: %s\n", value);
    } else {
        printf("MY_VARIABLE not found\n");
    }

    return 0;
}
