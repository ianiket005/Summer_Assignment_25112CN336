#include <stdio.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[15];
    char email[50];
};

struct Contact contacts[100];
int count = 0;

void addContact() {
    contacts[count].id = count + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", contacts[count].name);
    printf("Enter phone: ");
    scanf(" %[^\n]", contacts[count].phone);
    printf("Enter email: ");
    scanf(" %[^\n]", contacts[count].email);
    count++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Phone: %s | Email: %s\n",
               contacts[i].id, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void searchContact() {
    char searchName[50];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact Found: ID: %d | Phone: %s | Email: %s\n",
                   contacts[i].id, contacts[i].phone, contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact() {
    int id;
    printf("Enter contact ID to delete: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid contact ID.\n");
        return;
    }
    for (int i = id - 1; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    count--;
    printf("Contact deleted successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
