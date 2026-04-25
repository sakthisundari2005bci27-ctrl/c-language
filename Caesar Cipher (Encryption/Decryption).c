#include <stdio.h>
#include <string.h>

// Function to encrypt the text
void encrypt(char* text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        // Handle lowercase
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + key) % 26 + 'a';
        } 
        // Handle uppercase
        else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + key) % 26 + 'A';
        }
    }
}

// Decryption is just shifting backward
void decrypt(char* text, int key) {
    encrypt(text, 26 - (key % 26));
}

int main() {
    char message[100];
    int key, choice;

    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);
    getchar(); // Clear the newline from buffer

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    if (choice == 1) {
        encrypt(message, key);
        printf("Result: %s\n", message);
    } else {
        decrypt(message, key);
        printf("Result: %s\n", message);
    }
    return 0;
}

