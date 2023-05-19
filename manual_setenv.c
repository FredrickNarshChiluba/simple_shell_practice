#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ; // Declare the environ variable

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || value == NULL) {
        return -1;
    }

    size_t nameLen = strlen(name);
    size_t valueLen = strlen(value);

    // Check if the variable already exists in the environment
    char *existingVariable = getenv(name);
    if (existingVariable != NULL) {
        if (!overwrite) {
            return 0; // Variable already exists and overwrite is not allowed
        }

        // Calculate the length of the new environment entry
        size_t newEntryLen = nameLen + 1 + valueLen + 1;

        // Create the new environment entry
        char *newEntry = (char *)malloc(newEntryLen);
        if (newEntry == NULL) {
            return -1; // Failed to allocate memory
        }

        // Construct the new environment entry
        snprintf(newEntry, newEntryLen, "%s=%s", name, value);

        // Replace the existing environment entry with the new one
        for (char **env = environ; *env != NULL; ++env) {
            if (strncmp(*env, name, nameLen) == 0 && (*env)[nameLen] == '=') {
                *env = newEntry;
                return 0; // Variable successfully replaced
            }
        }

        free(newEntry);
    }

    // Calculate the length of the new environment entry
    size_t newEntryLen = nameLen + 1 + valueLen + 1;

    // Create the new environment entry
    char *newEntry = (char *)malloc(newEntryLen);
    if (newEntry == NULL) {
        return -1; // Failed to allocate memory
    }

    // Construct the new environment entry
    snprintf(newEntry, newEntryLen, "%s=%s", name, value);

    // Find the end of the environment array
    char **envEnd = environ;
    while (*envEnd != NULL) {
        ++envEnd;
    }

    // Allocate memory for the new environment entry and the trailing NULL pointer
    char **newEnv = (char **)realloc(environ, (envEnd - environ + 2) * sizeof(char *));
    if (newEnv == NULL) {
        free(newEntry);
        return -1; // Failed to allocate memory
    }

    // Add the new environment entry and the trailing NULL pointer
    newEnv[envEnd - environ] = newEntry;
    newEnv[envEnd - environ + 1] = NULL;

    environ = newEnv;
    return 0; // Variable successfully added
}

int main(void) {
    _setenv("MY_VARIABLE", "my_value", 1); // Change or add the environment variable

    // Test retrieving the modified environment variable
    const char *value = getenv("MY_VARIABLE");
    if (value != NULL) {
        printf("MY_VARIABLE: %s\n", value);
    } else {
        printf("MY_VARIABLE not found\n");
    }

    return 0;
}
