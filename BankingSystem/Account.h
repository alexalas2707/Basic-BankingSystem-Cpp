#pragma once
#include <string>

class Account {
private:
    static int nextAccountNumber; // Static variable to keep track of the next account number
    int accountNumber;
    float balance;
    std::string accountType;

public:
    Account(float bal, const std::string& type);

    void Deposit(float amount);
    bool Withdraw(float amount);
    void DisplayAccountDetails() const;

    float GetBalance() const;
    int GetAccountNumber() const;
};