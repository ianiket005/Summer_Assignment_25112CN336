#include <stdio.h>
#include <string.h>

char str[100];

void inputString() {
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("String stored successfully!\n");
}

void displayString() {
    if (strlen(str) == 0) {
        printf("No string available.\n");
        return;
    }
    printf("Current String: %s\n", str);
}

void lengthString() {
    if (strlen(str) == 0) {
        printf("No string available.\n");
        return;
    }
    printf("Length of string: %lu\n", strlen(str));
}

void reverseString() {
    if (strlen(str) == 0) {
        printf("No string available.\n");
        return;
    }
    int len = strlen(str);
    printf("Reversed String: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void copyString() {
    if (strlen(str) == 0) {
        printf("No string available.\n");
        return;
    }
    char copy[100];
    strcpy(copy, str);
    printf("Copied String: %s\n", copy);
}

void concatenateString() {
    char temp[100];
    printf("Enter another string: ");
    scanf(" %[^\n]", temp);
    strcat(str, temp);
    printf("Concatenated String: %s\n", str);
}

void compareString() {
    char temp[100];
    printf("Enter another string: ");
    scanf(" %[^\n]", temp);
    if (strcmp(str, temp) == 0) {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Menu Driven String Operations ---\n");
        printf("1. Input String\n");
        printf("2. Display String\n");
        printf("3. Length of String\n");
        printf("4. Reverse String\n");
        printf("5. Copy String\n");
        printf("6. Concatenate String\n");
        printf("7. Compare String\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inputString(); break;
            case 2: displayString(); break;
            case 3: lengthString(); break;
            case 4: reverseString(); break;
            case 5: copyString(); break;
            case 6: concatenateString(); break;
            case 7: compareString(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}
