#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *s;
    s = malloc(1024 * sizeof(char));
    
    // Read the entire line of input
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);

    // strtok(string, delimiter) gets the first token
    char *token = strtok(s, " ");
    
    // Continue getting tokens until there are no more
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " "); // NULL tells it to continue from where it left off
    }
    
    free(s);
    return 0;
}
