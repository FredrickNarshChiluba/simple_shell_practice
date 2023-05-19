#include <stdio.h>

int main(int argc, char* argv[]) {
    int i;

    printf("Number of command line arguments: %d\n", argc);
    printf("Command line arguments:\n");

    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }

    return 0;
}
