#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accNo;
    string name;
    double balance;

public:
    BankAccount(int a, string n, double b) {
        accNo = a;
        name = n;
        balance = b;
    }

    virtual void display() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: Rs. " << balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Money Deposited Successfully!\n";
        } else {
            cout << "Invalid Amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Money Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    int getAccNo() {
        return accNo;
    }
};

// Derived Class
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(int a, string n, double b)
        : BankAccount(a, n, b) {}

    void display() override {
        cout << "\n--- Savings Account ---";
        BankAccount::display();
    }
};

// Bank Management Class
class Bank {
private:
    vector<SavingsAccount> accounts;

public:
    void createAccount() {
        int a;
        string n;
        double b;

        cout << "Enter Account Number: ";
        cin >> a;

        for (auto &x : accounts) {
            if (x.getAccNo() == a) {
                cout << "Account Already Exists!\n";
                return;
            }
        }

        cout << "Enter Name: ";
        cin >> n;

        cout << "Enter Initial Balance: ";
        cin >> b;

        if (b < 0) {
            cout << "Invalid Balance!\n";
            return;
        }

        accounts.emplace_back(a, n, b);
        cout << "Account Created Successfully!\n";
    }

    SavingsAccount* search(int a) {
        for (auto &x : accounts) {
            if (x.getAccNo() == a) {
                return &x;
            }
        }
        return nullptr;
    }

    void depositMoney() {
        int a;
        double b;

        cout << "Enter Account Number: ";
        cin >> a;

        SavingsAccount* x = search(a);
        if (x) {
            cout << "Enter Amount: ";
            cin >> b;
            x->deposit(b);
        } else {
            cout << "Account Not Found!\n";
        }
    }

    void withdrawMoney() {
        int a;
        double b;

        cout << "Enter Account Number: ";
        cin >> a;

        SavingsAccount* x = search(a);
        if (x) {
            cout << "Enter Amount: ";
            cin >> b;
            x->withdraw(b);
        } else {
            cout << "Account Not Found!\n";
        }
    }

    void checkBalance() {
        int a;

        cout << "Enter Account Number: ";
        cin >> a;

        SavingsAccount* x = search(a);
        if (x) {
            x->display();
        } else {
            cout << "Account Not Found!\n";
        }
    }

    void displayAll() {
        if (accounts.empty()) {
            cout << "No Accounts Available!\n";
            return;
        }

        for (auto &x : accounts) {
            x.display();
        }
    }
};

// Main Function
int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Check Balance";
        cout << "\n5. Display All Accounts";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.depositMoney();
                break;
            case 3:
                bank.withdrawMoney();
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                bank.displayAll();
                break;
            case 6:
                cout << "Thank You!\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
