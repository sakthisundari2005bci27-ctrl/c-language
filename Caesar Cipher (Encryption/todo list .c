#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addTask() {
    char task[100];
    printf("Enter task description: ");
    getchar(); // Clear buffer
    fgets(task, sizeof(task), stdin);
    
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) return;
    fprintf(file, "- %s", task);
    fclose(file);
    printf("Task added successfully!\n");
}

void viewTasks() {
    char task[100];
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Your list is currently empty.\n");
        return;
    }
    printf("\n--- YOUR TASKS ---\n");
    while (fgets(task, sizeof(task), file)) {
        printf("%s", task);
    }
    fclose(file);
}

int main() {
    int choice;
    while(1) {
        printf("\n1. Add Task\n2. View Tasks\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) addTask();
        else if (choice == 2) viewTasks();
        else if (choice == 3) exit(0);
        else printf("Invalid choice!\n");
    }
    return 0;
}
