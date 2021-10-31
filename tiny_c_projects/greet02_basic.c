#include <stdio.h>

// clang -Wall greet02_basic.c -o greetings
int main(int argc, char *argv[]) {
    if (argc < 2) {
        puts("Hello, you handsome beast!");
    } else {
        printf("Hello, %s!\n", argv[1]);
    }

    return(0);
}