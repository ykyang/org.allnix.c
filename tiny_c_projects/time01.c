#include <stdio.h>
#include <time.h>

// clang -Wall time01.c -o time01
int main() {
    time_t now;

    time(&now);
    printf("The computer thinks it's %ld\n", now);
    printf("%s", ctime(&now));

    return(0);
}