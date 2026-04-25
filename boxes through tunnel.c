#include <stdio.h>

/**
* Define a structure to represent the box
*/
struct box {
    int length, width, height;
};

/**
* Calculate the volume of a box
*/
int get_volume(struct box b) {
    return b.length * b.width * b.height;
}

/**
* Check if a box can pass through the tunnel
*/
int is_lower_than_max_height(struct box b) {
    if (b.height < 41) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Use a struct to store current box data
    struct box b;

    for (int i = 0; i < n; i++) {
        // Read length, width, and height
        scanf("%d %d %d", &b.length, &b.width, &b.height);

        // Check the condition and print the volume
        if (is_lower_than_max_height(b)) {
            printf("%d\n", get_volume(b));
        }
    }

    return 0;
}
