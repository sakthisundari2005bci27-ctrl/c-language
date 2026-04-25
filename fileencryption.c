#include <stdio.h>
#include <stdlib.h>

void encryptFile(char *fileName, char key) {
    FILE *fp = fopen(fileName, "rb+");
    if (fp == NULL) return;

    int ch;
    long pos;
    while ((ch = fgetc(fp)) != EOF) {
        pos = ftell(fp);
        fseek(fp, pos - 1, SEEK_SET);
        fputc(ch ^ key, fp); // XOR operation
        fseek(fp, pos, SEEK_SET);
    }
    fclose(fp);
}

int main() {
    char name[50], key = 'K'; // Simple key
    printf("Enter filename to encrypt/decrypt: ");
    scanf("%s", name);
    encryptFile(name, key);
    printf("Operation completed using key: %c\n", key);
    return 0;
}
