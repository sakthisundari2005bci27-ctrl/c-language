#include <stdio.h>

int main() {
    float temp, converted;
    int choice;

    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nChoice: ");
    scanf("%d", &choice);

    printf("Enter temperature: ");
    scanf("%f", &temp);

    if (choice == 1) {
        converted = (temp * 9 / 5) + 32;
        printf("%.2f C = %.2f F\n", temp, converted);
    } else {
        converted = (temp - 32) * 5 / 9;
        printf("%.2f F = %.2f C\n", temp, converted);
    }
    return 0;
}
