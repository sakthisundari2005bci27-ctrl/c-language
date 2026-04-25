#include <stdio.h>

void toBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) printf("1");
        else printf("0");
        if (i % 8 == 0) printf(" "); // Formatting
    }
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    printf("Binary: ");
    toBinary(num);
    return 0;
}
