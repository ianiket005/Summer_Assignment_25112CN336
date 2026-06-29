#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    int available;
};

struct Book library[100];
int count = 0;

void addBook() {
    library[count].id = count + 1;
    printf("Enter book title: ");
    scanf(" %[^\n]", library[count].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", library[count].author);
    library[count].available = 1;
    count++;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
               library[i].id, library[i].title, library[i].author,
               library[i].available ? "Available" : "Issued");
    }
}

void searchBook() {
    char searchTitle[50];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", searchTitle);
    for (int i = 0; i < count; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book Found: ID: %d | Author: %s | Status: %s\n",
                   library[i].id, library[i].author,
                   library[i].available ? "Available" : "Issued");
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook() {
    int id;
    printf("Enter book ID to issue: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid book ID.\n");
        return;
    }
    if (library[id - 1].available) {
        library[id - 1].available = 0;
        printf("Book issued successfully!\n");
    } else {
        printf("Book already issued.\n");
    }
}

void returnBook() {
    int id;
    printf("Enter book ID to return: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid book ID.\n");
        return;
    }
    if (!library[id - 1].available) {
        library[id - 1].available = 1;
        printf("Book returned successfully!\n");
    } else {
        printf("Book was not issued.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Mini Library System ---\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
