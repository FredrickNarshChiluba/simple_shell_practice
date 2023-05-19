#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name) {
    extern char **environ;
    size_t name_length = strlen(name);

    for (char **env = environ; *env != NULL; ++env) {
        if (strncmp(*env, name, name_length) == 0 && (*env)[name_length] == '=') {
            return &(*env)[name_length + 1];
        }
    }

    return NULL;
}

int main(void) {
    const char *path = _getenv("PATH");
    if (path != NULL) {
        printf("The value of PATH is: %s\n", path);
    } else {
        printf("PATH environment variable not found\n");
    }

    return 0;
}
