#include <stdio.h>
#include <time.h>

int main() {
    time_t start, end;
    printf("Press Enter to start the timer...");
    getchar();
    start = time(NULL);

    printf("Timer running... Press Enter to stop.");
    getchar();
    end = time(NULL);

    printf("Elapsed time: %.f seconds\n", difftime(end, start));
    return 0;
}
