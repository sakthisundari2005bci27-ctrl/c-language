#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    struct Student s;
    printf("Enter Roll No, Name, Marks: ");
    scanf("%d %s %f", &s.rollNo, s.name, &s.marks);
    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Record Saved!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;
    if (fp == NULL) return;
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s.rollNo, s.name, s.marks);
    }
    fclose(fp);
}

int main() {
    int ch;
    while(1) {
        printf("\n1. Add Student\n2. View All\n3. Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 1) addStudent();
        else if (ch == 2) displayStudents();
        else break;
    }
    return 0;
}
