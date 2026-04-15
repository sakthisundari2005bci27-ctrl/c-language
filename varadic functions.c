#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count); // Start access to variable arguments

    for (int i = 0; i < count; i++) {
        total += va_arg(args, int); // Get the next argument of type int
    }

    va_end(args); // Clean up the list
    return total;
}

int min(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int minimum = va_arg(args, int); // Initialize with the first argument

    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val < minimum) {
            minimum = val;
        }
    }

    va_end(args);
    return minimum;
}

int max(int count, ...) {
    va_list args;
    va_start(args, count);
    
    int maximum = va_arg(args, int); // Initialize with the first argument

    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        if (val > maximum) {
            maximum = val;
        }
    }

    va_end(args);
    return maximum;
}
