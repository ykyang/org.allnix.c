#include <stdio.h>
#include <time.h>

// clang -Wall greet03_time.c -o greetings
int main(int argc, char *argv[]) {
    time_t now;
    struct tm *clock;  // man localtime
    int hour;

    time(&now); // man time.2
    clock = localtime(&now);
    hour = clock->tm_hour;

    printf("Good ");
    if (hour < 12) {
        printf("morning");
    } else if (hour < 17) {
        printf("afternoon");
    } else {
        printf("evening");
    }

    if (argc > 1) {
        printf(", %s", argv[1]);
    }
    putchar('\n');

    printf("It's %s", ctime(&now));

    return(0);
}