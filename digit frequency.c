#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1001];
    int counts[10] = {0}; // Initialize all 10 digit counters to zero

    // Read the string input
    scanf("%s", s);

    // Iterate through each character of the string
    for (int i = 0; i < strlen(s); i++) {
        // Check if the character is a digit between '0' and '9'
        if (s[i] >= '0' && s[i] <= '9') {
            // '0' has an ASCII value of 48. 
            // Subtracting '0' from the character gives the integer index.
            counts[s[i] - '0']++;
        }
    }

    // Print the frequencies separated by spaces
    for (int i = 0; i < 10; i++) {
        printf("%d ", counts[i]);
    }

    return 0;
}
