#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$:");

    if ((read = getline(&line, &len, stdin)) != -1) {
        printf("%s", line);
    }

    free(line);
    line = NULL;

    return 0;
}
