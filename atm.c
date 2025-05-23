#include <stdio.h>

// Function declarations
void check_balance(float balance);
float deposit(float balance);
float withdraw(float balance);

int main() {
    int choice;
    float balance = 1000000.0;  

    do {
        printf("\n==== ATM MENU ====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_balance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Exiting the ATM. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void check_balance(float balance) {
    printf("Your current balance is: %.2f\n", balance);
}

// Function to deposit money
float deposit(float balance) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Deposit amount must be positive.\n");
    } else {
        balance += amount;
        printf("Deposit successful. New balance: %.2f\n", balance);
    }
    return balance;
}

// Function to withdraw money
float withdraw(float balance) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Withdrawal amount must be positive.\n");
    } else if (amount > balance) {
        printf("Insufficient funds. Your balance is: %.2f\n", balance);
    } else {
        balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", balance);
    }
    return balance;
}

