#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary;
    float hra;  
    float da;   
    float grossSalary;
};

struct Employee employees[100];
int count = 0;

void calculateGross(struct Employee *emp) {
    emp->grossSalary = emp->basicSalary + emp->hra + emp->da;
}

void addEmployee() {
    printf("\nEnter Employee ID: ");
    scanf("%d", &employees[count].id);
    printf("Enter Name: ");
    scanf(" %[^\n]", employees[count].name);
    printf("Enter Basic Salary: ");
    scanf("%f", &employees[count].basicSalary);
    printf("Enter HRA: ");
    scanf("%f", &employees[count].hra);
    printf("Enter DA: ");
    scanf("%f", &employees[count].da);

    calculateGross(&employees[count]);
    count++;
    printf("Employee salary record added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }
    printf("\n--- Salary Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Basic: %.2f | HRA: %.2f | DA: %.2f | Gross: %.2f\n",
               employees[i].id, employees[i].name,
               employees[i].basicSalary, employees[i].hra,
               employees[i].da, employees[i].grossSalary);
    }
}

void searchEmployee() {
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Record Found: ID: %d | Name: %s | Basic: %.2f | HRA: %.2f | DA: %.2f | Gross: %.2f\n",
                   employees[i].id, employees[i].name,
                   employees[i].basicSalary, employees[i].hra,
                   employees[i].da, employees[i].grossSalary);
            return;
        }
    }
    printf("No record found with Employee ID %d\n", id);
}

void updateSalary() {
    int id;
    printf("\nEnter Employee ID to update salary: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("Enter new Basic Salary: ");
            scanf("%f", &employees[i].basicSalary);
            printf("Enter new HRA: ");
            scanf("%f", &employees[i].hra);
            printf("Enter new DA: ");
            scanf("%f", &employees[i].da);

            calculateGross(&employees[i]);
            printf("Salary updated successfully!\n");
            return;
        }
    }
    printf("No record found with Employee ID %d\n", id);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Salary Management System ---\n");
        printf("1. Add Employee Salary Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Employee Salary\n");
        printf("4. Update Employee Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateSalary(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
