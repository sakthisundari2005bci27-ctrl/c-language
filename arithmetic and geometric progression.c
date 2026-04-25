#include <stdio.h>
#include <math.h>

int main() {
    int a, d, r, n;
    printf("Enter first term, common difference(d), common ratio(r), and number of terms(n): ");
    scanf("%d %d %d %d", &a, &d, &r, &n);

    printf("AP: ");
    for(int i=0; i<n; i++) printf("%d ", a + i*d);
    
    printf("\nGP: ");
    for(int i=0; i<n; i++) printf("%.0f ", a * pow(r, i));

    return 0;
}
