#include <stdio.h>
#include <string.h>

struct Account {
    int id;
    char name[50];
    float balance;
};

struct Account accounts[100];
int count = 0;

void createAccount() {
    accounts[count].id = count + 1;
    printf("Enter account holder name: ");
    scanf(" %[^\n]", accounts[count].name);
    printf("Enter initial deposit: ");
    scanf("%f", &accounts[count].balance);
    count++;
    printf("Account created successfully!\n");
}

void displayAccounts() {
    if (count == 0) {
        printf("No accounts available.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Balance: %.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
}

void depositMoney() {
    int id;
    float amount;
    printf("Enter account ID: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid account ID.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    accounts[id - 1].balance += amount;
    printf("Deposit successful! New Balance: %.2f\n", accounts[id - 1].balance);
}

void withdrawMoney() {
    int id;
    float amount;
    printf("Enter account ID: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid account ID.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > accounts[id - 1].balance) {
        printf("Insufficient balance.\n");
    } else {
        accounts[id - 1].balance -= amount;
        printf("Withdrawal successful! New Balance: %.2f\n", accounts[id - 1].balance);
    }
}

void checkBalance() {
    int id;
    printf("Enter account ID: ");
    scanf("%d", &id);
    if (id <= 0 || id > count) {
        printf("Invalid account ID.\n");
        return;
    }
    printf("Account Balance: %.2f\n", accounts[id - 1].balance);
}

int main() {
    int choice;
    do {
        printf("\n--- Bank Account System ---\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Check Balance\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: checkBalance(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
