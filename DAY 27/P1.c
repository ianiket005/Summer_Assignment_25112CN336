#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int age;
    float marks;
};

struct Student students[100];
int count = 0;

void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Age: ");
    scanf("%d", &students[count].age);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student record added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Age: %d | Marks: %.2f\n",
               students[i].roll, students[i].name, students[i].age, students[i].marks);
    }
}

void searchStudent() {
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Record Found: Roll: %d | Name: %s | Age: %d | Marks: %.2f\n",
                   students[i].roll, students[i].name, students[i].age, students[i].marks);
            return;
        }
    }
    printf("No record found with Roll Number %d\n", roll);
}

void deleteStudent() {
    int roll;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("No record found with Roll Number %d\n", roll);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
