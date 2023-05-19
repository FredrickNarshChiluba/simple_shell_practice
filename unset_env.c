#include <stdio.h>
#include <stdlib.h>

int _unsetenv(const char *name) {
    if (name == NULL) {
        return -1;
    }

    return unsetenv(name);
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
