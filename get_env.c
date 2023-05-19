#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *path = getenv("PATH");
    if (path != NULL) {
        printf("The value of PATH is: %s\n", path);
    } else {
        printf("PATH environment variable not found\n");
    }

    return 0;
}
