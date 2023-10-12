#include "Customer.h"
#include <iostream>

// Constructor for the Customer class, initializing customerID and name
Customer::Customer(int id, const std::string& n) : customerID(id), name(n) {}

// Add an account to the customer's list of accounts
void Customer::AddAccount(const Account& acc) {
    accounts.push_back(acc);
}

// Display the customer's details, including their associated accounts
void Customer::DisplayCustomerDetails() const {
    std::cout << "Customer ID: " << customerID << std::endl;
    std::cout << "Name: " << name << std::endl;
    for (const auto& acc : accounts) {
        acc.DisplayAccountDetails();
    }
}

// Private helper method to find an account by its number within the customer's list of accounts
Account* Customer::FindAccount(int accountNumber) {
    for (auto& acc : accounts) {
        if (acc.GetAccountNumber() == accountNumber) {
            return &acc;
        }
    }
    return nullptr; // Return null if account is not found
}

// Deposit a specified amount into a customer's account
bool Customer::Deposit(int accountNumber, float amount) {
    Account* acc = FindAccount(accountNumber);
    if (acc) {
        acc->Deposit(amount);
        return true; // Successfully deposited
    }
    return false; // Deposit failed (account not found)
}

// Withdraw a specified amount from a customer's account
bool Customer::Withdraw(int accountNumber, float amount) {
    Account* acc = FindAccount(accountNumber);
    if (acc) {
        return acc->Withdraw(amount);
    }
    return false; // Withdrawal failed (account not found or insufficient balance)
}

// Retrieve the balance of a specified account
float Customer::GetBalance(int accountNumber) const {
    for (const auto& acc : accounts) {
        if (acc.GetAccountNumber() == accountNumber) {
            return acc.GetBalance();
        }
    }
    return -1; // Indicates that the account was not found
}

// Getter for customerID
int Customer::GetCustomerID() const {
    return customerID;
}

// Getter for name
const std::string& Customer::GetName() const {
    return name;
}
