#include <stdio.h>
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
    employees[count].id = count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", employees[count].name);
    printf("Enter department: ");
    scanf(" %[^\n]", employees[count].department);
    printf("Enter salary: ");
    scanf("%f", &employees[count].salary);
    count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Department: %s | Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].department, employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Employee not found.\n");
        return;
    }
    printf("Record Found: Name: %s | Department: %s | Salary: %.2f\n",
           employees[id - 1].name, employees[id - 1].department, employees[id - 1].salary);
}

void deleteEmployee() {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid employee ID.\n");
        return;
    }
    for (int i = id - 1; i < count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    count--;
    printf("Employee deleted successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Mini Employee Management System ---\n");
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
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
