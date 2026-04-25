#include <stdio.h>

int main() {
    int choice;
    float val;
    printf("1. KG to Lbs\n2. Meters to Feet\nChoice: ");
    scanf("%d", &choice);
    printf("Enter value: ");
    scanf("%f", &val);

    if (choice == 1) printf("%.2f KG = %.2f Lbs", val, val * 2.204);
    else printf("%.2f M = %.2f Ft", val, val * 3.28);
    
    return 0;
}
