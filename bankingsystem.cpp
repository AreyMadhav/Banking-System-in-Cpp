#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
public:
    Account(string accNumber, string accHolder, double balance)
        : accountNumber(accNumber), accountHolder(accHolder), balance(balance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << balance << endl;
        } else {
            cout << "Invalid amount for withdrawal or insufficient balance." << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

private:
    string accountNumber;
    string accountHolder;
    double balance;
};

int findAccount(vector<Account>& accounts, string accNumber) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNumber) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Account> accounts;

    while (true) {
        cout << "Banking System Menu" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Info" << endl;
        cout << "5. Compare Account Balances (Greater Than)" << endl;
        cout << "6. Compare Account Balances (Less Than)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            {
                string accNumber, accHolder;
                double initialBalance;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                cout << "Enter Account Holder Name: ";
                cin >> accHolder;
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;

                Account newAccount(accNumber, accHolder, initialBalance);
                accounts.push_back(newAccount);
                cout << "Account created successfully." << endl;
            }
            break;

        case 2:
            {
                string accNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                int index = findAccount(accounts, accNumber);
                if (index != -1) {
                    cout << "Enter Deposit Amount: ";
                    cin >> amount;
                    accounts[index].deposit(amount);
                } else {
                    cout << "Account not found." << endl;
                }
            }
            break;

        case 3:
            {
                string accNumber;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                int index = findAccount(accounts, accNumber);
                if (index != -1) {
                    cout << "Enter Withdrawal Amount: ";
                    cin >> amount;
                    accounts[index].withdraw(amount);
                } else {
                    cout << "Account not found." << endl;
                }
            }
            break;

        case 4:
            {
                string accNumber;
                cout << "Enter Account Number: ";
                cin >> accNumber;
                int index = findAccount(accounts, accNumber);
                if (index != -1) {
                    accounts[index].display();
                } else {
                    cout << "Account not found." << endl;
                }
            }
            break;

        case 5:
            {
                double compareBalance;
                cout << "Enter a balance to compare (greater than): $";
                cin >> compareBalance;

                cout << "Accounts with balance greater than $" << compareBalance << ":" << endl;
                for (const Account& account : accounts) {
                    if (account.getBalance() > compareBalance) {
                        account.display();
                        cout << endl;
                    }
                }
            }
            break;

        case 6:
            {
                double compareBalance;
                cout << "Enter a balance to compare (less than): $";
                cin >> compareBalance;

                cout << "Accounts with balance less than $" << compareBalance << ":" << endl;
                for (const Account& account : accounts) {
                    if (account.getBalance() < compareBalance) {
                        account.display();
                        cout << endl;
                    }
                }
            }
            break;

        case 7:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
