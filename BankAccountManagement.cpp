#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Simple OOP example for a Bank Account Management System.
class BankAccount {
private:
    string holderName;
    int accountNumber;
    double balance;
public:
    BankAccount(string name, int number, double openingBalance) {
        holderName = name;
        accountNumber = number;
        balance = openingBalance;
    }
    void deposit(double amount) {
        if (amount > 0) { balance += amount; cout << "Deposit successful.\n"; }
        else cout << "Enter a valid amount.\n";
    }
    void withdraw(double amount) {
        if (amount <= 0) cout << "Enter a valid amount.\n";
        else if (amount > balance) cout << "Insufficient balance.\n";
        else { balance -= amount; cout << "Withdrawal successful.\n"; }
    }
    void displayDetails() const {
        cout << "\n--- Account Details ---\n" << "Holder: " << holderName << '\n';
        cout << "Account Number: " << accountNumber << '\n';
        cout << "Balance: Rs. " << fixed << setprecision(2) << balance << '\n';
    }
};
int main() {
    string name; int number; double openingBalance;
    cout << "BANK ACCOUNT MANAGEMENT SYSTEM\nEnter account holder name: ";
    getline(cin, name);
    cout << "Enter account number: "; cin >> number;
    cout << "Enter opening balance: "; cin >> openingBalance;
    if (openingBalance < 0) { cout << "Opening balance cannot be negative.\n"; return 0; }
    BankAccount account(name, number, openingBalance); int choice;
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Display Details\n0. Exit\nEnter choice: "; cin >> choice;
        if (choice == 1) { double amount; cout << "Enter deposit amount: "; cin >> amount; account.deposit(amount); }
        else if (choice == 2) { double amount; cout << "Enter withdrawal amount: "; cin >> amount; account.withdraw(amount); }
        else if (choice == 3) account.displayDetails();
        else if (choice != 0) cout << "Invalid choice.\n";
    } while (choice != 0);
    cout << "Thank you.\n"; return 0;
}
