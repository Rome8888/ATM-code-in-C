#include <stdio.h>

int main() {
    int pin = 1234, enteredPin, option;
    float balance = 1000.0, deposit, withdraw;

    // Welcome message
    printf("Welcome to the ATM!\n");
    
    // Ask for PIN
    printf("Please enter your PIN: ");
    scanf("%d", &enteredPin);

    // Check if the entered PIN is correct
    if (enteredPin != pin) {
        printf("Incorrect PIN. Access Denied.\n");
        return 0;
    }

    do {
        // Menu options
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Check Balance
                printf("Your current balance is: $%.2f\n", balance);
                break;

            case 2: // Deposit Money
                printf("Enter amount to deposit: $");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("You have successfully deposited $%.2f\n", deposit);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3: // Withdraw Money
                printf("Enter amount to withdraw: $");
                scanf("%f", &withdraw);
                if (withdraw <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else if (withdraw > balance) {
                    printf("Insufficient balance. Your current balance is $%.2f\n", balance);
                } else {
                    balance -= withdraw;
                    printf("You have successfully withdrawn $%.2f\n", withdraw);
                }
                break;

            case 4: // Exit
                printf("Thank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 4);

    return 0;
}
