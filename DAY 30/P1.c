#include <stdio.h>
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
    students[count].roll = count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter age: ");
    scanf("%d", &students[count].age);
    printf("Enter marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student record added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s | Age: %d | Marks: %.2f\n",
               students[i].roll, students[i].name, students[i].age, students[i].marks);
    }
}

void searchStudent() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Record Found: Roll: %d | Age: %d | Marks: %.2f\n",
                   students[i].roll, students[i].age, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    if (roll <= 0 || roll > count) {
        printf("Invalid roll number.\n");
        return;
    }
    for (int i = roll - 1; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    printf("Record deleted successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Student Record System ---\n");
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
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
