#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks[5];  
    float total;
    float percentage;
    char grade;
};

struct Student students[100];
int count = 0;

char calculateGrade(float percentage) {
    if (percentage >= 90) return 'A';
    else if (percentage >= 75) return 'B';
    else if (percentage >= 60) return 'C';
    else if (percentage >= 40) return 'D';
    else return 'F';
}

void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    students[count].total = 0;
    for (int i = 0; i < 5; i++) {
        printf("Enter marks for Subject %d: ", i + 1);
        scanf("%f", &students[count].marks[i]);
        students[count].total += students[count].marks[i];
    }

    students[count].percentage = students[count].total / 5.0;
    students[count].grade = calculateGrade(students[count].percentage);

    count++;
    printf("Marksheet generated successfully!\n");
}

void displayMarksheet() {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }
    printf("\n--- Marksheet Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d | Name: %s\n", students[i].roll, students[i].name);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", students[i].marks[j]);
        }
        printf("\nTotal: %.2f | Percentage: %.2f%% | Grade: %c\n\n",
               students[i].total, students[i].percentage, students[i].grade);
    }
}

void searchStudent() {
    int roll;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("\n--- Marksheet ---\n");
            printf("Roll: %d | Name: %s\n", students[i].roll, students[i].name);
            printf("Marks: ");
            for (int j = 0; j < 5; j++) {
                printf("%.2f ", students[i].marks[j]);
            }
            printf("\nTotal: %.2f | Percentage: %.2f%% | Grade: %c\n",
                   students[i].total, students[i].percentage, students[i].grade);
            return;
        }
    }
    printf("No record found with Roll Number %d\n", roll);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Marksheet Generation System ---\n");
        printf("1. Add Student Marksheet\n");
        printf("2. Display All Marksheets\n");
        printf("3. Search Student Marksheet\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayMarksheet(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
