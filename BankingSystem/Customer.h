#pragma once
#include <string>
#include <vector>
#include "Account.h"

class Customer {
private:
    int customerID;
    std::string name;
    std::vector<Account> accounts;

    // Private helper method to find an account by its number
    Account* FindAccount(int accountNumber);

public:
    Customer(int id, const std::string& n);

    void AddAccount(const Account& acc);
    void DisplayCustomerDetails() const;

    // Transaction methods
    bool Deposit(int accountNumber, float amount);
    bool Withdraw(int accountNumber, float amount);
    float GetBalance(int accountNumber) const;

    int GetCustomerID() const;
    const std::string& GetName() const;
};
