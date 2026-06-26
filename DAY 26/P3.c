#include <stdio.h>

int main() {
    int choice;
    float balance = 1000.0;  
    float amount;

    printf(" Welcome to the ATM Simulation\n");

    do {
        printf("\n--- Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Current Balance: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                printf(" Deposited successfully! New Balance: %.2f\n", balance);
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if(amount > balance) {
                    printf(" Insufficient balance!\n");
                } else {
                    balance -= amount;
                    printf(" Withdrawal successful! New Balance: %.2f\n", balance);
                }
                break;

            case 4:
                printf(" Thank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf(" Invalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}
