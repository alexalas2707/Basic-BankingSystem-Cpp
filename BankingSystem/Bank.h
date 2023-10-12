#pragma once
#include <vector>
#include "Customer.h"

class Bank {
private:
    std::vector<Customer> customers;

public:
    void AddCustomer(const Customer& cust);
    void DisplayAllCustomers() const;
    Customer* FindCustomer(int id);
};
