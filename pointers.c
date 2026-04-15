#include <stdio.h>
#include <stdlib.h> // Required for the abs() function

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);
    
    // Update the values at the memory addresses
    *a = sum;
    *b = diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    // Taking input
    if (scanf("%d %d", &a, &b) == 2) {
        update(pa, pb);
        printf("%d\n%d", a, b);
    }

    return 0;
}
