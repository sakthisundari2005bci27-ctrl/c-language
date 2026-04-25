#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books on each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 */
int** total_number_of_pages;

int main() {
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    // Initialize the arrays for the given number of shelves
    total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = NULL; // Initially, no books on shelves
    }

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type;
        scanf("%d", &type);
        
        if (type == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            // Increment the book count for shelf x
            total_number_of_books[x]++;
            
            // Reallocate memory to accommodate the new book on shelf x
            total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            
            // Add the book with y pages at the end of the shelf
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;

        } else if (type == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    // Clean up memory
    if (total_number_of_books) {
        free(total_number_of_books);
    }
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (total_number_of_pages[i]) {
            free(total_number_of_pages[i]);
        }
    }
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
