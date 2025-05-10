#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu();
void deposit(double &balance);
void withdraw(double &balance);
void checkBalance(double balance);

int main() {
    double balance = 0.0;
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                deposit(balance);
                break;
            case 2:
                withdraw(balance);
                break;
            case 3:
                checkBalance(balance);
                break;
            case 4:
                cout << "Exiting the banking system. Thank you for using our service!" << endl;
                running = false;
                break;
            default:
                cout << "Invalid option! Please choose a valid menu option." << endl;
        }
    }
    return 0;
}

void displayMenu() {
    cout << "\n======== BANKING SYSTEM ========\n";
    cout << "1. Deposit Money\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Check Balance\n";
    cout << "4. Exit\n";
    cout << "================================\n";
    cout << "Choose an option: ";
}

void deposit(double &balance) {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful! New balance: $" << fixed << setprecision(2) << balance << endl;
    } else {
        cout << "Invalid amount. Deposit must be positive." << endl;
    }
}

void withdraw(double &balance) {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful! New balance: $" << fixed << setprecision(2) << balance << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds! Withdrawal failed." << endl;
    } else {
        cout << "Invalid amount. Withdrawal must be positive." << endl;
    }
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}
