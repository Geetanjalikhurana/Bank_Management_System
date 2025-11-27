#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
    string name, address, accountType;
    double balance;

public:
    BankAccount(string n, string a, string type, double b)
        : name(n), address(a), accountType(type), balance(b) {}

    void deposit(double amount) {    
        balance += amount;
        cout << "Deposited successfully. New balance: " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;  
        } else {
            balance -= amount;
            cout << "Withdrawn successfully. New balance: " << balance << endl;
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Name        : " << name << endl;
        cout << "Address     : " << address << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance     : " << balance << endl;
    }

    string getName() {
        return name;
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;
    string name, address, type;
    double amount, balance;
    bool running = true;

    while (running) {
        cout << "\n========== Bank Menu ==========\n";
        cout << "1. Open New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();  // Clear newline before next getline()

        switch (choice) {
        case 1:
            cout << "Enter your full name: ";
            getline(cin, name);
            cout << "Enter your address: ";
            getline(cin, address);
            cout << "Enter account type (Saving/Current): ";
            getline(cin, type);
            cout << "Enter initial deposit amount: ";
            cin >> balance;
            cin.ignore();  // Clear newline after numeric input
            accounts.push_back(BankAccount(name, address, type, balance));
            cout << "Account created successfully!\n";
            break;

        case 2: {
            cout << "Enter your name to deposit: ";
            getline(cin, name);
            bool found = false;
            for (size_t i = 0; i < accounts.size(); ++i) {
                if (accounts[i].getName() == name) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    cin.ignore();
                    accounts[i].deposit(amount);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Account not found.\n";
            break;
        }

        case 3: {
            cout << "Enter your name to withdraw: ";
            getline(cin, name);
            bool found = false;
            for (size_t i = 0; i < accounts.size(); ++i) {
                if (accounts[i].getName() == name) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    cin.ignore();
                    accounts[i].withdraw(amount);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Account not found.\n";
            break;
        }

        case 4: {
            cout << "Enter your name to view account: ";
            getline(cin, name);
            bool found = false;
            for (size_t i = 0; i < accounts.size(); ++i) {
                if (accounts[i].getName() == name) {
                    accounts[i].display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Account not found.\n";
            break;
        }

        case 5:
            running = false;
            cout << "Thank you for using the banking system. Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
