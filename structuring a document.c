#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Structures provided in the problem description
struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;
};

struct paragraph {
    struct sentence* data;
    int sentence_count;
};

struct document {
    struct paragraph* data;
    int paragraph_count;
};

// Helper function to split a string into an array of strings based on a delimiter
char** split(char* text, char delim, int* count) {
    char** result = malloc(sizeof(char*) * 1000); // Max capacity for simplicity
    int i = 0;
    char* temp = strdup(text);
    char* token = strtok(temp, &delim);
    while (token != NULL) {
        result[i++] = strdup(token);
        token = strtok(NULL, &delim);
    }
    *count = i;
    return result;
}

struct document get_document(char* text) {
    struct document doc;
    int p_count;
    // Paragraphs are separated by '\n'
    char** p_strings = split(text, '\n', &p_count);
    doc.paragraph_count = p_count;
    doc.data = malloc(sizeof(struct paragraph) * p_count);

    for (int i = 0; i < p_count; i++) {
        int s_count;
        // Sentences are separated by '.'
        char** s_strings = split(p_strings[i], '.', &s_count);
        doc.data[i].sentence_count = s_count;
        doc.data[i].data = malloc(sizeof(struct sentence) * s_count);

        for (int j = 0; j < s_count; j++) {
            int w_count;
            // Words are separated by ' '
            char** w_strings = split(s_strings[j], ' ', &w_count);
            doc.data[i].data[j].word_count = w_count;
            doc.data[i].data[j].data = malloc(sizeof(struct word) * w_count);

            for (int k = 0; k < w_count; k++) {
                doc.data[i].data[j].data[k].data = w_strings[k];
            }
        }
    }
    return doc;
}

struct paragraph get_paragraph(struct document doc, int k) {
    return doc.data[k - 1];
}

struct sentence get_sentence(struct document doc, int k, int m) {
    return doc.data[k - 1].data[m - 1];
}

struct word get_word(struct document doc, int k, int m, int l) {
    return doc.data[k - 1].data[m - 1].data[l - 1];
}
