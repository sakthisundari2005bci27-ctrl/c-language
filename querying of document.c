#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    char**** document = NULL;
    int p_count = 0, s_count = 0, w_count = 0;

    // Use delimiters to split text
    char* p_ptr = strtok(text, "\n");
    while (p_ptr != NULL) {
        document = realloc(document, (++p_count) * sizeof(char***));
        document[p_count-1] = NULL;
        
        char* s_ptr = strtok(p_ptr, ".");
        s_count = 0;
        while (s_ptr != NULL) {
            document[p_count-1] = realloc(document[p_count-1], (++s_count) * sizeof(char**));
            document[p_count-1][s_count-1] = NULL;
            
            char* w_ptr = strtok(s_ptr, " ");
            w_count = 0;
            while (w_ptr != NULL) {
                document[p_count-1][s_count-1] = realloc(document[p_count-1][s_count-1], (++w_count) * sizeof(char*));
                document[p_count-1][s_count-1][w_count-1] = w_ptr; // Store word pointer
                w_ptr = strtok(NULL, " ");
            }
            s_ptr = strtok(NULL, ".");
        }
        // Note: The logic above needs care with \n vs .
        // In a real implementation, you'd handle the 'text' pointer carefully
        p_ptr = strtok(NULL, "\n");
    }
    return document;
}
