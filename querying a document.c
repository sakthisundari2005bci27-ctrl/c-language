#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper to extract a word and move the pointer forward
char* get_word_str(char** text_ptr) {
    char* start = *text_ptr;
    int len = 0;
    while ((*text_ptr)[len] != ' ' && (*text_ptr)[len] != '.' && (*text_ptr)[len] != '\n' && (*text_ptr)[len] != '\0') {
        len++;
    }
    char* word = malloc(len + 1);
    strncpy(word, start, len);
    word[len] = '\0';
    *text_ptr += len;
    return word;
}

char**** get_document(char* text) {
    char**** doc = malloc(sizeof(char***) * 100); // Max paragraphs
    int p_idx = 0, s_idx = 0, w_idx = 0;
    
    char* curr = text;
    doc[p_idx] = malloc(sizeof(char**) * 100); // Max sentences in p
    doc[p_idx][s_idx] = malloc(sizeof(char*) * 100); // Max words in s

    while (*curr != '\0') {
        if (*curr == ' ') {
            curr++; // Move past space
            w_idx++;
        } else if (*curr == '.') {
            w_idx++;
            s_idx++;
            w_idx = 0;
            curr++; // Move past period
            if (*curr != '\n' && *curr != '\0') {
                doc[p_idx][s_idx] = malloc(sizeof(char*) * 100);
            }
        } else if (*curr == '\n') {
            s_idx++;
            p_idx++;
            s_idx = 0; w_idx = 0;
            curr++; // Move past newline
            doc[p_idx] = malloc(sizeof(char**) * 100);
            doc[p_idx][s_idx] = malloc(sizeof(char*) * 100);
        } else {
            doc[p_idx][s_idx][w_idx] = get_word_str(&curr);
        }
    }
    return doc;
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char** nth_sentence_in_mth_paragraph(char**** document, int m, int n) {
    return document[m-1][n-1];
}

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int n, int m, int k) {
    return document[n-1][m-1][k-1];
}
