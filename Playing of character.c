#include <stdio.h>

int main() {
    char ch;
    char s[100];
    char sen[100];

    // 1. Read a single character
    scanf("%c", &ch);
    
    // 2. Read a single word (string)
    scanf("%s", s);
    
    // 3. Read the remaining newline so it doesn't break the next scanf
    scanf("\n");
    
    // 4. Read a full sentence until a newline is hit
    scanf("%[^\n]%*c", sen);

    // Printing the outputs
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}
