#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[100];
int count = 0;

void addItem() {
    inventory[count].id = count + 1;
    printf("Enter item name: ");
    scanf(" %[^\n]", inventory[count].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[count].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[count].price);
    count++;
    printf("Item added successfully!\n");
}

void displayItems() {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: %.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    char searchName[50];
    printf("Enter item name to search: ");
    scanf(" %[^\n]", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Item Found: ID: %d | Quantity: %d | Price: %.2f\n",
                   inventory[i].id, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found.\n");
}

void updateItem() {
    int id;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid item ID.\n");
        return;
    }
    printf("Enter new quantity: ");
    scanf("%d", &inventory[id - 1].quantity);
    printf("Enter new price: ");
    scanf("%f", &inventory[id - 1].price);
    printf("Item updated successfully!\n");
}

void deleteItem() {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid item ID.\n");
        return;
    }
    for (int i = id - 1; i < count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    count--;
    printf("Item deleted successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateItem(); break;
            case 5: deleteItem(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
