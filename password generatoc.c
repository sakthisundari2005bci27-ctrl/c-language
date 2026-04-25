#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "!@#$%^&*";
    printf("Generated Password: ");
    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        printf("%c", charset[index]);
    }
    printf("\n");
}

int main() {
    int len;
    srand(time(0));
    printf("Enter desired password length: ");
    scanf("%d", &len);
    generatePassword(len);
    return 0;
}
