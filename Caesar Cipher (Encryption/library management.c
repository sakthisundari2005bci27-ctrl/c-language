#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
};

int main() {
    struct Book library[10];
    int count = 0, choice;

    while(1) {
        printf("\n1. Add Book\n2. View All Books\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            if (count < 10) {
                library[count].id = count + 1;
                printf("Enter Title: "); getchar();
                fgets(library[count].title, 50, stdin);
                printf("Enter Author: ");
                fgets(library[count].author, 50, stdin);
                count++;
            } else printf("Library Full!\n");
        } else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                printf("ID: %d | Title: %s | Author: %s", library[i].id, library[i].title, library[i].author);
            }
        } else if (choice == 3) break;
    }
    return 0;
}
