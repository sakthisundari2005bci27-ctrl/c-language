#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // The size of the grid will always be (2*n - 1)
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Find the minimum distance to any of the 4 edges
            int top = i;
            int bottom = size - 1 - i;
            int left = j;
            int right = size - 1 - j;

            // The value is n minus the minimum distance to an edge
            int min = top;
            if (bottom < min) min = bottom;
            if (left < min) min = left;
            if (right < min) min = right;

            printf("%d ", n - min);
        }
        printf("\n");
    }

    return 0;
}
