#include <stdio.h>

void tokenize(char *str, char delim) {
    while (*str) {
        if (*str == delim) printf("\n");
        else printf("%c", *str);
        str++;
    }
}

int main() {
    char msg[] = "GitHub,C,Programming,Portfolio";
    tokenize(msg, ',');
    return 0;
}
