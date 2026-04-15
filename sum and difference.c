#include <stdio.h>

int main() {
    int n, m;
    float a, b;

    // Read two integers from the first line
    scanf("%d %d", &n, &m);
    
    // Read two floats from the second line
    scanf("%f %f", &a, &b);

    // Print integer sum and difference
    printf("%d %d\n", n + m, n - m);
    
    // Print float sum and difference rounded to 1 decimal place
    // %.1f ensures only one digit after the decimal point
    printf("%.1f %.1f\n", a + b, a - b);

    return 0;
}
