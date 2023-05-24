#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& number, const std::string& holder, double initialBalance) {
        accountNumber = number;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    void displayAccountInfo() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    BankAccount account("123456789", "John Doe", 1000.0);

    account.displayAccountInfo();

    account.deposit(500.0);
    std::cout << "Amount deposited." << std::endl;

    account.displayAccountInfo();

    account.withdraw(200.0);
    std::cout << "Amount withdrawn." << std::endl;

    account.displayAccountInfo();

    account.withdraw(1500.0); // Withdrawal with insufficient balance
    account.displayAccountInfo();

    return 0;
}
