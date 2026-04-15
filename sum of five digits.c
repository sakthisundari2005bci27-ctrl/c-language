#include <stdio.h>

int main() {
    int n, sum = 0;
    
    // Take the five-digit integer as input
    scanf("%d", &n);
    
    // Loop until all digits are processed
    while (n > 0) {
        sum += (n % 10); // Get the last digit and add to sum
        n = n / 10;      // Remove the last digit from the number
    }
    
    printf("%d\n", sum);
    
    return 0;
}
