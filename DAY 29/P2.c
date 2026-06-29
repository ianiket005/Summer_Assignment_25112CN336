#include <stdio.h>

int arr[100], n = 0;

void createArray() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

void displayArray() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement() {
    int pos, val;
    if (n == 0) {
        printf("Array is empty. Create array first.\n");
        return;
    }
    printf("Enter position (1-%d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;
    printf("Element inserted successfully!\n");
}

void deleteElement() {
    int pos;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter position (1-%d): ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Element deleted successfully!\n");
}

void searchElement() {
    int val, found = 0;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

void sortArray() {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array sorted successfully!\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Menu Driven Array Operations ---\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Sort Array\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: searchElement(); break;
            case 6: sortArray(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
