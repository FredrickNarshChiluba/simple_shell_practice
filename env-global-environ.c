#include <stdio.h>
#include <stdlib.h>

extern char **environ; // Declare the environ variable

int main(void) {
    // Iterate over the environment variables
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}
