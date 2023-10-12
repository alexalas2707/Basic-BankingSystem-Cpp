#include "Account.h"
#include <iostream>

// Static variable initialization to keep track of the next account number
int Account::nextAccountNumber = 1;

// Constructor for the Account class
// It initializes account number, balance, and account type
// The account number is auto-incremented each time a new Account object is instantiated.
Account::Account(float bal, const std::string& type) :
    accountNumber(nextAccountNumber++), balance(bal), accountType(type) {}

// Deposit function to add a specified amount to the account balance
void Account::Deposit(float amount) {
    balance += amount;
}

// Withdraw function to remove a specified amount from the account balance
// Checks if there's enough balance to make the withdrawal
bool Account::Withdraw(float amount) {
    if (amount > balance) {
        std::cout << "Insufficient funds!" << std::endl;
        return false;
    }
    balance -= amount;
    return true;
}

// Display all details of the account: account number, balance, and type
void Account::DisplayAccountDetails() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Balance: " << balance << std::endl;
    std::cout << "Account Type: " << accountType << std::endl;
}

// Getter function to retrieve the balance of the account
float Account::GetBalance() const {
    return balance;
}

// Getter function to retrieve the account number
int Account::GetAccountNumber() const {
    return accountNumber;
}
