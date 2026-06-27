#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

struct Employee employees[100];
int count = 0;

void addEmployee() {
    printf("\nEnter Employee ID: ");
    scanf("%d", &employees[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", employees[count].name);
    printf("Enter Department: ");
    scanf(" %[^\n]", employees[count].department);
    printf("Enter Salary: ");
    scanf("%f", &employees[count].salary);
    count++;
    printf("Employee record added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }
    printf("\n--- Employee Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Record Found: ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
                   employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
            return;
        }
    }
    printf("No record found with Employee ID %d\n", id);
}

void deleteEmployee() {
    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            count--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("No record found with Employee ID %d\n", id);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Employee Management System ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
