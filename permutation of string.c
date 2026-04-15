#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to swap two strings
void swap(char **s, int i, int j) {
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

// Helper function to reverse a portion of the array
void reverse(char **s, int start, int end) {
    while (start < end) {
        swap(s, start++, end--);
    }
}

int next_permutation(int n, char **s) {
    // 1. Find the largest index i such that s[i] < s[i+1]
    int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i+1]) >= 0) {
        i--;
    }
    
    // If no such index exists, we are at the last permutation
    if (i < 0) return 0;
    
    // 2. Find the largest index j > i such that s[i] < s[j]
    int j = n - 1;
    while (strcmp(s[i], s[j]) >= 0) {
        j--;
    }
    
    // 3. Swap s[i] and s[j]
    swap(s, i, j);
    
    // 4. Reverse the sequence from s[i+1] to the end
    reverse(s, i + 1, n - 1);
    
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    char **s = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        s[i] = malloc(11 * sizeof(char));
        scanf("%s", s[i]);
    }
    
    // The first permutation is the sorted input itself
    do {
        for (int i = 0; i < n; i++) {
            printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
        }
    } while (next_permutation(n, s));
    
    for (int i = 0; i < n; i++) free(s[i]);
    free(s);
    return 0;
}
