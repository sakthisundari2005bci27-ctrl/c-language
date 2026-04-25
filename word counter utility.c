#include <stdio.h>

int main() {
    FILE *fp = fopen("test.txt", "r");
    char ch;
    int characters = 0, words = 0, lines = 0;

    if (fp == NULL) return 0;

    while ((ch = fgetc(fp)) != EOF) {
        characters++;
        if (ch == '\n') lines++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') words++;
    }
    
    printf("Lines: %d\nWords: %d\nChars: %d\n", lines, words, characters);
    fclose(fp);
    return 0;
}
