#include <stdio.h>
#include <stdlib.h>

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || value == NULL) {
        return -1;
    }

    if (overwrite || getenv(name) == NULL) {
        return setenv(name, value, 1);
    }

    return 0;
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
