#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Lexicographically non-decreasing
int lexicomes_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

// 2. Lexicographically non-increasing
int lexicomes_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

// Helper to count distinct characters
int count_distinct(const char* s) {
    int count = 0;
    int alphabet[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (alphabet[index] == 0) {
            alphabet[index] = 1;
            count++;
        }
    }
    return count;
}

// 3. Sort by number of distinct characters
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int res = count_distinct(a) - count_distinct(b);
    return (res == 0) ? strcmp(a, b) : res;
}

// 4. Sort by length
int sort_by_length(const char* a, const char* b) {
    int res = strlen(a) - strlen(b);
    return (res == 0) ? strcmp(a, b) : res;
}

// Custom Bubble Sort implementation
void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            // If the comparison function returns > 0, we swap the strings
            if (cmp_func(arr[j], arr[j + 1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
